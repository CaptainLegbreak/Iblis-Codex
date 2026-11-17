struct sub_006C4230_LinkStrc
{
    sub_006C4230_LinkStrc* m_prevlink;
    char* m_next;
};

struct sub_006C4230_List
{
    int m_linkoffset;
    sub_006C4230_LinkStrc m_terminator;

    char* sub_006C4230_Next(sub_006C4230_LinkStrc* pLink);
};

// 0x006C4230
char* sub_006C4230_List::sub_006C4230_Next(sub_006C4230_LinkStrc* pLink)
{
    sub_006C4230_LinkStrc* pCurrent = pLink ? pLink : &m_terminator;
    return (int)pCurrent->m_next > 0 ? pCurrent->m_next : 0;
}
