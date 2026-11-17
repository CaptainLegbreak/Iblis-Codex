int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590

// 0x00611930
int __fastcall DATATBLS_MapSkillsTxtKeywordToNumber(char* szKey)
{
    if (0 == SStrCmpI(szKey, "min", 32))
    {
        return 0;
    }
    else if (0 == SStrCmpI(szKey, "max", 32))
    {
        return 1;
    }
    else if (0 == SStrCmpI(szKey, "rand", 32))
    {
        return 2;
    }
    else if (0 == SStrCmpI(szKey, "skill", 32))
    {
        return 3;
    }
    else if (0 == SStrCmpI(szKey, "miss", 32))
    {
        return 4;
    }
    else if (0 == SStrCmpI(szKey, "stat", 32))
    {
        return 5;
    }
    else if (0 == SStrCmpI(szKey, "sklvl", 32))
    {
        return 6;
    }
    else
    {
        return -1;
    }
}

// 0x006119E0
int __fastcall sub_006119E0_SkillsCalcParamCount(int nValue)
{
    return (nValue == 6) + 2;
}
