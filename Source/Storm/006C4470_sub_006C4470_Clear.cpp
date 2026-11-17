struct sub_006C4470_Pair
{
    int nFirst;
    int nSecond;
};

// 0x006C4470
sub_006C4470_Pair* __fastcall sub_006C4470_Clear(sub_006C4470_Pair* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
    return pPair;
}
