extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DrlgActStrc;
struct D2InactiveItemNodeStrc;
struct D2InactiveUnitNodeStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xE0];
    D2UnitStrc* pRoomNext;
};
struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};
struct D2InactiveMonsterNodeStrc
{
    int nX;
    int nY;
    int nClassId;
    int nUnitId;
    unsigned int nUnitFlags;
    unsigned int nUnitFlagsEx;
    int nTypeFlags;
    char unk0x1C[0x3C];
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
    char unk0x20[0x9C];
    D2DrlgActStrc* pAct[5];
    char unk0xD0[0x08];
    D2InactiveUnitListStrc* pInactiveUnitList[5];
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomBySubtile(D2ActiveRoomStrc* pRoom, int nX, int nY);       // 0x00463740
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(D2DrlgActStrc* pAct, int nX, int nY);                    // 0x00619DA0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0

__declspec(noinline) static D2InactiveUnitListStrc* __stdcall sub_00541D20_GetListNodeFromActAndCoordinates(D2GameStrc* pGame, int nAct, int nX, int nY, int bAllocNewNode);
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

    if (bFound)
    {
        return pCurrent;
    }

    D2InactiveUnitListStrc* pNew = (D2InactiveUnitListStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveUnitListStrc), ".\\UNIT\\SUnitInactive.cpp", 0x424, 0);
    pNew->pInactiveItems = 0;
    pNew->pInactiveMonsters = 0;
    pNew->pInactiveUnits = 0;
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
    return pNew;
}

// 0x005429B0
int __fastcall sub_005429B0_IsDeadMonsterAt(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId)
{
    D2_ASSERT(pGame, 0x6DA);
    D2_ASSERT(pRoom, 0x6DB);
    D2_ASSERT(nX && nY, 0x6DC);

    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomBySubtile(pRoom, nX, nY);
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    if (!pTargetRoom)
    {
        pTargetRoom = sub_00619DA0_ActLookup(pGame->pAct[nAct], nX, nY);
    }

    if (pTargetRoom)
    {
        for (D2UnitStrc* pUnit = pTargetRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        {
            if ((!pUnit ? 6 : pUnit->dwUnitType) == 1 && pUnit->dwClassId == nClassId && SUNIT_IsDead(pUnit))
            {
                return 1;
            }
        }
    }

    D2InactiveUnitListStrc* pList = sub_00541D20_GetListNodeFromActAndCoordinates(pGame, nAct, nX, nY, 0);
    if (pList)
    {
        for (D2InactiveMonsterNodeStrc* pNode = pList->pInactiveMonsters; pNode; pNode = pNode->pNext)
        {
            if (pNode->nClassId == nClassId && (pNode->nTypeFlags & 4))
            {
                return 1;
            }
        }
    }

    return 0;
}
