struct Unicode
{
    unsigned short wChar;
};

struct D2ObjectsTxt
{
    char unk0x00[0x40];
    Unicode wszName[64];
    char f_C0[0x7A];
    unsigned char nIsDoor;
    char unk0x13B[0x36];
    unsigned char nLockable;
    char unk0x172[0x46];
    unsigned char nOpenWarp;
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    unsigned char InteractType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0xD0];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2MonStatsTxt
{
    char unk0x00[0x06];
    unsigned short wNameStr;
};

struct D2ItemsTxt
{
    char unk0x00[0xF4];
    unsigned short wNameStr;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

const Unicode* __fastcall sub_00463810_GetMonsterName(D2UnitStrc* pUnit);                                  // 0x00463810
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
const Unicode* __fastcall sub_00464A30_GetWarpName(D2ActiveRoomStrc* pRoom, D2UnitStrc* pTile);             // 0x00464A30
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall sub_00621B00_IsShrine(D2UnitStrc* pUnit);                                                     // 0x00621B00
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

// 0x00464A10
static D2UnitStrc* sub_00464A10_FindTileUnit(D2UnitStrc* pUnit)
{
    for (; pUnit; pUnit = pUnit->pRoomNext)
    {
        if (pUnit->dwUnitType == UNIT_TILE)
        {
            return pUnit;
        }
    }
    return 0;
}

const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit)
{
    const Unicode* pName;
    D2ActiveRoomStrc* pRoom;
    D2UnitStrc* pTile;
    D2ActiveRoomStrc** ppRooms;
    unsigned int nRooms;
    D2_ASSERT(pUnit, 0x99D);
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    {
        if (pUnit->pObjectData->pObjectTxt->nOpenWarp && pUnit->dwAnimMode == 2)
        {
            pRoom = UNITS_GetRoom(pUnit);
            pTile = sub_00464A10_FindTileUnit(pRoom->pUnitFirst);
            if (pTile)
            {
                return sub_00464A30_GetWarpName(pRoom, pTile);
            }
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
            for (unsigned int i = 0; i < nRooms; ++i)
            {
                if (ppRooms[i] != pRoom)
                {
                    pTile = sub_00464A10_FindTileUnit(ppRooms[i]->pUnitFirst);
                    if (pTile)
                    {
                        return sub_00464A30_GetWarpName(ppRooms[i], pTile);
                    }
                }
            }
        }
        if (pUnit->pObjectData->pObjectTxt->nIsDoor)
        {
            const int nMode = pUnit->dwAnimMode;
            unsigned short nStringId = 0xC9B;
            if (nMode == 5 || nMode == 4)
            {
                nStringId = 0xC9C;
            }
            else if (nMode == 0)
            {
                nStringId = 0xC99;
            }
            else if (nMode == 6)
            {
                nStringId = 0xC9D;
            }
            return D2LANG_GetStringFromTblIndex(nStringId);
        }
        if (sub_00621B00_IsShrine(pUnit))
        {
            return D2LANG_GetStringFromTblIndex(pUnit->pObjectData->InteractType + 0x2A39);
        }
        D2ObjectDataStrc* pObjectData = pUnit->pObjectData;
        if (pObjectData->pObjectTxt->nLockable && (pObjectData->InteractType & 0x80))
        {
            return D2LANG_GetStringFromTblIndex(0xCBE);
        }
        return pObjectData->pObjectTxt->wszName;
    }
    case UNIT_MONSTER:
    {
        pName = sub_00463810_GetMonsterName(pUnit);
        if (!sub_00526800(pName))
        {
            return D2LANG_GetStringFromTblIndex(DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId)->wNameStr);
        }
        return pName;
    }
    case UNIT_PLAYER:
    case UNIT_MISSILE:
    case UNIT_TILE:
        return 0;
    case UNIT_ITEM:
        return D2LANG_GetStringFromTblIndex(DATATBLS_GetItemsTxtRecord(pUnit->dwClassId)->wNameStr);
    }
    return 0;
}
