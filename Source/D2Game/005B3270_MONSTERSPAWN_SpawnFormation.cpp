struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2RoomCoordListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2UnkMonCreateStrc
{
    D2GameStrc* pGame;
    D2ActiveRoomStrc* pRoom;
    D2RoomCoordListStrc* pRoomCoordList;
    int nMonsterId;
    int nAnimMode;
    int nUnitGUID;
    int nX;
    int nY;
    int field_20;
    short nFlags;
};

struct D2UnkMonCreateStrc3
{
    int nXOffset;
    int nYOffset;
    int nSpawnType;
};

struct D2UnkMonCreateStrc2
{
    int nRecordCount;
    int unk0x04;
    unsigned char unk0x08;
    unsigned char pad0x09[3];
    D2UnkMonCreateStrc3 records[4];
};

D2UnitStrc* __fastcall D2GAME_SpawnNormalMonster_6FC68E30(D2UnkMonCreateStrc* pMonCreate); // 0x005B2A00
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
D2UnitStrc* __fastcall sub_005B3130_SpawnLeader(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nAnimMode, int a7, int a8, unsigned short nFlags); // 0x005B3130
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nAnimMode, int a7, short nFlags); // 0x005B2F20
int __fastcall sub_6FC6A230(D2GameStrc* pGame, D2UnitStrc* pOwner, int nX, int nY, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags); // 0x005B31B0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

// 0x005B3270
int __fastcall MONSTERSPAWN_SpawnFormation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pOwner, int nClassId, int nAnimMode, D2UnkMonCreateStrc2* pInfo, short nFlags)
{
    int nResult = 0;
    D2UnitStrc* pLeader = 0;
    int bForce = 0;
    int bIncrement = 0;
    if (pInfo->unk0x08 & 1) bIncrement = 1;
    if (nFlags & 1) bForce = 1;
    const int nCount = pInfo->nRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        pInfo = (D2UnkMonCreateStrc2*)pInfo->records;
        D2UnkMonCreateStrc3* pRecord = (D2UnkMonCreateStrc3*)pInfo;
        switch (bForce ? 4 : pRecord->nSpawnType)
        {
        case 1:
            pLeader = sub_005B3130_SpawnLeader(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 0, 0);
            if (pLeader) nResult = 1;
            break;
        case 2:
            pLeader = sub_005B3130_SpawnLeader(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 1, 0);
            if (pLeader) nResult = 1;
            break;
        case 5:
            if (pOwner)
            {
                D2UnitStrc* pMinion = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 0);
                if (pMinion)
                {
                    AIGENERAL_SetOwnerData(pGame, pMinion, sub_00451F50_GetUnitGUID(pOwner), sub_0044BE50_GetUnitTypeOrInvalid(pOwner), 0, 0);
                    nResult = 1;
                }
            }
            break;
        case 3:
            if (pLeader && sub_6FC6A230(pGame, pLeader, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 1, 0)) nResult = 1;
            break;
        case 0:
        {
            D2UnkMonCreateStrc monCreate;
            monCreate.nUnitGUID = 0;
            monCreate.nMonsterId = nClassId;
            monCreate.nAnimMode = nAnimMode;
            monCreate.field_20 = -1;
            monCreate.pGame = pGame;
            monCreate.pRoomCoordList = 0;
            monCreate.pRoom = pRoom;
            monCreate.nFlags = nFlags;
            monCreate.nX = nX + pRecord->nXOffset;
            monCreate.nY = nY + pRecord->nYOffset;
            if (D2GAME_SpawnNormalMonster_6FC68E30(&monCreate)) nResult = 1;
            break;
        }
        case 4:
        {
            nResult = 1;
            D2UnkMonCreateStrc monCreate;
            monCreate.nUnitGUID = 0;
            monCreate.nMonsterId = nClassId;
            monCreate.nAnimMode = nAnimMode;
            monCreate.field_20 = -1;
            monCreate.pGame = pGame;
            monCreate.pRoomCoordList = 0;
            monCreate.pRoom = pRoom;
            monCreate.nFlags = nFlags;
            monCreate.nX = nX + pRecord->nXOffset;
            monCreate.nY = nY + pRecord->nYOffset;
            if (!D2GAME_SpawnNormalMonster_6FC68E30(&monCreate)) return 0;
            break;
        }
        }
        if (bIncrement) ++nClassId;
    }
    return nResult;
}
