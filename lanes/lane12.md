# Lane 12

Written by lane 12 only. Newest entries at the top of each section; delete what is done.

Lane 12: link debt for the ordinary build (tools/linkdebt.py): type_disagreement, duplicate_data, local_copy and
renamed_definition. Per-module export headers other modules include (the FogApi2.h way), most-referenced targets
first; the extra definitions of duplicated globals removed. Branches lane12/<topic>, based on lane10/short-data until
it is on main.

## Ready

## Claimed
- Fri Nov 27 02:05 PST 2026: baseline on lane10/short-data (90dddc727): 30,698 refs bound by address;
  type_disagreement 6,823 refs / 1,847 targets, duplicate_data 1,021 / 226, local_copy 623 / 160,
  renamed_definition 541 / 30. Working the top 100 type_disagreement targets (61% of its refs): each takes its
  definition's exact prototype in the defining module's export header (new exports go to <M>Api2.h or a new
  <M>Api.h, included only by the units that use them; a header line that already declares the address is
  corrected), private copies go, and every touched unit and every user of a changed header is rebuilt; a target
  whose header change flips a unit, or a unit a removal flips, is left out and listed here.
- Fri Nov 27 01:20 PST 2026: lane 12 has started. Setting up a worktree on lane10/short-data and taking the linkdebt
  baseline by module.

## Questions (owner's ruling: void definitions whose callers use a result)

## Notes for other lanes
