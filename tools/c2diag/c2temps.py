#!/usr/bin/env python3
"""c2temps.py - read the pinned MSVC 2005 SP1 back end's (c2.dll 14.00.50727.762) local register assigner
(regasg.c) for one function: for every instruction tuple in layout order, which scratch register each
expression temporary / reload got, how (preference, rotation, first free, spill), the rotation pointer before
and after, which registers were busy and which were excluded for that temporary. Owner-side diagnostic; see
README.md ("c2temps").

usage: c2temps.py SOURCE --func NAME|0xVA [--flags "/GS- ..."] [--ob1] [--json OUT] [--events FILE]
                  [--lines A-B] [--all] [--frees] [--pre] [--picks]
"""
import argparse, json, os, re, shutil, subprocess, sys, tempfile, time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import c2prio                                        # harness: paths, flags, marker lookup (no compile there)
from c2prio import WORK, TC, REPO, winpath, target_name

R32 = {1: 'eax', 2: 'ecx', 3: 'edx', 4: 'ebx', 5: 'esp', 6: 'ebp', 7: 'esi', 8: 'edi'}
R16 = {1: 'ax', 2: 'cx', 3: 'dx', 4: 'bx', 5: 'sp', 6: 'bp', 7: 'si', 8: 'di'}
R8 = {1: 'al', 2: 'cl', 3: 'dl', 4: 'bl'}
ROTN = {1: 'EAX', 2: 'ECX', 3: 'EDX', 7: 'ESI', 8: 'EDI', 4: 'EBX', 6: 'EBP', 0: 'end'}


def run_compile(src, flags, func, events_path, timeout=600, keep=False, base=None):
    env = dict(os.environ, WINEDEBUG='-all')
    env['INCLUDE'] = ';'.join([winpath(os.path.join(REPO, 'headers')), winpath(REPO)])
    work = tempfile.mkdtemp(prefix='temps-', dir=os.path.join(WORK, 'runs'))
    cmd = ['wine', os.path.join(TC, 'cl.exe')] + (base or c2prio.BASE_FLAGS) + flags + \
          ['/Fo' + winpath(os.path.join(work, 'diag.obj')), winpath(src)]
    p = subprocess.Popen(cmd, cwd=work, env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    pid = None; t0 = time.time()
    while pid is None:
        if p.poll() is not None:
            sys.exit('cl exited before reaching the back end:\n' + p.stdout.read().decode('latin1'))
        if time.time() - t0 > 120:
            p.kill(); sys.exit('timeout waiting for c2.dll')
        try:
            if os.path.join(TC, 'c2.dll') in open('/proc/%d/maps' % p.pid).read():
                pid = p.pid
        except OSError:
            pass
        time.sleep(0.05)
    genv = dict(os.environ, C2TEMPS_OUT=events_path, C2TEMPS_FUNC=func)
    try:
        g = subprocess.run(['gdb', '-q', '-batch', '-nx', '-p', str(pid), '-ex',
                            'python exec(open(%r).read())' % os.path.join(HERE, 'c2temps_gdb.py')],
                           env=genv, capture_output=True, text=True, timeout=timeout)
        out = p.communicate(timeout=timeout)[0].decode('latin1')
    finally:
        if p.poll() is None:
            p.kill()
    if not keep:
        shutil.rmtree(work, ignore_errors=True)
    return out, g.stdout + g.stderr, work


def load(path):
    return [json.loads(l) for l in open(path) if l.strip()]


def rname(r, ty):
    sz = ty & 0xfff
    if sz == 1: return R8.get(r, 'r%d.b' % r)
    if sz == 2: return R16.get(r, 'r%d.w' % r)
    return R32.get(r, 'r%d' % r)


def ostr(d):
    k = d.get('k')
    if k == 1:
        if 'r' in d: return rname(d['r'], d['ty'])
        if 't' in d: return 'T%d' % d['t']
        return 'reg?'
    if k == 6:
        parts = []
        if d.get('sym'): parts.append(d['sym'].lstrip('_?').split('@')[0])
        if 'b' in d: parts.append(rname(d['b'], 4) if isinstance(d['b'], int) else d['b'])
        if 'i' in d:
            sc = {0: 1, 1: 1, 2: 2, 3: 4, 4: 8}.get(d.get('sc', 0), d.get('sc'))
            ix = rname(d['i'], 4) if isinstance(d['i'], int) else d['i']
            parts.append(ix + ('*%d' % sc if sc and sc != 1 else ''))
        s = '+'.join(parts)
        if d.get('disp'):
            s += ('%+d' % d['disp']) if s else str(d['disp'])
        return '[' + (s or '0') + ']'
    if k in (2, 3, 4):
        nm = (d.get('sym') or '').lstrip('_?').split('@')[0] or 'local'
        return ('[%s]' % nm) if d.get('op') == 0x27a and k == 3 else nm
    if k == 7: return str(d.get('imm'))
    return '?k%s' % k


def shown(d):
    if d.get('k') == 1 and d.get('r') == 5: return False          # esp operands of push / call
    return d.get('k') in (1, 2, 3, 6, 7) and (d.get('ty', 0) >> 12) != 9


def render(row):
    m = row.get('m') or 'op%d' % row['op']
    if m == 'call':
        tg = [d for d in row.get('src', []) if d.get('k') in (2, 4) and d.get('sym')]
        return 'call ' + (tg[0]['sym'].lstrip('_?').split('@')[0] if tg else '?')
    subs = set()
    for d in row.get('dst', []) + row.get('src', []):
        if d.get('k') == 6:
            subs.update(d[x] for x in ('ba', 'ia') if x in d)
    dst = [d for d in row.get('dst', []) if shown(d) and d.get('a') not in subs]
    src = [d for d in row.get('src', []) if shown(d) and d.get('a') not in subs]
    if dst and src and ostr(src[0]) == ostr(dst[0]) and row['op'] != 1:
        src = src[1:]                                  # two-address form: add eax, x
    return (m + ' ' + ', '.join(ostr(d) for d in dst + src)).strip()


def busy_str(occ, excl=()):
    out = []
    for r in (1, 2, 3, 7, 8, 4):
        o = occ.get(str(r))
        if o: out.append('%s=%s' % (R32[r], 'var' if o == 'R' else o))
    return ' '.join(out) or '-'


def how(p):
    path = p['path']
    if 'pref' in path: return 'pref'
    if 'rotate' in path: return 'rotate'
    if 'first-free' in path: return 'first-free'
    if 'free-any' in path: return 'free-any'
    if 'spill' in path: return 'spill(%s)' % (p.get('spill_who') or '?')
    return '/'.join(path) or '?'


def report(evs, lines=None, show_all=False, frees=False, pre=False, picks_only=False):
    funcs = [e['name'] for e in evs if e['ev'] == 'func']
    print('function:', ', '.join(funcs) or '(not reached - check --func)')
    errs = [e for e in evs if e['ev'] == 'error']
    if errs: print('hook errors:', errs[:3], file=sys.stderr)
    picks = {}; free_at = {}; evicts = {}; resets = set(); before = {}
    for e in evs:
        if e['ev'] == 'pick': picks.setdefault(e['t'], []).append(e)
        elif e['ev'] == 'free': free_at.setdefault(e['t'], []).append(e)
        elif e['ev'] == 'evict': evicts.setdefault(e['t'], []).append(e)
        elif e['ev'] == 'rotreset': resets.add(e['t'])
        elif e['ev'] == 'tuple' and 'src' in e: before.setdefault(e['t'], e)
    final = [e for e in evs if e['ev'] == 'final']
    if not final:
        print('no final tuple stream (the function did not reach the local assigner)'); return
    rows = final[-1]['rows']
    lo, hi = lines if lines else (None, None)
    print('rotation steps are over EAX ECX EDX; "ptr" is the rotation pointer before -> after the pick.')
    print('%-5s %-36s  %-6s %-4s %-10s %-11s %-28s %s' % ('line', 'instruction (after assignment)', 'temp', 'reg',
          'how', 'ptr', 'busy at the pick', 'excluded / pref'))
    nrot = 0; last = None; cur = None
    for row in rows:
        if not row['instr']: continue
        ln = row['line']
        eff = ln or cur                                  # a tuple without a line belongs to the line before it
        cur = eff
        if lo is not None and (eff is None or eff < lo or eff > hi): continue
        ps = picks.get(row['t'], [])
        if not ps and not show_all and not row.get('m'): continue
        if picks_only and not ps: continue
        text = render(row)
        btext = None
        if pre and row['t'] in before:
            b = before[row['t']]
            btext = render(dict(row, src=b['src'], dst=b['dst']))
            if btext == text: btext = None
        lab = 'L%s' % ln if ln and ln != last else ''
        last = ln or last
        if row['t'] in resets: print('      (rotation pointer reset to EAX here)')
        if not ps:
            extra = ''
            if frees and free_at.get(row['t']):
                extra = 'frees ' + ' '.join(R32.get(f['r'], str(f['r'])) for f in free_at[row['t']])
            print('%-5s %-36s  %s' % (lab, text[:36], extra))
            if btext: print('%-5s   before: %s' % ('', btext))
            continue
        fr = ''
        if frees and free_at.get(row['t']):      # frees happen before the picks of the same instruction
            fr = '; frees first: ' + ' '.join(R32.get(f['r'], str(f['r'])) for f in free_at[row['t']])
        for i, p in enumerate(ps):
            h = how(p)
            if h == 'rotate': nrot += 1
            ptr = '%s->%s' % (ROTN.get(p['ptr'], p['ptr']), ROTN.get(p['ptr_end'], p['ptr_end']))
            ex = ','.join(R32[r] for r in p['excl'] if r in (1, 2, 3, 7, 8, 4))
            pref = p.get('pref') or p.get('pref0')
            xs = ('excl ' + ex if ex else '') + (' pref ' + R32.get(pref, str(pref)) if pref and pref > 0 else '')
            print('%-5s %-36s  %-6s %-4s %-10s %-11s %-28s %s' % (lab if i == 0 else '', text[:36] if i == 0 else '',
                  'T%d' % p['tid'], R32.get(p['reg'], p['reg']), h, ptr, busy_str(p['occ']),
                  (xs.strip() + (fr if i == 0 else '')).strip()))
        if btext: print('%-5s   before: %s' % ('', btext))
        for ev in evicts.get(row['t'], []):
            print('%-5s %-36s  evicts %s from %s (fixed use)' % ('', '', ev['who'], R32.get(ev['r'], ev['r'])))
    print('rotation picks:', nrot)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source')
    ap.add_argument('--func', required=True, help='function name, decorated-name fragment, or 0xVA marker')
    ap.add_argument('--flags', default=None, help='extra cl flags after the fixed profile, e.g. "/GS-"; default: the '
                    'VA\'s flag rulings and the source\'s d2match opt-ins, as match.py applies them (c2prio.resolve_flags)')
    ap.add_argument('--ob1', action='store_true', help='use /Ob1 instead of /Ob2 (the d2match: ob1 opt-in)')
    ap.add_argument('--json', help='also write the raw event stream here')
    ap.add_argument('--events', help='skip compiling; report from an earlier --json file')
    ap.add_argument('--lines', help='only source lines A-B')
    ap.add_argument('--all', action='store_true', help='also print instructions with no temporary picked')
    ap.add_argument('--frees', action='store_true', help='print which registers each instruction frees')
    ap.add_argument('--picks', action='store_true', help='print only the instructions where a temporary got a register')
    ap.add_argument('--pre', action='store_true', help='also print each instruction as the assigner received it '
                    '(temporaries still Tn, register variables already coloured), when it differs')
    ap.add_argument('--keep', action='store_true', help='keep the scratch folder with the compiled object')
    a = ap.parse_args()
    if a.events:
        evs = load(a.events)
    else:
        src = os.path.abspath(a.source)
        name = target_name(src, a.func)
        base = list(c2prio.BASE_FLAGS)
        if a.ob1: base = [f if f != '/Ob2' else '/Ob1' for f in base]
        os.makedirs(os.path.join(WORK, 'runs'), exist_ok=True)
        evp = os.path.abspath(a.json) if a.json else os.path.join(WORK, 'runs', 'temps-%d.jsonl' % os.getpid())
        frag = name if name.startswith('?') else '?' + name + '@'
        out, glog, work = run_compile(src, c2prio.resolve_flags(src, a.func, a.flags), frag, evp, keep=a.keep, base=base)
        if a.keep: print('kept work folder (diag.obj):', work)
        if 'error' in out.lower():
            print(out)
        evs = load(evp)
    lines = tuple(int(x) for x in a.lines.split('-')) if a.lines else None
    report(evs, lines, a.all, a.frees, a.pre, a.picks)


if __name__ == '__main__':
    main()
