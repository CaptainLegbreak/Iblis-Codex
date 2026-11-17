struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
int __stdcall sub_0041A300_CancelRequests(void* pBuffer, void* pOther);

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

struct D2StormFileRecStrc
{
    char unk0x00[0x134];
    int nUnk0x134;
    char unk0x138[0x20];
};

struct D2StormSoundBufferStrc;

struct D2StormRequestStrc
{
    char unk0x00[0x28];
    D2StormSoundBufferStrc* pBuffer;
};

struct D2StormAudioStreamStrc;
#define STREAM_NEXT(l) ((D2StormAudioStreamStrc*)((((int)(l)->m_next <= 0) - 1) & (int)(l)->m_next))

struct D2StormAudioStreamStrc
{
    D2StormStreamLinkStrc f_0;
    D2StormFileRecStrc* pFileRec;
    char unk0x0C[0x30];
    D2StormSoundBufferStrc* pBuffer;
    int nUnk0x40;
    int bBufferOwned;
    int nUnk0x48;
    int nRefCount;

    ~D2StormAudioStreamStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern D2StormAudioStreamStrc* gpDdaHead_0070838C;                                                          // 0x0070838C
extern D2StormRequestStrc* gpCurrentRequest_0077902C;                                                       // 0x0077902C

static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}

// build: symbol ??1D2StormAudioStreamStrc@@QAE@XZ 0x004199A0
// 0x0041A990
int __stdcall sub_0041A990_DdaClose(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    if (!sub_00415950_GetFileRec(hFile, (D2StormFileRecStrc**)&hFile))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    D2StormAudioStreamStrc* pStream = gpDdaHead_0070838C;
    if ((int)pStream > 0)
    {
        do
        {
            D2StormAudioStreamStrc* pNext = STREAM_NEXT(&pStream->f_0);
            if (pStream->pFileRec == (D2StormFileRecStrc*)hFile)
            {
                if (gpCurrentRequest_0077902C && gpCurrentRequest_0077902C->pBuffer && gpCurrentRequest_0077902C->pBuffer == pStream->pBuffer)
                    gpCurrentRequest_0077902C->pBuffer = 0;
                sub_0041A300_CancelRequests(0, pStream->pBuffer);
                pStream->f_0.Unlink();
                if (!--pStream->nRefCount)
                    delete pStream;
            }
            pStream = pNext;
        } while (pStream);
    }
    ((D2StormFileRecStrc*)hFile)->nUnk0x134 = 0;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

#include "gen/data/Source/Storm/0041A990_sub_0041A990_DdaClose.inc"
