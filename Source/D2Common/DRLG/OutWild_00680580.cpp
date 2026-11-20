#include "D2Structs.h"
#define LEVEL_BLOODMOOR 2
#define LEVEL_COLDPLAINS 3
#define LEVEL_STONYFIELD 4
#define LEVEL_DARKWOOD 5
#define LEVEL_BLACKMARSH 6
#define LEVEL_TAMOEHIGHLAND 7
#define LEVEL_BURIALGROUNDS 17
#define LEVEL_MOOMOOFARM 39


struct D2DrlgLevelStrc
{
    char unk0x000[0x1C4];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int eLevelId;
};

#define C07_OFFSET_CHECK(name, type, field, offset) typedef char name[((unsigned int)&((type*)0)->field == (offset)) ? 1 : -1]
C07_OFFSET_CHECK(C07_check_pSeed, D2DrlgLevelStrc, pSeed, 0x1C4);
C07_OFFSET_CHECK(C07_check_nHighSeed, D2DrlgLevelStrc, pSeed.nHighSeed, 0x1C8);
C07_OFFSET_CHECK(C07_check_nLevelId, D2DrlgLevelStrc, eLevelId, 0x1D0);

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730
int __fastcall sub_00674920_PlaceRandomPreset(D2DrlgLevelStrc* pLevel, int nLvlPrestId, int nRand);       // 0x00674920
void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines);                      // 0x00674E40

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
        sub_00674920_PlaceRandomPreset(pLevel, nLvlPrestId, -1);

        if (bExtraCottage && (SEED_RollRandomNumber_Wild(&pLevel->pSeed) & 1))
        {
            sub_00674920_PlaceRandomPreset(pLevel, 0x31, -1);
        }
    }
    else
    {
        sub_00674920_PlaceRandomPreset(pLevel, nLvlPrestId, -1);
        sub_00674920_PlaceRandomPreset(pLevel, nLvlPrestId, -1);
    }
}

// 0x00680580
static __declspec(noinline) void DRLGOUTWILD_SpawnSpecialPresets(D2DrlgLevelStrc* pLevel)
{
    switch (pLevel->eLevelId)
    {
    case LEVEL_BLOODMOOR:
        sub_00674920_PlaceRandomPreset(pLevel, 0x2E, -1);
        DRLGOUTWILD_SpawnCottage(0, 0x2F, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    case LEVEL_COLDPLAINS:
        DRLGOUTWILD_SpawnCottage(1, 0x30, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x2C, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    case LEVEL_STONYFIELD:
        sub_00674920_PlaceRandomPreset(pLevel, 0xA0, -1);
        sub_00674920_PlaceRandomPreset(pLevel, 0x2D, -1);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0xA2, -1, 0, 15);
        DRLGOUTWILD_SpawnCottage(1, 0x2F, pLevel);
        DRLGOUTWILD_SpawnCottage(0, 0x2A, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1F, -1, 0, 15);
        return;

    case LEVEL_DARKWOOD:
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0xA1, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x29, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x28, -1, 0, 15);
        DRLGOUTWILD_SpawnCottage(1, 0x30, pLevel);
        DRLGOUTWILD_SpawnCottage(0, 0x2B, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    case LEVEL_BLACKMARSH:
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0xA3, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x26, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x27, -1, 0, 15);
        DRLGOUTWILD_SpawnCottage(1, 0x2F, pLevel);
        DRLGOUTWILD_SpawnCottage(0, 0x2A, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    case LEVEL_TAMOEHIGHLAND:
        DRLGOUTWILD_SpawnCottage(1, 0x30, pLevel);
        DRLGOUTWILD_SpawnCottage(0, 0x2B, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1F, -1, 0, 15);
        return;

    case LEVEL_BURIALGROUNDS:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 1, 1, 0x6C, -1, 0);
        return;

    case LEVEL_MOOMOOFARM:
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x32, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x2E, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1F, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x26, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x27, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    default:
        return;
    }
}

void __fastcall sub_C07_Emit_00680580(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
    DRLGOUTWILD_SpawnSpecialPresets(pLevel);
}
