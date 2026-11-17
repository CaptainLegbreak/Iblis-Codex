struct D2ActiveRoomStrc;
struct D2DrlgActStrc;

#define LEVEL_ROGUEENCAMPMENT 1
#define LEVEL_STONYFIELD 4
#define LEVEL_TRISTRAM 38
#define LEVEL_MOOMOOFARM 39
#define LEVEL_CANYONOFTHEMAGI 46
#define LEVEL_DURIELSLAIR 73
#define LEVEL_ARCANESANCTUARY 74
#define LEVEL_HARROGATH 109
#define LEVEL_FRIGIDHIGHLANDS 111
#define LEVEL_ARREATPLATEAU 112
#define LEVEL_TUNDRAWASTELANDS 117
#define LEVEL_NIHLATHAKSTEMPLE 121
#define LEVEL_HELL1 125
#define LEVEL_HELL2 126
#define LEVEL_HELL3 127

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
    char unk0xAC[0x10];
    D2DrlgActStrc* pAct[5];
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2ObjectDataStrc
{
    char unk0x00[0x04];
    unsigned char InteractType;
};

struct D2UnitStrc
{
    char unk0x00[0x10];
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
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

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_GetHoradricStaffTombLevelId(D2DrlgActStrc* pAct);                                     // 0x0061AEB0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

static __forceinline unsigned __int64 ITEMS_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0054FDB0
void __fastcall OBJECTS_InitFunction58_Fissure(D2ObjInitFnStrc* pOp)
{
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pOp->pGame, pOp->pRoom);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 8, pOp->pGame->dwGameFrame + (unsigned int)ITEMS_RollRandomNumberForceInline(&pObjectControl->pSeed) % 250 + 25, 0, 0);
}

// 0x0054FE10
void __fastcall OBJECTS_InitFunction59_VileDogAfterglow(D2ObjInitFnStrc* pOp)
{
    if (pOp->pObject && pOp->pObject->dwAnimMode != 0)
    {
        return;
    }

    UNITS_ChangeAnimMode(pOp->pObject, 1);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 7, pOp->pGame->dwGameFrame + 27, 0, 0);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pOp->pObjectTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
}

// 0x0054FE70
void __fastcall OBJECTS_InitFunction12_PermanentPortal(D2ObjInitFnStrc* pOp)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);
    if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        UNITS_BlockCollisionPath(pOp->pObject, pOp->pRoom, pOp->nX, pOp->nY);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pOp->pObjectTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }

    const int nTombLevelId = DUNGEON_GetHoradricStaffTombLevelId(pOp->pGame->pAct[1]);
    switch (nLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        pOp->pObject->pObjectData->InteractType = LEVEL_MOOMOOFARM;
        return;

    case LEVEL_MOOMOOFARM:
        pOp->pObject->pObjectData->InteractType = LEVEL_ROGUEENCAMPMENT;
        return;

    case LEVEL_TRISTRAM:
        pOp->pObject->pObjectData->InteractType = LEVEL_STONYFIELD;
        return;

    case LEVEL_STONYFIELD:
        pOp->pObject->pObjectData->InteractType = LEVEL_TRISTRAM;
        return;

    case LEVEL_ARCANESANCTUARY:
        pOp->pObject->pObjectData->InteractType = LEVEL_CANYONOFTHEMAGI;
        return;

    case LEVEL_CANYONOFTHEMAGI:
        pOp->pObject->pObjectData->InteractType = LEVEL_ARCANESANCTUARY;
        return;

    case LEVEL_DURIELSLAIR:
        pOp->pObject->pObjectData->InteractType = nTombLevelId;
        return;

    case LEVEL_NIHLATHAKSTEMPLE:
        pOp->pObject->pObjectData->InteractType = LEVEL_HARROGATH;
        return;

    case LEVEL_HARROGATH:
        pOp->pObject->pObjectData->InteractType = LEVEL_NIHLATHAKSTEMPLE;
        return;

    case LEVEL_HELL1:
        pOp->pObject->pObjectData->InteractType = LEVEL_FRIGIDHIGHLANDS;
        return;

    case LEVEL_HELL2:
        pOp->pObject->pObjectData->InteractType = LEVEL_ARREATPLATEAU;
        return;

    case LEVEL_HELL3:
        pOp->pObject->pObjectData->InteractType = LEVEL_TUNDRAWASTELANDS;
        return;

    case LEVEL_FRIGIDHIGHLANDS:
        if (pOp->pObject->pObjectData->InteractType != LEVEL_HELL1)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_HELL1;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 11, pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        return;

    case LEVEL_ARREATPLATEAU:
        if (pOp->pObject->pObjectData->InteractType != LEVEL_HELL2)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_HELL2;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 11, pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        return;

    case LEVEL_TUNDRAWASTELANDS:
        if (pOp->pObject->pObjectData->InteractType != LEVEL_HELL3)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_HELL3;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 11, pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        return;

    default:
        if (nLevelId == nTombLevelId)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_DURIELSLAIR;
        }
        return;
    }
}
