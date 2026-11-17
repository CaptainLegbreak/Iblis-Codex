struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

#pragma pack(push, 4)
struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
        unsigned __int64 lSeed;
    };
};
#pragma pack(pop)

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int unk0x04[7];
    D2SeedStrc tSeed;
    int unk0x28[1];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
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
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void* pInitFunc;
    int pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                          // 0x0064A3B0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __fastcall sub_00476A80_StartTiming(int nArg1, int nArg2, int nArg3, int nArg4);                       // 0x00476A80
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_UpdateFrame(D2UnitStrc* pUnit);                                                        // 0x00621310
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
void __stdcall sub_0064A690_SetMissileAnimSpeed(D2UnitStrc* pMissile, int nSpeed);                          // 0x0064A690
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit);         // 0x006505E0

// 0x0045C370
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned __int64 SEED_RollRandomNumber64(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __forceinline unsigned __int64 SEED_RollNext64(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (lPrev >> 32) + 0x6AC690C5i64 * (unsigned int)lPrev;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __forceinline unsigned __int64 SEED_RollNextHL(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (unsigned __int64)(unsigned int)(lPrev >> 32) + (unsigned __int64)(unsigned int)lPrev * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __forceinline unsigned __int64 SEED_RollHL64(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

static __forceinline unsigned int sub_004D2610_SeedRoll(D2SeedStrc* pSeed)
{
    const unsigned int nLowSeed = pSeed->nLowSeed;
    const unsigned int nHighSeed = pSeed->nHighSeed;
    const unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

// 0x004D2520
static void __stdcall sub_004D2520_SpawnBaalBolt(D2UnitStrc* pMissile, int nX, int nY)
{
    if (COLLISION_CheckMaskWithSize(UNITS_GetRoom(pMissile), nX, nY, 3, 1))
    {
        return;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x2001;
    tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tParams.nMissile = SEED_RollRandomNumber(&pMissile->tSeed) % 3 + 0x27B;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nX = nX;
    tParams.nY = nY;

    D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&tParams);
    if (pNewMissile)
    {
        sub_004DA1D0_SetMotionVectorA(pNewMissile, 0, 0, 0xFA);
        sub_004DA200_SetMotionVectorB(pNewMissile, 0, 0, -10, 1);
        MISSILE_SetTotalFrames(pNewMissile, 0x19);
        MISSILE_SetCurrentFrame(pNewMissile, 0x19);
        sub_0064A690_SetMissileAnimSpeed(pNewMissile, 0x80);
    }
}

// 0x004D2610
void __fastcall sub_004D2610_CltDoBaalStorm(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    int bInRange = 0;
    int nLevelId = 0;
    if (pOwner)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOwner));
    }
    switch (nLevelId)
    {
    case 131:
    case 132:
        bInRange = 1;
        break;
    }
    if (!pOwner || !bInRange)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
    UNITS_UpdateFrame(pMissile);

    if (!MISSILE_GetTargetX(pMissile) || !(SEED_RollRandomNumber(&pMissile->tSeed) & 0x3F))
    {
        sub_00476A80_StartTiming(6, 2000, 3000, 2000);
        MISSILE_SetTargetX(pMissile, 1);
    }

    unsigned __int64 lSeed = SEED_RollHL64(&pMissile->tSeed);
    if (!((unsigned int)lSeed % 10))
    {
        lSeed = SEED_RollNextHL(&pMissile->tSeed, lSeed);
        const unsigned int nRollX = (unsigned int)lSeed;
        lSeed = SEED_RollNextHL(&pMissile->tSeed, lSeed);
        const unsigned int nRollY = (unsigned int)lSeed;
        const int nX = CLIENTS_GetUnitX(pMissile) + nRollX % 60 - 30;
        const int nY = CLIENTS_GetUnitY(pMissile) + nRollY % 60 - 30;
        sub_004D2520_SpawnBaalBolt(pMissile, nX, nY);
    }
}

// build: context ?SEED_RollNextHL@@YA_KPAUD2SeedStrc@@_K@Z
// build: context ?SEED_RollHL64@@YA_KPAUD2SeedStrc@@@Z
