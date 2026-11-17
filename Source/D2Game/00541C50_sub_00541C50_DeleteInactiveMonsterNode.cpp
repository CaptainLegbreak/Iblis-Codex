#define UNIT_MONSTER 1

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
    char unk0x00[0x08];
    int nUnitType;
    int nClassId;
    char unk0x10[0x20];
    D2InactiveUnitNodeStrc* pNext;
};

struct D2InactiveMonsterNodeStrc
{
    char unk0x00[0x08];
    int nClassId;
    char unk0x0C[0x14];
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

// 0x00541C50
static void sub_00541C50_DeleteInactiveMonsterNode(D2GameStrc* pGame, unsigned short nClassId, unsigned char nAct)
{
    D2InactiveUnitListStrc* pInactiveUnitList = pGame->pInactiveUnitList[nAct];
    while (pInactiveUnitList)
    {
        D2InactiveMonsterNodeStrc* pInactiveMonsterNode = pInactiveUnitList->pInactiveMonsters;
        D2InactiveMonsterNodeStrc* pPreviousMonsterNode = 0;
        while (pInactiveMonsterNode)
        {
            if (pInactiveMonsterNode->nClassId == nClassId)
            {
                if (pInactiveMonsterNode == pInactiveUnitList->pInactiveMonsters)
                {
                    pInactiveUnitList->pInactiveMonsters = pInactiveMonsterNode->pNext;
                }
                else
                {
                    pPreviousMonsterNode->pNext = pInactiveMonsterNode->pNext;
                }
                AIGENERAL_FreeAllMinionLists(pGame, pInactiveMonsterNode->pMinionList);
                SUNITINACTIVE_FreeInactiveMonsterNode(pGame, pInactiveMonsterNode);
                return;
            }
            pPreviousMonsterNode = pInactiveMonsterNode;
            pInactiveMonsterNode = pInactiveMonsterNode->pNext;
        }
        pInactiveUnitList = pInactiveUnitList->pNext;
    }
}

// 0x00543140
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct)
{
    if (nUnitType == UNIT_MONSTER)
    {
        sub_00541C50_DeleteInactiveMonsterNode(pGame, nClassId, nAct);
        return;
    }
    D2InactiveUnitListStrc* pInactiveUnitList = pGame->pInactiveUnitList[nAct];
    while (pInactiveUnitList)
    {
        D2InactiveUnitNodeStrc* pInactiveUnitNode = pInactiveUnitList->pInactiveUnits;
        D2InactiveUnitNodeStrc* pPreviousUnitNode = 0;
        while (pInactiveUnitNode)
        {
            if (pInactiveUnitNode->nUnitType == nUnitType && pInactiveUnitNode->nClassId == nClassId)
            {
                if (pInactiveUnitNode == pInactiveUnitList->pInactiveUnits)
                {
                    pInactiveUnitList->pInactiveUnits = pInactiveUnitNode->pNext;
                }
                else
                {
                    pPreviousUnitNode->pNext = pInactiveUnitNode->pNext;
                }
                FOG_FreeServerMemory(pGame->pMemoryPool, pInactiveUnitNode, ".\\UNIT\\SUnitInactive.cpp", 804, 0);
                return;
            }
            pPreviousUnitNode = pInactiveUnitNode;
            pInactiveUnitNode = pInactiveUnitNode->pNext;
        }
        pInactiveUnitList = pInactiveUnitList->pNext;
    }
}
