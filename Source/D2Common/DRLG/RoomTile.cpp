#include "D2LevelIds.h"
#include "D2ItemsWorld.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgPresets.h"
#include "D2DrlgTiles.h"
#include "D2DrlgRooms.h"
#include "D2Path.h"
#include "D2TxtTables.h"

#pragma function(memset)

struct D2DrlgTileDataStrc;

union D2SeedStrc;

union D2C_PackedTileInformation;

struct D2DrlgRoomTilesStrc;

struct D2DrlgTileLinkStrc;

struct D2DrlgCoordStrc;

struct D2RoomTileStrc;

struct D2DrlgActStrc;

struct D2ActiveRoomStrc;

struct D2TileLibraryEntryStrc;

struct D2DrlgRoomStrc;

struct D2DrlgTileGridStrc;

struct D2DrlgStrc;

struct D2DrlgLevelStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall TileLibraryGetTiles(D2TileLibraryHeaderStrc** ppTiles, int nTileType, int nStyle, int nSequence, D2TileLibraryEntryStrc** ppTileEntries, int nMaxEntries); // 0x00604AE0

int __stdcall TileGetRarity(D2TileLibraryEntryStrc* pTile); // 0x00604C20

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

void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY); // 0x00643310

D2TileLibraryEntryStrc* __fastcall DRLGROOMTILE_GetTileCache(D2DrlgRoomStrc* pDrlgRoom, int nType, unsigned int nPackedTileInformation); // 0x0066D820

void __fastcall sub_0040B480(void*,void*,const char*,int,int); // 0x0040B480

void* __fastcall FOG_ReallocPool(void*,void*,int,const char*,int,int); // 0x0040B4B0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

int* __fastcall DRLGGRID_GetGridFlagsPointer(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C550

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __fastcall DRLGOUTPLACE_InitOutdoorRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x0067D2D0

void __fastcall DRLGPRESET_InitPresetRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x006667D0

D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AAE0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __stdcall DUNGEON_RemoveRoomFromAct(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom); // 0x0061A910

void __fastcall DRLGPRESET_FreeDrlgGridsFromPresetRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x00666610

void __fastcall DRLGPRESET_AddPresetRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom); // 0x00666AC0

void __fastcall DRLGLOGIC_FreeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom); // 0x0066C6E0

D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitShadowTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DF40

void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoomData(D2DrlgRoomStrc* pDrlgRoom); // 0x0067D680

void __fastcall DRLGOUTROOM_InitializeDrlgOutdoorRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x0067D710

static void DRLGROOMTILE_ResetRoomTileSelections(D2DrlgRoomStrc* pDrlgRoom);

#define RANGE_COUNT 37

#define STYLE_SHIFT 20

#define SEQ_SHIFT 8

extern const D2UnkDrlgRoomTileStrc gaDrlgRoomTileLevelRanges[RANGE_COUNT];                                  // 0x006EEFC8

extern const D2UnkDrlgRoomTileStrc2 gaDrlgRoomTilePresetUnits[];                                   // 0x006EF188

extern const D2CoordStrc gaWarpTileOffsets[4];                                                     // 0x006EF554

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall SKILLDESC_ValidateMonsterId(int nMonsterId);                                              // 0x004E6C50

void __fastcall COLLISION_ReplaceTileCollision(D2ActiveRoomStrc* pRoom, D2DrlgTileDataStrc* pTileData, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0064C860

int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId); // 0x0066AF30

D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(D2DrlgLevelStrc* pLevel, unsigned char nWarpId, char nDirection); // 0x0066AF50

int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoords, int nX, int nY);                   // 0x0066B980

int __fastcall DRLGROOM_AreXYInsideCoordinatesOrOnBorder(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY);      // 0x0066B9D0

void __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY); // 0x0066BF30

void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DDE0

__declspec(noinline) D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitFloorTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DEF0

D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitWallTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry, int nTileType); // 0x0066DC50

static void __stdcall DRLGROOMTILE_AddTilePresetUnits(D2DrlgTileDataStrc* pTileData, int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY); // 0x0066D9E0

struct D2PresetUnitStrc;

static void __stdcall DRLGROOMTILE_InitializeTileDataFlags(unsigned int nTileFlags, int nY, D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nType, int nX); // 0x0066DB20

static void __stdcall DRLGROOMTILE_LoadWallWarpTiles(D2DrlgTileDataStrc* pTileData, unsigned int nPackedTileInformation, int nTileType, D2DrlgRoomStrc* pDrlgRoom); // 0x0066E260

static void __stdcall DRLGROOMTILE_UpdateAndGetLvlWarpTxtRecord(int nTileType, D2RoomTileStrc* pWarpTile);

static int __stdcall DRLGROOMTILE_AddWarp(int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY);

static void __stdcall DRLGROOMTILE_LoadFloorWarpTiles(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int nTileType, unsigned int nPackedTileInformation);

static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_FindLinkedTileInRoom(D2DrlgRoomStrc* pNearRoom, int bFloor, int nX, int nY, unsigned int nPackedTileInformation);

static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_GetLinkedTileData(int bFloor, int nX, int nY, D2DrlgRoomStrc** ppDrlgRoom, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation);

static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_AddLinkedTileData(void* pMemPool, unsigned int nPackedTileInformation, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom, int nTileType);

void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY);

static void __stdcall DRLGROOMTILE_GetCreateLinkedTileData(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int nTileType, unsigned int nPackedTileInformation, int nX, int nY); // 0x0066E940

static void __stdcall DRLGROOMTILE_LoadInitRoomTile(void* pMemPool, int nX, int nY, int bFillBlanks, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nTileType);

static void __stdcall DRLGROOMTILE_SetTileDataPosition(D2DrlgTileDataStrc* pTileData, D2DrlgRoomStrc* pDrlgRoom, int nX, int nY);

struct D2DrlgDrlgStrc
{
    char unk0x000[0x464];
    void* hArchive;
};

struct D2UnkOutdoorStrc
{
    D2DrlgLevelStrc* pLevel;
    int* field_4;
    D2DrlgGridStrc* pGrid1;
    D2DrlgGridStrc* pGrid2;
    int nLevelPrestId;
    int field_14;
    int nLvlSubId;
    unsigned int(__fastcall* field_1C)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    int(__fastcall* field_20)(D2DrlgLevelStrc* pLevel, int nX, int nY, int nId, int nOffset, char nFlags);
    int(__fastcall* field_24)(D2DrlgLevelStrc* pLevel, int nX, int nY, int a4, int a5, unsigned int a6);
    int(__fastcall* field_28)(D2DrlgLevelStrc* pLevel, int nStyle, int a3);
    void(__fastcall* field_2C)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    void(__fastcall* field_30)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    void(__fastcall* field_34)(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nRand, int a6);
};

struct D2UnkOutdoorStrc2
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2DrlgOutdoorRoomStrc* pOutdoorRooms[4];
    D2DrlgGridStrc* pWallsGrids[4];
    D2DrlgGridStrc* pFloorGrid;
    int field_28;
    int nLayers;
    int nSubWaypoint_Shrine;
    int nSubTheme;
    int nSubThemePicked;
};

D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nId);                                                 // 0x0061FA90

void __fastcall DRLGTILESUB_InitializeDrlgFile(void* hArchive, D2LvlSubTxt* pLvlSubTxtRecord);                    // 0x006704E0

void __stdcall sub_0066FF50(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord); // 0x0066FF50

int __stdcall DRLGTILESUB_DoSubstitutions(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord);         // 0x00670170

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlags, int nOperation); // 0x0067C4F0

struct D2DrlgSubstGroupStrc;

struct D2LvlSubTxt;

struct D2UnkOutdoorStrc;

struct D2DrlgOutdoorInfoStrc;

struct D2CoordStrc;

struct D2DrlgOutdoorRoomStrc;

struct D2UnkOutdoorStrc2;

void __stdcall DRLGTILESUB_ReplaceSubPreset(int nX, int nY, D2UnkOutdoorStrc* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset); // 0x0066F520

static int __stdcall DRLGTILESUB_TestReplaceSubPreset(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, D2UnkOutdoorStrc* pOutdoor); // 0x0066F3B0

extern int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc* pSeed, int nLimit); // 0x0045C3E0

extern int __stdcall sub_0066F690_ApplySubstGroup(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pRecord, D2DrlgSubstGroupStrc* pGroup); // 0x0066F690

static int __stdcall sub_0066F350(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY);

static int __stdcall sub_0066F380(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY);

static void __stdcall DRLGROOMTILE_LinkedTileDataManager(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, D2DrlgTileDataStrc* pTileData, int nTileType, unsigned int nPackedTileInformation, int nX, int nY);

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468


int __stdcall sub_0066FCF0(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord);

void __fastcall sub_006707A0(D2UnkOutdoorStrc2* pOutdoor);

static inline unsigned int SEED_RollRandomNumberHighFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberHighFirst(pSeed) % nMax;
    }

    return SEED_RollRandomNumberHighFirst(pSeed) & (nMax - 1);
}

// 0x0066D820
D2TileLibraryEntryStrc* __fastcall DRLGROOMTILE_GetTileCache(D2DrlgRoomStrc* pDrlgRoom, int nType, unsigned int nPackedTileInformation)
{
    D2TileLibraryEntryStrc* ppTileEntries[40];

    const unsigned char nStyle = nPackedTileInformation ? (unsigned char)(nPackedTileInformation >> 20) & 0x3F : 0;
    const unsigned char nSequence = nPackedTileInformation ? (unsigned char)(nPackedTileInformation >> 8) : 0;

    const unsigned int nTiles = TileLibraryGetTiles(&pDrlgRoom->pTiles, nType, nStyle, nSequence, ppTileEntries, 40);
    if (!nTiles)
    {
        D2_ASSERT(TileLibraryGetTiles(&pDrlgRoom->pTiles, 10, 0, 0, ppTileEntries, 40), 0x73);
        return ppTileEntries[0];
    }

    int nTotalRarity = 0;
    for (unsigned int i = 0; i < nTiles; ++i)
    {
        D2_ASSERT(ppTileEntries[i], 0x7C);
        nTotalRarity += TileGetRarity(ppTileEntries[i]);
    }

    int nRand = SEED_RollLimitedRandomNumberInline(&pDrlgRoom->pSeed, nTotalRarity) + 1;
    int nIndex = 0;
    while (nTotalRarity && nTiles > 1 && nRand > 0)
    {
        nRand -= TileGetRarity(ppTileEntries[nIndex]);
        ++nIndex;
    }

    if (nIndex)
    {
        --nIndex;
    }

    return ppTileEntries[nIndex];
}

// 0x0066D960
int __stdcall DRLGROOMTILE_FindTilePresetUnitIndex(int nLevelId, unsigned int nPackedTileInformation, int bIsRightWallWithDoor)
{
    for (const int* rangeEnd = &gaDrlgRoomTileLevelRanges[0].nArrayEndId;
         (int)rangeEnd < (int)&gaDrlgRoomTileLevelRanges[RANGE_COUNT].nArrayEndId; rangeEnd += 3)
    {
        if (rangeEnd[-2] == nLevelId)
        {
            const int nTileStyle = (nPackedTileInformation >> STYLE_SHIFT) & 0x3F;
            const int nTileSequence = (nPackedTileInformation >> SEQ_SHIFT) & 0xFF;

            for (int j = rangeEnd[-1]; j <= *rangeEnd; ++j)
            {
                if (nTileStyle == gaDrlgRoomTilePresetUnits[j].nTileStyle
                    && nTileSequence == gaDrlgRoomTilePresetUnits[j].nTileSequence
                    && bIsRightWallWithDoor == gaDrlgRoomTilePresetUnits[j].bIsRightWallWithDoor)
                {
                    return j;
                }
            }
        }
    }

    return -1;
}

static inline D2DrlgTileDataStrc* sub_B04_InitFloorTileDataInline(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pTiles.pFloorTiles[pTileGrid->nFloors];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nFloors;

    DRLGROOMTILE_InitTileData(pDrlgRoom, pTileData, nX, nY, nPackedTileInformation, pTileLibraryEntry);
    return pTileData;
}

inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if ((nMax - 1) & nMax)
        return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

inline int __fastcall SKILLDESC_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }
    return -1;
}

// 0x0066D9E0
static void __stdcall DRLGROOMTILE_AddTilePresetUnits(D2DrlgTileDataStrc* pTileData, int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY)
{
    int bIsRightWallWithDoor;
    if (pTileData)
    {
        if (pTileData->dwFlags & 0x20)
        {
            return;
        }

        bIsRightWallWithDoor = pTileData->nTileType == 9;
    }
    else
    {
        bIsRightWallWithDoor = nTileType == 9;
    }

    const int nIndex = DRLGROOMTILE_FindTilePresetUnitIndex(pDrlgRoom->ptDrlgLevel->eLevelId, nPackedTileInformation, bIsRightWallWithDoor);
    if (nIndex != -1)
    {
        int nPosX = nX - pDrlgRoom->pDrlgCoord.nPosX;
        int nPosY = nY - pDrlgRoom->pDrlgCoord.nPosY;

        DUNGEON_GameTileToSubtileCoords(&nPosX, &nPosY);

        nPosX += gaDrlgRoomTilePresetUnits[nIndex].nX;
        nPosY += gaDrlgRoomTilePresetUnits[nIndex].nY;

        if (nPosX >= 0 && nPosY >= 0 && nPosX < 5 * pDrlgRoom->pDrlgCoord.nWidth && nPosY < 5 * pDrlgRoom->pDrlgCoord.nHeight)
        {
            int nUnitId = gaDrlgRoomTilePresetUnits[nIndex].nUnitId;
            int nUnitType = gaDrlgRoomTilePresetUnits[nIndex].nUnitType;
            int nMode = 0;
            int bAdd = 1;
            switch (nUnitType)
            {
            case 1:
                nUnitId = SKILLDESC_ValidateMonsterId(nUnitId);
                nMode = 1;
                break;

            case 2:
                nMode = 0;
                switch (nUnitId)
                {
                case 91:
                case 92:
                    bAdd = SEED_RollLimitedRandomNumber(&pDrlgRoom->pSeed, 3);
                    break;
                }
                break;
            }

            if (bAdd)
            {
                DRLGROOM_AllocPresetUnit(pDrlgRoom, pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, nUnitType, nUnitId, nMode, nPosX, nPosY);
            }
            if (pTileData)
            {
                pTileData->dwFlags |= 0x20;
            }
        }
    }
}

// 0x0066DB20
static void __stdcall DRLGROOMTILE_InitializeTileDataFlags(unsigned int nTileFlags, int nY, D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nType, int nX)
{
    if (pDrlgRoom && (nType == 9 || nType == 8))
    {
        DRLGROOMTILE_AddTilePresetUnits(pTileData, nX, 0, pDrlgRoom, nTileFlags, nY);
    }

    if (nType != 13)
    {
        pTileData->dwFlags |= ((int)((nTileFlags >> 18) & 3) + 1) << 14;
    }

    if (nType == 14)
    {
        pTileData->dwFlags |= 4;
    }
    else if (nType == 11 || nType == 10 || nType == 9 || nType == 8)
    {
        pTileData->dwFlags |= 2;
    }

    if (nTileFlags & 0x80)
    {
        pTileData->dwFlags |= 1;
    }

    if (nTileFlags & 0x10000000)
    {
        pTileData->dwFlags |= 0x102;
    }

    if (nTileFlags & 0x20000)
    {
        pTileData->dwFlags |= 0x40;
    }

    if (nTileFlags & 0x10000)
    {
        pTileData->dwFlags |= 0x80;
    }

    if (nTileFlags & 8)
    {
        pTileData->dwFlags |= 4;
    }

    if (nTileFlags & 0x80000000)
    {
        pTileData->dwFlags |= 8;
    }
    else
    {
        pTileData->dwFlags &= ~8;
    }

    if (nTileFlags & 0x4000000)
    {
        pTileData->dwFlags |= 0x20C;
    }

    if (nTileFlags & 0x20000000)
    {
        pTileData->dwFlags |= 0x800;
    }

    if (nTileFlags & 4)
    {
        pTileData->dwFlags |= 0x2000;
    }

    const unsigned int nFlags = D2CMP_10079_GetTileFlags(pTileData->pTile);
    if (nFlags & 1)
    {
        pTileData->dwFlags |= 4;
    }

    if (nFlags & 4)
    {
        pTileData->dwFlags |= 0x800;
    }
}

// 0x0066DC10
static void __stdcall DRLGROOMTILE_SetTileDataPosition(D2DrlgTileDataStrc* pTileData, D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    pTileData->nPosX = nX - pDrlgRoom->pDrlgCoord.nPosX;
    pTileData->nPosY = nY - pDrlgRoom->pDrlgCoord.nPosY;

    nY += 1;
    DUNGEON_GameTileToClientCoords(&nX, &nY);

    nY += 40;
    pTileData->nWidth = nX;
    pTileData->nHeight = nY;
}

// 0x0066DC50
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitWallTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry, int nTileType)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pTiles.pWallTiles[pTileGrid->nWalls];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nWalls;

    DRLGROOMTILE_SetTileDataPosition(pTileData, pDrlgRoom, nX, nY);
    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = nTileType;
    pTileData->dwFlags = 0;
    pTileData->dwPopFlags = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom, pTileData, nTileType, nX);

    if (nTileType == 3)
    {
        D2TileLibraryEntryStrc* pNorthCornerTile = DRLGROOMTILE_GetTileCache(pDrlgRoom, 4, nPackedTileInformation);
        D2DrlgTileDataStrc* pNorthCornerTileData = DRLGROOMTILE_InitWallTileData(pDrlgRoom, ppTileData, nX, nY, nPackedTileInformation, pNorthCornerTile, 4);
        DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom, pNorthCornerTileData, 4, nX);
    }

    return pTileData;
}

// 0x0066DDE0
void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = 0;
    pTileData->dwFlags = 0;
    pTileData->dwPopFlags = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    if (pDrlgRoom)
    {
        DRLGROOMTILE_SetTileDataPosition(pTileData, pDrlgRoom, nX, nY);
    }

    DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom, pTileData, 0, nX);
}

// 0x0066DEF0
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitFloorTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pFloorTiles[pTileGrid->nFloors];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nFloors;

    DRLGROOMTILE_InitTileData(pDrlgRoom, pTileData, nX, nY, nPackedTileInformation, pTileLibraryEntry);
    return pTileData;
}

// 0x0066DF40
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitShadowTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pTiles.pRoofTiles[pTileGrid->nShadows];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nShadows;

    DRLGROOMTILE_SetTileDataPosition(pTileData, pDrlgRoom, nX, nY);
    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = 13;
    pTileData->dwFlags = 0;
    pTileData->dwPopFlags = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom, pTileData, 13, nX);

    return pTileData;
}

void __fastcall sub_M107_Emit_0066F180(D2DrlgRoomStrc* pDrlgRoom, int bReset)
{
    if (bReset)
        DRLGROOMTILE_ResetRoomTileSelections(pDrlgRoom);
}

// 0x0066E060
void __fastcall DRLGROOMTILE_InitTileShadow(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, unsigned int nPackedTileInformation)
{
    DRLGROOMTILE_InitShadowTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, DRLGROOMTILE_GetTileCache(pDrlgRoom, 13, nPackedTileInformation));
}

// 0x0066E090
void __fastcall DRLGROOMTILE_ShrinkRoofTilesToShadowCount(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    if (!pTileGrid->nShadows)
    {
        if (pTileGrid->pTiles.pRoofTiles)
        {
            sub_0040B480(pMemPool, pTileGrid->pTiles.pRoofTiles, ".\\DRLG\\RoomTile.cpp", 599, 0);
        }
        pTileGrid->pTiles.pRoofTiles = 0;
        return;
    }

    if (pTileGrid->pTiles.nRoofs > pTileGrid->nShadows)
    {
        pTileGrid->pTiles.pRoofTiles = (D2DrlgTileDataStrc*)FOG_ReallocPool(pMemPool, pTileGrid->pTiles.pRoofTiles, pTileGrid->nShadows * sizeof(D2DrlgTileDataStrc), ".\\DRLG\\RoomTile.cpp", 607, 0);
        int i;
        const int& nCount = pTileGrid->nShadows;
        for (i = 0; i < nCount - 1; ++i)
        {
            pTileGrid->pTiles.pRoofTiles[i].pNext = &pTileGrid->pTiles.pRoofTiles[i + 1];
        }
        pTileGrid->pTiles.pRoofTiles[i].pNext = 0;
        pTileGrid->pTiles.nRoofs = pTileGrid->nShadows;
    }
}

// 0x0066E140
char __stdcall SKILLS_GetModeSideChar(int nMode)
{
    return nMode == 11 ? 'r' : 'l';
}

// 0x0066E160
static void __stdcall DRLGROOMTILE_UpdateAndGetLvlWarpTxtRecord(int nTileType, D2RoomTileStrc* pWarpTile)
{
    D2_ASSERT(pWarpTile, 627);

    D2LvlWarpTxt* pLvlWarpTxtRecord = pWarpTile->pLvlWarpTxtRecord;
    D2_ASSERT(pLvlWarpTxtRecord, 628);

    if (pLvlWarpTxtRecord->szDirection[0] != 'b')
    {
        const char szDirection = nTileType == 11 ? 'r' : 'l';
        if (pLvlWarpTxtRecord->szDirection[0] != szDirection)
        {
            pWarpTile->pLvlWarpTxtRecord = DATATBLS_GetLvlWarpTxtRecordFromLevelIdAndDirection(pLvlWarpTxtRecord->dwLevelId, szDirection);
        }
    }
}

// 0x0066E1C0
static int __stdcall DRLGROOMTILE_AddWarp(int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY)
{
    int nPosX;
    int nPosY;
    D2LvlWarpTxt* pLvlWarpTxtRecord = DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(pDrlgRoom->ptDrlgLevel, (nPackedTileInformation >> 20) & 0x3F, nTileType == 11 ? 'r' : 'l');
    if (pLvlWarpTxtRecord)
    {
        nPosX = nX - pDrlgRoom->pDrlgCoord.nPosX;
        nPosY = nY - pDrlgRoom->pDrlgCoord.nPosY;

        if (nPosX != pDrlgRoom->pDrlgCoord.nWidth && nPosY != pDrlgRoom->pDrlgCoord.nHeight)
        {
            DUNGEON_GameTileToSubtileCoords(&nPosX, &nPosY);

            nPosX += pLvlWarpTxtRecord->dwOffsetX;
            nPosY += pLvlWarpTxtRecord->dwOffsetY;

            DRLGROOM_AllocPresetUnit(pDrlgRoom, pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, 5, pLvlWarpTxtRecord->dwLevelId, 0, nPosX, nPosY);
            return 1;
        }
    }

    return 0;
}

// 0x0066E260
static void __stdcall DRLGROOMTILE_LoadWallWarpTiles(D2DrlgTileDataStrc* pTileData, unsigned int nPackedTileInformation, int nTileType, D2DrlgRoomStrc* pDrlgRoom)
{
    const unsigned char nTileSequence = (unsigned char)(nPackedTileInformation >> 8);
    D2DrlgCoordStrc* const pCoord = &pDrlgRoom->pDrlgCoord;
    D2RoomTileStrc* pWarpTile = pDrlgRoom->pRoomTiles;
    const int nDestinationLevelId = DRLGWARP_GetWarpDestinationFromArray(pDrlgRoom->ptDrlgLevel, (nPackedTileInformation >> 20) & 0x3F);
    while (pWarpTile && pWarpTile->pLvlWarpTxtRecord->dwLevelId != nDestinationLevelId)
    {
        pWarpTile = pWarpTile->pNext;
    }

    D2_ASSERT(pWarpTile, 689);

    if (nTileSequence == 0 || nTileSequence == 4)
    {
        if (!DRLGROOMTILE_AddWarp(pTileData->nPosX + pCoord->nPosX, nTileType, pDrlgRoom, nPackedTileInformation, pCoord->nPosY + pTileData->nPosY))
        {
            return;
        }
    }

    DRLGROOMTILE_UpdateAndGetLvlWarpTxtRecord(nTileType, pWarpTile);

    pTileData->pNext = pWarpTile->pUnselectedTiles;
    pWarpTile->pUnselectedTiles = pTileData;

    D2LvlWarpTxt* pWarpDef = pWarpTile->pLvlWarpTxtRecord;
    D2_ASSERT(pWarpDef, 715);

    if (pWarpDef->dwLitVersion)
    {
        const unsigned int nLitPackedTileInformation = (pWarpDef->dwTiles << 8) | nPackedTileInformation;
        D2TileLibraryEntryStrc* pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, nTileType, nLitPackedTileInformation);
        D2DrlgTileDataStrc* pLitTileData = DRLGROOMTILE_InitWallTileData(pDrlgRoom, &pWarpTile->pSelectedTiles, pTileData->nPosX + pCoord->nPosX, pCoord->nPosY + pTileData->nPosY, nLitPackedTileInformation, pTileCache, nTileType);
        if (pLitTileData)
        {
            pLitTileData->dwFlags |= 8;
        }
    }
}

// 0x0066E360
static void __stdcall DRLGROOMTILE_LoadFloorWarpTiles(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int nTileType, unsigned int nPackedTileInformation)
{
    --nX;
    --nY;

    pDrlgRoom->dwFlags |= 0x800000;

    D2RoomTileStrc* pWarpTile = pDrlgRoom->pRoomTiles;
    const int nDestinationLevelId = DRLGWARP_GetWarpDestinationFromArray(pDrlgRoom->ptDrlgLevel, (nPackedTileInformation >> 20) & 0x3F);
    while (pWarpTile && pWarpTile->pLvlWarpTxtRecord->dwLevelId != nDestinationLevelId)
    {
        pWarpTile = pWarpTile->pNext;
    }

    if (pWarpTile)
    {
        DRLGROOMTILE_UpdateAndGetLvlWarpTxtRecord(nTileType, pWarpTile);

        if (pWarpTile->pLvlWarpTxtRecord->dwLitVersion)
        {
            const unsigned char nTileSequence = (unsigned char)(nPackedTileInformation >> 8);
            for (int i = 0; i < 4; ++i)
            {
                const unsigned int nDestinationPacked = (nTileSequence << 20) | ((i | 4) << 8);
                D2TileLibraryEntryStrc* pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, 0, nDestinationPacked);
                D2DrlgTileDataStrc* pDestTileData = sub_B04_InitFloorTileDataInline(pDrlgRoom, &pWarpTile->pSelectedTiles, gaWarpTileOffsets[i].nX + nX, gaWarpTileOffsets[i].nY + nY, nDestinationPacked, pTileCache);
                pDestTileData->dwFlags |= 8;
            }

            D2DrlgTileDataStrc* pFloorTileData = pDrlgRoom->ptDrlgTiles->pTiles.pFloorTiles;
            for (int i = 0; i < pDrlgRoom->ptDrlgTiles->nFloors; ++i, ++pFloorTileData)
            {
                if (sub_00604B90_GetTileStyle(pFloorTileData->pTile) == nTileSequence && (unsigned int)sub_00604C50_GetTileSequence(pFloorTileData->pTile) < 4)
                {
                    pFloorTileData->pNext = pWarpTile->pUnselectedTiles;
                    pWarpTile->pUnselectedTiles = pFloorTileData;
                }
            }
        }
    }
}

// 0x0066E4C0
static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_FindLinkedTileInRoom(D2DrlgRoomStrc* pNearRoom, int bFloor, int nX, int nY, unsigned int nPackedTileInformation)
{
    if (!pNearRoom->ptDrlgTiles)
    {
        return 0;
    }

    if (!DRLGROOM_AreXYInsideCoordinatesOrOnBorder(&pNearRoom->pDrlgCoord, nX, nY))
    {
        return 0;
    }

    for (D2DrlgTileLinkStrc* pTileLink = pNearRoom->ptDrlgTiles->pMapLinks; pTileLink; pTileLink = pTileLink->pNext)
    {
        D2DrlgTileDataStrc* pTileData = pTileLink->pMapTile;
        if (pTileLink->bFloor)
        {
            if (!bFloor)
            {
                continue;
            }
        }
        else if (bFloor)
        {
            continue;
        }

        {
            for (; pTileData; pTileData = pTileData->pNext)
            {
                if (pNearRoom->pDrlgCoord.nPosX + pTileData->nPosX == nX && pNearRoom->pDrlgCoord.nPosY + pTileData->nPosY == nY)
                {
                    if (pTileData->nTileType != 4 && (pTileData->nTileType == 13 || !(nPackedTileInformation & 0x8000000)))
                    {
                        if (!(pTileData->dwFlags & 0x1C000) || ((pTileData->dwFlags >> 14) & 7) - 1 == ((nPackedTileInformation >> 18) & 3))
                        {
                            return pTileData;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

// 0x0066E580
static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_GetLinkedTileData(int bFloor, int nX, int nY, D2DrlgRoomStrc** ppDrlgRoom, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation)
{
    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        if (pDrlgRoom->ppRoomsNear[i] != pDrlgRoom)
        {
            D2DrlgTileDataStrc* pTileData = DRLGROOMTILE_FindLinkedTileInRoom(pDrlgRoom->ppRoomsNear[i], bFloor, nX, nY, nPackedTileInformation);
            if (pTileData)
            {
                *ppDrlgRoom = pDrlgRoom->ppRoomsNear[i];
                return pTileData;
            }
        }
    }

    *ppDrlgRoom = 0;
    return 0;
}

// 0x0066E5E0
static D2DrlgTileLinkStrc* __stdcall DRLGROOMTILE_AllocTileLink(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int bFloor)
{
    D2DrlgTileLinkStrc* pTileLink = (D2DrlgTileLinkStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgTileLinkStrc), ".\\DRLG\\RoomTile.cpp", 891, 0);
    pTileLink->bFloor = bFloor;
    pTileLink->pMapTile = 0;
    pTileLink->pNext = pDrlgRoom->ptDrlgTiles->pMapLinks;
    pDrlgRoom->ptDrlgTiles->pMapLinks = pTileLink;
    return pTileLink;
}

// 0x0066E620
static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_AddLinkedTileData(void* pMemPool, unsigned int nPackedTileInformation, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom, int nTileType)
{
    if ((nTileType == 11 || nTileType == 10) && !DRLGROOM_AreXYInsideCoordinates(&pDrlgRoom->pDrlgCoord, nX, nY))
    {
        return 0;
    }

    const int bFloor = nTileType == 0;
    D2DrlgTileLinkStrc* pTileLink;
    for (pTileLink = pDrlgRoom->ptDrlgTiles->pMapLinks; pTileLink; pTileLink = pTileLink->pNext)
    {
        if ((pTileLink->bFloor && bFloor) || (!pTileLink->bFloor && !bFloor))
        {
            break;
        }
    }

    if (!pTileLink)
    {
        pTileLink = DRLGROOMTILE_AllocTileLink(pMemPool, pDrlgRoom, bFloor);
    }

    D2TileLibraryEntryStrc* pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, nTileType, nPackedTileInformation);
    D2DrlgTileDataStrc* pTileData;
    if (nTileType == 0)
    {
        pTileData = DRLGROOMTILE_InitFloorTileData(pDrlgRoom, &pTileLink->pMapTile, nX, nY, nPackedTileInformation, pTileCache);
    }
    else if (nTileType == 13)
    {
        pTileData = DRLGROOMTILE_InitShadowTileData(pDrlgRoom, &pTileLink->pMapTile, nX, nY, nPackedTileInformation, pTileCache);
    }
    else
    {
        DRLGROOMTILE_InitWallTileData(pDrlgRoom, &pTileLink->pMapTile, nX, nY, nPackedTileInformation, pTileCache, nTileType);
        pTileData = pTileLink->pMapTile;
        if (nTileType == 11 || nTileType == 10)
        {
            DRLGROOMTILE_LoadWallWarpTiles(pTileData, nPackedTileInformation, nTileType, pDrlgRoom);
        }
    }

    return pTileData;
}

static inline bool TileTypeIsAWallWithDoor(int nTileType)
{
    return nTileType == 9 || nTileType == 8;
}

// 0x0066E740
static void __stdcall DRLGROOMTILE_LinkedTileDataManager(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, D2DrlgTileDataStrc* pTileData, int nTileType, unsigned int nPackedTileInformation, int nX, int nY)
{
    int nNewTileType;
// build: symbol ?gnWallRemapIndices@* 0x006EF620
    const int nRemapIndex = gnWallRemapIndices[nTileType];

    if (pTileData->dwFlags & 1)
    {
        if (TileTypeIsAWallWithDoor(pTileData->nTileType))
        {
            DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom1, pTileData, pTileData->nTileType, nX);
        }

        return;
    }

    if (!(nPackedTileInformation & 0x80))
    {
        int bRemap = 0;
        if (!TileTypeIsAWallWithDoor(nTileType))
        {
            if (TileTypeIsAWallWithDoor(pTileData->nTileType) && (nX - pDrlgRoom2->pDrlgCoord.nPosX == 0 || nY - pDrlgRoom2->pDrlgCoord.nPosY == 0))
            {
                return;
            }

            bRemap = 1;
        }

        if (bRemap || nX - pDrlgRoom1->pDrlgCoord.nPosX != 0 && nY - pDrlgRoom1->pDrlgCoord.nPosY != 0)
        {
            const bool bIsTileTypeANormalWallOrFloor = pTileData->nTileType <= 7;
            if (nRemapIndex < 0 || !bIsTileTypeANormalWallOrFloor)
            {
                if (nRemapIndex != -1)
                {
                    return;
                }
            }
            else
            {
                const int nWallIdx = pTileData->nTileType - 1;
// build: symbol ?gnWallTileTypeRemap@* 0x006EF578
                nNewTileType = gnWallTileTypeRemap[nRemapIndex][nWallIdx];
                goto TileTypeChosen;
            }
        }
    }

    nNewTileType = nTileType;

TileTypeChosen:
    if (pTileData->nTileType != 3)
    {
        if (nNewTileType == 3)
        {
            pTileData->dwFlags |= 0xC008;
            COLLISION_ReplaceTileCollision(pDrlgRoom2->pRoom, pTileData, 0);
            DRLGROOMTILE_AddLinkedTileData(pMemPool, nPackedTileInformation, nX, nY, pDrlgRoom1, 3);
        }
    }
    else if (nNewTileType != 3)
    {
        pTileData->pNext->dwFlags |= 8;
        COLLISION_ReplaceTileCollision(pDrlgRoom2->pRoom, pTileData->pNext, 0);
    }

    const int bBlankFloor = pTileData->nTileType == 0 && sub_00604B90_GetTileStyle(pTileData->pTile) == 30 && sub_00604C50_GetTileSequence(pTileData->pTile) == 0;
    if (nNewTileType != pTileData->nTileType || bBlankFloor)
    {
        D2TileLibraryEntryStrc* pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom2, nNewTileType, nPackedTileInformation);
        pTileData->nTileType = nNewTileType;

        if (pTileCache != pTileData->pTile && pDrlgRoom2->pRoom)
        {
            COLLISION_ReplaceTileCollision(pDrlgRoom2->pRoom, pTileData, pTileCache);
        }

        pTileData->pTile = pTileCache;
    }

    DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom1, pTileData, pTileData->nTileType, nX);
}

// 0x0066E940
static void __stdcall DRLGROOMTILE_GetCreateLinkedTileData(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int nTileType, unsigned int nPackedTileInformation, int nX, int nY)
{
    D2DrlgRoomStrc* pLinkedRoom = 0;
    D2DrlgTileDataStrc* pLinkedTileData = DRLGROOMTILE_GetLinkedTileData(nTileType == 0, nX, nY, &pLinkedRoom, pDrlgRoom, nPackedTileInformation);
    if (pLinkedTileData)
    {
        DRLGROOMTILE_LinkedTileDataManager(pMemPool, pDrlgRoom, pLinkedRoom, pLinkedTileData, nTileType, nPackedTileInformation, nX, nY);
    }
    else
    {
        DRLGROOMTILE_AddLinkedTileData(pMemPool, nPackedTileInformation, nX, nY, pDrlgRoom, nTileType);
    }
}

// 0x0066E9B0
static void __stdcall DRLGROOMTILE_LoadInitRoomTile(void* pMemPool, int nX, int nY, int bFillBlanks, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nTileType)
{
    const unsigned char nTileStyle = (unsigned char)((nPackedTileInformation >> 20) & 0x3F);
    const unsigned char nTileSequence = (unsigned char)(nPackedTileInformation >> 8);

    if ((nTileType == 11 || nTileType == 10) && nTileStyle >= 8)
    {
        return;
    }

    if (nTileType == 0 && nTileStyle == 30 && (nTileSequence == 0 || nTileSequence == 1))
    {
        nPackedTileInformation |= 0x80000000;
    }

    const unsigned int bHidden = nPackedTileInformation & 0x80000000;
    if (bHidden)
    {
        switch (nTileType)
        {
        case 10:
        case 11:
            if (nTileStyle < 8)
            {
                DRLGROOMTILE_AddWarp(nX, nTileType, pDrlgRoom, nPackedTileInformation, nY);
                DRLGROOMTILE_LoadFloorWarpTiles(pDrlgRoom, nX, nY, nTileType, nPackedTileInformation);
            }
            return;

        case 8:
        case 9:
            switch (pDrlgRoom->ptDrlgLevel->eLevelId)
            {
            case 111:
            case 112:
            case 117:
                break;

            default:
                DRLGROOMTILE_AddTilePresetUnits(0, nX, nTileType, pDrlgRoom, nPackedTileInformation, nY);
                return;
            }
            break;

        default:
            break;
        }
    }

    if (nPackedTileInformation & 4)
    {
        if (nPackedTileInformation & 2)
        {
            if (nTileStyle == 30 && (nTileSequence == 0 || nTileSequence == 1))
            {
                nPackedTileInformation &= ~0x80;
            }

            DRLGROOMTILE_GetCreateLinkedTileData(pMemPool, pDrlgRoom, 0, nPackedTileInformation, nX, nY);
            return;
        }

        if (nPackedTileInformation & 1)
        {
            DRLGROOMTILE_GetCreateLinkedTileData(pMemPool, pDrlgRoom, nTileType, nPackedTileInformation, nX, nY);
            return;
        }

        if ((nPackedTileInformation & 0x8000000) && !bHidden)
        {
            DRLGROOMTILE_GetCreateLinkedTileData(pMemPool, pDrlgRoom, 13, nPackedTileInformation, nX, nY);
            return;
        }
    }

    if (nPackedTileInformation & 2)
    {
        sub_B04_InitFloorTileDataInline(pDrlgRoom, 0, nX, nY, nPackedTileInformation, DRLGROOMTILE_GetTileCache(pDrlgRoom, 0, nPackedTileInformation));
    }
    else if (bFillBlanks && DRLGROOM_AreXYInsideCoordinates(&pDrlgRoom->pDrlgCoord, nX, nY))
    {
        D2C_PackedTileInformation nBlankTileInformation;
        nBlankTileInformation.nPackedValue = (nPackedTileInformation & ~0x80) | 0x80000000;

        D2TileLibraryEntryStrc* pTileCache;
        if (pDrlgRoom->ptDrlgLevel->eLevelId != LEVEL_ARCANESANCTUARY)
        {
            pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, 0, 0x1E00000);
        }
        else
        {
            pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, 0, 0x1E00100);
        }

        sub_B04_InitFloorTileDataInline(pDrlgRoom, 0, nX, nY, nBlankTileInformation.nPackedValue, pTileCache);
    }

    if (nPackedTileInformation & 1)
    {
        D2TileLibraryEntryStrc* pWallTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, nTileType, nPackedTileInformation);
        D2DrlgTileDataStrc* pWallTileData = DRLGROOMTILE_InitWallTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, pWallTileCache, nTileType);
        if ((nTileType == 11 || nTileType == 10) && pDrlgRoom->ptDrlgLevel->eLevelId != LEVEL_PANDEMONIUMRUN1)
        {
            DRLGROOMTILE_LoadWallWarpTiles(pWallTileData, nPackedTileInformation, nTileType, pDrlgRoom);
        }
    }

    if (nPackedTileInformation & 0x8000000)
    {
        DRLGROOMTILE_InitShadowTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, DRLGROOMTILE_GetTileCache(pDrlgRoom, 13, nPackedTileInformation));
    }
}

// 0x0066EC10
void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY)
{
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;

    const int nTileCountX = pDrlgRoom->pDrlgCoord.nWidth + (bKillEdgeX == 0);
    const int nTileCountY = pDrlgRoom->pDrlgCoord.nHeight + (bKillEdgeY == 0);

    const int nRoomX = pDrlgRoom->pDrlgCoord.nPosX;
    const int nRoomY = pDrlgRoom->pDrlgCoord.nPosY;

    for (int nTileOffsetY = 0; nTileOffsetY < nTileCountY; ++nTileOffsetY)
    {
        for (int nTileOffsetX = 0; nTileOffsetX < nTileCountX; ++nTileOffsetX)
        {
            const unsigned int nPackedTileInformation = DRLGGRID_GetGridEntry(pGrid, nTileOffsetX, nTileOffsetY);
            const int nTileType = pTileTypeGrid ? DRLGGRID_GetGridEntry(pTileTypeGrid, nTileOffsetX, nTileOffsetY) : 0;
            DRLGROOMTILE_LoadInitRoomTile(pMemPool, nRoomX + nTileOffsetX, nRoomY + nTileOffsetY, bCheckCoordinatesValidity, pDrlgRoom, nPackedTileInformation, nTileType);
        }
    }
}

// 0x0066ECE0
void __fastcall DRLGROOMTILE_CountAllTileTypes(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileInfoGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY)
{
    const int nTileCountX = pDrlgRoom->pDrlgCoord.nWidth + (bKillEdgeX == 0);
    D2DrlgCoordStrc* pDrlgCoord = &pDrlgRoom->pDrlgCoord;
    const int nTileCountY = pDrlgRoom->pDrlgCoord.nHeight + (bKillEdgeY == 0);
    const int nPosX = pDrlgCoord->nPosX;
    const int nPosY = pDrlgRoom->pDrlgCoord.nPosY;

    D2DrlgRoomTilesStrc* pTiles = &pDrlgRoom->ptDrlgTiles->pTiles;
    for (int nY = 0; nY < nTileCountY; ++nY)
    {
        for (int nX = 0; nX < nTileCountX; ++nX)
        {
            int* pFlags = DRLGGRID_GetGridFlagsPointer(pTileInfoGrid, nX, nY);
            if (*pFlags & 1)
            {
                ++pTiles->nWalls;
            }
            if (*pFlags & 2)
            {
                ++pTiles->nFloors;
            }
            else if (bCheckCoordinatesValidity && DRLGROOM_AreXYInsideCoordinates(pDrlgCoord, nX + nPosX, nY + nPosY))
            {
                ++pTiles->nFloors;
            }
            if (*pFlags & 0x8000000)
            {
                ++pTiles->nRoofs;
            }
        }
    }
}

// 0x0066EDB0
void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileInfoGrid, D2DrlgGridStrc* pTileTypeGrid, int bKillEdgeX, int bKillEdgeY)
{
    const int nTileCountX = pDrlgRoom->pDrlgCoord.nWidth + (bKillEdgeX == 0);
    const int nTileCountY = pDrlgRoom->pDrlgCoord.nHeight + (bKillEdgeY == 0);
    D2DrlgRoomTilesStrc* pTiles = &pDrlgRoom->ptDrlgTiles->pTiles;

    for (int nY = 0; nY < nTileCountY; ++nY)
    {
        for (int nX = 0; nX < nTileCountX; ++nX)
        {
            switch (DRLGGRID_GetGridEntry(pTileTypeGrid, nX, nY))
            {
            case 3:
                ++pTiles->nWalls;
                break;

            case 10:
            case 11:
                if (DRLGGRID_GetGridEntry(pTileInfoGrid, nX, nY) & 0x80000000)
                {
                    pTiles->nFloors += 6;
                }
                else
                {
                    ++pTiles->nWalls;
                }
                break;

            default:
                break;
            }
        }
    }
}

// 0x0066EE40
void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom)
{
    SEED_InitLowSeed(&pDrlgRoom->pSeed, pDrlgRoom->dwInitSeed);

    switch (pDrlgRoom->nType)
    {
    case 1:
        DRLGOUTPLACE_InitOutdoorRoomGrids(pDrlgRoom);
        break;

    case 2:
        DRLGPRESET_InitPresetRoomGrids(pDrlgRoom);
        break;
    }
}

// 0x0066EE70
void __fastcall DRLGROOMTILE_AddRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    switch (pDrlgRoom->nType)
    {
    case 1:
        DRLGOUTROOM_InitializeDrlgOutdoorRoom(pDrlgRoom);
        break;

    case 2:
        DRLGPRESET_AddPresetRoomMapTiles(pDrlgRoom);
        break;
    }

    pDrlgRoom->dwFlags |= 0x100000;
}

// 0x0066EEA0
void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom->ptDrlgTiles)
    {
        pDrlgRoom->ptDrlgTiles = (D2DrlgTileGridStrc*)FOG_AllocPool(pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, sizeof(D2DrlgTileGridStrc), ".\\DRLG\\RoomTile.cpp", 1331, 0);
        memset(pDrlgRoom->ptDrlgTiles, 0, sizeof(D2DrlgTileGridStrc));
    }
}

// 0x0066EEE0
void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgRoomTilesStrc* pRoomTiles = &pDrlgRoom->ptDrlgTiles->pTiles;

    if (pRoomTiles->nFloors)
    {
        pRoomTiles->pFloorTiles = (D2DrlgTileDataStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nFloors, ".\\DRLG\\RoomTile.cpp", 1349, 0);
        memset(pRoomTiles->pFloorTiles, 0, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nFloors);
    }

    if (pRoomTiles->nWalls)
    {
        pRoomTiles->pWallTiles = (D2DrlgTileDataStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nWalls, ".\\DRLG\\RoomTile.cpp", 1355, 0);
        memset(pRoomTiles->pWallTiles, 0, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nWalls);
    }

    if (pRoomTiles->nRoofs && !pRoomTiles->pRoofTiles)
    {
        pRoomTiles->pRoofTiles = (D2DrlgTileDataStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nRoofs, ".\\DRLG\\RoomTile.cpp", 1361, 0);
        memset(pRoomTiles->pRoofTiles, 0, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nRoofs);
    }
}

// 0x0066EFB0
void __fastcall DRLGROOMTILE_ReallocRoofTileGrid(void* pMemPool, D2DrlgTileGridStrc* pTileGrid, int nAdditionalRoofs)
{
    if (nAdditionalRoofs)
    {
        D2DrlgRoomTilesStrc* pRoomTiles = &pTileGrid->pTiles;
        pRoomTiles->pRoofTiles = (D2DrlgTileDataStrc*)FOG_ReallocPool(pMemPool, pRoomTiles->pRoofTiles, sizeof(D2DrlgTileDataStrc) * (nAdditionalRoofs + pRoomTiles->nRoofs), ".\\DRLG\\RoomTile.cpp", 1377, 0);

        int nCounter = 0;
        while (nCounter < pTileGrid->nShadows - 1)
        {
            pRoomTiles->pRoofTiles[nCounter].pNext = &pRoomTiles->pRoofTiles[nCounter + 1];
            ++nCounter;
        }

        pRoomTiles->pRoofTiles[nCounter].pNext = 0;
        pRoomTiles->nRoofs += nAdditionalRoofs;
    }
}

// 0x0066F030
int __fastcall DRLGROOMTILE_GetNumberOfShadowsFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
        return 0;
    return DUNGEON_GetRoomExFromRoom(pRoom)->ptDrlgTiles->nShadows;
}

// 0x0066F050
static void DRLGROOMTILE_FreeTileArrays(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool)
{
    D2DrlgRoomTilesStrc* pRoomTiles = pDrlgRoom->ptDrlgTiles ? &pDrlgRoom->ptDrlgTiles->pTiles : 0;
    if (pRoomTiles)
    {
        if (pRoomTiles->pWallTiles)
        {
            sub_0040B480(pMemPool, pRoomTiles->pWallTiles, ".\\DRLG\\RoomTile.cpp", 1426, 0);
        }

        if (pRoomTiles->pFloorTiles)
        {
            sub_0040B480(pMemPool, pRoomTiles->pFloorTiles, ".\\DRLG\\RoomTile.cpp", 1427, 0);
        }

        if (pRoomTiles->pRoofTiles)
        {
            sub_0040B480(pMemPool, pRoomTiles->pRoofTiles, ".\\DRLG\\RoomTile.cpp", 1428, 0);
        }
    }
}

// 0x0066F0B0
void __fastcall DRLGROOMTILE_FreeTileGrid(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;

    DRLGROOMTILE_FreeTileArrays(pDrlgRoom, pMemPool);

    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    if (pTileGrid)
    {
        D2DrlgTileLinkStrc* pTileLink = pTileGrid->pMapLinks;
        while (pTileLink)
        {
            D2DrlgTileLinkStrc* pFree = pTileLink;
            pTileLink = pTileLink->pNext;
            sub_0040B480(pMemPool, pFree, ".\\DRLG\\RoomTile.cpp", 1453, 0);
        }
        pTileGrid->pMapLinks = 0;

        D2DrlgAnimTileGridStrc* pAnimTileGrid = (D2DrlgAnimTileGridStrc*)pTileGrid->pAnimTiles;
        while (pAnimTileGrid)
        {
            D2DrlgAnimTileGridStrc* pFree = pAnimTileGrid;
            pAnimTileGrid = pAnimTileGrid->pNext;
            sub_0040B480(pMemPool, pFree->ppMapTileData, ".\\DRLG\\RoomTile.cpp", 1465, 0);
            sub_0040B480(pMemPool, pFree, ".\\DRLG\\RoomTile.cpp", 1466, 0);
        }

        sub_0040B480(pMemPool, pTileGrid, ".\\DRLG\\RoomTile.cpp", 1469, 0);
        pDrlgRoom->ptDrlgTiles = 0;
    }
}

// 0x0066F180
static void DRLGROOMTILE_ResetRoomTileSelections(D2DrlgRoomStrc* pDrlgRoom)
{
    for (D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
    {
        pRoomTile->pSelectedTiles = 0;
        pRoomTile->pUnselectedTiles = 0;
    }
}

// 0x0066F1A0
void __fastcall DRLGROOMTILE_FreeRoom(D2DrlgRoomStrc* pDrlgRoom, int bKeepRoom)
{
    D2DrlgStrc* pDrlg = pDrlgRoom->ptDrlgLevel->pDrlg;

    if (!bKeepRoom && pDrlgRoom->pRoom)
    {
        DUNGEON_RemoveRoomFromAct(pDrlg->pAct, pDrlgRoom->pRoom);
    }

    pDrlgRoom->pRoom = 0;

    DRLGLOGIC_FreeDrlgCoordList(pDrlgRoom);

    if (pDrlgRoom->dwFlags & 0x100000)
    {
        pDrlgRoom->dwFlags ^= 0x100000;
        ++pDrlg->nFreedRooms;
        DRLGROOMTILE_FreeTileGrid(pDrlgRoom);

        switch (pDrlgRoom->nType)
        {
        case 1:
            DRLGOUTROOM_FreeDrlgOutdoorRoomData(pDrlgRoom);
            break;

        case 2:
            DRLGPRESET_FreeDrlgGridsFromPresetRoom(pDrlgRoom);
            break;
        }

        for (D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
        {
            pRoomTile->pSelectedTiles = 0;
            pRoomTile->pUnselectedTiles = 0;
        }

        if (bKeepRoom)
        {
            pDrlgRoom->dwFlags |= 0x200000;
        }
    }
}

struct D2LvlTypesTxt
{
    char szFile[32][60];
};

// 0x0066F240
void __fastcall DRLGROOMTILE_LoadDT1FilesForRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    D2LvlTypesTxt* pLvlTypesTxtRecord = DATATBLS_GetLevelTypesTxtRecord(pDrlgRoom->ptDrlgLevel->nLevelType);

    unsigned int dwDT1Mask = pDrlgRoom->dwDT1Mask;
    for (unsigned int nFileIndex = 0; dwDT1Mask && nFileIndex < 32; dwDT1Mask >>= 1, ++nFileIndex)
    {
        if (dwDT1Mask & 1)
        {
            TileLibraryAddProject(&pDrlgRoom->pTiles, pLvlTypesTxtRecord->szFile[nFileIndex]);
        }
    }

    char szPath[260] = { 0 };

// build: symbol ?gszDataGlobal@* 0x006D4118
    wsprintfA(szPath, "%s\\Tiles\\Act1\\Outdoors\\Blank.dt1", gszDataGlobal);
    TileLibraryAddProject(&pDrlgRoom->pTiles, szPath);

    wsprintfA(szPath, "%s\\Tiles\\Act1\\Barracks\\InvisWal.dt1", gszDataGlobal);
    TileLibraryAddProject(&pDrlgRoom->pTiles, szPath);

    wsprintfA(szPath, "%s\\Tiles\\Act1\\Barracks\\Warp.dt1", gszDataGlobal);
    TileLibraryAddProject(&pDrlgRoom->pTiles, szPath);

    pDrlgRoom->dwFlags |= 0x1000000;
}

// 0x0066F350
static int __stdcall sub_0066F350(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY)
{
    if (pLvlSubTxtRecord->pDrlgFile->nFloorLayers)
    {
        return DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pFloorGrid, nX, nY);
    }

    return 0;
}

// 0x0066F380
static int __stdcall sub_0066F380(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY)
{
    if (pLvlSubTxtRecord->pDrlgFile->nWallLayers)
    {
        return DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pWallGrid, nX, nY);
    }

    return 0;
}

// 0x0066F3B0
static int __stdcall DRLGTILESUB_TestReplaceSubPreset(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, D2UnkOutdoorStrc* pOutdoor)
{
    nX -= nX % pLvlSubTxtRecord->dwGridSize;
    nY -= nY % pLvlSubTxtRecord->dwGridSize;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            const int nFloorFlags = sub_0066F350(pLvlSubTxtRecord, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            const int nWallFlags = sub_0066F380(pLvlSubTxtRecord, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            const int nPosX = nX + i * pLvlSubTxtRecord->dwGridSize;
            const int nPosY = nY + j * pLvlSubTxtRecord->dwGridSize;

            const int nEntry = DRLGGRID_GetGridEntry(pOutdoor->pGrid1, nPosX, nPosY);
            if (pOutdoor->field_24)
            {
                if (!pOutdoor->field_24(pOutdoor->pLevel, nPosX, nPosY, nEntry, nFloorFlags, nWallFlags))
                {
                    return 0;
                }
            }
            else if (nWallFlags & 1)
            {
                const int nStyle = ((nWallFlags >> 8) & 0xFF) - 1;
                if (nStyle != pOutdoor->field_14 && nStyle + pOutdoor->nLevelPrestId != nEntry)
                {
                    return 0;
                }

                if (!pOutdoor->field_1C(pOutdoor->pLevel, nPosX, nPosY))
                {
                    return 0;
                }
            }
            else if (nFloorFlags & 2)
            {
                if (!pOutdoor->field_20(pOutdoor->pLevel, nPosX, nPosY, 0, 0, 0))
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

// 0x0066F520
void __stdcall DRLGTILESUB_ReplaceSubPreset(int nX, int nY, D2UnkOutdoorStrc* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset)
{
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int nBaseX = pSubstGroup->tBox.nPosX + nOffset;
    const int nBaseY = pSubstGroup->tBox.nPosY;

    nX -= nX % pLvlSubTxtRecord->dwGridSize;
    nY -= nY % pLvlSubTxtRecord->dwGridSize;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            const int nWallFlags = sub_0066F380(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            const int nFloorFlags = sub_0066F350(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            const int nPosX = nX + i * pLvlSubTxtRecord->dwGridSize;
            const int nPosY = nY + j * pLvlSubTxtRecord->dwGridSize;
            if (nWallFlags & 1)
            {
                const int nStyle = (nWallFlags >> 8) & 0xFF;
                const int nSubStyle = nStyle - 1;
                int nPresetId = 0;
                if (pOutdoor->field_28)
                {
                    nPresetId = pOutdoor->field_28(pLevel, ((unsigned int)nWallFlags >> 20) & 0x3F, nStyle);
                }
                else
                {
                    nPresetId = nSubStyle + pOutdoor->nLevelPrestId;
                }

                if (nPresetId != -5 && nSubStyle != pOutdoor->field_14)
                {
                    pOutdoor->field_34(pLevel, nPosX, nPosY, nPresetId, 0, 1);
                }
            }
            else if (nFloorFlags & 2)
            {
                pOutdoor->field_2C(pLevel, nPosX, nPosY);
            }
            else
            {
                pOutdoor->field_30(pLevel, nPosX, nPosY);
            }
        }
    }
}

int __stdcall sub_M16_EmitTestReplaceSubPreset(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup, int* pPos)
{
    return DRLGTILESUB_TestReplaceSubPreset(pPos[0], pPos[1], pSubstGroup, pLvlSubTxtRecord, pOutdoor);
}

static inline unsigned int DRLGTILESUB_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int DRLGTILESUB_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return DRLGTILESUB_RollRandomNumberInline(pSeed) % nMax;
    return DRLGTILESUB_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x0066F690
int __stdcall sub_0066F690_ApplySubstGroup(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup)
{
    D2CoordStrc pCoord[256];
    int bWilderness;
    int bSmallWilderness;
    int* pBox = pOutdoor->field_4;
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int bSubType1 = pOutdoor->nLvlSubId == 1;
    const int nFlags = pLevel->pOutdoors->dwFlags & 12;

    if (pLevel->eLevelId >= 2 && pLevel->eLevelId <= 7)
        bWilderness = 1;
    else
        bWilderness = 0;

    const int nOffset = bSubType1 && nFlags ? -1 : 1;
    const int nWidth = pBox[2] - pSubstGroup->tBox.nWidth * pLvlSubTxtRecord->dwGridSize + nOffset;
    const int nHeight = pBox[3] - pSubstGroup->tBox.nHeight * pLvlSubTxtRecord->dwGridSize + 1;
    const int nArea = nWidth * nHeight;
    if (nArea)
    {
        if (bSubType1 && bWilderness && nWidth < 6 && nHeight < 6)
            bSmallWilderness = 1;
        else
            bSmallWilderness = 0;

        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const int nRand1 = DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, nArea);
            const int nRand2 = DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, nArea);
            const D2CoordStrc tTemp = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tTemp;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const int nX = pCoord[i].nX;
            const int nY = pCoord[i].nY;
            if (!bSmallWilderness || nX != 2 || nY != 2)
            {
                if (DRLGTILESUB_TestReplaceSubPreset(nX, nY, pSubstGroup, pLvlSubTxtRecord, pOutdoor))
                {
                    DRLGTILESUB_ReplaceSubPreset(nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord, (DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, pSubstGroup->nSubstGroup) + 1) * (pSubstGroup->tBox.nWidth + 1));
                    if (pLvlSubTxtRecord->dwBordType == 0)
                        return 1;
                    else if (pLvlSubTxtRecord->dwBordType == 1)
                        return 1;
                }
            }
        }
    }
    return 0;
}

// 0x0066F990
static void __stdcall sub_0066F990_ApplySecondaryGroups(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pRecord)
{
    D2DrlgFileStrc* pFile = pRecord->pDrlgFile;
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int nGroups = pFile->nSubstGroups;
    int nStart = 0;
    if (nGroups)
    {
        if (pOutdoor->field_14 == -1)
            pOutdoor->field_14 = 62;
        if (!pRecord->dwBordType)
            nStart = sub_0045C3E0_RollLimited(&pLevel->pSeed, nGroups);
        for (int i = 0; i < nGroups; ++i)
        {
            if (sub_0066F690_ApplySubstGroup(pOutdoor, pRecord, &pFile->pSubstGroups[(nStart + i) % nGroups])
                && !pRecord->dwBordType)
                break;
        }
    }
}

// 0x0066FA10
static void __stdcall sub_0066FA10(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2UnkOutdoorStrc2* pOutdoor, void* pMemPool, D2LvlSubTxt* pLvlSubTxtRecord)
{
    int nSubX = nX;
    int nSubY = nY;
    int nMinX = pSubstGroup->tBox.nPosX;
    int nMinY = pSubstGroup->tBox.nPosY;
    int nSizeX = pSubstGroup->tBox.nWidth;
    int nSizeY = pSubstGroup->tBox.nHeight;

    DUNGEON_GameTileToSubtileCoords(&nSubX, &nSubY);
    DUNGEON_GameTileToSubtileCoords(&nMinX, &nMinY);
    DUNGEON_GameTileToSubtileCoords(&nSizeX, &nSizeY);

    for (D2PresetUnitStrc* pPresetUnit = pLvlSubTxtRecord->pDrlgFile->pPresetUnit; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        if (pPresetUnit->nXpos > nMinX && pPresetUnit->nYpos > nMinY && pPresetUnit->nXpos < nMinX + nSizeX && pPresetUnit->nYpos < nMinY + nSizeY)
        {
            DRLGROOM_AllocPresetUnit(pOutdoor->pDrlgRoom, pMemPool, pPresetUnit->nUnitType, pPresetUnit->nIndex, pPresetUnit->nMode, nSubX + pPresetUnit->nXpos - nMinX, nSubY + pPresetUnit->nYpos - nMinY);
        }
    }
}

void __stdcall sub_0066FAD0(void* pMemPool, int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset)
{
    const int nBaseX = pSubstGroup->tBox.nPosX + nOffset;
    const int nWallLayers = pLvlSubTxtRecord->pDrlgFile->nWallLayers;
    D2DrlgRoomStrc* pDrlgRoom = pOutdoor->pDrlgRoom;
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    const int nBaseY = pSubstGroup->tBox.nPosY;
    int nCounter = 0;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            if (DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pShadowGrid, nBaseX + i, nBaseY + j) & 0x8000000)
            {
                ++nCounter;
            }
        }
    }

    DRLGROOMTILE_ReallocRoofTileGrid(pMemPool, pTileGrid, nCounter);

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            int nFlags = sub_0066F350(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            if (nFlags & 2)
            {
                DRLGGRID_AlterGridFlag(pOutdoor->pFloorGrid, nX + i, nY + j, nFlags | 0x80, 3);
            }

            for (int nLayer = 0; nLayer < nWallLayers; ++nLayer)
            {
                nFlags = DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pWallGrid[nLayer], nBaseX + i, nBaseY + j);
                if (nFlags & 1 && pOutdoor->pWallsGrids[nLayer])
                {
                    DRLGGRID_AlterGridFlag(pOutdoor->pWallsGrids[nLayer], nX + i, nY + j, nFlags, 3);
                }

                nFlags = DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pTileTypeGrid[nLayer], nBaseX + i, nBaseY + j);
                if (nFlags && pOutdoor->pOutdoorRooms[nLayer])
                {
                    DRLGGRID_AlterGridFlag(&pOutdoor->pOutdoorRooms[nLayer]->pTileTypeGrid, nX + i, nY + j, nFlags, 3);
                }
            }

            nFlags = DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pShadowGrid, nBaseX + i, nBaseY + j);
            if (nFlags & 0x8000000)
            {
                DRLGROOMTILE_InitTileShadow(pDrlgRoom, pDrlgRoom->pDrlgCoord.nPosX + i + nX, pDrlgRoom->pDrlgCoord.nPosY + j + nY, nFlags);
            }
        }
    }

    sub_0066FA10(nX, nY, pSubstGroup, pOutdoor, pMemPool, pLvlSubTxtRecord);
}

// 0x0066FCF0
int __stdcall sub_0066FCF0(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord)
{
    const int nLayers = pOutdoor->nLayers;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            if (DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pFloorGrid, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY) & 2
                || pLvlSubTxtRecord->pWallGrid[0].nWidth && DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pWallGrid, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY) & 1)
            {
                const int nFlags = DRLGGRID_GetGridEntry(pOutdoor->pFloorGrid, nX + i, nY + j);
                if (nFlags & 0x3F0FF00 || !(nFlags & 2))
                {
                    return 0;
                }

                for (int nLayer = 0; nLayer < nLayers; ++nLayer)
                {
                    if (pOutdoor->pWallsGrids[nLayer] && DRLGGRID_GetGridEntry(pOutdoor->pWallsGrids[nLayer], nX + i, nY + j) & 1)
                    {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

// 0x0066FE00
static int __stdcall sub_0066FE00_TestSubstGroupTiles(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup)
{
    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            const int nTileType = DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pTileTypeGrid, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            if (nTileType != DRLGGRID_GetGridEntry(&pOutdoor->pOutdoorRooms[0]->pTileTypeGrid, i + nX, j + nY))
            {
                return 0;
            }

            const int nFloorFlags1 = sub_0066F350(pLvlSubTxtRecord, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            if (nFloorFlags1 & 2)
            {
                const int nFloorFlags2 = DRLGGRID_GetGridEntry(pOutdoor->pFloorGrid, i + nX, j + nY);
                if (!(nFloorFlags2 & 2))
                {
                    return 0;
                }

                if ((nFloorFlags1 ^ nFloorFlags2) & 0x3F0FF00)
                {
                    return 0;
                }
            }

            const int nWallFlags1 = sub_0066F380(pLvlSubTxtRecord, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            if (nWallFlags1 & 1)
            {
                const int nWallFlags2 = DRLGGRID_GetGridEntry(pOutdoor->pWallsGrids[0], i + nX, j + nY);
                if (!(nWallFlags2 & 1))
                {
                    return 0;
                }

                if ((nWallFlags1 ^ nWallFlags2) & 0x3F0FF00)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int __stdcall sub_M16_EmitTestSubstGroupTiles(D2DrlgSubstGroupStrc* pSubstGroup, D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY)
{
    return sub_0066FE00_TestSubstGroupTiles(nX, nY, pOutdoor, pLvlSubTxtRecord, pSubstGroup);
}

// 0x00670750
void __fastcall sub_00670750_ApplySubstitutionBorder(D2UnkOutdoorStrc* pOutdoor)
{
    D2LvlSubTxt* pRecord = DATATBLS_GetLvlSubTxtRecord(pOutdoor->nLvlSubId);
    void* hArchive = pOutdoor->pLevel->pDrlg->hArchive;
    while (pRecord->dwType == pOutdoor->nLvlSubId)
    {
        DRLGTILESUB_InitializeDrlgFile(hArchive, pRecord);
        sub_0066F990_ApplySecondaryGroups(pOutdoor, pRecord);
        ++pRecord;
    }
}

// 0x006707A0
void __fastcall sub_006707A0(D2UnkOutdoorStrc2* pOutdoor)
{
    if (pOutdoor->nSubWaypoint_Shrine != -1)
    {
        D2LvlSubTxt* pLvlSubTxtRecord = DATATBLS_GetLvlSubTxtRecord(pOutdoor->nSubWaypoint_Shrine);
        unsigned int nThemeFlag = pOutdoor->nSubThemePicked;
        void* hArchive = pOutdoor->pDrlgRoom->ptDrlgLevel->pDrlg->hArchive;
        while (nThemeFlag)
        {
            if (nThemeFlag & 1)
            {
                DRLGTILESUB_InitializeDrlgFile(hArchive, pLvlSubTxtRecord);

                if (pLvlSubTxtRecord->dwCheckAll)
                {
                    sub_0066FF50(pOutdoor, pLvlSubTxtRecord);
                }
                else
                {
                    DRLGTILESUB_DoSubstitutions(pOutdoor, pLvlSubTxtRecord);
                }
            }

            nThemeFlag >>= 1;
            ++pLvlSubTxtRecord;
        }
    }
}

#include "gen/data/Source/D2Common/DRLG/RoomTile.inc"
