#include "Storm.h"
#include "D2GameTypes.h"


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith);                    // 0x0041D2C0

struct D2StormArchiveRecStrc
{

    char pad00[0x124];
    unsigned int nBlockSize;
};

struct D2StormFileRecStrc
{

    char pad00[0x110];
    int hFile;
    D2StormArchiveRecStrc* f_114;
    unsigned int* pBlock;
    int unk0x11C;
    unsigned int nPosition;
    char pad124[0x20];
    int nRequests;
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

struct D2StormStreamStrc;

struct D2StormStreamLinkStrc
{
    D2StormStreamLinkStrc* m_prevlink;
    D2StormStreamStrc* m_next;

    D2StormStreamStrc* Next()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
};

struct D2StormStreamStrc
{
    D2StormStreamLinkStrc f_0;

    D2StormFileRecStrc* pFile;
    unsigned int f_C;
    int unk0x10;
    int bRestart;
    int nState;
    unsigned int nCounter;
    unsigned int nStart;
    unsigned int nSize;
    unsigned int nOffset;
    unsigned int nPlayed;
    unsigned int f_30;
    int f_34;
    int f_38;
    D2StormSoundBufferStrc* pBuffer;
    unsigned int nBufferSize;
    int unk0x44;
    unsigned char nFill;
    char pad49[3];
    int nRefs;
};

struct D2StormStreamListStrc
{
    int m_linkoffset;
    D2StormStreamLinkStrc m_terminator;

    D2StormStreamStrc* Head()
    {
        D2StormStreamStrc* pHead = m_terminator.Next();
        return pHead;
    }
};

struct D2StormRequestStrc
{
    D2StormRequestLinkStrc f_0;

    int nUser;
    D2StormFileRecStrc* pFile;
    unsigned int nPosition;
    unsigned int nFileOffset;
    unsigned int nDueTime;
    int nArg9;
    void* pDest;
    unsigned int f_24;
    D2StormSoundBufferStrc* pBuffer;
    unsigned int f_2C;
    D2StormStreamStrc* pStream;
    unsigned int nBytes;
    int nArg11;
    unsigned int nRead;
    void* pCallback;

    D2StormRequestStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
};

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

struct D2StormRequestListStrc
{
    int m_linkoffset;
    D2StormRequestLinkStrc m_terminator;

    D2StormRequestLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormRequestLinkStrc*)pNode : &m_terminator;
    }
    // build: context D2StormRequestListStrc::LinkNode
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
    {
        D2StormRequestLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormRequestLinkStrc* pExistingLink = Link(pExistingNode);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            D2StormRequestLinkStrc* pPrevLink = pExistingLink->m_prevlink;
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
static int gbStreamsPaused_00779044;                                                                        // 0x00779044
static unsigned int gnStreamChunk_00779038;                                                                 // 0x00779038

// 0x00415950
static int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
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
    unsigned int nWritten = pStream->f_30;
    int nAhead = nWritten % pStream->nBufferSize - nPlay;
    if (nAhead <= 0)
        nAhead += pStream->nBufferSize;
    unsigned int nPlayed = nWritten - nAhead;
    if (nPlayed >= pStream->nSize)
        nPlayed = pStream->nSize;
    pStream->nPlayed = nPlayed;
    return nPlay;
}

int __stdcall sub_00418140_DdaGetPosition(void* hFile, unsigned int* pnPlayed, unsigned int* pnSize); // 0x00418140

// 0x00419790
static D2StormRequestStrc* __stdcall sub_00419790_QueueRequest(D2StormFileRecStrc* pFile, unsigned int nPosition, void* pDest, unsigned int nDestSize, D2StormSoundBufferStrc* pBuffer, unsigned int nBufferOffset, D2StormStreamStrc* pStream, unsigned int nBytes, unsigned int nDelay, int nArg9, int nUser, int nArg11, int bSignal, void* pCallback)
{
    int nValid = -1;
    nValid &= (pDest || pBuffer) ? -1 : 0;
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormRequestStrc* pRequest = gRequestList_00708360.NewNode(2, 0, 0);
    pRequest->nUser = nUser;
    pRequest->pFile = pFile;
    pRequest->nPosition = nPosition;
    if (pFile->hFile == -1)
        nPosition = (nPosition >> 1) + *pFile->pBlock;
    pRequest->nFileOffset = nPosition;
    pRequest->nDueTime = GetTickCount() + nDelay;
    pRequest->nArg9 = nArg9;
    pRequest->pDest = pDest;
    pRequest->f_24 = nDestSize;
    pRequest->pBuffer = pBuffer;
    pRequest->f_2C = nBufferOffset;
    pRequest->pStream = pStream;
    pRequest->nBytes = nBytes;
    pRequest->nArg11 = nArg11;
    pRequest->pCallback = pCallback;
    pFile->nRequests += 1;
    if (pStream)
        pStream->nRefs += 1;
    LeaveCriticalSection(&gBasePathLock_00779068);
    if (bSignal)
        SetEvent(ghStormEvent_00779054);
    return pRequest;
}

// 0x00419C00
void __cdecl sub_00419C00_PumpStreams()
{
    if (gbStreamsPaused_00779044)
        return;
    for (D2StormStreamStrc* pStream = gDdaList_00708384.Head(); (int)pStream > 0; pStream = pStream->f_0.m_next)
    {
        if (pStream->nState == 3 || (pStream->nState == 2 && pStream->pFile->nPosition >= pStream->nStart + pStream->nSize))
        {
            if (pStream->bRestart)
            {
                pStream->pFile->nPosition = pStream->nStart;
                pStream->f_30 = 0;
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
                if ((nPlay - pStream->f_C) % pStream->nBufferSize >= gnStreamChunk_00779038)
                {
                    unsigned int nCount;
                    if (gnStreamChunk_00779038 >= pStream->nBufferSize - pStream->f_C)
                        nCount = pStream->nBufferSize - pStream->f_C;
                    else
                        nCount = gnStreamChunk_00779038;
                    void* pLocked = 0;
                    unsigned long nLocked = nCount;
                    if (pStream->pBuffer->Lock(pStream->f_C, nCount, &pLocked, &nLocked, 0, 0, 0) >= 0)
                    {
                        SMemFill(pLocked, nLocked, pStream->nFill);
                        pStream->pBuffer->Unlock(pLocked, nLocked, 0, 0);
                        pStream->f_30 += nLocked;
                        pStream->nCounter += nLocked;
                        pStream->f_C += nLocked;
                        if (pStream->f_C >= pStream->nBufferSize)
                            pStream->f_C -= pStream->nBufferSize;
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
            if ((nPlay - pStream->f_C) % pStream->nBufferSize < gnStreamChunk_00779038)
                continue;
            unsigned int nCount = pStream->nBufferSize - pStream->f_C;
            if (gnStreamChunk_00779038 < nCount)
                nCount = gnStreamChunk_00779038;
            unsigned int nLeft = pStream->nSize + pStream->nStart - pStream->pFile->nPosition;
            if (nCount >= nLeft)
                nCount = nLeft;
            if (gbAlignReads_007790A4)
            {
                unsigned int nOver = (pStream->pFile->f_114->nBlockSize - 1) & (pStream->pFile->nPosition + nCount);
                if (nOver && nOver < nCount)
                    nCount -= nOver;
            }
            sub_00419790_QueueRequest(pStream->pFile, pStream->pFile->nPosition, 0, 0, pStream->pBuffer, pStream->f_C, pStream, nCount, 0, 0, 0, 1, 0, 0);
            pStream->pFile->nPosition += nCount;
            pStream->f_C += gnStreamChunk_00779038;
            if (pStream->f_C >= pStream->nBufferSize)
                pStream->f_C -= pStream->nBufferSize;
        }
        else if (pStream->nState == 0)
        {
            unsigned int nDone = 0;
            unsigned int nTotal;
            if (pStream->nBufferSize < pStream->nSize - pStream->nOffset)
                nTotal = pStream->nBufferSize;
            else
                nTotal = pStream->nSize - pStream->nOffset;
            pStream->pFile->nPosition = pStream->nStart + pStream->nOffset;
            unsigned int nIndex = 0;
            if (gbAlignReads_007790A4)
            {
                nDone = gnStreamChunk_00779038 < nTotal ? gnStreamChunk_00779038 : nTotal;
                unsigned int nOver = (pStream->pFile->f_114->nBlockSize - 1) & (pStream->pFile->nPosition + nDone);
                if (nOver && nOver < nDone)
                    nDone -= nOver;
                sub_00419790_QueueRequest(pStream->pFile, pStream->pFile->nPosition, 0, 0, pStream->pBuffer, 0, pStream, nDone, 0, 0, 0, 1, 0, 0);
                pStream->pFile->nPosition += nDone;
                nIndex = 1;
            }
            for (; nDone < nTotal; nDone += gnStreamChunk_00779038)
            {
                unsigned int nCount = gnStreamChunk_00779038;
                if (nCount >= nTotal - nDone)
                    nCount = nTotal - nDone;
                sub_00419790_QueueRequest(pStream->pFile, pStream->pFile->nPosition, 0, 0, pStream->pBuffer, nDone, pStream, nCount, nIndex, 0, 0, 1, 0, 0);
                ++nIndex;
                pStream->pFile->nPosition += nCount;
            }
            pStream->nState = 1;
            pStream->f_C = nDone % pStream->nBufferSize;
        }
    }
}

// build: context ?Next@D2StormStreamLinkStrc@@QAEPAUD2StormStreamStrc@@XZ
// build: context ?Head@D2StormStreamListStrc@@QAEPAUD2StormStreamStrc@@XZ
// build: context ?NextLink@D2StormRequestLinkStrc@@QAEPAU1@H@Z
// build: context ?Unlink@D2StormRequestLinkStrc@@QAEXXZ
// build: context ??0D2StormRequestStrc@@QAE@XZ
// build: context ??2@YAPAXIPAX@Z
// build: context ?Link@D2StormRequestListStrc@@QAEPAUD2StormRequestLinkStrc@@PAD@Z
// build: context ?NewNode@D2StormRequestListStrc@@QAEPAUD2StormRequestStrc@@III@Z
