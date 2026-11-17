struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

extern int gnPotionTableMax_00741B54;                                                                       // 0x00741B54
extern int gaPotionTable_00741B58[][3];                                                                     // 0x00741B58

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __fastcall sub_004EFC50_GetSkillParam3(int nSkillId);                                                   // 0x004EFC50
int __fastcall sub_004EFC80_FourthSkillParam(int nSkillId);                                                   // 0x004EFC80

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __declspec(noinline) int __stdcall sub_005D8100_GetFindItemPotion(D2UnitStrc* pUnit, D2GameStrc* pGame, int nSkillId);

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

#include "gen/data/Source/D2Game/005D8100_sub_005D8100_GetFindItemPotion.inc"
