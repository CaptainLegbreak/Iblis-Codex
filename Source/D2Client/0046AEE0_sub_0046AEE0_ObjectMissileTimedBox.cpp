struct D2UnitStrc;
struct D2ActiveRoomStrc;

struct D2MissilesTxt
{
    char unk0x000[0x38];
    int dwParam[5];
    char unk0x04C[0x4A];
    short wRange;
    char unk0x098[0x10C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
void __fastcall sub_0046AE50_StartTimedBox(int nFadeIn, int nHold, int nFadeOut, int nLevelId, int bForce);  // 0x0046AE50
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// 0x0046AEE0
void __cdecl sub_0046AEE0_ObjectMissileTimedBox()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(pRoom, 2, 0x11);
    if (!pObject)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pObject);
    const int nY = CLIENTS_GetUnitY(pObject);
    sub_004CDB40_SubmitRequest(pPlayer, 0x120, nX, nY, 0, 1);

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(0x120);
    sub_0046AE50_StartTimedBox(pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->wRange - 2 * pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->dwParam[0], 4, 1);
}
