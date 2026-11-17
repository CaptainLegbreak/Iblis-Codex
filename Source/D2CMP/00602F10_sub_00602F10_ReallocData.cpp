inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemAlloc(unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szLogFileName, int nLogLine, unsigned int nFlags);       // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x004133D0

extern "C" const char gszTypeNameCelSlotList[];                                                             // 0x00741F44

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2StormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormSlotLinkStrc()
    {
        Unlink();
    }
    D2StormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormSlotLinkStrc m_terminator;

    D2StormSlotListStrc(const D2StormSlotListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2StormSlotListStrc()
    {
        UnlinkAll();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void UnlinkAll();                                                                                       // 0x00602640
};

struct D2StormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    void sub_00602F10_ReallocData(unsigned int nAlloc);
};

// 0x00602F10
void D2StormSlotArrayStrc::sub_00602F10_ReallocData(unsigned int nAlloc)
{
    D2StormSlotListStrc* pOld = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOld[i].~D2StormSlotListStrc();
    f_0 = nAlloc;
    void* pNew = SMemReAlloc(pOld, nAlloc * sizeof(D2StormSlotListStrc), gszTypeNameCelSlotList, -2, 0x10);
    f_8 = (D2StormSlotListStrc*)pNew;
    if (!pNew)
    {
        f_8 = (D2StormSlotListStrc*)SMemAlloc(nAlloc * sizeof(D2StormSlotListStrc), gszTypeNameCelSlotList, -2, 0);
        if (pOld)
        {
            unsigned int nCopy = nAlloc >= f_4 ? f_4 : nAlloc;
            for (unsigned int i = 0; i < nCopy; i++)
            {
                new (&f_8[i]) D2StormSlotListStrc(pOld[i]);
                pOld[i].~D2StormSlotListStrc();
            }
            SMemFree(pOld, gszTypeNameCelSlotList, -2, 0);
        }
    }
}

#include "gen/data/Source/D2CMP/00602F10_sub_00602F10_ReallocData.inc"
