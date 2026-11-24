import csv,json,re,sys
# mkplan.py plan.tsv out.json [min_conf]
rows=list(csv.DictReader(open(sys.argv[1]),delimiter='\t'))
out=[]
for r in rows:
    if r['old_name']==r['new_name']: continue
    out.append(dict(va=r['va'],old=r['old_name'],new=r['new_name'],cls=None,src=r['source']))
    m=re.search(r'\(also spelled ([^)]*)\)',r['reason'])
    if m:
        for alt in re.split(r'[,\s]+',m.group(1)):
            alt=alt.strip('`; ')
            if re.match(r'^[A-Za-z_]\w*$',alt) and alt!=r['old_name']:
                out.append(dict(va=r['va'],old=alt,new=r['new_name'],cls=None,src=r['source'],alt=1))
json.dump(out,open(sys.argv[2],'w'),indent=1); print(len(rows),'rows',len(out),'renames')
