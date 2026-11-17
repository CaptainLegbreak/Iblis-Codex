struct sub_006C4010_Link
{
    sub_006C4010_Link* m_prevlink;
    char* m_next;
};

// 0x006C4010
char* __fastcall sub_006C4010_Head(sub_006C4010_Link* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}
