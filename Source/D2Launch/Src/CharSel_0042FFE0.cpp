#include "D2Launch.h"
#include "D2Unicode.h"

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_0042FF20_ShowLocalAddress();                                                                                // 0x0042FF20
int __cdecl sub_00430A20_FreeSlots();                                                                       // 0x00430A20
void __cdecl sub_00436CF0();                                                                                // 0x00436CF0
int __stdcall sub_00436D40_Callback(int nArg);                                                                       // 0x00436D40
void __cdecl sub_0043B9A0();                                                                                // 0x0043B9A0
void __cdecl sub_0043C4F0();                                                                                // 0x0043C4F0
void __cdecl sub_0043DB20_DestroyControls();                                                                // 0x0043DB20
void __cdecl sub_0043EA20_Wait();                                                                           // 0x0043EA20
void __cdecl sub_00443220_DestroyControls();                                                                                // 0x00443220
int __cdecl sub_00444E20();                                                                                 // 0x00444E20
int __stdcall sub_004F91C0(void* pEditBox);                                                                  // 0x004F91C0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern D2WinControlStrc* gpControl_00779338;                                                                // 0x00779338
extern D2WinControlStrc* gpControl_00779344;                                                                // 0x00779344
extern D2WinControlStrc* gpControl_00779588;                                                                // 0x00779588
extern D2WinControlStrc* gpControl_007795A0;                                                                // 0x007795A0
extern D2WinControlStrc* gpControl_007795A4;                                                                // 0x007795A4
D2WinControlStrc* gpControl_007795E0;                                                                       // 0x007795E0
D2WinControlStrc* gpControl_007795E4;                                                                       // 0x007795E4
extern int gbGatewayFlag_00779954;                                                                          // 0x00779954
D2WinControlStrc* gpEdit_007799CC;                                                                          // 0x007799CC
D2WinControlStrc* gpEdit_007799D0;                                                                          // 0x007799D0
D2WinControlStrc* gpControl_007799D4;                                                                       // 0x007799D4
extern int gdwGlobal_007799D8;                                                                              // 0x007799D8
extern D2CharSelCacheStrc* gpCharSelCache_00779DE8;                                                         // 0x00779DE8
extern D2WinControlStrc* gpControlMain_0077BC4C;                                                            // 0x0077BC4C
extern D2WinControlStrc* gpList_0077BD00;                                                                   // 0x0077BD00
D2WinControlStrc* gpControl_0077BD90;                                                                       // 0x0077BD90
extern D2WinControlStrc* gpWaitText_0077BD9C;                                                               // 0x0077BD9C
extern int gdwGlobal_00798CC0;                                                                              // 0x00798CC0

// 0x0042FFE0
void __cdecl sub_0042FFE0_CreateScreen()
{
    gbGatewayFlag_00779954 = 1;
    sub_0043B9A0();
    sub_0042F480_Reset();
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    sub_0042F430_CreateControl(0x102);
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x103);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x13FD));
    gpControl_00779338 = sub_0042F430_CreateControl(0x104);
    sub_004FD060_SetText(gpControl_00779338, D2LANG_GetStringFromTblIndex(0x1401));
    gpControl_007795A4 = sub_0042F430_CreateControl(0x106);
    gpControl_007795A0 = sub_0042F430_CreateControl(0x107);
    gpControl_007795E0 = sub_0042F430_CreateControl(0x108);
    sub_004FD060_SetText(gpControl_007795E0, D2LANG_GetStringFromTblIndex(0x1402));
    gpControl_007795E4 = sub_0042F430_CreateControl(0x109);
    sub_004FD060_SetText(gpControl_007795E4, D2LANG_GetStringFromTblIndex(0x1403));
    sub_004F9740_ControlSetState(gpControl_007795E0, 0);
    sub_004F9740_ControlSetState(gpControl_007795E4, 0);
    sub_004FA450_SetActive(sub_0042F430_CreateControl(0x10A));
    gpControl_00779344 = sub_0042F430_CreateControl(0x10B);
    sub_004FD830(gpControl_00779344);
    sub_004FDA50(gpControl_00779344);
    gpControl_00779588 = sub_0042F430_CreateControl(0x105);
    sub_0042FF20_ShowLocalAddress();
}

// 0x00436D50
void __cdecl sub_00436D50_CreateScreen()
{
    gdwGlobal_007799D8 = 0;
    sub_0043C4F0();
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x122);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B55), 0, 0, 0);
    pControl = sub_0042F430_CreateControl(0x123);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B56), 0, 0, 0);
    sub_0042F430_CreateControl(0x120);
    pControl = sub_0042F430_CreateControl(0x124);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B57));
    gpEdit_007799CC = sub_0042F430_CreateControl(0x126);
    sub_004FDB00_SetEnterCallback(gpEdit_007799CC, sub_00436D40_Callback);
    sub_0042F430_CreateControl(0x121);
    pControl = sub_0042F430_CreateControl(0x125);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B58));
    gpEdit_007799D0 = sub_0042F430_CreateControl(0x127);
    sub_004FDB00_SetEnterCallback(gpEdit_007799D0, sub_00436D40_Callback);
    gpControl_007799D4 = sub_0042F430_CreateControl(0x128);
    sub_0042F430_CreateControl(0x129);
    sub_0042F430_CreateControl(0x12A);
    sub_004F91C0(gpEdit_007799CC);
    sub_004FDDD0_LinkTab(gpEdit_007799CC, gpEdit_007799D0);
    sub_004FDDD0_LinkTab(gpEdit_007799D0, gpEdit_007799CC);
    sub_00436CF0();
}

// 0x00437B90
void __cdecl sub_00437B90_FreeCache()
{
    D2CharSelCacheStrc* pEntry = gpCharSelCache_00779DE8;
    while (pEntry)
    {
        D2CharSelCacheStrc* pNext = pEntry->pNext;
        SMemFree(pEntry->pData, ".\\Src\\CharSel.cpp", 0x10C, 0);
        SMemFree(pEntry, ".\\Src\\CharSel.cpp", 0x10D, 0);
        pEntry = pNext;
    }
    gpCharSelCache_00779DE8 = 0;
    sub_00430A20_FreeSlots();
}

// 0x0043F8C0
void __cdecl sub_0043F8C0_ResetLaunchState()
{
    sub_00443220_DestroyControls();
    sub_00443130_Reset();
    sub_0043DB20_DestroyControls();
    sub_0043EA20_Wait();
    sub_00443E10();
    gpList_0077BD00 = 0;
    sub_004F95C0_ControlDestroy(&gpWaitText_0077BD9C);
    sub_004F95C0_ControlDestroy(&gpControl_0077BD90);
    if (gdwGlobal_00798CC0 == 1)
        sub_00444E20();
    if (gnLaunchMode_0077BBE4 == 3)
        gnLaunchMode_0077BBE4 = 0;
    if (gpControlMain_0077BC4C)
        sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 1);
}
