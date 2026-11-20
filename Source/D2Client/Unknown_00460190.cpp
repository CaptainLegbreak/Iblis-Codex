#include "D2Client.h"

void __stdcall sub_0045FBC0_DrawCelPair(int bFirst);                                                        // 0x0045FBC0
void __cdecl sub_0045FFC0_DrawCenteredStrings();                                                            // 0x0045FFC0
void __stdcall sub_00460060_DrawPanelCels(int nFrame1, int nFrame2);                                        // 0x00460060
void __cdecl sub_004600F0_DrawCenteredStringPair();                                                         // 0x004600F0
void __cdecl sub_004684C0(); // 0x004684C0

extern int gnGlobal_007A524C;                                                                               // 0x007A524C
extern int gnGlobal_007A5250;                                                                               // 0x007A5250

// 0x00460190
void __cdecl sub_00460190_DrawFrame()
{
    if (WINDOW_GetState())
        return;
    if (!D2GFX_StartDraw(1, 0, 0, 0))
        return;
    D2GFX_ClearScreen(0);
    sub_004FB0D0();
    sub_0045FBC0_DrawCelPair(0);
    sub_0045FFC0_DrawCenteredStrings();
    sub_00460060_DrawPanelCels(gnGlobal_007A524C, gnGlobal_007A5250);
    sub_004600F0_DrawCenteredStringPair();
    sub_004684C0();
    D2GFX_EndScene();
}
