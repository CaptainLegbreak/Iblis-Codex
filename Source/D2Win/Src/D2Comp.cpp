#include "D2WinTypes.h"
#include "D2WinControls.h"
#include "D2Win32Types.h"
#include "D2CmpTypes.h"
#include "D2Records.h"
#include "D2StormTypes.h"
#include "D2TxtTables.h"
#include "D2Unicode.h"
#include "D2Win.h"

struct D2WinEditBoxStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;

struct D2TxtLinkStrc;

struct D2WinControlStrc;

struct D2WinAccountListDataStrc;

struct D2WinTextBoxStrc;

struct D2CofNodeStrc;

struct D2CofInfoStrc;

struct D2GfxInfoStrc;

struct D2CompositeUnitStrc;

struct D2PaletteRecordStrc;

struct D2BinFieldStrc;

struct D2ItemTypesTxt;

struct SMSGHANDLER_PARAMS;

struct Unicode;

struct D2WinSmackStrc;

struct D2WinListDataStrc;

struct D2WinListStrc;

struct D2WinAccountListStrc;

struct D2WinAccountListFontStrc;

struct D2WinProgressBarStrc;

struct D2WinScrollBarStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0

void __fastcall D2COMP_UnlinkCompositeUnit(D2CompositeUnitStrc* pCompositeUnit); // 0x00504100

struct D2PaletteRecordStrc
{
    unsigned char ab[0x100];
};

D2CompositeUnitStrc* gpCompositeUnitList_0087E838;                                                          // 0x0087E838

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker); // 0x006BD0B0

extern D2TxtLinkStrc* gpHitClassLinker_0087D820; // 0x0087D820

extern D2TxtLinkStrc* gpCompItemsLinker_0087D824; // 0x0087D824

extern D2TxtLinkStrc* gpItemTypesLinker_0087D828; // 0x0087D828

D2CofNodeStrc* gpCofNodeList_0087E83C; // 0x0087E83C

extern "C" const char szItemTypesFieldCode_006DCCE0[]; // 0x006DCCE0

extern "C" const char szItemTypesFieldEquiv1_006DCD14[]; // 0x006DCD14

extern "C" const char szItemTypesFieldEquiv2_006DCD0C[]; // 0x006DCD0C

extern "C" const char szBinFieldEnd_006D9060[]; // 0x006D9060

extern "C" const char szItemTypesTable_006DCD00[]; // 0x006DCD00

extern void* gpItemTypesTxt_0087D82C; // 0x0087D82C

extern int gnItemTypesTxtRecordCount_0087D830; // 0x0087D830

D2TxtLinkStrc* __stdcall sub_006BD040(const char* szFile, int nLine); // 0x006BD040

void* __stdcall D2COMP_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount, int nRecordSize); // 0x00504430

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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

int __stdcall SMsgRegisterCommand(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420BF0

int __stdcall SMsgRegisterKeyDown(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C10

int __stdcall SMsgRegisterKeyUp(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C30

int __stdcall SMsgRegisterMessage(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C50

int __stdcall SMsgUnregisterCommand(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C70

int __stdcall SMsgUnregisterKeyDown(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C90

int __stdcall SMsgUnregisterKeyUp(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420CB0

int __stdcall SMsgUnregisterMessage(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420CD0

void __stdcall WINDOW_DecodeSmacker(const char* szSmacker, unsigned char* pBuffer, int nVersion); // 0x004F5E00

void __stdcall WINDOW_CloseSmacker(void* pContext); // 0x004F5E80

int __stdcall CONTROL_SetFocusedEditBox(D2WinEditBoxStrc* pEditBox); // 0x004F91C0

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210

const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nRank, int bSoftCore); // 0x00505640

int __stdcall ACCOUNTLIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x00507A10

int __fastcall ACCOUNTLIST_Draw(D2WinControlStrc* pControl); // 0x00507B30

int __fastcall PROGRESSBAR_Draw(D2WinControlStrc* pControl); // 0x00507DC0

int __stdcall SCROLLBAR_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x00508120

int __fastcall SCROLLBAR_Draw(D2WinControlStrc* pControl); // 0x00508370

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern tagPOINT gMousePosition_6F8FE234; // 0x007D55A4

extern char gszSmackFileName_0087E860[260]; // 0x0087E860

extern char gnSmackVersion_0087E964; // 0x0087E964

extern int gbSmackKeepFile_0087E968; // 0x0087E968

int __stdcall SCROLLBAR_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg);

struct D2FontStrc;

struct D2CharStrc;

struct D2WinTimerStrc
{
    D2WinControlStrc controlHeader;
    unsigned int nTimeout;
    unsigned int dwTickCount;
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

void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink); // 0x005041B0

int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack);                                                     // 0x00506990

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern D2EmblemColorStrc gaEmblemColorRGB1_0072E19C[10];                                                    // 0x0072E19C

extern D2EmblemColorStrc gaEmblemColorRGB2_0072E1BC[10];                                                    // 0x0072E1BC

extern unsigned char gabEmblemColor1_0087D810[];                                                            // 0x0087D810

extern unsigned char gabEmblemColor2_0087E82C[];                                                            // 0x0087E82C

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

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile);                                                // 0x006019F0

extern D2CompPairStrc gaCompPairs_0072EF68[];                                                               // 0x0072EF68

extern unsigned int gnCompPairs_0072EFD0;                                                                   // 0x0072EFD0

extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                        // 0x00841DA0

extern D2CelFileStrc* ghSquelchCelFile_0087E844;                                                            // 0x0087E844

extern int gnSquelchCelFileFrameCount_0087E848;                                                             // 0x0087E848

extern D2CelFileStrc* ghSelectedCelFile_0087E850;                                                           // 0x0087E850

extern int gnSelectedCelFileFrameCount_0087E854;                                                            // 0x0087E854

unsigned char gabItemPalettes_00842710[9][0x6900]; // 0x00842710

unsigned long gdwListLastClickTick_0087E970; // 0x0087E970

// 0x00503410
static void __stdcall D2COMP_ReleaseCofNode(int bFree, D2CofNodeStrc* pCofNode)
{
    D2_ASSERT(pCofNode, 0x455);

    if (!gpCofNodeList_0087E83C)
        return;

    --pCofNode->nRefCount;
    if (pCofNode->nRefCount > 0)
        return;

    D2CofNodeStrc* pPrev = pCofNode->pPrev;
    D2CofNodeStrc* pNext = pCofNode->pNext;
    if (bFree)
    {
        FOG_Free(pCofNode->pCofData, ".\\Src\\D2Comp.cpp", 0x461, 0);
        pCofNode->pCofData = 0;
    }

    if (!pPrev)
    {
        gpCofNodeList_0087E83C = pNext;
        if (pNext)
            pNext->pPrev = 0;
    }
    else if (!pNext)
    {
        pPrev->pNext = 0;
    }
    else
    {
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
    }

    FOG_Free(pCofNode, ".\\Src\\D2Comp.cpp", 0x47A, 0);
}

// 0x005038D0
unsigned char* __fastcall D2COMP_GetComponentPalette(int nColor)
{
    int nRow = nColor >> 5;
    unsigned int nCol = nColor & 0x1F;
    if (nCol <= 0x14)
    {
        if (nRow == 0)
            nRow = 8;
        else if (nRow < 0)
            return 0;
        else if (nRow >= 9)
            return 0;
        else
        {
            if (nRow > 2)
            {
                if (nRow <= 4)
                    goto fail;
            }
        }
        return ((D2PaletteRecordStrc (*)[0x69])gabItemPalettes_00842710)[nRow][nCol].ab;
    }
fail:
    return 0;
}

// 0x00503F70
static inline int sub_00503F70(unsigned int selector)
{
    switch (selector) {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    default:
        return 1;
    }
}

int __stdcall emit_selector_00503F70(unsigned int selector)
{
    return sub_00503F70(selector);
}

// 0x00504020
int* __fastcall sub_00504020_ClearTable(int* table)
{
    for (int i = 0; i < 128; ++i)
        table[i] = 0;
    return table;
}

// 0x00504100
void __fastcall D2COMP_UnlinkCompositeUnit(D2CompositeUnitStrc* pCompositeUnit)
{
    D2CompositeUnitStrc* pPrev = pCompositeUnit->pPrev;
    D2CompositeUnitStrc* pNext = pCompositeUnit->pNext;
    if (!pPrev)
    {
        gpCompositeUnitList_0087E838 = pNext;
        if (pNext)
            pNext->pPrev = 0;
    }
    else if (!pNext)
    {
        pPrev->pNext = 0;
    }
    else
    {
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
    }
    FOG_Free(pCompositeUnit, ".\\Src\\D2Comp.cpp", 0x85A, 0);
}

// 0x00504170
int* __cdecl D2COMP_AllocGfxInfo()
{
    int* pValue = (int*)FOG_Alloc(4, ".\\Src\\D2Comp.cpp", 0x866, 0);
    D2_ASSERT(pValue, 0x867);
    *pValue = 0;
    return pValue;
}

// 0x005041B0
void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink)
{
    D2_ASSERT(pCompositeUnit, 0x877);

    D2GfxInfoStrc* pGfxInfo = pCompositeUnit->pGfxInfo;
    D2_ASSERT(pGfxInfo, 0x87B);

    D2CofInfoStrc* pCofInfo = pGfxInfo->pCofInfo;
    if (pCofInfo)
    {
        do
        {
            D2CofNodeStrc* pCofNode = pCofInfo->pCofNode;
            D2CofInfoStrc* pNext = pCofInfo->pNext;
            D2COMP_ReleaseCofNode(1, pCofNode);
            FOG_Free(pCofInfo, ".\\Src\\D2Comp.cpp", 0x883, 0);
            pCofInfo = pNext;
        }
        while (pCofInfo);
    }

    pGfxInfo->pCofInfo = 0;
    FOG_Free(pGfxInfo, ".\\Src\\D2Comp.cpp", 0x889, 0);

    if (pCompositeUnit->pEmblemCellFile)
    {
        ARCHIVE_FreeCellFile(pCompositeUnit->pEmblemCellFile);
        pCompositeUnit->pEmblemCellFile = 0;
    }

    if (bUnlink)
        D2COMP_UnlinkCompositeUnit(pCompositeUnit);
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
int __stdcall D2COMP_GetPairValue(int nKey)
{
    for (unsigned int i = 0; i < gnCompPairs_0072EFD0; ++i)
    {
        if (nKey == gaCompPairs_0072EF68[i].nKey)
            return gaCompPairs_0072EF68[i].nValue;
    }
    return 0;
}

// 0x005043B0
void __stdcall D2COMP_FreePoolMemory(void* pMemory)
{
    FOG_FreePool(0, pMemory, ".\\Src\\D2Comp.cpp", 0x939, 0);
}

// 0x005043D0
void __stdcall sub_005043D0_Stub4(int a1, int a2, int a3, int a4)
{
}

// 0x00504920
void __fastcall D2COMP_LoadItemTypes(void* hArchive)
{
    D2BinFieldStrc aItemTypesFields[] =
    {
        { szItemTypesFieldCode_006DCCE0, 0xA, 0, 0, &gpItemTypesLinker_0087D828 },
        { szItemTypesFieldEquiv1_006DCD14, 0xF, 0, 4, &gpItemTypesLinker_0087D828 },
        { szItemTypesFieldEquiv2_006DCD0C, 0xF, 0, 6, &gpItemTypesLinker_0087D828 },
        { szBinFieldEnd_006D9060, 0, 0, 0, 0 },
    };

    gpItemTypesLinker_0087D828 = sub_006BD040(".\\Src\\D2Comp.cpp", 0xA97);
    gpItemTypesTxt_0087D82C = D2COMP_CompileTxt(hArchive, szItemTypesTable_006DCD00, aItemTypesFields, &gnItemTypesTxtRecordCount_0087D830, 0xE4);
}

// 0x005049D0
void __stdcall D2COMP_FreeLinkers()
{
    if (gpCompItemsLinker_0087D824)
    {
        FOG_FreeLinker(gpCompItemsLinker_0087D824);
        gpCompItemsLinker_0087D824 = 0;
    }
    if (gpItemTypesLinker_0087D828)
    {
        FOG_FreeLinker(gpItemTypesLinker_0087D828);
        gpItemTypesLinker_0087D828 = 0;
    }
    if (gpHitClassLinker_0087D820)
    {
        FOG_FreeLinker(gpHitClassLinker_0087D820);
        gpHitClassLinker_0087D820 = 0;
    }
}

// 0x00504A20
int __stdcall D2COMP_IsItemTypeDescendant(int a1, int nItemType)
{
    if (!nItemType)
    {
        return 1;
    }

    if (!a1)
    {
        return 0;
    }

    int itemTypeStack[64];

    itemTypeStack[0] = a1;
    int nStackIndex = 1;
    while (nStackIndex)
    {
        const int v5 = itemTypeStack[nStackIndex - 1];
        --nStackIndex;

        if (nItemType == v5)
        {
            return 1;
        }

        D2ItemTypesTxt* pItemTypesTxtRecord = &((D2ItemTypesTxt*)gpItemTypesTxt_0087D82C)[v5];
        if (pItemTypesTxtRecord->nEquiv1)
        {
            itemTypeStack[nStackIndex] = pItemTypesTxtRecord->nEquiv1;
            ++nStackIndex;

            if (pItemTypesTxtRecord->nEquiv2)
            {
                itemTypeStack[nStackIndex] = pItemTypesTxtRecord->nEquiv2;
                ++nStackIndex;
            }
        }

        D2_ASSERT(nStackIndex < 64, 2898);
    }

    return 0;
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

// 0x00505360
void __stdcall D2Win_10156(D2CompositeUnitStrc* hCompositeUnit, int nFlags)
{
    D2_ASSERT(hCompositeUnit, 0xDA2);
    hCompositeUnit->dwFlags = nFlags;
}

// 0x005055D0
void __fastcall D2COMP_InitEmblemColorTables()
{
    for (int i = 0; i < 10; ++i)
        gabEmblemColor1_0087D810[i] = D2Win_10034_MixRGB(gaEmblemColorRGB1_0072E19C[i].nRed, gaEmblemColorRGB1_0072E19C[i].nGreen, gaEmblemColorRGB1_0072E19C[i].nBlue);
    for (int i = 0; i < 10; ++i)
        gabEmblemColor2_0087E82C[i] = D2Win_10034_MixRGB(gaEmblemColorRGB2_0072E1BC[i].nRed, gaEmblemColorRGB2_0072E1BC[i].nGreen, gaEmblemColorRGB2_0072E1BC[i].nBlue);
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
    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0x53);
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
    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0x66);
    WINDOW_CloseSmacker(&pSmack->field_140);
    if (!gbSmackKeepFile_0087E968)
        DeleteFileA(pSmack->szFileName);
    return 1;
}

// 0x005069F0
int __stdcall SMACK_SetCoordinates(D2WinSmackStrc* pSmack, int nX, int nY)
{
    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0x7B);
    pSmack->controlHeader.nImageX = nX;
    pSmack->controlHeader.nImageY = nY;
    pSmack->nMovieX = nX;
    pSmack->nMovieY = nY;
    return 1;
}

// 0x00506B10
int __stdcall SMACK_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinSmackStrc* pSmack = (D2WinSmackStrc*)pMsg->hWnd;
    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0xC0);
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
    D2_ASSERT(pList->controlHeader.eType == D2WIN_LIST, 0x154);
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
    D2_ASSERT(pList->controlHeader.eType == D2WIN_LIST, 0x179);
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
    D2_ASSERT(pList->controlHeader.eType == D2WIN_LIST, 0x18F);
    if (pMsg->uMessage == 0x102)
        return 0;
    switch (pMsg->wParam)
    {
    case 0x0D:
        CONTROL_SetFocusedEditBox(0);
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
        CONTROL_SetFocusedEditBox(0);
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
        CONTROL_SetFocusedEditBox(0);
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
    pAccountList->controlHeader.eType = D2WIN_ACCOUNTLIST;
    pAccountList->controlHeader.dwFlags |= gdwBitMasks[0];
    pAccountList->controlHeader.dwFlags |= gdwBitMasks[2];
    pAccountList->unk0x4C = a5;
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
    pAccountList->nFirstDrawnEntry = 0;
    pAccountList->controlHeader.pNext = 0;
    if (pFont)
    {
        pAccountList->eFont = pFont->eFont;
        pAccountList->unk0x54 = pFont->field_04;
    }
    else
    {
        pAccountList->eFont = 1;
        pAccountList->unk0x54 = 0;
    }
    CONTROL_AppendToList(&pAccountList->controlHeader);
    return pAccountList;
}

// 0x00507D70
int __stdcall PROGRESSBAR_SetProgress(D2WinProgressBarStrc* pProgressBar, float fProgress)
{
    D2_ASSERT(pProgressBar->controlHeader.eType == D2WIN_PROGRESSBAR, 0x3A);
    pProgressBar->fProgress = fProgress;
    return 1;
}

// 0x00507E50
D2WinProgressBarStrc* __fastcall PROGRESSBAR_Create(int nX, int nY, int nWidth, int nHeight)
{
    D2WinProgressBarStrc* pProgressBar = (D2WinProgressBarStrc*)FOG_Alloc(sizeof(D2WinProgressBarStrc), ".\\Src\\D2WinProgressBar.cpp", 0x1A, 0);
    memset(pProgressBar, 0, sizeof(D2WinProgressBarStrc));
    pProgressBar->controlHeader.eType = D2WIN_PROGRESSBAR;
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
    D2_ASSERT(pScrollBar->controlHeader.eType == D2WIN_SCROLLBAR, 0x1B0);
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
    pScrollBar->controlHeader.eType = D2WIN_SCROLLBAR;
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
    pScrollBar->nPageStep = 0;
    CONTROL_AppendToList(&pScrollBar->controlHeader);
    return pScrollBar;
}

#include "gen/data/Source/D2Win/Src/D2Comp.inc"
