#include "D2ItemTypes.h"
#include "D2Win.h"
#include "D2Win32Types.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2CmpTypes.h"
#include "D2CmpTypes.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define COF_PAD 0x20
#define TOKEN_CHAR(c) ((char)(c) == COF_PAD ? 0 : (char)(c))
struct D2CofDataStrc;
struct D2CofNodeStrc;
struct D2CofInfoStrc;
struct D2GfxInfoStrc;
struct D2CompositeUnitStrc;
struct D2CompItemStrc;
struct Unicode;
struct D2HoverLineStrc;
struct tagRECT;
struct D2BinFieldStrc;
struct D2CompPairStrc;
struct D2ItemsTxt;

struct D2GfxInfoStrc
{
    D2CofInfoStrc* pCofInfo;
};

struct D2GfxDataStrc
{
    int nFrame;
    unsigned char unk0x04;
    unsigned char nComponent;
    unsigned char unk0x06[2];
    int nUnitType;
    int nUnitIndex;
    unsigned int nMode;
    int unk0x14;
    unsigned int dwUnitToken;
    unsigned int dwComponentToken;
    unsigned int dwArmorType;
    unsigned int dwModeToken;
    unsigned int dwWClassToken;
    int unk0x2C[2];
    D2CelFileStrc* pCelFile;
    int nDrawFlag;
    D2CelStrc* pCel;
    int nDirection;
    unsigned int dwFlags;
};

struct D2CompositeUnitStrc
{
    unsigned int dwFlags;
    unsigned char nDirection;
    unsigned char nDirections;
    unsigned char unk0x06[2];
    int nFrame;
    int nFrameCount;
    int nAnimSpeed;
    int nX;
    int nY;
    unsigned int nUnitIndex;
    unsigned int nMode;
    unsigned int nWClassTokenIndex;
    unsigned char nComponentColors[16];
    unsigned int dwArmorType[16];
    int nItemTypes[16];
    D2GfxInfoStrc* pGfxInfo;
    D2CelFileStrc* pEmblemCellFile;
    unsigned char nEmblemColor1;
    unsigned char nEmblemColor2;
    unsigned char unk0xC2[2];
    D2CompositeUnitStrc* pNext;
    D2CompositeUnitStrc* pPrev;
    Unicode wszAccountName[64];
    Unicode wszCharName[64];
    Unicode wszGuildTag[16];
    Unicode wszRealmName[32];
    int nCharLevel;
    unsigned int dwProductCode;
};

struct D2CompItemStrc
{
    unsigned int dwCode;
    int nWeaponClass;
    int nItemType;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode); // 0x005042F0
void __stdcall D2COMP_InitCompItems(); // 0x00506000
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2CompItemStrc gaCompItems[]; // 0x0072E1E0
extern int gnItems; // 0x0087D834
extern D2CompItemStrc gaItems[]; // 0x0087D838
extern int gaItemWeaponClass[]; // 0x0087E430
extern D2CompositeUnitStrc* gpCompositeUnitList; // 0x0087E838
extern unsigned int gdwNextFrameTick; // 0x0087E840
extern D2CelFileStrc* ghSquelchCelFile; // 0x0087E844
extern int gnSquelchCelFileFrameCount; // 0x0087E848
extern int gnSquelchCelFileFrame; // 0x0087E84C
extern D2CelFileStrc* ghSelectedCelFile; // 0x0087E850
extern int gnSelectedCelFileFrameCount; // 0x0087E854
extern int gnSelectedCelFileFrame; // 0x0087E858

struct D2HoverLineStrc
{
    Unicode wszText[256];
    int nWidth;
    int nHeight;

    D2HoverLineStrc() {} // 0x00504020
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect); // 0x004F97B0
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
void __stdcall D2COMP_AddHoverTextLine(const Unicode* wszText, D2HoverLineStrc* pLines, int* pCount, int* pMaxWidth, int* pTotalHeight); // 0x00503FA0

typedef unsigned int size_t;

struct D2CompPairStrc
{
    unsigned int nKey;
    int nValue;
};

typedef char check_size_itemstxt[(sizeof(D2ItemsTxt) == 0x1A8) ? 1 : -1];
// build: symbol ?D2COMP_CompileTxt@* 0x00504430
void* __stdcall D2COMP_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount,
    int nRecordSize); // 0x00504430
void __fastcall D2COMP_LoadItems(void* hArchive); // 0x00504570
extern int gaWClassTokens[]; // 0x0072EF30
extern D2CompPairStrc gaCompPairs[]; // 0x0072EF68
extern unsigned int gnCompPairs; // 0x0072EFD0
extern int gnItemsTxtRecordCount_008426EC; // 0x008426EC
extern D2ItemsTxt* gpCompItemsTxt; // 0x008426F0

static D2CofNodeStrc* gpCofNodeList; // 0x0087E83C

// build: symbol ?D2COMP_CopyTokenPadded@* 0x005031D0
static void D2COMP_CopyTokenPadded(char* pDst, const char* pSrc)
{
    if (!pSrc[0])
    {
        pDst[0] = COF_PAD;
        pDst[1] = COF_PAD;
        pDst[2] = COF_PAD;
        pDst[3] = COF_PAD;
        return;
    }
    pDst[0] = pSrc[0];
    if (!pSrc[1])
    {
        pDst[1] = COF_PAD;
        pDst[2] = COF_PAD;
        pDst[3] = COF_PAD;
        return;
    }
    pDst[1] = pSrc[1];
    if (!pSrc[2])
    {
        pDst[2] = COF_PAD;
        pDst[3] = COF_PAD;
        return;
    }
    pDst[2] = pSrc[2];
    pDst[3] = COF_PAD;
}

// build: symbol ?D2COMP_LoadCofFile@* 0x00503250
static __declspec(noinline) D2CofDataStrc* __stdcall D2COMP_LoadCofFile(const char* szPath, unsigned int* pnSize)
{
    D2CofDataStrc* pCofData = (D2CofDataStrc*)sub_00517079_LoadFile(sub_004FAC80(), szPath, pnSize, ".\\Src\\D2Comp.cpp", 0x3EB);
    D2_ASSERT(pCofData, 0x3EC);
    D2_ASSERT(pCofData->nVersion == 20, 0x3F5);
    return pCofData;
}

// 0x00503340
static D2CofNodeStrc* __stdcall D2COMP_GetCofNode(unsigned int nClass, const char* szPath, unsigned int nMode, unsigned int dwWeaponClass)
{
    for (D2CofNodeStrc* pNode = gpCofNodeList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nClass == nClass && pNode->dwWeaponClass == dwWeaponClass)
        {
            ++pNode->nRefCount;
            return pNode;
        }
    }

    D2CofNodeStrc* pNode = (D2CofNodeStrc*)FOG_Alloc(sizeof(D2CofNodeStrc), ".\\Src\\D2Comp.cpp", 0x437, 0);
    memset(pNode, 0, sizeof(D2CofNodeStrc));
    pNode->nMode = nMode;
    pNode->nClass = nClass;
    D2CofNodeStrc* pHead = gpCofNodeList;
    ++pNode->nRefCount;
    pNode->dwWeaponClass = dwWeaponClass;
    pNode->pNext = pHead;
    pNode->pPrev = 0;
    if (pHead)
    {
        pHead->pPrev = pNode;
    }
    gpCofNodeList = pNode;
    pNode->pCofData = D2COMP_LoadCofFile(szPath, &pNode->dwCofSize);
    D2_ASSERT(pNode->pCofData, 0x446);
    return pNode;
}

// build: symbol ?D2COMP_BuildCofPath@* 0x005034B0
static void __stdcall D2COMP_BuildCofPath(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass, char* szPath)
{
    D2_ASSERT(nClass < 25, 0x488);
// build: symbol ?gnModeTokens@* 0x0072E0B4
    D2_ASSERT(nMode < gnModeTokens, 0x489);

    char szWeaponClass[4];
    char szUnit[4];
    char szMode[4];
// build: symbol ?gadwUnitTokens@* 0x0072E050
    const unsigned int dwUnit = gadwUnitTokens[nClass];
// build: symbol ?gadwModeTokens@* 0x0072E0B8
    const unsigned int dwMode = gadwModeTokens[nMode];
    const char* pWeaponClass = (const char*)&dwWeaponClass;
    szWeaponClass[0] = TOKEN_CHAR(pWeaponClass[0]);
    szWeaponClass[1] = TOKEN_CHAR(pWeaponClass[1]);
    szWeaponClass[2] = TOKEN_CHAR(pWeaponClass[2]);
    szWeaponClass[3] = 0;
    szUnit[0] = TOKEN_CHAR(dwUnit);
    szUnit[1] = TOKEN_CHAR(dwUnit >> 8);
    szUnit[2] = TOKEN_CHAR(dwUnit >> 16);
    szUnit[3] = 0;
    szMode[0] = TOKEN_CHAR(dwMode);
    szMode[1] = TOKEN_CHAR(dwMode >> 8);
    szMode[2] = TOKEN_CHAR(dwMode >> 16);
    szMode[3] = 0;

    const char* szDir = "DATA\\GLOBAL\\CHARS";
    if (nClass >= 7)
    {
        szDir = "DATA\\GLOBAL\\MONSTERS";
    }
    wsprintfA(szPath, "%s\\%s\\COF\\%s%s%s.COF", szDir, szUnit, szUnit, szMode, szWeaponClass);

    void* hFile;
// build: symbol ?FOG_FOpenFile@* 0x004068E0
    if (FOG_FOpenFile(szPath, &hFile))
    {
// build: symbol ?FOG_FCloseFile@* 0x004068F0
        FOG_FCloseFile(hFile);
    }
    else
    {
        szPath[0] = 0;
    }
}

// build: symbol ?D2COMP_FindCofInfo@* 0x005035F0
static D2CofInfoStrc* D2COMP_FindCofInfo(D2GfxInfoStrc* pGfxInfo, unsigned int nMode, unsigned int dwWeaponClass)
{
    D2_ASSERT(pGfxInfo, 0x4B0);
    for (D2CofInfoStrc* pCofInfo = pGfxInfo->pCofInfo; pCofInfo; pCofInfo = pCofInfo->pNext)
    {
        if (pCofInfo->pCofNode->nMode == nMode && pCofInfo->pCofNode->dwWeaponClass == dwWeaponClass)
        {
            return pCofInfo;
        }
    }
    return 0;
}

static D2CofDataStrc* __stdcall sub_00503640_GetCofData(D2GfxInfoStrc* pGfxInfo, unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    char szPath[260];

    D2_ASSERT(pGfxInfo, 0x4CA);

    D2CofInfoStrc* pCofInfo = D2COMP_FindCofInfo(pGfxInfo, nMode, dwWeaponClass);
    if (!pCofInfo)
    {
        szPath[0] = 0;
        memset(&szPath[1], 0, sizeof(szPath) - 1);
        D2COMP_BuildCofPath(nClass, nMode, dwWeaponClass, szPath);
        if (!szPath[0])
        {
            return 0;
        }

        pCofInfo = (D2CofInfoStrc*)FOG_Alloc(sizeof(D2CofInfoStrc), ".\\Src\\D2Comp.cpp", 0x4D8, 0);
        D2_ASSERT(pCofInfo, 0x4D9);
        memset(pCofInfo, 0, sizeof(D2CofInfoStrc));

        D2CofNodeStrc* pCofNode = D2COMP_GetCofNode(nClass, szPath, nMode, dwWeaponClass);
        D2_ASSERT(pCofNode, 0x4DC);
        pCofInfo->pCofNode = pCofNode;
        pCofInfo->pNext = pGfxInfo->pCofInfo;
        pGfxInfo->pCofInfo = pCofInfo;
    }

    D2CofDataStrc* pCofData = pCofInfo->pCofNode->pCofData;
    D2_ASSERT(pCofData, 0x4E2);
    return pCofData;
}

// build: symbol ?D2COMP_InitGfxData@* 0x00503740
void __fastcall D2COMP_InitGfxData(D2CompositeUnitStrc* pCompositeUnit, D2GfxDataStrc* pGfxData)
{
    pGfxData->nUnitIndex = pCompositeUnit->nUnitIndex;
    pGfxData->nMode = pCompositeUnit->nMode;
    const int nComponent = pGfxData->nComponent;
// build: symbol ?gadwComponentTokens@* 0x0072E108
    pGfxData->dwComponentToken = gadwComponentTokens[nComponent];
// build: symbol ?gadwWClassTokens@* 0x0072E15C
    pGfxData->dwWClassToken = gadwWClassTokens[pCompositeUnit->nWClassTokenIndex];
    pGfxData->dwUnitToken = gadwUnitTokens[pCompositeUnit->nUnitIndex];
    pGfxData->dwArmorType = 0x2074696C;
    if (pCompositeUnit->dwArmorType[nComponent])
    {
        pGfxData->dwArmorType = pCompositeUnit->dwArmorType[nComponent];
    }

    D2GfxInfoStrc* pGfxInfo = pCompositeUnit->pGfxInfo;
    D2_ASSERT(pGfxInfo, 0x502);

    D2CofDataStrc* pCofData = sub_00503640_GetCofData(pGfxInfo, pCompositeUnit->nUnitIndex, pCompositeUnit->nMode, gadwWClassTokens[pCompositeUnit->nWClassTokenIndex]);
    D2_ASSERT(pCofData, 0x506);

    const unsigned char* pLayer = (const unsigned char*)pCofData + 0x1C;
    for (unsigned int i = 0; i < pCofData->nLayers; ++i)
    {
        D2_ASSERT(nComponent < 16, 0x50E);
        if (pLayer[0] == nComponent)
        {
            pGfxData->nUnitType = pGfxData->nUnitIndex >= 7;
            pGfxData->dwModeToken = gadwModeTokens[pGfxData->nMode];
            D2_ASSERT(pGfxData->dwArmorType, 0x51F);
            unsigned int dwHitClass = 0;
            D2COMP_CopyTokenPadded((char*)&dwHitClass, (const char*)pLayer + 5);
            pGfxData->dwWClassToken = dwHitClass;
            break;
        }
        pLayer += 9;
    }

    D2_ASSERT(pGfxData->dwComponentToken, 0x52B);
    D2_ASSERT(pGfxData->dwUnitToken, 0x52C);
    D2_ASSERT(pGfxData->dwWClassToken, 0x52D);
    if (!pGfxData->dwArmorType)
    {
        pGfxData->dwArmorType = 0x20787878;
    }
    if (!pGfxData->dwModeToken)
    {
        pGfxData->dwModeToken = 0x20787878;
    }
}
