struct D2DrlgActStrc;

struct D2UnitStrc
{
    char unk0x00[0xE8];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2GameStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall SUNITINACTIVE_CompressUnitIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x005433F0
void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);            // 0x00542B40
void __fastcall D2GAME_PopulateRoom_6FC67190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                  // 0x0054EC90
void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                     // 0x00552610
void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                  // 0x005559A0
int __cdecl sub_005377B0();                                                                                 // 0x005377B0
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                   // 0x0061A180
int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom);                                                      // 0x0061A4D0
void __stdcall sub_0061AA20(D2DrlgActStrc* pAct);                                                           // 0x0061AA20

// 0x0052D090
static __forceinline void sub_0052D090_CompressRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc* pNextUnit = 0;
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNextUnit)
    {
        pNextUnit = pUnit->pRoomNext;
        SUNITINACTIVE_CompressUnitIfNeeded(pGame, pUnit);
    }
}

// 0x0052D0C0
static __forceinline void GAME_PopulateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    SUNIT_SpawnPresetUnitsInRoom(pGame, pRoom);
    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
    OBJECTS_PopulationHandler(pGame, pRoom);
    D2GAME_PopulateRoom_6FC67190(pGame, pRoom);
}

// 0x0052D2E0
static __forceinline void sub_0052D2E0_RefreshActs(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i])
        {
            sub_0061AA20(pGame->pAct[i]);
        }
    }
}

// 0x0052DAD0
void __cdecl sub_0052DAD0_AssertFail()
{
    D2_ASSERT(0, 0x1165);
}

// 0x0052DB80
int __cdecl sub_0052DB80_CountFlaggedClients()
{
    return sub_005377B0();
}

void __fastcall sub_M118_Emit_0052D000(D2GameStrc* pGame, int nAct)
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]); pRoom; pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct + 1]))
    {
        if (D2Common_10074(pRoom))
        {
            GAME_PopulateRoom(pGame, pRoom);
        }
        else
        {
            sub_0052D090_CompressRoomUnits(pGame, pRoom);
        }
    }
    sub_0052D2E0_RefreshActs(pGame);
}
