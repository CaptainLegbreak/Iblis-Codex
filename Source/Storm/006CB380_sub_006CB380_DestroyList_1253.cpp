// build: context ??_GD2StormList007088E8Strc@@QAEPAXI@Z
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

struct D2StormList007088E8Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList007088E8Strc()
    {
        sub_00426CF0_UnlinkAll();
    }
    void sub_00426CF0_UnlinkAll(); // 0x00426CF0
};
extern D2StormList007088E8Strc gList_007088E8; // 0x007088E8

// 0x006CB380
void __cdecl sub_006CB380_DestroyList()
{
    gList_007088E8.~D2StormList007088E8Strc();
}
