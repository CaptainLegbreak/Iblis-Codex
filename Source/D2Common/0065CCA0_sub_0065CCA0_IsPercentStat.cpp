static __forceinline int IsStatInRange(int nStatId, int nMin, int nMax)
{
    if (nStatId < nMin)
        return 0;
    if (nStatId > nMax)
        return 0;
    return 1;
}

static __declspec(noinline) int sub_0065CCA0_IsPercentStat(int nStatId);
// 0x0065CCA0
static int sub_0065CCA0_IsPercentStat(int nStatId)
{
    if (IsStatInRange(nStatId, 16, 18))
        return 1;
    return 0;
}

int __fastcall IsPercentStatContext(const int* pStatId)
{
    return sub_0065CCA0_IsPercentStat(*pStatId);
}
