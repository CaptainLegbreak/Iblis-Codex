#include "D2Client.h"

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

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
extern D2OrbSmoothStrc gtOrbSmooth_007BEF30[3];                                                             // 0x007BEF30
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
unsigned int __cdecl sub_0044DA90();                                                                        // 0x0044DA90
int __cdecl sub_004F5140();                                                                                 // 0x004F5140
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
extern unsigned char gnTextColorRed_007BEFBA;                                                              // 0x007BEFBA
extern unsigned char gnTextColorA_007BEFBB;                                                                 // 0x007BEFBB
extern unsigned char gnTextColorB_007BEFE4;                                                                 // 0x007BEFE4
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

static int ORB_AbsValue(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

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

// 0x004975B0
void __cdecl sub_004975B0_DrawStaminaBar()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nStamina = sub_00496DD0_GetSmoothedOrbValue(10);
    int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pPlayer);
    if (!gnTextColorRed_007BEFBA)
    {
        gnTextColorRed_007BEFBA = D2Win_10034_MixRGB(0xFF, 0, 0);
        gnTextColorA_007BEFBB = D2Win_10034_MixRGB(0xF4, 0xC0, 0x4C);
        gnTextColorB_007BEFE4 = D2Win_10034_MixRGB(0, 0, 0xFF);
    }

    int nColor = gnTextColorA_007BEFBB;
    if (nMaxStamina + 5 < nStamina || STATES_CheckStateMaskOnUnit(pPlayer, 0x18))
    {
        nMaxStamina = nStamina;
        nColor = gnTextColorB_007BEFE4;
    }

    int nWidth;
    if (nMaxStamina <= 0)
        nWidth = 0;
    else
        nWidth = 102 * nStamina / nMaxStamina;
    if (nWidth < 25)
        nColor = gnTextColorRed_007BEFBA;

    sub_0046EFD0_DrawFramedBox(gnGlobal_0071146C / 2 - 0x7F, gnGlobal_00711470 - 0x1B, nWidth, 0x12, nColor, 2);

    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    int nCur = sub_00496DD0_GetSmoothedOrbValue(10) / 256;
    const int nMax = STATLIST_GetMaxStaminaFromUnit(pPlayer) / 256;
    int nTextColor = 0;
    if (nCur > nMax || STATES_CheckState(pPlayer, 0x88))
    {
        nCur = nMax;
        nTextColor = 3;
    }

    Unicode wszText[100];
    if (nMouseX >= gnGlobal_0071146C / 2 - 0x7F && nMouseX <= gnGlobal_0071146C / 2 - 0x19
        && nMouseY >= gnGlobal_00711470 - 0x1B && nMouseY <= gnGlobal_00711470 - 9)
    {
        sub_005269D0(100, wszText, D2LANG_GetStringFromTblIndex(0x1044), nCur, nMax);
        sub_00502280_SetPopUpText(wszText, gnGlobal_0071146C / 2 - 0x4C, gnGlobal_00711470 - 0x34, nTextColor, 1);
    }
}
// 0x00498120
void __cdecl sub_00498120()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    Unicode wszLife[100];
    Unicode wszMana[100];
    Unicode wszLifeText[100];
    Unicode wszManaText[100];

    if (gdwShowHpText_007BEFDC || (nMouseX >= 0x1E && nMouseX <= 0x1E + 0x50
        && nMouseY >= gnGlobal_00711470 - 0x4B && nMouseY <= gnGlobal_00711470 - 0xF))
    {
        int nLife = sub_00496DD0_GetSmoothedOrbValue(6) >> 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer) >> 8;
        D2UnitStrc* pUnit = sub_00463DD0();
        if (pUnit && pUnit->dwUnitType == 0 && pUnit->dwAnimMode != 0x11 && nLife >= 0 && nLife <= 1)
            nLife = 1;

        sub_005269D0(100, wszLifeText, D2LANG_GetStringFromTblIndex(0x1045), nLife, nMaxLife);
        sub_00526700(wszLife, wszLifeText);
        const int nHalfWidth = sub_00501820(wszLife) / 2;
        sub_00502320(wszLife, 0x41 - nHalfWidth, gnGlobal_00711470 - 0x5F, 0, 0);
    }

    if (gdwShowMpText_007BEFE0 || (nMouseX >= gnGlobal_0071146C - 0x6F && nMouseX <= gnGlobal_0071146C - 0x1F
        && nMouseY >= gnGlobal_00711470 - 0x4B && nMouseY <= gnGlobal_00711470 - 0xF))
    {
        const int nMana = sub_00496DD0_GetSmoothedOrbValue(8) >> 8;
        sub_005269D0(100, wszManaText, D2LANG_GetStringFromTblIndex(0x1046), nMana, STATLIST_GetMaxManaFromUnit(pPlayer) >> 8);
        sub_00526700(wszMana, wszManaText);
        const int nHalfWidth = sub_00501820(wszMana) / 2;
        sub_00502320(wszMana, gnGlobal_0071146C - nHalfWidth - 0x50, gnGlobal_00711470 - 0x5F, 0, 0);
    }
}
