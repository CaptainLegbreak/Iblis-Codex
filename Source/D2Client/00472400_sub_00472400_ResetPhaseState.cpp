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
    int dwAnimMode;
    void* f_14;
    int nAct;
    void* pDrlgAct;
    D2SeedStrc pSeed;
};

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom();                                                     // 0x004646A0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

extern int gnGlobal_007A8998;                                                                               // 0x007A8998
extern int gnGlobal_007A899C;                                                                               // 0x007A899C
extern int gnPhaseMax_007A89C0;                                                                             // 0x007A89C0
extern int gnWeatherAngle_007A89C4;                                                                         // 0x007A89C4
extern int gnGlobal_007A89D8;                                                                               // 0x007A89D8
extern int gnGlobal_007A89DC;                                                                               // 0x007A89DC
extern int gnPhaseLevel_007A89E0;                                                                           // 0x007A89E0
extern int gnTargetAngle_007A89F8;                                                                          // 0x007A89F8
static int gnGlobal_007A8A08;                                                                               // 0x007A8A08
extern int gbWeatherSplash_007A8A14;                                                                        // 0x007A8A14

static __forceinline unsigned int sub_00472400_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00472400
void __cdecl sub_00472400_ResetPhaseState()
{
    int nLevelId = DUNGEON_GetLevelIdFromRoom(sub_004646A0_GetPlayerRoom());
    D2SeedStrc* pSeed = &sub_00463DE0_GetPlayerUnit()->pSeed;

    switch (nLevelId)
    {
    case 109:
    case 110:
    case 111:
    case 112:
        gnGlobal_007A89DC = 42;
        gnGlobal_007A89D8 = 42;
        gnGlobal_007A899C = 170;
        gnGlobal_007A8998 = 170;
        gnPhaseLevel_007A89E0 = gnPhaseMax_007A89C0 = sub_00472280(pSeed, 0x20, 0x38);
        return;

    case 117:
        gnGlobal_007A89D8 = 170;
        gnGlobal_007A8998 = 56;
        gnGlobal_007A89DC = 28;
        gnGlobal_007A899C = 56;
        gnPhaseLevel_007A89E0 = gnPhaseMax_007A89C0 = sub_00472280(pSeed, 0x20, 0x70);
        return;

    case 120:
    case 121:
        gnGlobal_007A89D8 = 28;
        gnGlobal_007A8998 = 28;
        gnGlobal_007A89DC = 28;
        gnGlobal_007A899C = 28;
        gnTargetAngle_007A89F8 = 28;
        gnWeatherAngle_007A89C4 = 28;
        gnPhaseMax_007A89C0 = 0x100;
        gnPhaseLevel_007A89E0 = 0x100;
        return;
    }

    gnPhaseLevel_007A89E0 = gnPhaseMax_007A89C0;
    if (!gbWeatherSplash_007A8A14)
    {
        sub_00472400_SeedStep(pSeed);
        gnGlobal_007A8A08 = 0;
    }
    else
    {
        gnGlobal_007A8A08 = 0;
    }
}
