struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2HirelingTxt
{
    char unk0x00[0x20];
    int dwExpPerLvl;
};

D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel);  // 0x006562F0
int __stdcall MONSTERS_GetHirelingExpForNextLevel(int nLevel, int nExpPerLevel);                            // 0x00663790

// 0x00533A70
__declspec(noinline) int __fastcall PLRSAVE_GetLegacyHirelingExpFactor(unsigned short nHirelingId, int nLevel)
{
    switch (nHirelingId)
    {
    case 0:
    case 1:
        if (nLevel >= 49)
            return 400;
        return (((nLevel < 25) - 1) & 100) + 100;
    case 2:
    case 3:
        return (((nLevel < 49) - 1) & 220) + 220;
    case 4:
    case 5:
    case 12:
    case 13:
    case 14:
    case 21:
    case 23:
        return 480;
    case 6:
    case 7:
    case 8:
        if (nLevel >= 55)
            return 420;
        return (((nLevel < 31) - 1) & 105) + 105;
    case 9:
    case 10:
    case 11:
        return (((nLevel < 55) - 1) & 230) + 230;
    case 15:
    case 17:
        if (nLevel >= 61)
            return 440;
        return (((nLevel < 37) - 1) & 110) + 110;
    case 16:
        if (nLevel >= 61)
            return 260;
        return (((nLevel < 37) - 1) & 115) + 115;
    case 18:
    case 20:
        return (((nLevel < 61) - 1) & 230) + 230;
    case 19:
        return (((nLevel < 61) - 1) & 240) + 240;
    case 22:
        return 500;
    case 24:
    case 25:
        if (nLevel >= 75)
            return 880;
        return (((nLevel < 42) - 1) & 220) + 220;
    case 26:
    case 27:
        return (((nLevel < 75) - 1) & 460) + 460;
    default:
        return 960;
    }
}

// 0x00533BF0
unsigned int __fastcall PLRSAVE_ConvertLegacyHirelingExperience(D2GameStrc* pGame, unsigned short nHirelingId, unsigned int nSavedExperience)
{
    int nLevel = 1;
    while ((unsigned int)((nLevel + 2) * (nLevel + 1) * PLRSAVE_GetLegacyHirelingExpFactor(nHirelingId, nLevel + 1) * 3) <= nSavedExperience && nLevel + 1 < 99)
        ++nLevel;

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
        return nSavedExperience;

    const unsigned int nExperience = MONSTERS_GetHirelingExpForNextLevel(nLevel, pHirelingTxtRecord->dwExpPerLvl);
    if (nExperience <= nSavedExperience)
        return nSavedExperience;

    return nExperience;
}
