struct D2ActiveRoomStrc;
struct D2MonStatsTxt { short nId; short nBaseId; unsigned char pad004[0x1A4]; };
struct D2DataTablesStrc { unsigned char pad000[0xA78]; D2MonStatsTxt* pMonStatsTxt; int unknownA7C; int nMonStatsTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtCoords(D2ActiveRoomStrc*, int, int); // 0x00463740
unsigned short __stdcall sub_0064D9B0_CheckSize(D2ActiveRoomStrc*, int, int, int, unsigned short); // 0x0064D9B0
static __forceinline D2MonStatsTxt* GetMonStatsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nId];
    return 0;
}
static __forceinline int GetMonsterBaseId(int nId)
{
    D2MonStatsTxt* pRecord = GetMonStatsTxtRecord(nId);
    if (!pRecord)
        return nId;
    return pRecord->nBaseId;
}
static __forceinline int ValidateMonsterId(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        return nId;
    return -1;
}
// 0x005FD350
int __fastcall sub_005FD350_CheckMonsterCollision(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int nFlag)
{
    switch (ValidateMonsterId(GetMonsterBaseId(nMonsterId)))
    {
    case 206:
    {
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtCoords(pRoom, nX, nY + 3);
        if (!pTargetRoom)
            return 0;
        if (sub_0064D9B0_CheckSize(pTargetRoom, nX, nY + 3, 2, 0x3C01))
            return 0;
        break;
    }
    case 228:
        nY += 2;
        pRoom = sub_00463740_FindRoomAtCoords(pRoom, nX, nY);
        if (!pRoom)
            return 0;
        if (sub_0064D9B0_CheckSize(pRoom, nX, nY, 2, 0x3C01))
            return 0;
        break;
    case 298:
        if (!nFlag)
        {
            pRoom = sub_00463740_FindRoomAtCoords(pRoom, nX, nY);
            if (!pRoom)
                return 0;
            if (sub_0064D9B0_CheckSize(pRoom, nX, nY, 2, 0x3C01))
                return 0;
        }
        break;
    case 334:
    {
        int nAdjustedX = nX - 2;
        int nAdjustedY = nY - 2;
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtCoords(pRoom, nAdjustedX, nAdjustedY);
        if (!pTargetRoom)
            return 0;
        if (sub_0064D9B0_CheckSize(pTargetRoom, nAdjustedX, nAdjustedY, 2, 0x1C0))
            return 0;
        break;
    }
    case 528:
    {
        nX += 2;
        nY += 4;
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtCoords(pRoom, nX, nY);
        if (!pTargetRoom)
            return 0;
        if (sub_0064D9B0_CheckSize(pTargetRoom, nX, nY, 2, 0x3C01))
            return 0;
        break;
    }
    }
    return 1;
}
