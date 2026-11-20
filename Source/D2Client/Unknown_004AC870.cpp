#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#define NULL 0
extern "C" char* __cdecl strcpy(char*, const char*);
#pragma intrinsic(strcpy)




struct D2SuperUniquesTxt
{
    unsigned short wSuperUnique;
    unsigned short wNameStr;
};



struct D2HoverModeStrc
{
    int nMode;
    unsigned short wStringId;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern wchar_t gwszSpace_007C0C58[];                                                                        // 0x007C0C58
extern const D2HoverModeStrc gaHoverModes_006DA488[];                                                       // 0x006DA488

int __fastcall sub_0045C390_RollRandom(D2SeedStrc* pSeed, int nMax);                                        // 0x0045C390
int __cdecl sub_0048BE80_Sprintf(wchar_t* wszDest, const wchar_t* wszFormat, ...);                          // 0x0048BE80
int __fastcall sub_004AE320_IsChampionMonster(D2UnitStrc* pUnit);                                                             // 0x004AE320
wchar_t* __fastcall D2LANG_GetStringFromTblIndex(unsigned short wIndex);                                    // 0x00524A30
void __fastcall sub_00526320_ToUnicode(wchar_t* pDest, const char* szSource, int nLength);                  // 0x00526320
void __fastcall sub_0063E810_SetUnitName(D2UnitStrc* pUnit, const wchar_t* wszName);                        // 0x0063E810
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nSeed);                                             // 0x00650E40
wchar_t* __fastcall sub_00653ED0_GetNamePrefix(D2UnitStrc* pUnit);                                          // 0x00653ED0
wchar_t* __fastcall sub_00653F10_GetNameSuffix(D2UnitStrc* pUnit);                                          // 0x00653F10
wchar_t* __fastcall sub_00653F50_GetNameAppellation(D2UnitStrc* pUnit);                                     // 0x00653F50
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                         // 0x006556E0

static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x004AC730
D2MonsterDataStrc* __fastcall sub_004AC730_MonsterDataOf(D2UnitStrc* pUnit)
{
    if (sub_0044BE50(pUnit) == 1)
        return pUnit->pMonsterData;
    return 0;
}

// 0x004AC760
unsigned short __fastcall sub_004AC760_GetNameSeed(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_004AC730_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return pMonsterData->wNameSeed;
}

// 0x004AC7C0
short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_004AC730_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return pMonsterData->wBossHcIdx;
}

// 0x004AC7E0
int __fastcall sub_004AC7E0_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = sub_004AC730_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return (unsigned short)(pMonsterData->nTypeFlag & nFlag) != 0;
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return NULL;
}

// 0x004AC870
void __fastcall sub_004AC870_SetMonsterHoverName(D2UnitStrc* pUnit, int nMode, int bShow)
{
    wchar_t wszName[300];

    if (!bShow)
    {
        return;
    }

    for (int k = 0; k < 300; ++k)
    {
        wszName[k] = 0;
    }
    char szSpace[8];
    strcpy(szSpace, " ");
    sub_00526320_ToUnicode(gwszSpace_007C0C58, szSpace, 2);

    D2SeedStrc* pSeed = &pUnit->pSeed;
    unsigned short nNameSeed = sub_004AC760_GetNameSeed(pUnit);
    D2MonsterDataStrc* pMonsterData = (pUnit && sub_0044BE50(pUnit) == 1) ? pUnit->pMonsterData : NULL;
    if (pMonsterData && (pMonsterData->nTypeFlag & 2))
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(sub_004AC7C0_GetSuperUniqueId(pUnit));
        if (!pSuperUniquesTxtRecord)
        {
            return;
        }

        unsigned short wNameStr = pSuperUniquesTxtRecord->wNameStr;
        if (!wNameStr)
        {
            wNameStr = 0x1506;
        }
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(wNameStr));
        return;
    }

    int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    if (sub_004AE320_IsChampionMonster(pUnit))
    {
        int i = 0;
        for (; i < 4; ++i)
        {
            if (gaHoverModes_006DA488[i].nMode == nMode)
            {
                break;
            }
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        sub_0048BE80_Sprintf(wszName, D2LANG_GetStringFromTblIndex(0x2B40), D2LANG_GetStringFromTblIndex(gaHoverModes_006DA488[i].wStringId), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), 0);
        sub_0063E810_SetUnitName(pUnit, wszName);
        return;
    }

    SEED_InitLowSeed(pSeed, nNameSeed);
    if (nMode == 12)
    {
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xC27));
        return;
    }

    switch (nClassId)
    {
    case 0x9C:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xBCD));
        return;

    case 0xD3:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xBEE));
        return;

    case 0xF2:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xBF6));
        return;

    case 0x100:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0x3F6));
        return;

    case 0xF3:
    case 0x14D:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xBF4));
        return;

    case 0x220:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xBF5));
        return;

    case 0x2C3:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0x2B92));
        return;

    case 0x2C4:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xBEE));
        return;

    case 0x2C0:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xBF6));
        return;

    case 0x2C2:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0x3F6));
        return;

    case 0x2C1:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xBF4));
        return;

    case 0x2C5:
        sub_0063E810_SetUnitName(pUnit, D2LANG_GetStringFromTblIndex(0xBF5));
        return;

    default:
        sub_0048BE80_Sprintf(wszName, D2LANG_GetStringFromTblIndex(0x6B9), sub_00653ED0_GetNamePrefix(pUnit), sub_00653F10_GetNameSuffix(pUnit), 0);
        if (sub_0045C390_RollRandom(pSeed, 100) < 50)
        {
            sub_0048BE80_Sprintf(wszName, D2LANG_GetStringFromTblIndex(0x6BA), sub_00653ED0_GetNamePrefix(pUnit), sub_00653F10_GetNameSuffix(pUnit), sub_00653F50_GetNameAppellation(pUnit), 0);
        }
        sub_0063E810_SetUnitName(pUnit, wszName);
        return;
    }
}

#include "gen/data/Source/D2Client/Unknown_004AC870.inc"
