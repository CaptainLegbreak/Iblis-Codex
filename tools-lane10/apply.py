import json,re,os,sys,glob
R=sys.argv[1]; plan=json.load(open(os.environ.get('PLAN','/home/claude/stormren/plan.json')))
extra=[dict(va='0x0041C340',old='sub_0041C340_SetLastError',new='SErrSetLastError',cls=None),
       dict(va='0x00423850',old='sub_00423850',new='SBigFromBinary',cls=None)]
only=set(sys.argv[2].split(',')) if len(sys.argv)>2 and sys.argv[2] else None
items=[p for p in plan+(extra if os.environ.get('EXTRA') else []) if not only or p['va'] in only]
excl=set(open(os.environ.get('EXCL','/home/claude/stormren/exclude.txt')).read().split()) if os.path.exists(os.environ.get('EXCL','/home/claude/stormren/exclude.txt')) else set()
items=[p for p in items if p['va'] not in excl]
pat=re.compile(r'\b('+'|'.join(re.escape(p['old']) for p in items)+r')\b')
m={p['old']:p['new'] for p in items}
vam={p['old']:'0x%08X'%int(p['va'],16) for p in items}
n=0
for f in glob.glob(R+'/Source/**/*',recursive=True):
    if not os.path.isfile(f): continue
    t=open(f,encoding='latin-1').read()
    # a declaration that has no address marker keeps its address: the old placeholder name carried it
    if pat.search(t):
        L=t.split('\n')
        for i,l in enumerate(L):
            if '//' in l or not l.rstrip().endswith(';') or '(' not in l: continue
            mo=re.search(r'\b('+pat.pattern[3:-3]+r')\s*\(',l)
            if mo and not re.search(r'[=]\s*\w*\s*'+re.escape(mo.group(1)),l) and not l.lstrip().startswith(('return','if','while')) and re.match(r'^\s*(extern\s+"C"\s+)?(static\s+)?[A-Za-z_][\w\s\*&:<>,]*?[\s\*&]'+re.escape(mo.group(1))+r'\s*\(',l):
                L[i]=l.rstrip()+' // '+vam[mo.group(1)]
        t2='\n'.join(L)
    else: t2=t
    u=pat.sub(lambda x:m[x.group(1)],t2)
    # an old placeholder name carried its address; where this file never states that address, say it
    if u!=t:
        L=u.split('\n'); ins={}
        for o,nw in m.items():
            if not re.search(r'_[0-9A-F]{8}',o) or not re.search(r'\b'+re.escape(o)+r'\b',t): continue
            a=vam[o]
            rx=re.compile(re.escape(a)+r'\b',re.I); nx=re.compile(r'\b'+re.escape(nw)+r'\b')
            if any(rx.search(l) and nx.search(l) for l in L) or any(rx.search(L[i]) and L[i].strip().startswith('//') and nx.search(L[i+1]) for i in range(len(L)-1)): continue
            k=next((i for i,l in enumerate(L) if re.search(r'\b'+re.escape(nw)+r'\b',l)),None)
            if k is None: continue
            decl=next((l for l in L if re.search(r'\b'+re.escape(nw)+r'\s*\(',l)),L[k])
            if 'extern "C"' in decl or 'extern"C"' in decl:
                sym=('@%s@*'%nw) if '__fastcall' in decl else ('_%s@*'%nw) if '__stdcall' in decl else ('_%s'%nw)
            else: sym='?%s@*'%nw
            ins.setdefault(k,[]).append('// build: symbol %s %s'%(sym,a))
        for k in sorted(ins,reverse=True): L[k:k]=ins[k]
        u='\n'.join(L)
    if u!=t: open(f,'w',encoding='latin-1',newline='').write(u); n+=1
mm=re.compile(r'(?<![A-Za-z0-9/])('+'|'.join(re.escape(p['old']) for p in items)+r')(?![A-Za-z0-9_])(?!\.(?:cpp|c|CPP|C|inc|h)\b)')   # never a file name
for j in ('build/units.json','build/functions.json','build/data_plan.json'):
    t=open(R+'/'+j).read(); u=mm.sub(lambda x:m[x.group(1)],t); open(R+'/'+j,'w').write(u)
va={int(p['va'],16):(p['new'],p.get('src','blizzard')) for p in items if not p.get('alt')}
L=open(R+'/names.csv').read().splitlines(); out=[L[0]]
for l in L[1:]:
    a=l.split(',')
    if int(a[0],16) in va: a[1]=va[int(a[0],16)][0]; a[2]=va[int(a[0],16)][1]
    if len(a)>3 and a[3]: a[3]=mm.sub(lambda x:m[x.group(1)],a[3])
    out.append(','.join(a))
open(R+'/names.csv','w').write('\n'.join(out)+'\n')
print(len(items),'renames',n,'files')
