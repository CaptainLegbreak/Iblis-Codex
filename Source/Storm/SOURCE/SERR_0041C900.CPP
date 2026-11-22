#include "Storm.h"
#include "D2StormAutoLink.h"
#include "D2StormTypes.h"

struct D2StormNodeListStrc;

struct D2StormHandlerNodeStrc;

struct D2StormArrayAStrc;

struct D2StormArrayCStrc;

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

void __stdcall SErrReportNamedResourceLeak(const char* szName, const char* szDetail); // 0x0041D010

void __cdecl sub_0041C1A0_LockErrorState(); // 0x0041C1A0

void __cdecl sub_0041C1E0_UnlockErrorState(); // 0x0041C1E0

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExisting);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            {
                D2StormLinkStrc* pPrev = pExistingLink->m_prevlink;
                pLink->m_prevlink = pPrev;
                pLink->m_next = pPrev->m_next;
                pPrev->m_next = pNode;
                pExistingLink->m_prevlink = pLink;
            }
            break;
        }
    }
};

struct D2StormHandlerNodeStrc
{
    D2StormLinkStrc f_0;
    int nValue;
};

extern D2StormNodeListStrc gHandlerList_00708420; // 0x00708420

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += f_4;
        if (nCount > f_0)
        {
            if (bRound)
            {
                unsigned int nChunk = f_C ? f_C : sub_004210A0_CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_004216E0_ReallocData(nCount);
        }
    }
    // build: context D2StormArrayAStrc::SetCount
    void SetCount(unsigned int nCount)
    {
        if (nCount > f_4)
            Reserve(nCount - f_4, 1);
        f_4 = nCount;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct D2StormArrayCStrc
{
    unsigned int f_0;
    unsigned int f_4;
    char* f_8;
    unsigned int f_C;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += f_4;
        if (nCount > f_0)
        {
            if (bRound)
            {
                unsigned int nChunk = f_C ? f_C : sub_00421240_CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_00421770_ReallocData(nCount);
        }
    }
    void ReallocAndClear(unsigned int nCount)
    {
        f_0 = nCount;
        if (f_8 || nCount)
            f_8 = (char*)SMemReAlloc(f_8, nCount, gszTypeNameChar_0070888C, -2, 0);
    }
    unsigned int sub_00421240_CalcChunkSize(unsigned int nCount);                                           // 0x00421240
    void sub_00421770_ReallocData(unsigned int nAlloc);                                                     // 0x00421770
    void sub_00421A50_Set(unsigned int nCount, const char* pData);
    unsigned int sub_00421F60_Add(unsigned int nCount, const char* pData);
};

inline void* operator new(unsigned int, void* pPlace) throw();

// build: context D2StormArrayAStrc::Reserve
// build: context D2StormArrayCStrc::Reserve
inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0

int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0

extern unsigned long gdwStormOwnerThread_007790C8; // 0x007790C8

void* gpStormOwnerA_007790C0; // 0x007790C0

extern void* gpStormOwnerB_007790C4; // 0x007790C4

extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args); // 0x00682DA1

void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300

// 0x0041C900
void __stdcall SErrRegisterHandler(int nValue)
{
    sub_0041C1A0_LockErrorState();
    D2StormHandlerNodeStrc* pNode = new (SMemAlloc(sizeof(D2StormHandlerNodeStrc), gszTypeNameHandler_00708434, -2, 0x8000008)) D2StormHandlerNodeStrc;
    gHandlerList_00708420.LinkNode((char*)pNode, 1, 0);
    pNode->nValue = nValue;
    sub_0041C1E0_UnlockErrorState();
}

// 0x0041D1E0
void __stdcall SErrReportResourceLeak(const char* szName)
{
    SErrReportNamedResourceLeak(szName, 0);
}

// 0x0041D160
void __cdecl sub_0041D160_DisplayAppFatal(const char* szFormat, ...)
{
    const char* szFile = 0;
    int nLine = 0;
    sub_0041C1A0_LockErrorState();
    if (gdwStormOwnerThread_007790C8 == GetCurrentThreadId())
    {
        szFile = (const char*)gpStormOwnerA_007790C0;
        nLine = (int)gpStormOwnerB_007790C4;
        SMemZero(&gpStormOwnerA_007790C0, 12);
    }
    sub_0041C1E0_UnlockErrorState();
    char szText[0x400];
    va_list args;
    va_start(args, szFormat);
    vsprintf(szText, szFormat, args);
    SErrDisplayError(0x85100084, szFile, nLine, szText, 0, 1);
    ExitProcess(1);
}
