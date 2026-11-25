# c2split_gdb.py - runs INSIDE gdb (python exec), attached to a cl.exe (wine) process whose c2.dll copy spins at the
# colour driver entry (0x10b0cf40 patched to EB FE, see setup_tcspin.py). Collects the global allocator's live-range
# splitting decisions as JSON lines: what started each split round, which webs were cut and how, the cut markers in the
# tuple stream, the stream before and after each rebuild, and the final stream with registers. It also records every
# event c2prio_gdb.py records (priorities, pops, picks). Addresses: c2.dll 14.00.50727.762 (SP1) at base 0x10b00000.
# Every breakpoint only reads memory and continues.
import gdb, struct, json, os

_HERE = os.environ['C2SPLIT_HERE']
os.environ['C2PRIO_OUT'] = os.environ['C2SPLIT_OUT']
os.environ['C2PRIO_FUNC'] = os.environ.get('C2SPLIT_FUNC', '')
os.environ.setdefault('C2PRIO_BLOCKS', '0')
exec(open(os.path.join(_HERE, 'c2prio_gdb.py')).read().split('\nsetup()')[0])     # hooks / helpers of c2prio
os.environ['C2TEMPS_OUT'] = os.devnull
TMP = {}
exec(open(os.path.join(_HERE, 'c2temps_gdb.py')).read().split('# ---- hooks')[0], TMP)  # operand decoding of c2temps

MARK_KIND, MARK_OP = 0x1c, 0x2f6       # cut marker tuple: kind 0x1c, opcode 0x2f6, bitset of web ids at +0x20
MNEMTAB, NMNEM = 0x10cdf220, 628
st.update(f=0, mode=None, who=None, mnem={})

def cmap():
    """candidate record address -> id, for every live candidate"""
    out = {}
    for b in range(1024):
        e = u32(HASH + 4 * b); k = 0
        while e and k < 10000:
            out[e] = u32(e + 0x1c); e = u32(e + 0x30); k += 1
    return out

def opnd(o, cm):
    d = TMP['opnd'](o)
    x = u32(o + 0x1c)
    if d.get('k') == 1 and x in cm: d['c'] = cm[x]          # operand of a web: +0x1c = candidate record
    if d.get('k') == 6:                                       # base / index of a memory operand can be webs too
        for nm in ('b', 'i'):
            if d.get(nm + 'a'):
                y = u32(d[nm + 'a'] + 0x1c)
                if y in cm: d[nm + 'c'] = cm[y]
    return d

def olist(p, cm):
    out = []; k = 0
    while p and k < 12:
        try: out.append(opnd(p, cm))
        except Exception: out.append(dict(k=-1))
        p = u32(p); k += 1
    return out

def stream():
    """every tuple of the function in layout order, block by block"""
    cm = cmap(); f = st['f']; rows = []; bi = 0; tot = 0
    b = u32(u32(f + 8))
    while b and bi < 4000 and tot < 40000:
        t = u32(b + 0x1c); last = u32(b + 0x20); j = 0
        rows.append(dict(blk=bi, label=True, depth=u8(b + 0x17e)))
        while t and j < 20000:
            fl = u8(t + 9); op = u32(t + 4); kd = u8(t + 8)
            row = dict(blk=bi, t=t, op=op, kind=kd, line=tline(t), instr=bool(fl & 1))
            if kd == MARK_KIND and op == MARK_OP:
                row['ids'] = bitset_items(u32(t + 0x20))
            elif fl & 1:
                if op < NMNEM:
                    if op not in st['mnem']: st['mnem'][op] = cstr(u32(MNEMTAB + 4 * op), 16)
                    row['m'] = st['mnem'][op]
                try:
                    row['src'] = olist(u32(t + 0x28), cm); row['dst'] = olist(u32(t + 0x2c), cm)
                except Exception: pass
            rows.append(row); tot += 1
            if t == last: break
            t = u32(t); j += 1
        b = u32(b); bi += 1
    return rows

def crec(c):
    r = cand_rec(c)
    r.update(f5=u8(c + 5), f6=u8(c + 6), b34=u8(c + 0x34), sw=s32(c + 0x40),
             allowed=bitset_items(u32(c + 0x20), 64) if u32(c + 0x20) else [])
    return r

def cid(c):
    try: return u32(c + 0x1c)
    except Exception: return None

# ---- function entry: keep the function pointer for the stream walks ----------------------------------------
def on_func_s():
    st['f'] = u32(reg('esp') + 4)
    on_func()

# ---- what started a split round (the driver's calls that can return a split set) ---------------------------
def mk_mode(name, cand_at=None, cand_reg=None):
    def f():
        esp = reg('esp')
        c = u32(esp + cand_at) if cand_at is not None else (reg(cand_reg) if cand_reg else 0)
        st['mode'] = name; st['who'] = cid(c) if c else None
        emit(ev='mode', mode=name, who=st['who'], cand=crec(c) if c else None)
    return f

def mk_mode_end(name):
    def f():
        resolve_marks()
        emit(ev='mode_end', mode=name, set=reg('eax') != 0)
        st['mode'] = None; st['who'] = None
    return f

# ---- the decisions inside those calls -----------------------------------------------------------------------
def on_cut(kind):                       # 0x10b16720 stdcall(cand, regset): cut where no register of regset is free
    def f():
        esp = reg('esp'); c = u32(esp + 4); rs = u32(esp + 8)
        emit(ev='decide', how=kind, id=cid(c), cand=crec(c), regs=bitset_items(rs, 64), mode=st['mode'], who=st['who'])
    return f

def on_blocksplit(kind):                # 0x10b1b3b0 / 0x10b1b280 stdcall(cand)
    def f():
        esp = reg('esp'); c = u32(esp + 4)
        emit(ev='decide', how=kind, id=cid(c), cand=crec(c), mode=st['mode'], who=st['who'])
    return f

def on_memory():                        # 0x10b17220 stdcall(func, cand): the whole web goes to memory
    esp = reg('esp'); c = u32(esp + 8)
    emit(ev='decide', how='memory', id=cid(c), cand=crec(c), mode=st['mode'], who=st['who'], ra=u32(esp))

def on_force():                         # 0x10b0d6a5: eax = 0x10b1b430's answer (1 = restricted to its preference)
    emit(ev='decide', how='force-pref' if reg('eax') else 'no-pref', id=st['who'], mode=st['mode'], who=st['who'])

def on_defer():                         # 0x10b0d6e5: re-inserted further down the list once (flag +5 0x40)
    emit(ev='decide', how='defer', id=cid(reg('edx')), mode=st['mode'], who=st['who'])

def on_mark_set():                      # 0x10b185d0(eax = candidate set, ecx = tuple, ...): may put one cut marker
    t = reg('ecx')                      # right after ecx; its final id set is read once the caller is done
    st.setdefault('pending', []).append((t, u32(t), u32(reg('esp'))))

def resolve_marks():
    for t, old_next, ra in st.pop('pending', []):
        m = u32(t)
        if m and m != old_next and u8(m + 8) == MARK_KIND and u32(m + 4) == MARK_OP:
            emit(ev='mark', ids=bitset_items(u32(m + 0x20)), after=t, line=tline(t), mode=st['mode'], who=st['who'], ra=ra)

def on_nb_lost():                       # 0x10b15579 in 0x10b15470: esi = neighbour, the coloured register removed
    c = reg('esi')
    if u32(u32(c + 0x20)) == 0:
        emit(ev='nb_lost', id=cid(c), cand=crec(c), who=st['who'])

def on_mark():                          # 0x10b18700 stdcall(after_tuple), eax = web id: one cut marker
    esp = reg('esp'); t = u32(esp + 4)
    emit(ev='mark', ids=[reg('eax')], after=t, line=tline(t), mode=st['mode'], who=st['who'], ra=u32(esp))

# ---- rebuild and final stream ----------------------------------------------------------------------------
def on_rebuild_in():                    # 0x10b11b20 stdcall(func, split set, class)
    esp = reg('esp'); resolve_marks()
    emit(ev='rb_in', ids=bitset_items(u32(esp + 8)), rows=stream(), cands=all_cands())

def on_rebuild_out():                   # 0x10b0d28e, right after the rebuild
    emit(ev='rb_out', rows=stream(), cands=all_cands())

def on_final_stream():                  # 0x10b0d5d7: after 0x10b178e0 (spill code finished, registers written)
    if st['on']:
        emit(ev='stream_end', rows=stream(), cands=all_cands())

def setup_split():
    gdb.execute('set pagination off')
    gdb.execute('handle all nostop noprint pass')
    gdb.execute('handle SIGTRAP stop print nopass')
    for t in gdb.selected_inferior().threads():
        t.switch()
        if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == 0x10b0cf40: break
    gdb.selected_inferior().write_memory(0x10b0cf40, b'\x83\xec')   # restore `sub esp, 0x18`
    BP(0x10b0cf40, on_func_s, always=True)
    BP(0x10b10420, on_prio_begin)
    BP(0x10b1153f, on_prio_end)
    BP(0x10b109b7, on_ref)
    BP(0x10b10ff9, on_ref)
    if WANT_BLOCKS: BP(0x10b11484, on_block_end)
    BP(0x10b0d341, on_pop)
    BP(0x10b0d37e, mk_path('d690'))
    BP(0x10b0d3aa, mk_path('requeue'))
    BP(0x10b0d3c5, mk_path('noreg'))
    BP(0x10b0d464, mk_path('colour'))
    BP(0x10b14e1a, on_pick)
    BP(0x10b0d28e, on_split_after)
    BP(0x10b0d5d2, on_func_end)
    # round starters
    BP(0x10b11770, mk_mode('precolour'))                     # sorted list built; webs with no register at all
    BP(0x10b0d22f, mk_mode_end('precolour'))
    BP(0x10b13460, mk_mode('pressure', cand_at=8))         # colour step: pressure check of the popped web
    BP(0x10b0d469, mk_mode_end('pressure'))
    BP(0x10b15470, mk_mode('neighbours', cand_at=8))         # after the colour: neighbours lose the register
    BP(0x10b0d485, mk_mode_end('neighbours'))
    BP(0x10b0d690, mk_mode('notcoloured', cand_reg='ecx'))   # pop of a web that is not coloured
    BP(0x10b0d383, mk_mode_end('notcoloured'))
    BP(0x10b0d830, mk_mode('noreg', cand_at=4))              # pop of a web with no register allowed
    BP(0x10b0d3ca, mk_mode_end('noreg'))
    # decisions
    BP(0x10b16720, on_cut('cut'))
    BP(0x10b1b3b0, on_blocksplit('blocks'))
    BP(0x10b1b280, on_blocksplit('loop'))
    BP(0x10b17220, on_memory)
    BP(0x10b0d6a5, on_force)
    BP(0x10b0d6e5, on_defer)
    BP(0x10b185d0, on_mark_set)
    BP(0x10b15579, on_nb_lost)
    BP(0x10b18700, on_mark)
    BP(0x10b11b20, on_rebuild_in)
    BP(0x10b0d28e, on_rebuild_out)
    BP(0x10b0d5d7, on_final_stream)
    if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == 0x10b0cf40:
        on_func_s()
    gdb.execute('continue')

setup_split()
