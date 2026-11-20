#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

#define QUEST_A1Q4_CAIN 4
#define ACT_II 1
#define QUEST_A3Q7_DARKWANDERER 28
#define QUEST_A5Q5_ANCIENTS 35
#define ITEMQUAL_NORMAL 2
#define EVENTTYPE_QUESTFN 7
#define QUESTSTATEFLAG_A5Q6 40
#define QUESTSTATEFLAG_A4Q1 25
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM1 5
#define QFLAG_CUSTOM2 6
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8
#define QFLAG_CUSTOM6 10
#define MONSTER_CAIN4 246
#define MONSTER_TYRAEL2 367
#define MONSTER_IZUALGHOST 406
#define MONSTER_LARZUK 511
#define MONSTER_DREHYA 512
#define MONSTER_MALAH 513
#define MONSTER_CAIN6 520
#define MONSTER_TYRAEL3 521
#define MONSTER_ANCIENTSTATUE1 539
#define MONSTER_ANCIENTSTATUE3 541

union D2SeedStrc;
struct D2ObjInitFnStrc;
struct D2GSPacketSrv53;
struct D2GSPacketSrv5D;
struct D2QuestGUIDStrc;
struct D2Act1Quest4Strc;
struct D2Act3Quest7Strc;
struct D2Act4Quest3Strc;
struct D2Act5Quest5Strc;
struct D2Act5Quest6Strc;
struct D2Act2Quest2Strc;
struct D2Act2Quest3Strc;
struct D2PlayerDataStrc;

#pragma pack(push, 1)
struct D2GSPacketSrv53
{
    unsigned char nHeader;
    int nIndex;
    int nTicks;
    unsigned char bEclipse;
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

#pragma pack(pop)



typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);


struct D2Act1Quest4Strc
{
    char unk0x00[0x8C];
    int nGoldPilesToDropFromWirtsBody;
    unsigned char bWirtsBodyInitialized;
    char unk0x91[0x23];
    D2QuestGUIDStrc tPlayerGUIDs;
};

struct D2Act3Quest7Strc
{
    char unk0x00[0x0C];
    unsigned char bVileDogsSpawned;
    unsigned char bVileDogSpawnTimerCreated;
    unsigned char unk0x0E[2];
    int nDarkWandererGUID;
};

struct D2Act4Quest3Strc
{
    char unk0x00[0x1C];
    unsigned char bSoulstoneAcquired;
};

struct D2Act5Quest5Strc
{
    char unk0x00[0x44];
    int nAncientsAlive;
    unsigned char bAncientsActivated;
};

struct D2Act5Quest6Strc
{
    char unk0x00[0x90];
    unsigned char bQuestStarted;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0
void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket); // 0x0053C900
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710

typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
bool __fastcall sub_005BD390(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x005BD390
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int nItemType, int bIgnoreRarity); // 0x00559A30
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

struct D2Act2Quest2Strc
{
    int unused0x00[5];
    int nItemDropCount;
    int nBaseStaffs;
    int nCubedStaffs;
    int nHoradricCubes;
    int nAmulets;
};

struct D2Act2Quest3Strc
{
    unsigned char unused0x00;
    unsigned char bDarkenTimerCreated;
    unsigned char bRewarded;
    unsigned char bBlackened;
    unsigned char bAltarDestroyed;
    unsigned char bAltarInitialized;
    unsigned char unk0x06;
    unsigned char pad0x07;
    int nAltarMode;
    int nAltarGUID;
    D2ActiveRoomStrc* pRoom;
    D2QuestGUIDStrc tPlayerGUIDs;
    int nAltarLevelId;
    int unk0x9C;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
int __fastcall ACT2Q3_UnitIterate_SendPacket0x53ToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A170
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760


struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

enum
{
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUESTSTATEFLAG_A2Q3 = 11,
};

extern char gpAct2Q3NpcMessages[]; // 0x0073A188
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall ACT2Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00599FB0
bool __fastcall ACT2Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059A1C0
void __fastcall ACT2Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059A270
bool __fastcall sub_0059A480_SeqCallback(D2QuestDataStrc* pQuestData); // 0x0059A480
void __fastcall ACT2Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059A5D0
void __fastcall ACT2Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059EBE0
void __fastcall ACT2Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059EE00

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __fastcall ACT2Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00599F50
int __fastcall ACT2Q3_UnitIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A100
int __fastcall ACT2Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A4F0

// build: context ACT5Q6_ActiveFilterCallback
bool __fastcall ACT5Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId >= MONSTER_ANCIENTSTATUE1 && nNpcId <= MONSTER_ANCIENTSTATUE3)
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, QUEST_A5Q5_ANCIENTS);
        if (pQuestData)
        {
            D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
            if (pQuestDataEx->bAncientsActivated && !pQuestDataEx->nAncientsAlive && pQuest->fState == 1 && !((D2Act5Quest6Strc*)pQuest->pQuestDataEx)->bQuestStarted)
            {
                return true;
            }
        }
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))
    {
        return false;
    }

    switch (nNpcId)
    {
    case MONSTER_LARZUK:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_ENTERAREA))
        {
            return true;
        }
        break;

    case MONSTER_CAIN6:
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM6))
        {
            break;
        }
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM1))
        {
            return true;
        }
        break;

    case MONSTER_MALAH:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM2))
        {
            return true;
        }
        break;

    case MONSTER_TYRAEL3:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM3))
        {
            return true;
        }
        break;

    case MONSTER_QUAL_KEHK:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM4))
        {
            return true;
        }
        break;

    case MONSTER_DREHYA:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM5))
        {
            return true;
        }
        break;

    default:
        break;
    }

    return false;
}

// 0x005940A0
void __fastcall sub_005940A0_ACT1Q4_RemovePlayerGUID(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN)->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pPlayer ? -1 : pPlayer->dwUnitId);
}

// 0x00594630
void __fastcall sub_00594630_QuestGoldDrop(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bWirtsBodyInitialized)
    {
        pQuestDataEx->bWirtsBodyInitialized = 1;
        pQuestDataEx->nGoldPilesToDropFromWirtsBody = OBJECTS_RollRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame), 10, 20);
        pUnit->dwDropItemCode = ' dlg';
    }

    if (pQuestDataEx->nGoldPilesToDropFromWirtsBody)
    {
        int nItemLevel = 0;
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pUnit, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            --pQuestDataEx->nGoldPilesToDropFromWirtsBody;
            if (pQuestDataEx->nGoldPilesToDropFromWirtsBody > 0)
            {
                EVENT_SetEvent(pQuestData->pGame, pUnit, EVENTTYPE_QUESTFN, pQuestData->pGame->dwGameFrame + 10, 0, 0);
            }
        }
    }
}

// 0x0059A100
int __fastcall ACT2Q3_UnitIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 322);
    if (CLIENTS_GetActNo(pClient) == ACT_II)
    {
        D2GSPacketSrv53 packet53;
        packet53.nHeader = 0x53;
        packet53.nIndex = 5;
        packet53.nTicks = 0;
        packet53.bEclipse = 1;
        D2GAME_SendPacket0x53_6FC3DF50(pClient, &packet53);

        D2GSPacketSrv5D packet5D;
        memset(&packet5D, 0, sizeof(packet5D));
        packet5D.nHeader = 0x5D;
        packet5D.nQuestId = QUEST_A2Q3_TAINTEDSUN;
        packet5D.nFlags = 16;
        sub_6FC3F380(pClient, &packet5D);
    }

    return 0;
}

// 0x005B37F0
bool __fastcall ACT4Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int nId = nNpcId;
    if (pQuest->bNotIntro && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q1, QFLAG_REWARDGRANTED))
    {
        if (nId == MONSTER_TYRAEL2)
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q1, QFLAG_REWARDPENDING) == 1 || pQuest->fState == 1)
            {
                return true;
            }
        }
        else if (nId == MONSTER_IZUALGHOST)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q1, QFLAG_CUSTOM1))
            {
                return true;
            }
        }
    }

    return false;
}

// 0x005B5EE0
bool __fastcall ACT4Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int nId = nNpcId;
    if (nId == MONSTER_CAIN4 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING)
        && pQuest->bNotIntro && pQuest->fState == 1 && !((D2Act4Quest3Strc*)pQuest->pQuestDataEx)->bSoulstoneAcquired)
    {
        return true;
    }

    return false;
}

// 0x005BD4A0
void __fastcall ACT3Q7_CreateVileDogSpawnTimer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q7_DARKWANDERER);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bVileDogsSpawned || pQuestDataEx->bVileDogSpawnTimerCreated)
    {
        return;
    }

    pQuestDataEx->bVileDogSpawnTimerCreated = 1;
    pQuestDataEx->nDarkWandererGUID = !pUnit ? -1 : pUnit->dwUnitId;
    QUESTS_CreateTimer(pQuestData, sub_005BD390, 2);
}

// 0x005994F0
bool __fastcall sub_005994F0_ACT2Q1_IsDoneOrInactive(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 8);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return true;
    }
    return pQuestData->fState == 5 ? true : false;
}

// 0x00599A20
void __fastcall sub_00599A20_EmptyCallback(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
}

// 0x00599BD0
void __fastcall sub_00599BD0_ACT2Q2_AddAmulets(D2QuestDataStrc* pQuestData, int nCount)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 9);
    if (pQuest)
    {
        ((D2Act2Quest2Strc*)pQuest->pQuestDataEx)->nAmulets += nCount;
    }
}

// 0x00599BF0
int __fastcall sub_00599BF0_HasNoHoradricStaff(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return !ITEMS_FindQuestItem(pGame, pUnit, ' tsh');
}

// 0x00599EE0
void __fastcall sub_00599EE0_OBJECTS_InitFunction31(D2ObjInitFnStrc* pOp)
{
}

// 0x00599EF0
void __fastcall sub_00599EF0_OBJECTS_InitFunction33(D2ObjInitFnStrc* pOp)
{
}

// 0x00599F00
void __fastcall sub_00599F00_OBJECTS_InitFunction32(D2ObjInitFnStrc* pOp)
{
}

// 0x0059A3C0
static __forceinline void sub_0059A3C0_ACT2Q3_EndTaintedSun(D2QuestDataStrc* pQuestData, D2GameStrc* pGame)
{
    if (pGame->pAct[1])
    {
        ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bRewarded = 0;
        ENVIRONMENT_TaintedSunEnd(pGame->pAct[1]);
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q3_UnitIterate_SendPacket0x53ToClient);
    }
}

// 0x0059AC20
bool __fastcall sub_0059AC20_ACT2Q3_IsDoneOrInactive(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 10);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return true;
    }
    return pQuestData->fState >= 4 ? true : false;
}

// 0x0059AC40
void __fastcall sub_0059AC40(D2GameStrc* pGame, unsigned char nActNo)
{
    if (nActNo != 1)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 10);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bBlackened != 1)
    {
        return;
    }

    ENVIRONMENT_TaintedSunBegin(pGame->pAct[1]);
    pQuestDataEx->bBlackened = 0;
    pQuestDataEx->bRewarded = 1;
}

void __fastcall sub_M118_Emit_0059A3C0(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->bNotIntro)
    {
        sub_0059A3C0_ACT2Q3_EndTaintedSun(pQuestData, pQuestData->pGame);
        QUESTS_TriggerFX(pQuestData->pGame, 6);
    }
}

// 0x00599F50
int __fastcall ACT2Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A2Q3_TAINTEDSUN);
    }

    return 0;
}

// 0x00599FE0
int __fastcall ACT2Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 14);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A2Q3_TAINTEDSUN, 0);
    }

    return 0;
}

// 0x0059EEA0
void __fastcall ACT2Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT2Q3_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT2Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT2Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[10] = ACT2Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[13] = ACT2Q3_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct2Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 803, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q3;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT2Q3_ActiveFilterCallback;
    pQuestData->pfSeqFilter = sub_0059A480_SeqCallback;
    pQuestData->nSeqId = QUESTSTATEFLAG_A2Q3;
    memset(pQuestDataEx, 0x00, sizeof(D2Act2Quest3Strc));
    pQuestDataEx->nAltarMode = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

#include "gen/data/Source/D2Game/Quests/a2q3.inc"
struct D2GameStrc;
struct D2ItemDropStrc;
struct D2QuestDataStrc;
struct D2UnitStrc;

// 0x0059A350
static bool sub_0059A350_ApplyDarkness(D2QuestDataStrc* pQuestData)
{
    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 1);
    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x211);
    }

    D2GameStrc* pGame = pQuestData->pGame;
    if (pGame->pAct[1])
    {
        ENVIRONMENT_TaintedSunBegin(pGame->pAct[1]);
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q3_UnitIterate_UpdateClient);
        return true;
    }

    ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bBlackened = 1;
    return false;
}

// 0x0059A3F0
void __fastcall sub_0059A3F0(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bAltarInitialized = 1;
    pQuestDataEx->nAltarGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (pQuestData->bNotIntro == 1)
    {
        if (pQuestData->fState <= 1)
        {
            if (!sub_0059A350_ApplyDarkness(pQuestData))
            {
                pQuestDataEx->bBlackened = 1;
            }
            else
            {
                pQuestDataEx->bRewarded = 1;
            }

            pQuestData->fState = 3;
            pQuestData->dwFlags &= 0xFFFFFF00;
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 1);
        }
    }

    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nAltarMode);
}

// build: context sub_0059A570_StartDarknessForPlayer
static void __stdcall sub_0059A570_StartDarknessForPlayer(D2UnitStrc* pPlayer, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!sub_0059A350_ApplyDarkness(pQuestData))
    {
        D2GSPacketSrv5D packet5D = {};
        pQuestDataEx->bBlackened = 1;
        packet5D.nFlags = 1;
        packet5D.nHeader = 0x5D;
        packet5D.nQuestId = 10;
        sub_6FC3F380(UnitGetClient(pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x2E0), &packet5D);
    }
    else
    {
        pQuestDataEx->bRewarded = 1;
    }
}

// build: context ACT2Q3_Callback13_PlayerStartedGame
void __fastcall ACT2Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 11, 1) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 11, 13);
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 2) == 1)
    {
        sub_0059A570_StartDarknessForPlayer(pQuestArg->pPlayer, pQuestData);

        if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 4))
        {
            pQuestData->fLastState = 2;
            pQuestData->fState = 3;
        }
        else if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 3))
        {
            pQuestData->fLastState = 2;
            pQuestData->fState = 2;
        }
        else
        {
            pQuestData->fLastState = 1;
            pQuestData->fState = 1;
        }
    }
}

// 0x0059ED80
bool __fastcall ACT2Q3_DarkenEnvironment(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bDarkenTimerCreated = 0;
    if (pQuestDataEx->bRewarded)
    {
        return true;
    }

    if (!sub_0059A350_ApplyDarkness(pQuestData))
    {
        pQuestDataEx->bBlackened = 1;
        return true;
    }

    pQuestDataEx->bRewarded = 1;
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_UpdateQuestStateFlags);
    return true;
}

// 0x0059EDC0
static void sub_0059EDC0_CreateDarkenTimer(D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->fState && !pQuestDataEx->bDarkenTimerCreated)
    {
        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pQuestData->pGame);
        QUESTS_CreateTimer(pQuestData, ACT2Q3_DarkenEnvironment, OBJECTS_RollRandomNumber(pSeed, 15, 17));
        pQuestDataEx->bDarkenTimerCreated = 1;
    }
}

// 0x0059EE00
void __fastcall ACT2Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;

    if ((nNewLevel == 0x2C || nNewLevel == 0x2D) && !pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        sub_0059EDC0_CreateDarkenTimer(pQuestData);
    }

    if (nNewLevel == 0x28 && pQuestDataEx->bBlackened == 1 && sub_0059A350_ApplyDarkness(pQuestData))
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_UpdateQuestStateFlags);
        pQuestDataEx->bBlackened = 0;
    }

    if (nOldLevel == 0x28)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x270);
        }
    }
}
