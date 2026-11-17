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
    p->pUnit = pUnit;
    p->unk0x04 = a3;
    pGame->pTargetNodes[nNodeIndex] = p;
    if (pNode)
    {
        p->pNext = pNode;
        pNode->unk0x0C = p;
    }
    pUnit->dwNodeIndex = nNodeIndex;
}
