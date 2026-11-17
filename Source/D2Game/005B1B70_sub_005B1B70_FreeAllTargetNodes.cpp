struct D2UnitStrc;

struct D2TargetNodeStrc
{
    D2UnitStrc* pUnit;
    int nNodeData;
    D2TargetNodeStrc* pNext;
    D2TargetNodeStrc* pPrevious;
};

struct D2GameStrc
{
    char unk0x0000[0x10F8];
    D2TargetNodeStrc* pTargetNodes[10];
    int unk0x1120;
};

void __fastcall D2GAME_FreeUnitNode_6FC40310(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x005B1A20

// 0x005B1B70
void __fastcall sub_005B1B70_FreeAllTargetNodes(D2GameStrc* pGame)
{
    if (!pGame)
    {
        return;
    }

    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* pTargetNode = *ppTargetNode;
    for (int nCount = 10; nCount; --nCount)
    {
        if (pTargetNode && pTargetNode->pUnit)
        {
            D2GAME_FreeUnitNode_6FC40310(pGame, pTargetNode->pUnit);
        }
        pTargetNode = *++ppTargetNode;
    }
}
