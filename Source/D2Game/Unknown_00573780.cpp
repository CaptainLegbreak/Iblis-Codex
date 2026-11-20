#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

#define UNIT_MONSTER 1
struct D2SeedStrc;
struct D2MonsterDataStrc;
struct D2ComponentVariantStrc;
struct D2MonRegDataStrc;





extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_00463860_GetMonsterClass(D2UnitStrc* pUnit); // 0x00463860
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nParam); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nFrame, int nParam1, int nParam2); // 0x005417D0

struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
};

struct D2ComponentVariantStrc
{
    unsigned char nComponent[16];
};

struct D2MonRegDataStrc
{
    char unk0x00[3];
    unsigned char nComponentVariantsMax;
    D2ComponentVariantStrc nComponentVariants[1];
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

static __forceinline int GetValidMonsterClass(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        return nClassId;
    return -1;
}

// 0x00573780
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    if (!pUnit) return;
    if (pUnit->dwAnimMode == 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 2, 0, 0);
    }
    else if (pUnit->dwAnimMode == 12 || pUnit->dwAnimMode == 0)
    {
        return;
    }
    switch (GetValidMonsterClass(sub_00463860_GetMonsterClass(pUnit)))
    {
    case 110:
    case 118:
    case 136:
    case 247:
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 2, 0, 0);
        break;
    }
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// build: context MONSTER_GetComponents
static __forceinline unsigned char* MONSTER_GetComponents(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return 0;
    }

    return pMonsterData->nComponent;
}

// 0x005739D0
void __fastcall MONSTER_SetComponents(D2MonRegDataStrc* pMonRegData, D2UnitStrc* pUnit)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER)
    {
        return;
    }

    if (pMonRegData && pMonRegData->nComponentVariantsMax > 0)
    {
        const D2ComponentVariantStrc* pVariant = &pMonRegData->nComponentVariants[ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pMonRegData->nComponentVariantsMax)];
        D2ComponentVariantStrc* pComponents = (D2ComponentVariantStrc*)MONSTER_GetComponents(pUnit);
        if (pComponents)
        {
            *pComponents = *pVariant;
        }
    }
    else
    {
        unsigned char* pComponents = MONSTER_GetComponents(pUnit);
        int i = 0;
        int nCount = 16;
        do
        {
            pComponents[i] = SEED_RollLimitedRandomNumber(&pUnit->pSeed, D2COMMON_11068_GetCompInfo(pUnit, i));
            ++i;
        }
        while (--nCount);
    }
}

// build: context sub_00573AE0_GetComponents
static __forceinline unsigned char* sub_00573AE0_GetComponents(D2UnitStrc* pUnit)
{
	if (!pUnit || pUnit->dwUnitType != 1)
	{
		return 0;
	}

	D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
	if (!pMonsterData)
	{
		return 0;
	}

	return pMonsterData->nComponent;
}

// 0x00573AE0
int __fastcall sub_00573AE0_HasComponents(D2UnitStrc* pUnit)
{
	const unsigned char* pComponents = sub_00573AE0_GetComponents(pUnit);
	int i = 0;
	do
	{
		if (*pComponents)
		{
			return 1;
		}
		++i;
		++pComponents;
	}
	while (i < 16);

	return 0;
}
