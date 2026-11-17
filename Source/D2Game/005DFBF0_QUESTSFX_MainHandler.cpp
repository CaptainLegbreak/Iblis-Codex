extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define MAX(a, b) ((a) < (b) ? (b) : (a))
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

enum D2C_M96QuestsFxConstants
{
    UNIT_MONSTER = 1,
    MONSTER_DIABLOCLONE = 333,
    MISSILE_RADAMENTDEATH = 347,
    EVENTTYPE_MONUMOD = 7,
    MONUMOD_TEMPSUMMON = 21,
};

struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc { char unk0x00[0x0C]; int nX; int nY; };
struct D2GameStrc { char unk0x00[0x1C]; void* pMemoryPool; char unk0x20[0xA8 - 0x20]; unsigned int dwGameFrame; };
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x20 - 0x08];
    D2SeedStrc pSeed;
    char unk0x28[4];
    union { D2DynamicPathStrc* pDynamicPath; D2StaticPathStrc* pStaticPath; };
};
struct D2UnitFindArgStrc
{
    int nFlags; int unk0x04; D2UnitStrc* pUnit; int nX; int nY; int nSize; int nMaxArrayEntries; int nIndex;
    void* pField; void* pfnUnitTest; int unk0x28; int unk0x2C; int unk0x30; int unk0x34;
};
struct D2UnitFindDataStrc
{
    void* pMemPool; D2UnitStrc** pUnitsArray; D2ActiveRoomStrc* pRoom; void* pfnUnitTest; D2UnitFindArgStrc* pUnitFindArg;
    int nFlags; int nIndex; int nMaxArrayEntries; int nX; int nY; int nSize;
};
struct D2MissilesTxt { char unk0x00[0x96]; short wRange; char unk0x98[0x1A4 - 0x98]; };
struct D2DataTablesStrc { char unk0x00[0xB64]; D2MissilesTxt* pMissilesTxt; char unk0xB68[4]; int nMissilesTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData);          // 0x0065AC70
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData);                               // 0x0065AA00
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                      // 0x0063E990
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

static void __stdcall QUESTSFX_MainHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nDelayMin, int nDelayMax, int bCheckIfUndead);

void __fastcall QUESTSFX_Bloodraven(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return QUESTSFX_MainHandler(pGame, pUnit, 35, 25, 125, 1);
}

// 0x005DFBF0
static void __stdcall QUESTSFX_MainHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nDelayMin, int nDelayMax, int bCheckIfUndead)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2_ASSERT(nDelayMax, 32);
    D2_ASSERT(nDelayMax > nDelayMin, 33);

    D2UnitFindArgStrc unitFindArg;
    memset(&unitFindArg, 0, sizeof(unitFindArg));
    unitFindArg.nX = nX;
    unitFindArg.nSize = nSize;
    unitFindArg.nFlags = 0x583;
    unitFindArg.pUnit = pUnit;
    unitFindArg.nY = nY;

    D2UnitFindDataStrc unitFindData;
    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, nSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

    for (int i = 0; i < unitFindData.nIndex; ++i)
    {
        D2UnitStrc* pMonster = unitFindData.pUnitsArray[i];
        if (pMonster && pMonster->dwUnitType == UNIT_MONSTER)
        {
            int bAllied = 0;
            if (STATLIST_GetUnitAlignment(pMonster) == 0)
            {
                bAllied = 1;
            }

            if (bCheckIfUndead && !MONSTERS_IsUndead(pMonster))
            {
                bAllied = 0;
            }

            if (pMonster->dwClassId != MONSTER_DIABLOCLONE && bAllied)
            {
                const int nDelay = nDelayMin + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nDelayMax - nDelayMin);
                EVENT_SetEvent(pGame, pMonster, EVENTTYPE_MONUMOD, pGame->dwGameFrame + nDelay, 0, 0);
                D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pMonster, MONUMOD_TEMPSUMMON, 0);
            }
        }
    }

    UNITFINDS_FreeUnitFindData(&unitFindData);
}

void __fastcall QUESTSFX_Andariel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return QUESTSFX_MainHandler(pGame, pUnit, 35, 1, 51, 0);
}

// 0x005DFE20
void __fastcall QUESTSFX_SpawnRadamentDeathMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(MISSILE_RADAMENTDEATH);

    const int nDelayMax = MAX(pMissilesTxtRecord->wRange - 100, 100);

    QUESTSFX_MainHandler(pGame, pUnit, 35, 40, nDelayMax, 0);

    D2GAME_CreateMissile_6FD115E0(pGame, pUnit, 0, 1, MISSILE_RADAMENTDEATH, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
}

void __fastcall QUESTSFX_Izual(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return QUESTSFX_MainHandler(pGame, pUnit, 105, 1, 2, 0);
}

void __fastcall QUESTSFX_ShenkTheOverseer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return QUESTSFX_MainHandler(pGame, pUnit, 35, 25, 125, 0);
}
