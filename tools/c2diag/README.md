# c2prio: allocator reading from the pinned SP1 back end

Published by the owner's word (leg, 2026-11-12 21:52 PT: "publish it"). It is a diagnostic: it compiles outside
`tools/match.py`, charges no attempt and never decides a match; `match.py` and the verifier do. Any contributor may run it
(OWNER-RULING-C2DIAG-USE-20261113). It reads, and never changes, what the compiler decides.
The patched compiler copy it needs is built locally, outside the repository, and must never be committed; nothing
from c2.dll other than the hook addresses and structure offsets below is in these files.

`c2prio.py` compiles one source with the pinned MSVC 2005 SP1 compiler (cl 14.00.50727.762, c2.dll sha256
497d1ffe...) under wine, with gdb attached. It then reports what the global register allocator (c2's `color.c`)
decided for one function. Nothing is modelled: every number is read from the compiler's own data structures while
it runs.

## Usage

    python3 contrib/c2diag/setup_tcspin.py <pinned SP1 bin/>   # once: builds ~/.d2match-c2diag/tcspin/bin (see "How it works")
    python3 contrib/c2diag/c2prio.py SOURCE --func 0x004DFC20 --flags "/GS-" [--blocks] [--only pSlot,tmp#32] [--json ev.jsonl]
    python3 contrib/c2diag/c2prio.py x --func x --events ev.jsonl --blocks   # re-report from a saved event file, no compile

- `--func` takes a `// 0xVA` marker (the definition after it is used), a plain name, or a fragment of the
  decorated name (starting with `?`).
- `--flags` takes what goes after the fixed profile `/nologo /c /TP /Zl /Z7 /Gy /MT /O2 /Oy- /Ob2 /Gd`
  (per-VA rulings such as `/GS-`). `--ob1` swaps in `/Ob1`.
- Without `--flags`, c2prio, c2temps, c2sched, c2split and c2slots use what `tools/match.py` would: every
  `"rule": "flag"` ruling in `docs/rulings/` that names the `--func` 0xVA (none when the source has
  `// d2match: base-profile`), then `/Ob1` for `// d2match: ob1` (`c2prio.ruling_flags`, lane GSFLAG). The line
  `c2diag: flags after the profile: ...` on stderr says what was used. `--flags` given (even `--flags ""`) is used as
  written, with a note when it differs from match.py's. With `--func` given as a name no ruling is looked up. A `/GL`
  ruling is refused (code is generated at link time). Before this, the readers compiled the bare profile unless
  `--flags` was passed: readings of a VA under a ruling taken without it were of another compile (c2force always
  applied the rulings).
- INCLUDE is set the way `tools/common.compile_env` sets it: `headers/`, then the repo root, so `gen/` resolves.
  The repository is this checkout by default; set `D2REPO` to point at another. Work files and the patched copy live
  in `$C2DIAG_HOME` (default `~/.d2match-c2diag`).
- `--class 0` (the default) is the integer class. `1` is x87; its registers print as numbers.
- About 4 s per run. Each run uses its own cl process, so parallel runs do not interfere.

## What it prints

The allocator runs in rounds. It computes priorities, colours candidates from the sorted list until a split is
needed, rebuilds the split pieces, recomputes their priorities, and carries on. For each round the report gives:

- **The candidate table.** The candidates are webs: named variables, unnamed temporaries or CSE values shown as
  `tmp#id(def Lnn)`, and kept constants shown as `const:0#id` or `addr:&g...#id`.
  - `prio` is the compiler's priority (candidate `+0x0c`).
  - `refs` is its reference count (`+0x24`).
  - `key` is the tie key (`+0x44`). Among equal priorities, the higher key is coloured first.
  - `web <N` means this candidate is a piece split from web N (same symbol record).
  - `reg` is the register picked in this round.
  - Def lines and use lines come from the tuples the references were counted on.
- **The colouring order.** Candidates in the order they are popped from the sorted list.
  - For each one: the register picked, the allowed set (registers in class order that are still free for it), and
    the per-register cost the colour step computed. The cheapest wins; equal costs go eax, ecx, edx, esi, edi, ebx.
    A negative cost is a preference, for example the arrival register or a dying copy source.
  - Or one of: `not coloured` (it goes to the split / memory path), `no register allowed`, `re-queued`.
- **`--blocks`.** One line per basic block: source line range, loop weight `w` (`1 << loop depth`) and K. Each
  candidate in the block shows `+refunits*w*K` when it is referenced there, or `-w*K(live)` when it is live but
  not referenced. A reference counts 2 units in this profile (more for some x87 cases). The block terms of every
  candidate sum exactly to its `prio`. This was checked for every candidate of every round on 0x004DFC20 (8 rounds,
  both classes).

Ids are reused after splits, so read an id within its own round.

## Validation

**0x004DFC20**, source `queue/parked/004DFC20/candidate.cpp` at commit 30847220 (sha256 470a1f43...), with `/GS-`:

- Round 1, integer class: `tmp#32`, the `pSlot->pObject` web, is defined at line 72 and the `const pObject` at
  line 78 is coalesced into it. It has priority 48 and 19 refs. `pSlot` has priority 13 and 18 refs. The block
  table shows pSlot's live-but-unreferenced penalties through lines 80 to 128.
- Round 2: pObject's piece `tmp#39` has priority 80 and 19 refs. Its allowed set is EBX only and it is coloured
  first, so it gets EBX. pSlot's piece is at 45.
- Round 3: pSlot's pieces are 60 (ESI), 30 (EAX) and -12 (ESI).
- This is exactly the coordinator's reading (48/19, 13/18, 80 EBX-only before 45 and lower).
- The object compiled under the instrumented run has an identical `.text` to the pinned compiler's (987 B).

**0x00514990**, parked source: the kept zero and the kept one tie at -86 with key 0. The one (created later) is
coloured first and takes EDI; the zero takes EBX. This is the documented 0/1 swap.

**0x005CF900**:

- Parked source: the inlined `GetUnitId` value `nId` (line 78) has priority 20, above the late pTarget piece at
  16. It is coloured first and takes EAX.
- Matched source: nId drops to 16 and the pTarget piece rises to 20. The pTarget piece takes ESI, and nId then
  takes ESI through a -1 preference cost. That is the "GUID took the dying pointer's ESI" lever.

**Synthetic files**: the registers match the compiler's own /FAs listing.

## How it works

`~/.d2match-c2diag/tcspin/bin` is a byte copy of the pinned `bin/` folder. The only change is the first two bytes of c2.dll's colour
driver, at VA 0x10b0cf40 (file offset 0xcf40). There `sub esp, 0x18` becomes `jmp $`, so the compiler parks itself
when it reaches the allocator. The pinned folder is never written to. `setup_tcspin.py` checks the c2.dll and
cl.exe hashes before it copies them.

`c2prio.py` runs wine cl from that folder and attaches gdb as soon as c2.dll is mapped. c2.dll always loads at its
preferred base 0x10b00000 under wine. `c2prio_gdb.py`, running inside gdb, puts the two bytes back in memory and
sets breakpoints that only read memory and continue. The events go to a JSON-lines file.

Hook points (c2.dll 14.00.50727.762):

| VA | What it is | What is read |
|---|---|---|
| 0x10b0cf40 | colour driver entry, stdcall(func) | `[[func]+4]` = decorated function name |
| 0x10b10420 / ret 0x10b1153f | priority pass, stdcall(func, class, class bitset) | every candidate in the class at the end |
| 0x10b109b7 / 0x10b10ff9 | reference counted (use / def): `add [cand+0x18], eax` | the tuple at `[esp+0x44]` gives the line |
| 0x10b11484 | end of a block in the priority pass: EDI = K, EBP = w | ECX = candidates that start in the block; `[esp+0x18]` = live-in list (flag `+6 & 0x10` = referenced); `[esp+0x1c]` = block |
| 0x10b0d341 | colouring loop pops the head of the priority list (0x10d1508c) | EBP = candidate |
| 0x10b0d37e / 3aa / 3c5 / 464 | the four paths out of the pop | not coloured / re-queued / no register / colour |
| 0x10b14e1a | colour step, just before `cand+0x10` is written | EBX = register; costs at 0x10d14f10[reg]; EBP = class register list; allowed set = bitset `[cand+0x20]` |
| 0x10b0d28e | after the split rebuild (0x10b11b20) | candidate ids |

Data layout:

- **Candidate** (0x48 bytes; hash at 0x10d15090, 1024 buckets, chain at `+0x30`, id at `+0x1c`): `+0x00` symbol
  record, `+0x0c` priority, `+0x10` register descriptor (number = `[desc+0x1c]`, 1 eax ... 8 edi), `+0x14`/`+0x18`
  list link / per-block ref units, `+0x20` allowed-register bitset, `+0x24` refs, `+0x28`/`+0x2c` first/last block,
  `+0x40` spill weight, `+0x44` tie key.
- **Symbol record**: `[[sym]+4]` is the name. An unnamed record whose `+0x28` operand has kind 0x275 is an
  immediate (value at `+0x18`); kind 0x27b is an address (symbol at `+0x18`).
- **Bitsets**: lists of `{base, lo32, hi32, next}`.
- **Lines**: tuple word `+0x14` is a vline. The range tree at 0x10d0eeec gives `line = base - lo + vline`.
- **Priority formula as coded**:
  - At each block end, `prio += refunits * w * K` for every referenced candidate.
  - Every live-in candidate that is not referenced gets `prio -= w * K` (only `-w` under PGO profile mode).
  - `w = 1 << block[+0x17e]` without profile data.
  - The sort is priority descending, then key descending (0x10b11970).
  - Register choice: strictly lowest cost wins, scanning class order eax, ecx, edx, esi, edi, ebx (table 0x10ce5a08).

## Limits

- Only the global allocator. Values the code generator places itself (expression temporaries, reloads, scratch
  rotation) never appear: that is the C2DEBUG2/TEMPS1 territory, read by `c2temps.py` (below).
- Unnamed webs carry no source name. Use the def / use lines (for example `tmp#32(def L72)` is
  `pSlot->pObject`).
- Line numbers ignore the file: a reference inside an `#include`d body prints that file's line number.
- The split step itself (which ranges become pieces, 0x10b15470 / 0x10b0d690 / 0x10b11b20) is reported only by its
  results: the new pieces with their web link, priorities and registers. Why it cut where it did is not decoded.
- Tied to this exact c2.dll build and base address. Any other build will not match (the setup refuses it).
- Needs wine (32-bit), gdb with Python and ptrace permission. Breakpoints stop the compiler often; a large function
  takes a few seconds.

# c2temps: scratch registers from the local assigner

`c2temps.py` is the counterpart of `c2prio.py` for the values the code generator places itself: expression
temporaries, field reads used once, reloads of memory-kept values, address computations, and the mask temporaries of a
lowered `?:`. It runs the same spin copy under gdb and stops in c2's local register assigner (`regasg.c`, which runs
after the global colouring). For every instruction tuple, in the assigner's order, it reports which register each
temporary got and why. Nothing is modelled: the register, the rotation pointer, the busy and excluded sets are read from
the compiler's own tables at the moment it decides. Same status as c2prio: an owner-side diagnostic that compiles
outside `tools/match.py`, charges nothing and decides nothing.

## Usage

    python3 contrib/c2diag/c2temps.py SOURCE --func 0x0055A2A0 [--flags "/GS-"] [--ob1] [--lines 60-75] [--picks] [--pre] [--frees] [--all] [--json ev.jsonl] [--keep]
    python3 contrib/c2diag/c2temps.py x --func x --events ev.jsonl --lines 60-75 --picks   # re-report, no compile

`--func`, `--flags`, `--ob1`, `--keep`, INCLUDE, `D2REPO` and `$C2DIAG_HOME` behave as in c2prio. The spin copy from
`setup_tcspin.py` is shared. A run takes about 5 s.

- `--picks`: only the instructions where a temporary got a register. This is the view for counting rotation steps in a
  window.
- `--pre`: under each instruction, the form the assigner received when it differs. Temporaries are still `Tn`; register
  variables are already coloured by the global allocator. This shows which operand is a temporary and which is a
  variable, for example the destination of a two-address `and`.
- `--frees`: which registers each instruction frees (dying sources).
- `--all`: also the non-instruction tuples.
- `--lines A-B`: a tuple with no line of its own belongs to the line before it.

## What it prints

One line per machine instruction, in the assigner's order. The instructions are rendered from the tuples after
assignment (`mov edx, [esi+12]`, `push eax`, `call Name`), with locals and globals by symbol name. An instruction where
a temporary got a register also carries these columns:

- `temp`: the temporary's id (`T294`). Ids are per function.
- `reg` and `how`:
  - `pref`: the temporary's preference register was free, allowed and not excluded. The pointer does not move.
  - `rotate`: the first usable register of EAX, ECX, EDX, starting at the pointer and wrapping. The pointer moves just
    past it.
  - `first-free`: the rotation found nothing. The temporary takes the first free, non-excluded register in class
    order eax ecx edx esi edi ebx ebp. The pointer does not move.
  - `free-any`: the first free register that the instruction does not reference, exclusions ignored (seen at a
    `div` whose operands exclude everything). The pointer does not move.
  - `spill(Tn)`: no register was free, so Tn was spilled for this temporary.
- `ptr`: the integer rotation pointer, before -> after.
- `busy at the pick`: what holds each register at that moment. `var` is a register that the global allocator gave a
  variable (or a fixed use in progress); `Tn` is a live temporary. A dying source operand of the same instruction has
  already been freed (`--frees` lists them).
- `excl`: registers the temporary may not take. These are the pre-pass's interference sets: registers of variables
  live across the temporary, fixed uses while it lives (a shift count in ECX), and call clobbers for a value live
  across a call.
- `pref`: the preference register, when there is one.

An instruction without these columns defines nothing the assigner picks. That covers register variables (the global
allocator colours them) and values the lowering already put in a fixed register: fastcall arguments, return values,
call results, shift counts and idiv operands. Those instructions never move the pointer.

## How the assigner works (as coded)

The driver (0x10bda210, stdcall(func)) works in this order:

1. It clears the occupant table.
2. It builds a per-register exclusion bitset over the temporary ids. This pre-pass also sets preferences.
3. It resets the rotation pointer to EAX.
4. It walks the instruction tuples in layout order.

For each tuple:

1. Sources (0x10bda4a0): each register operand is rewritten to its register. A dying operand frees its register.
2. Destinations (0x10bda5c0): a fixed register is marked busy. A temporary still in that register is moved or spilled
   first (0x10bdc8e0). A temporary not yet in a register gets one from the pick (0x10bda7c0).
3. The pick tries, in order: preference, rotation, first free, free-any, spill. The preference comes from the pre-pass
   (the temporary is later copied into a fixed register). It can also come at the pick itself, from a `mov`-family copy
   of a register or from a plain `lea [base]` (the source or base register).

The pointer is reset only at function entry, and at one pseudo-op when a flag is set; that reset was never hit in this
profile. There is one pointer per register class; the report shows the integer one.

**The assigner does not choose which operand of a two-address instruction is its destination.** The lowering has
already decided that: `--pre` shows `and T79, eax` or `and eax, T76` before any register is given. A residue in an
instruction's destination where the temporaries' registers already agree is therefore a source-shape difference, not a
scratch-rotation difference.

## Hook points (c2.dll 14.00.50727.762, base 0x10b00000)

| VA | What it is | What is read |
|---|---|---|
| 0x10bda210 | assigner driver, stdcall(func) | `[[func]+4]` = decorated name; `[[[func+8]]+0x1c]` = first tuple |
| 0x10bda3b8 | driver loop, before the source pass | ESI = tuple; with `--pre` its source / destination operand lists, before assignment |
| 0x10bda3fa | the rotation-reset pseudo-op | ESI = tuple (never hit in this profile) |
| 0x10bda510 / 0x10bda59e | a dying register source is freed | ESI = register number / ESI = register descriptor |
| 0x10bda650 | a fixed-register destination is marked busy | ESI = register number |
| 0x10bdc8e0 | stdcall(tuple, reg): move a temporary out of a fixed register | arguments |
| 0x10bda7c0 | the pick, stdcall(operand, tuple) | `[operand+0x1c]` = temporary record |
| 0x10bda895 | preference known | EAX = preference descriptor |
| 0x10bda8d0 | pick path: pref | |
| 0x10bdab46 | pick path: rotate | EDI = register, EAX = new pointer |
| 0x10bdac2b | pick path: first-free | |
| 0x10bdac6f | pick path: free-any | |
| 0x10bdaaf2 | pick path: spill | EBP = register |
| 0x10bda8e0, 0x10bdab36, 0x10bdabcf | the pick's three returns (`ret 8`) | EAX = register descriptor |
| 0x10bda452 | driver end | the final tuple stream |

Data layout:

- **Tables.**
  - Occupant table `0x10d0fd10[reg]`: the temporary record or register descriptor holding the register (0 = free).
  - Exclusion bitset pointer `0x10d0fba0[reg]`: same bitset format as c2prio; the bit is the temporary id.
  - Preference-allowed table `0x10d0f9f0[reg]`.
  - Integer rotation pointer `0x10d0f854`: a pointer into the class list at `0x10d0cfd0` (eax ecx edx esi edi ebx
    ebp 0). The rotation wraps at the first entry that is not eax, ecx or edx.
  - The compiler's mnemonic table at `0x10cdf220`, indexed by the tuple opcode, gives the names printed.
- **Register descriptor**: `0x10d09f70 + n*0x60`. `[desc+8]` is the full-width descriptor and `[full+0x1c]` its
  number (1 eax, 2 ecx, 3 edx, 4 ebx, 5 esp, 6 ebp, 7 esi, 8 edi).
- **Temporary record**: `+0x04` = 3, `+0x05 & 0x80` = needs a byte register, `+0x1c` = id, `+0x30` = preference
  descriptor.
- **Tuple**: `+0x00` next (layout order), `+0x04` opcode, `+0x09 & 1` = instruction, `+0x14` vline (line as in
  c2prio), `+0x28` source operand list, `+0x2c` destination operand list.
- **Operand**:
  - `+0x00` next.
  - `+0x08` kind: 1 register, 2 symbol, 3 local's address, 4 code symbol, 6 memory, 7 immediate, 0xb register set.
  - `+0x0a` type: `>> 12` is the class, `& 0xfff` the size.
  - `+0x15 & 0x10`: last use.
  - `+0x18`: symbol. `+0x1c`: register descriptor or temporary record.
  - Memory operands: `+0x24` symbol, `+0x28` displacement, `+0x2c` base operand, `+0x30` index operand.

## Validation

- **Same code as the pinned compiler.** Each instrumented compile emits exactly the pinned compiler's code: every
  non-debug section and its relocations were compared, with the hooks active. This was checked on the five parks below
  and three synthetic files.
- **Every pick matches the object.** For each pick, the instruction it belongs to was found in the object's
  disassembly with the same destination register, the same mnemonic family and the same registers read, each object
  instruction used once. The result was 140 of 140 picks over 0x004124B0, 0x00414930, 0x004122F0, 0x00488400,
  0x00578050, 0x0055A2A0 and three fixtures. A later peephole can change the mnemonic: `mov cl, [ebx+3]` comes out as
  `movzx ecx, byte ptr [ebx+3]`.
- **The recorded state agrees with the rule.** For each of the 162 picks (parks and every fixture), the recorded state
  (pointer, occupants, exclusions) gives back the reported register:
  - Every `rotate` pick took the first free, non-excluded register of EAX/ECX/EDX from the pointer, and the pointer
    moved just past it.
  - No `pref`, `first-free` or `free-any` pick moved the pointer.
  - No `first-free` pick had a usable scratch register.
  - There were no hook errors and no rotation resets.

The rules of the C2DEBUG2 section were reproduced on synthetic sources:

- **Rule 1, one pointer, never reset.** Take this fastcall function:
  `gX = s->a; if (n > 3) gY = s->b; else gY = s->c; Use(s->d); gZ = s->p->a;`.
  - The first read takes EAX by `rotate` (EAX->ECX).
  - The then-arm takes ECX (ECX->EDX) and the else-arm EDX (EDX->EAX).
  - After the call, `s->p` takes EAX and `->a` takes ECX.

  So the arms continue each other in layout order, and the call does not reset the pointer.
- **Rule 2, usable.** In `gY = s->a << s->b; gZ = s->p->a;` (s in EAX) the shifted value has `excl ecx` (the count's
  fixed ECX). EAX is busy, so it takes EDX and the pointer wraps to EAX. `s` dies as the base of `s->p`, so EAX is
  freed before `s->p` is placed and `s->p` takes EAX.
- **Rule 3, preferences and fixed defs do not move the pointer.** `Use(s->d); return s->a;` has no pick at all. The
  fastcall argument load is a fixed ECX def and the return value a fixed EAX def.
- **Rule 4, fallback.** In `v = Get(); return ((gA + gB) * (gC + gD)) * ((gE + gF) * (gG + gH)) + v;` the variables
  are v in ECX and the product in EAX. With the first sum operand in EDX, the second takes ESI by `first-free`, pointer
  unchanged (EAX->EAX). The `lea` sum then takes ESI by `pref`.

**The Storm validation chain end (0x004124B0, 0x004122F0, 0x00414930).** All three parks are /GS- and leave one byte:
the last validation `and`. Their notes describe the original in words: it writes the first mask's EAX, with the new
mask as the source.

- **0x004124B0** (park source, 410/410 B). The reading shows the following:
  - The phNext mask is a variable in EAX.
  - The pInfo mask T76 takes ECX by `rotate` (EAX busy, pointer EAX->EDX). Its `and` reaches the assigner as
    `and eax, T76`: the variable is the destination.
  - The size keep `nValid = (pInfo->dwSize == 0x128) ? nValid : 0` reaches the assigner as
    `mov T79, 0; setne T79; dec T79; and T79, eax; mov nValid, T79`. The lowering temporary is the destination, and the
    result is a memory def of nValid that is deleted after assignment (c2prio: not a candidate).
  - T79 (a byte temporary) takes EDX by `rotate` (pointer EDX->EAX). That is the original's `setne dl` register.

  So the scratch rotation is in phase and every register the assigner chose is the original's. The original's
  `and eax, edx` is the op-assign shape (`and var, Tmask`, as the two pointer terms lower), not a register choice. No
  scratch-rotation or preference lever can turn `and T79, eax` into it.
- **0x004122F0** (park source, 441/441 B). The same chain with three pointer terms:
  - The masks are T153 ECX and T183 EDX (both `rotate`), each as `and eax, Tn`.
  - The size keep is T73 EDX (`rotate`, EAX and ECX busy) as `and T73, eax`.
  - The emitted object shows `and edx, eax`. The reading is identical to 0x004124B0's.
- **0x00414930** (park source, one expression `((__int64)szDest ? -1 : 0) & (nMaxLength ? -1 : 0)`).
  - EAX (the szDest mask), ECX (szDest) and EDX (nMaxLength) are all variables, so the nMaxLength mask T64 takes ESI by
    `first-free` (pointer unchanged).
  - The `&` reaches the assigner as `and T64, eax; mov nValid, T64`: the temporary is the destination, ESI. The ESI
    itself is forced (nothing else is usable). The original's EAX destination again needs the variable to be the
    destination.

Synthetic fixtures (this chain shape, not game sources) confirm that the lowering, not the result's liveness, sets the
destination:

- A keep whose result is dead after the branch gives `and Tmask, nValid` + copy to the memory def.
- A keep whose result is read after the success path gives `and Tmask, nValid` + `mov edi, Tmask` (the result is a
  callee-saved variable).
- A keep whose result is read right after the check gives `and Tmask, nValid` + `mov eax, Tmask`, emitted as
  `and edx, eax; mov eax, edx`. The result is in EAX and still is not the `and`'s destination.
- `return nValid ? 1 : 0` at the end gives the same as the dead form.
- The op-assign size term `nValid &= (size == K) ? -1 : 0` drops the record-pointer term, as the park notes report.
  It ends in `test T79, T68` (two temporaries), so it says nothing about the destination.
- The two-mask expression with a live result coalesces the result with the second mask: `and esi, eax`, with ESI a
  variable.

So on these parks, a fix has to change the shape of the last term, not the register picture.

**0x00488400** (park source, 693/696 B). The memset buffer address `lea T537, [tContext]` takes ECX by `rotate`
(ECX->EDX); the original has EAX. The only rotating temporary between function entry and that address is the
`D2CLIENT_GetPlayerUnit()->pInventory` load T538 (`mov eax, [eax+96]`, EAX, EAX->ECX); the call result's dying EAX
is freed first. This confirms leg-6b2e's probe: in the original that read is not a rotation step (or there are two
more), so the pointer is still at EAX at the memset address.

**0x00578050** (park source, 1038/1037 B). These are the rotation picks up to the second repair-all call:

| Temporary | Line | What it is | Register | Pointer |
|---|---|---|---|---|
| T457 | L47 | `nNpcGUID` | EAX | EAX->ECX |
| T449 | L62 | the first `pGame->nDifficulty` | ECX | ECX->EDX |
| T528 | L64 | `pNpc->dwClassId` | EDX | EDX->EAX |
| T431 | L78 | the second call's difficulty | EAX | EAX->ECX |

T449 is then stored to the memory-kept `nDifficulty`. Its reload before the first call is a register-variable piece,
not a pick.

The original loads T431 into EDX, before the quest-flags result is pushed. With that result still live in EAX at the
pick, EDX needs the pointer at EDX when T431 is placed. Since T457 to T528 are instruction-equal (the park notes),
the step is T528 or later: in the original, `pNpc->dwClassId` is not a rotating temporary (a preference or a register
variable), or two more rotating temporaries come between L64 and L78. Ours has none in that window; L77's
`nNpcClassId` is a register variable (EBX).

**0x0055A2A0** (parked source). The picks reproduce the earlier reading:

- `lea ecx, [bPlaced]` takes ECX (ECX->EDX).
- After `push eax` of the GUID getter's result, the filler id load takes EDX (EDX->EAX).
- After the loop, the pItem reload takes EAX.
- 19/19 picks match the object.

A later pass hoists the EDX load above `mov ecx, pGame` and `push eax`. That hoist is the whole visible difference;
with EAX the load could not move. The original has the id in EAX and the pItem reload in EDX. If the id were a
rotation pick of EAX, the pointer would be left at ECX. At the pItem reload ECX is free (busy: esi and edi only), so
the reload would take ECX. A probe from the earlier reading (not re-run here) adds one rotating temporary before the call and shows exactly that: the id takes
EAX (placed after the push, as in the original) and pItem takes ECX.

So the original's id load is not a rotation step at all. It is a non-rotating EAX def: a preference, a fixed-register
def, or a variable that the global allocator coloured EAX. The pointer then stays at EDX for the pItem reload. Read the
residue as one rotation step too many in ours, and look for a form in which the filler id is not a fresh temporary,
rather than for an extra temporary.

## Limits

- The order printed is the assigner's. A later scheduling pass can still move an instruction when its registers allow
  it (0x0055A2A0 above; 0x004124B0's size load and `xor edx, edx`). Compare register choices with the object, not
  positions.
- Later peepholes can change mnemonics without changing registers (`mov cl, m` becomes `movzx ecx, m`; `mov r, 0`
  becomes `xor r, r`; `dec` becomes `sub r, 1`). A dead copy such as the keep's `mov nValid, Tn` is deleted after
  assignment.
- The tool reads which operand is the destination (`--pre`), but not why the lowering chose it. The lowering that
  builds the tuples (before regasg) is not hooked.
- Only the integer class's rotation pointer is reported. x87 / SSE temporaries get their register, but `ptr` is the
  integer one.
- The operand rendering is approximate: no size prefixes, jump targets or label names, and fields of local structs
  print as `local`. The same temporary id can show up again later in a function (0x00578050's T200 at a `div`).
- Line numbers ignore the file, as in c2prio. The tool is tied to this c2.dll build and base address.
- Why a register is excluded is not decoded, only that it is. The pre-pass at 0x10bdb270 builds the exclusion sets.

# c2slots: stack-frame layout (which home gets which [ebp-N])

`c2slots.py` compiles one source with the same spin copy and gdb harness as c2prio (about 4 s, no attempt charged) and
reads how c2.dll lays out the function's frame after register allocation: the references it counts on every memory
home (address-taken and spilled locals, spill pieces, inline helpers' result homes, unnamed temporaries), the
count-sorted home list, how homes are packed into shared slots, the slot sort and the final `[ebp-N]` (from the
object's CodeView records, `llvm-readobj --codeview`). It also simulates the list and sort rules for what-if counts.

## Usage

    python3 contrib/c2diag/c2slots.py SOURCE --func 0x00471620 --flags "/GS-" [--refs] [--bump NAME+N[@first|@last|@K]]
    python3 contrib/c2diag/c2slots.py x --func x --events ev.jsonl          # re-report from a saved --json file

- `--func`, `--flags`, `--ob1`, `--json`, `--events` as in c2prio.
- `--refs` prints every counted reference with its source line, in the order the pass walks the IL.
- `--bump` (repeatable) re-runs the simulator with N references added to (or, with `-N`, the last N removed from) a
  home, inserted after its last reference (`@last`, default), after its first (`@first`) or at trace index K. The
  packing groups are kept as compiled (interference is not modelled), so a bump that would change which homes share
  a slot is not predicted.

## What it prints

- One line per home in list order: references counted, size, packed slot (creation order), final slot, the final
  slot's weight per byte (weight * 1000 / size) and the `[ebp-N]` CodeView gives for named locals (`-` for unnamed
  temporaries and for homes outside the frame, such as parameter homes).
- The packed slots in creation order with their weights (sum of member counts), the packed size and whether the sort
  ran, then the final slot order nearest EBP first.
- `simulator on the same trace: reproduces it` when the rules below rebuild the compiler's final order from the
  counted references alone; then the `--bump` what-if list and order.

## The rules (as coded, c2.dll 14.00.50727.762)

1. **Counting** (0x10be8f10 walks the IL blocks in layout order, 0x10be9190 counts one reference): every operand
   that names a memory home counts 1, so a read-modify-write (`add [x], eax`) counts 2. The count is taken after
   allocation but before cross-jumping, so stores or reloads written in two paths and merged later count each; inline
   helpers' result homes and spill temporaries are homes too and can share a slot with a named local.
2. **List** (symbol record +0x38 = count, +0x20 = size, links +0x30 / +0x34, head 0x10d0fab0): grouped by size
   ascending; a new home goes to the end of its size group; a counted home moves back past every earlier home of its
   size whose count is strictly lower. Equal counts therefore keep the order in which the count was reached.
3. **Packing** (0x10beaef0, new slot 0x10beb760): homes are taken in list order; each joins the latest slot it does
   not interfere with (and fits), else opens a new slot; slot weight = sum of member counts. Slots below the first
   ordinary one (`lo`, 0x10d0faa8) are not sorted.
4. **Sort** (0x10bebbb0, comparator 0x10bebb30), only when the packed size is over 0x80 bytes (0x10beb315; in this
   profile): a K&R quicksort with a middle pivot, unstable, on a class byte (slot +0x18, then direction flag) and then
   weight * 1000 / size, descending. Small frames keep list order (ties by when the count was reached); in big frames
   equal weights come out in the quicksort's scrambled order, so a tie is moved by changing the whole array, not by
   age.
5. **Offsets**: slots get offsets in that order from EBP down.

## Hook points

| VA | What is read |
|---|---|
| 0x10b0cf40 | colour driver entry (as c2prio): function name, target filter |
| 0x10be9190 | one counted reference: EDX = home symbol record (name via `[[sym]+4]`), EBX = IL tuple (line) |
| 0x10be92d0 | numbering pass entry: the finished list from 0x10d0fab0 |
| 0x10beb315 | packing done: slots array 0x10d0fa9c (0x1c bytes each: +0 member bitset of home indices, +8 size, +0xc weight, +0x18 class byte), count 0x10d0fa98, index-to-home table 0x10d0faa4, `[esp+0x14]` packed size, `[esp+0x1c]` direction flag |
| 0x10beb354 | after the optional sort: the same slots array |

## Validation

- 0x00471620: parked source (69 unmasked) and matched source (equal). On both the simulator reproduces the
  compiler's final order and the CodeView offsets equal the original's map for the matched one (packed size 152,
  sorted). The matched source's pGfx shares its slot with the inlined `IsShapeShifted` result home and a temporary
  (weight 4 although pGfx itself has 2 references): that is the "+2 on pGfx" the original's order needs.
- 0x0062EAF0 (park source at 0a29f18d6a, 9 unmasked, and matched source) and 0x005EE5D0 (park at a24b19747a, 14,
  and matched): frames of 28 and 64 bytes, no sort; the simulator reproduces both orders of each, and the swapped
  pairs are exactly the list-order ties the FRAMESLOT lane closed.

## Limits

- Interference is read from the result, not modelled: `--bump` keeps the compiled packing groups.
- The other sort conditions next to the 0x80 test (two flag tests at 0x10beb31b) are not decoded; the report says
  whether the sort ran from the packed size only.
- Parameter homes and slots below `lo` are listed but not explained.
- Tied to this c2.dll build and base address, like c2prio.

# c2sched: the passes after allocation (scheduler, jump optimiser, late layout)

`c2sched.py` reads what c2.dll decides for one function after the global colouring (c2prio) and the local assigner
(c2temps): the list scheduler's instruction order (this is also where the callee-saved `push` / `pop` of the prologue
and epilogue are placed), the jump optimiser's changes (cross-jumping / tail merging, branch rewrites, tail calls) and,
with `--passes`, the tuple stream after every pass of the back-end pipeline. Same status as the other tools: an
owner-side diagnostic that compiles outside `tools/match.py`, charges nothing and decides nothing. It uses the spin copy
from `setup_tcspin.py` and reads only; the instrumented compile emits the pinned compiler's code (checked below).

## Usage

    python3 contrib/c2diag/c2sched.py SOURCE --func 0x0065E070 --flags "/GS-" [--lines A-B] [--region N] [--no-cycles] [--edges]
    python3 contrib/c2diag/c2sched.py SOURCE --func 0x006BCE20 --flags "/GS-" --jumps          # jump optimiser changes
    python3 contrib/c2diag/c2sched.py SOURCE --func NAME --passes [--diff] [--early]            # every pass, with diffs
    python3 contrib/c2diag/c2sched.py x --func x --events ev.jsonl [...]                        # re-report, no compile

`--func`, `--flags`, `--ob1`, `--json`, `--events`, `--keep`, INCLUDE, `D2REPO` and `$C2DIAG_HOME` behave as in
c2prio. A run takes about a second (`--passes` a little more).

- `--early` force-includes (`/FI`) a one-line prelude function. The spin point is the first colouring of the file, so
  without it the passes that run before colouring are not seen for the first function compiled; with it they are
  (the prelude is compiled first; the target's code is unchanged).
- `--lines A-B` keeps the scheduler regions that overlap those lines (and filters the final listing of `--passes`).

## What it prints

**Scheduler regions.** The scheduler (0x10c71dc0) cuts the stream into regions (a basic block, or a piece of at most
about 80 tuples), builds a dependence graph per region and issues it cycle by cycle. For each region:

- One line per graph node in the incoming order (the order the local assigner left, what `c2temps` prints): the
  instruction, its height `h` (longest latency path to the region end), the number of successors, flags and priority.
  Flags: `crit` (on the longest path), `brfeed` (sets what the region's closing branch tests), `memrd`, `memwr`,
  `fixed` (calls, branches, sentinels). Successors print as `nK(latency)`.
- **Priority** (as coded, weights at 0x10cd981c): `brfeed * 2^23 + memrd * 2^15 + (height + successors) * 1024`.
  The tool recomputes it and marks a node `!` if the compiler's value differs (never seen).
- The cycle table: the ready list at the start of each cycle (`node:priority/earliest cycle`, best first), what
  issued, and why the others did not (`unit busy`: the unit is taken this cycle or still occupied by a long
  instruction such as `imul` or `div`; `waits`: an operand is not ready until the cycle shown).
- **Ready-list order**: priority descending; ties go to the lower node number, i.e. the incoming order. So two
  independent instructions with the same height and successor count keep the order the assigner left.
- The issue order, the nodes that moved against the incoming order, and a check that the issue order is the order of
  those instructions in the final stream (instructions a later pass deletes, such as a jump after a noreturn call, are
  counted separately).

**Callee-saved pushes and pops** are ordinary nodes of the entry / exit region (`push ebx` ... from the prologue pass,
`_epush`, printed as `push`). Their edges: each push to the next push (latency 1) and to the first instruction that
writes its register (latency 0). A push therefore lands where its priority, `(height + successors) * 1024`, beats the
other ready nodes; a store or load with the same height and one more successor issues first.

**`--jumps`.** Every change of the jump optimiser (0x10b2c950: mode 0 right after the local assigner and prologue, mode
2 after the copy peephole, both before the scheduler; each runs sweeps of 0x10b2ccf0 until nothing changes) as a diff of
the stream, with the sweep and the transform function that made it. Named from their effect on the validation sources:

| VA | What it did |
|---|---|
| 0x10b2e1b0 | cross-jump: the instructions before a `jmp` that equal those before its target are deleted, the `jmp` retargeted into the other copy |
| 0x10b306c0 | cross-jump (mode 2 only): identical tails ending in the same jump or exit merged; the later copy survives |
| 0x10b27270 | `jcc` over a `jmp` inverted; a jump to the next tuple or an unused label removed |
| 0x10b2d400 | jump to the next tuple removed |
| 0x10b28590 | jump threading: a branch to a label followed by a `jmp` is retargeted to the `jmp`'s destination |
| 0x10b2d530 | tail call: a call followed by a jump to the return becomes `pop` + `jmp` |

**`--passes`.** One line per pass that changed the stream, with how many instructions it moved (order changed relative
to the others) or created, `--diff` for the change itself, then the final instruction order with the last pass that
moved or created each instruction. The passes seen to act on the validation sources:

| Callee (return address in the pipeline) | What it does |
|---|---|
| 0x10b49300 (0x10c06d08) | global optimiser: CSE, propagation, and the threading of a test that is decided on each incoming edge (the flag block lands behind the next `jmp`) |
| 0x10c5ba80 (0x10c072d2) | lowering to machine tuples |
| 0x10b0cf40 (0x10c073f3) / 0x10bda210 | global colouring (c2prio) / local assigner (c2temps) |
| 0x10c53e80 (0x10c075a7) | prologue / epilogue: `_epush`, `_epop`, `_eret` tuples |
| 0x10b2c950 (0x10c0767e, 0x10c077b6) | jump optimiser, modes 0 and 2 (`--jumps`) |
| 0x10c28970 (0x10c076c6) | copy peephole (`mov edx, edx` removed) |
| 0x10b312c0 (0x10c0780c) | late block layout: moves blocks into the gaps behind `jmp` / `ret`, inverts the branches around them, duplicates short return tails (`pop` / `ret`) |
| 0x10c71dc0 (0x10c07934) | list scheduler (above) |
| 0x10b23700 (0x10c07a4e) | pseudo-ops finalised (`_epush` -> `push`) |

On the validation sources the block order is already set at the first hooked pass; after it, blocks moved only by
threading (0x10b49300) and late layout (0x10b312c0).

## Hook points (c2.dll 14.00.50727.762, base 0x10b00000)

| VA | What it is | What is read |
|---|---|---|
| 0x10c71dc0 | scheduler, stdcall(func) | `[[func]+4]` = name |
| 0x10c71e3d / 0x10c71e79 | region found / graph built (0x10b1be00) | EBX = first tuple, EAX / EDI = end tuple |
| 0x10c71e7e | heights and priorities done (0x10c71f00) | context `[0x10d0fb88]` = {first node, last node}; nodes linked at +0 |
| 0x10c72185 | cycle loop, before the per-cycle pick (0x10c722c0) | cycle `[0x10d0fb4c]`; ready list head `0x10d0fb78`, next at node +0x10 |
| 0x10c72331 / 0x10c72360 | per candidate: unit check result (ESI, -1 = none) / readiness (EDX = cycle + backlog, node +0x34 = earliest) | EDI = node |
| 0x10c72378 | node issued | EDI = node, ESI = unit, EBP = cycle |
| 0x10b2c950 / 0x10b2ccf0 / 0x10b2cadb | jump optimiser entry (EAX = mode, ECX = func) / one sweep / end | |
| 0x10b2cdae, 0x10b2cdf8, 0x10b2ce3d, 0x10b2ce57, 0x10b2d1b6 | a sweep marks a change | EBP = the label / branch tuple; the last call site of the sweep names the transform |
| return addresses of the pipeline calls (`PIPELINE` in c2sched.py), 0x10bda452, 0x10c0666a | `--passes` snapshots; end of the local assigner; end of the per-function driver (final stream) | the stream from `[[[func+8]]+0x1c]`, next at +0 |
| 0x10c06890 / 0x10c06540 / 0x10bda210 | optimiser / code generation / assigner drivers | the function, to filter on the name |

Data layout:

- **Node** (scheduler): `+0x00` next, `+0x04` previous, `+0x08` predecessor edges (linked at edge +4), `+0x0c`
  successor edges (linked at edge +0), `+0x10` / `+0x14` ready-list links, `+0x1c` tuple, `+0x24` unscheduled
  predecessors, `+0x26` successors, `+0x28` weak predecessors, `+0x2c` / `+0x30` priority, `+0x34` earliest cycle,
  `+0x38` height (word), `+0x3a` node number (word, creation order = incoming order), `+0x3e` unit, `+0x40` flags
  (1 critical path, 2 feeds the closing branch, 4 reads memory, 8 writes memory, 0x10 issued, 0x20 fixed).
- **Edge**: `+0x08` from, `+0x0c` to, `+0x10` flags, `+0x14` latency (word), `+0x16` kind (`& 0x1f` != 0: weak).
- **Priority weights**: shift amounts at 0x10cd981c (`[0x10d07b8c]`), shorts: flag 2 by 23, height by 10, successors
  by 10, flag 1 by -1 (no effect), flag 4 by 15, flag 8 (float stores only) by 0.
- **Units**: 4 (`0x10d0f7fc`), issue width 3 (`0x10d0f804`), busy counts at `0x10d0f810 + 12*u`; per-opcode
  occupancy at `[0x10d439dc] + 12*op + 4`.
- **Tuples / labels**: a branch's code operand (kind 4) holds the label symbol at `+0x18`; a label tuple (kind 27,
  op 754) holds it at `+0x24`. Labels print as `L1`, `L2`, ... by first appearance in the report.

## Validation

- **Same code as the pinned compiler, hooks active** (`--jumps --passes`): the kept objects score exactly as the bench
  does on the parks 0x006BCE20 (540 B, 4 unmasked) and 0x0065E070 (256 B, 10), and RELOCATION_RESOLVED_EQUAL on the
  matched 0x0059EBE0 (/GS-), 0x004D2990, 0x005E26D0, 0x004477A0, 0x004684C0.
- **Issue order = final order**: in every scheduled region of those seven functions and three toys (94 regions) the
  scheduler's issue order is the order of its instructions in the final stream.
- **The pick rule**: in every one of the 770 cycles recorded on those sources the issued node is the first node of the ready list whose
  unit is free and whose earliest cycle has come; the ready list is sorted by priority and then by node number.
- **Toys** (synthetic, not game code): an if/else whose arms end in the same call + store (0x10b2e1b0 merges them into
  the second copy); repeated `Fail(1); return gX;` exits (0x10b306c0); `return Use(...)` at the end (0x10b2d530 tail
  call); an int flag set in both arms and tested after the join (threaded by 0x10b49300, the flag block moved behind
  the `jmp`); early returns (0x10b312c0 puts the else arm behind the `ret` and duplicates `pop esi; ret`).

## Readings

**0x0065E070** (park source, /GS-, 256/256 B, 10 unmasked: the original has `push esi` right after `push ebx`, before
the nMin store). Region 1 (L124-L134), cycle 3: the ready list is `mov nMin, ecx` 30720 (height 27, 3 successors:
the nMax load that reuses ECX, `lea ecx, [nMin]`, the first call) then `push esi` 29696 (height 27, 2 successors:
`push edi` and `lea esi, [edi+1]`). The store issues first. One point of `height + successors` decides it: with equal
priorities `push esi` (node 2) would win by node number. In ours `push ebx` already beats the store at cycle 2
(32768 against 30720). So the original's entry graph gives `push esi` one more unit (height or successor) or the nMin
store one fewer (an ECX anti-dependence or the memory edge to the call). Statement order cannot change this:
heights come from the dependence chains, not from the order. That is why all 120 entry orders gave the same residue.

**0x006BCE20** (park source, /GS-, 540/540 B, 4 unmasked: in the not-found arm the original loads pOut before nOut).
Region 12 (L103): `mov eax, nOut` and `mov ecx, pOut` both have priority 37888 (memrd, height 4, 1 successor) and
are both ready at cycle 0. The tie goes to the lower node number, nOut, because the assigner emitted it first. This
confirms leg-3a3c's reading: the scheduler only keeps the incoming order. The lever is the incoming tuple order
(the nOut piece's split / reload placement, c2prio), not the scheduler. The found arm (region 21) issues its loads
after the 10-cycle `imul`. pOut waits for EDX (an anti-dependence on the division's EDX), so nOut is first there too,
as in the original.

## Limits

- The unit model is read, not explained: which unit an opcode needs (node +0x3e before issue) and the occupancy table
  are printed only through their effect (`unit busy`). In this profile almost everything issues one per cycle.
- Why an edge exists (true, anti, output or memory dependence) is not decoded; the graph builder is 0x10b1be00. Use
  `--edges` and the registers / memory of the two instructions.
- The pass names in the tables are read from the passes' effects on the validation sources; a pass that did nothing
  there prints as `pass (0xVA)`. Transforms of the jump optimiser not seen on them print by address only.
- Late block layout (0x10b312c0) is reported by its result only; its rule (which block goes into which gap) is not
  decoded. Threading inside the global optimiser is likewise reported, not explained.
- `--passes` snapshots are taken at the return of each listed call; passes nested inside an unlisted callee show under
  that callee. Tied to this c2.dll build and base address, like the other tools.

# c2split: the allocator's live-range splitting

`c2split.py` reads the step that c2prio reports only by its results: how c2.dll's global allocator cuts a web into
pieces. It uses the same spin copy and gdb harness (about 2-5 s per run, no attempt charged) and reads only; the
instrumented compile emits the pinned compiler's code (checked below). For one function it reports every split round:
what started it, which webs were cut and why, where the cut markers sit in the tuple stream, what each operand of a cut
web became (a new piece, a reload temporary, a direct memory operand), each piece's priority and what the colouring
then did with it, and the spill stores, reloads and copies the rebuild inserted.

## Usage

    python3 contrib/c2diag/c2split.py SOURCE --func 0x005BE3F0 --flags "/GS-" [--only i,pItemsTxt] [--rounds 1,5] [--stream] [--json ev.jsonl]
    python3 contrib/c2diag/c2split.py SOURCE --func 0x005BE3F0 --flags "/GS-" --web i      # one variable, round by round
    python3 contrib/c2diag/c2split.py x --func x --events ev.jsonl [--web i]               # re-report, no compile

`--func`, `--flags`, `--ob1`, `--json`, `--events`, `--keep`, INCLUDE, `D2REPO` and `$C2DIAG_HOME` behave as in c2prio
(set `D2REPO` to a checkout that has `gen/` when the source includes generated data).

- `--web NAME` is the short view: one block per split round that cut a web of that variable (what was coloured just
  before, the priority, the kind of cut and where), its pieces with their reference lines, priority and fate
  (`coloured EBX (after the round 8 rebuild)`, `split again (round 3)`, `sent to memory`), then where every reference
  of the variable ended up in the stream after the allocator (register or memory, per instruction).
- `--only` keeps the rounds and pieces of the named webs; `--stream` adds the stream after each rebuild and the final
  one.

## What it prints

A **split round** is everything up to one rebuild (0x10b11b20), the step that turns cut webs into pieces. c2prio's
priority rounds start right after each rebuild, so split round N is followed by c2prio's round N+1 (per class). Web
ids are reused after every rebuild; read an id within its round (`tmp#5(def L12)`, `nMaxX#45`, `const:0#1`).

- **colouring before it**: the last pops and the register each got (as c2prio).
- **why**, per web of the rebuild set, from the hooked decisions:
  - `pressure cut while colouring X` (0x10b13460, the colour step's pressure check): markers put where X's colour
    leaves more live webs than free registers. The lowest-priority neighbours are cut there.
  - `lost its last register when X was coloured` (0x10b15470): X's register was the neighbour's last allowed one.
  - `cut around every point where all of {...} are taken` (0x10b16720 / 0x10b16bd0): the per-block cut of such a
    neighbour, before the rebuild. The markers go right after the instruction that takes the last register (a call,
    its `add esp`, a `jcc`, the `ret`), so a value live across a call with ESI / EDI / EBX held by others is cut at
    the call.
  - Two cuts for a popped web that is not coloured (0x10b0d690), chosen by candidate flag `+6 & 1`:
    - Flag set: the web is defined by a `load` from its home (op 661: a parameter, a kept constant, or a piece that
      starts with a reload). 0x10b1b280 deletes the load and puts a marker at the entry of each successor of its
      block where the web is live, so the rebuild loads it again there. `--web` prints this as `cut [loop]`.
    - Flag clear: 0x10b1b3b0 cuts at the entry of every block of its range where it is live.
  - `whole web to memory` (0x10b17220): a failed pop whose range is one block (or whose `+0x34` byte is 0); no
    pieces. The priority pass's follow-up (0x10b11560) also calls it; on the parks below, one-reference pieces go to
    memory there before they are ever popped.
  - `restricted to its preference register` (0x10b1b430) and `deferred once` (0x10b119f0): the two answers of a
    failed pop that do not cut anything. A deferred web comes back once; the second failure cuts or spills it.
  - `before colouring: no allowed register at all` (0x10b11770) and `no register allowed` (0x10b0d830) are the same
    cut (0x10b16720) at the other two entry points.
- **cut markers**: the marker tuples (kind 0x1c, opcode 0x2f6, web-id bitset at +0x20) as the rebuild receives them,
  shown as "after `instruction`" or "entry of block N". They are the piece boundaries.
- **pieces**: every operand of the cut web, followed through the rebuild by (tuple, side, operand index), grouped:
  - `piece NAME#id`: the operands now belong to a new web. It shows its lines, def / use count, the priority the next
    priority pass gives it, its fate, and the register its operands carry at the end. `final rewritten later` means a
    later rebuild replaced the tuple, so follow the piece's own later round.
  - `memory ... through fresh temporaries Tn`: each reference became a reload (or store) through a temporary, which
    the local assigner places (c2temps).
  - `memory ... reads / writes the home itself`: the instruction now addresses the frame home directly.
  - `rewritten`: the rebuild replaced the instruction itself (a tuple whose opcode or line changed was freed and
    reused).
- **inserted by the rebuild**: `spill-store [home], piece` after a def that a later memory piece reads, `mov Tn,
  [home]` reloads, `load piece, 0` rematerialised constants, and the `jmp`s of blocks the rebuild created to place a
  copy on an edge. Copies between two register pieces show as `mov piece, piece`.

## How the split step works (as coded)

The colouring loop (0x10b0d270) pops the head of the priority list. After each pop, at most one of these returns a
rebuild set:

1. Colouring the web: the pressure check (0x10b13460) marks pressure points through the inserter 0x10b185d0. The
   neighbour update (0x10b15470) then removes the register from every uncoloured neighbour. A neighbour whose
   allowed set becomes empty is cut by 0x10b15d50 -> 0x10b16720 -> 0x10b16bd0. Webs that cross a call go first with
   the callee-saved set; the others go with the class set.
2. A popped web that is not coloured (spill weight <= 0, 0x10b0d690): forced to its preference, deferred once, sent
   to memory, or cut at block entries (0x10b18700 inserts one marker per entry). Later webs of the list with spill
   weight <= 0 that were already deferred once are cut along with it.

The rebuild 0x10b11b20 rebuilds the webs of the set from the marked stream and gives them new ids. As seen on the
validation sources, a stretch between markers with a use and a def or several uses becomes a new web. A lone def
becomes a store to the home, and a lone use becomes a reload or a direct memory operand. The spill stores and reloads
are inserted there. Then the priority pass runs again (c2prio's next round). A piece with one reference in one block is
usually sent to memory by 0x10b11560 before it is ever popped.

## Hook points (c2.dll 14.00.50727.762, base 0x10b00000)

| VA | What it is | What is read |
|---|---|---|
| all of c2prio's | priorities, pops, picks | as c2prio |
| 0x10b11770 / 0x10b0d22f | pre-colour pass (sorted list; webs with no register) / its return | |
| 0x10b13460 / 0x10b0d469 | pressure check of the popped web, stdcall(func, cand, class, ...) / return | `[esp+8]` = web |
| 0x10b15470 / 0x10b0d485 | neighbour update after a colour / return | `[esp+8]` = coloured web |
| 0x10b15579 | a neighbour's allowed set after the removal | ESI = neighbour; empty `[[esi+0x20]]` = lost |
| 0x10b0d690 / 0x10b0d383 | failed pop, ecx = web / return (EAX = rebuild set) | |
| 0x10b0d830 / 0x10b0d3ca | pop with no register allowed / return | `[esp+4]` = web |
| 0x10b16720 | cut where every register of a set is taken, stdcall(web, register bitset) | |
| 0x10b1b3b0 / 0x10b1b280 | block-entry cut / cut of a load-defined web at its block's successors, stdcall(web) | |
| 0x10b17220 | whole web to memory, stdcall(func, web) | |
| 0x10b0d6a5 / 0x10b0d6e5 | preference restriction answer (EAX) / deferral (EDX = web) | |
| 0x10b185d0 | marker inserter (EAX = web set, ECX = tuple), read after its caller returns | the marker after ECX |
| 0x10b18700 | single-web marker, stdcall(tuple), EAX = web id | |
| 0x10b11b20 / 0x10b0d28e | rebuild, stdcall(func, set, class) / after it | the whole stream and every web |
| 0x10b0d5d7 | after 0x10b178e0 (registers written into the operands) | the final stream |

Data layout, besides c2prio's:

- **Operand of a web during allocation**: kind 1 with `+0x1c` = the candidate record. After the allocator, `+0x1c`
  is the register descriptor. A memory operand's base / index sub-operand can be a web too.
- **Candidate**: `+0x05` flags (`0x80` crosses a call, `0x40` deferred once, `0x02` in a rebuild set), `+0x06 & 1`
  loop-cut kind, `+0x34` byte checked by the failed-pop path, `+0x38` preference records.
- **Block**: `+0x00` next, `+0x0c` successor edges (`+0xc` = block), `+0x18` flags (`0x40000` has markers),
  `+0x1c` / `+0x20` first / last tuple, `+0x48` / `+0x4c` / `+0x50` web bitsets, `+0x17e` loop depth.
- **Tuples**: opcode 661 is the load of a parameter or kept constant into a web (`load`), 662 a spill store, 729 the
  return.

## Validation

- **Same code as the pinned compiler, hooks active.** The matched 0x005BE3F0 (`queue/submitted`, /GS-) was compiled
  by `tools/scratch.py` (RELOCATION_RESOLVED_EQUAL, 949 B) and under c2split with `--keep`. Both `.text` sections
  have equal bytes, and `objdump -dr` is identical.
- **Toy: a value live across a call with no callee-saved register free** (four call results x, y, z, w, then
  `Use(x, y); gA = z + w; Ext(0); Use(z, w); return x + y + z + w`). x, y and z take ESI, EDI and EBX. When z takes
  EBX, w and the `z + w` temporary lose their last register and are cut at each call and its `add esp`:
  - w: memory, with reloads `mov T78, [w]` at L12 and `mov T83, [w]` at L14.
  - `z + w`: a piece at L12 (def plus store) coloured EAX, a spill store after the def, and a reload at L15.
- **Toy: register pressure without calls** (seven loads from one pointer, an `if` arm with two products, a sum of
  all). When c takes EDI, the pressure check cuts d and e at the sum (`lea` of g + f, `add` of e). d becomes an L7-L11
  piece plus a memory use, e becomes memory. A later failed pop of g's reload piece moves its load to the next block (0x10b1b280), and g's use becomes a
  reload.
- **0x005BE3F0, the loop index split at the latch** (lane SCHEDREAD fifth pass, e1). On the matched source, `--web i`
  shows the following:
  - The round-5 rebuild makes i's head piece (L61, 64, 68, priority 55). Its pop fails and it is deferred.
  - In round 9, nResult's failed pop also cuts the webs that were already deferred, i's piece among them. The piece
    now starts with a reload of i, so 0x10b1b280 moves its load to block 59. The new piece (priority 52) takes ECX.
  - The latch reloads i once: `mov ecx, [i]` in block 60.

  With `nResult = 1` written once after the if / else (the form before e1), the piece reaches 49 and is coloured ECX
  with no loop cut. The two L141 reloads `mov ecx, [i]` sit in blocks 57 and 59, one per incoming edge, which is the
  cross-jumped pair MIDREADER described. This is the reading in the park's NOTES, now shown by the split step itself.

## Readings

- **0x005DCF70** (park, the genuine caller's unit, /GS-, 164/162 B). i takes EBX here, as in the original. The room
  list ppRoomList reaches the allocator with two references: the load at the town test (L121) and the load at the
  client test (L127). The pUnitFirst read reuses the L127 room pointer.
  - Its priority is -66, its pop fails and it is deferred once.
  - In round 2 its load is moved to the successor blocks (0x10b1b280, blocks 10, 19 and 20). L121 becomes a reload,
    and the L127 piece is a one-reference web (priority 16) that 0x10b11560 sends to memory.
  - Every use therefore reloads `[ppRoomList]`.

  The original's EAX copy, live across the latch, needs a list web that holds a def in the preheader or latch plus
  the uses in the loop. With only per-use loads in the IL, the split step can only make one-reference pieces. So the
  missing piece is a list load before the loop that the global optimiser keeps (a PRE / hoist question), not a split
  decision.
- **0x004C0810** (park, def before the GetTextDimensions call, /GS-, 1232/1232 B). Split round 1 comes right after
  the wszText address tmp#59 takes EBX (ESI nY, EDI pLabel).
  - bPlaced (priority 72) loses its last register there and is cut by 0x10b16720. The markers sit after `nTry = 0`
    (L193), at the entry of the retry loop's block 29, and after the two loop `jcc`s.
  - So the whole retry loop is a stretch with no flag register. The def (L187) becomes a memory store, and the found
    and exhausted edges make one piece (L198 / L200, priority 8) that takes EDX: `mov edx, [bPlaced]` on the found
    edge and `mov edx, 0` on the exhausted one. That is the original's flag shape.
  - nMaxX is cut in the same round: the pre-loop piece (L177 / L183, priority 40, later memory), the `- 32` piece
    (priority 96, EAX) and the retry-loop piece (L195 / L200, priority 44), which takes EBX after round 8.

  With the def after the call, the flag does not interfere with tmp#59, so it keeps EBX allowed and is never cut. To
  get the original's cut with the def after the call, something live in the retry loop has to hold EBX before the flag
  is popped. That is the "nMaxX loop piece over 72" condition of the park's NOTES, now located at the 0x10b16720 cut.

## Limits

- The cut rules are read by their effects: which instruction takes the last register (0x10b16bd0) and how the
  pressure check counts (0x10b13460) are not modelled. The report shows where the markers went and which hook placed
  them.
- Operands are followed by tuple and position. When a rebuild rewrites the instruction, the operand shows as
  `rewritten`; follow the piece in the later round instead.
- The marker of the pressure check is read after the call that inserted it returns, so a marker removed again in the
  same call is not seen.
- Only the integer class gets names for registers; the x87 class prints numbers.
- Tied to this c2.dll build and base address, like the other tools.

# c2force: change one back-end decision and see what comes out

`c2force.py` is the write side of the readers above. It compiles one source with the pinned SP1 back end under gdb (the
same spin copy and harness as c2prio / c2sched) and overrides ONE decision of the compiler for the target function: an
allocator priority, the register a web is coloured with, a web sent down the not-coloured path (or kept off it), a scheduler priority,
or one change of the jump optimiser skipped. The object is then scored the way the bench scores a source
(`checker.compare` against the original, plus an aligned instruction diff with relocations masked). A sweep tries
every single override of a kind and reports which one makes the function equal, or how close each gets, so a matcher
knows which decision to steer and by how much ("needs web X +2", "needs region 1 node 4 to win cycle 3").

It is a diagnostic only, like the readers (OWNER-RULING-C2DIAG-USE-20261113): it compiles outside `tools/match.py`,
charges no attempt, decides nothing, and an override is never a deliverable. What it says has to be reached by an
honest source change and then by `match.py`.

## Usage

    python3 contrib/c2diag/c2force.py 0xVA SOURCE --validate                         # no-op override vs the pinned compiler
    python3 contrib/c2diag/c2force.py 0xVA SOURCE [--diff]                            # plain compile under gdb, bench figure
    python3 contrib/c2diag/c2force.py 0xVA SOURCE --prio 1:nUnitX:+2 [--diff] [--keep] # one forced compile
    python3 contrib/c2diag/c2force.py 0xVA SOURCE --sweep prio|reg|sw|sched|jump|all [--steps K] [--deltas]
                                      [--rounds 1,2] [--only a,b] [--regions 3,4] [--lines A-B] [--sched-max N]
                                      [--top N] [--json OUT]
    python3 contrib/c2diag/c2force.py 0xVA SOURCE --sweep pairs [--pair-of prio|reg|sw|sched|jump|all] [--singles PREV.json]
                                      [--top N] [the single sweep's options] [--json OUT]

- The VA's flags are the ones `match.py` would use (profile, rulings, `// d2match: ob1` / `base-profile`); the length
  and the original's bytes come from the queue and the image, exactly as in the bench. `--func` names the target by a
  fragment of its decorated name when the checker's symbol is not wanted.
- Overrides (several may be given for one compile; a sweep on top of fixed overrides adds one more to them):
  - `--prio R:WEB:+N` adds N to WEB's priority (candidate `+0x0c`) at the end of the priority pass of allocation
    round R. WEB is a candidate id from c2prio's table for that round, or the name of a named variable.
  - `--reg R:WEB:esi` makes the colour step of round R give WEB that register, if its allowed set has it (else it is
    reported as refused).
  - `--mem R:WEB` sends WEB down the not-coloured path (split / memory) when round R pops it (once per round).
  - `--sw R:WEB:W` is the opposite for a web whose pop takes the failed-pop path 0x10b0d690 (spill weight `+0x40`
    <= 0, read with c2split): its weight is raised to W (default 1) at round R's pop, so the colour step tries it.
    It answers "what if this web had one more weighted use than reloads" (lane SPLITREAD's reading).
  - `--sched G:NODE:+N` adds N to the ready-list priority of scheduler node NODE in region G (numbers as in c2sched).
  - `--jskip SITE:N` skips the N-th call at jump-optimiser call site SITE (and later calls there on the same tuple);
    a `--sweep jump` lists the sites and call numbers that changed the stream.
- Sweeps (always one compile at a time; about 0.3 s to a few seconds each):
  - `prio` moves each referenced web of each round up / down by 1..K places in the sorted list (`--steps K`, default 2;
    the delta is computed so that the web passes exactly that many neighbours, ties by the key); `--deltas` uses raw
    +/-1..K instead.
  - `reg` forces each coloured web to every other register of its allowed set, and to memory.
  - `sw` gives every web that took the failed-pop path in a round a spill weight of 1 there.
  - `sched` makes every node that was ready but lost a cycle win it (and the winner lose it), by the smallest
    priority change that does it (at most `--sched-max`).
  - `jump` skips each recorded jump-optimiser change in turn.
  - `all` is all five (prio, reg, sw, sched, jump). The report lists the overrides that give an equal object, then the ones closer than the
    baseline (ranked: right length first, then aligned lines, then unmasked bytes), then how many changed nothing.
  - `pairs` (or `--pairs`) is for a residue that needs TWO decisions together. It runs the single sweep given by
    `--pair-of` (default `all`; the usual `--steps`, `--rounds`, `--regions` ... apply), or reads the singles of an
    earlier `--json` of the same source with `--singles FILE`, picks the `--top N` (default 12) most useful single
    overrides and compiles every pair of them; the report lists the equal pairs, else the pairs closer than the
    baseline (marked when a pair beats both of its members), else the closest pairs. "Most useful" is not closeness:
    the needed half of a pair usually fixes its part of the residue and breaks lines the other half repairs, so it
    scores worse than the baseline alone. The pool is ranked by how many of the original's instruction lines that the
    baseline gets wrong the override gets right (`fixes`), then by closeness; one override per resulting object (its
    equivalents are listed with it), at most two variants of one decision, and two overrides of the same web in the
    same round (or node in a region, or jump change) are never paired. 12 singles give at most 66 pairs, one compile
    at a time like every sweep.
- `--jobs` exists but defaults to 1 and should stay there: every job is a wine cl plus a gdb, and parallel sweeps have
  run small machines out of memory.

## Validation

- No-op override (`--validate`: every hook installed, delta 0 on every round-1 web and on node 1 of every scheduler
  region, jump skips that never come due, the jump recorder on): the non-debug sections and relocations of the object
  are identical to the pinned compiler's (no gdb) and to the plain gdb compile, and the bench figure is the same, on
  the matched 0x00451710, 0x0054D750 (both 20+ hooks reached), 0x005E4AC0 (48), 0x006B9C40 and 0x00508120 (51 no-op
  overrides applied, 9 jump changes recorded); all five RELOCATION_RESOLVED_EQUAL.
- Every override kind changes the object as intended on the lane parks (below): a priority delta reorders the colouring
  (0x0066D9E0, `--prio 1:nUnitX:+2` swaps ESI / EDI between the room and x), `--reg 2:7:ebx` on 0x00434060 gives the
  colour step's register and `--reg 1:pSlot:esi` (allowed set EBX only) is reported NOT applied, `--mem` takes the
  not-coloured exit of the pop (recorded as a `mempath` event), and every sweep reported 0 overrides never applied.
- Pair sweep: on 0x005D3790's if-max form (234/234 B, 17 unmasked, 15 lines; the C2TARGET reading needed nSkillId +12
  and nItemLevel -10 together) the single sweep (`--steps 3`, 156 overrides) has nothing equal and nothing closer; the
  pool ranks round-1 `nItemLevel -10` (fixes 8, breaks 11; 22 lines alone) and `nSkillId +10` (fixes 5, breaks 11;
  25 lines alone) first and third, and their pair is the only equal one of 58 (RELOCATION_RESOLVED_EQUAL; 65 s in
  all). Ranked by closeness alone, neither is among the top 30 singles.
- Safety: a forced compile that runs longer than 180 s is killed and reported as TIMEOUT; the event file is capped.
  (An early version forced `--mem` on every pop of the web; the split re-queues it under the same id, so that never
  ended. It is now applied once per web and round.)

## Readings

Single-override sweeps (`--sweep all --steps 3`, one compile at a time, 40 s to 4 min each) on the parks of lane
C2FORCE (leg-4c0f, 2026-11-13). Each park's NOTES.md has the details.

| Park | Sweep | What the compiler needs |
|---|---|---|
| 0x00434060 (388 B, 8) | 247 overrides, 3 equal | round 1 `nSize` +7 over `ppSlots` (+6 ties and loses on the key), or `ppSlots` -7, or `ppSlots` in EBX at its round-2 colour step. Nothing else: an honest form with one more `nSize` reference in the alloc block (+14 there, K 7) should close it if nothing else moves. |
| 0x006BCE20 (540 B, 4) | 407 + 847 (priorities up to 12 places), 2 equal | only the region-12 scheduler tie: the `pOut` load before the `nOut` piece load in the not-found arm (node order). No allocator, register, memory or jump override helps. |
| 0x0065E070 (256 B, 10) | 133, 2 equal | only `push esi` +1024 (one height-or-successor unit) over the `nMin` store in entry region 1, cycle 3. |
| 0x0066D9E0 park form (305/307 B, 7 lines) | 181, none equal | the right length comes back only with a round-3 temporary sent to memory (9 lines): the residue is the folded test, not allocation. |
| 0x0066D9E0 x-first form (307 B, 21 lines) | 184, none equal | round 1 `pDrlgRoom` +20 (or `nUnitX` -24, or `nUnitX` to EDI) leaves 3 lines, the operand order of x's add; a second sweep on top finds nothing, so that order is decided before the back end. |
| 0x0067C2D0 (328 B, 30) | 137 + 137 on top, 430 pairs; `--sw` | round 4 nDistMax's piece (spill weight 0, failed pop) at weight 1: 11 unmasked / 4 lines (lane PAIRS); the rest is the Bresenham call's argument order. |
| 0x00491D20 (1403 B, 9) | 476 + 476 on top, none equal | 3 bytes are the L809 global-load tie (region 33; also flipped by `msg` +14, and the two cancel); the other 6 (the tab-3 lower test's constant and branch, the R2 / L3 pair) no back-end decision reaches. |

The pattern: a park whose residue is one allocator or scheduler tie shows up as an exact "web X +N" / "node K +N"
answer; a park whose sweeps find nothing has a residue from the front end or the global optimiser (operand order,
compare canonicalisation, folded tests), and allocator steering will not close it.

## Limits

- One decision at a time, or two with `--sweep pairs` (pairs only among the pool; a pair whose halves are each
  neutral alone is missed, so read the pool and add fixed overrides by hand when a reading says which). A sweep's tables (rounds, regions) are recorded without the fixed overrides, so a round or
  region after the one a fixed override changes may be numbered or shaped differently under it.
- A priority delta acts on the priority pass of one round; the split rebuild recomputes later rounds from scratch, so
  "round R" means c2prio's round R of the unforced compile.
- The register override acts at the colour step only; the allowed set and costs are the compiler's.
- Tied to c2.dll 14.00.50727.762 at base 0x10b00000, like the readers. Hook points are those of c2prio (priority pass
  end 0x10b1153f, pop 0x10b0d341 and its exits, colour step 0x10b14e1a), c2sched (scheduler 0x10c71dc0, priorities
  done 0x10c71e7e, jump optimiser 0x10b2c950 and its call sites) and the end of code generation (0x10c0666a).

## Files

`c2prio.py` (front end), `c2prio_gdb.py` (collector run inside gdb), `c2temps.py` / `c2temps_gdb.py` (the local
assigner's counterpart; `c2temps.py` imports the paths and marker lookup from `c2prio.py`), `setup_tcspin.py` (builds
the spin copy outside the repository; all three tools use the same copy), `c2slots.py` / `c2slots_gdb.py` (frame
layout reader and simulator), `c2sched.py` / `c2sched_gdb.py` (scheduler, jump optimiser and pass
trace after allocation; the collector reuses c2temps_gdb.py's tuple decoding), `c2split.py` / `c2split_gdb.py` (the
allocator's live-range splitting; the collector runs c2prio_gdb.py's hooks and c2temps_gdb.py's operand decoding). `c2force.py` / `c2force_gdb.py` (the write side: one back-end decision overridden per compile, single-override and pair sweeps, scored like the bench; it imports c2prio.py and c2sched.py and runs their collectors for the tables it sweeps; lane TOOL-C2X's kinds also run c2temps_gdb.py and c2slots_gdb.py for their tables). `c2probe.py` (c2force's overrides on any source with no VA, scored against its own plain compile). `c2layout.py` / `c2layout_gdb.py` (the late jump optimiser and block layout; the collector reuses c2temps_gdb.py's line mapping). `gl/` (the /GL wrappers: the readers and c2force on the real LTCG link of `scratch.py --gl`). The exploration helpers used to find the hooks
print c2.dll code and are not published.

# c2force, more decisions (lane TOOL-C2X): the local assigner, pre-backend passes, the region builder, frame slots

Lane TOOL-C2X (chat fable-7709, 2026-11-16) added five override kinds to `c2force.py` / `c2force_gdb.py`, each with a
sweep. They reach decisions the first set could not: the local assigner's scratch rotation (c2temps' territory), any
pass or pass step before the back end (the operand canonicaliser, the global optimiser, the early layout pass), the
region builder that cuts a web that lost its last register (hooks found by lane FOCUS-14), and the frame-slot order
(c2slots' territory). Same status as the rest of c2force: a diagnostic only, never a deliverable; what an override
shows has to be reached by an honest source change and then confirmed by `match.py`. The existing options, sweeps
and `--sweep all` (still prio, reg, sw, sched, jump) are unchanged.

## Usage

    python3 contrib/c2diag/c2force.py 0xVA SOURCE --rot T294:ecx            # rotation pointer before T294's pick
    python3 contrib/c2diag/c2force.py 0xVA SOURCE --pick T294:edx[:rot]     # T294 takes EDX
    python3 contrib/c2diag/c2force.py 0xVA SOURCE --skip 0x10c06c96         # skip one call (site or routine)
    python3 contrib/c2diag/c2force.py 0xVA SOURCE --rg 2:14:both            # region builder call 2: block 14 alone
    python3 contrib/c2diag/c2force.py 0xVA SOURCE --slotswap 3,4 | --slotw y:+2
    python3 contrib/c2diag/c2force.py 0xVA SOURCE --sweep rot,pick,rg,slot  # or skip, or new (= all five)
    python3 contrib/c2diag/c2force.py 0xVA SOURCE --sweep skip --in 0x10baf600 [--skip-max 12]

`--sweep` now also takes a comma list; `new` is `rot,pick,rg,slot,skip`. `--sweep pairs --pair-of rot,pick,prio` pairs
across the kinds named (every new kind takes part in pairs like the old ones). Set `D2REPO` when the tools run from a
copy outside the checkout.

## The override kinds

- `--rot T[/O]:REG` (REG eax, ecx or edx). Before the O-th pick (default 1) of temporary T (c2temps' `Tn`, which
  the lowering numbers, so it is stable under any back-end override), the integer rotation pointer (0x10d0f854) is set
  to REG. Every later rotation pick follows from there, so this is "the rotation one step off from here", the reading
  "one more (or one fewer) rotating temporary before this point" without inventing the temporary.
- `--pick T[/O]:REG[:rot][:force]`. That pick takes REG, the way the preference path does it (0x10bdac90: occupant
  table, use mark, descriptor flag, then the pick returns), so the pointer does not move; with `:rot` it moves just
  past REG, as a rotation pick would. It is refused (`NOT applied`, with the reason) when REG is busy, excluded for T
  (the pre-pass's interference sets) or not byte-capable for a byte temporary; `:force` ignores the exclusion.
- `--skip ADDR[:N][=V]`. Skip the N-th call (default 1; 0 = every call) made for the target of the c2.dll routine
  ADDR: the routine returns V (default 0) at once, its argument bytes popped (its `ret N`, read from c2.dll). ADDR is a
  routine entry (every caller) or a `call` instruction (that call site only). The pipeline's passes and every step a
  pass calls can be skipped this way, one call at a time.
- `--rg CALL:BLK[:nopred|nosucc|both]` (lane FOCUS-14's hooks). The region builder 0x10b15d50 (called when a
  neighbour lost its last register, before the cut) puts each block where the webs are live into the first region it
  can join through a predecessor (0x10b15eae), else a successor (0x10b15f03), else a new one; the cut markers go on
  the edges between regions. In its CALL-th call for the target, block BLK (index in the block list) skips the
  predecessor join (`nopred`, the default), the successor join (`nosucc`) or both (a new region).
- `--slotw SLOT:+D` adds D to a packed slot's weight (slot `+0x0c`) when packing is done (0x10beb315), before the
  sort; only frames over 0x80 bytes are sorted. `--slotswap A,B` swaps two slots of the final order (0x10beb354); the
  offsets are then given in that order from EBP down. A slot is its index (c2slots' packed / final numbering) or the
  name of a home in it (`y#2` for the second slot holding a `y`).
- `--early` force-includes a one-line prelude function (`/FI`) so that the passes before the target's colouring are
  hooked (the spin point is the first colouring of the file). It is automatic with `--skip` and the skip sweep. The
  prelude does not change the target's code (checked below).

## The sweeps

- `rot`: before every rotation pick, the pointer set to each other scratch register whose rotation would pick a
  different register (an equal pick leaves the same pointer and the same object, so it is not compiled).
- `pick`: every pick given each other register that is free, not excluded and byte-capable when needed; a rotation
  pick also with the pointer moved.
- `skip`: by default every per-function pipeline call (c2sched.PIPELINE) skipped in turn. With `--in 0xFN,...` every
  call the target makes at the direct call sites of those routines (found by recursive descent of their code, tail
  jumps followed) is skipped in turn, up to `--skip-max` calls per site, so a pass can be taken apart step by step:
  sweep the pipeline, then `--in` the pass whose skip changed the object toward the original, then `--in` the step.
  A skipped call can make the compiler loop or allocate without end: every forced compile now runs under a watchdog
  (`--timeout`, 40 s in a skip sweep, else 180 s; `C2FORCE_MEMCAP_MB`, default 1200 MB resident) and is reported
  as TIMEOUT. An internal compiler error is reported as COMPILE_ERROR. Both are left out of the ranking.
- `rg`: in every region-builder call, every block that shares its region with another block made to skip its
  predecessor join, and made to start a new region.
- `slot`: every pair of adjacent final slots swapped, and (sorted frames) every packed slot's weight moved by
  +/-1..`--slot-steps` (default 2).
- `--greedy N` (any single sweep): keep the best closer override, run the same experiments again on top of it, and
  repeat up to N times; the chain is printed as command-line overrides. For residues made of several independent
  decisions (frame-slot pairs, a skip plus slots). The experiments are those of the first recording, so an index a
  kept override renumbers (a slot after a swap, a round after a split change) is tried as it stands.

## Hook points of the new kinds (c2.dll 14.00.50727.762, base 0x10b00000)

| VA | What it is | What the override does |
|---|---|---|
| 0x10bda210 | local assigner driver, stdcall(func) | names the function; resets the per-temporary pick count |
| 0x10bda7c0 | the pick, stdcall(operand, tuple); `[[operand+0x1c]+0x1c]` = temporary id | `rot`: writes the integer rotation pointer 0x10d0f854 (a pointer into the class list 0x10d0cfd0); `pick`: writes the occupant table 0x10d0fd10[r], the use mark 0x10d40c40[r] and the descriptor flag `[0x10d09f70 + 0x60r + 0x38]`, then returns the descriptor (`ret 8`), as the preference path 0x10bdac90 does; the exclusion bitsets 0x10d0fba0[r] and the byte flag `[rec+5] & 0x80` are checked first |
| 0x10c23503 | the per-class pointer selector of the rotation helpers 0x10c234c0 / 0x10c23520 | read: entry 0 is the integer pointer (`rot` refuses other classes) |
| 0x10c06890 / 0x10c06540 | per-function optimiser / code generation drivers, EAX = func | name the function before colouring (with the prelude) |
| any routine entry | `skip`: at its entry, `[esp]` = return address | EAX = V, ESP += 4 + the routine's `ret N`, EIP = the return address |
| 0x10b15d50 | region builder, stdcall(func, web set, register set) | counts the call, numbers the blocks (`[func+8]` list, next at +0) |
| 0x10b15eae / 0x10b15f03 | the predecessor / successor join loops of one block, EBX = the edge list, EBP = block | EBX = 0 (no join tried) |
| 0x10b1600e | every block has its region id (`+0x38`) | the `rg` sweep's recording (blocks where the webs are live, `+0x50`) |
| 0x10beb315 / 0x10beb354 | c2slots' packing done / after the sort | `slotw`: slot `+0x0c` += D; `slotswap`: two 0x1c-byte slot records exchanged in the array 0x10d0fa9c (offsets are assigned from it in order right after, 0x10beb36e on) |

The prelude, the skip and the local-assigner hooks need the function filter before colouring: c2 runs the next
function's optimiser before the previous function's code generation ends, so with `--early` the end hook
(0x10c0666a) closes only the function whose code generation began (0x10c06540).

## `c2probe.py`: the same overrides on a reproducer

    python3 contrib/c2diag/c2probe.py repro.cpp Mini [--flags "/GS-"] [fixed overrides] --show
    python3 contrib/c2diag/c2probe.py repro.cpp Mini --in 0x10b49300 [--max 8]

No VA and no original: the target is a fragment of a decorated name, and a skip is scored by how many of the target's
own instruction lines change against the plain compile (`--show` prints the code, relocations named). This is the way
to find which c2.dll step makes a decision: write a few-line function with the shape, `--in` the pass, then `--in`
the step whose skip changes the part you care about, and so on down; then run c2force's skip sweep with `--in` that
step on the park. Example (lane FOCUS-15's row-base reproducer): `--in 0x10b49300` shows the global optimiser's
strength reduction at 0x10b501b0 (skipped, the inner loop multiplies again); `--in 0x10b501b0` shows it calls
0x10b50360 once per loop nest (recursive for inner loops), and `--in 0x10b50360` the per-loop transform 0x10b39c50.

## Validation

- **No-op hooks, prelude included** (`--validate` now also compiles with the prelude and with every new hook
  installed and none coming due: a rot and a pick for no temporary, a region-builder call that never comes, a zero
  slot weight, and a skip of every pipeline routine at a call number that never comes). Target body and relocations
  identical to the baseline on the matched 0x005C09E0, 0x00471620 and 0x005BE3F0 (all RELOCATION_RESOLVED_EQUAL) and
  on the parks 0x0050CA00 and 0x0041B0B0; the old no-op check is unchanged (YES on all five).
- **Forcing what the compiler decided keeps the object; forcing something else changes it** (matched sources):
  - `rot` / `pick`: 0x005C09E0 `--rot T75:ecx` (the pointer it had) and `--pick T75:eax` (the register it took): same
    object; `--pick T75:ecx:rot` refused (ECX busy). 0x005BE3F0: 31 picks, 177 experiments; 171 change the object,
    the 6 that do not are pointer values whose rotation picks the same register (the sweep now leaves those out).
  - `skip`: 0x005C09E0, every pipeline call (69): 43 leave it equal (passes that do nothing for this function, among
    them the first operand canonicalisation), 26 change it or stop the compiler (skipping the whole global optimiser
    leaves 4 lines different).
  - `rg`: 0x004EDEA0 (4 region-builder calls, 370 experiments): 34 change the object, the rest are joins whose
    refusal gives the same cut.
  - `slot`: 0x00471620 (152-byte sorted frame, 21 slots): every adjacent swap changes the object; weight deltas that do
    not move a slot past a neighbour leave it equal (8 of 84). 0x005BE3F0 (small unsorted frame): all 10 swaps change it.
- **Safety**: a skipped pass often makes the compiler fault; under gdb its error handler can then print C1001 in a
  loop, or allocate without end (an unguarded first version ran the machine out of memory). The watchdog kills a
  compile at the first C1001 (COMPILE_ERROR, about 1 s), over the time limit or over the resident cap (TIMEOUT).

## Readings (lane TOOL-C2X, 2026-11-16; park sources as in queue/parked that day)

| Park | Sweep | What the compiler needs |
|---|---|---|
| 0x0041B0B0 | `rot,pick` on the park (30 lines): best 25. On lane FOCUS-16's probe source (the blocks parameter used once in the size-compare block, 9 lines), `--rot T608:edx` alone leaves 4 lines, the probe's own two and its alignment pad. On the probe-free base form (55 lines), the pair `--prio 1:21:-4` (the flags & 1 value) and `--rot T605:edx` leaves 7 lines, which are the per-path blocks loads | the rotation one step later at the first handle reload (pointer EDX, not ECX): one more rotation pick between the `&handle` lea and that reload, as FOCUS-16 read. With the blocks reference and the flag priority that is the whole residue |
| 0x0050CA00 | `skip` (pipeline): only the first operand canonicalisation (0x10baf600 at 0x10c06c96) helps: 87 -> 37 unmasked, 58 -> 39 lines. `skip --in 0x10baf600 --lines 144-149`: exactly one tree, call 44 of the per-tuple rewrite 0x10baf6e0 (the nWorldY assignment, L147): the same 37 | nWorldY's sum is not rewritten into the linear form that shares 2*nRow with nWorldX before the global optimiser. On top of that skip, `all,rot,pick,slot` (817): the best is the tRowStart / tRect slot pair swapped (23 unmasked, 25 lines, all frame offsets); the rest is the original's two scalar row variables against our two-element row base (frame layout, source shape) |
| 0x00677880 | `slot`: `--slotswap 3,4` (the nJ and y slots) or `--slotw 10:+2` (+3) on y's packed slot: 126 -> 109 unmasked, 92 -> 75 lines; nothing else in 209. On top of it, nothing. `skip` over the pipeline, the global optimiser's steps and the strength-reduction steps 0x10b501b0 / 0x10b50360 (211, per loop nest): nothing closer | y's slot two counts heavier (lane LARGE2's reading: 26 against 24). The row-base addend is not one skippable step at loop-nest granularity: skipping the reduction of a nest loses all of it |
| 0x00679C80 | `rot,pick,rg,slot` (65): nothing. Pairs with `all` (350 singles, 90 pairs): nothing equal; the closest single is the old jump optimiser's `--jskip 0x10b2d161:14` (the mode-2 transform 0x10b2eb00 at L463): right length 450/450 B, 67 unmasked, 16 lines; the new kinds on top of it: nothing | not a rotation residue on the park form; the right length needs the L463 jump-optimiser change undone |
| 0x00580C20 | `skip` (pipeline 71, global optimiser steps 112 and 87 with every-call skips): nothing closer | the propagated 2 is not made by one skippable global-optimiser step. On a reproducer the constant even survives skipping the whole global optimiser (it is rebuilt later as `lea ecx, [eax+1]` from the compared register), so look in the back end's constant tracking, not the optimiser |
| 0x005F78B0 | `skip` (pipeline 69; early layout 0x10b26ca0's steps 91): nothing closer; most skips of its steps stop the compiler | the original's IL has the fallback head as a join; no decision of the existing IL gives that (as PARK-F's RPO reading) |
| 0x0055A6D0 | `rg` on the park (6 region-builder calls, 740): nothing closer; lane FOCUS-14's block 144 without its predecessor join (call 2) gives 20 lines against 7 | the tail is not one region decision on this form |
| 0x005C09E0 | (matched) | used for validation; the "rotation one step off" park closed before this lane |

**Every park** (`--sweep rot,slot`, park sources of 2026-11-16, 253 folders, one compile at a time; 20 parks are
already equal on the bench, 3 do not compile here). A single new override is RELOCATION_RESOLVED_EQUAL on eight:

| Park | Single override that is equal | Reading |
|---|---|---|
| 0x0040CC10 (6 unmasked) | `--slotswap 9,10` (the pContext GS copy and dwNoStackDump) | the frame-slot tie lane PARK-F located (one more dwNoStackDump count) is the whole residue |
| 0x00502970 (17) | `--slotswap 1,2` (nLength and wszText) | the whole residue is that pair (the park's +2 text-pointer reading) |
| 0x00560F00 (30) | `--rot T329:eax` (the L371 pOldItem reload) | the rotation one step later from L371 (pointer EAX, not EDX): one more rotation pick between the L360 `&pOldItem` lea and the L371 reload, or that lea not rotating |
| 0x00565AB0 (8) | `--slotswap 13,14` (item and id) | one slot pair |
| 0x005852E0 (6) | `--rot T293:eax` (the L196 frame-count field read) | the rotation one step earlier at L196 (EAX, not ECX): one rotation pick fewer since L188 |
| 0x005A49B0 (2 unmasked, 47 lines) | `--rot T618:eax` (L1243, the room read for the minion call) | one rotation pick fewer before L1243 |
| 0x005BE3F0 (park copy, 9) | `--slotswap 3,4` (nOldLength and nStat) | one slot pair |
| 0x0064FE40 (4) | `--rot T411:ecx` (the L82 second field read) | the rotation one step later at L82's second read |

Pairs (`--sweep pairs --pair-of all,rot,pick,slot --steps 3`) on the parks whose best single was within 3 lines:
**0x0055A2A0** is equal under the single `--pick T294:eax` (the filler id load at L63 takes EAX without moving the
pointer): exactly the c2temps reading above, a non-rotating EAX def; also equal as that pick plus `--rot T273:edx`.
0x005DD370: `--rot T293:eax` leaves 1 line (`cmp edi, ecx` against `mov eax, ecx`, a shape difference); nothing on top.
0x004F4170: `--rot T245:eax` leaves 2 lines (the next field read's register); nothing on top. 0x004C3380:
`--rot T290:ecx` leaves no differing instruction line, 6 unmasked bytes (operands); nothing on top.

From the greedy chain: 0x0050CA00 with `--skip 0x10baf6ae:44 --greedy 10 --sweep slot` keeps four slot
swaps (tRowStart / tRect, then nY0 with a temporary and with nX0, then nResult / nOffset) and ends at 18 unmasked, 20
lines, all frame offsets of the original's two scalar row variables.

# c2layout: block layout and tail merging (the late control-flow passes)

`c2layout.py` reads what the pinned SP1 back end does to one function's block stream after register allocation: the
jump optimiser (tail merging, cross-jumping, branch threading, jumps to the next tuple removed) and the late block
layout (blocks pulled up behind jumps, short tails copied into jump sites), and the order the code is emitted in. It
runs the same spin copy and harness as c2prio (gdb attached to wine cl at the colour driver, every breakpoint
read-only). Same status as the other readers (OWNER-RULING-C2DIAG-USE-20261113): it compiles outside `tools/match.py`,
charges nothing and decides nothing.

## Usage

    python3 contrib/c2diag/c2layout.py SOURCE --func 0x004DB0D0 [--flags "/GS-"] [--ob1] [--steps] [--raw] [--verify] [--timeout 600] [--json ev.jsonl] [--keep]
    python3 contrib/c2diag/c2layout.py x --func x --events ev.jsonl [--steps]   # re-report, no compile

`--func`, `--flags`, `--ob1`, `--keep`, INCLUDE, `D2REPO` and `$C2DIAG_HOME` behave as in c2prio (the flags default to
the VA's rulings and opt-ins through `c2prio.ruling_flags`; a `/GL` ruling is refused, see "/GL readers" below for
reading under the LTCG link). A run takes about a second on a small function.

- `--verify` compiles the source a second time with the pinned compiler itself (no spin copy, no gdb) and says
  whether the two objects' `.text` sections are identical.
- `--timeout S` (or `C2LAYOUT_TIMEOUT`, default 600): the hooked compile is killed after S seconds. On exit, and on a
  timeout, every process whose working folder is the run's own folder (`$C2DIAG_HOME/runs/layout-*`) is killed, so a
  run never leaves a wine cl or gdb behind, and parallel runs stay apart (each has its own folder and attaches to its
  own cl by pid; there are no shared ports).
- `--steps` prints the whole block list after every change; `--raw` the raw tuple streams (`kind:line`).

## What it prints

1. **The stream before the late passes**, as blocks (`B0`, `B1`, ...; a block runs from a label to a branch or
   return): source lines, instruction count, terminator (`jmp Bn`, `jcc Bn`, `ret` or `fall`). Block names stay fixed
   for the whole report; a block made later gets a new number.
2. **FLOW pass** (it runs twice per function; the second run is headed `run 2`): every transform call inside it that
   changed the stream, by its short name (`cross-jump(e1b0)`, `tail-merge(eb00)`, `thread(28590)`,
   `drop-jump-to-next(d400)`, ...: the c2.dll routine's address tail; what each one does is read from its effect, the
   same reading as c2sched's `JNAME`), the line of the tuple it acted on, and the effect: instructions cut, blocks
   removed or new, branches retargeted, instructions moved between blocks, order changed. `(changed before this
   pass)` lines are what the passes between the two runs did.
3. **LAYOUT pass**: for every unconditional jump the layout pass considers, one line: the target tail `COPIED` (with
   the compiler's size estimate and limit), the target block `MOVED` up behind the jump, or `kept` and why (too big,
   refused, or not a single block ending in ret / jmp that nothing falls into). `(changed inside the pass, untraced
   step)` is a change no hooked call explains.
4. **The final order at code emission**, then the object: its size, the loop heads (backward-branch targets) with
   their offset mod 16, every alignment pad before a jump target, and, when the stream and the object have the same
   instruction count, each block's offset in the object.

Lines are file lines of SOURCE; inlined code carries the line of its call.

## The layout rules it confirmed (behavioural; compiler observed read-only)

These are the coordinator's readings (lanes C2LAYOUT and C2LAYOUT2, docs/COORDINATION.md class 4 and "Shared ideas"),
every one visible in this report:

- **Two merges in the late flow pass.**
  - *Pairwise tail merge*: a block ending `jmp L` and the block falling through into L have identical tails; the tail
    is cut from the jumping block, and the copy kept is the fall-through one, laid out just before the join. Merges
    repeat and chain. For a switch: the case whose copy should be kept must be the block that falls into the shared
    join (write it last, or put the join label right after its body).
  - *Cross-jump* of identical jump predecessors of one label: the copy kept is the one whose jump to the label was
    created first, which is normally the first in layout; the later identical copies jump into it.
  - Exception: when a callee-saved push is shrink-wrapped past an early return, the returns inside the wrapped region
    are re-pointed to the new restore label in reverse order, so among them the last in layout is kept.
- **Block order out of a condition.** A single test puts the then-arm first (`if (!c)` swaps the arms). With two or
  more tests (`&&`, `||`, `!(a && b)`) the arm reached when every test passes always follows the chain, whatever the
  spelling; bool temporaries, inline-helper last terms, nested ifs, early returns and gotos give the same order. A
  join block several blocks jump to (a goto label) is placed after all its forward predecessors.
- **The 20-byte copy rule.** In the layout pass, a jump to a block ending in ret / jmp is replaced by a copy of that
  block when the compiler's estimate is at most 20 bytes (calls allowed); 21 and more stays a jump.
- **Layout pulls a chain behind the first jump.** A forward chain that nothing falls into and that ends in jmp / ret
  is pulled up whole behind the first unconditional jump to it (for a jcc + jmp pair the jmp is tried first).
- **The 7-byte loop pad.** A loop head gets a 16-byte alignment pad only when 7 bytes or fewer are needed.

## Validation

- 0x004DB0D0 (verified, 61 B; `/GS-` from its ruling): the report's final order lines up instruction for instruction
  with the object (30 stream instructions, 30 object instructions plus one 4-byte pad before the loop head at +0x20,
  mod 16 = 0); the layout pass copies the 4-instruction return tail into the loop exit's jump (est. size 4 <= 20);
  `--verify`: the `.text` of the hooked compile and of the pinned compiler are IDENTICAL. The object is 61 B, the
  queue's length.

## Known gaps

- Only the two late passes and emission. Earlier block-order steps (the early jump cleanup 0x10b31fc0 and early
  layout 0x10b26ca0, which fix the arm order these passes start from) are not traced here: the spin copy attaches at the colour
  driver, which runs after them. `c2sched.py --passes --early` shows the stream after every pass instead.
- The transform names are the routines' address tails plus a reading of their effect, not decoded descriptions.
- The size estimate is the compiler's own, not the emitted byte count.
- Block offsets are printed only when the stream and the object have the same instruction count (pads apart).
- The object section looks for the target's own COMDAT under /Gy; a target that is not its own section is not shown.
- Tied to c2.dll 14.00.50727.762 at base 0x10b00000, like the other readers.

## Hook points (c2.dll 14.00.50727.762, base 0x10b00000)

| VA | What it is | What is read |
|---|---|---|
| 0x10b2c950 / 0x10b2cad2 | flow pass (jump optimiser) entry / exit | ECX = function object; stream at `[[[fobj+8]]+0x1c]` |
| 0x10b2cdf3 ... 0x10b2d317 (25 call sites, as c2sched `JCALLS`), 0x10b2cac3 | transform calls inside the flow pass, and their return addresses (site + 5) | EBP (EAX at 0x10b2cac3) = subject tuple; EAX at return != 0 = changed |
| 0x10b312c0 / 0x10b31984 | late layout pass entry / exit | `[esp+4]` = function object |
| 0x10b313a6, 0x10b31438, 0x10b31461 | tail duplication calls | EAX = subject tuple |
| 0x10b3147c, 0x10b31590, 0x10b315ab | other layout-pass calls | EAX = subject tuple |
| 0x10b315b8 | an unconditional jump is considered | ESI = the jmp tuple |
| 0x10b31866 | its copy-size check | EDI = estimated size, EAX = limit, `[esp+0x14]` = refuse flag |
| 0x10b318a2 / 0x10b317bf / 0x10b317ec | tail copied / block moved / next candidate | `[esp+0x10]`, `[esp+0x1c]`; ESI, EDI |
| 0x10c07a49 | code emission entry | the final stream |
| data 0x10d1239c | function being generated | `[[x]+4]` = decorated name |

Tuple: `+0x00` next, `+0x04` opcode, `+0x08` kind (13 op, 15 call, 16 ret, 18 branch, 26 / 27 label), `+0x14` vline
(mapped to a file line through c2temps' range tree), `+0x28` source operand list. A branch target is the operand of
kind 4 (`+0x08`) whose symbol (`+0x18`) is a label (`+0x30` == 3); the label's tuple is at symbol `+0x33`. A branch
whose opcode is 0x10 is a `jmp`.

# /GL readers (contrib/c2diag/gl/)

Under `/GL` the compiler front end only writes CIL; c2.dll generates the code inside the LTCG link, where the readers
above (which attach to cl.exe) never look, and they refuse a `/GL` ruling. These wrappers make c2prio, c2temps, c2sched,
c2layout and c2force read a `/GL` unit under the real LTCG link that `tools/scratch.py --gl` (the owner-side scratch
form of `match.py --gl`) runs. Same status as the readers: uncharged, decides nothing.

How: `glcap.py` runs `scratch.py VA OUTDIR/c.cpp --gl` and records every `link.exe` command line it starts
(`OUTDIR/links.json`); scratch.py leaves the LTCG work folder in `OUTDIR/gl`. `glread.py` re-runs the `A` link of
that recipe (the one with `/MAP:A.map`) with the spin copy's `link.exe` (`$C2DIAG_HOME/tcspin/bin`, built by
`setup_tcspin.py`; its c2.dll spins at the colour driver like cl's), attaches an unchanged collector
(`c2<reader>_gdb.py`) the way c2prio attaches to cl, and links to `OUTDIR/gl/R.exe` / `R.map`. The reader's own
`--events` option then prints the report. OUTDIR must be outside the repository (scratch.py's rule); every path is
taken relative to the checkout the scripts are in (`D2REPO` overrides it).

    python3 contrib/c2diag/gl/glcap.py 0xVA SOURCE OUTDIR                    # scratch --gl, links captured
    python3 contrib/c2diag/gl/glread.py OUTDIR --func 0xVA --reader prio|temps|sched|layout|slots|split [--events E]
    python3 contrib/c2diag/gl/glread.py OUTDIR --func 0xVA --reader force --ov prio=1:pInfo:-20 [--ov reg=1:x:edx]
    python3 contrib/c2diag/gl/gldis.py OUTDIR 0xVA [--tag R|A] [-q]             # aligned diff of the linked target vs the original
    contrib/c2diag/gl/glprio.sh   0xVA SOURCE OUTDIR [c2prio report args]      # glcap + glread prio + c2prio --events
    contrib/c2diag/gl/gltemps.sh  0xVA SOURCE OUTDIR [c2temps report args]
    contrib/c2diag/gl/gllayout.sh 0xVA SOURCE OUTDIR [c2layout report args]
    contrib/c2diag/gl/glforce.sh  OUTDIR 0xVA prio=1:pInfo:-20 [reg=...] [-- gldis args]   # after glcap; prints the diff and the count applied

- `--ov KIND=VALUE` takes c2force's CLI forms (`prio=R:WEB:+N`, `reg=R:WEB:esi`, `mem=R:WEB`, `sched=G:NODE:+N`,
  `jskip=SITE:N`, ...); `--spec` takes c2force's internal JSON list. glforce.sh prints `overrides applied: N` (the
  collector's `applied` events), which replaces the old glforce2.sh.
- Any `C2*` variable in the environment reaches the collector (for example `C2PRIO_BLOCKS=0`).
- Timeouts: glcap 900 s for the scratch run, glread 700 s for the link (the shell wrappers add an outer `timeout`).
- gldis.py takes the length from the queue and the original bytes from your own image at run time; it prints them
  (normalised) only to the terminal. Never commit or paste its output.
- Limits: only the `A` link is re-run (its layout is the one scratch.py compares; B, C and D differ only in placement
  shifts). Numbers such as round and region are those of the LTCG code generation, which can differ from a cl
  compile of the same source.

Tested (0x004DB0D0, `--gl` on top of its `/GS-` ruling; RAW_EQUAL under scratch --gl): glprio.sh gives the same round-1
table as c2prio on the cl compile (pData 65 ECX, i 44 ESI, ...); gltemps.sh and gllayout.sh report the function; gldis.py
on `A` has 0 differing lines; glforce.sh with `reg=1:pData:esi` changes the linked image (13 lines, 2 overrides applied).

    S=$(mktemp -d /tmp/c2diag-test.XXXX)             # outside the repository; leave TMPDIR unset (wine)
    cp queue/matched/004DB0D0/candidate.cpp $S/db.cpp
    python3 contrib/c2diag/c2layout.py $S/db.cpp --func 0x004DB0D0 --verify
    contrib/c2diag/gl/glprio.sh  0x004DB0D0 $S/db.cpp $S/gl1
    contrib/c2diag/gl/gltemps.sh 0x004DB0D0 $S/db.cpp $S/gl2 --picks
    contrib/c2diag/gl/gllayout.sh 0x004DB0D0 $S/db.cpp $S/gl3
    python3 contrib/c2diag/gl/gldis.py $S/gl3 0x004DB0D0 --tag A -q
    contrib/c2diag/gl/glforce.sh $S/gl1 0x004DB0D0 reg=1:pData:esi
