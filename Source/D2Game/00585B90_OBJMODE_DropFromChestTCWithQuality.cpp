extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2TCExShortStrc;
struct D2ObjectsTxt;
struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
D2ObjectsTxt* __stdcall UNITS_GetObjectTxtRecordFromObject(D2UnitStrc* pUnit);                              // 0x00621B30
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall DATATBLS_GetMonsterLevelInArea(int nLevelId, unsigned char nDifficulty, int bExpansion);      // 0x0061DCA0
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromActAndDifficulty(int nDifficulty, int nAct, int nTCIndex); // 0x00654E80
void __fastcall D2GAME_DropTC_6FC51360(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, D2TCExShortStrc* pTCTxtRecord, int nQuality, int nLvl, int a7, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems); // 0x0055A6D0
extern const int gnChestActLevelIds_006E1988[10];                                                           // 0x006E1988

// 0x00585B90
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality)
{
    D2_ASSERT(pOp->pObject, 0x1313);

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pOp->pObject);

    D2_ASSERT(pGame, 0x1315);
    D2_ASSERT(UNITS_GetObjectTxtRecordFromObject(pOp->pObject), 0x1317);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    if (!pRoom)
        return 0;

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    const unsigned char nAct = DRLG_GetActNoFromLevelId(nLevelId);

    const int nCurrentMonsterLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    const int nMinMonsterLevel = DATATBLS_GetMonsterLevelInArea(gnChestActLevelIds_006E1988[2 * nAct], pGame->nDifficulty, pGame->bExpansion);
    const int nMaxMonsterLevel = DATATBLS_GetMonsterLevelInArea(gnChestActLevelIds_006E1988[2 * nAct + 1], pGame->nDifficulty, pGame->bExpansion);

    int nMonsterLevelDiff = nMaxMonsterLevel - nMinMonsterLevel;
    if (nMonsterLevelDiff < 0)
        nMonsterLevelDiff = -nMonsterLevelDiff;

    const int nOffset = (nMonsterLevelDiff + 1) / 3;
    int nTCIndex;
    if (nCurrentMonsterLevel < nOffset + nMinMonsterLevel)
        nTCIndex = 0;
    else
        nTCIndex = (nCurrentMonsterLevel >= nMinMonsterLevel + 2 * nOffset) + 1;

    D2TCExShortStrc* pTCExRecord = DATATBLS_GetTreasureClassExRecordFromActAndDifficulty(pGame->nDifficulty, nAct, nTCIndex);
    if (!pTCExRecord)
        return 0;

    int nItemDropCount = 0;
    D2UnitStrc* ppDroppableItems[6] = {};
    D2GAME_DropTC_6FC51360(pGame, pOp->pObject, pOp->pPlayer, pTCExRecord, nItemQuality, nTCIndex, 0, ppDroppableItems, &nItemDropCount, 6);
    return ppDroppableItems[0];
}

#include "gen/data/Source/D2Game/00585B90_OBJMODE_DropFromChestTCWithQuality.inc"
