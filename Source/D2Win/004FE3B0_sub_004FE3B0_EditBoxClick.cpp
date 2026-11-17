// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

struct Unicode
{
    unsigned short wChar;
};

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
    void* pfFilter;
    void* pfOnChange;
    int eFont;
    int nTextColor;
    D2WinEditBoxStrc* pNext;
    D2WinEditBoxStrc* pPrevious;
    int bDragging;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2WIN_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2WIN_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);                                // 0x006CC45C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern const unsigned int gdwBitMasks[];                                                                    // 0x006CE268

int __stdcall sub_004F91C0(D2WinEditBoxStrc* pEditBox);                                                      // 0x004F91C0
void __fastcall sub_004FDCC0(D2WinEditBoxStrc* pEditBox);                                                    // 0x004FDCC0
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
int __stdcall D2Win_10125();                                                                                // 0x00501A40
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70

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
