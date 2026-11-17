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
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                 // 0x00681EF0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed);                                          // 0x00650E40
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
D2UnitStrc* __fastcall sub_004CD540(D2MissileStrc* pMissileParams);                                         // 0x004CD540

// 0x004CE320
D2UnitStrc* __fastcall sub_004CE320(D2UnitStrc* pMissile, int nRange, int nFrequency, int nMissileId)
{
    if (nFrequency <= 0)
    {
        return 0;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nFrequency)
    {
        return 0;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
    {
        return 0;
    }

    SEED_InitLowSeed(&pMissile->pSeed, CLIENTS_GetUnitX(pMissile) + sub_0064A3B0_GetElapsedFrames(pMissile));

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2003;
    tMissileParams.pOwner = pOwner;
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissileParams.nMissile = nMissileId;

    --nRange;
    const int nOffsetX = nRange - ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange);
    const int nOffsetY = nRange - ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange);
    const int nX = CLIENTS_GetUnitX(pMissile) + nOffsetX;
    tMissileParams.nX = nX;
    const int nY = CLIENTS_GetUnitY(pMissile) + nOffsetY;
    tMissileParams.nY = nY;

    if (COLLISION_CheckMask(pRoom, nX, nY, 4))
    {
        return 0;
    }

    return sub_004CD540(&tMissileParams);
}
