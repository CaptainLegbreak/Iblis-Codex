struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};
struct D2MissilesTxt
{
    int unk0x00;
    unsigned char nFlags[4];
    short unk0x08[2];
    short wSrvDoFunc;
    char unk0x0E[0x196];
};
struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};
enum
{
    MISSILESFLAGINDEX_TOWN = 10,
    MISSILESFLAGINDEX_SRCTOWN = 11,
};
typedef int(__fastcall* MISSMODE_SRVDO)(D2GameStrc* pGame, D2UnitStrc* pMissile);
extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern unsigned int gdwBitMasks[];                                                                           // 0x006CE268
extern MISSMODE_SRVDO gMissileSrvDoFuncTable_0073C768[];                                                     // 0x0073C768
extern int gnMissileSrvDoFuncCount_0073C71C;                                                                 // 0x0073C71C
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                          // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                          // 0x0045ADF0
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                 // 0x00552FD0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                 // 0x0061AB00
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                      // 0x00555600

inline D2MissilesTxt* GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static __forceinline int IsUnitInTown(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    return pRoom && DUNGEON_IsRoomInTown(pRoom);
}

// 0x005ADBB0
static __declspec(noinline) void __stdcall sub_005ADBB0_MISSMODE_SrvDo(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSrvDoFunc <= 0 || pMissilesTxtRecord->wSrvDoFunc >= gnMissileSrvDoFuncCount_0073C71C)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
    {
        pRoom = COLLISION_GetRoomBySubTileCoordinates(0, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if ((pMissilesTxtRecord->nFlags[MISSILESFLAGINDEX_SRCTOWN >> 3] & gdwBitMasks[MISSILESFLAGINDEX_SRCTOWN & 7]) && pOwner && IsUnitInTown(pOwner)
        || pOwner && pOwner->dwUnitType == 0 && IsUnitInTown(pOwner)
        || !(pMissilesTxtRecord->nFlags[MISSILESFLAGINDEX_TOWN >> 3] & gdwBitMasks[MISSILESFLAGINDEX_TOWN & 7]) && DUNGEON_IsRoomInTown(pRoom)
        || gMissileSrvDoFuncTable_0073C768[pMissilesTxtRecord->wSrvDoFunc](pGame, pMissile) == 2)
    {
        SUNIT_RemoveUnit(pGame, pMissile);
    }
}

// 0x005ADCC0
void __fastcall sub_005ADCC0(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused)
{
    sub_005ADBB0_MISSMODE_SrvDo(pGame, pMissile);
}

#include "gen/data/Source/D2Game/005ADBB0_sub_005ADBB0_MISSMODE_SrvDo.inc"
