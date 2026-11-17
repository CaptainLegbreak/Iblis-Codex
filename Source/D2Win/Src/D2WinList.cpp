#include "D2Win.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2WinControlStrc;
struct D2UnitStrc;
struct Unicode;
struct D2WinListDataStrc;
struct D2WinListStrc;
struct D2WinAccountListDataStrc;
struct D2WinAccountListStrc;
struct D2ViewStrc;
struct D2WinListInitStrc;

enum D2ControlTypes
{
    D2WIN_LIST = 7,
    D2WIN_ACCOUNTLIST = 12,
};

struct Unicode
{
    unsigned short wChar;
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinControlStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    D2WinControlFn pfDraw;
    D2WinControlFn pfInitialize;
    D2WinMsgHandler pfHandleMouseDown;
    D2WinMsgHandler pfHandleMouseUp;
    D2WinMsgHandler pfHandleCharInput;
    D2WinMsgHandler pfHandleVirtualKeyInput;
    D2WinMsgHandler field_34;
    D2WinControlFn pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

struct D2WinListDataStrc
{
    Unicode wszText[256];
    int field_200;
    D2WinMsgHandler field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    char field_218;
    char field_219;
    char field_21A;
    char field_21B;
    int field_21C;
    D2WinListDataStrc* pNext;
};

struct D2WinListStrc
{
    D2WinControlStrc controlHeader;
    int eFont;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int nWidestEntry;
    D2WinListDataStrc* pDataList;
    D2WinListDataStrc* pSelectedDataEntry;
};

struct D2WinAccountListStrc
{
    D2WinControlStrc controlHeader;
    D2WinAccountListDataStrc* pDataList;
    D2WinAccountListDataStrc* pSelectedDataEntry;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2ViewStrc
{
    char unk0x00[0x24];
    int nPosX;
    int nPosY;
};
extern unsigned char gabBeltHotkey_007BEFB0[]; // 0x007BEFB0
extern int gnBeltBox_0072235C; // 0x0072235C
extern int gnBeltRectX_00722360; // 0x00722360
extern int gnBeltRectY_00722364; // 0x00722364
extern int gnBeltHover_007BEF94; // 0x007BEF94
extern D2UnitStrc* gpBeltItemA_007BEFA8; // 0x007BEFA8
extern int gdwGlobal_007BEFAC; // 0x007BEFAC
extern int gnGlobal_007BEECC; // 0x007BEECC
extern unsigned char gnLifeColorHigh_007BEED0; // 0x007BEED0
extern unsigned char gnLifeColorMid_007BEED1; // 0x007BEED1
extern unsigned char gnLifeColorLow_007BEED2; // 0x007BEED2
extern unsigned char gbLifeColorsInit_007BEED3; // 0x007BEED3
extern unsigned char gnTextColorRed_007BEFBA; // 0x007BEFBA
extern unsigned char gabBeltColors_007BEF6C[4]; // 0x007BEF6C
extern int gnGlobal_00721E3C; // 0x00721E3C
extern int gnGlobal_00721E40; // 0x00721E40
extern int gnGlobal_00721E44; // 0x00721E44
extern int gnGlobal_00721E48; // 0x00721E48
extern int gnGlobal_00721E4C; // 0x00721E4C
extern int gnGlobal_00721E50; // 0x00721E50
extern int gdwGlobal_007BCBE4; // 0x007BCBE4
extern int gdwGlobal_007BCBE8; // 0x007BCBE8
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
extern D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4
extern int gdwGlobal_007BCBF8; // 0x007BCBF8

enum D2FontTypes
{
    D2FONT_FONT16 = 1,
};

struct D2WinListInitStrc
{
    int nStringId;
    char nFlag;
    char pad0x05[3];
    int nValue;
    D2WinMsgHandler f_C;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
int __fastcall LIST_Draw(D2WinControlStrc* pControl); // 0x00507160
int __stdcall LIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x005072F0
int __stdcall LIST_HandleCharInput(SMSGHANDLER_PARAMS* pMsg); // 0x005073B0
int __stdcall LIST_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg); // 0x00507420
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern int gnListFontHeight_006DD024[]; // 0x006DD024

// 0x00507000
int __fastcall LIST_GetSelectedDataIndex(D2WinListStrc* pList)
{
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0xD2);
    int nIndex = 0;
    D2WinListDataStrc* pData = pList->pDataList;
    while (pData)
    {
        if (pList->pSelectedDataEntry == pData)
        {
            break;
        }
        pData = pData->pNext;
        ++nIndex;
    }
    if (pData)
    {
        return nIndex;
    }
    return -1;
}

// 0x00507050
D2WinListDataStrc* __fastcall LIST_GetDataFromIndex(D2WinListStrc* pList, int nIndex)
{
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0xE5);
    int nCounter = 0;
    D2WinListDataStrc* pData = pList->pDataList;
    while (pData)
    {
        if (nCounter == nIndex)
        {
            break;
        }
        pData = pData->pNext;
        ++nCounter;
    }
    if (pData)
    {
        return pData;
    }
    return 0;
}

// 0x005070A0
int __fastcall D2Win_10141(D2WinListStrc* pList)
{
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0xF8);
    return pList->field_50;
}

// 0x005078A0
void __fastcall ACCOUNTLIST_AllocData(D2WinAccountListStrc* pAccountList, const char* szText)
{
    D2_ASSERT(pAccountList->controlHeader.nType == D2WIN_ACCOUNTLIST, 0x72);
    D2WinAccountListDataStrc* pData = (D2WinAccountListDataStrc*)FOG_Alloc(sizeof(D2WinAccountListDataStrc), ".\\Src\\D2WinAccountList.cpp", 0x77, 0);
    strncpy(pData->szText, szText, sizeof(pData->szText));
    pData->pNext = pAccountList->pDataList;
    pAccountList->pDataList = pData;
}

// 0x005079C0
int __fastcall ACCOUNTLIST_GetTextFromSelectedEntry(D2WinAccountListStrc* pAccountList, char* szBuffer)
{
    D2_ASSERT(pAccountList->controlHeader.nType == D2WIN_ACCOUNTLIST, 0xB9);
    const char* szText = pAccountList->pSelectedDataEntry->szText;
    if (szText)
    {
        char c;
        do
        {
            c = *szText;
            *szBuffer = c;
            ++szText;
            ++szBuffer;
        }
        while (c);
        return 1;
    }
    return 0;
}

D2CelFileStrc* ghPentagramCellFile; // 0x0087E96C

// 0x004760C0
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY)
{
    *pX = pView->nPosX;
    *pY = pView->nPosY;
}

// 0x00507140
void __stdcall LIST_UnloadPentspinCellfile()
{
    sub_004FAAE0_FreeCellFile(ghPentagramCellFile);
    ghPentagramCellFile = 0;
}

// 0x00498D50
void __fastcall sub_00498D50(int nX, int nArg)
{
    if ((unsigned int)nX < 4)
        gabBeltHotkey_007BEFB0[nX] = (unsigned char)nArg;
}

// 0x00498D60
void __cdecl sub_00498D60()
{
    gnBeltBox_0072235C = -1;
    gnBeltRectX_00722360 = -1;
    gnBeltRectY_00722364 = -1;
    gnBeltHover_007BEF94 = 0;
    gpBeltItemA_007BEFA8 = 0;
    gdwGlobal_007BEFAC = 0;
}

// 0x00492C10
int __cdecl sub_00492C10()
{
    return gnGlobal_007BEECC != 2;
}

// 0x00492F40
void __fastcall sub_00492F40_SetFade(int nMode)
{
    if (!nMode)
    {
        if (gbLifeColorsInit_007BEED3)
            return;
        gbLifeColorsInit_007BEED3 = 1;
    }

    gnLifeColorHigh_007BEED0 = D2Win_10034_MixRGB(0, 0x80, 0);
    gnLifeColorMid_007BEED1 = D2Win_10034_MixRGB(0xC0, 0xC0, 0);
    gnLifeColorLow_007BEED2 = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x00492F90
void __cdecl sub_00492F90()
{
    gbLifeColorsInit_007BEED3 = 0;
}

// 0x00497250
void __cdecl sub_00497250_InitTextColorRed()
{
    gnTextColorRed_007BEFBA = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x004972B0
void __cdecl sub_004972B0_InitBeltColors()
{
    gabBeltColors_007BEF6C[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabBeltColors_007BEF6C[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabBeltColors_007BEF6C[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabBeltColors_007BEF6C[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
}

// 0x004879D0
void __fastcall sub_004879D0(D2UnitStrc* pUnit)
{
    if (gdwGlobal_007BCBF4 == pUnit)
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

// 0x00487CA0
int __cdecl sub_00487CA0_SetNpcState6()
{
    if (gdwGlobal_007BCBF0 == 6)
        return 0;
    gdwGlobal_007BCBF0 = 6;
    return 1;
}

// 0x005075E0
D2WinListStrc* __fastcall LIST_Create(int nX, int nY, int nWidth, int nHeight, D2WinListInitStrc* pInit, int* pFont)
{
    D2WinListStrc* pList = (D2WinListStrc*)FOG_Alloc(sizeof(D2WinListStrc), ".\\Src\\D2WinList.cpp", 0x2E, 0);
    memset(pList, 0, sizeof(D2WinListStrc));
    pList->controlHeader.nType = D2WIN_LIST;
    pList->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pList->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pList->controlHeader.nImageX = nX;
    pList->controlHeader.nImageY = nY;
    pList->controlHeader.nWidth = nWidth;
    pList->controlHeader.nHeight = nHeight;
    pList->controlHeader.pCellFile = 0;
    pList->controlHeader.pfDraw = LIST_Draw;
    pList->controlHeader.pfHandleMouseDown = LIST_HandleMouseDown;
    pList->controlHeader.pfHandleMouseUp = 0;
    pList->controlHeader.pfHandleCharInput = LIST_HandleCharInput;
    pList->controlHeader.pfHandleVirtualKeyInput = LIST_HandleVirtualKeyInput;
    pList->controlHeader.field_34 = 0;
    pList->controlHeader.pNext = 0;
    pList->field_5C = 0;
    pList->pDataList = 0;
    pList->eFont = *pFont;
    pList->field_44 = gnListFontHeight_006DD024[pList->eFont];
    pList->field_48 = gnListFontHeight_006DD024[pList->eFont] >> 2;
    pList->nWidestEntry = 0;
    pList->field_4C = 0;
    pList->field_50 = 0;
    pList->field_54 = -1;
    pList->field_58 = nHeight / (pList->field_44 + 2 * pList->field_48) - 1;

    sub_00502EF0(*pFont);

    for (D2WinListInitStrc* pEntry = pInit; pEntry->nStringId; ++pEntry)
    {
        D2WinListDataStrc* pData = (D2WinListDataStrc*)FOG_Alloc(sizeof(D2WinListDataStrc), ".\\Src\\D2WinList.cpp", 0x56, 0);
        const Unicode* pText = D2LANG_GetStringFromTblIndex((unsigned short)pEntry->nStringId);
        D2_ASSERT(sub_00526800(pText) < 256, 0x58);
        sub_005267E0(pData->wszText, pText);

        int nTextWidth;
        int nTextHeight;
        D2Win_10131_GetTextDimensions(pText, &nTextWidth, &nTextHeight);
        nTextWidth += 8;
        if (nTextWidth > pList->nWidestEntry)
        {
            pList->nWidestEntry = nTextWidth;
        }

        pData->field_200 = nTextWidth;
        pData->field_204 = pEntry->f_C;
        pData->field_208 = 0;
        pData->field_20C = 0;
        pData->field_210 = 0;
        pData->field_214 = 0;
        pData->field_218 = pEntry->nFlag;
        pData->field_21C = pEntry->nValue;
        pData->pNext = 0;

        if (pList->pDataList)
        {
            D2WinListDataStrc* pLast = pList->pDataList;
            while (pLast->pNext)
            {
                pLast = pLast->pNext;
            }
            pLast->pNext = pData;
        }
        else
        {
            pList->pDataList = pData;
        }

        ++pList->field_50;
    }

    sub_00502EF0(D2FONT_FONT16);
    pList->pSelectedDataEntry = pList->pDataList;
    CONTROL_AppendToList(&pList->controlHeader);
    return pList;
}

#include "gen/data/Source/D2Win/Src/D2WinList.inc"
