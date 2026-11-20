#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_MAGIC 4
#define ITEMQUAL_UNIQUE 7
struct D2PlayerDataStrc;
struct D2Act1Quest4Strc;
struct D2Act2Quest2Strc;
struct D2Act2Quest4Strc;
struct D2Act2Quest5Strc;
struct D2Act2Quest6Strc;
struct D2GSPacketSrv53;
struct D2GSPacketSrv5D;
struct D2SeedStrc;
struct D2ObjOperateFnStrc;
struct D2Act2Quest3Strc;



struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char pad0x08[0x01];
    unsigned char bNotIntro;
    char pad0x0A[0x02];
    unsigned char fState;
    char pad0x0D[0x0B];
    void* pQuestDataEx;
    char pad0x1C[0xC4];
    int nQuestFilter;
};

struct D2Act1Quest4Strc
{
    char pad0x00[0x92];
    unsigned char bChangePortalInTownToSpecialMode;
    char pad0x93[0x03];
    unsigned char bCainPortalInTownSpawned;
    char pad0x97[0x11];
    D2CoordStrc pCainPortalInTownCoords;
    int nUnk0xB0;
};

struct D2Act2Quest2Strc
{
    int unused0x00[5];
    int nItemDropCount;
    int nBaseStaffs;
    int nCubedStaffs;
    int nHoradricCubes;
    int nAmulets;
    unsigned char bHoradricScrollDropped;
    unsigned char bCubeDropped;
    unsigned char bStaffCubed;
    unsigned char unk0x2B;
    int nPlayerGUID;
};

struct D2Act2Quest4Strc
{
    char pad0x00[0x40];
    unsigned short nHaremBlockerObjectMode;
    char pad0x42[0x04];
    unsigned char bIsHaremBlockerNeutral;
};

struct D2Act2Quest5Strc
{
    char pad0x00[0x04];
    D2ActiveRoomStrc* pRoom;
};

struct D2Act2Quest6Strc
{
    char pad0x00[0x40];
    D2UnitStrc* pTyrael;
    unsigned char bCloseToTyrael;
};

struct D2GSPacketSrv53
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short unk0x02;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned short unk0x06;
    unsigned char unk0x08;
    unsigned char unk0x09;
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

enum D2QuestConstants
{
    QUEST_A1Q1_DENOFEVIL = 1,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A2Q2_HORADRICSTAFF = 9,
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUEST_A2Q5_SUMMONER = 12,
    QUEST_A2Q6_DURIEL = 13,
    QUESTSTATEFLAG_A1Q1 = 1,
    QUESTSTATEFLAG_A2Q0 = 8,
    QUESTSTATEFLAG_A2Q1 = 9,
    QUESTSTATEFLAG_A2Q3 = 11,
    QUESTSTATEFLAG_A2Q4 = 12,
    QUESTSTATEFLAG_A2Q5 = 13,
    QUESTSTATEFLAG_A2Q6 = 14,
    QUESTSTATEFLAG_A2Q7 = 30,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_REWARDPENDING = 1,
    QFLAG_CUSTOM3 = 7,
    QFLAG_CUSTOM4 = 8,
    QFLAG_PRIMARYGOALDONE = 13,
    OBJMODE_OPENED = 2,
    ACT_II = 1,
    MONSTER_WARRIV2 = 175,
    MONSTER_ATMA = 176,
    MONSTER_DROGNAN = 177,
    MONSTER_FARA = 178,
    MONSTER_GREIZ = 198,
    MONSTER_ELZIX = 199,
    MONSTER_GEGLASH = 200,
    MONSTER_JERHYN = 201,
    MONSTER_LYSANDER = 202,
    MONSTER_MESHIF1 = 210,
    MONSTER_CAIN2 = 244,
    MONSTER_NAVI = 266,
    MONSTER_ACT2GUARD2 = 331,
    MONSTER_ACT2GUARD4 = 377,
    MONSTER_ACT2GUARD5 = 378,
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760


D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0
void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket); // 0x0053C900
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0


struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0
int __fastcall QUESTS_SetObjectSelection(D2ObjOperateFnStrc* pOp); // 0x00545850
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x00585970
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality); // 0x00585B90
int __fastcall ACT2Q2_UnitIterate_DetermineHoradricScrollDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00599700
int __fastcall ACT2Q2_UnitIterate_DetermineCubeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005997C0

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

struct D2Act2Quest3Strc
{
    char unk0[0x2];
    unsigned char bDarknessApplied;
    char bDarknessPending[0x1];
    unsigned char bAltarDestroyed;
    unsigned char bAltarInitialized;
    char unk0x06[0x2];
    int nAltarMode;
    int nAltarGUID;
    D2ActiveRoomStrc* pRoom;
    char tPlayerGUIDs[0x84];
    int nAltarLevelId;
    int nViperAmuletDropCount;
};

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
int __fastcall ACT2Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00599FE0
int __fastcall ACT2Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A0B0
int __fastcall ACT2Q3_UnitIterate_SendPacket0x53ToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A170
int __fastcall ACT2Q3_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A680
bool __fastcall ACT2Q3_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059A700
int __fastcall ACT2Q3_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A730
int __fastcall ACT2Q3_UnitIterate_DetermineViperAmuletDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A770
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0

// 0x00594360
int __fastcall ACT1Q4_GetCainPortalInTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (pQuestData && pQuestData->bNotIntro)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bCainPortalInTownSpawned && !pQuestDataEx->bChangePortalInTownToSpecialMode)
        {
            pCoord->nX = pQuestDataEx->pCainPortalInTownCoords.nX;
            pCoord->nY = pQuestDataEx->pCainPortalInTownCoords.nY;
            return 1;
        }
    }

    return 0;
}

// 0x005946D0
void __fastcall sub_005946D0_SetA1Q4Unk0xB0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->nUnk0xB0 = nValue;
    }
}

// 0x00596BC0
bool __fastcall ACT1Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId != MONSTER_NAVI || !QUESTS_GetQuestData(pQuest->pGame, QUEST_A1Q1_DENOFEVIL)->bNotIntro || QUESTS_GetGlobalState(pQuest->pGame, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        return false;
    }

    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE)
        && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING))
    {
        return true;
    }

    return false;
}

// 0x005985B0
bool __fastcall sub_005985B0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    return false;
}

// 0x00598780
bool __fastcall ACT2Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_JERHYN && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q0, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    return false;
}

// 0x0059A170
int __fastcall ACT2Q3_UnitIterate_SendPacket0x53ToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 357);
    if (CLIENTS_GetActNo(pClient) == ACT_II)
    {
        D2GSPacketSrv53 packet53;
        packet53.nHeader = 0x53;
        *(int*)&packet53.unk0x01 = 2;
        *(int*)&packet53.unk0x05 = 0;
        packet53.unk0x09 = 0;
        D2GAME_SendPacket0x53_6FC3DF50(pClient, &packet53);
    }

    return 0;
}

// 0x0059A1C0
bool __fastcall ACT2Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) == 1)
    {
        return false;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) == 1)
    {
        if (nNpcId == MONSTER_ATMA || nNpcId == MONSTER_WARRIV2 || nNpcId == MONSTER_GREIZ || nNpcId == MONSTER_ELZIX
            || nNpcId == MONSTER_DROGNAN || nNpcId == MONSTER_LYSANDER || nNpcId == MONSTER_CAIN2 || nNpcId == MONSTER_MESHIF1
            || nNpcId == MONSTER_GEGLASH || nNpcId == MONSTER_JERHYN)
        {
            return true;
        }
    }

    if (nNpcId == MONSTER_DROGNAN && pQuest->fState == 1)
    {
        return true;
    }

    return false;
}

// 0x0059BB40
bool __fastcall ACT2Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if ((nNpcId == MONSTER_ATMA || nNpcId == MONSTER_WARRIV2 || nNpcId == MONSTER_ELZIX || nNpcId == MONSTER_DROGNAN
        || nNpcId == MONSTER_LYSANDER || nNpcId == MONSTER_CAIN2 || nNpcId == MONSTER_MESHIF1 || nNpcId == MONSTER_JERHYN
        || nNpcId == MONSTER_GEGLASH || nNpcId == MONSTER_FARA)
        && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING) == 1)
    {
        return true;
    }

    return false;
}

// 0x0059BE70
int __fastcall ACT2Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q5_SUMMONER);
    D2_ASSERT(pQuestData, 269);

    D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)pQuestData->pQuestDataEx;
    int bInRange = 0;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom, 284);

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

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING) && bInRange)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING);
    }

    return 0;
}

// 0x0059DF30
void __fastcall ACT2Q6_UnitIterate_CheckDistanceToTyrael(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pData;
    if (sub_006416D0_UnitEdgeDistance(pUnit, pQuestDataEx->pTyrael) < 12)
    {
        pQuestDataEx->bCloseToTyrael = 1;
    }
}

// 0x0059E4B0
bool __fastcall ACT2Q8_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_ACT2GUARD5)
    {
        D2GameStrc* pGame = pQuest->pGame;
        D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, QUEST_A2Q6_DURIEL);
        if (pQuestData && pQuestData->bNotIntro && pQuestData->fState < 2
            && QUESTS_GetGlobalState(pQuest->pGame, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE)
            && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDPENDING)
            && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }

    return false;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x00599C10
int __fastcall OBJECTS_OperateFunction40_HoradricScrollChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    int nResult = 0;
    if (QUESTS_SetObjectSelection(pOp))
    {
        pOp->pObject->dwDropItemCode = ' 1rt';

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q2_HORADRICSTAFF);
        if (pQuestData)
        {
            D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->nItemDropCount = 0;
            SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT2Q2_UnitIterate_DetermineHoradricScrollDropCount);

            for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
            {
                int nItemLevel;
                D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, ITEMQUAL_UNIQUE, &nItemLevel, 0, -1, 1);
            }
        }

        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);

        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
        const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
        for (int i = 0; i < nCounter; ++i)
        {
            OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, ' dlg', 2);
        }
    }
    return nResult;
}

// 0x00599DF0
int __fastcall OBJECTS_OperateFunction39_HoradricCubeChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    int nResult = 0;
    if (QUESTS_SetObjectSelection(pOp))
    {
        pOp->pObject->dwDropItemCode = ' xob';

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q2_HORADRICSTAFF);
        if (pQuestData)
        {
            D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->nItemDropCount = 0;
            SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT2Q2_UnitIterate_DetermineCubeDropCount);

            for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
            {
                int nItemLevel;
                if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
                {
                    ++pQuestDataEx->nHoradricCubes;
                    pQuestDataEx->bCubeDropped = 1;
                }
            }
        }

        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);

        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
        const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
        for (int i = 0; i < nCounter; ++i)
        {
            OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, ' dlg', 2);
        }
    }
    return nResult;
}

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0059A7E0
int __fastcall OBJECTS_OperateFunction24_TaintedSunAltar(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 10);
    if (!pQuestData)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
    if ((QUESTRECORD_GetQuestState(pQuestFlags, 11, 1) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 11, 0) == 1)
        && (QUESTRECORD_GetQuestState(pQuestFlags, 10, 0) == 1 || ITEMS_FindQuestItem(pOp->pGame, pOp->pPlayer, ' piv') || ITEMS_FindQuestItem(pOp->pGame, pOp->pPlayer, ' tsh')))
    {
        SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        return 0;
    }

    if (pOp->pObject && pOp->pObject->dwAnimMode)
    {
        return 0;
    }

    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        pQuestDataEx->nAltarMode = 2;
        pQuestDataEx->nViperAmuletDropCount = 0;
        pQuestDataEx->bAltarDestroyed = 1;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT2Q3_UnitIterate_DetermineViperAmuletDropCount);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
        int nItemLevel = DUNGEON_GetLevelIdFromRoom(pRoom);
        int nAmuletsDropped = 0;
        pOp->pObject->dwDropItemCode = ' piv';
        for (int i = 0; i < pQuestDataEx->nViperAmuletDropCount; ++i)
        {
            D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, 7, &nItemLevel, 0, -1, 0);
            if (pItem)
            {
                ITEMS_SetItemFlag(pItem, 16, 1);
                ++nAmuletsDropped;
            }
        }

        OBJMODE_DropFromChestTCWithQuality(pOp, 4);
        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
        const int nGoldDropCount = SEED_RollRandomNumber(pSeed) % 5 + 5;
        for (int i = 0; i < nGoldDropCount; ++i)
        {
            OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, ' dlg', 2);
        }

        D2QuestDataStrc* pQuestDataStaff = QUESTS_GetQuestData(pQuestData->pGame, 9);
        if (pQuestDataStaff)
        {
            ((D2Act2Quest2Strc*)pQuestDataStaff->pQuestDataEx)->nAmulets += nAmuletsDropped;
        }
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    pQuestDataEx->pRoom = pRoom;
    pQuestDataEx->nAltarLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    UNITS_ChangeAnimMode(pOp->pObject, 1);
    pQuestDataEx->nAltarMode = 2;
    pQuestDataEx->bAltarInitialized = 1;
    pQuestDataEx->nAltarGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    pQuestDataEx->bAltarDestroyed = 1;

    if (pQuestData->bNotIntro)
    {
        D2GameStrc* pGame = pQuestData->pGame;
        if (pGame->pAct[1])
        {
            ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bDarknessApplied = 0;
            ENVIRONMENT_TaintedSunEnd(pGame->pAct[1]);
            SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q3_UnitIterate_SendPacket0x53ToClient);
        }

        QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 991);
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 992);
        QUESTS_TriggerFX(pQuestData->pGame, 6);
    }

    pQuestDataEx->nViperAmuletDropCount = 0;
    SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT2Q3_UnitIterate_DetermineViperAmuletDropCount);

    if (pQuestData->bNotIntro)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 11, 0))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 11, 1);
            QUESTRECORD_SetQuestState(pQuestFlags, 11, 13);
            QUESTRECORD_ClearQuestState(pQuestFlags, 11, 14);
        }

        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pObject, ACT2Q3_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pObject, ACT2Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pObject, ACT2Q3_UnitIterate_AttachCompletionSound);
        QUESTS_SetGlobalState(pOp->pGame, pQuestData->nQuestFilter, 13);
    }

    int nItemLevel = DUNGEON_GetLevelIdFromRoom(pQuestDataEx->pRoom);
    int nAmuletsDropped = 0;
    pOp->pObject->dwDropItemCode = ' piv';
    for (int i = 0; i < pQuestDataEx->nViperAmuletDropCount; ++i)
    {
        D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, 7, &nItemLevel, 0, -1, 0);
        if (pItem)
        {
            ITEMS_SetItemFlag(pItem, 16, 1);
            ++nAmuletsDropped;
        }
    }

    D2QuestDataStrc* pQuestDataStaff = QUESTS_GetQuestData(pQuestData->pGame, 9);
    if (pQuestDataStaff)
    {
        ((D2Act2Quest2Strc*)pQuestDataStaff->pQuestDataEx)->nAmulets += nAmuletsDropped;
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, 4);
    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nGoldDropCount = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nGoldDropCount; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, ' dlg', 2);
    }

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_SetCompletionFlag);
    QUESTS_CreateTimer(pQuestData, ACT2Q3_Timer_StatusCycler, 10);
    return 0;
}
