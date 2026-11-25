# c2temps_gdb.py - runs INSIDE gdb (python exec), attached to a cl.exe (wine) process whose c2.dll copy spins at
# the colour driver entry (0x10b0cf40 patched to EB FE, see setup_tcspin.py). Collects the local register
# assigner's (regasg.c) decisions as JSON lines. Addresses: c2.dll 14.00.50727.762 (SP1) at base 0x10b00000.
# Every breakpoint only reads memory and continues.
import gdb, struct, json, os

OUT = open(os.environ['C2TEMPS_OUT'], 'w')
TARGET = os.environ.get('C2TEMPS_FUNC', '')        # substring of the decorated name; '' = all functions
WANT_PRE = os.environ.get('C2TEMPS_PRE', '1') == '1'   # record each tuple's operands before assignment

REGDESC0 = 0x10d09f70      # register descriptor n = REGDESC0 + n*0x60, number at +0x1c
OCC = 0x10d0fd10           # occupant table: OCC[reg] = temp record / physical descriptor holding reg (0 = free)
EXCL = 0x10d0fba0          # EXCL[reg] = bitset of temp ids that may not take reg (built by the pre-pass)
ALLOWED = 0x10d0f9f0       # ALLOWED[reg] != 0: reg may be given to a preference
ROT = 0x10d0f854           # integer-class rotation pointer (into the class list at INTLIST)
INTLIST = 0x10d0cfd0       # integer class list: eax ecx edx esi edi ebx ebp 0
VROOT = 0x10d0eeec         # vline -> source line range tree
REGS = (1, 2, 3, 7, 8, 4, 6)
MNEMTAB = 0x10cdf220       # the compiler's own mnemonic table, indexed by machine tuple opcode
NMNEM = 628

def mem(a, n): return bytes(gdb.selected_inferior().read_memory(a, n))
def u32(a): return struct.unpack('<I', mem(a, 4))[0]
def s32(a): return struct.unpack('<i', mem(a, 4))[0]
def u16(a): return struct.unpack('<H', mem(a, 2))[0]
def u8(a): return mem(a, 1)[0]
def reg(r): return int(gdb.parse_and_eval('$' + r)) & 0xffffffff
def cstr(a, n=128):
    try: return mem(a, n).split(b'\0')[0].decode('latin1')
    except Exception: return None
def emit(**k): OUT.write(json.dumps(k) + '\n'); OUT.flush()

st = {'on': False, 'f': 0, 'seq': 0, 'pick': None, 'tuple': 0, 'mnem': {}}

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

def bitset_has(bs, bit):
    if not bs: return False
    n = u32(bs); base = bit & ~63; k = 0
    while n and k < 4096:
        b = u32(n)
        if b == base:
            lo, hi = u32(n + 4), u32(n + 8); r = bit & 63
            return bool((lo >> r) & 1) if r < 32 else bool((hi >> (r - 32)) & 1)
        if b > base: return False
        n = u32(n + 0xc); k += 1
    return False

def is_desc(p): return REGDESC0 <= p < REGDESC0 + 0x60 * 0x5c

def regnum(p):
    """register number of a (sub)register descriptor or of a physical record"""
    try:
        if not p: return 0
        if is_desc(p) or u8(p + 4) == 1: return u32(u32(p + 8) + 0x1c)   # +8 = full-width register
    except Exception: pass
    return -1

def symname(sym):
    try:
        n = u32(sym)
        return cstr(u32(n + 4), 96) if n else None
    except Exception: return None

def owner(p):
    """describe what OCC[reg] holds"""
    if not p: return None
    try:
        if is_desc(p): return 'R'                      # a physical register (register variable / fixed use)
        k = u8(p + 4)
        if k == 3: return 'T%d' % u32(p + 0x1c)         # a temporary
        if k == 1: return 'R'
        return 'k%d' % k
    except Exception: return '?'

def occupancy():
    return {str(r): owner(u32(OCC + 4 * r)) for r in REGS if u32(OCC + 4 * r)}

def rotptr():
    p = u32(ROT)
    try: return u32(p)
    except Exception: return -1

# ---- operand / tuple rendering (final stream) ---------------------------------------------------------
def opnd(o):
    """operand node: +4 opcode, +8 kind (1 register, 2 symbol in memory, 3 local's address, 4 code symbol,
    6 memory, 7 immediate, 0xb register set), +0xa type (>> 12 = class, & 0xfff = size),
    +0x14 flags, +0x18 symbol / web, +0x1c register descriptor or temp record; memory: +0x24 symbol,
    +0x28 displacement, +0x2c base operand, +0x30 index operand, +0x14 & 0xf scale code"""
    k = u8(o + 8); ty = u16(o + 0xa)
    d = dict(k=k, ty=ty, a=o, op=u32(o + 4))
    if k == 1:
        r = u32(o + 0x1c)
        if is_desc(r) or (r and u8(r + 4) == 1): d['r'] = regnum(r)
        elif r and u8(r + 4) == 3: d['t'] = u32(r + 0x1c)
        d['sym'] = symname(u32(o + 0x18)) if u32(o + 0x18) else None
        d['dies'] = bool(u8(o + 0x15) & 0x10)
    elif k == 6:
        for nm, off in (('b', 0x2c), ('i', 0x30)):
            p = u32(o + off)
            if p:
                sub = opnd(p); d[nm] = sub.get('r', 'T%s' % sub.get('t')); d[nm + 'a'] = p
        d['disp'] = s32(o + 0x28)
        d['sc'] = u8(o + 0x14) & 0xf
        s = u32(o + 0x24)
        d['sym'] = symname(s) if s else None
    elif k in (2, 3, 4):
        d['sym'] = symname(u32(o + 0x18)) if u32(o + 0x18) else None
        if d['sym'] is None and k == 4:
            x = u32(o + 0x18); d['sym'] = cstr(u32(x + 4), 96) if x else None
    elif k == 7:
        d['imm'] = s32(o + 0x18)
    return d

def olist(p):
    out = []; k = 0
    while p and k < 12:
        try: out.append(opnd(p))
        except Exception: out.append(dict(k=-1))
        p = u32(p); k += 1
    return out

def first_tuple():
    return u32(u32(u32(st['f'] + 8)) + 0x1c)

def on_end():
    t = first_tuple(); k = 0; rows = []
    while t and k < 20000:
        flags = u8(t + 9)
        op = u32(t + 4)
        row = dict(t=t, op=op, line=tline(t), instr=bool(flags & 1), kind=u8(t + 8))
        if op < NMNEM and flags & 1:
            if op not in st['mnem']: st['mnem'][op] = cstr(u32(MNEMTAB + 4 * op), 16)
            row['m'] = st['mnem'][op]
        if flags & 1:
            row['src'] = olist(u32(t + 0x28)); row['dst'] = olist(u32(t + 0x2c))
        rows.append(row)
        t = u32(t); k += 1
    emit(ev='final', rows=rows)
    st['on'] = False

# ---- hooks -------------------------------------------------------------------------------------------
class BP(gdb.Breakpoint):
    def __init__(self, addr, fn, always=False):
        super().__init__('*0x%x' % addr, internal=True); self.fn = fn; self.always = always
    def stop(self):
        if self.always or st['on']:
            try: self.fn()
            except Exception as ex: emit(ev='error', where=self.location, err=repr(ex))
        return False

def on_driver():                       # 0x10bda210 regasg driver, stdcall(func)
    f = u32(reg('esp') + 4)
    try: name = cstr(u32(u32(f) + 4), 256)
    except Exception: name = None
    st.update(f=f, seq=0, pick=None)
    st['on'] = (TARGET == '' or (name is not None and TARGET in name))
    if st['on']: emit(ev='func', name=name)

def on_tuple():                        # 0x10bda3b8: esi = instruction tuple about to be assigned
    t = reg('esi'); st['seq'] += 1; st['tuple'] = t
    ev = dict(ev='tuple', seq=st['seq'], t=t, op=u32(t + 4), line=tline(t), ptr=rotptr(), occ=occupancy())
    if WANT_PRE:                       # operands as the assigner first sees them: temporaries still virtual (Tn)
        try: ev['src'] = olist(u32(t + 0x28)); ev['dst'] = olist(u32(t + 0x2c))
        except Exception: pass
    emit(**ev)

def on_rotreset():                     # 0x10bda3fa: op 0x303 tuple resets the rotation pointers
    emit(ev='rotreset', t=reg('esi'))

def on_free_phys():                    # 0x10bda510: OCC[esi] = 0 (a physical register's last use)
    emit(ev='free', r=reg('esi'), what='R', t=st['tuple'])

def on_free_temp():                    # 0x10bda59e: dying temp operand; [esi+0x1c] = its register
    r = u32(reg('esi') + 0x1c)
    emit(ev='free', r=r, what=owner(u32(OCC + 4 * r)), t=st['tuple'])

def on_fixed():                        # 0x10bda650: OCC[esi] = physical register defined by the tuple
    r = reg('esi'); prev = u32(OCC + 4 * r)
    emit(ev='fixed', r=r, t=reg('ebp'), prev=owner(prev))

def on_evict():                        # 0x10bdc8e0 stdcall(tuple, reg): temp in reg must leave (fixed use)
    esp = reg('esp'); t = u32(esp + 4); r = u32(esp + 8)
    emit(ev='evict', t=t, r=r, who=owner(u32(OCC + 4 * r)))

def on_pick():                         # 0x10bda7c0 stdcall(operand, tuple): give a register to a temp
    esp = reg('esp'); o = u32(esp + 4); t = u32(esp + 8)
    rec = u32(o + 0x1c); tid = u32(rec + 0x1c)
    excl = [r for r in REGS if bitset_has(u32(EXCL + 4 * r), tid)]
    st['pick'] = dict(ev='pick', t=t, op=u32(t + 4), line=tline(t), tid=tid, ty=u16(o + 0xa),
                      byte=bool(u8(rec + 5) & 0x80), ptr=rotptr(), occ=occupancy(), excl=excl,
                      pref0=regnum(u32(rec + 0x30)), path=[], seq=st['seq'])

def mark(name):
    def f():
        if st['pick'] is not None: st['pick']['path'].append(name)
    return f

def on_pref_known():                   # 0x10bda895: eax = the temp's preference descriptor (0 = none)
    if st['pick'] is not None: st['pick']['pref'] = regnum(reg('eax'))

def on_rot_take():                     # 0x10bdab46: rotation found edi free; eax = new pointer position
    p = st['pick']
    if p is not None:
        p['path'].append('rotate'); p['rot_reg'] = reg('edi')
        try: p['ptr_after'] = u32(reg('eax'))
        except Exception: p['ptr_after'] = -1

def on_spill_choice():                 # 0x10bdaaf2: no free register: ebp = register taken from its holder
    p = st['pick']
    if p is not None:
        p['path'].append('spill'); p['spill_reg'] = reg('ebp')
        p['spill_who'] = owner(u32(OCC + 4 * reg('ebp')))

def on_pick_ret():                     # the three `ret 8` of the pick: eax = register descriptor
    p = st['pick']
    if p is None: return
    p['reg'] = regnum(reg('eax')); p['ptr_end'] = rotptr()
    emit(**p); st['pick'] = None

def setup():
    gdb.execute('set pagination off')
    gdb.execute('handle all nostop noprint pass')
    gdb.execute('handle SIGTRAP stop print nopass')
    for t in gdb.selected_inferior().threads():
        t.switch()
        if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == 0x10b0cf40: break
    gdb.selected_inferior().write_memory(0x10b0cf40, b'\x83\xec')   # restore `sub esp, 0x18`
    BP(0x10bda210, on_driver, always=True)
    BP(0x10bda3b8, on_tuple)
    BP(0x10bda3fa, on_rotreset)
    BP(0x10bda510, on_free_phys)
    BP(0x10bda59e, on_free_temp)
    BP(0x10bda650, on_fixed)
    BP(0x10bdc8e0, on_evict)
    BP(0x10bda7c0, on_pick)
    BP(0x10bda895, on_pref_known)
    BP(0x10bda8d0, mark('pref'))
    BP(0x10bdab46, on_rot_take)
    BP(0x10bdab7e, mark('class5-call'))
    BP(0x10bdac2b, mark('first-free'))   # class order, skipping excluded
    BP(0x10bdac6f, mark('free-any'))     # class order, ignoring exclusions
    BP(0x10bdaaf2, on_spill_choice)
    for a in (0x10bda8e0, 0x10bdab36, 0x10bdabcf): BP(a, on_pick_ret)
    BP(0x10bda452, on_end)
    gdb.execute('continue')

setup()
