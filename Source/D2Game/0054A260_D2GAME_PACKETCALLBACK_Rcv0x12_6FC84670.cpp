struct D2ClientStrc;
struct D2InventoryStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2DynamicPathStrc;
struct D2GSPacketSrv26;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
    char f_74[0x34];
    int dwGameFrame;

    int sub_005490E0_CheckCursorItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x005490E0
    int sub_005491B0_CheckStoredOrEquippedItem(D2UnitStrc* pUnit, int nItemGUID);                          // 0x005491B0
    int sub_005492F0_CheckBeltItem(D2UnitStrc* pUnit, int nItemGUID);                                      // 0x005492F0
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nFlags[4];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBA0];
    int nSkillsTxtRecordCount;
};

struct D2GSPacketClt15
{
    char unk0x00[0x103];
    char szName[16];
};

struct D2GSPacketSrv26Args
{
    D2GSPacketSrv26* pPacket26;
    D2GSPacketClt15* pPacket15;
    int nUnitId;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
int gbWhispReceiverNotListening_6FD4DC24;                                                                   // 0x008846E0
int gbWhispReceiverInGame_6FD4DC20;                                                                         // 0x008846E4
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
void __fastcall GAME_DisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType);            // 0x0052CAF0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
int __fastcall sub_6FC7C260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, unsigned int nValue);      // 0x00535510
int __fastcall sub_6FC7C3A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);                     // 0x00535610
int __fastcall sub_6FC7C450(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nHotkeyId, short nSkillId, int nHand, int nFlags); // 0x005356B0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, int nFlag);                                         // 0x00538670
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket); // 0x0053C750
int __fastcall ARENA_IsActive(D2GameStrc* pGame);                                                           // 0x0053FD10
int __fastcall ARENA_Return0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0053FDF0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall sub_6FC82010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode);   // 0x00548350
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pInteractUnitType, int* pInteractUnitGUID);     // 0x00554100
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag);                 // 0x0055B300
int __fastcall sub_6FC48D50(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nBeltItemGUID, int* a5); // 0x0055EB30
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall sub_6FC45B30(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nBodyLoc, int bSetQuantityFlag, int* a5); // 0x00560CD0
int __fastcall sub_00560F00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* a6); // 0x00560F00
int __fastcall sub_6FC46840(D2GameStrc* pGame, D2UnitStrc* pUnit, int* a3);                                 // 0x005616A0
int __fastcall sub_6FC48B40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4);                  // 0x00562250
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660
void __fastcall sub_6FC44030(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID);                          // 0x00563C00
int __fastcall sub_6FC93740(D2GameStrc* pGame, D2UnitStrc* pUnit);                                          // 0x00567840
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);       // 0x005678A0
void __fastcall sub_6FD11AE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                      // 0x0056C6A0
void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit);                                    // 0x0056DFA0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);           // 0x005701B0
int __fastcall PLAYERSTATS_SpendStatPoint(D2UnitStrc* pUnit, int nStatId);                                  // 0x00570D60
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue);             // 0x0058EC00
int __fastcall PARTYSCREEN_CommandHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCommand, int nArg, int nArg2); // 0x005A6000
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);                                          // 0x0061AB70
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                            // 0x00625DB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                       // 0x00641530
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define PLRMODE_WALK 2
#define PLRMODE_RUN 3
#define PLRMODE_DEAD 17
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STAT_GOLDLOST 0xAF
#define STATE_INFERNO 12
#define STATE_UNINTERRUPTABLE 0x36
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5
#define BODYLOC_BELT 8
#define EVENTTYPE_AITHINK 2
#define EVENTTYPE_PLAYERLEFT 3
#define CLIENTSAVEFLAG_HARDCORE 4
#define UNITFLAG_TARGETABLE 2
#define UNITFLAGEX_TELEPORTED 0x10000
#define MONSTATSFLAGINDEX_NPC 8
#define MONSTATSFLAGINDEX_INTERACT 9

inline int PLRMSG_IsBodyLocValid(int nBodyLoc)
{
    return nBodyLoc > 0 && nBodyLoc < 11;
}

// 0x0054A260
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x12_6FC84670(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    return 0;
}

// 0x0054A510
void __fastcall D2GAME_PACKETS_HandleWhisper_6FC848A0(D2ClientStrc* pClient, void* pArgs)
{
    D2GSPacketSrv26Args* pPacket26Args = (D2GSPacketSrv26Args*)pArgs;
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    D2GSPacketSrv26* pPacket26 = pPacket26Args->pPacket26;
    const char* szClientName = CLIENTS_GetName(pClient);
    if (!SStrCmpI(szClientName, pPacket26Args->pPacket15->szName, 0x7FFFFFFF))
    {
        const int nUnitGUID = pPacket26Args->nUnitId;
        if (nUnitGUID != -1)
        {
            D2UnitStrc* pReceiver = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nUnitGUID);
            D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
            if (pReceiver && pLocalPlayer)
            {
                if (PLAYERLIST_CheckFlag(pLocalPlayer, pReceiver, 4))
                {
                    gbWhispReceiverNotListening_6FD4DC24 = 1;
                    return;
                }

                if (PLAYERLIST_CheckFlag(pReceiver, pLocalPlayer, 2))
                {
                    gbWhispReceiverNotListening_6FD4DC24 = 1;
                    return;
                }
            }
        }

        gbWhispReceiverInGame_6FD4DC20 = 1;
        D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, pPacket26);
    }
}

// 0x0054AB40
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x17_DropItemOnGround_6FC84E20(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 0))
    {
        return 3;
    }

    sub_6FC44030(pGame, pUnit, nItemGUID);
    return 0;
}

// 0x0054ABB0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x18_InsertItemInBuffer_6FC84ED0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nX = *(int*)((char*)pPacket + 5);
    const int nY = *(int*)((char*)pPacket + 9);
    const unsigned int nInvPage = *(unsigned int*)((char*)pPacket + 13);
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (!PLAYER_IsBusy(pUnit) && nInvPage)
        {
            return 2;
        }

        if (nInvPage == 4)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
            {
                return 3;
            }
        }
        else
        {
            if (nInvPage != 3 && nInvPage != 2 && nInvPage != 0)
            {
                return 2;
            }

            if (nInvPage == 2 && !D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
            {
                return 3;
            }
        }
    }
    else if (nInvPage >= 5)
    {
        return 2;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (pItem)
    {
        ITEMS_SetInvPage(pItem, nInvPage);
        return D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrMsg.cpp", 3062, pGame, pUnit, nItemGUID, nX, nY, 0, 1, 0) ? 0 : 3;
    }

    return 2;
}

// 0x0054AEC0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1C_RemoveBodyItem_6FC854B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    const int nBodyLoc = *(unsigned short*)((char*)pPacket + 1);
    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc);
    if (sub_6FC7C3A0(pGame, pUnit, pItem) && (nBodyLoc != BODYLOC_BELT || sub_6FC93740(pGame, pUnit)))
    {
        int a5 = 0;
        if (!sub_6FC45B30(pGame, pUnit, nBodyLoc, 0, &a5) && a5)
        {
            return 3;
        }
    }

    return 0;
}

// 0x0054AF50
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1D_SwapCursorItemWithBody_6FC85550(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const unsigned char nBodyLoc = *((unsigned char*)pPacket + 5);
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    if (!INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc))
    {
        return 1;
    }

    if (nBodyLoc == BODYLOC_BELT && !sub_6FC93740(pGame, pUnit))
    {
        return 0;
    }

    if (!sub_6FC7C3A0(pGame, pUnit, INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc)))
    {
        return 0;
    }

    int a5 = 0;
    if (sub_00560F00(pGame, pUnit, nItemGUID, nBodyLoc, 0, &a5) || !a5)
    {
        return 0;
    }

    return 3;
}

// 0x0054B450
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x24_ItemFromBelt_6FC85F50(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nResult = pGame->sub_005492F0_CheckBeltItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!sub_6FC7C3A0(pGame, pUnit, 0))
    {
        return 0;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return 2;
    }

    int a5 = 0;
    if (sub_6FC48B40(pGame, pUnit, nItemGUID, &a5) || !a5)
    {
        return 0;
    }

    return 3;
}

// 0x0054B4E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x25_SwitchBeltItem_6FC86040(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nCursorItemGUID = *(int*)((char*)pPacket + 1);
    const int nBeltItemGUID = *(int*)((char*)pPacket + 5);
    int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nCursorItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = pGame->sub_005492F0_CheckBeltItem(pUnit, nBeltItemGUID);
    if (nResult)
    {
        return nResult;
    }

    int a5 = 0;
    if (sub_6FC48D50(pGame, pUnit, nCursorItemGUID, nBeltItemGUID, &a5) || !a5)
    {
        return 0;
    }

    return 3;
}

// 0x0054B650
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x28_SocketItem_6FC86310(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nCursorItemGUID = *(int*)((char*)pPacket + 1);
    const int nSocketableItemGUID = *(int*)((char*)pPacket + 5);
    int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nCursorItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = pGame->sub_005491B0_CheckStoredOrEquippedItem(pUnit, nSocketableItemGUID);
    if (nResult)
    {
        return nResult;
    }

    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        if (pInteractUnit && pInteractUnit->dwUnitType == UNIT_PLAYER)
        {
            return 0;
        }
    }

    int bPlaced = 0;
    if (D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pUnit, nCursorItemGUID, nSocketableItemGUID, &bPlaced, 1, 1, 1, 1) || !bPlaced)
    {
        return 0;
    }

    return 3;
}

// 0x0054BD10
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3A_AddStatPoint_6FC86E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    const unsigned short nValue = *(unsigned short*)((char*)pPacket + 1);
    int nCount = (nValue >> 8) + 1;
    const int nStatId = nValue & 0xFF;
    if (nStatId <= -1 || nStatId >= 16 || nCount < 1 || nCount > 100)
    {
        return 3;
    }

    while (nCount)
    {
        --nCount;
        if (!PLAYERSTATS_SpendStatPoint(pUnit, nStatId))
        {
            return 2;
        }
    }

    return 0;
}

// 0x0054C0E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x41_Resurrect_6FC87480(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (!pUnit || pUnit->dwAnimMode != PLRMODE_DEAD)
    {
        return 0;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 4579);
    if (CLIENTS_CheckFlag(pClient, CLIENTSAVEFLAG_HARDCORE))
    {
        GAME_DisconnectClient(pGame, pClient, EVENTTYPE_PLAYERLEFT);
        return 0;
    }

    const int n0 = ARENA_Return0(pGame, pUnit);
    D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);

    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxLife, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_HITPOINTS, nMaxLife, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_MANA, nMaxMana, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_STAMINA, nMaxStamina, pUnit);

    pUnit->dwFlags |= UNITFLAG_TARGETABLE;

    STATES_ToggleState(pUnit, STATE_UNINTERRUPTABLE, 1);
    STATES_ToggleState(pUnit, STATE_UNINTERRUPTABLE, 0);

    DRLG_GetActNoFromLevelId(0);
    const unsigned char nSourceAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nSourceAct);
    LEVEL_WarpUnit(pGame, pUnit, nTownLevelId, n0);

    sub_6FC817D0(pGame, pUnit, 0, 1, 0, 0, 1);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        D2GAME_AssignSkill_6FD13800(pUnit, 1, SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\PLAYER\\PlrMsg.cpp", 4617), SKILLS_GetOwnerGUIDFromSkill(pLeftSkill));
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\PLAYER\\PlrMsg.cpp", 4622), SKILLS_GetOwnerGUIDFromSkill(pRightSkill));
    }

    return 0;
}

// 0x0054C2A0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x5D_SquelchHostile_6FC876B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 7)
    {
        return 3;
    }

    if (ARENA_IsActive(pGame))
    {
        return 3;
    }

    const unsigned char nCommand = *((unsigned char*)pPacket + 1);
    const int nArg = *(int*)((char*)pPacket + 3);
    if (nCommand > 10)
    {
        return 2;
    }

    return PARTYSCREEN_CommandHandler(pGame, pUnit, nCommand, nArg, *((unsigned char*)pPacket + 2));
}

// 0x0054C300
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x5E_InviteToParty_6FC87720(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 6)
    {
        return 3;
    }

    if (ARENA_IsActive(pGame))
    {
        return 3;
    }

    const unsigned char nCommand = *((unsigned char*)pPacket + 1);
    if (nCommand > 10)
    {
        return 2;
    }

    PARTYSCREEN_CommandHandler(pGame, pUnit, nCommand, *(int*)((char*)pPacket + 2), 0);
    return 0;
}

// 0x0054C760
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4C_Transmogrify_6FC88170(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem && nItemGUID != -1)
    {
        return 1;
    }

    sub_6FD11AE0(pGame, pUnit, pItem);
    return 0;
}

// 0x0054C800
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x50_DropGold_6FC88210(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nUnitGUID = *(int*)((char*)pPacket + 1);
    const int nGoldValue = *(int*)((char*)pPacket + 5);
    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 3;
    }

    return sub_6FC7C260(pGame, pUnit, nUnitGUID, nGoldValue) ? 0 : 3;
}

// 0x0054C870
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x51_BindHotkeyToSkill_6FC88290(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const unsigned int nValue = *(unsigned int*)((char*)pPacket + 1);
    const int nOwnerGUID = *(int*)((char*)pPacket + 5);
    const unsigned int nHotKeyId = nValue >> 16;
    if (nHotKeyId <= 15)
    {
        int nSkillId = nValue & 0x7FFF;
        if (nSkillId > sgptDataTables->nSkillsTxtRecordCount)
        {
            nSkillId = -1;
        }
        else if (nSkillId != -1)
        {
            if (nSkillId < 0)
            {
                return 3;
            }

            if (nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
            {
                return 3;
            }

            if (!SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID))
            {
                return 3;
            }
        }

        return sub_6FC7C450(pGame, pUnit, nHotKeyId, nSkillId, (nValue >> 15) & 1, nOwnerGUID) ? 0 : 3;
    }

    return 3;
}

// 0x0054C940
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x53_TurnStaminaOn_6FC88340(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == PLRMODE_WALK)
    {
        if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0))
        {
            UNITS_ChangeAnimMode(pUnit, PLRMODE_RUN);
        }
    }

    return 0;
}

// 0x0054CA10
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x59_MakeEntityMove_6FC88400(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    const int v8 = *(int*)((char*)pPacket + 9);
    const int a3 = *(int*)((char*)pPacket + 13);
    if (nUnitType >= 6)
    {
        return 2;
    }

    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (pNpc && D2Common_10399(pUnit, pNpc) <= 50)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pNpc->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_INTERACT & 7] && pMonStatsTxtRecord->nFlags[MONSTATSFLAGINDEX_NPC >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NPC & 7])
        {
            if (pNpc->pDynamicPath)
            {
                D2Common_10153(pNpc->pDynamicPath);
            }

            D2GAME_EVENTS_Delete_6FC34840(pGame, pNpc, EVENTTYPE_AITHINK, 0);
            EVENT_SetEvent(pGame, pNpc, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
            AIGENERAL_SetAiControlParam(pNpc, 1, 40);
            AIGENERAL_SetAiControlParam(pNpc, 2, v8);
            AIGENERAL_SetAiControlParam(pNpc, 3, a3);
            return 0;
        }
    }

    return 1;
}

// 0x0054CE70
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x60_SwapWeapons_6FC888A0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (UNITS_GetUsedSkill(pUnit) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    int a3 = 0;
    if (sub_6FC46840(pGame, pUnit, &a3) || !a3)
    {
        return 0;
    }

    return 3;
}

// 0x0054DA10
void __fastcall sub_6FC820C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    sub_6FC82010(pGame, pUnit, pClient, nAnimMode);

    if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0))
    {
        const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_GOLDLOST, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_GOLDLOST, nValue, pUnit);
    }
}
