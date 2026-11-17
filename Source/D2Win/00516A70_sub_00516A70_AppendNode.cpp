extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                            // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

struct D2SoundNodeStrc
{
    int nKey;
    D2SoundNodeStrc* pNext;
};

// 0x00516A70
void __fastcall sub_00516A70_AppendNode(D2SoundNodeStrc** ppList, int nKey)
{
    D2SoundNodeStrc* pNew = (D2SoundNodeStrc*)FOG_Alloc(sizeof(D2SoundNodeStrc), ".\\Src\\D2SoundUtil.cpp", 0x120, 0);
    memset(pNew, 0, sizeof(D2SoundNodeStrc));
    pNew->nKey = nKey;

    for (D2SoundNodeStrc* pNode = *ppList; pNode; pNode = pNode->pNext)
    {
        if (!pNode->pNext)
        {
            pNode->pNext = pNew;
            return;
        }
    }

    *ppList = pNew;
}
