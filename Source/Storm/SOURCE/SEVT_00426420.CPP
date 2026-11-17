#include "Storm.h"

typedef void (__stdcall* SEVTHANDLER)(void* pData);

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
    unsigned int nSequence;
    SEVTHANDLER pfnHandler;
    D2StormEventHandlerStrc* pNext;
};

struct D2StormHandlerTableStrc
{
    D2StormEventHandlerStrc** ppTable;
    unsigned int nSize;
    unsigned int nUsed;
    D2StormHandlerTableStrc* pPrevState;
};

struct D2StormEventTypeStrc
{
    unsigned int nType;
    unsigned int nSubType;
    unsigned int nSequence;
    D2StormHandlerTableStrc* f_C;
    D2StormEventTypeStrc* pNext;
};

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
static int gbSEvtModified_007792F8;                                                                         // 0x007792F8
static D2StormEventTypeStrc** gppSEvtTypes_00779300;                                                        // 0x00779300
static unsigned int gnSEvtTypeTableSize_00779304;                                                           // 0x00779304
static unsigned int gnSEvtTypeCount_00779308;                                                               // 0x00779308
extern D2CriticalSectionStrc gtSEvtLock;                                                                    // 0x0077930C
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
void __stdcall sub_0041C340_SetLastError(unsigned int nError);                                              // 0x0041C340
static D2StormEventTypeStrc* sub_00426270(unsigned int nType, unsigned int nSubType);                       // 0x00426270

static __declspec(noinline) D2StormEventTypeStrc* sub_00426270(unsigned int nType, unsigned int nSubType)
{
    if (!gppSEvtTypes_00779300 || !gnSEvtTypeTableSize_00779304)
        return 0;
    D2StormEventTypeStrc* pType;
    for (pType = gppSEvtTypes_00779300[(nType ^ nSubType) & (gnSEvtTypeTableSize_00779304 - 1)]; pType; pType = pType->pNext)
        if (pType->nType == nType && pType->nSubType == nSubType)
            break;
    return pType;
}

// build: context CalcTableSize
static unsigned int CalcTableSize(unsigned int nCount)
{
    unsigned int nSize = 1;
    while (nSize <= nCount * 2 + 2)
        nSize <<= 1;
    return nSize;
}

// 0x00426420
int __stdcall SEvtRegisterHandler(unsigned int nType, unsigned int nSubType, unsigned int nId, unsigned int dwFlags, SEVTHANDLER pfnHandler)
{
    int nValid = (__int64)pfnHandler ? -1 : 0;
    VALIDATE(!dwFlags);
    VALIDATEEND;

    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = sub_00426270(nType, nSubType);
    if (!pType)
    {
        if (gnSEvtTypeCount_00779308 >= gnSEvtTypeTableSize_00779304 / 2)
        {
            unsigned int nNewSize = CalcTableSize(gnSEvtTypeCount_00779308);
            D2StormEventTypeStrc** ppNewTypes = (D2StormEventTypeStrc**)SMemAlloc(nNewSize * sizeof(D2StormEventTypeStrc*), gszSEvtCpp, 0x143, 8);
            if (gppSEvtTypes_00779300 && gnSEvtTypeTableSize_00779304)
            {
                for (unsigned int i = 0; i < gnSEvtTypeTableSize_00779304; ++i)
                {
                    D2StormEventTypeStrc* pNext;
                    for (D2StormEventTypeStrc* pCur = gppSEvtTypes_00779300[i]; pCur; pCur = pNext)
                    {
                        const unsigned int nBucket = (pCur->nSubType ^ pCur->nType) & (nNewSize - 1);
                        pNext = pCur->pNext;
                        pCur->pNext = ppNewTypes[nBucket];
                        ppNewTypes[nBucket] = pCur;
                    }
                }
            }
            if (gppSEvtTypes_00779300)
                SMemFree(gppSEvtTypes_00779300, gszSEvtCpp, 0x154, 0);
            gppSEvtTypes_00779300 = ppNewTypes;
            gnSEvtTypeTableSize_00779304 = nNewSize;
        }

        const unsigned int nBucket = (nType ^ nSubType) & (gnSEvtTypeTableSize_00779304 - 1);
        pType = (D2StormEventTypeStrc*)SMemAlloc(sizeof(D2StormEventTypeStrc), gszSEvtCpp, 0x15D, 8);
        pType->nType = nType;
        pType->nSubType = nSubType;
        pType->f_C = (D2StormHandlerTableStrc*)SMemAlloc(sizeof(D2StormHandlerTableStrc), gszSEvtCpp, 0x160, 8);
        ++gnSEvtTypeCount_00779308;
        pType->pNext = gppSEvtTypes_00779300[nBucket];
        gppSEvtTypes_00779300[nBucket] = pType;
    }

    if (pType->f_C->nUsed >= pType->f_C->nSize / 2)
    {
        unsigned int nNewSize;
        for (nNewSize = 1; nNewSize <= pType->f_C->nSize * 2 + 2; nNewSize *= 2)
            ;

        D2StormEventHandlerStrc** ppNewTable = (D2StormEventHandlerStrc**)SMemAlloc(nNewSize * sizeof(D2StormEventHandlerStrc*), gszSEvtCpp, 0x16E, 8);
        D2StormEventHandlerStrc*** pppTails = (D2StormEventHandlerStrc***)SMemAlloc(nNewSize * sizeof(D2StormEventHandlerStrc**), gszSEvtCpp, 0x16F, 8);
        for (unsigned int i = 0; i < nNewSize; ++i)
        {
            pppTails[i] = &ppNewTable[i];
        }

        if (pType->f_C->ppTable && pType->f_C->nSize)
        {
            for (unsigned int i = 0; i < pType->f_C->nSize; ++i)
            {
                D2StormEventHandlerStrc* pNext;
                for (D2StormEventHandlerStrc* pCur = pType->f_C->ppTable[i]; pCur; pCur = pNext)
                {
                    const unsigned int nBucket = pCur->nId & (nNewSize - 1);
                    pNext = pCur->pNext;
                    pCur->pNext = 0;
                    *pppTails[nBucket] = pCur;
                    pppTails[nBucket] = &pCur->pNext;
                }
            }
        }

        SMemFree(pppTails, gszSEvtCpp, 0x182, 0);
        if (pType->f_C->ppTable)
            SMemFree(pType->f_C->ppTable, gszSEvtCpp, 0x184, 0);

        pType->f_C->ppTable = ppNewTable;
        pType->f_C->nSize = nNewSize;
    }

    const unsigned int nBucket = (pType->f_C->nSize - 1) & nId;
    D2StormEventHandlerStrc* pHandler = (D2StormEventHandlerStrc*)SMemAlloc(sizeof(D2StormEventHandlerStrc), gszSEvtCpp, 0x18D, 8);
    pHandler->nId = nId;
    pHandler->nSequence = ++pType->nSequence;
    pHandler->pfnHandler = pfnHandler;
    pHandler->pNext = pType->f_C->ppTable[nBucket];
    pType->f_C->ppTable[nBucket] = pHandler;
    ++pType->f_C->nUsed;
    gbSEvtModified_007792F8 = 1;
    LeaveCriticalSection(&gtSEvtLock);
    return nValid ? 1 : 0;
}
