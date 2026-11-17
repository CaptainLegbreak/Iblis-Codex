struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
void __fastcall D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue);               // 0x00530EA0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall sub_0055A090_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                     // 0x00621CE0
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

// 0x00535510
int __fastcall sub_6FC7C260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, int nValue)
{
    if (SUNIT_GetServerUnit(pGame, 0, nUnitGUID) != pUnit)
    {
        return 0;
    }

    if (nValue > STATLIST_UnitGetStatValue(pUnit, 0xE, 0))
    {
        return 0;
    }

    if (nValue < 0)
    {
        return 0;
    }

    if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
    {
        return 0;
    }

    const unsigned int nAmount = nValue;
    if (nAmount > 0)
    {
        D2CoordStrc tCoord;
        UNITS_GetCoords(pUnit, &tCoord);

        unsigned int nGoldValue = nAmount;
        if (nAmount > 2000000000)
        {
            nGoldValue = 2000000000;
        }

        D2UnitStrc* pGoldPiles[0x20];
        int nCount = 0;
        sub_0055A090_DropGoldPiles(pGame, pUnit, nGoldValue, pGoldPiles, &nCount, 0x20);
        if (nCount)
        {
            for (int i = 0; i < nCount; ++i)
            {
                D2UnitStrc* pItem = pGoldPiles[i];
                if (pUnit && sub_0044BE50_GetUnitTypeOrInvalid(pUnit) == 0)
                {
                    UNITS_StoreOwner(pItem, pUnit);
                }

                const int nPileGold = STATLIST_UnitGetStatValue(pItem, 0xE, 0);
                D2GAME_SetStatOrResetGold_6FC7CA70(pUnit, 0xE, STATLIST_UnitGetStatValue(pUnit, 0xE, 0) - nPileGold);
            }
        }
    }

    return 1;
}
