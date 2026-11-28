# Declaration order and code generation

Some functions compile to the original's bytes only while the declarations ahead of them stay where they are.
This page says what that dependence is, how to find it and how to fix a unit that has stopped matching.

## The rule

A function's code can depend on **how many names are declared before a global it references, modulo 64**.

- Move that global's declaration past a multiple of 64 names and nothing changes.
- Move it by any other amount and the function may come out different.
- Names declared after the global never matter. That includes the function's own prototype, its callees and
  its locals.

The global is usually a string the function passes, such as `gszEmptyAssertText` in an assert. It can also be a
buffer, or a function whose address is taken. A function can depend on two globals at once. It can also depend on
the string literals written inside it; those are created where the function is, so for them only the count
ahead of the function can change.

## What counts as a name

| Declaration | Names |
|---|---|
| a variable (`extern`, definition, `static`, `const`), used or not | 1 |
| a typedef | 1 |
| a `D2_CHECK_SIZE` line | 2 |
| a `D2_CHECK_OFFSET` line | 3 |
| an enum | 1, plus 1 per enumerator |
| a prototype | 1, plus 1 per parameter (named or not), and the same again for every redeclaration |
| a struct, class or union definition | 7, plus 1 per data member; a declared method adds 1, an inline one 3 |
| a forward declaration of a struct not yet declared | 1 |
| a forward declaration of a struct already declared | 0 |
| a struct defined after its forward declaration | the definition's count, less the 1 already counted |
| a function definition | 2, plus 1 per parameter, per local and per string literal in it |
| a file included for the first time in the unit | 1 (a repeated include: 0) |
| a `#define`, a rename, a change of type, a comment | 0 |

## What changes in the code

Only small orderings: which of two register reloads comes first after a call, which stack slot a local gets,
which register is the base and which the index in a `lea`. The function's length and every other instruction
stay the same, so the checker reports the unit `NOT_ALL_EQUAL` with a handful of differing bytes.

## The tool

`tools/namecount.py` counts names the way the table above does.

- `python tools/namecount.py --diff origin/main` lists the units your tree moves against `origin/main` and by how
  many names, and names the known functions (the table at the end of this page) whose symbol moved.
- `python tools/namecount.py --known` prints each known function's symbol and the count ahead of it.
- `python tools/namecount.py --unit Source/X.cpp [--symbol NAME]` prints the running count through one unit, or the
  count ahead of one symbol.

Methods, templates and function bodies are approximated, so treat a difference of one or two in a unit marked `~`
as a reason to compile that unit, not as proof.

## Changing a header

Count the names the change adds or removes (`tools/namecount.py --diff origin/main` does it for every unit). If the
total is a multiple of 64, no includer can change.

If it isn't, bring it to one where that is natural: split one more placeholder into its fields, or add or drop a
`D2_CHECK_OFFSET` line. A forward declaration is the awkward case, because it counts 1 only in the units that
have not seen the type yet, so it cannot be balanced for every unit at once.

## Fixing a unit that has flipped

1. Find the function: the unit's build record lists the functions that are not equal.
2. Find the global. Insert a few unused `extern int` lines near the top of the unit so that the function matches
   again (try 1 to 63), then move them down the file. The function stops matching when they pass the declaration
   of the global it depends on.
3. Move that one declaration up or down past as many names as the header change added, modulo 64. Prefer a place
   that leaves room on both sides: test a few names more and a few fewer.
4. If the symbol is created inside the function (a string literal), change the count ahead of the function
   instead. A forward prototype of a function that is defined before its first use is a name that can go.

Leave a one-line comment at a declaration placed this way, so nobody sorts it back.

## Known cases

| Function | Unit | Depends on |
|---|---|---|
| `UNITSND_GetHitSounds` (0x004CA560) | D2Client/UNIT/UnitSnd.cpp | `gszEmptyAssertText` |
| `INV_DrawItemTooltip` (0x0048DD90) | D2Client/UI/inv_0048DD90.cpp | `gszEmptyAssertText` and the `NPCMENU_ClearUnicode` prototype |
| 0x0048BC10 | D2Client/UI/inv_0048BC10.cpp | `gwszRecipeScrollText` |
| 0x00488100 | D2Client/UI/inv.cpp | `szFmtD_006D57BC` |
| 0x00439210 | D2Launch/Src/CharSel.cpp | `gszLevelFormat` |
| 0x006571A0 | D2Common/DATATBLS/MonsterTbls.cpp | `gszTxtField_mS1` |
| `DATATBLS_LoadRareSuffix_PrefixTxt` (0x00633F40) | D2Common/DATATBLS/ItemTbls.cpp | `sgtRareItemModsDataTblDesc` and its own string literals |
