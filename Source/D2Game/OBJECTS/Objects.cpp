#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_OBJECT 2
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPENED 2
#define OBJECT_FLIES 103
#define LEVEL_ROGUEENCAMPMENT 1
#define EVENTTYPE_MODECHANGE 0
#define EVENTTYPE_STATREGEN 3
#define OBJMODE_OPERATING 1
#define OBJECTS_CONSTANT_00552AB0 2
#define UNIT_LIST_SIZE 128
#define WELL_PARAM 2
struct D2TimerArg2Strc;
struct D2MonStatsTxt;
struct D2SeedStrc;
struct D2ObjectDataStrc;
struct D2ObjectControlStrc;
struct D2ObjInitFnStrc;
struct D2LevelsTxt;
struct D2ObjectTableStrc;
struct ObjectData;
struct InitContext;
struct D2LvlWarpTxt;
struct D2PlayerDataStrc;
struct D2WarpDelayStrc;
struct D2WarpEventArgStrc;
struct R0052E0F0;
struct R00601DC0;

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    short nNextInClass;
    char unk0x006[0x1A2];
};


struct D2TimerArg2Strc
{
    union
    {
        int nUnitGUID;
        int unk0x00;
    };
    D2TimerArg2Strc* pNext;
};

struct D2TimerArgStrc
{
    D2TimerArg2Strc* unk0x00;
    unsigned int dwUnitId;
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    unsigned char InteractType;
    unsigned char unk_05[0x3];
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
    D2ObjectsTxt* pObjectTxt;
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

extern const D2ObjectTableStrc gaShrineObjectTable_006E1080[6]; // 0x006E1080
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord); // 0x00621BB0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800
D2UnitStrc* __fastcall sub_6FC4F640(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords); // 0x00559300
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
unsigned char __stdcall DRLG_GetActNoFromLevelId(int); // 0x006427F0
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc*, unsigned char); // 0x005540A0
int __fastcall ACT2Q6_GetObjectIdForArcaneThing(D2GameStrc* pGame); // 0x0059D830
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

struct Seed
{
    U32 lo;
    U32 hi;
};

struct Unit
{
    int type;
    int classId;
    void* pool;
    int id;
    int mode;
    ObjectData* data;
    char reserved24[N20];
    Path* path;
    char reserved48[N148];
    U32 flags;
};

struct Room
{
    char reserved0[N108];
    Seed seed;
};

struct InitContext
{
    Game* game;
    Unit* object;
    Room* room;
    Seed* control;
    ObjectRecord* record;
    int x;
    int y;
};

Unit* __stdcall sub_00550A30_Spawn(Game*,int,int,int,Room*,int,int,Permit); // 0x00550A30
U32 __stdcall sub_0061A1B0_Level(Room*); // 0x0061A1B0

struct D2ObjectsTxt
{
    char unk0x000[0x13F];
    unsigned char nMode[8];
    char unk0x147[0x2A];
    unsigned char nLockable;
    unsigned char unk_172[0x6];
    unsigned int dwParm[8];
    char unk0x198[0x1B];
    unsigned char nOperateFn;
};

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __fastcall OBJECTS_InitFunction02_Urn(D2ObjInitFnStrc* pOp); // 0x0054FBB0

struct D2LvlWarpTxt
{
    char unk0x00[0x14];
    int dwExitWalkX;
    int dwExitWalkY;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x04];
    unsigned char nTownLevelId;
};

struct D2WarpDelayStrc
{
    char unk0x00[0xDC];
    unsigned int dwWarpDelay;
};

struct D2WarpEventArgStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    D2ActiveRoomStrc* pRoom;
    int unk0x0C;
    D2WarpDelayStrc* pDelay;
    int nX;
    int nY;
};

extern "C" const char szSUnitCppFile_006E10F8[]; // 0x006E10F8
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0
int __fastcall QUESTS_LevelWarpCheck(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSourceLevel, int nDestinationLevel); // 0x00545B80
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nMode, int nX, int nY, int a7); // 0x005809D0
D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc* pRoom, int nSourceLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord); // 0x006195A0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

struct R0052E0F0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_0052E0F0_IsOpen();
};

struct R00601DC0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_00601DC0_IsOpen();
};
void __stdcall sub_M127_EmitSink(D2UnitStrc* pUnit);
void __fastcall sub_0054F580(D2GameStrc* pGame, D2TimerArgStrc* pTimerArg); // 0x0054F580
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x0054DA60
int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nNoInChain)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return -1;
    }

    int nClassId = pMonStatsTxtRecord->nBaseId;
    for (int i = 0; i < nNoInChain; ++i)
    {
        nClassId = pMonStatsTxtRecord->nNextInClass;
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord)
        {
            break;
        }
    }

    return nClassId;
}

// 0x0054F520
D2TimerArgStrc* __fastcall sub_0054F520_AllocTimerArg(D2GameStrc* pGame)
{
    D2TimerArgStrc* pTimerArg = (D2TimerArgStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TimerArgStrc), ".\\OBJECTS\\Objects.cpp", 0x1B8, 0);
    memset(pTimerArg, 0, sizeof(D2TimerArgStrc));
    pTimerArg->dwUnitId = -1;

    D2TimerArg2Strc* pArg = (D2TimerArg2Strc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TimerArg2Strc), ".\\OBJECTS\\Objects.cpp", 0x1BC, 0);
    pArg->nUnitGUID = -1;
    pArg->pNext = 0;
    pTimerArg->unk0x00 = pArg;
    return pTimerArg;
}

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
D2UnitStrc* __fastcall OBJECTS_SpawnShrine(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nClassId, int nX, int nY, int nMode)
{
    if (nClassId < 574 || nClassId > 579)
        return 0;

    const D2ObjectTableStrc* pObjectTableRecord = &gaShrineObjectTable_006E1080[nClassId - 574];
    D2_ASSERT(hRoom, 222);

    D2UnitStrc* pShrine = SUNIT_AllocUnitData(UNIT_OBJECT, pObjectTableRecord->nObjectId, nX, nY, pGame, hRoom, 1, nMode, 0);

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
    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(pObject);
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    if ((unsigned int)ITEMS_RollRandomNumberInline(&pObjectControl->pSeed) % 100 <= 70)
        return;

    D2CoordStrc tCoord;
    UNITS_GetCoords(pObject, &tCoord);
    D2_ASSERT(hRoom, 1946);
    SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FLIES, tCoord.nX, tCoord.nY, pGame, hRoom, 1, 0, 0);
}

#include "gen/data/Source/D2Game/OBJECTS/Objects.inc"

inline unsigned __int64 RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return nSeed;
}

// 0x0054F180
__declspec(noinline) D2UnitStrc* __fastcall sub_0054F180_SelectAndSpawnObject(
    D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nClassId, int nX, int nY, int nUnused)
{
    unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(hRoom));
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    int nLevel = DUNGEON_GetLevelIdFromRoom(hRoom);
    int nObject;
    switch (nAct)
    {
    case 1:
        if (nLevel == 0x4A)
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 3;
            int nChoices[] = { 0x183, 0x185, 0x186, 0x187 };
            nObject = nChoices[nIndex];
        }
        else
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 1;
            int nChoices[] = { 0x57, 0x58 };
            nObject = nChoices[nIndex];
        }
        break;
    case 2:
        if (nLevel == 0x53)
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 3;
            int nChoices[] = { 0x149, 0x14A, 0x14B, 0x14C };
            nObject = nChoices[nIndex];
        }
        else
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 1;
            int nChoices[] = { 0xB5, 0xB7 };
            nObject = nChoices[nIndex];
        }
        break;
    default:
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) % 13;
            int nChoices[] = { 5, 6, 0x8B, 0x8C, 0x8D, 0x90, 0xB0, 0xB1, 0xC6, 0xF0, 0xF1, 0xF2, 0xF3 };
            nObject = nChoices[nIndex];
        }
        break;
    }
    if (nClassId == 0x173)
        nObject = 0x173;
    D2_ASSERT(hRoom, 0x157);
    return SUNIT_AllocUnitData(2, nObject, nX, nY, pGame, hRoom, 1, 0, 0);
}

// 0x0054F430
D2UnitStrc* __fastcall OBJECTS_SpawnArcaneSymbol(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nClassId, int nX, int nY, int nMode)
{
    const int nObjectId = ACT2Q6_GetObjectIdForArcaneThing(pGame);

    D2_ASSERT(hRoom, 391);

    return SUNIT_AllocUnitData(UNIT_OBJECT, nObjectId, nX, nY, pGame, hRoom, 1, 0, 0);
}

// 0x0054F580
void __fastcall sub_0054F580(D2GameStrc* pGame, D2TimerArgStrc* pTimerArg)
{
    D2TimerArg2Strc* pArg = pTimerArg->unk0x00;
    while (pArg)
    {
        D2TimerArg2Strc* pNext = pArg->pNext;
        FOG_FreePool(pGame->pMemoryPool, pArg, ".\\OBJECTS\\Objects.cpp", 462, 0);
        pArg = pNext;
    }

    FOG_FreePool(pGame->pMemoryPool, pTimerArg, ".\\OBJECTS\\Objects.cpp", 465, 0);
}

static __forceinline U32 Roll(Seed* seed)
{
    unsigned __int64 value = (unsigned __int64)seed->hi + (unsigned __int64)seed->lo * NRNG;
    seed->hi = (U32)(value >> N32);
    seed->lo = (U32)value;
    return (U32)value;
}

static __forceinline U32 Limited(Seed* seed,int maximum)
{
    if (maximum <= N0)
        return N0;
    if (maximum & (maximum - N1))
        return Roll(seed) % maximum;
    return Roll(seed) & (maximum - N1);
}

// 0x0054F770
static __declspec(noinline) int __stdcall sub_0054F770_Select(Game* game,U32 level,Room* room,unsigned char category)
{
    if (!category || category > N4)
        category = N2;
    ShrineLists* lists = sub_00546FB0_Lists(game);
    if (lists->counts[category])
    {
        int retries = N8;
        int choice;
        do
        {
            int count = lists->counts[category];
            Seed* seed = sub_00546FA0_Control(game,room);
            U32 index = Limited(seed,count);
            choice = lists->lists[category][index];
            if (!choice)
                choice = N1;
            if (level >= sub_006414B0_ShrineRecord(choice)->minimumLevel)
                break;
            --retries;
        } while (retries > N0);
        return choice;
    }
    sub_00408A60(&gszEmptyAssertText,sub_00408090(),N716);
    exit(NNEG1);
}

// 0x0054F9D0
void __fastcall sub_0054F9D0_Initialize(InitContext* context)
{
    int mode = context->record->selection;
    U32 level = sub_0061A1B0_Level(context->room);
    int choice;
    if (mode)
    {
        int category;
        switch (mode)
        {
        case N1: category = N2; break;
        case N2: category = N3; break;
        default:
            category = N4;
            if (!(Roll(context->control) % N10))
                category = N1;
            break;
        }
        choice = sub_0054F770_Select(context->game,level,context->room,(unsigned char)category);
    }
    else
    {
        int retries = N8;
        const U32 randomLevel = sub_0061A1B0_Level(context->room);
        do
        {
            int count = sub_00641500_ShrineCount() - N1;
            choice = Limited(context->control,count) + N1;
            if (randomLevel >= sub_006414B0_ShrineRecord(choice)->minimumLevel)
                break;
            --retries;
        } while (retries > N0);
    }
    if (choice == N5)
        choice = N3;
    else if (choice == N4)
        choice = N2;
    else if (choice == N16)
        choice = N18;
    context->object->data->interact = (unsigned char)choice;
    sub_00621BB0_SetShrine(context->object,sub_006414B0_ShrineRecord(choice));
}

// 0x00552AC0
static __declspec(noinline) void __cdecl sub_00552AC0_Class(Unit* unit)
{
    int id;
    if (!unit)
        id = NNEG1;
    else
        id = unit->classId;
    int replacement = sub_00640E90_ObjectRecord(id)->subclass;
    int classId = N84;
    if (replacement && replacement < N573)
        classId = replacement;
    unit->classId = classId;
}

static __forceinline int CoordinateX(Unit* object)
{
    if (object->type == N2 || (object->type > N3 && object->type <= N5))
        return object->path->x;
    if (object->path)
        return sub_006488C0_PathX(object->path);
    return N0;
}

static __forceinline int CoordinateY(Unit* object)
{
    if (object->type == N2 || (object->type > N3 && object->type <= N5))
        return object->path->y;
    if (object->path)
        return sub_00648900_PathY(object->path);
    return N0;
}

Unit* __fastcall sub_00552B50_Create(Game* game,Room* room,int unusedGroup,int classId,unsigned short probability)
{
    ObjectRecord* record = sub_00640E90_ObjectRecord(classId);
    int sizeX = record->sizeX;
    int sizeY = record->sizeY;
    RoomBounds bounds;
    sub_00619730_Bounds(room,&bounds);
    int region = sub_0061A1F0_Region(room);
    Seed* seed = room ? &room->seed : N0;
    U32 roll = Roll(seed);
    unsigned char forced = N0;
    int retries = N3;
    if (sub_00547330_Force(game,region))
    {
        forced = N1;
        retries = N30;
    }
    else if (roll % N100 > probability)
        return N0;
    if (sub_00547360_Limit(game,region))
        return N0;
    while (retries > N0)
    {
        Unit* object = sub_00550A30_Spawn(game,classId,sizeX,sizeY,room,record->placement,region,sub_00547430_Permit);
        if (object)
        {
            if (record->collisions[object->mode])
                object->flags |= N2;
            else
                object->flags &= ~N2;
            if (object->data->interact == N2)
                sub_00547390_Increment(game,region);
            else if (forced)
            {
                sub_00552AC0_Class(object);
                sub_0054F770_Select(game,N1,room,N2);
                object->data->interact = N2;
                sub_00621BB0_SetShrine(object,sub_006414B0_ShrineRecord(N2));
                sub_00547390_Increment(game,region);
            }
            sub_00547490_Add(game,region,CoordinateX(object),CoordinateY(object));
            return object;
        }
        --retries;
    }
    return N0;
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

// 0x0054FB30
void __stdcall sub_0054FB30_Nop()
{
}

// 0x0060AB70
void __stdcall sub_0060AB70_Nop()
{
}

// 0x0060AC50
void __stdcall sub_0060AC50_Nop()
{
}

// 0x005500C0
void __fastcall OBJECTS_InitFunction08_Torch(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
}

// 0x005500D0
void __fastcall OBJECTS_InitFunction14_Brazier(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
}

// 0x005500E0
void __fastcall sub_005500E0(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
}

// 0x00552AB0
unsigned char __fastcall sub_00552AB0()
{
    return OBJECTS_CONSTANT_00552AB0;
}

// 0x00552AF0
void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* pPortal, int nUnitId)
{
    D2TimerArgStrc* pTimerArg = UNITS_GetTimerArg(pPortal);
    if (pTimerArg)
    {
        pTimerArg->dwUnitId = nUnitId;
    }
}

// 0x00552B10
int __fastcall OBJECTS_GetUnitIdFromTimerArg(D2UnitStrc* pUnit)
{
    D2TimerArgStrc* pTimerArg = UNITS_GetTimerArg(pUnit);
    if (pTimerArg)
    {
        return pTimerArg->dwUnitId;
    }

    return -1;
}

static __forceinline int sub_E03_GetAnimMode(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwAnimMode : 0;
}

// 0x00550140
void __fastcall sub_00550140_WarpEventCallback(D2WarpEventArgStrc* pArgs)
{
    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pArgs->pRoom));
    const int eLevelId = DUNGEON_GetTownLevelIdFromActNo(nAct);
    D2_ASSERT(eLevelId <= 0xFF, 0x46F);

    pArgs->pUnit->pPlayerData->nTownLevelId = eLevelId;

    if (sub_E03_GetAnimMode(pArgs->pUnit) == 1)
    {
        UNITS_BlockCollisionPath(pArgs->pUnit, pArgs->pRoom, pArgs->nX, pArgs->nY);
        EVENT_SetEvent(pArgs->pGame, pArgs->pUnit, 1, pArgs->pGame->dwGameFrame + (pArgs->pDelay->dwWarpDelay >> 8) + 1, 0, 0);
    }
}

// 0x00436E90
int __stdcall sub_00436E90_AlwaysOne(int nArg)
{
    return 1;
}

// 0x004C6020
int __stdcall sub_004C6020_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00551FF0
int __stdcall sub_00551FF0_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00643880
int __stdcall sub_00643880_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646260
int __stdcall sub_00646260_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646270
int __stdcall sub_00646270_AlwaysOne(int nArg)
{
    return 1;
}

// 0x006436E0
int __fastcall sub_006436E0_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x0064B700
int __fastcall sub_0064B700_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x006436F0
int __fastcall sub_006436F0_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x0064B710
int __fastcall sub_0064B710_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x00648390
int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x004C5390
void __fastcall sub_004C5390_EnlargeVector(int* pX, int* pY)
{
    int nDistance = *pX * *pX + *pY * *pY;
    if (nDistance < 4)
    {
        *pX <<= 2;
        *pY <<= 2;
        nDistance = *pX * *pX + *pY * *pY;
    }

    if (nDistance < 16)
    {
        *pX <<= 1;
        *pY <<= 1;
    }
}

// 0x0052E0F0
bool R0052E0F0::sub_0052E0F0_IsOpen()
{
    return m_pFile != 0;
}

// 0x00601DC0
bool R00601DC0::sub_00601DC0_IsOpen()
{
    return m_pFile != 0;
}

// 0x00552830
void __fastcall sub_00552830_SetObjectPopulateDensity(unsigned char nDensity)
{
    gnObjectPopulateDensity_00731BBD = nDensity;
}

// 0x00552D80
void __fastcall sub_00552D80_SetListNext(D2UnitStrc* pUnit, D2UnitStrc* pNext)
{
    D2_ASSERT(pUnit, 211);
    pUnit->pListNext = pNext;
}

// 0x00552DE0
static __forceinline void sub_00552DE0_SetFlag2AndField(D2UnitStrc* pUnit, int nValue)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
        pUnit->dwUnitId = nValue;
    }
}

void __fastcall sub_M127_Emit_00552DE0(D2UnitStrc* pUnit, int nValue)
{
    sub_00552DE0_SetFlag2AndField(pUnit, nValue);
    sub_M127_EmitSink(pUnit);
}

// 0x00552A00
void __fastcall OBJECTS_FreeHoverMessage(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && pObject->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pObject->pHoverText);
    }

    sub_0054F580(pGame, UNITS_GetTimerArg(pObject));
    sub_6FC349F0(pGame, pObject);
}

// 0x00552A40
void __fastcall OBJECTS_RemoveAll(D2GameStrc* pGame)
{
    for (int i = 0; i < UNIT_LIST_SIZE; ++i)
    {
        D2UnitStrc* pObject = pGame->pUnitList[UNIT_OBJECT][i];
        while (pObject)
        {
            D2UnitStrc* pCurrent = pObject;
            pObject = SUNIT_GetNextUnitFromList(pObject);
            SUNIT_RemoveUnit(pGame, pCurrent);
        }
    }
}

// 0x00552B30
void __fastcall OBJECTS_InitFunction16_Well(D2ObjInitFnStrc* pOp)
{
    pOp->pObject->pObjectData->InteractType = 2 * (unsigned char)pOp->pObjectTxt->dwParm[WELL_PARAM];
}

// 0x00552AA0
unsigned char __fastcall sub_00552AA0_GetRegenerateMax(D2ObjectsTxt* pObjectsTxtRecord)
{
    return 2 * pObjectsTxtRecord->dwParm[2];
}
