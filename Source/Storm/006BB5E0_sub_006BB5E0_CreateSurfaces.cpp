extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall sub_006B3730_CreateSurface(void** ppSurface, void** ppTexture, int nWidth, int nHeight); // 0x006B3730
extern void* gpSurface_00989BF8; // 0x00989BF8
extern void* gpTexture_00989BFC; // 0x00989BFC
extern void* gpSurface_00989C00; // 0x00989C00
extern void* gpTexture_00989C04; // 0x00989C04
extern int gnWidth_0096F4DC; // 0x0096F4DC
extern int gnHeight_009702B8; // 0x009702B8

// 0x006BB5E0
void __cdecl sub_006BB5E0_CreateSurfaces()
{
    D2_ASSERT(sub_006B3730_CreateSurface(&gpSurface_00989BF8, &gpTexture_00989BFC, gnWidth_0096F4DC, gnHeight_009702B8), 0x27);
    D2_ASSERT(sub_006B3730_CreateSurface(&gpSurface_00989C00, &gpTexture_00989C04, 0x20, 0x20), 0x2A);
}
