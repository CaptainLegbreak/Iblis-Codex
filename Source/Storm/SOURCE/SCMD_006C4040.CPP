struct TSLink006C4040
{
    TSLink006C4040* m_prevlink;
    int m_next;

    int NextLink(int linkoffset);
};

// 0x006C4040
int TSLink006C4040::NextLink(int linkoffset)
{
    if (m_next < 0)
        return ~m_next;
    if (linkoffset < 0)
        linkoffset = (int)this - m_prevlink->m_next;
    return m_next + linkoffset;
}
