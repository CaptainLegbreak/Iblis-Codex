struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

// 0x004CC790
int __fastcall sub_004CC790_RollRange(D2SeedStrc* pSeed, int nMin, int nMax)
{
    if (nMin >= nMax)
        return nMin;

    return ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1) + nMin;
}
