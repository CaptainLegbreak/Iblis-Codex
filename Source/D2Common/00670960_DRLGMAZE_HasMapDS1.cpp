struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgOrthStrc
{
    void* pTarget;
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
    int unk0x08;
    unsigned int dwFlags;
};

struct D2LvlMazeTxt
{
    int dwLevelId;
    int dwRooms[3];
    int dwSizeX;
    int dwSizeY;
};

struct D2DrlgStrc
{
    char unk0x000[0x450];
    unsigned char nDifficulty;
};

struct D2DrlgRoomStrc;

struct D2DrlgLevelStrc
{
    char unk0x000[0x10];
    D2DrlgRoomStrc* pFirstRoomEx;
    D2LvlMazeTxt* pMaze;
    char unk0x018[0x19C];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x8];
    int nLevelType;
    char unk0x1C4[0xC];
    int nLevelId;
};

struct D2DrlgRoomStrc
{
    D2DrlgOrthStrc* pDrlgOrth;
    char unk0x04[0x1C];
    D2RoomPresetStrc* pMaze;
    D2DrlgRoomStrc* pDrlgRoomNext;
    char unk0x28[0xC];
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x44[0x14];
    D2DrlgLevelStrc* pLevel;
};

extern "C" const char gszEmptyAssertText;                                                     // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                        // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);     // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                 // 0x00681E09
D2LvlMazeTxt* __fastcall DATATBLS_GetLvlMazeTxtRecordFromLevelId(int nLevelId);                                               // 0x0061F490
void __fastcall DRLG_SetLevelPositionAndSize(D2DrlgStrc* pDrlg, D2DrlgLevelStrc* pLevel);                       // 0x00642D10
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType);                     // 0x0066B3E0
void __fastcall DRLGROOM_AllocDrlgOrthsForRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection);   // 0x0066B5E0
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pCoord1, D2DrlgCoordStrc* pCoord2, int nDistance);    // 0x0066B860
int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDistance);   // 0x0066B900
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom);                   // 0x0066B970
void __fastcall DRLGROOM_FreeRoomEx(D2DrlgRoomStrc* pDrlgRoom);                                           // 0x0066C100
extern const int gnMazeExpansionPresetRemap[16][2];                                                         // 0x006EF6D8
extern const int gnMazePresetRemap[16][3];                                                      // 0x006EF758

// @ref 0x00670810
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

// @ref 0x00670880
static int __stdcall sub_00670880(D2DrlgRoomStrc* pDrlgRoom, int nDirection, D2DrlgRoomStrc* pNewRoomEx)
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

// @ref 0x00670970
static D2DrlgRoomStrc* __stdcall DRLGMAZE_SetPickedFileAndPresetId(D2DrlgRoomStrc* pDrlgRoom, int nLevelPrest, int nPickedFile, int bResetFlag)
{
    D2RoomPresetStrc* pMaze = pDrlgRoom->pMaze;
    pMaze->nLevelPrest = nLevelPrest;
    pMaze->nPickedFile = nPickedFile;

    if (bResetFlag)
    {
        pMaze->dwFlags &= ~2;
    }
    else
    {
        pMaze->dwFlags |= 2;
    }

    return pDrlgRoom;
}

// @ref 0x006709B0
static D2DrlgRoomStrc* __stdcall DRLGMAZE_PickRoomPreset(D2DrlgRoomStrc* pDrlgRoom, int bResetFlag)
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

    switch (pDrlgRoom->pLevel->nLevelType)
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
        if (pDrlgRoom->pLevel->nLevelId == 52 && nLevelPrest == 361)
        {
            nPickedFile = 2;
        }

        if (pDrlgRoom->pLevel->nLevelId == 54 && (nLevelPrest == 361 || nLevelPrest == 359))
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
        if (pDrlgRoom->pLevel->nLevelId == 84 && nLevelPrest == 662)
        {
            nLevelPrest = 664;
        }

        if (pDrlgRoom->pLevel->nLevelId == 85 && nLevelPrest == 661)
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
        if (!sub_00670810(pDrlgRoom->pLevel))
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
        DRLGMAZE_SetPickedFileAndPresetId(pDrlgRoom, nLevelPrest, nPickedFile, bResetFlag);
    }

    return pDrlgRoom;
}

// 0x00670960
static int DRLGMAZE_HasMapDS1(D2DrlgRoomStrc* pDrlgRoom)
{
    return !((pDrlgRoom->pMaze->dwFlags >> 1) & 1);
}

// @ref 0x00672340
static int DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(int nDirection, D2DrlgRoomStrc* pDrlgRoom)
{
    if (!DRLGMAZE_HasMapDS1(pDrlgRoom))
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

    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->pLevel, 2);
    pNewRoomEx->pDrlgCoord.nWidth = pNewRoomEx->pLevel->pMaze->dwSizeX;
    pNewRoomEx->pDrlgCoord.nHeight = pNewRoomEx->pLevel->pMaze->dwSizeY;

    if (!sub_00670880(pDrlgRoom, nDirection, pNewRoomEx))
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
        pNewRoomEx = 0;
    }
    else
    {
        DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pNewRoomEx, nDirection);
        DRLGROOM_AddRoomExToLevel(pDrlgRoom->pLevel, pNewRoomEx);
        DRLGMAZE_PickRoomPreset(pNewRoomEx, 1);
    }

    const int bResult = pNewRoomEx != 0;
    if (pNewRoomEx)
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
    }

    return bResult;
}

// @ref 0x00672420
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomEast(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;

    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosX < pResult->pDrlgCoord.nPosX) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(0, pDrlgRoom))
        {
            pResult = pDrlgRoom;
        }
    }

    return pResult;
}

// @ref 0x00672460
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomWest(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;

    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosX > pResult->pDrlgCoord.nPosX) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(2, pDrlgRoom))
        {
            pResult = pDrlgRoom;
        }
    }

    return pResult;
}

// @ref 0x006724A0
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomNorth(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;

    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosY > pResult->pDrlgCoord.nPosY) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(3, pDrlgRoom))
        {
            pResult = pDrlgRoom;
        }
    }

    return pResult;
}

// @ref 0x00673B10
void __fastcall DRLGMAZE_InitLevelData(D2DrlgLevelStrc* pLevel)
{
    pLevel->pMaze = DATATBLS_GetLvlMazeTxtRecordFromLevelId(pLevel->nLevelId);
    DRLG_SetLevelPositionAndSize(pLevel->pDrlg, pLevel);
}
