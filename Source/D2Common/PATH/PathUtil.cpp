#include "D2Common.h"

struct PathOwner { char pad0[0x2c]; D2DynamicPathStrc* pPath; };

struct D2DynamicPathStrc
{
    char pad0[0x10];
    unsigned short x;
    unsigned short y;
    char pad14[0x44];
    PathOwner* field58;
    char pad5C[0x0C];
    unsigned char field68;
};

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath); // 0x006487F0

// 0x00679190
void __fastcall sub_00679190(D2DynamicPathStrc* pPath)
{
    if (pPath == 0)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1ea);
        exit(-1);
    }
    if (pPath->field58 == 0)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1eb);
        exit(-1);
    }

    unsigned char dir = PATH_GetDirection(pPath->field58->pPath);
    int dir8 = (int)dir * 8;
    int offset = (int)pPath->field68 * 256;
    int angle = (dir8 - offset) & 0x1FF;
    float f = (float)pPath->field68;

    pPath->x += (unsigned short)(int)(sub_0040B330_Cos(angle) * f);
    pPath->y += (unsigned short)(int)(sub_0040B350_Sin(angle) * f);
}
