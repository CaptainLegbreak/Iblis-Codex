#include "D2Win.h"
#include "D2CelContext.h"

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct Unicode
{
    unsigned short wChar;

// build: symbol ?strncpy@Unicode@@SIPAU1@PAU1@PBU1@H@Z 0x00526790
    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                       // 0x00526790
};

struct tagPOINT
{
    long x;
    long y;
};
struct D2WinControlStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinControlStrc
{
    int eType;
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

struct D2WinEditBoxStrc
{
    D2WinControlStrc controlHeader;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int nTextLength;
    Unicode wszText[256];
    int field_25C;
    unsigned int dwEditBoxFlags;
    int field_264;
    int field_268;
    void* field_26C;
    int eFont;
    int nTextColor;
    D2WinEditBoxStrc* pNext;
    D2WinEditBoxStrc* pPreviousEditBox;
    int field_280;
};

struct D2WinFontAndColorStrc
{
    int eFont;
    int nColor;
};

struct D2AnimatedImageDescriptor
{
    D2CelFileStrc** ppCellFile1;
    D2CelFileStrc** ppCellFile2;
    int eDrawMode;
    unsigned int nAnimSpeed;
};

struct D2WinAnimImageStrc
{
    D2WinControlStrc controlHeader;
    D2AnimatedImageDescriptor* pAnimatedImageDescriptor;
    unsigned int nAnimSpeed;
    unsigned long dwStartTickCount;
    unsigned int nFrame;
    int nAnimType;
    int eDrawMode;
    D2WinMsgHandler field_58;
    int bIsRunning;
};

struct D2WinButtonStrc
{
    D2WinControlStrc controlHeader;
    unsigned int dwButtonFlags;
    int bIsPressed;
    int bIsCallbackPending;
    int nActivationCounter;
    int nActivationVirtualKey;
    int nIsPressedFrameOffset;
    int field_58;
    int nBaseFrame;
    int eFont;
    Unicode wszText[256];
    int nTextColor;
    D2WinMsgHandler pfUpdateHoverState;
    int isButtonHovered;
    int nStringId;
};


struct D2SplittedTextStrc
{
    Unicode* wszLine;
    D2SplittedTextStrc* pNextLine;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210
int __stdcall EDITBOX_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg);                                              // 0x004FE350
int __fastcall sub_004FF620_EditBoxDrawAlt(D2WinControlStrc* pControl);                                     // 0x004FF620
int __stdcall sub_004FFBF0_EditBoxMouseDown(SMSGHANDLER_PARAMS* pMsg);                                      // 0x004FFBF0
int __fastcall sub_004FFE50_EditBoxDraw(D2WinControlStrc* pControl);                                        // 0x004FFE50
D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4

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
    pEditBox->field_40 = a5;
    pEditBox->field_44 = a6;
    pEditBox->field_48 = 256;
    pEditBox->controlHeader.nImageY = nY;
    pEditBox->field_4C = 0;
    pEditBox->field_50 = 0;
    pEditBox->field_54 = -1;
    pEditBox->controlHeader.pfDraw = (nEditBoxFlags & 8) ? sub_004FF620_EditBoxDrawAlt : sub_004FFE50_EditBoxDraw;
    pEditBox->controlHeader.pfHandleMouseDown = (nEditBoxFlags & 8) ? sub_004FE710_EditBoxMouseDownAlt : sub_004FFBF0_EditBoxMouseDown;
    pEditBox->controlHeader.pfHandleMouseUp = EDITBOX_HandleMouseUp;
    pEditBox->controlHeader.pfHandleCharInput = 0;
    pEditBox->controlHeader.pfHandleVirtualKeyInput = 0;
    pEditBox->field_268 = 0;
    pEditBox->controlHeader.field_34 = a9;
    pEditBox->field_264 = a8;
    pEditBox->controlHeader.pNext = 0;
    pEditBox->wszText[0].wChar = 0;
    pEditBox->field_25C = 0;
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
    pEditBox->pPreviousEditBox = 0;
    CONTROL_AppendToList(&pEditBox->controlHeader);
    return pEditBox;
}

// 0x005003A0
int __fastcall ANIMIMAGE_ShouldMouseInputBeHandled(D2WinControlStrc* pControl)
{
    D2WinAnimImageStrc* pAnimImage = (D2WinAnimImageStrc*)pControl;
    D2_ASSERT(pAnimImage->controlHeader.eType == 2, 0x73);

    int nY = gMousePosition_6F8FE234.y;
    int nX = gMousePosition_6F8FE234.x;

    D2CelFileStrc* pCellFile = 0;
    D2CelFileStrc** ppCellFile = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile1;
    if (ppCellFile)
    {
        pCellFile = *ppCellFile;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;

    D2CelStrc* pCel = CelGetHandle(&tContext);
    const int nImageX = pAnimImage->controlHeader.nImageX;
    const int nImageY = pAnimImage->controlHeader.nImageY;
    const int nWidth = sub_006018C0(pCel);
    const int nHeight = sub_006018F0(pCel);
    nX -= sub_00601920(pCel);
    nY -= sub_00601950(pCel);
    return nX >= nImageX && nY >= nImageY - nHeight && nX < nImageX + nWidth && nY < nImageY;
}

// 0x00500B50
int __fastcall BUTTON_OnMouseWheelScrolled(D2WinButtonStrc* ptBtnData, int nMouseWheelIncrement)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == 6, 0xE2);

    if (!(ptBtnData->controlHeader.dwFlags & gdwBitMasks[0]) || !(ptBtnData->controlHeader.dwFlags & gdwBitMasks[2]) || ptBtnData->bIsPressed || ptBtnData->bIsCallbackPending)
    {
        return 0;
    }

    if ((nMouseWheelIncrement <= 0 || !(ptBtnData->dwButtonFlags & 8)) && (nMouseWheelIncrement >= 0 || !(ptBtnData->dwButtonFlags & 0x10)))
    {
        return 0;
    }

    SMSGHANDLER_PARAMS msg;
    memset(&msg.uMessage, 0, sizeof(msg) - sizeof(msg.hWnd));
    msg.hWnd = ptBtnData;

    if (ptBtnData->controlHeader.field_34)
    {
        ++gnWinCallbackDepth_007D55C4;
        ptBtnData->controlHeader.field_34(&msg);
        --gnWinCallbackDepth_007D55C4;
    }

    return 0;
}

// 0x005028E0
D2SplittedTextStrc* __stdcall sub_005028E0_AllocSplitTextLine(const Unicode* wszText, int nLength, int bSkipSpace)
{
    const Unicode* pText = wszText;
    D2SplittedTextStrc* pSplitText = (D2SplittedTextStrc*)FOG_Alloc(sizeof(D2SplittedTextStrc), ".\\Src\\D2WinFont.cpp", 0x588, 0);
    int nCount = nLength;
    if (bSkipSpace && pText->wChar < 0x100 && isspace(pText->wChar))
    {
        nCount = nCount - 1;
        pText = pText + 1;
    }
    pSplitText->wszLine = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nCount + 1), ".\\Src\\D2WinFont.cpp", 0x591, 0);
    pSplitText->pNextLine = 0;
    Unicode::strncpy(pSplitText->wszLine, pText, nCount);
    pSplitText->wszLine[nCount].wChar = 0;
    return pSplitText;
}
