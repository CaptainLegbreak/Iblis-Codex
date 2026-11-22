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

// 0x0041A8F0
static void MarkRequestPriority(int nValue, void* hWnd)
{
    if (!hWnd)
        return;
    EnterCriticalSection(&gBasePathLock_00779068);
    for (D2StormWindowNodeStrc* p = (D2StormWindowNodeStrc*)gRequestList_00708360.Head(); (int)p > 0; p = p->pNext)
    {
        if (p->hWnd == hWnd)
            p->nValue = nValue;
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
}

// 0x0041AA80
void __stdcall SFilePrioritizeRequest(void* hWnd, int nValue)
{
    VALIDATEBEGIN;
    VALIDATE(hWnd);
    VALIDATEENDVOID;
    if (nValid)
    {
        MarkRequestPriority(nValue > 0, hWnd);
        if (nValue >= 1)
            SetEvent(ghStormEvent_00779054);
    }
}
