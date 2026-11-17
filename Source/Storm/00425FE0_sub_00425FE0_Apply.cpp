int __stdcall sub_00425330(void* hHandle, int nArg1, int nArg2, int nArg3);                                 // 0x00425330
void __stdcall sub_00423B30(void* hHandle, void* pBuffer, unsigned int nSize, unsigned int* pRead);         // 0x00423B30
int __stdcall sub_00423850(void* hHandle, int nArg1, int nArg2);                                            // 0x00423850
void __stdcall sub_0041D300_ZeroMemory(void* pDest, unsigned int nSize);                                    // 0x0041D300

struct D2StormHandleRefStrc
{
    void* hHandle;

    D2StormHandleRefStrc& sub_00425FE0_Apply(const int& nArg1, const int& nArg2, const int& nArg3);
};

struct D2StormHandleStrc
{
    void* hHandle;

    void* sub_00426010_ReadFill(void* pBuffer, unsigned int nSize);
    int sub_00426050_Call(int nArg1, int nArg2);
};

struct D2StormHandlePairStrc
{
    void* hFirst;
    void* hSecond;

    void sub_00426070_CallBoth(int nArg1, int nArg2, int nArg3, int nArg4);
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
    D2StormLinkStrc* sub_00426930_NextLink(int nLinkOffset);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(D2StormLinkStrc* pNode)
    {
        return pNode ? pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_00426AE0_Link(D2StormLinkStrc* pNode);
    void sub_00426B00_LinkNode(D2StormLinkStrc* pNode, int nLinkType, D2StormLinkStrc* pExisting);
    char* sub_00426BB0_Next(D2StormLinkStrc* pNode);
    void sub_00426C10_UnlinkNode(D2StormLinkStrc* pNode);
    char* sub_00426C80_RawNext(D2StormLinkStrc* pNode);
};

// 0x00425FE0
D2StormHandleRefStrc& D2StormHandleRefStrc::sub_00425FE0_Apply(const int& nArg1, const int& nArg2, const int& nArg3)
{
    sub_00425330(hHandle, nArg1, nArg2, nArg3);
    return *this;
}

// 0x00426010
void* D2StormHandleStrc::sub_00426010_ReadFill(void* pBuffer, unsigned int nSize)
{
    unsigned int nRead;
    sub_00423B30(hHandle, pBuffer, nSize, &nRead);
    if (nRead < nSize)
        sub_0041D300_ZeroMemory((char*)pBuffer + nRead, nSize - nRead);
    return pBuffer;
}

// 0x00426050
int D2StormHandleStrc::sub_00426050_Call(int nArg1, int nArg2)
{
    return sub_00423850(hHandle, nArg1, nArg2);
}

// 0x00426070
void D2StormHandlePairStrc::sub_00426070_CallBoth(int nArg1, int nArg2, int nArg3, int nArg4)
{
    sub_00423850(hFirst, nArg1, nArg2);
    sub_00423850(hSecond, nArg3, nArg4);
}

// 0x00426930
D2StormLinkStrc* D2StormLinkStrc::sub_00426930_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00426AE0
D2StormLinkStrc* D2StormListAStrc::sub_00426AE0_Link(D2StormLinkStrc* pNode)
{
    return Link(pNode);
}

// 0x00426B00
void D2StormListAStrc::sub_00426B00_LinkNode(D2StormLinkStrc* pNode, int nLinkType, D2StormLinkStrc* pExisting)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExisting);
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = (char*)pNode;
        break;
    default:
        {
            D2StormLinkStrc* pPrev = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrev;
            pLink->m_next = pPrev->m_next;
            pPrev->m_next = (char*)pNode;
            pExistingLink->m_prevlink = pLink;
        }
        break;
    }
}

// 0x00426BB0
char* D2StormListAStrc::sub_00426BB0_Next(D2StormLinkStrc* pNode)
{
    return Link(pNode)->Next();
}

// 0x00426C10
void D2StormListAStrc::sub_00426C10_UnlinkNode(D2StormLinkStrc* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00426C80
char* D2StormListAStrc::sub_00426C80_RawNext(D2StormLinkStrc* pNode)
{
    return pNode ? pNode->m_next : m_terminator.m_next;
}
