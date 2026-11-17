#include "D2Client.h"

struct Unicode
{
    unsigned short wChar;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc tSeed;
    char unk0x28[0x38];
    D2InventoryStrc* pInventory;
};

typedef char sub_I16_AssertUnitSeed[(int)&((D2UnitStrc*)0)->tSeed == 0x20 ? 1 : -1];
typedef char sub_I16_AssertUnitInventory[(int)&((D2UnitStrc*)0)->pInventory == 0x60 ? 1 : -1];

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct tagRECT
{
    int left;
    int top;
    int right;
    int bottom;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit);                                      // 0x00464A60
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords);                       // 0x00620900
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY);                           // 0x004760C0
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex);                              // 0x004B82F0
void __fastcall sub_004B8370(void* pPanel, int nValue);                                                     // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8);                                                                   // 0x004B85F0
int __cdecl sub_004B4670();                                                                                 // 0x004B4670
int __cdecl sub_004B46D0();                                                                                 // 0x004B46D0
int __cdecl sub_004B4730();                                                                                 // 0x004B4730

extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640

static __forceinline D2UnitStrc* NPC_GetInteractUnit_Inline()
{
    return gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
}

static __forceinline unsigned int NPCDLG_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __declspec(noinline) int sub_004B1C80_GetNpcDialogPos(D2CoordStrc* pCoords)
{
    if (NPC_GetInteractUnit_Inline())
    {
        UNITS_GetClientCoords(NPC_GetInteractUnit_Inline(), pCoords);

        tagRECT tView;
        sub_00476070_GetViewRect(gpView_007A0640, &tView.left, &tView.top, &tView.right, &tView.bottom);

        D2CoordStrc tOffset;
        sub_004760C0_GetViewOffset(gpView_007A0640, &tOffset.nX, &tOffset.nY);

        tagRECT tRect;
        SetRect(&tRect, tOffset.nX, tOffset.nY, tOffset.nX + (tView.right - tView.left), tOffset.nY + (tView.bottom - tView.top));
        pCoords->nY += -150 - tRect.top;
        pCoords->nX -= tRect.left;
        if (pCoords->nY < 20)
        {
            pCoords->nY = 20;
        }

        return 1;
    }

    return 0;
}

// 0x004B4DB0
void __cdecl sub_004B4DB0_OpenGreetingDialog()
{
    if (!NPC_GetInteractUnit_Inline())
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return;
    }

    D2_ASSERT(!gpDialog_007C0D7B, 0xD69);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);

    gpDialog_007C0D7B = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B4670, sub_004B46D0, 0, 0, 1, 0, 0, 0, 1);
    sub_004B8370(gpDialog_007C0D7B, 1);

    Unicode wszName[80];
    for (int i = 0; i < 80; ++i)
    {
        wszName[i].wChar = 0;
    }

    sub_005267E0(wszName, sub_00464A60_GetUnitName(NPC_GetInteractUnit_Inline()));
    const int nLength = sub_00526800(wszName);
    for (int i = 0; i < nLength; ++i)
    {
        const unsigned short wChar = wszName[i].wChar;
        wszName[i].wChar = wChar < 0x100 ? gaCaseTable_00730778[wChar] : wChar;
    }

    sub_004B85F0_AddTextLine(gpDialog_007C0D7B, wszName, 0x15, 0, 4, 1, 0, 0);
    gnGlobal_007C0C6B = 1;

    unsigned short aStrings[5];
    int nStrings = 0;
    aStrings[nStrings++] = 0xD3A;
    aStrings[nStrings++] = 0xD3B;
    aStrings[nStrings++] = 0xD3C;
    aStrings[nStrings++] = 0xD3D;
    aStrings[nStrings++] = 0xD3E;
    D2UnitStrc* pPlayer = sub_00463DD0();
    const unsigned int nRoll = NPCDLG_RollSeed_Inline(&pPlayer->tSeed) % nStrings;
    sub_004B85F0_AddTextLine(gpDialog_007C0D7B, D2LANG_GetStringFromTblIndex(aStrings[nRoll]), 0xF, 0, 0, 1, sub_004B4730, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0D7B, D2LANG_GetStringFromTblIndex(0x102E), 0xF, 0, 0, 1, sub_004B4670, 1);
    sub_004B82F0_Select(gpDialog_007C0D7B, 1);
}
