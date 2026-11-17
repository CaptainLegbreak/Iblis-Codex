#include "Storm.h"

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
extern D2CriticalSectionStrc gtSEvtLock;                                                                    // 0x0077930C
extern D2StormEventTypeStrc** gppSEvtTypes_00779300;                                                        // 0x00779300
extern unsigned int gnSEvtTypeTableSize_00779304;                                                           // 0x00779304
static int gbSEvtModified_007792F8;                                                                         // 0x007792F8
void* __stdcall SMemAlloc(unsigned int nSize, const char* szLogName, int nLogLine, unsigned int nFlags);    // 0x00413020
void __cdecl operator delete(void* pMemory);                                                                // 0x004053F0
void __stdcall sub_00426180_CopyHandlerTable(D2StormHandlerTableStrc* pDest, D2StormHandlerTableStrc* pSource); // 0x00426180

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

// 0x00426370
int __stdcall SEvtPushState(unsigned int nType, unsigned int nSubType)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = sub_00426270(nType, nSubType);
    if (pType)
    {
        D2StormHandlerTableStrc* pState = (D2StormHandlerTableStrc*)SMemAlloc(sizeof(D2StormHandlerTableStrc), gszSEvtCpp, 284, 0);
        sub_00426180_CopyHandlerTable(pState, pType->f_C);
        pState->pPrevState = pType->f_C;
        pType->f_C = pState;
        gbSEvtModified_007792F8 = 1;
        bResult = 1;
    }
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
}

// 0x00426720
int __stdcall SEvtUnregisterHandler(unsigned int nType, unsigned int nSubType, unsigned int nId, void* pfnHandler)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = sub_00426270(nType, nSubType);
    if (pType && pType->f_C->ppTable && pType->f_C->nSize)
    {
        const unsigned int nKey = nId;
        D2StormEventHandlerStrc** ppNext = &pType->f_C->ppTable[nKey & (pType->f_C->nSize - 1)];
        while (*ppNext)
        {
            D2StormEventHandlerStrc* p = *ppNext;
            if (p->nId == nKey && (!pfnHandler || p->pfnHandler == pfnHandler))
            {
                *ppNext = p->pNext;
                delete p;
                gbSEvtModified_007792F8 = 1;
                bResult = 1;
                --pType->f_C->nUsed;
            }
            else
                ppNext = &p->pNext;
        }
    }
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
}
