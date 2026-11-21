#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"
#define INVALID_FILE_HANDLE ((void*)-1)

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

struct D2StormRequestCallbackStrc
{
    void (__stdcall* pfnDone)(unsigned int nSize, unsigned char* pEnd, D2StormRequestCallbackStrc* pCallback);
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

struct D2StormCryptFuncsStrc
{
    int (__stdcall* pfnAcquireContext)(unsigned int* phProv, const char* szContainer, const char* szProvider, unsigned int nProvType, unsigned int nFlags);
    int (__stdcall* pfnCreateHash)(unsigned int hProv, unsigned int nAlgId, unsigned int hKey, unsigned int nFlags, unsigned int* phHash);
    int (__stdcall* pfnDestroyHash)(unsigned int hHash);
    int (__stdcall* pfnDestroyKey)(unsigned int hKey);
    int (__stdcall* pfnHashData)(unsigned int hHash, const unsigned char* pData, unsigned int nSize, unsigned int nFlags);
    int (__stdcall* pfnImportKey)(unsigned int hProv, const void* pKey, unsigned int nSize, unsigned int hPubKey, unsigned int nFlags, unsigned int* phKey);
    int (__stdcall* pfnReleaseContext)(unsigned int hProv, unsigned int nFlags);
    int (__stdcall* pfnSignHash)(unsigned int hHash, unsigned int nKeySpec, const char* szDesc, unsigned int nFlags, unsigned char* pSig, unsigned int* pnSigLen);
    int (__stdcall* pfnVerifySignature)(unsigned int hHash, const unsigned char* pSig, unsigned int nSigLen, unsigned int hKey, const char* szDesc, unsigned int nFlags);

};

typedef int (__stdcall* D2CryptAcquireContextFn)(unsigned int*, const char*, const char*, unsigned int, unsigned int);
typedef int (__stdcall* D2CryptCreateHashFn)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
typedef int (__stdcall* D2CryptDestroyFn)(unsigned int);
typedef int (__stdcall* D2CryptHashDataFn)(unsigned int, const unsigned char*, unsigned int, unsigned int);
typedef int (__stdcall* D2CryptImportKeyFn)(unsigned int, const void*, unsigned int, unsigned int, unsigned int, unsigned int*);
typedef int (__stdcall* D2CryptReleaseContextFn)(unsigned int, unsigned int);
typedef int (__stdcall* D2CryptSignHashFn)(unsigned int, unsigned int, const char*, unsigned int, unsigned char*, unsigned int*);
typedef int (__stdcall* D2CryptVerifySignatureFn)(unsigned int, const unsigned char*, unsigned int, unsigned int, const char*, unsigned int);

struct D2StormSignatureKeyStrc
{
    const char* szResourceName;
    unsigned int nResult;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();                                    // 0x006CC1B4
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName);        // 0x006CC1B0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long nMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);                   // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                  // 0x006CC14C
extern "C" __declspec(dllimport) void* __stdcall CreateFileMappingA(void* hFile, void* pAttributes, unsigned long nProtect, unsigned long nSizeHigh, unsigned long nSizeLow, const char* szName); // 0x006CC314
extern "C" __declspec(dllimport) void* __stdcall MapViewOfFile(void* hMapping, unsigned long nAccess, unsigned long nOffsetHigh, unsigned long nOffsetLow, unsigned long nBytes); // 0x006CC310
extern "C" __declspec(dllimport) int __stdcall UnmapViewOfFile(const void* pView);                          // 0x006CC2F8
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void* __stdcall FindResourceA(void* hModule, const char* szName, const char* szType); // 0x006CC30C
extern "C" __declspec(dllimport) void* __stdcall LoadResource(void* hModule, void* hResInfo);               // 0x006CC308
extern "C" __declspec(dllimport) void* __stdcall LockResource(void* hResData);                              // 0x006CC304
extern "C" __declspec(dllimport) unsigned long __stdcall SizeofResource(void* hModule, void* hResInfo);     // 0x006CC300
extern "C" __declspec(dllimport) int __stdcall FreeResource(void* hResData);                                // 0x006CC2FC
extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);                             // 0x00686900
extern "C" char* __cdecl _fullpath(char* szAbsPath, const char* szRelPath, unsigned int nMaxLength);        // 0x006867F7
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
unsigned int __stdcall sub_00416AD0_ReadBlocks(D2StormFileRecStrc* pFile, unsigned int nOffset, unsigned char* pBuffer, unsigned int nSize);

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern unsigned int* gpCryptTable_00779048;                                                                 // 0x00779048
extern int gnValueA_0070834C;                                                                               // 0x0070834C
extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030
extern char gszBasePath_00778F28[];                                                                         // 0x00778F28
extern "C" const char gszPathJoinFormat_006CE200[];                                                         // 0x006CE200
extern "C" const char gszDriveRoot_006CF09C[];                                                              // 0x006CF09C
extern "C" const char gszUncPrefix_006CF098[];                                                              // 0x006CF098
extern "C" const char gszBackslash_006FF9B8[];                                                              // 0x006FF9B8
extern "C" const char gszSFileCpp_006CF084[];                                                               // 0x006CF084
extern "C" const char gszDelete_006CC824[];                                                                 // 0x006CC824
extern "C" const char gszSignatureName_006CF18C[];                                                          // 0x006CF18C
extern "C" const char gszHashTableKey_006CF1D8[];                                                           // 0x006CF1D8
extern "C" const char gszBlockTableKey_006CF1C8[];                                                          // 0x006CF1C8
extern "C" const char gszAdvapi32_006CCA1C[];                                                               // 0x006CCA1C
extern "C" const char gszCryptAcquireContextA_006CF174[];                                                   // 0x006CF174
extern "C" const char gszCryptCreateHash_006CF164[];                                                        // 0x006CF164
extern "C" const char gszCryptDestroyHash_006CF150[];                                                       // 0x006CF150
extern "C" const char gszCryptDestroyKey_006CF140[];                                                        // 0x006CF140
extern "C" const char gszCryptHashData_006CF130[];                                                          // 0x006CF130
extern "C" const char gszCryptImportKey_006CF120[];                                                         // 0x006CF120
extern "C" const char gszCryptReleaseContext_006CF10C[];                                                    // 0x006CF10C
extern "C" const char gszCryptSignHashA_006CF0FC[];                                                         // 0x006CF0FC
extern "C" const char gszCryptVerifySignatureA_006CF0E4[];                                                  // 0x006CF0E4
extern "C" const char gszCryptProvider_006CF0B8[];                                                          // 0x006CF0B8
extern "C" const char gszCryptContainer_006CF0A8[];                                                         // 0x006CF0A8
extern "C" const char gszKeyResourceType_006CF0A0[];                                                        // 0x006CF0A0
extern const D2StormSignatureKeyStrc gaSignatureKeys_006CF07C[];                                            // 0x006CF07C
extern D2StormArchiveListStrc gArchiveList_00708354;                                                        // 0x00708354
extern D2StormArchiveRecStrc* gpArchiveHead_0070835C;                                                       // 0x0070835C
extern D2StormEventListStrc gEventList_00708378;                                                            // 0x00708378
extern char* gpEventHead_00708380;                                                                          // 0x00708380
extern char gszTypeNameArchiveRec_00708398[];                                                               // 0x00708398
extern unsigned short gwLocale_0077905C;                                                                    // 0x0077905C
extern unsigned char gnPlatform_0077905E;                                                                   // 0x0077905E
extern int gbThreadStop_00778F24;                                                                           // 0x00778F24
extern unsigned int gnReadRate_0077904C;                                                                    // 0x0077904C
extern unsigned int gnReadUnit_00708348;                                                                    // 0x00708348
extern void* ghStormEvent_00779054;                                                                         // 0x00779054
static D2StormRequestStrc* gpCurrentRequest_0077902C;                                                       // 0x0077902C
extern unsigned int gnStreamChunk_00779038;                                                                 // 0x00779038
extern unsigned char* gpStreamBuffer_00779050;                                                              // 0x00779050

// build: context EventHead
static inline char* EventHead()
{
    return (int)gpEventHead_00708380 > 0 ? gpEventHead_00708380 : 0;
}

// 0x004154B0
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

// 0x00415560
static __declspec(noinline) int __stdcall sub_00415560_ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, unsigned int nOffset, D2StormFileRecStrc* pFile)
{
    unsigned int nFilePos;
    unsigned long nRead = 0;
    sub_004154B0_ReadAt(&nFilePos, pBuffer, nSize, pFile->szName, &nRead, nOffset, pFile->hFile);
    if (pnRead)
        *pnRead = nRead;
    return nRead == nSize;
}

// build: context sub_004157C0_FillStreamBuffer
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

// 0x00416FB0
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

// build: context sub_00417040_ReadArchived
static unsigned int __stdcall sub_00417040_ReadArchived(unsigned char* pBuffer, unsigned int nSize, D2StormFileRecStrc* pFile, unsigned int nPosition)
{
    const unsigned int nFileSize = pFile->pBlock->nFileSize;
    if (nFileSize <= nPosition)
        return 0;
    nSize = nSize < nFileSize - nPosition ? nSize : nFileSize - nPosition;
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
        unsigned int nCopy = nSize;
        if (nCopy >= pFile->pArchive->nBlockSize - ((pFile->pArchive->nBlockSize - 1) & nPosition))
            nCopy = pFile->pArchive->nBlockSize - ((pFile->pArchive->nBlockSize - 1) & nPosition);
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

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct D2StormRequestListStrc
{
    int m_linkoffset;
    void* m_prevlink;
    char* m_next;
    char* Head()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
};

extern D2StormRequestListStrc gRequestList_00708360;                                                        // 0x00708360
extern int gnValue_00708350;                                                                                // 0x00708350

// 0x0041A450
void __stdcall sub_0041A450_PickRequest(D2StormArchiveRecStrc* pLastArchive, unsigned int nLastOffset, D2StormRequestStrc** ppDue, D2StormRequestStrc** ppNear, int* pnDistance)
{
    *ppDue = 0;
    *ppNear = 0;
    *pnDistance = 0x7FFFFFFF;
    unsigned int nBest = 0xFFFFFFFF;
    unsigned long nNow = GetTickCount();
    for (D2StormRequestStrc* p = (D2StormRequestStrc*)gRequestList_00708360.Head(); _ReadWriteBarrier(), (int)p > 0; p = (D2StormRequestStrc*)p->tLink.m_next)
    {
        if (p->nDestSize)
        {
            if (p->tLink.Prev() && p->nDestSize == ((D2StormRequestStrc*)p->tLink.Prev())->nDestSize)
                continue;
        }

        unsigned int nDistance = 0;
        if (gnValue_00708350 && !p->pStream)
        {
            D2StormArchiveRecStrc* pArchive = p->pFile->pArchive;
            unsigned int nSkip = 0;
            if (pArchive && nLastOffset > pArchive->nBlockSize)
                nSkip = nLastOffset - pArchive->nBlockSize;
            if (pArchive == pLastArchive)
            {
                if (p->nFileOffset < nSkip)
                    nDistance = p->nFileOffset + 0x8000000;
                else
                    nDistance = p->nFileOffset - nSkip;
            }
            else
            {
                nDistance = 0xFFFFFFFE;
            }
        }
        if (nDistance <= nBest)
        {
            nBest = nDistance;
            *ppDue = p;
        }

        int nTime = p->nDueTime - nNow;
        if (p->nArg9 && nTime >= 1000)
            nTime = 1000;
        if (nTime < *pnDistance)
        {
            *pnDistance = nTime;
            *ppNear = p;
        }
    }
}

// 0x0041A550
unsigned long __stdcall sub_0041A550_ThreadProc(void* pParam)
{
    D2StormArchiveRecStrc* pLastArchive = 0;
    unsigned int nLastOffset = 0;
    unsigned long nLastTime = GetTickCount();
    while (!gbThreadStop_00778F24)
    {
        const unsigned long nNow = GetTickCount();
        int nWait = 0;
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
            D2StormRequestStrc* pNext = pDue;
            if (!pNext || nNow - nLastTime < nWait)
            {
                LeaveCriticalSection(&gBasePathLock_00779068);
                WaitForSingleObject(ghStormEvent_00779054, pNext ? nWait - nNow + nLastTime : 0xFA);
                continue;
            }
            pRequest = pNext;
        }
        gpCurrentRequest_0077902C = pRequest;
        nLastTime = nNow;
        pLastArchive = pRequest->pFile->pArchive;
        nLastOffset = pRequest->nFileOffset;
        pRequest->tLink.Unlink();
        LeaveCriticalSection(&gBasePathLock_00779068);
        unsigned char* pDest = gpCurrentRequest_0077902C->pDest;
        if (gpCurrentRequest_0077902C->pBuffer)
            pDest = gpStreamBuffer_00779050;
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
            if (gpCurrentRequest_0077902C->pFile->bCrc && gpCurrentRequest_0077902C->pFile->nCrcState == 4 && gpCurrentRequest_0077902C->pFile->nCrc != gpCurrentRequest_0077902C->pFile->pBlock->nCrc)
                SErrDisplayError(0x85100083, gpCurrentRequest_0077902C->pFile->szName, -4, 0, 0, 1);
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
