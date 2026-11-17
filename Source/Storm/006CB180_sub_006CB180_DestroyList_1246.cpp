// build: context ??_GD2StormList0070836CStrc@@QAEPAXI@Z
struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

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

struct D2StormList0070836CStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList0070836CStrc()
    {
        sub_00418980_UnlinkAll();
    }
    void sub_00418980_UnlinkAll(); // 0x00418980
};
extern D2StormList0070836CStrc gList_0070836C; // 0x0070836C

// 0x006CB180
void __cdecl sub_006CB180_DestroyList()
{
    gList_0070836C.~D2StormList0070836CStrc();
}
