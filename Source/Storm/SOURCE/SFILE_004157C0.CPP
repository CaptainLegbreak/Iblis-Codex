#include "D2GameTypes.h"
#include "D2SFileTypes.h"
#include "Storm.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"
#define INVALID_FILE_HANDLE ((void*)-1)


typedef int (__stdcall* D2CryptAcquireContextFn)(unsigned int*, const char*, const char*, unsigned int, unsigned int);
typedef int (__stdcall* D2CryptCreateHashFn)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
typedef int (__stdcall* D2CryptDestroyFn)(unsigned int);
typedef int (__stdcall* D2CryptHashDataFn)(unsigned int, const unsigned char*, unsigned int, unsigned int);
typedef int (__stdcall* D2CryptImportKeyFn)(unsigned int, const void*, unsigned int, unsigned int, unsigned int, unsigned int*);
typedef int (__stdcall* D2CryptReleaseContextFn)(unsigned int, unsigned int);
typedef int (__stdcall* D2CryptSignHashFn)(unsigned int, unsigned int, const char*, unsigned int, unsigned char*, unsigned int*);
typedef int (__stdcall* D2CryptVerifySignatureFn)(unsigned int, const unsigned char*, unsigned int, unsigned int, const char*, unsigned int);

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
void __fastcall CrcBuffer(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags); // 0x0041D810
void __cdecl sub_004158E0_InitBasePath();                                                                   // 0x004158E0
int __cdecl sub_00418B50();                                                                         // 0x00418B50
void* __cdecl StormGetInstance();                                                                  // 0x0041BEF0
void __cdecl sub_0041A880_StartThread();                                                                    // 0x0041A880
void __cdecl sub_00419C00_PumpStreams();
int __stdcall SFileCloseFile(void* pArg);                                                                     // 0x004198D0
int __stdcall SFileCloseArchive(void* hMpq);                                                                // 0x00419A80
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);
int __stdcall SFileAuthenticateArchiveEx(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00415BB0
unsigned int __stdcall InternalReadAligned(FILEREC* pFile, unsigned int nOffset, unsigned char* pBuffer, unsigned int nSize); // 0x00416AD0

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
extern ARCHIVEREC* gpArchiveHead_0070835C;                                                       // 0x0070835C
extern D2StormEventListStrc gEventList_00708378;                                                            // 0x00708378
extern char* gpEventHead_00708380;                                                                          // 0x00708380
extern char gszTypeNameArchiveRec_00708398[];                                                               // 0x00708398
extern unsigned short gwLocale_0077905C;                                                                    // 0x0077905C
extern unsigned char gnPlatform_0077905E;                                                                   // 0x0077905E
extern int gbThreadStop_00778F24;                                                                           // 0x00778F24
extern unsigned int gnReadRate_0077904C;                                                                    // 0x0077904C
extern unsigned int gnReadUnit_00708348;                                                                    // 0x00708348
extern void* ghStormEvent_00779054;                                                                         // 0x00779054
static REQUEST* gpCurrentRequest_0077902C;                                                       // 0x0077902C
extern unsigned int gnStreamChunk_00779038;                                                                 // 0x00779038
extern unsigned char* gpStreamBuffer_00779050;                                                              // 0x00779050

// build: context EventHead
static inline char* EventHead()
{
    return (int)gpEventHead_00708380 > 0 ? gpEventHead_00708380 : 0;
}

// 0x004154B0
static int __stdcall ReadFileChecked(unsigned int* pnFilePos, void* pBuffer, unsigned int nSize, const char* szName, unsigned long* pnRead, unsigned int nOffset, void* hFile)
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
static int __stdcall sub_00415560_ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, unsigned int nOffset, FILEREC* pFile)
{
    unsigned int nFilePos;
    unsigned long nRead = 0;
    ReadFileChecked(&nFilePos, pBuffer, nSize, pFile->szName, &nRead, nOffset, pFile->hFile);
    if (pnRead)
        *pnRead = nRead;
    return nRead == nSize;
}

// 0x004157C0
static void sub_004157C0_FillStreamBuffer(REQUEST* pRequest)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    // stands for a release-build assertion that a whole chunk fits in the sound buffer; without it the write-position sum below is evaluated in another order
    __assume(pRequest->stream->soundbuffersize - pRequest->soundbufferoffset >= gnStreamChunk_00779038);
    unsigned long nLocked;
    unsigned char** const ppDest = &pRequest->pDest;
    if (pRequest->pBuffer->Lock(pRequest->soundbufferoffset, gnStreamChunk_00779038, (void**)ppDest, &nLocked, 0, 0, 0) < 0
        || nLocked != gnStreamChunk_00779038)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return;
    }

    unsigned int nCopy = nLocked;
    if (pRequest->nRead < nCopy)
        nCopy = pRequest->nRead;
    SMemCopy(*ppDest, gpStreamBuffer_00779050, nCopy);
    if (nCopy < nLocked)
        SMemFill(*ppDest + nCopy, nLocked - nCopy, pRequest->stream->nFill);
    pRequest->pBuffer->Unlock(*ppDest, nLocked, 0, 0);
    pRequest->stream->writecursor = pRequest->location - pRequest->stream->waveheadersize + nLocked;
    if (pRequest->stream->writecursor > pRequest->stream->nSize)
        pRequest->stream->nCounter = pRequest->stream->writecursor - pRequest->stream->nSize;
    AUDIOSTREAM* pStream = pRequest->stream;
    if (pStream->fillstatus == 1)
    {
        const unsigned int nQueued = pRequest->nBytes - pRequest->stream->waveheadersize + pRequest->location;
        unsigned int nNeeded = pRequest->stream->nSize > 0x10000 ? 0x10000 : pStream->nSize;
        if (nNeeded >= pStream->soundbuffersize)
            nNeeded = pStream->soundbuffersize;
        if (nQueued >= nNeeded)
        {
            pRequest->stream->pBuffer->Play(0, 0, 1);
            pRequest->stream->fillstatus = 2;
        }
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
}

// 0x00416FB0
static unsigned int sub_00416FB0_LoadBlock(unsigned int nOffset, FILEREC* pFile)
{
    if (pFile->archive->pCachedFile == pFile && pFile->archive->nCachedOffset == nOffset)
        return pFile->archive->nCachedSize;
    unsigned int nSize = pFile->archive->sectorsize;
    D2StormBlockStrc* pBlock = pFile->pBlock;
    if (nOffset + nSize > pBlock->nFileSize && !(pBlock->dwFlags & 0xFF00))
        nSize = pBlock->nFileSize - nOffset;
    pFile->archive->pCachedFile = pFile;
    pFile->archive->nCachedOffset = nOffset;
    pFile->archive->nCachedSize = InternalReadAligned(pFile, nOffset, pFile->archive->pBlockBuffer, nSize);
    return pFile->archive->nCachedSize;
}

// build: context InternalReadUnaligned
static unsigned int __stdcall InternalReadUnaligned(unsigned char* pBuffer, unsigned int nSize, FILEREC* pFile, unsigned int nPosition) // 0x00417040
{
    const unsigned int nFileSize = pFile->pBlock->nFileSize;
    if (nFileSize <= nPosition)
        return 0;
    nSize = nSize < nFileSize - nPosition ? nSize : nFileSize - nPosition;
    if (pFile->bCrc && !nPosition)
    {
        CrcBuffer(0, 0, &pFile->nCrc, 1);
        pFile->nCrcPos = 0;
        pFile->nCrcState = 2;
    }
    unsigned int nHead = 0;
    if (nPosition & (pFile->archive->sectorsize - 1))
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        nHead = sub_00416FB0_LoadBlock(~(pFile->archive->sectorsize - 1) & nPosition, pFile);
        unsigned int nCopy = nSize;
        if (nCopy >= pFile->archive->sectorsize - ((pFile->archive->sectorsize - 1) & nPosition))
            nCopy = pFile->archive->sectorsize - ((pFile->archive->sectorsize - 1) & nPosition);
        SMemCopy(pBuffer, pFile->archive->pBlockBuffer + ((pFile->archive->sectorsize - 1) & nPosition), nCopy);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            CrcBuffer(pBuffer, nCopy, &pFile->nCrc, 2);
            pFile->nCrcPos += nCopy;
        }
        pBuffer += nCopy;
        nSize -= nCopy;
        if (nHead != pFile->archive->sectorsize || !nSize)
        {
            const unsigned int nSkip = (pFile->archive->sectorsize - 1) & nPosition;
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
        const unsigned int nAligned = ~(pFile->archive->sectorsize - 1) & nSize;
        nMiddle = InternalReadAligned(pFile, nPosition, pBuffer, nAligned);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            CrcBuffer(pBuffer, nMiddle, &pFile->nCrc, 2);
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
        SMemCopy(pBuffer, pFile->archive->pBlockBuffer, nSize);
        if (nSize < nTail)
            nTail = nSize;
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            CrcBuffer(pBuffer, nTail, &pFile->nCrc, 2);
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
void __stdcall CheckRequests(ARCHIVEREC* pLastArchive, unsigned int nLastOffset, REQUEST** ppDue, REQUEST** ppNear, int* pnDistance)
{
    *ppDue = 0;
    *ppNear = 0;
    *pnDistance = 0x7FFFFFFF;
    unsigned int nBest = 0xFFFFFFFF;
    unsigned long nNow = GetTickCount();
    for (REQUEST* p = (REQUEST*)gRequestList_00708360.Head(); _ReadWriteBarrier(), (int)p > 0; p = (REQUEST*)p->tLink.m_next)
    {
        if (p->nDestSize)
        {
            if (p->tLink.Prev() && p->nDestSize == ((REQUEST*)p->tLink.Prev())->nDestSize)
                continue;
        }

        unsigned int nDistance = 0;
        if (gnValue_00708350 && !p->stream)
        {
            ARCHIVEREC* pArchive = p->pFile->archive;
            unsigned int nSkip = 0;
            if (pArchive && nLastOffset > pArchive->sectorsize)
                nSkip = nLastOffset - pArchive->sectorsize;
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
unsigned long __stdcall CdThreadProc(void* pParam)
{
    ARCHIVEREC* pLastArchive = 0;
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
            SetEvent(((EVENTREC*)pNode)->hEvent);
            pNode = gEventList_00708378.sub_00419690_DeleteNode(pNode);
        }
        sub_00419C00_PumpStreams();
        REQUEST* pNear;
        int nDistance;
        REQUEST* pDue;
        CheckRequests(pLastArchive, nLastOffset, &pDue, &pNear, &nDistance);
        REQUEST* pRequest = pNear;
        if (!pRequest || nDistance > 1000)
        {
            REQUEST* pNext = pDue;
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
        pLastArchive = pRequest->pFile->archive;
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
                gpCurrentRequest_0077902C->nRead = InternalReadUnaligned(pDest, gpCurrentRequest_0077902C->nBytes, gpCurrentRequest_0077902C->pFile, gpCurrentRequest_0077902C->location);
                FILEREC* pFile = gpCurrentRequest_0077902C->pFile;
                if (pFile->bCrc && pFile->nCrcState == 2 && pFile->nCrcPos == pFile->pBlock->nFileSize)
                {
                    CrcBuffer(0, 0, &pFile->nCrc, 4);
                    gpCurrentRequest_0077902C->pFile->nCrcState = 4;
                }
            }
            else
            {
                sub_00415560_ReadFileRec(pDest, gpCurrentRequest_0077902C->nBytes, &gpCurrentRequest_0077902C->nRead, gpCurrentRequest_0077902C->location, gpCurrentRequest_0077902C->pFile);
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
                if (gpCurrentRequest_0077902C->stream)
                    gpCurrentRequest_0077902C->stream->fillstatus = 4;
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
            REQUEST* pDone = gpCurrentRequest_0077902C;
            pDone->~REQUEST();
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
