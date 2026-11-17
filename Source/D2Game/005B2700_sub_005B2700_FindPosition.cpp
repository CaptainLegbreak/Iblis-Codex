#ifdef MOVED_TEST
#define CENTER 7
#define MASK_A 0x102
#define MASK_B 0x1c19
#define OFFSET_BASE (g_006E2D50_offsets+1)
#else
#define CENTER 3
#define MASK_A 0x100
#define MASK_B 0x1c09
#define OFFSET_BASE (g_006E2D50_offsets)
#endif
struct D2TileLibraryEntryStrc;
struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};
struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
#ifdef MOVED_TEST
    char moved_pad[4];
#endif
    D2SeedStrc pSeed;
};
struct D2CoordStrc
{
    int nX;
    int nY;
};
struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};
struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int nPosX;
    int nPosY;
    int unk0x10;
    unsigned int dwFlags;
    D2TileLibraryEntryStrc* pTile;
    char unk0x1C[0x14];
};
typedef D2ActiveRoomStrc Room;
typedef D2DrlgTileDataStrc Tile;
typedef D2DrlgCoordsStrc Bounds;
typedef D2CoordStrc Coord;
extern Coord g_006E2D50_offsets[4];  // 0x006E2D50
D2DrlgTileDataStrc* __stdcall sub_00619660_GetFloorTiles(D2ActiveRoomStrc*,int*);
unsigned int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc*,int);
void __stdcall sub_00619730_GetCoordinates(D2ActiveRoomStrc*,D2DrlgCoordsStrc*);
int __stdcall sub_00604BC0_GetTileFlags(D2TileLibraryEntryStrc*);
unsigned short __stdcall sub_0064CB30_CheckMask(D2ActiveRoomStrc*,int,int,unsigned short);
unsigned short __stdcall sub_0064D9B0_CheckSize(D2ActiveRoomStrc*,int,int,int,unsigned short);
// 0x005B2700
int __stdcall sub_005B2700_FindPosition(Room* room,int* outX,int* outY)
{
    int count;
    Tile* tiles=sub_00619660_GetFloorTiles(room,&count);
    if (!tiles) return 0;
    if (!count) return 0;
    unsigned start=sub_0045C3E0_RollLimited(room?&room->pSeed:0,count);
    if (!start) start=1;
    Bounds bounds;
    sub_00619730_GetCoordinates(room,&bounds);
    unsigned index=start;
    unsigned stop=start-1;
    while (index!=stop) {
        Tile* tile=&tiles[index];
        if (tile->pTile && (sub_00604BC0_GetTileFlags(tile->pTile)&2)) {
            int x=5*(tile->nPosX+bounds.nTileXPos)+CENTER;
            int y=5*(tile->nPosY+bounds.nTileYPos)+CENTER;
            if (!sub_0064CB30_CheckMask(room,x,y,MASK_A)) {
                Coord* offset=OFFSET_BASE;
                do {
                    if (!sub_0064D9B0_CheckSize(room,x+offset->nX,y+offset->nY,2,MASK_B)) {
                        *outX=x;
                        *outY=y;
                        return 1;
                    }
                    ++offset;
                } while ((int)offset < (int)(OFFSET_BASE+4));
            }
        }
        index=(index+1)%(unsigned)count;
    }
    return 0;
}

#include "gen/data/Source/D2Game/005B2700_sub_005B2700_FindPosition.inc"
