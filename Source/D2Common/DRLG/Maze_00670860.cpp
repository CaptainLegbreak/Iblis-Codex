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
struct D2DrlgCoordStrc;
struct D2DrlgPresetRoomStrc;
struct D2DrlgStrc;
union D2SeedStrc;
struct D2LvlPrestTxt;
struct D2DrlgMapStrc;
struct D2DrlgPresetInfoStrc;
struct D2MazeLevelIdStrc;
struct D2MazeLavaSetStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType); // 0x0066B3E0
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pCoord1, D2DrlgCoordStrc* pCoord2, int nDistance); // 0x0066B860
int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDistance); // 0x0066B900
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B970
void __fastcall DRLGROOM_FreeRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0066C100
void __stdcall DRLGMAZE_MergeMazeRooms(D2DrlgRoomStrc* pDrlgRoom); // 0x00670C70
extern const int gnMazeExpansionPresetRemap[16][2]; // 0x006EF6D8
extern const int gnMazePresetRemap[16][3]; // 0x006EF758
extern const D2MazeLevelIdStrc gnAct2ArcaneSummonerIds[4]; // 0x006F00F8
static __declspec(noinline) void __stdcall DRLGMAZE_ScanReplaceSpecialPreset(D2DrlgLevelStrc* pLevel, const D2MazeLevelIdStrc* pMazeInit, int* pRand); // 0x006724E0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
static D2DrlgRoomStrc* __stdcall sSetChamberPreset(int bResetFlag, D2DrlgRoomStrc* pDrlgRoom); // 0x006709B0

static int DRLGMAZE_HasMapDS1(D2DrlgRoomStrc* pDrlgRoom)
{
    return !((pDrlgRoom->pMaze->dwFlags >> 1) & 1);
}

static D2DrlgRoomStrc* DRLGMAZE_SetPickedFileAndPresetId(D2DrlgRoomStrc* pDrlgRoom, int nLevelPrest, int nPickedFile, int bResetFlag)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    pMaze->nLevelPrest = nLevelPrest;
    pMaze->nPickedFile = nPickedFile;
    if (bResetFlag)
        pMaze->dwFlags &= ~2;
    else
        pMaze->dwFlags |= 2;
    return pDrlgRoom;
}

// 0x00670860
static void DRLGMAZE_SetRoomSize(D2DrlgRoomStrc* pDrlgRoom)
{
    D2LvlMazeTxt* pMaze = pDrlgRoom->ptDrlgLevel->pMaze;
    pDrlgRoom->pDrlgCoord.nWidth = pMaze->dwSizeX;
    pDrlgRoom->pDrlgCoord.nHeight = pMaze->dwSizeY;
}

// 0x006709A0
static void sub_006709A0_SetPickedFile(D2DrlgRoomStrc* pDrlgRoom, int nPickedFile)
{
    pDrlgRoom->pMaze->nPickedFile = nPickedFile;
}

// 0x00670C10
static D2DrlgRoomStrc* __stdcall DRLGMAZE_ReplaceRoomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nPickedFile, int bResetFlag)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (DRLGMAZE_HasMapDS1(pDrlgRoom) && pDrlgRoom->pMaze->nLevelPrest == nLevelPrestId1)
            return DRLGMAZE_SetPickedFileAndPresetId(pDrlgRoom, nLevelPrestId2, nPickedFile, bResetFlag);
    }
    return 0;
}

// build: context sub_M116_Emit_00670860
D2DrlgRoomStrc* __fastcall sub_M116_Emit_00670860(D2DrlgRoomStrc* pDrlgRoom, int nFile)
{
    DRLGMAZE_SetRoomSize(pDrlgRoom);
    sub_006709A0_SetPickedFile(pDrlgRoom, nFile);
    return DRLGMAZE_ReplaceRoomPreset(pDrlgRoom->ptDrlgLevel, nFile, 0x2C5, -1, 0);
}

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

// 0x00670810
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

// 0x006709B0
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

static __forceinline D2DrlgRoomStrc* MAZE_ReplaceRoomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nPickedFile)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (MAZE_IsPresetUnset(pDrlgRoom) && pDrlgRoom->pMaze->nLevelPrest == nLevelPrestId1)
        {
            MAZE_SetPickedFileAndPresetId(pDrlgRoom, nLevelPrestId2, nPickedFile, 0);
            return pDrlgRoom;
        }
    }
    return 0;
}

static D2DrlgRoomStrc* __stdcall DRLGMAZE_PlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms)
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

static D2DrlgRoomStrc* __stdcall DRLGMAZE_InitRoomFixedPreset(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int nLvlPrestId, int nFile, int bUseInitPreset)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->ptDrlgLevel, 2);
    MAZE_SetRoomSizeFromMaze(pNewRoomEx);

    if (!sub_00670880(pDrlgRoom, nDirection, pNewRoomEx))
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
        return 0;
    }

    DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pNewRoomEx, nDirection);
    DRLGROOM_AddRoomExToLevel(pDrlgRoom->ptDrlgLevel, pNewRoomEx);
    if (bUseInitPreset)
    {
        sSetChamberPreset(1, pDrlgRoom);
    }

    MAZE_SetPreset(pNewRoomEx, nLvlPrestId, nFile);
    return pNewRoomEx;
}

// build: context DRLGMAZE_AddSpecialPreset
static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddSpecialPreset(D2DrlgLevelStrc* pLevel, int nDirection, int nLvlPrestId, int nFile)
{
    D2DrlgRoomStrc* pNewRoomEx = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (MAZE_IsPresetUnset(pDrlgRoom))
        {
            pNewRoomEx = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, nDirection, nLvlPrestId, nFile, 1);
            if (pNewRoomEx)
            {
                break;
            }
        }
    }
    return pNewRoomEx;
}

// 0x00672340
static __declspec(noinline) int DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection)
{
    if (!MAZE_IsPresetUnset(pDrlgRoom))
    {
        return 0;
    }

    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        if (pDrlgOrth->nDirection == nDirection)
        {
            return 0;
        }
    }

    D2DrlgRoomStrc* pNewRoomEx = DRLGMAZE_PlaceAdjacentPresetRoom(pDrlgRoom, nDirection, 0);
    if (pNewRoomEx)
    {
        sSetChamberPreset(1, pNewRoomEx);
    }

    const int bResult = pNewRoomEx != 0;
    if (pNewRoomEx)
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
    }
    return bResult;
}

// 0x00672420
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomEast(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosX < pResult->pDrlgCoord.nPosX) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pDrlgRoom, 0))
        {
            pResult = pDrlgRoom;
        }
    }
    return pResult;
}

// build: context DRLGMAZE_ScanReplaceSpecialPreset
static __declspec(noinline) void __stdcall DRLGMAZE_ScanReplaceSpecialPreset(D2DrlgLevelStrc* pLevel, const D2MazeLevelIdStrc* pMazeInit, int* pRand)
{
    if (!MAZE_ReplaceRoomPreset(pLevel, pMazeInit->nLevelPrestId1, pMazeInit->nLevelPrestId2, pMazeInit->nPickedFile))
    {
        DRLGMAZE_AddSpecialPreset(pLevel, pMazeInit->nDirection, pMazeInit->nLevelPrestId2, pMazeInit->nPickedFile);
    }

    if (pRand)
    {
        *pRand = (*pRand + 1) % 4;
    }
}

// 0x00672E50
void __fastcall sub_00672E50(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2ArcaneSummonerIds[nRand], &nRand);
}

#include "gen/data/Source/D2Common/DRLG/Maze_00670860.inc"

static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddAdjacentMazeRoom(D2DrlgRoomStrc* pDrlgRoom, int bMergeRooms, int nDirection)
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

// 0x006719F0
void __fastcall DRLGMAZE_PlaceArcaneSanctuary(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pRooms[60];
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->ptRoomFirst;
    const int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    int n = 0;

    memset(pRooms, 0, sizeof(pRooms));

    for (int i = 0; i < 4; ++i)
    {
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 3) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 1) % 4);
        ++n;
        DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 2], 1, (i + 1) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 2) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 2) % 4);
        ++n;
        DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 3) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 2], 1, (i + 2) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 2) % 4);
        ++n;
    }

    for (int j = 0; j < 60; ++j)
    {
        if (pRooms[j])
        {
            pRooms[j]->pMaze->nPickedFile = (j / 15 + nRand) % 4;
        }
    }

    pFirstRoomEx->pMaze->nPickedFile = 4;
}
