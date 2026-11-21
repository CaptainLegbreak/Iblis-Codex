#include "D2Win.h"
#include "D2Win32Types.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"
#include "D2CelContext.h"
#include "D2WinTypes.h"

#pragma function(memset)

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;

struct D2WinEditBoxStrc;

struct UnicodeChar;

struct SMSGHANDLER_PARAMS;

struct Obj004FDA80;

// build: symbol _strncpy 0x00687330
struct Unicode
{
    unsigned short wChar;
    static Unicode* __fastcall strcat(Unicode* pDest, const Unicode* pSource);                             // 0x00526700
// build: symbol ?strncpy@Unicode@@SIPAU1@PAU1@PBU1@H@Z 0x00526790
    static Unicode* __fastcall strncpy(Unicode* pDest, const Unicode* pSource, int nCount);                // 0x00526790
    static Unicode* __fastcall win2Unicode(Unicode* pDest, const char* szSource, int nCount);              // 0x00526F20
};

typedef int (__stdcall* D2WinEditBoxFilterFn)(D2WinEditBoxStrc* pEditBox, int nCaret, char* pKey);

typedef void (__stdcall* D2WinEditBoxChangeFn)(int nArg);

typedef void (__stdcall* D2WinEditBoxEnterFn)(Unicode* pText);

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

void __fastcall sub_004FDCC0(D2WinEditBoxStrc* pEditBox); // 0x004FDCC0

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall sub_004F91C0(D2WinEditBoxStrc* pEditBox); // 0x004F91C0

int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

int __stdcall D2Win_10125(); // 0x00501A40

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

struct Obj004FDA80
{
    unsigned short wValue00;
};

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" int __fastcall sub_004FDA80(Obj004FDA80* pObj); // 0x004FDA80

extern "C" unsigned short* __fastcall sub_005267E0_2(unsigned short* pDst, const unsigned short* pSrc); // 0x005267E0

extern "C" int __fastcall sub_00526800_2(const unsigned short* pText); // 0x00526800

const char* __cdecl sub_004FDB40_GetClipboardText(); // 0x004FDB40

int __fastcall sub_004FDBB0_SetClipboardText(const char* szText); // 0x004FDBB0

int __fastcall D2Win_10082(D2WinEditBoxStrc* pEditBox); // 0x004FDD00

unsigned int __fastcall D2Win_10128(unsigned char nChar); // 0x00502550

static __declspec(noinline) void sub_004FE9F0_DeleteSelection(D2WinEditBoxStrc* pEditBox);

struct D2WinControlStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

#define D2WIN_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2WIN_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);                                 // 0x006CC45C

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

extern int gnWinCallbackDepth_007D55C4;                                                                     // 0x007D55C4

int __stdcall sub_004FE3B0_EditBoxClick(SMSGHANDLER_PARAMS* pMsg, int nX, int nY);                          // 0x004FE3B0

static int sub_004FDC70_HasSelection(D2WinEditBoxStrc* pEditBox);

static void sub_004FE9F0_DeleteSelection(D2WinEditBoxStrc* pEditBox);

static void sub_004FE7C0_UpdateVisibleChars(D2WinEditBoxStrc* pEditBox);

struct Character;

struct Character { signed char value; };

enum { FIRST_DIGIT = 48, LAST_DIGIT = 57 };

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern tagPOINT gMousePosition_6F8FE234; // 0x007D55A4

void __cdecl sub_004FE7C0_UpdateVisibleChars(); // 0x004FE7C0

#define EDITBOX_MIN(a, b) ((a) < (b) ? (a) : (b))

#define EDITBOX_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2CelContextStrc;

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300

int __stdcall sub_004FFBF0_EditBoxMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x004FFBF0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __fastcall D2Win_10133(const Unicode* wszText, int nX, int nY, int nColor, int nDrawMode, int nTextColor); // 0x00502480

D2WinEditBoxStrc* gpLastClickedEditBox_00841B78; // 0x00841B78

static unsigned long gdwLastClickTick_00841B7C; // 0x00841B7C

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinFontAndColorStrc
{
    int eFont;
    int nColor;
};



int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210

int __stdcall EDITBOX_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg);                                              // 0x004FE350

int __fastcall sub_004FF620_EditBoxDrawAlt(D2WinEditBoxStrc* pEditBox);                                     // 0x004FF620

int __fastcall sub_004FFE50_EditBoxDraw(D2WinEditBoxStrc* pEditBox);                                        // 0x004FFE50

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840

int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0

// 0x004FDC70
static int sub_004FDC70_HasSelection(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x198);
    D2_ASSERT(pEditBox->controlHeader.eType == 1, 0x19A);
    if (pEditBox->nSelectionStart != -1 && pEditBox->nSelectionStart != pEditBox->nSelectionEnd)
        return 1;
    return 0;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FDE30
static int __stdcall sub_004FDE30_GetEditTextHeight(const Unicode* wszText, D2WinEditBoxStrc* ptEditData)
{
    D2_ASSERT(ptEditData, 0x5EA);
    D2_ASSERT(ptEditData->controlHeader.eType == 1, 0x5EC);
    Unicode wszDash[2];
    sub_00502EF0(ptEditData->eFont);
    const int nStartY = D2Win_10125() + (ptEditData->nTextInsetY - ptEditData->controlHeader.nHeight) + ptEditData->controlHeader.nImageY;
    char szDash[] = "_";
    wszDash[0].wChar = 0;
    wszDash[1].wChar = 0;
    Unicode::win2Unicode(wszDash, szDash, 2);
    const int nDashWidth = D2Win_10122(wszDash, 2);
    Unicode wszLine[256];
    for (int i = 0; i < 256; ++i)
    {
        wszLine[i].wChar = 0;
    }
    char szText[256];
    sub_00526F70(szText, wszText, 256);
    const char* pLine = szText;
    const char* pChar = szText;
    int nY = nStartY;
    const int nLineHeight = D2Win_10125();
    const int nMaxWidth = ptEditData->controlHeader.nWidth - 2 * ptEditData->nTextInsetX;
    while (*pChar)
    {
        int nPos = pChar - pLine;
        int bWrapped = 0;
        char szLine[256];
        memset(szLine, 0, sizeof(szLine));
        while (*pChar && *pChar != '\r' && *pChar != '\n')
        {
            szLine[nPos] = *pChar;
            Unicode::win2Unicode(wszLine, szLine, 256);
            if (D2Win_10122(wszLine, nPos) + nDashWidth > nMaxWidth)
            {
                bWrapped = 1;
                break;
            }
            ++pChar;
            ++nPos;
        }
        Unicode::win2Unicode(wszLine, szLine, 256);
        if (bWrapped)
        {
            nY += nLineHeight;
        }
        if (*pChar == '\r')
        {
            if (pChar[1] == '\n')
            {
                do
                {
                    if (pChar[1] != '\n')
                    {
                        break;
                    }
                    pChar += 2;
                    nY += nLineHeight;
                }
                while (*pChar == '\r');
            }
            else
            {
                do
                {
                    ++pChar;
                    nY += nLineHeight;
                }
                while (*pChar == '\r');
            }
        }
        pLine = pChar;
    }
    return nY - nStartY;
}

// 0x004FDFF0
static void __stdcall sub_004FDFF0_GetCaretPosition(int* pX, int* pY, D2WinEditBoxStrc* ptEditData)
{
    D2_ASSERT(ptEditData, 0x648);
    D2_ASSERT(ptEditData->controlHeader.eType == 1, 0x64A);
    Unicode wszCopy[300];
    for (int i = 0; i < 300; ++i)
    {
        wszCopy[i].wChar = 0;
    }
    Unicode wszDash[2];
    sub_00502EF0(ptEditData->eFont);
    const int nStartX = ptEditData->controlHeader.nImageX + ptEditData->nTextInsetX;
    const int nStartY = D2Win_10125() + (ptEditData->nTextInsetY - ptEditData->controlHeader.nHeight) + ptEditData->controlHeader.nImageY;
    sub_005267E0(wszCopy, (Unicode*)ptEditData->wszText);
    char szDash[] = "_";
    wszDash[0].wChar = 0;
    wszDash[1].wChar = 0;
    sub_00526F20_ToUnicode(wszDash, szDash, 2);
    const int nDashWidth = D2Win_10122(wszDash, 2);
    Unicode wszLine[256];
    for (int i = 0; i < 256; ++i)
    {
        wszLine[i].wChar = 0;
    }
    char szText[256];
    sub_00526F70(szText, (Unicode*)ptEditData->wszText, 256);
    const char* pLine = szText;
    const char* pChar = szText;
    int nY = nStartY;
    const int nLineHeight = D2Win_10125();
    const int nMaxWidth = ptEditData->controlHeader.nWidth - 2 * ptEditData->nTextInsetX;
    const int nMaxHeight = ptEditData->controlHeader.nHeight - 2 * ptEditData->nTextInsetY;
    *pX = -1;
    *pY = -1;
    while (*pChar)
    {
        if (nY - nStartY >= nMaxHeight)
        {
            break;
        }
        int nPos = pChar - pLine;
        int bWrapped = 0;
        char szLine[256];
        memset(szLine, 0, sizeof(szLine));
        while (*pChar && *pChar != '\r' && *pChar != '\n')
        {
            szLine[nPos] = *pChar;
            sub_00526F20_ToUnicode(wszLine, szLine, 256);
            if (D2Win_10122(wszLine, nPos) + nDashWidth > nMaxWidth)
            {
                bWrapped = 1;
                break;
            }
            ++pChar;
            ++nPos;
        }
        const int nCaret = ptEditData->nCaretPosition - (pLine - szText);
        if (*pX == -1 && nCaret >= 0 && nCaret <= nPos)
        {
            int nX = nStartX;
            if (nCaret)
            {
                sub_00526F20_ToUnicode(wszLine, szLine, 256);
                nX += D2Win_10122(wszLine, nCaret);
            }
            *pX = nX;
            *pY = nY;
        }
        if (bWrapped)
        {
            nY += nLineHeight;
        }
        if (*pChar == '\r')
        {
            if (pChar[1] == '\n')
            {
                do
                {
                    if (pChar[1] != '\n')
                    {
                        break;
                    }
                    pChar += 2;
                    nY += nLineHeight;
                    if (*pX == -1 && ptEditData->nCaretPosition == pChar - szText && nY - nStartY < nMaxHeight)
                    {
                        *pX = nStartX;
                        *pY = nY;
                    }
                }
                while (*pChar == '\r');
            }
            else
            {
                do
                {
                    ++pChar;
                    nY += nLineHeight;
                    if (*pX == -1 && ptEditData->nCaretPosition == pChar - szText && nY - nStartY < nMaxHeight)
                    {
                        *pX = nStartX;
                        *pY = nY;
                    }
                }
                while (*pChar == '\r');
            }
        }
        pLine = pChar;
    }
    if (*pX != -1)
    {
        *pX = *pX - ptEditData->controlHeader.nImageX - 1;
        *pY += ptEditData->controlHeader.nHeight - ptEditData->controlHeader.nImageY - 1;
        *pX = D2WIN_MIN(D2WIN_MAX(*pX, ptEditData->nTextInsetX), ptEditData->controlHeader.nWidth - ptEditData->nTextInsetX - 1);
        *pY = D2WIN_MIN(D2WIN_MAX(*pY, ptEditData->nTextInsetY), ptEditData->controlHeader.nHeight - ptEditData->nTextInsetY - 1);
    }
}

int sub_A23_Emit_004FDC70(D2WinEditBoxStrc* pEditBox, unsigned char nKey)
{
    if (nKey != 0x18 && nKey != 1)
        return 0;
    return sub_004FDC70_HasSelection(pEditBox);
}

int __fastcall sub_A23_Emit_004FE9F0(D2WinEditBoxStrc* pEditBox, int nKey)
{
    if (nKey != 0x18 && nKey != 1)
        sub_004FE9F0_DeleteSelection(pEditBox);
    return sub_00526800((Unicode*)pEditBox->wszText) + pEditBox->nCaretPosition;
}

// 0x004FE3B0
int __stdcall sub_004FE3B0_EditBoxClick(SMSGHANDLER_PARAMS* pMsg, int nX, int nY)
{
    D2WinEditBoxStrc* ptEditData = (D2WinEditBoxStrc*)pMsg->hWnd;

    D2_ASSERT(ptEditData, 0x74E);
    D2_ASSERT(ptEditData->controlHeader.eType == 1, 0x74F);

    if (!(ptEditData->controlHeader.dwFlags & gdwBitMasks[2]) || !(ptEditData->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }

    sub_004F91C0(ptEditData);
    if (ptEditData->bMouseSelecting)
    {
        nX = D2WIN_MIN(D2WIN_MAX(nX, ptEditData->nTextInsetX), ptEditData->controlHeader.nWidth - ptEditData->nTextInsetX - 1);
        nY = D2WIN_MIN(D2WIN_MAX(nY, ptEditData->nTextInsetY), ptEditData->controlHeader.nHeight - ptEditData->nTextInsetY - 1);
    }

    if (nX >= -ptEditData->nTextInsetX && nX < ptEditData->controlHeader.nWidth - ptEditData->nTextInsetX
        && nY >= -ptEditData->nTextInsetY && nY < ptEditData->controlHeader.nHeight - ptEditData->nTextInsetY)
    {
        sub_00502EF0(ptEditData->eFont);
        char szDash[] = "_";
        UnicodeChar wszDash[2];
        sub_00526F20_ToUnicode(wszDash, szDash, 2);
        const int nDashWidth = sub_00501820(wszDash);
        char szText[256];
        sub_00526F70(szText, (Unicode*)ptEditData->wszText, 256);
        const char* pLine = szText;
        const char* pChar = szText;
        int nLineY = 0;
        int nLineHeight = D2Win_10125();
        const int nMaxWidth = ptEditData->controlHeader.nWidth - 2 * ptEditData->nTextInsetX;
        int bFound = 0;
        int nOldCaret = -1;
        while (*pChar)
        {
            UnicodeChar wszLine[256];
            int nPos = pChar - pLine;
            int bWrapped = 0;
            char szLine[256];
            memset(szLine, 0, sizeof(szLine));
            while (*pChar && *pChar != '\r' && *pChar != '\n')
            {
                szLine[nPos] = *pChar;
                sub_00526F20_ToUnicode(wszLine, szLine, 256);
                if (D2Win_10122(wszLine, nPos) + nDashWidth > nMaxWidth)
                {
                    bWrapped = 1;
                    break;
                }
                ++pChar;
                ++nPos;
            }

            const int nNextLineY = nLineY + nLineHeight;
            if (nY >= nLineY && nY < nNextLineY)
            {
                int nChars = 1;
                sub_00526F20_ToUnicode(wszLine, szLine, 256);
                while (nX > D2Win_10122(wszLine, nChars))
                {
                    if (nChars > nPos)
                    {
                        break;
                    }
                    ++nChars;
                }
                nOldCaret = ptEditData->nCaretPosition;
                ptEditData->nCaretPosition = pLine - szText + nChars - 1;
                bFound = 1;
            }

            if (!bWrapped)
            {
                if (*pChar == '\r')
                {
                    if (pChar[1] != '\n')
                    {
                        ++pChar;
                        nLineY += nLineHeight;
                    }
                    else
                    {
                        pChar += 2;
                        nLineY += nLineHeight;
                    }
                }
            }
            else
            {
                nLineY += nLineHeight;
            }
            pLine = pChar;
        }

        if (!bFound)
        {
            nOldCaret = ptEditData->nCaretPosition;
            ptEditData->nCaretPosition = sub_00526800((Unicode*)ptEditData->wszText);
        }

        if ((((unsigned int)GetKeyState(0x10) & 0x8000) || ptEditData->bMouseSelecting) && nOldCaret != -1)
        {
            if (ptEditData->nSelectionStart == -1)
            {
                ptEditData->nSelectionStart = nOldCaret;
            }
            ptEditData->nSelectionEnd = ptEditData->nCaretPosition;
        }
        else
        {
            sub_004FDCC0(ptEditData);
        }
    }

    if (pMsg->uMessage == 0x201)
    {
        ptEditData->bMouseSelecting = 1;
    }

    if (ptEditData->controlHeader.field_34)
    {
        return ptEditData->controlHeader.field_34(pMsg);
    }

    return 0;
}

// 0x004FE770
int __stdcall sub_004FE770(void* unused1,void* unused2,const Character* text)
{
    return text->value>=FIRST_DIGIT && text->value<=LAST_DIGIT;
}

// 0x004FE7C0
static void sub_004FE7C0_UpdateVisibleChars(D2WinEditBoxStrc* pEditBox)
{
    sub_00502EF0(pEditBox->eFont);
    int nAvail = pEditBox->controlHeader.nWidth - 2 * pEditBox->nTextInsetX;
    const int nLength = sub_00526800((Unicode*)pEditBox->wszText);
    Unicode wszText[300];
    for (int i = 0; i < 300; ++i)
    {
        wszText[i].wChar = 0;
    }
    if (pEditBox->dwEditBoxFlags & 1)
    {
        char szStar[] = "*";
        Unicode wszStar[2];
        wszStar[0].wChar = 0;
        wszStar[1].wChar = 0;
        sub_00526F20_ToUnicode(wszStar, szStar, 2);
        if (nLength > 0)
        {
            for (int i = 0; i < nLength; ++i)
            {
                wszText[i] = wszStar[0];
            }
        }
    }
    else
    {
        sub_005267E0(wszText, (Unicode*)pEditBox->wszText);
    }
    const int nTextWidth = sub_00501820(wszText);
    char szDash[] = "_";
    Unicode wszDash[2];
    wszDash[0].wChar = 0;
    wszDash[1].wChar = 0;
    sub_00526F20_ToUnicode(wszDash, szDash, 2);
    const int nDashWidth = sub_00501820(wszDash);
    const int nWidth = pEditBox->nCaretPosition == nLength ? nTextWidth + nDashWidth : nTextWidth;
    if (nWidth > nAvail)
    {
        if (pEditBox->nCaretPosition == nLength)
        {
            nAvail -= nDashWidth;
        }
        if (pEditBox->nCaretPosition > pEditBox->nLastVisibleChar)
        {
            pEditBox->nLastVisibleChar = pEditBox->nCaretPosition;
            pEditBox->nFirstVisibleChar = pEditBox->nCaretPosition - 1;
            while (pEditBox->nFirstVisibleChar)
            {
                if (D2Win_10122(&wszText[pEditBox->nFirstVisibleChar], pEditBox->nLastVisibleChar - pEditBox->nFirstVisibleChar + 1) >= nAvail)
                {
                    break;
                }
                --pEditBox->nFirstVisibleChar;
            }
            ++pEditBox->nFirstVisibleChar;
        }
        else if (pEditBox->nCaretPosition <= pEditBox->nFirstVisibleChar + 1)
        {
            const int nFirst = pEditBox->nCaretPosition - 1;
            pEditBox->nFirstVisibleChar = nFirst < 0 ? 0 : nFirst;
            pEditBox->nLastVisibleChar = pEditBox->nFirstVisibleChar + 1;
            while (pEditBox->nLastVisibleChar < nLength)
            {
                if (D2Win_10122(&wszText[pEditBox->nFirstVisibleChar], pEditBox->nLastVisibleChar - pEditBox->nFirstVisibleChar + 1) >= nAvail)
                {
                    break;
                }
                ++pEditBox->nLastVisibleChar;
            }
            --pEditBox->nLastVisibleChar;
        }
        else if (sub_00501820(&wszText[pEditBox->nFirstVisibleChar]) < nAvail)
        {
            pEditBox->nLastVisibleChar = nLength - 1;
            pEditBox->nFirstVisibleChar = pEditBox->nLastVisibleChar - 1;
            while (pEditBox->nFirstVisibleChar)
            {
                if (sub_00501820(&wszText[pEditBox->nFirstVisibleChar]) >= nAvail)
                {
                    break;
                }
                --pEditBox->nFirstVisibleChar;
            }
            ++pEditBox->nFirstVisibleChar;
        }
        else
        {
            pEditBox->nLastVisibleChar = pEditBox->nFirstVisibleChar + 1;
            while (pEditBox->nLastVisibleChar < nLength)
            {
                if (D2Win_10122(&wszText[pEditBox->nFirstVisibleChar], pEditBox->nLastVisibleChar - pEditBox->nFirstVisibleChar + 1) >= nAvail)
                {
                    break;
                }
                ++pEditBox->nLastVisibleChar;
            }
            --pEditBox->nLastVisibleChar;
        }
    }
    else
    {
        pEditBox->nLastVisibleChar = nLength - 1;
        pEditBox->nFirstVisibleChar = 0;
    }
}

// 0x004FE9F0
static __declspec(noinline) void sub_004FE9F0_DeleteSelection(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x1C2);
    D2_ASSERT(pEditBox->controlHeader.eType == 1, 0x1C4);
    Unicode wszHead[256];
    Unicode wszTail[256];
    for (int i = 0; i < 256; ++i)
    {
        wszHead[i].wChar = 0;
    }
    for (int i = 0; i < 256; ++i)
    {
        wszTail[i].wChar = 0;
    }
    const int nStart = pEditBox->nSelectionStart < pEditBox->nSelectionEnd ? pEditBox->nSelectionStart : pEditBox->nSelectionEnd;
    const int nEnd = pEditBox->nSelectionStart > pEditBox->nSelectionEnd ? pEditBox->nSelectionStart : pEditBox->nSelectionEnd;
    if (nStart)
    {
        sub_00526790(wszHead, (Unicode*)pEditBox->wszText, nStart);
    }
    else
    {
        wszHead[0].wChar = 0;
    }
    sub_005267E0(wszTail, (Unicode*)&pEditBox->wszText[nEnd]);
    sub_005267E0((Unicode*)pEditBox->wszText, wszHead);
    sub_00526700((Unicode*)pEditBox->wszText, wszTail);
    const int nLength = sub_00526800((Unicode*)pEditBox->wszText);
    if (nStart <= nLength)
    {
        pEditBox->nCaretPosition = nStart;
    }
    else
    {
        pEditBox->nCaretPosition = nLength;
    }
    sub_004FDCC0(pEditBox);
}

// 0x004FEAE0
int __fastcall D2Win_10074(D2WinEditBoxStrc* pEditBox, char nChar)
{
    D2_ASSERT(pEditBox, 0x1F6);
    D2_ASSERT(pEditBox->controlHeader.eType == 1, 0x1F8);
    if (!(pEditBox->controlHeader.dwFlags & gdwBitMasks[2]) || !(pEditBox->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }
    if (nChar == 9 && (pEditBox->dwEditBoxFlags & 4))
    {
        if (pEditBox->pfFilter)
        {
            ++gnWinCallbackDepth_007D55C4;
            ((D2WinEditBoxFilterFn)pEditBox->pfFilter)(pEditBox, pEditBox->nCaretPosition, &nChar);
            --gnWinCallbackDepth_007D55C4;
        }
        return 0;
    }
    {
        Unicode wKey;
        wKey.wChar = (unsigned char)nChar;
        if (!D2Win_10128(nChar))
        {
            const unsigned int dwEditBoxFlags = pEditBox->dwEditBoxFlags;
            if (!((dwEditBoxFlags & 0x20) && sub_004FDA80((Obj004FDA80*)&wKey))
                && !((dwEditBoxFlags & 8) && nChar == '\r')
                && !((dwEditBoxFlags & 0x10) && nChar == 0x0E)
                && nChar != 0x16 && nChar != 3 && nChar != 0x18 && nChar != 1)
            {
                return 0;
            }
        }
    }
    if (pEditBox->pfFilter && !((D2WinEditBoxFilterFn)pEditBox->pfFilter)(pEditBox, pEditBox->nCaretPosition, &nChar)
        && nChar != 0x16 && nChar != 3 && nChar != 0x18 && nChar != 1)
    {
        return 0;
    }
    if (sub_004FDC70_HasSelection(pEditBox) && nChar != 3 && nChar != 0x18 && nChar != 1)
    {
        sub_004FE9F0_DeleteSelection(pEditBox);
    }
    int nLength = sub_00526800_2(&pEditBox->wszText[0]);
    UnicodeChar wszText[512];
    sub_005267E0_2(&wszText[0].wChar, &pEditBox->wszText[0]);
    UnicodeChar* pCaret = &wszText[pEditBox->nCaretPosition];
    switch (nChar)
    {
    case 0x16:
    {
        const char* szClip = sub_004FDB40_GetClipboardText();
        if ((int)strlen(szClip) + nLength > pEditBox->nMaxLength - 1)
        {
            return 0;
        }
        if (pEditBox->pfFilter)
        {
            const int nClipLength = strlen(szClip);
            const int nCaret = pEditBox->nCaretPosition;
            for (int i = 0; i < nClipLength; ++i)
            {
                if (!D2Win_10128(szClip[i]))
                {
                    return 0;
                }
                if (!((D2WinEditBoxFilterFn)pEditBox->pfFilter)(pEditBox, nCaret + i, (char*)&szClip[i]))
                {
                    return 0;
                }
            }
        }
        UnicodeChar wszHead[256];
        UnicodeChar wszClip[256];
        UnicodeChar wszTail[256];
        int nStart;
        int nEnd;
        if (pEditBox->nSelectionStart == -1)
        {
            nStart = pEditBox->nCaretPosition;
            nEnd = nStart;
        }
        else
        {
            nStart = D2WIN_MIN(pEditBox->nSelectionStart, pEditBox->nSelectionEnd);
            nEnd = D2WIN_MAX(pEditBox->nSelectionStart, pEditBox->nSelectionEnd);
        }
        char szPaste[400];
        if (pEditBox->dwEditBoxFlags & 8)
        {
            strcpy(szPaste, szClip);
        }
        else
        {
            char* pDst = szPaste;
            for (const char* pSrc = szClip; *pSrc; ++pSrc)
            {
                if (*pSrc != '\r' && *pSrc != '\n')
                {
                    *pDst++ = *pSrc;
                }
            }
            *pDst = 0;
        }
        Unicode::strncpy(wszHead, wszText, nStart);
        sub_005267E0_2(&wszTail[0].wChar, &wszText[nEnd].wChar);
        Unicode::win2Unicode(wszClip, szPaste, strlen(szPaste) + 1);
        sub_005267E0_2(&wszText[0].wChar, &wszHead[0].wChar);
        Unicode::strcat(wszText, wszClip);
        Unicode::strcat(wszText, wszTail);
        sub_004FDCC0(pEditBox);
        pCaret = &wszText[nStart + strlen(szPaste)];
        break;
    }
    case 3:
        if (sub_004FDC70_HasSelection(pEditBox))
        {
            const int nStart = D2WIN_MIN(pEditBox->nSelectionStart, pEditBox->nSelectionEnd);
            const int nEnd = D2WIN_MAX(pEditBox->nSelectionStart, pEditBox->nSelectionEnd);
            char szCopy[256];
            sub_00526F70(szCopy, &wszText[nStart], D2WIN_MAX(nEnd - nStart + 1, 2));
            sub_004FDBB0_SetClipboardText(szCopy);
        }
        break;
    case 0x18:
        if (sub_004FDC70_HasSelection(pEditBox))
        {
            const int nStart = D2WIN_MIN(pEditBox->nSelectionStart, pEditBox->nSelectionEnd);
            const int nEnd = D2WIN_MAX(pEditBox->nSelectionStart, pEditBox->nSelectionEnd);
            char szCut[256];
            sub_00526F70(szCut, &wszText[nStart], D2WIN_MAX(nEnd - nStart + 1, 2));
            pCaret = &wszText[nStart];
            sub_004FDBB0_SetClipboardText(szCut);
            sub_004FE9F0_DeleteSelection(pEditBox);
            nLength = sub_00526800_2(&pEditBox->wszText[0]);
            sub_005267E0_2(&wszText[0].wChar, &pEditBox->wszText[0]);
        }
        break;
    case 1:
        D2Win_10082(pEditBox);
        break;
    default:
        if (nLength >= pEditBox->nMaxLength - 1)
        {
            return 0;
        }
        if (nLength < 0xFF)
        {
            char szKey[256];
            if (nChar == '\r')
            {
                sub_00526F70(&szKey[2], pCaret, 256);
                szKey[0] = '\r';
                szKey[1] = '\n';
                Unicode::win2Unicode(pCaret, szKey, 256);
                pCaret += 2;
            }
            else
            {
                sub_00526F70(&szKey[1], pCaret, 256);
                szKey[0] = nChar;
                Unicode::win2Unicode(pCaret, szKey, 256);
                ++pCaret;
            }
            sub_004FDCC0(pEditBox);
        }
        break;
    }
    const int nMaxHeight = pEditBox->controlHeader.nHeight - 2 * pEditBox->nTextInsetY;
    if ((pEditBox->dwEditBoxFlags & 8) && sub_004FDE30_GetEditTextHeight(wszText, pEditBox) >= nMaxHeight)
    {
        return 1;
    }
    sub_005267E0_2(&pEditBox->wszText[0], &wszText[0].wChar);
    pEditBox->nCaretPosition = pCaret - wszText;
    sub_004FE7C0_UpdateVisibleChars(pEditBox);
    if (pEditBox->pfOnChange)
    {
        ((D2WinEditBoxChangeFn)pEditBox->pfOnChange)(0);
    }
    return 1;
}

// 0x004FF050
int __fastcall sub_004FF050_EditBoxKeyDown(D2WinEditBoxStrc* ptEditData, char nKey)
{
    Unicode* pChar;
    D2_ASSERT(ptEditData, 0x300);
    D2_ASSERT(ptEditData->controlHeader.eType == 1, 0x302);
    if (!(ptEditData->controlHeader.dwFlags & gdwBitMasks[2]) || !(ptEditData->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }
    pChar = (Unicode*)&ptEditData->wszText[ptEditData->nCaretPosition];
    int bChanged = 0;
    int bDeleted = 0;
    const int bShift = ((unsigned int)GetKeyState(0x10) >> 15) & 1;
    switch (nKey)
    {
    case 8:
    case 46:
        if (sub_004FDC70_HasSelection(ptEditData))
        {
            sub_004FE9F0_DeleteSelection(ptEditData);
            bChanged = 1;
            bDeleted = 1;
            pChar = (Unicode*)&ptEditData->wszText[ptEditData->nCaretPosition];
        }
        break;
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
        if (bShift)
        {
            if (ptEditData->nSelectionStart == -1)
            {
                ptEditData->nSelectionStart = ptEditData->nCaretPosition;
                ptEditData->nSelectionEnd = ptEditData->nCaretPosition;
            }
        }
        else
        {
            sub_004FDCC0(ptEditData);
        }
        break;
    }
    switch (nKey)
    {
    case 36:
        pChar = (Unicode*)ptEditData->wszText;
        if (bShift)
        {
            ptEditData->nSelectionEnd = 0;
        }
        break;
    case 35:
        while (pChar->wChar)
        {
            ++pChar;
        }
        if (bShift)
        {
            ptEditData->nSelectionEnd = pChar - (Unicode*)ptEditData->wszText;
        }
        break;
    case 38:
        if (ptEditData->dwEditBoxFlags & 8)
        {
            int nX;
            int nY;
            sub_004FDFF0_GetCaretPosition(&nX, &nY, ptEditData);
            const int nLineHeight = D2Win_10125();
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = ptEditData;
            msg.uMessage = 0;
            sub_004FE3B0_EditBoxClick(&msg, nX, nY - nLineHeight);
            pChar = (Unicode*)&ptEditData->wszText[ptEditData->nCaretPosition];
        }
        else
        {
            pChar = (Unicode*)ptEditData->wszText;
            if (bShift)
            {
                ptEditData->nSelectionEnd = 0;
            }
        }
        break;
    case 40:
        if (ptEditData->dwEditBoxFlags & 8)
        {
            int nX;
            int nY;
            sub_004FDFF0_GetCaretPosition(&nX, &nY, ptEditData);
            const int nLineHeight = D2Win_10125();
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = ptEditData;
            msg.uMessage = 0;
            sub_004FE3B0_EditBoxClick(&msg, nX, nY + nLineHeight);
            pChar = (Unicode*)&ptEditData->wszText[ptEditData->nCaretPosition];
        }
        else
        {
            while (pChar->wChar)
            {
                ++pChar;
            }
            if (bShift)
            {
                ptEditData->nSelectionEnd = pChar - (Unicode*)ptEditData->wszText;
            }
        }
        break;
    case 37:
        --pChar;
        if (pChar->wChar == '\n')
        {
            --pChar;
        }
        if (pChar < (Unicode*)ptEditData->wszText)
        {
            pChar = (Unicode*)ptEditData->wszText;
        }
        else if (bShift && ptEditData->nSelectionStart != -1)
        {
            ptEditData->nSelectionEnd = pChar - (Unicode*)ptEditData->wszText;
        }
        break;
    case 39:
        if (pChar->wChar)
        {
            ++pChar;
            if (pChar->wChar && pChar->wChar == '\n')
            {
                ++pChar;
            }
            if (bShift && ptEditData->nSelectionStart != -1)
            {
                ptEditData->nSelectionEnd = pChar - (Unicode*)ptEditData->wszText;
            }
        }
        break;
    case 8:
        if (pChar > (Unicode*)ptEditData->wszText && !bDeleted)
        {
            --pChar;
            const int nLength = sub_00526800(pChar + 1) + 1;
            memmove(pChar, pChar + 1, 2 * nLength);
            if (pChar > (Unicode*)ptEditData->wszText && pChar[-1].wChar == '\r')
            {
                --pChar;
                memmove(pChar, pChar + 1, 2 * nLength);
            }
            bChanged = 1;
        }
        break;
    case 46:
        if (pChar->wChar && !bDeleted)
        {
            const int nLength = sub_00526800(pChar + 1) + 1;
            memmove(pChar, pChar + 1, 2 * nLength);
            if (pChar->wChar && pChar->wChar == '\n')
            {
                memmove(pChar, pChar + 1, 2 * (nLength - 1));
            }
            bChanged = 1;
        }
        break;
    case 13:
        if (ptEditData->pfOnEnter)
        {
            const unsigned int bKeepFocus = ptEditData->dwEditBoxFlags & 2;
            ++gnWinCallbackDepth_007D55C4;
            ((D2WinEditBoxEnterFn)ptEditData->pfOnEnter)((Unicode*)ptEditData->wszText);
            --gnWinCallbackDepth_007D55C4;
            if (bKeepFocus)
            {
                pChar = (Unicode*)&ptEditData->wszText[ptEditData->nCaretPosition];
            }
            else
            {
                goto LABEL_DONE;
            }
        }
        break;
    case 27:
        if (ptEditData->pfOnEnter)
        {
            ++gnWinCallbackDepth_007D55C4;
            ((D2WinEditBoxEnterFn)ptEditData->pfOnEnter)(0);
            --gnWinCallbackDepth_007D55C4;
        }
    LABEL_DONE:
        return 1;
    case 9:
    {
        D2WinEditBoxStrc* pFocus;
        if (GetKeyState(0x10) >= 0)
        {
            pFocus = ptEditData->pNext;
            if (!pFocus)
            {
                return 1;
            }
            do
            {
                if (pFocus == ptEditData)
                {
                    break;
                }
                if ((pFocus->controlHeader.dwFlags & gdwBitMasks[2]) && (pFocus->controlHeader.dwFlags & gdwBitMasks[0]))
                {
                    break;
                }
                pFocus = pFocus->pNext;
            }
            while (pFocus);
        }
        else
        {
            pFocus = ptEditData->pPrevious;
            if (!pFocus)
            {
                return 1;
            }
            do
            {
                if (pFocus == ptEditData)
                {
                    break;
                }
                if ((pFocus->controlHeader.dwFlags & gdwBitMasks[2]) && (pFocus->controlHeader.dwFlags & gdwBitMasks[0]))
                {
                    break;
                }
                pFocus = pFocus->pPrevious;
            }
            while (pFocus);
        }
        sub_004F91C0(pFocus);
        D2Win_10082(pFocus);
        return 1;
    }
    case 112:
        return 0;
    }
    ptEditData->nCaretPosition = pChar - (Unicode*)ptEditData->wszText;
    sub_004FE7C0_UpdateVisibleChars(ptEditData);
    if (bChanged && ptEditData->pfFilter && !((D2WinEditBoxFilterFn)ptEditData->pfFilter)(ptEditData, ptEditData->nCaretPosition, &nKey) && nKey != 8 && nKey != 46)
    {
        return 0;
    }
    if (ptEditData->pfOnChange)
    {
        ((D2WinEditBoxChangeFn)ptEditData->pfOnChange)(0);
    }
    return 1;
}

// 0x004FF5A0
int __fastcall sub_004FF5A0(D2WinEditBoxStrc* pEditBox, const Unicode* pText)
{
    D2_ASSERT(pEditBox, 0x45E);
    D2_ASSERT(pEditBox->controlHeader.eType == 1, 0x460);
    const int nLength = sub_00526800(pText);
    if (nLength)
    {
        sub_005267E0((Unicode*)pEditBox->wszText, pText);
    }
    else
    {
        pEditBox->wszText[0] = 0;
    }
    pEditBox->nCaretPosition = nLength;
    sub_004FE7C0_UpdateVisibleChars(pEditBox);
    if (pEditBox->pfOnChange)
    {
        ((D2WinEditBoxChangeFn)pEditBox->pfOnChange)(0);
    }
    return 1;
}

// 0x004FF620
int __fastcall sub_004FF620_EditBoxDrawAlt(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x510);
    D2_ASSERT(pEditBox->controlHeader.eType == 1, 0x512);

    if (pEditBox->controlHeader.dwFlags & gdwBitMasks[2] && pEditBox->controlHeader.dwFlags & gdwBitMasks[0])
    {
        if (!sub_004FA460())
        {
            pEditBox->bMouseSelecting = 0;
        }

        if (pEditBox->bMouseSelecting)
        {
            SMSGHANDLER_PARAMS tMsg;
            tMsg.hWnd = pEditBox;
            tMsg.uMessage = 0x201;
            sub_004FE710_EditBoxMouseDownAlt(&tMsg);
        }

        UnicodeChar wszText[300];
        sub_00502EF0(pEditBox->eFont);
        const int nX = pEditBox->controlHeader.nImageX + pEditBox->nTextInsetX;
        const int nYStart = D2Win_10125() + pEditBox->controlHeader.nImageY - pEditBox->controlHeader.nHeight + pEditBox->nTextInsetY;
        sub_005267E0(wszText, (Unicode*)pEditBox->wszText);
        int nY = nYStart;
        const unsigned char nShade = D2Win_10034_MixRGB(0x40, 0x40, 0x40);

        char szCaret[] = "_";
        UnicodeChar wszCaret[2];
        sub_00526F20_ToUnicode(wszCaret, szCaret, 2);
        const int nCaretWidth = D2Win_10122(wszCaret, 2);

        int bBlink;
        if (sub_004F9200() == (int)pEditBox && GetTickCount() / 250 & 1)
            bBlink = 1;
        else
            bBlink = 0;

        int bCaretDrawn = 0;
        UnicodeChar wszLine[256];
        char szText[256];
        sub_00526F70(szText, (Unicode*)pEditBox->wszText, 256);
        char* pLineStart = szText;
        char* pCur = szText;
        const int nLineHeight = D2Win_10125();
        const int nMaxWidth = pEditBox->controlHeader.nWidth - 2 * pEditBox->nTextInsetX;
        const int nMaxHeight = pEditBox->controlHeader.nHeight - 2 * pEditBox->nTextInsetY;

        if (!szText[0] && bBlink)
        {
            sub_00502320(wszCaret, nX, nYStart, pEditBox->nTextColor, 0);
            bCaretDrawn = 1;
        }

        while (*pCur)
        {
            if (nY - nYStart >= nMaxHeight)
                break;

            int nLen = pCur - pLineStart;
            char szLine[256];
            int bWrap = 0;
            memset(szLine, 0, sizeof(szLine));
            while (*pCur && *pCur != '\r' && *pCur != '\n')
            {
                szLine[nLen] = *pCur;
                sub_00526F20_ToUnicode(wszLine, szLine, 256);
                if (D2Win_10122(wszLine, nLen) + nCaretWidth > nMaxWidth)
                {
                    bWrap = 1;
                    break;
                }
                ++nLen;
                ++pCur;
            }

            if (sub_004FDC70_HasSelection(pEditBox))
            {
                int nSelMin = pEditBox->nSelectionStart < pEditBox->nSelectionEnd ? pEditBox->nSelectionStart : pEditBox->nSelectionEnd;
                int nSelMax = pEditBox->nSelectionStart > pEditBox->nSelectionEnd ? pEditBox->nSelectionStart : pEditBox->nSelectionEnd;
                const int nLineBegin = pLineStart - szText;
                const int nLineEnd = pCur - szText;
                int nDrawX = nX;
                int nWidth;
                int nHeight;
                if (nSelMin < nLineBegin && nSelMax >= nLineEnd)
                {
                    strncpy(szLine, pLineStart, nLen);
                    szLine[pCur - pLineStart] = 0;
                    sub_00526F20_ToUnicode(wszLine, szLine, 256);
                    D2Win_10131_GetTextDimensions(wszLine, &nWidth, &nHeight);
                    D2GFX_DrawBox(nDrawX, nY - nLineHeight, nDrawX + nWidth, nY, nShade, 5);
                }
                else if (nSelMin >= nLineBegin && nSelMin < nLineEnd || nSelMax >= nLineBegin && nSelMax < nLineEnd)
                {
                    const int nFrom = nSelMin > nLineBegin ? nSelMin : nLineBegin;
                    const int nTo = nSelMax < nLineEnd ? nSelMax : nLineEnd;
                    const int nSkip = nFrom - nLineBegin;
                    if (nSkip)
                    {
                        strncpy(szLine, pLineStart, nSkip);
                        szLine[nSkip] = 0;
                        sub_00526F20_ToUnicode(wszLine, szLine, 256);
                        D2Win_10131_GetTextDimensions(wszLine, &nWidth, &nHeight);
                        nDrawX = nWidth + nX;
                    }
                    const int nCount = nTo - nFrom;
                    strncpy(szLine, pLineStart + nSkip, nCount);
                    szLine[nCount] = 0;
                    sub_00526F20_ToUnicode(wszLine, szLine, 256);
                    D2Win_10131_GetTextDimensions(wszLine, &nWidth, &nHeight);
                    D2GFX_DrawBox(nDrawX, nY - nLineHeight, nDrawX + nWidth, nY, nShade, 5);
                }
            }

            strncpy(szLine, pLineStart, nLen);
            szLine[pCur - pLineStart] = 0;
            sub_00526F20_ToUnicode(wszLine, szLine, 256);
            sub_00502320(wszLine, nX, nY, pEditBox->nTextColor, 0);

            if (bBlink && !bCaretDrawn)
            {
                const int nCaretOffset = pEditBox->nCaretPosition - (pLineStart - szText);
                if (nCaretOffset >= 0 && nCaretOffset <= nLen)
                {
                    int nCaretX = nX;
                    if (nCaretOffset)
                        nCaretX = D2Win_10122(wszLine, nCaretOffset) + nX;
                    sub_00502320(wszCaret, nCaretX, nY, pEditBox->nTextColor, 0);
                    bCaretDrawn = 1;
                }
            }

            if (bWrap)
                nY += nLineHeight;

            if (*pCur == '\r')
            {
                if (pCur[1] == '\n')
                {
                    while (*pCur == '\r' && pCur[1] == '\n')
                    {
                        pCur += 2;
                        nY += nLineHeight;
                        if (bBlink && !bCaretDrawn && pEditBox->nCaretPosition == pCur - szText && nY - nYStart < nMaxHeight)
                            sub_00502320(wszCaret, nX, nY, pEditBox->nTextColor, 0);
                    }
                }
                else
                {
                    while (*pCur == '\r')
                    {
                        ++pCur;
                        nY += nLineHeight;
                        if (bBlink && !bCaretDrawn && pEditBox->nCaretPosition == pCur - szText && nY - nYStart < nMaxHeight)
                            sub_00502320(wszCaret, nX, nY, pEditBox->nTextColor, 0);
                    }
                }
            }

            pLineStart = pCur;
        }
    }

    return 1;
}

// 0x004FFBF0
int __stdcall sub_004FFBF0_EditBoxMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinEditBoxStrc* ptEditData = (D2WinEditBoxStrc*)pMsg->hWnd;

    D2_ASSERT(ptEditData, 0x6D0);
    D2_ASSERT(ptEditData->controlHeader.eType == 1, 0x6D1);

    if (!(ptEditData->controlHeader.dwFlags & gdwBitMasks[2]) || !(ptEditData->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }

    int nX = gMousePosition_6F8FE234.x;
    int nY = gMousePosition_6F8FE234.y;
    sub_004F91C0(ptEditData);
    nX -= ptEditData->controlHeader.nImageX + ptEditData->nTextInsetX;
    nY += ptEditData->controlHeader.nHeight - ptEditData->nTextInsetY - ptEditData->controlHeader.nImageY;
    const int nRight = ptEditData->controlHeader.nWidth - ptEditData->nTextInsetX;
    const int bInside = nX >= -ptEditData->nTextInsetX && nX < nRight && nY > -ptEditData->nTextInsetY && nY < ptEditData->controlHeader.nHeight - ptEditData->nTextInsetY;

    const unsigned long dwTick = GetTickCount();
    if (bInside && !ptEditData->bMouseSelecting && ptEditData == gpLastClickedEditBox_00841B78 && dwTick - gdwLastClickTick_00841B7C < 300)
    {
        D2Win_10082(ptEditData);
    }
    else
    {
        if (ptEditData->bMouseSelecting || bInside)
        {
            int nChars = 1;
            sub_00502EF0(ptEditData->eFont);
            if (ptEditData->bMouseSelecting)
            {
                if (nX < -ptEditData->nTextInsetX)
                {
                    ptEditData->nCaretPosition = D2WIN_MAX(ptEditData->nCaretPosition - 1, 0);
                    sub_004FE7C0_UpdateVisibleChars();
                }
                else if (nX >= nRight)
                {
                    const int nLength = sub_00526800((Unicode*)ptEditData->wszText);
                    ptEditData->nCaretPosition = D2WIN_MIN(ptEditData->nCaretPosition + 1, nLength - 1);
                    sub_004FE7C0_UpdateVisibleChars();
                }
            }

            while (nX > D2Win_10122((Unicode*)&ptEditData->wszText[ptEditData->nFirstVisibleChar], nChars))
            {
                if (nChars > sub_00526800((Unicode*)&ptEditData->wszText[ptEditData->nFirstVisibleChar]))
                {
                    break;
                }
                ++nChars;
            }

            const int nOldCaret = ptEditData->nCaretPosition;
            ptEditData->nCaretPosition = ptEditData->nFirstVisibleChar + nChars - 1;
            if (!((unsigned int)GetKeyState(0x10) & 0x8000) && !ptEditData->bMouseSelecting)
            {
                sub_004FDCC0(ptEditData);
            }
            else
            {
                if (ptEditData->nSelectionStart == -1)
                {
                    ptEditData->nSelectionStart = nOldCaret;
                }
                ptEditData->nSelectionEnd = ptEditData->nCaretPosition;
            }
        }

        if (pMsg->uMessage == 0x201)
        {
            ptEditData->bMouseSelecting = 1;
        }
    }

    gpLastClickedEditBox_00841B78 = ptEditData;
    gdwLastClickTick_00841B7C = dwTick;
    if (ptEditData->controlHeader.field_34)
    {
        return ptEditData->controlHeader.field_34(pMsg);
    }

    return 0;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FFE50
int __fastcall sub_004FFE50_EditBoxDraw(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x49C);
    D2_ASSERT(pEditBox->controlHeader.eType == 1, 0x49E);

    if (pEditBox->controlHeader.dwFlags & gdwBitMasks[2] && pEditBox->controlHeader.dwFlags & gdwBitMasks[0])
    {
        if (!sub_004FA460())
        {
            pEditBox->bMouseSelecting = 0;
        }

        if (pEditBox->bMouseSelecting)
        {
            SMSGHANDLER_PARAMS tMsg;
            tMsg.hWnd = pEditBox;
            tMsg.uMessage = 0x201;
            sub_004FFBF0_EditBoxMouseDown(&tMsg);
        }

        UnicodeChar wszText[300];
        if (pEditBox->controlHeader.pCellFile)
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = pEditBox->controlHeader.pCellFile;
            tContext.nDirection = 0;
            tContext.nFrame = 0;
            sub_004F6480(&tContext, pEditBox->controlHeader.nImageX, pEditBox->controlHeader.nImageY - 1, -1, 5, 0);
        }

        sub_00502EF0(pEditBox->eFont);
        int nX = pEditBox->nTextInsetX + pEditBox->controlHeader.nImageX;
        const int nY = pEditBox->nTextInsetY - pEditBox->controlHeader.nHeight + pEditBox->controlHeader.nImageY + 16;
        sub_00526790(wszText, (Unicode*)&pEditBox->wszText[pEditBox->nFirstVisibleChar], pEditBox->nLastVisibleChar - pEditBox->nFirstVisibleChar + 1);
        const int nLength = sub_00526800(wszText);
        if (pEditBox->dwEditBoxFlags & 1)
        {
            char szStar[] = "*";
            UnicodeChar wszStar[2];
            sub_00526F20_ToUnicode(wszStar, szStar, 2);
            if (nLength > 0)
            {
                for (int i = 0; i < nLength; ++i)
                {
                    wszText[i] = wszStar[0];
                }
            }
        }

        if (sub_004FDC70_HasSelection(pEditBox))
        {
            const unsigned char nShade = D2Win_10034_MixRGB(0x40, 0x40, 0x40);
            UnicodeChar wszHead[256];
            UnicodeChar wszSelected[256];
            UnicodeChar wszTail[256];
            const int nStart = EDITBOX_MAX(0, EDITBOX_MIN(pEditBox->nSelectionStart, pEditBox->nSelectionEnd) - pEditBox->nFirstVisibleChar);
            const int nCount = EDITBOX_MAX(0, EDITBOX_MAX(pEditBox->nSelectionStart, pEditBox->nSelectionEnd) - pEditBox->nFirstVisibleChar - nStart);
            sub_00526790(wszHead, wszText, nStart);
            sub_00526790(wszSelected, &wszText[nStart], nCount);
            sub_005267E0(wszTail, &wszText[nStart + nCount]);
            int nWidth1;
            int nWidth2;
            int nHeight;
            D2Win_10131_GetTextDimensions(wszHead, &nWidth1, &nHeight);
            D2Win_10131_GetTextDimensions(wszSelected, &nWidth2, &nHeight);
            nWidth1 += nX;
            const int nTailX = nWidth1 + nWidth2;
            sub_00502320(wszHead, nX, nY, pEditBox->nTextColor, 0);
            D2Win_10133(wszSelected, nWidth1, nY, nShade, 5, pEditBox->nTextColor);
            sub_00502320(wszTail, nTailX, nY, pEditBox->nTextColor, 0);
        }
        else
        {
            sub_00502320(wszText, nX, nY, pEditBox->nTextColor, 0);
        }

        if (sub_004F9200() == (int)pEditBox && GetTickCount() / 250 & 1)
        {
            char szCaret[] = "_";
            UnicodeChar wszCaret[2];
            sub_00526F20_ToUnicode(wszCaret, szCaret, 2);
            const int nCaretOffset = pEditBox->nCaretPosition - pEditBox->nFirstVisibleChar;
            if (nCaretOffset)
            {
                nX += D2Win_10122(wszText, nCaretOffset);
            }
            sub_00502320(wszCaret, nX, nY, pEditBox->nTextColor, 0);
        }
    }

    return 1;
}

// 0x005001D0
D2WinEditBoxStrc* __fastcall D2Win_10070_EDITBOX_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6, D2CelFileStrc* pCellFile, int a8, D2WinMsgHandler a9, int nEditBoxFlags, D2WinFontAndColorStrc* pFontAndColor)
{
    D2WinEditBoxStrc* pEditBox = (D2WinEditBoxStrc*)FOG_Alloc(sizeof(D2WinEditBoxStrc), ".\\Src\\D2WinEditBox.cpp", 0x39, 0);
    memset(pEditBox, 0, sizeof(D2WinEditBoxStrc));
    pEditBox->controlHeader.eType = 1;
    pEditBox->controlHeader.dwFlags |= gdwBitMasks[0];
    pEditBox->controlHeader.dwFlags |= gdwBitMasks[2];
    pEditBox->controlHeader.pCellFile = pCellFile;
    pEditBox->controlHeader.nImageX = nX;
    pEditBox->controlHeader.nWidth = nWidth;
    pEditBox->controlHeader.nHeight = nHeight;
    pEditBox->nTextInsetX = a5;
    pEditBox->nTextInsetY = a6;
    pEditBox->nMaxLength = 256;
    pEditBox->controlHeader.nImageY = nY;
    pEditBox->nFirstVisibleChar = 0;
    pEditBox->nLastVisibleChar = 0;
    pEditBox->nSelectionStart = -1;
    pEditBox->controlHeader.pfDraw = (D2WinControlFn)((nEditBoxFlags & 8) ? sub_004FF620_EditBoxDrawAlt : sub_004FFE50_EditBoxDraw);
    pEditBox->controlHeader.pfHandleMouseDown = (nEditBoxFlags & 8) ? sub_004FE710_EditBoxMouseDownAlt : sub_004FFBF0_EditBoxMouseDown;
    pEditBox->controlHeader.pfHandleMouseUp = EDITBOX_HandleMouseUp;
    pEditBox->controlHeader.pfHandleCharInput = 0;
    pEditBox->controlHeader.pfHandleVirtualKeyInput = 0;
    pEditBox->pfFilter = 0;
    pEditBox->controlHeader.field_34 = a9;
    pEditBox->pfOnEnter = (void*)a8;
    pEditBox->controlHeader.pNext = 0;
    pEditBox->wszText[0] = 0;
    pEditBox->nCaretPosition = 0;
    pEditBox->dwEditBoxFlags = nEditBoxFlags;
    if (pFontAndColor)
    {
        pEditBox->eFont = pFontAndColor->eFont;
        pEditBox->nTextColor = pFontAndColor->nColor;
    }
    else
    {
        pEditBox->eFont = 1;
        pEditBox->nTextColor = 0;
    }
    pEditBox->pNext = 0;
    pEditBox->pPrevious = 0;
    CONTROL_AppendToList(&pEditBox->controlHeader);
    return pEditBox;
}
