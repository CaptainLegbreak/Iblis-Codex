#define COORD_INDEX 0
#define SUBTILE_COUNT_PER_TILE 5
// 0x00643560
void __stdcall sub_00643560_GameTileToSubtileCoords(int* pX, int* pY)
{
    pX[COORD_INDEX] *= SUBTILE_COUNT_PER_TILE;
    pY[COORD_INDEX] *= SUBTILE_COUNT_PER_TILE;
}
