struct D2StormLinkStrc
{
    D2StormLinkStrc* pPrevious;
    char* pNext;
    D2StormLinkStrc* NextLink(int nOffset)
    {
        if ((int)pNext < 0)
            return (D2StormLinkStrc*)~(unsigned int)pNext;
        if (nOffset < 0)
            nOffset = (char*)this - pPrevious->pNext;
        return (D2StormLinkStrc*)(pNext + nOffset);
    }
    void Unlink()
    {
        if (pPrevious)
        {
            NextLink(-1)->pPrevious = pPrevious;
            pPrevious->pNext = pNext;
            pPrevious = 0;
            pNext = 0;
        }
    }
};
struct D2StormNodeListStrc
{
    int nLinkOffset;
    D2StormLinkStrc terminator;
    void __thiscall sub_0041EE40_UnlinkAll(); // 0x0041EE40
    __forceinline void Clear()
    {
        sub_0041EE40_UnlinkAll();
        terminator.Unlink();
    }
};
struct D2StormHuffItemStrc
{
    D2StormLinkStrc link;
    unsigned int nValue, nWeight;
    D2StormHuffItemStrc* pParent;
    D2StormHuffItemStrc* pChild;
};
struct D2StormHuffTreeStrc
{
    int unk_00[2];
    D2StormHuffItemStrc items[515];
    D2StormNodeListStrc listA;
    D2StormNodeListStrc listB;
};
void __fastcall sub_0041EE90_DestroyItem(void* pItem); // 0x0041EE90
void __stdcall sub_00686AD1_DestroyArray(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pDestroy)(void*)); // 0x00686AD1

// 0x0041F6A0
void __fastcall sub_0041F6A0_DestroyTree(D2StormHuffTreeStrc* pTree)
{
    pTree->listB.Clear();
    pTree->listA.Clear();
    sub_00686AD1_DestroyArray(pTree->items, sizeof(D2StormHuffItemStrc), 515, sub_0041EE90_DestroyItem);
}
