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
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
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
            pExistingLink->m_next = pNode;
            break;
        default:
            {
                D2StormLinkStrc* pPrev = pExistingLink->m_prevlink;
                pLink->m_prevlink = pPrev;
                pLink->m_next = pPrev->m_next;
                pPrev->m_next = pNode;
                pExistingLink->m_prevlink = pLink;
            }
            break;
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
};

struct D2StormHuffOutputStrc
{
    unsigned char* pOutputStart;
    unsigned int f_4;
    unsigned char* pOutput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    void sub_0041D950_PutBits(unsigned int nValue, unsigned int nBits);                                     // 0x0041D950
};

struct D2StormHuffTreeStrc
{
    int bIsCmp0;
    unsigned int nUnk0x04;
    D2StormHuffItemStrc f_8[0x203];
    D2StormNodeListStrc tFreeList;
    D2StormNodeListStrc tItemList;
    unsigned int nItemsUsed;
    D2StormHuffItemStrc* pItemsByValue[0x102];

    void sub_0041D9E0_EncodeOne(D2StormHuffOutputStrc* pOutput, unsigned int nValue);
    void sub_0041F350_IncWeights(D2StormHuffItemStrc* pItem);
};

// 0x0041D9E0
void D2StormHuffTreeStrc::sub_0041D9E0_EncodeOne(D2StormHuffOutputStrc* pOutput, unsigned int nValue)
{
    D2StormHuffItemStrc* pItem = pItemsByValue[nValue];
    unsigned int nCode = 0;
    unsigned int nBits = 0;
    for (D2StormHuffItemStrc* pParent = pItem->pParent; pParent; pParent = pParent->pParent)
    {
        nCode = (nCode << 1) | (pParent->pChild != pItem);
        nBits++;
        pItem = pParent;
    }
    pOutput->sub_0041D950_PutBits(nCode, nBits);
}

// 0x0041F350
void D2StormHuffTreeStrc::sub_0041F350_IncWeights(D2StormHuffItemStrc* pItem)
{
    for (; pItem; pItem = pItem->pParent)
    {
        pItem->nWeight++;
        D2StormHuffItemStrc* pCur = pItem;
        D2StormHuffItemStrc* pNext;
        for (;;)
        {
            pNext = (D2StormHuffItemStrc*)pCur->f_0.Next();
            if (!pNext || pNext->nWeight >= pItem->nWeight)
                break;
            pCur = pNext;
        }
        if (pCur == pItem)
            continue;
        tItemList.LinkNode((char*)pCur, 2, (char*)pItem);
        tItemList.LinkNode((char*)pItem, 2, (char*)pNext);
        D2StormHuffItemStrc* pCurParentChild = pCur->pParent->pChild;
        if (pItem->pParent->pChild == pItem)
            pItem->pParent->pChild = pCur;
        if (pCurParentChild == pCur)
            pCur->pParent->pChild = pItem;
        D2StormHuffItemStrc* pTemp = pItem->pParent;
        pItem->pParent = pCur->pParent;
        pCur->pParent = pTemp;
        nUnk0x04++;
    }
}
