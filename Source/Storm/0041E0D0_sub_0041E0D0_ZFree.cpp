struct D2StormZArenaStrc
{
    char* f_0;
    unsigned int nSize;
    char* f_8;
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

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

struct D2StormHuffItemStrc
{
    D2StormLinkStrc f_0;
    unsigned int nValue;
    unsigned int nWeight;
    D2StormHuffItemStrc* pParent;
    D2StormHuffItemStrc* pChild;

    D2StormHuffItemStrc();
    ~D2StormHuffItemStrc();
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

// 0x0041E0D0
void __fastcall sub_0041E0D0_ZFree(void* pArena, void* pAddress)
{
    D2StormZArenaStrc* pZArena = (D2StormZArenaStrc*)pArena;
    if ((char*)pAddress < pZArena->f_8 || (char*)pAddress >= pZArena->f_8 + pZArena->nSize)
        SMemFree(pAddress, ".\\SOURCE\\SCOMP.CPP", 0x4CC, 0);
}

// 0x0041EE80
D2StormHuffItemStrc::D2StormHuffItemStrc()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041EE90
D2StormHuffItemStrc::~D2StormHuffItemStrc()
{
    f_0.Unlink();
}
