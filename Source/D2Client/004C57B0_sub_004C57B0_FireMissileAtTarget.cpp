struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned char nMissileFlags[4];
    char unk0x08[0x30];
    int dwParam[5];
    char unk0x4C[0x137];
    unsigned char nCollideType;
    unsigned char nCollision;
    char unk0x185[0x05];
    unsigned char nSize;
    char unk0x18B[0x19];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

struct D2CollideTypeMaskStrc
{
    int nCollisionMask;
    int unk0x04;
};

struct D2LobBracketStrc
{
    int nMaxDistance;
    int nMultiplier;
    int nAddend;
};

struct D2BallisticStrc
{
    unsigned int dwFlags;
    int f_4;
    int f_8;
    int nVelocity;
    int nVelA;
    int nVelB;
    int nStartVelocity;
    int unk0x1C[2];
    int f_24;
    int unk0x28[8];
    int nFrames;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnBitMasks_006CE268[8];                                                                          // 0x006CE268
extern const int gaSpiralOuterY_006DADC0[7];                                                                // 0x006DADC0
extern const int gaSpiralOuterX_006DADE0[7];                                                                // 0x006DADE0
extern const int gaSpiralOuterB_006DAE00[7];                                                                // 0x006DAE00
extern const int gaSpiralInnerY_006DAE1C[4];                                                                // 0x006DAE1C
extern const int gaSpiralOuterA_006DAE2C[7];                                                                // 0x006DAE2C
extern const int gaSpiralInnerX_006DAE48[4];                                                                // 0x006DAE48
extern D2LobBracketStrc gaLobBrackets_006DAE70[2];                                                          // 0x006DAE70
extern D2CollideTypeMaskStrc gaCollideTypeMasks_0072A354[];                                                 // 0x0072A354

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __fastcall sub_004C52E0(D2UnitStrc* pUnit, int* pTargetX, int* pTargetY);                       // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_004CEA00(int nArg1, int nArg2, int nArg3, int nArg4);                                   // 0x004CEA00
void __stdcall sub_004DA000(D2UnitStrc* pUnit);                                                             // 0x004DA000
void __stdcall sub_004DA1D0(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);                            // 0x004DA1D0
void __stdcall sub_004DA200(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5);                 // 0x004DA200
void __stdcall sub_004DA250(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5);                 // 0x004DA250
void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames);                      // 0x004DA5B0
D2BallisticStrc* __fastcall sub_0046F060(D2UnitStrc* pUnit);                                                // 0x0046F060
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0
int __stdcall sub_006444A0(D2UnitStrc* pUnit);                                                              // 0x006444A0
int __stdcall sub_006444D0(D2UnitStrc* pUnit);                                                              // 0x006444D0
int __stdcall sub_006486C0(D2DynamicPathStrc* pDynamicPath);                                                // 0x006486C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                  // 0x00648C30
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall sub_00649D00(int nArg1, int nArg2, int nArg3, int nArg4, D2UnitStrc* pUnit, int nArg6); // 0x00649D00
void __stdcall sub_0064A100(D2UnitStrc* pMissile);                                                          // 0x0064A100
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
unsigned short __stdcall sub_0064D800(D2ActiveRoomStrc* pRoom, int nX, int nY, int nWidth, int nHeight, int nMask); // 0x0064D800

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004C57B0
D2UnitStrc* __fastcall sub_004C57B0_FireMissileAtTarget(int nMissile, D2UnitStrc* pUnit, int nSkill, int nSkillLevel, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = UNITS_GetUnitXPosition(pUnit) + nOffsetX;
    tMissileParams.nY = UNITS_GetUnitYPosition(pUnit) + nOffsetY;
    tMissileParams.nSkill = nSkill;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;

    if (nTargetX && nTargetY)
    {
        tMissileParams.nTargetX = nTargetX;
        tMissileParams.nTargetY = nTargetY;
    }
    else if (!sub_004C52E0(pUnit, &tMissileParams.nTargetX, &tMissileParams.nTargetY))
    {
        return 0;
    }

    if (!tMissileParams.nTargetX || !tMissileParams.nTargetY)
    {
        return 0;
    }

    return sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x004C71F0
void __fastcall sub_004C71F0(int nCount, D2MissileStrc* pMissileParams)
{
    D2_ASSERT((nCount - 1) / 5 <= 7, 0x848);

    pMissileParams->nTargetX = 14;
    pMissileParams->nTargetY = -14;
    sub_004CD540_CreateMissile(pMissileParams);

    int nRemaining = nCount - 1;
    for (int i = 0; i < 7; i++)
    {
        if (!nRemaining)
        {
            break;
        }

        for (int j = 0; j < 4 && nRemaining > 0; j++)
        {
            pMissileParams->nTargetX = gaSpiralInnerX_006DAE48[j] * gaSpiralOuterA_006DAE2C[i];
            pMissileParams->nTargetY = gaSpiralInnerY_006DAE1C[j] * gaSpiralOuterB_006DAE00[i];
            sub_004CD540_CreateMissile(pMissileParams);
            pMissileParams->nTargetX = gaSpiralInnerX_006DAE48[j] * gaSpiralOuterB_006DAE00[i];
            pMissileParams->nTargetY = gaSpiralInnerY_006DAE1C[j] * gaSpiralOuterA_006DAE2C[i];
            sub_004CD540_CreateMissile(pMissileParams);
            nRemaining -= 2;
        }

        pMissileParams->nTargetX = gaSpiralOuterX_006DADE0[i];
        pMissileParams->nTargetY = gaSpiralOuterY_006DADC0[i];
        sub_004CD540_CreateMissile(pMissileParams);
        nRemaining -= 1;
    }
}

// 0x004C7B20
int __fastcall sub_004C7B20(D2UnitStrc* pUnit, int nMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    int nTargetX = 0;
    int nTargetY = 0;

    D2_ASSERT(pMissilesTxtRecord, 0x9BF);

    if (!pRoom)
    {
        return 0;
    }

    sub_004C52E0(pUnit, &nTargetX, &nTargetY);
    if (!nTargetX || !nTargetY)
    {
        return 0;
    }

    return !sub_0064D800(pRoom, nTargetX, nTargetY, pMissilesTxtRecord->nSize, pMissilesTxtRecord->nSize, 5);
}

// 0x004C8670
void __fastcall sub_004C8670_SetLobVelocity(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return;
    }

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return;
    }

    const int nX = sub_006444A0(pTarget);
    const int nY = sub_006444D0(pTarget);
    const int nSpeed = sub_006486C0(pDynamicPath) >> 8;
    if (!nSpeed)
    {
        return;
    }

    int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nX, nY);
    if (nDistance < 1)
    {
        nDistance = 1;
    }

    int nFrames = (nDistance << 0x10) / (nSpeed << 0x0C);
    if (nFrames > 1)
    {
        nFrames -= 1;
    }

    int i = 0;
    for (; i < 1; i++)
    {
        if (nDistance < gaLobBrackets_006DAE70[i].nMaxDistance)
        {
            break;
        }
    }

    int nVelocity = gaLobBrackets_006DAE70[i].nMultiplier * nDistance + gaLobBrackets_006DAE70[i].nAddend;
    if (nVelocity < 0x1F4)
    {
        nVelocity = 0x1F4;
    }

    sub_004DA000(pUnit);
    sub_004DA250(pUnit, 0, 0, -nVelocity, 0);
    sub_004DA5B0_SetBallistic(pUnit, 0, nFrames);
}

// 0x004CD0A0
void __fastcall sub_004CD0A0(D2UnitStrc* pMissile, int nArg, int nTargetX, int nTargetY, int nUnused)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    sub_0064A100(pMissile);
    UNITS_ChangeAnimMode(pMissile, pMissilesTxtRecord->nCollideType);
    sub_00649D00(0, nArg, nTargetX, nTargetY, pMissile, 1);

    D2DynamicPathStrc* pDynamicPath = pMissile->pDynamicPath;
    if (pMissilesTxtRecord->nCollision)
    {
        PATH_SetFootprintCollisionMask(pDynamicPath, 0x40);
    }
    else
    {
        PATH_SetFootprintCollisionMask(pDynamicPath, 0);
    }
    PATH_SetMoveTestCollisionMask(pDynamicPath, gaCollideTypeMasks_0072A354[pMissilesTxtRecord->nCollideType].nCollisionMask);

    if (pMissilesTxtRecord->nMissileFlags[0] & gnBitMasks_006CE268[4])
    {
        pMissile->dwFlags |= 4;
    }
    else
    {
        pMissile->dwFlags &= ~4;
    }

    pMissile->dwFlags = (pMissile->dwFlags & ~0xA) | 0x20;
}

// 0x004CECC0
void __fastcall sub_004CECC0_DispatchPair(int nArg1, int nArg2, int nArg3, int nType)
{
    if ((unsigned int)(nType - 0xC9) <= 0x17)
    {
        sub_004CEA00(nArg1, nArg2, nArg3, 6);
        sub_004CEA00(nArg1, nArg2, nArg3, 6);
        return;
    }

    if (!(nType % 4))
    {
        sub_004CEA00(nArg1, nArg2, nArg3, 0x14);
    }
}

// 0x004D16C0
void __fastcall sub_004D16C0_SpawnOffsetMissile(int nUnitId, int nUnused, D2UnitStrc* pMissile, D2UnitStrc* pOwner)
{
    D2UnitStrc* pFound = sub_00463990(nUnitId, 2);
    if (!pFound)
    {
        return;
    }

    const int nOffsetX = UNITS_GetUnitXPosition(pMissile) - UNITS_GetUnitXPosition(pFound);
    const int nOffsetY = UNITS_GetUnitYPosition(pMissile) - UNITS_GetUnitYPosition(pFound);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pOwner;
    tMissileParams.pOrigin = pMissile;
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissileParams.nMissile = 0x179;

    D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pNewMissile)
    {
        sub_004DA000(pNewMissile);
        sub_004DA1D0(pNewMissile, 0, 0, 0);
        sub_004DA200(pNewMissile, 0, 0, 2, 1);
        sub_004DA250(pNewMissile, 0, 0, 0, 1);
        MISSILE_SetTargetX(pNewMissile, nOffsetX);
        MISSILE_SetTargetY(pNewMissile, nOffsetY);
    }
}

// 0x004DA5B0
void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames)
{
    D2BallisticStrc* pBallistic = sub_0046F060(pUnit);
    if (!pBallistic)
    {
        return;
    }

    pBallistic->dwFlags |= 2;
    pBallistic->nFrames = nFrames;
    if (nFrames < 1)
    {
        pBallistic->nFrames = 1;
    }

    nSpeed <<= 0x0B;
    pBallistic->f_4 = 0;
    pBallistic->f_8 = 0;
    pBallistic->nVelocity = nSpeed;
    if (!pBallistic->f_24)
    {
        pBallistic->f_24 = -0x1000;
    }

    pBallistic->nVelA = 0;
    pBallistic->nVelB = 0;
    pBallistic->nStartVelocity = (-nSpeed - pBallistic->f_24 * pBallistic->nFrames * pBallistic->nFrames / 2) / pBallistic->nFrames;
}

#include "gen/data/Source/D2Client/004C57B0_sub_004C57B0_FireMissileAtTarget.inc"
