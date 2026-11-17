struct TSLink006C4290
{
    TSLink006C4290* m_prevlink;
    int m_next;

    __forceinline TSLink006C4290* NextLink(int linkoffset)
    {
        if (m_next < 0)
            return (TSLink006C4290*)~m_next;
        if (linkoffset < 0)
            linkoffset = (int)this - m_prevlink->m_next;
        return (TSLink006C4290*)(m_next + linkoffset);
    }

    __forceinline void Unlink()
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

struct TSList006C4290
{
    int m_linkoffset;
    TSLink006C4290 m_terminator;

    void sub_006C4290(TSLink006C4290* link);
};

// 0x006C4290
void TSList006C4290::sub_006C4290(TSLink006C4290* link)
{
    if (!link)
        link = &m_terminator;
    link->Unlink();
}
