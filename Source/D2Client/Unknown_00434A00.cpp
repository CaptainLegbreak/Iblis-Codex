#include "D2Client.h"

struct Unicode;
struct D2FuncTable_0077ABF0Strc;
struct D2LaunchCharSelectStrc;

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x19];
    int nState19;
    char unk0x01D[0x85 - 0x1D];
    unsigned char nFlag085;
    unsigned char nFlag086;
    unsigned char nFlag087;
    unsigned char nFlag088;
    unsigned char nFlag089;
    unsigned char nFlag08A;
    unsigned char nFlag08B;
    char unk0x08C[0xBD - 0x8C];
    char szGameName[0x18];
    char szPassword[0x18];
    char unk0x0ED[0x101];
    char nMode;
    unsigned short wFlags;
    char unk0x1F1[0x18];
    unsigned int dwFlags209;
    char unk0x20D[0x20];
    char nByte22D;
    char unk0x22E[0x130];
    char nByte35E;
};

#pragma pack(pop)
struct Unicode
{
    unsigned short wChar;
    Unicode();                                                                                              // 0x0042F530
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x68];
    int (__fastcall* pfnSlot68)();
};

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
int __stdcall sub_00431D10_ClearLoop(int nArg); // 0x00431D10
int __stdcall sub_00432FE0_OnReceiveB(int nArg); // 0x00432FE0
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00433380
int __cdecl sub_0043BF60(); // 0x0043BF60
int __fastcall sub_0043C180_Connect(D2LaunchRecordStrc* pRecord, int bFlag, int nMode); // 0x0043C180
int __cdecl sub_00449B30_QueryAddress(); // 0x00449B30
int __cdecl sub_00449C00(); // 0x00449C00
int __stdcall sub_00449E10_Forward1(const char* szName); // 0x00449E10
int __fastcall sub_004F9190(); // 0x004F9190
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
extern char gaGlobal_007089C4[]; // 0x007089C4
extern void* gpGlobal_0070B738; // 0x0070B738
extern int gnLaunchState_007795E8; // 0x007795E8
extern int gnLaunchMode_007795EC; // 0x007795EC
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0
static void sub_00431E70_SetModeFlags(char nMode); // 0x00431E70
int __stdcall sub_0042FDE0_KeyFilter(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x0042FDE0
int __stdcall sub_0042FE60_KeyFilter(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x0042FE60
void __cdecl sub_004306C0_UpdateOk(); // 0x004306C0
int __stdcall sub_00433BE0_UpdateOk(int nArg); // 0x00433BE0
int __cdecl sub_0043B840(); // 0x0043B840
int __stdcall sub_004F91C0(D2WinControlStrc* pEditBox); // 0x004F91C0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength); // 0x004FDD50
void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext); // 0x004FDDD0
int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10
extern int gnValue_00779980; // 0x00779980

#pragma pack(push, 1)
struct D2LaunchCharSelectStrc
{
    char unk0x000[0x1EF];
    unsigned short wFlags;
};

#pragma pack(pop)

int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
int __stdcall sub_00430590_FilterNameChar(D2WinControlStrc* pControl, int bAllowSep, const char* pChar); // 0x00430590
void __cdecl sub_00430620_UpdateNameOk(); // 0x00430620
void __cdecl sub_004326F0_LoadFrontEndCells2(); // 0x004326F0
int __stdcall sub_00433BD0_UpdateNameOk(int nArg); // 0x00433BD0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0
void __stdcall sub_004FA450(void* a1); // 0x004FA450
void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB); // 0x004FB740
extern "C" const char gszFecharPalDat_006D39E8[]; // 0x006D39E8
extern int gnGlobal_00708D0C; // 0x00708D0C
extern int gnGlobal_0070CB80; // 0x0070CB80
extern D2WinControlStrc* gpControl_00779330; // 0x00779330
extern D2WinControlStrc* gpControl_00779348; // 0x00779348
extern D2WinControlStrc* gpControl_00779568; // 0x00779568
extern D2WinControlStrc* gpControl_00779598; // 0x00779598
extern D2WinControlStrc* gpControl_007795B4; // 0x007795B4
extern D2WinControlStrc* gpControl_007795C8; // 0x007795C8
extern D2LaunchCharSelectStrc* gpCharSelect_007795D4; // 0x007795D4
extern D2WinControlStrc* gpControl_007795D8; // 0x007795D8
extern D2WinControlStrc* gpControl_007795DC; // 0x007795DC
const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinControlStrc*); // 0x004FDD90
int __fastcall sub_00526800(const Unicode*); // 0x00526800
extern D2WinControlStrc* gpControl_007799D4; // 0x007799D4

static __declspec(noinline) void sub_00431E70_SetModeFlags(char nMode)
{
    gpLaunchRecord_007795D4->nMode = nMode;
    gpLaunchRecord_007795D4->nFlag085 = 0;
    gpLaunchRecord_007795D4->nFlag089 = 0;
    gpLaunchRecord_007795D4->nFlag088 = 0;
    gpLaunchRecord_007795D4->nFlag086 = 0;
    gpLaunchRecord_007795D4->nFlag087 = 0;
    gpLaunchRecord_007795D4->nFlag08A = 0;
    gpLaunchRecord_007795D4->nFlag08B = 0;

    if (nMode == 0)
    {
        gpLaunchRecord_007795D4->nFlag085 = 1;
    }
    else if (nMode == 4)
    {
        gpLaunchRecord_007795D4->nFlag089 = 1;
    }
    else if (nMode == 2)
    {
        gpLaunchRecord_007795D4->nFlag088 = 1;
    }
    else if (nMode == 3)
    {
        gpLaunchRecord_007795D4->nFlag086 = 1;
    }
    else if (nMode == 1)
    {
        gpLaunchRecord_007795D4->nFlag087 = 1;
    }
    else if (nMode == 5)
    {
        gpLaunchRecord_007795D4->nFlag08A = 1;
    }
    else if (nMode == 6)
    {
        gpLaunchRecord_007795D4->nFlag08B = 1;
    }
}

// 0x00434A00
int __fastcall sub_00434A00_Join(const char* szGameName, unsigned short wFlags, char nMode, const char* szPassword)
{
    int bPassword = szPassword[0] != 0;
    strcpy(gpLaunchRecord_007795D4->szGameName, szGameName);
    strcpy(gpLaunchRecord_007795D4->szPassword, szPassword);
    gpLaunchRecord_007795D4->wFlags = wFlags;
    sub_00431E70_SetModeFlags(nMode);

    if (gnLaunchMode_007795EC == 1 || gnLaunchMode_007795EC == 3)
    {
        if (!gpFuncTable_0077ABF0->pfnSlot68())
        {
            sub_0043C4F0();
            if (!sub_0043BF60())
                return 0;
            if (!sub_0043C180_Connect(gpLaunchRecord_007795D4, 0, 0))
                return 0;
        }
    }

    if (gnLaunchMode_007795EC == 0)
    {
        gpLaunchRecord_007795D4->nByte35E = 1;
        gnLaunchState_007795E8 = 1;
        gpLaunchRecord_007795D4->nState19 = 0;
        gpLaunchRecord_007795D4->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord_007795D4->dwFlags209 = 0x804;
        if (gpLaunchRecord_007795D4->wFlags & 0x20)
            gpLaunchRecord_007795D4->dwFlags209 |= 0x100000;
        sub_004F9190();
        return 1;
    }

    if (gnLaunchMode_007795EC == 2)
    {
        gpLaunchRecord_007795D4->nByte35E = 3;
        gnLaunchState_007795E8 = 1;
        gpLaunchRecord_007795D4->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord_007795D4->dwFlags209 = 0x804;
        if (gpLaunchRecord_007795D4->wFlags & 0x20)
            gpLaunchRecord_007795D4->dwFlags209 |= 0x100000;
        sub_004F9190();
        return 1;
    }
    {
        int bNewGame;
        if (bPassword)
        {
            switch (sub_00432480(szPassword, 0))
            {
            case 1:
                return 0;
            case 2:
            {
                const Unicode* pText = D2LANG_GetStringFromTblIndex(0x145B);
                sub_00433380_ShowMessage(pText, sub_0042FDD0, 1);
                return 1;
            }
            }

            if (sub_00449C00())
            {
                D2MCPClientCloseMCP();
                int nString;
                switch (sub_00449C00())
                {
                case 2:
                    nString = 0x145B;
                    break;
                case 0x47:
                    nString = 0x145C;
                    break;
                default:
                    nString = 0x145B;
                    break;
                }
                const Unicode* pText = D2LANG_GetStringFromTblIndex(nString);
                sub_00433380_ShowMessage(pText, sub_0042FDD0, 1);
                return 1;
            }

            sub_00449E10_Forward1(gpLaunchRecord_007795D4->szGameName);
            sub_0042F6E0();
            sub_004FA590_RunLoop(sub_00432FE0_OnReceiveB);
            int nState = sub_00449C00();
            if (nState == 0x46 || !sub_00449B30_QueryAddress())
            {
                sub_0042F3F0_DestroyControls();
                const Unicode* pText = D2LANG_GetStringFromTblIndex(0x140D);
                sub_00433380_ShowMessage(pText, sub_0042FDD0, 1);
                return 0;
            }

            if (nState == 0x7B)
            {
                Unicode wszText[256];
                Unicode wszName[256];
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord_007795D4->szGameName, 256);
                D2MCPClientCloseMCP();
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszName);
                sub_0042F3F0_DestroyControls();
                void* pSaved = gpGlobal_0070B738;
                gpGlobal_0070B738 = gaGlobal_007089C4;
                sub_00433380_ShowMessage(wszText, sub_0042FDD0, 1);
                gpGlobal_0070B738 = pSaved;
                return 0;
            }

            if (gdwGlobal_00779974)
            {
                sub_0042F3F0_DestroyControls();
                return 0;
            }

            bNewGame = 0;
        }
        else
        {
            gpLaunchRecord_007795D4->nByte22D = 0;
            gpLaunchRecord_007795D4->szPassword[0] = 0;
            bNewGame = 1;
        }

        if (!bNewGame)
        {
            gpLaunchRecord_007795D4->nByte35E = 2;
        }
        else
        {
            gpLaunchRecord_007795D4->nByte35E = 4;
            gpLaunchRecord_007795D4->dwFlags209 = 4;
            if (wFlags & 4)
                gpLaunchRecord_007795D4->dwFlags209 = 0x804;
            if (gpLaunchRecord_007795D4->wFlags & 0x20)
                gpLaunchRecord_007795D4->dwFlags209 |= 0x100000;
        }

        gnLaunchState_007795E8 = 3;
        sub_0042F6E0();
        sub_004FA590_RunLoop(sub_00431D10_ClearLoop);
        sub_004F9190();
        return 1;
    }
}

#include "gen/data/Source/D2Client/Unknown_00434A00.inc"
struct D2WinControlStrc;

D2WinControlStrc* gpEdit_00779334; // 0x00779334

D2WinControlStrc* gpEdit_0077958C; // 0x0077958C

D2WinControlStrc* gpControl_00779594; // 0x00779594

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
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = sub_0042F430_CreateControl(0x1B);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1469));
    if (!sub_00408F20_HasExpansionMpq())
    {
        pControl = sub_0042F430_CreateControl(0x1F);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1454), 0, 0, 0);
    }
    pControl = sub_0042F430_CreateControl(0x20);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1455), 0, 0, 0);
    gpEdit_0077958C = sub_0042F430_CreateControl(0x22);
    sub_004FDD50_SetMaxLength(gpEdit_0077958C, 0x10);
    sub_004FDB00_SetEnterCallback(gpEdit_0077958C, sub_00433BE0_UpdateOk);
    sub_004FDAD0_SetKeyCallback(gpEdit_0077958C, sub_0042FDE0_KeyFilter);
    gpEdit_00779334 = sub_0042F430_CreateControl(0x23);
    sub_004FDD50_SetMaxLength(gpEdit_00779334, 0xD);
    sub_004FDB00_SetEnterCallback(gpEdit_00779334, sub_00433BE0_UpdateOk);
    sub_004FDAD0_SetKeyCallback(gpEdit_00779334, sub_0042FE60_KeyFilter);
    if (SRegLoadString("Diablo II", "Last BNet", 0, szAccount, 0x400))
    {
        D2Win_10076(gpEdit_0077958C, szAccount);
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
        D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B62));
    }
    if (sub_00514D80())
        D2SOUND_10034(1);
}

D2WinControlStrc* gpControl_0077933C; // 0x0077933C

D2WinControlStrc* gpControl_0077934C; // 0x0077934C

D2WinControlStrc* gpControl_0077956C; // 0x0077956C

D2WinControlStrc* gpControl_00779570; // 0x00779570

D2WinControlStrc* gpControl_00779574; // 0x00779574

D2WinControlStrc* gpControl_00779578; // 0x00779578

D2WinControlStrc* gpControl_0077957C; // 0x0077957C

D2WinControlStrc* gpControl_00779580; // 0x00779580

D2WinControlStrc* gpControl_00779584; // 0x00779584

D2WinControlStrc* gpControl_007795B0; // 0x007795B0

D2WinControlStrc* gpControl_007795B8; // 0x007795B8

D2WinControlStrc* gpControl_007795C4; // 0x007795C4

D2WinControlStrc* gpControl_007795CC; // 0x007795CC

int gnGlobal_00779DA4; // 0x00779DA4

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

    if (gnLaunchMode_007795EC == 1)
    {
        gpControl_0077933C = sub_0042F430_CreateControl(0xC7);
        sub_004FB740(gpControl_0077933C, -6, 0);
        sub_004FC9B0_SetText(gpControl_0077933C, D2LANG_GetStringFromTblIndex(0x2B87), 1, 0, 0);
        sub_004FC9B0_SetText(gpControl_0077933C, D2LANG_GetStringFromTblIndex(0x2B88), 1, 0, 0);
    }

    sub_004FA450(sub_0042F430_CreateControl(0xAF));
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
        if (gnLaunchMode_007795EC == 1)
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
        if (gnLaunchMode_007795EC == 1)
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

    if (gnLaunchMode_007795EC == 1)
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
    if (gnLaunchMode_007795EC == 1)
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

// 0x00436CF0
void __cdecl sub_00436CF0()
{
 const Unicode* pText1=D2Win_10077_EDITBOX_GetText(gpEdit_007799CC);
 const Unicode* pText2=D2Win_10077_EDITBOX_GetText(gpEdit_007799D0);
 int bOk=sub_00526800(pText1)>0;
 bOk|=sub_00526800(pText2)>0;
 sub_004F96F0_ControlClearState(gpControl_007799D4,bOk);
}
