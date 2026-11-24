"""dedupe.py <root> <va,...> : for each function address, in every unit (.cpp/.c) of Source/ that declares it more than
once (prototypes ending in `; // 0x<VA>`, not the definition), keep one declaration and drop the others: the one whose
parameter and return types match the defining file's prototype if there is one, else the first. Functions defined as
class members (`X::name`) are skipped: their declarations belong in the class. Prints what it changed."""
import json, os, re, sys, glob
root, vas = sys.argv[1], [int(v, 16) for v in sys.argv[2].split(',') if v]
own = {int(f['va'], 16): u['file'] for u in json.load(open(root + '/build/units.json'))['units'] for f in u['functions']}


def norm(proto):
    p = re.sub(r'//.*', '', proto).strip().rstrip(';').strip()
    p = re.sub(r'^\s*(extern\s+"C"\s+)?(extern\s+)?(static\s+)?(inline\s+)?', '', p)
    m = re.match(r'(.*?)\b(\w+)\s*\((.*)\)\s*$', p, re.S)
    if not m:
        return None
    ret, args = m.group(1), m.group(3)
    parts = []
    for a in [x.strip() for x in args.split(',')] if args.strip() not in ('', 'void') else []:
        a = re.sub(r'\b(const|struct)\b', lambda k: k.group(1), a)
        a = re.sub(r'\s*\b[A-Za-z_]\w*\s*$', '', a) if re.search(r'[\w\*&]\s+[A-Za-z_]\w*\s*$', a) else a
        parts.append(re.sub(r'\s+', '', a))
    return re.sub(r'\s+', '', ret), tuple(parts)


changed = 0
for va in vas:
    tag = '0x%08X' % va
    df = own.get(va)
    if not df:
        continue
    t = open(os.path.join(root, df), encoding='latin-1').read()
    m = re.search(r'^// %s\s*\n([^\n{;]*\([^)]*\))' % tag, t, re.M)
    if not m or '::' in m.group(1).split('(')[0]:
        continue
    ref = norm(m.group(1) + ';')
    for f in glob.glob(root + '/Source/**/*.*', recursive=True):
        if not re.search(r'\.(cpp|c|h)$', f, re.I):
            continue
        L = open(f, encoding='latin-1').read().split('\n')
        idx = [i for i, l in enumerate(L) if re.search(r';\s*//\s*%s\b' % tag, l) and '(' in l and '=' not in l.split('//')[0]]
        if len(idx) < 2:
            continue
        keep = next((i for i in idx if norm(L[i]) == ref), idx[0])
        for i in idx:
            if i != keep:
                L[i] = None
        open(f, 'w', encoding='latin-1', newline='').write('\n'.join(l for l in L if l is not None))
        changed += 1
        print(tag, os.path.relpath(f, root), 'kept line', keep + 1, 'dropped', len(idx) - 1)
print('files changed', changed)
