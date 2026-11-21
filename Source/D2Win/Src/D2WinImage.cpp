#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Win.h"
#include "D2StormTypes.h"
#include "D2Win32Types.h"
#include "D2CelContext.h"
#include "D2CmpTypes.h"
#include "D2WinTypes.h"
#include "D2WinControls.h"
#include "D2Unicode.h"
#include "D2ClientTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;

struct D2WinControlStrc;

struct D2WinImageClickRectStrc;

struct D2UnitStrc;

struct D2CofDataStrc;

struct D2WinControl004FD110Strc;

struct Unicode;

struct tagRECT;

struct D2WinImage2Strc;

struct D2WinTimerStrc;

struct D2WinCommandRegisterStrc;

struct D2WinListDataStrc;

struct D2WinListStrc;

struct D2WinAccountListDataStrc;

struct D2WinAccountListStrc;

struct D2WinProgressBarStrc;

struct D2WinPopUpLineStrc;

struct D2WinPopUpStrc;

struct D2CelContextStrc;

struct D2CofNodeStrc;

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

struct D2WinControl004FD110Strc
{
    int eType;
    D2CelFileStrc* pCellFile;
    unsigned char f_8[0x38];
    int nFrame;
};

int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCellFile); // 0x006019F0

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

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __stdcall D2GFX_UtilRect(tagRECT* pRect, unsigned char nPaletteIndex); // 0x004F62A0

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

void __fastcall WREGISTER_RegisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback); // 0x00506C40

void __fastcall WREGISTER_UnregisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback); // 0x00506CF0

extern void* sghPentagram; // 0x0087E96C

struct D2WinImageClickRectStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int unk0x10;
    int (__stdcall* pCallback)(SMSGHANDLER_PARAMS* pMsg);
};

extern D2CofNodeStrc* gpCofNodeList_0087E83C; // 0x0087E83C

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

enum DrawMode
{
    DRAWMODE_NORMAL = 5,
};

void __stdcall TEXTURE_CelDrawClipped(D2GfxDataStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode); // 0x004F6510

int __fastcall D2Win_10058_0(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn);         // 0x004FB790

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210

int __stdcall IMAGE2_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                             // 0x004FD5D0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

// build: symbol ?IMAGE_Draw@@YIHPAUD2WinControlStrc@@@Z 0x004FD470

// 0x004FD110
int __stdcall sub_004FD110_SetFrame(D2WinControl004FD110Strc* pControl, int nFrame)
{
    D2_ASSERT(pControl->eType == 2, 0x8B);
    const int nFrames = CelFileGetCelsPerDirection(pControl->pCellFile);
    if (nFrame > nFrames - 1)
    {
        nFrame = nFrames - 1;
    }
    if (nFrame < 0)
    {
        nFrame = 0;
    }
    pControl->nFrame = nFrame;
    return 1;
}

unsigned int gdwTimeoutTickCount; // 0x00841B74

// 0x004FD1F0
int __fastcall IMAGE2_Draw(D2WinControlStrc* pControl)
{
    D2WinImage2Strc* pImage = (D2WinImage2Strc*)pControl;

    D2_ASSERT(pImage->controlHeader.eType == D2WIN_IMAGE, 0xB6);

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
        tContext.nDirection = 0;
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

int __fastcall sub_004FCD90_D2Win_10058(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn)
{
    return D2Win_10058_0(pControl, pText, a3, nColumn);
}

// 0x004FD340
static void __stdcall sub_004FD340_ImageDrawTiled(const D2CropRectStrc* pDst, const D2CropRectStrc* pSrc, D2GfxDataStrc* pGfxData)
{
    const int nSrcWidth = pSrc->nX1 - pSrc->nX0;
    const int nDstWidth = pDst->nX1 - pDst->nX0;
    const int nSrcHeight = pSrc->nY1 - pSrc->nY0;
    const int nDstHeight = pDst->nY1 - pDst->nY0;
    if (nSrcWidth == nDstWidth && nSrcHeight == nDstHeight)
    {
        TEXTURE_CelDrawClipped(pGfxData, pDst->nX0 - pSrc->nX0, pDst->nY1 - pSrc->nY1 + 256, (void*)pDst, DRAWMODE_NORMAL);
        return;
    }

    const int nColumns = (nDstWidth + nSrcWidth - 1) / nSrcWidth;
    const int nRows = (nDstHeight + nSrcHeight - 1) / nSrcHeight;
    int nY = pDst->nY0 - pSrc->nY0 + 256;
    D2CropRectStrc tRect;
    for (int j = 0; j < nRows; ++j)
    {
        int nX = pDst->nX0 - pSrc->nX0;
        for (int i = 0; i < nColumns; ++i)
        {
            tRect.nX0 = D2_MAX(pDst->nX0, pSrc->nX0 + nX);
            tRect.nX1 = D2_MIN(pDst->nX1, tRect.nX0 + nSrcWidth);
            tRect.nY0 = D2_MAX(pDst->nY0, pSrc->nY0 + nY - 256);
            tRect.nY1 = D2_MIN(pDst->nY1, tRect.nY0 + nSrcHeight);
            TEXTURE_CelDrawClipped(pGfxData, nX, nY, &tRect, DRAWMODE_NORMAL);
            nX += nSrcWidth;
        }
        nY += nSrcHeight;
    }
}

int __fastcall sub_005C33D0_GetSkillValue(int nSkillId)
{
    switch (nSkillId)
    {
    case SKILL_PENETRATE:
        return 0xA;
    case SKILL_IMMOLATIONARROW:
        return 0xC;
    case SKILL_METEOR:
        return 0xB;
    }
    return 0;
}

// 0x004FD5A0
static inline int sub_004FD5A0_IsInClickRect(const D2WinImageClickRectStrc* pClickRect, int nX, int nY)
{
    const int nTop = pClickRect->nY;
    if (nX >= pClickRect->nX && nY >= nTop - pClickRect->nHeight && nX < pClickRect->nX + pClickRect->nWidth && nY < nTop)
    {
        return 1;
    }
    return 0;
}

// 0x004FD860
int __fastcall sub_6F8B1C60(D2WinControlStrc* pControl)
{
    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)pControl;

    D2_ASSERT(pTimer->controlHeader.eType == D2WIN_TIMER, 0x52);

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

    D2_ASSERT(pTimer->controlHeader.eType == D2WIN_TIMER, 0x6A);

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

// 0x00503310
static inline D2CofNodeStrc* sub_00503310_FindCofNode(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    for (D2CofNodeStrc* pNode = gpCofNodeList_0087E83C; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nClass == nClass && pNode->dwWeaponClass == dwWeaponClass)
        {
            ++pNode->nRefCount;
            return pNode;
        }
    }
    return 0;
}

static inline void sub_0057B7A0_AddDefenseFromStat(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, STAT_ITEM_DAMAGETARGETAC, 0);
    if (nValue)
    {
        int nNew = STATLIST_UnitGetStatValue(pDefender, STAT_ARMORCLASS, 0) + nValue;
        if (nNew < 0)
        {
            nNew = 0;
        }
        STATLIST_SetUnitStat(pDefender, STAT_ARMORCLASS, nNew, 0);
    }
}

int __stdcall sub_M118_Emit_004FD5A0(const D2WinImageClickRectStrc* pClickRect, int nX, int nY)
{
    while (pClickRect && pClickRect->pCallback)
    {
        if (sub_004FD5A0_IsInClickRect(pClickRect, nX, nY))
        {
            return 1;
        }
        ++pClickRect;
    }
    return 0;
}

D2CofNodeStrc* __stdcall sub_M118_Emit_00503310(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    return sub_00503310_FindCofNode(nClass, nMode, dwWeaponClass);
}

void __stdcall sub_M118_Emit_0057B7A0(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    sub_0057B7A0_AddDefenseFromStat(pAttacker, pDefender);
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

    D2_ASSERT(pList->controlHeader.eType == D2WIN_LIST, 0x119);

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
    tContext.pCellFile = sghPentagram;
    tContext.nDirection = 0;
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


// 0x00507DC0
int __fastcall PROGRESSBAR_Draw(D2WinControlStrc* pControl)
{
    D2WinProgressBarStrc* pProgressBar = (D2WinProgressBarStrc*)pControl;

    D2_ASSERT(pProgressBar->controlHeader.eType == D2WIN_PROGRESSBAR, 0x4F);

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

    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0xC6);

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

int __fastcall IMAGE_Draw(D2WinControlStrc* pControl)
{
    D2WinImageStrc* pImage = (D2WinImageStrc*)pControl;

    D2_ASSERT(pImage->controlHeader.eType == D2WIN_IMAGE, 0x10F);

    const int nBorderX = pImage->field_4C;
    const int nBorderY = pImage->field_50;
    D2GfxDataStrc tGfxData;
    memset(&tGfxData, 0, sizeof(tGfxData));
    tGfxData.pCellFile = pImage->controlHeader.pCellFile;
    tGfxData.nDirection = 0;
    tGfxData.nFrame = 0;

    int nX[4];
    int nY[4];
    int nSrcY[4];
    int nSrcX[4];
    nSrcX[0] = 0;
    nSrcX[1] = nBorderX;
    nSrcX[2] = 256 - nBorderX;
    nSrcX[3] = 256;
    nSrcY[0] = 0;
    nSrcY[1] = nBorderY;
    nSrcY[2] = 256 - nBorderY;
    nSrcY[3] = 256;
    nX[0] = pImage->controlHeader.nImageX;
    nX[1] = pImage->controlHeader.nImageX + nBorderX;
    nX[2] = pImage->controlHeader.nImageX + pImage->controlHeader.nWidth - nBorderX;
    nX[3] = pImage->controlHeader.nImageX + pImage->controlHeader.nWidth;
    nY[0] = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight;
    nY[1] = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight + nBorderY;
    nY[2] = pImage->controlHeader.nImageY - nBorderY;
    nY[3] = pImage->controlHeader.nImageY;
    D2CropRectStrc tDst;
    D2CropRectStrc tSrc;
    for (int j = 0; j < 3; ++j)
    {
        tSrc.nY0 = nSrcY[j];
        tSrc.nY1 = nSrcY[j + 1];
        for (int i = 0; i < 3; ++i)
        {
            tDst.nX0 = nX[i];
            tDst.nX1 = nX[i + 1];
            tDst.nY0 = nY[j];
            tDst.nY1 = nY[j + 1];
            tSrc.nX0 = nSrcX[i];
            tSrc.nX1 = nSrcX[i + 1];
            sub_004FD340_ImageDrawTiled(&tDst, &tSrc, &tGfxData);
        }
    }

    return 1;
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

#include "gen/data/Source/D2Win/Src/D2WinImage.inc"
