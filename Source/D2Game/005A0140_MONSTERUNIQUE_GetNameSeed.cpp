struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
    unsigned short wNameSeed;
    unsigned short nTypeFlag;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

#define UNIT_MONSTER 1

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __fastcall sub_005A00F0_GetMonUModConstant(int nIndex);                                                 // 0x005A00F0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

// 0x005A0140
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 5382;
    }
    return pMonsterData->wNameSeed;
}

struct Data005A0180 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned short wUnknown14;
    unsigned short wFlags16;
};

struct Unit005A0180 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0180* pData;
};

extern "C" __declspec(dllexport) int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask) {
    Data005A0180* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return (unsigned short)(pData->wFlags16 & wMask) != 0;
}

// 0x005A0D20
static void sub_005A0D20_AddLifePercent(D2UnitStrc* pUnit, int nPercentage)
{
    int nHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    int nBonus;
    if (nHitpoints > 0x100000)
    {
        if (100 > (nHitpoints >> 4))
        {
            nBonus = (int)(nHitpoints * (__int64)nPercentage / 100);
        }
        else
        {
            nBonus = nPercentage * (nHitpoints / 100);
        }
    }
    else if (nPercentage > 0x10000)
    {
        if (100 > (nPercentage >> 4))
        {
            nBonus = (int)(nHitpoints * (__int64)nPercentage / 100);
        }
        else
        {
            nBonus = nHitpoints * (nPercentage / 100);
        }
    }
    else
    {
        nBonus = nPercentage * nHitpoints / 100;
    }

    nHitpoints += nBonus;
    STATLIST_SetUnitStat(pUnit, 7, nHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, 6, nHitpoints, 0);
}

void __fastcall MONSTERUNIQUE_UMod2_HealthBonus(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const unsigned char nDifficulty = pGame->nDifficulty;
    if (nDifficulty >= 3)
    {
        return;
    }

    if (!bUnique)
    {
        sub_005A0D20_AddLifePercent(pUnit, sub_005A00F0_GetMonUModConstant(nDifficulty + 1));
    }
    else
    {
        int nIndex;
        if (sub_005A0180((Unit005A0180*)pUnit, 4))
        {
            nIndex = nDifficulty + 4;
        }
        else
        {
            nIndex = nDifficulty + 7;
        }
        sub_005A0D20_AddLifePercent(pUnit, sub_005A00F0_GetMonUModConstant(nIndex));
        STATLIST_SetUnitStat(pUnit, 0x4A, 0, 0);
    }
}
