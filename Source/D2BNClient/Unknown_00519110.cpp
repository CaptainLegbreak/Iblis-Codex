#include "D2BNClient.h"

struct D2CacheHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwHeaderSize;
    unsigned int dwFileSize;
    unsigned int unk0x0C;
    unsigned int dwHashOffset;
    unsigned int dwBlockOffset;
    unsigned int nHashTableSize;
};

extern unsigned int* gpCacheTable_00881888; // 0x00881888
extern D2CacheHeaderStrc* gpCacheHeader_00881880; // 0x00881880
extern D2CacheHashEntryStrc* gpCacheHashTable_0088188C; // 0x0088188C

// 0x00518FA0
static unsigned int __stdcall sub_00518FA0_HashString(unsigned int nHashType, const char* szString)
{
    unsigned int dwSeed1 = 0x7FED7FED;
    unsigned int dwSeed2 = 0xEEEEEEEE;
    while (szString && *szString)
    {
        char ch = (char)toupper(*szString++);
        dwSeed1 = gpCacheTable_00881888[(nHashType << 8) + ch] ^ (dwSeed1 + dwSeed2);
        dwSeed2 = ch + dwSeed1 + dwSeed2 + (dwSeed2 << 5) + 3;
    }
    return dwSeed1;
}

__declspec(noinline) static int __stdcall sub_00519110_FindHashEntry(const char* szName, unsigned int dwLocale);

// 0x00519110
static int __stdcall sub_00519110_FindHashEntry(const char* szName, unsigned int dwLocale)
{
    unsigned int dwHash = sub_00518FA0_HashString(0, szName);
    unsigned int dwNameA = sub_00518FA0_HashString(1, szName);
    unsigned int dwNameB = sub_00518FA0_HashString(2, szName);
    unsigned int nSize = gpCacheHeader_00881880->nHashTableSize;
    unsigned int dwIndex = dwHash & (nSize - 1);
    D2CacheHashEntryStrc* pTable = gpCacheHashTable_0088188C;
    unsigned int dwStart = dwIndex;
    int nFallback = -1;

    unsigned int dwBlock;
    while ((dwBlock = pTable[dwIndex].dwBlockIndex) != (unsigned int)-1)
    {
        if (pTable[dwIndex].dwNameA == dwNameA && pTable[dwIndex].dwNameB == dwNameB && dwBlock != (unsigned int)-2)
        {
            if (pTable[dwIndex].dwLocale == dwLocale)
                return dwIndex;
            if (!pTable[dwIndex].dwLocale)
                nFallback = dwIndex;
        }

        dwIndex = (dwIndex + 1) & (nSize - 1);
        if (dwIndex == dwStart)
            break;
    }

    return nFallback;
}

int __cdecl sub_Emit_00519110(const char* szName, unsigned int dwLocale)
{
    int nIndex = sub_00519110_FindHashEntry(szName, dwLocale);
    if (nIndex == -1)
        return 0;
    return gpCacheHashTable_0088188C[nIndex].dwBlockIndex;
}
