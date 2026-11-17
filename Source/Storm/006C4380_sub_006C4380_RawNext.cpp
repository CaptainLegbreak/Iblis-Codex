struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_006C4380_RawNext(D2StormLinkStrc* pNode);
};

// 0x006C4380
char* D2StormListAStrc::sub_006C4380_RawNext(D2StormLinkStrc* pNode)
{
    return pNode ? pNode->m_next : m_terminator.m_next;
}
