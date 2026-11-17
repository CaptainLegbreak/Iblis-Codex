#include "D2BNClient.h"

struct D2CacheHeaderStrc
{
    char unk0x00[0x08];
    unsigned int nNextOffset;
    char unk0x0C[0x04];
    unsigned int nHashOffset;
    unsigned int nBlockOffset;
    unsigned int nHashTableSize;
    unsigned int f_1C;
    unsigned int dwHeaderCrc;
    unsigned int dwHashCrc;
    unsigned int dwBlockCrc;
};

struct D2CacheBlockEntryStrc
{
    unsigned int dwOffset;
    unsigned int dwSize;
    unsigned int dwFieldA;
    unsigned int dwFieldB;
};

struct D2FileTimeStrc
{
    unsigned int dwLow;
    unsigned int dwHigh;
};

struct D2CacheRecordStrc
{
    unsigned int dwSize;
    char unk0x04[0x08];
    unsigned int dwCrc;
    unsigned int dwDataCrc;
    char unk0x14[0x04];
    D2FileTimeStrc qwTime4;
    D2FileTimeStrc qwFileTime;
    D2FileTimeStrc qwTime1;
    D2FileTimeStrc qwTime2;
    D2FileTimeStrc qwTime3;
    char szName[0x104];
};
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, void* pFileTime); // 0x006CC26C
extern "C" __declspec(dllimport) long __stdcall CompareFileTime(const void* pFileTime1, const void* pFileTime2); // 0x006CC390
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pDistanceHigh, unsigned long dwMethod); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags);         // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40
void __cdecl sub_005198C0_ResetCache();                                                                     // 0x005198C0
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static void* ghCacheFile_0072FB78;                                                                          // 0x0072FB78
static D2CacheHeaderStrc* gpCacheHeader_00881880;                                                           // 0x00881880
static D2CacheBlockEntryStrc* gpCacheBlockTable_00881884;                                                   // 0x00881884
static unsigned int* gpCacheTable_00881888;                                                                 // 0x00881888
static D2CacheHashEntryStrc* gpCacheHashTable_0088188C;                                                     // 0x0088188C
extern D2CriticalSectionStrc gCacheLock_00881894;                                                           // 0x00881894
extern unsigned __int64 gqwCacheFileTime_008818AC;                                                          // 0x008818AC
extern unsigned long gdwCacheTimeTick_008818B4;                                                             // 0x008818B4
extern unsigned int gnCacheTimeSeconds_008818B8;                                                            // 0x008818B8

// 0x00519300
void __cdecl sub_00519300_FreeCache()
{
    EnterCriticalSection(&gCacheLock_00881894);
    gnCacheValue_00881890 = 0;
    if (gpCacheBlockTable_00881884)
    {
        SMemFree(gpCacheBlockTable_00881884, ".\\CACHE.CPP", 0x155, 0);
        gpCacheBlockTable_00881884 = 0;
    }
    if (gpCacheHashTable_0088188C)
    {
        SMemFree(gpCacheHashTable_0088188C, ".\\CACHE.CPP", 0x159, 0);
        gpCacheHashTable_0088188C = 0;
    }
    if (gpCacheHeader_00881880)
    {
        SMemFree(gpCacheHeader_00881880, ".\\CACHE.CPP", 0x15D, 0);
        gpCacheHeader_00881880 = 0;
    }
    if (ghCacheFile_0072FB78 != (void*)-1)
    {
        CloseHandle(ghCacheFile_0072FB78);
        ghCacheFile_0072FB78 = (void*)-1;
    }
    if (gpCacheTable_00881888)
    {
        SMemFree(gpCacheTable_00881888, ".\\CACHE.CPP", 0x165, 0);
        gpCacheTable_00881888 = 0;
    }
    LeaveCriticalSection(&gCacheLock_00881894);
}

// 0x00518DE0
static __declspec(noinline) unsigned int sub_00518DE0_Crc32(const void* pData, unsigned int nSize)
{
    VALIDATEBEGIN;
    VALIDATE(pData || !nSize);
    D2_ASSERT(pData || !nSize, 0x91);
    VALIDATEEND;

    const unsigned char* pBytes = (const unsigned char*)pData;
    unsigned int dwCrc;
    CACHE_CRC32(dwCrc, pBytes, nSize);
    return dwCrc;
}

static __declspec(noinline) void sub_00518EC0_EncryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey);

// 0x00518EC0
static void sub_00518EC0_EncryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey)
{
    unsigned int dwSeed = 0xEEEEEEEE;
    unsigned int nCount = nLength >> 2;
    if (nCount != 0)
    {
        const unsigned int* pTable = gpCacheTable_00881888;
        do
        {
            --nCount;
            unsigned int ch = *pData;
            dwSeed += pTable[0x400 + (dwKey & 0xFF)];
            *pData = ch ^ (dwKey + dwSeed);
            dwSeed = ch + dwSeed + (dwSeed << 5) + 3;
            dwKey = ((~dwKey << 0x15) + 0x11111111) | (dwKey >> 0x0B);
            ++pData;
        } while (nCount != 0);
    }
}

// 0x00518F30
static D2FileTimeStrc* sub_00518F30_GetCacheFileTime(unsigned int nSeconds)
{
    if (nSeconds != gnCacheTimeSeconds_008818B8 || GetTickCount() != gdwCacheTimeTick_008818B4)
    {
        D2SystemTimeStrc tSystemTime;
        GetSystemTime(&tSystemTime);
        SystemTimeToFileTime(&tSystemTime, &gqwCacheFileTime_008818AC);
        gqwCacheFileTime_008818AC += (unsigned __int64)nSeconds * 10000000;
        gnCacheTimeSeconds_008818B8 = nSeconds;
        gdwCacheTimeTick_008818B4 = GetTickCount();
    }
    return (D2FileTimeStrc*)&gqwCacheFileTime_008818AC;
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

// build: context sub_H08_ClearBlockEntry
static void sub_H08_ClearBlockEntry(D2CacheBlockEntryStrc* pBlockTable, unsigned int nBlock)
{
    pBlockTable[nBlock].dwFieldA = 0;
    pBlockTable[nBlock].dwFieldB = 0;
}

// 0x005191D0
static void sub_005191D0_DeleteHashEntries(const char* szName)
{
    int nIndex;
    while ((nIndex = sub_00519110_FindHashEntry(szName, 0)) != -1)
    {
        unsigned int* pBlock = &gpCacheHashTable_0088188C[nIndex].dwBlockIndex;
        if (*pBlock < gpCacheHeader_00881880->f_1C)
        {
            sub_H08_ClearBlockEntry(gpCacheBlockTable_00881884, *pBlock);
        }
        *pBlock = (unsigned int)-2;
    }
}

// 0x00519DB0
int __fastcall sub_00519DB0_WriteCacheFile(const char* szName, const void* pData, unsigned int nSize, const D2FileTimeStrc* pFileTime, unsigned int nSeconds1, unsigned int nSeconds2)
{
    D2CacheRecordStrc tRecord;
    D2CacheRecordStrc tOld;

    if (!szName || !*szName || !pData || !nSize || !pFileTime || !nSeconds2 || !gnCacheValue_00881890 || nSize > 0x1000000)
    {
        return 0;
    }

    int nError = 0;
    EnterCriticalSection(&gCacheLock_00881894);
    sub_005191D0_DeleteHashEntries(szName);

    const unsigned int nNeeded = nSize + 0x144;
    unsigned int nBlock = 0;
    while (nBlock < gpCacheHeader_00881880->f_1C)
    {
        if (!gpCacheBlockTable_00881884[nBlock].dwFieldB && gpCacheBlockTable_00881884[nBlock].dwSize >= nNeeded)
        {
            break;
        }
        ++nBlock;
    }

    if (nBlock >= gpCacheHeader_00881880->f_1C)
    {
        for (nBlock = 0; nBlock < gpCacheHeader_00881880->f_1C; ++nBlock)
        {
            if (gpCacheBlockTable_00881884[nBlock].dwSize < nNeeded)
            {
                continue;
            }

            unsigned long nCount;
            SetFilePointer(ghCacheFile_0072FB78, gpCacheBlockTable_00881884[nBlock].dwOffset, 0, 0);
            memset(&tOld, 0, sizeof(tOld));
            ReadFile(ghCacheFile_0072FB78, &tOld, 4, &nCount, 0);
            if (nCount != 4 || tOld.dwSize != 0x144)
            {
                break;
            }

            ReadFile(ghCacheFile_0072FB78, &tOld.unk0x04, 0x140, &nCount, 0);
            if (nCount != 0x140)
            {
                break;
            }

            if (CompareFileTime(sub_00518F30_GetCacheFileTime(0), &tOld.qwTime2) > 0)
            {
                break;
            }
        }
    }

    D2CacheHeaderStrc* pHeader = gpCacheHeader_00881880;
    if (nBlock < pHeader->f_1C)
    {
        for (unsigned int i = 0; i < pHeader->nHashTableSize; ++i)
        {
            if (gpCacheHashTable_0088188C[i].dwBlockIndex == nBlock)
            {
                gpCacheHashTable_0088188C[i].dwBlockIndex = (unsigned int)-2;
            }
        }
    }
    else
    {
        if (nBlock >= 0x400)
        {
            nError = 0xB;
            goto Fail;
        }

        gpCacheBlockTable_00881884[nBlock].dwOffset = pHeader->nNextOffset;
        gpCacheBlockTable_00881884[nBlock].dwSize = nNeeded;
        pHeader->nNextOffset += nNeeded;
        pHeader->f_1C = nBlock + 1;
    }

    {
        const unsigned int dwIndex = sub_00518FA0_HashString(0, szName);
        const unsigned int dwNameA = sub_00518FA0_HashString(1, szName);
        const unsigned int dwNameB = sub_00518FA0_HashString(2, szName);
        unsigned int nSlot = dwIndex & (gpCacheHeader_00881880->nHashTableSize - 1);
        const unsigned int nStart = nSlot;
        D2CacheHashEntryStrc* pTable = gpCacheHashTable_0088188C;
        unsigned int dwEntryBlock = pTable[nSlot].dwBlockIndex;
        while (dwEntryBlock != (unsigned int)-1 && dwEntryBlock != (unsigned int)-2)
        {
            nSlot = (nSlot + 1) & (gpCacheHeader_00881880->nHashTableSize - 1);
            if (nSlot == nStart)
            {
                break;
            }
            dwEntryBlock = pTable[nSlot].dwBlockIndex;
        }

        D2CacheHashEntryStrc* pEntry = &pTable[nSlot];
        if (pEntry->dwBlockIndex != (unsigned int)-1 && pEntry->dwBlockIndex != (unsigned int)-2)
        {
            nError = 0xC;
            goto Fail;
        }

        pEntry->dwNameA = dwNameA;
        pEntry->dwNameB = dwNameB;
        pEntry->dwBlockIndex = nBlock;
        pEntry->dwLocale = 0;
    }

    {
    unsigned long nCount;
    gpCacheBlockTable_00881884[nBlock].dwFieldA = nSize;
    gpCacheBlockTable_00881884[nBlock].dwFieldB = 0xC0000000;

    memset(&tRecord, 0, sizeof(tRecord));
    tRecord.dwSize = 0x144;

    const D2FileTimeStrc* pTime1 = sub_00518F30_GetCacheFileTime(0);
    tRecord.qwTime1.dwLow = pTime1->dwLow;
    tRecord.qwTime1.dwHigh = pTime1->dwHigh;
    tRecord.qwFileTime.dwLow = pFileTime->dwLow;
    tRecord.qwFileTime.dwHigh = pFileTime->dwHigh;
    const D2FileTimeStrc* pTime2 = sub_00518F30_GetCacheFileTime(nSeconds1);
    tRecord.qwTime2.dwLow = pTime2->dwLow;
    tRecord.qwTime2.dwHigh = pTime2->dwHigh;
    const D2FileTimeStrc* pTime3 = sub_00518F30_GetCacheFileTime(nSeconds2);
    tRecord.qwTime3.dwLow = pTime3->dwLow;
    tRecord.qwTime3.dwHigh = pTime3->dwHigh;
    const D2FileTimeStrc* pTime4 = sub_00518F30_GetCacheFileTime(0);
    tRecord.qwTime4.dwLow = pTime4->dwLow;
    tRecord.qwTime4.dwHigh = pTime4->dwHigh;
    strcpy(tRecord.szName, szName);
    tRecord.dwDataCrc = sub_00518DE0_Crc32(pData, nSize);
    {
        unsigned int nLeft = sizeof(tRecord);
        const unsigned char* pBytes = (const unsigned char*)&tRecord;
        unsigned int dwCrc;
        CACHE_CRC32(dwCrc, pBytes, nLeft);
        tRecord.dwCrc = dwCrc;
    }

    SetFilePointer(ghCacheFile_0072FB78, gpCacheBlockTable_00881884[nBlock].dwOffset, 0, 0);
    WriteFile(ghCacheFile_0072FB78, &tRecord, sizeof(tRecord), &nCount, 0);
    if (nCount != sizeof(tRecord))
    {
        nError = 0xD;
        goto Fail;
    }

    WriteFile(ghCacheFile_0072FB78, pData, nSize, &nCount, 0);
    if (nCount != nSize)
    {
        nError = 0xE;
        goto Fail;
    }

    {
        unsigned int nHashCount = gpCacheHeader_00881880->nHashTableSize;
        if (nHashCount < 0x400)
        {
            nHashCount = 0x400;
        }
        const unsigned int nHashBytes = nHashCount << 4;
        unsigned int nBlockCount = gpCacheHeader_00881880->f_1C;
        if (nBlockCount < 0x400)
        {
            nBlockCount = 0x400;
        }
        const unsigned int nBlockBytes = nBlockCount << 4;

        unsigned int* pBuffer = (unsigned int*)SMemAlloc(nHashBytes > nBlockBytes ? nHashBytes : nBlockBytes, ".\\CACHE.CPP", 0x391, 0);
        SetFilePointer(ghCacheFile_0072FB78, gpCacheHeader_00881880->nHashOffset, 0, 0);
        memcpy(pBuffer, gpCacheHashTable_0088188C, nHashBytes);
        sub_00518EC0_EncryptBlock(pBuffer, nHashBytes, sub_00518FA0_HashString(3, "(hash table)"));
        gpCacheHeader_00881880->dwHashCrc = sub_00518DE0_Crc32(pBuffer, nHashBytes);
        WriteFile(ghCacheFile_0072FB78, pBuffer, nHashBytes, &nCount, 0);
        if (nCount != nHashBytes)
        {
            SMemFree(pBuffer, ".\\CACHE.CPP", 0x39D, 0);
            nError = 0xF;
            goto Fail;
        }

        SetFilePointer(ghCacheFile_0072FB78, gpCacheHeader_00881880->nBlockOffset, 0, 0);
        memcpy(pBuffer, gpCacheBlockTable_00881884, nBlockBytes);
        sub_00518EC0_EncryptBlock(pBuffer, nBlockBytes, sub_00518FA0_HashString(3, "(block table)"));
        gpCacheHeader_00881880->dwBlockCrc = sub_00518DE0_Crc32(pBuffer, nBlockBytes);
        WriteFile(ghCacheFile_0072FB78, pBuffer, nBlockBytes, &nCount, 0);
        SMemFree(pBuffer, ".\\CACHE.CPP", 0x3AB, 0);
        if (nCount != nBlockBytes)
        {
            nError = 0x10;
            goto Fail;
        }
    }

    {
        D2CacheHeaderStrc* pCacheHeader = gpCacheHeader_00881880;
        pCacheHeader->dwHeaderCrc = 0;
        unsigned int nLeft = sizeof(D2CacheHeaderStrc);
        const unsigned char* pBytes = (const unsigned char*)pCacheHeader;
        unsigned int dwCrc;
        CACHE_CRC32(dwCrc, pBytes, nLeft);
        pCacheHeader->dwHeaderCrc = dwCrc;
    }

    SetFilePointer(ghCacheFile_0072FB78, 0, 0, 0);
    WriteFile(ghCacheFile_0072FB78, gpCacheHeader_00881880, sizeof(D2CacheHeaderStrc), &nCount, 0);
    if (nCount != sizeof(D2CacheHeaderStrc))
    {
        nError = 0x11;
        goto Fail;
    }
    }
    goto Done;

Fail:
    sub_00518D40_Log("bncache.dat is corrupt (%d) - rebuilding archive", nError);
    sub_005198C0_ResetCache();

Done:
    LeaveCriticalSection(&gCacheLock_00881894);
    return nError == 0;
}
