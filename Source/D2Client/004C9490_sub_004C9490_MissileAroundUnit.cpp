struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissileA;
    char unk0x0EC[0x28];
    int dwCltCalc[3];
    char unk0x120[0x11C];
};

typedef char D2SkillsTxt_size_check[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gnDirOffsetY_006DAE88[8];                                                                  // 0x006DAE88
extern const int gnDirOffsetX_006DAEA8[8];                                                                  // 0x006DAEA8

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                   // 0x004648F0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit);                                              // 0x00620100
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath);                                            // 0x006486C0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C9490
int __fastcall sub_004C9490_MissileAroundUnit(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!sub_004648F0_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    if (!pUnit->pDynamicPath)
    {
        return 0;
    }

    int nDirection;
    if (PATH_GetVelocity(pUnit->pDynamicPath))
    {
        nDirection = UNITS_GetDirection(pUnit) >> 3;
    }
    else
    {
        nDirection = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 8);
    }

    nDirection = (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3) + (nDirection + 4) % 8 - 1) & 7;
    const int nX = CLIENTS_GetUnitX(pUnit) + gnDirOffsetX_006DAEA8[nDirection];
    const int nY = CLIENTS_GetUnitY(pUnit) + gnDirOffsetY_006DAE88[nDirection];
    const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    if (nBonus > 0)
    {
        nMissile += SEED_RollLimitedRandomNumber(&pUnit->pSeed, nBonus);
    }

    sub_004CDBA0_SubmitOwnerRequest(pUnit, nMissile, nX, nY, nSkillId, nSkillLevel);
    return 1;
}

#include "gen/data/Source/D2Client/004C9490_sub_004C9490_MissileAroundUnit.inc"
