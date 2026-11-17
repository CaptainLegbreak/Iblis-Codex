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
    unsigned int nSequence;
    SEVTHANDLER pfnHandler;
    D2StormEventHandlerStrc* pNext;
};

struct D2StormHandlerTableStrc
{
    D2StormEventHandlerStrc** ppTable;
    unsigned int nSize;
};

struct D2StormEventTypeStrc
{
    unsigned int nType;
    unsigned int nSubType;
    char unk0x08[0x04];
    D2StormHandlerTableStrc* f_C;
    D2StormEventTypeStrc* pNext;
};

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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
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
        char* pHead = m_terminator.Next();
        return pHead;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    char* sub_00426C80_RawNext(D2StormLinkStrc* pNode);                                                    // 0x00426C80
    char* sub_00426F20_DeleteNode(char* pNode);                                                             // 0x00426F20
    char* DeleteNode(char* pNode);
};
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern D2StormBreakCmdListStrc gtSEvtBreakCmdList_007088E8;                                                 // 0x007088E8
static int gbSEvtModified_007792F8;                                                                         // 0x007792F8
static long gnSEvtDispatchDepth_007792FC;                                                                   // 0x007792FC
extern D2CriticalSectionStrc gtSEvtLock;                                                                    // 0x0077930C
extern D2StormEventTypeStrc** gppSEvtTypes_00779300;                                                        // 0x00779300
extern unsigned int gnSEvtTypeTableSize_00779304;                                                           // 0x00779304
int __stdcall SMemFree(void* pLocation, const char* szLogFileName, int nLogLine, unsigned int nFlags);       // 0x00412650

// build: context D2StormBreakCmdListStrc::DeleteNode
inline char* D2StormBreakCmdListStrc::DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormLinkStrc*)pNode)->Unlink();
    SMemFree(pNode, gszTypeBreakCmd_007088D8, -2, 0);
    return pNext;
}

// 0x00426270
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

// 0x00426F90
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
        {
            int nDelete = 0;
            char* pNode = gtSEvtBreakCmdList_007088E8.Head();
            while ((int)pNode > 0)
            {
                if (((D2StormBreakCmdStrc*)pNode)->pData == pData)
                {
                    bBreak = 1;
                    nDelete = -12;
                }
                if (nDelete)
                {
                    pNode = gtSEvtBreakCmdList_007088E8.DeleteNode(pNode);
                    pNode = (nDelete > 0) ? pNode : 0;
                    nDelete = 0;
                }
                else
                    pNode = ((D2StormLinkStrc*)pNode)->m_next;
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
            if (pType && pType->f_C->ppTable && pType->f_C->nSize)
            {
                for (pHandler = pType->f_C->ppTable[(pType->f_C->nSize - 1) & nId]; pHandler; pHandler = pHandler->pNext)
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

    if (gtSEvtBreakCmdList_007088E8.m_terminator.Next())
    {
        EnterCriticalSection(&gtSEvtLock);
        char* pNode = gtSEvtBreakCmdList_007088E8.Head();
        while ((int)pNode > 0)
        {
            if (((D2StormBreakCmdStrc*)pNode)->pData == pData)
                pNode = gtSEvtBreakCmdList_007088E8.sub_00426F20_DeleteNode(pNode);
            else
                pNode = gtSEvtBreakCmdList_007088E8.sub_00426C80_RawNext((D2StormLinkStrc*)pNode);
        }
        LeaveCriticalSection(&gtSEvtLock);
    }

    return bResult;
}
