inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
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

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListAStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
};

struct D2StormListArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;
    unsigned int m_chunk;

    D2StormListArrayStrc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_0044DF30_CalcChunkSize(unsigned int nCount);                                           // 0x0044DF30
    void sub_0044FE10_ReallocData(unsigned int nAlloc);                                                     // 0x0044FE10
    void sub_00450040_Reserve(unsigned int nCount, int bRound);
    void sub_00450110_SetCount(unsigned int nCount);
};

struct D2StormArray2Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;
    unsigned int m_chunk;

    unsigned int sub_00450810_CalcChunkSize(unsigned int nCount);
};

struct SGAMEDATA;
class HASHKEY_NONE;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>;
typedef TSHashTable<SGAMEDATA, HASHKEY_NONE> D2StormHashTableStrc;
// build: symbol ??0?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x004506B0

template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(char* pNode);                                                               // 0x004503F0
    virtual void sub_00450420_VirtSlot1();                                                                  // 0x00450420
    virtual void sub_00450550_VirtSlot2();                                                                  // 0x00450550
    virtual void sub_00450520_VirtSlot3();                                                                  // 0x00450520
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable();
};

// build: symbol ??_7?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@6B@ 0x006D5E5C
// 0x00450040
void D2StormListArrayStrc::sub_00450040_Reserve(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0044DF30_CalcChunkSize(nCount);
            nCount = RoundUp(nCount, nChunk);
        }
        sub_0044FE10_ReallocData(nCount);
    }
}

// 0x00450110
void D2StormListArrayStrc::sub_00450110_SetCount(unsigned int nCount)
{
    if (nCount > m_count)
    {
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0044DF30_CalcChunkSize(nCount);
            sub_0044FE10_ReallocData(RoundUp(nCount, nChunk));
        }
        for (unsigned int i = m_count; i < nCount; i++)
            new (&m_data[i]) D2StormListAStrc;
    }
    else if (nCount < m_count)
    {
        for (unsigned int i = nCount; i < m_count; i++)
            m_data[i].~D2StormListAStrc();
    }
    m_count = nCount;
}

// 0x004506B0
D2StormHashTableStrc::TSHashTable()
{
    m_fullnessIndicator = 0;
    m_fulllist.ChangeLinkOffset(0xC);
    m_slotmask = 3;
    m_slotlistarray.sub_00450110_SetCount(4);
    for (unsigned int i = 0; i <= m_slotmask; i++)
        m_slotlistarray.m_data[i].ChangeLinkOffset(4);
}

// 0x00450810
unsigned int D2StormArray2Strc::sub_00450810_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 8)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    m_chunk = 8;
    return 8;
}

// 0x00450850
unsigned int __stdcall sub_00450850_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

