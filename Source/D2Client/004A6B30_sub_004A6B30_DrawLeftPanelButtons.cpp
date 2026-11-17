struct Unicode;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
int __fastcall sub_004A6580_IsInPanelButton(int nMode, int nX, int nY);                                     // 0x004A6580
int __cdecl sub_004A65E0_IsInLeftButton();                                                                  // 0x004A65E0
int __fastcall sub_004A6630_IsInPanelButton2(int nMode, int nX, int nY);                                    // 0x004A6630
int __cdecl sub_004A6690_IsInRightButton();                                                                 // 0x004A6690
bool __stdcall sub_004A6A00_IsUiBusy(int nType);                                                            // 0x004A6A00
bool __stdcall sub_004A6D50_IsUiBusy2(int nType);                                                           // 0x004A6D50
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
D2CelStrc* __stdcall D2CMP_CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern void* gpGlobal_007C02DC;                                                                             // 0x007C02DC
extern void* gpGlobal_007C02E0;                                                                             // 0x007C02E0
extern int gnGlobal_007C02E4;                                                                               // 0x007C02E4
extern int gnGlobal_007C02E8;                                                                               // 0x007C02E8

// 0x004A6B30
void __cdecl sub_004A6B30_DrawLeftPanelButtons()
{
    const int nBorder = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2 && sub_004A6A00_IsUiBusy(nBorder))
    {
        gnGlobal_007C02E4 = 0;
        return;
    }

    int nX;
    if (nBorder == 2)
        nX = gnGlobal_0071146C / 2 + 0x28;
    else
        nX = 0x28;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02E0;
    tContext.nFrame = 0;
    const int nCelWidth = sub_006018C0(D2CMP_CelGetHandle(&tContext));
    const int nTextWidth = sub_00501820(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_00502320(D2LANG_GetStringFromTblIndex(0xF92), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnGlobal_00711470 - 0x8E, 0, 0);
        sub_004F6480(&tContext, nX, gnGlobal_00711470 - 0x69, -1, 5, 0);
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02DC;
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E4 && sub_004A6580_IsInPanelButton(nBorder, sub_00468730(), sub_00468740()))
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    else
    {
        if (gnGlobal_007C02E4 && sub_004A65E0_IsInLeftButton())
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    sub_006018C0(D2CMP_CelGetHandle(&tContext));
    sub_00501820(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_004F6480(&tContext, nX + 3, gnGlobal_00711470 - 0x6D, -1, 5, 0);
        return;
    }

    if (sub_004A65E0_IsInLeftButton() && !sub_004538D0(9))
        sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0xF92), gnGlobal_0071146C / 2 - 0xB3, gnGlobal_00711470 - 0x32, 0, 1);
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xC2, gnGlobal_00711470 - 8, -1, 5, 0);
}

// 0x004A6E60
void __cdecl sub_004A6E60_DrawRightPanelButtons()
{
    const int nBorder = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2 && sub_004A6D50_IsUiBusy2(nBorder))
    {
        gnGlobal_007C02E8 = 0;
        return;
    }

    int nX;
    if (nBorder == 1)
        nX = gnGlobal_0071146C - gnGlobal_0071146C / 2 - 0x49;
    else
        nX = gnGlobal_0071146C - 0x49;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02E0;
    tContext.nFrame = 0;
    const int nCelWidth = sub_006018C0(D2CMP_CelGetHandle(&tContext));
    const int nTextWidth = sub_00501820(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_00502320(D2LANG_GetStringFromTblIndex(0xF93), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnGlobal_00711470 - 0x8E, 0, 0);
        sub_004F6480(&tContext, nX, gnGlobal_00711470 - 0x69, -1, 5, 0);
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02DC;
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E8 && sub_004A6630_IsInPanelButton2(nBorder, sub_00468730(), sub_00468740()))
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    else
    {
        if (gnGlobal_007C02E8 && sub_004A6690_IsInRightButton())
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    sub_006018C0(D2CMP_CelGetHandle(&tContext));
    sub_00501820(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_004F6480(&tContext, nX + 3, gnGlobal_00711470 - 0x6D, -1, 5, 0);
        return;
    }

    if (sub_004A6690_IsInRightButton() && !sub_004538D0(9))
        sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0xF93), gnGlobal_0071146C / 2 + 0xB2, gnGlobal_00711470 - 0x32, 0, 1);
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0xA3, gnGlobal_00711470 - 8, -1, 5, 0);
}
