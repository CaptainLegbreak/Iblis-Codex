void __cdecl PANEL_SetBlackColour();                                                                                // 0x00499E30
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
extern int gnScreenWidth;                                                                               // 0x0071146C
extern int gnScreenHeight;                                                                               // 0x00711470
extern unsigned char gnHelpShadeColor;                                                                     // 0x007BEEF8
extern int gbHelpUiOpened;                                                                         // 0x007BEF00

// 0x00494EB0
void __cdecl sub_00494EB0()
{
    PANEL_SetBlackColour();
    AUTOMAP_DrawFramedBox(0, 0, gnScreenWidth, gnScreenHeight - 0x31, gnHelpShadeColor, 1);
}

