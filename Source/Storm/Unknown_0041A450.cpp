#include "Storm.h"
#include "D2GameTypes.h"
#define STREAM_NEXT(l) ((AUDIOSTREAM*)((((int)(l)->m_next <= 0) - 1) & (int)(l)->m_next))

struct D2StormSoundBufferStrc;
struct AUDIOSTREAM;
struct D2StormLink0041A450Strc;
struct D2StormArchive0041A450Strc;
struct D2StormFile0041A450Strc;
struct D2StormRequest0041A450Strc;
struct D2StormListStrc;
struct D2CriticalSectionStrc;
struct D2StormWindowNodeStrc;
struct D2StormStreamLinkStrc;
struct FILEREC;
struct REQUEST;

struct D2StormLink0041A450Strc
{
    D2StormLink0041A450Strc* m_prevlink;
    char* m_next;
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    char* Prev()
    {
        return m_prevlink->m_prevlink->Next();
    }
};

struct D2StormArchive0041A450Strc
{
    unsigned char unk_000[0x124];
    unsigned int nBaseOffset;
};

struct D2StormFile0041A450Strc
{
    unsigned char unk_000[0x114];
    D2StormArchive0041A450Strc* f_114;
};

struct D2StormRequest0041A450Strc
{
    D2StormLink0041A450Strc f_0;
    void* hEvent;
    D2StormFile0041A450Strc* pFile;
    unsigned int nPosition;
    unsigned int nFileOffset;
    unsigned int nDueTime;
    int bClampDue;
    unsigned char* pDest;
    unsigned int f_24;
    void* pBuffer;
    unsigned int f_2C;
    void* pStream;
};

struct D2StormListStrc
{
    int m_linkoffset;
    void* m_prevlink;
    char* m_next;
    char* Head()
    {
        char* pHead = (int)m_next <= 0 ? 0 : m_next;
        return pHead;
    }
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern D2StormListStrc gRequestList_00708360; // 0x00708360
void __cdecl sub_0041A880_StartThread(); // 0x0041A880


struct D2StormWindowNodeStrc
{
    void* pPrevLink;
    D2StormWindowNodeStrc* pNext;
    int unk0x08[5];
    int nValue;
    int unk0x20;
    void* hWnd;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
extern D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068
extern void* ghStormEvent_00779054; // 0x00779054
int __stdcall CancelRequest(void* pBuffer, void* pOther); // 0x0041A300
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2StormStreamLinkStrc
{
    D2StormStreamLinkStrc* m_prevlink;
    char* m_next;

    ~D2StormStreamLinkStrc()
    {
        Unlink();
    }
    D2StormStreamLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormStreamLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormStreamLinkStrc*)(m_next + nLinkOffset);
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

struct FILEREC
{
    char unk0x00[0x134];
    int nUnk0x134;
    char unk0x138[0x20];
};

struct REQUEST
{
    char unk0x00[0x28];
    D2StormSoundBufferStrc* pBuffer;
};

struct AUDIOSTREAM
{
    D2StormStreamLinkStrc f_0;
    FILEREC* pFileRec;
    char unk0x0C[0x30];
    D2StormSoundBufferStrc* pBuffer;
    int soundbuffersize;
    int bBufferOwned;
    int nUnk0x48;
    int nRefCount;

    ~AUDIOSTREAM();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

extern AUDIOSTREAM* gpDdaHead_0070838C; // 0x0070838C
extern REQUEST* gpCurrentRequest_0077902C; // 0x0077902C
extern D2StormWindowNodeStrc* gpWindowNodeHead_00708368;

// 0x0041A450
void __stdcall CheckRequests(D2StormArchive0041A450Strc* pLastArchive, unsigned int nLastOffset, D2StormRequest0041A450Strc** ppDue, D2StormRequest0041A450Strc** ppNear, int* pnDistance)
{
    *ppDue = 0;
    *ppNear = 0;
    *pnDistance = 0x7FFFFFFF;
    unsigned int nBest = 0xFFFFFFFF;
    unsigned long nNow = GetTickCount();
    for (D2StormRequest0041A450Strc* p = (D2StormRequest0041A450Strc*)gRequestList_00708360.Head(); (int)p > 0; p = (D2StormRequest0041A450Strc*)p->f_0.m_next)
    {
        if (p->f_24)
        {
            if (p->f_0.Prev() && p->f_24 == ((D2StormRequest0041A450Strc*)p->f_0.Prev())->f_24)
                continue;
        }

        unsigned int nDistance = 0;
        if (gnValue_00708350 && !p->pStream)
        {
            D2StormArchive0041A450Strc* pArchive = p->pFile->f_114;
            unsigned int nSkip = 0;
            if (pArchive && nLastOffset > pArchive->nBaseOffset)
                nSkip = nLastOffset - pArchive->nBaseOffset;
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
        if (p->bClampDue && nTime >= 1000)
            nTime = 1000;
        if (nTime < *pnDistance)
        {
            *pnDistance = nTime;
            *ppNear = p;
        }
    }
}

static void* ghStormThread_00779034; // 0x00779034

static unsigned long gdwStormThreadId_00779040; // 0x00779040

// 0x0041A8D0
void __fastcall sub_0041A8D0_GetThread(unsigned long* pdwThreadId, void** phThread)
{
    sub_0041A880_StartThread();
    *pdwThreadId = gdwStormThreadId_00779040;
    *phThread = ghStormThread_00779034;
}


// 0x0041A930
void __stdcall sub_0041A930_CancelRead(void* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEENDVOID;

    if (nValid)
        CancelRequest(pBuffer, 0);
}

// 0x0041A960
int __stdcall sub_0041A960_CancelReadResult(void* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEEND;

    if (nValid)
        return CancelRequest(pBuffer, 0);
    return 0;
}

static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, FILEREC** ppRec)
{
    *ppRec = (FILEREC*)hFile;
    return 1;
}

// build: symbol ??1AUDIOSTREAM@@QAE@XZ 0x004199A0
// 0x0041A990
int __stdcall sub_0041A990_DdaClose(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    if (!sub_00415950_GetFileRec(hFile, (FILEREC**)&hFile))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    AUDIOSTREAM* pStream = gpDdaHead_0070838C;
    if ((int)pStream > 0)
    {
        do
        {
            AUDIOSTREAM* pNext = STREAM_NEXT(&pStream->f_0);
            if (pStream->pFileRec == (FILEREC*)hFile)
            {
                if (gpCurrentRequest_0077902C && gpCurrentRequest_0077902C->pBuffer && gpCurrentRequest_0077902C->pBuffer == pStream->pBuffer)
                    gpCurrentRequest_0077902C->pBuffer = 0;
                CancelRequest(0, pStream->pBuffer);
                pStream->f_0.Unlink();
                if (!--pStream->nRefCount)
                    delete pStream;
            }
            pStream = pNext;
        } while (pStream);
    }
    ((FILEREC*)hFile)->nUnk0x134 = 0;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

#include "gen/data/Source/Storm/Unknown_0041A450.inc"

