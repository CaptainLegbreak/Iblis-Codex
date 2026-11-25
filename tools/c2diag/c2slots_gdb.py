# c2slots_gdb.py - runs INSIDE gdb (python exec), attached to a cl.exe (wine) process whose c2.dll copy spins at
# the colour driver entry (the patched tcspin copy c2prio uses). Collects the stack-packing events of one function
# as JSON lines: every reference counted on a memory home, the count-sorted home list, the packed slots before the
# sort decision and the slots after it. Addresses are for c2.dll 14.00.50727.762 (SP1) at its base 0x10b00000.
import gdb, struct, json, os

OUT = open(os.environ['C2SLOTS_OUT'], 'w')
TARGET = os.environ.get('C2SLOTS_FUNC', '')

COLOUR = 0x10b0cf40       # colour driver entry, stdcall(func): [[func]+4] = decorated name (also the spin point)
COUNT = 0x10be9190        # count one reference: EDX = home symbol record, EBX = the IL tuple being walked
LISTDONE = 0x10be92d0     # numbering pass: the count-sorted list is complete (head 0x10d0fab0, next at +0x30)
DECIDE = 0x10beb315       # after packing: [esp+0x14] = packed size, [esp+0x1c] = comparator direction flag
FINAL = 0x10beb354        # after the (optional) slot sort
LISTHEAD = 0x10d0fab0
SLOTS, NSLOTS, SLOTLO, BYINDEX = 0x10d0fa9c, 0x10d0fa98, 0x10d0faa8, 0x10d0faa4
VROOT = 0x10d0eeec        # vline -> source line range tree (as in c2prio_gdb.py)

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

st = {'on': False}

def name(sym):
    try:
        n = u32(sym)
        nm = cstr(u32(n + 4), 96) if n else None
        return nm or 'tmp@%x' % sym
    except Exception:
        return '?%x' % sym

def vline_to_line(v):
    n = u32(VROOT); k = 0
    while n and k < 64:
        lo, hi, base = u32(n + 8), u32(n + 0xc), u32(n + 0x10)
        if lo <= v <= hi: return base - lo + v
        n = u32(n + 4) if v < lo else u32(n)
        k += 1
    return None

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

class BP(gdb.Breakpoint):
    def __init__(self, addr, fn, always=False):
        super().__init__('*0x%x' % addr, internal=True); self.fn = fn; self.always = always
    def stop(self):
        if self.always or st['on']:
            try: self.fn()
            except Exception as ex: emit(ev='error', where=self.location, err=repr(ex))
        return False

def on_func():
    f = u32(reg('esp') + 4)
    nm = cstr(u32(u32(f) + 4), 256)
    st['on'] = (TARGET == '' or (nm is not None and TARGET in nm))
    if st['on']: emit(ev='func', name=nm)

def on_count():
    sym = reg('edx'); t = reg('ebx')
    try: line = vline_to_line(u16(t + 0x14))
    except Exception: line = None
    emit(ev='ref', sym=sym, name=name(sym), size=s32(sym + 0x20), before=s32(sym + 0x38), line=line)

def on_list():
    e = u32(LISTHEAD); out = []; k = 0
    while e and k < 4096:
        out.append(dict(sym=e, name=name(e), size=s32(e + 0x20), count=s32(e + 0x38), kind=u8(e + 4)))
        e = u32(e + 0x30); k += 1
    emit(ev='list', homes=out)

def slots():
    arr, n, idx = u32(SLOTS), u32(NSLOTS), u32(BYINDEX)
    out = []
    for i in range(n):
        w = struct.unpack('<7I', mem(arr + 0x1c * i, 0x1c))
        members = [name(u32(idx + 4 * k)) for k in bitset_items(w[0])]
        out.append(dict(members=members, size=w[2], weight=w[3], cls=w[6] & 0xff, align=w[5]))
    return out

def on_decide():
    esp = reg('esp')
    emit(ev='packed', lo=u32(SLOTLO), packed_size=s32(esp + 0x14), direction=u32(esp + 0x1c), slots=slots())

def on_final():
    emit(ev='final', lo=u32(SLOTLO), slots=slots())

def setup():
    gdb.execute('set pagination off')
    gdb.execute('handle all nostop noprint pass')
    gdb.execute('handle SIGTRAP stop print nopass')
    for t in gdb.selected_inferior().threads():
        t.switch()
        if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == COLOUR: break
    gdb.selected_inferior().write_memory(COLOUR, b'\x83\xec')   # restore `sub esp, 0x18`
    BP(COLOUR, on_func, always=True)
    BP(COUNT, on_count)
    BP(LISTDONE, on_list)
    BP(DECIDE, on_decide)
    BP(FINAL, on_final)
    if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == COLOUR:
        on_func()
    gdb.execute('continue')

setup()
