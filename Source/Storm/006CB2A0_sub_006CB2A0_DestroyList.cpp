// build: context ??_GD2StormList00708420Strc@@QAEPAXI@Z
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

struct D2StormList00708420Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708420Strc()
    {
        sub_0041C770_UnlinkAll();
    }
    void sub_0041C770_UnlinkAll(); // 0x0041C770
};
extern D2StormList00708420Strc gList_00708420; // 0x00708420

// 0x006CB2A0
void __cdecl sub_006CB2A0_DestroyList()
{
    gList_00708420.~D2StormList00708420Strc();
}
