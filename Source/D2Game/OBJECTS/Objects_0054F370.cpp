#include "D2Game.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define GAMEV (game)
struct D2SeedStrc;
struct D2ObjectControlStrc;
struct D2ObjectDataStrc;
struct D2DrlgCoordsStrc;
struct D2LevelsTxt;
struct D2ObjectPopulateStrc;
struct ObjectData;
struct InitContext;

struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned __int64 lSeed;
        };
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
    };
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2ObjectDataStrc
{
    char pad00[4];
    unsigned char nType;
};

struct D2UnitStrc
{
    char pad00[0x14];
    D2ObjectDataStrc* pObjectData;
    char pad18[0xAC];
    unsigned int dwFlags;
};

enum
{
    LEVEL_TOWERCELLARLEV5 = 25,
    LEVEL_MAGGOTLAIRLEV1 = 62,
    LEVEL_MAGGOTLAIRLEV3 = 64,
    OBJECT_COUNTESSCHEST = 0x173,
};

struct D2GameStrc
{
    char unk0x000[0xBC];
    D2DrlgActStrc* pAct[5];
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
D2UnitStrc* __fastcall sub_0054F180_SelectAndSpawnObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nUnused); // 0x0054F180
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest); // 0x005540A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSizeX, int nUnitSizeY, unsigned short nMask); // 0x0064D800
static __declspec(noinline) int __stdcall sub_005502F0_CanPlace(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY);

struct D2ObjectRegionStrc
{
    unsigned char nAct;
    char pad0x01[3];
    int field_4;
    int nPopulatedRooms;
    int unk0x0C;
    int nHealingShrines;
};

struct D2LevelsTxt
{
    char unk0x000[0xE5];
    unsigned char nObjGroup[8];
    unsigned char nObjPrb[8];
    char unk0x0F5[0x11B];
    unsigned int dwThemes;
};

struct D2ObjGroupTxt
{
    unsigned int dwId[8];
    unsigned char nDensity[8];
    unsigned char nProbability[8];
};



typedef int (__fastcall* OBJTHEMEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

typedef D2UnitStrc* (__fastcall* OBJECTPOPULATEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

struct D2ObjectPopulateStrc
{
    int bActive;
    OBJTHEMEFN pfPopulate;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2ObjectPopulateStrc gObjectThemeTable_00731E68[7]; // 0x00731E68
extern OBJECTPOPULATEFN sgPopulateTable[10]; // 0x00731D00
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

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

// build: context SEED_RollRandomNumber
inline unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x0054F370
D2UnitStrc* __fastcall sub_0054F370_SpawnChestObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nUnused)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    D2UnitStrc* pObject = sub_0054F180_SelectAndSpawnObject(pGame, pRoom, nLevelId == LEVEL_TOWERCELLARLEV5 ? OBJECT_COUNTESSCHEST : nClassId, nX, nY, nUnused);
    if (pObject)
    {
        if (nLevelId >= LEVEL_MAGGOTLAIRLEV1 && nLevelId <= LEVEL_MAGGOTLAIRLEV3
            && (int)((unsigned int)SEED_RollRandomNumber(&OBJRGN_GetObjectControlFromGame(pGame, pRoom)->pSeed) % 100) > 50)
        {
            pObject->dwFlags |= 0x80;
            UNITS_ChangeAnimMode(pObject, 0);
            return pObject;
        }

        D2GAME_SetSparkChest_6FCBD7C0(pObject, 1);
        if (nLevelId == LEVEL_TOWERCELLARLEV5)
        {
            pObject->pObjectData->nType = 3;
        }

        pObject->dwFlags |= 0x80;
        UNITS_ChangeAnimMode(pObject, 0);
    }

    return pObject;
}

// 0x005502F0
static int __stdcall sub_005502F0_CanPlace(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY)
{
    if (pDrlgCoords->nSubtileWidth < 2 || pDrlgCoords->nSubtileHeight < 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 2
        && (unsigned short)pCoord->nY > pDrlgCoords->nSubtileY + 2
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileWidth + pDrlgCoords->nSubtileX - nSizeX
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileHeight + pDrlgCoords->nSubtileY - nSizeY
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 2, nSizeY + 2, 0x3F11))
    {
        return 1;
    }
    return 0;
}

// calling-convention shim (not game code)
int __stdcall shim_3(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY)
{
    return sub_005502F0_CanPlace(pDrlgCoords, pCoord, pRoom, nSizeX, nSizeY);
}

static __forceinline unsigned int OBJPOP_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int OBJPOP_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
    {
        return OBJPOP_RollSeed_Inline(pSeed) % nMax;
    }

    return OBJPOP_RollSeed_Inline(pSeed) & (nMax - 1);
}

// 0x00552400
static int __stdcall sub_00552400_PopulateTheme(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned int nThemes, D2ObjectRegionStrc* pObjectRegion)
{
    if (pObjectRegion->nPopulatedRooms >= 10 * pObjectRegion->unk0x0C)
    {
        D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
        const int nRoll = OBJPOP_RollSeed_Inline(&pObjectControl->pSeed) % 100;

        int nProbability = 0;
        if (pObjectRegion->field_4 > pObjectRegion->nPopulatedRooms / 2)
        {
            nProbability = 5;
        }

        if (pObjectRegion->field_4 > pObjectRegion->nPopulatedRooms - pObjectRegion->nPopulatedRooms / 4)
        {
            nProbability += 5;
        }

        if (nRoll >= nProbability + 12)
        {
            return 0;
        }

        D2DrlgCoordsStrc drlgCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

        unsigned int nThemeBit = 1;
        int nIndices[7] = {};
        int nMax = 0;
        int nTheme = 1;
        int nCount = 7;
        do
        {
            if (nThemes & nThemeBit)
            {
                nIndices[nMax] = nTheme;
                ++nMax;
            }
            nThemeBit += nThemeBit;
            ++nTheme;
        }
        while (--nCount);

        const int nIndex = OBJPOP_RollLimited_Inline(&pObjectControl->pSeed, nMax);
        const int nThemeId = nIndices[nIndex];
        if (nIndex < nMax && nThemeId < nMax && gObjectThemeTable_00731E68[nThemeId].bActive && gObjectThemeTable_00731E68[nThemeId].pfPopulate)
        {
            return gObjectThemeTable_00731E68[nThemeId].pfPopulate(pGame, pRoom, &drlgCoords);
        }

        return 0;
    }

    return 0;
}

// 0x00552560
static int __stdcall sub_00552560_CanPopulateRoom(D2GameStrc* pGame, D2LevelsTxt* pLevelsTxtRecord, D2ActiveRoomStrc* pRoom)
{
    if (DUNGEON_HasWaypoint(pRoom))
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    D2ObjectRegionStrc* pObjectRegion = OBJRGN_GetObjectRegionForLevel(pGame, nLevelId);
    if (!nLevelId)
    {
        return 0;
    }

    if (D2Common_10087(pRoom))
    {
        return 0;
    }

    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    if (pObjectRegion->nPopulatedRooms == 0x7FFFFFFF)
    {
        pObjectRegion->nPopulatedRooms = DUNGEON_GetNumberOfPopulatedRoomsInLevel(pGame->pAct[pObjectRegion->nAct], nLevelId);
    }

    pObjectRegion->field_4 += 1;

    if (pLevelsTxtRecord->dwThemes)
    {
        if (sub_00552400_PopulateTheme(pGame, pRoom, pLevelsTxtRecord->dwThemes, pObjectRegion) == 1)
        {
            return 0;
        }
    }

    return 1;
}

void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord, 0xBEC);

    if (!sub_00552560_CanPopulateRoom(pGame, pLevelsTxtRecord, pRoom))
    {
        return;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    for (int i = 0; i < 8; ++i)
    {
        const int nObjGroup = pLevelsTxtRecord->nObjGroup[i];
        int nProbability = OBJPOP_RollSeed_Inline(pSeed) % 100;

        D2ObjectRegionStrc* pObjectRegion = OBJRGN_GetObjectRegionForLevel(pGame, DUNGEON_GetLevelIdFromPopulatedRoom(pRoom));
        if (pObjectRegion->nPopulatedRooms > 0 && (pObjectRegion->field_4 << 7) / pObjectRegion->nPopulatedRooms > 96 && !pObjectRegion->nHealingShrines
            && DATATBLS_GetObjectsTxtRecord(nObjGroup)->nSubClass)
        {
            nProbability = 100;
        }

        if (nObjGroup && nProbability <= pLevelsTxtRecord->nObjPrb[i])
        {
            D2ObjGroupTxt* pObjGroupTxtRecord = DATATBLS_GetObjGroupTxtRecord(nObjGroup);
            if (!pObjGroupTxtRecord)
            {
                return;
            }

            const int nRoll = OBJPOP_RollSeed_Inline(pSeed) % 100;
            int nAccumulatedProbability = 0;
            for (int j = 0; j < 8; ++j)
            {
                const unsigned int nObjectId = pObjGroupTxtRecord->dwId[j];
                if (!nObjectId)
                {
                    break;
                }

                nAccumulatedProbability += pObjGroupTxtRecord->nProbability[j];
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
                if (nRoll < nAccumulatedProbability && pObjectsTxtRecord->nGore <= gnObjectGoreLevel_00731BBC)
                {
                    D2_ASSERT(pObjectsTxtRecord->nPopulateFn < 10, 0xC43);
                    if (sgPopulateTable[pObjectsTxtRecord->nPopulateFn])
                    {
                        D2_ASSERT(!IsBadCodePtr((FARPROC)sgPopulateTable[pObjectsTxtRecord->nPopulateFn]), 0xC46);
                        const unsigned char nDensity = pObjGroupTxtRecord->nDensity[j];
                        D2_ASSERT(nDensity < 128, 0xC47);
                        sgPopulateTable[pObjectsTxtRecord->nPopulateFn](pGame, pRoom, nDensity, nObjectId, 100);
                    }
                    break;
                }
            }
        }
    }
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

static inline int UNITS_GetAnimMode(Unit* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->mode;
}

// 0x00552B50
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
        Unit* object = sub_00550A30_Spawn(GAMEV,classId,sizeX,sizeY,room,record->placement,region,sub_00547430_Permit);
        if (object)
        {
            if (record->collisions[UNITS_GetAnimMode(object)])
                object->flags |= N2;
            else
                object->flags &= ~N2;
            if (object->data->interact != N2)
            {
                if (forced)
                {
                    sub_00552AC0_Class(object);
                    sub_0054F770_Select(game,N1,room,N2);
                    object->data->interact = N2;
                    sub_00621BB0_SetShrine(object,sub_006414B0_ShrineRecord(N2));
                    sub_00547390_Increment(game,region);
                }
            }
            else
                sub_00547390_Increment(GAMEV,region);
            sub_00547490_Add(GAMEV,region,CoordinateX(object),CoordinateY(object));
            return object;
        }
        --retries;
    }
    return N0;
}
