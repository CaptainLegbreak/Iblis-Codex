#include "D2Game.h"

struct D2TargetNodeStrc;
struct D2UnitStrc;
struct D2GameStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2TargetNodeStrc
{
    D2UnitStrc* hUnit;
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

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x005B1880
void __fastcall sub_005B1880(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    if (!pGame || !pUnit || pUnit->dwUnitType != 0 || pUnit->dwNodeIndex != 11)
        return;
    D2TargetNodeStrc** ppNode = pGame->pTargetNodes;
    int i = 0;
    for (; i < 8; ++i, ++ppNode)
    {
        if (!*ppNode)
            break;
    }
    if (pGame->nClients > 8 || i >= 8)
        return;
    D2TargetNodeStrc* p = (D2TargetNodeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TargetNodeStrc), gszTargetsSourceFile, 57, 0);
    if (!p)
        return;
    memset(p, 0, sizeof(D2TargetNodeStrc));
    p->hUnit = pUnit;
    p->unk0x04 = a3;
    *ppNode = p;
    pUnit->dwNodeIndex = i;
}

// 0x005B1900
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex)
{
    if (!pGame || !pUnit || pUnit->dwNodeIndex != 11 || nNodeIndex >= 8 || (pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1))
        return;
    D2TargetNodeStrc* pNode = pGame->pTargetNodes[nNodeIndex];
    if (!pNode || !pNode->hUnit)
        return;
    D2TargetNodeStrc* p = (D2TargetNodeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TargetNodeStrc), gszTargetsSourceFile, 108, 0);
    if (!p)
        return;
    memset(p, 0, sizeof(D2TargetNodeStrc));
    p->hUnit = pUnit;
    p->unk0x04 = a3;
    p->pNext = pNode->pNext;
    p->unk0x0C = pNode;
    if (pNode->pNext)
        pNode->pNext->unk0x0C = p;
    pNode->pNext = p;
    pUnit->dwNodeIndex = nNodeIndex;
}

#include "gen/data/Source/D2Game/GAME/Targets.inc"

// 0x005B1990
void __fastcall sub_6FC40280(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex)
{
    if (!pGame || !pUnit || pUnit->dwNodeIndex != 11 || nNodeIndex < 8 || nNodeIndex > 9 || (pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1))
        return;
    D2TargetNodeStrc* pNode = pGame->pTargetNodes[nNodeIndex];
    D2TargetNodeStrc* p = (D2TargetNodeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TargetNodeStrc), gszTargetsSourceFile, 161, 0);
    if (!p)
        return;
    memset(p, 0, sizeof(D2TargetNodeStrc));
    p->hUnit = pUnit;
    p->unk0x04 = a3;
    pGame->pTargetNodes[nNodeIndex] = p;
    if (pNode)
    {
        p->pNext = pNode;
        pNode->unk0x0C = p;
    }
    pUnit->dwNodeIndex = nNodeIndex;
}

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
        if (pTargetNode->hUnit)
        {
            pTargetNode->hUnit->dwNodeIndex = 11;
        }

        FOG_FreePool(pGame->pMemoryPool, pTargetNode, gszTargetsSourceFile, 232, 0);
        pTargetNode = pNext;
    }
    pGame->pTargetNodes[nNodeIndex] = 0;
}

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
            if (pTargetNode->hUnit == pUnit)
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
            if (pTargetNode->hUnit == pUnit)
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
