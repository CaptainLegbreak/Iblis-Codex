#include "D2DDraw.h"
#include "D2Win32Types.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct T004013C0;

struct T004013C0
{
    int unk0x00;
    int nPlatform;
    char unk0x08[0x04];
    unsigned int nTotalMemory;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
T004013C0* __cdecl sub_00407360_GetSystemInfo(); // 0x00407360
int __stdcall SRegLoadData(const char* szKeyName, const char* szValueName, unsigned int nFlags, void* pBuffer, unsigned int nBufferSize, unsigned int* pnBytesRead); // 0x00414DE0
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50
extern unsigned char gabDDrawDeviceGuid_00881144[16]; // 0x00881144

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void __fastcall sub_006BE190_BuildGammaTable(int nGamma, void* pTable, double dScale, int nArg, int nEntries, int nMask); // 0x006BE190
extern tagPALETTEENTRY gaDDrawPalette_007C8CC8[256]; // 0x007C8CC8

unsigned long gdwVideoFlags_00881140; // 0x00881140

char gszDDrawDeviceName_00881154[256]; // 0x00881154

int gbDDrawPlatformFlag_0088125C; // 0x0088125C


tagPALETTEENTRY gaDDrawSavedPalette_00880D40[256]; // 0x00880D40

int gbPaletteDirty_00881298; // 0x00881298

// 0x00510160
void __fastcall sub_00510160_DDrawSetPalette(tagPALETTEENTRY* pPalette)
{
    memcpy(gaDDrawSavedPalette_00880D40, pPalette, sizeof(gaDDrawSavedPalette_00880D40));

    unsigned char abGamma[256];
    sub_006BE190_BuildGammaTable(gnDDrawGamma_0072F7CC, abGamma, gnDDrawGammaScale_0072F7C8, 1, 256, 0xFF);
    for (int i = 0; i < 256; ++i)
    {
        gaDDrawPalette_007C8CC8[i].peRed = abGamma[gaDDrawSavedPalette_00880D40[i].peRed];
        gaDDrawPalette_007C8CC8[i].peGreen = abGamma[gaDDrawSavedPalette_00880D40[i].peGreen];
        gaDDrawPalette_007C8CC8[i].peBlue = abGamma[gaDDrawSavedPalette_00880D40[i].peBlue];
    }

    gbPaletteDirty_00881298 = 1;
}

#include "gen/data/Source/D2DDraw/Unknown_00510020.inc"
