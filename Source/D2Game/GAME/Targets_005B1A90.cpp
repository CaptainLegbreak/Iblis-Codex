#include "D2Game.h"

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
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480

// 0x005B1A90
void __fastcall TARGETS_RemoveUnitNode(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || (pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1))
        return;
    const int nNodeIndex = pUnit->dwNodeIndex;
    if (nNodeIndex == 11)
        return;
    D2TargetNodeStrc* pTargetNode = pGame->pTargetNodes[nNodeIndex];
    if (!pTargetNode)
        return;
    if (nNodeIndex < 8)
    {
        for (pTargetNode = pTargetNode->pNext; pTargetNode; pTargetNode = pTargetNode->pNext)
        {
            if (pTargetNode->pUnit == pUnit)
            {
                pTargetNode->unk0x0C->pNext = pTargetNode->pNext;
                if (pTargetNode->pNext) pTargetNode->pNext->unk0x0C = pTargetNode->unk0x0C;
                FOG_FreePool(pGame->pMemoryPool, pTargetNode, gszTargetsSourceFile, 322, 0);
                pUnit->dwNodeIndex = 11;
                return;
            }
        }
    }
    else
    {
        D2TargetNodeStrc* const pHead = pTargetNode;
        for (; pTargetNode; pTargetNode = pTargetNode->pNext)
        {
            if (pTargetNode->pUnit == pUnit)
            {
                if (pTargetNode == pHead)
                {
                    pGame->pTargetNodes[nNodeIndex] = pTargetNode->pNext;
                    if (pTargetNode->pNext) pTargetNode->pNext->unk0x0C = 0;
                }
                else
                {
                    pTargetNode->unk0x0C->pNext = pTargetNode->pNext;
                    if (pTargetNode->pNext) pTargetNode->pNext->unk0x0C = pTargetNode->unk0x0C;
                }
                FOG_FreePool(pGame->pMemoryPool, pTargetNode, gszTargetsSourceFile, 322, 0);
                break;
            }
        }
    }
    pUnit->dwNodeIndex = 11;
}
