extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2ShrinesTxt;
struct D2ObjectsTxt;

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

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    D2ObjectControlStrc* pObjectregion;
    D2ObjectsTxt* pObjectsTxt;
    int nX;
    int nY;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2LevelsTxt
{
    char unk0x00[0x10];
    short wMonLvl[3];
};

struct D2ObjectTableStrc
{
    int nObjectId;
    int nMin;
    int nMax;
};

#define UNIT_OBJECT 2
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPENED 2
#define OBJECT_FLIES 103
#define COLLIDE_MASK_PLACEMENT 0x3F11

extern const D2ObjectTableStrc gaShrineObjectTable_006E1080[6];                                             // 0x006E1080

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId);                                        // 0x006414B0
void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord);    // 0x00621BB0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800
D2UnitStrc* __fastcall sub_6FC4F640(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords);      // 0x00559300
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870

static __forceinline unsigned __int64 ITEMS_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0054F0D0
D2UnitStrc* __fastcall OBJECTS_SpawnShrine(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode)
{
    if (nClassId < 574 || nClassId > 579)
        return 0;

    const D2ObjectTableStrc* pObjectTableRecord = &gaShrineObjectTable_006E1080[nClassId - 574];
    D2_ASSERT(pRoom, 222);

    D2UnitStrc* pShrine = SUNIT_AllocUnitData(UNIT_OBJECT, pObjectTableRecord->nObjectId, nX, nY, pGame, pRoom, 1, nMode, 0);

    int nShrineId = ITEMS_RollLimitedRandomNumber(&pShrine->pSeed, pObjectTableRecord->nMax - pObjectTableRecord->nMin) + pObjectTableRecord->nMin;
    if (nShrineId == 5 || nShrineId == 4)
        nShrineId = 2;

    pShrine->pObjectData->InteractType = nShrineId;
    UNITS_SetShrineTxtRecordInObjectData(pShrine, DATATBLS_GetShrinesTxtRecord(nShrineId));
    return pShrine;
}

// 0x0054F8C0
void __fastcall OBJECTS_InitFunction28_GoldPlaceHolder(D2ObjInitFnStrc* pOp)
{
    if (pOp->pObject && pOp->pObject->dwAnimMode != OBJMODE_NEUTRAL)
        return;

    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    D2CoordStrc pCoord;
    pCoord.nX = pOp->nX;
    pCoord.nY = pOp->nY;

    const int nCounter = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 9 + 1;
    for (int i = 0; i < nCounter; ++i)
    {
        const int nOffsetX = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) & 3;
        const int nOffsetY = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) & 3;
        D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(pOp->pRoom, pCoord.nX + nOffsetX, pCoord.nY + nOffsetY);
        if (pRoom == pOp->pRoom)
        {
            pCoord.nX = pOp->nX + nOffsetX;
            pCoord.nY = pOp->nY + nOffsetY;
            if (!COLLISION_CheckMaskWithSizeXY(pRoom, pCoord.nX, pCoord.nY, 1, 1, COLLIDE_MASK_PLACEMENT))
                sub_6FC4F640(pOp->pGame, pOp->pRoom, &pCoord);
        }
    }
}

// 0x0054FBB0
void __fastcall OBJECTS_InitFunction02_Urn(D2ObjInitFnStrc* pOp)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
    unsigned char nInteractType = 0;
    const int nRoll = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 100;
    if (nRoll < (unsigned short)(pLevelsTxtRecord->wMonLvl[0] / 8 + 5))
        nInteractType = OBJECTS_RollRandomNumber(&pOp->pObjectregion->pSeed, 1, 9);

    pOp->pObject->pObjectData->InteractType = nInteractType;
}

// 0x0054FC50
void __fastcall OBJECTS_InitFunction27_GooPile(D2ObjInitFnStrc* pOp)
{
    unsigned char nInteractType = 0;
    const int nRoll = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 1000;
    if (nRoll < 333)
        nInteractType = 3;

    pOp->pObject->pObjectData->InteractType = nInteractType;
}

// 0x00551150
void __stdcall sub_00551150_SpawnFlies(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    if ((unsigned int)ITEMS_RollRandomNumberInline(&pObjectControl->pSeed) % 100 <= 70)
        return;

    D2CoordStrc tCoord;
    UNITS_GetCoords(pObject, &tCoord);
    D2_ASSERT(pRoom, 1946);
    SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FLIES, tCoord.nX, tCoord.nY, pGame, pRoom, 1, 0, 0);
}

#include "gen/data/Source/D2Game/0054F0D0_OBJECTS_SpawnShrine.inc"
