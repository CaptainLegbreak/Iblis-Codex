#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2CelContext.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MsgHandlerEntryStrc;
struct Unicode;
struct D2RectStrc;
struct T00479230;
struct D2TextNodeStrc;
struct D2TextListStrc;
struct D2StringSoundStrc;


struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

struct D2ClientDialogStrc
{
    unsigned long dwTick;
    int unk0x04;
    void* pCelFile;
    int unk0x0C;
    int unk0x10;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int unk0x24;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    int unk0x34;
    int unk0x38;
    int unk0x3C;
    int unk0x40;
    int unk0x44;
    int unk0x48;
    int unk0x4C;
    int unk0x50;
    int unk0x54;
    int unk0x58;
    int unk0x5C;
    int unk0x60;
    int unk0x64;
    char unk0x68[0xB08 - 0x68];
    int unk0xB08;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void __cdecl sub_0044DA40(); // 0x0044DA40
int __cdecl sub_0044DCC0(); // 0x0044DCC0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0
void __fastcall sub_004898D0(int nState); // 0x004898D0
void __cdecl sub_004A43E0(); // 0x004A43E0
void __cdecl sub_004B7C60(); // 0x004B7C60
int __cdecl sub_004F59A0(); // 0x004F59A0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840
int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel); // 0x006018F0
D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool); // 0x0065C430
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273E4[]; // 0x007273E4
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273F0[]; // 0x007273F0
extern const char* gaszDialogCels_007274AC[]; // 0x007274AC
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern void* gpCelFile_007BF071; // 0x007BF071
extern void* gpCelFile_007BF075; // 0x007BF075
extern void* gpCelFile_007BF079; // 0x007BF079
extern void* gpCelFile_007BF274; // 0x007BF274
extern int gnGlobal_007C02AC; // 0x007C02AC
extern int gnGlobal_007C02B0; // 0x007C02B0
extern void* gpCelFile_007C02BC; // 0x007C02BC
extern void* gpGlobal_007C0D43; // 0x007C0D43
extern int gnGlobal_007C0DBC; // 0x007C0DBC
extern int gnGlobal_007C0DC0; // 0x007C0DC0
extern void* gpCelFile_007C0DC8; // 0x007C0DC8
extern void* gpCelFile_007C0DCC; // 0x007C0DCC
extern void* gpCelFile_007C546C; // 0x007C546C

struct Unicode
{
    unsigned short wChar;
    Unicode();
};


struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

#pragma pack(push, 2)
struct T00479230
{
    T0044CB60* pFirst;
    int nLines;
    int nTextTop;
    int nTextBottom;
    unsigned short nWidth;
    unsigned short nHeight;
    unsigned short f_14;
    int nScroll;
    int nField1A;
    int nField1E;
    int nField22;
    int nField26;
    unsigned short nField2A;
};

#pragma pack(pop)

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, Unicode* wszDest, int nDest);
extern "C" __declspec(dllimport) int __stdcall IntersectRect(D2RectStrc* pDest, const D2RectStrc* pSrc1, const D2RectStrc* pSrc2);
extern "C" int __cdecl atoi(const char* szString);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __cdecl sub_0045AE90();
void __fastcall sub_0049D8E0_DrawTextList(T00479230* pTextBox, int nX, int nY);
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);
int __fastcall sub_00502EF0(int nArg);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __cdecl sub_00525150();
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x006611D0
unsigned char __stdcall CHAT_GetLangIdFromHoverMsg(D2HoverTextStrc* pHoverMsg);
extern int gaHoverDirs_00722654[];
extern int gnHoverDirCount_00722674;
extern D2RectStrc gaHoverRects_007BF0A8[16];
extern int gnGameFrame_007BF20E; // 0x007BF20E
extern D2CoordStrc gtHoverOffset_007BF214; // 0x007BF214
extern int gnHoverRectCount_007BF224; // 0x007BF224

#pragma pack(push, 2)
struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    D2TextNodeStrc* pNext;
};

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst;
    unsigned short wCount;
};

#pragma pack(pop)

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __fastcall D2Win_10123(const Unicode* wszText, int nLength); // 0x00501730
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
extern D2TextListStrc gtTextList_007BF1EA; // 0x007BF1EA

struct D2StringSoundStrc
{
    unsigned short wStringId;
    unsigned short wSoundId;
};

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC
extern "C" const char gszFormatSound_006DA194[]; // 0x006DA194
extern D2StringSoundStrc* gapClassStringSounds_00722F1C[]; // 0x00722F1C
extern D2StringSoundStrc gaMonStringSounds_00723750[]; // 0x00723750

static void __stdcall sub_004A0A00_ShowHoverText(const Unicode* wszText, D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText, D2CoordStrc* pPos);

char gaGlobal_007C0C68[1]; // 0x007C0C68

static int gnGlobal_007C0E4C; // 0x007C0E4C

static D2ClientDialogStrc* gpGlobal_007C0E54; // 0x007C0E54

static int gnGlobal_007C0E58; // 0x007C0E58

static int gnGlobal_007C0E5C; // 0x007C0E5C

// 0x0049C580
void __cdecl sub_0049C580_LoadPanelCels()
{
    char szPath[0x104];
    if (!gpCelFile_007BF071)
    {
        sprintf(szPath, "%s\\ui\\menu\\waygatebackground", szDataGlobal_006D4118);
        gpCelFile_007BF071 = sub_004788B0(szPath, 0);
    }
    if (!gpCelFile_007BF075)
    {
        if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
        {
            sprintf(szPath, "%s\\ui\\menu\\expwaygatetabs", szDataGlobal_006D4118);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\waygatetabs", szDataGlobal_006D4118);
        }
        gpCelFile_007BF075 = sub_004788B0(szPath, 0);
    }
    if (!gpCelFile_007BF079)
    {
        sprintf(szPath, "%s\\ui\\menu\\waygateicons", szDataGlobal_006D4118);
        gpCelFile_007BF079 = sub_004788B0(szPath, 0);
    }
}

// 0x0049FA10
void __cdecl sub_0049FA10_DrawPanelFrame()
{
    char szPath[0x104];
    D2CelContextStrc tContext;

    D2GFX_DrawBox(gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, gnGlobal_0071146C / 2, gnGlobal_00711470 - 0x30, 0, 5);

    void* pCelFile = gpCelFile_007BF274;
    if (!pCelFile)
    {
        wsprintfA(szPath, "%s\\UI\\MENU\\scroin", szDataGlobal_006D4118);
        pCelFile = sub_004788B0(szPath, 0);
        gpCelFile_007BF274 = pCelFile;
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCelFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x6D, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x6D, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x31, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x31, -1, 5, 0);
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = 10;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x115, gnGlobal_00711470 + gnGlobal_007A285C - 0x3D, -1, 5, 0);
}

// 0x004A23D0
void __cdecl sub_004A23D0_LoadPanelCels()
{
    char szPath[0x104];
    if (sub_00483350())
    {
        return;
    }
    if (!gpCelFile_007BF2D5)
    {
        sprintf(szPath, "%s\\ui\\menu\\questbackground", szDataGlobal_006D4118);
        gpCelFile_007BF2D5 = sub_004788B0(szPath, 0);
    }
    if (!gpCelFile_007BF2D9)
    {
        if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
        {
            sprintf(szPath, "%s\\ui\\menu\\expquesttabs", szDataGlobal_006D4118);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\questtabs", szDataGlobal_006D4118);
        }
        gpCelFile_007BF2D9 = sub_004788B0(szPath, 0);
    }
    if (!gpCelFile_007BF2D1)
    {
        sprintf(szPath, "%s\\ui\\menu\\questsockets", szDataGlobal_006D4118);
        gpCelFile_007BF2D1 = sub_004788B0(szPath, 0);
    }
    if (!gpCelFile_007BF2DD)
    {
        sprintf(szPath, "%s\\ui\\menu\\questdone", szDataGlobal_006D4118);
        gpCelFile_007BF2DD = sub_004788B0(szPath, 0);
    }
    if (!gpCelFile_007BF351)
    {
        sprintf(szPath, "%s\\ui\\menu\\invps", szDataGlobal_006D4118);
        gpCelFile_007BF351 = sub_004788B0(szPath, 0);
    }
    if (!gpCelFile_007BF34D)
    {
        sprintf(szPath, "%s\\ui\\menu\\questlast", szDataGlobal_006D4118);
        gpCelFile_007BF34D = sub_004788B0(szPath, 0);
    }
}

// 0x004A5190
void __cdecl sub_004A5190_InitTextSlider()
{
    char szPath[0x104];
    sub_004A43E0();
    sprintf(szPath, "%s\\UI\\Menu\\TextSlid", szDataGlobal_006D4118);
    gpCelFile_007C02BC = sub_004788B0(szPath, 0);
    sub_004A5060();
    gnGlobal_007C02AC = 0;
    gnGlobal_007C02B0 = 0;
}

// 0x004B23E0
void __cdecl sub_004B23E0_InitPartyPanel()
{
    char szPath[0x104];
    gnGlobal_007C0DC0 = 0;
    gnGlobal_007C0DBC = 0;
    GetTickCount();
    memset(gaGlobal_007C0C68, 0, 0x160);
    gpGlobal_007C0D43 = QUESTRECORD_AllocRecord(0);
    gpGlobal_007C0D47 = QUESTRECORD_AllocRecord(0);
    gnGlobal_007C0C6B = 0;
    sprintf(szPath, "%s\\ui\\panel\\buysell", szDataGlobal_006D4118);
    gpCelFile_007C0DC8 = sub_004788B0(szPath, 0);
    sprintf(szPath, "%s\\ui\\menu\\goldbtn", szDataGlobal_006D4118);
    gpCelFile_007C0DCC = sub_004788B0(szPath, 0);
    gnGlobal_007C0DED = 0;
    gbGlobal_007C0DE0 = 0;
    gnGlobal_007C0DF1 = 0;
    gnGlobal_007C0DE9 = 0;
}

// 0x004B7CD0
D2ClientDialogStrc* __fastcall sub_004B7CD0_CreateDialogFromFile(int nArg1, int nArg2, int nArg8, int nArgC, int nType, int nArg14)
{
    char szPath[0x104];
    D2CelContextStrc tContext;

    sub_004545C0(0);
    sub_004898D0(0);
    sub_0044DA40();
    if (!nArg8)
    {
        return 0;
    }
    if (nType >= 1)
    {
        return 0;
    }

    gnGlobal_007C0E5C += 1;
    D2ClientDialogStrc* pDialog = (D2ClientDialogStrc*)FOG_Alloc(sizeof(D2ClientDialogStrc), ".\\UI\\dialog.cpp", 0x396, 0);
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->pNext = gpGlobal_007C0E54;
    gpGlobal_007C0E54 = pDialog;
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->unk0x34 = 0;
    pDialog->unk0x38 = 0;
    pDialog->unk0x50 = 0;
    pDialog->unk0x4C = 0;
    pDialog->unk0x44 = -1;
    pDialog->unk0x5C = 2;
    pDialog->unk0x2C = 0;
    pDialog->unk0x30 = 0;
    pDialog->unk0xB08 = 0;
    pDialog->unk0x60 = nArg8;
    pDialog->unk0x64 = nArgC;
    pDialog->unk0x58 = 0;
    pDialog->unk0x14 = 0;
    pDialog->dwTick = GetTickCount();
    pDialog->unk0x18 = nArg14;
    pDialog->unk0x48 = -1;
    pDialog->unk0x10 = 0;
    pDialog->unk0x54 = 0;
    pDialog->unk0x0C = 1;
    sprintf(szPath, "%s\\ui\\menu\\%s", szDataGlobal_006D4118, gaszDialogCels_007274AC[nType]);
    pDialog->pCelFile = sub_004788B0(szPath, 0);

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pDialog->pCelFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    D2CelStrc* hCel = CelGetHandle(&tContext);
    D2_ASSERT(hCel, 0x3B3);
    pDialog->unk0x34 = sub_006018C0(hCel);
    pDialog->unk0x38 = sub_006018F0(hCel);
    pDialog->unk0x24 = nArg1;
    pDialog->unk0x28 = nArg2;
    pDialog->unk0x2C = nArg1;
    pDialog->unk0x30 = nArg2;
    gnGlobal_007C0E58 = 1;
    sub_004B7C60();
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_007273F0, 0xE);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_007273E4, 1);
    gnGlobal_007C0E4C += 1;
    D2_ASSERT(gnGlobal_007C0E5C == 1, 0x3C8);
    return pDialog;
}

// 0x004BE020
void __cdecl sub_004BE020_LoadTextSliderCel()
{
    char szPath[0x104];
    sprintf(szPath, "%s\\ui\\menu\\textslid", szDataGlobal_006D4118);
    gpCelFile_007C546C = sub_004788B0(szPath, 0);
}

#include "gen/data/Source/D2Client/UI/text_0049C580.inc"
struct D2BitBufferStrc;
struct D2CelFileStrc;

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0049D370
static void sub_0049D370_FreeTextLines(T0044CB60* pLine)
{
    while (pLine)
    {
        T0044CB60* pNext = pLine->pNext;
        FOG_Free(pLine->pText, ".\\UI\\text.cpp", 0x60F, 0);
        FOG_Free(pLine, ".\\UI\\text.cpp", 0x610, 0);
        pLine = pNext;
    }
}

// 0x0049D3C0
static void sub_0049D3C0_MeasureTextBox(T00479230* pBox)
{
    int nMaxWidth = 0;
    pBox->nTextTop = 0;
    pBox->nTextBottom = pBox->f_14;
    for (T0044CB60* pLine = pBox->pFirst; pLine; pLine = pLine->pNext)
    {
        nMaxWidth = nMaxWidth > sub_00501820(pLine->pText) ? nMaxWidth : sub_00501820(pLine->pText);
    }
    pBox->nWidth = nMaxWidth + 0x14;
    pBox->nHeight = pBox->nLines * 0x0F + 6;
}

// 0x0049D410
void __stdcall sub_0049D410_FreeTextBox(T00479230* pTextBox)
{
    if (pTextBox)
    {
        sub_0049D370_FreeTextLines(pTextBox->pFirst);
        FOG_Free(pTextBox, ".\\UI\\text.cpp", 0x68E, 0);
    }
}

// 0x0049D9A0
static int sub_0049D9A0_DrawTextBoxAt(T00479230* pTextBox, D2RectStrc* pRect)
{
    if (!pTextBox->nScroll)
        pTextBox->nScroll = 1;
    else if (pTextBox->nScroll == 3)
        return 1;

    switch (sub_0045AE90())
    {
    case 1:
        if (pRect->nLeft > gnGlobal_0071146C / 2 - 10)
            return 1;
        break;
    case 2:
        if (pRect->nLeft < gnGlobal_0071146C / 2 + 10)
            return 1;
        break;
    case 3:
        return 1;
    }
    sub_0049D8E0_DrawTextList(pTextBox, pRect->nLeft, pRect->nTop);
    return 1;
}

static bool __stdcall sub_0049E070_PlaceHoverRect(int nCount, D2RectStrc* pRect)
{
    if (nCount >= 0x10)
        return false;

    if (!nCount)
    {
        gaHoverRects_007BF0A8[0] = *pRect;
        return true;
    }

    for (int i = 0; i < nCount; ++i)
    {
        D2RectStrc tOverlap;
        if (IntersectRect(&tOverlap, &gaHoverRects_007BF0A8[i], pRect))
        {
            for (int nDX = 0x32; nDX < 0x190; nDX += 0x32)
            {
                for (int nDY = 0x23; nDY < 0x118; nDY += 0x23)
                {
                    for (int nDir = 0; nDir < gnHoverDirCount_00722674; ++nDir)
                    {
                        D2RectStrc tRect = *pRect;
                        tRect.nLeft += gaHoverDirs_00722654[nDir] * nDX;
                        tRect.nTop += gaHoverDirs_00722654[nDir] * nDY;
                        tRect.nRight = tRect.nLeft + 0x190;
                        tRect.nBottom = tRect.nTop + 0x118;
                        if (tRect.nLeft < 0 || tRect.nRight > gnGlobal_0071146C || tRect.nTop < 0 || tRect.nBottom > gnGlobal_00711470)
                            continue;

                        bool bOverlap = false;
                        for (int j = 0; j < nCount; ++j)
                        {
                            if (IntersectRect(&tOverlap, &gaHoverRects_007BF0A8[j], &tRect))
                                bOverlap = true;
                        }
                        if (!bOverlap)
                        {
                            gaHoverRects_007BF0A8[nCount] = tRect;
                            *pRect = tRect;
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    }

    gaHoverRects_007BF0A8[nCount] = *pRect;
    return true;
}

static bool sub_0049E280_ConvertHoverText(Unicode* wszText, const char* szText, int nLangId)
{
    if (nLangId != 7 && nLangId != 0xC && nLangId != 6 && nLangId != 9)
    {
        sub_00526F20_ToUnicode(wszText, szText, 0x100);
        return true;
    }

    MultiByteToWideChar(0, 1, szText, 0x100, wszText, 0x100);
    const int nCurrentLangId = sub_00525150();
    if (nCurrentLangId == nLangId)
        return true;
    if (nCurrentLangId == 7)
    {
        if (nLangId == 0xC)
            return true;
    }
    else if (nCurrentLangId == 0xC && nLangId == 7)
    {
        return true;
    }

    for (const Unicode* pChar = wszText; pChar->wChar; ++pChar)
    {
        if (pChar->wChar >= 0x80)
            return false;
    }
    return true;
}

void __fastcall sub_004A0B30_DrawUnitHoverText(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
        return;

    D2CoordStrc tPos;
    UNITS_GetClientCoords(pUnit, &tPos);
    tPos.nX -= gtHoverOffset_007BF214.nX;
    tPos.nY += -0x1E - gtHoverOffset_007BF214.nY;
    switch (sub_0045AE90())
    {
    case 1:
        tPos.nX -= gnGlobal_0071146C / 4;
        break;
    case 2:
        tPos.nX += gnGlobal_0071146C / 4;
        break;
    case 3:
        return;
    }

    if (tPos.nY <= 0 || tPos.nY >= gnGlobal_00711470)
        return;
    if (tPos.nX <= -0x64 || tPos.nX >= gnGlobal_0071146C + 0x64)
        return;

    char szText[0x100];
    CHAT_CopyHoverMsgToBuffer(pHoverText, szText);
    if (szText[0] == -1 && szText[1] == -1)
    {
        const int nStringId = atoi(&szText[2]);
        if ((nStringId >= 0x42D && nStringId <= 0x50F) || (nStringId >= 0x5587 && nStringId <= 0x5615)
            || nStringId == 0x2AA4 || nStringId == 0x5586)
        {
            const Unicode* wszString = D2LANG_GetStringFromTblIndex(nStringId);
            if (wszString)
            {
                Unicode wszBuffer[0xC8];
                memset(wszBuffer, 0, sizeof(wszBuffer));
                int nLength = sub_00526800(wszString);
                if (nLength >= 0xC8)
                    nLength = 0xC7;
                sub_00526790(wszBuffer, wszString, nLength);
                sub_004A0A00_ShowHoverText(wszBuffer, pUnit, pHoverText, &tPos);
                return;
            }
        }
    }

    Unicode wszHover[0x100];
    if (!sub_0049E280_ConvertHoverText(wszHover, szText, CHAT_GetLangIdFromHoverMsg(pHoverText)))
        return;
    wszHover[0xFF].wChar = 0;
    sub_004A0A00_ShowHoverText(wszHover, pUnit, pHoverText, &tPos);
}

// 0x004A0D20
void __fastcall sub_004A0D20_DrawObjectHoverText(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
        return;

    D2CoordStrc tPos;
    UNITS_GetClientCoords(pUnit, &tPos);
    tPos.nY += -0x0A - gtHoverOffset_007BF214.nY;
    tPos.nX -= gtHoverOffset_007BF214.nX;
    switch (sub_0045AE90())
    {
    case 1:
        tPos.nX -= gnGlobal_0071146C / 4;
        break;
    case 2:
        tPos.nX += gnGlobal_0071146C / 4;
        break;
    case 3:
        return;
    }

    if (tPos.nY <= 0 || tPos.nY >= gnGlobal_00711470)
        return;
    if (tPos.nX <= -0x64 || tPos.nX >= gnGlobal_0071146C + 0x64)
        return;

    char szText[0x100];
    CHAT_CopyHoverMsgToBuffer(pHoverText, szText);
    const int nStringId = atoi(szText);
    if (nStringId < 1 || nStringId > 0xFFFE)
        return;

    const Unicode* wszString = D2LANG_GetStringFromTblIndex(nStringId);
    if (!wszString)
        return;

    Unicode wszBuffer[0xC8];
    memset(wszBuffer, 0, sizeof(wszBuffer));
    int nLength = sub_00526800(wszString);
    if (nLength >= 0xC8)
        nLength = 0xC7;
    sub_00526790(wszBuffer, wszString, nLength);
    sub_004A0A00_ShowHoverText(wszBuffer, pUnit, pHoverText, &tPos);
}

// 0x0049DEE0
void __cdecl sub_0049DEE0_DrawOverheadTextList()
{
    if (!gtTextList_007BF1EA.wCount)
    {
        return;
    }

    int nOldFont = sub_00502EF0(13);
    D2TextNodeStrc* pNode = gtTextList_007BF1EA.pFirst;
    int nX = 15;
    if (sub_004538D0(6) || sub_004538D0(0x11))
    {
        nX = 100;
    }

    if (pNode)
    {
        int nBoxRow = 0;
        int nTextRow = 0;
        do
        {
            for (int i = 0; i < 6; ++i)
            {
                if (pNode->pLines[i])
                {
                    sub_0046EFD0_DrawFramedBox(nX - 5, gnGlobal_00711470 - 25 * nBoxRow - i * 25 / 2 - 0x81,
                                               D2Win_10123(pNode->pLines[i], sub_00526800(pNode->pLines[i])) + 10, 0x10, 0, 1);
                    sub_00502320(pNode->pLines[i], nX, gnGlobal_00711470 + 25 * nTextRow - i * 25 / 2 - 0x73, pNode->nColor, 0);
                }
            }
            pNode = pNode->pNext;
            ++nBoxRow;
            --nTextRow;
        }
        while (pNode);
    }

    pNode = gtTextList_007BF1EA.pFirst;
    D2TextNodeStrc* pPrev = 0;
    unsigned int dwNow = GetTickCount();
    while (pNode)
    {
        if (pNode->dwEndTick < dwNow)
        {
            --gtTextList_007BF1EA.wCount;
            D2TextNodeStrc* pNext = pNode->pNext;
            if (gtTextList_007BF1EA.pFirst == pNode)
            {
                gtTextList_007BF1EA.pFirst = pNext;
            }

            for (int j = 0; j < 6; ++j)
            {
                if (pNode->pLines[j])
                {
                    FOG_Free(pNode->pLines[j], ".\\UI\\text.cpp", 0x6B3, 0);
                }
            }
            FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);

            if (pPrev)
            {
                pPrev->pNext = pNext;
            }
            pNode = pNext;
        }
        else
        {
            pPrev = pNode;
            pNode = pNode->pNext;
        }
    }

    sub_00502EF0(nOldFont);
}

// 0x0049F410
static void __stdcall sub_0049F410_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    if (!strlen(szText))
    {
        if (pUnit->pHoverText)
            CHAT_FreeHoverMsg(0, pUnit->pHoverText);
        pUnit->pHoverText = 0;
        return;
    }

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(0, szText, gnGameFrame_007BF20E);
    CHAT_SetLangIdInHoverMsg(pHoverText, nLangId);
    if (pUnit->pHoverText)
        CHAT_FreeHoverMsg(0, pUnit->pHoverText);
    pUnit->pHoverText = pHoverText;
}

// 0x004A0200
void __fastcall sub_004A0200_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId)
{
    char szText[12];

    if (!pUnit)
        return;

    const int nLangId = sub_00525150();
    if (nLangId < 6)
        return;
    if (nLangId > 7 && nLangId != 9)
        return;
    if (nStringId < 0xB76 || nStringId > 0x1230)
        return;

    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == 0)
    {
        const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
        D2StringSoundStrc* pTable = gapClassStringSounds_00722F1C[nClassId];
        for (unsigned int i = 0; i < 0x4A; ++i)
        {
            if (pTable[i].wStringId == nStringId)
            {
                sprintf(szText, gszFormatSound_006DA194, -1, -1, pTable[i].wSoundId);
                sub_0049F410_SetHoverText(sub_00525150(), szText, pUnit);
                return;
            }
        }
    }
    else if (nUnitType == 1)
    {
        for (unsigned int i = 0; i < 6; ++i)
        {
            if (gaMonStringSounds_00723750[i].wStringId == nStringId)
            {
                sprintf(szText, gszFormatD_006D57BC, gaMonStringSounds_00723750[i].wSoundId);
                sub_0049F410_SetHoverText(sub_00525150(), szText, pUnit);
                return;
            }
        }
    }
}

// 0x004A0A00
static void __stdcall sub_004A0A00_ShowHoverText(const Unicode* wszText, D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText, D2CoordStrc* pPos)
{
    if (gnGameFrame_007BF20E > CHAT_GetTimeoutFromHoverMsg(pHoverText))
    {
        CHAT_FreeHoverMsg(0, pHoverText);
        if (pUnit)
            pUnit->pHoverText = 0;
    }

    const int nOldFont = sub_00502EF0(0x0D);
    T00479230* pTextBox = (T00479230*)FOG_Alloc(sizeof(T00479230), ".\\UI\\text.cpp", 0x65D, 0);
    pTextBox->pFirst = sub_00502970_SplitText(wszText, &pTextBox->nLines, 0xB4);
    sub_0049D3C0_MeasureTextBox(pTextBox);

    pPos->nX -= pTextBox->nWidth >> 1;
    pPos->nY -= 0x32;
    pPos->nY = pPos->nY - pTextBox->nLines * 0x0F - 3;

    D2RectStrc tRect;
    tRect.nTop = pPos->nY;
    tRect.nLeft = pPos->nX;
    tRect.nBottom = pTextBox->nHeight + pPos->nY;
    tRect.nRight = pTextBox->nWidth + pPos->nX;
    if (gnHoverRectCount_007BF224 < 0x10 && !sub_0049E070_PlaceHoverRect(gnHoverRectCount_007BF224, &tRect))
    {
        sub_0049D410_FreeTextBox(pTextBox);
        return;
    }

    ++gnHoverRectCount_007BF224;
    sub_0049D9A0_DrawTextBoxAt(pTextBox, &tRect);
    sub_0049D410_FreeTextBox(pTextBox);
    sub_00502EF0(nOldFont);
}
