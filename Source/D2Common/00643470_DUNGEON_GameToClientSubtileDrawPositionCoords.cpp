struct D2SkillsTxt
{
    char unk0x00[0x14];
    signed char nRange;
    char unk0x15[0x23C - 0x15];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x34 - 0x08];
    int nOwnerGUID;
    int nCharges;
    int bExcludeFromHighestLevelLookup;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
    D2SkillStrc* pLeftSkill;
    D2SkillStrc* pRightSkill;
    D2SkillStrc* pUsedSkill;
    void* unk014;
};

struct D2DynamicPathStrc
{
    char unk0x00[0x24];
    int dwCurrentPointIdx;
    int dwPathPoints;
    char unk0x2C[0x34 - 0x2C];
    unsigned int dwFlags;
    char unk0x38[0x64 - 0x38];
    unsigned char nDirection;
    unsigned char nNewDirection;
    unsigned char nDiffDirection;
    char unk0x67[0x72 - 0x67];
    char tVelocityVector[8];
    char unk0x7A[0x84 - 0x7A];
    int dwMaxVelocity;
    int dwAcceleration;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    char unk0x0C[0x2C - 0x0C];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0xA8 - 0x30];
    D2SkillListStrc* pSkills;
};

struct D2SkillCalcStrc
{
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
};

struct D2ItemCalcStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pItem;
};

struct D2MonStatsTxt
{
    char unk0x00[0x18];
    short wMonStatsEx;
    char unk0x1A[0x1A8 - 0x1A];
};

struct D2MonStats2Txt
{
    int dwId;
    unsigned char nFlags[4];
    signed char nSizeX;
    char unk0x09[0x134 - 0x09];
};

struct D2DataTablesStrc
{
    char unk0x00[0x4C];
    char* pSkillDescCode;
    unsigned int nSkillDescCodeSize;
    char unk0x54[0xA78 - 0x54];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xA90 - 0xA84];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[4];
    int nMonStats2TxtRecordCount;
    char unk0xA9C[0xBD4 - 0xA9C];
    int nItemStatCostTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern const int gaCollisionPatternsFromSize[4];                                                            // 0x006EB3DC
extern void* gpSkillsCalcFunctions[];                                                                       // 0x00745774
extern int gnSkillsCalcFunctions;                                                                           // 0x007457AC
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc* pUnit);                                        // 0x004DC0B0
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);                                                   // 0x00622560
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit);                                                      // 0x00622D00
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY);                                                // 0x00643290
int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel);  // 0x00646460
int __fastcall sub_00646BE0(int nParamId, void* pUserData);                                  // 0x00646BE0
int __stdcall MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nParamId, int nMissileId, int nLevel); // 0x0064B340
int __stdcall DATATBLS_CalcEvaluateExpression(char* pCode, unsigned int nSize, int (__fastcall* pfParam)(int, void*), void** pFuncs, int nFuncs, void* pUserData); // 0x006C0BC0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2UnitInvalidGUID -1
#define STAT_TOHIT 19
#define COLLISION_UNIT_SIZE_COUNT 4
#define COLLISION_PATTERN_SMALL_UNIT_PRESENCE 1
#define COLLISION_PATTERN_BIG_UNIT_PRESENCE 2
#define COLLISION_PATTERN_SMALL_PET_PRESENCE 3
#define COLLISION_PATTERN_BIG_PET_PRESENCE 4
#define MONSTATS2FLAGINDEX_REVIVE 8
#define MONSTATS2FLAGINDEX_ISATT 9
#define MONSTATS2FLAGINDEX_SMALL 10
#define PATH_UNKNOWN_FLAG_0x00020 0x20
#define PATH_UNKNOWN_FLAG_0x00040 0x40

// build: context UNITS_GetMonStats2TxtRecordFromMonsterId_Inl
inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x00643470
void __stdcall DUNGEON_GameToClientSubtileDrawPositionCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = 16 * (nX - nY);
    *pY = 8 * (nX + nY);
    *pX -= 16;
    *pY += 16;
}

// 0x006434A0
void __stdcall sub_006434A0_GameTileToSubtileCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = nX * 5;
    *pY = nY * 5;
}

// 0x006434C0
void __stdcall sub_006434C0_GameSubtileToTileCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = nX / 5;
    if (nX < 0)
    {
        *pX = nX / 5 - 1;
    }
    *pY = nY / 5;
    if (nY < 0)
    {
        *pY = nY / 5 - 1;
    }
}

// 0x00643740
int __fastcall sub_00643740_SkillCalcMissileParam(int nMissileId, int nParamId, int nUnused, void* pUserData)
{
    D2SkillCalcStrc* pSkillCalc = (D2SkillCalcStrc*)pUserData;
    if (!pSkillCalc)
    {
        return 0;
    }

    return MISSILE_GetSpecialParamValue(0, pSkillCalc->pUnit, nParamId, nMissileId, pSkillCalc->nSkillLevel);
}

// 0x00643770
int __fastcall sub_00643770_ItemCalcStatParam(int nStatId, int nType, int nUnused, void* pUserData)
{
    D2ItemCalcStrc* pItemCalc = (D2ItemCalcStrc*)pUserData;
    if (pItemCalc && pItemCalc->pUnit && nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        if (nStatId == STAT_TOHIT)
        {
            return UNITS_GetAttackRate(pItemCalc->pUnit);
        }

        switch (nType)
        {
        case 1:
            return STATLIST_GetUnitBaseStat(pItemCalc->pUnit, nStatId, 0);
        case 2:
            return STATLIST_UnitGetItemStatOrSkillStatValue(pItemCalc->pUnit, nStatId, 0);
        default:
            return STATLIST_UnitGetStatValue(pItemCalc->pUnit, nStatId, 0);
        }
    }

    return 0;
}

// 0x00643890
int __stdcall SKILLS_GetRange(D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    if (!pSkill->pSkillsTxt)
    {
        return 0;
    }

    return pSkill->pSkillsTxt->nRange;
}

// 0x006438B0
D2SkillListStrc* __stdcall SKILLS_AllocSkillList(void* pMemPool)
{
    D2SkillListStrc* pSkillList = (D2SkillListStrc*)sub_0040B430(pMemPool, sizeof(D2SkillListStrc), ".\\SKILLS\\Skills.cpp", 895, 0);
    memset(pSkillList, 0x00, sizeof(D2SkillListStrc));
    pSkillList->pMemPool = pMemPool;
    return pSkillList;
}

// 0x00643A30
void* __stdcall D2Common_10959(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pUnit->pSkills)
    {
        return 0;
    }

    return pUnit->pSkills->unk014;
}

// 0x00643A60
void __stdcall SKILLS_FreeSkillList(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2SkillListStrc* pSkillList = pUnit->pSkills;
        if (pSkillList)
        {
            D2SkillStrc* pSkill = pSkillList->pFirstSkill;
            while (pSkill)
            {
                D2SkillStrc* pNextSkill = pSkill->pNextSkill;
                sub_0040B480(sub_004DC0B0_GetUnitMemoryPool(pUnit), pSkill, ".\\SKILLS\\Skills.cpp", 1285, 0);
                pSkill = pNextSkill;
            }

            sub_0040B480(pUnit->pMemoryPool, pSkillList, ".\\SKILLS\\Skills.cpp", 1288, 0);
            pUnit->pSkills = 0;
        }
    }
}

// 0x00643AD0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill)
{
    D2_ASSERT(pSkill, 1591);

    return pSkill->nOwnerGUID;
}

// 0x00643B70
int __stdcall SKILLS_SetCharges(D2SkillStrc* pSkill, int nCharges)
{
    D2_ASSERT(pSkill, 1623);

    if (pSkill->nOwnerGUID == D2UnitInvalidGUID)
    {
        return 0;
    }
    else
    {
        pSkill->bExcludeFromHighestLevelLookup = 1;
        pSkill->nCharges = nCharges;
        return 1;
    }
}

// 0x00645A90
int __fastcall sub_00645A90_GetDiminishingValue(int nLevel, int nMin, int nMax)
{
    int nValue = nMin + (nMax - nMin) * (110 * nLevel / (nLevel + 6)) / 100;
    int nPrevValue = nMin + (nMax - nMin) * (110 * (nLevel - 1) / (nLevel - 1 + 6)) / 100;

    if (nValue <= nPrevValue + 1)
    {
        return sub_00645A90_GetDiminishingValue(nLevel - 1, nMin, nMax) + 1;
    }

    if (nValue > nMax)
    {
        nValue = nMax;
    }

    return nValue;
}

// 0x00646C60
int __fastcall sub_00646C60_SkillCalcNestedParam(int nSkillId, int a2, int a3, void* pUserData)
{
    D2SkillCalcStrc* pSkillCalc = (D2SkillCalcStrc*)pUserData;
    if (!pSkillCalc)
    {
        return 0;
    }

    return SKILLS_GetSpecialParamValue(pSkillCalc->pUnit, a3, nSkillId, SKILLS_GetSpecialParamValue(pSkillCalc->pUnit, a2, pSkillCalc->nSkillId, pSkillCalc->nSkillLevel));
}

// 0x00646D00
int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
{
    D2SkillCalcStrc pSkillCalc;

    if (!sgptDataTables->pSkillDescCode)
    {
        return 0;
    }

    if (nCalc >= sgptDataTables->nSkillDescCodeSize)
    {
        return 0;
    }

    pSkillCalc.pUnit = pUnit;
    pSkillCalc.nSkillId = nSkillId;
    pSkillCalc.nSkillLevel = nSkillLevel;

    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pSkillDescCode[nCalc], sgptDataTables->nSkillDescCodeSize - nCalc, sub_00646BE0, gpSkillsCalcFunctions, gnSkillsCalcFunctions, &pSkillCalc);
}

// 0x00648300
void __stdcall PATH_GetClientCoordsVelocity(D2UnitStrc* pUnit, int* pX, int* pY)
{
    if (pUnit && UNITS_IsInMovingMode(pUnit))
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        if (pDynamicPath->dwPathPoints)
        {
            *pX = *(int*)&pDynamicPath->tVelocityVector[0];
            *pY = *(int*)&pDynamicPath->tVelocityVector[4];
            *pX >>= 11;
            *pY >>= 11;
            DUNGEON_GameToClientCoords(pX, pY);
        }
        else
        {
            *pX = 0;
            *pY = 0;
        }
    }
    else
    {
        *pX = 0;
        *pY = 0;
    }
}

// 0x00648460
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath)
{
    sub_0040B480(pMemPool, pDynamicPath, ".\\PATH\\Path.cpp", 985, 0);
}

// 0x006484E0
int __stdcall PATH_GetCollisionPatternFromMonStats2Txt(int nMonsterId)
{
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(nMonsterId);
    if (pMonStats2TxtRecord)
    {
        int nSizeX = pMonStats2TxtRecord->nSizeX;
        if (nSizeX >= 0 && nSizeX < COLLISION_UNIT_SIZE_COUNT)
        {
            int nCollisionPattern = gaCollisionPatternsFromSize[nSizeX];

            if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_REVIVE >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_REVIVE & 7]
                || pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_SMALL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_SMALL & 7])
            {
                if (!(pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_ISATT >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_ISATT & 7]))
                {
                    switch (nCollisionPattern)
                    {
                    case COLLISION_PATTERN_SMALL_UNIT_PRESENCE:
                        nCollisionPattern = COLLISION_PATTERN_SMALL_PET_PRESENCE;
                        break;
                    case COLLISION_PATTERN_BIG_UNIT_PRESENCE:
                        nCollisionPattern = COLLISION_PATTERN_BIG_PET_PRESENCE;
                        break;
                    }
                }
            }

            return nCollisionPattern;
        }
    }

    return COLLISION_PATTERN_SMALL_UNIT_PRESENCE;
}

// 0x00648640
void __stdcall D2COMMON_10193_PATH_AdjustDirection(D2DynamicPathStrc* pDynamicPath)
{
    if ((pDynamicPath->nDirection != pDynamicPath->nNewDirection) && !(pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x00040))
    {
        pDynamicPath->nDirection = (pDynamicPath->nDirection + pDynamicPath->nDiffDirection) & 63;

        const unsigned char dirDiff = (pDynamicPath->nDirection - pDynamicPath->nNewDirection) & 63;
        if ((dirDiff > 31 && pDynamicPath->nDiffDirection > 63) || (dirDiff < 31 && pDynamicPath->nDiffDirection < 63))
        {
            pDynamicPath->nDirection = pDynamicPath->nNewDirection;
        }
    }
}

// 0x006486F0
int __stdcall PATH_GetMaxVelocity(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwMaxVelocity;
}

// 0x00648720
int __stdcall PATH_GetAcceleration(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwAcceleration;
}

// 0x00648770
int __stdcall D2COMMON_10209_PathCheckPathingFlag(D2DynamicPathStrc* pDynamicPath)
{
    return (pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x00020);
}

// 0x006487C0
int __stdcall D2Common_10155(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwCurrentPointIdx;
}

#include "gen/data/Source/D2Common/00643470_DUNGEON_GameToClientSubtileDrawPositionCoords.inc"
