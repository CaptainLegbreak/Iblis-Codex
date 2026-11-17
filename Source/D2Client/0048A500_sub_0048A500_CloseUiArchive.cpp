typedef unsigned char U8;
typedef unsigned int U32;
extern U8 gColor;
extern int gScreenHeight;
extern int gScreenWidth;
extern U32 gUiState; // 0x007BCBF0
void* gUiArchive;        // 0x007BCC30
extern void* gResourceA;
extern void* gResourceB;
void __cdecl InitializePalette();
void __fastcall sub_004F6300(int x, int y, int width, int height, int color, int mode);
void __cdecl sub_0048A050(); // 0x0048A050
void __fastcall sub_00478A00(void* archive); // 0x00478A00
int __stdcall ReleaseResource(void* resource);

void __cdecl sub_00494EB0_DrawUiRectangle()
{
    InitializePalette();
    sub_004F6300(0, 0, gScreenWidth, gScreenHeight - 49, gColor, 1);
}

// 0x0048A500
void __cdecl sub_0048A500_CloseUiArchive()
{
    if (gUiState == 14)
    {
        gUiState = 0;
        sub_0048A050();
    }
    if (gUiArchive)
    {
        sub_00478A00(gUiArchive);
        gUiArchive = 0;
    }
}

void __cdecl sub_005239C0_ReleaseResources()
{
    if (gResourceA)
    {
        ReleaseResource(gResourceA);
        gResourceA = 0;
    }
    if (gResourceB)
    {
        ReleaseResource(gResourceB);
        gResourceB = 0;
    }
}
