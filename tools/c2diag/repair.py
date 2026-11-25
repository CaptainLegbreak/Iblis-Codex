#!/usr/bin/env python3
"""repair.py <va> <branch> <branch-file> <unit> <block> <outdir> : retry reading.py, fixing compile errors in the block:
an unknown `sub_<VA>...` name becomes names.csv's current name for that address; any other unknown identifier gets
its definition carried from the branch's file. Up to 8 tries."""
import sys, re, json, subprocess, csv
va, br, bf, unit, blk, out = sys.argv[1:7]
NAMES = {r[0].upper(): r[1] for r in list(csv.reader(open('/home/claude/vsw/names.csv')))[1:]}
src = subprocess.run(['git', '-C', '/home/claude/iblis-codex', 'show', br + ':' + bf], capture_output=True, text=True, encoding='latin-1').stdout
sys.path.insert(0, '/home/claude/c2diag')
def toplevel_def(text, ident):
    m = re.search(r'^(?:typedef\s+)?(?:struct|union|class)\s+%s\b[^;{]*\{' % re.escape(ident), text, re.M)
    if m:
        i = text.index('{', m.start()); d = 0
        for j in range(i, len(text)):
            d += {'{': 1, '}': -1}.get(text[j], 0)
            if d == 0: return text[m.start():text.index(';', j) + 1]
    m = re.search(r'^[^\n;{}]*\b%s\s*\([^;{]*\)\s*\n?\{' % re.escape(ident), text, re.M)
    if m:
        i = text.index('{', m.start()); d = 0
        for j in range(i, len(text)):
            d += {'{': 1, '}': -1}.get(text[j], 0)
            if d == 0: return text[m.start():j + 1]
    m = re.search(r'^[^\n]*\b%s\b[^\n]*;[^\n]*//\s*0x[0-9A-Fa-f]{8}[^\n]*$' % re.escape(ident), text, re.M) or re.search(r'^\s*(?:extern|typedef)[^\n]*\b%s\b[^\n]*;' % re.escape(ident), text, re.M)
    return m.group(0) if m else None
for k in range(8):
    r = subprocess.run(['python3', '/home/claude/c2diag/reading.py', va, unit, blk, out], capture_output=True, text=True)
    line = r.stdout.strip(); print('try', k, line[:240])
    if 'COMPILE_ERROR' not in line: break
    err = json.load(open(out + '/score.json')).get('err', '')
    ids = list(dict.fromkeys(re.findall(r"'([A-Za-z_]\w*)'\s*:\s*(?:identifier not found|undeclared identifier)", err)))
    if not ids: print('cannot repair:', err[-600:]); break
    b = open(blk, encoding='latin-1').read(); pre = []
    for i in ids:
        mm = re.match(r'sub_([0-9A-Fa-f]{8})', i)
        if mm and ('0X' + mm.group(1).upper()) in NAMES and NAMES['0X' + mm.group(1).upper()] != i:
            b = re.sub(r'\b%s\b' % re.escape(i), NAMES['0X' + mm.group(1).upper()], b); continue
        d = toplevel_def(src, i)
        if d and d not in b: pre.append(d)
        elif not d: print('  no definition for', i)
    open(blk, 'w', encoding='latin-1').write('\n'.join(pre) + ('\n\n' if pre else '') + b)
