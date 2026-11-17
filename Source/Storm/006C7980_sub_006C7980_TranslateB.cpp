extern const unsigned short gawTranslateTable_006FCFC0[]; // 0x006FCFC0

static __declspec(noinline) int __cdecl sub_006C78C0_Translate(const unsigned short* pTable, unsigned short* pDest, const unsigned char* pSource, int nCount);

// 0x006C78C0
static int __cdecl sub_006C78C0_Translate(const unsigned short* pTable, unsigned short* pDest, const unsigned char* pSource, int nCount)
{
    if (!nCount)
    {
        return 0;
    }

    unsigned short* pWrite = pDest;
    while (*pSource)
    {
        if (!nCount)
        {
            return pWrite - pDest;
        }
        *pWrite = pTable[*pSource];
        ++pSource;
        ++pWrite;
        --nCount;
    }

    if (nCount)
    {
        *pWrite = 0;
        ++pWrite;
    }
    return pWrite - pDest;
}

// 0x006C7980
int __stdcall sub_006C7980_TranslateB(unsigned short* pDest, const unsigned char* pSource, int nCount)
{
    return sub_006C78C0_Translate(gawTranslateTable_006FCFC0, pDest, pSource, nCount);
}
