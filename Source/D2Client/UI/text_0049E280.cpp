#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2RectStrc;
struct T00479230;
struct D2TextNodeStrc;
struct D2TextListStrc;
class ListBoxWrapper;

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

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, Unicode* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) int __stdcall IntersectRect(D2RectStrc* pDest, const D2RectStrc* pSrc1, const D2RectStrc* pSrc2); // 0x006CC4C4
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __cdecl sub_0045AE90(); // 0x0045AE90
void __fastcall sub_0049D8E0_DrawTextList(T00479230* pTextBox, int nX, int nY); // 0x0049D8E0
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall strncpy(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x006611D0
unsigned char __stdcall CHAT_GetLangIdFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x00661220
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gaHoverDirs_00722654[]; // 0x00722654
extern int gnHoverDirCount_00722674; // 0x00722674
extern D2RectStrc gaHoverRects_007BF0A8[16]; // 0x007BF0A8
extern int gnGameFrame_007BF20E; // 0x007BF20E
extern D2CoordStrc gtHoverOffset_007BF214; // 0x007BF214
extern int gnHoverRectCount_007BF224; // 0x007BF224
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

#pragma pack(push, 2)
struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    unsigned char pNext[4];
};

#pragma pack(pop)
class ListBoxWrapper
{
public:
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0C();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1C();
    virtual void Slot20(); virtual void Slot24(); virtual void Slot28(); virtual void Slot2C();
    virtual void Slot30(); virtual void Slot34(); virtual void Slot38();
    virtual void Refresh();
};

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
int __fastcall sub_00526D30_IsLineBreak(const Unicode* pText, unsigned int nIndex); // 0x00526D30
int __fastcall D2Win_10123(const Unicode* wszText, int nLength); // 0x00501730
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
void __fastcall sub_0049DBC0_AddToHistory(D2TextNodeStrc* pSource); // 0x0049DBC0
static void sub_0049D490_FreeTextNode(D2TextNodeStrc* pNode);
extern ListBoxWrapper* gpListBox_007BF1B4; // 0x007BF1B4
extern D2TextListStrc gtTextList_007BF1EA; // 0x007BF1EA

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
        FOG_Free(pTextBox, ".\\UI\\text.cpp", 0x68E, 0);
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

static inline int sub_F02_IntersectsAnyHoverRect(const D2RectStrc* pRect, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        D2RectStrc tOverlap;
        if (IntersectRect(&tOverlap, &gaHoverRects_007BF0A8[i], pRect))
            return 1;
    }
    return 0;
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

    if (!sub_F02_IntersectsAnyHoverRect(pRect, nCount))
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

// 0x0049E280
static bool sub_0049E280_ConvertHoverText(int nLangId, const char* szText, Unicode* wszText)
{
    if (nLangId != 7 && nLangId != 0xC && nLangId != 6 && nLangId != 9)
    {
        sub_00526F20_ToUnicode(wszText, szText, 0x100);
        return true;
    }

    MultiByteToWideChar(0, 1, szText, 0x100, wszText, 0x100);
    const int nCurrentLangId = STRTABLE_GetLanguage();
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
                strncpy(wszBuffer, wszString, nLength);
                sub_004A0A00_ShowHoverText(wszBuffer, pUnit, pHoverText, &tPos);
                return;
            }
        }
    }

    Unicode wszHover[0x100];
    if (!sub_0049E280_ConvertHoverText(CHAT_GetLangIdFromHoverMsg(pHoverText), szText, wszHover))
        return;
    wszHover[0xFF].wChar = 0;
    sub_004A0A00_ShowHoverText(wszHover, pUnit, pHoverText, &tPos);
}

// 0x0049D490
static void sub_0049D490_FreeTextNode(D2TextNodeStrc* pNode)
{
    for (int i = 0; i < 6; i++)
    {
        if (pNode->pLines[i])
            FOG_Free(pNode->pLines[i], ".\\UI\\text.cpp", 0x6B3, 0);
    }
    FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
}

// 0x0049E5C0
void __fastcall sub_0049E5C0_PrintPartyText(const Unicode* wszText, char nColor)
{
    const int nOldFont = sub_00502EF0(0xD);
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xDAD, 0);
    memset(pNode, 0, 0x24);
    *(D2TextNodeStrc**)pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;

    int nCount = sub_00526800(wszText);
    const int nTotal = nCount;
    int nStart = 0;
    pNode->nLines = 0;
    for (;;)
    {
        while (nCount > 0 && D2Win_10123(&wszText[nStart], nCount) > gnGlobal_0071146C - 0x46)
            nCount--;

        if (nStart + nCount != nTotal)
        {
            while (nCount > 0 && !sub_00526D30_IsLineBreak(&wszText[nStart], nCount + 1))
                nCount--;
        }

        if (!nCount)
            break;

        const Unicode* pSource = &wszText[nStart];
        int aLine[0x100];
        sub_005263E0((char*)aLine, pSource, nCount);
        if (pNode->nLines >= 6)
            break;

        const int nSize = nCount * 2 + 2;
        pNode->pLines[pNode->nLines] = (Unicode*)FOG_Alloc(nSize, ".\\UI\\text.cpp", 0xDD7, 0);
        memset(pNode->pLines[pNode->nLines], 0, nSize);
        strncpy(pNode->pLines[pNode->nLines], pSource, nCount);
        pNode->nLines++;
        nStart = nCount;
        nCount = nTotal - nCount;
    }
    pNode->nColor = (unsigned char)nColor;

    if (gtTextList_007BF1EA.pFirst)
    {
        D2TextNodeStrc* pLast = gtTextList_007BF1EA.pFirst;
        unsigned short nNodes = 0;
        D2TextNodeStrc** ppNext = (D2TextNodeStrc**)pLast->pNext;
        if (*ppNext)
        {
            do
            {
                pLast = *ppNext;
                ppNext = (D2TextNodeStrc**)pLast->pNext;
                nNodes++;
            } while (*ppNext);
        }
        D2_ASSERT(nNodes == gtTextList_007BF1EA.wCount - 1, 0xDF1);
        *(D2TextNodeStrc**)pLast->pNext = pNode;
    }
    else
    {
        gtTextList_007BF1EA.pFirst = pNode;
    }
    gtTextList_007BF1EA.wCount++;
    sub_0049DBC0_AddToHistory(pNode);

    if (gtTextList_007BF1EA.wCount > 2)
    {
        D2TextNodeStrc* pFirst = gtTextList_007BF1EA.pFirst;
        gtTextList_007BF1EA.pFirst = *(D2TextNodeStrc**)gtTextList_007BF1EA.pFirst->pNext;
        sub_0049D490_FreeTextNode(pFirst);
        gtTextList_007BF1EA.wCount--;
    }

    if (sub_004538D0(0x18) && gpListBox_007BF1B4)
    {
        gpListBox_007BF1B4->Refresh();
        sub_0049E340();
    }
    sub_00502EF0(nOldFont);
    sub_004B9A00(6, 0, 0, 0, 0);
}
