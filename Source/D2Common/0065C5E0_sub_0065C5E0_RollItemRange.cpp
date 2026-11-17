struct D2UnitStrc;
struct D2SeedStrc;

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

// 0x0065C5E0
static __forceinline int sub_0065C5E0_RollItemRange(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    int nPossibleRolls;
    if (ITEMS_GetItemFormat(pItem) < 1)
    {
        nPossibleRolls = nMax - nMin;
    }
    else
    {
        nPossibleRolls = nMax - nMin + 1;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

// 0x0065C620
static __forceinline int sub_0065C620_RollItemRange(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    int nPossibleRolls;
    if (ITEMS_GetItemFormat(pItem) < 1)
    {
        nPossibleRolls = nMax - nMin;
    }
    else
    {
        nPossibleRolls = nMax - nMin + 1;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

struct sub_M415_EmitArgs
{
    int nPad0;
    int nPad4;
    int nPad8;
    int nMin;
    int nMax;
};

int __stdcall sub_M415_EmitRoll_0065C5E0(D2UnitStrc* pItem, sub_M415_EmitArgs* pArgs, int nBias)
{
    return sub_0065C5E0_RollItemRange(pItem, pArgs->nMin, pArgs->nMax) + nBias;
}

int __stdcall sub_M415_EmitRoll_0065C620(D2UnitStrc* pItem, sub_M415_EmitArgs* pArgs, int nBias)
{
    return sub_0065C620_RollItemRange(pItem, pArgs->nMin, pArgs->nMax) + nBias;
}
