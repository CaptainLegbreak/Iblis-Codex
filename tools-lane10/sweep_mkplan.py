"""mkplan.py <root> <module>[,<module>...] <out.json> : a rename plan for every old placeholder spelling, anywhere in
Source/, of a function defined in the given modules whose names.csv name is real. Old spellings are `sub_<VA>...`
and `<anything>_<VA>`; emit helpers, shims, inline copies and impl copies are other functions and are skipped."""
import csv, json, os, re, subprocess, sys, io, collections
root, mods, out = sys.argv[1], sys.argv[2].split(','), sys.argv[3]
U = json.load(open(root + '/build/units.json'))['units']
own = {int(f['va'], 16): u['file'] for u in U for f in u['functions']}
names = {int(r['address'], 16): r for r in csv.DictReader(open(root + '/names.csv'))}
funcs = {int(r[0], 16) for r in json.load(open(root + '/build/functions.json'))['functions']}
want = {a: names[a]['name'] for a in names if a in funcs and names[a]['source'] != 'placeholder'
        and own.get(a, '').split('/')[1:2] and own[a].split('/')[1] in mods and re.fullmatch(r'[A-Za-z_]\w*', names[a]['name'])
        and not (re.fullmatch(r'[a-z][a-z0-9_]*', names[a]['name']) and own[a].split('/')[1] != 'Storm')}   # bare lower-case names are C runtime names: not for game functions
txt = subprocess.run(['git', 'grep', '-h', '-o', '-E', r'\b(sub_[0-9A-F]{8}\w*|\w+_[0-9A-F]{8})\b', '--', 'Source'], cwd=root,
                     capture_output=True, text=True).stdout.split()
stems = {os.path.splitext(os.path.basename(u['file']))[0] for u in U}   # file names are not function names
SKIP = re.compile(r'_Emit_|Emit\d|Shim|_Inline|Inline_|_Impl|Impl_|_Copy|_Ctx|Context')
plan = []; seen = set(); per = collections.Counter()
for tok in txt:
    if tok in seen: continue
    if tok in stems or tok.startswith('Unknown_'): continue
    seen.add(tok)
    m = re.match(r'sub_([0-9A-F]{8})', tok) or re.search(r'_([0-9A-F]{8})$', tok)
    if not m: continue
    a = int(m.group(1), 16)
    if a not in want or tok == want[a] or SKIP.search(tok): continue
    plan.append(dict(va='0x%08X' % a, old=tok, new=want[a], cls=None, src=names[a]['source'], alt=1)); per[a] += 1
json.dump(plan, open(out, 'w'), indent=0)
print(len(plan), 'spellings of', len(per), 'functions')
