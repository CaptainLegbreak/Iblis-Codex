# vbatch: many source variants per compile

One compile of a unit can hold dozens of variants of the same function. Each variant is a copy with a
`V_<name>` function name, inserted into the real unit before an anchor line, so every variant sees the unit's
real declarations. `multi.py` compiles once and compares every `V_` function's instructions with the original
at one address; `greedy.py` searches a template of alternatives with it. On a warm Wine, a batch of 40 variants
of a 790-byte function in AiThink4.cpp takes about 4 s.

Run from the checkout root (or set `IBLIS_ROOT`), after `tools/setup.py`. Needs `llvm-mc` (llvm-18).

    INTO=Source/D2Game/Ai/AiThink4.cpp ANCHOR='// 0x005EDF70' \
      python3 lanes/tools/vbatch/multi.py Source/D2Game/Ai/AiThink4.cpp variants.cpp 0x005EDC50

prints, per variant: whether the first three instructions (frame setup) match, compiled length / original length,
whether the prologue has the `push ecx` 4-byte slot, and `difflines` (instructions that differ after aligning the
two listings; calls and absolute addresses are normalised). `SHOW=V_name` prints that variant's diff.
The unit's flags come from build/units.json for UNIT_REL.

    python3 lanes/tools/vbatch/greedy.py TEMPLATE UNIT_REL VA INTO ANCHOR [--start 0,1,..] [--rounds N] [--pairs N]

TEMPLATE: shared declarations, then a line `//==FUNC==`, then the function with the name `FNAME` and groups
written `<<{as now<<ALT>>variant 1<<ALT>>variant 2}>>` (the coordinator's vsearch syntax, not nested). Each round
compiles every one-group change of the current best plus N random two-group changes, 60 per compile, and keeps
the best. A variant that fails to compile fails its whole batch, so keep every alternative compilable. `PRO=1`
adds a penalty when the frame setup differs. Writes TEMPLATE.best.cpp.

`--seed N` starts from a random choice of every group (run several seeds for restarts); INTO `-` compiles the
template's preamble alone (a minimal unit) instead of inserting into a real one. Each run uses its own scratch
file, so two searches can run at once.

A variant search ranks by listing difference only; a candidate still has to be marked and built in its unit
(tools/build.py --files) before it counts.

## ltlab.py: the same comparison through link-time code generation

    INTO=... ANCHOR=... python3 lanes/tools/vbatch/ltlab.py UNIT_REL variants.cpp VA [+flag|-flag ...]

Compiles the variants with `/GL`, links them `/LTCG` into a scratch DLL (unresolved externals allowed) and compares
each exported `V_` function with the original, as multi.py does. Variants must be declared `extern "C"` so they
can be exported. Run it with `env -u TMPDIR`, as the build does.
