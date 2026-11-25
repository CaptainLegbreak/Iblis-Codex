#!/usr/bin/env python3
"""c2slots.py - read how the pinned MSVC 2005 SP1 back end (c2.dll 14.00.50727.762) lays out one function's stack
frame: the references it counts on every memory home after register allocation, the count-sorted home list, how
homes are packed into shared slots, the slot sort for frames over 0x80 bytes, and the final [ebp-N] of each home.
Includes a simulator of the list / sort rules for what-if counts. Owner-side diagnostic; see README.md ("c2slots").

usage: c2slots.py SOURCE --func NAME|0xVA [--flags "/GS- ..."] [--ob1] [--json OUT] [--events FILE]
                  [--refs] [--bump NAME+N[@first|@last|@K] ...]
"""
import argparse, json, os, re, shutil, subprocess, sys, tempfile, time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import c2prio                                        # harness: paths, flags, marker lookup
from c2prio import WORK, TC, REPO, winpath, target_name


def run_compile(src, flags, func, events_path, timeout=600, base=None):
    env = dict(os.environ, WINEDEBUG='-all')
    env['INCLUDE'] = ';'.join([winpath(os.path.join(REPO, 'headers')), winpath(REPO)])
    work = tempfile.mkdtemp(prefix='slots-', dir=os.path.join(WORK, 'runs'))
    obj = os.path.join(work, 'diag.obj')
    cmd = ['wine', os.path.join(TC, 'cl.exe')] + (base or c2prio.BASE_FLAGS) + flags + ['/Fo' + winpath(obj), winpath(src)]
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
    genv = dict(os.environ, C2SLOTS_OUT=events_path, C2SLOTS_FUNC=func)
    try:
        subprocess.run(['gdb', '-q', '-batch', '-nx', '-p', str(pid), '-ex',
                        'python exec(open(%r).read())' % os.path.join(HERE, 'c2slots_gdb.py')],
                       env=genv, capture_output=True, text=True, timeout=timeout)
        out = p.communicate(timeout=timeout)[0].decode('latin1')
    finally:
        if p.poll() is None:
            p.kill()
    return out, work, obj


def codeview_offsets(obj, func):
    """[ebp+N] of every S_BPREL32 local of the function whose decorated name contains func (llvm-readobj)."""
    try:
        txt = subprocess.run(['llvm-readobj', '--codeview', obj], capture_output=True, text=True).stdout
    except OSError:
        return {}
    offs = {}; inside = False; off = None; proc = False
    for line in txt.splitlines():
        s = line.strip()
        if s.startswith('Kind: S_LPROC32') or s.startswith('Kind: S_GPROC32'):
            inside = False; proc = True        # block-scoped locals sit in S_BLOCK32 ... S_END inside the proc
        elif s.startswith('CodeOffset:') and proc:
            inside = func in s; proc = False   # later CodeOffset lines are labels and blocks of the same proc
        elif inside and s.startswith('Offset:'):
            off = int(s.split()[1])
        elif inside and s.startswith('VarName:') and off is not None:
            offs[s.split(None, 1)[1]] = off; off = None
    return offs


def clean(n):
    if not n: return '?'
    return n[1:] if n.startswith('_') and not n.startswith('__') else n


# ---- simulator of the rules read from c2.dll ------------------------------------------------------------------
def build_list(refs):
    """Home list as 0x10be9190 keeps it: grouped by size ascending; a new home goes to the end of its size group with
    count 1; a counted home moves back past every earlier home of its size with a strictly lower count."""
    lst, cnt, size = [], {}, {}
    for n, s in refs:
        size[n] = s
        if n not in cnt:
            cnt[n] = 1
            pos = len(lst)
            for i, m in enumerate(lst):
                if size[m] > s: pos = i; break
            lst.insert(pos, n)
        else:
            cnt[n] += 1
            i = lst.index(n); j = i - 1
            while j >= 0 and cnt[lst[j]] < cnt[n] and size[lst[j]] == s: j -= 1
            lst.pop(i); lst.insert(j + 1, n)
    return lst, cnt


def density(sl):
    return sl['weight'] * 1000 // max(1, sl['size'])


def slot_cmp(a, b, direction):
    """comparator 0x10bebb30 (a = the partition element, b = the element tested): -1 moves b in front."""
    if a['cls'] != b['cls']:
        if a['cls'] < b['cls']: return 1 if direction == 0 else -1
        return -1 if direction == 0 else 1
    da, db = density(a), density(b)
    if da == db: return 0
    return 1 if da >= db else -1


def kr_qsort(v, lo, hi, direction):
    """K&R quicksort with a middle pivot, as at 0x10bebbb0 (recursion on the left part, loop on the right)."""
    while lo < hi:
        mid = (lo + hi) // 2
        v[lo], v[mid] = v[mid], v[lo]
        last = lo
        for i in range(lo + 1, hi + 1):
            if slot_cmp(v[lo], v[i], direction) < 0:
                last += 1
                v[last], v[i] = v[i], v[last]
        v[lo], v[last] = v[last], v[lo]
        kr_qsort(v, lo, last - 1, direction)
        lo = last + 1


def simulate(refs, packed, lo, direction, sort):
    """Final slot order for a reference trace, keeping the compiler's packing groups (interference is not modelled):
    slots are created in list order of their first member, weight = sum of member counts."""
    lst, cnt = build_list(refs)
    fixed = packed[:lo]
    groups = [s['members'] for s in packed[lo:]]
    owner = {m: k for k, g in enumerate(groups) for m in g}
    order, seen = [], set()
    for n in lst:
        k = owner.get(n)
        if k is not None and k not in seen:
            seen.add(k); order.append(k)
    order += [k for k in range(len(groups)) if k not in seen]
    slots = []
    for k in order:
        sl = dict(packed[lo + k]); sl['weight'] = sum(cnt.get(m, 0) for m in groups[k]); slots.append(sl)
    v = fixed + slots
    if sort:
        kr_qsort(v, lo, len(v) - 1, direction)
    return v, lst, cnt


def apply_bumps(refs, bumps):
    refs = list(refs)
    sizes = {n: s for n, s in refs}
    for b in bumps:
        m = re.fullmatch(r'([^+\-@]+)([+-]\d+)(?:@(first|last|\d+))?', b)
        if not m: sys.exit('bad --bump %r (NAME+N[@first|@last|@K])' % b)
        nm, d, at = m.group(1), int(m.group(2)), m.group(3) or 'last'
        key = [n for n in sizes if clean(n) == nm]
        if not key: sys.exit('--bump: no home named %s' % nm)
        key = key[0]
        idx = [i for i, (n, _) in enumerate(refs) if n == key]
        if d < 0:
            for i in sorted(idx[d:], reverse=True): refs.pop(i)
            continue
        pos = idx[0] + 1 if at == 'first' else (idx[-1] + 1 if at == 'last' else int(at))
        for _ in range(d): refs.insert(pos, (key, sizes[key]))
    return refs


def fmt_slot(sl):
    return '%s:%d' % ('+'.join(clean(m) for m in sl['members']) or '?', sl['weight'])


def report(evs, offsets, show_refs=False, bumps=()):
    funcs = [e['name'] for e in evs if e['ev'] == 'func']
    print('function:', ', '.join(funcs) or '(not reached - check --func)')
    for e in evs:
        if e['ev'] == 'error': print('hook error:', e)
    refs = [(e['name'], e['size']) for e in evs if e['ev'] == 'ref']
    lists = [e for e in evs if e['ev'] == 'list']
    packed = [e for e in evs if e['ev'] == 'packed']
    final = [e for e in evs if e['ev'] == 'final']
    if not lists or not final:
        print('no frame layout events (no memory homes, or --func did not match)'); return
    homes = lists[-1]['homes']; pk = packed[-1] if packed else None; fn = final[-1]
    if show_refs:
        print('\nreferences counted (IL order after allocation):')
        for e in evs:
            if e['ev'] == 'ref':
                print('  L%-5s %-24s size %-4d -> %d' % (e['line'], clean(e['name']), e['size'], e['before'] + 1))
    slot_of = {}
    for k, sl in enumerate(fn['slots']):
        for m in sl['members']: slot_of[m] = k
    pslot_of = {}
    if pk:
        for k, sl in enumerate(pk['slots']):
            for m in sl['members']: pslot_of[m] = k
    print('\nhomes in list order (count-sorted within each size):')
    print('  %3s %-24s %5s %5s %6s %6s %7s %6s' % ('#', 'home', 'refs', 'size', 'packed', 'final', 'w/byte', 'ebp'))
    for i, h in enumerate(homes):
        k = slot_of.get(h['name'])
        sl = fn['slots'][k] if k is not None else None
        off = offsets.get(clean(h['name']))
        print('  %3d %-24s %5d %5d %6s %6s %7s %6s' % (i, clean(h['name'])[:24], h['count'], h['size'],
              pslot_of.get(h['name'], '-'), k if k is not None else '-', density(sl) if sl else '-',
              ('%d' % off) if off is not None else '-'))
    sort = bool(pk and pk['packed_size'] > 0x80)
    if pk:
        print('\npacked slots (creation order; slots below %d are not sorted), packed size %d -> %s:'
              % (pk['lo'], pk['packed_size'], 'quicksort by weight per byte' if sort else 'no sort (<= 0x80)'))
        print('  ' + ' '.join(fmt_slot(s) for s in pk['slots']))
    print('final slot order (nearest EBP first):')
    print('  ' + ' '.join(fmt_slot(s) for s in fn['slots']))
    if pk:
        v, _, _ = simulate(refs, pk['slots'], pk['lo'], pk['direction'], sort)
        same = [fmt_slot(s) for s in v] == [fmt_slot(s) for s in fn['slots']]
        print('simulator on the same trace: %s' % ('reproduces it' if same else 'DIFFERS: ' + ' '.join(fmt_slot(s) for s in v)))
        if bumps:
            v, lst, cnt = simulate(apply_bumps(refs, bumps), pk['slots'], pk['lo'], pk['direction'], sort)
            print('what-if %s:' % ' '.join(bumps))
            print('  list : ' + ' '.join('%s:%d' % (clean(n), cnt[n]) for n in lst))
            print('  final: ' + ' '.join(fmt_slot(s) for s in v))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source')
    ap.add_argument('--func', required=True, help='function name, decorated-name fragment, or 0xVA marker')
    ap.add_argument('--flags', default=None, help='extra cl flags after the fixed profile, e.g. "/GS-"; default: the '
                    'VA\'s flag rulings and the source\'s d2match opt-ins, as match.py applies them (c2prio.resolve_flags)')
    ap.add_argument('--ob1', action='store_true', help='use /Ob1 instead of /Ob2')
    ap.add_argument('--json', help='also write the raw event stream here (offsets are added as an "offsets" event)')
    ap.add_argument('--events', help='skip compiling; report from an earlier --json file')
    ap.add_argument('--refs', action='store_true', help='print every counted reference with its source line')
    ap.add_argument('--bump', action='append', default=[],
                    help='what-if: NAME+N or NAME-N extra / fewer references (@first, @last or @K = trace index)')
    a = ap.parse_args()
    if a.events:
        evs = [json.loads(l) for l in open(a.events) if l.strip()]
        offsets = next((e['offsets'] for e in evs if e['ev'] == 'offsets'), {})
    else:
        src = os.path.abspath(a.source)
        name = target_name(src, a.func)
        base = [f if f != '/Ob2' else '/Ob1' for f in c2prio.BASE_FLAGS] if a.ob1 else None
        os.makedirs(os.path.join(WORK, 'runs'), exist_ok=True)
        evp = os.path.abspath(a.json) if a.json else os.path.join(WORK, 'runs', 'slots-%d.jsonl' % os.getpid())
        frag = name if name.startswith('?') else '?' + name + '@'
        out, work, obj = run_compile(src, c2prio.resolve_flags(src, a.func, a.flags), frag, evp, base=base)
        if 'error' in out.lower(): print(out)
        offsets = codeview_offsets(obj, frag)
        shutil.rmtree(work, ignore_errors=True)
        with open(evp, 'a') as f: f.write(json.dumps(dict(ev='offsets', offsets=offsets)) + '\n')
        evs = [json.loads(l) for l in open(evp) if l.strip()]
    report(evs, offsets, a.refs, a.bump)


if __name__ == '__main__':
    main()
