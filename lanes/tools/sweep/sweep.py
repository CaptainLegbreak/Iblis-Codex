#!/usr/bin/env python3
"""sweep.py OUT.json [UNIT_REL ...]: for every `// build: context NAME` line in the units (all non-LTCG units by default),
test on the current checkout whether the unit still compares equal for all its functions
  (a) without that directive line (no recompile: the line is a comment), and
  (b) with the copy itself removed (its definition replaced by its prototype; one compile each).
Read-only: units are compiled from temporary copies. Results go to OUT.json, one record per directive."""
import sys, os, re, json, subprocess, tempfile, shutil
ROOT = os.environ.get('IBLIS_ROOT', '/home/claude/captainlegbreak/iblis-codex')
OUT = os.path.abspath(sys.argv[1])
sys.path.insert(0, ROOT + '/tools'); os.chdir(ROOT)
import checker
from common import settings, compile_env, unit_env, cl_command, expand_gen_includes, PE, default_flags, load_json

S = settings(); ENV = compile_env(S); pe = PE(S['image'])
L = {int(r[0], 16): int(r[1]) for r in load_json('functions.json')['functions']}
UNITS = [u for u in load_json('units.json')['units'] if not u.get('ltcg') and not u['file'].startswith('Source/StandIns')]
if len(sys.argv) > 2: UNITS = [u for u in UNITS if u['file'] in sys.argv[2:]]
EQ = ('RAW_EQUAL', 'RELOCATION_RESOLVED_EQUAL')
DIR = re.compile(r'^//\s*build:\s*context\s+(\S+)\s*$', re.M)


def compile_text(u, text):
    wd = tempfile.mkdtemp(prefix='sweep_', dir='/tmp')
    try:
        open(os.path.join(wd, 'unit.cpp'), 'w', encoding='latin-1', newline='').write(text)
        flags = list(u.get('flags') or default_flags(u['file']))
        r = subprocess.run(cl_command(S, flags, 'unit.obj', 'unit.cpp'), capture_output=True, text=True,
                           env=unit_env(S, ENV, u['file']), cwd=wd)
        p = os.path.join(wd, 'unit.obj')
        return open(p, 'rb').read() if r.returncode == 0 and os.path.exists(p) else None
    finally:
        shutil.rmtree(wd, ignore_errors=True)


def all_equal(u, ob, text):
    src = expand_gen_includes(text, u['file'])
    bad = []
    for f in u['functions']:
        v = int(f['va'], 16)
        rr = unit_twins(checker.compare(ob, src, v, f['length'], pe.read, L.get), src)
        if rr.get('status') not in EQ:
            bad.append(f['va'])
    return bad


def unit_twins(res, src):
    """tools/build.py's rule: an extra form is tolerated only if a marker maps it elsewhere."""
    if res.get("status") != "MULTI_FORM_REJECTED":
        return res
    defs, decls, symbols = checker.parse_markers(src)
    keep = [n for n in res["extra_forms"] if (lambda h, k: h is checker.AMBIGUOUS or not (k & {"symbol", "def_", "wildcard"}))(*checker.resolve(n, defs, decls, symbols))]
    res["extra_forms"] = keep
    if keep:
        return res
    equal_len = res["compiled_length"] == res["expected_length"]
    if equal_len and res["diff_bytes"] == 0: res["status"] = "RAW_EQUAL"
    elif equal_len and res["unmasked_diff_bytes"] == 0:
        res["status"] = "RELOCATION_RESOLVED_EQUAL" if not res["target_problems"] else "MASKED_EQUAL_BUT_TARGETS_DIFFER"
    else: res["status"] = "MISMATCH"
    return res


def plain_name(sym):
    m = re.match(r'^\?([A-Za-z_]\w*)@', sym) or re.match(r'^[_@]?([A-Za-z_]\w*?)(@\d+)?$', sym)
    return m.group(1) if m else sym


def find_definition(text, name):
    """(start, brace, end) of the first top-level definition of name, or None."""
    for m in re.finditer(r'(?m)^[^\s/#][^;{}()]*\b%s\s*\(' % re.escape(name), text):
        i = text.index('(', m.end() - 1); depth = 0; j = i
        while j < len(text):
            if text[j] == '(': depth += 1
            elif text[j] == ')':
                depth -= 1
                if depth == 0: break
            j += 1
        k = j + 1
        while k < len(text) and text[k] in ' \t\r\n': k += 1
        if k >= len(text) or text[k] != '{': continue
        depth = 0; e = k
        while e < len(text):
            if text[e] == '{': depth += 1
            elif text[e] == '}':
                depth -= 1
                if depth == 0: break
            e += 1
        return m.start(), k, e + 1
    return None


results = json.load(open(OUT)) if os.path.exists(OUT) else []
done = {(r['file'], r['line']) for r in results}
for u in UNITS:
    path = os.path.join(ROOT, u['file'])
    text = open(path, encoding='latin-1').read()
    dirs = [(m.start(), m.end(), m.group(1), text.count('\n', 0, m.start()) + 1) for m in DIR.finditer(text)]
    if not dirs or all((u['file'], d[3]) in done for d in dirs): continue
    base = compile_text(u, text)
    if base is None or all_equal(u, base, text):
        for d in dirs:
            results.append(dict(file=u['file'], line=d[3], name=d[2], status='baseline-not-equal'))
        json.dump(results, open(OUT, 'w'), indent=1); continue
    for s, e, name, line in dirs:
        rec = dict(file=u['file'], line=line, name=name)
        # (a) the directive line alone
        t_a = text[:s] + text[e + 1:] if text[e:e + 1] == '\n' else text[:s] + text[e:]
        rec['directive_removable'] = not all_equal(u, base, t_a)
        # (b) the copy itself: definition -> prototype
        df = find_definition(t_a, plain_name(name))
        if df is None:
            rec['copy'] = 'definition not found in file'
        else:
            st, br, en = df
            header = t_a[st:br].rstrip()
            local = re.search(r'\b(static|inline|__inline|__forceinline)\b', header.split('(')[0])
            # a file-local copy can only go if nothing uses it; an external one becomes its prototype
            t_b = t_a[:st] + t_a[en:] if local else t_a[:st] + header + ';' + t_a[en:]
            if True:
                ob = compile_text(u, t_b)
                if ob is None: rec['copy'] = 'does not compile without it'
                else:
                    bad = all_equal(u, ob, t_b)
                    rec['copy'] = 'removable' if not bad else 'needed by %s' % ','.join(bad[:4])
        results.append(rec); print(json.dumps(rec), flush=True)
        json.dump(results, open(OUT, 'w'), indent=1)
json.dump(results, open(OUT, 'w'), indent=1)
