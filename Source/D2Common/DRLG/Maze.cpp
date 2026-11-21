#include "D2Common.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgPresets.h"
#include "D2TxtTables.h"
#include "D2DrlgRooms.h"

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

struct D2DrlgOrthStrc;

struct D2DrlgBuildStrc;

struct D2DrlgCoordStrc;

union D2SeedStrc;

struct D2DrlgPresetRoomStrc;

struct D2LvlPrestTxt;

struct D2DrlgMapStrc;

struct D2DrlgPresetInfoStrc;

struct D2DrlgStrc;

struct D2MazeLevelIdStrc;

struct D2MazeLavaSetStrc;

struct D2DrlgRoomStrc;

struct D2DrlgLevelStrc;

struct D2LvlMazeTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType); // 0x0066B3E0

int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pCoord1, D2DrlgCoordStrc* pCoord2, int nDistance); // 0x0066B860

int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDistance); // 0x0066B900

void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B970

void __fastcall DRLGROOM_FreeRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0066C100

void __stdcall DRLGMAZE_MergeMazeRooms(D2DrlgRoomStrc* pDrlgRoom);

int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240

int __fastcall DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY); // 0x0066B800

extern const int gnMazeExpansionPresetRemap[16][2]; // 0x006EF6D8

extern const int gnMazePresetRemap[16][3]; // 0x006EF758

extern const D2MazeLevelIdStrc gnAct2ArcaneSummonerIds[4]; // 0x006F00F8

static D2DrlgRoomStrc* __stdcall sSetChamberPreset(int bResetFlag, D2DrlgRoomStrc* pDrlgRoom); // 0x006709B0

static __declspec(noinline) int DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection); // 0x00672340

static __declspec(noinline) void __stdcall DRLGMAZE_InitBasicMazeLayout(int nRoomsPerDirection, D2DrlgLevelStrc* pLevel);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed); // 0x00666ED0

D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom); // 0x00667ED0


static __declspec(noinline) int __stdcall sub_00670880(D2DrlgRoomStrc* pDrlgRoom, int nDirection, D2DrlgRoomStrc* pNewRoomEx);

static __declspec(noinline) D2DrlgRoomStrc* DRLGMAZE_GetFreeLocationForRoomSouth(D2DrlgLevelStrc* pLevel);

static __forceinline unsigned int MAZE_RollSeed(D2SeedStrc* pSeed);

static __forceinline D2DrlgRoomStrc* MAZE_ReplaceRoomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nPickedFile);

static D2DrlgRoomStrc* __stdcall DRLGMAZE_PlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms);

static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddSpecialPreset(int nDirection, int nLvlPrestId, int nFile, D2DrlgLevelStrc* pLevel);

static D2DrlgRoomStrc* __stdcall DRLGMAZE_InitRoomFixedPreset(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int nLvlPrestId, int nFile, int bUseInitPreset);


static __declspec(noinline) void __stdcall DRLGMAZE_ScanReplaceSpecialPreset(D2DrlgLevelStrc* pLevel, const D2MazeLevelIdStrc* pMazeInit, int* pRand);


// 0x006738C0
static void __stdcall sub_006738C0(D2DrlgMapStrc* pDrlgMap, int nPickedFile, D2DrlgLevelStrc* pLevel);

// build: context sub_00672E50
void __fastcall sub_00672E50(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2ArcaneSummonerIds[nRand], &nRand);
}

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

// 0x00670C70
void __stdcall DRLGMAZE_MergeMazeRooms(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!MAZE_IsPresetUnset(pDrlgRoom))
    {
        return;
    }

    D2LvlMazeTxt* pMaze = pDrlgRoom->ptDrlgLevel->pMaze;
    for (D2DrlgRoomStrc* pRoom = pDrlgRoom->ptDrlgLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        if (pRoom != pDrlgRoom && MAZE_IsPresetUnset(pRoom))
        {
            int nX = 0;
            int nY = 0;
            if (!DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(&pDrlgRoom->pDrlgCoord, &pRoom->pDrlgCoord, 1, &nX, &nY) && nX != nY)
            {
                D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth;
                while (pDrlgOrth && pDrlgOrth->pRoom != pRoom)
                {
                    pDrlgOrth = pDrlgOrth->pNext;
                }

                if (!pDrlgOrth && (int)(MAZE_RollSeed(&pRoom->pSeed) % 1000) < pMaze->dwMerge)
                {
                    const int nDirection = DRLG_GetDirectionFromCoordinates(&pRoom->pDrlgCoord, &pDrlgRoom->pDrlgCoord);
                    if (nDirection != -1)
                    {
                        DRLGROOM_AllocDrlgOrthsForRooms(pRoom, pDrlgRoom, nDirection);
                        sSetChamberPreset(1, pRoom);
                    }
                }
            }
        }
    }
}

// 0x00670DE0
static D2DrlgRoomStrc* __stdcall DRLGMAZE_InitRoomFixedPreset(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int nLvlPrestId, int nFile, int bUseInitPreset)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->ptDrlgLevel, 2);
    MAZE_SetRoomSizeFromMaze(pNewRoomEx);

    if (!sub_00670880(pDrlgRoom, nDirection, pNewRoomEx))
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
        pNewRoomEx = 0;
    }
    else
    {
        DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pNewRoomEx, nDirection);
        DRLGROOM_AddRoomExToLevel(pDrlgRoom->ptDrlgLevel, pNewRoomEx);
        if (bUseInitPreset)
        {
            sSetChamberPreset(1, pDrlgRoom);
        }

        MAZE_SetPreset(pNewRoomEx, nLvlPrestId, nFile);
    }

    return pNewRoomEx;
}

// 0x00670EB0
static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddSpecialPreset(int nDirection, int nLvlPrestId, int nFile, D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    D2DrlgRoomStrc* pNewRoomEx = 0;
    while (pDrlgRoom)
    {
        if (MAZE_IsPresetUnset(pDrlgRoom))
        {
            pNewRoomEx = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, nDirection, nLvlPrestId, nFile, 1);
            if (pNewRoomEx)
            {
                break;
            }
        }
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }
    return pNewRoomEx;
}

static __forceinline D2DrlgRoomStrc* DRLGMAZE_PlaceAdjacentPresetRoomInline(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms)
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

static __forceinline D2DrlgRoomStrc* DRLGMAZE_AddAdjacentMazeRoomInline(D2DrlgRoomStrc* pDrlgRoom, int bMergeRooms, int nDirection)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGMAZE_PlaceAdjacentPresetRoomInline(pDrlgRoom, nDirection, bMergeRooms);
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

// 0x00670F60
static void __stdcall DRLGMAZE_InitBasicMazeLayout(int nRoomsPerDirection, D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->ptRoomFirst;
    D2DrlgRoomStrc* pDrlgRoom = pFirstRoomEx;

    {
        const int nCount = nRoomsPerDirection - 1;
        if (nCount > 0)
        {
            int i = nCount;
            do
            {
                pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 1);
            } while (--i);
        }
    }

    {
        const int nCount = nRoomsPerDirection - 1;
        if (nCount > 0)
        {
            int i = nCount;
            do
            {
                pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 0);
            } while (--i);
        }
    }

    {
        const int nCount = nRoomsPerDirection - 1;
        if (nCount > 0)
        {
            int i = nCount;
            do
            {
                pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 3);
            } while (--i);
        }
    }

    {
        const int nCount = nRoomsPerDirection - 2;
        if (nCount > 0)
        {
            int i = nCount;
            do
            {
                pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 2);
            } while (--i);
        }
    }

    DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pFirstRoomEx, 2);
    sSetChamberPreset(1, pDrlgRoom);
    sSetChamberPreset(1, pFirstRoomEx);
}

static __forceinline unsigned int MAZE_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return MAZE_RollSeed(pSeed) % nMax;
    }

    return MAZE_RollSeed(pSeed) & (nMax - 1);
}

// 0x006711A0
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetRandomRoomExFromLevel(D2DrlgLevelStrc* pLevel)
{
    int i = MAZE_RollLimitedRandomNumberInline(&pLevel->pSeed, pLevel->nRooms);
    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    for (; i; --i)
    {
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }

    return pDrlgRoom;
}

// 0x00671210
void __stdcall DRLGMAZE_BuildBasicMaze(D2DrlgLevelStrc* pLevel)
{
    int nRooms = pLevel->pMaze->dwRooms[pLevel->pDrlg->nDifficulty];
    if (pLevel->eLevelId == pLevel->pDrlg->nStaffTombLevel)
    {
        nRooms *= 3;
    }

    if (pLevel->eLevelId == pLevel->pDrlg->nBossTombLevel)
    {
        nRooms *= 2;
    }

    while (pLevel->nRooms < nRooms)
    {
        D2DrlgRoomStrc* pRandomRoomEx = DRLGMAZE_GetRandomRoomExFromLevel(pLevel);
        const int nDirection = MAZE_RollSeed(&pRandomRoomEx->pSeed) & 3;
        if (MAZE_IsPresetUnset(pRandomRoomEx))
        {
            DRLGMAZE_AddAdjacentMazeRoomInline(pRandomRoomEx, 1, nDirection);
        }
    }
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

// 0x006718C0
void __stdcall DRLGMAZE_PlaceAct2TombPrev_Act5BaalPrev(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->ptRoomFirst;
    int nDirection = MAZE_RollSeed(&pLevel->pSeed) & 3;
    for (int i = 0; i < 3; ++i)
    {
        DRLGMAZE_AddAdjacentMazeRoomInline(pFirstRoomEx, 1, nDirection);
        nDirection = (nDirection + 1) % 4;
    }

    switch (pLevel->nLevelType)
    {
    case 17:
        MAZE_SetPreset(pFirstRoomEx, gnMazeTombBaalPrevPresets[nDirection][0], -1);
        break;
    case 34:
        MAZE_SetPreset(pFirstRoomEx, gnMazeTombBaalPrevPresets[nDirection][1], -1);
        break;
    }
}

void __stdcall sub_00670F60_Emit(D2DrlgLevelStrc* pLevel, int nRoomsPerDirection)
{
    DRLGMAZE_InitBasicMazeLayout(nRoomsPerDirection, pLevel);
}

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

static void __declspec(noinline) __stdcall sub_006738C0(D2DrlgMapStrc* pDrlgMap, int nPickedFile, D2DrlgLevelStrc* pLevel)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    if (nPickedFile != -1)
    {
        pDrlgMap->nPickedFile = nPickedFile;
        return;
    }

    const int nLevelDef = pDrlgMap->pLvlPrestTxtRecord->dwDef;
    const int nFiles = pDrlgMap->pLvlPrestTxtRecord->dwFiles;
    int nLvlPrestId = 0;
    switch (pLevel->nLevelType)
    {
    case 3:
        nLvlPrestId = 52;
        break;

    case 4:
        nLvlPrestId = 108;
        break;

    case 7:
        nLvlPrestId = 167;
        break;

    case 8:
        nLvlPrestId = 205;
        break;

    case 10:
        nLvlPrestId = 257;
        break;

    case 13:
        nLvlPrestId = 301;
        break;

    case 17:
        nLvlPrestId = 413;
        break;

    case 18:
        nLvlPrestId = 481;
        break;

    case 22:
        nLvlPrestId = 753;
        break;

    case 24:
        nLvlPrestId = 664;
        break;

    case 25:
        nLvlPrestId = 704;
        break;

    case 28:
        nLvlPrestId = 836;
        break;

    case 33:
        nLvlPrestId = 1002;
        break;

    case 34:
        nLvlPrestId = 1058;
        break;

    case 35:
        nLvlPrestId = 1052;
        break;

    default:
        nLvlPrestId = nLevelDef;
        break;
    }

    if (nLevelDef > nLvlPrestId && nLevelDef < nLvlPrestId + 16)
    {
        D2DrlgBuildStrc* pDrlgBuild = pLevel->pBuild;
        while (pDrlgBuild)
        {
            if (pDrlgBuild->nPreset == nLevelDef)
            {
                break;
            }
            pDrlgBuild = pDrlgBuild->pNext;
        }

        if (!pDrlgBuild)
        {
            pDrlgBuild = (D2DrlgBuildStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgBuildStrc), ".\\DRLG\\Maze.cpp", 1920, 0);
            memset(pDrlgBuild, 0, sizeof(D2DrlgBuildStrc));
            pDrlgBuild->nPreset = nLevelDef;
            pDrlgBuild->nDivisor = nFiles;
            pDrlgBuild->nRand = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, nFiles);
            pDrlgBuild->pNext = pLevel->pBuild;
            pLevel->pBuild = pDrlgBuild;
        }

        pDrlgBuild->nRand = (pDrlgBuild->nRand + 1) % pDrlgBuild->nDivisor;
        pDrlgMap->nPickedFile = pDrlgBuild->nRand;
    }
}

void __stdcall sub_Emit_00673A60_BuildMazeRoom(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLevelStrc* pLevel)
{
    D2DrlgPresetRoomStrc* pPreset = pDrlgRoom->pMaze;
    D2DrlgCoordStrc* pDrlgCoord = &pDrlgRoom->pDrlgCoord;
    D2DrlgMapStrc* pDrlgMap = DRLGPRESET_AllocDrlgMap(pLevel, pPreset->nLevelPrest, pDrlgCoord, &pLevel->pSeed);
    sub_006738C0(pDrlgMap, pPreset->nPickedFile, pLevel);
    DRLGPRESET_BuildArea(pLevel, pDrlgMap, 0, pDrlgCoord->nWidth <= 12 && pDrlgCoord->nHeight <= 12);
}

// 0x006723E0
static D2DrlgRoomStrc* DRLGMAZE_GetFreeLocationForRoomSouth(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        if ((!pResult || pRoom->pDrlgCoord.nPosY < pResult->pDrlgCoord.nPosY)
            && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pRoom, 1))
        {
            pResult = pRoom;
        }
    }
    return pResult;
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

D2DrlgRoomStrc* __fastcall FindSouthRoom(D2DrlgLevelStrc* pLevel)
{
    return DRLGMAZE_GetFreeLocationForRoomSouth(pLevel);
}

// 0x00672460
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomWest(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosX > pResult->pDrlgCoord.nPosX) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pDrlgRoom, 2))
        {
            pResult = pDrlgRoom;
        }
    }
    return pResult;
}

// 0x006724A0
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomNorth(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        if ((!pResult || pRoom->pDrlgCoord.nPosY > pResult->pDrlgCoord.nPosY)
            && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pRoom, 3))
        {
            pResult = pRoom;
        }
    }
    return pResult;
}

// 0x006724E0
static void __stdcall DRLGMAZE_ScanReplaceSpecialPreset(D2DrlgLevelStrc* pLevel, const D2MazeLevelIdStrc* pMazeInit, int* pRand)
{
    if (!MAZE_ReplaceRoomPreset(pLevel, pMazeInit->nLevelPrestId1, pMazeInit->nLevelPrestId2, pMazeInit->nPickedFile))
    {
        DRLGMAZE_AddSpecialPreset(pMazeInit->nDirection, pMazeInit->nLevelPrestId2, pMazeInit->nPickedFile, pLevel);
    }

    if (pRand)
    {
        *pRand = (*pRand + 1) % 4;
    }
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x006735F0
void __fastcall DRLGMAZE_RollAct_1_2_3_BasicPresets(D2DrlgLevelStrc* pLevel)
{
    int nLevelPrestId;
    switch (pLevel->nLevelType)
    {
    case 3:
        nLevelPrestId = 52;
        break;

    case 4:
        nLevelPrestId = 108;
        break;

    case 7:
        nLevelPrestId = 167;
        break;

    case 8:
        nLevelPrestId = 205;
        break;

    case 10:
        nLevelPrestId = 257;
        break;

    case 13:
        nLevelPrestId = 301;
        break;

    case 17:
        nLevelPrestId = 413;
        break;

    case 22:
        nLevelPrestId = 753;
        break;

    case 24:
        nLevelPrestId = 664;
        break;

    case 25:
        nLevelPrestId = 704;
        break;

    default:
        return;
    }

    if (pLevel->eLevelId == 8)
    {
        return;
    }

    int aSlots[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int nIndex = SEED_RollRandomNumber(&pLevel->pSeed) % 15;
    int nRemaining = D2_MAX(pLevel->nRooms / 5 + 1, 2);
    int nTries = 2 * pLevel->nRooms;

    for (int i = 0; i < 15; ++i)
    {
        const int nFirst = SEED_RollRandomNumber(&pLevel->pSeed) % 15;
        const int nSecond = SEED_RollRandomNumber(&pLevel->pSeed) % 15;
        const int nSlot = aSlots[nFirst];
        aSlots[nFirst] = aSlots[nSecond];
        aSlots[nSecond] = nSlot;
    }

    while (nRemaining && nTries)
    {
        const int nPreset = nLevelPrestId + aSlots[nIndex];
        const int nNewPreset = nLevelPrestId + aSlots[nIndex] + 15;
        for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
        {
            if ((~(pRoom->pMaze->dwFlags >> 1) & 1) && pRoom->pMaze->nLevelPrest == nPreset)
            {
                D2DrlgPresetRoomStrc* pMaze = pRoom->pMaze;
                pMaze->dwFlags |= 2;
                --nRemaining;
                pMaze->nLevelPrest = nNewPreset;
                pMaze->nPickedFile = -1;
                break;
            }
        }

        --nTries;
        ++nIndex;
        nIndex -= nIndex / 15 * 15;
    }
}

#include "gen/data/Source/D2Common/DRLG/Maze.inc"
