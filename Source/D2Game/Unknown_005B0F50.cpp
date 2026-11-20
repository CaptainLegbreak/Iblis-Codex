#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#define MONSTATSFLAGINDEX_OPENDOORS 3
#define STATE_STUNNED 21
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
struct D2MonStatsTxt;
struct D2DoorObjectAiCallbackArgStrc;
struct D2SeedStrc;
struct D2MonsterDataStrc;
struct D2MonStats2Txt;




struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    unsigned int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
    D2MonStats2Txt* pMonstats2Txt;
};


struct D2DoorObjectAiCallbackArgStrc
{
    D2UnitStrc* pDoor;
    int nDistance;
    int unk0x08[8];
};

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

extern unsigned int gdwBitMasks[]; // 0x006CE268
unsigned short __stdcall D2Common_10201(D2DynamicPathStrc* pDynamicPath); // 0x00648EB0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectType, int nObjectGUID); // 0x00584540
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __fastcall sub_005B0F50_AiOpenDoorCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B0F50
int __fastcall D2GAME_AICORE_MinionLeash_6FCF0D10(D2GameStrc* pGame, D2UnitStrc* pMonster, D2AiTickParamStrc* pAiTickParam); // 0x005B0FF0


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

typedef void (__fastcall* AIPARAMFN)(D2GameStrc*, D2UnitStrc*, D2AiTickParamStrc*);

struct D2AiControlStrc
{
    int nAiSpecialState;
    AIPARAMFN pAiParamFn;
    unsigned char unk_08[0xC];
    int dwAiParam[3];
};
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall sub_0054DC40_FindSpawnPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, int* pX, int* pY, int a7); // 0x0054DC40
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance); // 0x005DE200
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(int (__stdcall* lpfn)()); // 0x006CC34C



int __fastcall sub_005B10E0_AiTickPreChecks(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B10E0
int __fastcall sub_005B1650_AiTickTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B1650
int __fastcall sub_005B13E0_AiMeleeWalkTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B13E0

// 0x005B0F50
int __fastcall sub_005B0F50_OpenDoorInReach(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (BITARRAY_CHECK(pAiTickParam->pMonstatsTxt->nMonStatsFlags, MONSTATSFLAGINDEX_OPENDOORS) && D2Common_10201(pUnit->pDynamicPath) & 0x800)
    {
        D2DoorObjectAiCallbackArgStrc arg;
        arg.pDoor = 0;
        arg.nDistance = 9;

        sub_6FCF1E80(pGame, pUnit, &arg, 0, 8);

        D2UnitStrc* pDoor = arg.pDoor;
        if (pDoor)
        {
            const int nClassId = (pDoor ? pDoor->dwClassId : -1);
            if (DATATBLS_GetObjectsTxtRecord(nClassId)->nMonsterOK)
            {
                const int nDoorId = (pDoor ? pDoor->dwUnitId : -1);
                OBJMODE_OperateObjectInRange(pGame, pUnit, 2, nDoorId);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
                return 1;
            }
        }
    }

    return 0;
}

// 0x005B10E0
int __fastcall sub_005B10E0_AiTickPreChecks(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (STATES_CheckState(pUnit, STATE_STUNNED))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 3);
        return 1;
    }

    if (sub_005B0F50_AiOpenDoorCheck(pGame, pUnit, pAiTickParam))
    {
        return 1;
    }

    return D2GAME_AICORE_MinionLeash_6FCF0D10(pGame, pUnit, pAiTickParam) != 0;
}

static __forceinline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005B11F0
int __fastcall sub_005B11F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (!AIUTIL_CheckAiControlFlag(pAiTickParam->pAiControl, 0x20))
    {
        return 0;
    }

    if ((int)(SEED_RollRandomNumberInline(&pUnit->pSeed) % 100) >= 40)
    {
        return 0;
    }

    const int nId = sub_00463860(pUnit);
    const int nBaseId = (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) ? nId : -1;

    int bNoHeal = sub_00457490_CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, 1);
    if (nBaseId == 10 || nBaseId == 345 || nBaseId == 557)
    {
        bNoHeal = 1;
    }

    const int nLifePct = UNITS_GetCurrentLifePercentage(pUnit);
    if (nLifePct >= 30)
    {
        if (bNoHeal)
        {
            return 0;
        }

        if (pAiTickParam->nTargetDistance >= 10)
        {
            return 0;
        }
    }

    if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 15)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        D2RoomCoordListStrc* pCoordList = D2Common_10096(pRoom, UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit));
        int nX;
        int nY;
        if (sub_0054DC40_FindSpawnPosition(pGame, pRoom, pCoordList, nBaseId, &nX, &nY, 0))
        {
            D2ActiveRoomStrc* pTargetRoom = D2GAME_GetRoom_6FC52070(pRoom, nX, nY);
            if (pTargetRoom && !DUNGEON_IsRoomInTown(pTargetRoom))
            {
                if (nLifePct < 30 && SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 25 && !STATES_CheckState(pUnit, 52))
                {
                    int nHeal = STATLIST_UnitGetStatValue(pUnit, 12, 0) << 8;
                    const int nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0);
                    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
                    if (nLife + nHeal > nMaxLife)
                    {
                        nHeal = nMaxLife - nLife;
                    }
                    STATLIST_AddUnitStat(pUnit, 6, nHeal, 0);
                }

                AITACTICS_UseSkill(pGame, pUnit, 4, 184, 0, nX, nY);
                return 1;
            }
        }
    }

    return 0;
}

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005B14E0
void __fastcall D2GAME_AI_SpecialState02_6FCD1660(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int nDistance = pAiTickParam->nTargetDistance;
    if (sub_6FCF2E70(pUnit) || nDistance < 4)
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, 0);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (nDistance > 10 && !pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTarget, 12);
        return;
    }
    if ((AI_RollUnitSeed(pUnit) & 0xFF) < 77)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
        return;
    }
    if ((AI_RollUnitSeed(pUnit) & 0xFF) < 26)
    {
        pAiControl->dwAiParam[0] = 0;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

static __forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

static __forceinline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMonsterId = pUnit->dwClassId;
        if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nMonsterId];
        }
    }
    return 0;
}

static __forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecordFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMonsterId = pUnit->dwClassId;
        if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
            if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
            {
                return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
            }
        }
    }
    return 0;
}

// 0x005B1740
void __fastcall sub_005B1740(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    D2AiTickParamStrc aiTickParam = {};
    aiTickParam.pAiControl = AIGENERAL_GetAiControlFromUnit_Inline(pUnit);
    aiTickParam.pMonstatsTxt = MONSTERMODE_GetMonStatsTxtRecordFromUnit_Inline(pUnit);
    aiTickParam.pMonstats2Txt = MONSTERREGION_GetMonStats2TxtRecordFromUnit_Inline(pUnit);
    if (!aiTickParam.pMonstatsTxt || !aiTickParam.pMonstats2Txt)
    {
        return;
    }
    if (sub_005B10E0_AiTickPreChecks(pGame, pUnit, &aiTickParam))
    {
        return;
    }
    if (sub_005B1650_AiTickTarget(pGame, pUnit, &aiTickParam))
    {
        return;
    }
    if (sub_005B13E0_AiMeleeWalkTarget(pGame, pUnit, &aiTickParam))
    {
        return;
    }
    D2_ASSERT(!IsBadCodePtr((int (__stdcall*)())aiTickParam.pAiControl->pAiParamFn), 0x39E);
    aiTickParam.pAiControl->pAiParamFn(pGame, pUnit, &aiTickParam);
}
