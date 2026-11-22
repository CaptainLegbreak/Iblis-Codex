#include "D2DDraw.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2LevelTxt.h"
#include "D2ClientMenus.h"

struct D2PlayerDataStrc;
struct D2TextHeaderStrc;
struct D2SetsTxt { char unk0x000[0x128]; };

enum
{
    NUM_HOTKEYS = 114,
};

typedef void (__cdecl* D2WheelCallbackFn)();
typedef int (__stdcall* D2FarProcFn)();
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn);                              // 0x006CC34C
void __fastcall DLIGHTMAP_ReleaseLight(void* pResource);                                       // 0x004743D0
void __cdecl TEXT_ResetTextBox();                                                                   // 0x0049F960
void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader);                                          // 0x006612A0
int __stdcall SFileUnloadFile(void* pBuffer); // 0x00416710
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2WheelCallbackFn gpfnWheelUp_007A7404;                                                              // 0x007A7404
extern D2WheelCallbackFn gpfnWheelDown_007A7408;                                                            // 0x007A7408
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90
extern D2UnitStrc* gpAiTargets_007A7470[];                                                                  // 0x007A7470
extern unsigned char gabColors_007BCAD8[5];                                                                 // 0x007BCAD8
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern int gnGlobal_007BCE2C;                                                                               // 0x007BCE2C
extern int gnGlobal_00721E34;                                                                               // 0x00721E34
extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C
extern int gnGlobal_00721E40;                                                                               // 0x00721E40
extern int gnGlobal_00721E44;                                                                               // 0x00721E44
extern int gnGlobal_00721E48;                                                                               // 0x00721E48
extern int gnGlobal_00721E4C;                                                                               // 0x00721E4C
extern int gnGlobal_00721E50;                                                                               // 0x00721E50
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
extern int gdwGlobal_007BCBE8;                                                                              // 0x007BCBE8
extern int gdwGlobal_007BCBF4;                                                                              // 0x007BCBF4
extern int gdwGlobal_007BCBF8;                                                                              // 0x007BCBF8
extern int gnGlobal_007BF1FA;                                                                               // 0x007BF1FA
extern D2TextHeaderStrc* gpTextHeader_007BF250;                                                             // 0x007BF250
extern int gnGlobal_007C0E7C;                                                                               // 0x007C0E7C
unsigned char* gpDDrawDebugFontGlyphs_008815AC;                                                             // 0x008815AC
extern void* gpReply_008818D0;                                                                              // 0x008818D0
extern "C" void* gpCDKeyHandle_00882744;                                                                    // 0x00882744
extern "C" void* gpCDKeyHandle_00882750;                                                                    // 0x00882750

extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090

extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4

extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc); // 0x006CC0D8

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho); // 0x006CC0D4

extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534

extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void* hdc, int x, int y); // 0x006CC0B8

extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h); // 0x006CC09C

extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode); // 0x006CC0B4

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

extern int gaDDrawDebugFontCharWidths_00881428[96]; // 0x00881428

int gaDDrawDebugFontGlyphOffsets_008812A8[96]; // 0x008812A8

unsigned long gdwDDrawDebugFontBkColor_008815A8; // 0x008815A8

extern unsigned long gdwDDrawDebugFontTextColor_0072F7F0; // 0x0072F7F0

extern "C" const char gszCourier_006DD52C[]; // 0x006DD52C

extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, unsigned long bItalic, unsigned long bUnderline, unsigned long bStrikeOut, unsigned long iCharSet, unsigned long iOutPrecision, unsigned long iClipPrecision, unsigned long iQuality, unsigned long iPitchAndFamily, const char* pszFaceName); // 0x006CC0E0

extern "C" __declspec(dllimport) int __stdcall GetCharWidthA(void* hdc, unsigned int iFirst, unsigned int iLast, int* lpBuffer); // 0x006CC0D0

extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color); // 0x006CC0B0

extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color); // 0x006CC0AC

// 0x00464810
void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x10000;
    }
}

// 0x00464820
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case UNIT_MONSTER:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00464930
void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        DLIGHTMAP_ReleaseLight(pUnit->pLight);
        pUnit->pLight = 0;
    }
}

// 0x004693B0
void __fastcall CUNIT_DispatchMouseWheel(int nSteps)
{
    if (nSteps > 0)
    {
        if (gpfnWheelUp_007A7404)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelUp_007A7404), 0x383);
            gpfnWheelUp_007A7404();
        }
    }
    else if (nSteps < 0)
    {
        if (gpfnWheelDown_007A7408)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelDown_007A7408), 0x38B);
            gpfnWheelDown_007A7408();
        }
    }
}

// 0x00469AA0
unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nA && gtHotkeys_007A6F90[i].nMode == nB)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }

    return 0xFFFF;
}

// 0x00469D70
void __fastcall CUNIT_ClearHotkeyBinding(int nId, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (nId == gtHotkeys_007A6F90[i].nCommand && nB == gtHotkeys_007A6F90[i].nMode)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
        }
    }
}

// 0x00469D90
int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB)
{
    return CUNIT_GetHotkeyBinding(nA, nB) != 0xFFFF;
}

// 0x0046D750
void __cdecl CUNIT_ClearAiTargets()
{
    for (int i = 0; i < 8; ++i)
    {
        gpAiTargets_007A7470[i] = 0;
    }
}

// 0x00483410
D2SetsTxt* __fastcall DATATBLS_GetSetsTxtRecord(int nSetId)
{
    if (nSetId >= 0 && nSetId < sgptDataTables->nSetsTxtRecordCount)
    {
        return &sgptDataTables->pSetsTxt[nSetId];
    }

    return 0;
}

// 0x00483440
D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483470
D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483960
void __cdecl CUNIT_InitColorTable()
{
    gabColors_007BCAD8[0] = sub_004FB180_FindPaletteIndex(0x80, 0, 0);
    gabColors_007BCAD8[1] = sub_004FB180_FindPaletteIndex(0, 0x80, 0);
    gabColors_007BCAD8[2] = sub_004FB180_FindPaletteIndex(0, 0, 0x80);
    gabColors_007BCAD8[3] = sub_004FB180_FindPaletteIndex(0x80, 0x80, 0);
    gabColors_007BCAD8[4] = sub_004FB180_FindPaletteIndex(0x80, 0x40, 0x40);
}

// 0x00489840
int __cdecl sub_00489840_IsNpcState123()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3)
    {
        return 1;
    }

    return 0;
}

// 0x004898A0
void __fastcall sub_004898A0(int nMode)
{
    gnGlobal_007BCE2C = 1;
    if (gdwGlobal_007BCBF0 == 13)
    {
        gdwGlobal_007BCBF0 = 12;
    }

    sub_00455F20(5, 1, 0);
}

// 0x004898D0
void __fastcall CUNIT_SetDialogState(int nState)
{
    gnGlobal_00721E34 = nState;
    if (nState == 0)
    {
        gnGlobal_00721E3C = -1;
        gnGlobal_00721E40 = -1;
        gnGlobal_00721E44 = -1;
        gnGlobal_00721E48 = -1;
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
    }
}

// 0x004A1730
void __cdecl CUNIT_ClearTextPanel()
{
    TEXT_ResetTextBox();
    gnGlobal_007BF1FA = 0;
    if (gpTextHeader_007BF250)
    {
        TEXT_FreeTextHeader(gpTextHeader_007BF250);
        gpTextHeader_007BF250 = 0;
    }
}

// 0x004B8A10
int __cdecl sub_004B8A10()
{
    if (gnGlobal_007C0E7C == 1 || gnGlobal_007C0E7C == 2)
    {
        return 1;
    }

    return 0;
}

// 0x005125B0
void __cdecl DDRAW_FreeDebugFont()
{
    if (gpDDrawDebugFontGlyphs_008815AC)
    {
        FOG_Free(gpDDrawDebugFontGlyphs_008815AC, ".\\Src\\ddDebugFont.cpp", 0x5D, 0);
        gpDDrawDebugFontGlyphs_008815AC = 0;
    }
}

// 0x0051B210
void __cdecl BNSEND_FreeGamesList()
{
    if (gpReply_008818D0)
    {
        FOG_Free(gpReply_008818D0, ".\\BnSend.cpp", 0x36A, 0);
    }

    gpReply_008818D0 = 0;
}

// 0x005239C0
void __cdecl GRID_UnlockCDKeys()
{
    if (gpCDKeyHandle_00882744)
    {
        SFileUnloadFile(gpCDKeyHandle_00882744);
        gpCDKeyHandle_00882744 = 0;
    }

    if (gpCDKeyHandle_00882750)
    {
        SFileUnloadFile(gpCDKeyHandle_00882750);
        gpCDKeyHandle_00882750 = 0;
    }
}

// 0x00512430
void __cdecl DDRAW_CreateDebugFont()
{
    void* hDC = CreateDCA("DISPLAY", 0, 0, 0);
    void* hFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, gszCourier_006DD52C);
    void* hBitmap = CreateBitmap(8, 16, 1, 8, 0);
    SelectObject(hDC, hFont);
    SelectObject(hDC, hBitmap);
    SetTextColor(hDC, gdwDDrawDebugFontTextColor_0072F7F0);
    SetBkColor(hDC, gdwDDrawDebugFontBkColor_008815A8);
    SetBkMode(hDC, 2);
    tagRECT rect;
    SetRect(&rect, 0, 0, 8, 16);
    gpDDrawDebugFontGlyphs_008815AC = (unsigned char*)FOG_Alloc(0x3000, ".\\Src\\ddDebugFont.cpp", 0x3A, 0);
    unsigned char* pMask = gpDDrawDebugFontGlyphs_008815AC;
    int nOffset = 0;
    for (int nChar = 0x20; nChar <= 0x7F; ++nChar)
    {
        char cChar = nChar;
        DrawTextA(hDC, &cChar, 1, &rect, 0);
        for (int y = 0; y < 16; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                if (GetPixel(hDC, x, y) == gdwDDrawDebugFontTextColor_0072F7F0)
                    *pMask++ = 0xFF;
                else
                    *pMask++ = 0;
            }
        }
        gaDDrawDebugFontGlyphOffsets_008812A8[nChar - 0x20] = nOffset;
        nOffset += 0x80;
    }
    GetCharWidthA(hDC, 0x20, 0x7F, gaDDrawDebugFontCharWidths_00881428);
    DeleteObject(hBitmap);
    DeleteObject(hFont);
    DeleteDC(hDC);
}
