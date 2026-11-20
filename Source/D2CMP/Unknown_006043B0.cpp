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


struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00602D20_DeleteAll();                                                                          // 0x00602D20
    void sub_00603B60_DeleteAll();                                                                          // 0x00603B60
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
    void sub_00602800_InternalClear(int bWarn);                                                             // 0x00602800
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

// build: symbol ?Destroy@D2GameHashTableReuseStrc@@UAEXXZ 0x006046E0
void D2GameHashTableReuseStrc::Destroy()
{
    sub_00602800_InternalClear(0);
    m_chunkList.sub_00603B60_DeleteAll();
    m_reuseList.sub_00602D20_DeleteAll();
}
