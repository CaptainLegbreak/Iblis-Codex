int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590

// 0x00661800
int __fastcall DATATBLS_MapMissilesTxtKeywordToNumber(char* szKey)
{
    if (!SStrCmpI(szKey, "min", 32))
    {
        return 0;
    }
    else if (!SStrCmpI(szKey, "max", 32))
    {
        return 1;
    }
    else if (!SStrCmpI(szKey, "rand", 32))
    {
        return 2;
    }
    else if (!SStrCmpI(szKey, "skill", 32))
    {
        return 3;
    }
    else if (!SStrCmpI(szKey, "miss", 32))
    {
        return 4;
    }
    else
    {
        return -1;
    }
}
