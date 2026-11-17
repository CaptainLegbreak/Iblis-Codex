#pragma pack(push, 1)
struct D2TextBoxView
{
    char unk0x00[0x16];
    int dwState;
};
#pragma pack(pop)

typedef int(__fastcall* PANELCLOSEFN)(void* pArg, int a2, int a3);

extern D2TextBoxView* gpTextBox_007BF0A4; // 0x007BF0A4
extern int gnPanelOpen_007BF1BC; // 0x007BF1BC
extern int gnPending_007BF1C4; // 0x007BF1C4
extern void* gpHint_007BF202; // 0x007BF202
extern int gbHintActive_007BF20A; // 0x007BF20A
extern void* gpHint_007BF24B; // 0x007BF24B
extern PANELCLOSEFN gpfnClose_007BF258; // 0x007BF258
extern void* gpCloseArg_007BF25C; // 0x007BF25C
extern int gbHandlers_007BF27C; // 0x007BF27C
extern char gHandlerTable_00722600[]; // 0x00722600

int __cdecl sub_00514CC0(); // 0x00514CC0
int __fastcall sub_004B95C0_IsHintPlaying(void* pHint); // 0x004B95C0
static __declspec(noinline) int __cdecl sub_0049D5A0_UpdateTextBox(D2TextBoxView* pTextBox);
void __stdcall sub_0049D410_FreeTextBox(D2TextBoxView* pTextBox); // 0x0049D410
void __fastcall sub_00467430_SetSelectionRect(void* pRect); // 0x00467430
void __cdecl sub_0049F960_ResetTextBox(); // 0x0049F960
void __fastcall sub_004B3D10_CancelAndFlag(void* pHint); // 0x004B3D10
void __cdecl sub_00453AE0(); // 0x00453AE0
void* __stdcall sub_004F59A0(); // 0x004F59A0
void __fastcall sub_00451E10_UnregisterHandlerTable(void* hWnd, void* pTable, int nCount); // 0x00451E10

// build: context sub_0049D5A0_UpdateTextBox
// calling-convention shim (not game code)
static int __cdecl sub_0049D5A0_UpdateTextBox(D2TextBoxView* pTextBox)
{
    void* pA = sub_004F59A0();
    void* pB = sub_004F59A0();
    sub_00467430_SetSelectionRect(pA);
    sub_00467430_SetSelectionRect(pB);
    sub_00467430_SetSelectionRect(pA);
    sub_00467430_SetSelectionRect(pB);
    pTextBox->dwState = 1;
    return pTextBox->unk0x00[0];
}

// 0x004A0770
static int __stdcall sub_004A0770(int bIgnore, D2TextBoxView* pTextBox)
{
    if (bIgnore)
    {
        pTextBox->dwState = 2;
        return 0;
    }

    const int bBusy = sub_00514CC0();
    if (!gpHint_007BF24B || sub_004B95C0_IsHintPlaying(gpHint_007BF24B) || !bBusy)
    {
        gpHint_007BF24B = 0;
        if (sub_0049D5A0_UpdateTextBox(pTextBox))
        {
            gnPanelOpen_007BF1BC = 1;
            if (!gbHintActive_007BF20A && gpTextBox_007BF0A4)
            {
                sub_0049D410_FreeTextBox(gpTextBox_007BF0A4);
                gpTextBox_007BF0A4 = 0;
                sub_00467430_SetSelectionRect(0);
            }

            sub_0049F960_ResetTextBox();
            if (gpfnClose_007BF258)
            {
                return gpfnClose_007BF258(gpCloseArg_007BF25C, 0, 0);
            }

            if (gnPending_007BF1C4 == 1)
            {
                gnPending_007BF1C4 = 0;
            }
            else if (gbHintActive_007BF20A)
            {
                sub_004B3D10_CancelAndFlag(gpHint_007BF202);
            }

            sub_00453AE0();
            gbHintActive_007BF20A = 0;
            sub_00467430_SetSelectionRect(0);
            if (gbHandlers_007BF27C == 1)
            {
                gbHandlers_007BF27C = 0;
                sub_00451E10_UnregisterHandlerTable(sub_004F59A0(), gHandlerTable_00722600, 7);
            }

            return 0;
        }
    }

    return 1;
}

// build: context sub_004A0770_Shim
// calling-convention shim (not game code)
int __stdcall sub_004A0770_Shim()
{
    D2TextBoxView* pTextBox = gpTextBox_007BF0A4;
    if (pTextBox && (pTextBox->dwState == 1 || pTextBox->dwState == 0))
    {
        return sub_004A0770(gnPanelOpen_007BF1BC, pTextBox);
    }

    return 0;
}
