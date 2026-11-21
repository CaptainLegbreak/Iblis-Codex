#include "D2Win.h"
#include "D2CmpTypes.h"
#include "D2WinTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"

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

struct D2FontStrc;

struct D2CharStrc;

struct D2WinControlStrc;

struct D2WinTimerStrc
{
    D2WinControlStrc controlHeader;
    unsigned int nTimeout;
    unsigned int dwTickCount;
};

struct D2WinListDataStrc
{
    Unicode wszText[256];
    int unk0x200[8];
    D2WinListDataStrc* pNext;
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

struct D2EmblemColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

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

extern "C" unsigned int __cdecl strlen(const char* szString);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

void* __cdecl sub_004F59A0();                                                                              // 0x004F59A0

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210

int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310

void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

int __fastcall sub_6F8B1C60(D2WinControlStrc* pControl);                                                    // 0x004FD860

int __fastcall sub_6F8B1CF0(D2WinControlStrc* pControl);                                                    // 0x004FD8F0

int __stdcall TIMER_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg);                                        // 0x004FD970

int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0

void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink); // 0x005041B0

int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack);                                                     // 0x00506990

void __fastcall sub_00507EE0(void* pArg);                                                                   // 0x00507EE0

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern D2EmblemColorStrc gaEmblemColorRGB1_0072E19C[10];                                                    // 0x0072E19C

extern D2EmblemColorStrc gaEmblemColorRGB2_0072E1BC[10];                                                    // 0x0072E1BC

extern D2CelFileStrc* ghMonsterIndicators_00841DA4;                                                         // 0x00841DA4

extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8

extern unsigned char gabEmblemColor1_0087D810[];                                                            // 0x0087D810

extern unsigned char gabEmblemColor2_0087E82C[];                                                            // 0x0087E82C

D2CompositeUnitStrc* gpCompositeUnitList_0087E838;                                                          // 0x0087E838

D2WinPopUpStrc* gpPopUp_0087E974;                                                                           // 0x0087E974

struct D2CelFileStrc;

struct D2CelStrc;

struct D2WinImageClickRectStrc;

struct D2WinImage2Strc
{
    D2WinControlStrc controlHeader;
    int nFrame;
    int eDrawMode;
    D2WinImageClickRectStrc* pClickRect;
};

struct D2AnimatedImageDescriptor;

struct D2CompPairStrc
{
    int nKey;
    int nValue;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090


void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                                // 0x0040B380

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

int __fastcall IMAGE2_Draw(D2WinControlStrc* pControl);                                                     // 0x004FD1F0

int __fastcall IMAGE_Draw(D2WinControlStrc* pControl);                                                      // 0x004FD470

int __stdcall IMAGE2_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                             // 0x004FD5D0

int __fastcall ANIMIMAGE_ShouldMouseInputBeHandled(D2WinControlStrc* pControl);                             // 0x005003A0

int __fastcall ANIMIMAGE_Draw(D2WinControlStrc* pControl);                                                  // 0x005005B0

void __fastcall D2SOUND_10039(const char* szFile);                                                          // 0x00514EC0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

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

// 0x004FD830
void __fastcall sub_004FD830_2(D2WinTimerStrc* ptTimerData)
{
    D2_ASSERT(ptTimerData->controlHeader.eType == D2WIN_TIMER, 0x3B);
    ptTimerData->controlHeader.pfHandleVirtualKeyInput = 0;
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

// 0x004FD9D0
D2WinTimerStrc* __fastcall TIMER_Create(unsigned int nTimeout, D2WinMsgHandler pfCallback)
{
    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)FOG_Alloc(sizeof(D2WinTimerStrc), ".\\Src\\D2WinTimer.cpp", 0x1C, 0);
    memset(pTimer, 0, sizeof(D2WinTimerStrc));
    pTimer->controlHeader.eType = D2WIN_TIMER;
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
void __fastcall sub_004FDA50_2(D2WinTimerStrc* ptTimerData)
{
    D2_ASSERT(ptTimerData->controlHeader.eType == D2WIN_TIMER, 0x45);
    ptTimerData->controlHeader.pfInitialize = sub_6F8B1CF0;
}

// 0x004FDCC0
void __fastcall sub_004FDCC0(D2WinEditBoxStrc* ptEditData)
{
    D2_ASSERT(ptEditData, 0x1A4);
    D2_ASSERT(ptEditData->controlHeader.eType == D2WIN_EDITBOX, 0x1A6);
    ptEditData->nSelectionStart = -1;
    ptEditData->nSelectionEnd = 0;
}

// 0x00504270
void __stdcall D2Win_10154(D2CompositeUnitStrc* hCompositeUnit, const Unicode* a2, const Unicode* a3, const Unicode* a4, const Unicode* a5, int a6, int a7)
{
    D2_ASSERT(hCompositeUnit, 0x8A8);
    sub_005267E0((Unicode*)hCompositeUnit->wszAccountName, a2);
    sub_005267E0((Unicode*)hCompositeUnit->wszCharName, a3);
    sub_005267E0((Unicode*)hCompositeUnit->wszGuildTag, a4);
    sub_005267E0((Unicode*)hCompositeUnit->wszRealmName, a5);
    hCompositeUnit->nCharLevel = a6;
    hCompositeUnit->dwProductCode = a7;
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

// 0x00505100
void __stdcall D2Win_10146()
{
    D2CompositeUnitStrc* pCompositeUnit = gpCompositeUnitList_0087E838;
    while (pCompositeUnit)
    {
        D2CompositeUnitStrc* pNext = pCompositeUnit->pNext;
        D2Win_10142_CompUnitDestroy(pCompositeUnit, 0);
        FOG_Free(pCompositeUnit, ".\\Src\\D2Comp.cpp", 0xD38, 0);
        pCompositeUnit = pNext;
    }
    gpCompositeUnitList_0087E838 = 0;
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
    ptUnit->nDirection = nLow < ptUnit->nDirections ? (nValue > 0 ? nValue : 0) : ptUnit->nDirections;
}

// 0x00505200
unsigned char __stdcall D2Win_10150(D2CompositeUnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0xD61);
    return ptUnit->nDirections;
}

// 0x00505230
int __stdcall D2Win_10169(D2CompositeUnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0xD6B);
    return ptUnit->nFrameCount;
}

// 0x00505260
void __stdcall D2Win_10151(D2CompositeUnitStrc* ptUnit, int nFrame)
{
    D2_ASSERT(ptUnit, 0xD76);
    const int nValue = nFrame > 0 ? nFrame : 0;
    const int nMax = ptUnit->nFrameCount << 8;
    ptUnit->nFrame = nValue < nMax ? nValue : nMax;
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

// 0x005055D0
void __fastcall sub_005055D0_ApplyPalette()
{
    for (int i = 0; i < 10; ++i)
        gabEmblemColor1_0087D810[i] = D2Win_10034_MixRGB(gaEmblemColorRGB1_0072E19C[i].nRed, gaEmblemColorRGB1_0072E19C[i].nGreen, gaEmblemColorRGB1_0072E19C[i].nBlue);
    for (int i = 0; i < 10; ++i)
        gabEmblemColor2_0087E82C[i] = D2Win_10034_MixRGB(gaEmblemColorRGB2_0072E1BC[i].nRed, gaEmblemColorRGB2_0072E1BC[i].nGreen, gaEmblemColorRGB2_0072E1BC[i].nBlue);
}

#include "gen/data/Source/D2Win/Src/D2WinTextBox_004FBC80.inc"
