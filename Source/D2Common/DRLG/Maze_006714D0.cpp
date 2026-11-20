#include "D2Common.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgPresets.h"
#include "D2TxtTables.h"
#include "D2DrlgRooms.h"

struct D2DrlgOrthStrc;
struct D2DrlgBuildStrc;

extern "C" const char gszEmptyAssertText;                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                               // 0x00681E09

D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType);        // 0x0066B3E0
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pCoord1, D2DrlgCoordStrc* pCoord2, int nDistance); // 0x0066B860
int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDistance); // 0x0066B900
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B970
void __fastcall DRLGROOM_FreeRoomEx(D2DrlgRoomStrc* pDrlgRoom);                             // 0x0066C100
void __stdcall DRLGMAZE_MergeMazeRooms(D2DrlgRoomStrc* pDrlgRoom);                          // 0x00670C70

extern const int gnMazeExpansionPresetRemap[16][2];                                         // 0x006EF6D8
extern const int gnMazePresetRemap[16][3];                                                  // 0x006EF758
extern const D2MazeLevelIdStrc gnAct2ArcaneSummonerIds[4];                                  // 0x006F00F8

static __forceinline unsigned int MAZE_RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int MAZE_IsPresetUnset(D2DrlgRoomStrc* pDrlgRoom)
{
    return !((pDrlgRoom->pMaze->dwFlags >> 1) & 1);
}

static __forceinline void MAZE_SetRoomSizeFromMaze(D2DrlgRoomStrc* pDrlgRoom)
{
    D2LvlMazeTxt* pMaze = pDrlgRoom->ptDrlgLevel->pMaze;
    pDrlgRoom->pDrlgCoord.nWidth = pMaze->dwSizeX;
    pDrlgRoom->pDrlgCoord.nHeight = pMaze->dwSizeY;
}

static __forceinline void MAZE_SetPreset(D2DrlgRoomStrc* pDrlgRoom, int nLevelPrest, int nPickedFile)
{
    D2DrlgPresetRoomStrc* pPreset = pDrlgRoom->pMaze;
    pPreset->nLevelPrest = nLevelPrest;
    pPreset->nPickedFile = nPickedFile;
    pPreset->dwFlags |= 2;
}

static __forceinline D2DrlgRoomStrc* __stdcall MAZE_SetPickedFileAndPresetId(D2DrlgRoomStrc* pDrlgRoom, int nLevelPrest, int nPickedFile, int bResetFlag)
{
    D2DrlgPresetRoomStrc* pPreset = pDrlgRoom->pMaze;
    pPreset->nLevelPrest = nLevelPrest;
    pPreset->nPickedFile = nPickedFile;

    if (bResetFlag)
    {
        pPreset->dwFlags &= ~2;
    }
    else
    {
        pPreset->dwFlags |= 2;
    }

    return pDrlgRoom;
}

static int sub_00670810(D2DrlgLevelStrc* pLevel)
{
    if (!pLevel)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 28);
        exit(-1);
    }

    if (!pLevel->pMaze)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 30);
        exit(-1);
    }

    return pLevel->pMaze->dwRooms[pLevel->pDrlg->nDifficulty] == 1;
}

// 0x00670880
static __declspec(noinline) int __stdcall sub_00670880(D2DrlgRoomStrc* pDrlgRoom, int nDirection, D2DrlgRoomStrc* pNewRoomEx)
{
    D2DrlgCoordStrc* pCoord = &pNewRoomEx->pDrlgCoord;
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX - pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY;
        break;

    case 1:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY - pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 2:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY;
        break;

    case 3:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 4:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX - pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY - pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 5:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY - pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 6:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 7:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX - pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
        break;

    default:
        break;
    }

    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        if (!DRLG_CheckNotOverlappingUsingManhattanDistance(pCoord, pDrlgOrth->pBox, 0))
        {
            return 0;
        }
    }

    return DRLGMAZE_CheckRoomNotOverlaping(pNewRoomEx->ptDrlgLevel, pNewRoomEx, pDrlgRoom, 0);
}

static D2DrlgRoomStrc* __stdcall sSetChamberPreset(int bResetFlag, D2DrlgRoomStrc* pDrlgRoom); // 0x006709B0

// @ref 0x006709B0

// build: context sSetChamberPreset
static D2DrlgRoomStrc* __stdcall sSetChamberPreset(int bResetFlag, D2DrlgRoomStrc* pDrlgRoom)
{
    int nLevelPrest = 0;
    int nPickedFile = -1;

    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        switch (pDrlgOrth->nDirection)
        {
        case 0:
            nLevelPrest |= 1;
            break;

        case 1:
            nLevelPrest |= 8;
            break;

        case 2:
            nLevelPrest |= 2;
            break;

        case 3:
            nLevelPrest |= 4;
            break;

        default:
            break;
        }
    }

    D2DrlgLevelStrc* pLevel = pDrlgRoom->ptDrlgLevel;
    switch (pLevel->nLevelType)
    {
    case 3:
        nLevelPrest += 52;
        break;

    case 4:
        nLevelPrest += 108;
        break;

    case 7:
        nLevelPrest += 167;
        break;

    case 8:
        nLevelPrest += 205;
        break;

    case 10:
        nLevelPrest += 257;
        break;

    case 13:
        nLevelPrest += 301;
        break;

    case 14:
        nLevelPrest = gnMazePresetRemap[nLevelPrest][0];
        break;

    case 15:
        nLevelPrest = gnMazePresetRemap[nLevelPrest][1];
        if (pLevel->eLevelId == 52 && nLevelPrest == 361)
        {
            nPickedFile = 2;
        }

        if (pLevel->eLevelId == 54 && (nLevelPrest == 361 || nLevelPrest == 359))
        {
            nPickedFile = 3;
        }
        break;

    case 17:
        nLevelPrest += 413;
        break;

    case 18:
        nLevelPrest += 481;
        break;

    case 19:
        nLevelPrest += 509;
        break;

    case 22:
        nLevelPrest += 753;
        break;

    case 23:
        nLevelPrest = gnMazePresetRemap[nLevelPrest][2];
        if (pLevel->eLevelId == 84 && nLevelPrest == 662)
        {
            nLevelPrest = 664;
        }

        if (pLevel->eLevelId == 85 && nLevelPrest == 661)
        {
            nLevelPrest = 663;
        }
        break;

    case 24:
        nLevelPrest += 664;
        break;

    case 25:
        nLevelPrest += 704;
        break;

    case 28:
        nLevelPrest += 836;
        break;

    case 33:
        if (!sub_00670810(pLevel))
        {
            nLevelPrest += 1002;
        }
        break;

    case 32:
        nLevelPrest = gnMazeExpansionPresetRemap[nLevelPrest][0];
        break;

    case 34:
        nLevelPrest += 1058;
        break;

    case 35:
        nLevelPrest = gnMazeExpansionPresetRemap[nLevelPrest][1];
        break;

    default:
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 352);
        exit(-1);
    }

    if (nLevelPrest)
    {
        MAZE_SetPickedFileAndPresetId(pDrlgRoom, nLevelPrest, nPickedFile, bResetFlag);
    }

    return pDrlgRoom;
}

static __forceinline D2DrlgRoomStrc* DRLGMAZE_PlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->ptDrlgLevel, 2);
    MAZE_SetRoomSizeFromMaze(pNewRoomEx);

    if (!sub_00670880(pDrlgRoom, nDirection, pNewRoomEx))
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
        return 0;
    }

    DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pNewRoomEx, nDirection);
    if (bMergeRooms)
    {
        DRLGMAZE_MergeMazeRooms(pNewRoomEx);
    }
    DRLGROOM_AddRoomExToLevel(pDrlgRoom->ptDrlgLevel, pNewRoomEx);
    return pNewRoomEx;
}

static __forceinline D2DrlgRoomStrc* DRLGMAZE_AddAdjacentMazeRoom(D2DrlgRoomStrc* pDrlgRoom, int bMergeRooms, int nDirection)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGMAZE_PlaceAdjacentPresetRoom(pDrlgRoom, nDirection, bMergeRooms);
    if (pNewRoomEx)
    {
        if (bMergeRooms)
        {
            sSetChamberPreset(1, pDrlgRoom);
        }
        sSetChamberPreset(1, pNewRoomEx);
    }
    return pNewRoomEx;
}

// 0x006714D0
void __fastcall sub_006714D0(D2DrlgLevelStrc* pLevel, int nUnused, int bFirstLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->ptRoomFirst;
    if (bFirstLevel)
    {
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 1);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 2);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 3);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 0);
        MAZE_SetPreset(pFirstRoomEx, 290, -1);
    }
    else if (MAZE_RollSeed(&pLevel->pSeed) & 1)
    {
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 0);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 2);
        MAZE_SetPreset(pFirstRoomEx, 288, -1);
    }
    else
    {
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 1);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 3);
        MAZE_SetPreset(pFirstRoomEx, 289, -1);
    }
}
