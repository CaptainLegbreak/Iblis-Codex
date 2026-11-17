struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

struct D2CelFileStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

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
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    char pad1C[0x24];
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
    char pad264[0x0C];
    int eFont;
    int nTextColor;
    char pad278[0x08];
    int bMouseSelecting;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define EDITBOX_MIN(a, b) ((a) < (b) ? (a) : (b))
#define EDITBOX_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

int __cdecl sub_004F9200();                                                                                 // 0x004F9200
int __cdecl sub_004FA460();                                                                                 // 0x004FA460
int __stdcall sub_004FFBF0_EditBoxMouseDown(SMSGHANDLER_PARAMS* pMsg);                                      // 0x004FFBF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
void __fastcall D2Win_10133(const Unicode* wszText, int nX, int nY, int nColor, int nDrawMode, int nTextColor); // 0x00502480
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0

static __declspec(noinline) int sub_004FDC70_HasSelection(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x198);
    D2_ASSERT(pEditBox->nType == 1, 0x19A);
    if (pEditBox->nSelectionStart != -1 && pEditBox->nSelectionStart != pEditBox->nSelectionEnd)
        return 1;
    return 0;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FFE50
int __fastcall sub_004FFE50_EditBoxDraw(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x49C);
    D2_ASSERT(pEditBox->nType == 1, 0x49E);

    if (pEditBox->dwFlags & gdwBitMasks[2] && pEditBox->dwFlags & gdwBitMasks[0])
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
        if (pEditBox->pCellFile)
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = pEditBox->pCellFile;
            tContext.unk0x40 = 0;
            tContext.nFrame = 0;
            sub_004F6480(&tContext, pEditBox->nImageX, pEditBox->nImageY - 1, -1, 5, 0);
        }

        sub_00502EF0(pEditBox->eFont);
        int nX = pEditBox->nTextInsetX + pEditBox->nImageX;
        const int nY = pEditBox->nTextInsetY - pEditBox->nHeight + pEditBox->nImageY + 16;
        sub_00526790(wszText, &pEditBox->wszText[pEditBox->nFirstVisibleChar], pEditBox->nLastVisibleChar - pEditBox->nFirstVisibleChar + 1);
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
