#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
struct D2ItemsTxt;
#pragma pack(push, 1)
struct D2MonsterEquipmentStrc
{
	int nItemCode;
	unsigned char nBodyLoc;
	unsigned char unk0x05;
	unsigned char unk0x06;
	unsigned char unk0x07;
};
#pragma pack(pop)




extern const D2MonsterEquipmentStrc gtAncientEquipment[12]; // 0x006E2C90
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall sub_6FC61190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonsterEquipmentStrc* pItemInfo, int nLevel, unsigned int nFlags); // 0x00573B20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc* pUnit);

// 0x005B1C50
static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc* pUnit)
{
	const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
	D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
	const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
	const D2MonsterEquipmentStrc* pItemInfo = &gtAncientEquipment[nClassId - 540];

	int nItemId;
	int nCount = 4;
	do
	{
		D2MonsterEquipmentStrc itemInfo = *pItemInfo;
		D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pItemInfo->nItemCode, &nItemId);
		switch (pGame->nDifficulty)
		{
		case 1:
			itemInfo.nItemCode = pItemsTxtRecord->dwUberCode;
			break;

		case 2:
			itemInfo.nItemCode = pItemsTxtRecord->dwUltraCode;
			break;
		}

		sub_6FC61190(pGame, pUnit, &itemInfo, nLevel, 4);
		pItemInfo += 3;
		--nCount;
	}
	while (nCount);
}

// build: context sub_005B1C50_Shim

// calling-convention shim (not game code)
void __stdcall sub_005B1C50_Shim(D2UnitStrc* pUnit)
{
	MONSTERSPAWN_EquipAncientBarbarians(pUnit);
}
