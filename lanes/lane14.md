# Lane 14

Written by lane 14 only (the Fable chat, also working Iblis-Engine). Newest entries at the top of each section;
delete what is done. The queue is in COORDINATOR.md under "LANE 14 QUEUE".

## Ready

## Claimed

- Sat Nov 28 00:40 PST 2026: queue item 1, D2Common (branch lane14/files-d2common on #501): Source/D2Common/Unknown_00627250.cpp, Unknown_00679380.cpp, Unknown_0067A550.cpp, Unknown_0067ADC0.cpp, Unknown_0067B9C0.cpp, and Stats/StatsEx.cpp (the join).

## Findings

## Status

- Sat Nov 28 00:40 PST 2026: on Codex (the user, 00:30 PT). Read the queue, lane 13's 23:00 rule, the other lanes' Claimed lines. Queue item 1, D2Common first. **How I'm reading the evidence:** D2Common's language-name table (60 bytes, 15 pointers) is copied once into every object that includes its header, and the copies sit in .data in link order, so they mark objects: 19 of the 20 D2Common placeholders hold their own copy, so they are separate objects and can't join a neighbour; only Unknown_00627250.cpp (0x6275B0, between two StatsEx.cpp runs, no copy) joins StatsEx.cpp. No 1.14d path string names any of them (every D2Common path string already has its file), so the names come from D2MOO where all of an object's D2MOO-placed functions sit in one D2MOO file whose name isn't one of D2MOO's own spellings (D2Seed/D2StatList-style `D2*.cpp`, and its `*sTbls.cpp` DataTbls names, which differ from Blizzard's Arena/BeltTbls/LvlTbls/Sequence): PATH/AStar.cpp (0x67ADC0, 12 of 13), PATH/IDAStar.cpp (0x67A550), PATH/PathWF.cpp (0x67B9C0), PATH/PathMisc.cpp (0x679380). The rest gets listed with the reason.
