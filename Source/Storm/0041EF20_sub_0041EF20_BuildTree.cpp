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
        return (int)m_next > 0 ? m_next : 0;
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

    void sub_0041EF20_BuildTree(unsigned char nCmpType);
    D2StormHuffItemStrc* AllocateItem(unsigned int nLinkType)
    {
        D2StormHuffItemStrc* pItem = (D2StormHuffItemStrc*)tFreeList.m_terminator.Next();
        if (!pItem) pItem = &f_8[nItemsUsed++];
        tItemList.LinkNode((char*)pItem, nLinkType, 0);
        pItem->pParent = 0;
        pItem->pChild = 0;
        return pItem;
    }
};

extern unsigned char gaHuffDistribution_006CF3A0[][0x102]; // 0x006CF3A0
void __stdcall SMemZero(void*, unsigned int); // 0x0041D300
// 0x0041EF20
void D2StormHuffTreeStrc::sub_0041EF20_BuildTree(unsigned char nCmpType)
{
    D2StormHuffItemStrc* pItem;
    while ((pItem = (D2StormHuffItemStrc*)tItemList.m_terminator.Next()) != 0)
        tFreeList.LinkNode((char*)pItem, 1, 0);
    SMemZero(pItemsByValue, sizeof(pItemsByValue));
    unsigned int nMaxWeight = 0;
    int nValue;
    for (nValue = 0; nValue < 256; ++nValue)
    {
        if (!gaHuffDistribution_006CF3A0[nCmpType][nValue]) continue;
        pItem = AllocateItem(2);
        pItemsByValue[nValue] = pItem;
        pItem->nValue = nValue;
        pItem->nWeight = gaHuffDistribution_006CF3A0[nCmpType][nValue];
        if (pItem->nWeight >= nMaxWeight) nMaxWeight = pItem->nWeight;
        else
        {
            D2StormHuffItemStrc* pNext = (D2StormHuffItemStrc*)tItemList.m_terminator.Next();
            while (pNext && pNext->nWeight < pItem->nWeight)
                pNext = (D2StormHuffItemStrc*)pNext->f_0.Next();
            tItemList.LinkNode((char*)pItem, 2, (char*)pNext);
        }
    }
    for (; nValue < 258; ++nValue)
    {
        pItem = AllocateItem(1);
        pItemsByValue[nValue] = pItem;
        pItem->nValue = nValue;
        pItem->nWeight = 1;
    }
    D2StormHuffItemStrc* pLow = (D2StormHuffItemStrc*)tItemList.m_terminator.Next();
    while (pLow)
    {
        D2StormHuffItemStrc* pNext = (D2StormHuffItemStrc*)pLow->f_0.Next();
        if (!pNext)
            break;
        pItem = AllocateItem(2);
        pItem->nWeight = pLow->nWeight + pNext->nWeight;
        pItem->pChild = pLow;
        pLow->pParent = pItem;
        pNext->pParent = pItem;
        if (pItem->nWeight >= nMaxWeight) nMaxWeight = pItem->nWeight;
        else
        {
            D2StormHuffItemStrc* pInsert = (D2StormHuffItemStrc*)pNext->f_0.Next();
            while (pInsert && pInsert->nWeight < pItem->nWeight)
                pInsert = (D2StormHuffItemStrc*)pInsert->f_0.Next();
            tItemList.LinkNode((char*)pItem, 2, (char*)pInsert);
        }
        pLow = (D2StormHuffItemStrc*)pNext->f_0.Next();
    }
    nUnk0x04 = 1;
}

#include "gen/data/Source/Storm/0041EF20_sub_0041EF20_BuildTree.inc"
