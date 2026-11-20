#include "D2Client.h"

struct D2CellFileStrc;

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

void __cdecl sub_00477DD0();                                                                                // 0x00477DD0
void __stdcall sub_0045FBC0_DrawCelPair(int bFirst);                                                        // 0x0045FBC0
void __cdecl sub_0045FC60_DrawLoadingTexts();                                                               // 0x0045FC60
void __stdcall sub_0045FD20_DrawPanelCel(int nFrame);                                                       // 0x0045FD20
void __cdecl sub_0045FD80_DrawCenteredString();                                                             // 0x0045FD80
void __cdecl sub_004684C0(); // 0x004684C0
void __cdecl sub_00482C20_Tick();                                                                           // 0x00482C20
void __fastcall sub_00460190_DrawFrame(int nUnused);                                                        // 0x00460190
D2CellFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                             // 0x004788B0
void __fastcall sub_0044C930_SetClientState(int nState);                                                    // 0x0044C930
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
int __fastcall sub_00451BB0_MessageLoop(int (__stdcall* pfnIdle)(int));                                     // 0x00451BB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __cdecl sub_00460430_FreeCels();                                                                       // 0x00460430

extern D2MsgHandlerEntryStrc gaMsgHandlers_00711D40[];                                                      // 0x00711D40
extern D2MsgHandlerEntryStrc gaMsgHandlers_00711D70[];                                                      // 0x00711D70
D2CellFileStrc* gpGlobal_007A523C;                                                                          // 0x007A523C
D2CellFileStrc* gpGlobal_007A5240;                                                                          // 0x007A5240
D2CellFileStrc* gpGlobal_007A5244;                                                                          // 0x007A5244
extern int gnGlobal_007A524C;                                                                               // 0x007A524C
int gnGlobal_007A5254;                                                                                      // 0x007A5254
int gnGlobal_007A5258;                                                                                      // 0x007A5258
int gnGlobal_007A525C;                                                                                      // 0x007A525C

// 0x00460420
void __stdcall sub_00460420_SetCancelFlag(int nArg)
{
    gnGlobal_007A525C = 1;
}

// 0x00460490
int __stdcall sub_00460490_DrawPopup(int nArg)
{
    sub_00477DD0();
    if (!WINDOW_GetState() && D2GFX_StartDraw(1, 0, 0, 0))
    {
        D2GFX_ClearScreen(0);
        sub_004FB0D0();
        sub_0045FBC0_DrawCelPair(1);
        sub_0045FC60_DrawLoadingTexts();
        sub_0045FD20_DrawPanelCel(gnGlobal_007A524C);
        sub_0045FD80_DrawCenteredString();
        sub_004684C0();
        D2GFX_EndScene();
    }
    sub_00482C20_Tick();
    return gnGlobal_007A5254 != 0;
}

// 0x00460500
int __cdecl sub_00460500_RunPopup()
{
    gnGlobal_007A5254 = 0;
    sub_004FB130_SetActiveState(0);
    gpGlobal_007A523C = sub_004788B0("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5244 = sub_004788B0("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5240 = sub_004788B0("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
    sub_0044C930_SetClientState(1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00711D40, 4);
    sub_00451BB0_MessageLoop(sub_00460490_DrawPopup);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00711D40, 4);
    sub_0044C930_SetClientState(0);
    sub_00460430_FreeCels();
    return 1;
}

// 0x004605A0
int __cdecl sub_004605A0_RunPopup()
{
    gnGlobal_007A5254 = 0;
    sub_004FB130_SetActiveState(0);
    gpGlobal_007A523C = sub_004788B0("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5244 = sub_004788B0("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5240 = sub_004788B0("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
    sub_0044C930_SetClientState(1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00711D40, 4);
    sub_00451BB0_MessageLoop(sub_00460490_DrawPopup);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00711D40, 4);
    sub_0044C930_SetClientState(0);
    sub_00460430_FreeCels();
    return 1;
}

// 0x00460640
int __stdcall sub_00460640_PaintConfirmFrame(int nArg)
{
    sub_00477DD0();
    sub_00460190_DrawFrame(1);
    sub_00482C20_Tick();
    if (!gnGlobal_007A5258 && !gnGlobal_007A525C)
        return 0;
    return 1;
}

// 0x00460680
int __cdecl sub_00460680_RunOkCancel()
{
    int nResult = 1;
    gnGlobal_007A525C = 0;
    gnGlobal_007A5258 = 0;
    sub_004FB130_SetActiveState(0);
    gpGlobal_007A523C = sub_004788B0("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5244 = sub_004788B0("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5240 = sub_004788B0("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
    sub_0044C930_SetClientState(2);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00711D70, 4);
    sub_00451BB0_MessageLoop(sub_00460640_PaintConfirmFrame);
    if (gnGlobal_007A525C)
        nResult = 0;
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00711D70, 4);
    sub_0044C930_SetClientState(0);
    sub_00460430_FreeCels();
    return nResult;
}

#include "gen/data/Source/D2Client/Unknown_00460420.inc"
