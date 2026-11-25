#!/usr/bin/env python3
"""c2layout.py - watch what the pinned MSVC 2005 SP1 back end (c2.dll 14.00.50727.762) does to one function's block
stream in its two late control-flow passes: the jump optimiser (tail merging, cross-jumping, branch chaining) and the
late block layout (blocks pulled behind jumps, short tails copied into jump sites), and the order at code emission.
Owner-side diagnostic; see README.md ("c2layout").

usage: c2layout.py SOURCE --func NAME|0xVA [--flags "/GS- ..."] [--ob1] [--steps] [--raw] [--verify]
                   [--timeout S] [--json OUT] [--events FILE] [--keep]

Report:
  1. the stream before the late passes: blocks in stream order (a block = label .. branch / return), with source
     lines, instruction count and terminator.
  2. FLOW pass (after register allocation; it runs twice): every transform call that changed the stream, in order,
     with its subject line and its effect (instructions cut, blocks removed, branches retargeted, order changed).
  3. LAYOUT pass: for every unconditional jump the decision (target tail copied / target block moved behind the jump /
     kept, and why), and the changes.
  4. the final order at code emission, aligned with the object's own disassembly (block offsets, loop heads and their
     offset mod 16, alignment pads).
Lines are file lines of SOURCE (inlined code carries the call's line). --steps prints the block list after every
change; --raw prints the raw tuple streams.
"""
import argparse, glob, json, os, re, shutil, signal, subprocess, sys, tempfile, time

HERE = os.path.dirname(os.path.abspath(__file__))
LIB = os.environ.get('C2DIAG_LIB', HERE)           # where c2prio.py / c2temps_gdb.py live
sys.path.insert(0, LIB)
import c2prio                                        # harness: paths, flags, marker lookup
from c2prio import WORK, TC, REPO, winpath, target_name

INSN = (13, 15, 16, 18)                              # tuple kinds: op, call, ret, branch (26 / 27 = labels)
XNAME = {'e1b0': 'cross-jump(e1b0)', 'eb00': 'tail-merge(eb00)', 'eff0': 'tail-merge(eff0)',
         'e700': 'merge-into-target(e700)', 'd400': 'drop-jump-to-next(d400)', 'd530': 'tail-call(d530)',
         'd890': 'branch-fold(d890)', 'dff0': 'delete-branch(dff0)', 'dff0b': 'delete-branch(dff0b)',
         'd6c0': 'invert(d6c0)', 'f560': 'join-fallthrough(f560)', 'f700': 'f700', 'a400': 'a400',
         '306c0': 'cross-jump-mode2(306c0)', '30f00': '30f00', '321e0': '321e0', 'dc70': 'drop-jump(dc70)',
         '28590': 'thread(28590)', '27040': 'merge-label(27040)', 'c5cef0': 'call-tail(c5cef0)',
         'dup': 'tail-duplicate', '2cca0': '2cca0'}
PAD = ('mov edi, edi', 'mov esi, esi', 'lea esp, [esp]', 'lea esi, [esi]', 'lea ebx, [ebx]', 'lea ecx, [ecx]', 'nop',
       'lea edi, [edi]', 'lea esp, [esp + 0]', 'lea ebx, [ebx + 0]', 'lea esi, [esi + 0]', 'lea edi, [edi + 0]',
       'lea ecx, [ecx + 0]')


def kill_run(work):
    """kill every process (wine cl, wineserver children, gdb) whose working folder is this run's folder"""
    rd = os.path.realpath(work)
    for d in glob.glob('/proc/[0-9]*'):
        try: cw = os.readlink(d + '/cwd').replace(' (deleted)', '')
        except OSError: continue
        if cw == rd:
            try: os.kill(int(d[6:]), signal.SIGKILL)
            except OSError: pass


def run_compile(src, flags, func, events_path, timeout, keep=False):
    """compile SOURCE with the spin copy, gdb attached running c2layout_gdb.py; returns (compiler output, work folder,
    object bytes or None). Everything this run started is killed at the end or after `timeout` seconds."""
    os.makedirs(os.path.join(WORK, 'runs'), exist_ok=True)
    work = tempfile.mkdtemp(prefix='layout-', dir=os.path.join(WORK, 'runs'))
    env = dict(os.environ, WINEDEBUG='-all')
    env['INCLUDE'] = ';'.join([winpath(os.path.join(REPO, 'headers')), winpath(REPO)])
    cmd = ['wine', os.path.join(TC, 'cl.exe')] + c2prio.BASE_FLAGS + flags + \
          ['/Fo' + winpath(os.path.join(work, 'diag.obj')), winpath(src)]
    logp = os.path.join(work, 'cl.log')             # a file, not a pipe (a wineserver can hold a pipe open; c2force)
    with open(logp, 'wb') as log:
        p = subprocess.Popen(cmd, cwd=work, env=env, stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
    readlog = lambda: open(logp, 'rb').read().decode('latin1')
    g = None
    try:
        pid = None; t0 = time.time()
        while pid is None:
            if p.poll() is not None:
                sys.exit('cl exited before reaching the back end:\n' + readlog())
            if time.time() - t0 > 120:
                sys.exit('timeout waiting for c2.dll')
            try:
                if os.path.join(TC, 'c2.dll') in open('/proc/%d/maps' % p.pid).read(): pid = p.pid
            except OSError:
                pass
            time.sleep(0.05)
        genv = dict(os.environ, C2LAYOUT_OUT=events_path, C2LAYOUT_FUNC=func, C2LAYOUT_HERE=LIB)
        g = subprocess.Popen(['gdb', '-q', '-batch', '-nx', '-p', str(pid), '-ex',
                              'python exec(open(%r).read())' % os.path.join(HERE, 'c2layout_gdb.py')],
                             cwd=work, env=genv, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                             stdin=subprocess.DEVNULL)
        t1 = time.time()
        while g.poll() is None or p.poll() is None:
            if time.time() - t1 > timeout:
                sys.exit('c2layout: TIMEOUT after %d s (--timeout); the run was killed' % timeout)
            time.sleep(0.05)
        out = readlog()
    finally:
        for q in (p, g):
            if q is not None and q.poll() is None: q.kill()
        kill_run(work)
    objp = os.path.join(work, 'diag.obj')
    objb = open(objp, 'rb').read() if os.path.exists(objp) else None
    if not keep:
        shutil.rmtree(work, ignore_errors=True)
    return out, work, objb


def plain_object(src, flags):
    """the same compile with the pinned compiler itself (no spin copy, no gdb), for --verify"""
    sys.path.insert(0, os.path.join(REPO, 'tools'))
    import common
    s = common.local_settings()
    work = tempfile.mkdtemp(prefix='layout-plain-', dir=os.path.join(WORK, 'runs'))
    env = dict(os.environ, WINEDEBUG='-all')
    env['INCLUDE'] = ';'.join([winpath(os.path.join(REPO, 'headers')), winpath(REPO)])
    cmd = (['wine'] if s.get('runner', 'native') != 'native' else []) + [s['cl']] + c2prio.BASE_FLAGS + flags + \
          ['/Fo' + winpath(os.path.join(work, 'plain.obj')), winpath(src)]
    try:
        with open(os.path.join(work, 'cl.log'), 'wb') as log:
            subprocess.run(cmd, cwd=work, env=env, stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL,
                           timeout=600)
        p = os.path.join(work, 'plain.obj')
        return open(p, 'rb').read() if os.path.exists(p) else None
    finally:
        kill_run(work)
        shutil.rmtree(work, ignore_errors=True)


# ---- a minimal COFF reader (sections, symbols) ------------------------------------------------------------------------
def coff(objb):
    import struct
    nsec = struct.unpack_from('<H', objb, 2)[0]; symoff, nsym = struct.unpack_from('<II', objb, 8)
    opt = struct.unpack_from('<H', objb, 16)[0]
    secs = []
    for i in range(nsec):
        h = 20 + opt + 40 * i
        name = objb[h:h + 8].rstrip(b'\0').decode('latin1')
        size, rawp = struct.unpack_from('<II', objb, h + 16)
        secs.append(dict(name=name, data=objb[rawp:rawp + size] if rawp else b''))
    strtab = symoff + 18 * nsym; syms = []; i = 0
    while i < nsym:
        o = symoff + 18 * i
        if objb[o:o + 4] == b'\0\0\0\0':
            off = struct.unpack_from('<I', objb, o + 4)[0]
            nm = objb[strtab + off:objb.index(b'\0', strtab + off)].decode('latin1')
        else:
            nm = objb[o:o + 8].rstrip(b'\0').decode('latin1')
        val, sec = struct.unpack_from('<Ih', objb, o + 8); naux = objb[o + 17]
        syms.append((nm, sec, val)); i += 1 + naux
    return secs, syms


def objcode(objb, frag):
    """the target's instructions in the object (its own COMDAT section under /Gy)"""
    import capstone
    secs, syms = coff(objb)
    hit = next(((nm, sec, val) for nm, sec, val in syms if frag in nm and sec > 0 and secs[sec - 1]['name'] == '.text'), None)
    if hit is None: return None, None
    code = secs[hit[1] - 1]['data'][hit[2]:]
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    return hit[0], list(md.disasm(code, 0))


# ---- blocks and their changes -----------------------------------------------------------------------------------------
class Names:
    def __init__(s): s.m = {}
    def get(s, a):
        if a not in s.m: s.m[a] = 'B%d' % len(s.m)
        return s.m[a]


def blocks(stream):
    """split a tuple stream into blocks: a block starts at a label or after a branch / return"""
    out = []; cur = None
    for t in stream:
        a, kd = t[0], t[1]
        if kd in (26, 27) or cur is None or (cur['tup'] and cur['tup'][-1][1] in (16, 18)):
            if cur is not None and not cur['tup'] and kd in (26, 27):
                cur['labels'].append(a); continue
            cur = dict(first=a, labels=[a] if kd in (26, 27) else [], tup=[]); out.append(cur)
        if kd not in (26, 27): cur['tup'].append(t)
    return out


def fmtlines(ls):
    ls = sorted(set(l for l in ls if l and l > 0)); out = []; i = 0
    while i < len(ls):
        j = i
        while j + 1 < len(ls) and ls[j + 1] == ls[j] + 1: j += 1
        out.append(str(ls[i]) if i == j else '%d-%d' % (ls[i], ls[j])); i = j + 1
    return ','.join(out) or '-'


def tlines(ts): return fmtlines([t[2] for t in ts])


class View:
    def __init__(s): s.N = Names()
    def lab2blk(s, bl):
        m = {}
        for b in bl:
            for l in b['labels']: m[l] = b
        return m
    def desc(s, b, l2b):
        ins = [t for t in b['tup'] if t[1] in INSN]
        terms = []
        for t in b['tup']:
            if t[1] == 18:
                tb = l2b.get(t[4]); tn = s.N.get(tb['first']) if tb else '?'
                terms.append(('jmp ' if t[3] == 0x10 else 'jcc ') + tn)
            elif t[1] == 16: terms.append('ret')
        return '%-5s lines %-14s %2d insn  -> %s' % (s.N.get(b['first']), tlines(b['tup']), len(ins), '; '.join(terms) or 'fall')
    def show(s, stream, ind='  '):
        bl = blocks(stream); l2b = s.lab2blk(bl)
        return '\n'.join(ind + s.desc(b, l2b) for b in bl)


def diff(v, a, b):
    """what changed between two snapshots"""
    A = blocks(a); Bb = blocks(b)
    ka = [x['first'] for x in A]; kb = [x['first'] for x in Bb]
    la = {x['first']: x for x in A}; lb = {x['first']: x for x in Bb}
    l2b = v.lab2blk(Bb); l2a = v.lab2blk(A)
    out = []
    ta = {t[0]: t for x in A for t in x['tup']}; tb = {t[0]: t for x in Bb for t in x['tup']}
    gone = [t for k, t in ta.items() if k not in tb]; new = [t for k, t in tb.items() if k not in ta]
    for k in ka:
        if k not in lb: out.append('block %s removed (lines %s)' % (v.N.get(k), tlines(la[k]['tup'])))
    for k in kb:
        if k not in la: out.append('new block %s (lines %s)' % (v.N.get(k), tlines(lb[k]['tup'])))
    ins = [t for t in gone if t[1] in INSN]
    if ins: out.append('instructions cut: %d (lines %s)' % (len(ins), tlines(ins)))
    ins = [t for t in new if t[1] in INSN]
    if ins:
        ids = {n[0] for n in ins}
        where = sorted(set(v.N.get(x['first']) for x in Bb for t in x['tup'] if t[0] in ids))
        out.append('instructions copied in: %d (lines %s) into %s' % (len(ins), tlines(ins), ','.join(where)))
    common = [k for k in kb if k in la]
    if common != [k for k in ka if k in lb]:
        out.append('order changed: ' + ' '.join(v.N.get(k) for k in common))
    for k, t in tb.items():
        if k in ta and t[1] == 18 and ta[k][4] != t[4]:
            o = l2a.get(ta[k][4]); n = l2b.get(t[4])
            out.append('branch at line %s retargeted %s -> %s' % (t[2] or '-', v.N.get(o['first']) if o else '?',
                                                                 v.N.get(n['first']) if n else '?'))
        if k in ta and t[1] == 18 and ta[k][3] != t[3]:
            out.append('branch at line %s changed kind %x -> %x' % (t[2] or '-', ta[k][3], t[3]))
    wa = {t[0]: x['first'] for x in A for t in x['tup']}; wb = {t[0]: x['first'] for x in Bb for t in x['tup']}
    mv = {}
    for k in wb:
        if k in wa and wa[k] != wb[k] and tb[k][1] in INSN: mv.setdefault((wa[k], wb[k]), []).append(tb[k])
    for (x, y), ts in mv.items():
        out.append('%d instructions (lines %s) now in %s (were in %s)' % (len(ts), tlines(ts), v.N.get(y), v.N.get(x)))
    return out


def load(path):
    return [json.loads(l) for l in open(path) if l.strip()]


def report(ev, steps=False, raw=False, objb=None, frag=None):
    snaps = [e for e in ev if e[0] == 'snap']
    fn = next((e[2] for e in ev if e[0] == 'pass'), None)
    errs = [e for e in ev if e[0] == 'err']
    print('function: %s, %d snapshots%s' % (fn or '(not reached - check --func)', len(snaps),
          ', %d hook errors (first: %s)' % (len(errs), errs[0][1:]) if errs else ''))
    if not snaps: return
    v = View()
    first = snaps[0][2]
    for b in blocks(first): v.N.get(b['first'])
    print('\n1. before the late passes (stream order):'); print(v.show(first))
    prev = first; runs = {}; jst = {}; st = None

    def flushj():
        c = jst.pop('c', None)
        if not c: return
        bl = c.get('blk') or blocks(prev); l2b = v.lab2blk(bl); tb = l2b.get(c['tg'])
        tn = v.N.get(tb['first']) if tb else '?'
        tl = tlines(tb['tup']) if tb else '?'
        sz = c['sizes'][-1] if c['sizes'] else None
        if c['out'] == 'jcopy': why = 'COPIED the target tail (est. size %d <= limit %d)' % (sz[0], sz[1]) if sz else 'COPIED'
        elif c['out'] == 'jmove': why = 'MOVED the target block here (nothing fell into it)'
        elif sz and sz[2]: why = 'kept: the target holds something the copier refuses'
        elif sz and sz[0] > sz[1]: why = 'kept: target tail too big (est. size %d > limit %d)' % (sz[0], sz[1])
        else: why = 'kept: target is not a single block ending in ret / jmp, or something falls into it'
        print('  - jmp at line %-5s -> %s (lines %s): %s' % (c['line'] or '-', tn, tl, why))

    for e in ev:
        if e[0] == 'pass':
            cur = e[1]; runs[cur] = runs.get(cur, 0) + 1
            print('\n%s. %s pass%s' % ('2' if cur == 'flow' else '3', cur.upper(), ' (run %d)' % runs[cur] if runs[cur] > 1 else ''))
        elif e[0] == 'jcand':
            flushj(); jst['c'] = dict(j=e[1], line=e[2], tg=e[3], sizes=[], out=None)
        elif e[0] == 'jsize':
            if jst.get('c'): jst['c']['sizes'].append((e[2], e[3], e[4]))
        elif e[0] in ('jcopy', 'jmove'):
            if jst.get('c'): jst['c']['out'] = e[0]; jst['c']['blk'] = blocks(prev)
        elif e[0] == 'xf':
            st = e
        elif e[0] == 'snap':
            tag = e[1]
            if tag.startswith('after dup-'):
                flushj(); d = diff(v, prev, e[2])
                if d: print('      ' + '\n      '.join(d))
                prev = e[2]; continue
            if tag.endswith(':in') or tag == 'emit' or tag.endswith(':out'):
                d = diff(v, prev, e[2])
                if d: print('  (%s) ' % ('changed before this pass' if tag.endswith(':in') else
                                       'changed inside the pass, untraced step' if tag.endswith(':out') else
                                       'changed after the passes') + ('\n' + ' ' * 6).join(d))
                prev = e[2]; continue
            d = diff(v, prev, e[2])
            if tag.startswith('after') and d:
                nm = tag[6:]
                print('  - %-26s at line %-5s %s' % (XNAME.get(nm, nm), (st[5] or '-') if st else '-', ('\n' + ' ' * 43).join(d)))
                if steps: print(v.show(e[2], '      '))
            prev = e[2]
    flushj()
    last = next((e[2] for e in reversed(snaps) if e[1] == 'emit'), snaps[-1][2])
    print('\n4. final order at code emission:'); print(v.show(last))
    if raw:
        for e in snaps: print(e[1], ' '.join('%d:%d' % (t[1], t[2]) for t in e[2]))
    if objb and frag:
        nm, ins = objcode(objb, frag)
        if not ins:
            print('\n   object: target symbol not found'); return
        # the function's instructions end at the last ret / jmp that no later jump target follows
        tgt = set(); end = len(ins)
        for k, i in enumerate(ins):
            if i.mnemonic.startswith('j') and i.op_str.startswith('0x'): tgt.add(int(i.op_str, 16))
            if i.mnemonic == 'ret' and not any(t > i.address for t in tgt): end = k + 1; break
        ins = ins[:end]
        back = sorted(set(int(i.op_str, 16) for i in ins if i.mnemonic.startswith('j') and i.op_str.startswith('0x')
                          and int(i.op_str, 16) <= i.address))
        pads = [(i.address, i.size, ins[k + 1].address) for k, i in enumerate(ins)
                if ('%s %s' % (i.mnemonic, i.op_str)).strip() in PAD and k + 1 < len(ins) and ins[k + 1].address in tgt]
        print('\n   object: %d bytes, %d instructions; loop heads (backward-branch targets): %s' % (
            ins[-1].address + ins[-1].size, len(ins), ', '.join('+%x (mod16 %d)' % (h, h % 16) for h in back) or 'none'))
        for p0, sz, h in pads:
            print('   alignment pad +%x (%d B) before +%x -> head at mod16 %d' % (p0, sz, h, h % 16))
        fi = [t for b in blocks(last) for t in b['tup'] if t[1] in INSN]
        n = len(ins) - len(pads)
        print('   stream instructions %d vs object %d%s' % (len(fi), n, ' (aligned)' if len(fi) == n else ''))
        if len(fi) == n:
            padset = {p[0] for p in pads}; oi = [i for i in ins if i.address not in padset]
            where = {t[0]: oi[k].address for k, t in enumerate(fi)}
            print('   block offsets: ' + ' '.join('%s@+%x' % (v.N.get(b['first']), where[b['tup'][0][0]])
                                             for b in blocks(last) if b['tup'] and b['tup'][0][0] in where))


def text_sections(objb):
    return [s['data'] for s in coff(objb)[0] if s['name'].startswith('.text')]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source')
    ap.add_argument('--func', required=True, help='function name, decorated-name fragment, or 0xVA marker')
    ap.add_argument('--flags', default=None, help='extra cl flags after the fixed profile; default: the flag rulings '
                    'of the --func 0xVA and the source\'s d2match opt-ins, as match.py applies them')
    ap.add_argument('--ob1', action='store_true', help='use /Ob1 instead of /Ob2 (the d2match: ob1 opt-in)')
    ap.add_argument('--steps', action='store_true', help='print the block list after every change')
    ap.add_argument('--raw', action='store_true', help='print the raw tuple streams (kind:line)')
    ap.add_argument('--verify', action='store_true', help='also compile with the pinned compiler (no gdb) and compare '
                    'the .text sections')
    ap.add_argument('--timeout', type=int, default=int(os.environ.get('C2LAYOUT_TIMEOUT', '600')),
                    help='seconds the hooked compile may run before it is killed (default 600)')
    ap.add_argument('--json', help='also write the raw event stream here')
    ap.add_argument('--events', help='skip compiling; report from an earlier --json file (no object section)')
    ap.add_argument('--keep', action='store_true', help='keep the scratch folder with the compiled object')
    a = ap.parse_args()
    if a.events:
        report(load(a.events), a.steps, a.raw); return
    src = os.path.abspath(a.source)
    name = target_name(src, a.func)
    if a.ob1: c2prio.BASE_FLAGS = [f if f != '/Ob2' else '/Ob1' for f in c2prio.BASE_FLAGS]
    flags = c2prio.resolve_flags(src, a.func, a.flags)
    frag = name if name.startswith('?') else '?' + name + '@'
    os.makedirs(os.path.join(WORK, 'runs'), exist_ok=True)
    evp = os.path.abspath(a.json) if a.json else os.path.join(WORK, 'runs', 'layout-events-%d.jsonl' % os.getpid())
    t0 = time.time()
    out, work, objb = run_compile(src, flags, frag, evp, a.timeout, keep=a.keep)
    print('c2layout: %s, flags %s, %.1f s' % (os.path.basename(src), ' '.join(flags) or '(profile)', time.time() - t0))
    if a.keep: print('kept work folder (diag.obj):', work)
    if 'error' in out.lower(): print(out[-3000:])
    ev = load(evp)
    if not a.json: os.remove(evp)
    report(ev, a.steps, a.raw, objb, frag)
    if a.verify:
        po = plain_object(src, flags)
        if po is None or objb is None: print('   verify: a compile failed')
        else:
            print('   verify: .text sections of the hooked and the pinned compile are %s' % (
                'IDENTICAL' if text_sections(po) == text_sections(objb) else 'DIFFERENT'))


if __name__ == '__main__':
    main()
