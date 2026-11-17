struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int dwFlags;
};

struct D2RoomCoordListStrc
{
    D2DrlgCoordStrc pBox[2];
    int bNode;
    int bRoomActive;
    int nIndex;
    D2RoomCoordListStrc* pNext;
};

struct D2DrlgLogicalRoomInfoStrc
{
    int dwFlags;
    int nLists;
    D2DrlgGridStrc pIndexX;
    D2DrlgGridStrc pIndexY;
    D2RoomCoordListStrc* pCoordList;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x34];
    D2DrlgCoordStrc tCoords;
    char unk0x44[0x20];
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo;
};

extern "C" const char gszEmptyAssertText;                                                     // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                        // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);     // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                 // 0x00681E09
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                  // 0x0067C570

static D2RoomCoordListStrc* sub_0066CDA0(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY);
__declspec(noinline) static D2RoomCoordListStrc* sub_0066CDA0(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY);

// 0x0066CDA0
static D2RoomCoordListStrc* sub_0066CDA0(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    if (!pDrlgRoom->pLogicalRoomInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 668);
        exit(-1);
    }

    if (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1)
    {
        return pDrlgRoom->pLogicalRoomInfo->pCoordList;
    }

    nY -= pDrlgRoom->tCoords.nPosY;
    nX -= pDrlgRoom->tCoords.nPosX;
    return (D2RoomCoordListStrc*)DRLGGRID_GetGridEntry(&pDrlgRoom->pLogicalRoomInfo->pIndexY, nX, nY);
}

int __fastcall sub_0066CDA0_EmitGetCoordListIndex(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    D2RoomCoordListStrc* pRoomCoordList = sub_0066CDA0(pDrlgRoom, nX, nY);
    if (pRoomCoordList)
    {
        return pRoomCoordList->nIndex;
    }

    return -1;
}
