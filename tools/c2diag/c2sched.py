#!/usr/bin/env python3
"""c2sched.py - read what the pinned MSVC 2005 SP1 back end (c2.dll 14.00.50727.762) decides for one function AFTER
register allocation: the list scheduler's dependence graph, ready list and pick for every cycle of every region
(instruction order, callee-saved push / pop placement), the jump optimiser's changes (cross-jumping / tail merging,
threading, branch rewrites) and, with --passes, the tuple stream after every pass of the back-end pipeline with the
pass that last placed each final instruction. Owner-side diagnostic; see README.md ("c2sched").

usage: c2sched.py SOURCE --func NAME|0xVA [--flags "/GS- ..."] [--ob1] [--lines A-B] [--region N] [--cycles]
                  [--edges] [--jumps] [--passes [--diff]] [--early] [--json OUT] [--events FILE] [--keep]
"""
import argparse, json, os, re, shutil, subprocess, sys, tempfile, time, difflib

HERE = os.path.dirname(os.path.abspath(__file__))
LIB = os.environ.get('C2DIAG_LIB', HERE)           # where c2prio.py / c2temps.py / c2temps_gdb.py live
sys.path.insert(0, LIB)
import c2prio                                        # harness: paths, flags, marker lookup
from c2prio import WORK, TC, REPO, winpath, target_name
from c2temps import render as render_instr, R32

# Back-end pipeline call sites (c2.dll 14.00.50727.762): (callee, return address). The code generation driver at
# 0x10c06540 calls these in this order for every function; --passes snapshots the tuple stream after each one.
PIPELINE = [
    (0x10c99160, 0x10c068bb), (0x10bc4500, 0x10c0691a), (0x10ba34d0, 0x10c06944), (0x10b69110, 0x10c06964),
    (0x10c85230, 0x10c069aa), (0x10b9b620, 0x10c069da), (0x10c6e6d0, 0x10c069f2), (0x10bdd000, 0x10c06a26),
    (0x10b73c20, 0x10c06a6a), (0x10c6f7b0, 0x10c06a71), (0x10c6a2b0, 0x10c06aaa), (0x10c6a2b0, 0x10c06ab5),
    (0x10c6a770, 0x10c06ae0), (0x10bf7e00, 0x10c06b0c), (0x10ba5260, 0x10c06b19), (0x10b5d8b0, 0x10c06b3a),
    (0x10b5e2b0, 0x10c06b69), (0x10bdd9e0, 0x10c06b9f), (0x10b31fc0, 0x10c06bc6), (0x10b26b40, 0x10c06bdc),
    (0x10b73430, 0x10c06bfa), (0x10b98da0, 0x10c06c19), (0x10b2aed0, 0x10c06c4d), (0x10b26ca0, 0x10c06c6d),
    (0x10ba2540, 0x10c06c73), (0x10c5ad30, 0x10c06c80), (0x10baf600, 0x10c06c9b), (0x10bf0470, 0x10c06ca8),
    (0x10ba44d0, 0x10c06cea), (0x10b49300, 0x10c06d08), (0x10bf0470, 0x10c06d15), (0x10baf600, 0x10c06d39),
    (0x10cbce80, 0x10c06d4e), (0x10ba3980, 0x10c06d85), (0x10b80fb0, 0x10c06da8), (0x10b23ea0, 0x10c06db6),
    (0x10b24040, 0x10c06dbd), (0x10c084e0, 0x10c06dc2), (0x10ba3910, 0x10c06df0), (0x10b80fb0, 0x10c06e09),
    (0x10c3aa80, 0x10c06e31), (0x10b562e0, 0x10c06e53), (0x10c715f0, 0x10c06e73), (0x10be0340, 0x10c06e9a),
    (0x10baa730, 0x10c06ec1), (0x10cc2120, 0x10c06ef0), (0x10ba2e00, 0x10c06f10), (0x10c09cf0, 0x10c06f42),
    (0x10b2c6c0, 0x10c06f66), (0x10b9dfe0, 0x10c06f90), 
    (0x10c53da0, 0x10c06573), (0x10c5ba80, 0x10c072d2), (0x10b26b40, 0x10c072f0), (0x10b28470, 0x10c07310),
    (0x10b27660, 0x10c0731d), (0x10b27770, 0x10c07326), (0x10b85e90, 0x10c0732f), (0x10b2a180, 0x10c07336),
    (0x10ba2540, 0x10c0733c), (0x10b2bad0, 0x10c07391), (0x10b563f0, 0x10c073af), (0x10c57f80, 0x10c073ce),
    (0x10c52040, 0x10c073d4), (0x10b0cf40, 0x10c073f3), (0x10b26b40, 0x10c065ed),
    (0x10c65000, 0x10c07494), (0x10cbab30, 0x10c074cc), (0x10cb4c30, 0x10c074d3), (0x10c59460, 0x10c07502),
    (0x10bed0a0, 0x10c0751b), (0x10c52360, 0x10c07522), (0x10c593d0, 0x10c0753c), (0x10be8640, 0x10c0755c),
    (0x10c53e80, 0x10c075a7), (0x10c08320, 0x10c075e6), (0x10c2eb00, 0x10c07617),
    (0x10b2cae0, 0x10c07663), (0x10b26d50, 0x10c07669), (0x10b2c950, 0x10c0767e),
    (0x10b26b40, 0x10c076c0), (0x10c28970, 0x10c076c6), (0x10b2c3f0, 0x10c076f5), (0x10b26b40, 0x10c076fa),
    (0x10cc9e20, 0x10c07701), (0x10b26d50, 0x10c07707), (0x10b26bc0, 0x10c0773c), (0x10b26d50, 0x10c07742),
    (0x10c70930, 0x10c07759), (0x10c286f0, 0x10c07772), (0x10c559a0, 0x10c0661b),
    (0x10b2c950, 0x10c077b6), (0x10cae590, 0x10c077dd), (0x10b312c0, 0x10c0780c), (0x10b26e50, 0x10c0782c),
    (0x10b2c3f0, 0x10c07838), (0x10c5a390, 0x10c06647),
    (0x10c99fd0, 0x10c07879), (0x10b9f040, 0x10c078a8), (0x10cb4c80, 0x10c078cf), (0x10c284c0, 0x10c078e7),
    (0x10c71dc0, 0x10c07934), (0x10c58c40, 0x10c07953), (0x10c65e30, 0x10c07992),
    (0x10c9eab0, 0x10c079b3), (0x10b2a0e0, 0x10c079cf), (0x10c51640, 0x10c079ff), (0x10ba2290, 0x10c07a14),
    (0x10c5ae70, 0x10c07a36), (0x10b23700, 0x10c07a4e),
]
# What the passes seen to change the stream on the validation sources do (read from their effect, not decoded).
PASSNAME = {
    0x10b69110: 'block labels inserted', 0x10bf7e00: 'block labels removed', 0x10b31fc0: 'early jump cleanup',
    0x10baf600: 'operand canonicalisation', 0x10c06cc0: 'lowering to machine tuples',
    0x10b563f0: 'register variables bound', 0x10b0cf40: 'global colouring (c2prio)',
    0x10bda210: 'local assigner (c2temps)', 0x10c53e80: 'prologue / epilogue inserted (_epush/_epop/_eret)',
    0x10b26b40: 'block labels inserted', 0x10b26d50: 'block labels removed', 0x10c28970: 'copy peephole',
    0x10cc9e20: 'live-register pseudo-ops added', 0x10c286f0: 'live-register pseudo-ops removed',
    0x10b2c950: 'jump optimiser', 0x10c71dc0: 'list scheduler', 0x10b23700: 'pseudo-ops finalised',
    0x10b49300: 'global optimiser (CSE, propagation, threading of decided tests)', 0x10c5ba80: 'lowering to machine tuples',
    0x10b312c0: 'late block layout (moves blocks behind jmp/ret, duplicates small return tails)',
    0x10c06cc0: 'optimiser driver',
}
# Call sites inside one jump-optimiser sweep (0x10b2ccf0): (call VA, callee). The last one called before the sweep
# marks a change names the transform.
JCALLS = [
    (0x10b2cd8b, 0x10b26f90), (0x10b2cd9a, 0x10b27270), (0x10b2cdbf, 0x10b2d360), (0x10b2cdea, 0x10bf0ee0),
    (0x10b2cdf3, 0x10b27040), (0x10b2ce0a, 0x10b2d3b0), (0x10b2ce2f, 0x10bf0f20), (0x10b2ce38, 0x10b27040),
    (0x10b2ce52, 0x10b27040), (0x10b2ce7e, 0x10bf5360), (0x10b2cedb, 0x10bf7910), (0x10b2cf1a, 0x10bf0ee0),
    (0x10b2cf34, 0x10b28590), (0x10b2cf40, 0x10b28590), (0x10b2cf54, 0x10b306c0), (0x10b2cf68, 0x10b30f00),
    (0x10b2cf98, 0x10b321e0), (0x10b2cff3, 0x10bf7910), (0x10b2d00d, 0x10b2dc70), (0x10b2d056, 0x10b2d400),
    (0x10b2d065, 0x10b2d530), (0x10b2d0db, 0x10b2e1b0), (0x10b2d0ee, 0x10b2e700), (0x10b2d105, 0x10b2d890),
    (0x10b2d119, 0x10b2dff0), (0x10b2d134, 0x10b2d6c0), (0x10b2d161, 0x10b2eb00), (0x10b2d174, 0x10b2eff0),
    (0x10b2d184, 0x10b2f560), (0x10b2d1a6, 0x10b2f700), (0x10b2d1be, 0x10b2a400), (0x10b2d29a, 0x10b2dc70),
    (0x10b2d2e1, 0x10b2dc70), (0x10b2d317, 0x10c5cef0),
]
JNAME = {           # read from their effect on the validation sources (README), not decoded
    0x10b2e1b0: 'cross-jump: the instructions before a jmp that equal those before its target are deleted and the '
                'jmp retargeted into the other copy',
    0x10b306c0: 'cross-jump (mode 2): identical tails ending in the same jump or exit merged into one copy',
    0x10b27270: 'branch simplification: jcc over a jmp inverted, jump to the next tuple / unused label removed',
    0x10b2d400: 'jump to the next tuple removed',
    0x10b28590: 'jump threading: branches to a label followed by a jmp retargeted to its destination',
    0x10b2d530: 'tail call: call followed by a jump to the return turned into pop + jmp',
}
FLAGBITS = [(0x01, 'crit'), (0x02, 'brfeed'), (0x04, 'memrd'), (0x08, 'memwr'), (0x20, 'fixed')]
PRELUDE = 'int __cdecl c2sched_prelude_spin_(int a) { return a * 3 + 1; }\n'


def run_compile(src, flags, func, events_path, base, passes=False, jumps=True, early=False, timeout=900, keep=False):
    env = dict(os.environ, WINEDEBUG='-all')
    env['INCLUDE'] = ';'.join([winpath(os.path.join(REPO, 'headers')), winpath(REPO)])
    work = tempfile.mkdtemp(prefix='sched-', dir=os.path.join(WORK, 'runs'))
    extra = []
    if early:                     # a function compiled before the target, so every pass of the target is hooked
        pre = os.path.join(work, 'c2sched_prelude.h')
        open(pre, 'w').write(PRELUDE)
        extra = ['/FI' + winpath(pre)]
    cmd = ['wine', os.path.join(TC, 'cl.exe')] + base + flags + extra + \
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
    sites = [[ret - 5, callee, ret] for callee, ret in PIPELINE]
    genv = dict(os.environ, C2SCHED_OUT=events_path, C2SCHED_FUNC=func, C2SCHED_HERE=LIB,
                C2SCHED_PASSES='1' if passes else '0', C2SCHED_JUMPS='1' if jumps else '0',
                C2SCHED_SITES=json.dumps(sites), C2SCHED_JCALLS=json.dumps(JCALLS))
    try:
        g = subprocess.run(['gdb', '-q', '-batch', '-nx', '-p', str(pid), '-ex',
                            'python exec(open(%r).read())' % os.path.join(HERE, 'c2sched_gdb.py')],
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


# ---- rendering -----------------------------------------------------------------------------------------------------
class Labels:
    """stable names for branch-target labels (by label symbol), in order of first appearance"""
    def __init__(self): self.m = {}
    def name(self, sym):
        if sym not in self.m: self.m[sym] = 'L%d' % (len(self.m) + 1)
        return self.m[sym]


PSEUDO = {754: 'label', 755: 'block', 756: 'entry', 757: 'end', 759: 'params', 761: 'exit', 729: 'live'}


def rtext(row, labs, pseudo=True):
    if row is None: return '(sentinel)'
    if not row['instr']:
        if row.get('kind') == 27 and 'lab' in row: return '%s:' % labs.name(row['lab'])
        return '<%s>' % PSEUDO.get(row['op'], 'op%d' % row['op']) if pseudo else None
    s = render_instr(row)
    tg = [d['tgt'] for d in row.get('src', []) if d.get('k') == 4 and d.get('tgt')]
    m = row.get('m') or ''
    if tg and m != 'call':
        s = (m.lstrip('_') or 'branch') + ' ' + labs.name(tg[0])
    if m in ('', None) and row['op'] in (15, 16):
        s = {15: 'jcc', 16: 'jmp'}[row['op']] + (' ' + labs.name(tg[0]) if tg else '')
    return s.replace('_epush', 'push').replace('_epop', 'pop').replace('_eret', 'ret').replace('_imul2', 'imul')


def lab_of(line): return 'L%s' % line if line else ''


# ---- scheduler report ----------------------------------------------------------------------------------------------
def regions_of(evs):
    rs = []; cur = None; pending = None
    for e in evs:
        if e['ev'] == 'region_seen': pending = e
        elif e['ev'] == 'region':
            cur = dict(n=e['n'], dag=None, cycles=[], picks=[], seen=pending); rs.append(cur)
        elif cur is None: continue
        elif e['ev'] == 'dag': cur['dag'] = e
        elif e['ev'] == 'cycle': cur['cycles'].append(dict(e, tries=[]))
        elif e['ev'] in ('try', 'time') and cur['cycles']: cur['cycles'][-1]['tries'].append(e)
        elif e['ev'] == 'pick':
            cur['picks'].append(e)
            if cur['cycles']: cur['cycles'][-1]['tries'].append(e)
    return rs


def terms(n):
    fl = n['flags']; t = []
    if fl & 2: t.append('brfeed 2^23')
    if fl & 4: t.append('memrd 2^15')
    t.append('(h%d+s%d)*1024' % (n['height'], n['nsucc']))
    calc = (2 ** 23 if fl & 2 else 0) + (2 ** 15 if fl & 4 else 0) + (n['height'] + n['nsucc']) * 1024
    return ' + '.join(t), calc


def sched_report(evs, labs, lines=None, region=None, show_cycles=True, show_edges=False, final=None):
    funcs = [e['name'] for e in evs if e['ev'] == 'func']
    rs = regions_of(evs)
    if not rs:
        print('no scheduled region (the function did not reach the scheduler, or every region had one instruction)')
        return
    final_pos = {}
    if final:
        k = 0
        for r in final['rows']:
            if r['instr']: final_pos[r['t']] = k; k += 1
    print('list scheduler: %d regions scheduled. Priority = brfeed (feeds the closing branch) 2^23 + memrd (reads '
          'memory) 2^15 + (height + successors) * 1024; the ready list is kept by priority, ties by node number '
          '(the order the local assigner left), and the first ready node with a free unit whose operands are ready '
          'issues.' % len(rs))
    bad = 0
    for r in rs:
        d = r['dag']
        if d is None: continue
        nodes = {n['id']: n for n in d['nodes']}
        ins = [n for n in d['nodes'] if n['row'] and n['row']['instr']]
        lns = [n['row']['line'] for n in ins if n['row']['line']]
        if region and r['n'] != region: continue
        if lines and (not lns or max(lns) < lines[0] or min(lns) > lines[1]): continue
        order = [p['id'] for p in r['picks']]
        moved = [i for i in order if nodes[i]['row'] and nodes[i]['row']['instr']]
        inorder = [n['id'] for n in ins]
        print('\n=== region %d: %s, %d instructions; issued %s' % (
            r['n'], ('L%d-L%d' % (min(lns), max(lns))) if lns else 'no lines', len(ins),
            'in the incoming order' if moved == inorder else 'in a new order'))
        print('  %-4s %-5s %-34s %4s %4s %-22s %8s  %s' % ('node', 'line', 'instruction (incoming order)', 'h', 'succ',
              'flags', 'prio', 'successors (latency)'))
        for n in d['nodes']:
            row = n['row']
            txt = rtext(row, labs) if row else ('(top)' if n['id'] == d['first'] else '(bottom)')
            fl = ','.join(nm for b, nm in FLAGBITS if n['flags'] & b)
            tt, calc = terms(n)
            pr = '%d' % n['prio'] + ('' if calc == n['prio'] or not row else '!')
            sc = ' '.join('n%d(%d%s)' % (s['to'], s['lat'], ',k%x' % s['kind'] if s['kind'] else '') for s in n['succ'])
            print('  n%-3d %-5s %-34s %4d %4d %-22s %8s  %s' % (n['id'], lab_of(row['line'] if row else None),
                  txt[:34], n['height'], n['nsucc'], fl, pr, sc if show_edges or len(sc) < 60 else sc[:57] + '...'))
        if show_cycles:
            print('  cycle  ready list (node:priority/earliest, best first)               issued     not issued')
            for c in r['cycles']:
                rl = ' '.join('n%d:%d/%d' % (i, k, e) for i, k, e in c['ready'])
                issued = [t['id'] for t in c['tries'] if t['ev'] == 'pick']
                why = []; cur = {}
                for t in c['tries']:
                    if t['ev'] == 'try' and t['unit'] < 0: why.append('n%d unit busy' % t['id'])
                    elif t['ev'] == 'time' and t['early'] > t['limit']:
                        why.append('n%d waits (ready c%d)' % (t['id'], t['early']))
                print('  c%-5d %-62s %-10s %s' % (c['cyc'], rl[:62], ' '.join('n%d' % i for i in issued) or '-',
                      '; '.join(why)))
        print('  issue order: ' + ' '.join('n%d' % i for i in moved))
        if moved != inorder:
            sm = difflib.SequenceMatcher(None, inorder, moved, autojunk=False)
            keep = set()
            for tag, i1, i2, j1, j2 in sm.get_opcodes():
                if tag == 'equal': keep.update(moved[j1:j2])
            print('  moved against the incoming order: ' + ', '.join('n%d %s' % (i, rtext(nodes[i]['row'], labs))
                                                                    for i in moved if i not in keep))
        if final_pos:
            alive = [i for i in moved if nodes[i]['t'] in final_pos]
            ok = sorted(alive, key=lambda i: final_pos[nodes[i]['t']]) == alive
            if not ok: bad += 1
            gone = len(moved) - len(alive)
            print('  final stream: %s%s' % ('same order (checked)' if ok else 'DIFFERS from the issue order (a later pass moved it)',
                  ', %d deleted later' % gone if gone else ''))
    if final_pos and bad == 0:
        print('\nevery scheduled region appears in the final tuple stream in the scheduler\'s issue order.')


# ---- jump optimiser report -----------------------------------------------------------------------------------------
def stream_lines(rows, labs, pseudo=False):
    out = []
    for r in rows:
        txt = rtext(r, labs, pseudo=pseudo or r.get('kind') == 27)
        if txt is None: continue
        out.append(('%-5s %s' % (lab_of(r['line']), txt), r['t']))
    return out


def jump_report(evs, labs, context=2):
    print('\n=== jump optimiser (0x10b2c950; mode 0 runs right after the local assigner and the prologue, mode 2 after '
          'the copy peephole, before the late block layout and the scheduler)')
    prev = None; nchg = 0
    for e in evs:
        if e['ev'] != 'snap': continue
        lines = stream_lines(e['rows'], labs)
        if e['tag'].startswith('jumpopt') and 'jfn' in e and prev is not None:
            nchg += 1
            fn = e.get('jfn')
            print('\n  change %d: mode %s, sweep %s%s: %s' % (
                nchg, e.get('jmode'), e.get('jiter'), (', at ' + lab_of(e['atline'])) if e.get('atline') else '',
                ('0x%x' % fn) + (' ' + JNAME[fn] if fn in JNAME else '') if fn else 'inline'))
            for dl in difflib.unified_diff([l for l, _ in prev], [l for l, _ in lines], lineterm='', n=context):
                if dl.startswith(('---', '+++')): continue
                print('    ' + dl)
        prev = lines
    if not nchg:
        print('  no changes')


# ---- pass trace ----------------------------------------------------------------------------------------------------
def pass_name(e):
    c = e.get('callee')
    if c is None: return e['tag']
    nm = PASSNAME.get(c, 'pass')
    if c == 0x10b2c950: nm += ' mode %s' % ('0' if e.get('site') == 0x10c07679 else '2')
    return '%s (0x%x)' % (nm, c)


def pass_report(evs, labs, show_diff=False, lines=None):
    snaps = [e for e in evs if e['ev'] == 'snap' and (not e['tag'].startswith('jumpopt') or e['tag'].endswith(': end'))]
    if len(snaps) < 2:
        print('no pass snapshots (use --passes)'); return
    print('\n=== passes that changed the tuple stream (in pipeline order; "moved" = instructions whose order relative to '
          'the others changed, "new" = instruction tuples that did not exist before)')
    placed = {}; prev = None
    for s in snaps:
        ins = [r['t'] for r in s['rows'] if r['instr']]
        name = ('jump optimiser mode %s (0x10b2c950)' % s.get('jmode')) if s['tag'].startswith('jumpopt') else \
               (pass_name(s) if 'callee' in s else s['tag'])
        moved = new = 0
        if prev is not None:
            old = [r['t'] for r in prev['rows'] if r['instr']]
            olds = set(old)
            sm = difflib.SequenceMatcher(None, old, ins, autojunk=False)
            keep = set()
            for tag, i1, i2, j1, j2 in sm.get_opcodes():
                if tag == 'equal': keep.update(ins[j1:j2])
            for t in ins:
                if t not in olds: placed[t] = name + ' (new)'; new += 1
                elif t not in keep: placed[t] = name; moved += 1
            if prev['rows'] == s['rows']: continue
        else:
            for t in ins: placed[t] = 'first snapshot'
        print('  %-62s %4d tuples, %3d moved, %3d new' % (name[:62], len(s['rows']), moved, new))
        if show_diff and prev is not None:
            a = stream_lines(prev['rows'], labs); b = stream_lines(s['rows'], labs)
            for dl in difflib.unified_diff([l for l, _ in a], [l for l, _ in b], lineterm='', n=1):
                if dl.startswith(('---', '+++')): continue
                print('      ' + dl)
        prev = s
    fin = snaps[-1]
    print('\n=== final instruction order, with the last pass that moved (or created) each instruction')
    cur = None
    for r in fin['rows']:
        if not (r['instr'] or r.get('kind') == 27): continue
        ln = r['line'] or cur; cur = ln
        if lines and (ln is None or ln < lines[0] or ln > lines[1]): continue
        print('  %-5s %-36s %s' % (lab_of(r['line']), rtext(r, labs)[:36], placed.get(r['t'], '') if r['instr'] else ''))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source')
    ap.add_argument('--func', required=True, help='function name, decorated-name fragment, or 0xVA marker')
    ap.add_argument('--flags', default=None, help='extra cl flags after the fixed profile, e.g. "/GS-"; default: the '
                    'VA\'s flag rulings and the source\'s d2match opt-ins, as match.py applies them (c2prio.resolve_flags)')
    ap.add_argument('--ob1', action='store_true', help='use /Ob1 instead of /Ob2 (the d2match: ob1 opt-in)')
    ap.add_argument('--lines', help='only regions / final instructions within source lines A-B')
    ap.add_argument('--region', type=int, help='only scheduler region N')
    ap.add_argument('--no-cycles', action='store_true', help='omit the cycle-by-cycle ready list')
    ap.add_argument('--edges', action='store_true', help='print every successor edge (long lines)')
    ap.add_argument('--jumps', action='store_true', help='report the jump optimiser\'s changes (cross-jumps etc.)')
    ap.add_argument('--passes', action='store_true', help='snapshot the stream after every back-end pass')
    ap.add_argument('--diff', action='store_true', help='with --passes: print each pass\'s change')
    ap.add_argument('--early', action='store_true', help='force-include a prelude function compiled first, so the '
                    'passes before global colouring are also seen for the first function of the file')
    ap.add_argument('--json', help='also write the raw event stream here')
    ap.add_argument('--events', help='skip compiling; report from an earlier --json file')
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
        evp = os.path.abspath(a.json) if a.json else os.path.join(WORK, 'runs', 'sched-%d.jsonl' % os.getpid())
        frag = name if name.startswith('?') else '?' + name + '@'
        out, glog, work = run_compile(src, c2prio.resolve_flags(src, a.func, a.flags), frag, evp, base, passes=a.passes, jumps=True,
                                      early=a.early, keep=a.keep)
        if a.keep: print('kept work folder (diag.obj):', work)
        if 'error' in out.lower():
            print(out)
        evs = load(evp)
    errs = [e for e in evs if e['ev'] in ('error', 'snaperr')]
    if errs: print('hook errors:', errs[:3], file=sys.stderr)
    funcs = []
    for e in evs:
        if e['ev'] == 'func' and e['name'] not in funcs: funcs.append(e['name'])
    print('function:', ', '.join(funcs) or '(not reached - check --func)')
    lines = tuple(int(x) for x in a.lines.split('-')) if a.lines else None
    labs = Labels()
    fin = [e for e in evs if e['ev'] == 'snap' and e['tag'] == 'pipeline end']
    sched_report(evs, labs, lines, a.region, not a.no_cycles, a.edges, fin[-1] if fin else None)
    if a.jumps: jump_report(evs, labs)
    if a.passes: pass_report(evs, labs, a.diff, lines)


if __name__ == '__main__':
    main()
