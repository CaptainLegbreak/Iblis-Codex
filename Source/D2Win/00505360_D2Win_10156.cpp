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

struct tagPOINT
{
    long x;
    long y;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2CelFileStrc;
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

struct D2WinSmackStrc
{
    D2WinControlStrc controlHeader;
    char szFileName[256];
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
};

struct D2WinListDataStrc
{
    Unicode wszText[256];
    int field_200;
    D2WinMsgHandler field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    char field_218;
    char field_219;
    char field_21A;
    char field_21B;
    unsigned short field_21C;
    unsigned short field_21E;
    D2WinListDataStrc* pNext;
};

struct D2WinListStrc
{
    D2WinControlStrc controlHeader;
    int eFont;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int nWidestEntry;
    D2WinListDataStrc* pDataList;
    D2WinListDataStrc* pSelectedDataEntry;
};

struct D2WinAccountListDataStrc;

struct D2WinAccountListStrc
{
    D2WinControlStrc controlHeader;
    D2WinAccountListDataStrc* pDataList;
    D2WinAccountListDataStrc* pSelectedDataEntry;
    int field_48;
    int field_4C;
    int eFont;
    int field_54;
};

struct D2WinAccountListFontStrc
{
    int eFont;
    int field_04;
};

struct D2WinProgressBarStrc
{
    D2WinControlStrc controlHeader;
    float fProgress;
};

struct D2WinTextBoxStrc;

struct D2WinScrollBarStrc
{
    D2WinControlStrc controlHeader;
    int bIsUpperArrowPressed;
    int bIsLowerArrowPressed;
    int nMaxSteps;
    int nCurrentStep;
    int field_50;
    D2WinTextBoxStrc* pTextBox;
    int bIsStepIndicatorDragged;
    D2WinMsgHandler field_5C;
};

struct D2CompositeUnitStrc
{
    unsigned int dwFlags;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName);                         // 0x006CC1A0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330

int __stdcall SMsgRegisterCommand(void* hWnd, int nId, D2WinMsgHandler pfnHandler);                         // 0x00420BF0
int __stdcall SMsgRegisterKeyDown(void* hWnd, int nId, D2WinMsgHandler pfnHandler);                         // 0x00420C10
int __stdcall SMsgRegisterKeyUp(void* hWnd, int nId, D2WinMsgHandler pfnHandler);                           // 0x00420C30
int __stdcall SMsgRegisterMessage(void* hWnd, int nId, D2WinMsgHandler pfnHandler);                         // 0x00420C50
int __stdcall SMsgUnregisterCommand(void* hWnd, int nId, D2WinMsgHandler pfnHandler);                       // 0x00420C70
int __stdcall SMsgUnregisterKeyDown(void* hWnd, int nId, D2WinMsgHandler pfnHandler);                       // 0x00420C90
int __stdcall SMsgUnregisterKeyUp(void* hWnd, int nId, D2WinMsgHandler pfnHandler);                         // 0x00420CB0
int __stdcall SMsgUnregisterMessage(void* hWnd, int nId, D2WinMsgHandler pfnHandler);                       // 0x00420CD0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                                // 0x0040B380
void __stdcall WINDOW_DecodeSmacker(const char* szSmacker, unsigned char* pBuffer, int nVersion);           // 0x004F5E00
void __stdcall WINDOW_CloseSmacker(void* pContext);                                                         // 0x004F5E80
int __stdcall sub_004F91C0(void* pEditBox);                                                                  // 0x004F91C0
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210
const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nRank, int bSoftCore);                     // 0x00505640
int __stdcall ACCOUNTLIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                        // 0x00507A10
int __fastcall ACCOUNTLIST_Draw(D2WinControlStrc* pControl);                                                // 0x00507B30
int __fastcall PROGRESSBAR_Draw(D2WinControlStrc* pControl);                                                // 0x00507DC0
int __stdcall SCROLLBAR_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                          // 0x00508120
int __fastcall SCROLLBAR_Draw(D2WinControlStrc* pControl);                                                  // 0x00508370

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4
extern char gszSmackFileName_0087E860[260];                                                                 // 0x0087E860
extern char gnSmackVersion_0087E964;                                                                        // 0x0087E964
extern int gbSmackKeepFile_0087E968;                                                                        // 0x0087E968
unsigned long gdwListLastClickTick_0087E970;                                                                // 0x0087E970

int __stdcall SCROLLBAR_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg);

// 0x00505360
void __stdcall D2Win_10156(D2CompositeUnitStrc* pCompositeUnit, int nFlags)
{
    D2_ASSERT(pCompositeUnit, 0xDA2);
    pCompositeUnit->dwFlags = nFlags;
}

// 0x005068A0
const char* __stdcall D2Win_10161(int nClass, int nLevel, int bExpansion, int bSoftCore)
{
    int nRank;
    if (bSoftCore)
    {
        if (nLevel < 5)
            nRank = 0;
        else if (nLevel < 10)
            nRank = 1;
        else if (nLevel < 15)
            nRank = 2;
        else
            nRank = 3;
    }
    else
    {
        if (nLevel < 4)
            nRank = 0;
        else if (nLevel < 8)
            nRank = 1;
        else if (nLevel < 12)
            nRank = 2;
        else
            nRank = 3;
    }
    if (bExpansion && nRank)
        nRank += 3;
    return D2Win_10160_GetPlayerTitle(nClass, nRank, bSoftCore);
}

// 0x00506910
int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion)
{
    D2_ASSERT(pSmack->controlHeader.nType == D2WIN_SMACK, 0x53);
    strncpy(pSmack->szFileName, szFileName, 0x100);
    WINDOW_CloseSmacker(&pSmack->field_140);
    WINDOW_DecodeSmacker(pSmack->szFileName, (unsigned char*)&pSmack->field_140, nVersion);
    strncpy(gszSmackFileName_0087E860, szFileName, 0x104);
    gnSmackVersion_0087E964 = nVersion;
    return 1;
}

// 0x00506990
int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack)
{
    D2_ASSERT(pSmack->controlHeader.nType == D2WIN_SMACK, 0x66);
    WINDOW_CloseSmacker(&pSmack->field_140);
    if (!gbSmackKeepFile_0087E968)
        DeleteFileA(pSmack->szFileName);
    return 1;
}

// 0x005069F0
int __stdcall SMACK_SetCoordinates(D2WinSmackStrc* pSmack, int nX, int nY)
{
    D2_ASSERT(pSmack->controlHeader.nType == D2WIN_SMACK, 0x7B);
    pSmack->controlHeader.nImageX = nX;
    pSmack->controlHeader.nImageY = nY;
    pSmack->field_148 = nX;
    pSmack->field_14C = nY;
    return 1;
}

// 0x00506B10
int __stdcall SMACK_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinSmackStrc* pSmack = (D2WinSmackStrc*)pMsg->hWnd;
    D2_ASSERT(pSmack->controlHeader.nType == D2WIN_SMACK, 0xC0);
    if (!(pSmack->controlHeader.dwFlags & gdwBitMasks[2]) || !(pSmack->controlHeader.dwFlags & gdwBitMasks[0]) || !pSmack->controlHeader.field_34)
        return 0;
    return pSmack->controlHeader.field_34(pMsg);
}

// 0x00506C40
void __fastcall WREGISTER_RegisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback)
{
    D2_ASSERT(hWnd, 0x13);
    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x17);
        D2_ASSERT(nId != 0x101, 0x18);
        D2_ASSERT(nId != 0x100, 0x19);
        SMsgRegisterMessage(hWnd, nId, pCallback);
        break;
    case 1:
        SMsgRegisterCommand(hWnd, nId, pCallback);
        break;
    case 2:
        SMsgRegisterKeyUp(hWnd, nId, pCallback);
        break;
    case 3:
        SMsgRegisterKeyDown(hWnd, nId, pCallback);
        break;
    default:
        return;
    }
}

// 0x00506CF0
void __fastcall WREGISTER_UnregisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback)
{
    D2_ASSERT(hWnd, 0x30);
    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x34);
        D2_ASSERT(nId != 0x101, 0x35);
        D2_ASSERT(nId != 0x100, 0x36);
        SMsgUnregisterMessage(hWnd, nId, pCallback);
        break;
    case 1:
        SMsgUnregisterCommand(hWnd, nId, pCallback);
        break;
    case 2:
        SMsgUnregisterKeyUp(hWnd, nId, pCallback);
        break;
    case 3:
        SMsgUnregisterKeyDown(hWnd, nId, pCallback);
        break;
    default:
        return;
    }
}

// 0x005072F0
int __stdcall LIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinListStrc* pList = (D2WinListStrc*)pMsg->hWnd;
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0x154);
    const int nX = gMousePosition_6F8FE234.x;
    const int nY = gMousePosition_6F8FE234.y;
    const unsigned long dwTickCount = GetTickCount();
    for (D2WinListDataStrc* pData = pList->pDataList; pData; pData = pData->pNext)
    {
        if (nX > pData->field_208 && nX < pData->field_20C && nY > pData->field_210 && nY < pData->field_214)
        {
            if (pData != pList->pSelectedDataEntry || dwTickCount - gdwListLastClickTick_0087E970 >= 300)
                pList->pSelectedDataEntry = pData;
            else if (pData->field_204)
                return pData->field_204(pMsg);
        }
    }
    gdwListLastClickTick_0087E970 = dwTickCount;
    if (pList->controlHeader.field_34)
        return pList->controlHeader.field_34(pMsg);
    return 0;
}

// 0x005073B0
int __stdcall LIST_HandleCharInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinListStrc* pList = (D2WinListStrc*)pMsg->hWnd;
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0x179);
    for (D2WinListDataStrc* pData = pList->pDataList; pData; pData = pData->pNext)
    {
        if (pData->field_218 == (char)pMsg->wParam && pData->field_204)
            return pData->field_204(pMsg);
    }
    return 0;
}

// 0x00507420
int __stdcall LIST_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinListStrc* pList = (D2WinListStrc*)pMsg->hWnd;
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0x18F);
    if (pMsg->uMessage == 0x102)
        return 0;
    switch (pMsg->wParam)
    {
    case 0x0D:
        sub_004F91C0(0);
        if (pList->pSelectedDataEntry->field_204)
            return pList->pSelectedDataEntry->field_204(pMsg);
        break;
    case 0x26:
    {
        D2WinListDataStrc* pTemp = pList->pDataList;
        if (pList->pDataList == pList->pSelectedDataEntry)
        {
            while (pTemp->pNext)
                pTemp = pTemp->pNext;
        }
        else
        {
            while (pTemp->pNext != pList->pSelectedDataEntry)
                pTemp = pTemp->pNext;
        }
        pList->pSelectedDataEntry = pTemp;
        pList->field_54 = 0;
        for (D2WinListDataStrc* pData = pList->pDataList; pData != pTemp; pData = pData->pNext)
            ++pList->field_54;
        const int nIndex = pList->field_54;
        if (pList->field_4C > nIndex)
            pList->field_4C = nIndex;
        else
            for (int n = nIndex - pList->field_4C; n > pList->field_58; --n)
                ++pList->field_4C;
        sub_004F91C0(0);
        return 1;
    }
    case 0x28:
    {
        D2WinListDataStrc* pNext = pList->pSelectedDataEntry->pNext;
        if (!pNext)
            pNext = pList->pDataList;
        pList->pSelectedDataEntry = pNext;
        pList->field_54 = 0;
        for (D2WinListDataStrc* pData = pList->pDataList; pData != pNext; pData = pData->pNext)
            ++pList->field_54;
        const int nIndex = pList->field_54;
        if (pList->field_4C > nIndex)
            pList->field_4C = nIndex;
        else
            for (int n = nIndex - pList->field_4C; n > pList->field_58; --n)
                ++pList->field_4C;
        sub_004F91C0(0);
        return 1;
    }
    }
    for (D2WinListDataStrc* pData = pList->pDataList; pData; pData = pData->pNext)
    {
        if (pData->field_21C == pMsg->wParam && pData->field_204)
            return pData->field_204(pMsg);
    }
    return 0;
}

// 0x00507CA0
D2WinAccountListStrc* __fastcall ACCOUNTLIST_Create(int nX, int nY, int nWidth, int nHeight, int a5, D2WinAccountListFontStrc* pFont)
{
    D2WinAccountListStrc* pAccountList = (D2WinAccountListStrc*)FOG_Alloc(sizeof(D2WinAccountListStrc), ".\\Src\\D2WinAccountList.cpp", 0x24, 0);
    memset(pAccountList, 0, sizeof(D2WinAccountListStrc));
    pAccountList->controlHeader.nType = D2WIN_ACCOUNTLIST;
    pAccountList->controlHeader.dwFlags |= gdwBitMasks[0];
    pAccountList->controlHeader.dwFlags |= gdwBitMasks[2];
    pAccountList->field_4C = a5;
    pAccountList->controlHeader.nImageX = nX;
    pAccountList->controlHeader.nImageY = nY;
    pAccountList->controlHeader.nWidth = nWidth;
    pAccountList->controlHeader.nHeight = nHeight;
    pAccountList->controlHeader.pfDraw = ACCOUNTLIST_Draw;
    pAccountList->controlHeader.pfHandleMouseDown = ACCOUNTLIST_HandleMouseDown;
    pAccountList->controlHeader.pfHandleMouseUp = 0;
    pAccountList->controlHeader.pfHandleCharInput = 0;
    pAccountList->controlHeader.pfHandleVirtualKeyInput = 0;
    pAccountList->controlHeader.field_34 = 0;
    pAccountList->pDataList = 0;
    pAccountList->pSelectedDataEntry = 0;
    pAccountList->field_48 = 0;
    pAccountList->controlHeader.pNext = 0;
    if (pFont)
    {
        pAccountList->eFont = pFont->eFont;
        pAccountList->field_54 = pFont->field_04;
    }
    else
    {
        pAccountList->eFont = 1;
        pAccountList->field_54 = 0;
    }
    CONTROL_AppendToList(&pAccountList->controlHeader);
    return pAccountList;
}

// 0x00507D70
int __stdcall PROGRESSBAR_SetProgress(D2WinProgressBarStrc* pProgressBar, float fProgress)
{
    D2_ASSERT(pProgressBar->controlHeader.nType == D2WIN_PROGRESSBAR, 0x3A);
    pProgressBar->fProgress = fProgress;
    return 1;
}

// 0x00507E50
D2WinProgressBarStrc* __fastcall PROGRESSBAR_Create(int nX, int nY, int nWidth, int nHeight)
{
    D2WinProgressBarStrc* pProgressBar = (D2WinProgressBarStrc*)FOG_Alloc(sizeof(D2WinProgressBarStrc), ".\\Src\\D2WinProgressBar.cpp", 0x1A, 0);
    memset(pProgressBar, 0, sizeof(D2WinProgressBarStrc));
    pProgressBar->controlHeader.nType = D2WIN_PROGRESSBAR;
    pProgressBar->controlHeader.dwFlags |= gdwBitMasks[0];
    pProgressBar->controlHeader.dwFlags |= gdwBitMasks[2];
    pProgressBar->controlHeader.pCellFile = 0;
    pProgressBar->controlHeader.nImageX = nX;
    pProgressBar->controlHeader.nImageY = nY;
    pProgressBar->controlHeader.nWidth = nWidth;
    pProgressBar->controlHeader.nHeight = nHeight;
    pProgressBar->controlHeader.pfDraw = PROGRESSBAR_Draw;
    pProgressBar->controlHeader.pNext = 0;
    pProgressBar->controlHeader.pfHandleMouseDown = 0;
    pProgressBar->controlHeader.pfHandleMouseUp = 0;
    pProgressBar->controlHeader.pfHandleCharInput = 0;
    pProgressBar->controlHeader.pfHandleVirtualKeyInput = 0;
    pProgressBar->controlHeader.field_34 = 0;
    pProgressBar->fProgress = 0.0f;
    CONTROL_AppendToList(&pProgressBar->controlHeader);
    return pProgressBar;
}

// 0x00508310
int __stdcall SCROLLBAR_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinScrollBarStrc* pScrollBar = (D2WinScrollBarStrc*)pMsg->hWnd;
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_SCROLLBAR, 0x1B0);
    if (pScrollBar->bIsUpperArrowPressed || pScrollBar->bIsLowerArrowPressed || pScrollBar->bIsStepIndicatorDragged)
    {
        pScrollBar->bIsUpperArrowPressed = 0;
        pScrollBar->bIsLowerArrowPressed = 0;
        pScrollBar->bIsStepIndicatorDragged = 0;
        return 1;
    }
    return 0;
}

// 0x005084F0
D2WinScrollBarStrc* __fastcall SCROLLBAR_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, D2WinMsgHandler a6)
{
    D2WinScrollBarStrc* pScrollBar = (D2WinScrollBarStrc*)FOG_Alloc(sizeof(D2WinScrollBarStrc), ".\\Src\\D2WinScrollbar.cpp", 0x1C, 0);
    memset(pScrollBar, 0, sizeof(D2WinScrollBarStrc));
    pScrollBar->controlHeader.nType = D2WIN_SCROLLBAR;
    pScrollBar->controlHeader.dwFlags |= gdwBitMasks[0];
    pScrollBar->controlHeader.dwFlags |= gdwBitMasks[2];
    pScrollBar->controlHeader.pCellFile = pCellFile;
    pScrollBar->controlHeader.nImageX = nX;
    pScrollBar->controlHeader.nImageY = nY;
    pScrollBar->controlHeader.nWidth = nWidth;
    pScrollBar->controlHeader.nHeight = nHeight;
    pScrollBar->controlHeader.pfDraw = SCROLLBAR_Draw;
    pScrollBar->controlHeader.pNext = 0;
    pScrollBar->controlHeader.pfHandleMouseDown = SCROLLBAR_HandleMouseDown;
    pScrollBar->controlHeader.pfHandleMouseUp = SCROLLBAR_HandleMouseUp;
    pScrollBar->controlHeader.pfHandleCharInput = 0;
    pScrollBar->controlHeader.pfHandleVirtualKeyInput = 0;
    pScrollBar->controlHeader.field_34 = a6;
    pScrollBar->bIsUpperArrowPressed = 0;
    pScrollBar->bIsLowerArrowPressed = 0;
    pScrollBar->nMaxSteps = 0;
    pScrollBar->nCurrentStep = 0;
    pScrollBar->pTextBox = 0;
    pScrollBar->field_5C = 0;
    pScrollBar->field_50 = 0;
    CONTROL_AppendToList(&pScrollBar->controlHeader);
    return pScrollBar;
}
