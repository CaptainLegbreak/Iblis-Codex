struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct SEvtBreakCmdStrc;

struct SEvtLinkStrc
{
    SEvtLinkStrc* pPrevLink;
    SEvtBreakCmdStrc* pNext;

    SEvtLinkStrc() { pPrevLink = 0; pNext = 0; }
    SEvtLinkStrc* NextLink(int nLinkOffset = -1)
    {
        if ((int)pNext < 0)
            return (SEvtLinkStrc*)~(unsigned int)pNext;
        if (nLinkOffset < 0)
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        return (SEvtLinkStrc*)((int)pNext + nLinkOffset);
    }
    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink()->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct SEvtBreakCmdStrc
{
    SEvtLinkStrc f_0;
    void* pData;
};

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) { return pWhere; }

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218

void* __stdcall SMemAlloc(unsigned int nSize, const char* szLogName, int nLogLine, unsigned int nFlags);    // 0x00413020

extern "C" const char gszBREAKCMDTypeName[];                                                                // 0x007088D8
extern SEvtLinkStrc gtSEvtBreakCmdTerminator;                                                               // 0x007088EC
extern D2CriticalSectionStrc gtSEvtLock;                                                                    // 0x0077930C

// 0x00426E80
int __stdcall SEvtBreakHandlerChain(void* pData)
{
    EnterCriticalSection(&gtSEvtLock);
    SEvtBreakCmdStrc* pCmd = new (SMemAlloc(sizeof(SEvtBreakCmdStrc), gszBREAKCMDTypeName, -2, 8)) SEvtBreakCmdStrc;
    SEvtLinkStrc* pLink = pCmd ? &pCmd->f_0 : &gtSEvtBreakCmdTerminator;
    pLink->Unlink();
    SEvtLinkStrc* pTail = gtSEvtBreakCmdTerminator.pPrevLink;
    pLink->pPrevLink = pTail;
    pLink->pNext = pTail->pNext;
    pTail->pNext = pCmd;
    gtSEvtBreakCmdTerminator.pPrevLink = pLink;
    pCmd->pData = pData;
    LeaveCriticalSection(&gtSEvtLock);
    return 1;
}

#include "gen/data/Source/Storm/00426E80_SEvtBreakHandlerChain.inc"
