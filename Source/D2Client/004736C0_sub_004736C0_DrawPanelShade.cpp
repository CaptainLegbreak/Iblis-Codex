struct CellResource;
extern int gScreenWidth; // 0x0071146C
extern int gScreenHeight; // 0x00711470
extern CellResource* gHelpBorder;
extern CellResource* gWhiteBullet;
extern CellResource* gYellowBullet;
extern "C" int __cdecl sub_0045AE90(); // 0x0045AE90
extern "C" void __stdcall sub_004F6300(int x1, int y1, int x2, int y2, int color, int mode); // 0x004F6300
extern "C" int __cdecl ResolutionMode();
extern "C" void __fastcall ReleaseCell(CellResource* resource);
extern "C" CellResource* __fastcall LoadCell(const char* filename);
extern "C" const char gHelpBorder800File[];
extern "C" const char gHelpBorderFile[];
extern "C" const char gWhiteBulletFile[];
extern "C" const char gYellowBulletFile[];

// 0x004736C0
extern "C" void __cdecl sub_004736C0_DrawPanelShade()
{
    int left = 0;
    int bottom = gScreenHeight - 47;
    int right = gScreenWidth;
    switch (sub_0045AE90())
    {
    case 1:
        right -= (gScreenWidth / 4) * 2;
        break;
    case 2:
        left = (gScreenWidth / 4) * 2;
        break;
    }
    sub_004F6300(left, 0, right, bottom, 255, 5);
}
