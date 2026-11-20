#include "D2Common.h"
#include "D2Structs.h"

#pragma intrinsic(memset)

struct D2DrlgVertexStrc;
struct D2LevelFileListStrc;
struct D2DrlgRoomSubStrc;
struct D2DrlgCoordStrc;
struct D2MapAIPathPositionStrc;
struct D2MapAIStrc;
struct D2PresetUnitStrc;
struct D2LvlPrestTxt;
union D2C_PackedTileInformation;
struct D2DrlgMapStrc;
struct D2DrlgPresetRoomStrc;
struct D2DrlgPresetLevelStrc;
struct D2DrlgStrc;
struct D2SeedStrc;
struct D2CoordStrc;
struct D2StormLinkStrc;
struct D2StormListStrc;
struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
struct D2Unk00667420CStrc;
struct D2Unk00667420BStrc;
struct D2Unk00667420Strc;
struct D2ObjectsTxt;
struct D2DrlgTileInfoStrc;
struct D2RoomTileGridStrc;
struct D2DrlgRoomStrc;
struct D2DrlgGridStrc;
struct D2DrlgFileStrc;
struct D2DrlgLevelStrc;
struct D2DataTablesStrc;
struct D2DrlgPresetInfoStrc;

struct D2LevelFileListStrc
{
    char szPath[0x104];
    long nRefCount;
    D2DrlgFileStrc* pFile;
    D2LevelFileListStrc* pNext;
};

struct D2DrlgRoomSubStrc
{
    char unk0x00[0xEC];
    int nFieldEC;
};


struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x14];
    D2SeedStrc pSeed;
    char unk0x1C[0x4];
    union
    {
        D2DrlgRoomSubStrc* pSub20;
        D2DrlgPresetRoomStrc* pMaze;
    };
    char unk0x24[0x4];
    unsigned int dwFlags;
    char unk0x2C[0x8];
    union
    {
        struct
        {
            D2DrlgCoordStrc pDrlgCoord;
        };
        struct
        {
            int nTileXPos;
            int nTileYPos;
            int nTileWidth;
            int nTileHeight;
        };
    };
    char unk0x44[0x4];
    int nType;
    char unk0x4C[0x4];
    unsigned int dwDT1Mask;
    D2RoomTileGridStrc* pTileGrid;
    D2DrlgLevelStrc* pLevel;
};

extern D2LevelFileListStrc* gpLevelFilesList; // 0x0096D60C

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int nFlags;
};

struct D2MapAIPathPositionStrc
{
    int nMapAIAction;
    int nX;
    int nY;
};

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    D2MapAIStrc* pMapAI;
    int nUnitType;
    int nYpos;
    int bSpawned;
};

struct D2DrlgFileStrc
{
    char unk0x00[0x0C];
    int nWidth;
    int nHeight;
    int nWallLayers;
    int nFloorLayers;
    void* pTileTypeLayer[4];
    void* pWallLayer[4];
    void* pFloorLayer[2];
    unsigned char unk_44[0x10];
    D2PresetUnitStrc* pPresetUnit;
};

struct D2LvlPrestTxt
{
    int dwDef;
    int unk0x04;
    int dwPopulate;
    int dwLogicals;
    int dwOutdoors;
    int dwAnimate;
    int dwKillEdge;
    int dwFillBlanks;
    int unk0x20;
    int nAnimSpeed;
    int nSizeX;
    int nSizeY;
    unsigned char unk_30[0x4];
    int dwScan;
    int dwPops;
    unsigned char unk_3C[0x4];
    int dwFiles;
    char szFile[6][60];
    unsigned int dwDt1Mask;
};

union D2C_PackedTileInformation
{
    unsigned int nPackedValue;
    struct
    {
        unsigned int bIsWall : 1;
        unsigned int bIsFloor : 1;
        unsigned int bLOS : 1;
        unsigned int bEnclosed : 1;
        unsigned int bExit : 1;
        unsigned int bUnk0x20 : 1;
        unsigned int bLayerBelow : 1;
        unsigned int bLayerAbove : 1;
        unsigned int nTileSequence : 8;
        unsigned int bFillLOS : 1;
        unsigned int bUnwalkable : 1;
        unsigned int nWallLayer : 2;
        unsigned int nTileStyle : 6;
        unsigned int bRevealHidden : 1;
        unsigned int bShadow : 1;
        unsigned int bLinkage : 1;
        unsigned int bObjectWall : 1;
        unsigned int bUnk0x40000000 : 1;
        unsigned int bHidden : 1;
    };
};

struct D2DrlgMapStrc
{
    int nLevelPrest;
    int nPickedFile;
    D2LvlPrestTxt* pLvlPrestTxtRecord;
    D2DrlgFileStrc* pFile;
    D2DrlgCoordStrc pDrlgCoord;
    D2DrlgVertexStrc* pVertices;
    D2DrlgGridStrc pMapGrid;
    D2PresetUnitStrc* pPresetUnit;
    int bInited;
    int nPops;
    int* pPopsIndex;
    int* pPopsSubIndex;
    int* pPopsOrientation;
    D2DrlgCoordStrc* pPopsLocation;
    D2DrlgMapStrc* pNext;
};

struct D2DrlgPresetRoomStrc
{
    int nLevelPrest;
    int nPickedFile;
    D2DrlgMapStrc* pMap;
    unsigned int dwFlags;
    D2DrlgGridStrc pWallGrid[4];
    D2DrlgGridStrc pTileTypeGrid[4];
    D2DrlgGridStrc pFloorGrid[2];
    D2DrlgGridStrc pCellGrid;
    D2DrlgGridStrc* pMazeGrid;
    D2CoordStrc* pTombStoneTiles;
    int nTombStoneTiles;
};

struct D2DrlgPresetLevelStrc
{
    D2DrlgMapStrc* pDrlgMap;
};

struct D2DrlgStrc
{
    char unk0x000[0x464];
    void* hArchive;
    char unk0x468[0x10];
    void* pMempool;
};

struct D2DrlgTileInfoStrc
{
    int nPosX;
    int nPosY;
    int nTileIndex;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x14];
    D2DrlgPresetInfoStrc* pPreset;
    unsigned char unk_18[0x14];
    D2DrlgTileInfoStrc pTileInfo[32];
    unsigned char unk_1AC[0x4];
    D2DrlgMapStrc* pCurrentMap;
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int nLevelId;
    char unk0x1D4[0x04];
    int nTileInfo;
};

struct D2PresetUnitStrc* __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY); // 0x0066BF30
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
void __fastcall DRLGGRID_AssignCellsOffsetsAndFlags(D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth, int* pBuffer); // 0x0067CD30
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid); // 0x0067CDC0
void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed); // 0x00667620

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct D2CoordStrc
{
    int nX;
    int nY;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern unsigned short gwValue_0077905C;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

struct D2Storm416A90Strc
{
    char pad00[0x14C];
    int n14C;
    int n150;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId); // 0x0061F0B0

struct D2Unk00667420CStrc
{
    char unk0x00[0x20];
    int n20;
};

struct D2Unk00667420BStrc
{
    D2Unk00667420CStrc* p00;
};

struct D2Unk00667420Strc
{
    char unk0x00[0x14];
    D2Unk00667420BStrc* p14;
};

struct D2ObjectsTxt
{
    char unk0x00[0x167];
    unsigned char nSubClass;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, char nIndex); // 0x0066AF30
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType); // 0x0066B3E0
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B970
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlags, int nOperation); // 0x0067C4F0
void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlags, int nOperation); // 0x0067C590

struct D2RoomTileGridStrc
{
    char unk0x00[0x08];
    volatile int nWalls;
    volatile int nFloors;
    volatile int nShadows;
    int unk0x14;
    volatile int nTileWalls;
    int unk0x1C;
    volatile int nTileFloors;
    int unk0x24;
    volatile int nTileRoofs;
};

void __stdcall sub_00643560_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560
void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EEA0
void __fastcall sub_0067CBF0(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags); // 0x0067CBF0
void __fastcall sub_0066ECE0_CountAllTileTypes(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, int bFillBlanks, int bKillEdgeX, int bKillEdgeY); // 0x0066ECE0
void __fastcall DRLGANIM_TestLoadAnimatedRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int nTileType, int bKillEdgeX, int bKillEdgeY); // 0x0066D290
void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pWallGrid, D2DrlgGridStrc* pTileTypeGrid, int bKillEdgeX, int bKillEdgeY); // 0x0066EDB0
void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EEE0
void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bFillBlanks, int bKillEdgeX, int bKillEdgeY); // 0x0066EC10
void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pDrlgRoom, int nAnimSpeed, D2DrlgGridStrc* pWallGrids, int nWallLayers, D2DrlgGridStrc* pFloorGrids, int nFloorLayers, D2DrlgGridStrc* pCellGrid); // 0x0066D700
void __fastcall DRLGLOGIC_InitializeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileTypeGrid, D2DrlgGridStrc* pFloorGrid, D2DrlgGridStrc* pWallGrid); // 0x0066D110
void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pDrlgRoom); // 0x0066CCB0
static void __declspec(noinline) sub_00666990(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom);
int __stdcall DATATBLS_GetSuperUniquesTxtRecordCount(); // 0x00655710
D2PresetUnitStrc* __fastcall DRLGPRESET_CopyPresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit, int nX, int nY); // 0x00667510
D2DrlgRoomStrc* __fastcall DRLGPRESET_InitPresetRoomData(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, D2DrlgCoordStrc* pDrlgCoord, unsigned int dwDT1Mask, int dwRoomFlags, int dwPresetFlags, D2DrlgGridStrc* pMazeGrid); // 0x00666680
static void __stdcall DRLGPRESET_BuildPresetArea(D2DrlgLevelStrc* pLevel, D2DrlgGridStrc* pDrlgGrid, int nFlags, int bSingleRoom, D2DrlgMapStrc* pDrlgMap); // 0x00667970
static void __stdcall sub_00666E00(D2DrlgMapStrc* pDrlgMap, int nPops);

struct D2DrlgPresetInfoStrc
{
	void* pDrlgMap;
	int nDirection;
};

extern const char gszPresetFile[]; // 0x006EE7C4
int __fastcall sub_0045C3E0(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2LvlPrestTxt* __fastcall DATATBLS_GetLvlPrestTxtRecordFromLevelId(int nLevelId); // 0x0061F0E0
void __fastcall sub_00642D10(D2DrlgStrc* pDrlg, D2DrlgLevelStrc* pLevel); // 0x00642D10

// 0x00666070
static __forceinline void sub_00666070_FindLevelFile(D2DrlgFileStrc** ppDrlgFile, D2LevelFileListStrc** ppPrevious, D2LevelFileListStrc** ppCurrent)
{
    D2LevelFileListStrc* pFirst = gpLevelFilesList;
    *ppPrevious = 0;
    for (*ppCurrent = pFirst; *ppCurrent; *ppCurrent = (*ppCurrent)->pNext)
    {
        if ((*ppCurrent)->pFile == *ppDrlgFile)
        {
            return;
        }
        *ppPrevious = *ppCurrent;
    }
}

static __forceinline void __stdcall DRLGPRESET_AddRiverObject_Inline(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nIndex, int nX, int nY)
{
    D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, pMemPool, 2, nIndex, 0, nX, nY);
    pPresetUnit->bSpawned |= 1;
    pPresetUnit->pNext = pDrlgMap->pPresetUnit;
    pDrlgMap->pPresetUnit = pPresetUnit;
}

static void DRLGPRESET_SpawnRiver(D2DrlgMapStrc* pDrlgMap, int nX, int nY, void* pMemPool)
{
    int nSubtileX = nX;
    int nSubtileY = nY;
    int nEndSubtileX = 0;
    int nEndSubtileY = nY + pDrlgMap->pFile->nHeight;

    DUNGEON_GameTileToSubtileCoords(&nSubtileX, &nSubtileY);
    DUNGEON_GameTileToSubtileCoords(&nEndSubtileX, &nEndSubtileY);

    while (nSubtileY < nEndSubtileY)
    {
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 65, nSubtileX, nSubtileY);
        nSubtileY += 40;
    }
}

// 0x00666220
static void __stdcall DRLGPRESET_AddPresetRiverObjects(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nOffsetX, D2DrlgGridStrc* pDrlgGrid)
{
    for (int nY = 0; nY < pDrlgMap->pDrlgCoord.nHeight; ++nY)
    {
        const int nX = nOffsetX > 0 ? nOffsetX : 0;
        int nObjectX = pDrlgMap->pDrlgCoord.nPosX + nOffsetX;
        int nObjectY = pDrlgMap->pDrlgCoord.nPosY + nY;
        DUNGEON_GameTileToSubtileCoords(&nObjectX, &nObjectY);
        nObjectX -= 5;

        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 40, nObjectX, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 41, nObjectX + 5, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 41, nObjectX + 10, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 41, nObjectX + 15, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 42, nObjectX + 20, nObjectY);
        const unsigned int nGridEntry = DRLGGRID_GetGridEntry(pDrlgGrid, nX, nY);
        if (((unsigned char)(nGridEntry >> 20) & 0x3F) == 4)
        {
            switch ((unsigned char)(nGridEntry >> 8))
            {
            case 0:
            case 4:
            case 8:
            case 16:
            case 29:
            case 39:
                nY += 3;
                break;

            default:
                break;
            }
        }
    }
}

// 0x00666680
D2DrlgRoomStrc* __fastcall DRLGPRESET_InitPresetRoomData(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, D2DrlgCoordStrc* pDrlgCoord, unsigned int dwDT1Mask, int dwRoomFlags, int dwPresetFlags, D2DrlgGridStrc* pMazeGrid)
{
    D2DrlgRoomStrc* pDrlgRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
    pDrlgRoom->dwDT1Mask = dwDT1Mask;
    pDrlgRoom->dwFlags |= dwRoomFlags;
    pDrlgRoom->pDrlgCoord.nPosX = pDrlgCoord->nPosX;
    pDrlgRoom->pDrlgCoord.nPosY = pDrlgCoord->nPosY;
    pDrlgRoom->pDrlgCoord.nWidth = pDrlgCoord->nWidth;
    pDrlgRoom->pDrlgCoord.nHeight = pDrlgCoord->nHeight;

    D2DrlgPresetRoomStrc* pDrlgPresetRoom = pDrlgRoom->pMaze;
    pDrlgPresetRoom->pMap = pDrlgMap;
    pDrlgPresetRoom->nLevelPrest = pDrlgMap->pLvlPrestTxtRecord->dwDef;
    pDrlgPresetRoom->dwFlags = dwPresetFlags;
    pDrlgPresetRoom->pMazeGrid = pMazeGrid;

    if (pMazeGrid)
    {
        pMazeGrid->nHeight |= 1;
    }

    if (!pDrlgPresetRoom->pMap->pLvlPrestTxtRecord->dwPopulate)
    {
        pDrlgRoom->dwFlags |= 0x800000;
    }

    DRLGROOM_AddRoomExToLevel(pLevel, pDrlgRoom);
    return pDrlgRoom;
}

static void sub_006663C0(D2DrlgMapStrc* pDrlgMap, void* pMemPool)
{
    D2DrlgCoordStrc tDrlgCoord;
    D2DrlgGridStrc tDrlgGrid;
    int nCellFlags[256];

    tDrlgCoord.nPosX = 0;
    tDrlgCoord.nPosY = 0;
    tDrlgCoord.nWidth = pDrlgMap->pDrlgCoord.nWidth;
    tDrlgCoord.nHeight = pDrlgMap->pDrlgCoord.nHeight;
    DRLGGRID_AssignCellsOffsetsAndFlags(&tDrlgGrid, (int*)pDrlgMap->pFile->pFloorLayer[0], &tDrlgCoord, pDrlgMap->pDrlgCoord.nWidth + 1, nCellFlags);

    tDrlgCoord.nPosX = pDrlgMap->pDrlgCoord.nPosX;
    tDrlgCoord.nPosY = pDrlgMap->pDrlgCoord.nPosY;

    if (pDrlgMap->pLvlPrestTxtRecord->dwDef == 27)
    {
        DRLGPRESET_SpawnRiver(pDrlgMap, tDrlgCoord.nPosX - 1 + 1, tDrlgCoord.nPosY, pMemPool);
        DRLGPRESET_AddPresetRiverObjects(pDrlgMap, pMemPool, -1, &tDrlgGrid);
    }
    else
    {
        for (int nOffsetX = 0; nOffsetX < tDrlgCoord.nWidth; ++nOffsetX)
        {
            const unsigned int nGridEntry = DRLGGRID_GetGridEntry(&tDrlgGrid, nOffsetX, 0);
            if (((unsigned char)(nGridEntry >> 20) & 0x3F) == 2 && (unsigned char)(nGridEntry >> 8) == 24)
            {
                DRLGPRESET_SpawnRiver(pDrlgMap, tDrlgCoord.nPosX + nOffsetX + 1, tDrlgCoord.nPosY, pMemPool);
                DRLGPRESET_AddPresetRiverObjects(pDrlgMap, pMemPool, nOffsetX, &tDrlgGrid);
                nOffsetX += 4;
            }
        }
    }

    DRLGGRID_ResetGrid(&tDrlgGrid);
}

static void __stdcall sub_006664A0(D2DrlgMapStrc* pDrlgMap, void* pMemPool)
{
    int nX = pDrlgMap->pDrlgCoord.nPosX + pDrlgMap->pDrlgCoord.nWidth / 2;
    int nY = pDrlgMap->pDrlgCoord.nPosY + pDrlgMap->pDrlgCoord.nHeight / 2;
    DUNGEON_GameTileToSubtileCoords(&nX, &nY);

    const int nClassId = sgptDataTables->nMonStatsTxtRecordCount <= 266 ? -1 : 266;
    D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, pMemPool, 1, nClassId, 1, nX, nY);
    pPresetUnit->pNext = pDrlgMap->pPresetUnit;
    pDrlgMap->pPresetUnit = pPresetUnit;
}

void __fastcall DRLGPRESET_SpawnHardcodedPresetUnits(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgMapStrc* pDrlgMap = pDrlgRoom->pMaze->pMap;
    void* pMemPool = pDrlgRoom->pLevel->pDrlg->pMempool;
    if (!pDrlgMap->pFile)
    {
        DRLGPRESET_LoadDrlgFile(&pDrlgMap->pFile, pDrlgRoom->pLevel->pDrlg->hArchive, pDrlgMap->pLvlPrestTxtRecord->szFile[pDrlgMap->nPickedFile]);
        DRLGPRESET_AddPresetUnitToDrlgMap(pMemPool, pDrlgMap, &pDrlgRoom->pSeed);
    }

    if (pDrlgMap->bInited == 1)
    {
        pDrlgMap->bInited = 0;

        switch (pDrlgMap->nLevelPrest)
        {
        case 4:
        case 5:
        case 6:
        case 7:
            if (pDrlgRoom->pLevel->nLevelId == 2 && pDrlgMap->nPickedFile == 3)
            {
                sub_006664A0(pDrlgMap, pMemPool);
            }
            break;

        case 1:
        case 3:
        case 26:
        case 27:
        case 28:
        case 300:
            if (pDrlgRoom->dwFlags & 0x40000)
            {
                sub_006663C0(pDrlgMap, pMemPool);
            }
            break;

        default:
            break;
        }
    }

    pDrlgRoom->dwFlags |= 0x2000000;
}

// 0x00666990
static void sub_00666990(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    int nTombStoneTiles = 0;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze->pTombStoneTiles)
        return;

    pMaze->pTombStoneTiles = (D2CoordStrc*)FOG_AllocPool(pMemPool, 6 * sizeof(D2CoordStrc), gszDrlgPresetSourceFile_006EE7C4, 1964, 0);
    for (int i = 0; i < pDrlgRoom->nTileHeight; ++i)
    {
        for (int j = 0; j < pDrlgRoom->nTileWidth; ++j)
        {
            const unsigned int nPacked = DRLGGRID_GetGridEntry(pMaze->pWallGrid, j, i);
            const unsigned char nTileStyle = (nPacked >> 20) & 0x3F;
            const unsigned char nTileSequence = (unsigned char)(nPacked >> 8);
            if (nTileStyle == 10 && nTileSequence >= 23 && nTileSequence <= 27)
            {
                if (nTombStoneTiles < 6)
                {
                    int nY;
                    int nX;
                    nX = j + pDrlgRoom->nTileXPos;
                    nY = i + pDrlgRoom->nTileYPos;
                    DUNGEON_GameTileToSubtileCoords(&nX, &nY);
                    nX += 2;
                    nY += 2;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nX = nX;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nY = nY;
                    ++nTombStoneTiles;
                }
            }
        }
    }
    pMaze->nTombStoneTiles = nTombStoneTiles;
}

// 0x00666AC0
void __fastcall DRLGPRESET_AddPresetRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGROOMTILE_AllocTileGrid(pDrlgRoom);

    void* pMemPool = pDrlgRoom->pLevel->pDrlg->pMempool;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    D2DrlgMapStrc* pMazeMap = pMaze->pMap;
    const int bAnimate = pMazeMap->pLvlPrestTxtRecord->dwAnimate;
    const int bFillBlanks = pMazeMap->pLvlPrestTxtRecord->dwFillBlanks;

    int bKillEdgeX = 0;
    int bKillEdgeY = 0;
    if (pMazeMap->pLvlPrestTxtRecord->dwKillEdge)
    {
        bKillEdgeX = pDrlgRoom->nTileXPos + pDrlgRoom->nTileWidth == pMazeMap->pDrlgCoord.nPosX + pMazeMap->pDrlgCoord.nWidth;
        bKillEdgeY = pDrlgRoom->nTileYPos + pDrlgRoom->nTileHeight == pMazeMap->pDrlgCoord.nPosY + pMazeMap->pDrlgCoord.nHeight;
    }

    D2DrlgGridStrc tTileTypeGrid;
    D2DrlgGridStrc tTileInfoGrid;
    int aTileTypeCellPos[1024];
    int aTileTypeCellFlags[256];
    int aTileInfoCellPos[1024];
    int aTileInfoCellFlags[256];
    int bTownOrGraveyard = 0;
    switch (pDrlgRoom->pMaze->nLevelPrest)
    {
    case 1:
    case 108:
        bTownOrGraveyard = 1;
        sub_0067CBF0(&tTileTypeGrid, pDrlgRoom->nTileWidth + 1, pDrlgRoom->nTileHeight + 1, aTileTypeCellPos, aTileTypeCellFlags);
        sub_0067CBF0(&tTileInfoGrid, pDrlgRoom->nTileWidth + 1, pDrlgRoom->nTileHeight + 1, aTileInfoCellPos, aTileInfoCellFlags);
        break;
    }

    const int nWallLayers = pMaze->pMap->pFile->nWallLayers;
    const int nFloorLayers = pMaze->pMap->pFile->nFloorLayers;

    for (int i = 0; i < nFloorLayers; ++i)
    {
        sub_0066ECE0_CountAllTileTypes(pDrlgRoom, &pMaze->pFloorGrid[i], i == 0 && bFillBlanks, bKillEdgeX, bKillEdgeY);
        if (bAnimate)
        {
            DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pFloorGrid[i], 0, 0, bKillEdgeX, bKillEdgeY);
        }
    }

    for (int i = 0; i < nWallLayers; ++i)
    {
        DRLGROOMTILE_CountWallWarpTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], bKillEdgeX, bKillEdgeY);
        sub_0066ECE0_CountAllTileTypes(pDrlgRoom, &pMaze->pWallGrid[i], 0, bKillEdgeX, bKillEdgeY);
        if (bAnimate)
        {
            DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], 0, bKillEdgeX, bKillEdgeY);
        }
    }

    sub_0066ECE0_CountAllTileTypes(pDrlgRoom, &pMaze->pCellGrid, 0, bKillEdgeX, bKillEdgeY);
    if (bAnimate)
    {
        DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pCellGrid, 0, 13, bKillEdgeX, bKillEdgeY);
    }

    if (bTownOrGraveyard)
    {
        sub_0066ECE0_CountAllTileTypes(pDrlgRoom, &tTileInfoGrid, 0, bKillEdgeX, bKillEdgeY);
    }

    DRLGROOMTILE_AllocTileData(pDrlgRoom);

    for (int i = 0; i < nFloorLayers; ++i)
    {
        DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &pMaze->pFloorGrid[i], 0, i == 0 && bFillBlanks, bKillEdgeX, bKillEdgeY);
    }

    for (int i = 0; i < nWallLayers; ++i)
    {
        DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], 0, bKillEdgeX, bKillEdgeY);
    }

    DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &pMaze->pCellGrid, 0, 0, bKillEdgeX, bKillEdgeY);

    if (bTownOrGraveyard)
    {
        DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &tTileInfoGrid, &tTileTypeGrid, 0, bKillEdgeX, bKillEdgeY);
    }

    if (bAnimate)
    {
        DRLGANIM_AllocAnimationTileGrids(pDrlgRoom, pMaze->pMap->pLvlPrestTxtRecord->nAnimSpeed, pMaze->pWallGrid, nWallLayers, pMaze->pFloorGrid, nFloorLayers, &pMaze->pCellGrid);
    }

    D2RoomTileGridStrc* pTileGrid = pDrlgRoom->pTileGrid;
    pTileGrid->nTileWalls = pTileGrid->nWalls;
    pTileGrid->nTileFloors = pTileGrid->nFloors;
    pTileGrid->nTileRoofs = pTileGrid->nShadows;

    if (pMaze->pMap->pLvlPrestTxtRecord->dwLogicals)
    {
        DRLGLOGIC_InitializeDrlgCoordList(pDrlgRoom, pMaze->pTileTypeGrid, pMaze->pFloorGrid, pMaze->pWallGrid);
    }
    else
    {
        DRLGLOGIC_AllocCoordLists(pDrlgRoom);
    }

    if (bTownOrGraveyard)
    {
        DRLGGRID_ResetGrid(&tTileTypeGrid);
        DRLGGRID_ResetGrid(&tTileInfoGrid);
    }

    if (pDrlgRoom->pLevel->nLevelId == 17)
    {
        sub_00666990(pMemPool, pDrlgRoom);
    }
}

// 0x00666E00
static void __stdcall sub_00666E00(D2DrlgMapStrc* pDrlgMap, int nPops)
{
    pDrlgMap->nPops = nPops;

    for (int i = 0; i < nPops; ++i)
    {
        D2DrlgCoordStrc* pPopsLocation = &pDrlgMap->pPopsLocation[i];
        const int nX1 = pPopsLocation->nPosX < pPopsLocation->nWidth ? pPopsLocation->nPosX : pPopsLocation->nWidth;
        const int nY1 = pPopsLocation->nPosY < pPopsLocation->nHeight ? pPopsLocation->nPosY : pPopsLocation->nHeight;
        const int nX2 = pPopsLocation->nPosX > pPopsLocation->nWidth ? pPopsLocation->nPosX : pPopsLocation->nWidth;
        const int nY2 = pPopsLocation->nPosY > pPopsLocation->nHeight ? pPopsLocation->nPosY : pPopsLocation->nHeight;

        pPopsLocation->nPosX = nX1 + pDrlgMap->pDrlgCoord.nPosX;
        pPopsLocation->nPosY = nY1 + pDrlgMap->pDrlgCoord.nPosY;
        pPopsLocation->nWidth = nX2 - nX1 + 1;
        pPopsLocation->nHeight = nY2 - nY1 + 1;
        pDrlgMap->pPopsIndex[i] = pDrlgMap->pPopsIndex[i] / 4 - 1;
    }
}

void __fastcall sub_Z16_EmitTombStoneTiles(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool)
{
    if (pDrlgRoom->nTileWidth == 9)
        sub_00666990(pMemPool, pDrlgRoom);
}

unsigned short __stdcall sub_004166F0_GetWord()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00666EB0
char* __fastcall sub_00416800_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x00666ED0
D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed)
{
    D2DrlgMapStrc* pDrlgMap = (D2DrlgMapStrc*)FOG_AllocPool(pLevel->pDrlg->pMempool, sizeof(D2DrlgMapStrc), &gszDrlgPresetSourceFile, 2477, 0);
    memset(pDrlgMap, 0x00, sizeof(D2DrlgMapStrc));

    pDrlgMap->pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecord(nLvlPrestId);
    pDrlgMap->nLevelPrest = nLvlPrestId;

    pDrlgMap->nPickedFile = SEED_RollLimitedRandomNumber(pSeed, pDrlgMap->pLvlPrestTxtRecord->dwFiles);
    pDrlgMap->pDrlgCoord.nPosX = pDrlgCoord->nPosX;
    pDrlgMap->pDrlgCoord.nPosY = pDrlgCoord->nPosY;

    if (pDrlgMap->pLvlPrestTxtRecord->nSizeX && pDrlgMap->pLvlPrestTxtRecord->nSizeY)
    {
        pDrlgMap->pDrlgCoord.nWidth = pDrlgMap->pLvlPrestTxtRecord->nSizeX;
        pDrlgMap->pDrlgCoord.nHeight = pDrlgMap->pLvlPrestTxtRecord->nSizeY;
    }
    else
    {
        pDrlgMap->pDrlgCoord.nWidth = pDrlgCoord->nWidth;
        pDrlgMap->pDrlgCoord.nHeight = pDrlgCoord->nHeight;
    }

    pDrlgMap->bInited = 1;
    pDrlgMap->pNext = pLevel->pCurrentMap;
    pLevel->pCurrentMap = pDrlgMap;

    return pDrlgMap;
}

void __stdcall sub_M121_Emit_00666070(D2DrlgFileStrc** ppDrlgFile, D2LevelFileListStrc** ppPrevious, D2LevelFileListStrc** ppCurrent)
{
    sub_00666070_FindLevelFile(ppDrlgFile, ppPrevious, ppCurrent);
}

// 0x00666FF0
int __fastcall sub_00666FF0_GetRoomSubFieldEC(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->pSub20->nFieldEC;
}

// 0x00667000
int __fastcall DRLGPRESET_GetLevelPrestIdFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->pMaze->nLevelPrest;
}

// 0x00667420
int __fastcall sub_00667420_GetChainField20(D2Unk00667420Strc* p)
{
    return p->p14->p00->n20;
}

// build: context DRLGPRESET_GetFileCount
static __forceinline int DRLGPRESET_GetFileCount(D2LvlPrestTxt* pLvlPrestTxtRecord)
{
	return pLvlPrestTxtRecord->dwFiles;
}

// 0x00667430
void __fastcall DRLGPRESET_InitLevelData(D2DrlgLevelStrc* pLevel)
{
	void* const tArg1 = pLevel->pDrlg->pMempool;
	D2DrlgPresetInfoStrc* pPreset = (D2DrlgPresetInfoStrc*)FOG_AllocPool(tArg1, sizeof(D2DrlgPresetInfoStrc), gszPresetFile, 2809, 0);
	D2LvlPrestTxt* pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecordFromLevelId(pLevel->nLevelId);
	D2_ASSERT(pLvlPrestTxtRecord, 2811);

	pLevel->pPreset = pPreset;
	memset(pPreset, 0, sizeof(D2DrlgPresetInfoStrc));

	const int nFiles = DRLGPRESET_GetFileCount(pLvlPrestTxtRecord);
	if (nFiles)
	{
		pPreset->nDirection = sub_0045C3E0(&pLevel->pSeed, nFiles);
	}
	else
	{
		pPreset->nDirection = -1;
	}

	sub_00642D10(pLevel->pDrlg, pLevel);
}

static __forceinline int DRLGPRESET_GetMonsterId(int nMonsterId, int nMonStatsCount)
{
    if (nMonsterId >= 0 && nMonsterId < nMonStatsCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x00667620
void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed)
{
    D2PresetUnitStrc* pPresetUnit = pDrlgMap->pFile->pPresetUnit;
    int nX = pDrlgMap->pDrlgCoord.nPosX;
    int nY = pDrlgMap->pDrlgCoord.nPosY;
    DUNGEON_GameTileToSubtileCoords(&nX, &nY);

    for (; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        switch (pPresetUnit->nUnitType)
        {
        case 1:
        {
            const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
            if (pPresetUnit->nIndex < nMonStatsCount)
            {
                switch (DRLGPRESET_GetMonsterId(pPresetUnit->nIndex, nMonStatsCount))
                {
                case 204:
                case 205:
                case 371:
                case 372:
                    if (SEED_RollRandomNumber(pSeed) % 3)
                    {
                        continue;
                    }
                    break;
                }
            }
            else if (pPresetUnit->nIndex - nMonStatsCount >= DATATBLS_GetSuperUniquesTxtRecordCount())
            {
                const int nCount = sgptDataTables->nMonStatsTxtRecordCount;
                switch (pPresetUnit->nIndex - nCount - DATATBLS_GetSuperUniquesTxtRecordCount())
                {
                case 33:
                    if (!(SEED_RollRandomNumber(pSeed) & 3))
                    {
                        continue;
                    }
                    break;

                case 34:
                    if (!(SEED_RollRandomNumber(pSeed) & 1))
                    {
                        continue;
                    }
                    break;

                case 35:
                    if (SEED_RollRandomNumber(pSeed) & 3)
                    {
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        case 2:
            switch (pPresetUnit->nIndex)
            {
            case 196:
            case 261:
                if (SEED_RollRandomNumber(pSeed) & 1)
                {
                    continue;
                }
                break;

            case 581:
                if (!(SEED_RollRandomNumber(pSeed) & 3))
                {
                    continue;
                }
                break;
            }
            break;
        }

        D2PresetUnitStrc* pNew = DRLGPRESET_CopyPresetUnit(pMemPool, pPresetUnit, nX, nY);
        pNew->pNext = pDrlgMap->pPresetUnit;
        pDrlgMap->pPresetUnit = pNew;
    }
}

// 0x00667970
static void __stdcall DRLGPRESET_BuildPresetArea(D2DrlgLevelStrc* pLevel, D2DrlgGridStrc* pDrlgGrid, int nFlags, int bSingleRoom, D2DrlgMapStrc* pDrlgMap)
{
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    void* pMemPool = pDrlg->pMempool;
    int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pDrlg, pLevel->nLevelId);
    int nWarpFlag = 0x10;
    for (int i = 0; i < 8; ++i)
    {
        if (pVisArray[i] && DRLGWARP_GetWarpDestinationFromArray(pLevel, i) == -1)
        {
            nFlags |= nWarpFlag;
        }

        nWarpFlag <<= 1;
    }

    DRLGGRID_AlterAllGridFlags(pDrlgGrid, nFlags, 0);

    const int bScan = pDrlgMap->pLvlPrestTxtRecord->dwScan;
    const int nPops = pDrlgMap->pLvlPrestTxtRecord->dwPops;
    int nProcessedPops = 0;

    if (!bScan && !nPops)
    {
        return;
    }

    DRLGPRESET_LoadDrlgFile(&pDrlgMap->pFile, pDrlg->hArchive, pDrlgMap->pLvlPrestTxtRecord->szFile[pDrlgMap->nPickedFile]);
    DRLGPRESET_AddPresetUnitToDrlgMap(pMemPool, pDrlgMap, &pLevel->pSeed);

    D2_ASSERT(pDrlgMap->pFile->nWidth == pDrlgMap->pDrlgCoord.nWidth, 0x8B9);
    D2_ASSERT(pDrlgMap->pFile->nHeight == pDrlgMap->pDrlgCoord.nHeight, 0x8BA);

    if (nPops)
    {
        pDrlgMap->pPopsIndex = (int*)FOG_AllocPool(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8BF, 0);
        pDrlgMap->pPopsSubIndex = (int*)FOG_AllocPool(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8C0, 0);
        pDrlgMap->pPopsOrientation = (int*)FOG_AllocPool(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8C1, 0);
        pDrlgMap->pPopsLocation = (D2DrlgCoordStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgCoordStrc) * nPops, &gszDrlgPresetSourceFile, 0x8C2, 0);
    }

    memset(pDrlgMap->pPopsIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsSubIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsOrientation, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsLocation, 0, sizeof(D2DrlgCoordStrc) * nPops);

    D2DrlgFileStrc* pFile = pDrlgMap->pFile;
    D2DrlgCoordStrc tDrlgCoord = { 0 };
    D2DrlgGridStrc tTileTypeGrid = { 0 };
    D2DrlgGridStrc tWallGrid = { 0 };
    int nTileTypeCellFlags[0x100];
    int nWallCellFlags[0x100];

    tDrlgCoord.nWidth = pFile->nWidth + 1;
    tDrlgCoord.nHeight = pFile->nHeight + 1;

    for (int i = 0; i < pFile->nWallLayers; ++i)
    {
        DRLGGRID_AssignCellsOffsetsAndFlags(&tTileTypeGrid, (int*)pFile->pTileTypeLayer[i], &tDrlgCoord, pFile->nWidth + 1, nTileTypeCellFlags);
        DRLGGRID_AssignCellsOffsetsAndFlags(&tWallGrid, (int*)pFile->pWallLayer[i], &tDrlgCoord, pFile->nWidth + 1, nWallCellFlags);

        for (int nY = 0; nY < pFile->nHeight; ++nY)
        {
            for (int nX = 0; nX < pFile->nWidth; ++nX)
            {
                const int nTileType = DRLGGRID_GetGridEntry(&tTileTypeGrid, nX, nY);
                const int nWallFlags = DRLGGRID_GetGridEntry(&tWallGrid, nX, nY);
                const unsigned int nIndex = ((unsigned int)nWallFlags >> 0x14) & 0x3F;
                const int nSubIndex = (nWallFlags >> 8) & 0xFF;
                const int nUpperBit = nWallFlags & 0x80000000;

                if (nTileType == 0xB || nTileType == 0xA)
                {
                    if (bScan && nIndex <= 7 && (nSubIndex == 0 || nSubIndex == 4 || nUpperBit))
                    {
                        int nGridX;
                        int nGridY;
                        if (bSingleRoom)
                        {
                            nGridX = 0;
                            nGridY = 0;
                        }
                        else
                        {
                            nGridX = nX / 8;
                            nGridY = nY / 8;
                        }

                        DRLGGRID_AlterGridFlag(pDrlgGrid, nGridX, nGridY, 1 << (nIndex + 4), 0);
                    }

                    if (nPops && nIndex >= 8 && nIndex <= 0x1D)
                    {
                        int nCounter = 0;
                        while (nCounter < nProcessedPops)
                        {
                            if (pDrlgMap->pPopsIndex[nCounter] == nIndex)
                            {
                                pDrlgMap->pPopsLocation[nCounter].nWidth = nX;
                                pDrlgMap->pPopsLocation[nCounter].nHeight = nY;
                                break;
                            }

                            ++nCounter;
                        }

                        if (nCounter == nProcessedPops)
                        {
                            pDrlgMap->pPopsIndex[nProcessedPops] = nIndex;
                            pDrlgMap->pPopsSubIndex[nProcessedPops] = nSubIndex;
                            pDrlgMap->pPopsLocation[nProcessedPops].nPosX = nX;
                            pDrlgMap->pPopsLocation[nProcessedPops].nPosY = nY;
                            ++nProcessedPops;
                        }
                    }

                    if (bScan && nIndex >= 0x1E && nIndex <= 0x21)
                    {
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosX = nX + pDrlgMap->pDrlgCoord.nPosX;
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosY = nY + pDrlgMap->pDrlgCoord.nPosY;

                        switch (nIndex)
                        {
                        case 0x1E:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex;
                            break;

                        case 0x1F:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex + 5;
                            break;

                        case 0x20:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xA;
                            break;

                        case 0x21:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xB;
                            break;

                        case 0x22:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xC;
                            break;
                        }

                        ++pLevel->nTileInfo;
                    }
                }
            }
        }

        DRLGGRID_ResetGrid(&tWallGrid);
        DRLGGRID_ResetGrid(&tTileTypeGrid);
    }

    if (nPops)
    {
        sub_00666E00(pDrlgMap, nProcessedPops);
    }

    if (bScan)
    {
        for (D2PresetUnitStrc* pPresetUnit = pFile->pPresetUnit; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
        {
            if (pPresetUnit->nUnitType == 2 && pPresetUnit->nIndex < 0x23D && DATATBLS_GetObjectsTxtRecord(pPresetUnit->nIndex)->nSubClass & 0x40)
            {
                int nGridX;
                int nGridY;
                if (bSingleRoom)
                {
                    nGridX = 0;
                    nGridY = 0;
                }
                else
                {
                    nGridX = pPresetUnit->nXpos / 5 / 8;
                    nGridY = pPresetUnit->nYpos / 5 / 8;
                }

                DRLGGRID_AlterGridFlag(pDrlgGrid, nGridX, nGridY, 0x30000, 0);
            }
        }
    }
}

// 0x00667ED0
D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom)
{
    int nCellPos[0x400];
    int nCellFlags[0x100];
    D2DrlgGridStrc tDrlgGrid;

    const int nGridWidth = pDrlgMap->pDrlgCoord.nWidth / 8 + 1;
    const int nGridHeight = pDrlgMap->pDrlgCoord.nHeight / 8 + 1;
    if (pDrlgMap->pLvlPrestTxtRecord->dwOutdoors)
    {
        nFlags |= 0x80000;
    }

    DRLGGRID_FillGrid(&tDrlgGrid, nGridWidth, nGridHeight, nCellPos, nCellFlags);
    DRLGPRESET_BuildPresetArea(pLevel, &tDrlgGrid, nFlags, bSingleRoom, pDrlgMap);

    const unsigned int dwDT1Mask = pDrlgMap->pLvlPrestTxtRecord->dwDt1Mask;
    D2DrlgRoomStrc* pDrlgRoom = 0;
    if (bSingleRoom)
    {
        const int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, 0, 0);
        D2DrlgRoomStrc* pRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
        pRoom->dwDT1Mask = dwDT1Mask;
        pRoom->dwFlags |= nGridFlags;
        pRoom->pDrlgCoord.nPosX = pDrlgMap->pDrlgCoord.nPosX;
        pRoom->pDrlgCoord.nPosY = pDrlgMap->pDrlgCoord.nPosY;
        pRoom->pDrlgCoord.nWidth = pDrlgMap->pDrlgCoord.nWidth;
        pRoom->pDrlgCoord.nHeight = pDrlgMap->pDrlgCoord.nHeight;

        D2DrlgPresetRoomStrc* pDrlgPresetRoom = pRoom->pMaze;
        pDrlgPresetRoom->pMap = pDrlgMap;
        pDrlgPresetRoom->nLevelPrest = pDrlgMap->pLvlPrestTxtRecord->dwDef;
        pDrlgPresetRoom->dwFlags = 1;
        pDrlgPresetRoom->pMazeGrid = 0;

        if (!pDrlgMap->pLvlPrestTxtRecord->dwPopulate)
        {
            pRoom->dwFlags |= 0x800000;
        }

        DRLGROOM_AddRoomExToLevel(pLevel, pRoom);
        pDrlgRoom = pRoom;
    }
    else
    {
        const int nXEnd = pDrlgMap->pDrlgCoord.nWidth + pDrlgMap->pDrlgCoord.nPosX;
        const int nYEnd = pDrlgMap->pDrlgCoord.nPosY + pDrlgMap->pDrlgCoord.nHeight;
        D2DrlgCoordStrc tDrlgCoord = { 0, 0, 0, 0 };

        for (int nY = pDrlgMap->pDrlgCoord.nPosY, nGridY = 0; nY < nYEnd; nY += 8, ++nGridY)
        {
            for (int nX = pDrlgMap->pDrlgCoord.nPosX, nGridX = 0; nX < nXEnd; nX += 8, ++nGridX)
            {
                const int nDeltaToEndX = nXEnd - nX;
                const int nDeltaToEndY = nYEnd - nY;
                tDrlgCoord.nPosX = nX;
                tDrlgCoord.nPosY = nY;

                if (nDeltaToEndX < 8)
                    tDrlgCoord.nWidth = nDeltaToEndX;
                else
                    tDrlgCoord.nWidth = 8;

                tDrlgCoord.nHeight = nDeltaToEndY;
                if (nDeltaToEndY >= 8)
                {
                    tDrlgCoord.nHeight = 8;
                }

                int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, nGridX, nGridY);
                int nMapFlags = pDrlgMap->pVertices ? DRLGGRID_GetGridEntry(&pDrlgMap->pMapGrid, nGridX, nGridY) : 0;
                if (tDrlgCoord.nWidth && tDrlgCoord.nHeight)
                {
                    pDrlgRoom = DRLGPRESET_InitPresetRoomData(pLevel, pDrlgMap, &tDrlgCoord, dwDT1Mask, nGridFlags, 0, (D2DrlgGridStrc*)nMapFlags);
                }
            }
        }
    }

    DRLGGRID_ResetGrid(&tDrlgGrid);
    return pDrlgRoom;
}
