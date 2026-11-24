#!/usr/bin/env python3
"""multi.py UNIT_REL FILE VA [flags...]: compile FILE (as UNIT_REL's env/flags), and for every function in the object
whose name contains 'V_' compare its instruction sequence against VA's original (ignoring immediates of calls/pushes of addresses)."""
import sys, os, subprocess, tempfile, shutil, re, difflib
ROOT=os.environ.get('IBLIS_ROOT', os.getcwd()); F=os.path.abspath(sys.argv[2]); sys.path.insert(0,ROOT+'/tools'); os.chdir(ROOT)
import checker
from common import settings, compile_env, unit_env, cl_command, PE, default_flags, load_json
rel, va = sys.argv[1], int(sys.argv[3],16)
S=settings(); pe=PE(S['image']); L={int(r[0],16):int(r[1]) for r in load_json('functions.json')['functions']}
U=next((u for u in load_json('units.json')['units'] if u['file']==rel),None)
flags=list((U or {}).get('flags') or default_flags(rel))
for t in [x for x in sys.argv[4:] if x[:1] in '+-']:
    if t[0]=='+': flags.append(t[1:])
    elif t[0]=='-' and t[1:] in flags: flags.remove(t[1:])
wd=tempfile.mkdtemp(dir='/tmp')
txt=open(F,encoding='latin-1').read()
if os.environ.get('INTO'):
    base=open(os.environ['INTO'],encoding='latin-1').read(); anc=os.environ['ANCHOR']; assert anc in base, 'anchor'
    txt=base.replace(anc, txt+'\n'+anc, 1)
open(wd+'/unit.cpp','w',encoding='latin-1',newline='').write(txt)
r=subprocess.run(cl_command(S,flags,'unit.obj','unit.cpp'),capture_output=True,text=True,env=unit_env(S,compile_env(S),rel),cwd=wd)
if r.returncode: print((r.stdout+r.stderr)[-3000:]); sys.exit(1)
c=checker.Coff(open(wd+'/unit.obj','rb').read())
def dis(b):
    p=subprocess.run(['llvm-mc-18','--disassemble','-triple=i686','--output-asm-variant=1'],input=' '.join('0x%02x'%x for x in b),capture_output=True,text=True)
    out=[]
    for l in p.stdout.split('\n'):
        l=l.strip()
        if not l or l.startswith('.'): continue
        l=re.sub(r'^(call|jmp)\s+-?\d+$',r'\1 X',l); l=re.sub(r'push\s+\d{6,}$','push ADDR',l); l=re.sub(r'^call\s+0$','call X',l); l=re.sub(r'^push\s+0$','push 0',l)
        out.append(l)
    return out
O=dis(pe.read(va,L[va]))
for y in c.funcs():
    if 'V_' not in y['name']: continue
    sec=c.secs[y['scn']-1]; body=sec['raw'][y['value']:]
    A=dis(body)
    sm=difflib.SequenceMatcher(None,O,A,autojunk=False); n=sum(max(t[2]-t[1],t[4]-t[3]) for t in sm.get_opcodes() if t[0]!='equal')
    if os.environ.get('SHOW')==re.sub(r'@.*','',y['name']).lstrip('?_'):
        for l in difflib.unified_diff(O,A,'orig','ours',n=1,lineterm=''): print('   ',l)
    pro = 'PRO_OK' if A[:3]==O[:3] else 'PRO_BAD'
    print(pro, end=' ')
    print('%-12s len %4d/%d slot %d difflines %3d  regs %s' % (re.sub(r'@.*','',y['name']).lstrip('?_'), len(body), L[va], body[:4]==b'\x55\x8b\xec\x51', n, ''.join(sorted(set(re.findall(r'mov\t(e[bsd][xi]), dword ptr \[ebp \+ 8\]', '\n'.join(A)))))))
shutil.rmtree(wd)
