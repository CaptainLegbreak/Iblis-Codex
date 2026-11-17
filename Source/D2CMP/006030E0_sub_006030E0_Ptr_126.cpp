extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    char* Next()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
};

struct D2StormListArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;
};

struct D2StormHashNodeStrc
{
    unsigned int f_0;
};

struct D2StormHashTable006030E0Strc
{
    void* m_vtable;
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    char* sub_006030E0_Ptr(unsigned int nHashVal, int nKey);
};

// 0x006030E0
char* D2StormHashTable006030E0Strc::sub_006030E0_Ptr(unsigned int nHashVal, int nKey)
{
    for (char* pNode = m_slotlistarray.f_8[nHashVal & m_slotmask].Head(); _ReadWriteBarrier(), (int)pNode > 0; pNode = m_slotlistarray.f_8[nHashVal & m_slotmask].RawNext(pNode))
    {
        if (((D2StormHashNodeStrc*)pNode)->f_0 == nHashVal)
        {
            return pNode;
        }
    }
    return 0;
}
