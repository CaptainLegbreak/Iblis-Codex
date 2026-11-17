struct D2MapAIStrc;
struct D2MinionListStrc;

struct D2InactiveItemNodeStrc
{
    D2InactiveItemNodeStrc* pNext;
    int nFrame;
    int nOwnerId;
};

struct D2InactiveUnitNodeStrc
{
    char unk0x00[0x30];
    D2InactiveUnitNodeStrc* pNext;
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
    D2InactiveUnitNodeStrc* pInactiveUnits;
    D2InactiveUnitListStrc* pNext;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0xB8];
    D2InactiveUnitListStrc* pInactiveUnitList[5];
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall DRLGPRESET_FreeMapAI(void* pMemPool, D2MapAIStrc* pMapAi);                                  // 0x00666130
void __fastcall AIGENERAL_FreeAllMinionLists(D2GameStrc* pGame, D2MinionListStrc* pMinionList);             // 0x0058F350

static void SUNITINACTIVE_FreeInactiveMonsterNode(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pInactiveMonsterNode)
{
    if (pInactiveMonsterNode->pMapAI)
    {
        DRLGPRESET_FreeMapAI(pGame->pMemoryPool, pInactiveMonsterNode->pMapAI);
    }
    FOG_FreeServerMemory(pGame->pMemoryPool, pInactiveMonsterNode, ".\\UNIT\\SUnitInactive.cpp", 140, 0);
}

// 0x00541CD0
static void sub_00541CD0_FreeInactiveMonsters(D2GameStrc* pGame, D2InactiveUnitListStrc* pList)
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

// 0x00543080
void __fastcall SUNITINACTIVE_FreeInactiveUnitLists(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        D2InactiveUnitListStrc* pNextList = pGame->pInactiveUnitList[i];
        while (pNextList)
        {
            D2InactiveUnitListStrc* pCurrentList = pNextList;
            pNextList = pCurrentList->pNext;
            D2InactiveUnitNodeStrc* pNextUnit = pCurrentList->pInactiveUnits;
            while (pNextUnit)
            {
                D2InactiveUnitNodeStrc* pUnit = pNextUnit;
                pNextUnit = pNextUnit->pNext;
                FOG_FreeServerMemory(pGame->pMemoryPool, pUnit, ".\\UNIT\\SUnitInactive.cpp", 666, 0);
            }
            D2InactiveItemNodeStrc* pItem = pCurrentList->pInactiveItems;
            while (pItem)
            {
                D2InactiveItemNodeStrc* pNextItem = pItem->pNext;
                FOG_FreeServerMemory(pGame->pMemoryPool, pItem, ".\\UNIT\\SUnitInactive.cpp", 676, 0);
                pItem = pNextItem;
            }
            sub_00541CD0_FreeInactiveMonsters(pGame, pCurrentList);
            FOG_FreeServerMemory(pGame->pMemoryPool, pCurrentList, ".\\UNIT\\SUnitInactive.cpp", 683, 0);
        }
    }
}
