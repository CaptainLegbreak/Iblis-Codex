#define UNIT_MONSTER 1

struct D2AiControlStrc;

struct D2MonsterDataStrc
{
    char unk0x00[4];
    unsigned char nComponent[16];
    char unk0x14[0x14];
    D2AiControlStrc* pAiControl;
};

union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
};

struct D2NecroSkeletonComponentStrc
{
    unsigned char nHead;
    unsigned char nShield;
    unsigned char nTorso;
    unsigned char nSpecial1;
    unsigned char nSpecial2;
    unsigned char nLegs;
    unsigned char nRightArm;
    unsigned char nLeftArm;
    unsigned char nRightHand;
};

struct D2SkillsTxt
{
    char unk0x000[0x148];
    int dwParam[8];
    char unk0x168[0x23C - 0x168];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

struct D2StatListStrc;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const D2NecroSkeletonComponentStrc gaNecroSkeletonComponents_00741940[];                             // 0x00741940
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                            // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static void SKILLS_SetMonsterComponent_Inline(D2UnitStrc* pMonster, int nIndex, char nComponent)
{
    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER && pMonster->pMonsterData)
    {
        pMonster->pMonsterData->nComponent[nIndex] = nComponent;
    }
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __declspec(noinline) void __stdcall D2GAME_SetUnitComponent_6FD0C3A0(int bHasShield, int bSpecial, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nLevel); // 0x005C4180

// build: context D2GAME_SetUnitComponent_6FD0C3A0
static __declspec(noinline) void __stdcall D2GAME_SetUnitComponent_6FD0C3A0(int bHasShield, int bSpecial, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nLevel)
{
    if (nLevel > 10)
    {
        nLevel = 10;
    }

    SKILLS_SetMonsterComponent_Inline(pPet, 0, gaNecroSkeletonComponents_00741940[nLevel].nHead);
    SKILLS_SetMonsterComponent_Inline(pPet, 1, gaNecroSkeletonComponents_00741940[nLevel].nTorso);
    SKILLS_SetMonsterComponent_Inline(pPet, 8, gaNecroSkeletonComponents_00741940[nLevel].nSpecial1);
    SKILLS_SetMonsterComponent_Inline(pPet, 9, gaNecroSkeletonComponents_00741940[nLevel].nSpecial2);
    SKILLS_SetMonsterComponent_Inline(pPet, 2, gaNecroSkeletonComponents_00741940[nLevel].nLegs);
    SKILLS_SetMonsterComponent_Inline(pPet, 3, gaNecroSkeletonComponents_00741940[nLevel].nRightArm);
    SKILLS_SetMonsterComponent_Inline(pPet, 4, gaNecroSkeletonComponents_00741940[nLevel].nLeftArm);

    if (bHasShield)
    {
        SKILLS_SetMonsterComponent_Inline(pPet, 7, gaNecroSkeletonComponents_00741940[nLevel].nShield);
    }

    if (bSpecial)
    {
        const unsigned char nComponent = SEED_RollRandomNumber_Inline(&pUnit->pSeed) & 3;
        SKILLS_SetMonsterComponent_Inline(pPet, 11, nComponent);
        SKILLS_SetMonsterComponent_Inline(pPet, 12, nComponent);
        AITHINK_SetAiControlParams(pPet && pPet->dwUnitType == UNIT_MONSTER && pPet->pMonsterData ? pPet->pMonsterData->pAiControl : 0, 1, 0, -666);
    }
    else
    {
        SKILLS_SetMonsterComponent_Inline(pPet, 5, gaNecroSkeletonComponents_00741940[nLevel].nRightHand);
    }
}

// 0x005C4300
static __declspec(noinline) void __stdcall sub_005C4300_SetSkeletonComponents(D2UnitStrc* pPet, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    int nLevel = 1;
    if (STATES_CheckState(pUnit, 0x61))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x61);
        if (pStatList)
        {
            STATLIST_GetStatValue(pStatList, 0x15E, 0);
            nLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
        }
    }

    int bHasShield = 0;
    if (nSkillLevel > 2)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_Inline(nSkillId);
        const int nParam = !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[0];
        const int nRoll = SEED_RollRandomNumber_Inline(&pUnit->pSeed) % 100;
        if (nRoll < nParam)
        {
            bHasShield = 1;
        }
    }

    D2GAME_SetUnitComponent_6FD0C3A0(bHasShield, 0, pUnit, pPet, nLevel);
}

// 0x005C43D0
static __declspec(noinline) void __stdcall sub_005C43D0_SetMageComponents(D2UnitStrc* pPet, D2UnitStrc* pUnit)
{
    int nLevel = 1;
    if (STATES_CheckState(pUnit, 0x61))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x61);
        if (pStatList)
        {
            STATLIST_GetStatValue(pStatList, 0x15E, 0);
            nLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
        }
    }

    D2GAME_SetUnitComponent_6FD0C3A0(0, 1, pUnit, pPet, nLevel);
}

// 0x005C4430
void __fastcall sub_005C4430_SetNecroPetComponents(D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel)
{
    switch (!pPet ? -1 : pPet->dwClassId)
    {
    case 0x16B:
        sub_005C4300_SetSkeletonComponents(pPet, nSkillLevel, pUnit, nSkillId);
        break;
    case 0x16C:
        sub_005C43D0_SetMageComponents(pPet, pUnit);
        break;
    }
}

#include "gen/data/Source/D2Game/005C4300_sub_005C4300_SetSkeletonComponents.inc"
