#pragma once
// Storm's intrusive lists and growable arrays as the cel loader (CelCmp*.cpp) uses them: the link, the list kinds
// (slot, node, E, A lists) and the slot and entry arrays.

struct D2StormEntry38Strc;
struct D2StormHashChunkStrc;
struct D2CelEntryStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;                            // 0x00
    char* m_next;                                           // 0x04

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
    D2StormLinkStrc* sub_00601BC0_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_00601C30_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_00601D30_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0060E170_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0060E1C0_NextLink(int nLinkOffset);
};

struct D2StormNodeStrc
{
    D2StormLinkStrc f_0;                                    // 0x00
};

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;                        // 0x00
    char* m_next;                                           // 0x04

    D2StormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormSlotLinkStrc()
    {
        Unlink();
    }
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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormSlotListStrc
{
    int m_linkoffset;                                       // 0x00
    D2StormSlotLinkStrc m_terminator;                       // 0x04

    D2StormSlotListStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    D2StormSlotListStrc(const D2StormSlotListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2StormSlotListStrc()
    {
        UnlinkAll();
    }
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
    D2StormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void LinkToTail(char* pNode)
    {
        D2StormSlotLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormSlotLinkStrc* pExistingLink = Link(0);
        D2StormSlotLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
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
    void sub_006C4290(char* pNode)
    {
        Link(pNode)->Unlink();
    }
    void UnlinkAll();                                       // 0x00602640
    char* sub_00602260_RawNext(char* pNode);
    void sub_006026E0_ChangeLinkOffset(int nLinkOffset);
};

struct D2StormNodeListStrc
{
    int m_linkoffset;                                       // 0x00
    D2StormLinkStrc m_terminator;                           // 0x04

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
    D2StormNodeStrc* Head()
    {
        return (int)m_terminator.m_next > 0 ? (D2StormNodeStrc*)m_terminator.m_next : 0;
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
    D2StormLinkStrc* sub_00601FA0_Link(D2StormNodeStrc* pNode);
    void sub_00601FC0_LinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode);      // 0x00601FC0
    char* sub_00602070_Next(D2StormNodeStrc* pNode);
    void sub_00602190_UnlinkNode(D2StormNodeStrc* pNode);
    void sub_00602BF0_DeleteAll();                                                                          // 0x00602BF0
    D2CelEntryStrc* sub_006029B0_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    D2CelEntryStrc* sub_00602C40_DeleteNode(D2CelEntryStrc* pNode);
};

struct D2StormListEStrc
{
    int m_linkoffset;                                       // 0x00
    D2StormLinkStrc m_terminator;                           // 0x04

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
// build: symbol ?UnlinkAll@D2StormListEStrc@@QAEXXZ 0x00602690
    void UnlinkAll();
    D2StormLinkStrc* sub_00602110_Link(char* pNode);
    D2StormLinkStrc* sub_00602280_Link(char* pNode);
    void sub_006022A0_UnlinkNode(char* pNode);
    void sub_006022F0_InitLinkField(int nLinkOffset);
    char* sub_00602310_Next(char* pNode);
    void sub_00602350_InitLinkField(int nLinkOffset);
    void sub_006024E0_LinkNode(char* pNode, int nLinkType, char* pExistingNode);                            // 0x006024E0
    void sub_00602590_UnlinkNode(char* pNode);
    void sub_00602D20_DeleteAll();                                                                          // 0x00602D20
    char* sub_00602E30_DeleteNode(char* pNode);
    D2StormEntry38Strc* sub_006035A0_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    void sub_00603B60_DeleteAll();                                                                          // 0x00603B60
    void sub_00603F50_CopyLinkOffset(const D2StormListEStrc* pSource);
    void sub_00603FC0_LinkNode(char* pNode, int nLinkType, char* pExistingNode);                            // 0x00603FC0
    D2StormHashChunkStrc* sub_00604490_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    void sub_0060E370_CopyLinkOffset(const D2StormListEStrc* pSource);
    void sub_0060E390_CopyLinkOffset(const D2StormListEStrc* pSource);
};

struct D2StormListAStrc
{
    int m_linkoffset;                                       // 0x00
    D2StormLinkStrc m_terminator;                           // 0x04

    ~D2StormListAStrc();
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
    void UnlinkAll();
};

struct D2StormSlotArrayStrc
{
    unsigned int f_0;                                       // 0x00
    unsigned int f_4;                                       // 0x04
    D2StormSlotListStrc* f_8;                               // 0x08
    unsigned int f_C;                                       // 0x0C

    D2StormSlotArrayStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
    ~D2StormSlotArrayStrc() throw();                                                                        // 0x00603060
    void Clear()
    {
        this->~D2StormSlotArrayStrc();
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
    }
    unsigned int sub_00601E20_CalcChunkSize(unsigned int nCount);
    void sub_00602F10_ReallocData(unsigned int nAlloc);                                                     // 0x00602F10
    void sub_006031F0_Reserve(unsigned int nCount, int bRound);
    void sub_00603300_SetCount(unsigned int nCount);                                                        // 0x00603300
    void sub_00603760_Clear();
    void sub_00603850_SetCount(unsigned int nCount);
};

struct D2StormSlotGrowArrayStrc
{
    D2StormSlotArrayStrc m_array;                           // 0x00

// build: symbol ??1D2StormSlotGrowArrayStrc@@QAE@XZ 0x00603240
    ~D2StormSlotGrowArrayStrc() throw();
};

struct D2StormEntryArrayStrc
{
    unsigned int f_0;                                       // 0x00
    unsigned int f_4;                                       // 0x04
    D2StormEntry38Strc* f_8;                                // 0x08
    unsigned int f_C;                                       // 0x0C

    D2StormEntryArrayStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
    ~D2StormEntryArrayStrc();                                                                               // 0x00603140
    unsigned int sub_00603EE0_CalcChunkSize(unsigned int nCount);
    void sub_006041B0_ReallocData(unsigned int nAlloc);                                                     // 0x006041B0
    void sub_00604350_Reserve(unsigned int nCount, int bRound);
    void sub_00604440_Grow(unsigned int nCount);
};
