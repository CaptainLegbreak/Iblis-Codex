struct D2MapAIStrc;
struct D2MinionListStrc;

struct D2ItemDataStrc
{
    char pad0x00[0x24];
    int dwActionStamp;
};

struct D2UnitStrc
{
    char pad0x00[0x14];
    D2ItemDataStrc* pItemData;
};

struct D2InactiveItemNodeStrc
{
    D2InactiveItemNodeStrc* pNext;
    int nFrame;
    int nOwnerId;
};

struct D2InactiveMonsterNodeStrc
{
    char unk0x00[0x20];
    D2MinionListStrc* pMinionList;
    D2MapAIStrc* pMapAI;
    char unk0x28[0x30];
    D2InactiveMonsterNodeStrc* pNext;
};

struct D2InactiveUnitListStrc
{
    int nX;
    int nY;
    D2InactiveItemNodeStrc* pInactiveItems;
    D2InactiveMonsterNodeStrc* pInactiveMonsters;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall DRLGPRESET_FreeMapAI(void* pMemPool, D2MapAIStrc* pMapAi);                                  // 0x00666130
void __fastcall AIGENERAL_FreeAllMinionLists(D2GameStrc* pGame, D2MinionListStrc* pMinionList);             // 0x0058F350

// 0x00541880
void __fastcall sub_00541880_SetItemActionStamp(D2UnitStrc* pItem, int nStamp)
{
    pItem->pItemData->dwActionStamp = nStamp;
}

// 0x00541890
static void SUNITINACTIVE_FreeInactiveMonsterNode(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pInactiveMonsterNode)
{
    if (pInactiveMonsterNode->pMapAI)
    {
        DRLGPRESET_FreeMapAI(pGame->pMemoryPool, pInactiveMonsterNode->pMapAI);
    }
    FOG_FreeServerMemory(pGame->pMemoryPool, pInactiveMonsterNode, ".\\UNIT\\SUnitInactive.cpp", 140, 0);
}

void __fastcall sub_M105_Emit_00541890(D2GameStrc* pGame, D2InactiveUnitListStrc* pList)
{
    D2InactiveMonsterNodeStrc* pCurrent = pList->pInactiveMonsters;
    while (pCurrent)
    {
        D2InactiveMonsterNodeStrc* pNode = pCurrent;
        pCurrent = pCurrent->pNext;
        AIGENERAL_FreeAllMinionLists(pGame, pNode->pMinionList);
        SUNITINACTIVE_FreeInactiveMonsterNode(pGame, pNode);
    }
}

// 0x00541970
static int sub_00541970_IsItemNodeAlive(D2InactiveItemNodeStrc* pNode, D2GameStrc* pGame)
{
    const int nFrame = pNode->nFrame;
    if (!nFrame)
        return 1;
    return pGame->dwGameFrame <= nFrame;
}

void __fastcall sub_M105_Emit_00541970(D2GameStrc* pGame, D2InactiveUnitListStrc* pList)
{
    D2InactiveItemNodeStrc* pPrevious = 0;
    D2InactiveItemNodeStrc* pCurrent = pList->pInactiveItems;
    while (pCurrent)
    {
        D2InactiveItemNodeStrc* pNext = pCurrent->pNext;
        if (!sub_00541970_IsItemNodeAlive(pCurrent, pGame))
        {
            if (pPrevious)
                pPrevious->pNext = pNext;
            else
                pList->pInactiveItems = pNext;
            FOG_FreeServerMemory(pGame->pMemoryPool, pCurrent, ".\\UNIT\\SUnitInactive.cpp", 0x723, 0);
        }
        else
        {
            pPrevious = pCurrent;
        }
        pCurrent = pNext;
    }
}
