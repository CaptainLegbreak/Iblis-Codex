#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2CriticalSectionStrc;
struct D2StormFixedListStrc;

// build: context ArchiveHead
// build: context D2StormLinkStrc::Next

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szName, unsigned long dwAccess, unsigned long dwShare, void* pSecurity, unsigned long dwDisposition, unsigned long dwFlags, void* hTemplate); // 0x006CC19C
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMethod); // 0x006CC1AC

struct D2StormFixedListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_00418F20_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);    // 0x00418F20
};

typedef void (__stdcall* SFILEOPENCALLBACK)(const char* szFileName, void* pParam);
extern "C" const char gszSFileSourceFile_006CF084[]; // 0x006CF084
extern D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068
extern unsigned int* gpCryptTable_00779048; // 0x00779048
extern D2StormFixedListStrc gFileList_0070836C; // 0x0070836C
extern SFILEOPENCALLBACK gpfnOpenFileCallback_00779060; // 0x00779060
extern void* gpOpenFileCallbackParam_00779064; // 0x00779064
extern unsigned int gnFileCrc_007790B0; // 0x007790B0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString); // 0x00686900
void __cdecl sub_004158E0_InitBasePath(); // 0x004158E0
extern char gszBasePath_00778F28[]; // 0x00778F28
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
char* __stdcall SStrDup(const char* szString); // 0x00414310
void sub_00415B90_InitCryptTable(); // 0x00415B90
static unsigned int __stdcall sub_00415330_HashString(unsigned int nHashType, const char* szString);
static int sub_00415930_GetArchiveRec(void* hArchive, D2StormArchiveRecStrc** ppRec); // 0x00415930
static D2StormBlockStrc* sub_004155B0_GetBlockEntry(D2StormArchiveRecStrc* pArchive, int nHashIndex); // 0x004155B0
static int __stdcall sub_004155D0_FindHashEntry(unsigned short wLocale, unsigned char nPlatform, D2StormArchiveRecStrc* pArchive, const char* szName); // 0x004155D0
static int __stdcall sub_00415B00_FindDiskFile(unsigned int nFlags, const char* szName, char* szOut); // 0x00415B00
static int __stdcall sub_00417F10_FindFile(void* hArchive, const char* szName, unsigned int nFlags, D2StormArchiveRecStrc** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath);
int __cdecl sub_00418B50(); // 0x00418B50
int __stdcall SFileCloseFile(void* pArg); // 0x004198D0
int __fastcall s_OpenArchive(D2StormArchiveRecStrc* pArchive, unsigned int nFlags, int bKeepOnFail, void** phArchive); // 0x0041B6B0
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq); // 0x0041BA60
static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec);

inline void* operator new(unsigned int, void* pWhere) throw();

// 0x00415330
static unsigned int __stdcall sub_00415330_HashString(unsigned int nHashType, const char* szString)
{
    unsigned int nSeed1 = 0x7FED7FED;
    unsigned int nSeed2 = 0xEEEEEEEE;
    while (szString && *szString)
    {
        unsigned int nChar = (unsigned char)toupper(*szString++);
        nSeed1 = gpCryptTable_00779048[(nHashType << 8) + nChar] ^ (nSeed1 + nSeed2);
        nSeed2 = nChar + nSeed2 + (nSeed2 << 5) + nSeed1 + 3;
    }
    return nSeed1;
}

static inline D2StormArchiveRecStrc* ArchiveHead()
{
    return (int)gpArchiveHead_0070835C > 0 ? gpArchiveHead_0070835C : 0;
}

// 0x00415930
static __declspec(noinline) int sub_00415930_GetArchiveRec(void* hArchive, D2StormArchiveRecStrc** ppRec)
{
    *ppRec = (D2StormArchiveRecStrc*)hArchive;
    return 1;
}

// 0x004155B0
static D2StormBlockStrc* sub_004155B0_GetBlockEntry(D2StormArchiveRecStrc* pArchive, int nHashIndex)
{
    return &pArchive->pBlockTable[pArchive->pHashTable[nHashIndex].nBlockIndex];
}

// build: context sub_004155D0_FindHashEntry
static int __stdcall sub_004155D0_FindHashEntry(unsigned short wLocale, unsigned char nPlatform, D2StormArchiveRecStrc* pArchive, const char* szName)
{
    const unsigned int nHash = sub_00415330_HashString(0, szName);
    const unsigned int nName1 = sub_00415330_HashString(1, szName);
    const unsigned int nName2 = sub_00415330_HashString(2, szName);
    const unsigned int nMask = pArchive->pHeader->nHashEntries - 1;
    unsigned int nIndex = nMask & nHash;
    D2StormHashEntryStrc* pEntry = &pArchive->pHashTable[nIndex];
    const unsigned int nStart = nIndex;
    int nBest = -1;
    while (pEntry->nBlockIndex != -1)
    {
        if (pEntry->nName1 == nName1 && pEntry->nName2 == nName2 && pEntry->nBlockIndex != -2)
        {
            if (pEntry->wLocale == wLocale && pEntry->nPlatform == nPlatform)
                return nIndex;
            if ((!pEntry->wLocale || pEntry->wLocale == wLocale) && (!pEntry->nPlatform || pEntry->nPlatform == nPlatform))
                nBest = nIndex;
        }
        nIndex = (nIndex + 1) & nMask;
        if (nIndex == nStart)
            break;
        pEntry = &pArchive->pHashTable[nIndex];
    }
    return nBest;
}

// 0x00415940
static int sub_00415940_PathPresent(const char* szPath)
{
    return ~(GetFileAttributesA(szPath) >> 4) & 1;
}

// 0x00415A80
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
    wsprintfA(szBuffer, gszPathJoinFormat_006CE200, gszBasePath_00778F28, szName);
    _fullpath(szOut, szBuffer, 0x104);
}

// 0x00415B00
static int __stdcall sub_00415B00_FindDiskFile(unsigned int nFlags, const char* szName, char* szOut)
{
    int bResult = 0;
    if (nFlags & 3)
    {
        if (nFlags & 2)
        {
            sub_00415A80_BuildPath(1, szName, szOut);
            bResult = sub_00415940_PathPresent(szOut);
            if (bResult)
                return bResult;
        }
        if (nFlags & 1)
        {
            if (*szName != 0x5C && !strstr(szName, gszDriveRoot_006CF09C) && !strstr(szName, gszUncPrefix_006CF098))
            {
                sub_00415A80_BuildPath(0, szName, szOut);
                return sub_00415940_PathPresent(szOut);
            }
            SStrCopy(szOut, szName, 0x104);
            return sub_00415940_PathPresent(szOut);
        }
    }
    return bResult;
}

// 0x00417F10
static int __stdcall sub_00417F10_FindFile(void* hArchive, const char* szName, unsigned int nFlags, D2StormArchiveRecStrc** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath)
{
    if (ppArchive)
        *ppArchive = 0;
    if (ppBlock)
        *ppBlock = 0;
    int bResult = 0;
    D2StormArchiveRecStrc* pOnly = 0;
    if (!hArchive || sub_00415930_GetArchiveRec(hArchive, &pOnly))
    {
        D2StormArchiveRecStrc* pArchive = ArchiveHead();
        do
        {
            if (pOnly && pArchive != pOnly)
                continue;
            if (pArchive && pArchive->nRefs > 0)
                continue;
            D2StormArchiveRecStrc* pSearch = pArchive;
            if (pArchive && pArchive->pPatch)
                pSearch = pArchive->pPatch;
            const char* szLookup = szName;
            char szPrefixed[0x104];
            if (pArchive && pArchive->szPrefix[0])
            {
                char* szEnd = szPrefixed + SStrCopy(szPrefixed, pArchive->szPrefix, 0x104);
                szEnd += SStrCopy(szEnd, gszBackslash_006FF9B8, 0x104);
                SStrCopy(szEnd, szName, 0x104);
                szLookup = szPrefixed;
            }
            char szDiskPath[0x104];
            if ((nFlags & 3) && (!pSearch || !pSearch->bNoDiskSearch)
                && sub_00415B00_FindDiskFile(nFlags, szLookup, szDiskPath))
            {
                if (szFoundPath)
                    SStrCopy(szFoundPath, szDiskPath, 0x104);
                bResult = 2;
                goto Done;
            }
            if (pArchive)
            {
                const int nIndex = sub_004155D0_FindHashEntry(gwLocale_0077905C, gnPlatform_0077905E, pSearch, szLookup);
                if (nIndex != -1)
                {
                    bResult = 1;
                    D2StormBlockStrc* pBlock = sub_004155B0_GetBlockEntry(pSearch, nIndex);
                    const int bValid = (pBlock->dwFlags & 0x80000000) && (!(nFlags & 4) || !(pBlock->dwFlags & 0x1FF00));
                    if (!bValid)
                    {
                        bResult = 0;
                        sub_0041C340_SetLastError(0x3EE);
                    }
                    else
                    {
                        if (ppArchive)
                            *ppArchive = pSearch;
                        if (ppBlock)
                            *ppBlock = pBlock;
                    }
                    goto Done;
                }
            }
        }
        while (pArchive && (pArchive = (D2StormArchiveRecStrc*)pArchive->tLink.Next()) != 0);
        sub_0041C340_SetLastError(2);
    }
Done:
    return bResult;
}

// build: context sub_004192F0_OpenDiskFile
static __forceinline int sub_004192F0_OpenDiskFile(const char* szFileName, unsigned int dwFlags, void** phFile, const char* szPath)
{
    void* hFile = CreateFileA(szPath, 0x80000000, 1, 0, 3, 0x8000000, 0);
    if (hFile != (void*)-1)
    {
        if (dwFlags & 4)
        {
            *phFile = hFile;
        }
        else
        {
            D2StormFileRecStrc* pFile = (D2StormFileRecStrc*)gFileList_0070836C.sub_00418F20_NewNode(1, 0, 0);
            SStrCopy(pFile->name, szFileName, 0x104);
            pFile->szLocalPath = SStrDup(szPath);
            pFile->hFile = hFile;
            pFile->nRefCount = 1;
            pFile->nCrcValue = 0;
            *phFile = pFile;
        }

        return 2;
    }

    return 0;
}

// 0x004192F0
int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile)
{
    VALIDATEBEGIN;
    if (!phFile)
        nValid = 0;
    else
        *phFile = 0;
    VALIDATE(szFileName);
    __assume((szFileName) != 0);
    VALIDATE(*szFileName);
    __assume((*szFileName) != 0);
    VALIDATEEND;

    EnterCriticalSection(&gBasePathLock_00779068);
    sub_00415B90_InitCryptTable();

    D2StormBlockStrc* pBlock;
    D2StormArchiveRecStrc* pArchive;
    char szPath[0x104];
    int nResult = 0;
    const int nFound = sub_00417F10_FindFile((void*)hMpq, szFileName, dwFlags, &pArchive, &pBlock, szPath);
    if (nFound)
    {
        if (nFound == 2)
        {
            nResult = sub_004192F0_OpenDiskFile(szFileName, dwFlags, phFile, szPath);
        }
        else if (dwFlags & 4)
        {
            void* hFile = CreateFileA(pArchive->szName, 0x80000000, 1, 0, 3, 0x8000000, 0);
            nResult = hFile != (void*)-1;
            *phFile = hFile;
            if (nResult)
                SetFilePointer(hFile, pBlock->nOffset, 0, 0);
            else
                sub_0041C340_SetLastError(2);
        }
        else
        {
            const char* szBaseName = szFileName;
            const char* szSeparator = SStrChrR(szBaseName, ':');
            if (szSeparator)
                szBaseName = szSeparator + 1;
            szSeparator = SStrChrR(szBaseName, '\\');
            if (szSeparator)
                szBaseName = szSeparator + 1;

            unsigned int nKey = sub_00415330_HashString(3, szBaseName);
            D2StormBlockStrc* pFileBlock = pBlock;
            const unsigned int dwBlockFlags = pFileBlock->dwFlags;
            D2StormArchiveRecStrc* pFileArchive = pArchive;
            if (dwBlockFlags & 0x20000)
                nKey = (pFileBlock->nOffset - pFileArchive->nArchiveOffset + nKey) ^ pFileBlock->nFileSize;

            const unsigned int nBlocks = (pFileBlock->nFileSize + pFileArchive->nBlockSize - 1) / pFileArchive->nBlockSize;
            unsigned int* pBlockOffsets = 0;
            if (dwBlockFlags & 0xFF00)
                pBlockOffsets = (unsigned int*)SMemAlloc((nBlocks + 1) * sizeof(unsigned int), gszSFileSourceFile_006CF084, 0x1231, 0);

            D2StormFileRecStrc* pFile = (D2StormFileRecStrc*)gFileList_0070836C.sub_00418F20_NewNode(1, 0, 0);
            SStrCopy(pFile->name, szFileName, 0x104);
            pFile->hFile = (void*)-1;
            pFile->pArchive = pFileArchive;
            pFile->pBlock = pFileBlock;
            pFile->nKey = nKey;
            pFile->nBlocks = nBlocks;
            pFile->pBlockOffsets = pBlockOffsets;
            pFile->pBuffer = (unsigned char*)SMemAlloc(0x1000, gszSFileSourceFile_006CF084, 0x123C, 0);
            pFile->nRefCount = 1;
            pFile->nCrcValue = pFileBlock->nCrc ? gnFileCrc_007790B0 : 0;
            pFile->nCrcState = 1;
            ++pFileArchive->nOpenFiles;
            *phFile = pFile;
            nResult = 1;
        }
    }

    LeaveCriticalSection(&gBasePathLock_00779068);
    if (nResult && gpfnOpenFileCallback_00779060)
        gpfnOpenFileCallback_00779060(szFileName, gpOpenFileCallbackParam_00779064);

    return nResult;
}

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

// 0x00415950
static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}

// 0x0041BCA0
int __stdcall SFileOpenFileAsArchive(unsigned int hMpq, const char* szName, int nPriority, unsigned int nFlags, void** phArchive)
{
    void* hFile;
    if (!SFileOpenFileEx(hMpq, szName, sub_00418B50(), &hFile))
        return 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pFile;
    sub_00415950_GetFileRec(hFile, &pFile);
    if (pFile->hFile != INVALID_FILE_HANDLE)
    {
        SFileCloseFile(hFile);
        LeaveCriticalSection(&gBasePathLock_00779068);
        char szPath[0x104];
        sub_00415B00_FindDiskFile(sub_00418B50(), szName, szPath);
        return SFileOpenArchive(szName, nPriority, nFlags, phArchive);
    }
    if (!(pFile->pBlock->dwFlags & 0x1FF00))
    {
        void* pMemory = SMemAlloc(sizeof(D2StormArchiveRecStrc), gszTypeNameArchiveRec_00708398, -2, 8);
        D2StormArchiveRecStrc* pArchive = pMemory ? new (pMemory) D2StormArchiveRecStrc : 0;
        SStrCopy(pArchive->szName, szName, 0x104);
        pArchive->hFile = pFile->pArchive->hFile;
        pArchive->nMode = pFile->pArchive->nMode;
        pArchive->bNoDiskSearch = (nFlags >> 2) & 1;
        pArchive->nPriority = nPriority;
        pArchive->nRefs = 0;
        pArchive->nOpenFiles = 1;
        pArchive->hNestedFile = hFile;
        pArchive->pHeader = (D2StormMpqHeaderStrc*)SMemAlloc(sizeof(D2StormMpqHeaderStrc), gszSFileSourceFile_006CF084, 0x11AD, 0);
        pArchive->nArchiveOffset = pFile->pBlock->nOffset;
        pArchive->nArchiveLimit = pFile->pBlock->nFileSize + pFile->pBlock->nOffset;
        s_OpenArchive(pArchive, nFlags, pArchive->nMode, phArchive);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 1;
    }
    SFileCloseFile(hFile);
    sub_0041C340_SetLastError(0x3EE);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 0;
}
