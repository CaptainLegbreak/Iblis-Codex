inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemAlloc(unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szLogFileName, int nLogLine, unsigned int nFlags);       // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x004133D0

extern const char gszTypeBreakCmd_007088D8[];                                                               // 0x007088D8
extern const char gszTypeSGameData_0070F56C[];                                                              // 0x0070F56C
extern const char gszTypeExplicitList_0070F584[];                                                           // 0x0070F584

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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
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

struct D2StormBreakCmdListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    char* sub_00426F20_DeleteNode(char* pNode);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
};

struct D2StormListFixedArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;

    ~D2StormListFixedArrayStrc();
};

struct D2SGameDataStrc
{
    char unk0x00[0x1DF4];

    D2SGameDataStrc(const D2SGameDataStrc& tSource);                                                        // 0x00450950
    ~D2SGameDataStrc();                                                                                     // 0x0044F820
};

struct D2StormGameDataArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2SGameDataStrc* f_8;
    unsigned int f_C;

    void sub_00450D90_ReallocData(unsigned int nAlloc);
};

// 0x00426F20
char* D2StormBreakCmdListStrc::sub_00426F20_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormLinkStrc*)pNode)->Unlink();
    SMemFree(pNode, gszTypeBreakCmd_007088D8, -2, 0);
    return pNext;
}

// 0x0044FF60
D2StormListFixedArrayStrc::~D2StormListFixedArrayStrc()
{
    for (unsigned int i = 0; i < f_4; i++)
        f_8[i].~D2StormListAStrc();
    if (f_8)
        SMemFree(f_8, gszTypeExplicitList_0070F584, -2, 0);
}

// 0x00450D90
void D2StormGameDataArrayStrc::sub_00450D90_ReallocData(unsigned int nAlloc)
{
    D2SGameDataStrc* pOld = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOld[i].~D2SGameDataStrc();
    f_0 = nAlloc;
    void* pNew = SMemReAlloc(pOld, nAlloc * sizeof(D2SGameDataStrc), gszTypeSGameData_0070F56C, -2, 0x10);
    f_8 = (D2SGameDataStrc*)pNew;
    if (!pNew)
    {
        f_8 = (D2SGameDataStrc*)SMemAlloc(nAlloc * sizeof(D2SGameDataStrc), gszTypeSGameData_0070F56C, -2, 0);
        if (pOld)
        {
            unsigned int nCopy = nAlloc >= f_4 ? f_4 : nAlloc;
            for (unsigned int i = 0; i < nCopy; i++)
            {
                new (&f_8[i]) D2SGameDataStrc(pOld[i]);
                pOld[i].~D2SGameDataStrc();
            }
            SMemFree(pOld, gszTypeSGameData_0070F56C, -2, 0);
        }
    }
}
