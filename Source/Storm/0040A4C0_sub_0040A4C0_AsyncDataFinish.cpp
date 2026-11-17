typedef unsigned int size_t;

struct D2OverlappedStrc
{
    unsigned long Internal;
    unsigned long InternalHigh;
    unsigned long Offset;
    unsigned long OffsetHigh;
    void* hEvent;
};

struct AsyncDataLoadFileCallback
{
    unsigned long (__stdcall* callback)(void* pFileData, size_t nDataLength, AsyncDataLoadFileCallback* pCallbackData);
    unsigned long userData[4];
    void* pData;
    size_t nFileSize;
};

struct AsyncDataEventSlot;

struct AsyncData
{
    void* hFile;
    void* pMemPool;
    D2OverlappedStrc tOverlapped;
    AsyncDataLoadFileCallback pAsyncOpDesc;
    AsyncDataEventSlot* pEventSlot;
    void* pBuffer;
    unsigned int nFileSize;
    unsigned int nPriority;
    unsigned int nFlags;
    unsigned int nPreviousPriority;
    AsyncData* pNextPostponedPriorityChange;
};

struct AsyncDataEventSlot
{
    void* hEvent;
    unsigned long bSlotAvailable;
    AsyncData* pAsyncOp;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) int __stdcall ResetEvent(void* hEvent);                                    // 0x006CC22C
void __fastcall sub_004068F0(void* hFile);                                                                // 0x004068F0
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x0040A4C0
void __fastcall sub_0040A4C0_AsyncDataFinish(AsyncData* pAsyncData)
{
    if (pAsyncData->nFlags & 1)
    {
        return;
    }
    AsyncDataEventSlot* pSlot = pAsyncData->pEventSlot;
    if (pSlot)
    {
        ResetEvent(pSlot->hEvent);
        pSlot->bSlotAvailable = 1;
        pSlot->pAsyncOp = 0;
        pAsyncData->pEventSlot = 0;
    }
    if (pAsyncData->hFile)
    {
        sub_004068F0(pAsyncData->hFile);
        pAsyncData->hFile = 0;
    }
    pAsyncData->nFlags |= 1;
    if (pAsyncData->pAsyncOpDesc.pData)
    {
        FOG_FreeServerMemory(pAsyncData->pMemPool, pAsyncData->pBuffer, ".\\Src\\AsyncData.cpp", 215, 0);
        pAsyncData->pBuffer = pAsyncData->pAsyncOpDesc.pData;
        pAsyncData->nFileSize = pAsyncData->pAsyncOpDesc.nFileSize;
        memset(&pAsyncData->pAsyncOpDesc, 0, sizeof(pAsyncData->pAsyncOpDesc));
    }
}
