extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

struct Unicode
{
    unsigned short wChar;
};

struct D2CelStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2ButtonLayoutStrc
{
    int nTextX;
    int nRight;
    int nTop;
    int nBottom;
    int nTextY;
};

int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2CelStrc* __stdcall D2CMP_CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int nArg5);       // 0x00502320
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_004A2760(int nCount);                                                                   // 0x004A2760
void __cdecl sub_004A2550();                                                                                // 0x004A2550

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2ButtonLayoutStrc gaButtonLayouts_007241C0[];                                                       // 0x007241C0
extern int gnGlobal_007BF298;                                                                               // 0x007BF298
extern char gbGlobal_007BF2B0;                                                                              // 0x007BF2B0
extern char gbGlobal_007BF2B3;                                                                              // 0x007BF2B3
extern int gnGlobal_007C0255;                                                                               // 0x007C0255
extern void* gpGlobal_007C02DC;                                                                             // 0x007C02DC
extern void* gpGlobal_007C02E0;                                                                             // 0x007C02E0

// 0x004A2900
static int sub_004A2900_GetButtonLayout(int nMode)
{
    if (sub_004538D0(6) && !sub_004538D0(2))
    {
        const int nResolution = D2GFX_GetResolutionMode();
        if (nMode == 2)
            return nResolution == 2 ? 1 : 3;
        return nResolution == 2 ? 0 : 2;
    }

    const int nResolution = D2GFX_GetResolutionMode();
    if (nMode == 2)
    {
        if (nResolution == 2 || sub_004538D0(2))
            return 1;
        return 3;
    }
    return nResolution == 2 ? 0 : 2;
}

int __stdcall sub_004A2970_IsMouseOnButton(int nX, int nY)
{
    const int nMode = sub_0045AE90();
    const int nIndex = sub_004A2900_GetButtonLayout(nMode);
    const int nOffset = nMode == 2 ? (gnGlobal_0071146C - 0x280) / 2 : 0;
    const int nHeight = gnGlobal_00711470;
    const int nLeft = gaButtonLayouts_007241C0[nIndex].nTextX + nOffset;
    const int nTop = gaButtonLayouts_007241C0[nIndex].nTop + nHeight - 0x1E0;
    if (nX > nLeft && nX < gaButtonLayouts_007241C0[nIndex].nRight + (nMode == 2 ? (gnGlobal_0071146C - 0x280) / 2 : 0)
        && nY > nTop && nY < gaButtonLayouts_007241C0[nIndex].nBottom + nHeight - 0x1E0)
        return 1;
    return 0;
}

void __cdecl sub_004A2A80_DrawButton()
{
    if (sub_00463DF0())
    {
        sub_00455F20(0x11, 1, 0);
        if (gnGlobal_007BF298 == 1)
        {
            gbGlobal_007BF2B0 = 0;
            gnGlobal_007BF298 = 0;
        }
        return;
    }

    const int nMode = sub_0045AE90();
    if (nMode == 3)
        return;
    if (sub_004538D0(0xF))
        return;

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCellFile = gpGlobal_007C02E0;
    tCel.unk0x40 = 0;
    tCel.nFrame = 0;
    const int nIndex = sub_004A2900_GetButtonLayout(nMode);
    const int nCelWidth = sub_006018C0(D2CMP_CelGetHandle(&tCel));
    const int nTextWidth = sub_00501820(D2LANG_GetStringFromTblIndex(0xF58));
    int nTextX = nCelWidth / 2 - nTextWidth / 2 + gaButtonLayouts_007241C0[nIndex].nTextX + 1;
    const int nTextY = gaButtonLayouts_007241C0[nIndex].nTextY + gnGlobal_00711470 - 0x1E0;
    if (sub_0045AE90() == 2)
        nTextX += (gnGlobal_0071146C - 0x280) / 2;
    sub_00502320_DrawText(D2LANG_GetStringFromTblIndex(0xF58), nTextX, nTextY, 0, 0);

    const int nCelY = gaButtonLayouts_007241C0[nIndex].nBottom + gnGlobal_00711470 - 0x1E0;
    int nCelX = gaButtonLayouts_007241C0[nIndex].nTextX;
    if (sub_0045AE90() == 2)
        nCelX += (gnGlobal_0071146C - 0x280) / 2;
    sub_004F6480(&tCel, nCelX, nCelY, -1, 5, 0);

    tCel.pCellFile = gpGlobal_007C02DC;
    if (gbGlobal_007BF2B0 && (unsigned char)sub_004A2970_IsMouseOnButton(sub_00468730(), sub_00468740()))
        tCel.nFrame = 1;
    else
        tCel.nFrame = 0;
    sub_004F6480(&tCel, nCelX + 3, nCelY - 4, -1, 5, 0);
}

// 0x004A28D0
void __cdecl sub_004A28D0_ResetButton()
{
    if (gnGlobal_007C0255 < 5)
        sub_004A2760(gnGlobal_007C0255);
    gbGlobal_007BF2B0 = 0;
    gnGlobal_007BF298 = 0;
    gbGlobal_007BF2B3 = 0;
    sub_004A2550();
}
