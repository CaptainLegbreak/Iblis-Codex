#include "D2Client.h"

struct Unicode
{
    unsigned short wChar;

    Unicode();
};

struct D2CoordStrc
{
    int nX;
    int nY;
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

struct D2UnitStrc
{
    char unk0x00[0xA4];
    D2HoverTextStrc* pHoverText;
};

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, Unicode* wszDest, int nDest);
extern "C" __declspec(dllimport) int __stdcall IntersectRect(D2RectStrc* pDest, const D2RectStrc* pSrc1, const D2RectStrc* pSrc2);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" int __cdecl atoi(const char* szString);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);
int __cdecl sub_0045AE90();
void __fastcall sub_0049D8E0_DrawTextList(T00479230* pTextBox, int nX, int nY);
int __fastcall sub_00501820(const Unicode* wszText);
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);
int __fastcall sub_00502EF0(int nArg);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __cdecl sub_00525150();
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
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
