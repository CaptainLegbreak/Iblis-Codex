#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2GameTypes.h"
#define QFLAG_REWARDGRANTED 0
#define QFLAG_STARTED 2
#define QFLAG_CUSTOM3 7
#define MONSTER_CAIN3 245
#define UNIT_OBJECT 2
#define OBJMODE_OPENED 2
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_MAGIC 4
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QUESTSTATEFLAG_A2COMPLETED 15
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM1 5
#define QFLAG_CUSTOM2 6
union D2SeedStrc;
struct D2PlayerDataStrc;
struct D2Act3Quest2Strc;
struct D2ObjOperateFnStrc;
struct D2ObjInitFnStrc;
struct D2MonsterDataStrc;
struct D2GSPacketSrv5D;
struct D2QuestGUIDStrc;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);



D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall QUESTS_SetObjectSelection(D2ObjOperateFnStrc* pOp); // 0x00545850
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int nItemType, int bIgnoreRarity); // 0x00559A30
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x00585970
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality); // 0x00585B90
void __fastcall D2GAME_WarpPlayerToTile_6FCA5B20(D2ObjOperateFnStrc* pOp); // 0x0059D9D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
int __fastcall ACT3Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B7F90

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall ACT3Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8020
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4); // 0x005C0B50
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType); // 0x0058F090

typedef int (__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern char gpAct3Q2NpcMessages[]; // 0x0073F1A0
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300
void __fastcall sub_005B7FE0_EmptyCallback(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7FE0
void __fastcall ACT3Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7FF0
void __fastcall ACT3Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8060
bool __fastcall ACT3Q2_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B8150
void __fastcall ACT3Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8210
void __fastcall ACT3Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8470
bool __fastcall ACT3Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BD500
void __fastcall ACT3Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BD630
bool __fastcall ACT3Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005BD850

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x005B8020
void __fastcall ACT3Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_CAIN3)
    {
        return;
    }

    if (((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->bInitiallyTalkedToCain == 1)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = 0;
    }
}

// 0x005B8470
void __fastcall ACT3Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_REWARDGRANTED))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM3))
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 7;
    }
    else
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_STARTED))
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 7;
        }

        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;

        if (pQuestDataEx->nEyesDropped + pQuestDataEx->nBrainsDropped + pQuestDataEx->nHeartsDropped + pQuestDataEx->nFlailsDropped)
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 7;
        }
    }
}

// 0x005B84E0
int __fastcall OBJECTS_OperateFunction44_SewerStairs(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->hObject;
    if (pObject && pObject->dwAnimMode == OBJMODE_OPENED)
    {
        D2GAME_WarpPlayerToTile_6FCA5B20(pOp);
    }
    return 0;
}

// 0x005B8660
void __fastcall OBJECTS_InitFunction41_SewerStairs(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bSewerStairsInitialized = 1;
    pQuestDataEx->nSewerStairsObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nSewerStairsObjectMode);
    }
}

// 0x005B86B0
void __fastcall OBJECTS_InitFunction42_SewerLever(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData && !pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
}

// 0x005B8770
int __fastcall ACT3Q2_UnitIterate_DetermineKhalimEyeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' yeq') || ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        ++((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }
    return 0;
}

// 0x005B87C0
int __fastcall ACT3Q2_UnitIterate_DetermineKhalimBrainDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' rbq') || ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        ++((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }
    return 0;
}

// 0x005B8810
int __fastcall ACT3Q2_UnitIterate_DetermineKhalimHeartDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' rhq') || ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        ++((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }
    return 0;
}

// 0x005B8860
int __fastcall OBJECTS_OperateFunction57_KhalimChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_SetObjectSelection(pOp))
    {
        return 0;
    }

    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nCounter; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
    }
    pOp->hObject->dwDropItemCode = ' rhq';

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nItemDropCount = 0;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT3Q2_UnitIterate_DetermineKhalimHeartDropCount);

        for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
            {
                ++pQuestDataEx->nHeartsDropped;
                pQuestDataEx->bHeartDropped = 1;
            }
        }
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
    return 0;
}

// 0x005B8940
int __fastcall OBJECTS_OperateFunction58_KhalimChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_SetObjectSelection(pOp))
    {
        return 0;
    }

    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nCounter; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
    }
    pOp->hObject->dwDropItemCode = ' yeq';

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nItemDropCount = 0;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT3Q2_UnitIterate_DetermineKhalimEyeDropCount);

        for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
            {
                ++pQuestDataEx->nEyesDropped;
                pQuestDataEx->bEyeDropped = 1;
            }
        }
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
    return 0;
}

// 0x005B8A20
int __fastcall OBJECTS_OperateFunction59_KhalimChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_SetObjectSelection(pOp))
    {
        return 0;
    }

    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nCounter; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
    }
    pOp->hObject->dwDropItemCode = ' rbq';

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nItemDropCount = 0;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT3Q2_UnitIterate_DetermineKhalimBrainDropCount);

        for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
            {
                ++pQuestDataEx->nBrainsDropped;
                pQuestDataEx->bBrainDropped = 1;
            }
        }
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
    return 0;
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x005B8060
void __fastcall ACT3Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNPCNo == 245)
    {
        switch (nMessageIndex)
        {
        case 543:
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 504);
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 2);
            ((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->bInitiallyTalkedToCain = 1;
            pQuestData->pCallback[2] = ACT3Q2_Callback02_NpcDeactivate;
            break;

        case 545:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 3);
            break;

        case 544:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 6);
            break;

        case 546:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 4);
            break;

        case 547:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 5);
            break;

        case 548:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 7);
            break;

        default:
            return;
        }
    }
}

// 0x005C01D0
int __fastcall SKILLITEM_EventFunc28_HealAfterKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pAttacker);
    int nHitpoints = STATLIST_UnitGetStatValue(pAttacker, 6, 0);
    if (nHitpoints >= nMaxHp)
    {
        return 0;
    }

    nHitpoints += nValue << 8;
    nHitpoints = nHitpoints > 0 ? nHitpoints : 0;
    STATLIST_SetUnitStat(pAttacker, 6, nHitpoints < nMaxHp ? nHitpoints : nMaxHp, 0);
    UNITS_SetOverlay(pAttacker, 151, 0);
    return 1;
}

// 0x005C31F0
int __fastcall sub_005C31F0_IsValidAttractTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pTarget) != 0)
    {
        return 0;
    }

    if (!sub_6FD15190(pTarget, 19))
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    return SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) != 0;
}

// 0x005C3370
void __fastcall sub_6FD0B250(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (pUnit)
    {
        SUNITEVENT_Unregister(SUNIT_GetGameFromUnit(pUnit), pUnit, 1, nState);

        const int nType = pUnit ? pUnit->dwUnitType : 6;
        if (nType == 1)
        {
            AITHINK_ExecuteAiFn(SUNIT_GetGameFromUnit(pUnit), pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 0);
        }

        sub_6FD10E50(pUnit, nState, pStatList);
    }
}

// 0x005C3D50
int __fastcall sub_005C3D50_IsValidTerrorTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    const int nType = pTarget ? pTarget->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pTarget) != 0)
    {
        return 0;
    }

    if (!SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    return sub_6FD15190(pTarget, 11) != 0;
}

// 0x005C6BF0
int __fastcall sub_005C6BF0_GetConvertedMode(D2UnitStrc* pUnit, int nMode)
{
    int nUnitType;
    int nClassId;
    int nNewMode = nMode;

    int nTypeValue;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
        if (nTypeValue == 0)
        {
            return nMode;
        }
    }
    else
    {
        nTypeValue = 6;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nNewMode, gszSkillDruidSourceFile, 156);
    return nNewMode;
}

// 0x005D8510
int __fastcall SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    if (!sub_6FD15190(pUnit, 12))
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    int nOwnerGUID;
    int nOwnerType;
    AIGENERAL_GetOwnerData(pUnit, &nOwnerGUID, &nOwnerType);

    if (nOwnerGUID != -1 && nOwnerType == 0)
    {
        return 0;
    }

    return 1;
}

// 0x005B8150
bool __fastcall ACT3Q2_SeqCallback(D2QuestDataStrc* pQuestData)
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
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 539);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005B81C0
static void __stdcall sub_005B81C0_SendKhalimPacket(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, unsigned char nState)
{
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = 0x5D;
    packet5D.nQuestId = QUEST_A3Q2_KHALIMFLAIL;
    packet5D.nFlags = (unsigned char)pQuestData->dwFlags;
    packet5D.nState = nState;
    sub_6FC3F380(UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 568), &packet5D);
}

// 0x005B8210
void __fastcall ACT3Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2COMPLETED, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_REWARDGRANTED))
    {
        return;
    }

    const unsigned int dwItemCode = ITEMS_GetBaseCode(pQuestArg->pTarget);

    bool bNoCustom1 = false;
    bool bNoCustom3 = false;
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_STARTED);
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_LEAVETOWN);
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_ENTERAREA);
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM1))
    {
        bNoCustom1 = true;
    }
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM2);
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM3))
    {
        bNoCustom3 = true;
    }

    bool bEyeAvailable = false;
    bool bHeartAvailable = false;
    bool bBrainAvailable = false;
    bool bBaseFlailAvailable = false;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 1fq'))
    {
        bBaseFlailAvailable = true;
    }

    ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2fq');

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' yeq'))
    {
        bEyeAvailable = true;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rbq'))
    {
        bBrainAvailable = true;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rhq'))
    {
        bHeartAvailable = true;
    }

    if (dwItemCode == ' 2fq')
    {
        if (pQuestData->fLastState)
        {
            pQuestData->fLastState = 7;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2COMPLETED, QFLAG_REWARDGRANTED))
        {
            return;
        }

        if (bNoCustom3)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 5);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 6);
        }
    }
    else if (dwItemCode == ' 1fq')
    {
        if (!bEyeAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 1);
        }
        else if (!bBrainAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 2);
        }
        else if (!bHeartAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 4);
        }
        else if (bNoCustom1)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 5);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
    else if (dwItemCode == ' yeq')
    {
        if (!bBrainAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 2);
        }
        else if (!bBaseFlailAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 3);
        }
        else if (!bHeartAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 4);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
    else if (dwItemCode == ' rhq')
    {
        if (!bBrainAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 2);
        }
        else if (!bBaseFlailAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 3);
        }
        else if (!bEyeAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 1);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
    else if (dwItemCode == ' rbq')
    {
        if (!bHeartAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 4);
        }
        else if (!bBaseFlailAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 3);
        }
        else if (!bEyeAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 1);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
}

// 0x005BDA30
void __fastcall ACT3Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->bActive = 1;
    pQuestData->fLastState = 1;
    pQuestData->pNPCMessages = gpAct3Q2NpcMessages;
    pQuestData->fState = 0;
    pQuestData->eFilter = 18;
    pQuestData->nInitNo = 0;
    pQuestData->pfStatusFilter = ACT3Q2_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Q2_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT3Q2_SeqCallback;
    pQuestData->nSeqId = 15;
    pQuestData->pCallback[0] = ACT3Q2_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Q2_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT3Q2_Callback03_ChangedLevel;
    pQuestData->pCallback[13] = ACT3Q2_Callback13_PlayerStartedGame;
    pQuestData->pCallback[10] = sub_005B7FE0_EmptyCallback;
    pQuestData->pCallback[4] = ACT3Q2_Callback04_ItemPickedUp;

    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 923, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest2Strc));
    pQuestDataEx->nSewerStairsObjectMode = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

#include "gen/data/Source/D2Game/Quests/a3q2.inc"
struct D2GameStrc;
struct D2ItemDropStrc;
struct D2UnitStrc;
