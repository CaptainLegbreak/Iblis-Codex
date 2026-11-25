#!/usr/bin/env python3
"""c2split.py - read the live-range splitting of the pinned MSVC 2005 SP1 back end's (c2.dll 14.00.50727.762) global
register allocator for one function: what started each split round, which webs were cut and why, where the cut
markers sit in the tuple stream, the pieces the rebuild made (operands, lines, priority, the register each piece
finally got, or memory) and the copies, spill stores and reloads the rebuild inserted. Owner-side diagnostic; see
README.md ("c2split").

usage: c2split.py SOURCE --func NAME|0xVA [--flags "/GS- ..."] [--ob1] [--json OUT] [--events FILE]
                  [--only NAME,ID] [--rounds 1,3] [--stream] [--keep]
"""
import argparse, collections, json, os, shutil, subprocess, sys, tempfile, time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import c2prio                                        # harness: paths, flags, marker lookup, candidate labels
from c2prio import WORK, TC, REPO, winpath, target_name
from c2temps import ostr as temps_ostr, shown, R32

PSEUDO = {661: 'load', 662: 'spill-store', 729: 'ret'}   # pseudo-ops as they print in this report
REGN = {0: '-', 1: 'EAX', 2: 'ECX', 3: 'EDX', 4: 'EBX', 5: 'ESP', 6: 'EBP', 7: 'ESI', 8: 'EDI'}
MODES = {
    'precolour': 'before colouring: the web has no allowed register at all (0x10b11770)',
    'pressure': 'pressure check while colouring %s (0x10b13460)',
    'neighbours': 'after %s was coloured: neighbours that lost their last register (0x10b15470)',
    'notcoloured': 'pop of %s, which is not coloured (0x10b0d690)',
    'noreg': 'pop of %s, which has no register allowed (0x10b0d830)',
}
HOW = {
    'cut': 'cut around every point where all of {%s} are taken: call clobbers, coloured neighbours (0x10b16720)',
    'blocks': 'cut at the entry of every block of its range where it is live (0x10b1b3b0)',
    'loop': 'defined by a load from its home: the load is moved to the entry of each successor of its block where '
            'the web is live (0x10b1b280)',
    'memory': 'whole web to memory, no pieces (0x10b17220)',
    'force-pref': 'restricted to its preference register and re-queued, no cut (0x10b1b430)',
    'no-pref': 'no usable preference register',
    'defer': 'deferred once: re-inserted further down the list (0x10b119f0)',
}


def run_compile(src, flags, func, events_path, timeout=900, keep=False, base=None):
    env = dict(os.environ, WINEDEBUG='-all')
    env['INCLUDE'] = ';'.join([winpath(os.path.join(REPO, 'headers')), winpath(REPO)])
    work = tempfile.mkdtemp(prefix='split-', dir=os.path.join(WORK, 'runs'))
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
    genv = dict(os.environ, C2SPLIT_OUT=events_path, C2SPLIT_FUNC=func, C2SPLIT_HERE=HERE)
    try:
        g = subprocess.run(['gdb', '-q', '-batch', '-nx', '-p', str(pid), '-ex',
                            'python exec(open(%r).read())' % os.path.join(HERE, 'c2split_gdb.py')],
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


# ---- rendering ---------------------------------------------------------------------------------------------
class Names:
    """web id -> label at one moment (ids are reused after rebuilds): built from a candidate snapshot and the tuple
    stream of the same moment (def / use lines of each web)"""
    def __init__(self, cands=None, rows=None):
        self.cands = {c['id']: c for c in (cands or [])}
        dl = collections.defaultdict(set); ul = collections.defaultdict(set)
        for r in rows or []:
            if r.get('label') or 'ids' in r or not r.get('line'): continue
            for side, acc in (('dst', dl), ('src', ul)):
                for d in r.get(side, []):
                    if 'c' in d: acc[d['c']].add(r['line'])
        self.deflines = {k: ','.join(map(str, sorted(v))) for k, v in dl.items()}
        self.uselines = {k: ','.join(map(str, sorted(v))) for k, v in ul.items()}

    def label(self, i):
        c = self.cands.get(i)
        if i is None: return '?'
        if not c: return '#%d' % i
        if c['name']:
            n = c['name']
            if n.startswith('_') and not n.startswith('__'): n = n[1:]
            return '%s#%d' % (n, i)
        if c.get('const'): return '%s#%d' % (c['const'].replace(' ', ':'), i)
        return 'tmp#%d' % i + ('(def L%s)' % self.deflines[i] if i in self.deflines else '')


def odesc(d, names):
    if d.get('k') == 6 and ('bc' in d or 'ic' in d):
        d = dict(d)
        for nm in ('b', 'i'):
            if nm + 'c' in d: d[nm] = '{%s}' % names.label(d[nm + 'c'])
    if d.get('k') == 1 and 'c' in d: return '{%s}' % names.label(d['c'])
    if d.get('k') == 1 and 'r' in d: return R32.get(d['r'], 'r%d' % d['r'])
    if d.get('k') == 2 and not d.get('sym'): return '[home]'
    if d.get('k') == 2: return '[%s]' % (d['sym'] or '').lstrip('_?').split('@')[0]
    return temps_ostr(d)


def render(row, names):
    if 'ids' in row:
        return 'cut marker {%s}' % ', '.join(names.label(i) for i in row['ids'])
    m = row.get('m') or ('op%d' % row['op'])
    if m == 'call':
        tg = [d for d in row.get('src', []) if d.get('k') in (2, 4) and d.get('sym')]
        return 'call ' + (tg[0]['sym'].lstrip('_?').split('@')[0] if tg else '?')
    subs = set()
    for d in row.get('dst', []) + row.get('src', []):
        if d.get('k') == 6: subs.update(d[x] for x in ('ba', 'ia') if x in d)
    dst = [d for d in row.get('dst', []) if shown(d) and d.get('a') not in subs]
    src = [d for d in row.get('src', []) if shown(d) and d.get('a') not in subs]
    if dst and src and odesc(src[0], names) == odesc(dst[0], names) and row['op'] != 1:
        src = src[1:]
    m = PSEUDO.get(row['op'], m)
    return (m + ' ' + ', '.join(odesc(d, names) for d in dst + src)).strip()


def ln(row):
    return 'L%s' % row['line'] if row.get('line') else 'L?'


def okeys(rows):
    """(tuple, side, index) -> operand, for every instruction operand of a stream snapshot"""
    out = {}
    for r in rows:
        if r.get('label') or 'ids' in r: continue
        for side in ('dst', 'src'):
            for i, d in enumerate(r.get(side, [])):
                out[(r['t'], side, i)] = (r, d)
    return out


# ---- analysis ------------------------------------------------------------------------------------------------
def split_rounds(evs):
    """cut the event stream into split rounds: everything up to and including one rebuild (rb_in / rb_out), with
    the priority round that preceded it and the one that followed it"""
    rounds = []; cur = dict(events=[]); prio = None; refs = []; last_prio = None
    for e in evs:
        if e['ev'] == 'prio_begin':
            refs = []
        elif e['ev'] == 'ref':
            refs.append(e)
        elif e['ev'] == 'prio_end':
            last_prio = dict(cands=e['cands'], refs=list(refs), cls=e['cls'])
            if rounds and rounds[-1].get('after') is None:
                rounds[-1]['after'] = last_prio
        elif e['ev'] == 'rb_in':
            cur['before'] = last_prio; cur['rb_in'] = e
        elif e['ev'] == 'rb_out':
            cur['rb_out'] = e; cur['after'] = None; rounds.append(cur); cur = dict(events=[])
            continue
        cur['events'].append(e)
    tail = cur
    return rounds, tail


def piece_table(rnd, final_rows):
    """for each web in the split set: what each of its operands became after the rebuild and at the end. An operand
    is followed by (tuple, side, index); a tuple whose opcode or line changed was freed and reused, so it counts as
    removed."""
    rin, rout = rnd['rb_in']['rows'], rnd['rb_out']['rows']
    split = set(rnd['rb_in']['ids'])
    kin, kout = okeys(rin), okeys(rout)
    kend = okeys(final_rows) if final_rows else {}
    def same(r1, r2): return r1['op'] == r2['op'] and r1.get('line') == r2.get('line')
    webs = collections.OrderedDict()
    for key, (row, d) in kin.items():
        c = d.get('c')
        if c not in split: continue
        after = kout.get(key)
        if after is None or not same(row, after[0]):
            what = ('removed', None)
        else:
            d2 = after[1]
            if 'c' in d2: what = ('piece', d2['c'])
            elif d2.get('k') == 1 and 't' in d2: what = ('temp', d2['t'])
            elif d2.get('k') in (2, 6): what = ('memory', None)
            else: what = ('other', None)
        end = kend.get(key); fin = None
        if end is not None and same(row, end[0]):
            de = end[1]
            fin = ('reg', de['r']) if de.get('k') == 1 and 'r' in de else \
                  ('temp', de.get('t')) if de.get('k') == 1 and 't' in de else ('memory', None)
        webs.setdefault(c, []).append(dict(key=key, row=row, side=key[1], what=what, fin=fin))
    return webs


def marks_in(rows, split, names):
    """cut markers of the split webs as they sit in a stream: (web ids, what the marker follows)"""
    prev = None; out = []
    for r in rows:
        if r.get('label'):
            prev = ('entry of block %d' % r['blk'], r); continue
        if 'ids' in r:
            ids = [i for i in r['ids'] if i in split]
            if ids: out.append((ids, prev))
            continue
        if r.get('instr'): prev = (render(r, names), r)
    return out


def fate(rounds, tail, n, pid):
    """what became of piece pid made by round n (1-based): coloured, split again or sent to memory. An id keeps
    naming the same web until a rebuild takes it."""
    for k in range(n, len(rounds) + 1):
        r = rounds[k] if k < len(rounds) else tail
        for e in r['events']:
            if e['ev'] == 'pick' and e['id'] == pid:
                return 'coloured %s%s' % (REGN.get(e['chosen'], '?'), ' (after the round %d rebuild)' % k if k > n else '')
            if e['ev'] == 'decide' and e['how'] == 'memory' and e.get('id') == pid:
                return 'sent to memory'
        if r.get('rb_in') and pid in r['rb_in']['ids']:
            return 'split again (round %d)' % (k + 1)
    return 'never coloured'


def fin_str(lst):
    fins = collections.Counter(o['fin'] for o in lst)
    parts = []
    for f, cnt in fins.items():
        if f is None: s = 'rewritten later'
        elif f[0] == 'reg': s = REGN.get(f[1], '?')
        elif f[0] == 'temp': s = 'memory (reload T%s)' % f[1]
        else: s = 'memory'
        parts.append(s + ('' if len(fins) == 1 else ' x%d' % cnt))
    return ', '.join(parts)


def report(evs, only=None, want_rounds=None, show_stream=False):
    funcs = [e['name'] for e in evs if e['ev'] == 'func']
    print('function:', ', '.join(funcs) or '(not reached - check --func)')
    errs = [e for e in evs if e['ev'] == 'error']
    if errs: print('hook errors:', errs[:3], file=sys.stderr)
    rounds, tail = split_rounds(evs)
    fin = [e for e in evs if e['ev'] == 'stream_end']
    final_rows = fin[-1]['rows'] if fin else None
    if not rounds:
        print('no split round: every web was coloured or sent to memory without a rebuild')
    for n, rnd in enumerate(rounds, 1):
        names = Names(rnd['rb_in'].get('cands'), rnd['rb_in']['rows'])
        for e in rnd['events']:           # webs sent to memory before the rebuild are no longer in its snapshot
            if e.get('cand') and e['cand']['id'] not in names.cands: names.cands[e['cand']['id']] = e['cand']
        after = Names(rnd['rb_out'].get('cands'), rnd['rb_out']['rows'])
        if rnd.get('after'):               # priorities of the pieces: the priority pass that follows the rebuild
            for c in rnd['after']['cands']:
                if c['id'] in after.cands: after.cands[c['id']] = c
        split = rnd['rb_in']['ids']
        if want_rounds and n not in want_rounds: continue
        if only and not any(names.label(i).split('#')[0] in only or str(i) in only for i in split):
            continue
        print('\n=== split round %d: rebuild of {%s} ===' % (n, ', '.join(names.label(i) for i in split)))
        # the colouring that led to it
        pops = [e for e in rnd['events'] if e['ev'] == 'pop']
        picks = {e['id']: e for e in rnd['events'] if e['ev'] == 'pick'}
        if pops:
            seq = []
            for p in pops[-6:]:
                pk = picks.get(p['id'])
                seq.append('%s %s' % (names.label(p['id']), REGN.get(pk['chosen'], '?') if pk else '(not coloured)'))
            print('  colouring before it (%s%d pops): %s' % ('last %d of ' % len(seq) if len(pops) > len(seq) else '',
                                                               len(pops), '; '.join(seq)))
        # why each web was cut: the hooked decision, else the call that inserted its markers
        why = collections.OrderedDict()
        for e in rnd['events']:
            if e['ev'] == 'nb_lost':
                why.setdefault(e['id'], []).append('lost its last register when %s was coloured%s' % (
                    names.label(e['who']), ' (crosses a call)' if e['cand']['f5'] & 0x80 else ''))
            elif e['ev'] == 'decide':
                how = e['how']; txt = HOW.get(how, how)
                if how == 'cut':
                    txt = txt % ' '.join(REGN.get(r, str(r)).lower() for r in e.get('regs', []))
                if e.get('cand'):
                    c = e['cand']
                    txt += ' [prio %d, refs %d%s]' % (c['prio'], c['refs'], ', crosses a call' if c['f5'] & 0x80 else '')
                if e.get('mode') in MODES and how not in ('memory',):
                    txt += '; during: ' + (MODES[e['mode']] % names.label(e['who']) if '%s' in MODES[e['mode']] else MODES[e['mode']])
                why.setdefault(e.get('id'), []).append(txt)
            elif e['ev'] == 'mark' and e.get('mode') == 'pressure':
                for i in e['ids']:
                    t = 'pressure cut while colouring %s: too many live webs for the free registers there (0x10b13460)' % names.label(e['who'])
                    if t not in why.get(i, []): why.setdefault(i, []).append(t)
        print('  why:')
        for i in list(why) + [i for i in split if i not in why]:
            for t in why.get(i, ['(no hooked decision)']):
                print('    %-26s %s' % (names.label(i), t))
        # markers, as they sit in the stream the rebuild receives
        marks = marks_in(rnd['rb_in']['rows'], set(split), names)
        if marks:
            print('  cut markers (the web is cut right after the instruction shown):')
            byweb = collections.OrderedDict()
            for ids, pv in marks:
                for i in ids: byweb.setdefault(i, []).append(pv)
            for i, lst in byweb.items():
                print('    %s:' % names.label(i))
                for pv in lst:
                    if pv is None: print('      at function entry')
                    elif pv[0].startswith('entry of block'):
                        print('      %s (loop depth %d)' % (pv[0], pv[1]['depth']))
                    else: print('      %-5s after `%s`' % (ln(pv[1]), pv[0]))
        # pieces
        webs = piece_table(rnd, final_rows)
        print('  pieces (each operand of the web, followed through the rebuild):')
        for c, ops in webs.items():
            if only and not (names.label(c).split('#')[0] in only or str(c) in only): continue
            cand = names.cands.get(c, {})
            print('    %s  [prio %s, refs %s; def L%s / use L%s]' % (names.label(c), cand.get('prio', '?'), cand.get('refs', '?'),
                  names.deflines.get(c, '-'), names.uselines.get(c, '-')))
            groups = collections.OrderedDict()
            for o in ops: groups.setdefault(o['what'], []).append(o)
            for (kind, pid), lst in groups.items():
                lines = sorted({o['row']['line'] for o in lst if o['row'].get('line')})
                lr = 'L%d-%d' % (lines[0], lines[-1]) if len(lines) > 1 and lines[0] != lines[-1] else ('L%d' % lines[0] if lines else 'L?')
                nd = sum(1 for o in lst if o['side'] == 'dst'); nu = len(lst) - nd
                if kind == 'piece':
                    pc = after.cands.get(pid, {})
                    col = fate(rounds, tail, n, pid)
                    print('      piece %-10s %-9s %d def / %d use  prio %s refs %s  %s; final %s' % (
                        after.label(pid), lr, nd, nu, pc.get('prio', '?'), pc.get('refs', '?'), col, fin_str(lst)))
                elif kind == 'temp':
                    print('      %-16s %-9s %d def / %d use  through fresh temporaries %s (reload / store of the home)' % (
                        'memory', lr, nd, nu, ', '.join('T%s' % o['what'][1] for o in lst)))
                elif kind == 'memory':
                    print('      %-16s %-9s %d def / %d use  the instruction reads / writes the home itself' % ('memory', lr, nd, nu))
                elif kind == 'removed':
                    print('      %-16s %-9s %d operand(s): instruction rewritten by the rebuild' % ('rewritten', lr, len(lst)))
                else:
                    print('      %-16s %-9s %d operand(s)' % (kind, lr, len(lst)))
        # copies inserted by the rebuild
        rin = rnd['rb_in']['rows']; rout = rnd['rb_out']['rows']
        tin = {r['t']: r for r in rin if not r.get('label')}
        tout = {r['t']: r for r in rout if not r.get('label')}
        def is_new(r): return r['t'] not in tin or tin[r['t']]['op'] != r['op'] or tin[r['t']].get('line') != r.get('line')
        new = [r for r in rout if not r.get('label') and r.get('instr') and is_new(r)]
        gone = [r for r in rin if not r.get('label') and r.get('instr') and
                (r['t'] not in tout or tout[r['t']]['op'] != r['op'] or tout[r['t']].get('line') != r.get('line'))]
        if new:
            print('  inserted by the rebuild (piece copies, spill stores, reloads):')
            for r in new: print('    %-5s blk %-3d %s' % (ln(r), r['blk'], render(r, after)))
        if gone:
            print('  removed by the rebuild:')
            for r in gone: print('    %-5s blk %-3d %s' % (ln(r), r['blk'], render(r, names)))
        if show_stream:
            print('  stream after the rebuild:')
            for r in rout:
                if r.get('label'): print('    --- block %d (loop depth %d)' % (r['blk'], r['depth'])); continue
                if r.get('instr') or 'ids' in r: print('    %-5s %s' % (ln(r), render(r, after)))
    # what is still in memory at the end, and the final registers of every web
    if final_rows:
        fe = fin[-1]
        names = Names(fe.get('cands'), [])
        if show_stream:
            print('\n=== final stream (after the allocator, before the local assigner) ===')
            for r in final_rows:
                if r.get('label'): print('    --- block %d (loop depth %d)' % (r['blk'], r['depth'])); continue
                if r.get('instr'): print('    %-5s %s' % (ln(r), render(r, names)))


def web_history(evs, name):
    """one variable through every split round, then where each of its references ended up"""
    funcs = [e['name'] for e in evs if e['ev'] == 'func']
    print('function:', ', '.join(funcs) or '(not reached - check --func)')
    rounds, tail = split_rounds(evs)
    fin = [e for e in evs if e['ev'] == 'stream_end']
    final_rows = fin[-1]['rows'] if fin else None
    def named(nm): return nm and (nm == name or nm.lstrip('_') == name)
    print('web history of %s (one line per split round that cut it):' % name)
    for n, rnd in enumerate(rounds, 1):
        names = Names(rnd['rb_in'].get('cands'), rnd['rb_in']['rows'])
        after = Names(rnd['rb_out'].get('cands'), rnd['rb_out']['rows'])
        if rnd.get('after'):
            for c in rnd['after']['cands']:
                if c['id'] in after.cands: after.cands[c['id']] = c
        mine = [i for i in rnd['rb_in']['ids'] if named((names.cands.get(i) or {}).get('name'))]
        if not mine: continue
        pops = [e for e in rnd['events'] if e['ev'] == 'pop']
        picks = {e['id']: e for e in rnd['events'] if e['ev'] == 'pick'}
        last = pops[-1] if pops else None
        trig = ('after %s %s' % (names.label(last['id']), REGN.get(picks[last['id']]['chosen'], '?') if last['id'] in picks
                                 else '(not coloured)')) if last else 'before colouring'
        webs = piece_table(rnd, final_rows)
        marks = marks_in(rnd['rb_in']['rows'], set(mine), names)
        for c in mine:
            cand = names.cands.get(c, {})
            how = sorted({e['how'] for e in rnd['events'] if e['ev'] == 'decide' and e.get('id') == c})
            if any(e['ev'] == 'mark' and e.get('mode') == 'pressure' and c in e['ids'] for e in rnd['events']):
                how.append('pressure')
            cuts = []
            for ids, pv in marks:
                if c not in ids: continue
                cuts.append('blk%d' % pv[1]['blk'] if pv and pv[0].startswith('entry') else (ln(pv[1]) if pv else 'entry'))
            print('  round %-3d %s %s (prio %s) cut [%s] at %s' % (n, trig, names.label(c), cand.get('prio', '?'),
                  ','.join(how) or '?', ' '.join(cuts) or '-'))
            groups = collections.OrderedDict()
            for o in webs.get(c, []): groups.setdefault(o['what'], []).append(o)
            for (kind, pid), lst in groups.items():
                lines = sorted({o['row']['line'] for o in lst if o['row'].get('line')})
                lr = ','.join(map(str, lines)) or '?'
                if kind == 'piece':
                    pc = after.cands.get(pid, {})
                    col = '-> ' + fate(rounds, tail, n, pid)
                    print('            piece %-10s lines %-22s prio %-5s %s' % (after.label(pid), lr, pc.get('prio', '?'), col))
                else:
                    print('            %-16s lines %s' % ({'temp': 'memory (reload)', 'memory': 'memory'}.get(kind, kind), lr))
    if final_rows:
        print('where each reference of %s ended up (stream after the allocator):' % name)
        nm = Names(fin[-1].get('cands'), [])
        for r in final_rows:
            if r.get('label') or not r.get('instr'): continue
            hits = []
            for side in ('dst', 'src'):
                for d in r.get(side, []):
                    if named(d.get('sym')):
                        hits.append('%s %s' % ('def' if side == 'dst' else 'use',
                                    REGN.get(d['r'], '?') if d.get('k') == 1 and 'r' in d else 'memory'))
            if hits:
                print('  %-5s blk %-3d %-34s %s' % (ln(r), r['blk'], render(r, nm)[:34], '; '.join(hits)))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source')
    ap.add_argument('--func', required=True, help='function name, decorated-name fragment, or 0xVA marker')
    ap.add_argument('--flags', default=None, help='extra cl flags after the fixed profile, e.g. "/GS-"; default: the '
                    'VA\'s flag rulings and the source\'s d2match opt-ins, as match.py applies them (c2prio.resolve_flags)')
    ap.add_argument('--ob1', action='store_true', help='use /Ob1 instead of /Ob2 (the d2match: ob1 opt-in)')
    ap.add_argument('--json', help='also write the raw event stream here')
    ap.add_argument('--events', help='skip compiling; report from an earlier --json file')
    ap.add_argument('--only', help='comma-separated web names or ids: only split rounds / pieces of these')
    ap.add_argument('--rounds', help='comma-separated split round numbers to print')
    ap.add_argument('--web', help='one variable: its pieces round by round and where each reference ended up')
    ap.add_argument('--stream', action='store_true', help='also print the stream after each rebuild and the final one')
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
        evp = os.path.abspath(a.json) if a.json else os.path.join(WORK, 'runs', 'split-%d.jsonl' % os.getpid())
        frag = name if name.startswith('?') else '?' + name + '@'
        out, glog, work = run_compile(src, c2prio.resolve_flags(src, a.func, a.flags), frag, evp, keep=a.keep, base=base)
        if a.keep: print('kept work folder (diag.obj):', work)
        if 'error' in out.lower():
            print(out)
        evs = load(evp)
        if not evs:
            print(glog[-3000:])
    if a.web:
        web_history(evs, a.web); return
    report(evs, set(a.only.split(',')) if a.only else None,
           {int(x) for x in a.rounds.split(',')} if a.rounds else None, a.stream)


if __name__ == '__main__':
    main()
