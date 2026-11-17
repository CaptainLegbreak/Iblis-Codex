struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

struct D2WinControlInitStrc
{
    int nType;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int field_14;
    int nStringId;
    void* ppCellFile;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
};

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit);                             // 0x004F93C0
void __stdcall sub_004FA450_SetActive(D2WinControlStrc* pControl);                                          // 0x004FA450
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int nArg);                      // 0x004FCFF0
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine);                                          // 0x004FBA30
void __cdecl sub_0043F8C0_ResetLaunchState();                                                               // 0x0043F8C0
int __cdecl sub_0043DB10();                                                                                 // 0x0043DB10

extern "C" const char gszSpace_006FFC44[];                                                                  // 0x006FFC44
extern D2WinControlInitStrc gtControlInit_0070E9E0;                                                         // 0x0070E9E0
extern D2WinControlInitStrc gtControlInit_0070EA10;                                                         // 0x0070EA10
extern D2WinControlInitStrc gtControlInit_0070EA40;                                                         // 0x0070EA40
extern D2WinControlInitStrc gtControlInit_0070EA70;                                                         // 0x0070EA70
extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
D2WinControlStrc* gpControl_00798CB0;                                                                       // 0x00798CB0
D2WinControlStrc* gpControl_00798CB4;                                                                       // 0x00798CB4
D2WinControlStrc* gpControl_00798CB8;                                                                       // 0x00798CB8
D2WinControlStrc* gpControl_00798CBC;                                                                       // 0x00798CBC
int gnValue_00798CC0;                                                                                       // 0x00798CC0

// 0x00444020
int __cdecl sub_00444020_CreateControls()
{
    sub_0043F8C0_ResetLaunchState();
    int bExpansion = sub_0043DB10();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gpControl_00798CBC = CONTROL_Create(&gtControlInit_0070E9E0);
    gpControl_00798CB0 = CONTROL_Create(&gtControlInit_0070EA10);
    sub_004FD060_SetText(gpControl_00798CB0, D2LANG_GetStringFromTblIndex(bExpansion ? 0x14BC : 0x2AE));
    gpControl_00798CB4 = CONTROL_Create(&gtControlInit_0070EA40);
    if (!bExpansion)
    {
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2AF));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B0));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, bExpansion);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B1));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, bExpansion);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B2));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, bExpansion);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B3));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, bExpansion);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B4));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, bExpansion);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B5));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, bExpansion);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B6));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B7));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, bExpansion);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B8));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B34));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B9));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BA));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BB));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B35));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BD));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, bExpansion);
    }
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BE));
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BF));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C0));
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C1));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C2));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C3));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C4));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C5));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C6));
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C7));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C8));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C9));
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CA));
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CB));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CC));
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CD));
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CE));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CF));
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D0));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D1));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D2));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x276C));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x276D));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D3));
    D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    if (!bExpansion)
    {
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D4));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B26));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B27));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B28));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2714));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2715));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DA));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B21));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B22));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DB));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DC));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2716));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2717));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DF));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2718));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2719));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E2));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E3));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E4));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E5));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E6));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E7));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E8));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E9));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2EA));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271A));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2EC));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2ED));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2EE));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271B));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F0));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271C));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F2));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F3));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F4));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271D));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271E));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F7));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F8));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F9));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FA));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FB));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FC));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FD));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FE));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FF));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x300));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x301));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271F));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x303));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x304));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x305));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x306));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x307));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B23));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x309));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30A));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30B));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30C));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30D));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30E));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30F));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x310));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x311));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x312));
        sub_004FD060_SetText(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x313));
        D2Win_10046(gpControl_00798CB4, gszSpace_006FFC44, 0);
    }
    gpControl_00798CB8 = CONTROL_Create(&gtControlInit_0070EA70);
    sub_004FA450_SetActive(gpControl_00798CB8);
    gnValue_00798CC0 = 1;
    D2Win_10053(gpControl_00798CB4, 0);
    return 1;
}

#include "gen/data/Source/D2Client/00444020_sub_00444020_CreateControls.inc"
