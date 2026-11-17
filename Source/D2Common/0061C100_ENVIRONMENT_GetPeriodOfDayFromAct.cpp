struct D2DrlgActStrc;

struct D2DrlgEnvironmentStrc
{
    int nCycleIndex;
    int nPeriodOfDay;
    int nTicks;
    char unk0x0C[0x1C];
    int nTimeRate;
};

D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct);                       // 0x0061AA60

// 0x0061C100
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    if (!pEnvironment)
    {
        if (pBaseTime)
        {
            *pBaseTime = 0;
        }
        return 0;
    }

    if (pBaseTime)
    {
        if (pEnvironment->nTimeRate)
        {
            *pBaseTime = pEnvironment->nTicks / pEnvironment->nTimeRate;
        }
        else
        {
            *pBaseTime = 0;
        }
    }
    return pEnvironment->nPeriodOfDay;
}
