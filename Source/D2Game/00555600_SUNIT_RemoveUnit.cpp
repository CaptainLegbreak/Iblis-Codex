extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define NUM_UNIT_TYPES 6

struct D2QuestChainStrc;
struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    void* f_14;
    char unk0x18[0x14];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x44];
    D2QuestChainStrc* pQuestEventList;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

void __fastcall sub_00555580_DetachUnit(D2UnitStrc* pUnit, D2GameStrc* pGame, int bKeepInRoom);           // 0x00555580
void __fastcall QUESTS_FreeChainRecord(D2GameStrc* pGame, D2QuestChainStrc* pChain);                       // 0x00543590
void __fastcall D2GAME_FreeUnitNode_6FC40310(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x005B1A20
void __fastcall sub_00535430(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x00535430
void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                   // 0x005407A0
void __fastcall PLAYER_Destroy(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                     // 0x005349D0
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath);                       // 0x00648460
void __fastcall sub_005B1A90(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x005B1A90
void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster);                                      // 0x005736A0
void __fastcall OBJECTS_FreeHoverMessage(D2GameStrc* pGame, D2UnitStrc* pObject);                           // 0x00552A00
void __stdcall UNITS_FreeStaticPath(D2UnitStrc* pUnit);                                                     // 0x00623570
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
void __fastcall MISSILES_Free(D2GameStrc* pGame, D2UnitStrc* pMissile);                                     // 0x0059F8E0
void __fastcall ITEMS_FreeSocketInventoryAndTimers(D2GameStrc* pGame, D2UnitStrc* pItem);                  // 0x00557EE0
void __stdcall ITEMS_FreeItemData(void* pMemPool, D2UnitStrc* pItem);                                       // 0x00627D00
void __fastcall SUNITEVENT_FreeEventList(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005C0A90
void __fastcall D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(D2UnitStrc* pUnit);                              // 0x00571F40
void __stdcall UNITS_FreeUnit(D2UnitStrc* pUnit);                                                           // 0x00620300

// 0x00555600
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pGame, 0x59);
    D2_ASSERT(pUnit, 0x5C);
    D2_ASSERT(pUnit->dwUnitType < NUM_UNIT_TYPES, 0x61);

    sub_00555580_DetachUnit(pUnit, pGame, 0);

    if (pUnit->pQuestEventList)
    {
        QUESTS_FreeChainRecord(pGame, pUnit->pQuestEventList);
        pUnit->pQuestEventList = 0;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        D2GAME_FreeUnitNode_6FC40310(pGame, pUnit);
        sub_00535430(pGame, pUnit);
        PARTY_LeaveParty(pGame, pUnit);
        PLAYER_Destroy(pGame, pUnit);

        if (pUnit->pDynamicPath)
        {
            PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
            pUnit->pDynamicPath = 0;
        }
        break;

    case UNIT_MONSTER:
        sub_005B1A90(pGame, pUnit);

        if (pUnit->pDynamicPath)
        {
            PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
            pUnit->pDynamicPath = 0;
        }

        MONSTER_Free(pGame, pUnit);
        break;

    case UNIT_OBJECT:
        OBJECTS_FreeHoverMessage(pGame, pUnit);
        UNITS_FreeStaticPath(pUnit);
        FOG_FreePool(pGame->pMemoryPool, pUnit->f_14, ".\\UNIT\\SUnit.cpp", 0xA4, 0);
        break;

    case UNIT_MISSILE:
        if (pUnit->pDynamicPath)
        {
            PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
            pUnit->pDynamicPath = 0;
        }

        MISSILES_Free(pGame, pUnit);
        break;

    case UNIT_ITEM:
        ITEMS_FreeSocketInventoryAndTimers(pGame, pUnit);
        ITEMS_FreeItemData(pGame->pMemoryPool, pUnit);
        UNITS_FreeStaticPath(pUnit);
        break;

    case UNIT_TILE:
        UNITS_FreeStaticPath(pUnit);
        break;
    }

    SUNITEVENT_FreeEventList(pGame, pUnit);
    D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(pUnit);
    UNITS_FreeUnit(pUnit);
}
