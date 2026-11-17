int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);   // 0x004F60F0
void __stdcall D2GFX_ClearScreen(int bPartial);                                                             // 0x004F63B0
void __fastcall sub_004FB0D0();                                                                             // 0x004FB0D0
void __stdcall sub_0045FBC0_DrawCelPair(int bFirst);                                                        // 0x0045FBC0
void __cdecl sub_0045FC60_DrawLoadingTexts();                                                               // 0x0045FC60
void __stdcall sub_0045FD20_DrawPanelCel(int nFrame);                                                       // 0x0045FD20
void __cdecl sub_0045FD80_DrawCenteredString();                                                             // 0x0045FD80
void __fastcall sub_004684C0();                                                                  // 0x004684C0
int __stdcall D2GFX_EndScene();                                                                             // 0x004F6190
extern int gnGlobal_007A524C;                                                                               // 0x007A524C

// 0x0045FDE0
void __cdecl sub_0045FDE0_DrawLoadingScreen()
{
    if (WINDOW_GetState())
        return;
    if (!D2GFX_StartDraw(1, 0, 0, 0))
        return;
    D2GFX_ClearScreen(0);
    sub_004FB0D0();
    sub_0045FBC0_DrawCelPair(1);
    sub_0045FC60_DrawLoadingTexts();
    sub_0045FD20_DrawPanelCel(gnGlobal_007A524C);
    sub_0045FD80_DrawCenteredString();
    sub_004684C0();
    D2GFX_EndScene();
}
