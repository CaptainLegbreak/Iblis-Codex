struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromPopulatedRoom(D2ActiveRoomStrc* pRoom);                                 // 0x0061A1F0
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId);                                      // 0x0063EC70
D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

// 0x005B2490
D2UnitStrc* __fastcall sub_6FC6A150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!DUNGEON_GetLevelIdFromPopulatedRoom(pRoom))
    {
        return 0;
    }

    const int nSpawnMonsterId = D2Common_11063(pRoom, nMonsterId);
    return sub_6FC68D70(pGame, pUnit, nSpawnMonsterId, nAnimMode, a5, nFlags);
}
