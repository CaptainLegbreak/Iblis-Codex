struct D2GameStrc;

void __fastcall MONSTER_RemoveAll(D2GameStrc* pGame);                                                       // 0x00573640
void __fastcall OBJECTS_RemoveAll(D2GameStrc* pGame);                                                       // 0x00552A40
void __fastcall PLAYER_RemoveAllPlayers(D2GameStrc* pGame);                                                 // 0x00534A50
void __fastcall ITEMS_RemoveAll(D2GameStrc* pGame);                                                         // 0x00557F10
void __fastcall MISSILES_RemoveAll(D2GameStrc* pGame);                                                      // 0x0059F840
void __fastcall sub_00555770_RemoveAllTiles(D2GameStrc* pGame);                                             // 0x00555770

// 0x0053AFD0
void __fastcall LEVEL_RemoveAllUnits(D2GameStrc* pGame)
{
    MONSTER_RemoveAll(pGame);
    OBJECTS_RemoveAll(pGame);
    PLAYER_RemoveAllPlayers(pGame);
    ITEMS_RemoveAll(pGame);
    MISSILES_RemoveAll(pGame);
    sub_00555770_RemoveAllTiles(pGame);
}
