#pragma once

#include "D2GfxTypes.h"
#include "D2SysTypes.h"

struct D2CmpCelContextStrc;
struct D2GfxSettingsStrc;
struct D2TileDrawFunctionsStrc;

extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack); // 0x006CC608
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char szDDSmackFile_006DE20C[]; // 0x006DE20C
extern D2GfxSettingsStrc* gpGfxSettings_007C9148; // 0x007C9148
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C; // 0x007C914C
extern int gbRenderPaused_007C9144; // 0x007C9144
extern int gbSurfaceActive_007C9140; // 0x007C9140
extern int gnScreenHeight_007C913C; // 0x007C913C
extern int gnScreenWidth_007C9138; // 0x007C9138
extern unsigned char* gpScreenBuffer_007C9154; // 0x007C9154
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned int gdwVideoFlags_00881140; // 0x00881140
extern void* ghDDrawWindow_007C9140; // 0x007C9140
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
void __fastcall sub_005103B0(const char* szText, long nResult); // 0x005103B0
void __stdcall CelDraw(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};
