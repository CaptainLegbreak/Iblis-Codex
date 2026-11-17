struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1C4];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int nLevelId;
};

int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nPickedFile, int a4, int a5); // 0x00674730
int __fastcall DRLGOUTDOORS_SpawnRandomOutdoorDS1(D2DrlgLevelStrc* pLevel, int nLvlPrestId, int nRand);       // 0x00674920

static __forceinline unsigned int SEED_RollRandomNumber_Wild(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x006804E0
static __declspec(noinline) void __stdcall DRLGOUTWILD_SpawnCottage(int bExtraCottage, int nLvlPrestId, D2DrlgLevelStrc* pLevel)
{
    if (SEED_RollRandomNumber_Wild(&pLevel->pSeed) & 3)
    {
        DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, nLvlPrestId, -1);

        if (bExtraCottage && (SEED_RollRandomNumber_Wild(&pLevel->pSeed) & 1))
        {
            DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, 0x31, -1);
        }
    }
    else
    {
        DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, nLvlPrestId, -1);
        DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, nLvlPrestId, -1);
    }
}

void __fastcall sub_M90_Emit_006804E0(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, 0x2E, -1);
    DRLGOUTWILD_SpawnCottage(0, 0x2F, pLevel);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
    DRLGOUTWILD_SpawnCottage(1, 0x30, pLevel);
}
