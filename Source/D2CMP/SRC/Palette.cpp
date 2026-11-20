#include "D2CMP.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pFileSizeHigh);

unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
int __fastcall sub_00605340_LoadPcxPalette(const char* szFileName);                                         // 0x00605340
extern unsigned int gnPaletteEnd_008E902C;                                                                  // 0x008E902C
extern unsigned int gnPaletteStart_008E9930;                                                                // 0x008E9930
extern int gnSquareTable_008E9034[511];                                                                     // 0x008E9034
extern unsigned int gdwSwappedColor_008E9D38;                                                               // 0x008E9D38
int gbPaletteLoaded_008E9934;                                                                               // 0x008E9934
unsigned char gaPaletteRaw_008E8D28[0x300];                                                                 // 0x008E8D28
unsigned char gaPcxPalette_008E9938[256 * 4];                                                               // 0x008E9938

// 0x006054F0
int __stdcall PaletteInit(const char* szFile, int nStart, int nEnd)
{
    D2_ASSERT(szFile, 0x3B6);
    D2_ASSERT(nStart <= nEnd, 0x3B7);
    D2_ASSERT(nStart >= 0, 0x3B8);
    D2_ASSERT(nEnd < 0x100, 0x3B9);

    gnPaletteEnd_008E902C = nEnd;
    gnPaletteStart_008E9930 = 1;
    for (int i = -0x100; i < 0x100; i++)
    {
        gnSquareTableCenter_008E9430[i] = i * i;
    }

    gdwSwappedColor_008E9D38 = 0;
    if (SStrLen(szFile))
    {
        void* hFile = CreateFileA(szFile, 0x80000000, 1, 0, 3, 0, 0);
        if (hFile == (void*)-1)
        {
            OutputDebugStringA("Unable to open ");
            OutputDebugStringA(szFile);
            OutputDebugStringA(gszNewline_006FFCB0);
            return 0;
        }

        if (GetFileSize(hFile, (unsigned long*)&nStart) == 0x300)
        {
            unsigned long nRead = 0;
            ReadFile(hFile, gaPaletteRaw_008E8D28, 0x300, &nRead, 0);
            if (nRead == 0x300)
            {
                for (unsigned int i = 0; i < 0x100; ++i)
                {
                    gaPcxPalette_008E9938[i * 4 + 2] = gaPaletteRaw_008E8D28[i * 3 + 0];
                    gaPcxPalette_008E9938[i * 4 + 1] = gaPaletteRaw_008E8D28[i * 3 + 1];
                    gaPcxPalette_008E9938[i * 4 + 0] = gaPaletteRaw_008E8D28[i * 3 + 2];
                }

                gbPaletteLoaded_008E9934 = 1;
                CloseHandle(hFile);
                return gbPaletteLoaded_008E9934;
            }

            gbPaletteLoaded_008E9934 = 0;
            CloseHandle(hFile);
            return gbPaletteLoaded_008E9934;
        }

        CloseHandle(hFile);
        gbPaletteLoaded_008E9934 = sub_00605340_LoadPcxPalette(szFile);
        return gbPaletteLoaded_008E9934;
    }

    for (unsigned int i = 0; i < 0x100; ++i)
    {
        gaPcxPalette_008E9938[i * 4 + 0] = (unsigned char)i;
        gaPcxPalette_008E9938[i * 4 + 1] = (unsigned char)i;
        gaPcxPalette_008E9938[i * 4 + 2] = (unsigned char)i;
    }

    gbPaletteLoaded_008E9934 = 1;
    return 1;
}
