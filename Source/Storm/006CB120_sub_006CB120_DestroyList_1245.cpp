// build: context ??_GD2StormList00708360Strc@@QAEPAXI@Z
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

struct D2StormList00708360Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708360Strc()
    {
        sub_00418940_UnlinkAll();
    }
    void sub_00418940_UnlinkAll(); // 0x00418940
};
extern D2StormList00708360Strc gRequestList_00708360; // 0x00708360

// 0x006CB120
void __cdecl sub_006CB120_DestroyList()
{
    gRequestList_00708360.~D2StormList00708360Strc();
}
