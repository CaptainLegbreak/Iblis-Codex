struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x68];
    int (__fastcall* pfnSlot68)();
};

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
int __stdcall sub_0042FDE0_KeyFilter(D2WinControlStrc* pControl, int nArg, const char* pChar);             // 0x0042FDE0
int __stdcall sub_0042FE60_KeyFilter(D2WinControlStrc* pControl, int nArg, const char* pChar);             // 0x0042FE60
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
void __cdecl sub_004306C0_UpdateOk();                                                                       // 0x004306C0
void __cdecl sub_004336C0();                                                                                // 0x004336C0
int __stdcall sub_00433BE0_OnEnter(int nArg);                                                               // 0x00433BE0
int __cdecl sub_0043B840();                                                                                 // 0x0043B840
void __cdecl sub_0043B9A0();                                                                                // 0x0043B9A0
int __cdecl sub_0043BF60();                                                                    // 0x0043BF60
void __cdecl sub_0043C4F0();                                                                                // 0x0043C4F0
int __stdcall sub_004F91C0(D2WinControlStrc* pEditBox);                                                      // 0x004F91C0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength);                         // 0x004FDD50
void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext);                  // 0x004FDDD0
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FFE10
void __fastcall D2SOUND_10034(int nArg);                                                                    // 0x005148F0
int __cdecl sub_00514D80();                                                                                 // 0x00514D80
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

D2WinControlStrc* gpEdit_00779334;                                                                          // 0x00779334
D2WinControlStrc* gpEdit_0077958C;                                                                          // 0x0077958C
D2WinControlStrc* gpControl_00779594;                                                                       // 0x00779594
extern D2WinControlStrc* gpEdit_007795A8;                                                                   // 0x007795A8
extern int gnValue_00779980;                                                                                // 0x00779980
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0

static int s_bGatewayFlag_00779954; // 0x00779954

// 0x00435330
void __cdecl sub_00435330_ShowLoginScreen()
{
    char szAccount[0x400];
    s_bGatewayFlag_00779954 = 1;
    int bConnected = gpFuncTable_0077ABF0->pfnSlot68();
    if (bConnected && !sub_0043B840())
        goto create;
    if (bConnected)
        sub_0043B9A0();
    sub_004336C0();
    if (!sub_0043BF60())
        return;
create:
    gpEdit_0077958C = 0;
    gpEdit_00779334 = 0;
    gpEdit_007795A8 = 0;
    gpControl_00779594 = 0;
    sub_0043C4F0();
    sub_0042F430_CreateControl(0x15);
    sub_0042F430_CreateControl(0x16);
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x1A);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = sub_0042F430_CreateControl(0x1B);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1469));
    if (!sub_00408F20_HasExpansionMpq())
    {
        pControl = sub_0042F430_CreateControl(0x1F);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1454), 0, 0, 0);
    }
    pControl = sub_0042F430_CreateControl(0x20);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1455), 0, 0, 0);
    gpEdit_0077958C = sub_0042F430_CreateControl(0x22);
    sub_004FDD50_SetMaxLength(gpEdit_0077958C, 0x10);
    sub_004FDB00_SetEnterCallback(gpEdit_0077958C, sub_00433BE0_OnEnter);
    sub_004FDAD0_SetKeyCallback(gpEdit_0077958C, sub_0042FDE0_KeyFilter);
    gpEdit_00779334 = sub_0042F430_CreateControl(0x23);
    sub_004FDD50_SetMaxLength(gpEdit_00779334, 0xD);
    sub_004FDB00_SetEnterCallback(gpEdit_00779334, sub_00433BE0_OnEnter);
    sub_004FDAD0_SetKeyCallback(gpEdit_00779334, sub_0042FE60_KeyFilter);
    if (SRegLoadString("Diablo II", "Last BNet", 0, szAccount, 0x400))
    {
        sub_004FFE10_SetTextA(gpEdit_0077958C, szAccount);
        sub_004F91C0(gpEdit_00779334);
    }
    else
        sub_004F91C0(gpEdit_0077958C);
    sub_004FDDD0_LinkTab(gpEdit_0077958C, gpEdit_00779334);
    sub_004FDDD0_LinkTab(gpEdit_00779334, gpEdit_0077958C);
    sub_0042F430_CreateControl(0x24);
    sub_0042F430_CreateControl(0x25);
    gpControl_00779594 = sub_0042F430_CreateControl(0x26);
    sub_0042F430_CreateControl(0x27);
    sub_004306C0_UpdateOk();
    if (gnValue_00779980)
    {
        pControl = sub_0042F430_CreateControl(0x28);
        sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B62));
    }
    if (sub_00514D80())
        D2SOUND_10034(1);
}
