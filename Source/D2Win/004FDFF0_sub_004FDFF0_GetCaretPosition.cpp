struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2WinEditBoxStrc
{
    int nType;
    char pad04[0x4];
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    char pad1C[0x24];
    int nTextInsetX;
    int nTextInsetY;
    char pad48[0x4];
    int nFirstVisibleChar;
    int nLastVisibleChar;
    int nSelectionStart;
    int nSelectionEnd;
    Unicode wszText[256];
    int nCaretPosition;
    unsigned int dwEditBoxFlags;
    void (__stdcall* pfOnEnter)(Unicode* pText);
    int (__stdcall* pfFilter)(D2WinEditBoxStrc* pEditBox, int nCaret, char* pKey);
    void (__stdcall* pfOnChange)(int nArg);
    int eFont;
    int nTextColor;
    D2WinEditBoxStrc* pNext;
    D2WinEditBoxStrc* pPrevious;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2WIN_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2WIN_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);                                 // 0x006CC45C
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
#pragma function(memset)
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern int gnWinCallbackDepth_007D55C4;                                                                     // 0x007D55C4

int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0
int __stdcall D2Win_10125();                                                                                // 0x00501A40
int __stdcall sub_004F91C0(void* pEditBox);                                                                  // 0x004F91C0
int __fastcall D2Win_10082(D2WinControlStrc* pEditBox);                                                     // 0x004FDD00
void __fastcall sub_004FDCC0(D2WinEditBoxStrc* pEditBox);                                                    // 0x004FDCC0
int __stdcall sub_004FE3B0_EditBoxClick(SMSGHANDLER_PARAMS* pMsg, int nX, int nY);                          // 0x004FE3B0

static __declspec(noinline) int sub_004FDC70_HasSelection(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x198);
    D2_ASSERT(pEditBox->nType == 1, 0x19A);
    if (pEditBox->nSelectionStart != -1 && pEditBox->nSelectionStart != pEditBox->nSelectionEnd)
        return 1;
    return 0;
}

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

// 0x004FDFF0
static void __stdcall sub_004FDFF0_GetCaretPosition(int* pX, int* pY, D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x648);
    D2_ASSERT(pEditBox->nType == 1, 0x64A);
    Unicode wszCopy[300];
    for (int i = 0; i < 300; ++i)
    {
        wszCopy[i].wChar = 0;
    }
    Unicode wszDash[2];
    sub_00502EF0(pEditBox->eFont);
    const int nStartX = pEditBox->nImageX + pEditBox->nTextInsetX;
    const int nStartY = D2Win_10125() + (pEditBox->nTextInsetY - pEditBox->nHeight) + pEditBox->nImageY;
    sub_005267E0(wszCopy, pEditBox->wszText);
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
    sub_00526F70(szText, pEditBox->wszText, 256);
    const char* pLine = szText;
    const char* pChar = szText;
    int nY = nStartY;
    const int nLineHeight = D2Win_10125();
    const int nMaxWidth = pEditBox->nWidth - 2 * pEditBox->nTextInsetX;
    const int nMaxHeight = pEditBox->nHeight - 2 * pEditBox->nTextInsetY;
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
        const int nCaret = pEditBox->nCaretPosition - (pLine - szText);
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
                    if (*pX == -1 && pEditBox->nCaretPosition == pChar - szText && nY - nStartY < nMaxHeight)
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
                    if (*pX == -1 && pEditBox->nCaretPosition == pChar - szText && nY - nStartY < nMaxHeight)
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
        *pX = *pX - pEditBox->nImageX - 1;
        *pY += pEditBox->nHeight - pEditBox->nImageY - 1;
        *pX = D2WIN_MIN(D2WIN_MAX(*pX, pEditBox->nTextInsetX), pEditBox->nWidth - pEditBox->nTextInsetX - 1);
        *pY = D2WIN_MIN(D2WIN_MAX(*pY, pEditBox->nTextInsetY), pEditBox->nHeight - pEditBox->nTextInsetY - 1);
    }
}

// 0x004FF050
int __fastcall sub_004FF050_EditBoxKeyDown(D2WinEditBoxStrc* pEditBox, char nKey)
{
    Unicode* pChar;
    D2_ASSERT(pEditBox, 0x300);
    D2_ASSERT(pEditBox->nType == 1, 0x302);
    if (!(pEditBox->dwFlags & gdwBitMasks[2]) || !(pEditBox->dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }
    pChar = &pEditBox->wszText[pEditBox->nCaretPosition];
    int bChanged = 0;
    int bDeleted = 0;
    const int bShift = ((unsigned int)GetKeyState(0x10) >> 15) & 1;
    switch (nKey)
    {
    case 8:
    case 46:
        if (sub_004FDC70_HasSelection(pEditBox))
        {
            sub_004FE9F0_DeleteSelection(pEditBox);
            bChanged = 1;
            bDeleted = 1;
            pChar = &pEditBox->wszText[pEditBox->nCaretPosition];
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
            if (pEditBox->nSelectionStart == -1)
            {
                pEditBox->nSelectionStart = pEditBox->nCaretPosition;
                pEditBox->nSelectionEnd = pEditBox->nCaretPosition;
            }
        }
        else
        {
            sub_004FDCC0(pEditBox);
        }
        break;
    }
    switch (nKey)
    {
    case 36:
        pChar = pEditBox->wszText;
        if (bShift)
        {
            pEditBox->nSelectionEnd = 0;
        }
        break;
    case 35:
        while (pChar->wChar)
        {
            ++pChar;
        }
        if (bShift)
        {
            pEditBox->nSelectionEnd = pChar - pEditBox->wszText;
        }
        break;
    case 38:
        if (pEditBox->dwEditBoxFlags & 8)
        {
            int nX;
            int nY;
            sub_004FDFF0_GetCaretPosition(&nX, &nY, pEditBox);
            const int nLineHeight = D2Win_10125();
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = pEditBox;
            msg.uMessage = 0;
            sub_004FE3B0_EditBoxClick(&msg, nX, nY - nLineHeight);
            pChar = &pEditBox->wszText[pEditBox->nCaretPosition];
        }
        else
        {
            pChar = pEditBox->wszText;
            if (bShift)
            {
                pEditBox->nSelectionEnd = 0;
            }
        }
        break;
    case 40:
        if (pEditBox->dwEditBoxFlags & 8)
        {
            int nX;
            int nY;
            sub_004FDFF0_GetCaretPosition(&nX, &nY, pEditBox);
            const int nLineHeight = D2Win_10125();
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = pEditBox;
            msg.uMessage = 0;
            sub_004FE3B0_EditBoxClick(&msg, nX, nY + nLineHeight);
            pChar = &pEditBox->wszText[pEditBox->nCaretPosition];
        }
        else
        {
            while (pChar->wChar)
            {
                ++pChar;
            }
            if (bShift)
            {
                pEditBox->nSelectionEnd = pChar - pEditBox->wszText;
            }
        }
        break;
    case 37:
        --pChar;
        if (pChar->wChar == '\n')
        {
            --pChar;
        }
        if (pChar < pEditBox->wszText)
        {
            pChar = pEditBox->wszText;
        }
        else if (bShift && pEditBox->nSelectionStart != -1)
        {
            pEditBox->nSelectionEnd = pChar - pEditBox->wszText;
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
            if (bShift && pEditBox->nSelectionStart != -1)
            {
                pEditBox->nSelectionEnd = pChar - pEditBox->wszText;
            }
        }
        break;
    case 8:
        if (pChar > pEditBox->wszText && !bDeleted)
        {
            --pChar;
            const int nLength = sub_00526800(pChar + 1) + 1;
            memmove(pChar, pChar + 1, 2 * nLength);
            if (pChar > pEditBox->wszText && pChar[-1].wChar == '\r')
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
        if (pEditBox->pfOnEnter)
        {
            const unsigned int bKeepFocus = pEditBox->dwEditBoxFlags & 2;
            ++gnWinCallbackDepth_007D55C4;
            pEditBox->pfOnEnter(pEditBox->wszText);
            --gnWinCallbackDepth_007D55C4;
            if (bKeepFocus)
            {
                pChar = &pEditBox->wszText[pEditBox->nCaretPosition];
            }
            else
            {
                goto LABEL_DONE;
            }
        }
        break;
    case 27:
        if (pEditBox->pfOnEnter)
        {
            ++gnWinCallbackDepth_007D55C4;
            pEditBox->pfOnEnter(0);
            --gnWinCallbackDepth_007D55C4;
        }
    LABEL_DONE:
        return 1;
    case 9:
    {
        D2WinEditBoxStrc* pFocus;
        if (GetKeyState(0x10) >= 0)
        {
            pFocus = pEditBox->pNext;
            if (!pFocus)
            {
                return 1;
            }
            do
            {
                if (pFocus == pEditBox)
                {
                    break;
                }
                if ((pFocus->dwFlags & gdwBitMasks[2]) && (pFocus->dwFlags & gdwBitMasks[0]))
                {
                    break;
                }
                pFocus = pFocus->pNext;
            }
            while (pFocus);
        }
        else
        {
            pFocus = pEditBox->pPrevious;
            if (!pFocus)
            {
                return 1;
            }
            do
            {
                if (pFocus == pEditBox)
                {
                    break;
                }
                if ((pFocus->dwFlags & gdwBitMasks[2]) && (pFocus->dwFlags & gdwBitMasks[0]))
                {
                    break;
                }
                pFocus = pFocus->pPrevious;
            }
            while (pFocus);
        }
        sub_004F91C0(pFocus);
        D2Win_10082((D2WinControlStrc*)pFocus);
        return 1;
    }
    case 112:
        return 0;
    }
    pEditBox->nCaretPosition = pChar - pEditBox->wszText;
    sub_004FE7C0_UpdateVisibleChars(pEditBox);
    if (bChanged && pEditBox->pfFilter && !pEditBox->pfFilter(pEditBox, pEditBox->nCaretPosition, &nKey) && nKey != 8 && nKey != 46)
    {
        return 0;
    }
    if (pEditBox->pfOnChange)
    {
        pEditBox->pfOnChange(0);
    }
    return 1;
}
