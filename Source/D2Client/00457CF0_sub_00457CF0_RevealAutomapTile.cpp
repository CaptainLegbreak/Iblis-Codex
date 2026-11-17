struct D2DrlgLevelStrc
{
    char unk0x00[0x1D0];
    int nLevelId;
};

struct D2AutomapRoomStrc
{
    char unk0x00[0x34];
    int nPosX;
    int nPosY;
    char unk0x3C[0x1C];
    D2DrlgLevelStrc* pLevel;
};

struct D2TileLibraryEntryStrc;

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int nPosX;
    int nPosY;
    int unk0x10;
    unsigned int dwFlags;
    D2TileLibraryEntryStrc* pTile;
    int nTileType;
    D2DrlgTileDataStrc* unk0x20;
    int unk0x24;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nIntensity;
    int unk0x2C;
};

struct D2AutomapCellStrc
{
    unsigned int fSaved;
    unsigned short nCellNo;
    unsigned short xPixel;
    unsigned short yPixel;
    unsigned short wWeight;
    D2AutomapCellStrc* pPrev;
    D2AutomapCellStrc* pNext;
};

struct D2AutomapLayerStrc
{
    unsigned int nLayerNo;
    unsigned int fSaved;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
};

struct D2ActiveRoomStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __stdcall sub_00642750_GetAutomapLevelType(int nLevelId);                                             // 0x00642750
int __stdcall sub_00604B60_GetTileType(D2TileLibraryEntryStrc* pTile);                                      // 0x00604B60
int __stdcall sub_00604B90_GetTileStyle(D2TileLibraryEntryStrc* pTile);                                     // 0x00604B90
int __stdcall sub_00604C50_GetTileSequence(D2TileLibraryEntryStrc* pTile);                                  // 0x00604C50
int __fastcall DATATBLS_GetAutomapCellId(void* pAutomapLevelType, int nAutomapTileType, int nStyle, int nSequence); // 0x0061FFF0
D2AutomapCellStrc* __cdecl sub_00457C30();                                                       // 0x00457C30
void __stdcall sub_00643310_MapToAutomapPos(int* pX, int* pY);                                              // 0x00643310
void __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot);              // 0x00457B00
D2AutomapRoomStrc* __fastcall sub_0061AAE0_GetAutomapRoom(D2ActiveRoomStrc* pRoom);                        // 0x0061AAE0
D2DrlgTileDataStrc* __stdcall sub_00619660_GetFloorTiles(D2ActiveRoomStrc* pRoom, unsigned int* pCount);    // 0x00619660
D2DrlgTileDataStrc* __stdcall sub_006196A0_GetWallTiles(D2ActiveRoomStrc* pRoom, unsigned int* pCount);     // 0x006196A0
void __stdcall sub_00458DC0_RevealRoomObjects(D2ActiveRoomStrc* pRoom, D2AutomapCellStrc** ppRoot);         // 0x00458DC0
int gbRevealAutomap_007A51A0;                                                                               // 0x007A51A0

// 0x00457CF0
static void __stdcall sub_00457CF0_RevealAutomapTile(D2DrlgTileDataStrc* pTileData, D2AutomapRoomStrc* pRoom, D2AutomapCellStrc** ppRoot)
{
    if (pTileData->dwFlags & 0x40000)
    {
        return;
    }
    pTileData->dwFlags |= 0x40000;
    void* pLevelType = sub_00642750_GetAutomapLevelType(pRoom->pLevel->nLevelId);
    const int nType = sub_00604B60_GetTileType(pTileData->pTile);
    const int nStyle = sub_00604B90_GetTileStyle(pTileData->pTile);
    const int nSequence = sub_00604C50_GetTileSequence(pTileData->pTile);
    const int nCell = DATATBLS_GetAutomapCellId(pLevelType, nType, nStyle, nSequence);
    if (nCell == -1)
    {
        return;
    }
    D2AutomapCellStrc* pCell = sub_00457C30();
    int nX = pRoom->nPosX + pTileData->nPosX;
    int nY = pRoom->nPosY + pTileData->nPosY;
    sub_00643310_MapToAutomapPos(&nX, &nY);
    nX /= 10;
    nY /= 10;
    D2_ASSERT(nX >= -0x8000 && nX <= 0x7FFF, 913);
    D2_ASSERT(nY >= -0x8000 && nY <= 0x7FFF, 914);
    D2_ASSERT(nCell >= -0x8000 && nCell <= 0x7FFF, 915);
    if (pTileData->nTileType >= 0x10)
    {
        nY += 0x18;
    }
    pCell->nCellNo = nCell;
    pCell->xPixel = nX;
    pCell->yPixel = nY;
    sub_00457B00(pCell, ppRoot);
}

// 0x00458F40
void __stdcall sub_00458F40_RevealRoomTiles(D2ActiveRoomStrc* pActiveRoom, int bRevealAll, D2AutomapLayerStrc* pLayer)
{
    unsigned int nCount = 0;
    D2AutomapRoomStrc* pRoom = sub_0061AAE0_GetAutomapRoom(pActiveRoom);
    D2DrlgTileDataStrc* pTiles = sub_00619660_GetFloorTiles(pActiveRoom, &nCount);
    for (unsigned int i = 0; i < nCount; i++)
    {
        D2DrlgTileDataStrc* pTileData = &pTiles[i];
        if (!(pTileData->dwFlags & 8) && ((pTileData->dwFlags & 0x20000) || gbRevealAutomap_007A51A0 || bRevealAll))
        {
            sub_00457CF0_RevealAutomapTile(pTileData, pRoom, &pLayer->pFloors);
        }
    }
    pTiles = sub_006196A0_GetWallTiles(pActiveRoom, &nCount);
    for (unsigned int i = 0; i < nCount; i++)
    {
        D2DrlgTileDataStrc* pTileData = &pTiles[i];
        if (!(pTileData->dwFlags & 8) && ((pTileData->dwFlags & 0x20000) || gbRevealAutomap_007A51A0 || bRevealAll))
        {
            sub_00457CF0_RevealAutomapTile(pTileData, pRoom, &pLayer->pWalls);
        }
    }
    sub_00458DC0_RevealRoomObjects(pActiveRoom, &pLayer->pObjects);
}
