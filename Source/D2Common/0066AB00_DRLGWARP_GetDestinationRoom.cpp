struct D2ActiveRoomStrc;
struct D2LvlWarpTxt
{
    int dwLevelId;
};

struct D2DrlgWarpStrc
{
    int nLevel;
    int nVis[8];
    int nWarp[8];
    D2DrlgWarpStrc* pNext;
};

struct D2DrlgStrc
{
    char unk0x00[0x90];
    D2DrlgWarpStrc* pWarp;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x18];
    int nLevelId;
};

struct D2LevelDefBin
{
    char unk0x00[0x68];
    int dwWarp[8];
};

struct D2DrlgRoomStrc;

struct D2RoomTileStrc
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2RoomTileStrc* pNext;
    int bEnabled;
    void* unk0x0C;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x30];
    D2ActiveRoomStrc* pRoom;
    char unk0x34[0x18];
    D2RoomTileStrc* pRoomTiles;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

extern "C" const char gszEmptyAssertText;                                                     // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                        // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);     // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                 // 0x00681E09
void __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom);                                       // 0x0061B730
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                             // 0x0061E470
D2LvlWarpTxt* __fastcall DATATBLS_GetLvlWarpTxtRecordFromLevelIdAndDirection(int nLevelId, char szDirection);                          // 0x0061F310

// 0x0066AB00
D2ActiveRoomStrc* __fastcall DRLGWARP_GetDestinationRoom(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel, int* pDestinationLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord)
{
    for (D2RoomTileStrc* pSourceRoomTile = pDrlgRoom->pRoomTiles; pSourceRoomTile; pSourceRoomTile = pSourceRoomTile->pNext)
    {
        if (pSourceRoomTile->pLvlWarpTxtRecord->dwLevelId == nSourceLevel)
        {
            D2DrlgRoomStrc* pDestinationRoom = pSourceRoomTile->pDrlgRoom;
            for (D2RoomTileStrc* pDestinationRoomTile = pDestinationRoom->pRoomTiles; pDestinationRoomTile; pDestinationRoomTile = pDestinationRoomTile->pNext)
            {
                if (pDestinationRoomTile->pDrlgRoom == pDrlgRoom)
                {
                    *pDestinationLevel = pDestinationRoomTile->pLvlWarpTxtRecord->dwLevelId;
                    *ppLvlWarpTxtRecord = pDestinationRoomTile->pLvlWarpTxtRecord;

                    if (!pDestinationRoom->pRoom)
                    {
                        DRLGACTIVATE_InitializeRoomEx(pDestinationRoom);
                    }

                    return pDestinationRoom->pRoom;
                }
            }

            return 0;
        }
    }

    return 0;
}

// 0x0066AEC0
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* pDrlgWarp = pDrlg->pWarp; pDrlgWarp; pDrlgWarp = pDrlgWarp->pNext)
    {
        if (!pDrlgWarp->nLevel)
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 418);
            exit(-1);
        }

        if (nLevelId == pDrlgWarp->nLevel)
        {
            return pDrlgWarp->nWarp;
        }
    }

    return DATATBLS_GetLevelDefRecord(nLevelId)->dwWarp;
}

inline int DRLGWARP_GetWarpDestinationFromArrayInline(D2DrlgLevelStrc* pLevel, unsigned char nWarpId)
{
    return DRLGWARP_GetWarpIdArrayFromLevelId(pLevel->pDrlg, pLevel->nLevelId)[nWarpId];
}

// 0x0066AF50
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(D2DrlgLevelStrc* pLevel, unsigned char nWarpId, char szDirection)
{
    return DATATBLS_GetLvlWarpTxtRecordFromLevelIdAndDirection(DRLGWARP_GetWarpDestinationFromArrayInline(pLevel, nWarpId), szDirection);
}

// 0x0066AF80
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromUnit(D2DrlgRoomStrc* pDrlgRoom, D2UnitStrc* pUnit)
{
    D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles;
    int nClassId;

    if (!pUnit)
    {
        nClassId = -1;
    }
    else
    {
        nClassId = pUnit->dwClassId;
    }

    while (pRoomTile)
    {
        if (pRoomTile->pLvlWarpTxtRecord->dwLevelId == (unsigned char)nClassId)
        {
            if (pRoomTile->bEnabled)
            {
                return pRoomTile->pLvlWarpTxtRecord;
            }

            return 0;
        }

        pRoomTile = pRoomTile->pNext;
    }

    return 0;
}
