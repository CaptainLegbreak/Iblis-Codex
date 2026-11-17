#include "Storm.h"

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2StormMpqHeaderStrc
{
    unsigned int dwSignature;
    unsigned int f_4;
    unsigned int nArchiveSize;
    unsigned short wVersion;
    unsigned char nSectorShift;
    unsigned char unk0x0F;
    unsigned int nHashOffset;
    unsigned int nBlockOffset;
    unsigned int nHashEntries;
    unsigned int nBlockEntries;
};

struct D2StormArchiveRecStrc
{
    D2StormLinkStrc f_0;
    char szName[0x104];
    void* hFile;
    int nMode;
    int bNoDiskSearch;
    int nPriority;
    void* pCachedFile;
    unsigned int nCachedOffset;
    unsigned int nBlockSize;
    unsigned char* pBlockBuffer;
    unsigned int f_12C;
    unsigned int nArchiveOffset;
    unsigned int nArchiveLimit;
    D2StormMpqHeaderStrc* pHeader;
    void* pBlockTable;
    void* f_140;
    unsigned int nFilePos;
    int bNested;
    void* hNestedFile;
    D2StormArchiveRecStrc* pPatch;
    char szPrefix[0x104];
    int nRefs;

    D2StormArchiveRecStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwAccess, unsigned long dwShareMode, void* pSecurity, unsigned long dwDisposition, unsigned long dwFlags, void* hTemplate); // 0x006CC19C
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pnSizeHigh); // 0x006CC2F0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);                             // 0x00686900
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
const char* __stdcall SStrChrR(const char* szString, char nChar);                                           // 0x004134D0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __cdecl sub_004158E0_InitBasePath();                                                                   // 0x004158E0
void __cdecl sub_00415B90_InitCryptTable();                                                                 // 0x00415B90
int __stdcall sub_00415960_CheckVolume(const char* szPath);                                                 // 0x00415960
int __fastcall sub_0041B6B0_LoadArchive(D2StormArchiveRecStrc* pArchive, unsigned int nFlags, int bKeepOnFail, void** phArchive); // 0x0041B6B0
static __declspec(noinline) int sub_00415940_PathPresent(const char* szPath);                                // 0x00415940
static __declspec(noinline) void __stdcall sub_00415A80_BuildPath(int bStripPath, const char* szName, char* szOut); // 0x00415A80

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern char gszBasePath_00778F28[];                                                                         // 0x00778F28

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

static int sub_00415940_PathPresent(const char* szPath)
{
    return ~(GetFileAttributesA(szPath) >> 4) & 1;
}

static void __stdcall sub_00415A80_BuildPath(int bStripPath, const char* szName, char* szOut)
{
    if (!gszBasePath_00778F28[0])
        sub_004158E0_InitBasePath();
    if (bStripPath)
    {
        const char* szSlash = SStrChrR(szName, 0x5C);
        if (szSlash)
            szName = szSlash + 1;
    }
    char szBuffer[0x104];
    wsprintfA(szBuffer, "%s%s", gszBasePath_00778F28, szName);
    _fullpath(szOut, szBuffer, 0x104);
}

// 0x0041BA60
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq)
{
    void* hFile;
    VALIDATEBEGIN;
    if (!phMpq)
        nValid = 0;
    else
        *phMpq = 0;
    VALIDATE(szMpqName);
    __assume((szMpqName) != 0);
    VALIDATE(*szMpqName);
    __assume((*szMpqName) != 0);
    VALIDATEEND;

    EnterCriticalSection(&gBasePathLock_00779068);
    sub_00415B90_InitCryptTable();

    char szPath[0x104];
    SStrCopy(szPath, szMpqName, 0x104);
    szPath[0x103] = 0;
    if (!sub_00415940_PathPresent(szPath))
    {
        if (*szMpqName != 0x5C && !strstr(szMpqName, ":\\") && !strstr(szMpqName, "\\\\"))
            sub_00415A80_BuildPath(0, szMpqName, szPath);
        else
            SStrCopy(szPath, szMpqName, 0x104);
    }

    const int nVolume = sub_00415960_CheckVolume(szPath);
    if ((dwFlags & 1) && !nVolume)
    {
        sub_0041C340_SetLastError(0xF);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }

    hFile = CreateFileA(szPath, 0x80000000, 1, 0, 3, 0, 0);
    if (hFile == (void*)-1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }

    void* pMemory = SMemAlloc(sizeof(D2StormArchiveRecStrc), gszTypeNameArchiveRec_00708398, -2, 8);
    D2StormArchiveRecStrc* pArchive = pMemory ? new (pMemory) D2StormArchiveRecStrc : 0;
    SStrCopy(pArchive->szName, szPath, 0x104);
    pArchive->hFile = hFile;
    pArchive->nMode = nVolume ? 3 : 0;
    pArchive->nPriority = nPriority;
    pArchive->bNested = 1;
    if (nVolume)
        pArchive->nMode = 3;
    else
        pArchive->nMode = ((unsigned char)dwFlags >> 1) & 1;
    pArchive->bNoDiskSearch = (dwFlags >> 2) & 1;
    pArchive->pHeader = (D2StormMpqHeaderStrc*)SMemAlloc(sizeof(D2StormMpqHeaderStrc), ".\\SOURCE\\SFILE.CPP", 0x1052, 0);
    pArchive->nArchiveOffset = 0;
    pArchive->nArchiveLimit = GetFileSize(hFile, 0);
    pArchive->nRefs = 0;
    const int nResult = sub_0041B6B0_LoadArchive(pArchive, dwFlags, nVolume, phMpq);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}
