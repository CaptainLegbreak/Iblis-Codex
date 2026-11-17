struct D2LinkStrc
{
    D2LinkStrc* pPrev;
    D2LinkStrc* pNext;
};

struct D2TaskStrc
{
    int nTaskQ;
    int nType;
    D2LinkStrc pTaskBalanceLink;
    D2LinkStrc pTaskQueueLink;
};

struct D2CriticalSectionStrc
{
    char unk0x00[0x18];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern D2TaskStrc* gtTaskSlots_0088C708[32];                                                                // 0x0088C708
extern int gnNumberOfTasksCreated_0088C798;                                                                 // 0x0088C798
extern int gnGamesCount_0088C79C;                                                                           // 0x0088C79C
extern D2CriticalSectionStrc gtTaskQueuesCriticalSections_0088C7A8[32];                                     // 0x0088C7A8
extern D2CriticalSectionStrc gTaskSlotsCriticalSection_0088CAA8;                                            // 0x0088CAA8

// 0x00564250
void __fastcall TASK_LinkList_PushFront(D2LinkStrc* pList, D2LinkStrc* pLink)
{
    D2_ASSERT(pList, 0x77);
    D2_ASSERT(pLink, 0x78);

    pLink->pPrev = pList;
    pLink->pNext = pList->pNext;
    pLink->pNext->pPrev = pLink;
    pList->pNext = pLink;
}

// 0x005642E0
D2LinkStrc* __fastcall TASK_LinkList_Remove(D2LinkStrc* pLink)
{
    D2_ASSERT(pLink, 0x87);

    pLink->pPrev->pNext = pLink->pNext;
    pLink->pNext->pPrev = pLink->pPrev;
    return pLink;
}

// 0x00564890
void __stdcall TASK_FreeAllQueueSlots()
{
    EnterCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);

    for (unsigned int i = 0; i < 32; ++i)
    {
        EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[i]);

        if (D2TaskStrc* pTask = gtTaskSlots_0088C708[i])
        {
            TASK_LinkList_Remove(&pTask->pTaskQueueLink);
            FOG_FreeServerMemory(0, gtTaskSlots_0088C708[i], ".\\GAME\\Task.cpp", 0x330, 0);
            gtTaskSlots_0088C708[i] = 0;
        }

        LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[i]);
    }

    gnNumberOfTasksCreated_0088C798 = 0;
    gnGamesCount_0088C79C = 0;
    LeaveCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
}
