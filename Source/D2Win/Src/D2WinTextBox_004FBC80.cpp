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
};

struct D2CelFileStrc;
struct D2CelStrc;
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

struct D2WinTextBoxStrc
{
    D2WinControlStrc controlHeader;
    int field_40;
    int field_44;
    void* pFirstLine;
    void* pLastLine;
    void* pCurrentLine;
    int nNumLines;
    int nLine;
    int dwTextBoxFlags;
    int nCurrentLine;
    int nNumColumns;
    int unk0x68[5];
    int unk0x7C[5];
};

struct D2WinImageClickRectStrc;

struct D2WinImage2Strc
{
    D2WinControlStrc controlHeader;
    int nFrame;
    int eDrawMode;
    D2WinImageClickRectStrc* pClickRect;
};

struct D2WinImageStrc
{
    D2WinControlStrc controlHeader;
    int nFrame;
    int eDrawMode;
    D2WinImageClickRectStrc* pClickRect;
    int field_4C;
    int field_50;
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

struct D2AnimatedImageDescriptor;

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

struct D2CharStrc
{
    unsigned short wChar;
    unsigned char unk0x02;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x05;
    unsigned short unk0x06;
    unsigned short nImageIndex;
};

struct D2CompositeUnitStrc
{
    unsigned int dwFlags;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned int unk0x08;
    unsigned int unk0x0C;
    unsigned int unk0x10;
    int nX;
    int nY;
    char unk0x1C[0xA8];
    D2CompositeUnitStrc* pNext;
    D2CompositeUnitStrc* unk0xC8;
    Unicode unk0xCC[64];
    Unicode unk0x14C[64];
    Unicode unk0x1CC[16];
    Unicode unk0x1EC[32];
    unsigned int unk0x22C;
    unsigned int unk0x230;
};

struct D2CompPairStrc
{
    int nKey;
    int nValue;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                                // 0x0040B380
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210
int __fastcall IMAGE2_Draw(D2WinControlStrc* pControl);                                                     // 0x004FD1F0
int __fastcall IMAGE_Draw(D2WinControlStrc* pControl);                                                      // 0x004FD470
int __stdcall IMAGE2_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                             // 0x004FD5D0
int __fastcall ANIMIMAGE_ShouldMouseInputBeHandled(D2WinControlStrc* pControl);                             // 0x005003A0
int __fastcall ANIMIMAGE_Draw(D2WinControlStrc* pControl);                                                  // 0x005005B0
void __fastcall D2SOUND_10039(const char* szFile);                                                          // 0x00514EC0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex);                                       // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile);                                                // 0x006019F0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern unsigned int gdwInvBitMasks[];                                                                       // 0x006CE2E8
extern D2CompPairStrc gaCompPairs_0072EF68[];                                                               // 0x0072EF68
extern unsigned int gnCompPairs_0072EFD0;                                                                   // 0x0072EFD0
extern int gnWinCallbackDepth_007D55C4;                                                                     // 0x007D55C4
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                        // 0x00841DA0
Unicode gwszFramedText_00841EC8[1024];                                                                      // 0x00841EC8
int gnFramedTextX_008426C8;                                                                                 // 0x008426C8
int gnFramedTextY_008426CC;                                                                                 // 0x008426CC
int gnFramedTextColor_008426D0;                                                                             // 0x008426D0
int gnFramedTextAlign_008426D4;                                                                             // 0x008426D4
int gnFramedTextRectColor_008426D8;                                                                         // 0x008426D8
extern D2CelFileStrc* ghSquelchCelFile_0087E844;                                                            // 0x0087E844
extern int gnSquelchCelFileFrameCount_0087E848;                                                             // 0x0087E848
extern D2CelFileStrc* ghSelectedCelFile_0087E850;                                                           // 0x0087E850
extern int gnSelectedCelFileFrameCount_0087E854;                                                            // 0x0087E854

// 0x004FBC80
void __fastcall D2Win_10059(D2WinTextBoxStrc* pTextBox, int nColumn, int a3)
{
    D2_ASSERT(pTextBox, 0x2EF);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x2F0);
    D2_ASSERT((nColumn >= 0) && (nColumn < pTextBox->nNumColumns), 0x2F2);
    pTextBox->unk0x68[nColumn] = a3;
}

// 0x004FBCD0
void __fastcall D2Win_10060(D2WinTextBoxStrc* ptTextData, int nColumn, int a3)
{
    D2_ASSERT(ptTextData, 0x2FC);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x2FD);
    D2_ASSERT(nColumn >= 0, 0x2FF);
    ptTextData->unk0x7C[nColumn] = a3;
}

// 0x004FD070
int __stdcall IMAGE_SetCellFile(D2WinImageStrc* pImage, D2CelFileStrc* pCellFile, D2WinImageClickRectStrc* pClickRect)
{
    D2_ASSERT(pImage->controlHeader.eType == 2, 0x5F);
    pImage->controlHeader.pCellFile = pCellFile;
    pImage->pClickRect = pClickRect;
    return 1;
}

// 0x004FD0B0
int __stdcall IMAGE_SetCoordinates(D2WinImageStrc* ptImageData, int nX, int nY)
{
    D2_ASSERT(ptImageData->controlHeader.eType == 2, 0x6C);
    ptImageData->controlHeader.nImageX = nX;
    ptImageData->controlHeader.nImageY = nY;
    return 1;
}

// 0x004FD170
int __stdcall IMAGE_ForceNormalDrawMode(D2WinImageStrc* ptImageData, int nUnused)
{
    D2_ASSERT(ptImageData->controlHeader.eType == 2, 0x9D);
    ptImageData->eDrawMode = 5;
    return 1;
}

// 0x004FD1B0
int __stdcall IMAGE_GetFrameCount(D2WinImageStrc* ptImageData)
{
    D2_ASSERT(ptImageData->controlHeader.eType == 2, 0xA9);
    return CelFileGetCelsPerDirection(ptImageData->controlHeader.pCellFile);
}

// 0x004FD6C0
D2WinImage2Strc* __fastcall IMAGE2_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, D2WinMsgHandler a6, D2WinImageClickRectStrc* pClickRect, D2WinMsgHandler pfHandleVirtualKeyInput)
{
    D2WinImage2Strc* pImage = (D2WinImage2Strc*)FOG_Alloc(sizeof(D2WinImage2Strc), ".\\Src\\D2WinImage.cpp", 0x1D, 0);
    memset(pImage, 0, sizeof(D2WinImage2Strc));
    pImage->controlHeader.eType = 2;
    pImage->controlHeader.dwFlags |= gdwBitMasks[0];
    pImage->controlHeader.dwFlags |= gdwBitMasks[2];
    pImage->controlHeader.pCellFile = pCellFile;
    pImage->controlHeader.nImageX = nX;
    pImage->controlHeader.nImageY = nY;
    pImage->controlHeader.nWidth = nWidth;
    pImage->controlHeader.nHeight = nHeight;
    pImage->controlHeader.pfDraw = IMAGE2_Draw;
    pImage->controlHeader.pNext = 0;
    pImage->controlHeader.pfHandleMouseDown = IMAGE2_HandleMouseDown;
    pImage->controlHeader.pfHandleMouseUp = 0;
    pImage->controlHeader.pfHandleCharInput = 0;
    pImage->controlHeader.pfHandleVirtualKeyInput = pfHandleVirtualKeyInput;
    pImage->controlHeader.field_34 = a6;
    pImage->pClickRect = pClickRect;
    pImage->nFrame = 0;
    pImage->eDrawMode = 5;
    CONTROL_AppendToList(&pImage->controlHeader);
    return pImage;
}

// 0x004FD770
D2WinImageStrc* __fastcall IMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6, int a7)
{
    D2WinImageStrc* pImage = (D2WinImageStrc*)FOG_Alloc(sizeof(D2WinImageStrc), ".\\Src\\D2WinImage.cpp", 0x3B, 0);
    memset(pImage, 0, sizeof(D2WinImageStrc));
    pImage->controlHeader.eType = 2;
    pImage->controlHeader.dwFlags |= gdwBitMasks[0];
    pImage->controlHeader.dwFlags |= gdwBitMasks[2];
    pImage->controlHeader.pCellFile = pCellFile;
    pImage->controlHeader.nImageX = nX;
    pImage->controlHeader.nImageY = nY;
    pImage->controlHeader.nWidth = nWidth;
    pImage->controlHeader.nHeight = nHeight;
    pImage->controlHeader.pfDraw = IMAGE_Draw;
    pImage->controlHeader.pNext = 0;
    pImage->controlHeader.pfHandleMouseDown = IMAGE2_HandleMouseDown;
    pImage->controlHeader.pfHandleMouseUp = 0;
    pImage->controlHeader.pfHandleCharInput = 0;
    pImage->controlHeader.pfHandleVirtualKeyInput = 0;
    pImage->controlHeader.field_34 = 0;
    pImage->pClickRect = 0;
    pImage->nFrame = 0;
    pImage->eDrawMode = 5;
    pImage->field_4C = a6;
    pImage->field_50 = a7;
    CONTROL_AppendToList(&pImage->controlHeader);
    return pImage;
}

// 0x004FD970
int __stdcall TIMER_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinControlStrc* pTimer = (D2WinControlStrc*)pMsg->hWnd;
    D2_ASSERT(pTimer->eType == 8, 0x82);
    if (pMsg->uMessage == 0x102 || pMsg->wParam != 0x20)
        return 0;
    if (pTimer->field_34)
        pTimer->field_34(pMsg);
    return 1;
}

// 0x004FE350
int __stdcall EDITBOX_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinEditBoxStrc* pEditBox = (D2WinEditBoxStrc*)pMsg->hWnd;
    D2_ASSERT(pEditBox, 0x739);
    D2_ASSERT(pEditBox->controlHeader.eType == 1, 0x73A);
    if (pEditBox->field_280)
    {
        pEditBox->field_280 = 0;
        return 1;
    }
    return 0;
}

// 0x004FE790
int __stdcall D2Win_10079_IsLetter(int nUnused1, int nUnused2, const char* szChar)
{
    return *szChar >= 'a' && *szChar <= 'z' || *szChar >= 'A' && *szChar <= 'Z';
}

// 0x00500790
int __stdcall ANIMIMAGE_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinAnimImageStrc* pAnimImage = (D2WinAnimImageStrc*)pMsg->hWnd;
    D2_ASSERT(pAnimImage->controlHeader.eType == 2, 0x15A);
    int nResult;
    if (pAnimImage->controlHeader.field_34)
        nResult = pAnimImage->controlHeader.field_34(pMsg);
    else
        nResult = 0;
    if (nResult)
    {
        if (pAnimImage->nAnimType == 3)
        {
            pAnimImage->nAnimType = 4;
            pAnimImage->nFrame = 0;
            pAnimImage->dwStartTickCount = GetTickCount();
        }
        else if (pAnimImage->nAnimType == 1)
        {
            pAnimImage->nAnimType = 2;
            pAnimImage->nFrame = 0;
            pAnimImage->dwStartTickCount = GetTickCount();
        }
    }
    return nResult;
}

// 0x00500810
int __stdcall ANIMIMAGE_SetIsRunning(D2WinAnimImageStrc* ptAnim, int bIsRunning)
{
    D2_ASSERT(ptAnim->controlHeader.eType == 2, 0x183);
    ptAnim->bIsRunning = bIsRunning;
    return 1;
}

// 0x00500850
D2WinAnimImageStrc* __fastcall ANIMIMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, unsigned int nAnimSpeed, D2WinMsgHandler a7, D2AnimatedImageDescriptor* pDescriptor, int eDrawMode, D2WinMsgHandler a10)
{
    D2WinAnimImageStrc* pAnimImage = (D2WinAnimImageStrc*)FOG_Alloc(sizeof(D2WinAnimImageStrc), ".\\D2WinAnimImage.cpp", 0x1C, 0);
    memset(pAnimImage, 0, sizeof(D2WinAnimImageStrc));
    pAnimImage->controlHeader.eType = 2;
    pAnimImage->controlHeader.dwFlags |= gdwBitMasks[0];
    pAnimImage->controlHeader.dwFlags |= gdwBitMasks[2];
    pAnimImage->controlHeader.pCellFile = pCellFile;
    pAnimImage->controlHeader.nImageX = nX;
    pAnimImage->controlHeader.nImageY = nY;
    pAnimImage->controlHeader.nWidth = nWidth;
    pAnimImage->controlHeader.nHeight = nHeight;
    pAnimImage->controlHeader.pfDraw = ANIMIMAGE_Draw;
    pAnimImage->controlHeader.pNext = 0;
    pAnimImage->controlHeader.pfHandleMouseDown = ANIMIMAGE_HandleMouseDown;
    pAnimImage->controlHeader.pfHandleMouseUp = 0;
    pAnimImage->controlHeader.pfHandleCharInput = 0;
    pAnimImage->controlHeader.pfHandleVirtualKeyInput = 0;
    pAnimImage->controlHeader.field_34 = a7;
    pAnimImage->pAnimatedImageDescriptor = pDescriptor;
    pAnimImage->nAnimSpeed = nAnimSpeed;
    pAnimImage->nFrame = 0;
    pAnimImage->dwStartTickCount = GetTickCount();
    pAnimImage->nAnimType = 0;
    if (pDescriptor)
        pAnimImage->controlHeader.pfShouldMouseInputBeHandled = ANIMIMAGE_ShouldMouseInputBeHandled;
    if (!eDrawMode)
        pAnimImage->eDrawMode = 5;
    else
        pAnimImage->eDrawMode = eDrawMode;
    pAnimImage->field_58 = a10;
    pAnimImage->bIsRunning = 1;
    CONTROL_AppendToList(&pAnimImage->controlHeader);
    return pAnimImage;
}

// 0x005009D0
void __fastcall BUTTON_SetText(D2WinButtonStrc* pButton, int eFont, const Unicode* wszText, int nTextColor)
{
    D2_ASSERT(pButton->controlHeader.eType == 6, 0x84);
    pButton->eFont = eFont;
    pButton->nTextColor = nTextColor;
    sub_005267E0(pButton->wszText, wszText);
}

// 0x00500A20
void __fastcall BUTTON_SetTextWithStringId(D2WinButtonStrc* ptBtnData, int eFont, unsigned short nStringId, int nTextColor)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == 6, 0x96);
    ptBtnData->eFont = eFont;
    ptBtnData->nTextColor = nTextColor;
    sub_005267E0(ptBtnData->wszText, D2LANG_GetStringFromTblIndex(nStringId));
}

// 0x00500A70
void __fastcall BUTTON_SetCoordinates(D2WinButtonStrc* ptBtnData, int nX, int nY, int nWidth, int nHeight)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == 6, 0xAB);
    ptBtnData->controlHeader.nImageX = nX;
    ptBtnData->controlHeader.nImageY = nY;
    ptBtnData->controlHeader.nWidth = nWidth;
    ptBtnData->controlHeader.nHeight = nHeight;
}

// 0x00501090
int __stdcall BUTTON_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)pMsg->hWnd;
    D2_ASSERT(pButton->controlHeader.eType == 6, 0x1FD);
    if (!(pButton->controlHeader.dwFlags & gdwBitMasks[2]) || !(pButton->controlHeader.dwFlags & gdwBitMasks[0]))
        return 0;
    if (pButton->dwButtonFlags & 2)
    {
        pButton->bIsPressed = pButton->bIsPressed == 0;
        pButton->bIsCallbackPending = pButton->bIsCallbackPending == 0;
    }
    else
    {
        if (pButton->bIsPressed && pButton->bIsCallbackPending)
            return 1;
        pButton->bIsPressed = 1;
        pButton->bIsCallbackPending = 1;
    }
    if (!(pButton->dwButtonFlags & 4))
        D2SOUND_10039("data\\global\\sfx\\cursor\\button.wav");
    if ((pButton->dwButtonFlags & 3) && pButton->controlHeader.field_34)
    {
        D2_ASSERT(gnWinCallbackDepth_007D55C4 > 0, 0x221);
        pButton->controlHeader.field_34(pMsg);
    }
    return 1;
}

// 0x00501150
int __stdcall BUTTON_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)pMsg->hWnd;
    D2_ASSERT(pButton->controlHeader.eType == 6, 0x232);
    int nResult = 0;
    pButton->controlHeader.dwFlags |= gdwBitMasks[1];
    if (!(pButton->controlHeader.dwFlags & gdwBitMasks[2]) || !(pButton->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        pButton->controlHeader.dwFlags &= gdwInvBitMasks[1];
        return 0;
    }
    if (!(pButton->dwButtonFlags & 3))
    {
        pButton->bIsPressed = 0;
        if (pButton->bIsCallbackPending && pButton->controlHeader.field_34)
        {
            D2_ASSERT(gnWinCallbackDepth_007D55C4 > 0, 0x243);
            nResult = pButton->controlHeader.field_34(pMsg);
        }
        pButton->bIsCallbackPending = 0;
    }
    pButton->controlHeader.dwFlags &= gdwInvBitMasks[1];
    return nResult;
}

// 0x005011F0
int __stdcall BUTTON_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)pMsg->hWnd;
    D2_ASSERT(pButton->controlHeader.eType == 6, 0x259);
    int nResult = 0;
    if (pMsg->uMessage != 0x102 && pButton->nActivationVirtualKey == pMsg->wParam && pButton->controlHeader.pfHandleMouseDown)
    {
        pButton->nActivationCounter = 1;
        D2_ASSERT(gnWinCallbackDepth_007D55C4 > 0, 0x263);
        nResult = pButton->controlHeader.pfHandleMouseDown(pMsg);
        if (pButton->controlHeader.pfHandleMouseUp)
        {
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = pMsg->hWnd;
            ++gnWinCallbackDepth_007D55C4;
            pButton->controlHeader.pfHandleMouseUp(&msg);
            --gnWinCallbackDepth_007D55C4;
        }
    }
    return nResult;
}

// 0x005017D0
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength)
{
    int nCount = 0;
    int nWidth = 0;
    for (const Unicode* i = wszText; i->wChar; ++i)
    {
        if (nCount >= nTextLength)
            break;
        const unsigned short wChar = i->wChar;
        if (wChar != '\n')
            nWidth += gpfGetCharInfo_00841DA0(wChar)->nWidth;
        ++nCount;
    }
    return nWidth;
}

// 0x00502280
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign)
{
    if (wszText && sub_00526800(wszText) < 1024)
        sub_005267E0(gwszFramedText_00841EC8, wszText);
    else
        memset(gwszFramedText_00841EC8, 0, sizeof(gwszFramedText_00841EC8));
    gnFramedTextX_008426C8 = nX;
    gnFramedTextY_008426CC = nY;
    gnFramedTextColor_008426D0 = nTextColor;
    gnFramedTextAlign_008426D4 = nAlign;
    gnFramedTextRectColor_008426D8 = 0;
}

// 0x005022F0
void __fastcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign, int nRectangleColor)
{
    D2Win_10129_DrawFramedText(wszText, nX, nY, nTextColor, nAlign);
    gnFramedTextRectColor_008426D8 = nRectangleColor;
}

// 0x00504270
void __stdcall D2Win_10154(D2CompositeUnitStrc* hCompositeUnit, const Unicode* a2, const Unicode* a3, const Unicode* a4, const Unicode* a5, int a6, int a7)
{
    D2_ASSERT(hCompositeUnit, 0x8A8);
    sub_005267E0(hCompositeUnit->unk0xCC, a2);
    sub_005267E0(hCompositeUnit->unk0x14C, a3);
    sub_005267E0(hCompositeUnit->unk0x1CC, a4);
    sub_005267E0(hCompositeUnit->unk0x1EC, a5);
    hCompositeUnit->unk0x22C = a6;
    hCompositeUnit->unk0x230 = a7;
}

// 0x00504370
int __stdcall sub_00504370_LookupPairValue(int nKey)
{
    for (unsigned int i = 0; i < gnCompPairs_0072EFD0; ++i)
    {
        if (nKey == gaCompPairs_0072EF68[i].nKey)
            return gaCompPairs_0072EF68[i].nValue;
    }
    return 0;
}

// 0x005043B0
void __stdcall sub_005043B0_ReleaseToPool(void* pMemory)
{
    FOG_FreePool(0, pMemory, ".\\Src\\D2Comp.cpp", 0x939, 0);
}

// 0x00504D30
void __stdcall D2Win_10159(D2CelFileStrc* pSquelchCelFile, D2CelFileStrc* pSelectedCelFile)
{
    ghSquelchCelFile_0087E844 = pSquelchCelFile;
    gnSquelchCelFileFrameCount_0087E848 = CelFileGetCelsPerDirection(pSquelchCelFile);
    ghSelectedCelFile_0087E850 = pSelectedCelFile;
    gnSelectedCelFileFrameCount_0087E854 = CelFileGetCelsPerDirection(pSelectedCelFile);
}

// 0x00505160
D2CompositeUnitStrc* __stdcall D2Win_10148(D2CompositeUnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0xD4C);
    return ptUnit->pNext;
}

// 0x005051A0
void __stdcall D2Win_10149(D2CompositeUnitStrc* ptUnit, unsigned char nValue)
{
    D2_ASSERT(ptUnit, 0xD57);
    const int nLow = nValue > 0 ? nValue : 0;
    ptUnit->unk0x04 = nLow < ptUnit->unk0x05 ? (nValue > 0 ? nValue : 0) : ptUnit->unk0x05;
}

// 0x00505200
unsigned char __stdcall D2Win_10150(D2CompositeUnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0xD61);
    return ptUnit->unk0x05;
}

// 0x005052B0
void __stdcall D2Win_10152(D2CompositeUnitStrc* ptUnit, int nX)
{
    D2_ASSERT(ptUnit, 0xD81);
    ptUnit->nX = nX;
}

// 0x005052F0
void __stdcall D2Win_10153(D2CompositeUnitStrc* ptUnit, int nY)
{
    D2_ASSERT(ptUnit, 0xD8C);
    ptUnit->nY = nY;
}

// 0x00505330
unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc* hCompositeUnit)
{
    D2_ASSERT(hCompositeUnit, 0xD95);
    return hCompositeUnit->dwFlags;
}

#include "gen/data/Source/D2Win/Src/D2WinTextBox_004FBC80.inc"
