extern const unsigned short gWideTable_006FD1C0[]; // 0x006FD1C0

static __declspec(noinline) int __stdcall sub_006C78C0_ConvertToWide(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount, const unsigned short* pTable);

// 0x006C78C0
static int __stdcall sub_006C78C0_ConvertToWide(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount, const unsigned short* pTable)
{
    if (!nCount)
    {
        return 0;
    }

    unsigned short* pOut = pDest;
    while (*pSource && nCount)
    {
        *pOut++ = pTable[*pSource++];
        --nCount;
    }

    if (nCount)
    {
        *pOut++ = 0;
    }

    return pOut - pDest;
}

// 0x006C79A0
int __stdcall sub_006C79A0_TranslateC(unsigned short* pDest, const unsigned char* pSource, int nCount)
{
    return sub_006C78C0_ConvertToWide(pDest, pSource, nCount, gWideTable_006FD1C0);
}
