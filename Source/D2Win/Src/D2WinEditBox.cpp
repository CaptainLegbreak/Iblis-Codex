#include "D2Win.h"

#pragma function(memset)

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;
struct D2WinEditBoxStrc;
struct UnicodeChar;
struct SMSGHANDLER_PARAMS;
struct Obj004FDA80;

struct Unicode
{
    unsigned short wChar;
    static Unicode* __fastcall strcat(Unicode* pDest, const Unicode* pSource);                             // 0x00526700
// build: symbol ?strncpy@Unicode@@SIPAU1@PAU1@PBU1@H@Z 0x00526790
    static Unicode* __fastcall strncpy(Unicode* pDest, const Unicode* pSource, int nCount);                // 0x00526790
    static Unicode* __fastcall win2Unicode(Unicode* pDest, const char* szSource, int nCount);              // 0x00526F20
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

struct D2WinEditBoxStrc
{
    int nType;
    char pad04[0x4];
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    char pad1C[0x18];
    D2WinMsgHandler pfMouseDownHook;
    char f_38[0x8];
    int nTextInsetX;
    int nTextInsetY;
    int nMaxLength;
    int nFirstVisibleChar;
    int nLastVisibleChar;
    int nSelectionStart;
    int nSelectionEnd;
    Unicode wszText[256];
    int nCaretPosition;
    unsigned int dwEditBoxFlags;
    void* pfOnEnter;
    int (__stdcall* pfFilter)(D2WinEditBoxStrc* pEditBox, int nCaret, char* pKey);
    void (__stdcall* pfOnChange)(int nArg);
    int eFont;
    int nTextColor;
    D2WinEditBoxStrc* pNext;
    D2WinEditBoxStrc* pPrevious;
    int bDragging;
};

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

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern const unsigned int gdwBitMasks[]; // 0x006CE268
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

// 0x004FDC70
static __declspec(noinline) int sub_004FDC70_HasSelection(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x198);
    D2_ASSERT(pEditBox->nType == 1, 0x19A);
    if (pEditBox->nSelectionStart != -1 && pEditBox->nSelectionStart != pEditBox->nSelectionEnd)
        return 1;
    return 0;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FDE30
static int __stdcall sub_004FDE30_GetEditTextHeight(const Unicode* wszText, D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x5EA);
    D2_ASSERT(pEditBox->nType == 1, 0x5EC);
    Unicode wszDash[2];
    sub_00502EF0(pEditBox->eFont);
    const int nStartY = D2Win_10125() + (pEditBox->nTextInsetY - pEditBox->nHeight) + pEditBox->nImageY;
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
    const int nMaxWidth = pEditBox->nWidth - 2 * pEditBox->nTextInsetX;
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
    return sub_00526800(pEditBox->wszText) + pEditBox->nCaretPosition;
}

// 0x004FE3B0
int __stdcall sub_004FE3B0_EditBoxClick(SMSGHANDLER_PARAMS* pMsg, int nX, int nY)
{
    D2WinEditBoxStrc* pEditBox = (D2WinEditBoxStrc*)pMsg->hWnd;

    D2_ASSERT(pEditBox, 0x74E);
    D2_ASSERT(pEditBox->nType == 1, 0x74F);

    if (!(pEditBox->dwFlags & gdwBitMasks[2]) || !(pEditBox->dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }

    sub_004F91C0(pEditBox);
    if (pEditBox->bDragging)
    {
        nX = D2WIN_MIN(D2WIN_MAX(nX, pEditBox->nTextInsetX), pEditBox->nWidth - pEditBox->nTextInsetX - 1);
        nY = D2WIN_MIN(D2WIN_MAX(nY, pEditBox->nTextInsetY), pEditBox->nHeight - pEditBox->nTextInsetY - 1);
    }

    if (nX >= -pEditBox->nTextInsetX && nX < pEditBox->nWidth - pEditBox->nTextInsetX
        && nY >= -pEditBox->nTextInsetY && nY < pEditBox->nHeight - pEditBox->nTextInsetY)
    {
        sub_00502EF0(pEditBox->eFont);
        char szDash[] = "_";
        UnicodeChar wszDash[2];
        sub_00526F20_ToUnicode(wszDash, szDash, 2);
        const int nDashWidth = sub_00501820(wszDash);
        char szText[256];
        sub_00526F70(szText, pEditBox->wszText, 256);
        const char* pLine = szText;
        const char* pChar = szText;
        int nLineY = 0;
        int nLineHeight = D2Win_10125();
        const int nMaxWidth = pEditBox->nWidth - 2 * pEditBox->nTextInsetX;
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
                nOldCaret = pEditBox->nCaretPosition;
                pEditBox->nCaretPosition = pLine - szText + nChars - 1;
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
            nOldCaret = pEditBox->nCaretPosition;
            pEditBox->nCaretPosition = sub_00526800(pEditBox->wszText);
        }

        if ((((unsigned int)GetKeyState(0x10) & 0x8000) || pEditBox->bDragging) && nOldCaret != -1)
        {
            if (pEditBox->nSelectionStart == -1)
            {
                pEditBox->nSelectionStart = nOldCaret;
            }
            pEditBox->nSelectionEnd = pEditBox->nCaretPosition;
        }
        else
        {
            sub_004FDCC0(pEditBox);
        }
    }

    if (pMsg->uMessage == 0x201)
    {
        pEditBox->bDragging = 1;
    }

    if (pEditBox->pfMouseDownHook)
    {
        return pEditBox->pfMouseDownHook(pMsg);
    }

    return 0;
}

// 0x004FE7C0
static void sub_004FE7C0_UpdateVisibleChars(D2WinEditBoxStrc* pEditBox)
{
    sub_00502EF0(pEditBox->eFont);
    int nAvail = pEditBox->nWidth - 2 * pEditBox->nTextInsetX;
    const int nLength = sub_00526800(pEditBox->wszText);
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
        sub_005267E0(wszText, pEditBox->wszText);
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
    D2_ASSERT(pEditBox->nType == 1, 0x1C4);
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
        sub_00526790(wszHead, pEditBox->wszText, nStart);
    }
    else
    {
        wszHead[0].wChar = 0;
    }
    sub_005267E0(wszTail, &pEditBox->wszText[nEnd]);
    sub_005267E0(pEditBox->wszText, wszHead);
    sub_00526700(pEditBox->wszText, wszTail);
    const int nLength = sub_00526800(pEditBox->wszText);
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
    D2_ASSERT(pEditBox->nType == 1, 0x1F8);
    if (!(pEditBox->dwFlags & gdwBitMasks[2]) || !(pEditBox->dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }
    if (nChar == 9 && (pEditBox->dwEditBoxFlags & 4))
    {
        if (pEditBox->pfFilter)
        {
            ++gnWinCallbackDepth_007D55C4;
            pEditBox->pfFilter(pEditBox, pEditBox->nCaretPosition, &nChar);
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
    if (pEditBox->pfFilter && !pEditBox->pfFilter(pEditBox, pEditBox->nCaretPosition, &nChar)
        && nChar != 0x16 && nChar != 3 && nChar != 0x18 && nChar != 1)
    {
        return 0;
    }
    if (sub_004FDC70_HasSelection(pEditBox) && nChar != 3 && nChar != 0x18 && nChar != 1)
    {
        sub_004FE9F0_DeleteSelection(pEditBox);
    }
    int nLength = sub_00526800_2(&pEditBox->wszText[0].wChar);
    UnicodeChar wszText[512];
    sub_005267E0_2(&wszText[0].wChar, &pEditBox->wszText[0].wChar);
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
                if (!pEditBox->pfFilter(pEditBox, nCaret + i, (char*)&szClip[i]))
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
            nLength = sub_00526800_2(&pEditBox->wszText[0].wChar);
            sub_005267E0_2(&wszText[0].wChar, &pEditBox->wszText[0].wChar);
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
    const int nMaxHeight = pEditBox->nHeight - 2 * pEditBox->nTextInsetY;
    if ((pEditBox->dwEditBoxFlags & 8) && sub_004FDE30_GetEditTextHeight(wszText, pEditBox) >= nMaxHeight)
    {
        return 1;
    }
    sub_005267E0_2(&pEditBox->wszText[0].wChar, &wszText[0].wChar);
    pEditBox->nCaretPosition = pCaret - wszText;
    sub_004FE7C0_UpdateVisibleChars(pEditBox);
    if (pEditBox->pfOnChange)
    {
        pEditBox->pfOnChange(0);
    }
    return 1;
}

// 0x004FF5A0
int __fastcall sub_004FF5A0(D2WinEditBoxStrc* pEditBox, const Unicode* pText)
{
    D2_ASSERT(pEditBox, 0x45E);
    D2_ASSERT(pEditBox->nType == 1, 0x460);
    const int nLength = sub_00526800(pText);
    if (nLength)
    {
        sub_005267E0(pEditBox->wszText, pText);
    }
    else
    {
        pEditBox->wszText[0].wChar = 0;
    }
    pEditBox->nCaretPosition = nLength;
    sub_004FE7C0_UpdateVisibleChars(pEditBox);
    if (pEditBox->pfOnChange)
    {
        pEditBox->pfOnChange(0);
    }
    return 1;
}
