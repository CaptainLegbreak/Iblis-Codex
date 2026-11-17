struct D2GameStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MissilesTxt
{
    char pad0x000[0x4C];
    int dwHitPar[3];
    char pad0x058[0x14C];
};

typedef char D2MissilesTxt_size_check[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];

struct D2DataTablesStrc
{
    char pad0x000[0xA80];
    int nMonStatsTxtRecordCount;
    char pad0xA84[0xE0];
    D2MissilesTxt* pMissilesTxt;
    char pad0xB68[0x04];
    int nMissilesTxtRecordCount;
};

#define MONMODE_NEUTRAL 1

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

// 0x005AA1C0
int __fastcall sub_005AA1C0(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;

    pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->dwHitPar[0] >= 0 && pMissilesTxtRecord->dwHitPar[0] < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nSpawnMode = MONMODE_NEUTRAL;
        if (pMissilesTxtRecord->dwHitPar[1] >= 0 && pMissilesTxtRecord->dwHitPar[1] < 16)
        {
            nSpawnMode = pMissilesTxtRecord->dwHitPar[1];
        }

        D2GAME_SpawnPresetMonster_6FC66560(pGame, UNITS_GetRoom(pMissile), pMissilesTxtRecord->dwHitPar[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), nSpawnMode);
    }

    return 1;
}
