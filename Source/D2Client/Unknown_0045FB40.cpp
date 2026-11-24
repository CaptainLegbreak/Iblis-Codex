#include "D2Client.h"

struct D2CelFileStrc;

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0
extern D2CelFileStrc* gpPopupOkCelA; // 0x007A523C
extern D2CelFileStrc* gpOkCancelButtonCel; // 0x007A5240
extern D2CelFileStrc* gpPopupOkCelB; // 0x007A5244
void __stdcall UI_DrawCelPair(int bFirst); // 0x0045FBC0
void __cdecl SCMD_DrawLoadingTexts(); // 0x0045FC60
void __stdcall VIEW_DrawPanelCel(int nFrame); // 0x0045FD20
void __cdecl UI_DrawCenteredString(); // 0x0045FD80
void __cdecl CURSOR_DrawCursor(); // 0x004684C0
extern int gbPopupOkPressed; // 0x007A524C

// 0x0045FB40
void __cdecl sub_0045FB40_LoadPopupCels()
{
    gpPopupOkCelA = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpPopupOkCelB = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpOkCancelButtonCel = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
}

// 0x0045FDE0
void __cdecl sub_0045FDE0_DrawLoadingScreen()
{
    if (WINDOW_GetState())
        return;
    if (!D2GFX_StartDraw(1, 0, 0, 0))
        return;
    D2GFX_ClearScreen(0);
// build: symbol ?D2Win_10179_UpdatePaletteFlash@* 0x004FB0D0
    D2Win_10179_UpdatePaletteFlash();
    UI_DrawCelPair(1);
    SCMD_DrawLoadingTexts();
    VIEW_DrawPanelCel(gbPopupOkPressed);
    UI_DrawCenteredString();
    CURSOR_DrawCursor();
    D2GFX_EndScene();
}
