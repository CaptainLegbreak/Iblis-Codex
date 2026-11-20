#include "D2Game.h"
#include "D2Structs.h"

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2PlayerDataStrc
{
    char unk0x000[0x168];
    int dwGameFrame;
};


struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;

    int sub_005490E0_CheckCursorItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x005490E0
    int sub_00549150_CheckStoredItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x00549150
    int sub_005492F0_CheckBeltItem(D2UnitStrc* pUnit, int nItemGUID);                                      // 0x005492F0
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nFlags[4];
};

struct D2SkillsTxt
{
    char unk0x00[0x04];
    unsigned char nFlags[8];
};

struct D2DataTablesStrc
{
    char unk0x00[0xC5C];
    int nLevelsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit);                           // 0x00535E80
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall QUESTS_UseClueItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID);                    // 0x00544840
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer);    // 0x00547F50
void __fastcall sub_00549A60_SendCantDoThat(D2UnitStrc* pUnit);                                             // 0x00549A60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x00554D00
void __fastcall SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTile);                // 0x005550B0
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0
unsigned int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);             // 0x0055B6C0
void __fastcall D2GAME_PickupItemEx_6FC42B80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x0055CF50
int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pItemStatus); // 0x0055E170
int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus); // 0x0055E7C0
int __fastcall D2GAME_Return0_6FC48930(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x0055E9A0
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus); // 0x0055EF20
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0
int __fastcall ITEMMODE_UseItemOnItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetGUID, int nUseItemGUID, int* pItemStatus); // 0x00561ED0
int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc); // 0x00562390
int __fastcall ITEMMODE_PlaceItemInCube(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nCubeGUID, int* pItemStatus); // 0x005628C0
int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00563560
void __fastcall PLRTRADE_TryToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);         // 0x00566E60
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);       // 0x005678A0
void __fastcall MONSTERAI_ActivateNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract); // 0x00572E60
void __fastcall MONSTERAI_EndNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract); // 0x00572F20
void __fastcall MONSTERAI_StartNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonsterInteractStrc* pMonInteract, char nQuestFlags); // 0x00573020
int __fastcall NPC_HandleDialogMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nType, int nNpcGUID, int nItemGUID); // 0x00579D60
void __fastcall sub_0057FB70_PickUpCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody);  // 0x0057FB70
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
void __fastcall D2GAME_PLAYERMODE_Change_6FC81A00(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectType, int nObjectGUID); // 0x00584540
void __fastcall OBJMODE_UpdateDoorModeFromCollision(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID); // 0x005845D0
void __fastcall sub_00584F60(D2GameStrc* pGame, D2UnitStrc* pUnit, int nWaypointGUID, int nLevelId); // 0x00584F60
int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, short nState); // 0x005852E0
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue);             // 0x0058EC00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall sub_00622B50_TestInteractCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask);        // 0x00622B50
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit);                                                    // 0x00622DC0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);                        // 0x00623660
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);                                                     // 0x0062A4E0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD50
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                       // 0x00641530
void __fastcall sub_00641F20_SetPlayerModeState(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2);         // 0x00641F20
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                          // 0x00643860
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                           // 0x00644140
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill);                                                        // 0x00644530
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue);                                           // 0x00644620
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                       // 0x00645460
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                   // 0x00647960
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo);                // 0x00660E00
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField);                      // 0x00660E50

inline int PLRMSG_IsBodyLocValid(int nBodyLoc)
{
    return nBodyLoc > 0 && nBodyLoc < 11;
}

static __forceinline D2MonsterInteractStrc* PLRMSG_GetMonInteract(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }

    return 0;
}

static __forceinline int PLRMSG_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int PLRMSG_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static __declspec(noinline) void __stdcall sub_00548A50_ChangeModeAndSetInteract(int nInteractSkill, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pPlayer, 0, 3, nUnitType, nUnitGUID, 0);
    sub_00641F20_SetPlayerModeState(pPlayer, nInteractSkill, nUnitType, nUnitGUID);
}

// 0x00548A80
static __declspec(noinline) int __stdcall sub_6FC83D00(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pTarget))))
    {
        return 0;
    }

    return 2;
}

int __fastcall sub_6FC828D0(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame)
{
    switch (nUnitType)
    {
    case 2:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 2, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        D2_ASSERT(DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId), 703);

        if (pUnit->dwAnimMode >= 8)
        {
            return 3;
        }

        if (D2Common_10399(pPlayer, pUnit) > 50)
        {
            return 1;
        }

        if (UNITS_IsObjectInInteractRange(pPlayer, pUnit) && !sub_00622B50_TestInteractCollision(pPlayer, pUnit, 0x804))
        {
            D2Common_10153(pPlayer->pDynamicPath);
            if (!OBJMODE_OperateObjectInRange(pGame, pPlayer, 2, nUnitGUID))
            {
                return 3;
            }
        }
        else
        {
            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 2, nUnitGUID);
        }

        return 0;
    }
    case 5:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 5, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        const int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance > 4)
        {
            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 5, nUnitGUID);
        }
        else
        {
            SUNIT_WarpPlayer(pGame, pPlayer, pUnit);
        }

        return 0;
    }
    case 4:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 4, nUnitGUID);
        const int nAnimMode = pUnit ? pUnit->dwAnimMode : 0;
        if (!pUnit || nAnimMode != 3)
        {
            return 1;
        }

        const int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance <= 4 && !sub_00622B50_TestInteractCollision(pPlayer, pUnit, 0x804))
        {
            int bFailed;
            if (a4)
            {
                D2GAME_PickupItemEx_6FC42B80(pGame, pPlayer, nUnitGUID, &bFailed);
            }
            else
            {
                D2GAME_PickupItem_6FC43340(pGame, pPlayer, nUnitGUID, &bFailed);
            }

            if (bFailed)
            {
                return 3;
            }
        }
        else
        {
            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 4, nUnitGUID);
        }

        return 0;
    }
    case 1:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 1, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        const int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nFlags[1] & gdwBitMasks[1] && pMonStatsTxtRecord->nFlags[1] & gdwBitMasks[0])
        {
            D2Common_10153(pUnit->pDynamicPath);
            AIGENERAL_SetAiControlParam(pUnit, 1, 40);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 1, 0, 0);
        }

        if (nDistance > 6)
        {
            if (nDistance >= 9)
            {
                return 0;
            }

            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 1, nUnitGUID);
            return 0;
        }
        else if (!PLAYER_IsBusy(pPlayer))
        {
            D2Common_10153(pPlayer->pDynamicPath);
            MONSTERAI_StartNpcInteraction(pGame, pPlayer, pUnit, sub_00535E80_GetMonInteract(pUnit), 0);
        }

        return 0;
    }
    case 0:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        const unsigned int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance > 8)
        {
            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 0, nUnitGUID);
            return 0;
        }

        if (pUnit->dwAnimMode == 17 && !D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pPlayer, 1) && !D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
        {
            sub_0057FB70_PickUpCorpse(pGame, pPlayer, pUnit);
        }
        else
        {
            PLRTRADE_TryToTrade(pGame, pPlayer, pUnit);
        }

        return 0;
    }
    }

    return 1;
}

// 0x00548EF0
static __declspec(noinline) int __stdcall sub_6FC83C60(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance)
{
    const int nUnitX = PLRMSG_GetUnitX(pUnit);
    const int nUnitY = PLRMSG_GetUnitY(pUnit);

    int nXDiff = nUnitX - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }

    if (nXDiff <= nMaxDistance)
    {
        int nYDiff = nUnitY - nY;
        if (nYDiff < 0)
        {
            nYDiff = -nYDiff;
        }

        if (nYDiff <= nMaxDistance)
        {
            return 0;
        }
    }

    return 1;
}

static __declspec(noinline) int __stdcall sub_00548F80_CheckTargetUnit(int nMaxDistance, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (!pTarget)
    {
        return 1;
    }

    if (nUnitType == 4 && ITEMS_IsInPlayersInventory(pPlayer, pTarget, 0))
    {
        return 0;
    }

    const unsigned char nPlayerAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer)));
    if (nPlayerAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pTarget))))
    {
        return 2;
    }

    return sub_6FC83C60(PLRMSG_GetUnitX(pTarget), PLRMSG_GetUnitY(pTarget), pPlayer, nMaxDistance);
}

static __declspec(noinline) int __stdcall sub_00549220_CheckOwnedItem(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pGame, 1192);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem))
    {
        return 0;
    }

    return INVENTORY_GetCursorItem(pUnit->pInventory) != pItem;
}

// 0x00549350
static __declspec(noinline) int __stdcall sub_6FC86520(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pGame, 1283);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    int nResult = 0;
    switch (pItem->dwAnimMode)
    {
    case 3:
    {
        nResult = sub_6FC83D00(pPlayer, pItem);
        if (nResult)
        {
            return nResult;
        }

        const int nX = CLIENTS_GetUnitX(pItem);
        nResult = sub_6FC83C60(nX, CLIENTS_GetUnitY(pItem), pPlayer, 10);
        if (nResult)
        {
            return nResult;
        }
        break;
    }
    case 0:
    case 1:
    case 2:
    case 4:
        nResult = sub_00549220_CheckOwnedItem(nItemGUID, pGame, pPlayer);
        if (nResult)
        {
            return nResult;
        }
        break;
    default:
        return 1;
    }

    return 0;
}

static __declspec(noinline) int __stdcall sub_00549520_CheckOrificeObject(int nItemGUID, unsigned short nState, D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID)
{
    const int nResult = sub_00548F80_CheckTargetUnit(50, pGame, pUnit, 2, nObjectGUID);
    if (nResult)
    {
        return nResult;
    }

    switch (nState)
    {
    case 2:
        return 0;
    case 3:
        return pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    default:
        return 2;
    }
}

static __declspec(noinline) int __stdcall sub_00549570_CheckWaypointObject(D2UnitStrc* pUnit, D2GameStrc* pGame, int nObjectGUID, unsigned short nLevelId)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nObjectGUID);
    if (!pObject)
    {
        return 1;
    }

    const unsigned char nUnitAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    if (nUnitAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject))))
    {
        return 2;
    }

    const int nX = PLRMSG_GetUnitX(pObject);
    const int nY = PLRMSG_GetUnitY(pObject);
    int nMaxDistance = 10;
    if (pUnit && pUnit->dwClassId == 1)
    {
        nMaxDistance = 22;
    }

    const int nResult = sub_6FC83C60(nX, nY, pUnit, nMaxDistance);
    if (nResult)
    {
        return nResult;
    }

    if (!nLevelId)
    {
        return 0;
    }

    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount)
    {
        return 3;
    }

    D2_ASSERT(UNITS_GetPlayerData(pUnit), 1586);

    unsigned short nWaypointNo;
    if (!WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &nWaypointNo))
    {
        return 3;
    }

    return WAYPOINTS_IsActivated(sub_00547F50(pGame, pUnit), nWaypointNo) ? 0 : 2;
}

static __declspec(noinline) int __stdcall sub_6FC82D10(D2GameStrc* pGame, int nPacketSize, unsigned short* pX, unsigned short* pY, D2UnitStrc* pUnit, void* pPacket)
{
    *pX = 0;
    *pY = 0;

    if (nPacketSize != 5)
    {
        return 3;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    if (!pPlayerData)
    {
        return 2;
    }

    const unsigned short nX = *(unsigned short*)((char*)pPacket + 1);
    const unsigned short nY = *(unsigned short*)((char*)pPacket + 3);

    const int nResult = sub_6FC83C60(nX, nY, pUnit, 50);
    if (nResult)
    {
        if (pGame->dwGameFrame - pPlayerData->dwGameFrame > 25)
        {
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 1639);
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(pClient, 0x15, 0, !pUnit ? -1 : pUnit->dwUnitId, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1);
            }
        }

        return nResult;
    }

    pPlayerData->dwGameFrame = pGame->dwGameFrame;
    *pX = nX;
    *pY = nY;
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x01_Walk_6FC82CB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    sub_6FC817D0(pGame, pUnit, 0, 2, nX, nY, 0);
    return 0;
}

static __declspec(noinline) int __stdcall sub_00549830_ReadTargetUnitPacket(D2GameStrc* pGame, int nPacketSize, int* pUnitType, int* pUnitGUID, D2UnitStrc* pUnit, void* pPacket)
{
    *pUnitType = 0;
    *pUnitGUID = 0;

    if (nPacketSize != 9)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    if (nUnitType >= 6)
    {
        return 2;
    }

    const int nResult = sub_00548F80_CheckTargetUnit(50, pGame, pUnit, nUnitType, nUnitGUID);
    if (nResult)
    {
        return nResult;
    }

    *pUnitType = nUnitType;
    *pUnitGUID = nUnitGUID;
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x02_WalkToEntity_6FC82ED0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, 0, 2, nUnitType, nUnitGUID, 0);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x03_Run_6FC83090(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    sub_6FC817D0(pGame, pUnit, 0, 3, nX, nY, 0);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x04_RunToEntity_6FC830F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, 0, 3, nUnitType, nUnitGUID, 0);
    return 0;
}

static __declspec(noinline) D2SkillStrc* __stdcall sub_6FC83450(D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    D2SkillStrc* pUsedSkill = pSkill;
    if (!SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 1804))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (pRightWeapon && (!sub_0062A4E0_TestItem(pRightWeapon) || ITEMS_GetItemType(pRightWeapon) == 38))
        {
            pRightWeapon = 0;
        }

        D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (pLeftWeapon && (!sub_0062A4E0_TestItem(pLeftWeapon) || ITEMS_GetItemType(pLeftWeapon) == 38))
        {
            pLeftWeapon = 0;
        }

        if (pRightWeapon && pLeftWeapon && ITEMS_CheckItemTypeId(pRightWeapon, 45) && ITEMS_CheckItemTypeId(pLeftWeapon, 45))
        {
            if (!SKILLS_GetParam4(pSkill))
            {
                pUsedSkill = SKILLS_GetSkillById(pUnit, 5, -1);
                D2_ASSERT(pUsedSkill, 1829);
                SKILLS_SetParam4(pSkill, 5);
            }
            else
            {
                SKILLS_SetParam4(pSkill, 0);
            }
        }
    }

    return pUsedSkill;
}

static __declspec(noinline) int __stdcall sub_6FC83340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY)
{
    if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 17)
    {
        return 2;
    }

    D2SkillStrc* pUsedSkill = pSkill;
    if (UNITS_CanDualWield(pUnit))
    {
        pUsedSkill = sub_6FC83450(pSkill, pUnit);
    }

    int nSkillUseState = SKILLS_GetUseState(pUnit, pUsedSkill);
    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pUsedSkill);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    if (nSkillUseState > 0 && (nSkillUseState <= 2 || nSkillUseState == 4) && pSkillsTxtRecord->nFlags[3] & gdwBitMasks[4])
    {
        pUsedSkill = SKILLS_GetSkillById(pUnit, 0, -1);
        nSkillUseState = SKILLS_GetUseState(pUnit, pUsedSkill);
    }

    const int nSkillMode = SKILLS_GetSkillModeFromUnit(pUnit, pUsedSkill);
    if (!nSkillMode)
    {
        return 2;
    }

    if (nSkillUseState != 0)
    {
        if (nSkillUseState == 1)
        {
            sub_00549A60_SendCantDoThat(pUnit);
        }

        return 2;
    }

    sub_6FC817D0(pGame, pUnit, pUsedSkill, nSkillMode, nX, nY, 0);
    return 0;
}

static __declspec(noinline) int __stdcall PLRMSG_UseSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nUnitType, int nUnitGUID, int bCheckRange)
{
    if (UNITS_CanDualWield(pUnit))
    {
        pSkill = sub_6FC83450(pSkill, pUnit);
    }

    int nUseState = SKILLS_GetUseState(pUnit, pSkill);
    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    if (nUseState > 0 && (nUseState <= 2 || nUseState == 4) && pSkillsTxtRecord->nFlags[3] & gdwBitMasks[4])
    {
        pSkill = SKILLS_GetSkillById(pUnit, 0, -1);
        nUseState = SKILLS_GetUseState(pUnit, pSkill);
    }

    if (nUseState)
    {
        return 2;
    }

    const int nSkillMode = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
    if (!nSkillMode)
    {
        return 2;
    }

    if (!(pSkillsTxtRecord->nFlags[3] & gdwBitMasks[3]) && (nUnitType < 0 || nUnitType > 1 && nUnitType != 3))
    {
        return 2;
    }

    D2UnitStrc* pOtherUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (pOtherUnit && STATES_CheckState(pOtherUnit, 0x8F))
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pOtherUnit);
        if (pOwner)
        {
            nUnitType = pOwner->dwUnitType;
            nUnitGUID = pOwner->dwUnitId;
            pOtherUnit = pOwner;
        }
    }

    if (!bCheckRange || !pOtherUnit)
    {
        D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
        return 0;
    }

    const int nSkillRange = D2Common_11016(pUnit, pSkill);
    if (nSkillRange == 1)
    {
        if (UNITS_IsInMeleeRange(pUnit, pOtherUnit, UNITS_IsInMovingModeEx(pOtherUnit)))
        {
            D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
            return 0;
        }
    }
    else if (nSkillRange != 4)
    {
        D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
        return 0;
    }

    sub_00548A50_ChangeModeAndSetInteract(SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 2013), pGame, pUnit, nUnitType, nUnitGUID);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x05_ShiftLeftClickSkill_6FC832B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    sub_6FC83340(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nX, nY);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x06_LeftSkillOnUnit_6FC83550(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nUnitType, nUnitGUID, 1);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x07_ShiftLeftSkillOnUnit_6FC83890(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nUnitType, nUnitGUID, 0);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x08_ShiftLeftSkillHold_6FC83A10(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x05_ShiftLeftClickSkill_6FC832B0(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x09_LeftSkillOnUnitHold_6FC83AC0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x06_LeftSkillOnUnit_6FC83550(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0A_ShiftLeftSkillOnUnitHold_6FC83D40(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x07_ShiftLeftSkillOnUnit_6FC83890(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0C_RightSkill_6FC83EF0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    sub_6FC83340(pGame, pUnit, UNITS_GetRightSkill(pUnit), nX, nY);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0D_RightSkillOnUnit_6FC83F80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetRightSkill(pUnit), nUnitType, nUnitGUID, 1);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0E_ShiftRightSkillOnUnit_6FC84100(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetRightSkill(pUnit), nUnitType, nUnitGUID, 0);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0F_RightSkillHold_6FC84280(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x0C_RightSkill_6FC83EF0(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x10_RightSkillOnUnitHold_6FC84330(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x0D_RightSkillOnUnit_6FC83F80(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x11_ShiftRightSkillOnUnitHold_6FC844D0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x0E_ShiftRightSkillOnUnit_6FC84100(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1A_EquipItem_6FC85280(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const unsigned char nBodyLoc = *((unsigned char*)pPacket + 5);
    if (nSize != 9)
    {
        return 3;
    }

    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    int nItemStatus = 0;
    if (ITEMMODE_EquipCursorItem(pGame, pUnit, nItemGUID, nBodyLoc, 0, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    return 3;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x20_UseGridItem_6FC85990(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nX = *(int*)((char*)pPacket + 5);
    const int nY = *(int*)((char*)pPacket + 9);
    if (nSize != 13)
    {
        return 3;
    }

    int nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = sub_6FC83C60(nX, nY, pUnit, 50);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_UseStoredItemAtCoordinates(pGame, pUnit, nItemGUID, nX, nY, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    return 3;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x27_UseItemAction_6FC85B50(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nTargetItemGUID = *(int*)((char*)pPacket + 1);
    const int nUseItemGUID = *(int*)((char*)pPacket + 5);
    int nResult = sub_00549220_CheckOwnedItem(nTargetItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = sub_00549220_CheckOwnedItem(nUseItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_UseItemOnItem(pGame, pUnit, nTargetItemGUID, nUseItemGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x21_StackItems_6FC85C80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID1 = *(int*)((char*)pPacket + 1);
    const int nItemGUID2 = *(int*)((char*)pPacket + 5);
    int nResult = sub_00549220_CheckOwnedItem(nItemGUID1, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = sub_00549220_CheckOwnedItem(nItemGUID2, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    if (nItemGUID1 == nItemGUID2)
    {
        return 3;
    }

    int nItemStatus;
    if (ITEMMODE_MergeItemStacks(pGame, pUnit, nItemGUID1, nItemGUID2, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x22_UnstackItems_6FC85DA0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nResult = sub_00549220_CheckOwnedItem(nItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus;
    if (D2GAME_Return0_6FC48930(pGame, pUnit, nItemGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x26_UseBeltItem_6FC86150(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int bUseOnMerc = *(int*)((char*)pPacket + 5);
    const int nX = PLRMSG_GetUnitX(pUnit);
    const int nY = PLRMSG_GetUnitY(pUnit);
    int nResult = pGame->sub_005492F0_CheckBeltItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = sub_6FC83C60(nX, nY, pUnit, 50);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_UseBeltItem(pGame, pUnit, nItemGUID, nX, nY, &nItemStatus, bUseOnMerc) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x29_ScrollToBook_6FC86450(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nScrollGUID = *(int*)((char*)pPacket + 1);
    const int nBookGUID = *(int*)((char*)pPacket + 5);
    int nResult = sub_6FC86520(nScrollGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nBookGUID);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_AddScrollToBook(pGame, pUnit, nScrollGUID, nBookGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2A_ItemToCubeIndirect_6FC866E0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nCubeGUID = *(int*)((char*)pPacket + 5);
    int nResult = sub_6FC86520(nItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nCubeGUID);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_PlaceItemInCube(pGame, pUnit, nItemGUID, nCubeGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

static int __stdcall sub_00549410_GetInteractNpc(int bCheckRange, D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc** ppNpc, int nNpcGUID)
{
    *ppNpc = SUNIT_GetServerUnit(pGame, 1, nNpcGUID);
    if (!*ppNpc)
    {
        return 1;
    }

    if (!PLRMSG_GetMonInteract(*ppNpc))
    {
        return 3;
    }

    const int nResult = sub_6FC83D00(pUnit, *ppNpc);
    if (nResult)
    {
        return nResult;
    }

    if (bCheckRange)
    {
        const int nX = CLIENTS_GetUnitX(*ppNpc);
        const int nRange = sub_6FC83C60(nX, CLIENTS_GetUnitY(*ppNpc), pUnit, 10);
        if (nRange)
        {
            return nRange;
        }
    }

    return 0;
}

// 0x0054B930
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2F_InitEntityChat_6FC868C0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    D2UnitStrc* pNpc;
    const int nResult = sub_00549410_GetInteractNpc(1, pGame, pUnit, &pNpc, *(int*)((char*)pPacket + 5));
    if (!nResult)
    {
        MONSTERAI_ActivateNpcInteraction(pGame, pUnit, pNpc, PLRMSG_GetMonInteract(pNpc));
        return 0;
    }

    return nResult;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x30_TerminateEntityChat_6FC869F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    D2UnitStrc* pNpc;
    const int nResult = sub_00549410_GetInteractNpc(0, pGame, pUnit, &pNpc, *(int*)((char*)pPacket + 5));
    if (nResult)
    {
        return nResult;
    }

    MONSTERAI_EndNpcInteraction(pGame, pUnit, pNpc, PLRMSG_GetMonInteract(pNpc));
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x38_EntityAction_6FC86CB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nAction = *(int*)((char*)pPacket + 1);
    const int nNpcGUID = *(int*)((char*)pPacket + 5);
    const int nItemGUID = *(int*)((char*)pPacket + 9);
    const int nResult = sub_00548F80_CheckTargetUnit(50, pGame, pUnit, 1, nNpcGUID);
    if (nResult)
    {
        return nResult;
    }

    return NPC_HandleDialogMessage(pGame, pUnit, nAction, nNpcGUID, nItemGUID);
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3D_HighlightADoor_6FC870F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nObjectGUID = *(int*)((char*)pPacket + 1);
    const int nResult = sub_00548F80_CheckTargetUnit(10, pGame, pUnit, 2, nObjectGUID);
    if (nResult)
    {
        return nResult;
    }

    OBJMODE_UpdateDoorModeFromCollision(pGame, pUnit, nObjectGUID);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3E_ActivateInifussScroll_6FC87270(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (!ITEMS_IsInPlayersInventory(pUnit, pItem, 0))
    {
        const unsigned char nUnitAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
        if (nUnitAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pItem))))
        {
            return 2;
        }

        const int nResult = sub_6FC83C60(PLRMSG_GetUnitX(pItem), PLRMSG_GetUnitY(pItem), pUnit, 10);
        if (nResult)
        {
            return nResult;
        }
    }

    QUESTS_UseClueItem(pGame, pUnit, nItemGUID);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x44_StaffInOrifice_6FC87780(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    const int nObjectGUID = *(int*)((char*)pPacket + 5);
    const int nItemGUID = *(int*)((char*)pPacket + 9);
    const unsigned short nState = *(unsigned short*)((char*)pPacket + 13);
    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 3;
    }

    const int nResult = sub_00549520_CheckOrificeObject(nItemGUID, nState, pGame, pUnit, nObjectGUID);
    if (!nResult)
    {
        OBJMODE_MainObeliskHandler(pGame, !pUnit ? -1 : pUnit->dwUnitId, nObjectGUID, nItemGUID, nState);
    }

    return nResult;
}

// build: context D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp_6FC87E60
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp_6FC87E60(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nWaypointGUID = *(int*)((char*)pPacket + 1);
    const unsigned short nLevelId = *(unsigned short*)((char*)pPacket + 5);
    const unsigned int nTick = PLAYERLIST_GetHostileDelay(pUnit, 0) + 10000;
    if (nTick > GetTickCount())
    {
        SUNIT_AttachSound(pUnit, 19, pUnit);
        SUNIT_ResetInteractInfo(pUnit);
        return 1;
    }

    const int nResult = sub_00549570_CheckWaypointObject(pUnit, pGame, nWaypointGUID, nLevelId);
    if (nResult)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
        D2UnitStrc* pWaypoint = SUNIT_GetServerUnit(pGame, 2, nWaypointGUID);
        if (pWaypoint && pWaypoint == pInteractUnit)
        {
            SUNIT_ResetInteractInfo(pUnit);
        }

        return nResult;
    }

    sub_00584F60(pGame, pUnit, nWaypointGUID, nLevelId);
    return 0;
}
