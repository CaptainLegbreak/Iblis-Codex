extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

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
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

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
    p->pUnit = pUnit;
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
    if (!pNode || !pNode->pUnit)
        return;
    D2TargetNodeStrc* p = (D2TargetNodeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TargetNodeStrc), gszTargetsSourceFile, 108, 0);
    if (!p)
        return;
    memset(p, 0, sizeof(D2TargetNodeStrc));
    p->pUnit = pUnit;
    p->unk0x04 = a3;
    p->pNext = pNode->pNext;
    p->unk0x0C = pNode;
    if (pNode->pNext)
        pNode->pNext->unk0x0C = p;
    pNode->pNext = p;
    pUnit->dwNodeIndex = nNodeIndex;
}

#include "gen/data/Source/D2Game/005B1880_sub_005B1880.inc"
