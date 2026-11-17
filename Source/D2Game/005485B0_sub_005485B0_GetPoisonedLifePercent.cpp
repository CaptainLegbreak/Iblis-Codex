struct D2UnitStrc;
struct D2StatListStrc;

struct D2GameStrc
{
	char unk_00[0xA8];
	int dwGameFrame;
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall sub_00626090(D2StatListStrc* pStatList); // 0x00626090

// build: context PoisonStat_GetPerFrame
static __forceinline int PoisonStat_GetPerFrame(D2StatListStrc* pStatList)
{
	if (pStatList)
	{
		return STATLIST_GetStatValue(pStatList, 74, 0);
	}
	return 0;
}

static __declspec(noinline) unsigned char sub_005485B0_GetPoisonedLifePercent(D2UnitStrc* pUnit);

// 0x005485B0
static unsigned char sub_005485B0_GetPoisonedLifePercent(D2UnitStrc* pUnit)
{
	const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
	const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
	D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 100);
	if (!pStatList || !nMaxLife)
	{
		return 0;
	}

	D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
	const int nFrames = sub_00626090(pStatList) - pGame->dwGameFrame;
	const unsigned char nPercent = (unsigned char)((((PoisonStat_GetPerFrame(pStatList) * nFrames + nHitpoints) >> 8) * 100) / nMaxLife);
	const int nClamped = nPercent > 100 ? 100 : nPercent;
	return (unsigned char)nClamped;
}

// build: context sub_005485B0_Shim

// calling-convention shim (not game code)
int __stdcall sub_005485B0_Shim(D2UnitStrc* pUnit)
{
	return sub_005485B0_GetPoisonedLifePercent(pUnit);
}
