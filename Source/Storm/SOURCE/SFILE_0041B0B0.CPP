#include "Storm.h"
#include "D2GameTypes.h"


struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormMpqHeaderStrc
{
    unsigned int dwSignature;

    unsigned int nHeaderSize;
    unsigned int nArchiveSize;
    unsigned short wVersion;
    unsigned char nSectorShift;
    unsigned char unk0x0F;
    unsigned int nHashOffset;
    unsigned int nBlockOffset;
    unsigned int nHashEntries;
    unsigned int nBlockEntries;
};

struct D2StormHashEntryStrc
{
    unsigned int nName1;
    unsigned int nName2;

    unsigned short wLocale;
    unsigned char nPlatform;
    unsigned char unk0x0B;
    int nBlockIndex;
};

struct D2FileTimeStrc
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};

struct D2StormBlockStrc
{
    unsigned int nOffset;
    unsigned int nPackedSize;

    unsigned int nFileSize;
    unsigned int dwFlags;
    D2FileTimeStrc tFileTime;
    unsigned int nCrc;
    unsigned int dwDigest[4];

    void sub_004156A0_ExpandEntries(unsigned int nCount);                                                    // 0x004156A0
};

struct D2StormFileRecStrc;

struct D2StormArchiveRecStrc
{
    D2StormLinkStrc tLink;

    char szName[0x104];
    void* hFile;
    int nMode;
    int bNoDiskSearch;
    int nPriority;
    D2StormFileRecStrc* pCachedFile;
    unsigned int nCachedOffset;
    unsigned int nBlockSize;
    unsigned char* pBlockBuffer;
    unsigned int nCachedSize;
    unsigned int nArchiveOffset;
    unsigned int nArchiveLimit;
    D2StormMpqHeaderStrc* pHeader;
    D2StormBlockStrc* pBlockTable;
    D2StormHashEntryStrc* pHashTable;
    unsigned int nFilePos;
    int bNested;
    void* hNestedFile;
    D2StormArchiveRecStrc* pPatch;
    char szPrefix[0x104];
    int nRefs;

    D2StormArchiveRecStrc()
    {
        tLink.m_prevlink = 0;
        tLink.m_next = 0;
    }
    ~D2StormArchiveRecStrc();                                                                                // 0x00418A50
};

struct D2StormFileRecStrc
{
    D2StormLinkStrc tLink;

    char szName[0x108];
    void* hFile;
    D2StormArchiveRecStrc* pArchive;
    D2StormBlockStrc* pBlock;
    unsigned int nKey;
    unsigned int nPosition;
    int unk0x124;
    unsigned int nBlocks;
    unsigned int* pBlockOffsets;
    int bOffsetsLoaded;
    char pad0x134[0x10];
    int nRequests;
    unsigned int nCrc;
    int bCrc;
    int nCrcState;
    unsigned int nCrcPos;
};

struct D2StormSoundBufferStrc
{
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* pnPlay, unsigned long* pnWrite) = 0;
    virtual long __stdcall GetFormat(void* pFormat, unsigned long nSize, unsigned long* pnWritten) = 0;
    virtual long __stdcall GetVolume(long* pnVolume) = 0;
    virtual long __stdcall GetPan(long* pnPan) = 0;
    virtual long __stdcall GetFrequency(unsigned long* pnFrequency) = 0;
    virtual long __stdcall GetStatus(unsigned long* pnStatus) = 0;
    virtual long __stdcall Initialize(void* pDirectSound, const void* pDesc) = 0;
    virtual long __stdcall Lock(unsigned long nOffset, unsigned long nBytes, void** ppPtr1, unsigned long* pnBytes1, void** ppPtr2, unsigned long* pnBytes2, unsigned long nFlags) = 0;
    virtual long __stdcall Play(unsigned long nReserved, unsigned long nPriority, unsigned long nFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long nPosition) = 0;
    virtual long __stdcall SetFormat(const void* pFormat) = 0;
    virtual long __stdcall SetVolume(long nVolume) = 0;
    virtual long __stdcall SetPan(long nPan) = 0;
    virtual long __stdcall SetFrequency(unsigned long nFrequency) = 0;
    virtual long __stdcall Stop() = 0;
    virtual long __stdcall Unlock(void* pPtr1, unsigned long nBytes1, void* pPtr2, unsigned long nBytes2) = 0;
};

struct D2StormStreamStrc
{
    D2StormLinkStrc tLink;

    D2StormFileRecStrc* pFile;
    unsigned int nWritePos;
    int unk0x10;
    int bRestart;
    int nState;
    unsigned int nCounter;
    unsigned int nStart;
    unsigned int nSize;
    unsigned int nOffset;
    unsigned int nPlayed;
    unsigned int nWritten;
    int nVolume;
    int nPan;
    D2StormSoundBufferStrc* pBuffer;
    unsigned int nBufferSize;
    int unk0x44;
    unsigned char nFill;
    char pad0x49[3];
    int nRefs;
};

struct D2StormRequestStrc
{
    D2StormLinkStrc tLink;

    void* hEvent;
    D2StormFileRecStrc* pFile;
    unsigned int nPosition;
    unsigned int nFileOffset;
    unsigned int nDueTime;
    int nArg9;
    unsigned char* pDest;
    unsigned int nDestSize;
    D2StormSoundBufferStrc* pBuffer;
    unsigned int nBufferOffset;
    D2StormStreamStrc* pStream;
    unsigned int nBytes;
    int bDelete;
    unsigned int nRead;
    D2StormRequestCallbackStrc* pCallback;

    ~D2StormRequestStrc();                                                                                  // 0x0041A020
};

struct D2StormArchiveListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormArchiveRecStrc* Head()
    {
        return (D2StormArchiveRecStrc*)m_terminator.Next();
    }
    void LinkBefore(D2StormArchiveRecStrc* pNode, D2StormArchiveRecStrc* pExisting)
    {
        pNode->tLink.Unlink();
        D2StormLinkStrc* pExistingLink = pExisting ? &pExisting->tLink : &m_terminator;
        D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pNode->tLink.m_prevlink = pPrevLink;
        pNode->tLink.m_next = pPrevLink->m_next;
        pPrevLink->m_next = (char*)pNode;
        pExistingLink->m_prevlink = &pNode->tLink;
    }
};

struct D2StormEventStrc
{
    D2StormLinkStrc tLink;
    void* hEvent;
};

struct D2StormEventListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_00419690_DeleteNode(char* pNode);                                                             // 0x00419690
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long nMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);                             // 0x00686900
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith);                    // 0x0041D2C0
const char* __stdcall SStrChrR(const char* szString, char nChar);                                           // 0x004134D0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __fastcall sub_0041D810_Crc32(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags); // 0x0041D810
void __cdecl sub_004158E0_InitBasePath();                                                                   // 0x004158E0
int __cdecl sub_00418B50();                                                                         // 0x00418B50
void* __cdecl sub_0041BEF0_GetExeModule();                                                                  // 0x0041BEF0
void __cdecl sub_0041A880_StartThread();                                                                    // 0x0041A880
void __cdecl sub_00419C00_PumpStreams();
int __stdcall sub_004198D0(void* pArg);                                                                     // 0x004198D0
int __stdcall SFileCloseArchive(void* hMpq);                                                                // 0x00419A80
int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0
int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pdwFileSizeHigh);                  // 0x00416370
int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped);       // 0x0041B050
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);
int __stdcall sub_00415BB0_CheckAuthentication(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00415BB0
unsigned int __stdcall sub_00416AD0_ReadBlocks(D2StormFileRecStrc* pFile, unsigned int nOffset, unsigned char* pBuffer, unsigned int nSize);
void __stdcall sub_0041A450_PickRequest(D2StormArchiveRecStrc* pLastArchive, unsigned int nLastOffset, D2StormRequestStrc** ppDue, D2StormRequestStrc** ppNear, int* pnDistance); // 0x0041A450

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern unsigned int* gpCryptTable_00779048;                                                                 // 0x00779048
extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030
extern char gszBasePath_00778F28[];                                                                         // 0x00778F28
extern "C" const char gszSFileCpp_006CF084[];                                                               // 0x006CF084
extern const D2StormSignatureKeyStrc gaSignatureKeys_006CF07C[];                                            // 0x006CF07C
extern D2StormArchiveListStrc gArchiveList_00708354;                                                        // 0x00708354
extern D2StormEventListStrc gEventList_00708378;                                                            // 0x00708378
extern int gbThreadStop_00778F24;                                                                           // 0x00778F24
extern void* ghStormEvent_00779054;                                                                         // 0x00779054
static D2StormRequestStrc* gpCurrentRequest_0077902C;                                                       // 0x0077902C
extern unsigned int gnStreamChunk_00779038;                                                                 // 0x00779038
extern unsigned char* gpStreamBuffer_00779050;                                                              // 0x00779050

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

static inline D2StormArchiveRecStrc* ArchiveHead()
{
    return (int)gpArchiveHead_0070835C > 0 ? gpArchiveHead_0070835C : 0;
}

static inline char* EventHead()
{
    return (int)gpEventHead_00708380 > 0 ? gpEventHead_00708380 : 0;
}

// 0x004152D0
static void sub_004152D0_DecryptBlock(unsigned int* pData, unsigned int nBytes, unsigned int nKey)
{
    unsigned int nSeed = 0xEEEEEEEE;
    unsigned int nCount = nBytes >> 2;
    while (nCount--)
    {
        nSeed += gpCryptTable_00779048[0x400 + (nKey & 0xFF)];
        *pData ^= nKey + nSeed;
        nSeed = *pData + nSeed + (nSeed << 5) + 3;
        ++pData;
        nKey = ((~nKey << 0x15) + 0x11111111) | (nKey >> 0x0B);
    }
}

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

// 0x004154B0
static int __stdcall sub_004154B0_ReadAt(unsigned int* pnFilePos, void* pBuffer, unsigned int nOffset, unsigned int nSize, const char* szName, void* hFile, unsigned long* pnRead)
{
    int nRetry = 0;
    for (;;)
    {
        if (nOffset != -1)
            SetFilePointer(hFile, nOffset, 0, 0);
        const int bRead = ReadFile(hFile, pBuffer, nSize, pnRead, 0);
        *pnFilePos = *pnRead + nOffset;
        if (bRead)
        {
            if (*pnRead == nSize)
                return 1;
            sub_0041C340_SetLastError(0x26);
            return 0;
        }
        const unsigned long dwError = GetLastError();
        switch (gnValueA_0070834C)
        {
        case 0:
            return 0;
        case 1:
            if (!gpfnReadErrorCallback_00779030)
                return 0;
            if (!gpfnReadErrorCallback_00779030(szName, dwError, nRetry++))
                return 0;
            break;
        case 2:
            SErrDisplayError(dwError, szName, -4, 0, 0, 1);
            break;
        }
    }
}

static __declspec(noinline) int __stdcall sub_0041B0B0_LoadAttributes(D2StormArchiveRecStrc* pArchive, D2StormBlockStrc* pBlockTable, unsigned int nCount);

// 0x0041B0B0
static int __stdcall sub_0041B0B0_LoadAttributes(D2StormArchiveRecStrc* pArchive, D2StormBlockStrc* pBlockTable, unsigned int nCount)
{
    int bResult = 0;
    void* hFile;
    if (SFileOpenFileEx((unsigned int)pArchive, "(attributes)", 0, &hFile))
    {
        unsigned int nSize = sub_00416370_StormGetFileSize(hFile, 0);
        unsigned char* pData = (unsigned char*)SMemAlloc(nSize, gszSFileCpp_006CF084, 1411, 0);
        if (SFileReadFile(hFile, pData, nSize, 0, 0))
        {
            unsigned int nExpected = 8;
            if (nSize >= nExpected)
            {
                unsigned int dwFlags = ((unsigned int*)pData)[1];
                unsigned char* pCursor = pData + 8;
                unsigned int bChecksum = dwFlags & 1;
                if (dwFlags & 1)
                    nExpected += nCount * 4;
                unsigned int bTime = dwFlags & 2;
                if (bTime)
                    nExpected += nCount * 8;
                unsigned int bDigest = dwFlags & 4;
                if (bDigest)
                    nExpected += nCount * 16;
                if (nSize == nExpected)
                {
                    if (bChecksum)
                    {
                        for (unsigned int i = 0; i < nCount; ++i, pCursor += 4)
                            pBlockTable[i].nCrc = *(unsigned int*)pCursor;
                    }
                    if (bTime)
                    {
                        for (unsigned int i = 0; i < nCount; ++i, pCursor += 8)
                            pBlockTable[i].tFileTime = *(D2FileTimeStrc*)pCursor;
                    }
                    if (bDigest)
                    {
                        for (unsigned int i = 0; i < nCount; ++i, pCursor += 16)
                        {
                            unsigned int* pDigest = pBlockTable[i].dwDigest;
                            const unsigned int* pSource = (const unsigned int*)pCursor;
                            pDigest[0] = pSource[0];
                            pDigest[1] = pSource[1];
                            pDigest[2] = pSource[2];
                            pDigest[3] = pSource[3];
                        }
                    }
                    bResult = 1;
                }
            }
        }
        if (pData)
            SMemFree(pData, gszSFileCpp_006CF084, 1450, 0);
        sub_004198D0(hFile);
    }
    return bResult;
}

static void sub_004152D0_DecryptBlock(unsigned int* pData, unsigned int nBytes, unsigned int nKey); // 0x004152D0
static unsigned int __stdcall sub_00415330_HashString(unsigned int nHashType, const char* szString); // 0x00415330
static int __stdcall sub_004154B0_ReadAt(unsigned int* pnFilePos, void* pBuffer, unsigned int nOffset, unsigned int nSize, const char* szName, void* hFile, unsigned long* pnRead); // 0x004154B0

int __fastcall sub_0041B6B0_LoadArchive(D2StormArchiveRecStrc* pArchive, unsigned int nFlags, int bKeepOnFail, void** phArchive); // 0x0041B6B0
// build: context sub_0041B6B0_LoadArchive
int __fastcall sub_0041B6B0_LoadArchive(D2StormArchiveRecStrc* pArchive, unsigned int nFlags, int bKeepOnFail, void** phArchive)
{
    unsigned char* pBuffer = (unsigned char*)SMemAlloc(0x1000, gszSFileCpp_006CF084, 0x10C2, 0);
    unsigned int nBufferStart = 0;
    unsigned int nBufferSize = 0;
    for (;;)
    {
        if (pArchive->nArchiveOffset >= nBufferStart + nBufferSize)
        {
            nBufferStart = pArchive->nArchiveOffset;
            SetFilePointer(pArchive->hFile, pArchive->nArchiveOffset, 0, 0);
            unsigned long nRead = 0;
            ReadFile(pArchive->hFile, pBuffer, 0x1000, &nRead, 0);
            if (nRead < sizeof(D2StormMpqHeaderStrc) || pArchive->nArchiveOffset + sizeof(D2StormMpqHeaderStrc) >= pArchive->nArchiveLimit)
            {
                pArchive->~D2StormArchiveRecStrc();
                SMemFree(pArchive, gszDelete_006CC824, -1, 0);
                sub_0041C340_SetLastError(0x8510006C);
                SMemFree(pBuffer, gszSFileCpp_006CF084, 0x10DF, 0);
                return 0;
            }
            nBufferSize = nRead;
        }
        SMemCopy(pArchive->pHeader, pBuffer + pArchive->nArchiveOffset - nBufferStart, sizeof(D2StormMpqHeaderStrc));
        if (pArchive->pHeader->dwSignature == 0x1A51504D && pArchive->pHeader->nHeaderSize >= sizeof(D2StormMpqHeaderStrc))
        {
            SMemFree(pBuffer, gszSFileCpp_006CF084, 0x1106, 0);
            break;
        }
        pArchive->nArchiveOffset += 0x200;
    }
    pArchive->nBlockSize = 0x200 << pArchive->pHeader->nSectorShift;
    pArchive->pBlockBuffer = (unsigned char*)SMemAlloc(pArchive->nBlockSize, gszSFileCpp_006CF084, 0x110B, 0);
    pArchive->pHashTable = (D2StormHashEntryStrc*)SMemAlloc(pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), gszSFileCpp_006CF084, 0x1114, 0);
    unsigned long nRead;
    sub_004154B0_ReadAt(&pArchive->nFilePos, pArchive->pHashTable, pArchive->pHeader->nHashOffset + pArchive->nArchiveOffset, pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), pArchive->szName, pArchive->hFile, &nRead);
    sub_004152D0_DecryptBlock((unsigned int*)pArchive->pHashTable, pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), sub_00415330_HashString(3, gszHashTableKey_006CF1D8));
    pArchive->pBlockTable = (D2StormBlockStrc*)SMemAlloc(pArchive->pHeader->nBlockEntries * sizeof(D2StormBlockStrc), gszSFileCpp_006CF084, 0x1133, 0);
    sub_004154B0_ReadAt(&pArchive->nFilePos, pArchive->pBlockTable, pArchive->pHeader->nBlockOffset + pArchive->nArchiveOffset, pArchive->pHeader->nBlockEntries << 4, pArchive->szName, pArchive->hFile, &nRead);
    sub_004152D0_DecryptBlock((unsigned int*)pArchive->pBlockTable, pArchive->pHeader->nBlockEntries << 4, sub_00415330_HashString(3, gszBlockTableKey_006CF1C8));
    pArchive->pBlockTable->sub_004156A0_ExpandEntries(pArchive->pHeader->nBlockEntries);
    if (pArchive->nArchiveOffset)
    {
        for (unsigned int i = 0; i < pArchive->pHeader->nBlockEntries; ++i)
        {
            if (pArchive->pBlockTable[i].nOffset)
                pArchive->pBlockTable[i].nOffset += pArchive->nArchiveOffset;
        }
    }
    D2StormArchiveRecStrc* pExisting;
    for (pExisting = gArchiveList_00708354.Head(); pExisting; pExisting = (D2StormArchiveRecStrc*)pExisting->tLink.Next())
    {
        if (pExisting->nPriority <= pArchive->nPriority)
            break;
    }
    gArchiveList_00708354.LinkBefore(pArchive, pExisting);
    if (pArchive->nMode)
    {
        sub_0041A880_StartThread();
    }
    else if ((nFlags & 1) && !bKeepOnFail)
    {
        SFileCloseArchive(pArchive);
        sub_0041C340_SetLastError(0x0F);
        return 0;
    }
    *phArchive = pArchive;
    LeaveCriticalSection(&gBasePathLock_00779068);
    sub_0041B0B0_LoadAttributes(pArchive, pArchive->pBlockTable, pArchive->pHeader->nBlockEntries);
    EnterCriticalSection(&gBasePathLock_00779068);
    return 1;
}
