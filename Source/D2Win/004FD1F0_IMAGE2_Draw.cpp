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

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
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

struct D2WinImageClickRectStrc;

struct D2WinImage2Strc
{
    D2WinControlStrc controlHeader;
    int nFrame;
    int eDrawMode;
    D2WinImageClickRectStrc* pClickRect;
};

struct D2WinTimerStrc
{
    D2WinControlStrc controlHeader;
    unsigned int nTimeout;
    unsigned int dwTickCount;
};

struct D2WinCommandRegisterStrc
{
    int nType;
    int nId;
    D2WinMsgHandler pCallback;
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
    int field_21C;
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
    D2WinAccountListDataStrc* pSelectedDataEntry;
    int field_48;
    int field_4C;
    int eFont;
    int field_54;
};

struct D2WinProgressBarStrc
{
    D2WinControlStrc controlHeader;
    float fProgress;
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

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __stdcall D2GFX_UtilRect(tagRECT* pRect, unsigned char nPaletteIndex);                                 // 0x004F62A0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);   // 0x004FB180
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);         // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall WREGISTER_RegisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback);       // 0x00506C40
void __fastcall WREGISTER_UnregisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback);     // 0x00506CF0

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
unsigned int gdwTimeoutTickCount;                                                                           // 0x00841B74
extern void* ghPentagramCellFile;                                                                           // 0x0087E96C

// 0x004FD1F0
int __fastcall IMAGE2_Draw(D2WinControlStrc* pControl)
{
    D2WinImage2Strc* pImage = (D2WinImage2Strc*)pControl;

    D2_ASSERT(pImage->controlHeader.nType == D2WIN_IMAGE, 0xB6);

    if (!(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    if (pImage->controlHeader.pCellFile)
    {
        const int nX = pImage->controlHeader.nImageX;
        const int nBaseY = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight + 1;
        const int nColumns = (pImage->controlHeader.nWidth + 255) >> 8;
        const int nRows = ((pImage->controlHeader.nHeight + 255) >> 8) - 1;

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = pImage->controlHeader.pCellFile;
        tContext.unk0x40 = 0;
        tContext.nFrame = pImage->nFrame;

        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nColumns; ++j)
            {
                sub_004F6480(&tContext, nX + 256 * j, nBaseY + 256 * (i + 1), -1, pImage->eDrawMode, 0);
                ++tContext.nFrame;
            }
        }

        if (nRows >= 0)
        {
            for (int i = 0; i < nColumns; ++i)
            {
                sub_004F6480(&tContext, nX + 256 * i, pImage->controlHeader.nImageY, -1, pImage->eDrawMode, 0);
                ++tContext.nFrame;
            }
        }
    }

    return 1;
}

// 0x004FD860
int __fastcall sub_6F8B1C60(D2WinControlStrc* pControl)
{
    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)pControl;

    D2_ASSERT(pTimer->controlHeader.nType == D2WIN_TIMER, 0x52);

    if (!(pTimer->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTimer->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned int dwNow = GetTickCount();
    const unsigned int dwStart = pTimer->dwTickCount / 1000;
    if (dwNow / 1000 - dwStart <= pTimer->nTimeout)
    {
        return 1;
    }

    SMSGHANDLER_PARAMS tMsg;
    tMsg.hWnd = pTimer;

    if (pTimer->controlHeader.field_34)
    {
        pTimer->controlHeader.field_34(&tMsg);
    }

    return 1;
}

// 0x004FD8F0
int __fastcall sub_6F8B1CF0(D2WinControlStrc* pControl)
{
    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)pControl;

    D2_ASSERT(pTimer->controlHeader.nType == D2WIN_TIMER, 0x6A);

    if (!(pTimer->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTimer->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned int dwTickCount = GetTickCount();
    if (dwTickCount < gdwTimeoutTickCount)
    {
        return 1;
    }

    SMSGHANDLER_PARAMS tMsg;
    tMsg.hWnd = pTimer;

    if (pTimer->controlHeader.field_34)
    {
        pTimer->controlHeader.field_34(&tMsg);
    }

    gdwTimeoutTickCount = dwTickCount + pTimer->nTimeout;
    return 1;
}

// 0x00506DA0
void __fastcall WREGISTER_RegisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands)
{
    D2_ASSERT(hWnd, 0x4D);

    for (unsigned int i = 0; i < nCommands; ++i)
    {
        WREGISTER_RegisterCommand(hWnd, pCommandRegister[i].nType, pCommandRegister[i].nId, pCommandRegister[i].pCallback);
    }
}

// 0x00506E00
void __fastcall WREGISTER_UnregisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands)
{
    D2_ASSERT(hWnd, 0x5A);

    for (unsigned int i = 0; i < nCommands; ++i)
    {
        WREGISTER_UnregisterCommand(hWnd, pCommandRegister[i].nType, pCommandRegister[i].nId, pCommandRegister[i].pCallback);
    }
}

// 0x00507160
int __fastcall LIST_Draw(D2WinControlStrc* pControl)
{
    D2WinListStrc* pList = (D2WinListStrc*)pControl;

    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0x119);

    sub_00502EF0(pList->eFont);

    int nTextY = pList->controlHeader.nImageY - pList->controlHeader.nHeight + pList->field_48 + pList->field_44;

    D2WinListDataStrc* pData = pList->pDataList;
    for (int i = 0; i < pList->field_4C; ++i)
    {
        if (pData)
        {
            pData = pData->pNext;
        }
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = ghPentagramCellFile;
    tContext.unk0x40 = 0;
    tContext.nFrame = pList->field_5C;

    while (pData)
    {
        if (nTextY >= pList->controlHeader.nImageY)
        {
            break;
        }

        const int nTextX = pList->controlHeader.nImageX + ((pList->controlHeader.nWidth - pData->field_200) >> 1);

        if (pData == pList->pSelectedDataEntry)
        {
            int nImageY = nTextY + 3;
            if (pList->eFont == 2)
            {
                nImageY += 6;
            }

            const int nOffsetX = (pList->controlHeader.nWidth - pList->nWidestEntry) >> 2;
            const int nImageX1 = pList->controlHeader.nImageX + nOffsetX - 25;
            const int nImageX2 = pList->controlHeader.nImageX - nOffsetX + pList->controlHeader.nWidth - 25;
            sub_004F6480(&tContext, nImageX1, nImageY, -1, 5, 0);
            sub_004F6480(&tContext, nImageX2, nImageY, -1, 5, 0);
        }

        sub_00502320(pData->wszText, nTextX, nTextY, 0, 0);

        pData->field_208 = pList->controlHeader.nImageX;
        pData->field_20C = pData->field_208 + pList->controlHeader.nWidth;
        pData->field_210 = nTextY - pList->field_44 - pList->field_48;
        pData->field_214 = nTextY + pList->field_48;

        nTextY += pList->field_44 + 2 * pList->field_48;

        pData = pData->pNext;
    }

    ++pList->field_5C;
    if (pList->field_5C >= 8)
    {
        pList->field_5C = 0;
    }

    sub_00502EF0(1);

    return 1;
}

// 0x00507900
int __fastcall ACCOUNTLIST_RemoveEntry(D2WinAccountListStrc* pAccountList, const char* szText)
{
    D2_ASSERT(pAccountList->controlHeader.nType == D2WIN_ACCOUNTLIST, 0x90);

    D2WinAccountListDataStrc* pPrevious = 0;
    for (D2WinAccountListDataStrc* pData = pAccountList->pDataList; pData; pData = pData->pNext)
    {
        if (!strcmp(pData->szText, szText))
        {
            if (pAccountList->pSelectedDataEntry == pData)
            {
                pAccountList->pSelectedDataEntry = 0;
            }

            if (pPrevious)
            {
                pPrevious->pNext = pData->pNext;
            }
            else
            {
                pAccountList->pDataList = pData->pNext;
            }

            FOG_Free(pData, ".\\Src\\D2WinAccountList.cpp", 0xA7, 0);
            return 1;
        }

        pPrevious = pData;
    }

    return 0;
}

// 0x00507DC0
int __fastcall PROGRESSBAR_Draw(D2WinControlStrc* pControl)
{
    D2WinProgressBarStrc* pProgressBar = (D2WinProgressBarStrc*)pControl;

    D2_ASSERT(pProgressBar->controlHeader.nType == D2WIN_PROGRESSBAR, 0x4F);

    if (!(pProgressBar->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pProgressBar->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned char nColor = D2Win_10034_MixRGB(0xFF, 0, 0);
    D2GFX_DrawBox(
        pProgressBar->controlHeader.nImageX,
        pProgressBar->controlHeader.nImageY,
        pProgressBar->controlHeader.nImageX + (int)(pProgressBar->controlHeader.nWidth * pProgressBar->fProgress),
        pProgressBar->controlHeader.nImageY + pProgressBar->controlHeader.nHeight,
        nColor,
        5);

    return 1;
}

// 0x005087A0
int __fastcall POPUP_Draw(D2WinControlStrc* pControl)
{
    D2WinPopUpStrc* pPopUp = (D2WinPopUpStrc*)pControl;

    D2_ASSERT(pPopUp->controlHeader.nType == D2WIN_POPUP, 0xC6);

    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned char nColor = D2Win_10034_MixRGB(0x3F, 0x3F, 0x3F);

    tagRECT tRect = { pPopUp->controlHeader.nImageX - 5, pPopUp->controlHeader.nImageY - pPopUp->controlHeader.nHeight - 5, pPopUp->controlHeader.nImageX + pPopUp->controlHeader.nWidth + 5, pPopUp->controlHeader.nImageY + 5 };

    D2GFX_UtilRect(&tRect, 0xFF);
    D2GFX_DrawBox(tRect.left, tRect.bottom, tRect.right, tRect.top, nColor, 2);
    sub_00502EF0(1);

    for (int i = 0; i < pPopUp->nLines; ++i)
    {
        sub_00502320(pPopUp->lines[i].wszText, pPopUp->controlHeader.nImageX, pPopUp->controlHeader.nImageY + 20 * (i - pPopUp->nLines + 1), ((i != pPopUp->nCurrentLine) - 1) & 3, 0);
    }

    return 1;
}

#include "gen/data/Source/D2Win/004FD1F0_IMAGE2_Draw.inc"
