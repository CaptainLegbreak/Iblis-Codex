struct D2StormIdNodeStrc
{
    D2StormIdNodeStrc* pPrevLink;
    D2StormIdNodeStrc* pNext;
    int nId;
};

struct D2StormListStrc
{
    int m_linkoffset;
    void* m_prevlink;
    char* m_next;
    char* Head()
    {
        char* pHead = (int)m_next <= 0 ? 0 : m_next;
        return pHead;
    }
};

extern D2StormListStrc gIdList_00708860; // 0x00708860

// 0x004209E0
D2StormIdNodeStrc* __fastcall sub_004209E0_FindById(int nId)
{
    for (D2StormIdNodeStrc* pNode = (D2StormIdNodeStrc*)gIdList_00708860.Head(); (int)pNode > 0; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
            return pNode;
    }
    return 0;
}
