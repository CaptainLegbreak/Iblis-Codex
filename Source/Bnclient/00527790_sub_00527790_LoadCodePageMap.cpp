typedef unsigned int size_t;

struct D2LangByteRangeStrc
{
    unsigned char f_0;
    unsigned char f_1;
};

struct D2LangCharMapEntryStrc
{
    unsigned short wValue;
    unsigned short f_2;
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

void __cdecl operator delete[](void* pMemory)
{
    if (pMemory)
    {
        SMemFree(pMemory, "delete[]", -1, 0);
    }
}

void* __cdecl operator new[](size_t nSize)
{
    return SMemAlloc(nSize, "new[]", -1, 0);
}

extern "C" int __cdecl strncmp(const char* szLeft, const char* szRight, size_t nCount);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);
extern "C" char* __cdecl strtok(char* szText, const char* szDelim);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine);
extern "C" const char gszNewline_006FFCB0[];                                                                // 0x006FFCB0
static unsigned short gnCharMapCount_00882B20;                                                              // 0x00882B20
static unsigned char gnLeadByteRangeCount_00882B22;                                                         // 0x00882B22
extern D2LangCharMapEntryStrc* gpCharMap_00882B24;                                                          // 0x00882B24
extern D2LangByteRangeStrc* gpLeadByteRanges_00882B28;                                                      // 0x00882B28
extern unsigned short* gpCharMapIndex_00882B2C;                                                             // 0x00882B2C
char gszCodePageName_00882AF8[0x28];                                                                        // 0x00882AF8

// 0x00527790
int __fastcall sub_00527790_LoadCodePageMap(void* hArchive, const char* szPath)
{
    char szName[0x28];
    unsigned char* pData = (unsigned char*)sub_00517079_LoadFile(hArchive, szPath, 0, ".\\Unicode\\UNISYS.CPP", 0x61);
    if (strncmp((const char*)pData, "KAMAP\n", 5))
    {
        FOG_Free(pData, ".\\Unicode\\UNISYS.CPP", 0x65, 0);
        return 0;
    }

    unsigned char* pCursor = pData + 6;
    int nLen = 0;
    int bFound = 0;
    do
    {
        if (pCursor[nLen] != 0x1A)
        {
            ++nLen;
        }
        else
        {
            bFound = 1;
        }

        if (nLen >= 0x28)
        {
            FOG_Free(pData, ".\\Unicode\\UNISYS.CPP", 0x79, 0);
            return 0;
        }
    }
    while (!bFound);

    strncpy(szName, (const char*)pCursor, nLen + 1);
    szName[nLen + 1] = 0;
    strtok(szName, gszNewline_006FFCB0);

    pCursor += nLen + 5;
    unsigned short* pMapCount = (unsigned short*)pCursor;
    pCursor += 2;
    unsigned char* pRangeCount = pCursor;
    pCursor += 1;

    delete[] gpLeadByteRanges_00882B28;
    D2LangByteRangeStrc* pRanges = new D2LangByteRangeStrc[*pRangeCount];
    gpLeadByteRanges_00882B28 = pRanges;
    if (!pRanges)
    {
        FOG_Free(pData, ".\\Unicode\\UNISYS.CPP", 0x91, 0);
        return 0;
    }

    memcpy(pRanges, pCursor, *pRangeCount * sizeof(D2LangByteRangeStrc));
    pCursor += *pRangeCount * sizeof(D2LangByteRangeStrc);

    delete[] gpCharMap_00882B24;
    D2LangCharMapEntryStrc* pCharMap = new D2LangCharMapEntryStrc[*pMapCount];
    gpCharMap_00882B24 = pCharMap;
    if (!pCharMap)
    {
        FOG_Free(pData, ".\\Unicode\\UNISYS.CPP", 0x9E, 0);
        return 0;
    }

    for (int i = 0; i < *pMapCount; ++i)
    {
        pCharMap[i].wValue = pCursor[0];
        pCharMap[i].f_2 = pCursor[2];
        pCursor += 4;
    }

    delete[] gpCharMapIndex_00882B2C;
    unsigned short* pIndex = new unsigned short[*pMapCount];
    gpCharMapIndex_00882B2C = pIndex;
    if (!pIndex)
    {
        FOG_Free(pData, ".\\Unicode\\UNISYS.CPP", 0xB0, 0);
        return 0;
    }

    for (int i = 0; i < *pMapCount; ++i)
    {
        pIndex[i] = *(unsigned short*)pCursor;
        pCursor += 2;
    }

    gnCharMapCount_00882B20 = *pMapCount;
    gnLeadByteRangeCount_00882B22 = *pRangeCount;
    strcpy(gszCodePageName_00882AF8, szName);
    FOG_Free(pData, ".\\Unicode\\UNISYS.CPP", 0xBE, 0);
    return 1;
}
