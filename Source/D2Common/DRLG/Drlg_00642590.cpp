#include "D2Common.h"
#include "D2Structs.h"
#include "D2Drlg.h"

struct D2DrlgActStrc;
struct D2GameStrc;
struct D2DrlgCoordStrc;
union D2SeedStrc;
struct D2DrlgStrc;




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall DRLG_GetMinAndMaxCoordinatesFromLevel(D2DrlgLevelStrc* pLevel, int* pTileMinX, int* pTileMinY, int* pTileMaxX, int* pTileMaxY); // 0x00642520

typedef void (__stdcall* AUTOMAPFN)(D2RoomStrc*);

typedef void (__stdcall* TOWNAUTOMAPFN)(int, int, int, int);



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall DUNGEON_GetMemPoolFromAct(D2DrlgActStrc* pAct); // 0x00619550
void __fastcall DRLGACTIVATE_InitializeRoomExStatusLists(D2DrlgStrc* pDrlg); // 0x0061B7E0
void __fastcall sub_00641F60_LoadTownTiles(D2DrlgStrc* pDrlg); // 0x00641F60
D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642AE0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nSeed); // 0x00650E40
void __fastcall DRLGOUTPLACE_CreateLevelConnections(D2DrlgStrc* pDrlg, unsigned char nAct); // 0x00678AD0

// 0x00642590
void __fastcall DRLG_UpdateRoomExCoordinates(D2DrlgLevelStrc* pLevel)
{
    int nTileX[2];
    int nTileY[2];

    if (!pLevel)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 739);
        exit(-1);
    }

    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    if (!pDrlgRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 740);
        exit(-1);
    }

    DRLG_GetMinAndMaxCoordinatesFromLevel(pLevel, &nTileX[0], &nTileY[0], &nTileX[1], &nTileY[1]);

    D2DrlgRoomStrc* pRoom = pDrlgRoom;

    if (pLevel->nWidth < nTileX[1] - nTileX[0])
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 747);
        exit(-1);
    }

    if (pLevel->nHeight < nTileY[1] - nTileY[0])
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 748);
        exit(-1);
    }

    const int nMinX = nTileX[0];
    const int nMinY = nTileY[0];
    for (; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        pRoom->pDrlgCoord.nPosX += pLevel->nPosX - nMinX;
        pRoom->pDrlgCoord.nPosY += pLevel->nPosY - nMinY;
    }
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline D2DrlgLevelStrc* DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (pLevel->eLevelId == nLevelId)
        {
            return pLevel;
        }
    }

    return DRLG_AllocLevel(pDrlg, nLevelId);
}

// 0x00642DA0
D2DrlgStrc* __fastcall DRLG_AllocDrlg(D2DrlgActStrc* pAct, unsigned char nActNo, void* hArchive, unsigned int nInitSeed, int nTownLevelId, unsigned int nFlags, D2GameStrc* pGame, unsigned char nDifficulty, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap)
{
    void* pMemPool = DUNGEON_GetMemPoolFromAct(pAct);
    D2DrlgStrc* pDrlg = (D2DrlgStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgStrc), ".\\DRLG\\Drlg.cpp", 0x3A, 0);
    memset(pDrlg, 0, sizeof(D2DrlgStrc));

    pDrlg->pMempool = pMemPool;
    pDrlg->hArchive = hArchive;
    pDrlg->nAct = nActNo;
    pDrlg->pAct = pAct;

    SEED_InitLowSeed(&pDrlg->pSeed, nInitSeed);

    pDrlg->dwStartSeed = SEED_RollRandomNumber(&pDrlg->pSeed);
    pDrlg->dwGameLowSeed = nInitSeed;
    pDrlg->dwFlags = nFlags;
    pDrlg->pGame = pGame;
    pDrlg->nDifficulty = nDifficulty;
    pDrlg->pfAutomap = pfAutoMap;
    pDrlg->pfTownAutomap = pfTownAutoMap;

    if (nActNo == 1)
    {
        unsigned int nStaffLevelOffset;
        unsigned int nBossLevelOffset;
        unsigned __int64 lSeed;
        do
        {
            lSeed = (unsigned __int64)pDrlg->pSeed.nLowSeed * 0x6AC690C5 + pDrlg->pSeed.nHighSeed;
            pDrlg->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pDrlg->pSeed.nLowSeed = (unsigned int)lSeed;
            nStaffLevelOffset = (unsigned int)lSeed % 7;
            lSeed = (unsigned __int64)pDrlg->pSeed.nLowSeed * 0x6AC690C5 + pDrlg->pSeed.nHighSeed;
            pDrlg->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pDrlg->pSeed.nLowSeed = (unsigned int)lSeed;
            nBossLevelOffset = (unsigned int)lSeed % 7;
        }
        while (nStaffLevelOffset == nBossLevelOffset);

        pDrlg->nStaffTombLevel = nStaffLevelOffset + 0x42;
        pDrlg->nBossTombLevel = nBossLevelOffset + 0x42;
    }
    else if (nActNo == 2)
    {
        pDrlg->bJungleInterlink = SEED_RollRandomNumber(&pDrlg->pSeed) & 1;
    }

    sub_00641F60_LoadTownTiles(pDrlg);
    DRLGACTIVATE_InitializeRoomExStatusLists(pDrlg);
    DRLGOUTPLACE_CreateLevelConnections(pDrlg, nActNo);

    if (nTownLevelId)
    {
        DRLG_InitLevel(DRLG_GetLevel(pDrlg, nTownLevelId));
    }

    return pDrlg;
}
