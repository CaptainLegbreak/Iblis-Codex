# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/place-c 7df3a184 570->560 ten placements; VERIFIED b9cc909be167
  - WINMAIN.CPP: Unknown_0044AB70, Unknown_0044AB80 (14 MCP packet handlers; their packet records keep the placeholder's pack(1)).
  - panel.cpp: Unknown_00499DE0. text.cpp: Unknown_004A7720, Unknown_004A78C0, Unknown_0049D310.
  - ui.cpp: Unknown_004549F0 and Unknown_00454A70 together (hover text). 0x4549F0 takes Unicode text; `gwszHoverLine` is `Unicode[256]` defined in ui.cpp; `AUTOMAP_GetHoverMonsterName` takes `unsigned short` (the caller passes a string id without widening it).
  - Roster.cpp: Unknown_004790F0, rewritten on Roster.cpp's `D2RosterPetStrc` (unit id 0x08, value 0x10) instead of a second view of the record.
  - SoundHdr.cpp: Unknown_00481920 returns SoundHdr.cpp's own `D2SoundEnvironTxtStrc`; units.json name updated to the new mangling.
  - Based on #296; merges into #297 with a docs-only conflict. Nothing outside lane 4. Borrowed data 15,691 B (same as my other builds).
- `soundenv-name` and `chat-more` are in #295/#297; nothing left for them.

## Questions

## Notes for other lanes

- Lane 1: D2Client.h line 847 still declares 0x4DF6C0 as `sub_004DF6C0(int nArg)`; nothing in lane 4 uses that declaration any more.
- Lane 1: by the ownership table, these lane-4 residue placeholders are yours now: Unknown_004C0440 (0x4C0550 left: a static panel mode swaps a stack slot in 0x4BFDD0), Unknown_004C7C80, Unknown_004C97C0 (register allocation in Skills.cpp).
- Lane 2: `D2ClientTypes.h`'s `D2GfxDataStrc` holds its 20 entries as byte pairs because moving `D2GfxEntryStrc` out of D2Client.h changes code in useitem.cpp and inv_0048DD90.cpp. useitem.cpp and Unknown_0047BD80 kept private cel-context copies for the same reason (Unknown_0047BD80 is now in chat.cpp on chat-run-3, using the shared one).

## Left in place (and why)

- Unknown_00469420 (CmdTbl.cpp's run): CmdTbl.cpp's 0x469C20 calls it in the original, and in CmdTbl.cpp it would be inlined.
- Unknown_0045AE90 (ui.cpp's run): ui.cpp would inline it into a caller the original calls it from.
- Unknown_004A6260 (text run): its callers 0x4A6310/0x4A6350 are in text_0049A950.cpp, which defines `gnKeyConfigSelected`; in that piece or text.cpp the code changes. Two definitions of that global (text.cpp static, the piece global) need sorting out first.
- Unknown_00450520 (View.cpp's run): Storm hash table template destructors; not placing compiler-generated template code by run evidence.
- Unknown_0047C420 (0x47C420): in chat.cpp it compiles with different registers; cause not found yet. chat.cpp keeps an unmarked copy for its caller 0x47CA70, as WardenClient.cpp did.
- WardenClient.cpp 0x47F8B0-0x47F990 and Unknown_0047F950: no assert; they sit on the chat/Warden boundary just before 0x47FA20.
- Weather block 0x472210-0x473F50 (Unknown_00472210, Unknown_004726F0, Unknown_00472890, Unknown_00473090, Unknown_004737B0): no assert path or data reference names its file yet.
- Unknown_0046C7D0: Gfx.cpp would inline its functions into 0x46CE40 and 0x46D780.
- Hireables.cpp's four placeholders (0x493A00, 0x493B50, 0x493CE0, 0x493E10): they disagree on the pet-icon helpers' argument order; aligning the calls made seven functions differ.
