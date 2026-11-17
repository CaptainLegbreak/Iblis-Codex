struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2OrbSmoothStrc
{
    int nValue;
    int nTick;
    int f_8;
    int nPrevTick;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2OrbSmoothStrc gtOrbSmooth_007BEF30[3];                                                                    // 0x007BEF30
extern void* gpCellFile_007BEF68;                                                                           // 0x007BEF68
extern void* gpCellFile_007BEF80;                                                                           // 0x007BEF80
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
unsigned int __cdecl sub_0044DA90();                                                                        // 0x0044DA90
int __cdecl sub_004F5140();                                                                                 // 0x004F5140
int __stdcall sub_004F64E0(D2CelContextStrc* pContext, int nX, int nY, int nTop, int nHeight, int nDrawMode); // 0x004F64E0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                            // 0x00625DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

static int ORB_AbsValue(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x00496DD0
static int sub_00496DD0_GetSmoothedOrbValue(int nStatId)
{
    int bCheckDrop = 1;
    D2UnitStrc* pPlayer = sub_00463DD0();
    int nValue = STATLIST_UnitGetStatValue(pPlayer, nStatId, 0);
    int nIndex;
    int nMax = 0;
    switch (nStatId)
    {
    case 6:
        nMax = STATLIST_GetMaxLifeFromUnit(pPlayer);
        nIndex = 0;
        bCheckDrop = 0;
        break;
    case 8:
        nMax = STATLIST_GetMaxManaFromUnit(pPlayer);
        nIndex = 1;
        break;
    case 10:
        nMax = STATLIST_GetMaxStaminaFromUnit(pPlayer);
        nIndex = 2;
        break;
    }

    if (!nMax)
        return 0;

    if (sub_0044DA90() <= 1)
    {
        gtOrbSmooth_007BEF30[nIndex].f_8 = nValue;
        gtOrbSmooth_007BEF30[nIndex].nValue = nValue;
    }

    if (!bCheckDrop && nValue < gtOrbSmooth_007BEF30[nIndex].nValue)
    {
        gtOrbSmooth_007BEF30[nIndex].f_8 = nValue;
        gtOrbSmooth_007BEF30[nIndex].nValue = nValue;
        const unsigned int nTick = sub_0044DA90();
        gtOrbSmooth_007BEF30[nIndex].nTick = nTick;
        gtOrbSmooth_007BEF30[nIndex].nPrevTick = nTick;
    }

    const int nLast = gtOrbSmooth_007BEF30[nIndex].nValue;
    if (nLast != nValue)
    {
        const int nDiff = ORB_AbsValue(nLast - nValue);

        if (nDiff >= nMax / 8)
        {
            gtOrbSmooth_007BEF30[nIndex].f_8 = nValue;
            gtOrbSmooth_007BEF30[nIndex].nPrevTick = sub_0044DA90();
        }
        else
        {
            gtOrbSmooth_007BEF30[nIndex].nPrevTick = gtOrbSmooth_007BEF30[nIndex].nTick;
            if (nValue == nMax)
                gtOrbSmooth_007BEF30[nIndex].f_8 = nValue;
            else
                gtOrbSmooth_007BEF30[nIndex].f_8 = nLast;
        }
        gtOrbSmooth_007BEF30[nIndex].nValue = nValue;
        gtOrbSmooth_007BEF30[nIndex].nTick = sub_0044DA90();
    }

    const int nStart = gtOrbSmooth_007BEF30[nIndex].nTick;
    const int nElapsed = sub_0044DA90() - nStart;
    int nDuration = nStart - gtOrbSmooth_007BEF30[nIndex].nPrevTick;
    if (nDuration < 7)
        nDuration = 7;
    else if (nDuration > 15)
        nDuration = 15;

    if (nValue > 0 && nElapsed < nDuration)
    {
        const int nFrom = gtOrbSmooth_007BEF30[nIndex].f_8;
        const int nDelta = gtOrbSmooth_007BEF30[nIndex].nValue - nFrom;
        if (nDelta)
        {
            nValue = (int)((double)(nElapsed + 1) / nDuration * nDelta) + nFrom;
        }
    }

    if (nValue < 0)
        nValue = 0;
    else if (nValue > nMax)
        nValue = nMax;
    return nValue;
}

// 0x00496F80
void __cdecl sub_00496F80_DrawLifeOrb()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nLife = sub_00496DD0_GetSmoothedOrbValue(6);
    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer);
    if (!nMaxLife)
        return;

    int nHeight = 80 * nLife / nMaxLife;
    if (nHeight >= 1 && nHeight <= 2)
    {
        D2UnitStrc* pUnit = sub_00463DD0();
        if (pUnit && pUnit->dwUnitType == 0 && pUnit->dwAnimMode != 0x11)
            nHeight = 2;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpCellFile_007BEF68;
    tContext.nFrame = 0;
    if (STATES_CheckState(sub_00463DD0(), 0x64))
    {
        int nPoison = 80 * STATLIST_UnitGetStatValue(sub_00463DD0(), 0x4A, 0) / 100;
        if (nPoison > 80)
            nPoison = 80;
        if (nPoison > nHeight)
        {
            if (sub_004F5140() == 6)
                sub_004F64E0(&tContext, 0x1C, gnGlobal_00711470 - 0xD, nHeight, nPoison - nHeight, 0);
            else
                sub_004F64E0(&tContext, 0x1D, gnGlobal_00711470 - 0xD, nHeight, nPoison - nHeight, 0);
        }
    }

    tContext.nFrame = STATES_CheckState(sub_00463DD0(), 2) ? 2 : 0;
    if (nHeight)
    {
        switch (sub_004F5140())
        {
        case 1:
        case 3:
            sub_004F64E0(&tContext, 0x1D, gnGlobal_00711470 - 0xD, 0, nHeight, 5);
            break;
        default:
            sub_004F64E0(&tContext, 0x1D, gnGlobal_00711470 - 0xD, 0, nHeight, 5);
            break;
        }
    }

    tContext.pCellFile = gpCellFile_007BEF80;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0x1C, gnGlobal_00711470 - 5, -1, 5, 0);
}

// 0x00497110
void __cdecl sub_00497110_DrawManaOrb()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    int nMana = sub_00496DD0_GetSmoothedOrbValue(8);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pPlayer);
    if (!nMaxMana)
        return;

    if (nMana > nMaxMana)
        nMana = nMaxMana;
    const int nHeight = 80 * nMana / nMaxMana;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpCellFile_007BEF68;
    tContext.nFrame = 1;
    if (STATES_CheckState(sub_00463DD0(), 0x6A))
    {
        int nShield = 80 * STATLIST_UnitGetStatValue(sub_00463DD0(), 0x1A, 0) / 100;
        if (nShield > 80)
            nShield = 80;
        if (nShield > nHeight)
        {
            if (sub_004F5140() == 6)
                sub_004F64E0(&tContext, gnGlobal_0071146C - 0x70, gnGlobal_00711470 - 0xD, nHeight, nShield - nHeight, 0);
            else
                sub_004F64E0(&tContext, gnGlobal_0071146C - 0x6F, gnGlobal_00711470 - 0xD, nHeight, nShield - nHeight, 0);
        }
    }

    switch (sub_004F5140())
    {
    case 1:
    case 3:
        sub_004F64E0(&tContext, gnGlobal_0071146C - 0x6F, gnGlobal_00711470 - 0xD, 0, nHeight, 5);
        break;
    default:
        sub_004F64E0(&tContext, gnGlobal_0071146C - 0x6F, gnGlobal_00711470 - 0xD, 0, nHeight, 5);
        break;
    }

    tContext.pCellFile = gpCellFile_007BEF80;
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_0071146C - 0x6E, gnGlobal_00711470 - 9, -1, 5, 0);
}
