# Lane 7

Written by lane 7 only. Newest entries at the top of each section; delete what is done.

## Status

- 2026-11-23 21:55 PT: lane 7 has started: the 8 borrowed functions (all but 0x4A4AD0). Order: 0x6BD230, 0x62B5B0, 0x55A6D0, 0x5DD7F0, 0x5EDC50, 0x4F8B80, 0x677880, 0x679C80. Branches will be `lane7/<va>`.
- 2026-11-23 22:10 PT, progress (nothing ready yet):
  - **0x6BD230** (Fog, 246 B): parked for now. In Excel.cpp itself (its types, gszExcelSourceFile extern) it is 244/246 and every other Excel.cpp function stays equal; the only difference is the missing unused `push ecx` slot. Also tried a __stdcall member of D2TxtLinkStrc and an in-class inline member called from the export (not inlined under /Ob2, and it flips 0x6BD780). Coming back to it after the others.
  - **0x62B5B0** (D2Common Items.cpp, 1,192 B): same length in today's Items.cpp. Writing the level checks as `cond ? (int)rec->classLevelReq : (int)rec->levelReq` gives the original's per-arm movzx (1176 B; register choice still differs: the original keeps nRequiredLevel in esi and spills pPlayer and the rare-loop offset). A 10-group variant search is running here.
  - **0x4F8B80** (561 B): its natural unit is **D2Gfx `Window.cpp`** (it sits between Window.cpp's 0x4F89F0 and 0x4F8E40, its callees are Window.cpp's 0x4F8810/0x4F8850/0x4F88B0/0x4F89F0, and it reads Window.cpp's clip statics), not D2Win. Built there with Window.cpp's /Oy- /GS-, the body structure matches; 579/561, register and stack-slot choice differ. An 11-group variant search is running here.
  - **0x55A6D0** (D2Game Items.cpp, 2,253 B): Items.cpp already holds an unmarked body of D2GAME_DropTC_6FC51360. With a `// 0x0055A6D0` marker it builds 2,239/2,253 with the rest of Items.cpp equal. Next up.

## Ready

## Questions

## Notes for other lanes

## Left in place (and why)
