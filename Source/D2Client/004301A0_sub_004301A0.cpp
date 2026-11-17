struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

struct D2LaunchRecordStrc
{
    char unk0x000[0x8D];
    char szAccount[0x18];
    char szPassword[0x100];
};

extern D2WinControlStrc* gpEdit_0077958C;                                                                   // 0x0077958C
extern D2WinControlStrc* gpEdit_00779334;                                                                   // 0x00779334
D2WinControlStrc* gpEdit_007795A8;                                                                          // 0x007795A8
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __stdcall sub_0042FE70_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar);          // 0x0042FE70
int __stdcall sub_0042FF00_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar);          // 0x0042FF00
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
void __cdecl sub_0043C4F0();                                                                                // 0x0043C4F0
int __stdcall sub_004F91C0(void* pEditBox);                                                                  // 0x004F91C0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength);                         // 0x004FDD50
void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext);                  // 0x004FDDD0
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FFE10
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

// 0x004301A0
void __cdecl sub_004301A0()
{
    sub_0043C4F0();
    sub_0042F430_CreateControl(0x15);
    sub_0042F430_CreateControl(0x16);
    sub_0042F430_CreateControl(0x17);
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x1A);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = sub_0042F430_CreateControl(0x1B);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1469));
    pControl = sub_0042F430_CreateControl(0x1C);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2A52));
    if (!sub_00408F20_HasExpansionMpq())
    {
        pControl = sub_0042F430_CreateControl(0x1F);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1466), 0, 0, 0);
    }

    pControl = sub_0042F430_CreateControl(0x20);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1467), 0, 0, 0);

    gpEdit_0077958C = sub_0042F430_CreateControl(0x54);
    sub_004FDAD0_SetKeyCallback(gpEdit_0077958C, sub_0042FE70_FilterChar);
    sub_004FDD50_SetMaxLength(gpEdit_0077958C, 0x10);
    sub_004FFE10_SetTextA(gpEdit_0077958C, gpLaunchRecord_007795D4->szAccount);

    gpEdit_00779334 = sub_0042F430_CreateControl(0x55);
    sub_004FDAD0_SetKeyCallback(gpEdit_00779334, sub_0042FF00_FilterChar);
    sub_004FDD50_SetMaxLength(gpEdit_00779334, 0x0D);
    sub_004FFE10_SetTextA(gpEdit_00779334, gpLaunchRecord_007795D4->szPassword);

    gpEdit_007795A8 = sub_0042F430_CreateControl(0x56);
    sub_004FDD50_SetMaxLength(gpEdit_007795A8, 0x0D);

    if (gpLaunchRecord_007795D4->szAccount[0])
    {
        if (gpLaunchRecord_007795D4->szPassword[0])
        {
            sub_004F91C0(gpEdit_007795A8);
        }
        else
        {
            sub_004F91C0(gpEdit_00779334);
        }
    }
    else
    {
        sub_004F91C0(gpEdit_0077958C);
    }

    sub_004FDDD0_LinkTab(gpEdit_0077958C, gpEdit_00779334);
    sub_004FDDD0_LinkTab(gpEdit_00779334, gpEdit_007795A8);
    sub_004FDDD0_LinkTab(gpEdit_007795A8, gpEdit_0077958C);
    sub_0042F430_CreateControl(0x57);
    sub_0042F430_CreateControl(0x58);
}
