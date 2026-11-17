struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2WaypointDataStrc;
struct D2GameStrc
{
    char unk0x00[109];
    unsigned char nDifficulty;
};
struct D2PlayerDataStrc
{
    char unk0x00[16];
    D2BitBufferStrc* pQuestData[3];
    D2WaypointDataStrc* pWaypointData[3];
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

// 0x00543520
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00547F50
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pWaypointData[pGame->nDifficulty];
}
