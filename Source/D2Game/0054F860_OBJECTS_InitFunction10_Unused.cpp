struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectDataStrc
{
    char unk0x00[0x04];
    unsigned char InteractType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2ObjectsTxt
{
    char unk0x000[0x13F];
    unsigned char nMode[8];
    char unk0x147[0x2A];
    unsigned char nLockable;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    D2ObjectControlStrc* pObjectregion;
    D2ObjectsTxt* pObjectTxt;
    int nX;
    int nY;
};

struct D2LevelsTxt
{
    char unk0x00[0x10];
    short wMonLvl[3];
};

#define LEVEL_ROGUEENCAMPMENT 1
#define OBJMODE_OPENED 2
#define EVENTTYPE_MODECHANGE 0
#define EVENTTYPE_STATREGEN 3
#define EVENTTYPE_PERIODICSKILLS 8

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest);                // 0x005540A0
void __fastcall OBJECTS_InitFunction02_Urn(D2ObjInitFnStrc* pOp);                                           // 0x0054FBB0

static __forceinline unsigned __int64 ITEMS_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0054F860
void __fastcall OBJECTS_InitFunction10_Unused(D2ObjInitFnStrc* pOp)
{
    if (DUNGEON_GetLevelIdFromRoom(pOp->pRoom) == LEVEL_ROGUEENCAMPMENT)
    {
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_PERIODICSKILLS, pOp->pGame->dwGameFrame + 60, 0, 0);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_MODECHANGE, pOp->pGame->dwGameFrame + 25, 0, 0);
    }
}

// 0x0054FB40
void __fastcall OBJECTS_InitFunction22_Fire(D2ObjInitFnStrc* pOp)
{
    if (pOp->pObjectTxt->nMode[2])
    {
        if (!pOp->pObject || !pOp->pObject->dwAnimMode)
        {
            if (!pOp->pObjectTxt->nMode[0])
            {
                UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
            }
        }
    }

    EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_MODECHANGE, pOp->pGame->dwGameFrame + 25, 0, 0);
}

// 0x0054FB90
void __fastcall OBJECTS_InitFunction24_SpikeFloorTrap(D2ObjInitFnStrc* pOp)
{
    EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_STATREGEN, pOp->pGame->dwGameFrame + 25, 0, 0);
}

// 0x0054FCB0
void __fastcall OBJECTS_InitFunction03_Chest(D2ObjInitFnStrc* pOp)
{
    OBJECTS_InitFunction02_Urn(pOp);
    unsigned char nInteractType = pOp->pObject->pObjectData->InteractType;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
    if (pOp->pObjectTxt->nLockable)
    {
        const int nRoll = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 100;
        if (nRoll < pLevelsTxtRecord->wMonLvl[0] / 2 + 8)
            nInteractType |= 0x80;
        else
            nInteractType &= 0x7F;
    }
    else
    {
        nInteractType &= 0x7F;
    }
    SEED_InitLowSeed(&pOp->pObject->pSeed, (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 65534 + 1);
    pOp->pObject->pObjectData->InteractType = nInteractType;
}

// 0x0054FD90
void __fastcall OBJECTS_InitFunction57_SparklyChest(D2ObjInitFnStrc* pOp)
{
    OBJECTS_InitFunction03_Chest(pOp);
    D2GAME_SetSparkChest_6FCBD7C0(pOp->pObject, 1);
}
