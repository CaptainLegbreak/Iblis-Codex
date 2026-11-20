#include "D2GameTypes.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma function(memset)
extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385


extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pFileSizeHigh); // 0x006CC2F0
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char* szPathName, void* pSecurityAttributes); // 0x006CC1B8
extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                         // 0x0041C340
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40
void __cdecl sub_00519000_InitCryptTable();
void __cdecl sub_005192A0_DeleteCacheFile();                                                                // 0x005192A0
void __cdecl sub_00519300_FreeCache();                                                                      // 0x00519300

struct D2CacheHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwHeaderSize;
    unsigned int dwFileSize;
    unsigned int unk0x0C;
    unsigned int dwHashOffset;
    unsigned int dwBlockOffset;
    unsigned int nHashTableSize;
    unsigned int f_1C;
    unsigned int dwHeaderCrc;
    unsigned int dwHashCrc;
    unsigned int dwBlockCrc;
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

extern unsigned int gdwCacheCrcTable_0072FB80[];                                                            // 0x0072FB80
extern void* ghCacheFile_0072FB78;                                                                          // 0x0072FB78
static D2CacheHeaderStrc* gpCacheHeader_00881880; // 0x00881880
static D2CacheBlockEntryStrc* gpCacheBlockTable_00881884; // 0x00881884
extern unsigned int* gpCacheTable_00881888;                                                                 // 0x00881888
static D2CacheHashEntryStrc* gpCacheHashTable_0088188C; // 0x0088188C
int gnCacheValue_00881890;                                                                                  // 0x00881890
D2CriticalSectionStrc gCacheLock_00881894;                                                                  // 0x00881894

#define CACHE_CRC32(dwCrc, pBytes, nCount) \
    dwCrc = 0xFFFFFFFF; \
    for (; nCount; --nCount, ++pBytes) \
        dwCrc = (dwCrc >> 8) ^ gdwCacheCrcTable_0072FB80[(*pBytes ^ dwCrc) & 0xFF]; \
    dwCrc = ~dwCrc

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

static __declspec(noinline) void sub_00519220_GetCacheFilePath(char* szPath)
{
    D2_ASSERT(SHGetFolderPathA(0, 0x23, 0, 0, szPath) == 0, 0x112);
    sub_00413800(szPath, "\\Blizzard Entertainment", 0x104);
    CreateDirectoryA(szPath, 0);
    sub_00413800(szPath, "\\Diablo II", 0x104);
    CreateDirectoryA(szPath, 0);
    sub_00413800(szPath, "\\bncache.dat", 0x104);
}

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

// 0x005193E0
int __cdecl sub_005193E0_LoadCache()
{
    char szPath[0x104];
    unsigned long nTableRead;
    unsigned long nFileSize;
    unsigned long nHeaderRead;
    D2CacheHeaderStrc* pHeader;

    EnterCriticalSection(&gCacheLock_00881894);
    if (gnCacheValue_00881890)
    {
        sub_00519300_FreeCache();
    }

    szPath[0] = 0;
    sub_00519220_GetCacheFilePath(szPath);
    ghCacheFile_0072FB78 = CreateFileA(szPath, 0xC0000000, 0, 0, 4, 0x80, 0);
    if (ghCacheFile_0072FB78 == (void*)-1)
    {
        sub_00519300_FreeCache();
        LeaveCriticalSection(&gCacheLock_00881894);
        return 0;
    }

    gpCacheTable_00881888 = (unsigned int*)SMemAlloc(0x1400, ".\\CACHE.CPP", 0x193, 0);
    sub_00519000_InitCryptTable();
    gpCacheHeader_00881880 = (D2CacheHeaderStrc*)SMemAlloc(sizeof(D2CacheHeaderStrc), ".\\CACHE.CPP", 0x197, 8);
    nFileSize = GetFileSize(ghCacheFile_0072FB78, 0);
    if (nFileSize && nFileSize <= 0xA00000)
    {
        int nError;
        unsigned int dwHeaderCrc;
        unsigned int nHashSize;
        unsigned int nBlockSize;
        if (nFileSize < sizeof(D2CacheHeaderStrc))
        {
            nError = 1;
            goto error;
        }

        ReadFile(ghCacheFile_0072FB78, gpCacheHeader_00881880, sizeof(D2CacheHeaderStrc), &nHeaderRead, 0);
        if (nHeaderRead < sizeof(D2CacheHeaderStrc))
        {
            nError = 2;
            goto error;
        }

        if (gpCacheHeader_00881880->dwMagic == 0x1A324E42)
        {
            goto create;
        }

        if (gpCacheHeader_00881880->dwMagic != 0x1A334E42)
        {
            nError = 3;
            goto error;
        }

        dwHeaderCrc = gpCacheHeader_00881880->dwHeaderCrc;
        {
            unsigned int nCount = sizeof(D2CacheHeaderStrc);
            gpCacheHeader_00881880->dwHeaderCrc = 0;
            const unsigned char* pBytes = (const unsigned char*)gpCacheHeader_00881880;
            unsigned int dwCrc;
            CACHE_CRC32(dwCrc, pBytes, nCount);
            if (dwHeaderCrc != dwCrc)
            {
                nError = 4;
                goto error;
            }
        }
        gpCacheHeader_00881880->dwHeaderCrc = dwHeaderCrc;

        if (!gpCacheHeader_00881880->dwHashOffset || !gpCacheHeader_00881880->nHashTableSize)
        {
            nError = 5;
            goto error;
        }

        if (!gpCacheHeader_00881880->dwBlockOffset || !gpCacheHeader_00881880->f_1C)
        {
            nError = 6;
            goto error;
        }

        nHashSize = gpCacheHeader_00881880->nHashTableSize;
        if (nHashSize < 0x400)
        {
            nHashSize = 0x400;
        }
        nHashSize *= sizeof(D2CacheHashEntryStrc);
        if (gpCacheHeader_00881880->dwHashOffset + nHashSize > nFileSize)
        {
            nError = 7;
            goto error;
        }

        gpCacheHashTable_0088188C = (D2CacheHashEntryStrc*)SMemAlloc(nHashSize, ".\\CACHE.CPP", 0x1CC, 8);
        SetFilePointer(ghCacheFile_0072FB78, gpCacheHeader_00881880->dwHashOffset, 0, 0);
        ReadFile(ghCacheFile_0072FB78, gpCacheHashTable_0088188C, nHashSize, &nTableRead, 0);
        if (nTableRead != nHashSize)
        {
            nError = 8;
            goto error;
        }

        if (gpCacheHeader_00881880->dwHashCrc != sub_00518DE0_Crc32(gpCacheHashTable_0088188C, nHashSize))
        {
            nError = 9;
            goto error;
        }

        sub_00518E60_DecryptBlock((unsigned int*)gpCacheHashTable_0088188C, nHashSize, sub_00518FA0_HashString(3, "(hash table)"));

        nBlockSize = gpCacheHeader_00881880->f_1C;
        if (nBlockSize < 0x400)
        {
            nBlockSize = 0x400;
        }
        nBlockSize *= sizeof(D2CacheBlockEntryStrc);
        if (gpCacheHeader_00881880->dwBlockOffset + nBlockSize > nFileSize)
        {
            nError = 10;
            goto error;
        }

        gpCacheBlockTable_00881884 = (D2CacheBlockEntryStrc*)SMemAlloc(nBlockSize, ".\\CACHE.CPP", 0x1E2, 8);
        SetFilePointer(ghCacheFile_0072FB78, gpCacheHeader_00881880->dwBlockOffset, 0, 0);
        ReadFile(ghCacheFile_0072FB78, gpCacheBlockTable_00881884, nBlockSize, &nTableRead, 0);
        if (nTableRead != nBlockSize)
        {
            nError = 11;
            goto error;
        }

        if (gpCacheHeader_00881880->dwBlockCrc != sub_00518DE0_Crc32(gpCacheBlockTable_00881884, nBlockSize))
        {
            nError = 12;
            goto error;
        }

        sub_00518E60_DecryptBlock((unsigned int*)gpCacheBlockTable_00881884, nBlockSize, sub_00518FA0_HashString(3, "(block table)"));
        goto loaded;

error:
        sub_00518D40_Log("WARNING- cache file is invalid. Replacing with new cache file", nError);
    }

create:
    if (!gnCacheValue_00881890)
    {
        if (gpCacheHashTable_0088188C)
        {
            SMemFree(gpCacheHashTable_0088188C, ".\\CACHE.CPP", 0x1FC, 0);
        }
        if (gpCacheBlockTable_00881884)
        {
            SMemFree(gpCacheBlockTable_00881884, ".\\CACHE.CPP", 0x1FE, 0);
        }
        sub_005192A0_DeleteCacheFile();
        ghCacheFile_0072FB78 = CreateFileA(szPath, 0xC0000000, 0, 0, 4, 0x80, 0);
        if (ghCacheFile_0072FB78 == (void*)-1)
        {
            sub_00519300_FreeCache();
            LeaveCriticalSection(&gCacheLock_00881894);
            return 0;
        }

        pHeader = gpCacheHeader_00881880;
        memset(pHeader, 0, sizeof(D2CacheHeaderStrc));
        pHeader->dwMagic = 0x1A334E42;
        pHeader->dwHeaderSize = sizeof(D2CacheHeaderStrc);
        gpCacheHashTable_0088188C = (D2CacheHashEntryStrc*)SMemAlloc(0x400 * sizeof(D2CacheHashEntryStrc), ".\\CACHE.CPP", 0x21C, 8);
        gpCacheHeader_00881880->dwHashOffset = sizeof(D2CacheHeaderStrc);
        gpCacheHeader_00881880->nHashTableSize = 0x400;
        gpCacheHeader_00881880->dwFileSize = gpCacheHeader_00881880->dwFileSize > sizeof(D2CacheHeaderStrc) + 0x400 * sizeof(D2CacheHashEntryStrc) ? gpCacheHeader_00881880->dwFileSize : sizeof(D2CacheHeaderStrc) + 0x400 * sizeof(D2CacheHashEntryStrc);
        for (int i = 0; i < 0x400; ++i)
        {
            gpCacheHashTable_0088188C[i].dwBlockIndex = (unsigned int)-1;
        }

        gpCacheBlockTable_00881884 = (D2CacheBlockEntryStrc*)SMemAlloc(0x400 * sizeof(D2CacheBlockEntryStrc), ".\\CACHE.CPP", 0x229, 8);
        gpCacheHeader_00881880->dwBlockOffset = sizeof(D2CacheHeaderStrc) + 0x400 * sizeof(D2CacheHashEntryStrc);
        gpCacheHeader_00881880->dwFileSize = gpCacheHeader_00881880->dwFileSize > sizeof(D2CacheHeaderStrc) + 0x400 * (sizeof(D2CacheHashEntryStrc) + sizeof(D2CacheBlockEntryStrc)) ? gpCacheHeader_00881880->dwFileSize : sizeof(D2CacheHeaderStrc) + 0x400 * (sizeof(D2CacheHashEntryStrc) + sizeof(D2CacheBlockEntryStrc));
loaded:
        gnCacheValue_00881890 = 1;
    }

    LeaveCriticalSection(&gCacheLock_00881894);
    return 1;
}

#include "gen/data/Source/D2BNClient/CACHE_005193E0.inc"
