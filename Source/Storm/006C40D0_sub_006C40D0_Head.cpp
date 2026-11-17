struct sub_006C40D0_Link
{
    sub_006C40D0_Link* m_prevlink;
    char* m_next;
};

// 0x006C40D0
char* __fastcall sub_006C40D0_Head(sub_006C40D0_Link* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}
