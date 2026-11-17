typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;
struct Unit;
typedef void (__fastcall *UnitCallback)(Unit*);
extern U32 gUiState; // 0x007BCBF0
extern U32 gSelectionState; // 0x007BCC50
U32 gButtonA;        // 0x007BCE30
U32 gButtonB;        // 0x007BCE34
U32 gPressedFrame;        // 0x007BCE38
U32 gButtonLatch;        // 0x007BCE3C
void* gArchiveA;        // 0x007BCC2C
void* gArchiveB;        // 0x007BCC3C
extern U8 gPaletteA;
extern U8 gPaletteB;
extern U8 gPaletteC;
extern U8 gPaletteD;
int __fastcall sub_00455F20(U32 id, U32 state, U32 flags); // 0x00455F20
void __fastcall sub_004649D0(UnitCallback callback); // 0x004649D0
void __fastcall sub_00489DA0(Unit* unit); // 0x00489DA0
void __cdecl sub_0044DA40(); // 0x0044DA40
void __fastcall sub_00478A00(void* archive); // 0x00478A00
U32 __stdcall PaletteColor(U32 red, U32 green, U32 blue);
void __fastcall sub_00478600(U8 command, U16 value, U32 word2, U32 word3); // 0x00478600

// 0x00489E00
void __cdecl sub_00489E00_OpenUi()
{
    if (sub_00455F20(25, 0, 0))
    {
        gSelectionState = 0;
        sub_004649D0(sub_00489DA0);
        gUiState = 12;
        sub_0044DA40();
        gButtonA = 0;
        gButtonB = 0;
        gPressedFrame = 0;
        gButtonLatch = 0;
    }
}

// 0x00489F50
void __cdecl sub_00489F50_CloseUiArchives()
{
    if (gUiState == 12 || gUiState == 13)
    {
        gUiState = 0;
        sub_00455F20(25, 1, 0);
    }
    if (gArchiveA)
    {
        sub_00478A00(gArchiveA);
        gArchiveA = 0;
    }
    if (gArchiveB)
    {
        sub_00478A00(gArchiveB);
        gArchiveB = 0;
    }
}

// 0x00489EE0
void __cdecl sub_00489EE0_CloseUiAndSend()
{
    if (gUiState == 12 || gUiState == 13)
    {
        gUiState = 0;
        sub_00455F20(25, 1, 0);
        sub_00478600(79, 18, 0, 0);
    }
    if (gArchiveA)
    {
        sub_00478A00(gArchiveA);
        gArchiveA = 0;
    }
    if (gArchiveB)
    {
        sub_00478A00(gArchiveB);
        gArchiveB = 0;
    }
}

// build: context sub_004972B0_InitializePalette
void __cdecl sub_004972B0_InitializePalette()
{
    gPaletteA = (U8)PaletteColor(128, 0, 0);
    gPaletteB = (U8)PaletteColor(0, 128, 0);
    gPaletteC = (U8)PaletteColor(0, 0, 128);
    gPaletteD = (U8)PaletteColor(128, 128, 0);
}
