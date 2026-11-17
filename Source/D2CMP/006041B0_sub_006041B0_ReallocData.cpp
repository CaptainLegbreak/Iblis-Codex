inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

extern "C" const char gszTypeNameCelList[];                                                                 // 0x00741F2C

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

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormNodeListStrc(const D2StormNodeListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    ~D2StormNodeListStrc()
    {
        UnlinkAll();
    }
    void UnlinkAll();                                                                                       // 0x006025E0
};

struct D2StormHashObjectStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    int f_14;

    D2StormHashObjectStrc()
    {
    }
    ~D2StormHashObjectStrc();                                                                               // 0x00602430
};

struct D2StormEntry38Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeListStrc tList;

    D2StormEntry38Strc(const D2StormEntry38Strc& source)
        : dwFlags(source.dwFlags), nType(source.nType), nData(source.nData), nCount(source.nCount),
          nDirections(source.nDirections), tList(source.tList)
    {
    }
};

struct D2StormEntryArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormEntry38Strc* f_8;
    unsigned int f_C;

    void sub_006041B0_ReallocData(unsigned int nAlloc);
};

// 0x006041B0
void D2StormEntryArrayStrc::sub_006041B0_ReallocData(unsigned int nAlloc)
{
    D2StormEntry38Strc* pOldData = f_8;
    for (unsigned int i = nAlloc; i < f_4; ++i)
    {
        pOldData[i].~D2StormEntry38Strc();
    }

    f_0 = nAlloc;
    f_8 = (D2StormEntry38Strc*)SMemReAlloc(pOldData, nAlloc * sizeof(D2StormEntry38Strc), gszTypeNameCelList, -2, 0x10);
    if (!f_8)
    {
        f_8 = (D2StormEntry38Strc*)SMemAlloc(nAlloc * sizeof(D2StormEntry38Strc), gszTypeNameCelList, -2, 0);
        if (pOldData)
        {
            const unsigned int nCopy = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCopy; ++i)
            {
                new (&f_8[i]) D2StormEntry38Strc(pOldData[i]);
                pOldData[i].~D2StormEntry38Strc();
            }
            SMemFree(pOldData, gszTypeNameCelList, -2, 0);
        }
    }
}
