inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemAlloc(unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szLogFileName, int nLogLine, unsigned int nFlags);       // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x004133D0

extern const char gszTypeSGameData_0070F56C[];                                                              // 0x0070F56C
extern const char gszTypeExplicitList_0070F584[];                                                           // 0x0070F584
extern const char gszTypeHashObjectChunk_0070F5F4[];                                                        // 0x0070F5F4

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
};

struct D2SGameDataStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    char unk0x14[0x1DE0];

    D2SGameDataStrc()
    {
    }
    ~D2SGameDataStrc();                                                                                     // 0x0044F820
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListAStrc(const D2StormListAStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    D2SGameDataStrc* HeadNode()
    {
        return (int)m_terminator.m_next > 0 ? (D2SGameDataStrc*)m_terminator.m_next : 0;
    }
    // build: context D2StormListAStrc::LinkNode
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        if (pLink->m_prevlink)
            pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExisting);
        if (nLinkType == 1)
        {
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
        }
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
    void sub_0044FC60_DeleteAll();
};

struct D2StormListArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;

    void sub_0044FE10_ReallocData(unsigned int nAlloc);
};

struct D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;
};

struct D2StormHashTableReuseStrc : D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2StormGameDataArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2SGameDataStrc* f_8;
    unsigned int f_C;
};

struct D2StormHashObjectChunkStrc
{
    D2StormGameDataArrayStrc m_array;
    D2StormLinkStrc f_10;
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormHashObjectChunkStrc* HeadChunk()
    {
        return (int)m_terminator.m_next > 0 ? (D2StormHashObjectChunkStrc*)m_terminator.m_next : 0;
    }
    void sub_00450580_DeleteAll();
};

// 0x0044FC60
void D2StormListAStrc::sub_0044FC60_DeleteAll()
{
    D2SGameDataStrc* pNode;
    while ((pNode = HeadNode()) != 0)
    {
        pNode->f_C.Unlink();
        pNode->m_linktoslot.Unlink();
        SMemFree(pNode, gszTypeSGameData_0070F56C, -2, 0);
    }
}

// 0x0044FE10
void D2StormListArrayStrc::sub_0044FE10_ReallocData(unsigned int nAlloc)
{
    D2StormListAStrc* pOld = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOld[i].~D2StormListAStrc();
    f_0 = nAlloc;
    void* pNew = SMemReAlloc(pOld, nAlloc * sizeof(D2StormListAStrc), gszTypeExplicitList_0070F584, -2, 0x10);
    f_8 = (D2StormListAStrc*)pNew;
    if (!pNew)
    {
        f_8 = (D2StormListAStrc*)SMemAlloc(nAlloc * sizeof(D2StormListAStrc), gszTypeExplicitList_0070F584, -2, 0);
        if (pOld)
        {
            unsigned int nCopy = nAlloc >= f_4 ? f_4 : nAlloc;
            for (unsigned int i = 0; i < nCopy; i++)
            {
                new (&f_8[i]) D2StormListAStrc(pOld[i]);
                pOld[i].~D2StormListAStrc();
            }
            SMemFree(pOld, gszTypeExplicitList_0070F584, -2, 0);
        }
    }
}

// build: symbol ?InternalDelete@D2StormHashTableStrc@@UAEXPAUD2SGameDataStrc@@@Z 0x004503F0
void D2StormHashTableStrc::InternalDelete(D2SGameDataStrc* pNode)
{
    pNode->~D2SGameDataStrc();
    SMemFree(pNode, gszTypeSGameData_0070F56C, -2, 0);
}

// build: symbol ?InternalNew@D2StormHashTableStrc@@UAEPAUD2SGameDataStrc@@PAUD2StormListAStrc@@II@Z 0x00450420
D2SGameDataStrc* D2StormHashTableStrc::InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2SGameDataStrc) + nExtraBytes, gszTypeSGameData_0070F56C, -2, nFlags | 8);
    D2SGameDataStrc* pNode = new (pMemory) D2SGameDataStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// 0x00450580
void D2StormChunkListStrc::sub_00450580_DeleteAll()
{
    D2StormHashObjectChunkStrc* pChunk;
    while ((pChunk = HeadChunk()) != 0)
    {
        pChunk->f_10.Unlink();
        for (unsigned int i = 0; i < pChunk->m_array.f_4; i++)
        {
            D2SGameDataStrc* pNode = &pChunk->m_array.f_8[i];
            pNode->f_C.Unlink();
            pNode->m_linktoslot.Unlink();
        }
        if (pChunk->m_array.f_8)
            SMemFree(pChunk->m_array.f_8, gszTypeSGameData_0070F56C, -2, 0);
        SMemFree(pChunk, gszTypeHashObjectChunk_0070F5F4, -2, 0);
    }
}

// build: symbol ?InternalDelete@D2StormHashTableReuseStrc@@UAEXPAUD2SGameDataStrc@@@Z 0x00450D60
void D2StormHashTableReuseStrc::InternalDelete(D2SGameDataStrc* pNode)
{
    pNode->~D2SGameDataStrc();
    SMemFree(pNode, gszTypeSGameData_0070F56C, -2, 0);
}

// build: symbol ?InternalNew@D2StormHashTableReuseStrc@@UAEPAUD2SGameDataStrc@@PAUD2StormListAStrc@@II@Z 0x00451000
D2SGameDataStrc* D2StormHashTableReuseStrc::InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2SGameDataStrc) + nExtraBytes, gszTypeSGameData_0070F56C, -2, nFlags | 8);
    D2SGameDataStrc* pNode = new (pMemory) D2SGameDataStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

#include "gen/data/Source/D2Client/0044FC60_sub_0044FC60_DeleteAll.inc"
