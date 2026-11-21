#include "Storm.h"
#include "D2GameTypes.h"
#include "D2SFileTypes.h"


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith);                    // 0x0041D2C0


inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

struct D2StormRequestListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    // build: context D2StormRequestListStrc::LinkNode
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExistingNode);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    D2StormRequestStrc* NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
    {
        void* pMemory = SMemAlloc(sizeof(D2StormRequestStrc) + nExtraBytes, gszTypeNameRequest_007083F0, -2, nFlags | 8);
        D2StormRequestStrc* pRecord = pMemory ? new (pMemory) D2StormRequestStrc : 0;
        if (nLinkType)
            LinkNode((char*)pRecord, nLinkType, 0);
        return pRecord;
    }
};

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern D2StormStreamListStrc gDdaList_00708384;                                                             // 0x00708384
extern D2StormRequestListStrc gRequestList_00708360;                                                        // 0x00708360
extern void* ghStormEvent_00779054;                                                                         // 0x00779054
extern int gbStreamsPaused_00779044;                                                                        // 0x00779044
extern unsigned int gnStreamChunk_00779038;                                                                 // 0x00779038
extern D2StormStreamStrc* gpDdaHead_0070838C;                                                               // 0x0070838C

static inline D2StormStreamStrc* DdaHead()
{
    return (int)gpDdaHead_0070838C > 0 ? gpDdaHead_0070838C : 0;
}

static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}

// 0x00415760
static unsigned int sub_00415760_UpdatePlayed(D2StormStreamStrc* pStream)
{
    unsigned long nPlay = 0;
    unsigned long nWrite = 0;
    if (pStream->pBuffer->GetCurrentPosition(&nPlay, &nWrite) < 0)
        return -1;
    unsigned int nWritten = pStream->nWritten;
    int nAhead = nWritten % pStream->nBufferSize - nPlay;
    if (nAhead <= 0)
        nAhead += pStream->nBufferSize;
    unsigned int nPlayed = nWritten - nAhead;
    if (nPlayed >= pStream->nSize)
        nPlayed = pStream->nSize;
    pStream->nPlayed = nPlayed;
    return nPlay;
}

// 0x00418140
int __stdcall SFileDdaGetPos(void* hFile, unsigned int* pnPlayed, unsigned int* pnSize)
{
    int bResult = 0;
    unsigned int nSize = 0;
    unsigned int nPlayed = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (sub_00415950_GetFileRec(hFile, &pRec))
    {
        D2StormStreamStrc* pStream;
        for (pStream = gDdaList_00708384.Head(); pStream; pStream = (D2StormStreamStrc*)pStream->tLink.Next())
        {
            if (pStream->pFile == pRec)
                break;
        }
        if (!pStream)
        {
            sub_0041C340_SetLastError(0x85100072);
        }
        else
        {
            nSize = pStream->nSize;
            const int nState = pStream->nState;
            if (nState == 4)
            {
                sub_0041C340_SetLastError(0x85100072);
            }
            else
            {
                bResult = 1;
                if (nState != 0 && nState != 1)
                {
                    sub_00415760_UpdatePlayed(pStream);
                    nPlayed = pStream->nPlayed;
                }
            }
        }
    }
    if (pnPlayed)
        *pnPlayed = nPlayed;
    if (pnSize)
        *pnSize = nSize;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return bResult;
}

static D2StormRequestStrc* __stdcall IssueRequest(unsigned int nPosition, void* pDest, unsigned int nDestSize, D2StormSoundBufferStrc* pBuffer, unsigned int nBufferOffset, D2StormStreamStrc* pStream, unsigned int nBytes, unsigned int nDelay, int nArg9, int nUser, int nArg11, int bSignal, void* pCallback, D2StormFileRecStrc* pFile)
{
    int bValid = (pDest || pBuffer) ? -1 : 0;
    if (!bValid)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormRequestStrc* pRequest = gRequestList_00708360.NewNode(2, 0, 0);
    pRequest->nUser = nUser;
    pRequest->pFile = pFile;
    pRequest->nPosition = nPosition;
    if (pFile->nKind == -1)
        nPosition = (nPosition >> 1) + *pFile->pBlockWords;
    pRequest->nFileOffset = nPosition;
    pRequest->nDueTime = GetTickCount() + nDelay;
    pRequest->nArg9 = nArg9;
    pRequest->pDest = (unsigned char*)pDest;
    pRequest->nDestSize = nDestSize;
    pRequest->pBuffer = pBuffer;
    pRequest->nBufferOffset = nBufferOffset;
    pRequest->pStream = pStream;
    pRequest->nBytes = nBytes;
    pRequest->bDelete = nArg11;
    pRequest->pCallback = (D2StormRequestCallbackStrc*)pCallback;
    pFile->nRequests += 1;
    if (pStream)
        pStream->nRefs += 1;
    LeaveCriticalSection(&gBasePathLock_00779068);
    if (bSignal)
        SetEvent(ghStormEvent_00779054);
    return pRequest;
}

void __cdecl sub_00419C00_PumpStreams()
{
    if (gbStreamsPaused_00779044)
        return;
    for (D2StormStreamStrc* pStream = DdaHead(); (int)pStream > 0; pStream = (D2StormStreamStrc*)pStream->tLink.m_next)
    {
        if (pStream->nState == 3 || (pStream->nState == 2 && pStream->pFile->nPosition >= pStream->nStart + pStream->nSize))
        {
            if (pStream->bRestart)
            {
                pStream->pFile->nPosition = pStream->nStart;
                pStream->nWritten = 0;
                pStream->nCounter = 0;
            }
            else
            {
                unsigned int nPlay = sub_00415760_UpdatePlayed(pStream);
                if (nPlay == -1)
                    continue;
                if (pStream->nPlayed >= pStream->nSize)
                {
                    pStream->pBuffer->Stop();
                    pStream->nState = 4;
                    continue;
                }
                if ((nPlay - pStream->nWritePos) % pStream->nBufferSize >= gnStreamChunk_00779038)
                {
                    unsigned int nCount = gnStreamChunk_00779038;
                    if (nCount >= pStream->nBufferSize - pStream->nWritePos)
                        nCount = pStream->nBufferSize - pStream->nWritePos;
                    void* pLocked = 0;
                    unsigned long nLocked = nCount;
                    if (pStream->pBuffer->Lock(pStream->nWritePos, nCount, &pLocked, &nLocked, 0, 0, 0) >= 0)
                    {
                        SMemFill(pLocked, nLocked, pStream->nFill);
                        pStream->pBuffer->Unlock(pLocked, nLocked, 0, 0);
                        pStream->nWritten += nLocked;
                        pStream->nCounter += nLocked;
                        pStream->nWritePos += nLocked;
                        if (pStream->nWritePos >= pStream->nBufferSize)
                            pStream->nWritePos -= pStream->nBufferSize;
                    }
                }
                pStream->nState = 3;
            }
        }
        if (pStream->nState == 2)
        {
            unsigned int nPlay = sub_00415760_UpdatePlayed(pStream);
            if (nPlay == -1)
                continue;
            if ((nPlay - pStream->nWritePos) % pStream->nBufferSize < gnStreamChunk_00779038)
                continue;
            unsigned int nCount = pStream->nBufferSize - pStream->nWritePos;
            if (gnStreamChunk_00779038 < nCount)
                nCount = gnStreamChunk_00779038;
            unsigned int nLeft = pStream->nSize + pStream->nStart - pStream->pFile->nPosition;
            if (nCount >= nLeft)
                nCount = nLeft;
            if (gbAlignReads_007790A4)
            {
                unsigned int nOver = (pStream->pFile->pArchive->nBlockSize - 1) & (pStream->pFile->nPosition + nCount);
                if (nOver && nOver < nCount)
                    nCount -= nOver;
            }
            IssueRequest(pStream->pFile->nPosition, 0, 0, pStream->pBuffer, pStream->nWritePos, pStream, nCount, 0, 0, 0, 1, 0, 0, pStream->pFile);
            pStream->pFile->nPosition += nCount;
            pStream->nWritePos += gnStreamChunk_00779038;
            if (pStream->nWritePos >= pStream->nBufferSize)
                pStream->nWritePos -= pStream->nBufferSize;
        }
        else if (pStream->nState == 0)
        {
            unsigned int nTotal = pStream->nSize - pStream->nOffset;
            if (pStream->nBufferSize < nTotal)
                nTotal = pStream->nBufferSize;
            unsigned int nDone = 0;
            pStream->pFile->nPosition = pStream->nStart + pStream->nOffset;
            unsigned int nIndex = 0;
            if (gbAlignReads_007790A4)
            {
                nDone = gnStreamChunk_00779038 < nTotal ? gnStreamChunk_00779038 : nTotal;
                unsigned int nOver = (pStream->pFile->pArchive->nBlockSize - 1) & (pStream->pFile->nPosition + nDone);
                if (nOver && nOver < nDone)
                    nDone -= nOver;
                IssueRequest(pStream->pFile->nPosition, 0, 0, pStream->pBuffer, 0, pStream, nDone, 0, 0, 0, 1, 0, 0, pStream->pFile);
                pStream->pFile->nPosition += nDone;
                nIndex = 1;
            }
            for (; nDone < nTotal; nDone += gnStreamChunk_00779038)
            {
                unsigned int nCount = gnStreamChunk_00779038;
                if (nCount >= nTotal - nDone)
                    nCount = nTotal - nDone;
                IssueRequest(pStream->pFile->nPosition, 0, 0, pStream->pBuffer, nDone, pStream, nCount, nIndex, 0, 0, 1, 0, 0, pStream->pFile);
                ++nIndex;
                pStream->pFile->nPosition += nCount;
            }
            pStream->nState = 1;
            pStream->nWritePos = nDone % pStream->nBufferSize;
        }
    }
}
