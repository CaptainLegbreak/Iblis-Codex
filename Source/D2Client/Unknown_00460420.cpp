#include "D2Client.h"
#include "D2ClientTypes.h"

struct D2CelFileStrc;


void __cdecl sub_00477DD0();                                                                                // 0x00477DD0
void __stdcall UI_DrawCelPair(int bFirst);                                                        // 0x0045FBC0
void __cdecl SCMD_DrawLoadingTexts();                                                               // 0x0045FC60
void __stdcall VIEW_DrawPanelCel(int nFrame);                                                       // 0x0045FD20
void __cdecl UI_DrawCenteredString();                                                             // 0x0045FD80
void __cdecl CURSOR_DrawCursor(); // 0x004684C0
void __cdecl INV_TickSound();                                                                           // 0x00482C20
void __fastcall sub_00460190_DrawFrame(int nUnused);                                                        // 0x00460190
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType);                             // 0x004788B0
void __fastcall GAME_SetClientState(int nState);                                                    // 0x0044C930
int __cdecl WINDOW_GetWindow();                                                                                // 0x004F59A0
void __fastcall COMCALLBACK_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
int __fastcall SCMD_RunMessageLoop(int (__stdcall* pfnIdle)(int));                                     // 0x00451BB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __cdecl UI_FreeCels();                                                                       // 0x00460430

extern D2MsgHandlerEntryStrc gaMsgHandlers_00711D40[];                                                      // 0x00711D40
extern D2MsgHandlerEntryStrc gaMsgHandlers_00711D70[];                                                      // 0x00711D70
D2CelFileStrc* gpGlobal_007A523C;                                                                          // 0x007A523C
D2CelFileStrc* gpGlobal_007A5240;                                                                          // 0x007A5240
D2CelFileStrc* gpGlobal_007A5244;                                                                          // 0x007A5244
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
        UI_DrawCelPair(1);
        SCMD_DrawLoadingTexts();
        VIEW_DrawPanelCel(gnGlobal_007A524C);
        UI_DrawCenteredString();
        CURSOR_DrawCursor();
        D2GFX_EndScene();
    }
    INV_TickSound();
    return gnGlobal_007A5254 != 0;
}

// 0x00460500
int __cdecl sub_00460500_RunPopup()
{
    gnGlobal_007A5254 = 0;
    sub_004FB130_SetActiveState(0);
    gpGlobal_007A523C = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5244 = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5240 = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
    GAME_SetClientState(1);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaMsgHandlers_00711D40, 4);
    SCMD_RunMessageLoop(sub_00460490_DrawPopup);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMsgHandlers_00711D40, 4);
    GAME_SetClientState(0);
    UI_FreeCels();
    return 1;
}

// 0x004605A0
int __cdecl sub_004605A0_RunPopup()
{
    gnGlobal_007A5254 = 0;
    sub_004FB130_SetActiveState(0);
    gpGlobal_007A523C = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5244 = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5240 = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
    GAME_SetClientState(1);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaMsgHandlers_00711D40, 4);
    SCMD_RunMessageLoop(sub_00460490_DrawPopup);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMsgHandlers_00711D40, 4);
    GAME_SetClientState(0);
    UI_FreeCels();
    return 1;
}

// 0x00460640
int __stdcall sub_00460640_PaintConfirmFrame(int nArg)
{
    sub_00477DD0();
    sub_00460190_DrawFrame(1);
    INV_TickSound();
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
    gpGlobal_007A523C = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5244 = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5240 = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
    GAME_SetClientState(2);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaMsgHandlers_00711D70, 4);
    SCMD_RunMessageLoop(sub_00460640_PaintConfirmFrame);
    if (gnGlobal_007A525C)
        nResult = 0;
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMsgHandlers_00711D70, 4);
    GAME_SetClientState(0);
    UI_FreeCels();
    return nResult;
}

#include "gen/data/Source/D2Client/Unknown_00460420.inc"
