struct D2GameStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
	int dwUnitType;
	int dwClassId;
	void* pMemoryPool;
	int dwUnitId;
};

struct D2PlayerDataStrc
{
	char unk_00[0x48];
	int dwUniqueId;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2UnitStrc* __fastcall sub_00553720(D2GameStrc* pGame, D2UnitStrc* pPortal); // 0x00553720
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __fastcall ACT5Q5_OnPortalClosed(D2GameStrc* pGame, D2UnitStrc* pPortal); // 0x0058CF50
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset); // 0x0061AED0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pPlayer); // 0x006221A0

// 0x00535430
void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
	D2_ASSERT(pPlayer, 602);

	D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
	D2_ASSERT(pPlayerData, 605);

	D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, pPlayerData->dwUniqueId);
	if (!pPortal || pPortal->dwClassId != 59)
	{
		return;
	}

	ACT5Q5_OnPortalClosed(pGame, pPortal);

	D2UnitStrc* pOwner = sub_00553720(pGame, pPortal);
	D2ActiveRoomStrc* pPortalRoom = UNITS_GetRoom(pPortal);
	if (pPortalRoom)
	{
		DUNGEON_AllocDrlgDelete(pPortalRoom, 2, !pPortal ? -1 : pPortal->dwUnitId);
	}

	SUNIT_RemoveUnit(pGame, pPortal);
	DUNGEON_ToggleHasPortalFlag(pPortalRoom, 1);

	if (!pOwner)
	{
		return;
	}

	ACT5Q5_OnPortalClosed(pGame, pOwner);

	D2ActiveRoomStrc* pOwnerRoom = UNITS_GetRoom(pOwner);
	if (pOwnerRoom)
	{
		DUNGEON_AllocDrlgDelete(pOwnerRoom, 2, !pOwner ? -1 : pOwner->dwUnitId);
	}

	SUNIT_RemoveUnit(pGame, pOwner);
	DUNGEON_ToggleHasPortalFlag(pOwnerRoom, 1);
}
