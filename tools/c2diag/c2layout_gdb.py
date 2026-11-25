# c2layout_gdb.py - runs INSIDE gdb (python exec), attached to a cl.exe (wine) process whose c2.dll copy spins at the
# colour driver entry (the tcspin copy from setup_tcspin.py, shared with c2prio / c2temps / c2sched / c2force). Records,
# for one function, the tuple stream around c2.dll's two late control-flow passes: the jump optimiser (flow pass,
# 0x10b2c950: tail merging, cross-jumping, branch chaining) and the late block layout (0x10b312c0: blocks pulled behind
# jumps, short tails copied into jump sites), plus the stream at code emission. Addresses: c2.dll 14.00.50727.762 (SP1)
# at its base 0x10b00000. Every breakpoint only reads memory and continues. Events are JSON lines (lists) in
# $C2LAYOUT_OUT.
import gdb, struct, json, os

# memory readers and vline -> line: shared with c2temps_gdb.py (its part before the hooks), as c2sched_gdb.py does
_src = open(os.path.join(os.environ['C2LAYOUT_HERE'], 'c2temps_gdb.py')).read().split('# ---- hooks')[0]
_src = _src.replace("OUT = open(os.environ['C2TEMPS_OUT'], 'w')", '')
exec(_src)

OUT = open(os.environ['C2LAYOUT_OUT'], 'w')
FUNC = os.environ.get('C2LAYOUT_FUNC', '')     # substring of the decorated name; '' = every function
CURFUNC = 0x10d1239c                           # the function being generated: [[CURFUNC]+4] = decorated name
SPIN = 0x10b0cf40                              # colour driver entry, patched to EB FE in the spin copy
L = {'on': False, 'fobj': 0, 'nsnap': 0}
MAXSNAP = int(os.environ.get('C2LAYOUT_MAXSNAP', '4000'))


def ev(*a):
    OUT.write(json.dumps(list(a)) + '\n'); OUT.flush()


def curfn():
    try: return cstr(u32(u32(CURFUNC) + 4), 256) or '?'
    except Exception: return '?'


# tuple: +0x00 next, +0x04 opcode, +0x08 kind (13 op, 15 call, 16 ret, 18 branch, 26/27 label), +0x14 vline,
# +0x28 source operand list. A branch's target: operand kind 4 (+0x08) whose symbol (+0x18) is a label (+0x30 == 3);
# the label's tuple is at symbol +0x33.
def target(t):
    try:
        op = u32(t + 0x28)
        if not op or u8(op + 8) != 4: return 0
        x = u32(op + 0x18)
        if u8(x + 0x30) != 3: return 0
        return u32(x + 0x33)
    except Exception: return 0


def stream(fobj):
    """the function's tuple stream: first tuple at [[[fobj+8]]+0x1c]; rows [tuple, kind, line, opcode, target]"""
    out = []
    try: t = u32(u32(u32(fobj + 8)) + 0x1c)
    except Exception: return out
    k = 0
    while t and k < 20000:
        try: b = mem(t, 0x18)
        except Exception: break
        nx, op = struct.unpack('<II', b[:8]); kd = b[8]
        ln = tline(t) or 0
        out.append([t, kd, ln, op, target(t) if kd == 18 else 0])
        t = nx; k += 1
    return out


def snap(tag):
    if L['on'] and L['fobj'] and L['nsnap'] < MAXSNAP:
        L['nsnap'] += 1
        ev('snap', tag, stream(L['fobj']))


class BP(gdb.Breakpoint):
    def __init__(s, a, fn):
        super().__init__('*0x%x' % a, internal=True); s.fn = fn
    def stop(s):
        try: s.fn()
        except Exception as e: ev('err', '%x' % int(s.location.lstrip('*'), 16), repr(e))
        return False


def mk_pass_entry(name, fobj_get):
    def h():
        fn = curfn()
        L['on'] = (not FUNC) or (FUNC in fn)
        if L['on']:
            L['fobj'] = fobj_get(); ev('pass', name, fn); snap(name + ':in')
    return h


def mk_pass_exit(name):
    def h():
        if L['on']: snap(name + ':out')
    return h


# Transform call sites inside the flow pass (the same sites as c2sched.JCALLS; subject tuple in EBP at the call, EAX for
# 0x10b2cac3) and their short names. A call that returns nonzero (or a void one) is followed by a snapshot.
FLOW = {0x10b2d056: 'd400', 0x10b2d065: 'd530', 0x10b2d0db: 'e1b0', 0x10b2d0ee: 'e700', 0x10b2d105: 'd890',
        0x10b2d119: 'dff0', 0x10b2d134: 'd6c0', 0x10b2d161: 'eb00', 0x10b2d174: 'eff0', 0x10b2d184: 'f560',
        0x10b2d1a6: 'f700', 0x10b2d1be: 'a400', 0x10b2cf54: '306c0', 0x10b2cf68: '30f00', 0x10b2cf98: '321e0',
        0x10b2d00d: 'dc70', 0x10b2d29a: 'dc70', 0x10b2d2e1: 'dc70', 0x10b2cf34: '28590', 0x10b2cf40: '28590',
        0x10b2cdf3: '27040', 0x10b2ce38: '27040', 0x10b2ce52: '27040', 0x10b2d317: 'c5cef0', 0x10b2cac3: 'dff0b'}
VOID = {'28590', '27040', 'a400', '2cca0'}


def mk_call(name, subj_reg):
    def h():
        if not L['on']: return
        t = reg(subj_reg)
        try: ln = tline(t) or 0; kd = u8(t + 8)
        except Exception: ln = -1; kd = -1
        L['pend'] = [name, t, kd, ln]
    return h


def mk_ret(name, ps):
    def h():
        if not L['on'] or not L.get('pend'): return
        p = L.pop('pend'); r = reg('eax')
        if r or name in VOID:
            ev('xf', ps, p[0], p[1], p[2], p[3], r); snap('after ' + p[0])
    return h


def arm():
    # flow pass: entry 0x10b2c950 (ECX = function object), exit 0x10b2cad2; every hooked site is a direct E8 call,
    # so its return address is site + 5
    BP(0x10b2c950, mk_pass_entry('flow', lambda: reg('ecx')))
    BP(0x10b2cad2, mk_pass_exit('flow'))
    for a, n in FLOW.items():
        BP(a, mk_call(n, 'ebp' if n != 'dff0b' else 'eax')); BP(a + 5, mk_ret(n, 'flow'))
    # late layout pass: entry 0x10b312c0 ([esp+4] = function object), exit 0x10b31984
    BP(0x10b312c0, mk_pass_entry('layout', lambda: u32(reg('esp') + 4)))
    BP(0x10b31984, mk_pass_exit('layout'))
    for a in (0x10b313a6, 0x10b31438, 0x10b31461):           # tail duplication call sites (EAX = subject)
        BP(a, mk_call('dup', 'eax')); BP(a + 5, mk_ret('dup', 'layout'))
    for a, n in ((0x10b3147c, '2cca0'), (0x10b31590, 'dff0'), (0x10b315ab, 'd400')):
        BP(a, mk_call(n, 'eax')); BP(a + 5, mk_ret(n, 'layout'))

    # the decision for each unconditional jump in the layout pass: candidate (ESI = the jmp), the copy-size check
    # (EDI = estimated size, EAX = limit, [esp+0x14] = refuse flag), copy taken, block moved, next candidate
    def jc():
        if L['on']:
            j = reg('esi'); ev('jcand', j, tline(j) or 0, target(j))
    def sz():
        if L['on']: ev('jsize', 0, reg('edi'), reg('eax'), u32(reg('esp') + 0x14))
    def cp():
        if L['on']: ev('jcopy', u32(reg('esp') + 0x10), u32(reg('esp') + 0x1c)); L['pendsnap'] = 'after dup-copy'
    def mv():
        if L['on']: ev('jmove', reg('esi'), reg('edi')); L['pendsnap'] = 'after dup-move'
    def loopnext():
        if L['on'] and L.get('pendsnap'): snap(L.pop('pendsnap'))
    BP(0x10b315b8, jc); BP(0x10b31866, sz); BP(0x10b318a2, cp); BP(0x10b317bf, mv); BP(0x10b317ec, loopnext)

    # code emission entry: the final stream
    def emit_final():
        if L['on']: snap('emit')
        L['on'] = False
    BP(0x10c07a49, emit_final)


def setup():
    gdb.execute('set pagination off')
    gdb.execute('handle all nostop noprint pass')
    gdb.execute('handle SIGTRAP stop print nopass')
    for t in gdb.selected_inferior().threads():
        t.switch()
        if (int(gdb.parse_and_eval('$pc')) & 0xffffffff) == SPIN: break
    gdb.selected_inferior().write_memory(SPIN, b'\x83\xec')   # restore `sub esp, 0x18`
    arm()
    gdb.execute('continue')


setup()
