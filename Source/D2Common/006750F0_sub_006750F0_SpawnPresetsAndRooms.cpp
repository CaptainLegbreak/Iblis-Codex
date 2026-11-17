struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgGridStrc
{
    int unk_00[5];
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
    void* pVertex;
    int nVertices;
    int nGridWidth;
    int nGridHeight;
};

struct D2DrlgLevelStrc
{
    int unk_000[5];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    int unk_018;
    D2DrlgCoordStrc pLevelCoords;
    char unk_02C[0x194];
    int nLevelType;
    D2SeedStrc pSeed;
};

struct D2DrlgMapStrc;
struct D2DrlgRoomStrc;

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed); // 0x00666ED0
int __fastcall DRLGPRESET_SetPickedFileInDrlgMap(D2DrlgMapStrc* pDrlgMap, int nPickedFile); // 0x00666EC0
D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom); // 0x00667ED0
D2DrlgRoomStrc* __fastcall sub_0067D540(D2DrlgLevelStrc* pLevel, int nX, int nY, int nWidth, int nHeight, unsigned int dwRoomFlags, unsigned int dwOutdoorFlags, int nOutdoor58, int nRoom50); // 0x0067D540

static __declspec(noinline) void sub_006750F0_SpawnPresetsAndRooms(D2DrlgLevelStrc* pLevel);

// 0x006750F0
static void sub_006750F0_SpawnPresetsAndRooms(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nLevelFlags = 0;
    switch (pLevel->nLevelType)
    {
    case 2:
        nLevelFlags = 0x44103;
        break;
    case 16:
        nLevelFlags = 1;
        break;
    case 21:
        nLevelFlags = 4;
        break;
    case 22:
        nLevelFlags = 1;
        break;
    case 27:
        nLevelFlags = 1;
        break;
    case 28:
        nLevelFlags = 1;
        break;
    case 30:
        nLevelFlags = 0x11;
        break;
    case 31:
        nLevelFlags = 0x11;
        break;
    }

    int nPosY = pLevel->pLevelCoords.nPosY;
    for (int nY = 0; nY < pOutdoors->nGridHeight; ++nY)
    {
        int nPosX = pLevel->pLevelCoords.nPosX;
        for (int nX = 0; nX < pOutdoors->nGridWidth; ++nX)
        {
            const int nRoomFlags = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[1], nX, nY);
            const unsigned int dwCellFlags = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY);
            if (dwCellFlags & 0x200)
            {
                const int nLvlPrestId = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], nX, nY);
                if (nLvlPrestId)
                {
                    D2DrlgCoordStrc tDrlgCoord;
                    tDrlgCoord.nPosX = nPosX;
                    tDrlgCoord.nPosY = nPosY;
                    tDrlgCoord.nWidth = 0;
                    tDrlgCoord.nHeight = 0;
                    D2DrlgMapStrc* pDrlgMap = DRLGPRESET_AllocDrlgMap(pLevel, nLvlPrestId, &tDrlgCoord, &pLevel->pSeed);
                    DRLGPRESET_SetPickedFileInDrlgMap(pDrlgMap, (dwCellFlags >> 16) & 0xF);
                    DRLGPRESET_BuildArea(pLevel, pDrlgMap, nRoomFlags, 0);
                }
            }
            else if (!(dwCellFlags & 0x100))
            {
                const int nOutdoorEntry = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[3], nX, nY);
                sub_0067D540(pLevel, nPosX, nPosY, 8, 8, nRoomFlags, dwCellFlags, nOutdoorEntry, nLevelFlags);
            }

            nPosX += 8;
        }

        nPosY += 8;
    }
}

void __fastcall sub_006750F0_EmitSpawnPresetsAndRooms(D2DrlgLevelStrc* pLevel)
{
    sub_006750F0_SpawnPresetsAndRooms(pLevel);
}
