#include "D2Lang.h"

#include "D2LangTypes.h"
#include "D2Unicode.h"

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

void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine);

extern "C" const char gszNewline[];                                                                // 0x006FFCB0

static unsigned short gnCharMapCount;                                                              // 0x00882B20

static unsigned char gnLeadByteRangeCount;                                                         // 0x00882B22

extern D2LangByteRangeStrc* gpLeadByteRanges;                                                      // 0x00882B28

extern unsigned short* gpCharMapIndex;                                                             // 0x00882B2C

char gszCodePageName[0x28];                                                                        // 0x00882AF8

void __cdecl operator delete[](void* pMemory); // 0x00527660
D2LangByteRangeStrc* gpLeadByteRanges; // 0x00882B28
unsigned short* gpCharMapIndex; // 0x00882B2C

int sub_005276E0_IsLeadByte(unsigned char nByte); // 0x005276E0

static __forceinline int sub_00527A50_FindIndex(const D2LangCharMapEntryStrc* pMap, unsigned short wChar)
{
    int nLow = 0;
    int nHigh = gnCharMapCount - 1;
// build: symbol ?gpCharMapIndex@* 0x00882B2C
    if (wChar < pMap[gpCharMapIndex[0]].wValue)
        return -1;
    if (wChar > pMap[gpCharMapIndex[nHigh]].wValue)
        return -1;
    if (wChar == pMap[gpCharMapIndex[nHigh]].wValue)
        return nHigh;
    int nMid = nHigh >> 1;
    do
    {
        if (wChar < pMap[gpCharMapIndex[nMid]].wValue)
            nHigh = nMid;
        else
            nLow = nMid;
        nMid = (nHigh + nLow) >> 1;
    } while (nHigh - nLow > 1);
    if (pMap[gpCharMapIndex[nMid]].wValue != wChar)
        return -1;
    return nMid;
}

// 0x00527A50
static int UNISYS_MapCodePageChar(unsigned short wChar)
{
    if (wChar < 0x20)
        return wChar;
    const int nIndex = sub_00527A50_FindIndex(gpCharMap, wChar);
    if (nIndex < 0)
        return -1;
    return gpCharMap[gpCharMapIndex[nIndex]].f_2;
}

// 0x00527B50
Unicode* __fastcall sub_00527B50_CodePageToUnicode(Unicode* pDest, const char* szSrc, int nCount)
{
    if (!gpCharMapIndex)
    {
        return sub_00526F20_ToUnicode(pDest, szSrc, nCount);
    }
    int i = 0;
    for (; i < nCount; ++i)
    {
        const unsigned char nByte = *szSrc;
        if (!nByte)
        {
            goto terminate;
        }
        unsigned short wChar;
        if (sub_005276E0_IsLeadByte(nByte))
        {
            wChar = (unsigned short)((nByte << 8) | (unsigned char)szSrc[1]);
            szSrc += 2;
        }
        else
        {
            wChar = nByte;
            ++szSrc;
        }
        const int nUnicode = UNISYS_MapCodePageChar(wChar);
        if (nUnicode < 0)
        {
            --i;
        }
        else
        {
            pDest[i].wChar = nUnicode;
        }
    }
    if (*szSrc)
    {
        return pDest;
    }
terminate:
    if (i < nCount)
    {
        pDest[i].wChar = 0;
    }
    return pDest;
}

// 0x00527720
void __cdecl UNISYS_FreeCodePageTables()
{
    if (gpLeadByteRanges)
    {
        SMemFree(gpLeadByteRanges, "delete[]", -1, 0);
        gpLeadByteRanges = 0;
    }
// build: symbol ?gpCharMap@* 0x00882B24
    if (gpCharMap)
    {
        SMemFree(gpCharMap, "delete[]", -1, 0);
        gpCharMap = 0;
    }
    if (gpCharMapIndex)
    {
        SMemFree(gpCharMapIndex, "delete[]", -1, 0);
        gpCharMapIndex = 0;
    }
}

// 0x00527790
int __fastcall UNISYS_LoadSysMap(void* hArchive, const char* szPath)
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
    strtok(szName, gszNewline);

    pCursor += nLen + 5;
    unsigned short* pMapCount = (unsigned short*)pCursor;
    pCursor += 2;
    unsigned char* pRangeCount = pCursor;
    pCursor += 1;

    delete[] gpLeadByteRanges;
    D2LangByteRangeStrc* pRanges = new D2LangByteRangeStrc[*pRangeCount];
    gpLeadByteRanges = pRanges;
    if (!pRanges)
    {
        FOG_Free(pData, ".\\Unicode\\UNISYS.CPP", 0x91, 0);
        return 0;
    }

    memcpy(pRanges, pCursor, *pRangeCount * sizeof(D2LangByteRangeStrc));
    pCursor += *pRangeCount * sizeof(D2LangByteRangeStrc);

// build: symbol ?gpCharMap@* 0x00882B24
    delete[] gpCharMap;
    D2LangCharMapEntryStrc* pCharMap = new D2LangCharMapEntryStrc[*pMapCount];
    gpCharMap = pCharMap;
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

    delete[] gpCharMapIndex;
    unsigned short* pIndex = new unsigned short[*pMapCount];
    gpCharMapIndex = pIndex;
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

    gnCharMapCount = *pMapCount;
    gnLeadByteRangeCount = *pRangeCount;
    strcpy(gszCodePageName, szName);
    FOG_Free(pData, ".\\Unicode\\UNISYS.CPP", 0xBE, 0);
    return 1;
}
