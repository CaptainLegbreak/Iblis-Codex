extern unsigned int* gpCryptTable_00779048;                                                                 // 0x00779048
void* __stdcall SMemAlloc(int nSize, const char* szFile, int nLine, int nFlags);                            // 0x00413020

static void sub_00415390_PrepareCryptTable(unsigned int dwSeed)
{
    if (!gpCryptTable_00779048)
    {
        gpCryptTable_00779048 = (unsigned int*)SMemAlloc(0x1400, ".\\SOURCE\\SFILE.CPP", 832, 0);
    }

    unsigned int* pTable = gpCryptTable_00779048;
    for (int i = 0; i < 0x100; ++i)
    {
        unsigned int* pEntry = &pTable[i];
        for (int j = 0; j < 5; ++j)
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            const unsigned int dwHigh = (dwSeed & 0xFFFF) << 16;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            const unsigned int dwLow = dwSeed & 0xFFFF;
            *pEntry = dwHigh | dwLow;
            pEntry += 0x100;
        }
    }
}

// 0x00415B90
void __cdecl sub_00415B90_InitCryptTable()
{
    if (!gpCryptTable_00779048)
    {
        sub_00415390_PrepareCryptTable(0x100001);
    }
}
