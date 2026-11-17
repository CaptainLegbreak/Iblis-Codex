struct sub_006C4160_LinkStrc
{
    sub_006C4160_LinkStrc* m_prevlink;
    char* m_next;
};

struct sub_006C4160_List
{
    int m_linkoffset;
    sub_006C4160_LinkStrc m_terminator;

    sub_006C4160_LinkStrc* sub_006C4160_Link(sub_006C4160_LinkStrc* pLink);
};

// 0x006C4160
sub_006C4160_LinkStrc* sub_006C4160_List::sub_006C4160_Link(sub_006C4160_LinkStrc* pLink)
{
    return pLink ? pLink : &m_terminator;
}
