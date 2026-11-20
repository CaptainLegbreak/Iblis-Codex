struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
};

struct D2DrlgLevelStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    D2DrlgOutdoorInfoStrc* pOutdoorInfo;
    char unk0x18[0x1B8];
    int eLevelId;
};

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6);  // 0x006743C0
int __fastcall sub_00674730(D2DrlgLevelStrc* pLevel, int nPresetId, int nArg, int a4, int a5);          // 0x00674730
void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nIndex, int nPresetId);                     // 0x006752A0
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel);                                                  // 0x00675770
void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel);                                                  // 0x00675850

static const int gAct4SecondPresetBase[3] = { 828, 832, 832 }; // 0x006F22A4

static const int gAct4FirstPresetBase[3] = { 812, 817, 823 }; // 0x006F22B0

static const int gAct4Level108Presets[25] = // 0x006F22C0
{
    836, 836, 836, 836, 836,
    836, 836, 861, 836, 836,
    836, 858, 862, 859, 836,
    836, 836, 860, 836, 836,
    836, 836, 857, 836, 836,
};

// 0x0067E660
static void sub_0067E660(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    if (pInfo->dwFlags & 0x400000)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 1, 0x31E, -1, 0);
    }
    if (pInfo->dwFlags & 0x800000)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 4, 0x31E, -1, 0);
    }
}

// 0x0067E6A0
static void sub_0067E6A0(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == 106)
    {
        sub_00674730(pLevel, 0x32B, -1, 0, 15);
    }

    int nFirst = gAct4FirstPresetBase[pLevel->eLevelId - 104];
    int nSecond = gAct4SecondPresetBase[pLevel->eLevelId - 104];

    sub_00674730(pLevel, nFirst, -1, 0, 15);
    sub_00674730(pLevel, nFirst + 1, -1, 0, 15);
    sub_00674730(pLevel, nFirst + 1, -1, 0, 15);
    sub_00674730(pLevel, nFirst + 2, -1, 0, 15);
    sub_00674730(pLevel, nFirst + 2, -1, 0, 15);
    sub_00674730(pLevel, nFirst + 3, -1, 0, 15);
    sub_00674730(pLevel, nFirst + 3, -1, 0, 15);

    if (pLevel->eLevelId == 105)
    {
        sub_00674730(pLevel, 0x336, -1, 0, 15);
    }

    sub_00674730(pLevel, nFirst + 4, -1, 0, 15);
    sub_00674730(pLevel, nFirst + 4, -1, 0, 15);
    sub_00674730(pLevel, nFirst + 4, -1, 0, 15);
    sub_00674730(pLevel, nFirst + 4, -1, 0, 15);

    sub_00674730(pLevel, nSecond, -1, 0, 15);
    sub_00674730(pLevel, nSecond + 1, -1, 0, 15);
    sub_00674730(pLevel, nSecond + 1, -1, 0, 15);
    sub_00674730(pLevel, nSecond + 2, -1, 0, 15);
    sub_00674730(pLevel, nSecond + 2, -1, 0, 15);
    sub_00674730(pLevel, nSecond + 3, -1, 0, 15);
    sub_00674730(pLevel, nSecond + 3, -1, 0, 15);
    sub_00674730(pLevel, nSecond + 3, -1, 0, 15);
    sub_00674730(pLevel, nSecond + 3, -1, 0, 15);
}

// 0x0067E840
static void sub_0067E840(D2DrlgLevelStrc* pLevel)
{
    for (int i = 0; i < 25; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, (i % 5) * 3, (i / 5) * 3, gAct4Level108Presets[i], -1, 0);
    }
}

// 0x0067E890
void __fastcall sub_0067E890(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == 108)
    {
        DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    }
    else
    {
        DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
        DRLGOUTPLACE_PlaceAct1245OutdoorBorders(pLevel);
    }

    switch (pLevel->eLevelId)
    {
    case 104:
    case 105:
    case 106:
        sub_0067E660(pLevel);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 1, 0x31F);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 0x31F);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 0x31F);
        sub_0067E6A0(pLevel);
        break;

    case 108:
        sub_0067E840(pLevel);
        break;
    }
}
