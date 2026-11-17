#include "Storm.h"

struct D2StormFileRecStrc;
struct D2CriticalSectionStrc;
struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct D2StormFixedListStrc;
struct D2StormAudioStreamStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

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
    D2StormLinkStrc f_0;
    char unk0x08[0x13C];
    int nRefCount;
    ~D2StormFileRecStrc();                                                                                  // 0x00419070
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2StormFixedListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2StormArchiveRecStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x140];
    int nRefCount;
    void* hParentFile;
    D2StormArchiveRecStrc* pParent;

    ~D2StormArchiveRecStrc();                                                                               // 0x00418A50
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

extern D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068
extern D2StormNodeListStrc gStormList_00708354; // 0x00708354
extern D2StormFixedListStrc gFileList_0070836C; // 0x0070836C

struct D2StormAudioStreamStrc {
    char prefix[0x4C];
    int nRefCount;
    ~D2StormAudioStreamStrc();  // 0x004199A0
    static void operator delete(void* memory) {
        if (memory) SMemFree(memory, "delete", -1, 0);
    }
};

// 0x00419760
static void sub_00419760_ReleaseFile(D2StormFileRecStrc* pFile)
{
    if (pFile && !--pFile->nRefCount)
        delete pFile;
}

void __fastcall sub_M126_Emit_00419760(int a, D2StormFileRecStrc* pFile, int nUnused)
{
    sub_00419760_ReleaseFile(pFile);
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

// 0x004198D0
int __stdcall sub_004198D0(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    (pRec ? &pRec->f_0 : &gFileList_0070836C.m_terminator)->Unlink();
    if (pRec && !--pRec->nRefCount)
        delete pRec;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00419A80
int __stdcall SFileCloseArchive(void* hArchive)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormArchiveRecStrc* pRec;
    if (!sub_00415930_GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    D2StormArchiveRecStrc* pHandle = (D2StormArchiveRecStrc*)hArchive;
    if (pHandle)
    {
        if (pHandle->hParentFile)
        {
            D2StormFileRecStrc* pFile;
            if (sub_00415950_GetFileRec(pRec->hParentFile, &pFile))
                sub_004198D0(pRec->hParentFile);
        }
        else if (pHandle->pParent)
        {
            D2StormArchiveRecStrc* pParent = pRec->pParent;
            if (pParent && !--pParent->nRefCount)
                delete pParent;
        }
    }
    (pRec ? &pRec->f_0 : &gStormList_00708354.m_terminator)->Unlink();
    if (pRec && !--pRec->nRefCount)
        delete pRec;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00419BD0
static __forceinline void sub_00419BD0(D2StormAudioStreamStrc* stream)
{
    if (stream && --stream->nRefCount == 0)
        delete stream;
}

void __stdcall emit_release_00419BD0(D2StormAudioStreamStrc* stream) { sub_00419BD0(stream); }
