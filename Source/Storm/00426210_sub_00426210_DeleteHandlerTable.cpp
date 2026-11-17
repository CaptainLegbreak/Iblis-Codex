struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormEventHandlerStrc
{
    unsigned int nId;
    int unk0x04;
    void* pfnHandler;
    D2StormEventHandlerStrc* pNext;
};

struct D2StormHandlerTableStrc
{
    D2StormEventHandlerStrc** ppTable;
    unsigned int nSize;
    int nUsed;
    D2StormHandlerTableStrc* pPrevState;
};

struct D2StormEventTypeStrc
{
    unsigned int nType;
    unsigned int nSubType;
    int unk0x08;
    D2StormHandlerTableStrc* f_C;
    D2StormEventTypeStrc* pNext;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" const char gszSEvtCpp[];                                                                        // 0x006D0224
D2CriticalSectionStrc gtSEvtLock;                                                                           // 0x0077930C
D2StormEventTypeStrc** gppSEvtTypes_00779300;                                                               // 0x00779300
unsigned int gnSEvtTypeTableSize_00779304;                                                                  // 0x00779304
unsigned int gnSEvtTypeCount_00779308;                                                                      // 0x00779308
static int gbSEvtModified_007792F8;                                                                         // 0x007792F8
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void __cdecl operator delete(void* pMemory);                                                                // 0x004053F0

static D2StormEventTypeStrc* sub_00426270(unsigned int nType, unsigned int nSubType)
{
    if (!gppSEvtTypes_00779300 || !gnSEvtTypeTableSize_00779304)
        return 0;
    D2StormEventTypeStrc* pType;
    for (pType = gppSEvtTypes_00779300[(nType ^ nSubType) & (gnSEvtTypeTableSize_00779304 - 1)]; pType; pType = pType->pNext)
        if (pType->nType == nType && pType->nSubType == nSubType)
            break;
    return pType;
}

// 0x00426210
static void __cdecl sub_00426210_DeleteHandlerTable(D2StormHandlerTableStrc* pTable)
{
    for (unsigned int i = 0; i < pTable->nSize; i++)
    {
        D2StormEventHandlerStrc* pHandler;
        while ((pHandler = pTable->ppTable[i]) != 0)
        {
            pTable->ppTable[i] = pHandler->pNext;
            SMemFree(pHandler, "delete", -1, 0);
        }
    }
    SMemFree(pTable->ppTable, gszSEvtCpp, 88, 0);
    SMemFree(pTable, "delete", -1, 0);
}
#define DELETE_TABLE sub_00426210_DeleteHandlerTable

// 0x004262B0
int __stdcall SEvtDestroy()
{
    EnterCriticalSection(&gtSEvtLock);
    for (unsigned int i = 0; i < gnSEvtTypeTableSize_00779304; i++)
    {
        D2StormEventTypeStrc* pType;
        while ((pType = gppSEvtTypes_00779300[i]) != 0)
        {
            D2StormHandlerTableStrc* pState;
            while ((pState = pType->f_C) != 0)
            {
                pType->f_C = pState->pPrevState;
                DELETE_TABLE(pState);
            }
            gppSEvtTypes_00779300[i] = pType->pNext;
            SMemFree(pType, "delete", -1, 0);
        }
    }
    if (gppSEvtTypes_00779300)
        SMemFree(gppSEvtTypes_00779300, "delete", -1, 0);
    gppSEvtTypes_00779300 = 0;
    gnSEvtTypeTableSize_00779304 = 0;
    gnSEvtTypeCount_00779308 = 0;
    gbSEvtModified_007792F8 = 1;
    LeaveCriticalSection(&gtSEvtLock);
    return 1;
}

// 0x00426810
int __stdcall SEvtUnregisterType(unsigned int nType, unsigned int nSubType)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = sub_00426270(nType, nSubType);
    if (pType)
    {
        D2StormHandlerTableStrc* pState;
        while ((pState = pType->f_C) != 0)
        {
            pType->f_C = pState->pPrevState;
            DELETE_TABLE(pState);
        }
        D2StormEventTypeStrc** ppNext = &gppSEvtTypes_00779300[(nType ^ nSubType) & (gnSEvtTypeTableSize_00779304 - 1)];
        while (*ppNext)
        {
            D2StormEventTypeStrc* p = *ppNext;
            if (p == pType)
            {
                *ppNext = p->pNext;
                delete p;
                gnSEvtTypeCount_00779308 -= 1;
            }
            else
                ppNext = &p->pNext;
        }
        gbSEvtModified_007792F8 = 1;
        bResult = 1;
    }
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
}
#define UNREGISTER_TYPE SEvtUnregisterType

// 0x004269C0
int __stdcall SEvtPopState(unsigned int nType, unsigned int nSubType)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = sub_00426270(nType, nSubType);
    if (pType)
    {
        D2StormHandlerTableStrc* pState = pType->f_C;
        D2StormHandlerTableStrc* pPrev = pState->pPrevState;
        if (!pPrev)
            bResult = UNREGISTER_TYPE(nType, nSubType);
        else
        {
            DELETE_TABLE(pState);
            pType->f_C = pPrev;
        }
    }
    gbSEvtModified_007792F8 = 1;
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
}
