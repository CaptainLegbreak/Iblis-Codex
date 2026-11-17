#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define MONSTER_HRATLI 253
#define MONSTER_ASHEARA 252
#define MONSTER_ORMUS 255
#define QUESTSTATEFLAG_A3Q3 19
struct D2PlayerDataStrc;
struct D2Act3Quest3Strc;
struct D2ObjInitFnStrc;
struct D2ObjOperateFnStrc;
struct D2ItemsTxt;
struct D2QuestGUIDStrc;

typedef int (__stdcall* FARPROC)();

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
    char unk0xAC[0x10];
    void* pAct[5];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xD4];
    D2UnitStrc* pRoomNext;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

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
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        int nOldLevel;
        unsigned short nNPCNo;
    };
    union
    {
        int nNewLevel;
        unsigned short nMessageIndex;
    };
};

struct D2Act3Quest3Strc
{
    unsigned char bGidbinnDropped;
    unsigned char bHratliActivated;
    unsigned char bBossHasSpawned;
    unsigned char bGidbinnObjectActivated;
    unsigned char bBossIsSpawning;
    unsigned char bSpawnTimerStarted;
    unsigned char unk0x06;
    unsigned char bGidbinnBroughtToOrmus;
    int nGidbinnX;
    int nGidbinnY;
    int nAltarX;
    int nAltarY;
    unsigned char bGidbinnObjectInitialized;
    char unk0x19[0x03];
    int nGidbinnsInGame;
    unsigned char bPlayerWithGidbinnDropped;
    char unk0x21[0x03];
    int nFetishBossGUID;
    int nAltarGUID;
    int nAltarObjectMode;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;

    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    int unk0x0C[2];
    int nX;
    int nY;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;

    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    void* pObjectregion;
    int nObjectIdx;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct3Q3NpcMessages[]; // 0x0073FB98
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
D2UnitStrc* __fastcall sub_005A43E0_QUESTS_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int nMonsterId, int a5, int a6, int a7, int a8); // 0x005A43E0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(void* pAct, int a2, int a3); // 0x00619DA0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
int __fastcall ACT3Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B8B20
int __fastcall ACT3Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B8BF0
void __fastcall ACT3Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8C50
bool __fastcall ACT3Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B8CC0
bool __fastcall ACT3Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B8E10
void __fastcall ACT3Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8EC0
void __fastcall ACT3Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B9240
void __fastcall ACT3Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B9700
void __fastcall ACT3Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B9980

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __fastcall ACT3Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B9130
void __fastcall ACT3Q3_UnitIterate_SetGidbinnBroughtBackQuestState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B91B0

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B9090
void __fastcall ACT3Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    if (pQuestArg->nNewLevel == 78 && pQuestData->bNotIntro && !pQuestData->fState)
    {
        pQuestData->fState = 1;
    }

    if (nOldLevel != 75)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);

    if (pQuestData->fState == 2)
    {
        D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 15) != 1)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 482);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
        }
    }
    else if (pQuestData->fState == 5)
    {
        pQuestData->bActive = 0;
    }
}

// 0x005B9130
int __fastcall ACT3Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 0)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 19, 6)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 19, 8)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 19, 7)
        && !ITEMS_FindQuestItem(pGame, pUnit, ' 33g'))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 14);
    }

    return 0;
}

// 0x005B91B0
void __fastcall ACT3Q3_UnitIterate_SetGidbinnBroughtBackQuestState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!QUESTS_GetQuestData(pGame, 17))
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, 19, 6)
        || QUESTRECORD_GetQuestState(pQuestFlags, 19, 8)
        || QUESTRECORD_GetQuestState(pQuestFlags, 19, 7))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 6);
    }
}

// 0x005B9520
void __fastcall ACT3Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "ginbinn acquired", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 693);

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId);
    if (pQuestData->bNotIntro && pItemsTxtRecord->dwCode == ' 33g')
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q3_UnitIterate_StatusCyclerEx, 1);

        D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 9))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 9);
            SUNIT_AttachSound(pQuestArg->pPlayer, 65, pQuestArg->pPlayer);
        }

        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 710);
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q3_UnitIterate_StatusCyclerEx, 1);
    }

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
}

// 0x005B9610
bool __fastcall ACT3Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            pQuestData->fState = 1;
        }
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 732);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005B9680
void __fastcall ACT3Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g'))
    {
        ++pQuestDataEx->nGidbinnsInGame;
    }

    if (pQuestDataEx->bPlayerWithGidbinnDropped && pQuestDataEx->nGidbinnsInGame == 1)
    {
        pQuestDataEx->bPlayerWithGidbinnDropped = 0;
    }
}

// 0x005B96C0
void __fastcall ACT3Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_GetBaseCode(pQuestArg->pTarget) != ' 33g')
    {
        return;
    }

    --pQuestDataEx->nGidbinnsInGame;
    if (!pQuestDataEx->nGidbinnsInGame && pQuestDataEx->bGidbinnDropped && pQuestData->bNotIntro && pQuestData->fState < 5)
    {
        pQuestDataEx->bPlayerWithGidbinnDropped = 1;
    }
}

// 0x005B9850
void __fastcall ACT3Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pNPCMessages = gpAct3Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->nQuestFilter = 19;
    pQuestData->pfActiveFilter = ACT3Q3_ActiveFilterCallback;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = ACT3Q3_StatusFilterCallback;
    pQuestData->pfSeqFilter = ACT3Q3_SeqCallback;
    pQuestData->nSeqId = 15;
    pQuestData->pfCallback[4] = ACT3Q3_Callback04_ItemPickedUp;
    pQuestData->pfCallback[0] = ACT3Q3_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT3Q3_Callback11_ScrollMessage;
    pQuestData->pfCallback[3] = ACT3Q3_Callback03_ChangedLevel;
    pQuestData->pfCallback[2] = ACT3Q3_Callback02_NpcDeactivate;
    pQuestData->pfCallback[13] = ACT3Q3_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[14] = ACT3Q3_Callback14_PlayerJoinedGame;
    pQuestData->pfCallback[9] = ACT3Q3_Callback09_PlayerDroppedWithQuestItem;

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 916, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest3Strc));
    pQuestDataEx->nAltarObjectMode = 0;
}

// 0x005B9D40
void __fastcall OBJECTS_InitFunction39_GidbinnAltar(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 17);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nAltarGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    pQuestDataEx->nAltarX = pOp->nX;
    pQuestDataEx->nAltarY = pOp->nY;

    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nAltarObjectMode);
}

#include "gen/data/Source/D2Game/Quests/a3q3.inc"

// 0x005B9240
void __fastcall ACT3Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNpcNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 0) == 1)
    {
        return;
    }

    if (nNpcNo == MONSTER_ORMUS)
    {
        if (nMessageIndex == 587)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g') && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 5) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8))
            {
                ((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bGidbinnBroughtToOrmus = 1;
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g');
                --((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->nGidbinnsInGame;
                QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 6);

                const unsigned short nPartyId = SUNIT_GetPartyId(pQuestArg->pPlayer);
                if (nPartyId != 0xFFFF)
                {
                    PARTY_IteratePartyMembers(pQuestData->pGame, nPartyId, ACT3Q3_UnitIterate_SetGidbinnBroughtBackQuestState, 0);
                }

                SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_SetCompletionFlag);
            }

            if (pQuestData->bNotIntro)
            {
                QUESTS_SetGlobalState(pQuestArg->pGame, QUESTSTATEFLAG_A3Q3, 13);
            }

            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q3_UnitIterate_StatusCyclerEx, 0);

            if (!pQuestData->bNotIntro || pQuestData->fState == 5)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 621);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 622);
            pQuestData->pfSeqFilter(pQuestData);
        }
        else if (nMessageIndex == 593 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 6) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8);

            int nItemLevel = 21;
            switch (pQuestArg->pGame->nDifficulty)
            {
            case 1:
                nItemLevel = 35;
                break;
            case 2:
                nItemLevel = 75;
                break;
            }

            QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' nir', nItemLevel, 6, 1);

            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 7))
            {
                return;
            }

            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 13);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 0);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        }
    }
    else if (nNpcNo == MONSTER_HRATLI)
    {
        if (nMessageIndex == 571)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 659);
            ((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bHratliActivated = 1;
        }
    }
    else if (nNpcNo == MONSTER_ASHEARA)
    {
        if (nMessageIndex != 589 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 7))
        {
            return;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 7);
        D2GAME_NPC_AssignMercenary_6FCCB520(pQuestData->pGame, pQuestArg->pPlayer, MONSTER_ASHEARA);

        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8))
        {
            return;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 13);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 0);
        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    }
}

// 0x005B9960
unsigned char __fastcall sub_005B9960_IsBossSpawning(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (pQuestData)
    {
        return ((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bBossIsSpawning;
    }
    return 0;
}

// 0x005B9C50
bool __fastcall sub_005B9C50_GetBossGUID(D2GameStrc* pGame, int* pGUID)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return false;
    }
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bBossHasSpawned)
    {
        return false;
    }
    *pGUID = pQuestDataEx->nFetishBossGUID;
    return true;
}

// 0x005B9C80
void __fastcall sub_005B9C80_ClearBossSpawned(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bBossHasSpawned == 1 && pQuestDataEx->nFetishBossGUID == (!pUnit ? -1 : pUnit->dwUnitId))
    {
        pQuestDataEx->bBossHasSpawned = 0;
    }
}
