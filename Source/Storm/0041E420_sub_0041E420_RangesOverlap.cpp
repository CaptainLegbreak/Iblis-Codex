struct D2SCompLinkStrc
{
    D2SCompLinkStrc* m_prevlink;
    char* m_next;

    D2SCompLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2SCompLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2SCompLinkStrc*)(m_next + nLinkOffset);
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

struct D2SCompListViewStrc
{
    int m_linkoffset;
    D2SCompLinkStrc m_terminator;
};

struct D2SCompLinkNextAStrc { D2SCompLinkStrc tLink; char* sub_0041E930_Next(); };
struct D2SCompLinkNextBStrc { D2SCompLinkStrc tLink; char* sub_0041EA40_Next(); };
struct D2SCompLinkPrevStrc { D2SCompLinkStrc tLink; char* sub_0041E940_Prev(); };
struct D2SCompLinkRawAStrc { D2SCompLinkStrc tLink; char* sub_0041E960_RawNext(); };
struct D2SCompLinkRawBStrc { D2SCompLinkStrc tLink; char* sub_0041EA50_RawNext(); };
struct D2SCompUnlinkAStrc { D2SCompLinkStrc tLink; void sub_0041E970_Unlink(); };
struct D2SCompUnlinkBStrc { D2SCompLinkStrc tLink; void sub_0041EA70_Unlink(); };
struct D2SCompUnlinkCStrc { D2SCompLinkStrc tLink; void sub_0041EAE0_Unlink(); };
struct D2SCompUnlinkDStrc { D2SCompLinkStrc tLink; void sub_0041ED30_Unlink(); };
struct D2SCompListTermStrc { D2SCompListViewStrc tList; void sub_0041E9B0_InitializeTerminator(); };
struct D2SCompLinkCtorAStrc { D2SCompLinkStrc* m_prevlink; char* m_next; D2SCompLinkCtorAStrc(); };
struct D2SCompLinkCtorBStrc { D2SCompLinkStrc* m_prevlink; char* m_next; D2SCompLinkCtorBStrc(); };
struct D2SCompListHeadStrc { D2SCompListViewStrc tList; char* sub_0041EAB0_Head(); };
struct D2SCompListTailStrc { D2SCompListViewStrc tList; char* sub_0041EAC0_Tail(); };
struct D2SCompListInitStrc { D2SCompListViewStrc tList; void sub_0041EB20_Init(); };
struct D2SCompTermLinkStrc
{
    D2SCompTermLinkStrc* m_prevlink;
    char* m_next;
    D2SCompTermLinkStrc() { m_prevlink = 0; m_next = 0; }
};
struct D2SCompListStrc
{
    int m_linkoffset;
    D2SCompTermLinkStrc m_terminator;
    D2SCompListStrc();
};

// 0x0041E420
static int sub_0041E420_RangesOverlap(const char* pA, const char* pB, unsigned int nSize)
{
    if (pA + nSize > pB && pB + nSize > pA)
        return 1;
    return 0;
}

int __stdcall sub_M107_Emit_0041E420(const char* pA, const char* pB, unsigned int nSize, int nCount)
{
    if (nCount >= 2 || sub_0041E420_RangesOverlap(pA, pB, nSize))
        return nCount + 1;
    return nCount;
}

// 0x0041E930
char* D2SCompLinkNextAStrc::sub_0041E930_Next() { return (int)tLink.m_next <= 0 ? 0 : tLink.m_next; }

// 0x0041E940
char* D2SCompLinkPrevStrc::sub_0041E940_Prev()
{
    D2SCompLinkStrc* pLink = tLink.m_prevlink->m_prevlink;
    return (int)pLink->m_next <= 0 ? 0 : pLink->m_next;
}

// 0x0041E960
char* D2SCompLinkRawAStrc::sub_0041E960_RawNext() { return tLink.m_next; }

// 0x0041E970
void D2SCompUnlinkAStrc::sub_0041E970_Unlink() { tLink.Unlink(); }

// 0x0041E9B0
void D2SCompListTermStrc::sub_0041E9B0_InitializeTerminator()
{
    tList.m_terminator.m_prevlink = &tList.m_terminator;
    tList.m_terminator.m_next = (char*)~(unsigned int)&tList.m_terminator;
}

// 0x0041E9D0
void __fastcall sub_0041E9D0_SwapDwords(int* pA, int* pB)
{
    int nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

// 0x0041EA40
char* D2SCompLinkNextBStrc::sub_0041EA40_Next() { return (int)tLink.m_next <= 0 ? 0 : tLink.m_next; }

// 0x0041EA50
char* D2SCompLinkRawBStrc::sub_0041EA50_RawNext() { return tLink.m_next; }

// 0x0041EA60
D2SCompLinkCtorAStrc::D2SCompLinkCtorAStrc() { m_prevlink = 0; m_next = 0; }

// 0x0041EA70
void D2SCompUnlinkBStrc::sub_0041EA70_Unlink() { tLink.Unlink(); }

// 0x0041EAB0
char* D2SCompListHeadStrc::sub_0041EAB0_Head() { return (int)tList.m_terminator.m_next <= 0 ? 0 : tList.m_terminator.m_next; }

// 0x0041EAC0
char* D2SCompListTailStrc::sub_0041EAC0_Tail()
{
    D2SCompLinkStrc* pLink = tList.m_terminator.m_prevlink->m_prevlink;
    return (int)pLink->m_next <= 0 ? 0 : pLink->m_next;
}

// 0x0041EAE0
void D2SCompUnlinkCStrc::sub_0041EAE0_Unlink() { tLink.Unlink(); }

// 0x0041EB20
void D2SCompListInitStrc::sub_0041EB20_Init()
{
    tList.m_linkoffset = 0;
    tList.m_terminator.m_prevlink = &tList.m_terminator;
    tList.m_terminator.m_next = (char*)~(unsigned int)&tList.m_terminator;
}

// 0x0041EBB0
D2SCompLinkCtorBStrc::D2SCompLinkCtorBStrc() { m_prevlink = 0; m_next = 0; }

// 0x0041ED30
void D2SCompUnlinkDStrc::sub_0041ED30_Unlink() { tLink.Unlink(); }

// 0x0041ED70
D2SCompListStrc::D2SCompListStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}
