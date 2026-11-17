struct D2ActiveRoomStrc
{
    char unk0x00[0x78];
    int nNumClients;
};

struct D2DynamicPathStrc;
struct D2DrlgActStrc;

struct D2ItemDataStrc
{
    char unk0x00[0x24];
    int dwActionStamp;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x8];
    int dwAnimMode;
    D2ItemDataStrc* pItemData;
    unsigned char nAct;
    char unk0x19[0x3];
    D2DrlgActStrc* pDrlgAct;
    char unk0x20[0xC];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x98];
    unsigned int dwFlagEx;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x9C];
    D2DrlgActStrc* pAct[5];
};

struct D2ObjectsTxt
{
    char unk0x00[0x120];
    unsigned char nHasCollision[8];
};

enum D2C_UnitTypes
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 17
#define IMODE_ONGROUND 3
#define COLLISION_PATTERN_SMALL_NO_PRESENCE 5
#define COLLIDE_CORPSE 0x8000
#define UNITFLAGEX_HASBEENDELETED 0x100

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                              // 0x006427F0
void __stdcall PATH_AllocDynamicPath(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag); // 0x00649D00
void __fastcall sub_00534AD0_ResetModeAndEvents(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY);      // 0x00534AD0
int __fastcall MONSTER_SetVelocityAndPosition(D2GameStrc* pGame, D2UnitStrc* pMonster, int nX, int nY, int a5); // 0x005735A0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00573780
void __fastcall sub_00553220(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00553220
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350
int __stdcall UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused);           // 0x0064C2C0
void __fastcall sub_00553060_AddToUnitList(D2UnitStrc* pUnit, D2GameStrc* pGame);                           // 0x00553060
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int a2);                                      // 0x00620FA0
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath);                       // 0x00648460
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce);                          // 0x00649560
void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode);                                      // 0x00649190
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00558A10

// 0x00553160
static int sub_00553160_RoomHasClients(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    return pRoom->nNumClients != 0;
}

// 0x00554850
void __fastcall SUNIT_Add(D2UnitStrc* pUnit, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bSkipRoomUpdate)
{
    D2_ASSERT(pGame, 0x3FF);
    D2_ASSERT(pUnit, 0x403);

    pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    pUnit->pDrlgAct = pGame->pAct[pUnit->nAct];

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        sub_00534AD0_ResetModeAndEvents(pGame, pUnit, nX, nY);
        break;

    case UNIT_MONSTER:
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        MONSTER_SetVelocityAndPosition(pGame, pUnit, nX, nY, bSkipRoomUpdate);
        if (sub_00553160_RoomHasClients(pUnit))
        {
            MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
        }
        else
        {
            sub_00553220(pGame, pUnit);
        }
        break;

    case UNIT_OBJECT:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        if (pObjectsTxtRecord->nHasCollision[pUnit->dwAnimMode])
        {
            UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        }

        D2_ASSERT(pRoom, 0x420);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;
    }
    case UNIT_ITEM:
        if (pUnit->dwAnimMode == IMODE_ONGROUND)
        {
            UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
            UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
            if (pRoom)
            {
                UNITROOM_AddUnitToRoomEx(pUnit, pRoom, 0);
            }
        }
        break;

    case UNIT_MISSILE:
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        break;

    case UNIT_TILE:
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        D2_ASSERT(pRoom, 0x442);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;

    default:
        D2_ASSERT(0, 0x447);
        break;
    }

    sub_00553060_AddToUnitList(pUnit, pGame);

    if (UNITS_GetRoom(pUnit))
    {
        UNITROOM_RefreshUnit(pUnit);
    }

    if (!bSkipRoomUpdate)
    {
        UNITS_SetCurrentRoomInvalid(pUnit, 1);
    }
}

// 0x00554A30
void __fastcall SUNIT_Restore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(pGame, 0x45C);
    D2_ASSERT(pUnit, 0x45D);

    pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    pUnit->pDrlgAct = pGame->pAct[pUnit->nAct];
    pUnit->dwFlagEx &= ~UNITFLAGEX_HASBEENDELETED;

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
        pUnit->pDynamicPath = 0;
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        sub_00534AD0_ResetModeAndEvents(pGame, pUnit, nX, nY);
        if (pUnit->dwAnimMode == PLRMODE_DEAD || pUnit->dwAnimMode == PLRMODE_DEATH)
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            sub_00649190_SetPathMode(pUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
            PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_CORPSE);
        }
        break;

    case UNIT_MONSTER:
        PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
        pUnit->pDynamicPath = 0;
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        MONSTER_SetVelocityAndPosition(pGame, pUnit, nX, nY, 0);
        if (sub_00553160_RoomHasClients(pUnit))
        {
            MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
        }
        else
        {
            sub_00553220(pGame, pUnit);
        }

        if (MONSTERS_IsDead(pUnit))
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            sub_00649190_SetPathMode(pUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
            PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_CORPSE);
        }
        break;

    case UNIT_OBJECT:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        if (pObjectsTxtRecord->nHasCollision[pUnit->dwAnimMode])
        {
            UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        }

        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;
    }
    case UNIT_ITEM:
        if (pUnit->dwAnimMode == IMODE_ONGROUND)
        {
            UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
            UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
            UNITROOM_AddUnitToRoom(pUnit, pRoom);
            pUnit->pItemData->dwActionStamp = ITEMS_GetGroundRemovalTime(pGame, pUnit);
        }
        break;

    case UNIT_MISSILE:
        PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
        pUnit->pDynamicPath = 0;
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        break;

    case UNIT_TILE:
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;

    default:
        D2_ASSERT(0, 0x4AA);
        break;
    }

    if (UNITS_GetRoom(pUnit))
    {
        UNITROOM_RefreshUnit(pUnit);
    }

    UNITS_SetCurrentRoomInvalid(pUnit, 1);
}
