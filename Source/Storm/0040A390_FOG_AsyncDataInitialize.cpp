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

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __stdcall sub_004164A0_SetValue(int nValue);                                                           // 0x004164A0
void __stdcall sub_00416570_SetPowerOfTwoValue(int nValue);                                                 // 0x00416570
int __stdcall sub_0041A930_CancelRead(void* pBuffer);                                                       // 0x0041A930
void __fastcall sub_0040A4C0_AsyncDataFinish(AsyncData* pAsyncData);                                        // 0x0040A4C0
int __fastcall FOG_AsyncDataTestLoaded(AsyncData* pAsyncData);                                              // 0x0040A7F0
void __fastcall FOG_AsyncDataWaitAndGetBuffer(AsyncData* pAsyncData);                                       // 0x0040A960

extern AsyncData* gpAsyncDataPostponed_0075AF90;                                                            // 0x0075AF90

static int s_bAsyncDataEnabled_0075AF94;                                                                    // 0x0075AF94
static unsigned int s_nAsyncEventSlots_0075AF98;                                                            // 0x0075AF98
static AsyncDataEventSlot* s_pAsyncEventSlots_0075AF9C;                                                     // 0x0075AF9C

// 0x0040A390
void __fastcall FOG_AsyncDataInitialize(int bEnable, int nUnused)
{
    D2_ASSERT(!s_bAsyncDataEnabled_0075AF94, 123);
    sub_004164A0_SetValue(0x40000);
    sub_00416570_SetPowerOfTwoValue(0x4000);
    if (bEnable)
    {
        s_pAsyncEventSlots_0075AF9C = (AsyncDataEventSlot*)FOG_Alloc(0x3000, ".\\Src\\AsyncData.cpp", 136, 0);
        D2_ASSERT(s_pAsyncEventSlots_0075AF9C, 137);
        for (int i = 0; i < 0x100; i++)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[i];
            pSlot->hEvent = CreateEventA(0, 1, 0, 0);
            pSlot->bSlotAvailable = 1;
        }
        s_nAsyncEventSlots_0075AF98 = 0x100;
        s_bAsyncDataEnabled_0075AF94 = 1;
    }
}

// 0x0040A440
void __cdecl FOG_AsyncDataDestroy()
{
    if (s_pAsyncEventSlots_0075AF9C)
    {
        for (unsigned int i = 0; i < s_nAsyncEventSlots_0075AF98; i++)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[i];
            if (pSlot && pSlot->hEvent)
            {
                CloseHandle(pSlot->hEvent);
                pSlot->hEvent = 0;
            }
        }
        FOG_Free(s_pAsyncEventSlots_0075AF9C, ".\\Src\\AsyncData.cpp", 174, 0);
        s_pAsyncEventSlots_0075AF9C = 0;
        s_nAsyncEventSlots_0075AF98 = 0;
    }
    s_bAsyncDataEnabled_0075AF94 = 0;
}

// 0x0040A550
AsyncDataEventSlot* __cdecl sub_0040A550_AsyncDataGetEventSlot()
{
    if (s_bAsyncDataEnabled_0075AF94)
    {
        for (unsigned int i = 0; i < s_nAsyncEventSlots_0075AF98; i++)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[i];
            if (pSlot->bSlotAvailable)
            {
                pSlot->bSlotAvailable = 0;
                return pSlot;
            }
        }
        for (unsigned int i = 0; i < s_nAsyncEventSlots_0075AF98; i++)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[i];
            if (!WaitForSingleObject(pSlot->hEvent, 0))
            {
                sub_0040A4C0_AsyncDataFinish(pSlot->pAsyncOp);
                pSlot->bSlotAvailable = 0;
                return pSlot;
            }
        }
        if (s_nAsyncEventSlots_0075AF98 < 0x400)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[s_nAsyncEventSlots_0075AF98++];
            pSlot->hEvent = CreateEventA(0, 1, 0, 0);
            pSlot->bSlotAvailable = 0;
            return pSlot;
        }
    }
    return 0;
}

// 0x0040A9E0
void* __fastcall FOG_AsyncDataGetBuffer(AsyncData* pAsyncData)
{
    D2_ASSERT(pAsyncData, 607);
    D2_ASSERT((pAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 608);
    if (!(pAsyncData->nFlags & 1))
    {
        FOG_AsyncDataWaitAndGetBuffer(pAsyncData);
    }
    D2_ASSERT(pAsyncData->nFlags & 1, 614);
    return pAsyncData->pBuffer;
}

// 0x0040AA40
unsigned int __fastcall FOG_AsyncDataGetBufferSize(AsyncData* pAsyncData)
{
    D2_ASSERT(pAsyncData, 625);
    D2_ASSERT((pAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 626);
    return pAsyncData->nFileSize;
}

// 0x0040AB00
void __fastcall FOG_AsyncDataFree(AsyncData* pAsyncData)
{
    D2_ASSERT(pAsyncData, 656);
    D2_ASSERT((pAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 657);
    if (pAsyncData->nFlags & 8)
    {
        for (AsyncData** ppLink = &gpAsyncDataPostponed_0075AF90; ppLink; ppLink = &(*ppLink)->pNextPostponedPriorityChange)
        {
            if (*ppLink == pAsyncData)
            {
                *ppLink = pAsyncData->pNextPostponedPriorityChange;
                break;
            }
        }
    }
    if (!FOG_AsyncDataTestLoaded(pAsyncData))
    {
        sub_0041A930_CancelRead(pAsyncData->pBuffer);
        WaitForSingleObject(pAsyncData->pEventSlot->hEvent, (unsigned long)-1);
        sub_0040A4C0_AsyncDataFinish(pAsyncData);
    }
    if (pAsyncData->nFlags & 2)
    {
        D2_ASSERT(pAsyncData->pBuffer, 707);
        FOG_FreeServerMemory(pAsyncData->pMemPool, pAsyncData->pBuffer, ".\\Src\\AsyncData.cpp", 710, 0);
        pAsyncData->nFlags &= 0xF;
        pAsyncData->pBuffer = 0;
    }
    FOG_FreeServerMemory(pAsyncData->pMemPool, pAsyncData, ".\\Src\\AsyncData.cpp", 717, 0);
}
