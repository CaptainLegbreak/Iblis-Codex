#include "Storm.h"
#include "D2GameTypes.h"


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

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
        char* pNext = m_next;
        if ((int)pNext < 0)
            return (D2StormStreamLinkStrc*)~(unsigned int)pNext;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormStreamLinkStrc*)(pNext + nLinkOffset);
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

struct AUDIOSTREAM;

struct AUDIOSTREAM
{
    D2StormStreamLinkStrc tLink;
    void* pFileRec;
    char unk0x0C[0x30];
    void* pBuffer;
    int nUnk0x40;
    int bBufferOwned;
    int nUnk0x48;
    int nRefCount;

    ~AUDIOSTREAM();                                                                              // 0x004199A0
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, gszDelete_006CC824, -1, 0);
    }
};

struct REQUEST;

struct D2StormListStrc
{
    int m_linkoffset;
    void* m_prevlink;
    char* m_next;
    char* Head()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
};

struct D2StormDdaListStrc
{
    int m_linkoffset;
    D2StormStreamLinkStrc m_terminator;
    D2StormStreamLinkStrc* Link(AUDIOSTREAM* pNode)
    {
        return pNode ? &pNode->tLink : &m_terminator;
    }
    void sub_006C4290(AUDIOSTREAM* pNode)
    {
        Link(pNode)->Unlink();
    }
};

#define WAIT_TIMEOUT 0x102

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern D2StormListStrc gRequestList_00708360;                                                               // 0x00708360
extern D2StormDdaListStrc gDdaList_00708384;                                                                // 0x00708384
extern void* gpDirectSound_00778F20;                                                                        // 0x00778F20
extern REQUEST* gpCurrentRequest_0077902C;                                                       // 0x0077902C
extern void* ghStormThread_00779034;                                                                        // 0x00779034
extern int gbStreamsPaused_00779044;                                                                        // 0x00779044

// 0x00419F30
int __cdecl SFileDdaDestroy()
{
    EnterCriticalSection(&gBasePathLock_00779068);
    gbStreamsPaused_00779044 = 1;
    LeaveCriticalSection(&gBasePathLock_00779068);

    while (ghStormThread_00779034 && (gpCurrentRequest_0077902C || gRequestList_00708360.Head()))
    {
        if (WaitForSingleObject(ghStormThread_00779034, 10) != WAIT_TIMEOUT)
            break;
    }

    EnterCriticalSection(&gBasePathLock_00779068);
    AUDIOSTREAM* pStream = (AUDIOSTREAM*)gDdaList_00708384.m_terminator.m_next;
    if ((int)pStream > 0)
    {
        do
        {
            AUDIOSTREAM* pNext = (AUDIOSTREAM*)pStream->tLink.Next();
            gDdaList_00708384.sub_006C4290(pStream);
            if (!--pStream->nRefCount)
                delete pStream;
            pStream = pNext;
        } while (pStream);
    }
    gpDirectSound_00778F20 = 0;
    gbStreamsPaused_00779044 = 0;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}
