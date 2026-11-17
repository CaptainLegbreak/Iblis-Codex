int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);                // 0x00412650

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

struct D2StormBigStrc
{
    int unk0x00[0x5A];

    ~D2StormBigStrc();                                                                                      // 0x00421D80
    static void operator delete(void* pMemory);
};

struct D2StormBreakCmdStrc
{
    D2StormLinkStrc f_0;
    int nData;

    static void operator delete(void* pMemory);
};

struct D2GameStrc;

struct D2GameLinkStrc
{
    D2GameLinkStrc* pPrevLink;
    D2GameStrc* pNext;
};

struct D2GameStrc
{
    unsigned int dwHashValue;
    D2GameLinkStrc tLinkToSlot;
    D2GameLinkStrc tLinkToFull;
    char unk0x14[0x1DE0];

    ~D2GameStrc();                                                                                          // 0x0044F820
    static void operator delete(void* pMemory);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormListAStrc();
    void UnlinkAll();                                                                                       // 0x0044F8E0
    static void operator delete(void* pMemory);
};

struct D2StormGameArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2GameStrc* f_8;
    unsigned int f_C;

    ~D2StormGameArrayStrc();                                                                                // 0x0044FD80
};

struct D2StormHashObjectChunkStrc
{
    D2StormGameArrayStrc m_array;
    D2StormLinkStrc f_10;

    static void operator delete(void* pMemory);
};

struct D2StormListArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;

    ~D2StormListArrayStrc();                                                                                // 0x0044FF60
    static void operator delete(void* pMemory);
};

// build: symbol ??_GD2GameStrc@@QAEPAXI@Z 0x0044FBB0
// build: symbol ??_GD2StormBigStrc@@QAEPAXI@Z 0x00423820
// build: symbol ??_GD2StormBreakCmdStrc@@QAEPAXI@Z 0x00426E20
// build: symbol ??_GD2StormHashObjectChunkStrc@@QAEPAXI@Z 0x004500A0
// build: symbol ??_GD2StormListArrayStrc@@QAEPAXI@Z 0x004504D0
// 0x00423820
inline void D2StormBigStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00426E20
inline void D2StormBreakCmdStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0044FBB0
inline void D2GameStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// build: symbol ??_GD2StormListAStrc@@QAEPAXI@Z 0x0044FCF0
inline D2StormListAStrc::~D2StormListAStrc()
{
    UnlinkAll();
}

inline void D2StormListAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x004500A0
inline void D2StormHashObjectChunkStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x004504D0
inline void D2StormListArrayStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

void sub_Emit_D2StormBigStrc(D2StormBigStrc* p)
{
    delete p;
}

// build: context sub_Emit_D2StormBreakCmdStrc
void sub_Emit_D2StormBreakCmdStrc(D2StormBreakCmdStrc* p)
{
    delete p;
}

void sub_Emit_D2GameStrc(D2GameStrc* p)
{
    delete p;
}

// build: context sub_Emit_D2StormListAStrc
void sub_Emit_D2StormListAStrc(D2StormListAStrc* p)
{
    delete p;
}

// build: context sub_Emit_D2StormHashObjectChunkStrc
void sub_Emit_D2StormHashObjectChunkStrc(D2StormHashObjectChunkStrc* p)
{
    delete p;
}

void sub_Emit_D2StormListArrayStrc(D2StormListArrayStrc* p)
{
    delete p;
}
