# Lane 12

Written by lane 12 only. Newest entries at the top of each section; delete what is done.

Lane 12: link debt for the ordinary build (tools/linkdebt.py): type_disagreement, duplicate_data, local_copy and
renamed_definition. Per-module export headers other modules include (the FogApi2.h way), most-referenced targets
first; the extra definitions of duplicated globals removed. Branches lane12/<topic>, based on lane10/short-data until
it is on main; from #473, based on main.

## Ready
- Sat Nov 28 0:30 PST 2026: **lane12/compile-1** (f9458f508, stacked on types-6): queue item 5, lane 14's compile findings.
  D2Game's timer event types defined once in a new Source/Include/D2GameEvents.h (macros only), replacing 30
  files' #defines and enums; Player.cpp and PlrSave.cpp had redefined FREEHOVER/STATREGEN/TRAP with each other's
  values partway down, so the later uses are renamed to the names of the values they pass (code unchanged). The
  doubled D2_MIN/D2_MAX (Skills.cpp, SkillAss.cpp, D2WinFont.cpp), MonsterTbls.cpp's D2_ASSERT, ObjMode.cpp's
  UNITFLAG_TARGETABLE and inv.cpp's va_start go; d3dFloorCache.cpp's casting RELEASE becomes FLOORCACHE_RELEASE.
  D2GAME_PACKETS_SendPacket0xAE returns 0 after its exiting assertion. Not done, with reasons in the commit: the
  PKWARE API names (one void* declaration would need casts in SCOMP.CPP's typed callbacks) and the returns of
  MONUNIQUE_ApplyResistantMod, MONSTERUNIQUE_UMod8_Resistant, D3DSPRITE_DrawSpriteQuad (the original returns what
  eax holds; return 0 and the immunity count both change the code). Full build 538 units equal. VERIFIED tree
  6ae99aa0cc8808ad8b4f256c284ff49ddcf0138a. linkdebt unchanged (19,973). auditguard: no count rose.
- Fri Nov 27 23:39 PST 2026: **lane12/types-6** (bd1d49abf, stacked on types-5): two commits. "D2Client ui.cpp: the gold panel is a
  dialog" (gpGoldPanel typed D2ClientDialogStrc*, as DIALOG_CreateDialogFromFile returns; ui.cpp's
  DIALOG_AddTextLine declaration takes the definition's), and the next 120 targets the same way as types-5: 28
  addresses changed. Full build 538 units equal. VERIFIED tree 9bd4429aff880e0524597cf568e3fe137fb8d652. linkdebt vs
  types-5: 20,015 -> 19,973 (type_disagreement 3,923 -> 3,881; D2Game -20, D2Client -13, D2Common -7, Fog -2; no
  module rises). auditguard: no count rose (pointer casts 4,851 -> 4,849).
  The one-address-at-a-time pass is done: the remaining 3,881 refs are spread thin (about 2 per target) and
  each needs a type changed by hand (a caller's variable, a struct field, a definition) or the decisions noted in
  Claimed. Unless the coordinator wants that long tail next, I'd take a list from you.

## Claimed
- Fri Nov 27 22:32 PST 2026: status. Ready: types-5. On types-6 (from types-5): ui.cpp's gold panel typed as the dialog it is
  (DIALOG_AddTextLine's last disagreeing caller), and the next 120 targets (394 refs: the long tail now, about 3
  refs each) running one at a time. Not doing by hand, because each would add a pointer cast:
  D2COMMON_10475_PostStatToStatList (defined on D2StatListExStrc*, 35 units pass D2StatListStrc*) and SStrChr
  (returns const char*, callers keep char*): both need the stat-list and string ownership decided first.
- Fri Nov 27 20:37 PST 2026: status. Ready: types-4. Running: types-5, the next 120 type_disagreement targets (1,221 refs) one
  address at a time with each unit rebuilt (43 of 120 done); then the hand cases (PostStatToStatList's stat-list
  struct, SStrChr's const, DIALOG_AddTextLine's dialog type).
- Fri Nov 27 15:10 PST 2026: status. On top of api-d2client-2: D2Game (11 copies), and a second genheaders pass over the modules
  module-api-headers covered (D2Gfx 16, D2CMP 4, D2Sound 12, D2Net 2, D2MCPClient 49 copies so far), with new
  exports in <M>Api2.h and existing header lines left alone (--no-fix-headers: correcting them flipped
  declaration-count units such as inv_0048BC10.cpp). Running: D2Win, D2Launch, D2Multi, D2BNClient, Bnclient,
  D2Glide, D2DDraw; then one verified branch for the lot.
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

## Units that flip when their declarations change (queue item 4)
- Fri Nov 27 15:58 PST 2026: from every genheaders run so far: the unit, and the exports whose declaration change (the private copy
  dropped or retyped, or "via a header": the export header's line) changes the unit's code or stops it compiling.
  Counts include unnamed compile errors, so not every entry is a code change.
    D2Client/UNIT/Player.cpp (45): COLLISION_CheckMaskWithPattern, COLLISION_GetFreeCoordinates, COMPOSIT_GetWeaponClassId, D2Common_10958, DUNGEON_CheckLOSDraw, DUNGEON_GetLevelIdFromRoom, DUNGEON_GetPortalFlagFromLevelId, DUNGEON_IsRoomInTown, DUNGEON_UpdatePops, INVENTORY_AllocInventory, PATH_GetLastPointX, PATH_GetLastPointY, PATH_GetNextRoom, PATH_GetUnitCollisionPattern, PATH_SetDirection, PATH_SetDist, PATH_SetFootprintCollisionMask, SKILLS_AssignSkill, SKILLS_GetSkillsTxtRecordFromSkill, SKILLS_SetFlags, STATES_IsUnitShapeShifted, STATLIST_AllocStatListEx, STATLIST_GetOwner, STATLIST_SetUnitStat, STATLIST_UnitGetStatValue, UNITROOM_RemoveUnitFromRoom, UNITS_AllocPlayerData, UNITS_ChangeAnimMode, UNITS_FreePlayerData, UNITS_GetLeftSkill, UNITS_GetPlayerPortalFlags, UNITS_GetRightSkill, UNITS_GetRoom, UNITS_GetRunAndWalkSpeedForPlayer, UNITS_GetUnitSizeX, UNITS_GetUsedSkill, UNITS_IsCurrentRoomInvalid, UNITS_IsInMeleeRange, UNITS_IsInMovingModeEx, UNITS_IsObjectInInteractRange, UNITS_SetCurrentRoomInvalid, UNITS_SetPlayerPortalFlags, UNITS_SetUsedSkill, UNITS_StopSequence, UNITS_TestCollisionBetweenInteractingUnits
    D2Game/ITEMS/Items.cpp (30): DATATBLS_GetItemRatioTxtRecord, DATATBLS_GetItemRecordFromItemCode, DUNGEON_AllocDrlgDelete, ITEMMODS_AssignProperty, ITEMMODS_SetRandomElixirFileIndex, ITEMS_AssignPrefix, ITEMS_AssignRareSuffix, ITEMS_CheckIfSocketable, ITEMS_CheckIfStackable, ITEMS_CheckIfThrowable, ITEMS_CheckItemTypeIfThrowable, ITEMS_GetBaseCode, ITEMS_GetEarLevel, ITEMS_GetFileIndex, ITEMS_GetItemQuality, ITEMS_GetItemType, ITEMS_GetMaxSockets, ITEMS_GetMinStack, ITEMS_GetSpawnStack, ITEMS_GetVarInvGfxCount, ITEMS_SetInvPage, ITEMS_SetItemFormat, ITEMS_SetItemLevel, ITEMS_SetItemQuality, STATLIST_FreeStatList, STATLIST_GetMaxDurabilityFromUnit, UNITROOM_RemoveUnitFromRoom, UNITS_ChangeAnimMode, UNITS_FreeCollisionPath, UNITS_GetInventoryGoldLimit
    D2Game/PLAYER/PlrMsg.cpp (27): CHAT_SetLangIdInHoverMsg, DRLG_GetDistanceToXY, DUNGEON_GetTownLevelIdFromActNo, INVENTORY_AllocInventory, ITEMS_GetItemType, ITEMS_SetInvPage, ITEMS_SetItemCell, PATH_GetLastPointX, PATH_GetLastPointY, PATH_GetMoveTestCollisionMask, PATH_SetMoveTestCollisionMask, PATH_SetPathTarget, PATH_SetTargetPos, SKILLS_CheckRequiredAttributes, SKILLS_CheckRequiredSkills, SKILLS_GetSkillsTxtRecordFromSkill, SKILLS_GetUseState, SKILLS_SetParam4, STATLIST_GetListExpireFrame, STATLIST_GetMaxManaFromUnit, STATLIST_GetMaxStaminaFromUnit, UNITS_ChangeAnimMode, UNITS_GetCurrentLifePercentage, UNITS_GetInventoryRecordId, UNITS_GetLeftSkill, UNITS_GetRightSkill, UNITS_SetInteractData
    D2Game/SKILLS/SkillAss.cpp (26): D2Common_10235_PATH_UpdateRiderPath, DATATBLS_GetLevelsTxtRecord, DRLG_GetDistanceToXY, INVENTORY_GetEightWayDirection, INVENTORY_GetLeftHandWeapon, ITEMS_GetBaseCode, ITEMS_GetBodyLocation, MISSILE_SetCurrentFrame, MISSILE_SetTargetY, MISSILE_SetTotalFrames, MONSTERS_GetHirelingTypeId, MONSTERS_IsBoss, PATH_SetNumberOfPathPoints, SEED_GetSeeds, SEED_SetSeeds, SKILLS_GetToHitFactor, SKILLS_SetParam3, SKILLS_SetParam4, STATES_ToggleGfxStateFlag, STATES_UpdatePgsvFlags, STATLIST_FreeStatList, STATLIST_GetOwner, STATLIST_GetSkillId, STATLIST_GetStatListFromUnitAndFlag, STATLIST_MergeStatLists, UNITS_GetDirectionToCoords
    D2Game/OBJECTS/ObjMode.cpp (24): COLLISION_GetFreeCoordinates, DATATBLS_GetLevelDefRecord, DATATBLS_GetTreasureClassExRecordFromActAndDifficulty, DUNGEON_AllocDrlgDelete, DUNGEON_GetTownLevelIdFromActNo, DUNGEON_ToggleHasPortalFlag, ENVIRONMENT_GetPeriodOfDayFromAct, INVENTORY_GetLeftHandWeapon, INVENTORY_GetWieldType, ITEMS_GetItemType, ITEMS_SetItemCell, MONSTERS_IsBoss, MONSTERS_IsDead, SKILLS_GetSkillMode, SKILLS_GetSkillsTxtRecordFromSkill, SKILLS_GetWeaponMasteryBonus, STATLIST_FreeStatList, STATLIST_GetMaxManaFromUnit, STATLIST_GetMaxStaminaFromUnit, UNITS_ChangeAnimMode, UNITS_CheckObjectPortalFlag, UNITS_FreeCollisionPath, UNITS_GetUnitSizeX, UNITS_GetUnitSizeY
    D2Client/UNIT/CUnit.cpp (24): COLLISION_GetFreeCoordinates, D2COMMON_10209_PathCheckPathingFlag, D2COMMON_11013_ConvertMode, D2Common_10216, D2Common_10958, D2Common_11020, DATATBLS_GetNoPerFromLevelsTxt, DATATBLS_GetSuperUniquesTxtRecord, DUNGEON_FindRoomBySubtileCoordinates, DUNGEON_GameSubtileToClientCoords, ENVIRONMENT_GetPeriodOfDayFromAct, INVENTORY_AllocInventory, MONSTERS_GetHirelingTypeId, PATH_SetPathingFlag, SKILLS_GetSkillsTxtRecordFromSkill, SKILLS_SetFlags, UNITROOM_RemoveUnitFromRoom, UNITS_ChangeAnimMode, UNITS_GetAnimOrSeqMode, UNITS_GetClientCoordX, UNITS_GetClientCoordY, UNITS_GetLeftSkill, UNITS_GetRightSkill, UNITS_GetUnitSizeX
    D2Game/PLAYER/PlrModes.cpp (22): DUNGEON_AllocDrlgDelete, INVENTORY_GetCorpseCount, ITEMS_CheckIfStackable, ITEMS_CheckIfThrowable, ITEMS_GetBodyLocation, ITEMS_GetItemType, ITEMS_SetInvPage, LOG_11100, PATH_SetPathTarget, SKILLS_GetSkillsTxtRecordFromSkill, SKILLS_GetUseState, SKILLS_SetFlags, STATLIST_FreeStatList, STATLIST_GetMaxManaFromUnit, STATLIST_GetMaxStaminaFromUnit, UNITS_ChangeAnimMode, UNITS_FreeCollisionPath, UNITS_GetInventoryGoldLimit, UNITS_GetInventoryRecordId, UNITS_GetLeftSkill, UNITS_GetRightSkill, UNITS_SetUsedSkill
    D2Game/SKILLS/SkillSor.cpp (21): CLIENTS_GetUnitX, CLIENTS_GetUnitY, DATATBLS_GetLevelsTxtRecord, GAME_GetUnitTypeOrInvalid, INVENTORY_GetEightWayDirection, MISSILE_SetCurrentFrame, MISSILE_SetTotalFrames, MONSTERS_GetHirelingTypeId, SEED_RollLimitedRandomNumber, SKILLDESC_GetSkillParamByLevel, SKILLDESC_GetSkillParamTwo, SKILLS_GetElementalLength, SKILLS_GetParam1, SKILLS_GetSkillsTxtParam7, STATES_ToggleGfxStateFlag, STATLIST_FreeStatList, UNITS_GetDirectionToCoords, UNITS_SetOverlay, sub_0045C4B0_GetSkillsTxtRecord, sub_00463740_FindRoomAtPoint, sub_0046ACE0_GetMissilesTxtRecord
    D2Win/Src/D2WinMain.cpp (21): D2GFX_ClearScreen, D2GFX_DrawBoxAlpha, D2GFX_EndScene, D2GFX_GetBackBuffer, D2GFX_GetResolutionMode, D2GFX_HardwareAcceleratedRenderMode, D2GFX_IsFixedAspectRatio, D2GFX_StartDraw, SCROLLBAR_Destroy, WINDOW_CenterWindow, WINDOW_CheckCutScene, WINDOW_ClearCaches, WINDOW_Create, WINDOW_Destroy, WINDOW_EndCutScene, WINDOW_GetDimensions, WINDOW_GetResolutionSize, WINDOW_GetWindow, WINDOW_IsFullScreen, WINDOW_Resize, WINDOW_SetPaused
    D2Game/PLAYER/PlrTrade.cpp (18): ITEMMODS_AddCraftPropertyList, ITEMS_AssignRareSuffix, ITEMS_CheckIfStackable, ITEMS_CheckItemTypeIdByItemId, ITEMS_GetBaseCode, ITEMS_GetEarLevel, ITEMS_GetFileIndex, ITEMS_GetItemQuality, ITEMS_GetItemType, ITEMS_GetMaxSockets, ITEMS_GetSockets, ITEMS_SetInvPage, ITEMS_SetItemCell, ITEMS_SetItemQuality, STATLIST_GetFullStatsCountFromUnit, UNITS_ChangeAnimMode, UNITS_GetInventoryGoldLimit, sub_00408090
    D2Glide/Unknown_0050BD30.cpp (18): DDCORE_CreateSurface, DDCORE_ReleaseSurfaces, gaDDrawDebugFontGlyphOffsets, gbDDrawBinkDone, gdwDDrawDebugFontBkColor, gdwDDrawDebugFontTextColor, gnDDrawBinkFlags, gnDDrawBinkX, gnDDrawBinkY, gnGlideBinkFlags, gnGlideBinkY, gnGlideDebugX, gnGlideDebugY, gpDDrawBink, gpDDrawDebugFontGlyphs, gpDDrawPalette, gppGlideDebugBuffer, sub_00512710_DDrawDrawBox
    D2Game/SKILLS/SkillBar.cpp (17): COLLISION_CheckAnyCollisionWithPattern, COLLISION_GetFreeCoordinates, COLLISION_ResetMaskWithPattern, DRLG_GetDistanceToXY, PATH_GetUnitCollisionPattern, PATH_SetFootprintCollisionMask, PATH_SetMoveTestCollisionMask, SKILLS_GetParam1, SKILLS_SetFlags, SKILLS_SetParam3, SKILLS_SetParam4, STATES_ToggleGfxStateFlag, STATLIST_FreeStatList, STATLIST_SetListExpireFrame, UNITS_GetUnitSizeX, UNITS_SetOverlay, UNITS_SetUsedSkill
    D2Game/UNIT/SUnit.cpp (15): DUNGEON_FindRoomBySubtileCoordinates, DUNGEON_GetPresetUnitsFromRoom, DUNGEON_IncreaseAlliedCountOfRoom, DUNGEON_StreamRoomAtCoords, STATLIST_RemoveAllStatsFromOverlay, UNITS_AllocStaticPath, UNITS_AllocUnit, UNITS_ChangeAnimMode, UNITS_FreeStaticPath, UNITS_FreeUnit, UNITS_GetCurrentLifePercentage, UNITS_GetInventoryRecordId, UNITS_GetUnitSizeX, UNITS_InitializeSequence, UNITS_SetAnimData
    D2Multi/Src/ChatDlg.cpp (15): ARCHIVE_FreeCellFile, BUTTON_SetBaseFrame, CONTROL_MouseInsideRect, CONTROL_SetCellFile, D2Win_10005, D2Win_10015, D2Win_10016, D2Win_10045, D2Win_10050_TEXTBOX_SetLine, D2Win_10057, D2Win_10076, D2Win_10142_CompUnitDestroy, D2Win_10146, D2Win_10161, D2Win_StopMessageLoop
    D2Client/UI/inv_0048BC10.cpp (14): D2COMMON_10267_Return (via a header), D2Win_10129_DrawFramedText, DATATBLS_GetLevelThreshold (via a header), DUNGEON_GetFloorTilesFromRoom (via a header), ENVIRONMENT_GetPeriodOfDayFromAct, FOG_GetInstallPath (via a header), ITEMS_GetItemQuality, MONSTERS_GetActFromHirelingTxt (via a header), STATLIST_GetOwner, STATLIST_GetUnitBaseStat, STATLIST_MergeStatLists, STATLIST_UnitGetStatValue, UNITS_GetInventoryRecordId, sub_00420290_BreakHandlerChain
    D2Game/SKILLS/SkillDruid.cpp (13): COLLISION_CheckAnyCollisionWithPattern, COLLISION_CheckMask, D2COMMON_11013_ConvertMode, MISSILE_SetTargetY, PATH_GetFinalTargetX, PATH_GetFinalTargetY, PATH_GetUnitCollisionPattern, SKILLS_GetElementalLength, SKILLS_GetParam1, SKILLS_GetToHitFactor, STATES_ToggleGfxStateFlag, STATLIST_FreeStatList, STATLIST_SetListExpireFrame
    D2Client/UNIT/Item.cpp (12): D2COMMON_10160_PathUpdateDirection, DATAARRAYS_FreeEntry (via a header), DUNGEON_GameSubtileToClientCoords, DUNGEON_GetTileDataFromAct, ITEMMODS_AssignProperty, SBigDel (via a header), UNITROOM_RemoveUnitFromRoom, UNITS_ChangeAnimMode, UNITS_FreeCollisionPath, UNITS_GetInventoryRecordId, UNITS_GetLeftSkill, UNITS_GetRightSkill
    D2Game/PLAYER/PlrSave.cpp (11): INVENTORY_AllocInventory, INVENTORY_GetLeftHandWeapon, ITEMS_CheckIfFlagIsSet, ITEMS_GetBodyLocation, ITEMS_SetInvPage, STATLIST_GetMaxManaFromUnit, STATLIST_GetMaxStaminaFromUnit, UNITS_ChangeAnimMode, UNITS_GetInventoryGoldLimit, UNITS_SetSwitchLeftSkill, UNITS_SetSwitchRightSkill
    D2Client/SKILLS/SkillsMon.cpp (11): D2COMMON_10160_PathUpdateDirection, D2COMMON_10475_PostStatToStatList, D2Common_10216, INVENTORY_GetEightWayDirection, MISSILE_SetCurrentFrame, MISSILE_SetStreamMissile, MISSILE_SetStreamRange, MISSILE_SetTotalFrames, SKILLS_SetFlags, SKILLS_SetParam3, UNITS_GetWeaponClass
    D2Client/UI/ui.cpp (10): D2GFX_DrawBox, D2GFX_GetResolutionMode, D2LANG_GetStringByReferenceString, D2LANG_GetStringFromTblIndex, DUNGEON_GetLvlWarpTxtRecordFromRoomAndUnit (via a header), WINDOW_GetWindow, WINDOW_IsFullScreen, sub_00526320_ToUnicode, sub_005269D0_FormatText, sub_005272B0_FormatText
    D2Client/GAME/Game.cpp (10): D2GFX_DisableFixedAspectRatio, D2GFX_EnableVSync, D2GFX_GetResolutionMode, D2GFX_Release, D2GFX_SetAmbientColor, TEXTURE_CelDraw, WINDOW_Destroy, WINDOW_GetWindow, WINDOW_IsFullScreen, WINDOW_ShowAll
    D2Client/UI/text_0049C9C0.cpp (8): D2GFX_DrawBox, D2LANG_GetStringFromTblIndex, D2Win_10117_DrawText, D2Win_10121_GetTextWidth, DUNGEON_GetLevelIdFromRoom, FOG_IsExpansion, QUESTRECORD_GetQuestState, UNITS_GetRoom
    D2Launch/Src/CharSel.cpp (6): D2COMP_CreateCompositeUnit, D2Win_10156, D2Win_10161, FOG_Decode14BitsFromString, SMemAlloc, SMemFree
    D2BNClient/BnDownload.cpp (6): SMemCopy, SRegSaveData, SRegSaveString, SRegSaveValue, SStrCopy, SStrLen
    D2Multi/Src/ComCallback.cpp (6): D2Win_10078_IsNumber, SErrGetErrorStr, SMsgDispatchMessage, SRegSaveValue, SStrCopy, SStrPrintf
    D2Common/DATATBLS/DataTbls.cpp (6): D2LANG_GetStringByReferenceString, D2LANG_GetStringFromTblIndex, STRTABLE_FindString, UNICODE_ToAscii, gpAnimData, sub_00526320_ToUnicode
    D2Client/UI/UseItem.cpp (6): D2WINFONT_SplitText, D2Win_10117_DrawText, D2Win_10121_GetTextWidth, D2Win_10129_DrawFramedText, UNITS_ChangeAnimMode, WINDOW_GetWindow
    D2Gdi/Src/gdiCore.cpp (6): CelGetHeight, CelGetOffsetX, CelGetOffsetY, CelGetWidth, CmpDoLensEffect, WINDOW_GetWindow
    D2Client/UI/inv_0048DD90.cpp (5): D2Win_10117_DrawText, D2Win_10121_GetTextWidth, D2Win_10129_DrawFramedText, D2Win_10131_GetTextDimensions, FOG_IsExpansion
    D2Client/UI/automap.cpp (4): D2GFX_DrawLine, FOG_Encode14BitsToString, gadwLogOpenTick, gadwLogWriteTick
    D2Common/DATATBLS/ItemTbls_00634DC0.cpp (3): FOG_10216_AddRecordToLinkingTable, FOG_AllocLinker, sub_00408090
    D2Client/UI/SkillDesc_004F30A0.cpp (3): D2LANG_GetStringFromTblIndex, sub_00526320_ToUnicode, sub_005269D0_FormatText
    D2Client/Unknown_004E89A0.cpp (3): D2LANG_GetStringFromTblIndex, sub_00526320_ToUnicode, sub_005269D0_FormatText
    D2Client/Unknown_004EDCA0.cpp (3): D2LANG_GetStringFromTblIndex, sub_00526320_ToUnicode, sub_005269D0_FormatText
    D2Game/Unknown_0054DAC0.cpp (3): DATATBLS_GetLevelsTxtRecord, DATATBLS_GetSuperUniquesTxtRecordCount, DUNGEON_GetWarpCoordinatesFromRoom
    D2Game/MISSILES/MissMode.cpp (3): COLLISION_CheckMaskWithSize, PATH_SetNewDistance, STATLIST_SetState
    D2Client/GAME/Wall2.cpp (3): D2GFX_CheckLowQuality, D2GFX_CheckPerspective, D2GFX_GetResolutionMode
    D2Client/UI/Hireables.cpp (3): D2GFX_DrawBox, D2GFX_DrawLine, D2GFX_GetResolutionMode
    D2CMP/Unknown_006009C0.cpp (2): ARCHIVE_ReadFileToBuffer, sub_00408090
    D2Gfx/SRC/Window.cpp (2): ERRORMANAGER_RaiseErrorReport, FOG_IsExpansion
    D2Common/DATATBLS/ItemTbls.cpp (2): SStrCmpI (via a header), sub_0040EB10 (via a header)
    D2Hell/SRC/Archive.cpp (2): SFileCloseArchive, SStrChr (via a header)
    D2Game/GAME/Game.cpp (2): SMemZero, UNITS_GetInventoryGoldLimit
    D2Client/UNIT/MonUnique.cpp (2): D2LANG_GetStringFromTblIndex, sub_00526320_ToUnicode
    D2Client/DRAW/dLightMap.cpp (2): UNITS_GetPrecisionX, UNITS_GetPrecisionY
    Main/Unknown_004059D0.cpp (2): WINMAIN_InitInterface, sub_0042E590_SetOwner
    D2Client/ENGINE/Cursor.cpp (2): CelGetHeight, CelGetWidth
    D2Client/Unknown_004BBE10.cpp (2): CelGetHeight, CelGetWidth
    D2Win/Src/D2WinEditBox.cpp (2): D2GFX_DrawBox, WINDOW_GetWindow
    D2Client/Unknown_00477620.cpp (1): sub_0040ABE0
    D2Common/DATATBLS/MissileTbls.cpp (1): FOG_AllocLinker
    D2Common/DATATBLS/TokTbls.cpp (1): sub_00408090
    D2Direct3D/Src/d3dCore.cpp (1): LOGMANAGER_WriteLogLine
    D2Game/UNIT/SUnitMsg.cpp (1): BITMANIP_GetSize
    D2Multi/Unknown_0043C8A0.cpp (1): FOG_Encode14BitsToString
    Bnclient/Unknown_0052A240.cpp (1): SMemZero
    D2Common/DATATBLS/ItemTbls_00633730.cpp (1): STRTABLE_FindString
    D2Common/Unknown_0063F690.cpp (1): D2LANG_GetStringByReferenceString
    D2Common/Unknown_006634F0.cpp (1): D2LANG_GetStringFromTblIndex
    Fog/Src/ErrorManager.cpp (1): STRTABLE_GetSystemLanguage
    D2Client/ENGINE/Gfx.cpp (1): ITEMS_GetColor (via a header)
    D2Client/ENGINE/GfxUtil.cpp (1): ITEMS_GetColor (via a header)
    D2Client/ENGINE/Gfx_0046DB90.cpp (1): DATATBLS_GetMonModeTxtRecord (via a header)
    D2Client/ENGINE/Particle.cpp (1): WAYPOINTS_AllocWaypointData
    D2Game/MONSTER/MonsterAI.cpp (1): MONSTERS_GetActFromHirelingTxt
    D2Game/MONSTER/MonsterEval.cpp (1): DATATBLS_CalculateMonsterStatsByLevel
    D2Game/Quests/QUESTS.CPP (1): ITEMS_SetItemCell
    D2Game/PLAYER/Player.cpp (1): D2Common_10231
    D2Client/GAME/SCmd.cpp (1): STATLIST_SetUnitStat
    D2Game/UNIT/SUNITNPC.CPP (1): ITEMS_SetItemCell
    D2Common/DATATBLS/LvlTbls.cpp (1): ITEMS_RollLimitedRandomNumber
    Storm/SOURCE/SMEM.CPP (1): gpFreeBlockSweep
    D2Client/SKILLS/Skills.cpp (1): ITEMS_RollLimitedRandomNumber
    D2Client/Unknown_0046ACE0.cpp (1): ITEMS_RollLimitedRandomNumber
    D2Client/Unknown_004C9420.cpp (1): ITEMS_RollLimitedRandomNumber
    D2Common/DRLG/Preset.cpp (1): ITEMS_RollLimitedRandomNumber
    D2Common/ITEMS/ItemMods.cpp (1): ITEMS_RollLimitedRandomNumber
    D2Client/UI/npcmenu.cpp (1): ITEMS_RollLimitedRandomNumber
    D2Common/DATATBLS/AnimTbls.cpp (1): DATATBLS_GetAnimData
    D2Client/GAME/Record.cpp (1): WINDOW_GetWindow
    D2Client/UI/text_0049D5A0.cpp (1): WINDOW_GetWindow
    D2Client/UI/text_004A10E0.cpp (1): WINDOW_GetWindow
    D2Sound/Unknown_00513BC0.cpp (1): WINDOW_GetWindow
    D2Win/Src/D2WinPopup.cpp (1): D2GFX_DrawBox
    D2Win/Src/D2WinProgressBar.cpp (1): D2GFX_DrawBox

## Questions (owner's ruling: void definitions whose callers use a result)
- Sat Nov 28 0:00 PST 2026: **queue item 7 (lane 14's list in Iblis-Engine docs/LANE14.md): this session can't open the Iblis-Engine
  repository** (attaching it was refused here). Could the 151 calling-interface disagreements and the 157
  unmarked declarations be copied onto the coord branch (e.g. lanes/lane14-for-lane12.md)? Until then I'm doing
  item 5 (lane 14's compile findings), which is all in this repository.
- (resolved) width_only: the coordinator ruled at 19:35 PT to keep counting width disagreements as type_disagreement; no linkdebt.py change.
- Fri Nov 27 16:00 PST 2026: **parameter width, the same kind of question as the void ruling.** The most-referenced type_disagreement
  targets left are definitions taking a narrower parameter than their callers declare: STATLIST_SetUnitStat (197
  refs), STATLIST_UnitGetStatValue (185), STATLIST_GetUnitBaseStat (36), STATLIST_UnitGetItemStatOrSkillStatValue
  (28) take `unsigned short nLayer`, the D2Game/D2Client callers declare `int`; AITACTICS_SetAiParam (93) takes an
  `unsigned char`, callers `int`; ITEMS_CheckItemFlag (165) is `unsigned int` vs the callers' `int`. In the
  original each DLL had its own header, so both existed. Making the definition take `int` changes its own code
  (tried for the four STATLIST ones: each alone changes StatsEx.cpp), and giving the callers the narrow type
  changes theirs (the genheaders runs left those copies in place for that reason). **Ruling wanted:** keep these
  as they are, or write the definition with an `int` parameter narrowed inside (`unsigned short nLayer =
  (unsigned short)nLayerArg;`) if that keeps its bytes. I won't do either without a ruling.

## Notes for other lanes
- For lane 11 (the D2Multi/D2Launch renames): in CharSel.cpp, MainMenus.cpp, ChatDlg.cpp and ComCallback.cpp these
  private declarations keep a type other than their definition's, because the unit's code changes with the
  definition's type (type_disagreement items; leave them as they are when renaming):
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
