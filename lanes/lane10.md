# Lane 10

Written by lane 10 only. Newest entries at the top of each section; delete what is done.

Lane 10 has started (2026-11-23). Names: naming plans for placeholder-named functions in known files, as `lanes/names/<scope>.tsv` + `<scope>-skipped.tsv`. Edits no source.

## Claimed
- D2Game (next), then D2CMP, D2Common, the rest.

## Plans
- plan d2client-editbox: 0 high, 0 medium, 96 skipped. editbox.cpp holds only virtual members of the Button/EditBox/Spinner control classes (vtable slots, wrappers, ctors/dtors) plus identical forwarders; all wait on the member-function question. Only the skipped list is posted (no plan file).
- plan d2client-ui: 60 high, 26 medium, 96 skipped (d2moo 0, inferred 86). D2Client UI/ except editbox.cpp (ui, automap, CmdTbl, inv, chat, Hireables, panel, text, spellsel, npcmenu, useitem, SkillDesc). Point-in-rect tests on unnamed rectangles, numbered panel-mode tests and near-identical callback pairs are skipped.
- plan d2client-units: 35 high, 30 medium, 82 skipped (d2moo 0, inferred 65). D2Client UNIT, ENGINE, SKILLS, DRAW, WARDEN, Sound, CORE (everything outside GAME/ and UI/). Client-AI routines, unexplained flag testers and D2Common-ordinal forwarders are skipped.
- plan d2client-game: 38 high, 25 medium, 111 skipped (d2moo 0, inferred 63). D2Client GAME/ (Game, SCmd, View, Select, Msg, RosterPets, Roster, Wall2). Prefixes as the files use (GAME_, SCMD_Handle…, VIEW_, MSG_Send…, ROSTERPETS_, WALL2_); SELECT_ for Select.cpp. Many skips are list/array template members and empty stubs.
- plan fog: 51 high, 17 medium, 106 skipped (d2moo 14, inferred 54). All of Fog in named files, plus 0x0040ECC0/0x0040ED40 (filed in Storm SFILE.CPP, but in LogManager's run; storm-sfile-skipped.tsv now points here). Prefixes as each file already uses (ERRORMANAGER_, LOGMANAGER_, EXCEPTIONS_, SYSTEM_, DATAARRAYS_, D2QSQUEUE_; D2QSSOCKET_ for D2QSSocket.cpp, whose only named functions are FOG_ exports); FOG_ for the exports D2MOO's ordinal list places. FOG_10083_Cos_LUT / FOG_10084_Sin_LUT keep the ordinal style the file already has (FOG_10082_Noop).
- All three plans re-checked against #327: every old name is still a placeholder, every new name is unused in Source and names.csv.
- plan storm-rest: 70 high, 30 medium, 127 skipped (d2moo 12, inferred 88). All of Storm outside SFILE (SMem, SStr, SReg, SErr, SSignature, SBig, SComp, SLog, SMsg, SEvt, SCmd) and the 3 zlib functions still sub_ (get_crc_table, zlibVersion, zlibCompileFlags: the source already defines them under those names). SBig's static helpers get a Big stem (BigAdd…) because bare Add/And are array member names elsewhere.
- plan storm-sfile: 23 high, 17 medium, 133 skipped (d2moo 7, inferred 33). Storm SFILE.CPP and its pieces. Storm's own style: export-like functions as SFile…, statics as bare VerbNoun (as ReadFileChecked, InternalReadAligned already are). The d2moo names are Storm exports placed by D2MOO's ordinal list: each sits between the same two named exports in 1.10f and 1.14d.

## Questions
- Coordinator: member functions with placeholder names (e.g. `BigBuffer::sub_004212D0_Get`, `CBitInput::sub_0041D8D0_Peek`, `CHuffman::sub_0041EED0_NewItem`). Their natural names are bare members (Get, Peek, NewItem), which are not unique repo-wide, so I skip them for now. Can your rename tool take `Class::Member` targets? If yes, I'll plan them as `Class::Member` in a later round. Template-list and growable-array members (TSList NewNode/DeleteNode, the per-type copies) stay skipped either way.

## Notes for other lanes
- Lane 3: 0x0040ECC0 and 0x0040ED40 (log banners) are filed in Storm SFILE.CPP but sit in Fog's run and only Fog LogManager.cpp calls them; 0x0041D9A0 (CBitOutput flush) is filed in SFILE.CPP inside the SComp run. Skipped in my plan until they move.
- Coordinator: about 80 zlib functions in Source/Storm/zlib/ are marked `placeholder` in names.csv but already carry their zlib 1.2.8 names; they need a names.csv source fix, not a rename. My Storm plan names only the 3 that are still sub_.
