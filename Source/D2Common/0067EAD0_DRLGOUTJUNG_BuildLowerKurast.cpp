struct D2DrlgStrc
{
    char unk0x000[0x474];
    int bJungleInterlink;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x24];
    int nWidth;
    int nHeight;
    char unk0x02C[0x188];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x18];
    int nLevelId;
};

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6);   // 0x006743C0
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nPickedFile, int a4, int a5);            // 0x00674730
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel);                                                                // 0x00675770
void __fastcall DRLGOUTJUNG_BuildJungle(D2DrlgLevelStrc* pLevel);       // 0x0067E910
void __fastcall DRLGOUTJUNG_SpawnRandomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nMaxSpawns);   // 0x0067EED0

// 0x0067EAD0
void __fastcall DRLGOUTJUNG_BuildLowerKurast(D2DrlgLevelStrc* pLevel)
{
    int nWidth = pLevel->nWidth / 8 - 1;
    int nHeight = pLevel->nHeight / 8 - 1;
    int nMiddle = nWidth / 2;
    int nGate = 0;

    if (pLevel->pDrlg->bJungleInterlink)
    {
        nGate = 1;
    }
    else
    {
        nGate = nWidth - 1;
    }

    for (int i = 1; i < nWidth; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, 0, (i == nGate) ? 0x25D + 8 : 0x25D, -1, 0);
    }

    for (int i = 1; i < nWidth; i += (i == nMiddle) + 1)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, nHeight, (i == nMiddle) ? 0x25E + 8 : 0x25E, -1, 0);
    }

    for (int i = 1; i < nHeight; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, i, 0x25F, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, i, 0x260, -1, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x262, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, 0, 0x261, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, nHeight, 0x264, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, nHeight, 0x263, -1, 0);
}

// 0x0067EC30
void __fastcall DRLGOUTJUNG_BuildKurastBazaar(D2DrlgLevelStrc* pLevel)
{
    int nWidth = pLevel->nWidth / 8 - 1;
    int nHeight = pLevel->nHeight / 8 - 1;
    int nGateS = pLevel->pDrlg->bJungleInterlink ? 1 : nWidth - 1;
    int nGateN = pLevel->pDrlg->bJungleInterlink ? nWidth - 1 : 1;

    for (int i = 1; i < nWidth; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, 0, (i == nGateN) ? 0x26B + 8 : 0x26B, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, nHeight, (i == nGateS) ? 0x26C + 8 : 0x26C, -1, 0);
    }

    for (int i = 1; i < nHeight; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, i, 0x26D, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, i, 0x26E, -1, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x270, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, 0, 0x26F, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, nHeight, 0x272, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, nHeight, 0x271, -1, 0);
}

// 0x0067ED70
void __fastcall DRLGOUTJUNG_BuildUpperKurast(D2DrlgLevelStrc* pLevel)
{
    int nWidth = pLevel->nWidth / 8 - 1;
    int nHeight = pLevel->nHeight / 8 - 1;
    int nGate = 0;

    if (pLevel->pDrlg->bJungleInterlink)
    {
        nGate = nWidth - 1;
    }
    else
    {
        nGate = 1;
    }

    int nHalf = nWidth / 2;
    for (int i = 1; i < nWidth; i += (i == nHalf) + 1)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, 0, (i == nHalf) ? 0x27C + 8 : 0x27C, -1, 0);
    }

    for (int i = 1; i < nWidth; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, nHeight, (i == nGate) ? 0x27D + 8 : 0x27D, -1, 0);
    }

    for (int i = 1; i < nHeight; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, i, 0x27E, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, i, 0x27F, -1, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x281, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, 0, 0x280, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, nHeight, 0x283, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, nHeight, 0x282, -1, 0);
}

// 0x0067F190
void __fastcall sub_0067F190(D2DrlgLevelStrc* pLevel)
{
    switch (pLevel->nLevelId)
    {
    case 79:
        DRLGOUTJUNG_BuildLowerKurast(pLevel);
        break;

    case 80:
        DRLGOUTJUNG_BuildKurastBazaar(pLevel);
        break;

    case 81:
        DRLGOUTJUNG_BuildUpperKurast(pLevel);
        break;

    default:
        break;
    }

    const int nRight = pLevel->nWidth / 8 - 4;
    const int nBottom = pLevel->nHeight / 8 - 4;

    switch (pLevel->nLevelId)
    {
    case 79:
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x277, 0, 0, 15);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x26A, 0x26A, 4);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x268, 0x269, 0);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x267, 0x267, 0);
        break;

    case 80:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 3, 3, 0x275, 0, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nRight, 3, 0x275, 1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x276, 0, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x276, 1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x277, 0, 0, 15);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x27B, 0x27B, 4);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x279, 0x27A, 0);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x278, 0x278, 0);
        break;

    case 81:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 3, nBottom, 0x286, 0, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nRight, nBottom, 0x286, 1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x287, 0, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x287, 1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x277, 0, 0, 15);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x28B, 0x28B, 4);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x289, 0x28A, 0);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x288, 0x288, 0);
        break;

    case 82:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x28C, 0, 0);
        break;

    default:
        return;
    }
}

// 0x0067F3B0
void __fastcall sub_0067F3B0(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nLevelId == 83)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x28D, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 2, 0, 0x28E, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 6, 0, 0x28F, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 4, 0x290, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 2, 4, 0x291, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 6, 4, 0x292, -1, 0);
    }
}

// 0x0067F450
void __fastcall sub_0067F450(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    DRLGOUTJUNG_BuildJungle(pLevel);
    sub_0067F190(pLevel);
    sub_0067F3B0(pLevel);
}
