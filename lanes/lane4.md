# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Handover to lane 1 (D2Client 0x4A0000 and up)

Lane 4 starts nothing new in this range. In flight and staying with lane 4: `editbox-split` (posted ready) and `spellsel-data` (verifying). Everything else here is yours:

- **QuestLog.cpp** (0x4A18F0-0x4A40D0, 29 functions on main). Its object also takes the 0x4A1760-0x4A3410 strays still filed in `UI/text_0049A950.cpp`: 0x4A1760, 0x4A1770, 0x4A1870, 0x4A18C0, 0x4A18E0, 0x4A1910, 0x4A1930, 0x4A2610, 0x4A2630, 0x4A2690, 0x4A26F0, 0x4A27D0, 0x4A2840, 0x4A2A20, 0x4A3020, 0x4A3410 (they sit between QuestLog.cpp's own functions). 0x4A01A0 sits in text.cpp's run (text.cpp ends around 0x4A15xx).
- **QuestLog's layout initializer** 0x6CAC30 (filed in `Storm/Unknown_006CAA30.cpp`) writes 0x7241C8-0x724210. Parked: the struct modelling of that block is not consistent yet, so the initializer can't be rebuilt against it.
- **Key config:** 0x4A4110 (text_0049A950.cpp) is inside the key-config object's run, and text_0049A950.cpp still defines `gnKeyConfigSelected`, which the key-config unit also has as a static. Move both into `Unknown_004A43E0.cpp` together.
- **Unknown_004A6260.cpp** (0x4A6260) and the strays 0x4A6310, 0x4A6350 (text_0049A950.cpp) are one object after the key-config one (0x4A61A0-0x4A63B0).
- **spellsel / levelup:** `Unknown_004A7AE0.cpp` (0x4A7AE0, 0x4A8ED0, 0x4A9260, 0x4A9300, 0x4A9690, 0x4A9870) and 0x4A8A30, 0x4A8CF0 (`Unknown_004A76C0.cpp`) sit in spellsel.cpp's run; check the asserts and data readers before joining.
- **npcmenu area:** 0x4B17A0 and 0x4B1D70 (`Unknown_004A9BD0.cpp`) sit between npcmenu.cpp's and Monster.cpp's functions.
- **SkillDesc:** `UI/SkillDesc.cpp` holds 4 language-table copies (0x72D728, 0x72D994, 0x72D9D0, 0x72DA0C) and `UI/SkillDesc_004E1FF0.cpp` 3 (0x72D8D8, 0x72D914, 0x72D950), so they span 4 and 3 original objects. `Unknown_004DF6C0.cpp` holds 9.
- **Other copies in this range:** text.cpp's 0x724A80, 0x7274B0, 0x7274EC, 0x727528 (all past text.cpp's own data at 0x723768, so they start later objects); `Unknown_004A43E0.cpp` 0x724798, 0x7247D8; useitem.cpp 0x7279B0, 0x7279EC; Wall2.cpp 0x72A96C, 0x72A9A8. 0x7274B0/0x7274EC are ambiguous: I couldn't tie them to code.
- **Borrowed data in the range:** 0x724CD8 (8 zero bytes between Unknown_004A76C0.cpp and Unknown_00499500.cpp), npcmenu.cpp's zero blocks (112 B, 18 blocks; most should join the record in front, as in zero-gaps), 0x726C54, and the editbox/Object.cpp edge (0x727708 is Object.cpp's copy; editbox-split places the other two).

## Status

- Wed Nov 25 12:35 PST 2026: audit-decls-d2client-hi posted (the 0x4A0000-up files' shared declarations; D2Client's private copies are now 2,800 fewer over the four branches).

## Ready

- lane4/audit-decls-d2client-hi 13a5ead0d (on #406): audit item 4 for D2Client's files from 0x4A0000 up (lane 1's old range). 218 D2Client functions declared privately with one spelling in two or more of those files: 142 more prototypes go into D2ClientFuncs.h (76 were there already), the 62 files include it, and 658 private copies go. Same exclusions as before (definition spelled differently, linkage, Unicode, data-table stubs). **GAME/Msg.cpp is an eighth declaration-count unit:** its 0x478350 moves with the header's growth, so it stops including D2ClientFuncs.h and gets back its two private declarations (header comment updated). Unknown_004DF4B0.cpp defines its own CLIENTS_GetUnitX/Y and keeps its copies. All 139 D2Client.h includers all equal; audit guard: no count rose. Full build: Game.exe identical, tree 511e39e3c14a98b299b503e97018d6859bc55712, borrowed code / data 10,018 / 261 B.

## Claimed



## Questions



## Notes for other lanes

- **Lane 1 (the coordinator's answer on audit item 4):** `lane4/audit-decls-d2client` adds `Source/D2Client/D2ClientFuncs.h`, a second D2Client header for function prototypes, included after D2Client.h. Please add your range's (0x4A0000 up) shared declarations to it rather than to D2Client.h, and switch your files over: my branch only touches files in 0x440000-0x49FFFF now, so your files still declare my range's functions privately too. Seven units must not include it: inv.cpp, inv_004886C0.cpp, inv_0048BC10.cpp, inv_0048DD90.cpp, useitem.cpp, Item.cpp and UnitSnd.cpp (declaration-count functions 0x488100, 0x488B00, 0x48BC10, 0x48DD90, 0x4BFDD0, 0x4C4740, 0x4CA560; useitem and Item.cpp are yours). The script I used is generic; ask here if you want it.

- **Lane 1 (D2Client.h):** for audit item 4 I'm adding prototypes for functions in my range (0x440000-0x49FFFF) to D2Client.h, in one block near the end, and deleting their private copies in D2Client .cpp files (yours included where they declare them). If you're moving declarations too, take functions from 0x4A0000 up so we don't touch the same lines; tell me here if you'd rather do D2Client.h edits yourself.

- **Lane 1:** `lane4/player-object` edits D2Client/UNIT/Player.cpp the same way (its run 0x460760-0x463859 is in lane 4's range): five functions and gaPlayerModeInfo join it, and it builds /GS-.
- **Lane 1:** `lane4/join-unitmode-4815a0` edits D2Client/UNIT/UnitMode.cpp (its 0x480490-0x481830 run is in lane 4's address range): two functions join it and its old unmarked copies go. Rebase around it if you have UnitMode.cpp work in flight.

- **Lane 3, audit (Game.cpp's 183 `f_<hex>` fields):** almost all of them are the single member of about 75 structs Game.cpp names after Storm and D2Common functions, e.g. `struct sub_00417810 { D2StormLinkStrc f_0; ~sub_00417810(); };` (0x417xxx-0x426xxx Storm, 0x601xxx-0x602xxx D2Common, a few 0x44Dxxx/0x44Exxx). They look like Storm list/link template instances (destructors and members of TSLink/TSList over other element types) spelled as one struct per function. Renaming `f_0` wouldn't help; they want stpl.h's templates. Is that on your stpl one-definition list? If you'd rather I convert them in Game.cpp with your templates, say which instances they are and I'll do it.

- **Lane 10:** `lane4/join-game-f9b0` deletes `Source/D2Client/Unknown_0044F9B0.cpp` (its contents move to D2Client/GAME/Game.cpp). Your `names-fileprefix-d2cmp` renames in that file: when you rebase, apply them in Game.cpp instead (the member names are compiler-mangled template members, so most may simply drop out).

- Lane 6 (your 0x70F7A4 question): agreed it isn't ComCallback.cpp's, but it isn't SCmd.cpp's either: SCmd.cpp has its own copy at 0x711490 (just before gaPacketTable). The copy starts the data of the window-message object after Record.cpp: code 0x451A90-0x451F0F (the SCMD_* window handlers filed in SCmd.cpp, automap.cpp's 0x451E10 and Unknown_00451E70.cpp), data the copy 0x70F7A4, gbClientAppActive 0x70F7E0 and gaWindowMsgHandlers 0x70F7E4 (Unknown_00451E70.cpp's, pointing at those handlers). I'm taking it on lane4/winmsg-object: the copy's plan record moves from your ComCallback.cpp entry to Unknown_00451E70.cpp (plan only, nothing in your source changes).

- Coordinator (0x45FB80, your follow-up): tried; it can't be emitted plainly in Unknown_00460420.cpp. Nothing in the image calls it or points at it (no rel32 call, no base relocation to 0x45FB80), yet it takes nX in eax (`mov edi, eax`), a compiler-chosen register convention that MSVC gives only to internal functions whose every call site it sees. As an external function in the popup unit it compiles with the stdcall convention (stack argument, different registers); as a static nothing references, the compiler drops it (NO_SYMBOL). A header inline emitted out of line would use the normal convention too. Its placeholder emits it only through context copies of the skill tree's callers. So it needs an existing emit helper or the original caller; leaving it in Unknown_0045FB80.cpp.

- Lane 1: the 8 borrowed zero bytes at 0x723F30, between text.cpp's gaQuestPageRanges (0x723F08, 40 B) and the quest lookup record at 0x723F38 (filed in View.cpp), are read byte by byte by 0x4A1950, 0x4A2CB0, 0x4A3220 (text.cpp) and 0x4A2C30, 0x4A34F0 (QuestLog.cpp). Zero-only data compiles to .bss, so in the original they are members of an aggregate with nonzero bytes: the tail of the page ranges' record or the head of 0x723F38's. Yours, by range.

- Lane 6 (McpConnect.cpp): the MCP state accessors 0x449AD0-0x449E6F (getters filed in D2Client's Game.cpp, setters in Unknown_00449890.cpp, plus WINMAIN.CPP's 0x449B70) read only McpConnect's bss (0x798F7C-0x798FCC, 0x7992E0-0x799318), as do McpConnect.cpp's 0x449E70-0x44A16F and the packet run in D2MCPClient/Unknown_0044A170.cpp. They look like McpConnect.cpp's own accessors, filed before its path users. Yours to take if you agree; I haven't moved them.

- Lane 2, all lanes (D2LanguageNames.h): a header copy is placed only when its unit's .data section places as a whole, that is when the unit has other planned data right after the copy and nothing elsewhere in the same section. Of 21 lane 4 units, 11 got their copy borrowed instead: units whose .data is the copy alone (PalShift.cpp), units that also hold a record far away (View.cpp holds 0x723F38), or a zero record next to it. The full verify still passes, so check the borrowed figure (or PROVENANCE's `copied` runs at the copy) after converting.

- Lane 1: the borrowed copy at 0x727708 starts Object.cpp's data (the spinner object's data ends with its RTTI at 0x727708; then come the copy, the 22-int table at 0x727744 and gnShrineHandlerCount at 0x72779C). Object.cpp can take it from D2LanguageNames.h if nothing of Object.cpp's comes before it.

- Lane 1: 0x721CDC, the borrowed copy after WardenClient's data, starts UnitMode.cpp's data by the code order (WardenClient 0x47F8B0, UnitMode 0x480490, SoundHdr 0x481840). Yours to define.

- Lane 1: the copy at 0x724D3C starts the data of the object after the skill tree, which by the data that follows (gpfnUModCallbacks, 0x724D78) is MonUnique.cpp. 14 of its pointers sit inside gaSkillTabX (planned as int[12][3], 144 B; the table itself is 88 B) and the 15th is gData_00724D74, left in Unknown_00499500.cpp. I'm not moving them into your file.

- Coordinator, lane 3: WardenClient's RTTI (0x700140-0x70018C: object locator, class hierarchy, base class array and descriptor) has come from the compiler since warden-class (#307); PROVENANCE marks it `source`. 0x70018C-0x7001C0 is UIWidget's (type descriptor 0x7275B0), also `source` now. Nothing left to take there.
- Lane 1: D2Client.h line 847 still declares 0x4DF6C0 as `sub_004DF6C0(int nArg)`; nothing in lane 4 uses it.
- Lane 2: `D2ClientTypes.h`'s `D2GfxDataStrc` holds its 20 entries as byte pairs because moving `D2GfxEntryStrc` out of D2Client.h changes code in useitem.cpp and inv_0048DD90.cpp.

## Left in place (and why)

- Unknown_004E89A0.cpp (0x4E89A0, the elemental damage sum, inside SkillDesc.cpp's run; its tables gaElemDamageColors/gaElemDamageStats are read only by it). SkillDesc.cpp already has its own copy of the function, and marked there it builds 1,000/1,000 B with one difference: in the no-poison path the original loads pMaxDamage into esi before pMinDamage into ebx, and SkillDesc.cpp's build swaps the two loads. Tried in SkillDesc.cpp: the two poison helpers as plain `inline` (they aren't inlined there; the function comes out 581 B), the helpers' code written straight into the function (the swap), one helper holding the poison step and clamp, the clamp in the caller, block-local copies of the two pointers in the helper's order (all the swap or not inlined), and the placeholder's own `__forceinline` helpers (the swap). Since the same source builds equal in the placeholder, it's SkillDesc.cpp's surroundings (declarations or other code), not the function. Parked.
- Unknown_004E2320.cpp is its own object (its data starts with its own copy, 0x72CD90), not a SkillDesc join.

- Unknown_0047CC90.cpp's language copy (0x713008) stays a plan record. **Coordinator / lane 5 (link_exe.py), diagnosis:** with the copy from D2LanguageNames.h the unit's .data is laid out exactly as before (copy at 0, gtMainOptionHeader at 60, gData_00713048 at 80 …; checked symbol by symbol), and nothing in the unit refers to the copy. The marker fails only because `place_data`'s relocation anchors include five wrong ones (0x712FB8-0x712FF8, 16 bytes apart): `take()` anchors a section at `S - y["value"]` for each relocation from placed code, and a reference that carries an addend in the instruction (an element or field past a symbol's start, as the option tables are indexed) comes out shifted by it. Without a marker the plan's name markers outvote them, so no build has gone wrong; the static-marker check is strict and stops. Subtracting the instruction addend for section-symbol / static references (or only checking the marker against anchors from names, like `data_marker_anchors`) would let this copy, and any similar unit's, convert. I haven't touched the tool.
- Unknown_0046C570.cpp: its own object (its data starts with its own copy, 0x712A28).

- Unknown_00463BC0.cpp (0x463BC0, inside CUnit.cpp's run): uncalled and unreferenced, yet takes pUnit/pRoom/nX in esi/edi/ebx with nY on the stack, the compiler's convention for a static whose callers are all visible. Same case as 0x468B20 and 0x45FB80.
- Unknown_0045C370.cpp (0x45C4B0) and Unknown_00463720.cpp (0x463720/0x463740/0x463810): called from D2Client, D2Game and D2Common alike (identical code folded across objects), so adjacency doesn't name their file.

- Unknown_00467DF0.cpp (0x468B20, the spell hotkey handler, inside CmdTbl.cpp's run): nothing calls it or points at it, yet it takes nHotkey in esi, a compiler-chosen convention for a static whose callers are all visible (CmdTbl.cpp's CMDTBL_Hotkey0-15 have its body inlined). A plain function in CmdTbl.cpp would get the stack convention, so it stays behind its emit helper, like 0x45FB80.

- inv.cpp's second language copy (0x722298): inv's code (inv.cpp with its inv_* pieces) ends at 0x492BB3 and Hireables.cpp starts at 0x492BC0, and Hireables has its own copy at 0x7222D4 right before gdwHelpMenu (0x722310). So 0x722298 starts an object with neither data of its own nor code in that gap. A unit for it would have no functions, which the tree has nowhere yet, and the copy is built (not borrowed). Left in inv.cpp until there's a code-less unit form, or its code turns up.

- The five objmap leads that join two language-copy objects (npcmenu.cpp <- Unknown_0046ACE0, text.cpp <- Unknown_0049BB40, Game.cpp <- Unknown_00477620, WINMAIN.CPP <- Unknown_0044BA20, Roster.cpp <- Unknown_0047A980): separate objects, each with its own copy (coordinator's answer).
- automap.cpp <- Unknown_0045AE90: separate objects; the original calls 0x45AE90 out of line from three automap.cpp functions, which in one /Ob2 unit would inline it (coordinator's answer).
- Party.cpp <- Unknown_0049AF60 (0x49AF60, 0x49BDD0): 0x49AF60 is a register-convention static of Party.cpp's object that keeps a stack slot for a parameter it never reads (`ret 0x10`). A plain static in this compiler drops that slot, and reading the parameter only to keep it would be a forcing construct (coordinator, #374), so the placeholder stays with its struct-argument view.

- WardenClient.cpp: of the strays listed earlier, 0x479230, 0x4936E0 and 0x496B10-0x496BE0 have gone to RosterPets.cpp and Hireables.cpp, and 0x4922A0 is on `warden-4922a0`. 0x4E6560 and the text panel opener 0x4A1320 are in lane 1's range now (0x4A1320 belongs to the text unit by its data, gnTextTop 0x7225FC, but brings the text panel globals WardenClient.cpp defines under other types).
- 0x70F814 and 0x722314 (4 zero bytes before ui.cpp's and panel.cpp's language table copies): alignment padding, but only once the copy is the first data of its unit. D2LanguageNames.h with a build symbol marker stops the link ("static data marker disagrees with the section's other anchors"): neither unit's .data is in the original order (panel.cpp defines gbControlPanelMouseDown before gnUiRecordIndex; ui.cpp's data has another file's 32 bytes at 0x70F858). Parked until those units' data are in order.
- 0x47C420: retried in chat.cpp. It differs only by an esi/edi swap throughout. Not the cause: any other chat.cpp function's definition (each one, and all its chat.cpp callees together, turned into declarations), or whether gbNoPickup, gnLanguageId and gbChatInputOpen are defined or extern. So it is the order or set of declarations.
- Weather block: in Unknown_00472210.cpp, 0x4726F0 and 0x473090 inline the seed roll differently (different length); Unknown_00472890/004737B0 and Gfx.cpp's 0x473A70 need their declarations sorted first.


- Game.cpp subsets of Unknown_0044F9B0/Unknown_0044F9D0 (0x44F9D0-0x450F70): the placeholders define Storm list/hash-table template members that Game.cpp already declares differently; merging them needs one definition of those templates first.
- Unknown_0045AE90 (ui.cpp's run): ui.cpp would inline it into a caller the original calls it from.
- Unknown_004A6260 (text run): its callers 0x4A6310/0x4A6350 are in text_0049A950.cpp, which defines `gnKeyConfigSelected`; text.cpp has its own static one. The two definitions need sorting out first.
- Unknown_00450520 (View.cpp's run): Storm hash table template destructors; not placing compiler-generated template code by run evidence.
- WardenClient.cpp 0x47F8B0-0x47F990 and Unknown_0047F950: no assert; they sit on the chat/Warden boundary just before 0x47FA20.
- Weather block 0x472210-0x473F50: no assert path or data reference names its file yet.
- Unknown_0046C7D0: Gfx.cpp would inline its functions into 0x46CE40 and 0x46D780.
- Hireables.cpp's four placeholders (0x493A00, 0x493B50, 0x493CE0, 0x493E10): they disagree on the pet-icon helpers' argument order; aligning the calls made seven functions differ. Retried one at a time in Hireables.cpp: 0x493B50 and 0x493CE0 differ only by ebx/edi swaps, the other two are rejected forms.

