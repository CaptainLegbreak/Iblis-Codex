#include "D2StormAutoLink.h"
struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void UnlinkAll();
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void UnlinkAll();
};

// build: symbol ?UnlinkAll@D2StormListAStrc@@QAEXXZ 0x0044F8E0
void D2StormListAStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

// build: symbol ?UnlinkAll@D2StormChunkListStrc@@QAEXXZ 0x0044F930
void D2StormChunkListStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}
