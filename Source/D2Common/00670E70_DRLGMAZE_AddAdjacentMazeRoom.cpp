struct D2DrlgRoomStrc;
struct D2DrlgLevelStrc;
struct D2DrlgOrthStrc;
struct D2DrlgBuildStrc;

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgOrthStrc
{
    D2DrlgRoomStrc* pRoom;
    int nDirection;
    int bPreset;
    int bInit;
    D2DrlgCoordStrc* pBox;
    D2DrlgOrthStrc* pNext;
};

struct D2RoomPresetStrc
{
    int nLevelPrest;
    int nPickedFile;
    char unk0x08[0x4];
    unsigned int dwFlags;
};

struct D2LvlMazeTxt
{
    int dwLevelId;
    int dwRooms[3];
    int dwSizeX;
    int dwSizeY;
    int dwMerge;
};

struct D2LvlPrestTxt
{
    int dwDef;
    char unk0x04[0x3C];
    int dwFiles;
};

struct D2DrlgMapStrc
{
    char unk0x00[0x4];
    int nPickedFile;
    D2LvlPrestTxt* pLvlPrestTxtRecord;
};

struct D2DrlgBuildStrc
{
    int nPreset;
    int nDivisor;
    int nRand;
    D2DrlgBuildStrc* pNext;
};

struct D2DrlgPresetInfoStrc
{
    char unk0x00[0x4];
    int nDirection;
};

struct D2DrlgStrc
{
    char unk0x00[0x94];
    int nStaffTombLevel;
    char unk0x98[0x3B8];
    unsigned char nDifficulty;
    char unk0x451[0x27];
    void* pMemPool;
    char unk0x47C[0x4];
    unsigned char nAct;
    char unk0x481[0x3];
    int nBossTombLevel;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x8];
    int nRooms;
    char unk0x0C[0x4];
    D2DrlgRoomStrc* pFirstRoomEx;
    union
    {
        D2LvlMazeTxt* pMaze;
        D2DrlgPresetInfoStrc* pPreset;
    };
    char unk0x18[0x4];
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
    char unk0x2C[0x188];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x8];
    int nLevelType;
    D2SeedStrc pSeed;
    D2DrlgBuildStrc* pBuild;
    int nLevelId;
};

struct D2DrlgRoomStrc
{
    D2DrlgOrthStrc* pDrlgOrth;
    char unk0x04[0x10];
    D2SeedStrc pSeed;
    char unk0x1C[0x4];
    D2RoomPresetStrc* pMaze;
    D2DrlgRoomStrc* pDrlgRoomNext;
    char unk0x28[0xC];
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x44[0x14];
    D2DrlgLevelStrc* pLevel;
};

struct D2MazeLevelIdStrc
{
    int nLevelPrestId1;
    int nLevelPrestId2;
    int nPickedFile;
    int nDirection;
};

struct D2MazeLavaSetStrc
{
    int nLevelPrest;
    int nDirection;
    int nPickedFile;
};

extern "C" const char gszEmptyAssertText;                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);          // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);         // 0x0045C3E0
void __fastcall DRLG_UpdateRoomExCoordinates(D2DrlgLevelStrc* pLevel);                      // 0x00642590
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                  // 0x00642BB0
void __fastcall DRLG_GetMinAndMaxCoordinatesFromLevel(D2DrlgLevelStrc* pLevel, int* pTileMinX, int* pTileMinY, int* pTileMaxX, int* pTileMaxY); // 0x00642520
D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed); // 0x00666ED0
D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom); // 0x00667ED0
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType);        // 0x0066B3E0
void __fastcall DRLGROOM_AllocDrlgOrthsForRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection); // 0x0066B5E0
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset); // 0x0066B790
int __fastcall DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY); // 0x0066B800
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pCoord1, D2DrlgCoordStrc* pCoord2, int nDistance); // 0x0066B860
int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDistance); // 0x0066B900
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B970
void __fastcall DRLGROOM_FreeRoomEx(D2DrlgRoomStrc* pDrlgRoom);                             // 0x0066C100
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetRandomRoomExFromLevel(D2DrlgLevelStrc* pLevel);      // 0x006711A0
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomEast(D2DrlgLevelStrc* pLevel);    // 0x00672420
void __fastcall sub_00672E50(D2DrlgLevelStrc* pLevel);                  // 0x00672E50
void __fastcall DRLGMAZE_RollAct_1_2_3_BasicPresets(D2DrlgLevelStrc* pLevel);               // 0x006735F0
void __fastcall DRLGMAZE_PlaceArcaneSanctuary(D2DrlgLevelStrc* pLevel);

extern const int gnMazeExpansionPresetRemap[16][2];                                         // 0x006EF6D8
extern const int gnMazePresetRemap[16][3];                                                  // 0x006EF758
extern const D2MazeLavaSetStrc gnMazeAct5LavaSets[8];                                       // 0x006EF828
extern const int gnMazeTombBaalPrevPresets[4][2];                                           // 0x006EF888
extern const D2MazeLevelIdStrc gnAct1CavePrevIds[4];                                        // 0x006EF8A8
extern const D2MazeLevelIdStrc gnAct1CaveDOEIds[4];                                         // 0x006EF8E8
extern const D2MazeLevelIdStrc gnAct1CaveDownIds[4];                                        // 0x006EF928
extern const D2MazeLevelIdStrc gnAct1CaveColdcrowIds[4];                                    // 0x006EF968
extern const D2MazeLevelIdStrc gnAct1CaveNextIds[4];                                        // 0x006EF9A8
extern const D2MazeLevelIdStrc gnAct1CryptPrevIds[4];                                       // 0x006EF9E8
extern const D2MazeLevelIdStrc gnAct1CryptSpecialIds[4];                                    // 0x006EFA28
extern const D2MazeLevelIdStrc gnAct1CryptChestIds[4];                                      // 0x006EFAA8
extern const D2MazeLevelIdStrc gnAct1CryptNextIds[4];                                       // 0x006EFAE8
extern const D2MazeLevelIdStrc gnAct1JailPrevIds[4];                                        // 0x006EFB28
extern const D2MazeLevelIdStrc gnAct1JailCathIds[4];                                        // 0x006EFB68
extern const D2MazeLevelIdStrc gnAct1JailNextIds[4];                                        // 0x006EFBA8
extern const D2MazeLevelIdStrc gnAct1JailWaypointIds[4];                                    // 0x006EFBE8
extern const D2MazeLevelIdStrc gnAct1JailPitspawnIds[4];                                    // 0x006EFC28
extern const D2MazeLevelIdStrc gnAct1CatacombsNextIds[4];                                   // 0x006EFC68
extern const D2MazeLevelIdStrc gnAct1CatacombsWaypointIds[4];                               // 0x006EFCA8
extern const D2MazeLevelIdStrc gnAct2SewerPrevIds[4];                                       // 0x006EFCE8
extern const D2MazeLevelIdStrc gnAct2SewerNextIds[4];                                       // 0x006EFD28
extern const D2MazeLevelIdStrc gnAct2SewerWaypointIds[4];                                   // 0x006EFD68
extern const D2MazeLevelIdStrc gnAct2SewerRadamentIds[4];                                   // 0x006EFDA8
extern const D2MazeLevelIdStrc gnAct2SewerChestIds[4];                                      // 0x006EFDE8
extern const D2MazeLevelIdStrc gnAct2TombPrevIds[4];                                        // 0x006EFE28
extern const D2MazeLevelIdStrc gnAct2TombNextIds[4];                                        // 0x006EFE68
extern const D2MazeLevelIdStrc gnAct2TombTreasureIds[4];                                    // 0x006EFEA8
extern const D2MazeLevelIdStrc gnAct2TombTalRashaIds[4];                                    // 0x006EFEE8
extern const D2MazeLevelIdStrc gnAct2TombNext2Ids[4];                                       // 0x006EFF28
extern const D2MazeLevelIdStrc gnAct2TombChest2Ids[4];                                      // 0x006EFF68
extern const D2MazeLevelIdStrc gnAct2TombOrificeIds[4];                                     // 0x006EFFA8
extern const D2MazeLevelIdStrc gnAct2TombBossIds[4];                                        // 0x006EFFE8
extern const D2MazeLevelIdStrc gnAct2LairPrevIds[4];                                        // 0x006F0028
extern const D2MazeLevelIdStrc gnAct2LairSpecialIds[9];                                     // 0x006F0068
extern const D2MazeLevelIdStrc gnAct3DungeonPrevIds[4];                                     // 0x006F0138
extern const D2MazeLevelIdStrc gnAct3DungeonNextIds[4];                                     // 0x006F0178
extern const D2MazeLevelIdStrc gnAct3SewerPrevIds[4];                                       // 0x006F01B8
extern const D2MazeLevelIdStrc gnAct3SewerNextIds[4];                                       // 0x006F01F8
extern const D2MazeLevelIdStrc gnAct3KurastPrevIds[4];                                      // 0x006F0238
extern const D2MazeLevelIdStrc gnAct3KurastNextIds[4];                                      // 0x006F0278
extern const D2MazeLevelIdStrc gnAct3KurastChestIds[4];                                     // 0x006F02B8
extern const D2MazeLevelIdStrc gnAct5TemplePrevIds[4];                                      // 0x006F02F8
extern const D2MazeLevelIdStrc gnAct5TempleNextIds[4];                                      // 0x006F0328
extern const D2MazeLevelIdStrc gnAct5BaalPrevIds[4];                                        // 0x006F0368
extern const D2MazeLevelIdStrc gnAct5BaalNextIds[4];                                        // 0x006F03A8
extern const D2MazeLevelIdStrc gnAct1BarracksNextIds[4];                                    // 0x006F03E8
extern const D2MazeLevelIdStrc gnAct1BarracksForgeIds[4];                                   // 0x006F0428
typedef D2DrlgRoomStrc* (__fastcall* D2MazeRoomFn)(D2DrlgLevelStrc* pLevel);
extern D2MazeRoomFn const gpfnMazeGetBarracksEntryRoom[3]; // 0x006F0468
extern const D2MazeLevelIdStrc gnAct4LavaForgeIds[2];                                       // 0x006F0474
extern const D2MazeLevelIdStrc gnAct5IcePrevIds[4];                                         // 0x006F0498
extern const D2MazeLevelIdStrc gnAct5IceNextIds[4];                                         // 0x006F04D8
extern const D2MazeLevelIdStrc gnAct5IceShrineIds[4];                                       // 0x006F0518
extern const D2MazeLevelIdStrc gnAct5IceSpecialIds[4];                                      // 0x006F0558
extern const D2MazeLevelIdStrc gnAct5IceWaypointIds[4];                                     // 0x006F0598

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
    D2LvlMazeTxt* pMaze = pDrlgRoom->pLevel->pMaze;
    pDrlgRoom->pDrlgCoord.nWidth = pMaze->dwSizeX;
    pDrlgRoom->pDrlgCoord.nHeight = pMaze->dwSizeY;
}

static __forceinline void MAZE_SetPreset(D2DrlgRoomStrc* pDrlgRoom, int nLevelPrest, int nPickedFile)
{
    D2RoomPresetStrc* pPreset = pDrlgRoom->pMaze;
    pPreset->nLevelPrest = nLevelPrest;
    pPreset->nPickedFile = nPickedFile;
    pPreset->dwFlags |= 2;
}

static __forceinline D2DrlgRoomStrc* __stdcall MAZE_SetPickedFileAndPresetId(D2DrlgRoomStrc* pDrlgRoom, int nLevelPrest, int nPickedFile, int bResetFlag)
{
    D2RoomPresetStrc* pPreset = pDrlgRoom->pMaze;
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

    return DRLGMAZE_CheckRoomNotOverlaping(pNewRoomEx->pLevel, pNewRoomEx, pDrlgRoom, 0);
}

static D2DrlgRoomStrc* __stdcall DRLGMAZE_PickRoomPreset(int bResetFlag, D2DrlgRoomStrc* pDrlgRoom); // 0x006709B0

// build: context DRLGMAZE_PickRoomPreset
static D2DrlgRoomStrc* __stdcall DRLGMAZE_PickRoomPreset(int bResetFlag, D2DrlgRoomStrc* pDrlgRoom)
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

    D2DrlgLevelStrc* pLevel = pDrlgRoom->pLevel;
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
        if (pLevel->nLevelId == 52 && nLevelPrest == 361)
        {
            nPickedFile = 2;
        }

        if (pLevel->nLevelId == 54 && (nLevelPrest == 361 || nLevelPrest == 359))
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
        if (pLevel->nLevelId == 84 && nLevelPrest == 662)
        {
            nLevelPrest = 664;
        }

        if (pLevel->nLevelId == 85 && nLevelPrest == 661)
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
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (MAZE_IsPresetUnset(pDrlgRoom) && pDrlgRoom->pMaze->nLevelPrest == nLevelPrestId1)
        {
            MAZE_SetPickedFileAndPresetId(pDrlgRoom, nLevelPrestId2, nPickedFile, 0);
            return pDrlgRoom;
        }
    }
    return 0;
}

void __stdcall DRLGMAZE_MergeMazeRooms(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!MAZE_IsPresetUnset(pDrlgRoom))
    {
        return;
    }

    D2LvlMazeTxt* pMaze = pDrlgRoom->pLevel->pMaze;
    for (D2DrlgRoomStrc* pRoom = pDrlgRoom->pLevel->pFirstRoomEx; pRoom; pRoom = pRoom->pDrlgRoomNext)
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
                        DRLGMAZE_PickRoomPreset(1, pRoom);
                    }
                }
            }
        }
    }
}

static D2DrlgRoomStrc* __stdcall DRLGMAZE_PlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms); // 0x00670D70

// build: context DRLGMAZE_PlaceAdjacentPresetRoom
static D2DrlgRoomStrc* __stdcall DRLGMAZE_PlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->pLevel, 2);
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
    DRLGROOM_AddRoomExToLevel(pDrlgRoom->pLevel, pNewRoomEx);
    return pNewRoomEx;
}

static D2DrlgRoomStrc* __stdcall DRLGMAZE_InitRoomFixedPreset(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int nLvlPrestId, int nFile, int bUseInitPreset)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->pLevel, 2);
    MAZE_SetRoomSizeFromMaze(pNewRoomEx);

    if (!sub_00670880(pDrlgRoom, nDirection, pNewRoomEx))
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
        return 0;
    }

    DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pNewRoomEx, nDirection);
    DRLGROOM_AddRoomExToLevel(pDrlgRoom->pLevel, pNewRoomEx);
    if (bUseInitPreset)
    {
        DRLGMAZE_PickRoomPreset(1, pDrlgRoom);
    }

    MAZE_SetPreset(pNewRoomEx, nLvlPrestId, nFile);
    return pNewRoomEx;
}

// 0x00670E70
static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddAdjacentMazeRoom(D2DrlgRoomStrc* pDrlgRoom, int bMergeRooms, int nDirection)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGMAZE_PlaceAdjacentPresetRoom(pDrlgRoom, nDirection, bMergeRooms);
    if (pNewRoomEx)
    {
        if (bMergeRooms)
        {
            DRLGMAZE_PickRoomPreset(1, pDrlgRoom);
        }
        DRLGMAZE_PickRoomPreset(1, pNewRoomEx);
    }
    return pNewRoomEx;
}

static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddSpecialPreset(D2DrlgLevelStrc* pLevel, int nDirection, int nLvlPrestId, int nFile)
{
    D2DrlgRoomStrc* pNewRoomEx = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
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

static void __stdcall DRLGMAZE_InitBasicMazeLayout(D2DrlgLevelStrc* pLevel, int nRoomsPerDirection)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->pFirstRoomEx;
    D2DrlgRoomStrc* pDrlgRoom = pFirstRoomEx;

    for (int i = nRoomsPerDirection - 1; i > 0; --i)
    {
        pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoom(pDrlgRoom, 1, 1);
    }

    for (int i = nRoomsPerDirection - 1; i > 0; --i)
    {
        pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoom(pDrlgRoom, 1, 0);
    }

    for (int i = nRoomsPerDirection - 1; i > 0; --i)
    {
        pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoom(pDrlgRoom, 1, 3);
    }

    for (int i = nRoomsPerDirection - 2; i > 0; --i)
    {
        pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoom(pDrlgRoom, 1, 2);
    }

    DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pFirstRoomEx, 2);
    DRLGMAZE_PickRoomPreset(1, pDrlgRoom);
    DRLGMAZE_PickRoomPreset(1, pFirstRoomEx);
}

void __stdcall DRLGMAZE_BuildBasicMaze(D2DrlgLevelStrc* pLevel)
{
    int nRooms = pLevel->pMaze->dwRooms[pLevel->pDrlg->nDifficulty];
    if (pLevel->nLevelId == pLevel->pDrlg->nStaffTombLevel)
    {
        nRooms *= 3;
    }

    if (pLevel->nLevelId == pLevel->pDrlg->nBossTombLevel)
    {
        nRooms *= 2;
    }

    while (pLevel->nRooms < nRooms)
    {
        D2DrlgRoomStrc* pRandomRoomEx = DRLGMAZE_GetRandomRoomExFromLevel(pLevel);
        const int nDirection = MAZE_RollSeed(&pRandomRoomEx->pSeed) & 3;
        if (MAZE_IsPresetUnset(pRandomRoomEx))
        {
            DRLGMAZE_AddAdjacentMazeRoom(pRandomRoomEx, 1, nDirection);
        }
    }
}

static void __stdcall DRLGMAZE_FillBlankMazeSpaces(D2DrlgLevelStrc* pLevel, int nLevelPrest, D2DrlgRoomStrc* pIgnoreRoomEx); // 0x00671320

// build: context DRLGMAZE_FillBlankMazeSpaces
static void __stdcall DRLGMAZE_FillBlankMazeSpaces(D2DrlgLevelStrc* pLevel, int nLevelPrest, D2DrlgRoomStrc* pIgnoreRoomEx)
{
    void* pMemPool = pLevel->pDrlg->pMemPool;
    D2DrlgRoomStrc** ppDrlgRooms = (D2DrlgRoomStrc**)FOG_AllocPool(pMemPool, sizeof(D2DrlgRoomStrc*) * pLevel->nRooms, ".\\DRLG\\Maze.cpp", 625, 0);

    D2DrlgRoomStrc* pTemp = pLevel->pFirstRoomEx;
    const int nRooms = pLevel->nRooms;
    for (int i = 0; i < nRooms; ++i)
    {
        ppDrlgRooms[i] = pTemp;
        pTemp = pTemp->pDrlgRoomNext;
    }

    for (int i = 0; i < nRooms; ++i)
    {
        if (ppDrlgRooms[i] != pIgnoreRoomEx)
        {
            for (int j = 0; j < 8; ++j)
            {
                DRLGMAZE_InitRoomFixedPreset(ppDrlgRooms[i], j, nLevelPrest, -1, 0);
            }
        }
    }

    sub_0040B480(pMemPool, ppDrlgRooms, ".\\DRLG\\Maze.cpp", 648, 0);
}

static void DRLGMAZE_PlaceAct5LavaPresets(D2DrlgLevelStrc* pLevel); // 0x00671430

// build: context DRLGMAZE_PlaceAct5LavaPresets
static void DRLGMAZE_PlaceAct5LavaPresets(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->pFirstRoomEx;
    const int nSet = 2 * (MAZE_RollSeed(&pFirstRoomEx->pSeed) & 3);
    D2_ASSERT(nSet < 7, 683);

    const D2MazeLavaSetStrc* pSet = &gnMazeAct5LavaSets[nSet];
    DRLGMAZE_InitRoomFixedPreset(pFirstRoomEx, pSet->nDirection, pSet->nLevelPrest, pSet->nPickedFile, 1);
    ++pSet;
    DRLGMAZE_InitRoomFixedPreset(pFirstRoomEx, pSet->nDirection, pSet->nLevelPrest, pSet->nPickedFile, 1);
    DRLGMAZE_FillBlankMazeSpaces(pLevel, 836, 0);
}

static void __stdcall sub_006714D0(D2DrlgLevelStrc* pLevel, int bFirstLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->pFirstRoomEx;
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

void __stdcall DRLGMAZE_PlaceAct2TombPrev_Act5BaalPrev(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->pFirstRoomEx;
    int nDirection = MAZE_RollSeed(&pLevel->pSeed) & 3;
    for (int i = 0; i < 3; ++i)
    {
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, nDirection);
        nDirection = (nDirection + 1) % 4;
    }

    if (pLevel->nLevelType == 17)
    {
        MAZE_SetPreset(pFirstRoomEx, gnMazeTombBaalPrevPresets[nDirection][0], -1);
    }
    else if (pLevel->nLevelType == 34)
    {
        MAZE_SetPreset(pFirstRoomEx, gnMazeTombBaalPrevPresets[nDirection][1], -1);
    }
}

static int DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection)
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
        DRLGMAZE_PickRoomPreset(1, pNewRoomEx);
    }

    const int bResult = pNewRoomEx != 0;
    if (pNewRoomEx)
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
    }
    return bResult;
}

static D2DrlgRoomStrc* DRLGMAZE_GetFreeLocationForRoomSouth(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosY < pResult->pDrlgCoord.nPosY) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pDrlgRoom, 1))
        {
            pResult = pDrlgRoom;
        }
    }
    return pResult;
}

D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomWest(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosX > pResult->pDrlgCoord.nPosX) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pDrlgRoom, 2))
        {
            pResult = pDrlgRoom;
        }
    }
    return pResult;
}

D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomNorth(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosY > pResult->pDrlgCoord.nPosY) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pDrlgRoom, 3))
        {
            pResult = pDrlgRoom;
        }
    }
    return pResult;
}

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

static void sub_00672550(D2DrlgLevelStrc* pLevel); // 0x00672550

// build: context sub_00672550
static void sub_00672550(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CavePrevIds[nRand], &nRand);
    if (pLevel->nLevelId == 8)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CaveDOEIds[nRand], &nRand);
    }
    else
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CaveDownIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 9)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CaveColdcrowIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 10)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CaveNextIds[nRand], &nRand);
    }
}

static void sub_00672610(D2DrlgLevelStrc* pLevel); // 0x00672610

// build: context sub_00672610
static void sub_00672610(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CryptPrevIds[nRand], &nRand);
    if (pLevel->nLevelId == 18)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CryptSpecialIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 19 || pLevel->nLevelId == 133)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CryptChestIds[nRand], &nRand);
    }

    if (pLevel->nLevelId >= 21 && pLevel->nLevelId <= 24)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CryptNextIds[nRand], &nRand);
    }
}

static void sub_006726D0(D2DrlgLevelStrc* pLevel); // 0x006726D0

// build: context sub_006726D0
static void sub_006726D0(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailPrevIds[nRand], &nRand);
    if (pLevel->nLevelId == 29)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailWaypointIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 30)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailPitspawnIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 31)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailCathIds[nRand], &nRand);
    }
    else
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailNextIds[nRand], &nRand);
    }
}

static void sub_006727A0(D2DrlgLevelStrc* pLevel); // 0x006727A0

// build: context sub_006727A0
static void sub_006727A0(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CatacombsNextIds[nRand], &nRand);
    if (pLevel->nLevelId == 35)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CatacombsWaypointIds[nRand], &nRand);
    }
}

static __forceinline D2DrlgRoomStrc* MAZE_PlaceAdjacentPresetRoomInline(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->pLevel, 2);
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
    DRLGROOM_AddRoomExToLevel(pDrlgRoom->pLevel, pNewRoomEx);
    return pNewRoomEx;
}

static __forceinline D2DrlgRoomStrc* MAZE_AddAdjacentMazeRoomInline(D2DrlgRoomStrc* pDrlgRoom, int nDirection)
{
    D2DrlgRoomStrc* pNewRoomEx = MAZE_PlaceAdjacentPresetRoomInline(pDrlgRoom, nDirection, 1);
    if (pNewRoomEx)
    {
        DRLGMAZE_PickRoomPreset(1, pDrlgRoom);
        DRLGMAZE_PickRoomPreset(1, pNewRoomEx);
    }
    return pNewRoomEx;
}

static __declspec(noinline) void DRLGMAZE_ScanReplaceSpecialAct2SewersPresets(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_ScanReplaceSpecialAct2SewersPresets(D2DrlgLevelStrc* pLevel)
{
    const int nDirection = (2 * (MAZE_RollSeed(&pLevel->pSeed) & 1)) | 1;
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;

    switch (pLevel->nLevelId)
    {
    case 47:
    {
        D2DrlgRoomStrc* pDrlgRoom = DRLGMAZE_GetFreeLocationForRoomSouth(pLevel);
        pDrlgRoom = MAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1);
        pDrlgRoom = MAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1);
        DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, 0, 333, 0, 1);

        pDrlgRoom = DRLGMAZE_GetFreeLocationForRoomWest(pLevel);
        pDrlgRoom = MAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 2);
        pDrlgRoom = MAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 2);
        pDrlgRoom = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, nDirection, 336, 0, 1);
        D2DrlgRoomStrc* pLastRoomEx = MAZE_PlaceAdjacentPresetRoomInline(pDrlgRoom, nDirection, 0);
        if (pLastRoomEx)
        {
            DRLGMAZE_PickRoomPreset(1, pLastRoomEx);
        }

        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerNextIds[nRand], &nRand);
        break;
    }
    case 48:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerPrevIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerWaypointIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerNextIds[nRand], &nRand);
        break;

    case 49:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerPrevIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerRadamentIds[nRand], &nRand);
        break;

    case 65:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerPrevIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerChestIds[nRand], &nRand);
        break;

    default:
        break;
    }
}

static void DRLGMAZE_PlaceAct2TombStuff(D2DrlgLevelStrc* pLevel); // 0x00672BE0

// build: context DRLGMAZE_PlaceAct2TombStuff
static void DRLGMAZE_PlaceAct2TombStuff(D2DrlgLevelStrc* pLevel)
{
    D2RoomPresetStrc* pPreset = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        pPreset = pDrlgRoom->pMaze;
        if (pPreset->nLevelPrest > 428)
        {
            break;
        }
    }

    int nRand = 0;
    switch (pPreset->nLevelPrest)
    {
    case 446:
        nRand = 0;
        break;

    case 445:
        nRand = 1;
        break;

    case 447:
        nRand = 2;
        break;

    case 444:
        nRand = 3;
        break;

    default:
        D2_ASSERT(0, 1305);
    }

    if (pLevel->nLevelId >= 55 && pLevel->nLevelId <= 58)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombPrevIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 57)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombNextIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 59 || pLevel->nLevelId == 61)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombTreasureIds[nRand], &nRand);
    }

    if (pLevel->nLevelId >= 66 && pLevel->nLevelId <= 72 && pLevel->nLevelId != pLevel->pDrlg->nStaffTombLevel)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombTreasureIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 59)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombTalRashaIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 60)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombNext2Ids[nRand], &nRand);
    }

    if (pLevel->nLevelId == 59 || pLevel->nLevelId == 61)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombChest2Ids[nRand], &nRand);
    }

    if (pLevel->nLevelId == pLevel->pDrlg->nStaffTombLevel)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombOrificeIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == pLevel->pDrlg->nBossTombLevel)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombBossIds[nRand], &nRand);
    }
}

static void DRLGMAZE_PlaceAct2LairStuff(D2DrlgLevelStrc* pLevel); // 0x00672DC0

// build: context DRLGMAZE_PlaceAct2LairStuff
static void DRLGMAZE_PlaceAct2LairStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    if (pLevel->nLevelId == 64)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2LairSpecialIds[8], &nRand);
        nRand = 3;
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2LairSpecialIds[7], &nRand);
    }
    else
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2LairSpecialIds[nRand], &nRand);
    }

    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2LairPrevIds[nRand], &nRand);
}

static void DRLGMAZE_PlaceAct3DungeonStuff(D2DrlgLevelStrc* pLevel); // 0x00672EA0

// build: context DRLGMAZE_PlaceAct3DungeonStuff
static void DRLGMAZE_PlaceAct3DungeonStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3DungeonPrevIds[nRand], &nRand);
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3DungeonNextIds[nRand], &nRand);
}

static void DRLGMAZE_PlaceAct3SewerStuff(D2DrlgLevelStrc* pLevel); // 0x00672F00

// build: context DRLGMAZE_PlaceAct3SewerStuff
static void DRLGMAZE_PlaceAct3SewerStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3SewerPrevIds[nRand], &nRand);
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3SewerNextIds[nRand], &nRand);
}

static void DRLGMAZE_PlaceAct3MephistoStuff(D2DrlgLevelStrc* pLevel); // 0x00672F60

// build: context DRLGMAZE_PlaceAct3MephistoStuff
static void DRLGMAZE_PlaceAct3MephistoStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3KurastPrevIds[nRand], &nRand);
    if (pLevel->nLevelId == 101)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3KurastNextIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3KurastChestIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 100)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3KurastChestIds[nRand], &nRand);
    }
}

static void DRLGMAZE_PlaceAct5TempleStuff(D2DrlgLevelStrc* pLevel); // 0x00673000

// build: context DRLGMAZE_PlaceAct5TempleStuff
static void DRLGMAZE_PlaceAct5TempleStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) % 3;
    const int nFirstRand = nRand;
    if (pLevel->nLevelId != 124)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5TemplePrevIds[nRand], &nRand);
    }

    if (pLevel->nLevelId == 123)
    {
        D2_ASSERT(nRand != nFirstRand, 1532);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5TempleNextIds[nRand], &nRand);
    }
}

static void DRLGMAZE_PlaceAct5BaalStuff(D2DrlgLevelStrc* pLevel); // 0x006730B0

// build: context DRLGMAZE_PlaceAct5BaalStuff
static void DRLGMAZE_PlaceAct5BaalStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5BaalPrevIds[nRand], &nRand);
    if (pLevel->nLevelId == 129)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5BaalNextIds[nRand], &nRand);
    }
}

static void DRLGMAZE_PlaceAct1Barracks(D2DrlgLevelStrc* pLevel); // 0x00673120

// build: context DRLGMAZE_PlaceAct1Barracks
static void DRLGMAZE_PlaceAct1Barracks(D2DrlgLevelStrc* pLevel)
{
    D2DrlgLevelStrc* pOuterCloisterLevel = DRLG_GetLevel(pLevel->pDrlg, 27);
    int nDirection = pOuterCloisterLevel->pPreset->nDirection;
    D2DrlgRoomStrc* pDrlgRoom = gpfnMazeGetBarracksEntryRoom[nDirection](pLevel);
    int nX = pOuterCloisterLevel->nPosX;
    D2LvlMazeTxt* pMaze = pLevel->pMaze;
    int nY = pOuterCloisterLevel->nPosY;
    D2DrlgRoomStrc* pBarracksRoomEx = 0;

    switch (nDirection)
    {
    case 0:
        pBarracksRoomEx = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, 2, 167, 0, 1);
        DRLGROOM_AddOrth(&pBarracksRoomEx->pDrlgOrth, pOuterCloisterLevel, 2, 0);
        nX -= pBarracksRoomEx->pDrlgCoord.nPosX + pMaze->dwSizeX;
        nY += pOuterCloisterLevel->nHeight / 2 - pBarracksRoomEx->pDrlgCoord.nPosY;
        break;

    case 1:
        pBarracksRoomEx = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, 3, 167, 1, 1);
        DRLGROOM_AddOrth(&pBarracksRoomEx->pDrlgOrth, pOuterCloisterLevel, 3, 0);
        nX += pOuterCloisterLevel->nWidth / 2 - pBarracksRoomEx->pDrlgCoord.nPosX - 6;
        nY -= pBarracksRoomEx->pDrlgCoord.nPosY + pMaze->dwSizeY;
        break;

    case 2:
        pBarracksRoomEx = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, 0, 167, 2, 1);
        DRLGROOM_AddOrth(&pBarracksRoomEx->pDrlgOrth, pOuterCloisterLevel, 0, 0);
        nX += pOuterCloisterLevel->nWidth - pBarracksRoomEx->pDrlgCoord.nPosX;
        nY += pOuterCloisterLevel->nHeight / 2 - pBarracksRoomEx->pDrlgCoord.nPosY + 1;
        break;

    default:
        break;
    }

    if (MAZE_RollSeed(&pLevel->pSeed) & 1)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1BarracksNextIds[nDirection], &nDirection);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1BarracksForgeIds[nDirection], &nDirection);
    }
    else
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1BarracksForgeIds[nDirection], &nDirection);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1BarracksNextIds[nDirection], &nDirection);
    }

    for (D2DrlgRoomStrc* pRoom = pLevel->pFirstRoomEx; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        pRoom->pDrlgCoord.nPosX += nX;
        pRoom->pDrlgCoord.nPosY += nY;
    }

    int nTileMinX = 0;
    int nTileMinY = 0;
    int nTileMaxX = 0;
    int nTileMaxY = 0;
    DRLG_GetMinAndMaxCoordinatesFromLevel(pLevel, &nTileMinX, &nTileMinY, &nTileMaxX, &nTileMaxY);
    pLevel->nPosX = nTileMinX;
    pLevel->nPosY = nTileMinY;
    pLevel->nWidth = nTileMaxX - nTileMinX;
    pLevel->nHeight = nTileMaxY - nTileMinY;
}

static void DRLGMAZE_PlaceAct4Lava(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->pDrlg->nAct == 4)
    {
        return;
    }

    D2DrlgLevelStrc* pChaosSanctum = DRLG_GetLevel(pLevel->pDrlg, 108);
    D2DrlgRoomStrc* pParentRoom = DRLGMAZE_GetFreeLocationForRoomNorth(pLevel);
    DRLGMAZE_InitRoomFixedPreset(pParentRoom, 3, 852, -1, 1);

    pParentRoom = DRLGMAZE_GetFreeLocationForRoomSouth(pLevel);
    D2DrlgRoomStrc* pBridgeRoomEx1 = DRLGMAZE_InitRoomFixedPreset(pParentRoom, 1, 855, -1, 1);
    D2DrlgRoomStrc* pBridgeRoomEx2 = DRLGMAZE_PlaceAdjacentPresetRoom(pBridgeRoomEx1, 1, 0);
    if (pBridgeRoomEx2)
    {
        MAZE_SetPreset(pBridgeRoomEx2, 856, -1);
    }

    D2DrlgRoomStrc* pBridgeRoomEx3 = DRLGMAZE_PlaceAdjacentPresetRoom(pBridgeRoomEx2, 1, 0);
    if (pBridgeRoomEx3)
    {
        MAZE_SetPreset(pBridgeRoomEx3, 856, -1);
    }

    DRLGROOM_AddOrth(&pBridgeRoomEx3->pDrlgOrth, pChaosSanctum, 1, 0);
    const int nX = pChaosSanctum->nPosX + 2 * pBridgeRoomEx3->pDrlgCoord.nWidth - pBridgeRoomEx3->pDrlgCoord.nPosX;
    const int nY = pChaosSanctum->nPosY + pChaosSanctum->nHeight - pBridgeRoomEx3->pDrlgCoord.nPosY;

    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct4LavaForgeIds[MAZE_RollSeed(&pLevel->pSeed) & 1], 0);
    DRLGMAZE_FillBlankMazeSpaces(pLevel, 836, pBridgeRoomEx3);

    for (D2DrlgRoomStrc* pRoom = pLevel->pFirstRoomEx; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        pRoom->pDrlgCoord.nPosX += nX;
        pRoom->pDrlgCoord.nPosY += nY;
    }

    int nTileMinX = 0;
    int nTileMinY = 0;
    int nTileMaxX = 0;
    int nTileMaxY = 0;
    DRLG_GetMinAndMaxCoordinatesFromLevel(pLevel, &nTileMinX, &nTileMinY, &nTileMaxX, &nTileMaxY);
    pLevel->nPosX = nTileMinX;
    pLevel->nPosY = nTileMinY;
    pLevel->nWidth = nTileMaxX - nTileMinX;
    pLevel->nHeight = nTileMaxY - nTileMinY;
}

static void DRLGMAZE_PlaceAct5IceStuff(D2DrlgLevelStrc* pLevel); // 0x00673530

// build: context DRLGMAZE_PlaceAct5IceStuff
static void DRLGMAZE_PlaceAct5IceStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IcePrevIds[nRand], &nRand);
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IceNextIds[nRand], &nRand);
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IceShrineIds[nRand], &nRand);

    switch (pLevel->nLevelId)
    {
    case 115:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IceSpecialIds[nRand], &nRand);

    case 113:
    case 118:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IceWaypointIds[nRand], &nRand);
        break;

    default:
        break;
    }
}

static void __stdcall sub_006738C0(D2DrlgMapStrc* pDrlgMap, int nPickedFile, D2DrlgLevelStrc* pLevel)
{
    void* pMemPool = pLevel->pDrlg->pMemPool;
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
            pDrlgBuild->nRand = 0;
            pDrlgBuild->pNext = 0;
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

// 0x00673A60
static void __stdcall sub_00673A60(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLevelStrc* pLevel)
{
    D2RoomPresetStrc* pPreset = pDrlgRoom->pMaze;
    D2DrlgCoordStrc* pDrlgCoord = &pDrlgRoom->pDrlgCoord;
    D2DrlgMapStrc* pDrlgMap = DRLGPRESET_AllocDrlgMap(pLevel, pPreset->nLevelPrest, pDrlgCoord, &pLevel->pSeed);
    sub_006738C0(pDrlgMap, pPreset->nPickedFile, pLevel);
    D2DrlgRoomStrc* pBuiltRoomEx = DRLGPRESET_BuildArea(pLevel, pDrlgMap, 0, pDrlgCoord->nWidth <= 12 && pDrlgCoord->nHeight <= 12);
    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        if (pDrlgOrth->bInit == 1)
        {
            DRLGROOM_AllocDrlgOrthsForRooms(pBuiltRoomEx, pDrlgOrth->pRoom, pDrlgOrth->nDirection);
        }
    }
    DRLGROOM_FreeRoomEx(pDrlgRoom);
}

// 0x00673AF0
static void DRLGMAZE_RollBasicPresets(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx;
    while (pDrlgRoom)
    {
        D2DrlgRoomStrc* pCurrentRoomEx = pDrlgRoom;
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
        sub_00673A60(pCurrentRoomEx, pLevel);
    }
}

void __fastcall DRLGMAZE_GenerateLevel(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pDrlgRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
    MAZE_SetRoomSizeFromMaze(pDrlgRoom);
    pDrlgRoom->pDrlgCoord.nPosX = pLevel->nPosX + (pLevel->nWidth - pDrlgRoom->pDrlgCoord.nWidth) / 2;
    pDrlgRoom->pDrlgCoord.nPosY = pLevel->nPosY + (pLevel->nHeight - pDrlgRoom->pDrlgCoord.nHeight) / 2;
    DRLGROOM_AddRoomExToLevel(pLevel, pDrlgRoom);

    switch (pLevel->nLevelType)
    {
    case 3:
        DRLGMAZE_BuildBasicMaze(pLevel);
        sub_00672550(pLevel);
        break;

    case 4:
        DRLGMAZE_BuildBasicMaze(pLevel);
        sub_00672610(pLevel);
        break;

    case 7:
        DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
        DRLGMAZE_BuildBasicMaze(pLevel);
        break;

    case 8:
        DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
        DRLGMAZE_BuildBasicMaze(pLevel);
        sub_006726D0(pLevel);
        break;

    case 10:
        sub_006714D0(pLevel, pLevel->nLevelId == 34);
        DRLGMAZE_BuildBasicMaze(pLevel);
        sub_006727A0(pLevel);
        break;

    case 13:
        DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
        DRLGMAZE_BuildBasicMaze(pLevel);
        DRLGMAZE_ScanReplaceSpecialAct2SewersPresets(pLevel);
        break;

    case 14:
    case 15:
    case 23:
        DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
        break;

    case 17:
        if (pLevel->nLevelId == 61)
        {
            MAZE_SetPreset(pDrlgRoom, 480, -1);
        }
        else
        {
            DRLGMAZE_PlaceAct2TombPrev_Act5BaalPrev(pLevel);
            DRLGMAZE_BuildBasicMaze(pLevel);
            DRLGMAZE_PlaceAct2TombStuff(pLevel);
        }
        break;

    case 18:
        DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
        DRLGMAZE_BuildBasicMaze(pLevel);
        DRLGMAZE_PlaceAct2LairStuff(pLevel);
        break;

    case 19:
        DRLGMAZE_PlaceArcaneSanctuary(pLevel);
        sub_00672E50(pLevel);
        break;

    case 22:
        DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
        DRLGMAZE_BuildBasicMaze(pLevel);
        DRLGMAZE_PlaceAct3MephistoStuff(pLevel);
        break;

    case 24:
        DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
        DRLGMAZE_BuildBasicMaze(pLevel);
        DRLGMAZE_PlaceAct3DungeonStuff(pLevel);
        break;

    case 25:
        if (pLevel->nLevelId == 92)
        {
            DRLGMAZE_InitBasicMazeLayout(pLevel, 5);
            D2_ASSERT(MAZE_ReplaceRoomPreset(pLevel, 709, 735, -1), 2121);
            D2_ASSERT(MAZE_ReplaceRoomPreset(pLevel, 710, 736, -1), 2122);
            D2_ASSERT(MAZE_ReplaceRoomPreset(pLevel, 713, 737, -1), 2123);
            D2_ASSERT(MAZE_ReplaceRoomPreset(pLevel, 714, 738, -1), 2124);
            DRLGMAZE_BuildBasicMaze(pLevel);
            DRLGMAZE_PlaceAct3SewerStuff(pLevel);
        }
        else
        {
            DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
            DRLGMAZE_BuildBasicMaze(pLevel);
            DRLGMAZE_PlaceAct3SewerStuff(pLevel);
        }
        break;

    case 28:
        DRLGMAZE_BuildBasicMaze(pLevel);
        break;

    case 33:
        switch (pLevel->nLevelId)
        {
        case 114:
            D2_ASSERT(pLevel->pFirstRoomEx, 2142);
            MAZE_SetPreset(pLevel->pFirstRoomEx, SEED_RollLimitedRandomNumber(&pDrlgRoom->pLevel->pSeed, 2) ? 1038 : 1039, -1);
            break;

        case 116:
            MAZE_SetPreset(pLevel->pFirstRoomEx, 1040, -1);
            break;

        case 119:
            MAZE_SetPreset(pLevel->pFirstRoomEx, 1041, -1);
            break;

        default:
            DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
            DRLGMAZE_BuildBasicMaze(pLevel);
            DRLGMAZE_PlaceAct5IceStuff(pLevel);
            break;
        }
        break;

    case 32:
        DRLGMAZE_InitBasicMazeLayout(pLevel, 2);
        DRLGMAZE_PlaceAct5TempleStuff(pLevel);
        break;

    case 34:
        DRLGMAZE_PlaceAct2TombPrev_Act5BaalPrev(pLevel);
        DRLGMAZE_BuildBasicMaze(pLevel);
        DRLGMAZE_PlaceAct5BaalStuff(pLevel);
        break;

    case 35:
        DRLGMAZE_PlaceAct5LavaPresets(pLevel);
        break;

    default:
        D2_ASSERT(0, 2179);
    }

    switch (pLevel->nLevelId)
    {
    case 28:
        DRLGMAZE_PlaceAct1Barracks(pLevel);
        break;

    case 107:
        DRLGMAZE_PlaceAct4Lava(pLevel);
        break;

    default:
        DRLG_UpdateRoomExCoordinates(pLevel);
        break;
    }

    DRLGMAZE_RollAct_1_2_3_BasicPresets(pLevel);
    DRLGMAZE_RollBasicPresets(pLevel);
}

#include "gen/data/Source/D2Common/00670E70_DRLGMAZE_AddAdjacentMazeRoom.inc"
