#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218

D2CriticalSectionStrc gtSEvtLock;                                                                           // 0x0077930C

static D2StormEventTypeStrc** gppSEvtTypes_00779300;                                                        // 0x00779300

static unsigned int gnSEvtTypeTableSize_00779304;                                                           // 0x00779304

static unsigned int gnSEvtTypeCount_00779308;                                                               // 0x00779308

static int gbSEvtModified_007792F8;                                                                         // 0x007792F8

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

void __cdecl operator delete(void* pMemory);                                                                // 0x004053F0

static D2StormEventTypeStrc* sub_00426270(unsigned int nType, unsigned int nSubType);

struct D2StormBreakCmdStrc
{
    D2StormLinkStrc f_0;
    void* pData;
};

struct D2StormBreakCmdListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
    char* sub_00426C80_RawNext(D2StormLinkStrc* pNode);                                                    // 0x00426C80
    char* sub_00426F20_DeleteNode(char* pNode);                                                             // 0x00426F20
};

extern D2StormBreakCmdListStrc gtSEvtBreakCmdList_007088E8;                                                 // 0x007088E8

static long gnSEvtDispatchDepth_007792FC;                                                                   // 0x007792FC

void* __stdcall SMemAlloc(unsigned int nSize, const char* szLogName, int nLogLine, unsigned int nFlags);    // 0x00413020

void __stdcall sub_00426180_CopyHandlerTable(D2StormHandlerTableStrc* pDest, D2StormHandlerTableStrc* pSource); // 0x00426180

#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340


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

// 0x00426270
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

int __stdcall SEvtDispatch(unsigned int nType, unsigned int nSubType, unsigned int nId, void* pData)
{
    InterlockedIncrement(&gnSEvtDispatchDepth_007792FC);
    int bResult = 0;
    unsigned int nMinSequence = 0xFFFFFFFF;
    D2StormEventHandlerStrc* pHandler = 0;
    do
    {
        EnterCriticalSection(&gtSEvtLock);

        int bBreak = 0;
        for (char* pNode = gtSEvtBreakCmdList_007088E8.Head(); pNode; pNode = ((D2StormLinkStrc*)pNode)->Next())
        {
            if (((D2StormBreakCmdStrc*)pNode)->pData == pData)
            {
                ((D2StormLinkStrc*)pNode)->Unlink();
                SMemFree(pNode, gszTypeBreakCmd_007088D8, -2, 0);
                bBreak = 1;
                break;
            }
        }

        if (bBreak)
        {
            LeaveCriticalSection(&gtSEvtLock);
            break;
        }

        if (!pHandler || gbSEvtModified_007792F8)
        {
            pHandler = 0;
            D2StormEventTypeStrc* pType = sub_00426270(nType, nSubType);
            if (pType && pType->pHandlers->ppTable && pType->pHandlers->nSize)
            {
                D2StormHandlerTableStrc* pTable = pType->pHandlers;
                for (pHandler = pTable->ppTable[(pTable->nSize - 1) & nId]; pHandler; pHandler = pHandler->pNext)
                {
                    if (pHandler->nId == nId && pHandler->nSequence < nMinSequence)
                        break;
                }

                if (gnSEvtDispatchDepth_007792FC == 1)
                    gbSEvtModified_007792F8 = 0;
            }
        }

        SEVTHANDLER pfnHandler = 0;
        if (pHandler)
        {
            nMinSequence = pHandler->nSequence;
            pfnHandler = pHandler->pfnHandler;
            do
            {
                pHandler = pHandler->pNext;
            }
            while (pHandler && pHandler->nId != nId);
        }

        LeaveCriticalSection(&gtSEvtLock);

        if (pfnHandler)
        {
            bResult = 1;
            pfnHandler(pData);
        }
    }
    while (pHandler);

    InterlockedDecrement(&gnSEvtDispatchDepth_007792FC);

    if (gtSEvtBreakCmdList_007088E8.Head())
    {
        EnterCriticalSection(&gtSEvtLock);
        char* pNode = gtSEvtBreakCmdList_007088E8.Head();
        while (pNode)
        {
            if (((D2StormBreakCmdStrc*)pNode)->pData == pData)
                pNode = gtSEvtBreakCmdList_007088E8.sub_00426F20_DeleteNode(pNode);
            else
                pNode = gtSEvtBreakCmdList_007088E8.sub_00426C80_RawNext((D2StormLinkStrc*)pNode);
            if ((int)pNode <= 0)
                pNode = 0;
        }
        LeaveCriticalSection(&gtSEvtLock);
    }

    return bResult;
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
            while ((pState = pType->pHandlers) != 0)
            {
                pType->pHandlers = pState->pPrevState;
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

// 0x00426370
int __stdcall SEvtPushState(unsigned int nType, unsigned int nSubType)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = sub_00426270(nType, nSubType);
    if (pType)
    {
        D2StormHandlerTableStrc* pState = (D2StormHandlerTableStrc*)SMemAlloc(sizeof(D2StormHandlerTableStrc), gszSEvtCpp, 284, 0);
        sub_00426180_CopyHandlerTable(pState, pType->pHandlers);
        pState->pPrevState = pType->pHandlers;
        pType->pHandlers = pState;
        gbSEvtModified_007792F8 = 1;
        bResult = 1;
    }
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
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
        pType->pHandlers = (D2StormHandlerTableStrc*)SMemAlloc(sizeof(D2StormHandlerTableStrc), gszSEvtCpp, 0x160, 8);
        ++gnSEvtTypeCount_00779308;
        pType->pNext = gppSEvtTypes_00779300[nBucket];
        gppSEvtTypes_00779300[nBucket] = pType;
    }

    if (pType->pHandlers->nUsed >= pType->pHandlers->nSize / 2)
    {
        unsigned int nNewSize;
        for (nNewSize = 1; nNewSize <= pType->pHandlers->nSize * 2 + 2; nNewSize *= 2)
            ;

        D2StormEventHandlerStrc** ppNewTable = (D2StormEventHandlerStrc**)SMemAlloc(nNewSize * sizeof(D2StormEventHandlerStrc*), gszSEvtCpp, 0x16E, 8);
        D2StormEventHandlerStrc*** pppTails = (D2StormEventHandlerStrc***)SMemAlloc(nNewSize * sizeof(D2StormEventHandlerStrc**), gszSEvtCpp, 0x16F, 8);
        for (unsigned int i = 0; i < nNewSize; ++i)
        {
            pppTails[i] = &ppNewTable[i];
        }

        if (pType->pHandlers->ppTable && pType->pHandlers->nSize)
        {
            for (unsigned int i = 0; i < pType->pHandlers->nSize; ++i)
            {
                D2StormEventHandlerStrc* pNext;
                for (D2StormEventHandlerStrc* pCur = pType->pHandlers->ppTable[i]; pCur; pCur = pNext)
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
        if (pType->pHandlers->ppTable)
            SMemFree(pType->pHandlers->ppTable, gszSEvtCpp, 0x184, 0);

        pType->pHandlers->ppTable = ppNewTable;
        pType->pHandlers->nSize = nNewSize;
    }

    const unsigned int nBucket = (pType->pHandlers->nSize - 1) & nId;
    D2StormEventHandlerStrc* pHandler = (D2StormEventHandlerStrc*)SMemAlloc(sizeof(D2StormEventHandlerStrc), gszSEvtCpp, 0x18D, 8);
    pHandler->nId = nId;
    pHandler->nSequence = ++pType->nSequence;
    pHandler->pfnHandler = pfnHandler;
    pHandler->pNext = pType->pHandlers->ppTable[nBucket];
    pType->pHandlers->ppTable[nBucket] = pHandler;
    ++pType->pHandlers->nUsed;
    gbSEvtModified_007792F8 = 1;
    LeaveCriticalSection(&gtSEvtLock);
    return nValid ? 1 : 0;
}

// 0x00426720
int __stdcall SEvtUnregisterHandler(unsigned int nType, unsigned int nSubType, unsigned int nId, void* pfnHandler)
{
    int bResult = 0;
    EnterCriticalSection(&gtSEvtLock);
    D2StormEventTypeStrc* pType = sub_00426270(nType, nSubType);
    if (pType && pType->pHandlers->ppTable && pType->pHandlers->nSize)
    {
        const unsigned int nKey = nId;
        D2StormEventHandlerStrc** ppNext = &pType->pHandlers->ppTable[nKey & (pType->pHandlers->nSize - 1)];
        while (*ppNext)
        {
            D2StormEventHandlerStrc* p = *ppNext;
            if (p->nId == nKey && (!pfnHandler || p->pfnHandler == pfnHandler))
            {
                *ppNext = p->pNext;
                delete p;
                gbSEvtModified_007792F8 = 1;
                bResult = 1;
                --pType->pHandlers->nUsed;
            }
            else
                ppNext = &p->pNext;
        }
    }
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
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
        while ((pState = pType->pHandlers) != 0)
        {
            pType->pHandlers = pState->pPrevState;
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
        D2StormHandlerTableStrc* pState = pType->pHandlers;
        D2StormHandlerTableStrc* pPrev = pState->pPrevState;
        if (!pPrev)
            bResult = UNREGISTER_TYPE(nType, nSubType);
        else
        {
            DELETE_TABLE(pState);
            pType->pHandlers = pPrev;
        }
    }
    gbSEvtModified_007792F8 = 1;
    LeaveCriticalSection(&gtSEvtLock);
    return bResult;
}
