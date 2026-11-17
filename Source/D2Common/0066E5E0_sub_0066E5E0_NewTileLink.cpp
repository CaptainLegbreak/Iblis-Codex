struct D2DrlgTileDataStrc;

struct D2DrlgTileLinkStrc
{
    int bFloor;
    D2DrlgTileDataStrc* pMapTile;
    D2DrlgTileLinkStrc* pNext;
};

struct D2DrlgTileGridStrc
{
    D2DrlgTileLinkStrc* pMapLinks;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x54];
    D2DrlgTileGridStrc* pTileGrid;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall sub_M105_EmitSink_0066E5E0(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY);

// 0x0066E5E0
static D2DrlgTileLinkStrc* __stdcall sub_0066E5E0_NewTileLink(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int bFloor)
{
    D2DrlgTileLinkStrc* pTileLink = (D2DrlgTileLinkStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgTileLinkStrc), ".\\DRLG\\RoomTile.cpp", 891, 0);
    pTileLink->bFloor = bFloor;
    pTileLink->pMapTile = 0;
    pTileLink->pNext = pDrlgRoom->pTileGrid->pMapLinks;
    pDrlgRoom->pTileGrid->pMapLinks = pTileLink;
    return pTileLink;
}

void __fastcall sub_M105_Emit_0066E5E0(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int nTileType, int nX, int nY)
{
    D2DrlgTileLinkStrc* pCurLink;
    for (pCurLink = pDrlgRoom->pTileGrid->pMapLinks; pCurLink; pCurLink = pCurLink->pNext)
    {
        if ((pCurLink->bFloor && nTileType == 0) || (!pCurLink->bFloor && nTileType != 0))
            break;
    }
    if (!pCurLink)
        pCurLink = sub_0066E5E0_NewTileLink(pMemPool, pDrlgRoom, nTileType == 0);
    sub_M105_EmitSink_0066E5E0(pDrlgRoom, &pCurLink->pMapTile, nX, nY);
}
