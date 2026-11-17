enum D2ControlTypes
{
    D2WIN_EDITBOX = 1,
    D2WIN_IMAGE = 2,
    D2WIN_ANIMIMAGE = 3,
    D2WIN_TEXTBOX = 4,
    D2WIN_SCROLLBAR = 5,
    D2WIN_BUTTON = 6,
    D2WIN_LIST = 7,
    D2WIN_TIMER = 8,
    D2WIN_SMACK = 9,
    D2WIN_PROGRESSBAR = 10,
    D2WIN_POPUP = 11,
    D2WIN_ACCOUNTLIST = 12,
    D2WIN_IMAGE2 = 13,
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

struct Unicode
{
    unsigned short wChar;
};

struct D2CelFileStrc;
struct D2FontStrc;
struct D2CharStrc;
struct D2WinControlStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinControlStrc
{
    int nType;
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

struct D2WinScrollBarStrc;

struct D2WinTextBoxStrc
{
    D2WinControlStrc controlHeader;
    int unk0x40[20];
    D2WinScrollBarStrc* pScrollBar;
};

struct D2WinTimerStrc
{
    D2WinControlStrc controlHeader;
    unsigned int nTimeout;
    unsigned int dwTickCount;
};

struct D2WinEditBoxStrc
{
    D2WinControlStrc controlHeader;
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
    void* pfOnReturn;
    void* pfKeyFilter;
    void* pfOnChange;
    int eFont;
    int nTextColor;
    D2WinEditBoxStrc* pNext;
    D2WinEditBoxStrc* pPrevious;
    int bMouseSelecting;
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

struct D2WinSmackStrc
{
    D2WinControlStrc controlHeader;
};

struct D2WinListDataStrc
{
    Unicode wszText[256];
    int unk0x200[8];
    D2WinListDataStrc* pNext;
};

struct D2WinListStrc
{
    D2WinControlStrc controlHeader;
    int unk0x40[9];
    D2WinListDataStrc* pDataList;
};

struct D2WinAccountListDataStrc
{
    char szText[50];
    short field_32;
    D2WinAccountListDataStrc* pNext;
};

struct D2WinAccountListStrc
{
    D2WinControlStrc controlHeader;
    D2WinAccountListDataStrc* pDataList;
};

struct D2WinScrollBarStrc
{
    D2WinControlStrc controlHeader;
    int unk0x40;
    int unk0x44;
    int nMaxSteps;
    int nCurrentStep;
    int unk0x50;
    D2WinTextBoxStrc* pTextBox;
};

struct D2WinPopUpLineStrc
{
    Unicode wszText[64];
    void (__stdcall* pfHandleMouseInput)();
};

struct D2WinPopUpStrc
{
    D2WinControlStrc controlHeader;
    int nLines;
    D2WinPopUpLineStrc lines[8];
    int nCurrentLine;
};

struct D2FontCacheStrc
{
    D2CelFileStrc* pCellFile;
    D2FontStrc* pFontInfo[2];
    D2CharStrc* pCharInfo;
    unsigned int dwShiftedTickCount;
};

struct D2CofDataStrc
{
    unsigned char nLayers;
    unsigned char nFramesPerDirection;
    unsigned char nDirections;
    unsigned char nVersion;
    unsigned int unk0x04;
    unsigned int nBoxLeft;
    unsigned int nBoxRight;
    unsigned int nBoxTop;
    unsigned int nBoxBottom;
    unsigned int nAnimSpeed;
};

struct D2CofNodeStrc
{
    int nRefCount;
    int nMode;
    unsigned int nClass;
    unsigned int dwWeaponClass;
    unsigned int unk0x10;
    D2CofDataStrc* pCofData;
};

struct D2CofInfoStrc
{
    D2CofNodeStrc* pCofNode;
    D2CofInfoStrc* pNext;
};

struct D2GfxInfoStrc
{
    D2CofInfoStrc* pCofInfo;
};

struct D2CompositeUnitStrc
{
    unsigned int dwFlags;
    unsigned char nDirection;
    unsigned char nDirections;
    unsigned char unk0x06;
    unsigned char unk0x07;
    int nFrame;
    int nFrameCount;
    unsigned int nAnimSpeed;
    int nX;
    int nY;
    int nUnitIndex;
    int nMode;
    char unk0x24[0x94];
    D2GfxInfoStrc* pGfxInfo;
    D2CelFileStrc* pEmblemCellFile;
    unsigned char nEmblemColor1;
    unsigned char nEmblemColor2;
    unsigned char unk0xC2;
    unsigned char unk0xC3;
    D2CompositeUnitStrc* pNext;
};

struct D2EmblemColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall GlobalUnlock(void* hMem);                                    // 0x006CC364
extern "C" __declspec(dllimport) void* __stdcall GlobalLock(void* hMem);                                    // 0x006CC368
extern "C" __declspec(dllimport) void* __stdcall GlobalAlloc(unsigned int uFlags, unsigned int dwBytes);    // 0x006CC36C
extern "C" __declspec(dllimport) void* __stdcall GlobalFree(void* hMem);                                    // 0x006CC370
extern "C" __declspec(dllimport) void* __stdcall GetClipboardData(unsigned int uFormat);                    // 0x006CC454
extern "C" __declspec(dllimport) int __stdcall CloseClipboard();                                            // 0x006CC51C
extern "C" __declspec(dllimport) int __stdcall OpenClipboard(void* hWnd);                                   // 0x006CC524
extern "C" __declspec(dllimport) int __stdcall IsClipboardFormatAvailable(unsigned int uFormat);            // 0x006CC528
extern "C" __declspec(dllimport) void* __stdcall SetClipboardData(unsigned int uFormat, void* hMem);        // 0x006CC52C
extern "C" __declspec(dllimport) int __stdcall EmptyClipboard();                                            // 0x006CC530
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
extern "C" unsigned int __cdecl strlen(const char* szString);

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* __cdecl sub_004F59A0();                                                                              // 0x004F59A0
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310
void __fastcall sub_004FAAE0_FreeCellFile(D2CelFileStrc* pCellFile);                                        // 0x004FAAE0
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);   // 0x004FB180
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
int __fastcall sub_6F8B1C60(D2WinControlStrc* pControl);                                                    // 0x004FD860
int __fastcall sub_6F8B1CF0(D2WinControlStrc* pControl);                                                    // 0x004FD8F0
int __stdcall TIMER_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg);                                        // 0x004FD970
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0
int __stdcall sub_005041B0_Destroy(D2CompositeUnitStrc* pComposite, int nFlag);                             // 0x005041B0
int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack);                                                     // 0x00506990
void __fastcall sub_00507EE0(void* pArg);                                                                   // 0x00507EE0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
extern D2EmblemColorStrc gaEmblemColorRGB1_0072E19C[10];                                                    // 0x0072E19C
extern D2EmblemColorStrc gaEmblemColorRGB2_0072E1BC[10];                                                    // 0x0072E1BC
extern int gnWinCallbackDepth_007D55C4;                                                                     // 0x007D55C4
char gszClipboardText_00841B80[0x200];                                                                      // 0x00841B80
extern D2CelFileStrc* ghMonsterIndicators_00841DA4;                                                         // 0x00841DA4
extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8
extern unsigned char gabEmblemColor1_0087D810[];                                                            // 0x0087D810
extern unsigned char gabEmblemColor2_0087E82C[];                                                            // 0x0087E82C
D2CompositeUnitStrc* gpCompositeUnitList_0087E838;                                                          // 0x0087E838
D2WinPopUpStrc* gpPopUp_0087E974;                                                                           // 0x0087E974

static void* ghClipboardData_00841D80;                                                                      // 0x00841D80

// 0x004FC960
int __fastcall D2Win_10043_TEXTBOX_Destroy(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0xCB);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0xCC);
    if (pTextBox->pScrollBar)
        sub_00507EE0(pTextBox->pScrollBar);
    sub_004FB6A0_ClearText(&pTextBox->controlHeader);
    return CONTROL_RemoveFromList(&pTextBox->controlHeader);
}

// 0x004FD060
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText)
{
    sub_004FC9B0_SetText(pControl, pText, 4, 0, 0);
}

// 0x004FD830
void __fastcall sub_004FD830_2(D2WinTimerStrc* pTimer)
{
    D2_ASSERT(pTimer->controlHeader.nType == D2WIN_TIMER, 0x3B);
    pTimer->controlHeader.pfHandleVirtualKeyInput = 0;
}

// 0x004FD9D0
D2WinTimerStrc* __fastcall TIMER_Create(unsigned int nTimeout, D2WinMsgHandler pfCallback)
{
    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)FOG_Alloc(sizeof(D2WinTimerStrc), ".\\Src\\D2WinTimer.cpp", 0x1C, 0);
    memset(pTimer, 0, sizeof(D2WinTimerStrc));
    pTimer->controlHeader.nType = D2WIN_TIMER;
    pTimer->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pTimer->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pTimer->nTimeout = nTimeout;
    pTimer->dwTickCount = GetTickCount();
    pTimer->controlHeader.pfInitialize = sub_6F8B1C60;
    pTimer->controlHeader.pNext = 0;
    pTimer->controlHeader.field_34 = pfCallback;
    pTimer->controlHeader.pfHandleVirtualKeyInput = TIMER_HandleVirtualKeyInput;
    CONTROL_AppendToList(&pTimer->controlHeader);
    return pTimer;
}

// 0x004FDA50
void __fastcall sub_004FDA50_2(D2WinTimerStrc* pTimer)
{
    D2_ASSERT(pTimer->controlHeader.nType == D2WIN_TIMER, 0x45);
    pTimer->controlHeader.pfInitialize = sub_6F8B1CF0;
}

// 0x004FDAA0
int __fastcall D2Win_10071_EDITBOX_Destroy(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x6E);
    D2_ASSERT(pEditBox->controlHeader.nType == D2WIN_EDITBOX, 0x70);
    return CONTROL_RemoveFromList(&pEditBox->controlHeader);
}

// 0x004FDAD0
void __fastcall sub_004FDAD0(D2WinEditBoxStrc* pEditBox, void* pfKeyFilter)
{
    D2_ASSERT(pEditBox, 0x79);
    D2_ASSERT(pEditBox->controlHeader.nType == D2WIN_EDITBOX, 0x7B);
    pEditBox->pfKeyFilter = pfKeyFilter;
}

// 0x004FDB00
void __fastcall sub_004FDB00(D2WinEditBoxStrc* pEditBox, void* pfOnChange)
{
    D2_ASSERT(pEditBox, 0x86);
    D2_ASSERT(pEditBox->controlHeader.nType == D2WIN_EDITBOX, 0x88);
    pEditBox->pfOnChange = pfOnChange;
}

// 0x004FDB40
const char* __cdecl sub_004FDB40_GetClipboardText()
{
    if (!IsClipboardFormatAvailable(1))
        return &gszEmptyAssertText;
    if (!OpenClipboard(sub_004F59A0()))
        return &gszEmptyAssertText;
    void* hData = GetClipboardData(1);
    if (hData)
    {
        const char* szData = (const char*)GlobalLock(hData);
        if (szData)
        {
            strncpy(gszClipboardText_00841B80, szData, 0x200);
            GlobalUnlock(hData);
        }
    }
    CloseClipboard();
    return gszClipboardText_00841B80;
}

// 0x004FDBB0
int __fastcall sub_004FDBB0_SetClipboardText(const char* szText)
{
    if (ghClipboardData_00841D80)
    {
        GlobalFree(ghClipboardData_00841D80);
        ghClipboardData_00841D80 = 0;
    }
    if (!OpenClipboard(sub_004F59A0()))
        return 0;
    EmptyClipboard();
    const int nLength = strlen(szText);
    ghClipboardData_00841D80 = GlobalAlloc(0x2000, nLength + 1);
    if (!ghClipboardData_00841D80)
    {
        CloseClipboard();
        return 0;
    }
    char* pData = (char*)GlobalLock(ghClipboardData_00841D80);
    memcpy(pData, szText, nLength);
    pData[nLength] = 0;
    GlobalUnlock(ghClipboardData_00841D80);
    SetClipboardData(1, ghClipboardData_00841D80);
    CloseClipboard();
    return 1;
}

// 0x004FDCC0
void __fastcall sub_004FDCC0(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x1A4);
    D2_ASSERT(pEditBox->controlHeader.nType == D2WIN_EDITBOX, 0x1A6);
    pEditBox->nSelectionStart = -1;
    pEditBox->nSelectionEnd = 0;
}

// 0x004FDD00
int __fastcall D2Win_10082(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x1B3);
    D2_ASSERT(pEditBox->controlHeader.nType == D2WIN_EDITBOX, 0x1B5);
    pEditBox->nSelectionStart = 0;
    pEditBox->nSelectionEnd = sub_00526800(pEditBox->wszText);
    return pEditBox->nSelectionEnd;
}

// 0x004FDD50
void __fastcall sub_004FDD50(D2WinEditBoxStrc* pEditBox, int nMaxLength)
{
    D2_ASSERT(pEditBox, 0x445);
    D2_ASSERT(pEditBox->controlHeader.nType == D2WIN_EDITBOX, 0x448);
    pEditBox->nMaxLength = nMaxLength;
}

// 0x004FDD90
const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x47E);
    D2_ASSERT(pEditBox->controlHeader.nType == D2WIN_EDITBOX, 0x480);
    return pEditBox->wszText;
}

// 0x004FDDD0
void __fastcall D2Win_10080_EDITBOX_SetNextEditBox(D2WinEditBoxStrc* pEditBox, D2WinEditBoxStrc* pNext)
{
    D2_ASSERT(pEditBox, 0x48A);
    D2_ASSERT(pEditBox->controlHeader.nType == D2WIN_EDITBOX, 0x48C);
    D2_ASSERT(pNext, 0x48E);
    D2_ASSERT(pNext->controlHeader.nType == D2WIN_EDITBOX, 0x490);
    pEditBox->pNext = pNext;
    pNext->pPrevious = pEditBox;
}

// 0x00500930
int __fastcall BUTTON_Destroy(D2WinButtonStrc* pButton)
{
    D2_ASSERT(pButton->controlHeader.nType == D2WIN_BUTTON, 0x59);
    return CONTROL_RemoveFromList(&pButton->controlHeader);
}

// 0x00500960
int __fastcall BUTTON_IsPressed(D2WinButtonStrc* pButton)
{
    D2_ASSERT(pButton->controlHeader.nType == D2WIN_BUTTON, 0x65);
    return pButton->bIsPressed && pButton->bIsCallbackPending ? 1 : 0;
}

// 0x00500AB0
void __fastcall BUTTON_SimulateClick(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)pMsg->hWnd;
    D2_ASSERT(pButton->controlHeader.nType == D2WIN_BUTTON, 0xBC);
    if (pButton->controlHeader.pfHandleMouseDown)
    {
        pButton->nActivationCounter = 1;
        pButton->controlHeader.pfHandleMouseDown(pMsg);
        if (pButton->controlHeader.pfHandleMouseUp)
        {
            SMSGHANDLER_PARAMS tMsg;
            tMsg.hWnd = pMsg->hWnd;
            ++gnWinCallbackDepth_007D55C4;
            pButton->controlHeader.pfHandleMouseUp(&tMsg);
            --gnWinCallbackDepth_007D55C4;
        }
    }
}

// 0x00500BF0
void __fastcall BUTTON_SetStringId(D2WinButtonStrc* pButton, int nStringId)
{
    D2_ASSERT(pButton->controlHeader.nType == D2WIN_BUTTON, 0x100);
    pButton->nStringId = nStringId;
}

// 0x005015F0
void __stdcall D2Win_10116()
{
    for (int i = 0; i < 14; ++i)
    {
        if (gFontCache_00841DA8[i].pCellFile)
        {
            sub_004FAAE0_FreeCellFile(gFontCache_00841DA8[i].pCellFile);
            gFontCache_00841DA8[i].pCellFile = 0;
        }
        if (gFontCache_00841DA8[i].pFontInfo[0])
        {
            FOG_Free(gFontCache_00841DA8[i].pFontInfo[0], ".\\Src\\D2WinFont.cpp", 0x135, 0);
            gFontCache_00841DA8[i].pFontInfo[0] = 0;
        }
    }
    sub_004FAAE0_FreeCellFile(ghMonsterIndicators_00841DA4);
    ghMonsterIndicators_00841DA4 = 0;
}

// 0x00501820
int __fastcall sub_00501820(const Unicode* wszText)
{
    return D2Win_10122(wszText, sub_00526800(wszText));
}

// build: context sub_D2Win_10143_ApplyCof
static int sub_D2Win_10143_ApplyCof(D2CompositeUnitStrc* pCompositeUnit, D2CofNodeStrc* pCofNode, int nMode)
{
    D2CofDataStrc* pCofData = pCofNode->pCofData;
    D2_ASSERT(pCofData, 0x3DD);
    pCompositeUnit->nMode = nMode;
    pCompositeUnit->nFrameCount = pCofData->nFramesPerDirection;
    pCompositeUnit->nFrame = 0;
    pCompositeUnit->nAnimSpeed = pCofData->nAnimSpeed;
    pCompositeUnit->nDirections = pCofData->nDirections;
    return 1;
}

// 0x005042F0
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode)
{
    D2_ASSERT(pCompositeUnit, 0x8BF);
    for (D2CofInfoStrc* pCofInfo = pCompositeUnit->pGfxInfo->pCofInfo; pCofInfo; pCofInfo = pCofInfo->pNext)
    {
        if (pCofInfo->pCofNode->nMode == nMode)
            return sub_D2Win_10143_ApplyCof(pCompositeUnit, pCofInfo->pCofNode, nMode);
    }
    return 0;
}

// 0x00505100
void __stdcall D2Win_10146()
{
    D2CompositeUnitStrc* pCompositeUnit = gpCompositeUnitList_0087E838;
    while (pCompositeUnit)
    {
        D2CompositeUnitStrc* pNext = pCompositeUnit->pNext;
        sub_005041B0_Destroy(pCompositeUnit, 0);
        FOG_Free(pCompositeUnit, ".\\Src\\D2Comp.cpp", 0xD38, 0);
        pCompositeUnit = pNext;
    }
    gpCompositeUnitList_0087E838 = 0;
}

// 0x00505230
int __stdcall D2Win_10169(D2CompositeUnitStrc* pCompositeUnit)
{
    D2_ASSERT(pCompositeUnit, 0xD6B);
    return pCompositeUnit->nFrameCount;
}

// 0x00505260
void __stdcall D2Win_10151(D2CompositeUnitStrc* pCompositeUnit, int nFrame)
{
    D2_ASSERT(pCompositeUnit, 0xD76);
    const int nValue = nFrame > 0 ? nFrame : 0;
    const int nMax = pCompositeUnit->nFrameCount << 8;
    pCompositeUnit->nFrame = nValue < nMax ? nValue : nMax;
}

// 0x005055D0
void __fastcall sub_005055D0_ApplyPalette()
{
    for (int i = 0; i < 10; ++i)
        gabEmblemColor1_0087D810[i] = D2Win_10034_MixRGB(gaEmblemColorRGB1_0072E19C[i].nRed, gaEmblemColorRGB1_0072E19C[i].nGreen, gaEmblemColorRGB1_0072E19C[i].nBlue);
    for (int i = 0; i < 10; ++i)
        gabEmblemColor2_0087E82C[i] = D2Win_10034_MixRGB(gaEmblemColorRGB2_0072E1BC[i].nRed, gaEmblemColorRGB2_0072E1BC[i].nGreen, gaEmblemColorRGB2_0072E1BC[i].nBlue);
}

// 0x00506A40
int __fastcall SMACK_Destroy(D2WinSmackStrc* pSmack)
{
    D2_ASSERT(pSmack->controlHeader.nType == D2WIN_SMACK, 0x8C);
    SMACK_DeleteFile(pSmack);
    return CONTROL_RemoveFromList(&pSmack->controlHeader);
}

// 0x00506E60
int __fastcall LIST_Destroy(D2WinListStrc* pList)
{
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0x80);
    D2WinListDataStrc* pNext = 0;
    for (D2WinListDataStrc* pData = pList->pDataList; pData; pData = pNext)
    {
        pNext = pData->pNext;
        FOG_Free(pData, ".\\Src\\D2WinList.cpp", 0x85, 0);
    }
    return CONTROL_RemoveFromList(&pList->controlHeader);
}

// 0x00507850
void __fastcall ACCOUNTLIST_FreeData(D2WinAccountListStrc* pAccountList)
{
    D2_ASSERT(pAccountList->controlHeader.nType == D2WIN_ACCOUNTLIST, 0x5D);
    D2WinAccountListDataStrc* pNext = 0;
    for (D2WinAccountListDataStrc* pData = pAccountList->pDataList; pData; pData = pNext)
    {
        pNext = pData->pNext;
        FOG_Free(pData, ".\\Src\\D2WinAccountList.cpp", 0x63, 0);
    }
}

// 0x00507AF0
int __fastcall ACCOUNTLIST_Destroy(D2WinAccountListStrc* pAccountList)
{
    D2_ASSERT(pAccountList->controlHeader.nType == D2WIN_ACCOUNTLIST, 0x50);
    ACCOUNTLIST_FreeData(pAccountList);
    return CONTROL_RemoveFromList(&pAccountList->controlHeader);
}

// 0x00507F20
int __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* pScrollBar, int nMaxSteps)
{
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_SCROLLBAR, 0x56);
    pScrollBar->nMaxSteps = nMaxSteps > 0 ? nMaxSteps : 0;
    return 1;
}

// 0x00507F60
int __fastcall SCROLLBAR_SetCurrentStep(D2WinScrollBarStrc* pScrollBar, int nCurrentStep)
{
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_SCROLLBAR, 0x65);
    if (nCurrentStep > pScrollBar->nMaxSteps)
        nCurrentStep = pScrollBar->nMaxSteps;
    pScrollBar->nCurrentStep = nCurrentStep;
    return 1;
}

// 0x00507FD0
int __fastcall SCROLLBAR_SetTextBox(D2WinScrollBarStrc* pScrollBar, D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_SCROLLBAR, 0x7F);
    pScrollBar->pTextBox = pTextBox;
    return 1;
}

// 0x005085A0
int __stdcall POPUP_Destroy()
{
    int nResult = 0;
    if (gpPopUp_0087E974)
    {
        nResult = CONTROL_RemoveFromList(&gpPopUp_0087E974->controlHeader);
        gpPopUp_0087E974 = 0;
    }
    return nResult;
}

// 0x005085C0
int __stdcall POPUP_IsActive()
{
    D2WinPopUpStrc* pPopUp = gpPopUp_0087E974;
    if (!pPopUp)
        return 0;
    D2_ASSERT(pPopUp->controlHeader.nType == D2WIN_POPUP, 0x62);
    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
        return 0;
    return 1;
}

// 0x005086A0
int __stdcall POPUP_HandleMouseButtonInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinPopUpStrc* pPopUp = gpPopUp_0087E974;
    D2_ASSERT(pPopUp->controlHeader.nType == D2WIN_POPUP, 0x90);
    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
        return 0;
    const int nCurrentLine = pPopUp->nCurrentLine;
    if (nCurrentLine == -1)
        return 0;
    void (__stdcall* pfHandleMouseInput)() = pPopUp->lines[nCurrentLine].pfHandleMouseInput;
    if (!pfHandleMouseInput)
        return 0;
    pfHandleMouseInput();
    return 1;
}

#include "gen/data/Source/D2Win/004FC960_D2Win_10043_TEXTBOX_Destroy.inc"
