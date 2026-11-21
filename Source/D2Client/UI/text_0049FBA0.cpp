#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2Path.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;

struct D2ScrollPosStrc;

struct Unicode;

struct D2ScrollPosStrc
{
    int nX;
    int nY;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0

void __cdecl sub_0049FA10_DrawPanelFrame(); // 0x0049FA10

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

extern D2ScrollPosStrc gaScrollPiecePos_00722EB8[5]; // 0x00722EB8

extern D2ScrollPosStrc gaScrollFadePos_00722EE0[5]; // 0x00722EE0

extern unsigned int gaScrollThresholds_00722F08[5]; // 0x00722F08

extern unsigned short gawScrollSlots_007BF098[5]; // 0x007BF098

extern unsigned int gdwScrollTick_007BF243; // 0x007BF243

extern unsigned int gnScrollCounter_007BF247; // 0x007BF247

extern D2CelFileStrc* gpScroin3_007BF26C; // 0x007BF26C

extern D2CelFileStrc* gpScroin2_007BF270; // 0x007BF270

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

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

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);

int __cdecl sub_0045AE90();

void __fastcall sub_0049D8E0_DrawTextList(T00479230* pTextBox, int nX, int nY);

T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

int __cdecl sub_00525150();

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);

void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords);                       // 0x00620900

void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);

unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg);

unsigned char __stdcall CHAT_GetLangIdFromHoverMsg(D2HoverTextStrc* pHoverMsg);                             // 0x00661220

extern "C" const char gszTextSourceFile[];

extern int gnGlobal_0071146C;                                                                               // 0x0071146C

extern int gnGlobal_00711470;                                                                               // 0x00711470

extern int gaHoverDirs_00722654[];

extern int gnHoverDirCount_00722674;

extern D2RectStrc gaHoverRects_007BF0A8[16];

extern int gnGameFrame_007BF20E;

extern D2CoordStrc gtHoverOffset_007BF214;                                                                  // 0x007BF214

extern int gnHoverRectCount_007BF224;

// 0x0049FBA0
void __stdcall sub_0049FBA0_OpenTextPanel(int bDraw)
{
    if (!sub_00463DD0_GetPlayerUnit())
    {
        return;
    }

    D2CelContextStrc tPiece;
    memset(&tPiece, 0, sizeof(tPiece));
    sub_0049FA10_DrawPanelFrame();

    if (!gpScroin2_007BF270)
    {
        char szPath[0x104] = { 0 };
        sprintf(szPath, "%s\\%s", "DATA\\GLOBAL", "UI\\menu\\scroin2");
        gpScroin2_007BF270 = sub_004788B0(szPath, 0);
    }

    if (!gpScroin3_007BF26C)
    {
        char szPath[0x104] = { 0 };
        sprintf(szPath, "%s\\%s", "DATA\\GLOBAL", "UI\\menu\\scroin3");
        gpScroin3_007BF26C = sub_004788B0(szPath, 0);
    }

    if (!bDraw)
    {
        return;
    }

    const int nOldMode = sub_00502EF0(5);
    tPiece.pCellFile = gpScroin2_007BF270;
    if (!gdwScrollTick_007BF243)
    {
        gdwScrollTick_007BF243 = GetTickCount();
        gnScrollCounter_007BF247 = 0;
    }
    else if (gdwScrollTick_007BF243 + 50 < GetTickCount())
    {
        gdwScrollTick_007BF243 = GetTickCount();
        ++gnScrollCounter_007BF247;
    }

    for (int i = 0; i < 5; ++i)
    {
        if (gnScrollCounter_007BF247 > gaScrollThresholds_00722F08[i])
        {
            const int nTicks = gnScrollCounter_007BF247 - gaScrollThresholds_00722F08[i];
            tPiece.nFrame = i;
            int nDrawMode = 5;
            if (nTicks == 1)
            {
                sub_004B9A00(0xA6F, 0, 0, 0, 0);
            }
            if (nTicks < 5)
            {
                nDrawMode = 0;
            }
            else if (nTicks < 10)
            {
                nDrawMode = 1;
            }
            else if (nTicks < 15)
            {
                nDrawMode = 2;
            }

            const unsigned short nSlot = gawScrollSlots_007BF098[i];
            if (nSlot < 6)
            {
                D2_ASSERT(nSlot < 5, 0x1673);
                TEXTURE_CelDraw(&tPiece, gaScrollPiecePos_00722EB8[nSlot].nX + gnGlobal_007A2858, gaScrollPiecePos_00722EB8[nSlot].nY - gnGlobal_007A285C, -1, nDrawMode, 0);

                D2CelContextStrc tFade;
                memset(&tFade, 0, sizeof(tFade));
                tFade.pCellFile = gpScroin3_007BF26C;
                tFade.nFrame = nTicks >= 21 ? 0 : nTicks;
                TEXTURE_CelDraw(&tFade, gaScrollFadePos_00722EE0[nSlot].nX + gnGlobal_007A2858, gaScrollFadePos_00722EE0[nSlot].nY - gnGlobal_007A285C, -1, 3, 0);
            }
        }
    }

    sub_00502EF0(nOldMode);
}

// build: context TEXT_ReadLine
static __forceinline const unsigned short* TEXT_ReadLine(Unicode* pLine, const unsigned short* pText)
{
    int i = 0;
    memset(pLine, 0, 100 * sizeof(Unicode));
    for (; i < 100 && *pText != '\n'; ++i)
    {
        pLine[i] = *pText++;
    }
    if (i < 100 && *pText == '\n')
    {
        ++pText;
    }
    return pText;
}

// 0x004A0320
T0044CB60* __stdcall sub_004A0320_BuildTextLines(const unsigned short* wszText, int* pLineCount, unsigned short* pMaxLines)
{
    Unicode szLine[100];
    const unsigned short* pText = wszText;

    *pLineCount = 0;
    T0044CB60* pLast = 0;
    T0044CB60* pFirst = 0;
    int bFirstLine = 1;
    while (*pText)
    {
        pText = TEXT_ReadLine(szLine, pText);

        T0044CB60* pLine = (T0044CB60*)FOG_Alloc(sizeof(T0044CB60), ".\\UI\\text.cpp", 0x5B8, 0);
        if (bFirstLine == 1)
        {
            const int nLength = sub_00526800(szLine);
            int bAscii = 1;
            for (int j = 0; j < nLength; ++j)
            {
                if (szLine[j].wChar >= 0x80)
                {
                    bAscii = 0;
                }
            }

            if (bAscii)
            {
                char szNumber[100];
                sub_005263E0(szNumber, szLine, 100);
                *pMaxLines = atoi(szNumber);
            }
            else
            {
                char szMessage[80];
                wsprintfA(szMessage, "line 0 of string does not contain scroll rate");
                *pMaxLines = 8;
            }

            bFirstLine = 0;
            pText = TEXT_ReadLine(szLine, pText);
        }

        const int nLength = sub_00526800(szLine);
        if (sub_00501820(szLine) >= 0x134)
        {
            char szMessage[80];
            wsprintfA(szMessage, "line %d of string is too long", *pLineCount);
        }

        pLine->pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nLength + 1), ".\\UI\\text.cpp", 0x5EB, 0);
        sub_005267E0(pLine->pText, szLine);
        pLine->pNext = 0;
        if (pLast)
        {
            pLast->pNext = pLine;
        }
        else
        {
            pFirst = pLine;
        }
        ++*pLineCount;
        pLast = pLine;
    }
    return pFirst;
}

static void sub_0049D370_FreeTextLines(T0044CB60* pLine)
{
    while (pLine)
    {
        T0044CB60* pNext = pLine->pNext;
        FOG_Free(pLine->pText, gszTextSourceFile, 0x60F, 0);
        FOG_Free(pLine, gszTextSourceFile, 0x610, 0);
        pLine = pNext;
    }
}

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

void __stdcall sub_0049D410_FreeTextBox(T00479230* pTextBox)
{
    if (pTextBox)
    {
        sub_0049D370_FreeTextLines(pTextBox->pFirst);
        FOG_Free(pTextBox, gszTextSourceFile, 0x68E, 0);
    }
}

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

static __forceinline int sub_J06_IntersectsAnyHoverRect(const D2RectStrc* pRect, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        D2RectStrc tOverlap;
        if (IntersectRect(&tOverlap, &gaHoverRects_007BF0A8[i], pRect))
            return 1;
    }
    return 0;
}

// build: context sub_0049E070_PlaceHoverRect
static bool __stdcall sub_0049E070_PlaceHoverRect(int nCount, D2RectStrc* pRect)
{
    if (nCount >= 0x10)
        return false;

    if (!nCount)
    {
        gaHoverRects_007BF0A8[0] = *pRect;
        return true;
    }

    if (!sub_J06_IntersectsAnyHoverRect(pRect, nCount))
    {
        gaHoverRects_007BF0A8[nCount] = *pRect;
        return true;
    }

    int nDir;
    for (int nDX = 0x32; nDX < 0x190; nDX += 0x32)
    {
        for (int nDY = 0x23; nDY < 0x118; nDY += 0x23)
        {
            for (nDir = 0; gnHoverDirCount_00722674 > nDir; ++nDir)
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
                    D2RectStrc tTest;
                    if (IntersectRect(&tTest, &gaHoverRects_007BF0A8[j], &tRect))
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

static bool sub_0049E280_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText)
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

    for (; wszText->wChar; ++wszText)
    {
        if (wszText->wChar >= 0x80)
            return false;
    }
    return true;
}

static void __stdcall sub_004A0A00_ShowHoverText(const Unicode* wszText, D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText, D2CoordStrc* pPos)
{
    if (gnGameFrame_007BF20E > CHAT_GetTimeoutFromHoverMsg(pHoverText))
    {
        CHAT_FreeHoverMsg(0, pHoverText);
        if (pUnit)
            pUnit->pHoverText = 0;
    }

    const int nOldFont = sub_00502EF0(0x0D);
    T00479230* pTextBox = (T00479230*)FOG_Alloc(sizeof(T00479230), gszTextSourceFile, 0x65D, 0);
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

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A0B30
void __fastcall sub_004A0B30_DrawUnitHoverText(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
        return;

    D2CoordStrc tPos;
    UNITS_GetClientCoords(pUnit, &tPos);
    tPos.nY += -0x1E - gtHoverOffset_007BF214.nY;
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

    char szText[0x104];
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
    if (!sub_0049E280_ConvertHoverText(CHAT_GetLangIdFromHoverMsg(pHoverText), wszHover, szText))
        return;
    wszHover[0xFF].wChar = 0;
    sub_004A0A00_ShowHoverText(wszHover, pUnit, pHoverText, &tPos);
}

#include "gen/data/Source/D2Client/UI/text_0049FBA0.inc"
