# c2force_gdb.py - runs INSIDE gdb (python exec), attached to a cl.exe (wine) process whose c2.dll copy spins at the
# colour driver entry (the tcspin copy from setup_tcspin.py, shared with the other c2diag tools). The WRITE side of
# c2diag: it overrides one (or a few) back-end decisions for one function of one compile, as given in C2FORCE_SPEC, and
# records what it did. With C2FORCE_RECORD it also records the jump optimiser's changes in the form the overrides name
# them (call site + invocation number). Addresses: c2.dll 14.00.50727.762 (SP1) at its base 0x10b00000.
#
# Override kinds (JSON list in C2FORCE_SPEC):
#   {"kind": "prio",  "cls": 0, "round": R, "id": I | "name": N, "delta": D}   allocator priority (+0x0c) += D
#   {"kind": "reg",   "cls": 0, "round": R, "id": I | "name": N, "reg": n}     colour step picks register n (if allowed)
#   {"kind": "mem",   "cls": 0, "round": R, "id": I | "name": N}               pop sends the web down the not-coloured path
#   {"kind": "sw",    "cls": 0, "round": R, "id": I | "name": N, "weight": W}  pop sees spill weight max(old, W) (W > 0:
#                                                                               the web is not sent down the failed-pop path)
#   {"kind": "sched", "region": G, "node": K, "delta": D}                      scheduler ready-list priority (+0x30) += D
#   {"kind": "jskip", "site": S, "n": K}                                        skip the K-th call at jump-optimiser site S
#                                                                               and every later call there on the same tuple
# Added by lane TOOL-C2X (the local assigner, pre-backend passes, frame slots; region builder after lane FOCUS-14):
#   {"kind": "rot",   "tid": T, "occ": O, "reg": n}        local assigner: before the O-th pick of temporary T, set the
#                                                          integer rotation pointer to n (1 eax, 2 ecx, 3 edx)
#   {"kind": "pick",  "tid": T, "occ": O, "reg": n, "rot": b}  local assigner: the pick of T takes register n (if free,
#                                                          not excluded, byte-capable when needed), as a preference
#                                                          pick (pointer unchanged) or, with rot, moving the pointer past n
#   {"kind": "skip",  "fn": A, "from": R|null, "n": K|0, "pop": P, "ret": V}   skip the K-th call (0 = every call) of
#                                                          c2.dll routine A made for the target (only calls returning to
#                                                          R when given): return V at once, popping P argument bytes
#   {"kind": "rg",    "call": N, "blk": B, "what": "nopred"|"nosucc"|"both"}  region builder 0x10b15d50 (lane
#                                                          FOCUS-14): in its N-th call block B joins no region through
#                                                          its predecessors / successors, so it starts a new one
#   {"kind": "slotw", "slot": I | "home": NAME, "delta": D}  frame layout: slot weight (+0x0c) += D before the sort
#   {"kind": "slotswap", "a": I | NAME, "b": I | NAME}     frame layout: swap two slots of the final order (offsets
#                                                          are given in that order)
import gdb, struct, json, os

OUT = open(os.environ['C2FORCE_OUT'], 'w')
TARGET = os.environ.get('C2FORCE_FUNC', '')        # substring of the decorated name ('' = every function)
SPEC = json.loads(os.environ.get('C2FORCE_SPEC', '[]'))
RECORD = os.environ.get('C2FORCE_RECORD', '') == '1'
JSITES = {int(k): v for k, v in json.loads(os.environ.get('C2FORCE_JSITES', '{}')).items()}  # site -> bytes popped

def mem(a, n): return bytes(gdb.selected_inferior().read_memory(a, n))
def u32(a): return struct.unpack('<I', mem(a, 4))[0]
def s32(a): return struct.unpack('<i', mem(a, 4))[0]
def u16(a): return struct.unpack('<H', mem(a, 2))[0]
def w32(a, v): gdb.selected_inferior().write_memory(a, struct.pack('<I', v & 0xffffffff))
def reg(r): return int(gdb.parse_and_eval('$' + r)) & 0xffffffff
def setreg(r, v): gdb.execute('set $%s = %d' % (r, v & 0xffffffff))
def cstr(a, n=256):
    try: return mem(a, n).split(b'\0')[0].decode('latin1')
    except Exception: return None
NEMIT = [0]
def emit(**k):                                     # capped: a runaway override must not fill the disk
    NEMIT[0] += 1
    if NEMIT[0] > 50000: return
    if NEMIT[0] == 50000: k = dict(ev='error', err='event cap reached; later events dropped')
    OUT.write(json.dumps(k) + '\n'); OUT.flush()

VROOT = 0x10d0eeec
def vline_to_line(v):
    n = u32(VROOT); k = 0
    while n and k < 64:
        lo, hi, base = u32(n + 8), u32(n + 0xc), u32(n + 0x10)
        if lo <= v <= hi: return base - lo + v
        n = u32(n + 4) if v < lo else u32(n)
        k += 1
    return None
def tline(t):
    try:
        v = u16(t + 0x14)
        return vline_to_line(v) if v else None
    except Exception: return None

def bitset_items(bs, limit=4096):
    out = []
    if not bs: return out
    n = u32(bs); k = 0
    while n and k < limit:
        b, lo, hi = u32(n), u32(n + 4), u32(n + 8)
        for i in range(32):
            if (lo >> i) & 1: out.append(b + i)
            if (hi >> i) & 1: out.append(b + 32 + i)
        n = u32(n + 0xc); k += 1
    return out

def bitset_has(bs, bit):
    return bit in bitset_items(bs)

def symname(sym):
    try:
        n = u32(sym)
        return cstr(u32(n + 4), 96) if n else None
    except Exception: return None

HASH = 0x10d15090
def find_cand(cid):
    e = u32(HASH + 4 * (cid & 0x3ff)); k = 0
    while e and k < 10000:
        if u32(e + 0x1c) == cid: return e
        e = u32(e + 0x30); k += 1
    return 0

st = dict(on=False, f=0, name=None, rounds={}, cur=None, region=0, jcount={}, jskip={}, applied=0, memdone=set(), popped=None,
          scount={}, srec={}, pocc={}, rgn=0, rgidx={})
ALLOC = [o for o in SPEC if o['kind'] in ('prio', 'reg', 'mem', 'sw')]
RAO = [o for o in SPEC if o['kind'] in ('rot', 'pick')]
SKIPO = [o for o in SPEC if o['kind'] == 'skip']
RGO = [o for o in SPEC if o['kind'] == 'rg']
SLOTO = [o for o in SPEC if o['kind'] in ('slotw', 'slotswap')]
SKIPREC = [int(x) for x in json.loads(os.environ.get('C2FORCE_SKIPREC', '[]'))]   # call sites to count
RGREC = os.environ.get('C2FORCE_RGREC', '') == '1'
SCHEDO = [o for o in SPEC if o['kind'] == 'sched']
JUMPO = [o for o in SPEC if o['kind'] == 'jskip']

def set_func(f, where):
    name = None
    try: name = cstr(u32(u32(f) + 4))
    except Exception: pass
    on = TARGET == '' or (name is not None and TARGET in name)
    if f == st['f'] and st['name'] is not None and name == st['name']:
        st['on'] = on                               # the same function again (e.g. its code generation after the
        return                                      # previous function's end hook switched the filter off)
    if f != st['f'] or name != st['name']:
        st.update(rounds={}, cur=None, region=0, jcount={}, jskip={}, scount={}, srec={}, slines={}, pocc={}, rgn=0)
    st.update(f=f, name=name, on=on)
    if on: emit(ev='func', name=name, where=where)

def matches(o, cid, sym):
    if 'id' in o and o['id'] is not None: return o['id'] == cid
    if 'name' in o and o['name']:
        nm = symname(sym) if sym else None
        return nm is not None and nm.lstrip('_') == o['name'].lstrip('_')
    return False

# ---- allocator ---------------------------------------------------------------------------------------------------
def on_colour_driver():
    set_func(u32(reg('esp') + 4), 'colour')
    st.update(rounds={}, cur=None)

def on_prio_begin():
    cls = u32(reg('esp') + 8)
    st['rounds'][cls] = st['rounds'].get(cls, 0) + 1
    st['cur'] = (cls, st['rounds'][cls])

def on_prio_end():
    esp = reg('esp'); cls = u32(esp + 8)
    rnd = st['rounds'].get(cls, 0)
    for o in ALLOC:
        if o['kind'] != 'prio' or o.get('cls', 0) != cls or o['round'] != rnd: continue
        hit = False
        for cid in bitset_items(u32(esp + 0xc)):
            e = find_cand(cid)
            if not e or not matches(o, cid, u32(e)): continue
            old = s32(e + 0xc); w32(e + 0xc, old + o['delta']); hit = True; st['applied'] += 1
            emit(ev='applied', kind='prio', round=rnd, cls=cls, id=cid, old=old, new=old + o['delta'])
        if not hit: emit(ev='miss', kind='prio', round=rnd, spec=o)

def cur_alloc(kind):
    if not st['cur']: return []
    cls, rnd = st['cur']
    return [o for o in ALLOC if o['kind'] == kind and o.get('cls', 0) == cls and o['round'] == rnd]

def on_pop():                                       # 0x10b0d341: EBP = candidate just taken off the priority list
    st['popped'] = None
    e = reg('ebp'); cid = u32(e + 0x1c)
    for o in cur_alloc('sw'):
        if matches(o, cid, u32(e)):
            key = (st['cur'], cid, 'sw')
            if key in st['memdone']: continue
            st['memdone'].add(key)
            old = s32(e + 0x40); new = max(old, o.get('weight', 1)); w32(e + 0x40, new); st['applied'] += 1
            st['popped'] = cid
            emit(ev='applied', kind='sw', round=st['cur'][1], id=cid, old_weight=old, new_weight=new)
    os_ = cur_alloc('mem')
    if not os_: return
    for o in os_:
        if matches(o, cid, u32(e)):
            key = (st['cur'], cid)
            if key in st['memdone']:                # once per web and round: the forced pop re-queues it, and
                continue                            # forcing every later pop never ends
            st['memdone'].add(key)
            old = s32(e + 0x40); w32(e + 0x40, -1); st['applied'] += 1; st['popped'] = cid
            emit(ev='applied', kind='mem', round=st['cur'][1], id=cid, old_weight=old)

def mk_path(name):                                  # the four ways out of the pop, reported for a forced web
    def f():
        if st.get('popped') is not None:
            emit(ev='mempath', id=st['popped'], path=name); st['popped'] = None
    return f

def on_pick():                                      # 0x10b14e1a: EBX (= [esp+0x10]) = register the colour step chose
    os_ = cur_alloc('reg')
    if not os_: return
    esp = reg('esp'); cand = u32(esp + 0x20); cid = u32(cand + 0x1c)
    for o in os_:
        if not matches(o, cid, u32(cand)): continue
        allowed = bitset_items(u32(cand + 0x20))
        was = reg('ebx')
        if o['reg'] not in allowed:
            emit(ev='refused', kind='reg', round=st['cur'][1], id=cid, want=o['reg'], allowed=allowed, chose=was)
            continue
        setreg('ebx', o['reg']); w32(esp + 0x10, o['reg']); st['applied'] += 1
        emit(ev='applied', kind='reg', round=st['cur'][1], id=cid, was=was, now=o['reg'], allowed=allowed)

# ---- scheduler ---------------------------------------------------------------------------------------------------
CTX = 0x10d0fb88
def on_sched():
    set_func(u32(reg('esp') + 4), 'sched')
    st['region'] = 0

def on_region_built():
    st['region'] += 1

def on_sched_prio():                                # 0x10c71e7e: heights and priorities done, issue loop not started
    os_ = [o for o in SCHEDO if o['region'] == st['region']]
    if not os_: return
    first = u32(u32(CTX)); last = u32(u32(CTX) + 4)
    n = first; k = 0; seen = set()
    while n and k < 5000:
        nid = u16(n + 0x3a)
        for o in os_:
            if o['node'] == nid:
                old = u32(n + 0x30); new = max(0, old + o['delta'])
                w32(n + 0x30, new); st['applied'] += 1; seen.add(id(o))
                emit(ev='applied', kind='sched', region=st['region'], node=nid, old=old, new=new, line=tline(u32(n + 0x1c)))
        if n == last: break
        n = u32(n); k += 1
    for o in os_:
        if id(o) not in seen: emit(ev='miss', kind='sched', spec=o)

# ---- jump optimiser ----------------------------------------------------------------------------------------------
JOPT = 0x10b2c950
JCHANGE = (0x10b2cdae, 0x10b2cdf8, 0x10b2ce3d, 0x10b2ce57, 0x10b2d1b6)
def on_jopt():
    set_func(reg('ecx'), 'jumpopt')
    st['jmode'] = reg('eax'); st['jsweep'] = 0

def on_jsweep():
    st['jsweep'] = st.get('jsweep', 0) + 1; st['jlast'] = None

def mk_site(site):
    def f():
        n = st['jcount'].get(site, 0) + 1; st['jcount'][site] = n
        t = reg('ebp'); st['jlast'] = (site, n, t)
        skip = False
        for o in JUMPO:
            if o['site'] == site and o['n'] == n:
                st['jskip'].setdefault(site, set()).add(t); skip = True
        if not skip and t in st['jskip'].get(site, ()):
            skip = True
        if skip:
            pop = JSITES.get(site, 0)
            setreg('esp', reg('esp') + pop); setreg('eax', 0); setreg('pc', site + 5)
            st['applied'] += 1
            emit(ev='applied', kind='jskip', site=site, n=n, line=tline(t), mode=st.get('jmode'), sweep=st.get('jsweep'))
    return f

def on_jchange():
    if RECORD and st.get('jlast'):
        site, n, t = st['jlast']
        emit(ev='jchange', site=site, n=n, line=tline(t), mode=st.get('jmode'), sweep=st.get('jsweep'), at=reg('pc'))


# ---- TOOL-C2X: pipeline drivers (they name the function before colouring; with the prelude every pass is seen) --------
def mk_f_eax(where):
    def f():
        set_func(reg('eax'), where)
        if where == 'codegen': st['cg'] = reg('eax')
    return f

# ---- local assigner (regasg.c): rotation pointer and picks ---------------------------------------------------------
OCC, EXCL, ALLOWEDT, ROT, INTLIST, REGDESC0 = 0x10d0fd10, 0x10d0fba0, 0x10d0f9f0, 0x10d0f854, 0x10d0cfd0, 0x10d09f70
CLASSBYTE = 0x10c23503            # rotation pointer selector per type class: 0 = the integer pointer at ROT
def u8(a): return mem(a, 1)[0]

def on_regasg():
    set_func(u32(reg('esp') + 4), 'regasg')
    st['pocc'] = {}

def excluded(r, tid):
    return bitset_has(u32(EXCL + 4 * r), tid)

def on_ra_pick():                                   # 0x10bda7c0 stdcall(operand, tuple): give a register to a temporary
    esp = reg('esp'); o = u32(esp + 4); rec = u32(o + 0x1c); tid = u32(rec + 0x1c)
    occ = st['pocc'][tid] = st['pocc'].get(tid, 0) + 1
    intcls = u8(CLASSBYTE + (u16(o + 0xa) >> 12)) == 0
    for x in RAO:
        if x['tid'] != tid or x.get('occ', 1) != occ: continue
        if x['kind'] == 'rot':
            if not intcls:
                emit(ev='refused', kind='rot', tid=tid, why='not an integer temporary'); continue
            old = u32(u32(ROT)); w32(ROT, INTLIST + 4 * (x['reg'] - 1)); st['applied'] += 1
            emit(ev='applied', kind='rot', tid=tid, occ=occ, was=old, now=x['reg'])
        elif x['kind'] == 'pick':
            r = x['reg']; why = None
            if u32(OCC + 4 * r): why = 'busy'
            elif (u8(rec + 5) & 0x80) and r >= 5: why = 'needs a byte register'
            elif excluded(r, tid) and not x.get('force'): why = 'excluded'
            if why:
                emit(ev='refused', kind='pick', tid=tid, occ=occ, want=r, why=why); continue
            # what the preference path does (0x10bdac90): occupant, use mark, descriptor flag; then `ret 8`
            w32(OCC + 4 * r, rec); w32(0x10d40c40 + 4 * r, 1)
            desc = REGDESC0 + 0x60 * r; w32(desc + 0x38, 0x1000000)
            if x.get('rot') and intcls and r in (1, 2, 3):
                nxt = u32(INTLIST + 4 * r)
                w32(ROT, INTLIST + 4 * r if nxt in (1, 2, 3) else INTLIST)
            ra = u32(esp); setreg('eax', desc); setreg('esp', esp + 12); setreg('pc', ra)
            st['applied'] += 1
            emit(ev='applied', kind='pick', tid=tid, occ=occ, now=r, rot=bool(x.get('rot')), line=tline(u32(esp + 8)))
            return

# ---- skip one call of a c2.dll routine (pre-backend passes and their steps) ---------------------------------------
def mk_skip(fn):
    os_ = [o for o in SKIPO if o['fn'] == fn]
    def f():
        esp = reg('esp'); ra = u32(esp)
        for o in os_:
            if o.get('from') and o['from'] != ra: continue
            key = (fn, o.get('from'))
            n = st['scount'][key] = st['scount'].get(key, 0) + 1
            if o['n'] and o['n'] != n: continue
            setreg('eax', o.get('ret', 0)); setreg('esp', esp + 4 + o.get('pop', 0)); setreg('pc', ra)
            st['applied'] += 1
            emit(ev='applied', kind='skip', fn=fn, frm=ra, n=n)
            return
    return f

def guess_line():                                   # label only: a source line if EAX, ECX or the first stack
    for v in (reg('eax'), reg('ecx'), u32(reg('esp'))):   # word is an IL tuple (vline at +0x14)
        if 0x10000 <= v < 0x80000000:
            try:
                ln = tline(v)
                if ln and 0 < ln < 100000: return ln
            except Exception: pass
    return None

def mk_srec(site):                                  # count the calls made at one call site for the target
    def f():
        st['srec'][site] = st['srec'].get(site, 0) + 1
        if st['srec'][site] <= 3000: st.setdefault('slines', {}).setdefault(site, []).append(guess_line())
    return f

# ---- region builder 0x10b15d50 (lane FOCUS-14's hooks) --------------------------------------------------------------
def on_rg_entry():
    st['rgn'] += 1
    f = u32(reg('esp') + 4); idx = {}; b = u32(u32(f + 8)); bi = 0
    while b and bi < 5000:
        idx[b] = bi; b = u32(b); bi += 1
    st['rgidx'] = idx
    st['rgwebs'] = u32(reg('esp') + 8)

def mk_rg(which):
    def f():
        bi = st['rgidx'].get(reg('ebp'))
        for o in RGO:
            if o['call'] == st['rgn'] and o['blk'] == bi and o['what'] in (which, 'both'):
                setreg('ebx', 0); st['applied'] += 1
                emit(ev='applied', kind='rg', call=st['rgn'], blk=bi, what=which)
    return f

def on_rg_done():                                   # 0x10b1600e: every block has its region id (+0x38)
    webs = bitset_items(st.get('rgwebs', 0)); rows = []
    b = u32(u32(st['f'] + 8)); bi = 0
    while b and bi < 4000:
        if any(bitset_has(u32(b + 0x50), w) for w in webs):
            t = u32(b + 0x1c); last = u32(b + 0x20); ln = None; k = 0
            while t and k < 200 and ln is None:       # the first tuple of the block with a line (labels have none)
                ln = tline(t)
                if t == last: break
                t = u32(t); k += 1
            rows.append(dict(blk=bi, line=ln, rid=u32(b + 0x38)))
        b = u32(b); bi += 1
    emit(ev='rg', call=st['rgn'], webs=webs, rows=rows)

# ---- frame layout (c2slots' hooks): slot weights before the sort, the final order ---------------------------------
SLOTS, NSLOTS, SLOTLO, BYINDEX = 0x10d0fa9c, 0x10d0fa98, 0x10d0faa8, 0x10d0faa4
def slot_names():
    arr, n, idx = u32(SLOTS), u32(NSLOTS), u32(BYINDEX); out = []
    for i in range(n):
        names = []
        for k in bitset_items(u32(arr + 0x1c * i)):
            sym = u32(idx + 4 * k); nm = symname(sym)
            names.append(nm or 'tmp@%x' % sym)
        out.append(names)
    return out

def slot_index(ref, names):
    if isinstance(ref, int): return ref
    nm, _, k = ref.partition('#'); k = int(k) if k else 1; seen = 0
    for i, ms in enumerate(names):
        if any(m.lstrip('_') == nm.lstrip('_') for m in ms):
            seen += 1
            if seen == k: return i
    return None

def on_slot_decide():
    names = slot_names(); arr = u32(SLOTS)
    for o in SLOTO:
        if o['kind'] != 'slotw': continue
        i = slot_index(o.get('slot', o.get('home')), names)
        if i is None: emit(ev='miss', kind='slotw', spec=o); continue
        old = s32(arr + 0x1c * i + 0xc); w32(arr + 0x1c * i + 0xc, old + o['delta']); st['applied'] += 1
        emit(ev='applied', kind='slotw', slot=i, members=names[i], old=old, new=old + o['delta'])

def on_slot_final():
    names = slot_names(); arr = u32(SLOTS)
    for o in SLOTO:
        if o['kind'] != 'slotswap': continue
        i, j = slot_index(o['a'], names), slot_index(o['b'], names)
        if i is None or j is None or i == j: emit(ev='miss', kind='slotswap', spec=o); continue
        a, b = mem(arr + 0x1c * i, 0x1c), mem(arr + 0x1c * j, 0x1c)
        gdb.selected_inferior().write_memory(arr + 0x1c * i, b); gdb.selected_inferior().write_memory(arr + 0x1c * j, a)
        names[i], names[j] = names[j], names[i]; st['applied'] += 1
        emit(ev='applied', kind='slotswap', a=i, b=j)

def on_end():
    if (SKIPO or SKIPREC) and st.get('cg') != st['f']:
        return                                      # the end of the previous function's code generation: c2 runs
                                                    # the next function's optimiser before it (seen with the prelude)
    if st['on']:
        emit(ev='end', applied=st['applied'], rounds=st['rounds'], regions=st['region'])
        if SKIPREC: emit(ev='srec', counts={str(k): v for k, v in st['srec'].items()},
                         lines={str(k): v for k, v in st.get('slines', {}).items()})
    st['on'] = False

class BP(gdb.Breakpoint):
    def __init__(self, addr, fn, always=False):
        super().__init__('*0x%x' % addr, internal=True); self.fn = fn; self.always = always
    def stop(self):
        if self.always or st['on']:
            try: self.fn()
            except Exception as ex: emit(ev='error', where=self.location, err=repr(ex))
        return False

def setup():
    gdb.execute('set pagination off')
    gdb.execute('handle all nostop noprint pass')
    gdb.execute('handle SIGTRAP stop print nopass')
    for th in gdb.selected_inferior().threads():
        th.switch()
        if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == 0x10b0cf40: break
    gdb.selected_inferior().write_memory(0x10b0cf40, b'\x83\xec')   # restore `sub esp, 0x18`
    BP(0x10b0cf40, on_colour_driver, always=True)
    if ALLOC:
        BP(0x10b10420, on_prio_begin)
        BP(0x10b1153f, on_prio_end)
        if any(o['kind'] in ('mem', 'sw') for o in ALLOC):
            BP(0x10b0d341, on_pop)
            for a, nm in ((0x10b0d37e, 'not coloured'), (0x10b0d3aa, 're-queued'), (0x10b0d3c5, 'no register'), (0x10b0d464, 'colour')):
                BP(a, mk_path(nm))
        if any(o['kind'] == 'reg' for o in ALLOC): BP(0x10b14e1a, on_pick)
    if SCHEDO:
        BP(0x10c71dc0, on_sched, always=True)
        BP(0x10c71e79, on_region_built)
        BP(0x10c71e7e, on_sched_prio)
    if JUMPO or RECORD:
        BP(JOPT, on_jopt, always=True)
        BP(0x10b2ccf0, on_jsweep)
        sites = set(JSITES) if RECORD else {o['site'] for o in JUMPO}
        for s in sorted(sites): BP(s, mk_site(s))
        if RECORD:
            for a in JCHANGE: BP(a, on_jchange)
    BP(0x10c0666a, on_end)                                             # end of the code generation driver
    if SKIPO or SKIPREC:
        BP(0x10c06890, mk_f_eax('optimiser'), always=True)             # per-function optimiser driver, eax = func
        BP(0x10c06540, mk_f_eax('codegen'), always=True)               # per-function code generation driver, eax = func
        for fn in sorted({o['fn'] for o in SKIPO}): BP(fn, mk_skip(fn))
        for s_ in SKIPREC: BP(s_, mk_srec(s_))
    if RAO:
        BP(0x10bda210, on_regasg, always=True)
        BP(0x10bda7c0, on_ra_pick)
    if RGO or RGREC:
        BP(0x10b15d50, on_rg_entry)
        if RGO:
            BP(0x10b15eae, mk_rg('nopred')); BP(0x10b15f03, mk_rg('nosucc'))
        if RGREC: BP(0x10b1600e, on_rg_done)
    if SLOTO:
        BP(0x10beb315, on_slot_decide); BP(0x10beb354, on_slot_final)
    if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == 0x10b0cf40:
        on_colour_driver()
    gdb.execute('continue')

setup()
