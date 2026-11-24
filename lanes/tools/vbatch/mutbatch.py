#!/usr/bin/env python3
"""mutbatch.py UNIT_REL BASE.cpp VA OUTDIR [minutes] [--seed N]
Batch hill-climb over lane 7's source mutations (lanes/vsearch/mutsearch.py's generator): every round compiles
all one-mutation neighbours of the current best as V_ copies in one build of the real unit (multi.py), keeps the
best, and on a plateau takes a random two-mutation kick. BASE.cpp is the unit with the function marked `// 0xVA`.
Score = difflines + 2*|length diff|. Writes OUTDIR/best.cpp (the whole unit) and OUTDIR/log.txt."""
import sys, os, re, random, subprocess, time, json
rel, base_path, va = sys.argv[1], os.path.abspath(sys.argv[2]), sys.argv[3]
out = os.path.abspath(sys.argv[4]); mins = float(sys.argv[5]) if len(sys.argv) > 5 and not sys.argv[5].startswith('--') else 60
if '--seed' in sys.argv: random.seed(int(sys.argv[sys.argv.index('--seed') + 1]))
os.makedirs(out, exist_ok=True); deadline = time.time() + 60 * mins
G = {'re': re, 'random': random}
src = open('/home/claude/iblis-codex/lanes/vsearch/mutsearch.py').read()
gen = src[src.index("ID = r'"):src.index('visited = set()')]
gen = gen.replace("a, b = body_span(t); f = t[a:b]", "a, b = 0, len(t); f = t")
# drop the &&/|| operand swap: it crosses macro arguments and moves null checks behind the dereference
_i = gen.index("        for m in re.finditer(r'\\((%s) (&&|")
_j = gen.index("        for m in re.finditer", _i + 10)
gen = gen[:_i] + gen[_j:]
assert '(&&|' not in gen
exec(gen, G)
text = open(base_path, encoding='latin-1').read()
mark = '// 0x%08X\n' % int(va, 16)
a = text.index('\n' + mark) + 1 + len(mark); b = text.index('\n}\n', a) + 3
func = text[a:b]
hdr = func[:func.index('{')]
name = re.search(r'([A-Za-z_]\w*)\s*\(', hdr).group(1)
nparams = 0 if re.search(r'\(\s*(void)?\s*\)', hdr) else hdr.count(',') + 1
static = bool(re.search(r'\bstatic\b', hdr.split(name)[0]))
log = open(os.path.join(out, 'log.txt'), 'a')
BATCH = 60


def render(f, k):
    return f.replace(name + '(', 'V_%04d(' % k, 1)


def score_batch(fs):
    res = {}
    for c in range(0, len(fs), BATCH):
        chunk = fs[c:c + BATCH]
        body = '\n'.join(render(f, c + i) for i, f in enumerate(chunk))
        if static:
            body += '\nvoid VCALLER_%s()\n{\n%s}\n' % (va[2:], ''.join('    V_%04d(%s);\n' % (c + i, ', '.join(['0'] * nparams)) for i in range(len(chunk))))
        p = '/tmp/mutbatch_%d.cpp' % os.getpid(); open(p, 'w', encoding='latin-1').write(body)
        env = dict(os.environ, INTO=base_path, ANCHOR=mark, WINEDEBUG='-all'); env.pop('TMPDIR', None)
        r = subprocess.run(['python3', '/home/claude/work/multi.py', rel, p, va], capture_output=True, text=True, env=env)
        for l in r.stdout.splitlines():
            m = re.search(r'V_(\d+)\s+len\s+(\d+)/(\d+) slot (\d) difflines\s+(\d+)', l)
            if m: res[int(m.group(1))] = int(m.group(5)) + 2 * abs(int(m.group(2)) - int(m.group(3)))
        if not any(c <= k < c + len(chunk) for k in res):
            # one bad variant fails the batch: split it in halves until the bad ones are alone
            if len(chunk) > 1:
                h = len(chunk) // 2
                for off, part in ((0, chunk[:h]), (h, chunk[h:])):
                    for i, s in enumerate(score_batch(part)):
                        if s < 10 ** 6: res[c + off + i] = s
    return [res.get(k, 10 ** 6) for k in range(len(fs))]


NARROW = re.compile(r'^\s*(const )?(short|unsigned short|char|unsigned char) \w+( = [^;]*)?;$')
def neighbours(f):
    a_, b_, L, M = G['mutations'](f)
    out = []
    for m in M:
        i, new = m
        # no narrowing of a local that was wider: it changes the arithmetic, not just the code
        if new != ('SWAP',) and NARROW.match(new) and not NARROW.match(L[i]):
            name_ = re.search(r'(\w+)( = [^;]*)?;$', new).group(1)
            init = re.search(r'= (.*);$', new)
            # allowed only for a flag-like local initialised with a constant
            if not (init and re.fullmatch(r'-?\d+', init.group(1).strip())): continue
        out.append(G['apply'](f, a_, b_, L, m))
    out += inline_single_use(f)
    return out


CONSTDEF = re.compile(r'^(\s*)(?:const )?(?:int|unsigned int|short|unsigned short|char|unsigned char|BOOL) (\w+) = ([^;]+);$')
def inline_single_use(f):
    """Fold a local used once into its use (and the reverse is what the original may have had)."""
    L = f.split('\n'); res = []
    for i, l in enumerate(L):
        m = CONSTDEF.match(l)
        if not m or '(' in m.group(3) and not re.fullmatch(r'[\w\[\]\.\->\s\(\)\*\+-]+', m.group(3)): continue
        name, expr = m.group(2), m.group(3)
        if re.search(r'\w\s*\(', expr): continue
        uses = [j for j in range(i + 1, len(L)) if re.search(r'\b%s\b' % name, L[j])]
        if len(uses) != 1: continue
        j = uses[0]
        if len(re.findall(r'\b%s\b' % name, L[j])) != 1: continue
        ids = set(re.findall(r'[A-Za-z_]\w*', expr))
        between = '\n'.join(L[i + 1:j + 1])
        if any(re.search(r'\b%s\b\s*([-+*/|&^]?=[^=]|\+\+|--)|(\+\+|--)\s*\b%s\b' % (x, x), between) for x in ids): continue
        if re.search(r'\b(for|while|do)\b', between): continue
        L2 = L[:]; L2[j] = re.sub(r'\b%s\b' % name, '(%s)' % expr, L2[j]); del L2[i]
        res.append('\n'.join(L2))
    return res


cur = func; cs = score_batch([cur])[0]; best = (cs, cur)
print('start', cs, flush=True); log.write('start %d\n' % cs)
seen = {hash(cur)}
while time.time() < deadline and cs > 0:
    N = [n for n in neighbours(cur) if hash(n) not in seen]
    if not N: break
    S = score_batch(N)
    for n in N: seen.add(hash(n))
    k = min(range(len(N)), key=lambda i: S[i])
    if S[k] < cs:
        cur, cs = N[k], S[k]
        if cs < best[0]:
            best = (cs, cur); open(os.path.join(out, 'best.cpp'), 'w', encoding='latin-1').write(text[:a] + cur + text[b:])
        print('improved', cs, '(%d tried)' % len(N), flush=True); log.write('improved %d\n' % cs); log.flush()
    else:
        ties = [N[i] for i in range(len(N)) if S[i] == cs]
        nxt = random.choice(ties) if ties and random.random() < 0.5 else None
        if nxt is None:
            n2 = random.choice(N); n3s = neighbours(n2); n3 = random.choice(n3s) if n3s else n2
            s3 = score_batch([n3])[0]
            if s3 < 10 ** 6: nxt, cs = n3, s3
        else:
            pass
        if nxt is not None: cur = nxt
        print('plateau at', S[k], 'move to', cs, 'best', best[0], flush=True); log.write('plateau %d best %d\n' % (S[k], best[0])); log.flush()
print('DONE best', best[0], flush=True); log.write('DONE %d\n' % best[0])
