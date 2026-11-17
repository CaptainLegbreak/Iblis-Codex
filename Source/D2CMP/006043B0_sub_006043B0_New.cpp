inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct D2StormEntryArray604080Strc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

    D2StormEntryArray604080Strc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
};

struct D2StormEntryLink604080Strc
{
    D2StormEntryLink604080Strc* m_prevlink;
    char* m_next;

    D2StormEntryLink604080Strc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2StormEntryList604080Strc
{
    int m_linkoffset;
    D2StormEntryLink604080Strc m_terminator;

    D2StormEntryList604080Strc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2StormEntry604080Strc
{
    unsigned int unk0x00;
    D2StormEntryArray604080Strc tArray;
    unsigned int unk0x14;
    unsigned int nField18;
    unsigned int nField1C;
    unsigned int nField20;
    unsigned int nField24;
    unsigned int nField28;
    D2StormEntryList604080Strc tList;

    D2StormEntry604080Strc()
    {
    }
};

struct D2StormEntryGrowArray604460Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormEntry604080Strc* f_8;
    unsigned int f_C;

    unsigned int sub_00603EE0_CalcChunkSize(unsigned int nCount);                                           // 0x00603EE0
    void sub_006041B0_ReallocData(unsigned int nAlloc);                                                     // 0x006041B0
    D2StormEntry604080Strc* sub_006043B0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormEntryGrowArray604460Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_00603EE0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_006041B0_ReallocData(nCount);
    }
}

// 0x006043B0
D2StormEntry604080Strc* D2StormEntryGrowArray604460Strc::sub_006043B0_New()
{
    ReserveInline(1, 1);
    new (&f_8[f_4]) D2StormEntry604080Strc;
    return &f_8[f_4++];
}
