struct D2WinControlStrc;
struct D2WinAnimImageStrc;

void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);                         // 0x0042F2E0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
int __stdcall ANIMIMAGE_SetIsRunning(D2WinAnimImageStrc* pAnimImage, int bIsRunning);                       // 0x00500810

// 0x00430390
void __cdecl sub_00430390_CreateScreenControls()
{
    sub_0042F480_Reset();
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(6);
    ANIMIMAGE_SetIsRunning((D2WinAnimImageStrc*)pControl, 0);
    pControl = sub_0042F430_CreateControl(7);
    ANIMIMAGE_SetIsRunning((D2WinAnimImageStrc*)pControl, 0);
    sub_0042F430_CreateControl(8);
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
}
