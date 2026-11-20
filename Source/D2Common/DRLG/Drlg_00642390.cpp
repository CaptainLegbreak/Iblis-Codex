#include "D2Structs.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                  // 0x00681EF0
#pragma function(memset)


struct D2DrlgLevelStrc;

struct D2DrlgStrc
{
    char unk0x000[0x08C];
    unsigned int dwFlags;
    char unk0x090[0x470 - 0x090];
    unsigned int dwStartSeed;
    char unk0x474[0x478 - 0x474];
    void* pMempool;
    D2DrlgLevelStrc* pLevel;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    D2DrlgRoomStrc* pDrlgRoomNext;
    unsigned int dwFlags;
    char unk0x2C[0x34 - 0x2C];
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    char unk0x44[0x60 - 0x44];
    unsigned int dwOtherFlags;
};

struct D2LevelDefBin
{
    char unk0x00[0x30];
    int dwDrlgType;
    int dwLevelType;
};

struct D2DrlgLevelStrc
{
    int nDrlgType;
    unsigned int dwFlags;
    int nRooms;
    char unk0x00C[0x010 - 0x00C];
    D2DrlgRoomStrc* ptRoomFirst;
    char unk0x014[0x1AC - 0x014];
    D2DrlgLevelStrc* pNextLevel;
    char unk0x1B0[0x1B4 - 0x1B0];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x1C0 - 0x1B8];
    int nLevelType;
    D2SeedStrc pSeed;
    char unk0x1CC[0x1D0 - 0x1CC];
    int eLevelId;
    char unk0x1D4[0x1E0 - 0x1D4];
    int nRoom_Center_Warp_X[9];
    int nRoom_Center_Warp_Y[9];
    int nRoomCoords;
    int* pPresetMaps;
};

typedef char D2DrlgLevelStrc_size_check[(sizeof(D2DrlgLevelStrc) == 0x230) ? 1 : -1];

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);            // 0x0040B430
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void __fastcall DRLGMAZE_InitLevelData(D2DrlgLevelStrc* pLevel);                                            // 0x00673B10
void __fastcall DRLGPRESET_InitLevelData(D2DrlgLevelStrc* pLevel);                                          // 0x00667430
void __fastcall DRLGOUTDOORS_AllocOutdoorInfo(D2DrlgLevelStrc* pLevel);                                     // 0x00675320
void __fastcall MazeLevelGenerate(D2DrlgLevelStrc* pLevel);                                            // 0x00673B30
void __fastcall DRLGPRESET_GenerateLevel(D2DrlgLevelStrc* pLevel);                                          // 0x00668100
void __fastcall DRLGOUTDOORS_GenerateLevel(D2DrlgLevelStrc* pLevel);                                        // 0x00675360
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId);         // 0x0066AF30
void __stdcall DUNGEON_GameTileToSubtileCoords(int* pX, int* pY);                                           // 0x00643560

// 0x00642390
static __declspec(noinline) void sub_00642390_MarkPresetRooms(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nRooms && pLevel->pPresetMaps)
    {
        int nCounter = 0;
        for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
        {
            if (pLevel->pPresetMaps[nCounter++])
            {
                pDrlgRoom->dwOtherFlags |= 1;
            }
        }
    }
}

// 0x006423D0
static __declspec(noinline) void DRLG_ComputeLevelWarpInfo(D2DrlgLevelStrc* pLevel)
{
    int bHasWarp = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (pDrlgRoom->dwFlags & 0x30000)
        {
            bHasWarp = 1;
        }

        if ((pDrlgRoom->dwFlags & 0xFF0) && !bHasWarp)
        {
            unsigned int nMask = 0x10;
            unsigned char nWarpIndex = 0;
            for (; nMask & 0xFF0; nMask <<= 1, ++nWarpIndex)
            {
                if ((pDrlgRoom->dwFlags & nMask) && DRLGWARP_GetWarpDestinationFromArray(pLevel, nWarpIndex) != -1)
                {
                    bHasWarp = 1;
                    break;
                }
            }
        }

        if (bHasWarp)
        {
            int* pX = &pLevel->nRoom_Center_Warp_X[pLevel->nRoomCoords];
            int* pY = &pLevel->nRoom_Center_Warp_Y[pLevel->nRoomCoords];
            *pX = pDrlgRoom->nTileXPos + pDrlgRoom->nTileWidth / 2;
            bHasWarp = 0;
            *pY = pDrlgRoom->nTileYPos + pDrlgRoom->nTileHeight / 2;
            DUNGEON_GameTileToSubtileCoords(pX, pY);
            ++pLevel->nRoomCoords;
        }
    }
}

// 0x006424A0
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel)
{
    SEED_InitLowSeed(&pLevel->pSeed, pLevel->eLevelId + pLevel->pDrlg->dwStartSeed);

    switch (pLevel->nDrlgType)
    {
    case 1:
        MazeLevelGenerate(pLevel);
        break;
    case 2:
        DRLGPRESET_GenerateLevel(pLevel);
        break;
    case 3:
        DRLGOUTDOORS_GenerateLevel(pLevel);
        break;
    }

    sub_00642390_MarkPresetRooms(pLevel);
    DRLG_ComputeLevelWarpInfo(pLevel);
}

// 0x00642AE0
D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    D2DrlgLevelStrc* pLevel = (D2DrlgLevelStrc*)FOG_AllocPool(pDrlg->pMempool, sizeof(D2DrlgLevelStrc), ".\\DRLG\\Drlg.cpp", 0x1A8, 0);
    memset(pLevel, 0, sizeof(D2DrlgLevelStrc));

    pLevel->pDrlg = pDrlg;
    pLevel->eLevelId = nLevelId;
    pLevel->nLevelType = DATATBLS_GetLevelDefRecord(nLevelId)->dwLevelType;
    pLevel->nDrlgType = DATATBLS_GetLevelDefRecord(nLevelId)->dwDrlgType;

    if (pDrlg->dwFlags & 1)
    {
        pLevel->dwFlags |= 0x10;
    }

    SEED_InitLowSeed(&pLevel->pSeed, pLevel->eLevelId + pLevel->pDrlg->dwStartSeed);

    switch (pLevel->nDrlgType)
    {
    case 1:
        DRLGMAZE_InitLevelData(pLevel);
        break;
    case 2:
        DRLGPRESET_InitLevelData(pLevel);
        break;
    case 3:
        DRLGOUTDOORS_AllocOutdoorInfo(pLevel);
        break;
    default:
        break;
    }

    pLevel->pNextLevel = pDrlg->pLevel;
    pDrlg->pLevel = pLevel;

    return pLevel;
}
