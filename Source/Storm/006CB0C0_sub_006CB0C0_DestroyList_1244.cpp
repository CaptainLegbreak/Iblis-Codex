// build: context ??_GD2StormList00708354Strc@@QAEPAXI@Z
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

struct D2StormList00708354Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708354Strc()
    {
        sub_00418900_UnlinkAll();
    }
    void sub_00418900_UnlinkAll(); // 0x00418900
};
extern D2StormList00708354Strc gArchiveList_00708354; // 0x00708354

// 0x006CB0C0
void __cdecl sub_006CB0C0_DestroyList()
{
    gArchiveList_00708354.~D2StormList00708354Strc();
}
