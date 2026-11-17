struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2SeedStrc;

struct D2UnitStrc
{
    char unk0x00[0xC4];
    unsigned int dwFlagEx;
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

D2UnitStrc* __fastcall sub_0054E600_SpawnPresetMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600
D2UnitStrc* __fastcall sub_0054F490_SpawnPresetObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054F490
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int a4); // 0x00557AB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

// 0x005557D0
D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId, int nX, int nY, int nMode, int nUnitFlags)
{
    D2UnitStrc* pUnit = 0;

    switch (nUnitType)
    {
    case 2:
        if (nClassId > 573)
        {
            pUnit = sub_0054F490_SpawnPresetObject(pGame, pRoom, nClassId, nX, nY, nMode);
            break;
        }
        if (nClassId == 573)
        {
            return 0;
        }

    default:
        pUnit = SUNIT_AllocUnitData(nUnitType, nClassId, nX, nY, pGame, pRoom, 1, nMode, 0);
        if (nUnitType == 4 && pUnit)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.nQuality = 2;
            itemDrop.nItemLvl = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (!D2GAME_InitItemStats_6FC4E520(pGame, &pUnit, &itemDrop, 1))
            {
                SUNIT_RemoveUnit(pGame, pUnit);
                return 0;
            }
        }
        if (pUnit)
        {
            pUnit->dwFlagEx |= 0x3000000;
        }
        return pUnit;

    case 1:
        pUnit = sub_0054E600_SpawnPresetMonster(pGame, pRoom, nClassId, nX, nY, nMode);
        break;
    }

    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x3000000;
    }

    return pUnit;
}
