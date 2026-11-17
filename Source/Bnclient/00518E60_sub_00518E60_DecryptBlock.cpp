struct D2CacheHeaderStrc
{
    char unk0x00[0x18];
    unsigned int nHashTableSize;
    unsigned int f_1C;
};

struct D2CacheHashEntryStrc
{
    unsigned int dwNameA;
    unsigned int dwNameB;
    unsigned int dwLocale;
    unsigned int dwBlockIndex;
};

struct D2CacheBlockEntryStrc
{
    char unk0x00[0x08];
    unsigned int dwFieldA;
    unsigned int dwFieldB;
};

extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385

extern D2CacheHeaderStrc* gpCacheHeader_00881880;                                                           // 0x00881880
extern D2CacheBlockEntryStrc* gpCacheBlockTable_00881884;                                                   // 0x00881884
extern unsigned int* gpCacheTable_00881888;                                                                 // 0x00881888
extern D2CacheHashEntryStrc* gpCacheHashTable_0088188C;                                                     // 0x0088188C
extern const char gszH08EmitKey[];

// 0x00518E60
static void sub_00518E60_DecryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey)
{
    unsigned int dwSeed = 0xEEEEEEEE;
    nLength >>= 2;
    while (nLength-- != 0)
    {
        dwSeed += gpCacheTable_00881888[0x400 + (dwKey & 0xFF)];
        *pData ^= dwKey + dwSeed;
        unsigned int ch = *pData++;
        dwSeed = ch + dwSeed + (dwSeed << 5) + 3;
        dwKey = ((~dwKey << 0x15) + 0x11111111) | (dwKey >> 0x0B);
    }
}

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

static int __stdcall sub_00519110_FindHashEntry(unsigned int dwLocale, const char* szName)
{
    unsigned int dwIndex = sub_00518FA0_HashString(0, szName);
    unsigned int dwNameA = sub_00518FA0_HashString(1, szName);
    unsigned int dwNameB = sub_00518FA0_HashString(2, szName);
    unsigned int dwMask = gpCacheHeader_00881880->nHashTableSize - 1;
    unsigned int i = dwIndex & dwMask;
    D2CacheHashEntryStrc* pTable = gpCacheHashTable_0088188C;
    D2CacheHashEntryStrc* pEntry = &pTable[i];
    unsigned int dwBlock = pEntry->dwBlockIndex;
    unsigned int dwStart = i;
    int nFound = -1;
    while (dwBlock != (unsigned int)-1)
    {
        if (pEntry->dwNameA == dwNameA && pEntry->dwNameB == dwNameB && dwBlock != (unsigned int)-2)
        {
            unsigned int dwEntryLocale = pEntry->dwLocale;
            if (dwEntryLocale == dwLocale)
            {
                return i;
            }
            if (!dwEntryLocale)
            {
                nFound = i;
            }
        }
        i = (i + 1) & dwMask;
        if (i == dwStart)
        {
            break;
        }
        pEntry = &pTable[i];
        dwBlock = pEntry->dwBlockIndex;
    }
    return nFound;
}

static void sub_H08_ClearBlockEntry(D2CacheBlockEntryStrc* pBlockTable, unsigned int nBlock)
{
    pBlockTable[nBlock].dwFieldA = 0;
    pBlockTable[nBlock].dwFieldB = 0;
}

// 0x005191D0
static void sub_005191D0_DeleteHashEntries(const char* szName)
{
    int nIndex;
    while ((nIndex = sub_00519110_FindHashEntry(0, szName)) != -1)
    {
        unsigned int* pBlock = &gpCacheHashTable_0088188C[nIndex].dwBlockIndex;
        if (*pBlock < gpCacheHeader_00881880->f_1C)
        {
            sub_H08_ClearBlockEntry(gpCacheBlockTable_00881884, *pBlock);
        }
        *pBlock = (unsigned int)-2;
    }
}

void __cdecl sub_H08_Emit_00518E60(unsigned int nSize)
{
    sub_00518E60_DecryptBlock((unsigned int*)gpCacheHashTable_0088188C, nSize, sub_00518FA0_HashString(3, gszH08EmitKey));
}

void __cdecl sub_H08_Emit_005191D0(const char* szName)
{
    sub_005191D0_DeleteHashEntries(szName);
}
