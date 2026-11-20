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

struct D2StormBlockStrc
{
    unsigned int nOffset;
    unsigned int nPackedSize;

    unsigned int nFileSize;
    unsigned int dwFlags;
    unsigned int unk0x10;
    unsigned int unk0x14;
    unsigned int nCrc;
    unsigned int unk0x1C[4];

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
    void sub_0041B0B0_LoadAttributes(D2StormBlockStrc* pBlockTable, unsigned int nCount);                    // 0x0041B0B0
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
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);
int __stdcall sub_00415BB0_CheckAuthentication(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00415BB0
unsigned int __stdcall sub_00416AD0_ReadBlocks(D2StormFileRecStrc* pFile, unsigned int nOffset, unsigned char* pBuffer, unsigned int nSize); // 0x00416AD0
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

static __declspec(noinline) int sub_00415930_GetArchiveRec(void* hArchive, D2StormArchiveRecStrc** ppRec)
{
    *ppRec = (D2StormArchiveRecStrc*)hArchive;
    return 1;
}

static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}

static void sub_004152D0_DecryptBlock(unsigned int nKey, unsigned int* pData, unsigned int nBytes)
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

static int __stdcall sub_004154B0_ReadAt(unsigned int* pnFilePos, void* pBuffer, unsigned int nSize, const char* szName, unsigned long* pnRead, unsigned int nOffset, void* hFile)
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

static __declspec(noinline) int __stdcall sub_00415560_ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, unsigned int nOffset, D2StormFileRecStrc* pFile)
{
    unsigned int nFilePos;
    unsigned long nRead = 0;
    sub_004154B0_ReadAt(&nFilePos, pBuffer, nSize, pFile->szName, &nRead, nOffset, pFile->hFile);
    if (pnRead)
        *pnRead = nRead;
    return nRead == nSize;
}

static __declspec(noinline) D2StormBlockStrc* sub_004155B0_GetBlockEntry(D2StormArchiveRecStrc* pArchive, int nHashIndex)
{
    return &pArchive->pBlockTable[pArchive->pHashTable[nHashIndex].nBlockIndex];
}

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

static void sub_004157C0_FillStreamBuffer(D2StormRequestStrc* pRequest)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    unsigned long nLocked;
    if (pRequest->pBuffer->Lock(pRequest->nBufferOffset, gnStreamChunk_00779038, (void**)&pRequest->pDest, &nLocked, 0, 0, 0) >= 0
        && nLocked == gnStreamChunk_00779038)
    {
        unsigned int nCopy = nLocked;
        if (pRequest->nRead < nCopy)
            nCopy = pRequest->nRead;
        SMemCopy(pRequest->pDest, gpStreamBuffer_00779050, nCopy);
        if (nCopy < nLocked)
            SMemFill(pRequest->pDest + nCopy, nLocked - nCopy, pRequest->pStream->nFill);
        pRequest->pBuffer->Unlock(pRequest->pDest, nLocked, 0, 0);
        const unsigned int nWritten = nLocked - pRequest->pStream->nStart;
        pRequest->pStream->nWritten = nWritten + pRequest->nPosition;
        if (pRequest->pStream->nWritten > pRequest->pStream->nSize)
            pRequest->pStream->nCounter = pRequest->pStream->nWritten - pRequest->pStream->nSize;
        D2StormStreamStrc* pStream = pRequest->pStream;
        if (pStream->nState == 1)
        {
            const unsigned int nQueued = pRequest->nBytes - pStream->nStart + pRequest->nPosition;
            unsigned int nNeeded = 0x10000;
            if (pStream->nSize <= 0x10000)
                nNeeded = pStream->nSize;
            if (nNeeded >= pStream->nBufferSize)
                nNeeded = pStream->nBufferSize;
            if (nQueued >= nNeeded)
            {
                pRequest->pStream->pBuffer->Play(0, 0, 1);
                pRequest->pStream->nState = 2;
            }
        }
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
}

static __declspec(noinline) int sub_00415940_PathPresent(const char* szPath)
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
    wsprintfA(szBuffer, gszPathJoinFormat_006CE200, gszBasePath_00778F28, szName);
    _fullpath(szOut, szBuffer, 0x104);
}

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

static unsigned int sub_00416FB0_LoadBlock(unsigned int nOffset, D2StormFileRecStrc* pFile);  // 0x00416FB0
static unsigned int sub_00416FB0_LoadBlock(unsigned int nOffset, D2StormFileRecStrc* pFile)
{
    if (pFile->pArchive->pCachedFile == pFile && pFile->pArchive->nCachedOffset == nOffset)
        return pFile->pArchive->nCachedSize;
    unsigned int nSize = pFile->pArchive->nBlockSize;
    D2StormBlockStrc* pBlock = pFile->pBlock;
    if (nOffset + nSize > pBlock->nFileSize && !(pBlock->dwFlags & 0xFF00))
        nSize = pBlock->nFileSize - nOffset;
    pFile->pArchive->pCachedFile = pFile;
    pFile->pArchive->nCachedOffset = nOffset;
    pFile->pArchive->nCachedSize = sub_00416AD0_ReadBlocks(pFile, nOffset, pFile->pArchive->pBlockBuffer, nSize);
    return pFile->pArchive->nCachedSize;
}

// 0x00417040
static unsigned int __stdcall sub_00417040_ReadArchived(unsigned char* pBuffer, unsigned int nSize, D2StormFileRecStrc* pFile, unsigned int nPosition)
{
    const unsigned int nFileSize = pFile->pBlock->nFileSize;
    if (nFileSize <= nPosition)
        return 0;
    nSize = D2_MIN(nSize, nFileSize - nPosition);
    if (pFile->bCrc && !nPosition)
    {
        sub_0041D810_Crc32(0, 0, &pFile->nCrc, 1);
        pFile->nCrcPos = 0;
        pFile->nCrcState = 2;
    }
    unsigned int nHead = 0;
    if (nPosition & (pFile->pArchive->nBlockSize - 1))
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        nHead = sub_00416FB0_LoadBlock(~(pFile->pArchive->nBlockSize - 1) & nPosition, pFile);
        const unsigned int nCopy = D2_MIN(nSize, pFile->pArchive->nBlockSize - ((pFile->pArchive->nBlockSize - 1) & nPosition));
        SMemCopy(pBuffer, pFile->pArchive->pBlockBuffer + ((pFile->pArchive->nBlockSize - 1) & nPosition), nCopy);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            sub_0041D810_Crc32(pBuffer, nCopy, &pFile->nCrc, 2);
            pFile->nCrcPos += nCopy;
        }
        pBuffer += nCopy;
        nSize -= nCopy;
        if (nHead != pFile->pArchive->nBlockSize || !nSize)
        {
            const unsigned int nSkip = (pFile->pArchive->nBlockSize - 1) & nPosition;
            if (nHead < nSkip)
                return 0;
            return nCopy < nHead - nSkip ? nCopy : nHead - nSkip;
        }
        nHead = nCopy;
        nPosition += nCopy;
    }
    unsigned int nMiddle = 0;
    if (nSize)
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        const unsigned int nAligned = ~(pFile->pArchive->nBlockSize - 1) & nSize;
        nMiddle = sub_00416AD0_ReadBlocks(pFile, nPosition, pBuffer, nAligned);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            sub_0041D810_Crc32(pBuffer, nMiddle, &pFile->nCrc, 2);
            pFile->nCrcPos += nMiddle;
        }
        pBuffer += nAligned;
        nSize -= nAligned;
        nPosition += nAligned;
        if (nAligned != nMiddle || !nSize)
            return nMiddle + nHead;
    }
    unsigned int nTail = 0;
    if (nSize)
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        nTail = sub_00416FB0_LoadBlock(nPosition, pFile);
        SMemCopy(pBuffer, pFile->pArchive->pBlockBuffer, nSize);
        if (nSize < nTail)
            nTail = nSize;
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            sub_0041D810_Crc32(pBuffer, nTail, &pFile->nCrc, 2);
            pFile->nCrcPos += nTail;
        }
    }
    return nMiddle + nTail + nHead;
}

int __stdcall SFileAuthenticateArchive(void* hArchive, unsigned int* pnResult)
{
    if (sub_00415BB0_CheckAuthentication(hArchive, pnResult, 0, 0, 0, 0))
        return 1;
    if (pnResult)
        *pnResult = 0;
    D2StormArchiveRecStrc* pArchive;
    if (!sub_00415930_GetArchiveRec(hArchive, &pArchive))
        return 0;
    int bResult = 0;
    if (sub_004155D0_FindHashEntry(0, 0, pArchive, gszSignatureName_006CF18C) == -1)
    {
        if (pnResult)
            *pnResult = 1;
        sub_0041C340_SetLastError(0x4DC);
        return 0;
    }
    D2StormCryptFuncsStrc* pFuncs = 0;
    unsigned int hHash = 0;
    unsigned int hKey = 0;
    void* hMapping = 0;
    unsigned int hProv = 0;
    unsigned char* pView = 0;
    void* hLibrary = LoadLibraryA(gszAdvapi32_006CCA1C);
    if (hLibrary)
    {
        pFuncs = (D2StormCryptFuncsStrc*)SMemAlloc(sizeof(D2StormCryptFuncsStrc), gszSFileCpp_006CF084, 0xA74, 0);
        if (!(pFuncs->pfnAcquireContext = (D2CryptAcquireContextFn)GetProcAddress(hLibrary, gszCryptAcquireContextA_006CF174)))
            goto cleanup;
        if (!(pFuncs->pfnCreateHash = (D2CryptCreateHashFn)GetProcAddress(hLibrary, gszCryptCreateHash_006CF164)))
            goto cleanup;
        if (!(pFuncs->pfnDestroyHash = (D2CryptDestroyFn)GetProcAddress(hLibrary, gszCryptDestroyHash_006CF150)))
            goto cleanup;
        if (!(pFuncs->pfnDestroyKey = (D2CryptDestroyFn)GetProcAddress(hLibrary, gszCryptDestroyKey_006CF140)))
            goto cleanup;
        if (!(pFuncs->pfnHashData = (D2CryptHashDataFn)GetProcAddress(hLibrary, gszCryptHashData_006CF130)))
            goto cleanup;
        if (!(pFuncs->pfnImportKey = (D2CryptImportKeyFn)GetProcAddress(hLibrary, gszCryptImportKey_006CF120)))
            goto cleanup;
        if (!(pFuncs->pfnReleaseContext = (D2CryptReleaseContextFn)GetProcAddress(hLibrary, gszCryptReleaseContext_006CF10C)))
            goto cleanup;
        if (!(pFuncs->pfnSignHash = (D2CryptSignHashFn)GetProcAddress(hLibrary, gszCryptSignHashA_006CF0FC)))
            goto cleanup;
        if (!(pFuncs->pfnVerifySignature = (D2CryptVerifySignatureFn)GetProcAddress(hLibrary, gszCryptVerifySignatureA_006CF0E4)))
            goto cleanup;
        if (!pFuncs->pfnAcquireContext(&hProv, gszCryptContainer_006CF0A8, gszCryptProvider_006CF0B8, 1, 0)
            && !pFuncs->pfnAcquireContext(&hProv, gszCryptContainer_006CF0A8, gszCryptProvider_006CF0B8, 1, 8))
            goto cleanup;
        hMapping = CreateFileMappingA(pArchive->hFile, 0, 0x8000002, 0, 0, 0);
        if (!hMapping)
            goto cleanup;
        pView = (unsigned char*)MapViewOfFile(hMapping, 4, 0, 0, 0);
        if (!pView)
            goto cleanup;
        const int nIndex = sub_004155D0_FindHashEntry(0, 0, pArchive, gszSignatureName_006CF18C);
        if (nIndex == -1)
            goto cleanup;
        D2StormBlockStrc* pBlock = sub_004155B0_GetBlockEntry(pArchive, nIndex);
        if ((pBlock->dwFlags & 0x1FF00) || pBlock->nFileSize <= 8 || !pBlock->nOffset)
        {
            if (pnResult)
                *pnResult = 2;
            goto cleanup;
        }
        const unsigned int nKeyIndex = *(unsigned int*)(pBlock->nOffset + pView);
        if (nKeyIndex >= 1)
        {
            if (pnResult)
                *pnResult = 3;
            goto cleanup;
        }
        void* hResInfo = FindResourceA(sub_0041BEF0_GetExeModule(), gaSignatureKeys_006CF07C[nKeyIndex].szResourceName, gszKeyResourceType_006CF0A0);
        void* hResData = LoadResource(sub_0041BEF0_GetExeModule(), hResInfo);
        void* pKey = LockResource(hResData);
        if (pKey)
            pFuncs->pfnImportKey(hProv, pKey, SizeofResource(sub_0041BEF0_GetExeModule(), hResInfo), 0, 0, &hKey);
        FreeResource(hResData);
        if (!hKey)
            goto cleanup;
        if (!pFuncs->pfnCreateHash(hProv, 0x8003, 0, 0, &hHash))
            goto cleanup;
        if (!pFuncs->pfnHashData(hHash, pView + pArchive->nArchiveOffset, pBlock->nOffset - pArchive->nArchiveOffset, 0))
            goto cleanup;
        unsigned char* pZero = (unsigned char*)SMemAlloc(pBlock->nFileSize, gszSFileCpp_006CF084, 0xACA, 8);
        const int bHashed = pFuncs->pfnHashData(hHash, pZero, pBlock->nFileSize, 0);
        SMemFree(pZero, gszSFileCpp_006CF084, 0xACF, 0);
        if (!bHashed)
            goto cleanup;
        if (pBlock->nOffset + pBlock->nFileSize < pArchive->pHeader->nArchiveSize + pArchive->nArchiveOffset)
        {
            if (!pFuncs->pfnHashData(hHash, pView + pBlock->nOffset + pBlock->nFileSize, pArchive->pHeader->nArchiveSize - pBlock->nOffset - pBlock->nFileSize + pArchive->nArchiveOffset, 0))
                goto cleanup;
        }
        if (pFuncs->pfnVerifySignature(hHash, pView + pBlock->nOffset + 8, pBlock->nFileSize - 8, hKey, 0, 0))
        {
            bResult = 1;
            if (pnResult)
                *pnResult = gaSignatureKeys_006CF07C[nKeyIndex].nResult;
        }
        else
        {
            if (pnResult)
                *pnResult = 2;
        }
    }
cleanup:
    if (hHash)
        pFuncs->pfnDestroyHash(hHash);
    if (hKey)
        pFuncs->pfnDestroyKey(hKey);
    if (pView)
        UnmapViewOfFile(pView);
    if (hMapping)
        CloseHandle(hMapping);
    if (hProv)
    {
        pFuncs->pfnReleaseContext(hProv, 0);
        pFuncs->pfnAcquireContext(&hProv, gszCryptContainer_006CF0A8, gszCryptProvider_006CF0B8, 1, 0x10);
    }
    if (pFuncs)
        SMemFree(pFuncs, gszSFileCpp_006CF084, 0xAF8, 0);
    if (hLibrary)
        FreeLibrary(hLibrary);
    if (!bResult)
        sub_0041C340_SetLastError(0x4DC);
    return bResult;
}

int __fastcall sub_00417F10_FindFile(void* hArchive, D2StormBlockStrc** ppBlock, const char* szName, unsigned int nFlags, D2StormArchiveRecStrc** ppArchive, char* szFoundPath)
{
    if (ppArchive)
        *ppArchive = 0;
    if (ppBlock)
        *ppBlock = 0;
    int bResult = 0;
    D2StormArchiveRecStrc* pOnly = 0;
    if (hArchive && !sub_00415930_GetArchiveRec(hArchive, &pOnly))
        return bResult;
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
            return 2;
        }
        if (pArchive)
        {
            const int nIndex = sub_004155D0_FindHashEntry(gwLocale_0077905C, gnPlatform_0077905E, pSearch, szLookup);
            if (nIndex != -1)
            {
                bResult = 1;
                D2StormBlockStrc* pBlock = sub_004155B0_GetBlockEntry(pSearch, nIndex);
                if ((int)pBlock->dwFlags >= 0 || ((nFlags & 4) && (pBlock->dwFlags & 0x1FF00)))
                {
                    sub_0041C340_SetLastError(0x3EE);
                    bResult = 0;
                }
                else
                {
                    if (ppArchive)
                        *ppArchive = pSearch;
                    if (ppBlock)
                        *ppBlock = pBlock;
                }
                return bResult;
            }
        }
    }
    while (pArchive && (pArchive = (D2StormArchiveRecStrc*)pArchive->tLink.Next()) != 0);
    sub_0041C340_SetLastError(2);
    return 0;
}

unsigned long __stdcall sub_0041A550_ThreadProc(void* pParam)
{
    D2StormArchiveRecStrc* pLastArchive = 0;
    unsigned int nLastOffset = 0;
    unsigned long nLastTime = GetTickCount();
    while (!gbThreadStop_00778F24)
    {
        const unsigned long nNow = GetTickCount();
        unsigned long nWait = 0;
        if (gnReadRate_0077904C)
            nWait = gnReadUnit_00708348 * 1000 / gnReadRate_0077904C;
        EnterCriticalSection(&gBasePathLock_00779068);
        for (char* pNode = EventHead(); (int)pNode > 0; )
        {
            SetEvent(((D2StormEventStrc*)pNode)->hEvent);
            pNode = gEventList_00708378.sub_00419690_DeleteNode(pNode);
        }
        sub_00419C00_PumpStreams();
        D2StormRequestStrc* pNear;
        int nDistance;
        D2StormRequestStrc* pDue;
        sub_0041A450_PickRequest(pLastArchive, nLastOffset, &pDue, &pNear, &nDistance);
        D2StormRequestStrc* pRequest = pNear;
        if (!pRequest || nDistance > 1000)
        {
            pRequest = pDue;
            if (!pRequest || nNow - nLastTime < nWait)
            {
                LeaveCriticalSection(&gBasePathLock_00779068);
                if (pRequest)
                    nWait = nWait - nNow + nLastTime;
                else
                    nWait = 0xFA;
                WaitForSingleObject(ghStormEvent_00779054, nWait);
                continue;
            }
        }
        pLastArchive = pRequest->pFile->pArchive;
        nLastOffset = pRequest->nFileOffset;
        gpCurrentRequest_0077902C = pRequest;
        nLastTime = nNow;
        pRequest->tLink.Unlink();
        LeaveCriticalSection(&gBasePathLock_00779068);
        unsigned char* pDest = !gpCurrentRequest_0077902C->pBuffer ? gpCurrentRequest_0077902C->pDest : gpStreamBuffer_00779050;
        if (pDest)
        {
            if (gpCurrentRequest_0077902C->pFile->hFile == INVALID_FILE_HANDLE)
            {
                gpCurrentRequest_0077902C->nRead = sub_00417040_ReadArchived(pDest, gpCurrentRequest_0077902C->nBytes, gpCurrentRequest_0077902C->pFile, gpCurrentRequest_0077902C->nPosition);
                D2StormFileRecStrc* pFile = gpCurrentRequest_0077902C->pFile;
                if (pFile->bCrc && pFile->nCrcState == 2 && pFile->nCrcPos == pFile->pBlock->nFileSize)
                {
                    sub_0041D810_Crc32(0, 0, &pFile->nCrc, 4);
                    gpCurrentRequest_0077902C->pFile->nCrcState = 4;
                }
            }
            else
            {
                sub_00415560_ReadFileRec(pDest, gpCurrentRequest_0077902C->nBytes, &gpCurrentRequest_0077902C->nRead, gpCurrentRequest_0077902C->nPosition, gpCurrentRequest_0077902C->pFile);
            }
        }
        else
        {
            gpCurrentRequest_0077902C->nRead = 0;
        }
        if (gpCurrentRequest_0077902C->pBuffer)
        {
            if (gpCurrentRequest_0077902C->nRead)
            {
                sub_004157C0_FillStreamBuffer(gpCurrentRequest_0077902C);
            }
            else if (gpCurrentRequest_0077902C->nBytes)
            {
                gpCurrentRequest_0077902C->pBuffer->Stop();
                if (gpCurrentRequest_0077902C->pStream)
                    gpCurrentRequest_0077902C->pStream->nState = 4;
            }
        }
        if (gpCurrentRequest_0077902C->pCallback && gpCurrentRequest_0077902C->pCallback->pfnDone)
        {
            D2StormFileRecStrc* pFile = gpCurrentRequest_0077902C->pFile;
            if (pFile->bCrc && pFile->nCrcState == 4 && pFile->nCrc != pFile->pBlock->nCrc)
                SErrDisplayError(0x85100083, pFile->szName, -4, 0, 0, 1);
            gpCurrentRequest_0077902C->pCallback->pfnDone(gpCurrentRequest_0077902C->nDestSize, gpCurrentRequest_0077902C->nRead + gpCurrentRequest_0077902C->pDest - gpCurrentRequest_0077902C->nDestSize, gpCurrentRequest_0077902C->pCallback);
        }
        void* hEvent = gpCurrentRequest_0077902C->hEvent;
        EnterCriticalSection(&gBasePathLock_00779068);
        if (gpCurrentRequest_0077902C->bDelete)
        {
            D2StormRequestStrc* pDone = gpCurrentRequest_0077902C;
            pDone->~D2StormRequestStrc();
            SMemFree(pDone, gszDelete_006CC824, -1, 0);
        }
        gpCurrentRequest_0077902C = 0;
        LeaveCriticalSection(&gBasePathLock_00779068);
        if (hEvent)
            SetEvent(hEvent);
    }
    gbThreadStop_00778F24 = 0;
    return 0;
}

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
            SetFilePointer(pArchive->hFile, nBufferStart, 0, 0);
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
            break;
        pArchive->nArchiveOffset += 0x200;
    }
    SMemFree(pBuffer, gszSFileCpp_006CF084, 0x1106, 0);
    pArchive->nBlockSize = 0x200 << pArchive->pHeader->nSectorShift;
    pArchive->pBlockBuffer = (unsigned char*)SMemAlloc(pArchive->nBlockSize, gszSFileCpp_006CF084, 0x110B, 0);
    pArchive->pHashTable = (D2StormHashEntryStrc*)SMemAlloc(pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), gszSFileCpp_006CF084, 0x1114, 0);
    unsigned long nRead;
    sub_004154B0_ReadAt(&pArchive->nFilePos, pArchive->pHashTable, pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), pArchive->szName, &nRead, pArchive->pHeader->nHashOffset + pArchive->nArchiveOffset, pArchive->hFile);
    unsigned int nKey = sub_00415330_HashString(3, gszHashTableKey_006CF1D8);
    sub_004152D0_DecryptBlock(nKey, (unsigned int*)pArchive->pHashTable, pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc));
    pArchive->pBlockTable = (D2StormBlockStrc*)SMemAlloc(pArchive->pHeader->nBlockEntries * sizeof(D2StormBlockStrc), gszSFileCpp_006CF084, 0x1133, 0);
    sub_004154B0_ReadAt(&pArchive->nFilePos, pArchive->pBlockTable, pArchive->pHeader->nBlockEntries << 4, pArchive->szName, &nRead, pArchive->pHeader->nBlockOffset + pArchive->nArchiveOffset, pArchive->hFile);
    nKey = sub_00415330_HashString(3, gszBlockTableKey_006CF1C8);
    sub_004152D0_DecryptBlock(nKey, (unsigned int*)pArchive->pBlockTable, pArchive->pHeader->nBlockEntries << 4);
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
    pArchive->sub_0041B0B0_LoadAttributes(pArchive->pBlockTable, pArchive->pHeader->nBlockEntries);
    EnterCriticalSection(&gBasePathLock_00779068);
    return 1;
}

int __stdcall sub_0041BCA0_OpenArchiveInArchive(void* hMpq, const char* szName, int nPriority, unsigned int nFlags, void** phArchive)
{
    void* hFile;
    if (!SFileOpenFileEx(hMpq, szName, sub_00418B50(), &hFile))
        return 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pFile;
    sub_00415950_GetFileRec(hFile, &pFile);
    if (pFile->hFile != INVALID_FILE_HANDLE)
    {
        sub_004198D0(hFile);
        LeaveCriticalSection(&gBasePathLock_00779068);
        char szPath[0x104];
        sub_00415B00_FindDiskFile(sub_00418B50(), szName, szPath);
        return SFileOpenArchive(szName, nPriority, nFlags, phArchive);
    }
    if (pFile->pBlock->dwFlags & 0x1FF00)
    {
        sub_004198D0(hFile);
        sub_0041C340_SetLastError(0x3EE);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    void* pMemory = SMemAlloc(sizeof(D2StormArchiveRecStrc), gszTypeNameArchiveRec_00708398, -2, 8);
    D2StormArchiveRecStrc* pArchive = pMemory ? new (pMemory) D2StormArchiveRecStrc : 0;
    SStrCopy(pArchive->szName, szName, 0x104);
    pArchive->hFile = pFile->pArchive->hFile;
    pArchive->nMode = pFile->pArchive->nMode;
    pArchive->bNoDiskSearch = (nFlags >> 2) & 1;
    pArchive->nPriority = nPriority;
    pArchive->nRefs = 0;
    pArchive->bNested = 1;
    pArchive->hNestedFile = hFile;
    pArchive->pHeader = (D2StormMpqHeaderStrc*)SMemAlloc(sizeof(D2StormMpqHeaderStrc), gszSFileCpp_006CF084, 0x11AD, 0);
    pArchive->nArchiveOffset = pFile->pBlock->nOffset;
    pArchive->nArchiveLimit = pFile->pBlock->nFileSize + pFile->pBlock->nOffset;
    sub_0041B6B0_LoadArchive(pArchive, nFlags, pArchive->nMode, phArchive);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}
