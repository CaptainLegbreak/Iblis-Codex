#ifdef MOVED_TEST
#define DEAD_MARKER 0xDDDDDDE1
#else
#define DEAD_MARKER 0xDDDDDDDD
#endif
inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct D2StormCtorLinkStrc
{
    D2StormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2StormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};
struct D2StormDeadListStrc
{
    int m_linkoffset;
#ifdef MOVED_TEST
    int movedPadding;
#endif
    D2StormCtorLinkStrc m_terminator;

    D2StormDeadListStrc()
    {
        m_linkoffset = DEAD_MARKER;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormDeadListStrc(const D2StormDeadListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};
// 0x0060F020
void __fastcall sub_0060F020_ConstructDeadList(D2StormDeadListStrc* pList) {
 new(pList) D2StormDeadListStrc;
}
