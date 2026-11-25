# c2prio_gdb.py - runs INSIDE gdb (python exec), attached to a cl.exe (wine) process whose c2.dll copy
# spins at the colour driver entry (0x10b0cf40 patched to EB FE). Collects allocator events as JSON lines.
# All addresses are for c2.dll 14.00.50727.762 (SP1) loaded at its preferred base 0x10b00000.
import gdb, struct, json, os

OUT = open(os.environ['C2PRIO_OUT'], 'w')
TARGET = os.environ.get('C2PRIO_FUNC', '')          # substring of the decorated name; '' = all functions
WANT_BLOCKS = os.environ.get('C2PRIO_BLOCKS', '1') == '1'

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

HASH = 0x10d15090          # candidate hash table, 1024 buckets, chain at +0x30
REGDESC0 = 0x10d09f70      # register descriptor n = REGDESC0 + n*0x60, number at +0x1c
REGLIST = 0x10ce5a08       # per-class allocation order (0-terminated list of register numbers)
COST = 0x10d14f10          # per-register cost table built by the colour step
VROOT = 0x10d0eeec         # vline -> source line range tree

st = {'on': False, 'func': None, 'cls': None}

def regno(p):
    if not p: return 0
    try: return u32(p + 0x1c)
    except Exception: return -1

def symname(sym):
    try:
        n = u32(sym)
        return cstr(u32(n + 4), 96) if n else None
    except Exception: return None

def vline_to_line(v):
    n = u32(VROOT); k = 0
    while n and k < 64:
        lo, hi, base = u32(n + 8), u32(n + 0xc), u32(n + 0x10)
        if lo <= v <= hi: return base - lo + v
        n = u32(n + 4) if v < lo else u32(n)
        k += 1
    return None

def tline(t):
    try: return vline_to_line(u16(t + 0x14))
    except Exception: return None

def bitset_has(bs, bit):
    if not bs: return False
    n = u32(bs); base = bit & ~63; k = 0
    while n and k < 4096:
        b = u32(n)
        if b == base:
            lo, hi = u32(n + 4), u32(n + 8)
            r = bit & 63
            return bool((lo >> r) & 1) if r < 32 else bool((hi >> (r - 32)) & 1)
        if b > base: return False
        n = u32(n + 0xc); k += 1
    return False

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

def const_of(sym):
    # unnamed symbol records of kept constants point (+0x28) at an operand node: kind 0x275 = immediate
    # (value at +0x18), 0x27b = address of a symbol (symbol record at +0x18)
    try:
        if not sym or u32(sym): return None
        n = u32(sym + 0x28)
        if not n: return None
        k = u32(n + 4)
        if k == 0x275: return 'const %d' % s32(n + 0x18)
        if k == 0x27b:
            nm = symname(u32(n + 0x18))
            return 'addr &%s' % (nm.lstrip('_') if nm else '?')
    except Exception: pass
    return None

def cand_rec(e):
    w = struct.unpack('<18I', mem(e, 0x48))
    pr = w[3] - (1 << 32) if w[3] & 0x80000000 else w[3]
    cost = w[16] - (1 << 32) if w[16] & 0x80000000 else w[16]
    return dict(id=w[7], sym=w[0], name=symname(w[0]) if w[0] else None, const=const_of(w[0]), prio=pr, refs=w[9],
                cost=cost, key=w[17], flags=w[1], reg=regno(w[4]), first_blk=w[10], last_blk=w[11])

def all_cands():
    out = []
    for b in range(1024):
        e = u32(HASH + 4 * b); k = 0
        while e and k < 10000:
            out.append(cand_rec(e)); e = u32(e + 0x30); k += 1
    return out

def find_cand(cid):
    e = u32(HASH + 4 * (cid & 0x3ff))
    while e:
        if u32(e + 0x1c) == cid: return e
        e = u32(e + 0x30)
    return 0

class BP(gdb.Breakpoint):
    def __init__(self, addr, fn, always=False):
        super().__init__('*0x%x' % addr, internal=True); self.fn = fn; self.always = always
    def stop(self):
        if self.always or st['on']:
            try: self.fn()
            except Exception as ex: emit(ev='error', where=self.location, err=repr(ex))
        return False

# ---- function entry (colour driver) -------------------------------------------------------------
def on_func():
    f = u32(reg('esp') + 4)
    name = cstr(u32(u32(f) + 4), 256)
    st['func'] = name
    st['on'] = (TARGET == '' or (name is not None and TARGET in name))
    if st['on']: emit(ev='func', name=name)

# ---- priority pass (0x10b10420, stdcall(func, class, classset)) ---------------------------------
def on_prio_begin():
    esp = reg('esp')
    st['cls'] = u32(esp + 8)
    st['clsset'] = u32(esp + 0xc)
    emit(ev='prio_begin', cls=st['cls'])

def on_prio_end():
    esp = reg('esp')                 # at ret 0xc: [esp+4]=func [esp+8]=class [esp+0xc]=class set
    cls = u32(esp + 8); ids = set(bitset_items(u32(esp + 0xc)))
    cands = [c for c in all_cands() if c['id'] in ids]
    emit(ev='prio_end', cls=cls, cands=cands)

def on_ref():                        # add [ebp+0x18], eax  (ebp = candidate, eax = weight units)
    esp = reg('esp'); cand = reg('ebp'); inc = reg('eax')
    t = u32(esp + 0x44); blk = u32(esp + 0x1c)
    emit(ev='ref', id=u32(cand + 0x1c), inc=inc, line=tline(t), blk=blk, op=u32(t + 4),
         kind=('use' if gdb.selected_frame().pc() == 0x10b109b7 else 'def'))

def on_block_end():                  # at imul edi, ebp: edi = K, ebp = w; ecx = list A, [esp+0x18] = list B
    esp = reg('esp'); K = reg('edi'); w = reg('ebp'); blk = u32(esp + 0x1c)
    A = []; e = reg('ecx'); k = 0
    while e and k < 4096:
        A.append(dict(id=u32(e + 0x1c), refunits=u32(e + 0x18), counted=(u32(e + 0x10) == 0)))
        e = u32(e + 0x14); k += 1
    B = []; e = u32(esp + 0x18); k = 0
    while e and k < 4096:
        B.append(dict(id=u32(e + 0x1c), refunits=u32(e + 0x18), referenced=bool(u8(e + 6) & 0x10)))
        e = u32(e + 0x14); k += 1
    lines = []
    if WANT_BLOCKS:
        t = u32(blk + 0x1c); last = u32(blk + 0x20); k = 0
        while t and k < 5000:
            l = tline(t)
            if l: lines.append(l)
            if t == last: break
            t = u32(t); k += 1
    emit(ev='block', blk=blk, w=w, K=K, depth=u8(blk + 0x17e), A=A, B=B,
         lines=[min(lines), max(lines)] if lines else None,
         profmode=u32(0x10d0ffdc))

# ---- colouring loop ------------------------------------------------------------------------------
def on_pop():                        # after mov ebp,[0x10d1508c]
    e = reg('ebp'); c = cand_rec(e)
    emit(ev='pop', cand=c, id=c['id'], prio=c['prio'], key=c['key'], cost=c['cost'])

def mk_path(name):
    def f(): emit(ev='path', path=name, id=u32(reg('ebp') + 0x1c))
    return f

def on_pick():                       # in 14b70 before the register write: ebx = chosen register number
    esp = reg('esp'); cand = u32(esp + 0x20)
    lst = []; p = reg('ebp'); k = 0
    while k < 16:
        r = u32(p + 4 * k)
        if not r: break
        lst.append(r); k += 1
    allowed = u32(cand + 0x20)
    costs = {str(r): s32(COST + 4 * r) for r in lst}
    emit(ev='pick', id=u32(cand + 0x1c), chosen=reg('ebx'), order=lst,
         allowed=[r for r in lst if bitset_has(allowed, r)], costs=costs)

def on_split_after():                # after 11b20 (rebuild pieces) - record the new set of ids
    emit(ev='rebuild', ids=sorted(c['id'] for c in all_cands()))

def on_func_end():
    if st['on']:
        emit(ev='final', cands=all_cands())

def setup():
    gdb.execute('set pagination off')
    gdb.execute('handle all nostop noprint pass')
    gdb.execute('handle SIGTRAP stop print nopass')
    for t in gdb.selected_inferior().threads():       # pick the thread parked on the spin point, if any
        t.switch()
        if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == 0x10b0cf40: break
    gdb.selected_inferior().write_memory(0x10b0cf40, b'\x83\xec')   # restore `sub esp, 0x18`
    BP(0x10b0cf40, on_func, always=True)
    BP(0x10b10420, on_prio_begin)
    BP(0x10b1153f, on_prio_end)
    BP(0x10b109b7, on_ref)
    BP(0x10b10ff9, on_ref)
    BP(0x10b11484, on_block_end)
    BP(0x10b0d341, on_pop)
    BP(0x10b0d37e, mk_path('d690'))
    BP(0x10b0d3aa, mk_path('requeue'))
    BP(0x10b0d3c5, mk_path('noreg'))
    BP(0x10b0d464, mk_path('colour'))
    BP(0x10b14e1a, on_pick)
    BP(0x10b0d28e, on_split_after)
    BP(0x10b0d5d2, on_func_end)       # before 178e0 near the driver's end
    # if the thread is already parked on the spin point, gdb will step over the breakpoint there on `continue`,
    # so record that first entry by hand; otherwise the breakpoint catches it.
    if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == 0x10b0cf40:
        on_func()
    gdb.execute('continue')

setup()
