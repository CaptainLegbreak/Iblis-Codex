struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgRoomStrc;

struct D2DrlgLevelStrc
{
    char unk0x00[0x8];
    int nRooms;
    int unk0x0C;
    D2DrlgRoomStrc* pFirstRoomEx;
    char unk0x14[0x1A0];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgOrthStrc
{
    D2DrlgRoomStrc* pTarget;
    int nDirection;
    int bPreset;
    int bInit;
    void* pBox;
    D2DrlgOrthStrc* pNext;
};

struct D2PresetUnitStrc
{
    int unk0x00[3];
    D2PresetUnitStrc* pNext;
};

struct D2DrlgRoomStrc
{
    D2DrlgOrthStrc* pDrlgOrth;
    int unk0x04;
    D2DrlgRoomStrc** ppRoomsNear;
    char unk0x0C[0x18];
    D2DrlgRoomStrc* pDrlgRoomNext;
    unsigned int dwFlags;
    int nRoomsNear;
    char unk0x30[0x18];
    int nType;
    char unk0x4C[0xC];
    D2DrlgLevelStrc* pLevel;
    D2PresetUnitStrc* pPresetUnits;
};

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
void __fastcall DRLGPRESET_FreePresetRoomData(D2DrlgRoomStrc* pDrlgRoom);                                     // 0x006665B0
void __fastcall DRLGPRESET_FreePresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit);                   // 0x006675D0
void __fastcall DRLGROOM_FreeRoomTiles(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom);                      // 0x0066B4F0
void __fastcall DRLGROOM_FreeRoomData(void* pMemPool, D2DrlgOrthStrc* pDrlgOrth);                       // 0x0066B530
void __fastcall sub_0066B610(void* pMemPool, D2DrlgOrthStrc** ppDrlgOrth, D2DrlgRoomStrc* pDrlgRoom);   // 0x0066B610
void __fastcall DRLGLOGIC_FreeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom);                                      // 0x0066C6E0
void __fastcall DRLGROOMTILE_FreeTileGrid(D2DrlgRoomStrc* pDrlgRoom);                                       // 0x0066F0B0
void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoom(D2DrlgRoomStrc* pDrlgRoom);                                        // 0x0067D610

// 0x0066C100
void __fastcall DRLGROOM_FreeRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->pLevel->pDrlg->pMempool;

    DRLGROOM_FreeRoomTiles(pMemPool, pDrlgRoom);

    if (pDrlgRoom->ppRoomsNear)
    {
        sub_0040B480(pMemPool, pDrlgRoom->ppRoomsNear, ".\\DRLG\\DrlgRoom.cpp", 105, 0);
        pDrlgRoom->nRoomsNear = 0;
        pDrlgRoom->ppRoomsNear = 0;
    }

    switch (pDrlgRoom->nType)
    {
    case 1:
        DRLGOUTROOM_FreeDrlgOutdoorRoom(pDrlgRoom);
        break;

    case 2:
        DRLGPRESET_FreePresetRoomData(pDrlgRoom);
        break;
    }

    D2PresetUnitStrc* pPresetUnit = pDrlgRoom->pPresetUnits;
    while (pPresetUnit)
    {
        D2PresetUnitStrc* pFree = pPresetUnit;
        pPresetUnit = pPresetUnit->pNext;
        DRLGPRESET_FreePresetUnit(pMemPool, pFree);
    }

    D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth;
    while (pDrlgOrth)
    {
        D2DrlgOrthStrc* pCurrent = pDrlgOrth;
        pDrlgOrth = pDrlgOrth->pNext;
        if (pCurrent->bInit == 1)
        {
            D2DrlgRoomStrc* pTarget = pCurrent->pTarget;
            sub_0066B610(pMemPool, &pDrlgRoom->pDrlgOrth, pTarget);
            sub_0066B610(pMemPool, &pTarget->pDrlgOrth, pDrlgRoom);
        }
    }

    DRLGROOM_FreeRoomData(pMemPool, pDrlgRoom->pDrlgOrth);

    D2DrlgLevelStrc* pLevel = pDrlgRoom->pLevel;
    D2DrlgRoomStrc* pCurrentRoomEx = pLevel->pFirstRoomEx;
    if (pCurrentRoomEx == pDrlgRoom)
    {
        pLevel->pFirstRoomEx = pDrlgRoom->pDrlgRoomNext;
        --pLevel->nRooms;
    }
    else
    {
        while (pCurrentRoomEx->pDrlgRoomNext)
        {
            if (pCurrentRoomEx->pDrlgRoomNext == pDrlgRoom)
            {
                pCurrentRoomEx->pDrlgRoomNext = pDrlgRoom->pDrlgRoomNext;
                --pLevel->nRooms;
                break;
            }

            pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext;
        }
    }

    DRLGROOMTILE_FreeTileGrid(pDrlgRoom);
    DRLGLOGIC_FreeDrlgCoordList(pDrlgRoom);
    sub_0040B480(pMemPool, pDrlgRoom, ".\\DRLG\\DrlgRoom.cpp", 174, 0);
}
