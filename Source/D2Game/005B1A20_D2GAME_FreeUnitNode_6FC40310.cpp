struct D2UnitStrc;

struct D2TargetNodeStrc
{
    D2UnitStrc* pUnit;
    int unk0x04;
    D2TargetNodeStrc* pNext;
    D2TargetNodeStrc* unk0x0C;
};

struct D2UnitStrc
{
    int dwUnitType;
    char pad0x04[0xCC];
    int dwNodeIndex;
};

struct D2GameStrc
{
    char pad0x00[0x1C];
    void* pMemoryPool;
    char pad0x20[0x6C];
    int nClients;
    char pad0x90[0x1068];
    D2TargetNodeStrc* pTargetNodes[10];
};

extern "C" const char gszTargetsSourceFile[];                                                               // 0x006E2C78
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480

// 0x005B1A20
void __fastcall D2GAME_FreeUnitNode_6FC40310(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || (pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1))
    {
        return;
    }

    const int nNodeIndex = pUnit->dwNodeIndex;
    if (nNodeIndex == 11)
    {
        return;
    }

    D2TargetNodeStrc* pTargetNode = pGame->pTargetNodes[nNodeIndex];
    while (pTargetNode)
    {
        D2TargetNodeStrc* pNext = pTargetNode->pNext;
        if (pTargetNode->pUnit)
        {
            pTargetNode->pUnit->dwNodeIndex = 11;
        }

        FOG_FreePool(pGame->pMemoryPool, pTargetNode, gszTargetsSourceFile, 232, 0);
        pTargetNode = pNext;
    }
    pGame->pTargetNodes[nNodeIndex] = 0;
}
