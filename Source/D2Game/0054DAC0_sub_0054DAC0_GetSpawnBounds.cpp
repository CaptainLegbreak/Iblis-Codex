struct D2ActiveRoomStrc;
struct tagRECT { long left; long top; long right; long bottom; };
struct D2DrlgCoordsStrc { int nSubtileX; int nSubtileY; int nSubtileWidth; int nSubtileHeight; int nTileXPos; int nTileYPos; int nTileWidth; int nTileHeight; };
struct D2SpawnAreaStrc { char unk0x00[0x10]; tagRECT tRect; };
extern "C" __declspec(dllimport) int __stdcall CopyRect(tagRECT* lprcDst, const tagRECT* lprcSrc);              // 0x006CC458
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __stdcall DUNGEON_GameTileToSubtileCoords(long* pX, long* pY);                                        // 0x00643560

// 0x0054DAC0
static void __stdcall sub_0054DAC0_GetSpawnBounds(D2ActiveRoomStrc* pRoom, int* pWidth, D2SpawnAreaStrc* pArea, int* pX, int* pY, int* pHeight)
{
    if (!pArea)
    {
        D2DrlgCoordsStrc coords;
        DUNGEON_GetRoomCoordinates(pRoom, &coords);
        *pX = coords.nSubtileX + 1;
        *pY = coords.nSubtileY + 1;
        *pWidth = coords.nSubtileWidth - 1;
        *pHeight = coords.nSubtileHeight - 1;
    }
    else
    {
        tagRECT rect;
        CopyRect(&rect, &pArea->tRect);
        DUNGEON_GameTileToSubtileCoords(&rect.left, &rect.top);
        DUNGEON_GameTileToSubtileCoords(&rect.right, &rect.bottom);
        *pX = rect.left + 1;
        *pY = rect.top + 1;
        *pWidth = rect.right - *pX;
        *pHeight = rect.bottom - *pY;
    }
}

void __stdcall sub_M96_UseBounds_0054DAC0(int nX, int nY, int nWidth, int nHeight);
void __fastcall sub_M96_Emit_0054DAC0(void* pGame, D2ActiveRoomStrc* pRoom, D2SpawnAreaStrc* pArea)
{
    int nX, nY, nWidth, nHeight;
    sub_0054DAC0_GetSpawnBounds(pRoom, &nWidth, pArea, &nX, &nY, &nHeight);
    sub_M96_UseBounds_0054DAC0(nX, nY, nWidth, nHeight);
}
