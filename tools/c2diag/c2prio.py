#!/usr/bin/env python3
"""c2prio.py - read the pinned MSVC 2005 SP1 back end's (c2.dll 14.00.50727.762) global register allocation
decisions for one function: candidates, priorities, per-block references and liveness, colouring order, splits
and the register each piece got. Owner-side diagnostic; see README.md.

usage: c2prio.py SOURCE --func NAME|0xVA [--flags "/GS- ..."] [--json OUT] [--blocks] [--events] [--class N]
"""
import argparse, json, os, re, shutil, subprocess, sys, tempfile, time, collections

HERE = os.path.dirname(os.path.abspath(__file__))
WORK = os.environ.get('C2DIAG_HOME', os.path.join(os.path.expanduser('~'), '.d2match-c2diag'))   # outside the repo
TC = os.path.join(WORK, 'tcspin', 'bin')            # copy of the pinned toolchain; c2.dll entry patched to spin
REPO = os.environ.get('D2REPO', os.path.abspath(os.path.join(HERE, '..', '..')))
BASE_FLAGS = ['/nologo', '/c', '/TP', '/Zl', '/Z7', '/Gy', '/MT', '/O2', '/Oy-', '/Ob2', '/Gd']
REGN = {0: '-', 1: 'eax', 2: 'ecx', 3: 'edx', 4: 'ebx', 5: 'esp', 6: 'ebp', 7: 'esi', 8: 'edi'}


def winpath(p):
    return 'Z:' + os.path.abspath(p).replace('/', '\\')


def target_name(src, func):
    """--func may be a function name or a `// 0xVA` marker; returns the identifier to look for."""
    if not re.fullmatch(r'0x[0-9A-Fa-f]{8}', func):
        return func
    lines = open(src, encoding='latin1').read().splitlines()
    for i, l in enumerate(lines):
        if l.strip().lower() == '// ' + func.lower():
            for j in range(i + 1, min(i + 6, len(lines))):
                # skip __declspec(...), calling-convention and other keywords before the function's own name
                names = [n for n in re.findall(r'([A-Za-z_][A-Za-z0-9_:]*)\s*\(', lines[j])
                         if not n.startswith('__') and n not in ('noinline', 'naked', 'static', 'inline')]
                if names:
                    return names[0].split('::')[-1]
    sys.exit('no `// %s` marker followed by a definition in %s' % (func, src))


def ruling_flags(src, func):
    """The flags tools/match.py puts after the fixed profile for this source and VA: every `"rule": "flag"` ruling in
    docs/rulings/ naming the VA (none when the source has `// d2match: base-profile`), then /Ob1 for the
    `// d2match: ob1` opt-in. Same order and repeat rule as match.py. Returns (flags, ruling file names); func must be
    a 0xVA, otherwise only the opt-in is read."""
    text = open(src, encoding='latin1').read()
    flags, used = [], []
    prof = list(BASE_FLAGS)
    if re.fullmatch(r'0x[0-9A-Fa-f]{8}', func) and not re.search(r'^\s*//\s*d2match:\s*base-profile\s*$', text, re.M):
        va = '0x%08X' % int(func, 16)
        import glob
        for rp in sorted(glob.glob(os.path.join(REPO, 'docs', 'rulings', '*.json'))):
            try:
                rj = json.load(open(rp))
            except Exception:
                continue
            if rj.get('rule') != 'flag':
                continue
            try:
                vas = ['0x%08X' % int(str(x).strip().lower().replace('0x', ''), 16) for x in rj.get('vas', [])]
            except ValueError:
                continue
            allf = prof + flags
            if va in vas and allf[-1] != rj.get('flag'):
                if rj['flag'] in allf and rj['flag'] not in ('/Oy-', '/Ob1', '/Ob2', '/Oy', '/O1', '/O2', '/Os', '/Ot'):
                    continue
                flags.append(rj['flag']); used.append(os.path.basename(rp))
    if re.search(r'^\s*//\s*d2match:\s*ob1\s*$', text, re.M) and '/Ob1' not in flags:
        flags.append('/Ob1'); used.append('// d2match: ob1')
    return flags, used


def resolve_flags(src, func, given):
    """--flags given (even "") is used as written; otherwise the VA's rulings and opt-ins (ruling_flags), so a reading
    is of the compile match.py launches. Says on stderr what it used; refuses /GL (code is generated at link time,
    where these hooks are not reached)."""
    auto, used = ruling_flags(src, func)
    if given is None:
        flags = auto
        if not re.fullmatch(r'0x[0-9A-Fa-f]{8}', func):
            print('c2diag: --func is a name, so no flag ruling is looked up; pass the 0xVA marker (or --flags) for a '
                  'VA under a ruling', file=sys.stderr)
        print('c2diag: flags after the profile: %s%s' % (' '.join(flags) or '(none)',
              ' (from %s)' % ', '.join(used) if used else ''), file=sys.stderr)
    else:
        flags = given.split()
        if flags != auto:
            print('c2diag: --flags %r given; match.py would use %r for this source%s' % (
                ' '.join(flags), ' '.join(auto), ' (from %s)' % ', '.join(used) if used else ''), file=sys.stderr)
    if '/GL' in flags:
        sys.exit('c2diag: /GL defers code generation to the link; these readers cannot follow it')
    return flags


def run_compile(src, flags, func, events_path, blocks=True, timeout=600, keep=False):
    env = dict(os.environ, WINEDEBUG='-all')
    env['INCLUDE'] = ';'.join([winpath(os.path.join(REPO, 'headers')), winpath(REPO)])
    work = tempfile.mkdtemp(prefix='run-', dir=os.path.join(WORK, 'runs'))
    cmd = ['wine', os.path.join(TC, 'cl.exe')] + BASE_FLAGS + flags + ['/Fo' + winpath(os.path.join(work, 'diag.obj')), winpath(src)]
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
    genv = dict(os.environ, C2PRIO_OUT=events_path, C2PRIO_FUNC=func, C2PRIO_BLOCKS='1' if blocks else '0')
    try:
        g = subprocess.run(['gdb', '-q', '-batch', '-nx', '-p', str(pid), '-ex',
                            'python exec(open(%r).read())' % os.path.join(HERE, 'c2prio_gdb.py')],
                           env=genv, capture_output=True, text=True, timeout=timeout)
        out = p.communicate(timeout=timeout)[0].decode('latin1')
    finally:
        if p.poll() is None:          # gdb failed: the compiler would spin forever
            p.kill()
    if not keep:
        shutil.rmtree(work, ignore_errors=True)
    return out, g.stdout + g.stderr, work


def load(path):
    return [json.loads(l) for l in open(path) if l.strip()]


def rounds_of(evs):
    """split the event stream into priority rounds: each round = prio_begin .. prio_end plus the colouring
    events that follow it (until the next prio_begin)."""
    rounds = []; cur = None
    for e in evs:
        if e['ev'] == 'prio_begin':
            cur = dict(cls=e['cls'], refs=[], blocks=[], cands=None, pops=[], picks={}, paths={}, order=[])
            rounds.append(cur)
        elif cur is None:
            continue
        elif e['ev'] == 'ref': cur['refs'].append(e)
        elif e['ev'] == 'block': cur['blocks'].append(e)
        elif e['ev'] == 'prio_end': cur['cands'] = e['cands']
        elif e['ev'] == 'pop': cur['order'].append(e)
        elif e['ev'] == 'path': cur['paths'].setdefault(e['id'], []).append(e['path'])
        elif e['ev'] == 'pick': cur['picks'][e['id']] = e
    return rounds


def label(c, deflines):
    if c['name']:
        n = c['name']
        if n.startswith('_') and not n.startswith('__'): n = n[1:]
        return n
    if c.get('const'):
        return '%s#%d' % (c['const'].replace(' ', ':'), c['id'])
    ls = deflines.get(c['id'])
    return 'tmp#%d(def L%s)' % (c['id'], ls) if ls else 'tmp#%d' % c['id']


def report(evs, cls_filter=0, show_blocks=False, top=40, minrefs=1, only=None):
    funcs = [e['name'] for e in evs if e['ev'] == 'func']
    print('function:', ', '.join(funcs) or '(not reached - check --func)')
    rs = [r for r in rounds_of(evs) if r['cands'] is not None and (cls_filter is None or r['cls'] == cls_filter)]
    if not rs:
        print('no allocation rounds for class', cls_filter); return
    # sym -> web grouping across rounds (pieces of a split share the symbol / temp record)
    symweb = {}
    for r in rs:
        for c in r['cands']:
            symweb.setdefault(c['sym'], c['id'])
    for n, r in enumerate(rs, 1):
        deflines = collections.defaultdict(set); uselines = collections.defaultdict(set)
        for e in r['refs']:
            if e['line']:
                (deflines if e['kind'] == 'def' else uselines)[e['id']].add(e['line'])
        dl = {k: ','.join(map(str, sorted(v))) for k, v in deflines.items()}
        cands = [c for c in r['cands'] if c['refs'] >= minrefs or c['prio'] != 0]
        cands.sort(key=lambda c: (-c['prio'], -c['key']))
        print('\n=== round %d (register class %d): %d candidates with references ===' % (n, r['cls'], len(cands)))
        print('  %-28s %5s %6s %4s %5s %4s  %-6s %s' % ('candidate', 'id', 'prio', 'refs', 'key', 'web', 'reg', 'def lines / use lines'))
        shown = [c for c in cands if not only or label(c, dl).split('(')[0] in only or str(c['id']) in only] if only else cands[:top]
        for c in shown:
            pk = r['picks'].get(c['id'])
            regs = REGN.get(pk['chosen'], '?') if pk else ''
            path = r['paths'].get(c['id'])
            if not pk and path: regs = '(' + path[-1] + ')'
            web = symweb.get(c['sym'])
            print('  %-28s %5d %6d %4d %5x %4s  %-6s %s / %s' % (label(c, dl)[:28], c['id'], c['prio'], c['refs'], c['key'],
                  '' if web == c['id'] else '<%d' % web, regs, dl.get(c['id'], ''),
                  ','.join(map(str, sorted(uselines.get(c['id'], []))))))
        if r['order'] and any(o['cand']['refs'] or o['cand']['prio'] for o in r['order']):
            print('  colouring order:')
            for o in r['order']:
                c = o.get('cand')
                if c is None or (c['refs'] == 0 and c['prio'] == 0): continue
                if only and label(c, dl).split('(')[0] not in only and str(c['id']) not in only: continue
                pk = r['picks'].get(o['id']); path = r['paths'].get(o['id'], ['?'])[-1]
                if pk:
                    al = '/'.join(REGN[x] for x in pk['allowed']) or 'none'
                    cs = ' '.join('%s=%d' % (REGN[int(k)], v) for k, v in pk['costs'].items() if int(k) in pk['allowed'])
                    print('    %-28s prio %5d -> %-4s (allowed %s; costs %s)' % (label(c, dl)[:28], o['prio'], REGN.get(pk['chosen'], '?'), al, cs))
                else:
                    print('    %-28s prio %5d -> %s' % (label(c, dl)[:28], o['prio'], {'d690': 'not coloured (split / memory)', 'noreg': 'no register allowed', 'requeue': 're-queued'}.get(path, path)))
        if show_blocks:
            byid = {c['id']: c for c in r['cands']}
            print('  blocks (w = loop weight, K = candidates referenced in the block):')
            for b in r['blocks']:
                wk = b['w'] * b['K']
                parts = []
                for a in b['A']:
                    if a['counted'] and a['refunits']:
                        parts.append('%s+%d' % (label(byid[a['id']], dl) if a['id'] in byid else a['id'], a['refunits'] * wk))
                for a in b['B']:
                    nm = label(byid[a['id']], dl) if a['id'] in byid else str(a['id'])
                    if a['referenced']: parts.append('%s+%d' % (nm, a['refunits'] * wk))
                    else: parts.append('%s-%d(live)' % (nm, b['w'] if b['profmode'] == 2 else wk))
                if only:
                    parts = [p for p in parts if re.split(r'[+-]', p)[0].split('(')[0] in only]
                    if not parts: continue
                ln = 'L%d-%d' % tuple(b['lines']) if b['lines'] else 'L?'
                print('    blk %08x %-10s w=%d K=%d: %s' % (b['blk'], ln, b['w'], b['K'], ' '.join(parts)))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source')
    ap.add_argument('--func', required=True, help='function name, decorated-name fragment, or 0xVA marker')
    ap.add_argument('--flags', default=None, help='extra cl flags after the fixed profile, e.g. "/GS-"; default: the '
                    'flag rulings of the --func 0xVA and the source\'s d2match opt-ins, as match.py applies them')
    ap.add_argument('--ob1', action='store_true', help='use /Ob1 instead of /Ob2 (the d2match: ob1 opt-in)')
    ap.add_argument('--json', help='also write the raw event stream here')
    ap.add_argument('--events', help='skip compiling; report from an earlier --json file')
    ap.add_argument('--blocks', action='store_true', help='print per-block priority contributions')
    ap.add_argument('--class', dest='cls', default='0', help='register class to report (0 = integer; "all")')
    ap.add_argument('--top', type=int, default=60)
    ap.add_argument('--keep', action='store_true', help='keep the scratch folder with the compiled object')
    ap.add_argument('--only', help='comma-separated candidate labels or ids to restrict the tables to (e.g. pSlot,tmp#32)')
    a = ap.parse_args()
    if a.events:
        evs = load(a.events)
    else:
        src = os.path.abspath(a.source)
        name = target_name(src, a.func)
        global BASE_FLAGS
        if a.ob1: BASE_FLAGS = [f if f != '/Ob2' else '/Ob1' for f in BASE_FLAGS]
        os.makedirs(os.path.join(WORK, 'runs'), exist_ok=True)
        evp = os.path.abspath(a.json) if a.json else os.path.join(WORK, 'runs', 'events-%d.jsonl' % os.getpid())
        frag = name if name.startswith('?') else '?' + name + '@'
        out, glog, work = run_compile(src, resolve_flags(src, a.func, a.flags), frag, evp, keep=a.keep)
        if a.keep: print('kept work folder (diag.obj):', work)
        if 'error' in out.lower():
            print(out)
        evs = load(evp)
        errs = [e for e in evs if e['ev'] == 'error']
        if errs: print('hook errors:', errs[:5], file=sys.stderr)
    report(evs, None if a.cls == 'all' else int(a.cls), a.blocks, a.top, only=set(a.only.split(',')) if a.only else None)


if __name__ == '__main__':
    main()
