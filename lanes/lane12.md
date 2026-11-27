# Lane 12

Written by lane 12 only. Newest entries at the top of each section; delete what is done.

Lane 12: link debt for the ordinary build (tools/linkdebt.py): type_disagreement, duplicate_data, local_copy and
renamed_definition. Per-module export headers other modules include (the FogApi2.h way), most-referenced targets
first; the extra definitions of duplicated globals removed. Branches lane12/<topic>, based on lane10/short-data until
it is on main; from #473, based on main.

## Ready
- Fri Nov 27 13:45 PST 2026: **lane12/api-d2client-2** (7e1f35f19, on #487 7425acf9d): two commits, declunits-1 (below, rebased onto
  #487 without conflicts) and "D2Client: declarations of its exports agree with their definitions" (genheaders
  --module D2Client --header D2ClientApi.h): a new narrowly included D2ClientApi.h, other headers' lines for
  D2Client addresses corrected, 370 private copies in 79 units go. Left: 12 exports (AUTOMAP_InitCharSaveHeader,
  GAME_GetUnitTypeOrInvalid, SCMD_RegisterMsgHandler, SEED_RollRandomNumber, CUNIT_GetMonsterBaseId, gtMcpInfo,
  gtGameDataTable, the MCP packet and wheel callbacks, gbRightClickConsumed: callers' types or typedefs) and per
  unit the copies whose removal changes the unit. VERIFIED tree faec1a3dd1cb1b06073df3241f8ff91af61aaaf4 (on
  #487). linkdebt of the D2Client commit, measured on dupdata-2: 23,056 -> 22,945 (type_disagreement -71,
  renamed_definition 104 -> 64; D2Common -54, D2Game -41, D2Client -16; no module rises). auditguard: no count
  rose (raw offset 120, byte pointer math 153, pointer casts 4,890 -> 4,874). Take this instead of declunits-1.
- Fri Nov 27 13:04 PST 2026: **lane12/declunits-1** (in api-d2client-2; 5fc38001c, stacked on dupdata-2): the coordinator's 12:07 item, done before lane 11
  renames D2Multi/D2Launch. CharSel.cpp, MainMenus.cpp, ChatDlg.cpp and ComCallback.cpp reconciled one name at a
  time, each change followed by a build of the whole unit: 54 private lines take their definition's prototype, 11
  that an included header already declares the same way go (no new includes, so no declaration count changes).
  63 keep their own type because the unit's code changes with the definition's; for lane 11 and the type owners
  these stay as they are (type_disagreement), by unit:
    CharSel.cpp: MAINMENUS_JoinGame (0x00434a00), MAINMENUS_DeleteCharFiles (0x0043c750), 
      CONTROL_SetFocusedEditBox (0x004f91c0), D2Win_10051 (0x004fc9b0), IMAGE_SetCoordinates (0x004fd0b0), 
      EDITBOX_SetText (0x004ff5a0), ANIMIMAGE_SetIsRunning (0x00500810)
    ChatDlg.cpp: CHATDLG_RequestCharLogon (0x00449e10), WINMAIN_SendMcpCreateGame (0x0044a400), 
      CONTROL_SetFocusedEditBox (0x004f91c0), D2Win_10052_TEXTBOX_GetNumLines (0x004fb910), D2Win_10196 (0x004fbb90), 
      D2Win_10188 (0x004fbde0), EDITBOX_SetText (0x004ff5a0), D2Win_10076 (0x004ffe10), BUTTON_SetIsPressed 
      (0x005009a0), STR_GroupUint64DigitsWithSuffix (0x005255c0), STRTABLE_LoadStringTables (0x005259c0), 
      gpLevelDiffCheck (0x00798c40)
    ComCallback.cpp: SStrChr (0x00413490), CHATDLG_IsPrintableChar (0x00443600), CONTROL_SetFocusedEditBox 
      (0x004f91c0), IMAGE_GetFrameCount (0x004fd1b0), D2Win_10078_IsNumber (0x004fe770), BUTTON_SetIsPressed 
      (0x005009a0), gData_0070CD84 (0x0070cd84), gData_0070CD94 (0x0070cd94), gpBnetJoinGameScrollBarsCelFile 
      (0x0077bc20), gpJoinGameBckgCelFile (0x0077bc50), gpGameButtonBlankCelFile (0x0077bc5c), 
      gpJoinGameClickBoxCelFile (0x0077bc60), gpGreyLevelBoxCelFile (0x0077bc64), gpRadioButtonCelFile (0x0077bc68), 
      gpNumberArrowsCelFileA (0x0077bcc0), gpNumberArrowsCelFileB (0x0077bcc4), gpNumberArrowsCelFileC (0x0077bcc8), 
      gpNumberArrowsCelFileD (0x0077bccc), gpNumberGreyArrowsCelFile (0x0077bcd0), gpCreateGameBckgCelFile 
      (0x0077bd0c), gpBnetWideButtonBlankCelFile (0x0077bd18), gpBnetCancelButtonBlankCelFileB (0x0077bd2c), 
      gpLadderChoiceExpCelFile (0x0077bd34), gpPlayerProfileBckgCelFileA (0x0077bd3c), gpPlayerProfileBckgCelFileB 
      (0x0077bd40)
    MainMenus.cpp: FOG_ComputeChecksum (0x00411130), GAME_GetPreferredRealm (0x00437d00), 
      CHATDLG_RequestCharCreate (0x00449df0), CHATDLG_RequestCharLogon (0x00449e10), CONTROL_SetFocusedEditBox 
      (0x004f91c0), CONTROL_Create (0x004f93c0), D2Win_10053 (0x004fba30), D2Win_10055 (0x004fbab0), D2Win_10051 
      (0x004fc9b0), IMAGE_SetFrame (0x004fd110), IMAGE_ForceNormalDrawMode (0x004fd170), IMAGE_GetFrameCount 
      (0x004fd1b0), D2Win_10082 (0x004fdd00), D2Win_10077_EDITBOX_GetText (0x004fdd90), D2Win_10106 (0x00500310), 
      D2Win_10104 (0x00500340), BUTTON_SetIsPressed (0x005009a0), BUTTON_SetText (0x005009d0)
  VERIFIED tree 2f42091733a0ecd68cb0834f89b00afd28aa758d. linkdebt vs dupdata-2: 23,075 -> 23,056
  (type_disagreement 5,576 -> 5,557; D2Multi -10, D2Launch -9; no module rises). auditguard: no count rose.

## Claimed
- Fri Nov 27 13:45 PST 2026: status. Ready: api-d2client-2 (declunits + D2Client). Next: genheaders for D2Game, then a second pass
  over D2Win/D2Gfx/D2CMP/D2Sound (module-api-headers was made before the tool). Files: Source/Include/D2GameApi.h
  (new) and the private copies of D2Game's functions in other modules.
- Fri Nov 27 8:40 PST 2026: status. D2Lang done on top of api-storm-2 (only 3 copies can go: D2LangApi.h already agrees with the
  definitions, and dropping the rest changes their units; it will ride with D2Common). D2Common through genheaders
  is running (905 symbols, 1,237 copies; round 1: 42 of 251 units still differ). Finding for the owners:
  D2COMMON_10475_PostStatToStatList (0x626E10) is defined taking D2StatListExStrc* while 21 D2Game units declare
  D2StatListStrc*; those keep their copies for now (a definition-side type question, not a void return).
- Fri Nov 27 7:20 PST 2026: status. Ready: module-api-headers-8, genheaders-3, api-fog-2, api-storm (a stack, in that order on #477).
  Next: D2Lang, then D2Common (new exports to a new narrowly included D2CommonApi3.h), on api-storm.
- Fri Nov 27 05:12 PST 2026: status. Held branches done (module-api-headers-7 Ready; the other three dropped, see
  below). genheaders: a third commit (includes placed where the copy stood, forward declarations for corrected
  header lines, --plan) is verifying on #476 as lane12/genheaders-2. Next: Storm, D2Lang, then D2Common through
  genheaders, each stacked on api-fog. Files claimed: Source/Include/StormApi*.h, D2LangApi*.h, D2CommonApi*.h and
  the private copies of Storm's, D2Lang's and D2Common's functions in other modules' units.
- Fri Nov 27 03:54 PST 2026: the other three held branches, checked on #474: **lane2/gfxdata-record-3 dropped**: its one
  commit is module-api-headers-6's first commit, carried there. **lane9/decls-renderers-2 dropped**: already on main
  (git cherry marks its commit equivalent; D2Glide.h has the 41 declarations). **lane5/decls-d2game-8 dropped**:
  12 of its 14 commits are already on main (each cherry-picks empty); the other two, Task.cpp taking in
  TASK_TASK_ProcessGame (0x5645E0) and Items.cpp taking in D2GAME_CreateItemUnit (0x559CE0), add two noinline
  (auditguard: noinline 109 -> 111) and a __forceinline, which the current rules forbid, so I don't carry them; they
  are function placement, not declarations, if lane 5's owner wants them ruled on.
  Next: genheaders module by module, Fog, Storm and D2Lang first, then D2Common (new exports to a narrowly included
  D2CommonApi3.h: appending to the widely included D2CommonApi.h changes units that count declarations), then the
  rest. These branches stack on lane12/module-api-headers-6 (its 130 units are the same ones), and say so.
  Files claimed: Source/Include/FogApi*.h, StormApi*.h, D2LangApi*.h, D2CommonApi*.h and the private copies of
  those modules' functions in other modules' units.

## Questions (owner's ruling: void definitions whose callers use a result)

## Notes for other lanes
