struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MonStatsTxt
{
    char unk0x000[0x18];
    short wMonStatsEx;
    char unk0x01A[0x18E];
};

struct D2MonStats2Txt
{
    char unk0x000[0x11D];
    unsigned char nLocalBlood;
    char unk0x11E[0x16];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x0C];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[0x04];
    int nMonStats2TxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gnBloodOffsetY_006DA5F0[];                                                                 // 0x006DA5F0
extern const int gnBloodOffsetX_006DA610[];                                                                 // 0x006DA610

D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit);                                              // 0x00620100
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath);                                            // 0x006486C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

static __forceinline unsigned int sub_M165_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int sub_M165_RollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return sub_M165_SeedStep(pSeed) % nMax;
    }

    return sub_M165_SeedStep(pSeed) & (nMax - 1);
}

static __forceinline D2MonStats2Txt* sub_M165_GetMonStats2Txt(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            const int nMonStatsEx = sgptDataTables->pMonStatsTxt[pUnit->dwClassId].wMonStatsEx;
            if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
            {
                return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
            }
        }
    }

    return 0;
}

static __forceinline int sub_M165_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_M165_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004AF890
void __fastcall sub_004AF890_SpawnBloodMissiles(D2UnitStrc* pUnit, int nDefaultCount, int bRandomChance)
{
    if (bRandomChance && sub_M165_SeedStep(&pUnit->pSeed) % 25)
    {
        return;
    }

    if (pUnit && pUnit->dwUnitType == 1 && pUnit->dwAnimMode == 3 && sub_M165_SeedStep(&pUnit->pSeed) % 3)
    {
        return;
    }

    int nCount = nDefaultCount;
    const int nExtraBlood = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x8C, 0);
    if (nExtraBlood)
    {
        nCount = nExtraBlood;
    }

    D2MonStats2Txt* pMonStats2Txt = sub_M165_GetMonStats2Txt(pUnit);
    if (!pMonStats2Txt || pMonStats2Txt->nLocalBlood <= 0)
    {
        return;
    }

    for (int i = 0; i < nCount; ++i)
    {
        int nDirection;
        if (PATH_GetVelocity(pUnit->pDynamicPath))
        {
            const int nUnitDirection = UNITS_GetDirection(pUnit) >> 3;
            nDirection = (nUnitDirection + sub_M165_SeedStep(&pUnit->pSeed) % 7 - 3) & 7;
        }
        else
        {
            nDirection = sub_M165_RollLimited(&pUnit->pSeed, 8);
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        int nDir = nDirection;
        const int nLastDirection = (nDirection - 1) & 7;
        int nX;
        int nY;
        if (nDir == nLastDirection)
        {
            return;
        }

        do
        {
            nX = gnBloodOffsetX_006DA610[nDir] + sub_M165_UnitX(pUnit);
            nY = gnBloodOffsetY_006DA5F0[nDir] + sub_M165_UnitY(pUnit);
            if (!COLLISION_CheckMask(pRoom, nX, nY, 1))
            {
                goto LABEL_SPAWN;
            }

            nDir = (nDir + 1) & 7;
        }
        while (nDir != nLastDirection);

        return;

LABEL_SPAWN:
        sub_004CDBA0_SubmitOwnerRequest(pUnit, 0x12 + sub_M165_RollLimited(&pUnit->pSeed, 2 * pMonStats2Txt->nLocalBlood), nX, nY, 0, 1);
    }
}

#include "gen/data/Source/D2Client/004AF890_sub_004AF890_SpawnBloodMissiles.inc"
