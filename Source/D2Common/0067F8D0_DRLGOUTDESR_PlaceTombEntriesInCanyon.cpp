struct D2DrlgLevelStrc;

struct D2DrlgOutDesertInitStrc
{
    int nLvlPrestId;
    int nRand;
    int nX;
    int nY;
};

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0
void __fastcall DRLGOUTDESR_InitAct2OutdoorLevel(D2DrlgLevelStrc* pLevel);                                   // 0x0067F980

extern const D2DrlgOutDesertInitStrc gaTombEntries_006F2610[9];                                             // 0x006F2610

// 0x0067F8D0
static __declspec(noinline) void DRLGOUTDESR_PlaceTombEntriesInCanyon(D2DrlgLevelStrc* pLevel)
{
    for (int i = 0; i < 9; ++i)
    {
        const D2DrlgOutDesertInitStrc* pInit = &gaTombEntries_006F2610[i];
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pInit->nX, pInit->nY, pInit->nLvlPrestId, pInit->nRand, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 4, 4, 0x18A, -1, 0);
}

void __fastcall sub_I19_Emit_0067F8D0(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
    DRLGOUTDESR_PlaceTombEntriesInCanyon(pLevel);
    DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
}

#include "gen/data/Source/D2Common/0067F8D0_DRLGOUTDESR_PlaceTombEntriesInCanyon.inc"
