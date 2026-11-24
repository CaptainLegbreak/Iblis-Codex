#include "D2StormLink.h"
struct D2StormEntry38Strc;
struct D2StormSlotListStrc;
struct D2StormEntryArray604080Strc;
struct D2StormEntryLink604080Strc;
struct D2StormEntryList604080Strc;
struct D2StormEntry604080Strc;
struct D2StormEntryGrowArray604460Strc;
struct D2StormLinkStrc;
struct D2StormListEStrc;
struct D2GameHashTableStrc;
struct D2GameHashTableReuseStrc;

struct D2StormEntryArray604080Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;
    unsigned int m_chunk;

    D2StormEntryArray604080Strc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
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
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormEntry604080Strc* m_data;
    unsigned int m_chunk;

    unsigned int CelListArrayCalcChunkSize(unsigned int nCount);                                           // 0x00603EE0
    void sub_006041B0_ReallocData(unsigned int nAlloc);                                                     // 0x006041B0
    D2StormEntry604080Strc* sub_006043B0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};


struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void CelReuseListDeleteAll();                                                                          // 0x00602D20
    void CelChunkListDeleteAll();                                                                          // 0x00603B60
};

struct D2GameHashTableStrc
{
    int unk0x04[3];
    unsigned int m_fullnessIndicator;
    int unk0x14[4];
    unsigned int m_slotmask;

    virtual void InternalDelete(D2StormEntry38Strc* pNode);
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2GameHashTableStrc();                                                                         // 0x00603460
    virtual void Destroy();
    void CelListTableInternalClear(int bWarn);                                                             // 0x00602800
};

struct D2GameHashTableReuseStrc : D2GameHashTableStrc
{
    D2StormListEStrc m_reuseList;
    int unk0x34;
    D2StormListEStrc m_chunkList;

    virtual void InternalDelete(D2StormEntry38Strc* pNode);
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2GameHashTableReuseStrc();                                                                    // 0x00604640
    virtual void Destroy();
};


inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormEntryGrowArray604460Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : CelListArrayCalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_006041B0_ReallocData(nCount);
    }
}

// 0x006043B0
D2StormEntry604080Strc* D2StormEntryGrowArray604460Strc::sub_006043B0_New()
{
    ReserveInline(1, 1);
    new (&m_data[m_count]) D2StormEntry604080Strc;
    return &m_data[m_count++];
}

// build: symbol ?Destroy@D2GameHashTableReuseStrc@@UAEXXZ 0x006046E0
void D2GameHashTableReuseStrc::Destroy()
{
    CelListTableInternalClear(0);
    m_chunkList.CelChunkListDeleteAll();
    m_reuseList.CelReuseListDeleteAll();
}
