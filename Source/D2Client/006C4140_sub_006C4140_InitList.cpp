struct sub_006C4140_Link
{
    sub_006C4140_Link* m_prevlink;
    char* m_next;
};

struct sub_006C4140_List
{
    int m_linkoffset;
    sub_006C4140_Link m_terminator;
};

// 0x006C4140
void __fastcall sub_006C4140_InitList(sub_006C4140_List* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_linkoffset = 0;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}
