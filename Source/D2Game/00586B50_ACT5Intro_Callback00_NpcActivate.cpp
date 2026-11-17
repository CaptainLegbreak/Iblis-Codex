struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2TextHeaderStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2QuestDataStrc;
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char unk0x1C[0xC4];
    int nQuestFilter;
    void* pfStatusFilter;
    void* pfActiveFilter;
    void* pfQuestFilterEC;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    D2TextHeaderStrc* pTextControl;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    void* pObjectregion;
    int nObjectIdx;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[2];
};

struct D2MissilesTxt
{
    char unk0x00[0x96];
    short wRange;
    char unk0x98[0x10C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x3C];
    int nPlayerGUID;
    char unk0x40[0x10];
    unsigned char unk0x50;
    unsigned char pad0x51[0x03];
    int nCainGibbetObjectMode;
};

struct D2Act1Quest5Strc
{
    int nUnitGUIDs1[12];
    unsigned short nUnitCount1;
    unsigned char pad0x32[2];
    int nUnitGUIDs2[12];
    unsigned short nUnitCount2;
};

struct D2Act2Quest0Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
};

struct D2Act2Quest1Strc
{
    char unk0x00[0x04];
    D2ActiveRoomStrc* pRoom;
};

struct D2Act2Quest6Strc
{
    char unk0x00[0x03];
    unsigned char bTimerActive;
    char unk0x04[0x09];
    unsigned char bObjectsNeedUpdate;
    unsigned char bStaffItemsRemoved;
};

struct D2Act3Quest5Strc
{
    char unk0x00[0x0C];
    unsigned char bOrbSmashed;
    char unk0x0D[0x1F];
    int nCompellingOrbGUID;
    char unk0x30[0x08];
    int nHits;
};

struct D2Act5Quest2Strc
{
    char unk0x00[0xEC];
    int nPortalGUIDs[3];
    unsigned char bPortalSpawned[3];
    unsigned char pad0xFB;
    int nPortalUpdateInvocations[3];
    unsigned char unk0x108[3];
    unsigned char bChangeToSpecialObjectMode[3];
    unsigned char unk0x10E[6];
    int unk0x114[3];
};

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);
typedef int (__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode);                      // 0x00544160
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer);   // 0x00543520
int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545290
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005455B0
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                      // 0x00545760
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId);                // 0x005723C0
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);           // 0x00587FC0
void __fastcall ACT1Q4_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);   // 0x005930B0
void __fastcall sub_005940A0_ACT1Q4_RemovePlayerGUID(D2GameStrc* pGame, D2UnitStrc* pPlayer);               // 0x005940A0
void __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);   // 0x00598D40
bool __fastcall ACT2Q6_Timer_UpdateObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);                 // 0x0059D870
void __fastcall ACT2Q6_UnitIterate_DeleteHoradricItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x0059DBD0
void __fastcall ACT3Q5_UnitIterate_DeleteKhalimItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);    // 0x005BB850
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall QUESTSFX_SpawnCompellingOrbMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x005DFEE0
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                            // 0x0063BEF0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet);                              // 0x0061AED0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    D2MissilesTxt* pRecord;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        pRecord = 0;
    }
    else
    {
        pRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return pRecord;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00586B50
void __fastcall ACT5Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass1 = 7;
    int nSpecialIntroClass2 = 7;
    switch (nNpcId)
    {
    case 513:
        nSpecialIntroClass1 = 4;
        nSpecialIntroClass2 = 1;
        break;
    case 514:
        nSpecialIntroClass1 = 6;
        nSpecialIntroClass2 = 2;
        break;
    case 515:
        nSpecialIntroClass1 = 5;
        nSpecialIntroClass2 = 3;
        break;
    case 512:
    case 520:
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialIntroClass1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else if (nPlayerClass == nSpecialIntroClass2)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x00588880
void __fastcall ACT5Q2_UpdateWussieCounters(D2GameStrc* pGame, int nUnused, D2UnitStrc* pWussie)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 32);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }

    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    int nIndex = sub_00587FC0_GetWussieGroupIndex(pQuestData, pWussie);
    if (nIndex >= 0)
    {
        pQuestDataEx->unk0x114[nIndex] += 1;
        if (pQuestDataEx->unk0x114[nIndex] >= 5)
        {
            pQuestDataEx->unk0x108[nIndex] = 1;
        }
    }
}

// 0x00588D60
int __fastcall ACT5Q2_FindPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc** ppPortal)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 32);
    if (pQuestData)
    {
        D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
        int nIndex = sub_00587FC0_GetWussieGroupIndex(pQuestData, pUnit);
        if (nIndex >= 0 && pQuestDataEx->bPortalSpawned[nIndex])
        {
            D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nPortalGUIDs[nIndex]);
            if (pPortal)
            {
                *ppPortal = pPortal;
                return 1;
            }
        }
    }

    return 0;
}

// 0x0058F8F0
void __fastcall ACT1Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialClass;
    switch (nNpcId)
    {
    case 150:
        nSpecialClass = 0;
        break;
    case 147:
        nSpecialClass = 2;
        break;
    case 154:
        nSpecialClass = 4;
        break;
    case 148:
        nSpecialClass = 1;
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialClass)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x00593480
int __fastcall OBJECTS_OperateFunction10_CainGibbet(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 4);
    D2Act1Quest4Strc* pQuestDataEx = 0;
    if (pQuestData)
    {
        pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestData->bNotIntro || pQuestDataEx->unk0x50 == 1 || pQuestData->fState >= 6)
        {
            return 0;
        }
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) || QUESTRECORD_GetQuestState(pQuestFlags, 4, 0))
    {
        SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        return 0;
    }

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);

    if (pOp->pObject && pOp->pObject->dwAnimMode != 0)
    {
        return 0;
    }

    UNITS_ChangeAnimMode(pOp->pObject, 1);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);

    if (pQuestDataEx)
    {
        pQuestDataEx->nCainGibbetObjectMode = 3;
        pQuestDataEx->nPlayerGUID = !pOp->pPlayer ? -1 : pOp->pPlayer->dwUnitId;
    }

    EVENT_SetEvent(pOp->pGame, pOp->pObject, 7, pOp->pGame->dwGameFrame + 17, 0, 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->pObject), 0);

    QUESTRECORD_SetQuestState(pQuestFlags, 4, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 4, 1);

    QUESTS_UpdatePlayerFlags(pOp->pGame, pOp->pPlayer);

    const unsigned short nPartyId = SUNIT_GetPartyId(pOp->pPlayer);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pOp->pGame, nPartyId, ACT1Q4_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x005952C0
bool __fastcall ACT1Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuest->pQuestDataEx;
    int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;

    for (int i = 0; i < pQuestDataEx->nUnitCount2; ++i)
    {
        if (pQuestDataEx->nUnitGUIDs2[i] == nUnitId)
        {
            if (nNpcId == 155 || nNpcId == 147)
            {
                return false;
            }

            return true;
        }
    }

    return false;
}

// 0x005984C0
void __fastcall ACT2Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass = 7;
    switch (nNpcId)
    {
    case 199:
        nSpecialIntroClass = 2;
        break;
    case 200:
        nSpecialIntroClass = 4;
        break;
    case 210:
        nSpecialIntroClass = 0;
        break;
    case 178:
        nSpecialIntroClass = 3;
        break;
    case 177:
        nSpecialIntroClass = 1;
        break;
    case 175:
    case 198:
    case 202:
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialIntroClass)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x005986B0
void __fastcall ACT2Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (nNpcId == 201)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 8, 0))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 201, 0);
        }
    }
    else if (nNpcId == 244)
    {
        D2Act2Quest0Strc* pQuestDataEx = (D2Act2Quest0Strc*)pQuestData->pQuestDataEx;
        if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 14) != 1)
        {
            return;
        }

        const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->tPlayerGUIDs, nUnitId))
        {
            return;
        }

        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 244, 1);
        sub_005940A0_ACT1Q4_RemovePlayerGUID(pQuestData->pGame, pQuestArg->pPlayer);
    }
}

// 0x00598E20
int __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 8);
    D2_ASSERT(pQuestData, 390);

    D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)pQuestData->pQuestDataEx;
    int bInRange = 0;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom, 405);

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pUnitRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pQuestDataEx->pRoom)
            {
                bInRange = 1;
                break;
            }
        }
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0))
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1))
    {
        return 0;
    }

    if (!bInRange)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 9, 5);
    QUESTS_UpdatePlayerFlags(pQuestData->pGame, pUnit);

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q1_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x0059DD80
void __fastcall ACT2Q6_DeleteAllHoradricItemsAndOpenTomb(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_SetQuestState(pQuestFlags, 10, 0);
    pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_SetQuestState(pQuestFlags, 10, 13);

    QUESTS_DeleteItem(pGame, pUnit, ' tsh');
    QUESTS_DeleteItem(pGame, pUnit, ' piv');
    QUESTS_DeleteItem(pGame, pUnit, ' fsm');

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q6_UnitIterate_DeleteHoradricItems, 0);
    }

    QUESTS_TriggerFX(pGame, 3);

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(338);
    const int nTicks = (pMissilesTxtRecord->wRange - 75) / 20;

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bObjectsNeedUpdate = 1;
    pQuestDataEx->bStaffItemsRemoved = 1;
    if (!pQuestDataEx->bTimerActive)
    {
        QUESTS_CreateTimer(pQuestData, ACT2Q6_Timer_UpdateObjects, nTicks);
        pQuestDataEx->bTimerActive = 1;
    }

    UNITS_ChangeAnimMode(pObject, 1);

    D2ActiveRoomStrc* pObjectRoom = UNITS_GetRoom(pObject);
    D2_ASSERT(pObjectRoom, 1670);

    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(pObjectRoom, UNITS_GetUnitXPosition(pObject) - 13, UNITS_GetUnitYPosition(pObject) + 3);
    DUNGEON_ToggleHasPortalFlag(pObjectRoom, 0);
    if (pRoom)
    {
        DUNGEON_ToggleHasPortalFlag(pRoom, 0);
    }
}

// 0x005B6D30
void __fastcall ACT3Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass = 7;
    switch (nNpcId)
    {
    case 254:
        nSpecialIntroClass = 2;
        break;
    case 264:
        nSpecialIntroClass = 4;
        break;
    case 252:
        nSpecialIntroClass = 0;
        break;
    case 255:
        nSpecialIntroClass = 3;
        break;
    case 245:
    case 297:
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialIntroClass)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x005BB980
int __fastcall OBJECTS_OperateFunction53_CompellingOrb(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
    {
        D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pOp->pPlayer->pInventory);
        if (!pItem || ITEMS_GetBaseCode(pItem) != ' 2fq')
        {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        }
        else
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 19);
            D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;

            pQuestDataEx->nHits += 1;
            if (pQuestDataEx->nHits >= 2)
            {
                D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
                QUESTRECORD_SetQuestState(pQuestFlags, 18, 0);
                pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
                QUESTRECORD_SetQuestState(pQuestFlags, 18, 13);

                QUESTS_DeleteItem(pOp->pGame, pOp->pPlayer, ' 2fq');

                pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
                if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) && !QUESTRECORD_GetQuestState(sub_00543520(pOp->pGame, pOp->pPlayer), 21, 0))
                {
                    QUESTRECORD_SetQuestState(sub_00543520(pOp->pGame, pOp->pPlayer), 21, 0);
                }

                D2UnitStrc* pCompellingOrb = SUNIT_GetServerUnit(pOp->pGame, 1, pQuestDataEx->nCompellingOrbGUID);
                if (pCompellingOrb)
                {
                    AITACTICS_ChangeModeAndTargetCoordinates(pOp->pGame, pCompellingOrb, 0, 0, 0);
                    QUESTSFX_SpawnCompellingOrbMissile(pOp->pGame, pCompellingOrb);
                }

                UNITS_ChangeAnimMode(pOp->pObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->pObject ? -1 : pOp->pObject->dwClassId);
                EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);
                pQuestDataEx->bOrbSmashed = 1;

                QUESTS_TriggerFX(pQuestData->pGame, 10);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 851);
                pQuestData->pfSeqFilter(pQuestData);

                const unsigned short nPartyId = SUNIT_GetPartyId(pOp->pPlayer);
                if (nPartyId != 0xFFFF)
                {
                    PARTY_IteratePartyMembers(pOp->pGame, nPartyId, ACT3Q5_UnitIterate_DeleteKhalimItems, 0);
                }
            }
        }
    }

    return 0;
}
