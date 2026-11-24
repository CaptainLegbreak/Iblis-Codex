#include "D2Client.h"

void __stdcall UI_DrawCelPair(int bFirst);                                                        // 0x0045FBC0
void __cdecl UI_DrawCenteredStrings();                                                            // 0x0045FFC0
void __stdcall VIEW_DrawPanelCels(int nFrame1, int nFrame2);                                        // 0x00460060
void __cdecl UI_DrawCenteredStringPair();                                                         // 0x004600F0
void __cdecl CURSOR_DrawCursor(); // 0x004684C0

extern int gbPopupOkPressed;                                                                               // 0x007A524C
extern int gbPopupCancelPressed;                                                                               // 0x007A5250

// 0x00460190
void __cdecl sub_00460190_DrawFrame()
{
    if (WINDOW_GetState())
        return;
    if (!D2GFX_StartDraw(1, 0, 0, 0))
        return;
    D2GFX_ClearScreen(0);
// build: symbol ?D2Win_10179_UpdatePaletteFlash@* 0x004FB0D0
    D2Win_10179_UpdatePaletteFlash();
    UI_DrawCelPair(0);
    UI_DrawCenteredStrings();
    VIEW_DrawPanelCels(gbPopupOkPressed, gbPopupCancelPressed);
    UI_DrawCenteredStringPair();
    CURSOR_DrawCursor();
    D2GFX_EndScene();
}
