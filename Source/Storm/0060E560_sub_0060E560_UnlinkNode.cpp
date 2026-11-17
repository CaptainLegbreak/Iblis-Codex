inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0
char* __stdcall sub_00414310(const char* szString);                                                             // 0x00414310

extern "C" const char gszTypeNameMappingEntryNode_0074362C[];                                               // 0x0074362C
extern "C" const char gszTypeNameStringEntryNode_0074364C[];                                                // 0x0074364C
extern "C" const char gszTypeNameStringEntryList_0074366C[];                                                // 0x0074366C
extern "C" const char gszTypeNameMappingEntryList_007436AC[];                                               // 0x007436AC

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
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

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2CommonStormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2CommonStormSlotLinkStrc()
    {
        Unlink();
    }
    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormHashKeyStrIStrc
{
    char* m_str;

    D2StormHashKeyStrIStrc()
    {
        m_str = 0;
    }
    D2StormHashKeyStrIStrc& operator=(const D2StormHashKeyStrIStrc& source)
    {
        if (m_str)
            SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E9, 0);
        m_str = sub_00414310(source.m_str);
        return *this;
    }
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    D2StormHashKeyStrIStrc f_14;

    ~D2CommonStringEntryNodeStrc();                                                                         // 0x0060EAE0
    static void operator delete(void* pMemory);
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    D2StormHashKeyStrIStrc f_14;

    ~D2CommonMappingEntryNodeBaseStrc();                                                                    // 0x0060EA10
};

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    void* pMapped;

    D2CommonMappingEntryNodeStrc()
    {
        pMapped = 0;
    }
    ~D2CommonMappingEntryNodeStrc()
    {
        if (pMapped)
            SMemFree(pMapped, ".\\Chat\\Ignorelist.cpp", 0x11, 0);
    }
    static void operator delete(void* pMemory);
};

struct D2CommonStormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
// build: symbol ?UnlinkAll@D2CommonStormSlotListAStrc@@QAEXXZ 0x0060E820
    void UnlinkAll();
    void sub_0060E490_LinkNode(char* pNode, int nLinkType, char* pExistingNode);                            // 0x0060E490
    void sub_0060E560_UnlinkNode(char* pNode);
    char* sub_0060F270_DeleteNode(D2CommonStringEntryNodeStrc* pNode);
    D2CommonStringEntryNodeStrc* sub_0060FE90_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2CommonStormListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
// build: symbol ?UnlinkAll@D2CommonStormSlotListBStrc@@QAEXXZ 0x0060ECB0
    void UnlinkAll();
    void sub_0060E960_UnlinkNode(char* pNode);
    char* sub_0060EF60_DeleteNode(D2CommonMappingEntryNodeStrc* pNode);
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormSlotListAStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    D2CommonStormSlotListAStrc(const D2CommonStormSlotListAStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2CommonStormSlotListAStrc()
    {
        UnlinkAll();
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Next(char* pNode)
    {
        return Link(pNode)->Next();
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
    void UnlinkAll();
    static void operator delete(void* pMemory);
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormSlotListBStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    D2CommonStormSlotListBStrc(const D2CommonStormSlotListBStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2CommonStormSlotListBStrc()
    {
        UnlinkAll();
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Next(char* pNode)
    {
        return Link(pNode)->Next();
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
    void UnlinkAll();
    static void operator delete(void* pMemory);
};

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;

    void sub_0060F390_ReallocData(unsigned int nAlloc);
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;

    void sub_0060F720_ReallocData(unsigned int nAlloc);
};

// build: symbol ??_GD2CommonMappingEntryNodeStrc@@QAEPAXI@Z 0x0060EDF0
// build: symbol ??_GD2CommonStormSlotListAStrc@@QAEPAXI@Z 0x0060EFC0
// build: symbol ??_GD2CommonStormSlotListBStrc@@QAEPAXI@Z 0x0060F300
// build: symbol ??_GD2CommonStringEntryNodeStrc@@QAEPAXI@Z 0x0060F160
// 0x0060E560
void D2CommonStormListAStrc::sub_0060E560_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0060E960
void D2CommonStormListBStrc::sub_0060E960_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0060EDF0
inline void D2CommonMappingEntryNodeStrc::operator delete(void* pMemory)
{
    SMemFree(pMemory, "delete", -1, 0);
}

// 0x0060EF60
char* D2CommonStormListBStrc::sub_0060EF60_DeleteNode(D2CommonMappingEntryNodeStrc* pNode)
{
    char* pNext = Link((char*)pNode)->Next();
    pNode->~D2CommonMappingEntryNodeStrc();
    SMemFree(pNode, gszTypeNameMappingEntryNode_0074362C, -2, 0);
    return pNext;
}

// 0x0060EFC0
inline void D2CommonStormSlotListAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0060F160
inline void D2CommonStringEntryNodeStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0060F270
char* D2CommonStormListAStrc::sub_0060F270_DeleteNode(D2CommonStringEntryNodeStrc* pNode)
{
    char* pNext = Link((char*)pNode)->Next();
    pNode->~D2CommonStringEntryNodeStrc();
    SMemFree(pNode, gszTypeNameStringEntryNode_0074364C, -2, 0);
    return pNext;
}

// 0x0060F300
inline void D2CommonStormSlotListBStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0060F390
void D2CommonStormSlotArrayAStrc::sub_0060F390_ReallocData(unsigned int nAlloc)
{
    D2CommonStormSlotListAStrc* pOldData = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOldData[i].~D2CommonStormSlotListAStrc();
    f_0 = nAlloc;
    f_8 = (D2CommonStormSlotListAStrc*)SMemReAlloc(pOldData, nAlloc * sizeof(D2CommonStormSlotListAStrc), gszTypeNameStringEntryList_0074366C, -2, 0x10);
    if (!f_8)
    {
        f_8 = (D2CommonStormSlotListAStrc*)SMemAlloc(nAlloc * sizeof(D2CommonStormSlotListAStrc), gszTypeNameStringEntryList_0074366C, -2, 0);
        if (pOldData)
        {
            unsigned int nCount = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCount; i++)
            {
                new (&f_8[i]) D2CommonStormSlotListAStrc(pOldData[i]);
                pOldData[i].~D2CommonStormSlotListAStrc();
            }
            SMemFree(pOldData, gszTypeNameStringEntryList_0074366C, -2, 0);
        }
    }
}

// 0x0060F720
void D2CommonStormSlotArrayBStrc::sub_0060F720_ReallocData(unsigned int nAlloc)
{
    D2CommonStormSlotListBStrc* pOldData = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOldData[i].~D2CommonStormSlotListBStrc();
    f_0 = nAlloc;
    f_8 = (D2CommonStormSlotListBStrc*)SMemReAlloc(pOldData, nAlloc * sizeof(D2CommonStormSlotListBStrc), gszTypeNameMappingEntryList_007436AC, -2, 0x10);
    if (!f_8)
    {
        f_8 = (D2CommonStormSlotListBStrc*)SMemAlloc(nAlloc * sizeof(D2CommonStormSlotListBStrc), gszTypeNameMappingEntryList_007436AC, -2, 0);
        if (pOldData)
        {
            unsigned int nCount = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCount; i++)
            {
                new (&f_8[i]) D2CommonStormSlotListBStrc(pOldData[i]);
                pOldData[i].~D2CommonStormSlotListBStrc();
            }
            SMemFree(pOldData, gszTypeNameMappingEntryList_007436AC, -2, 0);
        }
    }
}

// 0x0060FE90
D2CommonStringEntryNodeStrc* D2CommonStormListAStrc::sub_0060FE90_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    D2CommonStringEntryNodeStrc* pNode = new (SMemAlloc(sizeof(D2CommonStringEntryNodeStrc) + nExtraBytes, gszTypeNameStringEntryNode_0074364C, -2, nFlags | 8)) D2CommonStringEntryNodeStrc;
    if (nLinkType)
        sub_0060E490_LinkNode((char*)pNode, nLinkType, 0);
    return pNode;
}

void sub_F44_EmitMappingEntryNode(D2CommonMappingEntryNodeStrc* p)
{
    delete p;
}

void sub_F44_EmitStringEntryNode(D2CommonStringEntryNodeStrc* p)
{
    delete p;
}

// build: context sub_F44_EmitSlotListA
void sub_F44_EmitSlotListA(D2CommonStormSlotListAStrc* p)
{
    delete p;
}

// build: context sub_F44_EmitSlotListB
void sub_F44_EmitSlotListB(D2CommonStormSlotListBStrc* p)
{
    delete p;
}

#include "gen/data/Source/Storm/0060E560_sub_0060E560_UnlinkNode.inc"
