struct D2ActiveRoomStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2CoordStrc { int nX; int nY; };
struct D2UnitStrc { char pad[0x20]; D2SeedStrc pSeed; };
struct D2MonStatsTxt { char pad[0x18]; short wMonStatsEx; char pad2[0x1a8 - 0x1a]; };
struct D2MonStats2Txt { char pad[8]; signed char nSizeX; char pad2[0x134 - 9]; };
struct D2DataTablesStrc {
    char pad[0xA78]; D2MonStatsTxt* pMonStatsTxt; char pad1[4]; int nMonStatsTxtRecordCount;
    char pad2[0xA90 - 0xA84]; D2MonStats2Txt* pMonStats2Txt; char pad3[4]; int nMonStats2TxtRecordCount;
};

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* room, int x, int y); // 0x00463740
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static __forceinline D2MonStats2Txt* GetMonStats2(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nEx >= 0 && nEx < sgptDataTables->nMonStats2TxtRecordCount)
            return &sgptDataTables->pMonStats2Txt[nEx];
    }
    return 0;
}

// 0x0046C320
void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2MonStats2Txt* pTxt = GetMonStats2(nMonsterId);
    if (!pTxt)
        return;

    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);
    for (int i = 0; i < 10; ++i)
    {
        unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        const int nX = tCoord.nX + (unsigned int)lSeed % 5 - 2;
        lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        const int nY = tCoord.nY + (unsigned int)lSeed % 5 - 2;
        pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
        if (!COLLISION_CheckMaskWithSize(pRoom, nX, nY, pTxt->nSizeX, 0x3F11))
        {
            sub_00466730_SpawnPresetUnit(nMonsterId, nX, nY, 1, 0);
            --nCount;
        }
        if (nCount <= 0)
            break;
    }
}
