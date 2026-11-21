#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

union D2SeedStrc;
struct D2SkillsTxt;

extern int gnPotionTableMax_00741B54; // 0x00741B54
extern int gaPotionTable_00741B58[][3]; // 0x00741B58
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
static __declspec(noinline) int __stdcall sub_005D8100_GetFindItemPotion(D2UnitStrc* pUnit, D2GameStrc* pGame, int nSkillId);


typedef char chk_D2SkillsTxt_size[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall sub_005A8000_ModeChangeTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nUnused); // 0x005A8000

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005D8100
static int __stdcall sub_005D8100_GetFindItemPotion(D2UnitStrc* pUnit, D2GameStrc* pGame, int nSkillId)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    if (nAct < 0 || nAct >= 5)
    {
        return 0;
    }

    const int nIndex = nAct + 5 * pGame->nDifficulty;
    int nType = 0;
    const int nChance = SEED_RollRandomNumber(&pUnit->pSeed) % 100;

    const int nParam3 = sub_004EFC50_GetSkillParam3(nSkillId);
    if (nChance < nParam3)
    {
        nType = 1;
    }
    else if (nChance < nParam3 + sub_004EFC80_FourthSkillParam(nSkillId))
    {
        nType = 2;
    }

    if (nIndex > gnPotionTableMax_00741B54)
    {
        return 0;
    }

    return gaPotionTable_00741B58[nIndex][nType];
}

int __fastcall sub_005D8100_EmitCaller(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    return sub_005D8100_GetFindItemPotion(pUnit, pGame, nSkillId);
}

#include "gen/data/Source/D2Game/Unknown_005D8100.inc"
#include "D2DataTbls.h"

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005D8780
int __fastcall sub_005D8780_SrvDoStageRoll(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!D2COMMON_11019(pTarget))
    {
        return 0;
    }

    if (STATES_CheckState(pTarget, 0x76))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, 0x76, 1);
    UNITROOM_RefreshUnit(pTarget);

    const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) >= nChance)
    {
        return 0;
    }

    const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100);
    int nStage = 1;
    int nLow = 0;
    int nHigh = 0;
    for (int i = 0; i < 4; ++i)
    {
        nHigh += pSkillsTxtRecord->dwParam[i];
        if (nRoll >= nLow && nRoll < nHigh)
        {
            nStage = i + 1;
        }
        nLow += pSkillsTxtRecord->dwParam[i];
    }

    sub_005A8000_ModeChangeTarget(pGame, pTarget, pUnit, nStage);
    return 1;
}
