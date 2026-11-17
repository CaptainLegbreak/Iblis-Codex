// build: context D2CommonStormSlotListAStrc::LinkNode
// build: context D2CommonStormSlotListBStrc::LinkNode

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
char* __stdcall sub_00414310(const char* szString);                                                             // 0x00414310

extern "C" const char gszTypeNameMappingEntryNode_0074362C[];                                               // 0x0074362C
extern "C" const char gszTypeNameStringEntryNode_0074364C[];                                                // 0x0074364C

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
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExistingNode);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExistingNode);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
};

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayAStrc();                                                                         // 0x0060F610
    D2CommonStormSlotListAStrc& operator[](unsigned int nIndex)
    {
        return f_8[nIndex];
    }
    static void operator delete(void* pMemory);
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayBStrc();                                                                         // 0x0060F950
    D2CommonStormSlotListBStrc& operator[](unsigned int nIndex)
    {
        return f_8[nIndex];
    }
    static void operator delete(void* pMemory);
};

struct StringEntryNode;
struct MappingEntryNode;
class HASHKEY_STRI;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>;
typedef TSHashTable<StringEntryNode, HASHKEY_STRI> D2CommonStormHashTableAStrc;
template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>;
typedef TSHashTable<MappingEntryNode, HASHKEY_STRI> D2CommonStormHashTableBStrc;
class IgnoreList;
typedef IgnoreList D2CommonIgnoreListStrc;
// build: symbol ??1?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x0060FD90
// build: symbol ??1?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x00610550

template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>
{
public:
    explicit TSHashTable(int nEmitTag)
    {
    }
    virtual void sub_0060FFA0_InternalDelete(D2CommonStringEntryNodeStrc* pNode);
    virtual D2CommonStringEntryNodeStrc* sub_0060FEF0_InternalNew(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~TSHashTable();                                                                 // 0x0060FD90
    virtual void sub_00610020_VirtSlot3();                                                                  // 0x00610020
    static void operator delete(void* pMemory);

    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;

    int sub_00610840(unsigned int nSlot);                                                   // 0x00610840
    D2CommonStringEntryNodeStrc* sub_0060F8B0_Ptr(const char* szKey);                                       // 0x0060F8B0
    D2CommonStringEntryNodeStrc* sub_00610D60_New(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags); // 0x00610D60
    D2CommonStringEntryNodeStrc* sub_00610BE0_InternalNewNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags);
};

template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>
{
public:
    explicit TSHashTable(int nEmitTag)
    {
    }
    virtual void sub_00610690_InternalDelete(D2CommonMappingEntryNodeStrc* pNode);
    virtual D2CommonMappingEntryNodeStrc* sub_006106D0_InternalNew(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~TSHashTable();                                                                 // 0x00610550
    virtual void sub_006107D0_VirtSlot3();                                                                  // 0x006107D0
    static void operator delete(void* pMemory);

    D2CommonStormSlotListBStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;

    int sub_00610CA0(unsigned int nSlot);                                                   // 0x00610CA0
    D2CommonMappingEntryNodeStrc* sub_00610DF0_InternalNewNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags);
};

class IgnoreList
{
public:
    virtual int sub_00610EB0_Add(const char* szName);
    virtual void sub_0060FB20_VirtSlot1();                                                                  // 0x0060FB20
    virtual int sub_00610380_IsListed(const char* szName);
    virtual void sub_00610F90_VirtSlot3();                                                                  // 0x00610F90
    virtual void sub_0060FBE0_VirtSlot4();                                                                  // 0x0060FBE0
    virtual void sub_0060FC40_VirtSlot5();                                                                  // 0x0060FC40
    virtual void sub_00611320_VirtSlot6();                                                                  // 0x00611320
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize);                        // 0x0060F870
    virtual int sub_0060DDF0_IsEnabled();                                                                   // 0x0060DDF0
    virtual void sub_0060DE00_VirtSlot9();                                                                  // 0x0060DE00
    virtual void sub_0060F500_VirtSlot10();                                                                 // 0x0060F500
    virtual void sub_00610D30_VirtSlot11();                                                                 // 0x00610D30

    D2CommonStormHashTableAStrc m_table;

    void sub_0060DE30_Normalize(const char* szName, char* szOut, int nSize);                                // 0x0060DE30
    void sub_0060DEA0_NormalizeAlias(const char* szName, char* szOut, int nSize);                           // 0x0060DEA0
    void sub_0060DF10_OnAdded(const char* szKey);                                                           // 0x0060DF10
    void sub_0060DFF0_NormalizeKey(const char* szName, char* szOut, int nSize);                             // 0x0060DFF0
    int sub_0060FD50_Contains(const char* szKey);                                                           // 0x0060FD50
};

// build: symbol ??_G?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@UAEPAXI@Z 0x00610050
// build: symbol ??_G?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@UAEPAXI@Z 0x00610800
// build: symbol ??_GD2CommonStormSlotArrayAStrc@@QAEPAXI@Z 0x0060FFD0
// build: symbol ??_GD2CommonStormSlotArrayBStrc@@QAEPAXI@Z 0x00610780
// 0x0060FEF0
D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::sub_0060FEF0_InternalNew(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2CommonStringEntryNodeStrc) + nExtraBytes, gszTypeNameStringEntryNode_0074364C, -2, nFlags | 8);
    D2CommonStringEntryNodeStrc* pNode = new (pMemory) D2CommonStringEntryNodeStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// 0x0060FFA0
void D2CommonStormHashTableAStrc::sub_0060FFA0_InternalDelete(D2CommonStringEntryNodeStrc* pNode)
{
    pNode->~D2CommonStringEntryNodeStrc();
    SMemFree(pNode, gszTypeNameStringEntryNode_0074364C, -2, 0);
}

// 0x0060FFD0
inline void D2CommonStormSlotArrayAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00610050
inline void D2CommonStormHashTableAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00610380
int D2CommonIgnoreListStrc::sub_00610380_IsListed(const char* szName)
{
    if (!szName || !*szName || !sub_0060DDF0_IsEnabled())
        return 0;
    char szAlias[0x100] = "";
    char szNormalized[0x100] = "";
    sub_0060DE30_Normalize(szName, szNormalized, 0x100);
    sub_0060F870_Translate(szNormalized, szAlias, 0x100);
    if (!szAlias[0])
        sub_0060DEA0_NormalizeAlias(szName, szAlias, 0x100);
    if (szAlias[0] && sub_0060FD50_Contains(szAlias))
        return 1;
    if (szNormalized[0] && sub_0060FD50_Contains(szNormalized))
        return 1;
    return 0;
}

// 0x00610690
void D2CommonStormHashTableBStrc::sub_00610690_InternalDelete(D2CommonMappingEntryNodeStrc* pNode)
{
    pNode->~D2CommonMappingEntryNodeStrc();
    SMemFree(pNode, gszTypeNameMappingEntryNode_0074362C, -2, 0);
}

// 0x006106D0
D2CommonMappingEntryNodeStrc* D2CommonStormHashTableBStrc::sub_006106D0_InternalNew(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2CommonMappingEntryNodeStrc) + nExtraBytes, gszTypeNameMappingEntryNode_0074362C, -2, nFlags | 8);
    D2CommonMappingEntryNodeStrc* pNode = new (pMemory) D2CommonMappingEntryNodeStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// 0x00610780
inline void D2CommonStormSlotArrayBStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00610800
inline void D2CommonStormHashTableBStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00610BE0
D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::sub_00610BE0_InternalNewNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags)
{
    unsigned int nSlot = nHashVal & m_slotmask;
    if (sub_00610840(nSlot))
        nSlot = nHashVal & m_slotmask;
    D2CommonStringEntryNodeStrc* pNode = sub_0060FEF0_InternalNew(&m_slotlistarray[nSlot], nExtraBytes, nFlags);
    m_fulllist.LinkNode((char*)pNode, 2, 0);
    pNode->f_0 = nHashVal;
    pNode->f_14 = key;
    return pNode;
}

// 0x00610DF0
D2CommonMappingEntryNodeStrc* D2CommonStormHashTableBStrc::sub_00610DF0_InternalNewNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags)
{
    unsigned int nSlot = nHashVal & m_slotmask;
    if (sub_00610CA0(nSlot))
        nSlot = nHashVal & m_slotmask;
    D2CommonMappingEntryNodeStrc* pNode = sub_006106D0_InternalNew(&m_slotlistarray[nSlot], nExtraBytes, nFlags);
    m_fulllist.LinkNode((char*)pNode, 2, 0);
    pNode->f_0 = nHashVal;
    pNode->f_14 = key;
    return pNode;
}

// 0x00610EB0
int D2CommonIgnoreListStrc::sub_00610EB0_Add(const char* szName)
{
    if (!szName || !*szName || !sub_0060DDF0_IsEnabled())
        return 0;
    char szKey[0x100] = "";
    sub_0060DFF0_NormalizeKey(szName, szKey, 0x100);
    if (!szKey[0])
        return 0;
    if (!m_table.sub_0060F8B0_Ptr(szKey))
    {
        m_table.sub_00610D60_New(szKey, 0, 0);
        sub_0060DF10_OnAdded(szKey);
    }
    return 1;
}

void sub_F45_EmitHashTables(void* pTableA, void* pTableB)
{
    new (pTableA) D2CommonStormHashTableAStrc(0);
    new (pTableB) D2CommonStormHashTableBStrc(0);
}

void sub_F45_EmitSlotArrays(D2CommonStormSlotArrayAStrc* pArrayA, D2CommonStormSlotArrayBStrc* pArrayB)
{
    delete pArrayA;
    delete pArrayB;
}

#include "gen/data/Source/Storm/0060FEF0_sub_0060FEF0_InternalNew.inc"
