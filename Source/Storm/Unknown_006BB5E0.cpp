#include "Storm.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
int __fastcall sub_006B3730_CreateSurface(void** ppSurface, void** ppTexture, int nWidth, int nHeight); // 0x006B3730
extern void* gpSurface_00989BF8; // 0x00989BF8
extern void* gpTexture_00989BFC; // 0x00989BFC
extern void* gpSurface_00989C00; // 0x00989C00
extern void* gpTexture_00989C04; // 0x00989C04
extern int gnWidth_0096F4DC; // 0x0096F4DC
void* __cdecl sub_00681EF0_ClearMemory(void* destination, int value, unsigned int size); // 0x00681EF0

// 0x006BB5E0
void __cdecl sub_006BB5E0_CreateSurfaces()
{
    D2_ASSERT(sub_006B3730_CreateSurface(&gpSurface_00989BF8, &gpTexture_00989BFC, gnWidth_0096F4DC, gnHeight_009702B8), 0x27);
    D2_ASSERT(sub_006B3730_CreateSurface(&gpSurface_00989C00, &gpTexture_00989C04, 0x20, 0x20), 0x2A);
}

static __declspec(noinline)
// 0x006BB6B0
void sub_006BB6B0_DecodeTile(const unsigned char* source, unsigned char* destination)
{
    int rows = 32;
    unsigned char* row = destination;
    unsigned char* pixel = destination;
    const unsigned char* input = source;
    sub_00681EF0_ClearMemory(destination, 0, 1024);
    do
    {
        unsigned char skip = *input++;
        unsigned char count = *input++;
        if (!skip && !count)
        {
            --rows;
            row += 32;
            pixel = row;
        }
        else
        {
            pixel += skip;
            while (count--)
                *pixel++ = *input++;
        }
    } while (rows);
}

void __fastcall EmitDecodeTile(unsigned char* destination, const unsigned char* source)
{
    sub_006BB6B0_DecodeTile(source, destination + 1);
}
