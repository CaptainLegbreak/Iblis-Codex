#pragma once

#include "D2GfxTypes.h"

struct D2CriticalSectionStrc;
struct D2D3DDeviceStrc;
struct D2D3DObjStrc;

extern "C" __declspec(dllimport) unsigned int __stdcall SmackDoFrame(D2SmackStrc* smack); // 0x006CC5FC
extern "C" __declspec(dllimport) unsigned int __stdcall SmackWait(D2SmackStrc* smack); // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* smack); // 0x006CC600
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern D2CriticalSectionStrc* gpLock_007C9134; // 0x007C9134
extern D2D3DDeviceStrc* gpD3DDevice_00970E78; // 0x00970E78
extern const char gszAssertExpr_006CC837[]; // 0x006CC837
extern const char gszFloorPoolSourceFile_006FC3E4[]; // 0x006FC3E4
extern const char gszSubtilePoolSourceFile_006FC3A8[]; // 0x006FC3A8
extern const char gszTexPoolSourceFile_006FC36C[]; // 0x006FC36C
extern const unsigned int gnRenderFlag_006CE290; // 0x006CE290
extern int gaGlyphWidths_00970FC8[]; // 0x00970FC8
extern int gbRenderPaused_007C9144; // 0x007C9144
extern int gnBytesPerPixel_00970E80; // 0x00970E80
extern int gnGlobal_0096F4DC; // 0x0096F4DC
extern int gnGlobal_009702B8; // 0x009702B8
extern int gnHeight_007C913C; // 0x007C913C
extern int gnScreenHeight_007C913C; // 0x007C913C
extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnWidth_007C9138; // 0x007C9138
extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8
extern void* gapGlyphTextures_009712D0[]; // 0x009712D0
extern void* ghDDrawWindow_007C9140; // 0x007C9140
extern void* gpArray_009897EC[2]; // 0x009897EC
int __fastcall sub_006B58A0_CreateTexture(D2D3DObjStrc** ppTexture, D2D3DObjStrc** ppSurface, int nWidth, int nHeight); // 0x006B58A0
unsigned int __fastcall sub_006B1D50_GetColor(unsigned int index); // 0x006B1D50
void __cdecl sub_006B3800_Flush(); // 0x006B3800
void __fastcall sub_006B1EA0_SetMode(int); // 0x006B1EA0
void __stdcall sub_006B9F00_PresentFrame(); // 0x006B9F00
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define LRU_ASSERT(expr, line) if (!(expr)) { sub_00408A60(gszAssertExpr_006CC837, sub_00408090(), line); exit(-1); }
#define RELEASE(p) if (p) { p->lpVtbl->Release(p); p = 0; }

struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };

struct D2D3DObjVtblStrc
{
	void* pQueryInterface;
	void* pAddRef;
	unsigned long (__stdcall* pRelease)(D2D3DObjStrc* pObj);
};

struct D2D3DObjStrc
{
	D2D3DObjVtblStrc* pVtbl;
};

struct D2FloorPoolOwnerStrc
{
	char unk0x00[0x42];
	short nPoolId;
};

struct D2FloorPoolEntryStrc
{
	int nIndex;
	D2FloorPoolOwnerStrc* pOwner;
	D2D3DObjStrc* pTexture;
	D2D3DObjStrc* pSurface;
	D2FloorPoolEntryStrc* pNext;
	D2FloorPoolEntryStrc* pPrev;
};

struct D2FloorPoolStrc
{
	int nCapacity;
	int nInUse;
	D2FloorPoolEntryStrc* pInUseFirst;
	D2FloorPoolEntryStrc* pInUseLast;
	D2FloorPoolEntryStrc* pSpareFirst;
	D2FloorPoolEntryStrc* pSpareLast;
	D2FloorPoolEntryStrc* pEntries;
};

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2TexOwnerSlotStrc
{
	void* pTexture;
	void* pInfo;
};

struct D2TexPoolEntryStrc
{
	int nIndex;
	D2TexOwnerSlotStrc* pOwnerSlots;
	int nOwnerSlot;
	int unk0x0C;
	D2D3DObjStrc* pTexture;
	D2D3DObjStrc* pSurface;
	D2TexPoolEntryStrc* pNext;
	D2TexPoolEntryStrc* pPrev;
};

struct D2TexPoolStrc
{
	int nCapacity;
	int nInUse;
	D2TexPoolEntryStrc* pInUseFirst;
	D2TexPoolEntryStrc* pInUseLast;
	D2TexPoolEntryStrc* pSpareFirst;
	D2TexPoolEntryStrc* pSpareLast;
	D2TexPoolEntryStrc* pEntries;
};

