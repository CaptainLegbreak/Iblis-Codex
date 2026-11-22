#include "Storm.h"
#include "D2StormAutoLink.h"
#include "D2StormTypes.h"
struct D2StormNodeListStrc;
struct WNDREC;
struct D2StormArrayAStrc;
struct D2StormArrayCStrc;
extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam); // 0x006CC488
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult); // 0x00420B00
int __stdcall SEvtPushState(unsigned int nType, unsigned int nSubtype); // 0x00426370
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
struct WNDREC
{
    D2StormLinkStrc f_0;
    int nValue;
};
extern D2StormNodeListStrc gWndRecList_00708860; // 0x00708860
#include "D2StormBigBuffer.h"
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
struct SMSGHANDLER_PARAMS;
int __stdcall SEvtBreakHandlerChain(void* pData); // 0x00426E80
extern int gdwGlobal_007792F4;                                                                              // 0x007792F4
struct D2StormNodeListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_00420520_Link(char* pNode);
    void sub_00420540_LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);
    char* sub_004205F0_Next(char* pNode);
    void sub_00420650_UnlinkNode(char* pNode);
    char* sub_004206E0_RawNext(char* pNode);
};
// build: context D2StormArrayAStrc::Reserve
// build: context D2StormArrayCStrc::Reserve
inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}
int __stdcall sub_004269C0_RegisterHandler(unsigned long dwId, void* pContext); // 0x004269C0

// 0x00420290
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg)
{
    return SEvtBreakHandlerChain(pMsg);
}

// 0x00420360
int __stdcall SMsgPushRegisterState(int nType)
{
    SEvtPushState('SMSH', nType);
    SEvtPushState('SMSI', nType);
    SEvtPushState('SMSJ', nType);
    SEvtPushState('SMSG', nType);
    return 1;
}

// 0x004203A0
int __stdcall SMsgSetDefaultWindow(int hWnd)
{
    gdwGlobal_007792F4 = hWnd;
    return 1;
}

// 0x004203F0
D2StormLinkStrc* D2StormLinkStrc::sub_004203F0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00420520
D2StormLinkStrc* D2StormNodeListBStrc::sub_00420520_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
}

// 0x00420540
void D2StormNodeListBStrc::sub_00420540_LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
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

// 0x004205F0
char* D2StormNodeListBStrc::sub_004205F0_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00420650
void D2StormNodeListBStrc::sub_00420650_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004206E0
char* D2StormNodeListBStrc::sub_004206E0_RawNext(char* pNode)
{
    return pNode ? ((D2StormLinkStrc*)pNode)->m_next : m_terminator.m_next;
}

// 0x004208E0
void __stdcall sub_004208E0_AddWndRec(int nValue)
{
    WNDREC* pNode = new (SMemAlloc(sizeof(WNDREC), gszTypeNameWndRec_00708850, -2, 8)) WNDREC;
    gWndRecList_00708860.LinkNode((char*)pNode, 2, 0);
    pNode->nValue = nValue;
}

// 0x00420CF0
int __stdcall sub_00420CF0_WindowProc(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam)
{
    int bUseResult = 0;
    int lResult = 0;
    if (SMsgDispatchMessage(hWnd, uMsg, wParam, lParam, &bUseResult, &lResult) && bUseResult)
        return lResult;
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

// 0x00420310
int __cdecl sub_00420310()
{
    return gdwGlobal_007792F4;
}

// 0x00420320
int __stdcall sub_00420320_RegisterHandlers(void* pContext)
{
    sub_004269C0_RegisterHandler(0x534D5348, pContext);
    sub_004269C0_RegisterHandler(0x534D5349, pContext);
    sub_004269C0_RegisterHandler(0x534D534A, pContext);
    sub_004269C0_RegisterHandler(0x534D5347, pContext);
    return 1;
}
