struct TSLink
{
    TSLink* m_prevlink;
    void* m_next;

    TSLink* NextLink(int nLinkOffset);  // 0x005174C0
    void Unlink();
};

// 0x005174E2
void TSLink::Unlink()
{
    TSLink* pPrev = m_prevlink;
    if (pPrev)
    {
        NextLink(-1)->m_prevlink = pPrev;
        m_prevlink->m_next = m_next;
        m_prevlink = 0;
        m_next = 0;
    }
}
