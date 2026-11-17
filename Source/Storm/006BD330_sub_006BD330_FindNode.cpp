struct D2TreeNode006BD330Strc
{
    unsigned char unk_00[0x20];
    int nId20;
    D2TreeNode006BD330Strc* pLeft24;
    D2TreeNode006BD330Strc* pRight28;
};
extern D2TreeNode006BD330Strc* const gpTreeSentinel_0074C3D8; // 0x0074C3D8

// 0x006BD330
D2TreeNode006BD330Strc* __fastcall sub_006BD330_FindNode(D2TreeNode006BD330Strc* pNode, int nId)
{
    if (!pNode)
    {
        return gpTreeSentinel_0074C3D8;
    }
    if (pNode->nId20 == nId)
    {
        return pNode;
    }
    D2TreeNode006BD330Strc* pFound;
    if (pNode->pLeft24)
    {
        pFound = sub_006BD330_FindNode(pNode->pLeft24, nId);
        if (pFound != gpTreeSentinel_0074C3D8)
        {
            return pFound;
        }
    }
    if (pNode->pRight28)
    {
        pFound = sub_006BD330_FindNode(pNode->pRight28, nId);
        if (pFound != gpTreeSentinel_0074C3D8)
        {
            return pFound;
        }
    }
    return gpTreeSentinel_0074C3D8;
}

#include "gen/data/Source/Storm/006BD330_sub_006BD330_FindNode.inc"
