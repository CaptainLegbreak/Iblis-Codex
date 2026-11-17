int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
struct D2SoundNode00516A10Strc
{
    int nKey;
    D2SoundNode00516A10Strc* pNext;
};

static __forceinline void RemoveNode(D2SoundNode00516A10Strc** ppList, int nKey)
{
    D2SoundNode00516A10Strc* pPrev = 0;
    for (D2SoundNode00516A10Strc* pNode = *ppList; pNode; pNode = pNode->pNext)
    {
        if (pNode && pNode->nKey == nKey)
        {
            if (*ppList == pNode)
            {
                *ppList = pNode->pNext;
            }
            if (pPrev)
            {
                pPrev->pNext = pNode->pNext;
            }
            FOG_Free(pNode, ".\\Src\\D2SoundUtil.cpp", 0xF1, 0);
            return;
        }
        pPrev = pNode;
    }
}

// 0x00516A10
void __fastcall sub_00516A10_FreeList(D2SoundNode00516A10Strc** ppList)
{
    while (*ppList)
    {
        RemoveNode(ppList, (*ppList)->nKey);
    }
}
