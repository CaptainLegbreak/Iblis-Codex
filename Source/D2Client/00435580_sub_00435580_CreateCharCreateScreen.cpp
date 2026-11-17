struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

#pragma pack(push, 1)
struct D2LaunchCharSelectStrc
{
    char unk0x000[0x1EF];
    unsigned short wFlags;
};
#pragma pack(pop)

int __cdecl sub_00408F20_HasExpansionMpq(); // 0x00408F20
void __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId); // 0x0042F430
void __cdecl sub_0042F480_Reset(); // 0x0042F480
int __stdcall sub_00430590_FilterNameChar(D2WinControlStrc* pControl, int bAllowSep, const char* pChar); // 0x00430590
void __cdecl sub_00430620_UpdateNameOk(); // 0x00430620
void __cdecl sub_004326F0_LoadFrontEndCells2(); // 0x004326F0
int __stdcall sub_00433BD0_UpdateNameOk(int nArg); // 0x00433BD0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet); // 0x004F9740
void __stdcall sub_004FA450_SetActive(D2WinControlStrc* pControl); // 0x004FA450
void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB); // 0x004FB740
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength); // 0x004FDD50
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern "C" const char gszFecharPalDat_006D39E8[]; // 0x006D39E8
extern int gnGlobal_00708D0C; // 0x00708D0C
extern int gnGlobal_0070CB80; // 0x0070CB80
extern D2WinControlStrc* gpControl_00779330; // 0x00779330
D2WinControlStrc* gpControl_0077933C;        // 0x0077933C
extern D2WinControlStrc* gpControl_00779348; // 0x00779348
D2WinControlStrc* gpControl_0077934C;        // 0x0077934C
extern D2WinControlStrc* gpControl_00779568; // 0x00779568
D2WinControlStrc* gpControl_0077956C;        // 0x0077956C
D2WinControlStrc* gpControl_00779570;        // 0x00779570
D2WinControlStrc* gpControl_00779574;        // 0x00779574
D2WinControlStrc* gpControl_00779578;        // 0x00779578
D2WinControlStrc* gpControl_0077957C;        // 0x0077957C
D2WinControlStrc* gpControl_00779580;        // 0x00779580
D2WinControlStrc* gpControl_00779584;        // 0x00779584
extern D2WinControlStrc* gpControl_00779598; // 0x00779598
D2WinControlStrc* gpControl_007795B0;        // 0x007795B0
extern D2WinControlStrc* gpControl_007795B4; // 0x007795B4
D2WinControlStrc* gpControl_007795B8;        // 0x007795B8
D2WinControlStrc* gpControl_007795C4;        // 0x007795C4
extern D2WinControlStrc* gpControl_007795C8; // 0x007795C8
D2WinControlStrc* gpControl_007795CC;        // 0x007795CC
extern D2LaunchCharSelectStrc* gpCharSelect_007795D4; // 0x007795D4
extern D2WinControlStrc* gpControl_007795D8; // 0x007795D8
extern D2WinControlStrc* gpControl_007795DC; // 0x007795DC
extern int gnScreenMode_007795EC; // 0x007795EC
int gnGlobal_00779DA4;        // 0x00779DA4

// 0x00435580
void __cdecl sub_00435580_CreateCharCreateScreen()
{
    sub_004326F0_LoadFrontEndCells2();
    sub_0042F480_Reset();
    gnGlobal_00708D0C = -1;
    gnGlobal_0070CB80 = -1;
    gpCharSelect_007795D4->wFlags = 0;
    sub_0042F2E0_ReadPaletteFiles(gszFecharPalDat_006D39E8, "palette\\fechar\\pal.pl2");

    sub_0042F430_CreateControl(0xB1);
    gpControl_007795D8 = sub_0042F430_CreateControl(0xC5);
    gpControl_007795DC = sub_0042F430_CreateControl(0xC6);
    D2WinControlStrc* pTitle = sub_0042F430_CreateControl(0xAE);
    sub_004FC9B0_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x1407), 0, 0, 0);

    if (gnScreenMode_007795EC == 1)
    {
        gpControl_0077933C = sub_0042F430_CreateControl(0xC7);
        sub_004FB740(gpControl_0077933C, -6, 0);
        sub_004FC9B0_SetText(gpControl_0077933C, D2LANG_GetStringFromTblIndex(0x2B87), 1, 0, 0);
        sub_004FC9B0_SetText(gpControl_0077933C, D2LANG_GetStringFromTblIndex(0x2B88), 1, 0, 0);
    }

    sub_004FA450_SetActive(sub_0042F430_CreateControl(0xAF));
    gpControl_00779598 = sub_0042F430_CreateControl(0xC8);
    gpControl_007795CC = sub_0042F430_CreateControl(0xC9);
    sub_004FC9B0_SetText(gpControl_007795CC, D2LANG_GetStringFromTblIndex(0x1405), 4, 0, 0);
    gpControl_0077934C = sub_0042F430_CreateControl(0xCC);
    sub_004FDD50_SetMaxLength(gpControl_0077934C, 0x10);
    sub_004FDAD0_SetKeyCallback(gpControl_0077934C, sub_00430590_FilterNameChar);
    sub_004FDB00_SetEnterCallback(gpControl_0077934C, sub_00433BD0_UpdateNameOk);

    if (sub_00408F20_HasExpansionMpq())
    {
        gpControl_00779568 = sub_0042F430_CreateControl(0xD3);
        sub_004FC9B0_SetText(gpControl_00779568, D2LANG_GetStringFromTblIndex(0x58CB), 4, 0, 0);
        sub_004F9740_SetControlState(gpControl_00779568, 0);
        gpControl_007795C8 = sub_0042F430_CreateControl(0xD4);
        sub_004F9740_SetControlState(gpControl_007795C8, 0);
        gpControl_007795B4 = sub_0042F430_CreateControl(0xD5);
        sub_004F9740_SetControlState(gpControl_007795B4, 0);
        gpControl_007795B0 = sub_0042F430_CreateControl(0xBD);
        sub_004FC9B0_SetText(gpControl_007795B0, D2LANG_GetStringFromTblIndex(0x1406), 4, 0, 0);
        gpControl_007795C4 = sub_0042F430_CreateControl(0xBE);
        if (gnScreenMode_007795EC == 1)
        {
            if (gnGlobal_00779DA4)
            {
                gpControl_007795B8 = sub_0042F430_CreateControl(0xC3);
                gpControl_00779348 = sub_0042F430_CreateControl(0xC4);
            }
            else
            {
                gpControl_007795B8 = sub_0042F430_CreateControl(0xC1);
                gpControl_00779348 = sub_0042F430_CreateControl(0xC2);
            }
        }
    }
    else
    {
        gpControl_007795B0 = sub_0042F430_CreateControl(0xCA);
        sub_004FC9B0_SetText(gpControl_007795B0, D2LANG_GetStringFromTblIndex(0x1406), 4, 0, 0);
        gpControl_007795C4 = sub_0042F430_CreateControl(0xCB);
        if (gnScreenMode_007795EC == 1)
        {
            if (gnGlobal_00779DA4)
            {
                gpControl_007795B8 = sub_0042F430_CreateControl(0xC1);
                gpControl_00779348 = sub_0042F430_CreateControl(0xC2);
            }
            else
            {
                gpControl_007795B8 = sub_0042F430_CreateControl(0xBF);
                gpControl_00779348 = sub_0042F430_CreateControl(0xC0);
            }
        }
    }

    if (gnScreenMode_007795EC == 1)
    {
        sub_004FC9B0_SetText(gpControl_007795B8, D2LANG_GetStringFromTblIndex(0x2AAF), 4, 0, 0);
    }

    gpControl_00779330 = sub_0042F430_CreateControl(0xB0);
    if (!gnGlobal_00779DA4)
    {
        sub_004F96F0_ControlClearState(gpControl_007795C4, 0);
        sub_004F96F0_ControlClearState(gpControl_007795B0, 0);
    }

    sub_004F9740_SetControlState(gpControl_00779598, 0);
    sub_004F9740_SetControlState(gpControl_007795CC, 0);
    sub_004F9740_SetControlState(gpControl_007795B0, 0);
    sub_004F9740_SetControlState(gpControl_007795C4, 0);
    sub_004F9740_SetControlState(gpControl_0077934C, 0);
    sub_004F9740_SetControlState(gpControl_00779330, 0);
    if (gnScreenMode_007795EC == 1)
    {
        sub_004F9740_SetControlState(gpControl_007795B8, 0);
        sub_004F9740_SetControlState(gpControl_00779348, 0);
    }

    gpControl_0077956C = sub_0042F430_CreateControl(0xB6);
    if (sub_00408F20_HasExpansionMpq())
    {
        gpControl_00779578 = sub_0042F430_CreateControl(0xBA);
        gpControl_0077957C = sub_0042F430_CreateControl(0xBB);
        gpControl_00779570 = sub_0042F430_CreateControl(0xB5);
        gpControl_00779584 = sub_0042F430_CreateControl(0xD1);
        gpControl_00779574 = sub_0042F430_CreateControl(0xBC);
        gpControl_00779580 = sub_0042F430_CreateControl(0xD2);
        sub_0042F430_CreateControl(0xB2);
    }
    else
    {
        gpControl_00779570 = sub_0042F430_CreateControl(0xB5);
        gpControl_00779578 = sub_0042F430_CreateControl(0xB7);
        gpControl_00779574 = sub_0042F430_CreateControl(0xB4);
        gpControl_0077957C = sub_0042F430_CreateControl(0xB8);
        sub_0042F430_CreateControl(0xB3);
    }

    sub_00430620_UpdateNameOk();
}
