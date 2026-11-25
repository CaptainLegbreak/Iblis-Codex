# The compiler readers on Iblis-Codex

These read what the pinned MSVC 2005 SP1 back end decides for one function: the global register allocator's
candidates, priorities, reference counts, tie keys, colouring order and the register each one gets (`c2prio.py`),
plus frame slots, temporaries, scheduling and splits (the other readers; README.md covers them all). They read the
compiler and never change what it emits. They are diagnostics: our source still has to be plain C, with no forcing
constructs. A reading tells you which variable needs more or fewer weighted uses, and in which block, for the
original's choice to come out.

## Setup (once, about a minute)

    apt-get install -y gdb                     # gdb with Python
    python3 /home/claude/coordwt/tools/c2diag/setup_tcspin.py /home/claude/iblis-codex/toolchain/bin
    mkdir -p ~/.d2match-c2diag/runs

`setup_tcspin.py` checks that our toolchain is the pinned one (same c2.dll as theirs) and makes a patched copy
in `~/.d2match-c2diag`, outside the repo. Never commit that copy.

## A reading of one function

    unset TMPDIR
    cd /home/claude/iblis-codex      # your clone, with the candidate in its unit and its // 0x<VA> marker
    F=$(python3 /home/claude/coordwt/tools/c2diag/iblis_pp.py Source/X/Y.cpp /tmp/y.i.cpp)   # preprocess as build.py does; prints the unit's extra flags
    python3 /home/claude/coordwt/tools/c2diag/c2prio.py /tmp/y.i.cpp --func <function name> --flags "$F" --blocks

Use the function's name for `--func`: preprocessing drops the `// 0x<VA>` comments.

`reading.py` (used for lanes/borrowed/) does this end to end in the coordinator's scratch worktree: it puts a draft
into its unit, scores it, writes the instruction diff and the reading, and restores the unit.

## How to use it on a register difference

1. In `idiff.txt`, find the first place the original and ours pick different registers, and name the variable in
   each register on both sides.
2. In the reading, find those variables' `prio`, `refs` and `key` in the round where the choice is made, and the
   colouring order. The original's winner needs a higher priority than ours, or an equal priority and a higher key.
3. Priority is the sum over blocks of `refunits * weight * K` for blocks where the variable is referenced, minus
   `weight * K` for blocks where it is live but unused (`--blocks` prints each term). So adding a real use in a loop
   raises it a lot; ending a variable's life earlier removes the minus terms.
4. Find a plain-C change that moves the numbers the right way, then build the unit and check the bytes.
