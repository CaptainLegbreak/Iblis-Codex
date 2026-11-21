struct TSLink006C4070
{
    TSLink006C4070* m_prevlink;
    int m_next;

    inline TSLink006C4070* NextLink(int linkoffset)
    {
        if (m_next < 0)
            return (TSLink006C4070*)~m_next;
        if (linkoffset < 0)
            linkoffset = (int)this - m_prevlink->m_next;
        return (TSLink006C4070*)(m_next + linkoffset);
    }

    void Unlink();
};

// 0x006C4070
void TSLink006C4070::Unlink()
{
    if (m_prevlink)
    {
        NextLink(-1)->m_prevlink = m_prevlink;
        m_prevlink->m_next = m_next;
        m_prevlink = 0;
        m_next = 0;
    }
}
