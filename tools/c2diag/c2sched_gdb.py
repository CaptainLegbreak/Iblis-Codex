# c2sched_gdb.py - runs INSIDE gdb (python exec), attached to a cl.exe (wine) process whose c2.dll copy spins at
# the colour driver entry (the tcspin copy from setup_tcspin.py, shared with c2prio / c2temps / c2slots). Collects,
# for one function, what c2.dll decides AFTER register allocation: the list scheduler's dependence graph, ready list
# and picks per region, the jump optimiser's changes (cross-jumping, threading, branch rewrites) and, with
# C2SCHED_PASSES=1, the tuple stream after every pass of the back-end pipeline. Addresses: c2.dll 14.00.50727.762
# (SP1) at its base 0x10b00000. Every breakpoint only reads memory and continues.
import gdb, struct, json, os

# memory readers, vline -> line, tuple / operand decoding: shared with c2temps_gdb.py (its part before the hooks)
_src = open(os.path.join(os.environ['C2SCHED_HERE'], 'c2temps_gdb.py')).read().split('# ---- hooks')[0]
_src = _src.replace("OUT = open(os.environ['C2TEMPS_OUT'], 'w')", '')
exec(_src)

OUT = open(os.environ['C2SCHED_OUT'], 'w')
TARGET = os.environ.get('C2SCHED_FUNC', '')
PASSES = os.environ.get('C2SCHED_PASSES', '0') == '1'
JUMPS = os.environ.get('C2SCHED_JUMPS', '1') == '1'
PASS_SITES = json.loads(os.environ.get('C2SCHED_SITES', '[]'))   # [call VA, callee VA, return VA] in the pipeline

def emit(**k): OUT.write(json.dumps(k) + '\n'); OUT.flush()

st.update(on=False, f=0, region=0, last=None, jlast=None, jmode=None, jiter=0, nsnap=0)

# ---- scheduler (the list scheduler at 0x10c71dc0, stdcall(func)) ---------------------------------------------------
SCHED = 0x10c71dc0        # entry: [esp+4] = func
REGION_END = 0x10c71e3d   # 0x10c725c0 returned: EBX = first tuple of the region, EAX = the tuple it stops at
REGION_BUILT = 0x10c71e79 # dependence graph built (0x10b1be00); EBX = first tuple, EDI = end tuple
PRIO_DONE = 0x10c71e7e    # heights / priorities computed (0x10c71f00); context [0x10d0fb88] = {first node, last node}
CYCLE = 0x10c72185        # cycle loop, before the per-cycle pick (0x10c722c0): cycle = [0x10d0fb4c]
UNIT = 0x10c72331         # per candidate: ESI = unit returned by the slot check (-1 = no slot), EDI = node
TIME = 0x10c72360         # per candidate with a slot: EDX = cycle + unit backlog, [EDI+0x34] = earliest cycle
PICK = 0x10c72378         # EDI = node picked, ESI = unit, EBP = cycle
SCHED_END = 0x10c71ef1    # ret 4
CTX = 0x10d0fb88
READY_HEAD = 0x10d0fb78   # ready list, best first, linked through node +0x10
UNITS = 0x10d0f810        # per unit (4 of them, stride 12): busy count
TIMES = 0x10d439dc        # per opcode (stride 12): +4 = cycles the instruction occupies its unit

def node_id(n): return u16(n + 0x3a)    # creation index; 0 = the region's top sentinel

def row_of(t):
    if not t: return None
    flags = u8(t + 9); op = u32(t + 4)
    row = dict(t=t, op=op, line=tline(t), instr=bool(flags & 1), kind=u8(t + 8))
    if op < NMNEM and flags & 1:
        if op not in st['mnem']: st['mnem'][op] = cstr(u32(MNEMTAB + 4 * op), 16)
        row['m'] = st['mnem'][op]
    if flags & 1:
        row['src'] = olist(u32(t + 0x28)); row['dst'] = olist(u32(t + 0x2c))
        for d in row['src']:
            if d.get('k') == 4 and not d.get('sym'): d['tgt'] = u32(d['a'] + 0x18)   # branch target label symbol
    elif row['kind'] == 27:
        row['lab'] = u32(t + 0x24)                                                      # label symbol
    return row

def set_func(f, where):
    try: name = cstr(u32(u32(f) + 4), 256)
    except Exception: name = None
    on = (TARGET == '' or (name is not None and TARGET in name))
    if on and (not st['on'] or st['f'] != f):
        emit(ev='func', name=name, where=where)
        st.update(last=None)
    st.update(on=on, f=f)

def on_sched_entry():
    set_func(u32(reg('esp') + 4), 'sched')
    st['region'] = 0
    if st['on']: emit(ev='sched_begin')

def on_region_end():
    if st['on']:
        emit(ev='region_seen', start=reg('ebx'), end=reg('eax'), line=tline(reg('ebx')) if reg('ebx') else None)

def on_region_built():
    st['region'] += 1
    emit(ev='region', n=st['region'], start=reg('ebx'), end=reg('edi'))

def on_prio_done():
    first = u32(u32(CTX)); last = u32(u32(CTX) + 4)
    n = first; k = 0; nodes = []
    while n and k < 5000:
        succ = []; e = u32(n + 0xc); j = 0
        while e and j < 1000:                      # edge: +0 next succ edge, +4 next pred edge, +8 from, +0xc to
            succ.append(dict(to=node_id(u32(e + 0xc)), lat=u16(e + 0x14), kind=u8(e + 0x16), fl=u32(e + 0x10)))
            e = u32(e); j += 1
        t = u32(n + 0x1c)
        try: occ = u32(u32(TIMES) + 12 * u32(t + 4) + 4) if t and u32(t + 4) < 0x273 else 0
        except Exception: occ = None
        nodes.append(dict(id=node_id(n), t=t, row=row_of(t), npred=u16(n + 0x24), nsucc=u16(n + 0x26),
                          nweak=u16(n + 0x28), prio=u32(n + 0x2c), key=u32(n + 0x30), height=u16(n + 0x38),
                          unit=u16(n + 0x3e), flags=u8(n + 0x40), occ=occ, succ=succ))
        if n == last: break
        n = u32(n); k += 1
    emit(ev='dag', region=st['region'], first=node_id(first), last=node_id(last), nodes=nodes)

def ready_list():
    out = []; n = u32(READY_HEAD); k = 0
    while n and k < 2000:
        out.append([node_id(n), u32(n + 0x30), u32(n + 0x34)])
        n = u32(n + 0x10); k += 1
    return out

def on_cycle():
    emit(ev='cycle', region=st['region'], cyc=u32(0x10d0fb4c), ready=ready_list(),
         units=[s32(UNITS + 12 * i) for i in range(4)])

def on_unit():
    u = reg('esi'); u = u - (1 << 32) if u & 0x80000000 else u
    emit(ev='try', id=node_id(reg('edi')), unit=u)

def on_time():
    emit(ev='time', id=node_id(reg('edi')), early=u32(reg('edi') + 0x34), limit=reg('edx'))

def on_pick():
    emit(ev='pick', id=node_id(reg('edi')), unit=reg('esi'), cyc=reg('ebp'))

def on_sched_end():
    if st['on']: emit(ev='sched_end')

# ---- tuple stream snapshots (pipeline passes and jump optimiser changes) -------------------------------------------
def first_tuple_of(f):
    return u32(u32(u32(f + 8)) + 0x1c)

def take_snap():
    t = first_tuple_of(st['f']); k = 0; rows = []
    while t and k < 50000:
        rows.append(row_of(t)); t = u32(t); k += 1
    return rows

def snap(tag, force=False, **extra):
    if not st['on']: return
    try: rows = take_snap()
    except Exception as ex:
        emit(ev='snaperr', tag=tag, err=repr(ex)); return
    sig = [(r['t'], r['op'], json.dumps(r.get('src')), json.dumps(r.get('dst'))) for r in rows]
    if force or sig != st['last']:
        st['nsnap'] += 1
        emit(ev='snap', tag=tag, rows=rows, n=st['nsnap'], **extra); st['last'] = sig

# ---- jump optimiser (0x10b2c950: eax = mode, ecx = func; iterates 0x10b2ccf0 until nothing changes, at most 17x) --
JOPT = 0x10b2c950
JITER = 0x10b2ccf0        # one sweep over the tuple stream; EBP walks the label / branch tuples
JOPT_END = 0x10b2cadb
JCHANGE = (0x10b2cdae, 0x10b2cdf8, 0x10b2ce3d, 0x10b2ce57, 0x10b2d1b6)   # sweep sets its 'changed' flag

def on_jopt():
    st['jmode'] = reg('eax'); st['jiter'] = 0
    if reg('ecx') != st['f']: set_func(reg('ecx'), 'jumpopt')
    if st['on']:
        emit(ev='jopt_begin', mode=st['jmode'])
        snap('jumpopt mode %d: start' % st['jmode'])

def on_jiter():
    st['jiter'] += 1; st['jlast'] = None

def on_jcall(target):
    def f():
        st['jlast'] = target
    return f

def on_jchange():
    t = reg('ebp')
    snap('jumpopt mode %s, sweep %d: %s' % (st['jmode'], st['jiter'],
         ('0x%x' % st['jlast']) if st['jlast'] else 'inline'), force=False,
         jmode=st['jmode'], jiter=st['jiter'], jfn=st['jlast'], at=t, atline=tline(t) if t else None)

def on_jopt_end():
    if st['on']:
        snap('jumpopt mode %s: end' % st['jmode'], force=True, jmode=st['jmode'])
        emit(ev='jopt_end', mode=st['jmode'], sweeps=st['jiter'])

# ---- pipeline drivers that name the function early (with the --early prelude, every pass of the target is seen) --
def on_f_eax(where):
    def f():
        set_func(reg('eax'), where)
    return f

def on_regasg():
    set_func(u32(reg('esp') + 4), 'regasg')

def on_regasg_end():
    snap('local assigner (regasg) done')

def on_pipe_end():
    if st['on']:
        snap('pipeline end', force=True)
        emit(ev='pipe_end')
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
    BP(0x10c06890, on_f_eax('optimiser'), always=True)              # per-function optimiser driver, eax = func
    BP(0x10c06540, on_f_eax('codegen'), always=True)                # per-function code generation driver, eax = func
    BP(0x10bda210, on_regasg, always=True)                           # local assigner driver, stdcall(func)
    BP(0x10bda452, on_regasg_end)
    BP(0x10c0666a, on_pipe_end)                                      # end of the code generation driver
    BP(SCHED, on_sched_entry, always=True)
    BP(REGION_END, on_region_end)
    BP(REGION_BUILT, on_region_built)
    BP(PRIO_DONE, on_prio_done)
    BP(CYCLE, on_cycle)
    BP(UNIT, on_unit)
    BP(TIME, on_time)
    BP(PICK, on_pick)
    BP(SCHED_END, on_sched_end)
    if JUMPS:
        BP(JOPT, on_jopt, always=True)
        BP(JITER, on_jiter)
        BP(JOPT_END, on_jopt_end)
        for a in JCHANGE: BP(a, on_jchange)
        for a, tgt in json.loads(os.environ.get('C2SCHED_JCALLS', '[]')): BP(a, on_jcall(tgt))
    if PASSES:
        for a, tgt, nxt in PASS_SITES:
            BP(nxt, (lambda a=a, tgt=tgt: snap('pass 0x%x (called at 0x%x)' % (tgt, a), callee=tgt, site=a)))
    gdb.execute('continue')

setup()
