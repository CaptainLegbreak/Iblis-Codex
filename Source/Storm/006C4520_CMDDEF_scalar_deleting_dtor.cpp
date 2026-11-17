int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

extern "C" const char gszDelete[]; // 0x006CC824

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

struct CMDDEF
{
    D2StormLinkStrc m_link;
    int nData;

    static void operator delete(void* pMemory);
};

// build: symbol ??_GCMDDEF@@* 0x006C4520
inline void CMDDEF::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, gszDelete, -1, 0);
}

struct CMDDEFList
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    CMDDEF* Head()
    {
        return (int)m_terminator.m_next <= 0 ? 0 : (CMDDEF*)m_terminator.m_next;
    }
};

// build: context sub_Emit_CMDDEF
void sub_Emit_CMDDEF(CMDDEFList* pList)
{
    CMDDEF* p;
    while ((p = pList->Head()) != 0)
        delete p;
}
