#include "D2CMP.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelStrc;
struct D2StormEntry38Strc;
struct D2CmpCelFileViewStrc;
struct D2CmpCelContextStrc;
struct D2StormLinkStrc;
struct D2StormSlotLinkStrc;
struct D2StormSlotListStrc;
struct D2StormNodeStrc;
struct D2CelEntryStrc;
struct D2StormNodeListStrc;
struct D2StormHashObjectStrc;
struct D2StormSlotArrayStrc;
struct D2StormEntryArrayStrc;
struct D2GameHashTableStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue);

struct D2CmpCelFileViewStrc
{
    int nVersion;
    char unk0x04[0x0C];
    unsigned int nDirections;
    unsigned int nFrames;
    D2CelStrc* pCels[1];
};

struct D2CmpCelContextStrc
{
    unsigned int nFrame;
    char unk0x04[0x30];
    D2CmpCelFileViewStrc* pCelFile;
    char unk0x38[0x08];
    unsigned int nDirection;
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormLinkStrc()
    {
        Unlink();
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2StormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormSlotLinkStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
    D2StormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormSlotLinkStrc m_terminator;
    D2StormSlotListStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2StormSlotListStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
    D2StormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2StormSlotLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormSlotLinkStrc* pExistingLink = Link(pExistingNode);
        D2StormSlotLinkStrc* pPrevLink;
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    // build: symbol ?UnlinkAll@D2StormSlotListStrc@@QAEXXZ 0x00602640
    void UnlinkAll();
};

struct D2StormNodeStrc
{
    D2StormLinkStrc f_0;
};

struct D2CelEntryStrc : D2StormNodeStrc
{
    int nArg8;
    unsigned int nHeight;
    unsigned int nWidth;
    unsigned int nSize;
    int nArg6;
    int nArg7;
    void* pData;
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormNodeListStrc()
    {
        m_linkoffset = 0;
        InitializeTerminator();
    }
    ~D2StormNodeListStrc()
    {
        UnlinkAll();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormLinkStrc* Link(D2StormNodeStrc* pNode)
    {
        return pNode ? &pNode->f_0 : &m_terminator;
    }
    void LinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExistingNode);
        D2StormLinkStrc* pPrevLink;
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = (char*)pNode;
            break;
        default:
            pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = (char*)pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    D2CelEntryStrc* NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
// build: symbol ?UnlinkAll@D2StormNodeListStrc@@QAEXXZ 0x006025E0
    void UnlinkAll();
    void sub_00601FC0_LinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode);      // 0x00601FC0
    void sub_00602BF0_DeleteAll();                                                                          // 0x00602BF0
    D2CelEntryStrc* sub_006029B0_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    D2CelEntryStrc* sub_00602C40_DeleteNode(D2CelEntryStrc* pNode);
};

struct D2StormHashObjectStrc
{
    unsigned int f_0;
    D2StormSlotLinkStrc m_linktoslot;
    D2StormSlotLinkStrc f_C;
    int f_14;
};

struct D2StormEntry38Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeListStrc tList;

    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;
    D2StormSlotArrayStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
    ~D2StormSlotArrayStrc();                                                                                // 0x00603060
    void Clear()
    {
        this->~D2StormSlotArrayStrc();
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
    }
};

struct D2StormEntryArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormEntry38Strc* f_8;
    unsigned int f_C;

    D2StormEntryArrayStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
    ~D2StormEntryArrayStrc();                                                                               // 0x00603140
};

struct D2GameHashTableStrc
{
    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x006036D0
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00603610
    virtual ~D2GameHashTableStrc();                                                                         // 0x00603460
    virtual void Destroy();
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_00602800_InternalClear(int bWarn);                                                             // 0x00602800
};

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

// 0x00601810
int __stdcall sub_00601810_IsGfxFrameValid(D2CmpCelContextStrc* pContext)
{
    D2CmpCelFileViewStrc* pCelFile = pContext->pCelFile;
    if (!pCelFile)
    {
        return 0;
    }

    if (pCelFile->nVersion != 6)
    {
        return 0;
    }

    if (pContext->nDirection >= 0x40)
    {
        return 0;
    }

    if (pContext->nFrame > pCelFile->nFrames)
    {
        return 0;
    }

    return 1;
}

// 0x00601840
D2CelStrc* __stdcall D2CMP_CelGetHandle(D2CmpCelContextStrc* pContext)
{
    D2_ASSERT(pContext, 0x566);
    D2_ASSERT(sub_00601810_IsGfxFrameValid(pContext), 0x567);

    D2CmpCelFileViewStrc* pCelFile = pContext->pCelFile;
    const unsigned int nDirection = pContext->nDirection;
    const unsigned int nDirections = pCelFile->nDirections;
    const int nIndex = gaDirectionIndex64_006E45A0[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
    return pCelFile->pCels[nIndex * pCelFile->nFrames + pContext->nFrame];
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

inline D2StormSlotLinkStrc::~D2StormSlotLinkStrc()
{
    Unlink();
}

inline D2StormSlotListStrc::~D2StormSlotListStrc()
{
    UnlinkAll();
}

// build: symbol ??1D2StormHashObjectStrc@@QAE@XZ 0x00602430
// 0x00603060
D2StormSlotArrayStrc::~D2StormSlotArrayStrc()
{
    for (unsigned int i = 0; i < f_4; ++i)
        f_8[i].~D2StormSlotListStrc();
    if (f_8)
        SMemFree(f_8, gszTypeNameCelSlotList, -2, 0);
}

// 0x00603140
D2StormEntryArrayStrc::~D2StormEntryArrayStrc()
{
    for (unsigned int i = 0; i < f_4; ++i)
        f_8[i].~D2StormEntry38Strc();
    if (f_8)
        SMemFree(f_8, gszTypeNameCelList, -2, 0);
}

// 0x00603780
void D2GameHashTableStrc::Destroy()
{
    sub_00602800_InternalClear(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.Clear();
}
