struct D2SoundNode00516980Strc
{
    int nId;
    D2SoundNode00516980Strc* pNext;
};
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

// 0x00516980
void __fastcall sub_00516980_RemoveNode(D2SoundNode00516980Strc** ppList, int nId)
{
    D2SoundNode00516980Strc* pPrev = 0;
    for (D2SoundNode00516980Strc* pNode = *ppList; pNode; pNode = pNode->pNext)
    {
        if (pNode && pNode->nId == nId)
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
