struct D2GameStrc
{
    unsigned int f_0;
};

struct HASHKEY_NONE
{
    int nUnused;
};

struct D2GameHashLinkStrc
{
    D2GameHashLinkStrc* m_prevlink;
    D2GameStrc* m_next;

    D2GameHashLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
        {
            return (D2GameHashLinkStrc*)~(int)m_next;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (char*)this - (char*)m_prevlink->m_next;
        }
        return (D2GameHashLinkStrc*)((char*)m_next + nLinkOffset);
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

struct D2GameHashListStrc
{
    int m_linkoffset;
    D2GameHashLinkStrc m_terminator;
};

struct D2GameDataTableStrc
{
    virtual void sub_Destroy();
    virtual D2GameStrc* sub_NewNode(D2GameHashListStrc* pList, int nExtraBytes, int nFlags);

    int m_linkoffset;
    D2GameHashLinkStrc m_terminator;
    unsigned int m_fullnessIndicator;
    unsigned int f_14;
    unsigned int f_18;
    D2GameHashListStrc* m_slotlistarray;
    unsigned int f_20;
    unsigned int m_hashmask;

    int sub_00530600(unsigned int nSlot);                                                   // 0x00530600
    D2GameStrc* sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags);
};

// 0x00530820
D2GameStrc* D2GameDataTableStrc::sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags)
{
    unsigned int nSlot = nHashVal & m_hashmask;
    if (sub_00530600(nSlot))
    {
        nSlot = nHashVal & m_hashmask;
    }

    D2GameHashListStrc* pList = &m_slotlistarray[nSlot];
    D2GameStrc* pNode = sub_NewNode(pList, nExtraBytes, nFlags);

    D2GameHashLinkStrc* pLink;
    if (pNode)
    {
        pLink = (D2GameHashLinkStrc*)((char*)pNode + m_linkoffset);
    }
    else
    {
        pLink = &m_terminator;
    }

    pLink->Unlink();

    D2GameHashLinkStrc* pPrev = m_terminator.m_prevlink;
    pLink->m_prevlink = pPrev;
    pLink->m_next = pPrev->m_next;
    pPrev->m_next = pNode;
    m_terminator.m_prevlink = pLink;

    pNode->f_0 = nHashVal;
    return pNode;
}
