typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
void __fastcall sub_0040A4C0_AsyncDataFinish(AsyncData* pAsyncData);                                        // 0x0040A4C0

// 0x0040A7F0
int __fastcall FOG_AsyncDataTestLoaded(AsyncData* pAsyncData)
{
    if (!pAsyncData)
    {
        return 0;
    }
    D2_ASSERT((pAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 452);
    if (!(pAsyncData->nFlags & 1))
    {
        if (!WaitForSingleObject(pAsyncData->pEventSlot->hEvent, 0))
        {
            sub_0040A4C0_AsyncDataFinish(pAsyncData);
        }
    }
    return pAsyncData->nFlags & 1;
}
