#!/usr/bin/env python3
"""objmap.py OUT.md [OUT.json]: evidence for which original object each placeholder file (Unknown_<addr>.cpp) belongs to.

Reads the original Game.exe (local.json), build/units.json and build/data_plan.json, and the sources' address
markers on global definitions. For every placeholder unit it scores every other unit on:
  path    the source path strings its functions pass (".\\UI\\editbox.cpp") against the files' names
  static  call edges to or from a function that only that pair of units calls (a file static or private helper)
  data    references to data that unit defines, more if nobody else references it
  place   the placeholder's code sitting inside, or right next to, that unit's address run
and lists the best candidates with their evidence. It also lists named, whole files whose address run has
placeholder code inside it. Candidates only: a join still has to build equal."""
import sys, os, re, json, bisect, subprocess, tempfile, collections
_CWD = os.getcwd()
ROOT = os.environ.get('IBLIS_ROOT', '/home/claude/captainlegbreak/iblis-codex')
sys.path.insert(0, ROOT + '/tools'); os.chdir(ROOT)
from common import PE, load_json, settings
OUT_MD = os.path.join(_CWD, sys.argv[1]); OUT_JSON = os.path.join(_CWD, sys.argv[2]) if len(sys.argv) > 2 else None

pe = PE(settings()['image']); IB = pe.image_base
units = [u for u in load_json('units.json')['units'] if not u['file'].startswith('Source/StandIns')]
fstart, fend, fowner = [], [], []
for u in units:
    for f in u['functions']:
        fstart.append(int(f['va'], 16)); fend.append(int(f['va'], 16) + f['length']); fowner.append(u['file'])
order = sorted(range(len(fstart)), key=lambda i: fstart[i])
fstart = [fstart[i] for i in order]; fend = [fend[i] for i in order]; fowner = [fowner[i] for i in order]


def func_at(a):
    i = bisect.bisect_right(fstart, a) - 1
    return i if i >= 0 and a < fend[i] else None


# --- data owners: the data plan's definitions, then address markers on global definitions in the sources
dstart, dend, downer = [], [], []
for d in load_json('data_plan.json')['definitions']:
    v = int(d['va'], 16); dstart.append(v); dend.append(v + max(1, d['size'])); downer.append(d['file'])
GDEF = re.compile(r'^(?!extern\b)(?!\s)(?!//)(?!#)[^(){};]*?\b[gs][A-Za-z_]\w*(\s*\[[^\]]*\])*\s*(=[^;]*)?;\s*//\s*0x([0-9A-Fa-f]{8})\b', re.M)
for u in units:
    try:
        t = open(u['file'], encoding='latin-1').read()
    except OSError:
        continue
    for m in GDEF.finditer(t):
        v = int(m.group(3), 16); dstart.append(v); dend.append(v + 1); downer.append(u['file'])
o2 = sorted(range(len(dstart)), key=lambda i: dstart[i])
dstart = [dstart[i] for i in o2]; dend = [dend[i] for i in o2]; downer = [downer[i] for i in o2]


def data_owner(a):
    i = bisect.bisect_right(dstart, a) - 1
    if i >= 0 and (a < dend[i] or (dend[i] - dstart[i] == 1 and a - dstart[i] < 4)):
        return downer[i], dstart[i]
    return None, None


secs = {s['name']: s for s in pe.sections}
text = secs['.text']; tlo = IB + text['va']; thi = tlo + text['vsize']
data_ranges = [(IB + s['va'], IB + s['va'] + max(s['vsize'], s['rawsize'])) for s in pe.sections if s['name'] in ('.rdata', '.data')]
in_data = lambda a: any(lo <= a < hi for lo, hi in data_ranges)

# --- source path strings in .rdata / .data
paths = {}
for s in pe.sections:
    if s['name'] not in ('.rdata', '.data'): continue
    raw = pe.data[s['rawptr']:s['rawptr'] + s['rawsize']]
    for m in re.finditer(rb'[ -~]{4,200}?\.(?:cpp|CPP|Cpp|c|C)\0', raw):
        sv = m.group(0)[:-1].decode('latin-1')
        if '\\' in sv or '/' in sv:
            paths[IB + s['va'] + m.start()] = sv
stem = lambda p: re.split(r'[\\/]', p)[-1].rsplit('.', 1)[0].lower()

# --- disassemble .text once
with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as f:
    f.write(pe.data[text['rawptr']:text['rawptr'] + min(text['rawsize'], text['vsize'])]); binp = f.name
p = subprocess.Popen(['objdump', '-D', '-b', 'binary', '-mi386', '-Mintel', '--no-show-raw-insn', '--adjust-vma=0x%x' % tlo, binp],
                     stdout=subprocess.PIPE, text=True)
calls = collections.defaultdict(set)        # caller func index -> callee func indices
drefs = collections.defaultdict(set)        # func index -> data addresses (owner start)
pathuse = collections.defaultdict(set)      # func index -> path strings
HEX = re.compile(r'0x([0-9a-f]{6,8})\b')
for line in p.stdout:
    if ':\t' not in line: continue
    a, ins = line.split(':\t', 1)
    try: a = int(a, 16)
    except ValueError: continue
    fi = func_at(a)
    if fi is None: continue
    m = re.match(r'\s*(call|jmp)\s+0x([0-9a-f]+)\s*$', ins)
    if m:
        t = int(m.group(2), 16); ti = func_at(t)
        if ti is not None and ti != fi and fowner[ti] != fowner[fi]: calls[fi].add(ti)
        elif ti is not None and ti != fi: calls[fi].add(ti)
        continue
    for h in HEX.findall(ins):
        v = int(h, 16)
        if v in paths: pathuse[fi].add(paths[v])
        if in_data(v):
            o, st = data_owner(v)
            if o: drefs[fi].add((o, st))
p.wait(); os.unlink(binp)

callers = collections.defaultdict(set)
for fi, cs in calls.items():
    for ti in cs: callers[ti].add(fi)
datausers = collections.defaultdict(set)
for fi, ds in drefs.items():
    for o, st in ds: datausers[(o, st)].add(fowner[fi])

byunit = collections.defaultdict(list)
for i, o in enumerate(fowner): byunit[o].append(i)
STEMRE = re.compile(r'^(.*/)([A-Za-z0-9]+?)(_[0-9A-F]{8})?\.(cpp|CPP|c)$')
def file_stem(f):
    m = STEMRE.match(f); return m.group(2).lower() if m else os.path.basename(f).lower()
is_ph = lambda f: '/Unknown_' in f
named_by_stem = collections.defaultdict(set)
for f in byunit:
    if not is_ph(f): named_by_stem[file_stem(f)].add(f)
# unit runs in address order
runs = collections.OrderedDict()
seq = []
for i in range(len(fstart)):
    if not seq or seq[-1][0] != fowner[i]: seq.append([fowner[i], i, i])
    else: seq[-1][2] = i
span = {}
for f, a, b in seq:
    lo, hi = span.get(f, (a, b)); span[f] = (min(lo, a), max(hi, b))


def lane(f):
    mod = f.split('/')[1]; v = min(fstart[i] for i in byunit[f])
    if mod == 'D2Client': return 1 if v >= 0x4A0000 else 4
    return {'D2Game': 5, 'D2Common': 8, 'Storm': 3, 'Fog': 3, 'SRP': 3, 'D2Gfx': 9, 'D2Direct3D': 9, 'D2DDraw': 9,
            'D2Gdi': 9, 'D2Glide': 9, 'D2Hell': 9}.get(mod, 6)


report = []
for P in sorted(byunit):
    if not is_ph(P): continue
    fis = byunit[P]
    score = collections.Counter(); ev = collections.defaultdict(list)
    # path strings
    ps = collections.Counter(stem(s) for fi in fis for s in pathuse[fi])
    path_note = []
    for st_, n in ps.items():
        cands = named_by_stem.get(st_, set())
        if cands:
            for F in cands: score[F] += 10 * n; ev[F].append('path %s.cpp x%d' % (st_, n))
        else:
            path_note.append('%s.cpp x%d (no file of that name yet)' % (st_, n))
    # static-like call edges: callee called only from this pair of units
    for fi in fis:
        for ti in calls[fi]:
            F = fowner[ti]
            if F == P: continue
            if {fowner[c] for c in callers[ti]} <= {P, F}:
                score[F] += 3; ev[F].append('calls %08X, used only by the two' % fstart[ti])
        cs = {fowner[c] for c in callers[fi]} - {P}
        if len(cs) == 1:
            F = cs.pop(); score[F] += 3; ev[F].append('%08X called only from it' % fstart[fi])
    # data
    for fi in fis:
        for o, st_ in drefs[fi]:
            if o == P: continue
            us = datausers[(o, st_)]
            w = 2 if us <= {P, o} else 1
            score[o] += w; ev[o].append('data %08X%s' % (st_, ' (only these two use it)' if w == 2 else ''))
    # place: P's run sits between two runs of the same unit (a sandwich), or right next to a unit's run
    k = [x for x in seq if x[0] == P]
    for f_, i0, i1 in k:
        j = seq.index([f_, i0, i1])
        before = seq[j - 1][0] if j > 0 else None; after = seq[j + 1][0] if j + 1 < len(seq) else None
        if before and before == after:
            score[before] += 8; ev[before].append('sits between two runs of it')
        else:
            for nb in (before, after):
                if nb: score[nb] += 2; ev[nb].append('next to it')
    mod = P.split('/')[1]
    for F in list(score):
        if F.split('/')[1] != mod: del score[F]
    best = score.most_common(3)
    def summ(F):
        c = collections.Counter(re.sub(r'[0-9A-F]{8}', '#', e) for e in ev[F])
        return '; '.join('%s%s' % (k_, ' x%d' % n if n > 1 else '') for k_, n in c.most_common(6))
    report.append(dict(file=P, lane=lane(P), functions=len(fis), first='0x%08X' % fstart[min(fis)],
                       best=[dict(file=F, score=s, evidence=summ(F)) for F, s in best], path_note=path_note))

enclosed = []
for F in span:
    if is_ph(F) or len(named_by_stem.get(file_stem(F), ())) != 1: continue
    inside = sorted({seq[j][0] for j in range(1, len(seq) - 1) if is_ph(seq[j][0]) and seq[j - 1][0] == F and seq[j + 1][0] == F})
    if inside: enclosed.append((F, inside))
if OUT_JSON: json.dump(dict(placeholders=report, whole_with_placeholders_inside=enclosed), open(OUT_JSON, 'w'), indent=1)
L = ['# Placeholder object map (candidates)', '',
     'Generated by `objmap.py` from the original image and the build data. Score: path string 10 per use, a call',
     'edge only the pair uses 3, data 1 (2 if only the pair uses it), sitting between two runs of the other file 8,',
     'next to it 2. Only files of the same module are candidates. A candidate is a lead, not a verdict: a join still has to build equal.', '']
for ln in sorted({r['lane'] for r in report}):
    rs = [r for r in report if r['lane'] == ln]
    strong = [r for r in rs if r['best'] and r['best'][0]['score'] >= 4 and (len(r['best']) == 1 or r['best'][0]['score'] >= 2 * r['best'][1]['score'])]
    for r in rs: r['clear'] = r in strong
    L.append('## Lane %d: %d placeholder files, %d with a clear lead' % (ln, len(rs), len(strong))); L.append('')
    for r in sorted(rs, key=lambda r: -(r['best'][0]['score'] if r['best'] else 0)):
        if not r['best'] and not r['path_note']: continue
        head = '- %s`%s` (%d functions, %s)' % ('**clear** ' if r['clear'] else '', r['file'].split('/', 2)[2], r['functions'], r['first'])
        if r['path_note']: head += ', path strings: ' + ', '.join(r['path_note'])
        L.append(head)
        for b in r['best']:
            L.append('  - %d `%s`: %s' % (b['score'], b['file'].split('/', 2)[2], b['evidence']))
    L.append('')
L.append('## Whole named files with placeholder code sitting between two of their runs (%d)' % len(enclosed)); L.append('')
for F, inside in sorted(enclosed):
    L.append('- `%s`: %s' % (F.split('/', 2)[2], ', '.join('`%s`' % x.split('/')[-1] for x in inside)))
open(OUT_MD, 'w').write('\n'.join(L) + '\n')
print('placeholders', len(report), 'enclosed', len(enclosed))
if OUT_JSON: json.dump(dict(placeholders=report, whole_with_placeholders_inside=enclosed), open(OUT_JSON, 'w'), indent=1)
