#!/usr/bin/env python3
"""c2force.py - the WRITE side of c2diag: compile one source with the pinned MSVC 2005 SP1 back end (c2.dll
14.00.50727.762) while overriding ONE decision of it for the target function (an allocator priority, a web's register,
a web sent to memory, a scheduler priority, one jump-optimiser change skipped), and compare the object with the original
the way the bench does (checker.compare + an aligned instruction diff). A sweep mode tries every single override of a
kind and reports which one makes the function equal, or how close each gets. Owner-side diagnostic, never delivered: it
compiles outside tools/match.py, charges no attempt and decides nothing; see README.md ("c2force").

usage:
  c2force.py 0xVA SOURCE [--prio R:WEB:+N] [--reg R:WEB:esi] [--mem R:WEB] [--sw R:WEB:W] [--sched G:NODE:+N] [--jskip SITE:N]
                         [--diff] [--keep]                                   # one forced compile (several overrides ok)
  c2force.py 0xVA SOURCE --sweep prio|sched|jump|reg|sw|all [--steps K] [--deltas] [--rounds 1,2] [--regions 3,4]
                         [--lines A-B] [--sched-max N] [--jobs J] [--top N] [--json OUT]
  c2force.py 0xVA SOURCE --sweep pairs [--pair-of prio|sched|jump|reg|sw|all] [--singles PREV.json] [--top N] ...
                         # the single sweep (or an earlier --json of it), then every pair of its N most useful overrides
  c2force.py 0xVA SOURCE --validate                                          # no-op override vs the pinned compiler
 added by lane TOOL-C2X (local assigner, pre-backend passes, region builder after lane FOCUS-14, frame slots):
  c2force.py 0xVA SOURCE [--rot T[/O]:ecx] [--pick T[/O]:edx[:rot]] [--skip ADDR[:N][=V]] [--rg CALL:BLK[:nopred|nosucc|both]]
                         [--slotw SLOT:+D] [--slotswap A,B] [--early]
  c2force.py 0xVA SOURCE --sweep rot|pick|skip|rg|slot|new [--in 0xFN,...] [--skip-max N] [--lines A-B] ...
  (--sweep takes a comma list too: --sweep rot,pick; `new` = rot,pick,rg,slot,skip; `all` keeps its five kinds)
WEB is a candidate id of that round (c2prio's table) or its name (a named variable); NODE a scheduler node number
(c2sched's table); R / G are c2prio round numbers (per register class) / c2sched region numbers.
"""
import argparse, collections, concurrent.futures as cf, hashlib, json, os, re, shutil, subprocess, sys, tempfile, time

HERE = os.path.dirname(os.path.abspath(__file__))
# the readers (c2prio / c2sched and their collectors): next to this file, else C2DIAG_LIB, else the checkout's copy
LIB = os.environ.get('C2DIAG_LIB') or (HERE if os.path.exists(os.path.join(HERE, 'c2prio.py')) else
                                      os.path.join(os.environ.get('D2REPO', '/home/claude/diablo2-native'), 'contrib', 'c2diag'))
sys.path.insert(0, LIB)
import c2prio
from c2prio import WORK, TC, REPO, winpath
sys.path.insert(0, os.path.join(REPO, 'tools'))

REGNUM = {'eax': 1, 'ecx': 2, 'edx': 3, 'ebx': 4, 'esi': 7, 'edi': 8}
REGNAME = {v: k for k, v in REGNUM.items()}
# Jump-optimiser call sites inside one sweep (0x10b2ccf0), as in c2sched.JCALLS: (call VA, callee)
from c2sched import JCALLS, JNAME
GDB_TIMEOUT = 180        # one forced compile; a sweep entry that runs longer is reported as TIMEOUT
MEMCAP_MB = int(os.environ.get('C2FORCE_MEMCAP_MB', '1200'))   # resident limit of one forced compile (lane TOOL-C2X)


# ---- the compare (the bench's code: checker.compare, then an aligned instruction diff with relocations masked) -----
class Target:
    def __init__(self, va, src):
        import spellsearch, common, checker
        self.checker = checker
        wd = os.path.join(WORK, 'runs'); os.makedirs(wd, exist_ok=True)
        self.C = spellsearch.Compiler(va, src, wd)      # queue length, image reader, the VA's flags (rulings, opt-ins)
        self.va = va; self.src = src; self.length = self.C.length
        self.flags = self.C.flags_for(src)
        self.orig = self.C.pe.read(va, self.length)

    def compare(self, objb):
        res = self.checker.compare(objb, self.src, self.va, self.length, self.C.pe.read, self.C._qlen)
        if res['status'] in ('NO_MARKER', 'NO_SYMBOL'):
            return dict(status=res['status'], err=res.get('detail'))
        body = res['_body']
        relo = set()
        for x in res['relocations']:
            relo.update(range(x['offset'], x['offset'] + 4))
        ours = instr_lines(body, relo); orig = instr_lines(self.orig, None)
        nd, ops = align(ours, orig)
        return dict(status=res['status'], unmasked=res['unmasked_diff_bytes'], length=res['compiled_length'],
                    lines=nd, sha=res['compiled_body_sha256'], symbol=res.get('symbol'), _ours=ours, _orig=orig,
                    _ops=ops, problems=res.get('target_problems'))


_md = None
def instr_lines(b, mask):
    global _md
    import capstone
    if _md is None: _md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    out = []
    for ins in _md.disasm(b, 0):
        s = '%s %s' % (ins.mnemonic, ins.op_str)
        if mask and any(o in mask for o in range(ins.address, ins.address + ins.size)):
            ops = s.split(' ', 1)[1] if ' ' in s else ''
            ops = re.sub(r'(ebp|esp) ([-+]) 0x[0-9a-f]+', lambda m: m.group(0).replace('0x', 'OFS'), ops)
            s = (s.split(' ', 1)[0] + ' ' + ops)
            s = re.sub(r'(?<![\w-])(0x[0-9a-f]+|0)(?![\w])', 'REL', s).replace('OFS', '0x')
        if mask is None:
            s = re.sub(r'\b0x[4-9a-f][0-9a-f]{5}\b', 'REL', s)
        s = re.sub(r'\b(j\w+|call) (0x[0-9a-f]+|REL)$', lambda m: m.group(1) + ' L', s)
        s = re.sub(r' [+-] REL\]', ']', s)
        out.append((ins.address, s))
    return out


def align(a, b):
    import difflib
    ta = [s for _, s in a]; tb = [s for _, s in b]
    sm = difflib.SequenceMatcher(None, ta, tb, autojunk=False)
    nd = 0; ops = sm.get_opcodes()
    for tag, i1, i2, j1, j2 in ops:
        if tag != 'equal': nd += max(i2 - i1, j2 - j1)
    return nd, ops


def print_diff(r, ctx=2):
    a, b = r['_ours'], r['_orig']
    for tag, i1, i2, j1, j2 in r['_ops']:
        if tag == 'equal': continue
        for k in range(max(0, i1 - ctx), i1): print('   %04X %-40s' % (a[k][0], a[k][1]))
        for k in range(max(i2 - i1, j2 - j1)):
            l = '%04X %-40s' % a[i1 + k] if i1 + k < i2 else ' ' * 45
            rr = '%04X %s' % b[j1 + k] if j1 + k < j2 else ''
            print(' ! %s | %s' % (l, rr))
        print('   ---')
    print('differing aligned lines:', r['lines'])


EQUAL = ('RAW_EQUAL', 'RELOCATION_RESOLVED_EQUAL')
def fig(r):
    if r.get('status') in EQUAL: return '%s' % r['status']
    if 'unmasked' not in r: return '%s %s' % (r.get('status'), (r.get('err') or '')[:120])
    return '%s len %d/%d unmasked %d lines %d' % (r['status'], r['length'], r.get('claimed', 0), r['unmasked'], r['lines'])


def rank(r):
    if r.get('status') in EQUAL: return (0, 0, 0)
    if 'unmasked' not in r: return (9, 10 ** 6, 10 ** 6)
    return (1 if r['length'] == r.get('claimed') else 2, r['lines'], r['unmasked'])


# ---- one compile under gdb with overrides ------------------------------------------------------------------------
def jsite_pops():
    """bytes each jump-optimiser transform pops on return (its `ret N`), so a skipped call leaves the stack balanced"""
    import capstone, pefile
    pe = pefile.PE(os.path.join(TC, 'c2.dll'), fast_load=True)
    img = pe.get_memory_mapped_image(); base = pe.OPTIONAL_HEADER.ImageBase
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    out = {}
    for site, callee in JCALLS:
        n = 0
        for ins in md.disasm(img[callee - base:callee - base + 0x4000], callee):
            if ins.mnemonic == 'ret':
                n = int(ins.op_str, 16) if ins.op_str else 0
                break
        out[site] = n
    return out


PRELUDE = 'int __cdecl c2force_prelude_spin_(int a) { return a * 3 + 1; }\n'
EARLY = [False]          # --early (automatic with --skip / --sweep skip): a prelude function compiled before the target,
                         # so the passes before the target's colouring are hooked too (the spin point is the first
                         # colouring of the file)


def gdb_compile(src_text, flags, script, genv, keep=False, tag='force'):
    """compile src_text with the spin copy, gdb attached running `script` (a c2diag collector) with the extra
    environment `genv` (its event file is genv's *_OUT, set by the caller to `<work>/events.jsonl`); returns
    (object bytes or None, events, compiler output, work folder)"""
    os.makedirs(os.path.join(WORK, 'runs'), exist_ok=True)
    work = tempfile.mkdtemp(prefix=tag + '-', dir=os.path.join(WORK, 'runs'))
    cpp = os.path.join(work, 'candidate.cpp'); obj = os.path.join(work, 'candidate.obj')
    open(cpp, 'w', encoding='latin-1', newline='').write(src_text)
    env = dict(os.environ, WINEDEBUG='-all')
    env['INCLUDE'] = ';'.join([winpath(os.path.join(REPO, 'headers')), winpath(REPO)])
    extra = []
    if EARLY[0]:
        open(os.path.join(work, 'c2force_prelude.h'), 'w').write(PRELUDE)
        extra = ['/FI' + 'c2force_prelude.h']
    cmd = ['wine', os.path.join(TC, 'cl.exe')] + flags + extra + ['/Focandidate.obj', 'candidate.cpp']
    # the compiler's output goes to a file, never a pipe: a wineserver that this cl starts inherits the pipe and keeps
    # it open while any other wine process (another chat's diagnostic) runs, so reading a pipe to EOF can hang
    logp = os.path.join(work, 'cl.log'); log = open(logp, 'wb')
    p = subprocess.Popen(cmd, cwd=work, env=env, stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
    log.close()
    readlog = lambda: open(logp, 'rb').read().decode('latin1')
    evp = os.path.join(work, 'events.jsonl')
    genv = {k: (evp if v == '@EVENTS' else v) for k, v in genv.items()}
    pid = None; t0 = time.time()
    while pid is None:
        if p.poll() is not None:
            out = readlog()
            if not keep: shutil.rmtree(work, ignore_errors=True)
            return None, [], 'cl exited before reaching the back end:\n' + out, work
        if time.time() - t0 > 120:
            p.kill(); raise SystemExit('timeout waiting for c2.dll')
        try:
            if os.path.join(TC, 'c2.dll') in open('/proc/%d/maps' % p.pid).read(): pid = p.pid
        except OSError:
            pass
        time.sleep(0.03)
    timed_out = False; ice = None
    try:
        g = subprocess.Popen(['gdb', '-q', '-batch', '-nx', '-p', str(pid), '-ex',
                              'python exec(open(%r).read())' % os.path.join(HERE if os.path.exists(os.path.join(HERE, script)) else LIB, script)],
                             env=dict(os.environ, **genv), stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                             stdin=subprocess.DEVNULL)
        # watchdog (lane TOOL-C2X): a skipped pass can make the compiler loop or allocate without end; a compile over
        # the time limit or over MEMCAP_MB resident is killed (an unguarded one ran a small machine out of memory)
        t1 = time.time(); over = None; ice = [False]
        while g.poll() is None or p.poll() is None:
            if time.time() - t1 > GDB_TIMEOUT: over = 'TIMEOUT after %d s (the override made the compiler loop?)' % GDB_TIMEOUT
            else:
                try:
                    rss = int(re.search(r'VmRSS:\s+(\d+)', open('/proc/%d/status' % p.pid).read()).group(1)) // 1024
                    if rss > MEMCAP_MB: over = 'TIMEOUT: compiler over %d MB resident (the override made it allocate without end?)' % MEMCAP_MB
                except (OSError, AttributeError): pass
            try:
                if os.path.getsize(logp) and b'C1001' in open(logp, 'rb').read():
                    # an internal compiler error: under gdb its handler can fault again and again, printing the
                    # message in a loop, so stop it at the first one (reported as COMPILE_ERROR with the message)
                    for q in (p, g):
                        if q.poll() is None: q.kill()
                    ice[0] = True
                    break
            except OSError: pass
            if over: break
            time.sleep(0.05)
        if over:
            for q in (p, g):
                if q.poll() is None: q.kill()
            raise subprocess.TimeoutExpired('cl', GDB_TIMEOUT, output=over)
        out = readlog()
    except subprocess.TimeoutExpired as ex:
        timed_out = True; out = ex.output if isinstance(ex.output, str) else 'TIMEOUT after %d s (the override made the compiler loop?)' % GDB_TIMEOUT
    finally:
        if p.poll() is None: p.kill(); p.wait()
    if timed_out:
        evs = []
        try:
            with open(evp) as f:
                for k, l in enumerate(f):
                    if k >= 200: break
                    if l.strip(): evs.append(json.loads(l))
        except (OSError, ValueError): pass
        if not keep: shutil.rmtree(work, ignore_errors=True)
        return None, evs, out, work
    evs = []
    if os.path.exists(evp):
        for l in open(evp):
            try: evs.append(json.loads(l))
            except ValueError: pass                 # the last line of a killed collector can be cut short
    objb = open(obj, 'rb').read() if os.path.exists(obj) and not (ice and ice[0]) else None
    if objb is not None and len(objb) < 20: objb = None
    if not keep: shutil.rmtree(work, ignore_errors=True)
    return objb, evs, out, work


def run_forced(src_text, flags, func, spec, record=False, keep=False, tag='force'):
    """compile src_text under gdb, applying `spec` to the function whose decorated name contains `func`"""
    return gdb_compile(src_text, flags, 'c2force_gdb.py',
                       dict(C2FORCE_OUT='@EVENTS', C2FORCE_FUNC=func, C2FORCE_SPEC=json.dumps(spec),
                            C2FORCE_RECORD='1' if record else '0',
                            C2FORCE_JSITES=json.dumps({str(k): v for k, v in JPOPS.items()})), keep=keep, tag=tag)


JPOPS = {}


def forced_result(T, func, spec, record=False, keep=False):
    objb, evs, out, work = run_forced(T.src, T.flags, func, spec, record=record, keep=keep)
    if objb is None:
        return dict(status='TIMEOUT' if out.startswith('TIMEOUT') else 'COMPILE_ERROR', err=out[-400:], events=evs,
                    applied=[e for e in evs if e['ev'] == 'applied'], issues=[])
    r = T.compare(objb); r['claimed'] = T.length; r['events'] = evs
    r['applied'] = [e for e in evs if e['ev'] == 'applied']
    r['issues'] = [e for e in evs if e['ev'] in ('miss', 'refused', 'error')]
    if keep: r['work'] = work
    r['_obj'] = objb
    return r


def pinned_object(T):
    """the object from the pinned compiler itself (no gdb, no spin copy), compiled exactly like the forced runs"""
    import common
    s = common.local_settings()
    work = tempfile.mkdtemp(prefix='pinned-', dir=os.path.join(WORK, 'runs'))
    open(os.path.join(work, 'candidate.cpp'), 'w', encoding='latin-1', newline='').write(T.src)
    env = dict(os.environ, WINEDEBUG='-all')
    env['INCLUDE'] = ';'.join([winpath(os.path.join(REPO, 'headers')), winpath(REPO)])
    cmd = (['wine'] if s.get('runner', 'native') != 'native' else []) + [s['cl']] + T.flags + ['/Focandidate.obj', 'candidate.cpp']
    with open(os.path.join(work, 'cl.log'), 'wb') as log:     # a file, not a pipe (see run_forced)
        subprocess.run(cmd, cwd=work, env=env, stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, timeout=600)
    p = os.path.join(work, 'candidate.obj')
    b = open(p, 'rb').read() if os.path.exists(p) else None
    shutil.rmtree(work, ignore_errors=True)
    return b


def code_sections(objb):
    """every non-debug section's raw data and relocations (what the linker takes from the object)"""
    import struct
    nsec = struct.unpack_from('<H', objb, 2)[0]; symoff, nsym = struct.unpack_from('<II', objb, 8)
    opt = struct.unpack_from('<H', objb, 16)[0]
    out = []
    for i in range(nsec):
        h = 20 + opt + 40 * i
        name = objb[h:h + 8].rstrip(b'\0').decode('latin1')
        size, rawp, relp, _, nrel = struct.unpack_from('<IIIIH', objb, h + 16)
        if name.startswith('.debug') or name == '.drectve': continue
        out.append((name, objb[rawp:rawp + size] if rawp else b'', objb[relp:relp + 10 * nrel] if nrel else b''))
    return out


# ---- the recordings the sweeps start from ------------------------------------------------------------------------
def record_alloc(T, func, cls):
    """c2prio's collector on the same source and flags: the candidates of every allocation round"""
    _, evs, out, _ = gdb_compile(T.src, list(T.flags), 'c2prio_gdb.py',
                                 dict(C2PRIO_OUT='@EVENTS', C2PRIO_FUNC=func, C2PRIO_BLOCKS='0'), tag='rec')
    rounds = [r for r in c2prio.rounds_of(evs) if r['cands'] is not None and (cls is None or r['cls'] == cls)]
    for r in rounds:
        dl = collections.defaultdict(set)
        for e in r['refs']:
            if e['line'] and e['kind'] == 'def': dl[e['id']].add(e['line'])
        r['labels'] = {c['id']: c2prio.label(c, {k: ','.join(map(str, sorted(v))) for k, v in dl.items()}) for c in r['cands']}
    return rounds


def record_sched(T, func):
    """c2sched's collector (scheduler only): regions, dependence graphs, ready lists and picks"""
    import c2sched
    _, evs, out, _ = gdb_compile(T.src, list(T.flags), 'c2sched_gdb.py',
                                 dict(C2SCHED_OUT='@EVENTS', C2SCHED_FUNC=func, C2SCHED_HERE=c2sched.LIB,
                                      C2SCHED_PASSES='0', C2SCHED_JUMPS='0',
                                      C2SCHED_SITES=json.dumps([[ret - 5, callee, ret] for callee, ret in c2sched.PIPELINE]),
                                      C2SCHED_JCALLS=json.dumps(c2sched.JCALLS)), tag='rec')
    return c2sched.regions_of(evs)


# ---- experiment generation ---------------------------------------------------------------------------------------
OVERRIDES = ('prio', 'reg', 'mem', 'sw', 'sched', 'jskip', 'rot', 'pick', 'skip', 'rg', 'slotw', 'slotswap')
SWEEPS = ('prio', 'reg', 'sw', 'sched', 'jump', 'all', 'pairs', 'rot', 'pick', 'skip', 'rg', 'slot', 'new')
def sweep_kinds(x):
    for k in x.split(','):
        if k not in SWEEPS: raise argparse.ArgumentTypeError('unknown sweep %r (one of %s)' % (k, ', '.join(SWEEPS)))
    if 'pairs' in x.split(',') and x != 'pairs': raise argparse.ArgumentTypeError('pairs is given alone (with --pair-of)')
    return x


# ---- TOOL-C2X recorders and experiment generators -------------------------------------------------------------------
def record_picks(T, func):
    """c2temps' collector: every pick of the local assigner (temporary id, path, pointer, busy and excluded sets)"""
    _, evs, out, _ = gdb_compile(T.src, list(T.flags), 'c2temps_gdb.py',
                                 dict(C2TEMPS_OUT='@EVENTS', C2TEMPS_FUNC=func, C2TEMPS_PRE='0'), tag='rec')
    occ = collections.Counter(); picks = []
    for e in evs:
        if e['ev'] != 'pick': continue
        occ[e['tid']] += 1; e['nocc'] = occ[e['tid']]; picks.append(e)
    return picks


def tname(p):
    return 'T%d%s(L%s)' % (p['tid'], '/%d' % p['nocc'] if p['nocc'] > 1 else '', p.get('line'))


def rot_experiments(picks, lines):
    """the rotation pointer moves only at rotation picks: before each one, set it to each other scratch register"""
    exps = []
    for p in picks:
        if 'rotate' not in p['path'] or p.get('ptr') not in (1, 2, 3): continue
        if lines and not (p.get('line') and lines[0] <= p['line'] <= lines[1]): continue
        busy = {int(k) for k in (p.get('occ') or {})}
        def takes(ptr):                              # the rotation from ptr: first free, non-excluded of eax/ecx/edx
            for k in range(3):
                r = (ptr - 1 + k) % 3 + 1
                if r not in busy and r not in p.get('excl', []): return r
        for r in (1, 2, 3):
            if r == p['ptr'] or takes(r) == p.get('reg'): continue   # same register, same pointer after: same object
            exps.append(dict(spec=[dict(kind='rot', tid=p['tid'], occ=p['nocc'], reg=r)],
                             what='rotation pointer %s before %s (was %s, took %s)' % (REGNAME[r], tname(p), REGNAME[p['ptr']],
                                                                                     REGNAME.get(p.get('reg'), p.get('reg')))))
    return exps


def pick_experiments(picks, lines):
    """every pick given each other free, allowed register (as a preference pick; a rotation pick also with the
    pointer moved past the new register)"""
    exps = []
    for p in picks:
        if lines and not (p.get('line') and lines[0] <= p['line'] <= lines[1]): continue
        busy = {int(k) for k in (p.get('occ') or {}) if isinstance(p.get('occ'), dict)}
        for r in (1, 2, 3, 7, 8, 4):
            if r == p.get('reg') or r in busy or r in p.get('excl', []): continue
            if p.get('byte') and r >= 5: continue
            for rot in ((False, True) if 'rotate' in p['path'] and r in (1, 2, 3) else (False,)):
                o = dict(kind='pick', tid=p['tid'], occ=p['nocc'], reg=r)
                if rot: o['rot'] = True
                exps.append(dict(spec=[o], what='%s -> %s%s (was %s by %s)' % (tname(p), REGNAME[r], ' moving the pointer' if rot else '',
                                                                              REGNAME.get(p.get('reg'), p.get('reg')), '/'.join(p['path']) or '?')))
    return exps


def record_rg(T, func):
    _, evs, out, _ = gdb_compile(T.src, list(T.flags), 'c2force_gdb.py',
                                 dict(C2FORCE_OUT='@EVENTS', C2FORCE_FUNC=func, C2FORCE_SPEC='[]', C2FORCE_RGREC='1'), tag='rec')
    return [e for e in evs if e['ev'] == 'rg']


def rg_experiments(rgs, lines):
    """in every region-builder call, every block that shares its region with another block starts a new one
    (predecessor join refused; then also the successor join)"""
    exps = []
    for g in rgs:
        cnt = collections.Counter(r['rid'] for r in g['rows'])
        for r in g['rows']:
            if not r['rid'] or cnt[r['rid']] < 2: continue    # region 0: cut inside the block, no join to refuse
            if lines and not (r.get('line') and lines[0] <= r['line'] <= lines[1]): continue
            for what in ('nopred', 'both'):
                exps.append(dict(spec=[dict(kind='rg', call=g['call'], blk=r['blk'], what=what)],
                                 what='region call %d block %d (L%s, region %d) %s' % (g['call'], r['blk'], r.get('line'), r['rid'],
                                                                                      'new region' if what == 'both' else 'no predecessor join')))
    return exps


def record_slots(T, func):
    _, evs, out, _ = gdb_compile(T.src, list(T.flags), 'c2slots_gdb.py', dict(C2SLOTS_OUT='@EVENTS', C2SLOTS_FUNC=func), tag='rec')
    packed = [e for e in evs if e['ev'] == 'packed']; final = [e for e in evs if e['ev'] == 'final']
    if not final: return None
    return dict(packed=packed[-1]['slots'] if packed else None, final=final[-1]['slots'], lo=final[-1]['lo'],
                size=packed[-1]['packed_size'] if packed else None)


def slot_experiments(sl, steps):
    """adjacent final slots swapped, and (frames that are sorted) each slot's weight moved by +/-1..K"""
    if not sl: return []
    exps = []; fin = sl['final']; lo = sl['lo']
    lab = lambda s: '+'.join(m.lstrip('_') for m in s['members'][:3]) + ('...' if len(s['members']) > 3 else '')
    for i in range(lo, len(fin) - 1):
        exps.append(dict(spec=[dict(kind='slotswap', a=i, b=i + 1)],
                         what='slots %d/%d swapped (%s <-> %s)' % (i, i + 1, lab(fin[i]), lab(fin[i + 1]))))
    if sl.get('size') and sl['size'] > 0x80 and sl.get('packed'):
        for i in range(lo, len(sl['packed'])):
            for d in [k for j in range(1, steps + 1) for k in (j, -j)]:
                exps.append(dict(spec=[dict(kind='slotw', slot=i, delta=d)],
                                 what='packed slot %d (%s, weight %d) %+d' % (i, lab(sl['packed'][i]), sl['packed'][i]['weight'], d)))
    return exps


def skip_experiments(T, func, fns, nmax, fixed=(), lines=None):
    """skip each call made for the target at the direct call sites of the routines `fns` (default: the per-function
    pipeline calls), one call at a time"""
    import c2sched
    if fns is None:
        sites = [(ret - 5, ret, callee) for callee, ret in c2sched.PIPELINE]
    else:
        sites = [x for fn in fns for x in c2calls(fn)]
    sites = [x for x in sites if x[2] not in SKIP_NEVER]
    _, evs, out, _ = gdb_compile(T.src, list(T.flags), 'c2force_gdb.py',
                                 dict(C2FORCE_OUT='@EVENTS', C2FORCE_FUNC=func, C2FORCE_SPEC=json.dumps(list(fixed)),
                                      C2FORCE_SKIPREC=json.dumps(sorted({x[0] for x in sites}))), tag='rec')
    counts = {}; lns = {}
    for e in evs:
        if e['ev'] == 'srec':
            counts = {int(k): v for k, v in e['counts'].items()}
            lns = {int(k): v for k, v in (e.get('lines') or {}).items()}
    print('skip sweep: %d call sites in %s, %d reached for the target (%d calls)' % (
        len(sites), 'the pipeline' if fns is None else ', '.join('0x%x' % f for f in fns), len(counts), sum(counts.values())))
    exps = []
    for site, ret, callee in sites:
        k = 0
        if counts.get(site, 0) > 1 and not lines:  # every call at the site too: a step that a later iteration
            nm = c2sched.PASSNAME.get(callee, '')  # redoes can only be seen skipped as a whole
            exps.append(dict(spec=[dict(kind='skip', fn=callee, n=0, ret=0, pop=c2pop(callee), **{'from': ret})],
                             what='skip every call (%d) of 0x%x at 0x%x%s' % (counts[site], callee, site, (' (' + nm + ')') if nm else '')))
        for n in range(1, counts.get(site, 0) + 1):
            ln = (lns.get(site) or [])[n - 1] if n <= len(lns.get(site) or []) else None
            if lines and not (ln and lines[0] <= ln <= lines[1]): continue
            k += 1
            if k > nmax: break
            nm = c2sched.PASSNAME.get(callee, '')
            exps.append(dict(spec=[dict(kind='skip', fn=callee, n=n, ret=0, pop=c2pop(callee), **{'from': ret})],
                             what='skip call %d of 0x%x at 0x%x%s%s' % (n, callee, site, (' L%s' % ln) if ln else '',
                                                                         (' (' + nm + ')') if nm else '')))
    return exps


# never skipped by a sweep: the pass the spin copy and every hook depend on, and the allocator / assigner themselves
SKIP_NEVER = {0x10b0cf40, 0x10bda210, 0x10c5ba80}


def order_of(cands):
    return [c['id'] for c in sorted(cands, key=lambda c: (-c['prio'], -c['key']))]


def prio_experiments(rounds, steps, raw_deltas, round_filter, only):
    exps = []
    for rn, r in enumerate(rounds, 1):
        if round_filter and rn not in round_filter: continue
        cands = [c for c in r['cands'] if c['refs'] > 0]
        if only: cands_t = [c for c in cands if r['labels'][c['id']].split('(')[0] in only or str(c['id']) in only]
        else: cands_t = cands
        base = tuple(order_of(cands)); seen = {base}
        byid = {c['id']: c for c in cands}
        for c in cands_t:
            pos = base.index(c['id'])
            deltas = []
            if raw_deltas:
                deltas = [d for k in range(1, steps + 1) for d in (k, -k)]
            else:
                for j in range(1, steps + 1):
                    if pos - j >= 0:
                        y = byid[base[pos - j]]
                        deltas.append(y['prio'] - c['prio'] + (0 if c['key'] > y['key'] else 1))
                    if pos + j < len(base):
                        y = byid[base[pos + j]]
                        deltas.append(y['prio'] - c['prio'] - (0 if c['key'] < y['key'] else 1))
            for d in deltas:
                if d == 0: continue
                trial = [dict(x) for x in cands]
                for x in trial:
                    if x['id'] == c['id']: x['prio'] += d
                o = tuple(order_of(trial))
                if o in seen: continue
                seen.add(o)
                exps.append(dict(spec=[dict(kind='prio', cls=r['cls'], round=rn, id=c['id'], delta=d)],
                                 what='round %d %s %+d' % (rn, r['labels'][c['id']], d),
                                 note='now after %s' % (r['labels'][o[o.index(c['id']) - 1]] if o.index(c['id']) else '(top)')))
    return exps


def reg_experiments(rounds, round_filter, only):
    """every coloured web of every round, forced to each other register its allowed set has, and to memory"""
    exps = []
    for rn, r in enumerate(rounds, 1):
        if round_filter and rn not in round_filter: continue
        for cid, pk in r['picks'].items():
            lab = r['labels'].get(cid, str(cid))
            if only and lab.split('(')[0] not in only and str(cid) not in only: continue
            for rg in pk['allowed']:
                if rg == pk['chosen'] or rg not in REGNAME: continue
                exps.append(dict(spec=[dict(kind='reg', cls=r['cls'], round=rn, id=cid, reg=rg)],
                                 what='round %d %s -> %s (was %s)' % (rn, lab, REGNAME[rg], REGNAME.get(pk['chosen'], pk['chosen']))))
            exps.append(dict(spec=[dict(kind='mem', cls=r['cls'], round=rn, id=cid)],
                             what='round %d %s -> not coloured (was %s)' % (rn, lab, REGNAME.get(pk['chosen'], pk['chosen']))))
    return exps


def sw_experiments(rounds, round_filter, only):
    """every web whose pop took the failed-pop path (spill weight <= 0: split / memory without a colour try) given a
    spill weight of 1 at that pop, so the colour step tries it"""
    exps = []
    for rn, r in enumerate(rounds, 1):
        if round_filter and rn not in round_filter: continue
        for cid, paths in r['paths'].items():
            if 'd690' not in paths: continue
            lab = r['labels'].get(cid, str(cid))
            if only and lab.split('(')[0] not in only and str(cid) not in only: continue
            exps.append(dict(spec=[dict(kind='sw', cls=r['cls'], round=rn, id=cid, weight=1)],
                             what='round %d %s spill weight -> 1 (failed pop)' % (rn, lab)))
    return exps


def sched_experiments(regions, region_filter, lines, maxd):
    import c2sched
    labs = c2sched.Labels()
    exps = []; seen = set()
    for g in regions:
        if region_filter and g['n'] not in region_filter: continue
        nodes = {n['id']: n for n in (g['dag'] or {}).get('nodes', [])}
        def lab(i):
            n = nodes.get(i)
            return ('n%d %s L%s' % (i, c2sched.rtext(n['row'], labs), n['row'].get('line'))) if n and n.get('row') else 'n%d' % i
        if lines:
            ls = [n['row'].get('line') for n in nodes.values() if n.get('row') and n['row'].get('line')]
            if not any(lines[0] <= l <= lines[1] for l in ls): continue
        for cyc in g['cycles']:
            picks = [t for t in cyc['tries'] if t['ev'] == 'pick']
            if not picks: continue
            ready = cyc['ready']; prio = {i: p for i, p, _ in ready}
            for pk in picks:
                P = pk['id']
                if P not in prio: continue
                for i, p, early in ready:
                    if i == P or early > cyc['cyc']: continue
                    # the loser must come before P in the ready order: higher priority, or equal and lower number
                    if p > prio[P] or (p == prio[P] and i < P): continue
                    d = prio[P] - p + (1 if i > P else 0)
                    if d > maxd: continue
                    for node, dd, why in ((i, d, 'wins cycle %d over %s' % (cyc['cyc'], lab(P))),
                                          (P, -d, 'loses cycle %d to %s' % (cyc['cyc'], lab(i)))):
                        key = (g['n'], node, dd)
                        if key in seen: continue
                        seen.add(key)
                        exps.append(dict(spec=[dict(kind='sched', region=g['n'], node=node, delta=dd)],
                                         what='region %d %s %+d' % (g['n'], lab(node), dd), note=why))
    return exps


def jump_experiments(T, func, fixed=()):
    r = forced_result(T, func, list(fixed), record=True)
    exps = []
    for e in r['events']:
        if e['ev'] != 'jchange': continue
        callee = dict(JCALLS).get(e['site'])
        nm = JNAME.get(callee, 'transform 0x%x' % callee if callee else '?').split(':')[0]
        exps.append(dict(spec=[dict(kind='jskip', site=e['site'], n=e['n'])],
                         what='skip %s (site 0x%x call %d, mode %s sweep %s, L%s)' % (nm, e['site'], e['n'], e['mode'], e['sweep'], e['line'])))
    return exps


def omatched(r):
    """indices of the original's instruction lines that the aligned diff pairs with an equal line of ours"""
    out = set()
    for tag, i1, i2, j1, j2 in r.get('_ops') or ():
        if tag == 'equal': out.update(range(j1, j2))
    return out


def gain_loss(r, base):
    """(residue lines of the baseline this result fixes, baseline-equal lines it breaks), on the original's lines"""
    if r.get('omatch') is None or base.get('omatch') is None: return (0, 0)
    m, b = set(r['omatch']), set(base['omatch'])
    return (len(m - b), len(b - m))


def run_experiments(T, func, exps, jobs, base, fixed=()):
    res = []
    if 'omatch' not in base and '_ops' in base: base['omatch'] = sorted(omatched(base))
    def one(x):
        r = forced_result(T, func, list(fixed) + x['spec'])
        r.pop('_obj', None)
        if '_ops' in r: r['omatch'] = sorted(omatched(r))
        return x, r
    with cf.ThreadPoolExecutor(max_workers=jobs) as ex:
        for n, (x, r) in enumerate(ex.map(one, exps), 1):
            r['same_as_base'] = r.get('sha') == base.get('sha')
            r['gain'], r['loss'] = gain_loss(r, base)
            res.append((x, r))
            mark = '=' if r.get('status') in EQUAL else ('.' if r['same_as_base'] else '*')
            sys.stderr.write(mark + ('\n' if n % 80 == 0 else '')); sys.stderr.flush()
    sys.stderr.write('\n')
    return res


def parse_override(kind, s):
    p = s.split(':')
    web = lambda w: dict(id=int(w)) if re.fullmatch(r'\d+', w) else dict(name=w)
    if kind == 'prio': return dict(kind='prio', cls=0, round=int(p[0]), delta=int(p[2]), **web(p[1]))
    if kind == 'reg': return dict(kind='reg', cls=0, round=int(p[0]), reg=REGNUM[p[2].lower()], **web(p[1]))
    if kind == 'mem': return dict(kind='mem', cls=0, round=int(p[0]), **web(p[1]))
    if kind == 'sw': return dict(kind='sw', cls=0, round=int(p[0]), weight=int(p[2]) if len(p) > 2 else 1, **web(p[1]))
    if kind == 'sched': return dict(kind='sched', region=int(p[0]), node=int(p[1]), delta=int(p[2]))
    if kind == 'jskip': return dict(kind='jskip', site=int(p[0], 16), n=int(p[1]))
    if kind in ('rot', 'pick'):
        t, _, occ = p[0].lstrip('Tt').partition('/')
        o = dict(kind=kind, tid=int(t), occ=int(occ) if occ else 1, reg=REGNUM[p[1].lower()])
        if kind == 'pick' and 'rot' in p[2:]: o['rot'] = True
        if kind == 'pick' and 'force' in p[2:]: o['force'] = True
        return o
    if kind == 'skip':
        a, _, v = s.partition('=')
        q = a.split(':')
        return skip_spec(int(q[0], 16), int(q[1]) if len(q) > 1 else 1, int(v, 0) if v else 0)
    if kind == 'rg':
        return dict(kind='rg', call=int(p[0]), blk=int(p[1]), what=p[2] if len(p) > 2 else 'nopred')
    if kind == 'slotw':
        return dict(kind='slotw', delta=int(p[1]), **slotref('slot', p[0]))
    if kind == 'slotswap':
        a, b = s.split(',')
        return dict(kind='slotswap', a=slotref('a', a)['a'], b=slotref('b', b)['b'])


def spec_arg(o):
    """the command-line form of one override (for the greedy chain's summary)"""
    k = o['kind']; w = lambda: str(o['id']) if o.get('id') is not None else o.get('name')
    if k == 'prio': return '--prio %d:%s:%+d' % (o['round'], w(), o['delta'])
    if k == 'reg': return '--reg %d:%s:%s' % (o['round'], w(), REGNAME.get(o['reg'], o['reg']))
    if k == 'mem': return '--mem %d:%s' % (o['round'], w())
    if k == 'sw': return '--sw %d:%s:%d' % (o['round'], w(), o.get('weight', 1))
    if k == 'sched': return '--sched %d:%d:%+d' % (o['region'], o['node'], o['delta'])
    if k == 'jskip': return '--jskip 0x%x:%d' % (o['site'], o['n'])
    if k == 'rot': return '--rot T%d/%d:%s' % (o['tid'], o.get('occ', 1), REGNAME[o['reg']])
    if k == 'pick': return '--pick T%d/%d:%s%s' % (o['tid'], o.get('occ', 1), REGNAME[o['reg']], ':rot' if o.get('rot') else '')
    if k == 'skip': return '--skip 0x%x:%d' % ((o['from'] - 5) if o.get('from') else o['fn'], o['n'])
    if k == 'rg': return '--rg %d:%d:%s' % (o['call'], o['blk'], o['what'])
    if k == 'slotw': return '--slotw %s:%+d' % (o.get('slot', o.get('home')), o['delta'])
    if k == 'slotswap': return '--slotswap %s,%s' % (o['a'], o['b'])
    return json.dumps(o)


def slotref(key, x):
    return {key: int(x)} if re.fullmatch(r'\d+', x) else {key: x}


# ---- TOOL-C2X: static reading of c2.dll for the skip override (call sites, callees, argument bytes) ----------------
_C2 = {}
def c2img():
    if not _C2:
        import capstone, pefile
        pe = pefile.PE(os.path.join(TC, 'c2.dll'), fast_load=True)
        _C2.update(img=pe.get_memory_mapped_image(), base=pe.OPTIONAL_HEADER.ImageBase,
                   md=capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32))
    return _C2


def c2ins(a):
    c = c2img()
    return next(c['md'].disasm(c['img'][a - c['base']:a - c['base'] + 16], a), None)


def c2body(a, maxn=20000):
    """the instructions of the c2.dll routine at a, by recursive descent over its branches"""
    seen = {}; todo = [a]
    while todo and len(seen) < maxn:
        p = todo.pop()
        while p not in seen:
            ins = c2ins(p)
            if ins is None: break
            seen[p] = ins
            if ins.mnemonic.startswith('j'):
                try: todo.append(int(ins.op_str, 16))
                except ValueError: pass
                if ins.mnemonic == 'jmp': break
            if ins.mnemonic in ('ret', 'int3'): break
            p += ins.size
    return seen


def c2pop(fn):
    """argument bytes the routine pops (its `ret N`; 0 for a caller-cleaned one)"""
    b = c2body(fn)
    for p in sorted(b):
        if b[p].mnemonic == 'ret': return int(b[p].op_str, 16) if b[p].op_str else 0
    return 0


def c2calls(fn):
    """(call site, return address, callee) of every direct call in the routine"""
    out = []
    for p, ins in sorted(c2body(fn).items()):
        if ins.mnemonic == 'call':
            try: out.append((p, p + ins.size, int(ins.op_str, 16)))
            except ValueError: pass
    return out


def skip_spec(addr, n=1, ret=0):
    """--skip ADDR: a routine entry (every caller) or a `call` instruction (that call site only)"""
    ins = c2ins(addr); frm = None
    if ins is not None and ins.mnemonic == 'call':
        frm = addr + ins.size; addr = int(ins.op_str, 16)
    return dict(kind='skip', fn=addr, n=n, ret=ret, pop=c2pop(addr), **({'from': frm} if frm else {}))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('va'); ap.add_argument('source')
    for k in OVERRIDES:
        ap.add_argument('--' + k, action='append', default=[])
    ap.add_argument('--sweep', type=sweep_kinds, help='prio|reg|sw|sched|jump|all|pairs, or (lane TOOL-C2X) rot|pick|skip|rg|slot|new; a comma list is accepted')
    ap.add_argument('--early', action='store_true', help='force-include a prelude function compiled first, so the passes '
                    'before the target\'s colouring are hooked (automatic with --skip and the skip sweep)')
    ap.add_argument('--in', dest='inside', help='skip sweep: sweep the direct call sites of these c2.dll routines (comma list of '
                    'hex addresses; default: the per-function pipeline calls of c2sched.PIPELINE)')
    ap.add_argument('--timeout', type=int, help='seconds one forced compile may run (default 180; 40 in a skip sweep)')
    ap.add_argument('--greedy', type=int, help='single sweep: keep the best closer override and sweep again on top, up to N times')
    ap.add_argument('--skip-max', type=int, default=12, help='skip sweep: calls tried per call site (default 12)')
    ap.add_argument('--slot-steps', type=int, default=2, help='slot sweep: raw weight deltas +/-1..K per slot (default 2)')
    ap.add_argument('--pairs', dest='sweep', action='store_const', const='pairs', help='same as --sweep pairs')
    ap.add_argument('--pair-of', type=sweep_kinds, default='all',
                    help='pair sweep: the single sweep whose overrides are paired (default all)')
    ap.add_argument('--singles', help='pair sweep: take the single overrides from this earlier --json sweep of the same source')
    ap.add_argument('--steps', type=int, default=2, help='prio sweep: move each web up / down by 1..K places (or +/-1..K with --deltas)')
    ap.add_argument('--deltas', action='store_true', help='prio sweep: raw deltas +/-1..K instead of place moves')
    ap.add_argument('--rounds', help='prio / reg sweep: only these rounds (comma list)')
    ap.add_argument('--only', help='prio / reg sweep: only these webs (labels or ids)')
    ap.add_argument('--regions', help='sched sweep: only these regions')
    ap.add_argument('--lines', help='sched sweep: only regions with an instruction in source lines A-B')
    ap.add_argument('--sched-max', type=int, default=2048, help='sched sweep: largest priority change tried')
    ap.add_argument('--class', dest='cls', type=int, default=0)
    ap.add_argument('--jobs', type=int, default=1, help='parallel forced compiles (default 1; each is a wine cl plus gdb, keep it at 1 on a small machine)')
    ap.add_argument('--top', type=int, help='closest results listed (default 25); with --sweep pairs, the number of single overrides paired (default 12)')
    ap.add_argument('--json', help='write every sweep result here')
    ap.add_argument('--diff', action='store_true'); ap.add_argument('--keep', action='store_true')
    ap.add_argument('--validate', action='store_true', help='no-op override vs the pinned compiler, section by section')
    ap.add_argument('--func', help='decorated-name fragment of the target (default: the symbol the checker finds)')
    a = ap.parse_args()
    va = int(a.va, 16)
    src = open(a.source, encoding='latin-1', newline='').read()
    T = Target(va, src)
    JPOPS.update(jsite_pops())
    kinds0 = set((a.pair_of if a.sweep == 'pairs' else a.sweep or '').split(','))
    if a.early or a.skip or 'skip' in kinds0 or 'new' in kinds0: EARLY[0] = True
    if a.timeout: globals()['GDB_TIMEOUT'] = a.timeout
    elif 'skip' in kinds0 or 'new' in kinds0: globals()['GDB_TIMEOUT'] = 40   # a skipped pass that loops is not worth 3 min

    base = forced_result(T, a.func or '#no-function#', [])      # the plain compile under gdb (no override, no filter hit)
    if base.get('status') in ('COMPILE_ERROR', 'NO_MARKER', 'NO_SYMBOL'):
        sys.exit('baseline: %s %s' % (base['status'], base.get('err')))
    func = a.func or base['symbol']
    print('target %s  symbol %s  flags %s' % (a.va, func, ' '.join(T.flags[11:]) or '(profile)'))
    print('baseline (no override):', fig(base))

    if a.validate:
        pin = pinned_object(T)
        # every hook installed, every override a no-op: delta 0 on every round-1 web and on scheduler node 1 of every
        # region seen, a jump skip that never comes due, and the jump recorder on
        noop = forced_result(T, func, [dict(kind='prio', cls=0, round=1, name=None, id=i, delta=0) for i in range(1, 400)] +
                             [dict(kind='sched', region=g, node=1, delta=0) for g in range(1, 60)] +
                             [dict(kind='jskip', site=s, n=10 ** 9) for s, _ in JCALLS], record=True)
        same = code_sections(pin) == code_sections(base['_obj']) == code_sections(noop['_obj'])
        print('no-op overrides applied (hooks reached the function): %d; jump changes recorded: %d' % (
            len(noop['applied']), sum(1 for e in noop['events'] if e['ev'] == 'jchange')))
        print('pinned compiler      :', fig(T.compare(pin) | dict(claimed=T.length)))
        print('forced, no-op spec   :', fig(noop), ' issues:', len([i for i in noop['issues'] if i['ev'] != 'miss']))
        print('non-debug sections and relocations identical (pinned / gdb baseline / no-op override):', 'YES' if same else 'NO')
        # lane TOOL-C2X: the new hooks, every one installed and none coming due, with the prelude compiled first
        import c2sched
        noop2 = [dict(kind='rot', tid=-1, occ=1, reg=1), dict(kind='pick', tid=-1, occ=1, reg=1),
                 dict(kind='rg', call=10 ** 9, blk=0, what='both'), dict(kind='slotw', slot=0, delta=0)] + \
                [dict(kind='skip', fn=c, n=10 ** 9, ret=0, pop=0) for c in sorted({c for c, _ in c2sched.PIPELINE} - SKIP_NEVER)]
        EARLY[0] = True
        eb = forced_result(T, func, [])
        en = forced_result(T, func, noop2)
        EARLY[0] = False
        print('with the prelude (--early): plain %s, new-kind no-op hooks %s (%d applied); target body and relocations '
              'identical to the baseline: %s' % (fig(eb), fig(en), len(en['applied']),
                                                 'YES' if eb.get('sha') == en.get('sha') == base.get('sha') and
                                                 eb.get('status') == en.get('status') == base.get('status') else 'NO'))
        return

    spec = [parse_override(k, s) for k in OVERRIDES for s in getattr(a, k)]
    if spec and a.sweep:
        # a sweep on top of fixed overrides: every experiment is the fixed list plus one more override, and the
        # baseline the sweep is ranked against is the fixed list alone
        base = forced_result(T, func, spec)
        print('fixed overrides:', '; '.join('%s' % {k: v for k, v in o.items() if k != 'cls'} for o in spec))
        print('baseline with them:', fig(base))
        if any(o['kind'] != 'jskip' for o in spec) and a.sweep != 'jump':
            print('note: the allocator / scheduler tables the sweep starts from are recorded without the fixed overrides;'
                  ' a round or region after the one they change may be numbered or shaped differently under them')
    elif spec:
        r = forced_result(T, func, spec, keep=a.keep)
        for e in r.get('applied', []): print('applied:', {k: v for k, v in e.items() if k != 'ev'})
        for e in r.get('issues', []): print('NOT applied:', {k: v for k, v in e.items() if k != 'ev'})
        print('forced  :', fig(r), '(same object as baseline)' if r.get('sha') == base.get('sha') else '')
        if a.keep and r.get('work'): print('kept:', r['work'])
        if a.diff and 'unmasked' in r: print_diff(r)
        return

    if not a.sweep:
        if a.diff: print_diff(base)
        return
    base['omatch'] = sorted(omatched(base))
    rf = set(map(int, a.rounds.split(','))) if a.rounds else None
    only = set(a.only.split(',')) if a.only else None
    kind = a.pair_of if a.sweep == 'pairs' else a.sweep
    kinds = set(kind.split(','))
    if 'all' in kinds: kinds |= {'prio', 'reg', 'sw', 'sched', 'jump'}
    if 'new' in kinds: kinds |= {'rot', 'pick', 'rg', 'slot', 'skip'}
    jf = open(a.json, 'w') if a.json else None
    def dump(res, stage):
        if not jf: return
        for x, r in res:
            jf.write(json.dumps(dict(stage=stage, what=x['what'], note=x.get('note'), spec=x['spec'],
                                     **{k: v for k, v in r.items() if not k.startswith('_') and k != 'events'})) + '\n')
        jf.flush()

    if a.sweep == 'pairs' and a.singles:
        res = read_singles(a.singles, base)
        print('single overrides read from %s: %d' % (a.singles, len(res)))
    else:
        exps = []
        if kinds & {'prio', 'reg', 'sw'}:
            rounds = record_alloc(T, func, a.cls)
            print('allocation rounds (class %d): %d' % (a.cls, len(rounds)))
            if 'prio' in kinds: exps += prio_experiments(rounds, a.steps, a.deltas, rf, only)
            if 'reg' in kinds: exps += reg_experiments(rounds, rf, only)
            if 'sw' in kinds: exps += sw_experiments(rounds, rf, only)
        ln = tuple(map(int, a.lines.split('-'))) if a.lines else None
        if kinds & {'rot', 'pick'}:
            picks = record_picks(T, func)
            print('local-assigner picks: %d (%d by rotation)' % (len(picks), sum(1 for p in picks if 'rotate' in p['path'])))
            if 'rot' in kinds: exps += rot_experiments(picks, ln)
            if 'pick' in kinds: exps += pick_experiments(picks, ln)
        if 'rg' in kinds:
            rgs = record_rg(T, func)
            print('region-builder calls: %d' % len(rgs))
            exps += rg_experiments(rgs, ln)
        if 'slot' in kinds:
            sl = record_slots(T, func)
            print('frame slots: %d' % (len(sl['final']) if sl else 0))
            exps += slot_experiments(sl, a.slot_steps)
        if 'skip' in kinds:
            fns = [int(x, 16) for x in a.inside.split(',')] if a.inside else None
            exps += skip_experiments(T, func, fns, a.skip_max, spec, ln)
        if kinds & {'sched'}:
            regs = record_sched(T, func)
            gf = set(map(int, a.regions.split(','))) if a.regions else None
            ln = tuple(map(int, a.lines.split('-'))) if a.lines else None
            print('scheduler regions: %d' % len(regs))
            exps += sched_experiments(regs, gf, ln, a.sched_max)
        if 'jump' in kinds:
            exps += jump_experiments(T, func, spec)
        print('experiments: %d (jobs %d)' % (len(exps), a.jobs))
        t0 = time.time()
        res = run_experiments(T, func, exps, a.jobs, base, spec)
        print('done in %.0f s' % (time.time() - t0))
        dump(res, 'single')
    res.sort(key=lambda xr: rank(xr[1]))
    report(res, base, 'a single override', a.top or 25)
    if a.sweep != 'pairs' and a.greedy and not a.singles:
        # lane TOOL-C2X: greedy chain. Keep the best closer override, run the same experiments again on top of it, and
        # repeat; for residues made of several independent decisions (frame slots, one skip plus slots). The
        # experiments are those of the first recording; an index that a kept override renumbers is tried as it stands.
        chain = list(spec)
        for step in range(1, a.greedy + 1):
            bl = rank(base)
            best = [xr for xr in res if xr[1].get('applied') and (rank(xr[1]) < bl or xr[1].get('status') in EQUAL)]
            if not best: print('\ngreedy: nothing closer at step %d; chain ends' % step); break
            x, r = best[0]; chain += x['spec']
            print('\ngreedy step %d: keep %s -> %s' % (step, x['what'], fig(r)))
            if r.get('status') in EQUAL: print('greedy: EQUAL with the chain:', '; '.join(json.dumps(o) for o in chain)); break
            base = forced_result(T, func, chain); base.pop('_obj', None); base['omatch'] = sorted(omatched(base))
            done = {json.dumps(o, sort_keys=True) for o in chain}
            exps2 = [e for e in exps if not any(json.dumps(o, sort_keys=True) in done for o in e['spec'])
                     and not ({decision(o) for o in e['spec']} & {decision(o) for o in chain})]
            res = run_experiments(T, func, exps2, a.jobs, base, chain)
            dump(res, 'greedy%d' % step)
            res.sort(key=lambda xr: rank(xr[1]))
        print('greedy chain:', ' '.join(spec_arg(o) for o in chain))
    if a.sweep != 'pairs':
        if jf: jf.close()
        return

    # ---- pairs: the N single overrides that fix the most residue lines (then the closest), every pair of them -----
    pool = pair_pool(res, a.top or 12)
    print('\npair pool (top %d distinct single overrides; fixes / breaks = original lines the baseline gets wrong / right):' % len(pool))
    for k, (x, r) in enumerate(pool, 1):
        print('  %2d %-58s fixes %2d breaks %2d  %s%s' % (k, x['what'], r.get('gain', 0), r.get('loss', 0), fig(r),
                                                          ('  (= ' + '; '.join(x['same'][:3]) + ')') if x.get('same') else ''))
    pexps = pair_experiments(pool)
    print('pairs: %d (jobs %d)' % (len(pexps), a.jobs))
    t0 = time.time()
    pres = run_experiments(T, func, pexps, a.jobs, base, spec)
    print('done in %.0f s' % (time.time() - t0))
    dump(pres, 'pair')
    if jf: jf.close()
    pres.sort(key=lambda xr: rank(xr[1]))
    report(pres, base, 'a pair of overrides', 25, pair=True)


def report(res, base, what, top, pair=False):
    eq = [xr for xr in res if xr[1].get('status') in EQUAL]
    print('\nEQUAL under %s: %d' % (what, len(eq)))
    for x, r in eq: print('  %-60s %s  %s' % (x['what'], r['status'], x.get('note') or ''))
    bl = rank(base)
    better = [xr for xr in res if rank(xr[1]) < bl and xr[1].get('status') not in EQUAL]
    print('\ncloser than the baseline (%s): %d' % (fig(base), len(better)))
    for x, r in better[:top]:
        extra = ''
        if pair:   # a pair that beats both of its members is a joint decision, not one member doing the work
            extra = '  [%s]' % ('beats both' if all(rank(r) < m for m in x['members']) else 'no better than a member')
        print('  %-60s %s%s  %s' % (x['what'], fig(r), extra, x.get('note') or ''))
    if pair and not better and not eq:
        print('closest pairs:')
        for x, r in [xr for xr in res if not xr[1].get('same_as_base')][:top]:
            print('  %-60s %s  fixes %d breaks %d' % (x['what'], fig(r), r.get('gain', 0), r.get('loss', 0)))
    nochange = sum(1 for _, r in res if r.get('same_as_base'))
    notapplied = [x['what'] for x, r in res if not r.get('applied')]
    print('\nsame object as the baseline: %d of %d; overrides never applied: %d%s' % (
        nochange, len(res), len(notapplied), (' (' + '; '.join(notapplied[:5]) + ')') if notapplied else ''))


def read_singles(path, base):
    """the single overrides of an earlier `--json` sweep of the same source (records without a stage are singles)"""
    res = []
    for l in open(path):
        if not l.strip(): continue
        d = json.loads(l)
        if d.get('stage', 'single') != 'single': continue
        x = dict(what=d.pop('what'), note=d.pop('note', None), spec=d.pop('spec'))
        d.pop('stage', None)
        if 'gain' not in d: d['gain'], d['loss'] = gain_loss(d, base)
        res.append((x, d))
    return res


def decision(o):
    """what one override decides: overrides of the same web in the same round (or node in a region, or jump change)
    are the same decision and never make a pair"""
    if o['kind'] in ('prio', 'reg', 'mem', 'sw'): return ('alloc', o.get('cls', 0), o['round'], o.get('id') if o.get('id') is not None else o.get('name'))
    if o['kind'] == 'sched': return ('sched', o['region'], o['node'])
    if o['kind'] in ('rot', 'pick'): return ('ra', o['tid'], o.get('occ', 1))
    if o['kind'] == 'skip': return ('skip', o['fn'], o.get('from'), o['n'])
    if o['kind'] == 'rg': return ('rg', o['call'], o['blk'])
    if o['kind'] in ('slotw', 'slotswap'): return ('slot', str(o.get('slot', o.get('home', o.get('a')))))
    return ('jump', o['site'], o['n'])


def pair_pool(res, n):
    """the single overrides worth pairing: applied, changed the object, compiled; ranked by how many of the baseline's
    residue lines they fix (a needed half of a pair often fixes its part and breaks something the other half
    repairs, so it ranks low on closeness alone), then by closeness; one per resulting object (equivalent overrides
    are listed with it; at most two variants of one decision)"""
    ok = [(x, r) for x, r in res if r.get('applied') and not r.get('same_as_base') and 'unmasked' in r]
    ok.sort(key=lambda xr: (-xr[1].get('gain', 0), rank(xr[1]), xr[1].get('loss', 0)))
    pool = []; bysha = {}; perdec = collections.Counter()
    for x, r in ok:
        if r.get('sha') in bysha:
            bysha[r['sha']][0].setdefault('same', []).append(x['what']); continue
        dk = frozenset(decision(o) for o in x['spec'])
        if len(pool) >= n or perdec[dk] >= 2: continue     # two variants of one decision at most (they never pair)
        perdec[dk] += 1
        x = dict(x); bysha[r.get('sha')] = (x, r); pool.append((x, r))
    return pool


def pair_experiments(pool):
    exps = []
    for i in range(len(pool)):
        for j in range(i + 1, len(pool)):
            (x, r), (y, q) = pool[i], pool[j]
            if {decision(o) for o in x['spec']} & {decision(o) for o in y['spec']}: continue
            exps.append(dict(spec=x['spec'] + y['spec'], what='%s & %s' % (x['what'], y['what']),
                             members=(rank(r), rank(q)), note='pool %d + %d' % (i + 1, j + 1)))
    return exps

if __name__ == '__main__':
    main()
