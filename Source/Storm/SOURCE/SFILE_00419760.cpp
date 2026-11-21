#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormLink.h"

struct D2CriticalSectionStrc;
struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct D2StormFixedListStrc;
struct D2StormAudioStreamStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

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
static void RemoveFileRef(D2StormFileRecStrc* pFile)
{
    if (pFile && !--pFile->nRefCount)
        delete pFile;
}

void __fastcall sub_M126_Emit_00419760(int a, D2StormFileRecStrc* pFile, int nUnused)
{
    RemoveFileRef(pFile);
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
int __stdcall SFileCloseFile(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    (pRec ? &pRec->tLink : &gFileList_0070836C.m_terminator)->Unlink();
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
                SFileCloseFile(pRec->hParentFile);
        }
        else if (pHandle->pParent)
        {
            D2StormArchiveRecStrc* pParent = pRec->pParent;
            if (pParent && !--pParent->nRefCount)
                delete pParent;
        }
    }
    (pRec ? &pRec->tLink : &gStormList_00708354.m_terminator)->Unlink();
    if (pRec && !--pRec->nRefCount)
        delete pRec;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00419BD0
static inline void RemoveStreamRef(D2StormAudioStreamStrc* stream)
{
    if (stream && --stream->nRefCount == 0)
        delete stream;
}

void __stdcall emit_release_00419BD0(D2StormAudioStreamStrc* stream) { RemoveStreamRef(stream); }
