struct D2ActiveRoomStrc;
struct D2InactiveItemNodeStrc;
struct D2InactiveMonsterNodeStrc;
struct D2InactiveUnitNodeStrc;

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

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);               // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                           // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                              // 0x006427F0

// build: context sub_00541D20_GetListNodeFromActAndCoordinates
static D2InactiveUnitListStrc* __stdcall sub_00541D20_GetListNodeFromActAndCoordinates(D2GameStrc* pGame, int nAct, int nX, int nY, int bAllocNewNode)
{
    int bFound = 0;
    D2InactiveUnitListStrc* pCurrent = pGame->pInactiveUnitList[nAct];
    D2InactiveUnitListStrc* pPrevious = 0;
    while (pCurrent)
    {
        if (nX == pCurrent->nX && nY == pCurrent->nY)
        {
            bFound = 1;
            break;
        }

        if (nX > pCurrent->nX)
        {
            break;
        }

        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    if (!bAllocNewNode)
    {
        return bFound ? pCurrent : 0;
    }

    if (!bFound)
    {
        D2InactiveUnitListStrc* pNew = (D2InactiveUnitListStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveUnitListStrc), ".\\UNIT\\SUnitInactive.cpp", 0x424, 0);
        *(int*)&pNew->pInactiveItems = 0;
        *(int*)&pNew->pInactiveMonsters = 0;
        *(int*)&pNew->pInactiveUnits = 0;
        pNew->nX = nX;
        pNew->nY = nY;
        pNew->pNext = pCurrent;
        if (pPrevious)
        {
            pPrevious->pNext = pNew;
        }
        else
        {
            pGame->pInactiveUnitList[nAct] = pNew;
        }
        pCurrent = pNew;
    }

    return pCurrent;
}

static __declspec(noinline) D2InactiveUnitListStrc* __stdcall sub_00541DE0_GetListNodeFromRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAllocNewNode);

// 0x00541DE0
static D2InactiveUnitListStrc* __stdcall sub_00541DE0_GetListNodeFromRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAllocNewNode)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    return sub_00541D20_GetListNodeFromActAndCoordinates(pGame, nAct, tCoords.nSubtileX, tCoords.nSubtileY, bAllocNewNode);
}

D2InactiveMonsterNodeStrc* __stdcall sub_C899_Emit_00541DE0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAlloc)
{
    D2InactiveUnitListStrc* pList = sub_00541DE0_GetListNodeFromRoom(pGame, pRoom, bAlloc);
    return pList ? pList->pInactiveMonsters : 0;
}
