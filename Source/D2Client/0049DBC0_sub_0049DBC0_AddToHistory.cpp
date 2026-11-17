struct Unicode
{
    unsigned short wChar;
};

#pragma pack(push, 2)
struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    D2TextNodeStrc* pNext;
};

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst;
    unsigned short nCount;
};
#pragma pack(pop)

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2TextNodeStrc* __fastcall sub_0049DB10_CloneStringList(D2TextNodeStrc* pSource);                           // 0x0049DB10
D2TextListStrc gtTextList_007BF1F0;                                                                         // 0x007BF1F0

static void sub_0049D490_FreeTextNode(D2TextNodeStrc* pNode)
{
    for (int i = 0; i < 6; i++)
    {
        if (pNode->pLines[i])
            FOG_Free(pNode->pLines[i], ".\\UI\\text.cpp", 0x6B3, 0);
    }
    FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
}

// 0x0049DBC0
void __fastcall sub_0049DBC0_AddToHistory(D2TextNodeStrc* pSource)
{
    D2TextNodeStrc* pClone = sub_0049DB10_CloneStringList(pSource);
    D2TextNodeStrc* pNode;
    if (gtTextList_007BF1F0.nCount >= 0x80)
    {
        pNode = gtTextList_007BF1F0.pFirst;
        if (!pNode)
        {
            goto link;
        }

        D2TextNodeStrc* pPrevious = 0;
        while (pNode->pNext)
        {
            pPrevious = pNode;
            pNode = pNode->pNext;
        }
        sub_0049D490_FreeTextNode(pNode);
        if (pPrevious)
            pPrevious->pNext = 0;
        if (gtTextList_007BF1F0.nCount >= 1)
            gtTextList_007BF1F0.nCount--;
    }
    pNode = gtTextList_007BF1F0.pFirst;
link:
    pClone->pNext = pNode;
    gtTextList_007BF1F0.nCount++;
    gtTextList_007BF1F0.pFirst = pClone;
}
