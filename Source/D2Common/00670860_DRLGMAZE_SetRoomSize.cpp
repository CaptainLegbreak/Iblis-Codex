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

static int DRLGMAZE_HasMapDS1(D2DrlgRoomStrc* pDrlgRoom)
{
    return !((pDrlgRoom->pMaze->dwFlags >> 1) & 1);
}

static D2DrlgRoomStrc* DRLGMAZE_SetPickedFileAndPresetId(D2DrlgRoomStrc* pDrlgRoom, int nLevelPrest, int nPickedFile, int bResetFlag)
{
    D2RoomPresetStrc* pMaze = pDrlgRoom->pMaze;
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
    D2LvlMazeTxt* pMaze = pDrlgRoom->pLevel->pMaze;
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
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
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
    return DRLGMAZE_ReplaceRoomPreset(pDrlgRoom->pLevel, nFile, 0x2C5, -1, 0);
}
