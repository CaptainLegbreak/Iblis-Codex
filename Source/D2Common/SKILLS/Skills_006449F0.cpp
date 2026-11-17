#include "D2Common.h"

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
struct D2InventoryStrc;
struct D2SkillsTxt;
struct D2SkillCalcStrc;

struct D2SkillsTxt
{
    char unk0x00[4];
    unsigned char nFlags[8];
    unsigned char unk_0C[0x18C];
    int dwToHit;
    int dwLevToHit;
    unsigned int dwToHitCalc;
    unsigned char nToHitShift;
    unsigned char nSrcDam;
    char unk0x1A6[2];
    int dwMinDam;
    int dwMaxDam;
    int dwMinLvlDam[5];
    int dwMaxLvlDam[5];
    unsigned int dwDmgSymPerCalc;
    unsigned char nEType;
    char unk0x1DD[3];
    int dwEMin;
    int dwEMax;
    int dwEMinLev[5];
    int dwEMaxLev[5];
    unsigned int dwEDmgSymPerCalc;
    int dwELen;
    int dwELevLen[3];
    unsigned int dwELenSymPerCalc;
    char unk0x228[572 - 532 - 20];
};

struct D2DataTablesStrc
{
    char unk0x00[64];
    char* pSkillsCode;
    unsigned int nSkillsCodeSize;
    char unk0x48[2968 - 64 - 8];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2SkillCalcStrc
{
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __fastcall sub_00646BE0(int nParamId, void* pUserData); // 0x00646BE0

struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[96 - 4];
    D2InventoryStrc* pInventory;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340
int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625E60
int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage); // 0x00644B70
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// build: context SKILLS_EvaluateSkillFormulaInl
__forceinline int SKILLS_EvaluateSkillFormulaInl(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
{
    D2SkillCalcStrc pSkillCalc;

    if (!sgptDataTables->pSkillsCode)
    {
        return 0;
    }

    if (nCalc >= sgptDataTables->nSkillsCodeSize)
    {
        return 0;
    }

    pSkillCalc.pUnit = pUnit;
    pSkillCalc.nSkillId = nSkillId;
    pSkillCalc.nSkillLevel = nSkillLevel;

    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pSkillsCode[nCalc], sgptDataTables->nSkillsCodeSize - nCalc, sub_00646BE0, gpSkillsCalcFunctions, gnSkillsCalcFunctions, &pSkillCalc);
}

// 0x00646CA0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
{
    return SKILLS_EvaluateSkillFormulaInl(pUnit, nCalc, nSkillId, nSkillLevel);
}

// 0x006449F0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    {
        unsigned int nCalc = pSkillsTxtRecord->dwToHitCalc;
        if (nCalc != -1)
        {
            return SKILLS_EvaluateSkillFormulaInl(pUnit, nCalc, nSkillId, nSkillLevel);
        }

        return pSkillsTxtRecord->dwToHit + (nSkillLevel - 1) * pSkillsTxtRecord->dwLevToHit;
    }
}

// 0x00644B70
int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage)
{
    if (nLevel > 1 && pLevelDamage)
    {
        if (nLevel > 28)
        {
            return 7 * *pLevelDamage + pLevelDamage[4] * (nLevel - 28) + 6 * (pLevelDamage[2] + pLevelDamage[3]) + 8 * pLevelDamage[1];
        }
        else if (nLevel > 22)
        {
            return 7 * *pLevelDamage + pLevelDamage[3] * (nLevel - 22) + 6 * pLevelDamage[2] + 8 * pLevelDamage[1];
        }
        else if (nLevel > 16)
        {
            return 7 * *pLevelDamage + pLevelDamage[2] * (nLevel - 16) + 8 * pLevelDamage[1];
        }
        else if (nLevel > 8)
        {
            return 7 * *pLevelDamage + pLevelDamage[1] * (nLevel - 8);
        }
        else
        {
            return *pLevelDamage * (nLevel - 1);
        }
    }

    return 0;
}

#include "gen/data/Source/D2Common/SKILLS/Skills_006449F0.inc"

// 0x00644C20
static int __stdcall sub_00644C20(D2UnitStrc* pUnit, int bMin)
{
    int nDamage;

    if (pUnit && pUnit->dwUnitType == 0)
    {
        nDamage = STATLIST_UnitGetStatValue(pUnit, 2, 0) + STATLIST_UnitGetStatValue(pUnit, 0, 0) - 20;
    }
    else
    {
        nDamage = 3 * STATLIST_UnitGetStatValue(pUnit, 12, 0);
    }

    if (nDamage < 1)
    {
        nDamage = 1;
    }

    if (bMin)
    {
        return nDamage / 4 << 8;
    }

    return nDamage / 3 << 8;
}

// @ref 0x00647D00
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 9))
        {
            return sub_00644C20(pUnit, 0);
            int nDamage;
            if (!pUnit || pUnit->dwUnitType != 0)
            {
                nDamage = 3 * STATLIST_UnitGetStatValue(pUnit, 12, 0);
            }
            else
            {
                nDamage = STATLIST_UnitGetStatValue(pUnit, 2, 0) + STATLIST_UnitGetStatValue(pUnit, 0, 0) - 20;
            }

            if (nDamage < 1)
            {
                nDamage = 1;
            }

            return nDamage / 3 << 8;
        }
        else
        {
            int nDamage = 0;
            if (pSkillsTxtRecord->nSrcDam && a4)
            {
                D2UnitStrc* pItem = D2Common_10434(pUnit, 0);
                int nWeaponDamage = 0;
                if (pItem && INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
                {
                    nWeaponDamage = STATLIST_GetMaxDamageFromUnit(pItem, 24);
                }
                else
                {
                    nWeaponDamage = STATLIST_UnitGetStatValue(pUnit, 22, 0);
                }
                nDamage = (nWeaponDamage * pSkillsTxtRecord->nSrcDam) / 128;
            }

            nDamage += pSkillsTxtRecord->dwMaxDam + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwMaxLvlDam);

            if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
            {
                int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);

                if (nBonus)
                {
                    nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
                }
            }

            return nDamage << pSkillsTxtRecord->nToHitShift;
        }
    }
}

// 0x00647BC0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 9))
    {
        int nDamage;
        if (pUnit && pUnit->dwUnitType == 0)
        {
            nDamage = STATLIST_UnitGetStatValue(pUnit, 2, 0) + STATLIST_UnitGetStatValue(pUnit, 0, 0) - 20;
        }
        else
        {
            nDamage = 3 * STATLIST_UnitGetStatValue(pUnit, 12, 0);
        }

        if (nDamage < 1)
        {
            nDamage = 1;
        }

        return nDamage / 4 << 8;
    }

    int nDamage = 0;
    if (pSkillsTxtRecord->nSrcDam && a4)
    {
        D2UnitStrc* pItem = D2Common_10434(pUnit, 0);
        int nWeaponDamage;
        if (pItem)
        {
            if (INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
                nWeaponDamage = STATLIST_GetMinDamageFromUnit(pItem, 1);
            else
                nWeaponDamage = STATLIST_UnitGetStatValue(pUnit, 21, 0);
        }
        else
        {
            nWeaponDamage = STATLIST_UnitGetStatValue(pUnit, 21, 0);
        }
        nDamage = (nWeaponDamage * pSkillsTxtRecord->nSrcDam) / 128;
    }

    nDamage += pSkillsTxtRecord->dwMinDam + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwMinLvlDam);

    if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
    {
        const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);
        if (nBonus)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
        }
    }

    return nDamage << pSkillsTxtRecord->nToHitShift;
}
