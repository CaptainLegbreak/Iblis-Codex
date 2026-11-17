struct D2GameStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPortal, int nDestLevel, int nSourceLevel); // 0x0056CF40
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit); // 0x006222C0
struct D2PortalFlags00581410Strc
{
    unsigned char nFlags;
};
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, D2PortalFlags00581410Strc tFlags); // 0x00622300
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

// 0x00581410
void __fastcall sub_00581410_OpenLinkPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    int nPortalLevel = 0x7F;
    switch (nLevelId)
    {
    case 0x6F:
        nPortalLevel = 0x7D;
        break;
    case 0x70:
        nPortalLevel = 0x7E;
        break;
    }
    D2UnitStrc* pPortal = D2GAME_CreateLinkPortal_6FD13B20(pGame, 0, pUnit, nPortalLevel, nLevelId);
    if (pPortal)
    {
        D2PortalFlags00581410Strc tFlags;
        tFlags.nFlags = UNITS_GetObjectPortalFlags(pPortal) | 3;
        UNITS_SetObjectPortalFlags(pPortal, tFlags);
    }
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pUnit), 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pPortal), 0);
}
