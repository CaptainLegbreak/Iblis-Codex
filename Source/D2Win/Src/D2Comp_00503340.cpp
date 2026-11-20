#include "D2Win.h"
#include "D2Txt.h"
#include "D2Records.h"

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

struct D2CofDataStrc
{
    unsigned char nLayers;
    unsigned char nFramesPerDirection;
    unsigned char nDirections;
    unsigned char nVersion;
};

struct D2CofNodeStrc
{
    int nRefCount;
    unsigned int nMode;
    unsigned int nClass;
    unsigned int dwWeaponClass;
    unsigned int dwCofSize;
    D2CofDataStrc* pCofData;
    D2CofNodeStrc* pNext;
    D2CofNodeStrc* pPrev;
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

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
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
void __stdcall sub_00506000_InitCompItems(); // 0x00506000
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2CompItemStrc gaCompItems_0072E1E0[]; // 0x0072E1E0
extern int gnItems_0087D834; // 0x0087D834
extern D2CompItemStrc gaItems_0087D838[]; // 0x0087D838
extern int gaItemWeaponClass_0087E430[]; // 0x0087E430
extern D2CompositeUnitStrc* gpCompositeUnitList_0087E838; // 0x0087E838
extern unsigned int gdwNextFrameTick_0087E840; // 0x0087E840
extern D2CelFileStrc* ghSquelchCelFile_0087E844; // 0x0087E844
extern int gnSquelchCelFileFrameCount_0087E848; // 0x0087E848
extern int gnSquelchCelFileFrame_0087E84C; // 0x0087E84C
extern D2CelFileStrc* ghSelectedCelFile_0087E850; // 0x0087E850
extern int gnSelectedCelFileFrameCount_0087E854; // 0x0087E854
extern int gnSelectedCelFileFrame_0087E858; // 0x0087E858

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
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
__declspec(noinline) void __stdcall sub_00503FA0_AddHoverLine(const Unicode* wszText, D2HoverLineStrc* pLines, int* pCount, int* pMaxWidth, int* pTotalHeight);

typedef unsigned int size_t;


struct D2CompPairStrc
{
    unsigned int nKey;
    int nValue;
};


typedef char check_size_itemstxt[(sizeof(D2ItemsTxt) == 0x1A8) ? 1 : -1];
void* __stdcall sub_00504430_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount,
    int nRecordSize); // 0x00504430
void __fastcall sub_00504570_LoadItems(void* hArchive); // 0x00504570
extern int gaWClassTokens_0072EF30[]; // 0x0072EF30
extern D2CompPairStrc gaCompPairs_0072EF68[]; // 0x0072EF68
extern unsigned int gnCompPairs_0072EFD0; // 0x0072EFD0
extern int gnItemsTxtRecordCount_008426EC; // 0x008426EC
extern D2ItemsTxt* gpItemsTxt_008426F0; // 0x008426F0

static D2CofNodeStrc* gpCofNodeList_0087E83C; // 0x0087E83C

static __declspec(noinline) void sub_005031D0_CopyTokenPadded(char* pDst, const char* pSrc)
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

static __declspec(noinline) D2CofDataStrc* __stdcall sub_00503250_LoadCofFile(const char* szPath, unsigned int* pnSize)
{
    D2CofDataStrc* pCofData = (D2CofDataStrc*)sub_00517079_LoadFile(sub_004FAC80(), szPath, pnSize, ".\\Src\\D2Comp.cpp", 0x3EB);
    D2_ASSERT(pCofData, 0x3EC);
    D2_ASSERT(pCofData->nVersion == 20, 0x3F5);
    return pCofData;
}

// 0x00503340
static __declspec(noinline) D2CofNodeStrc* __stdcall sub_00503340_GetCofNode(unsigned int nClass, const char* szPath, unsigned int nMode, unsigned int dwWeaponClass)
{
    for (D2CofNodeStrc* pNode = gpCofNodeList_0087E83C; pNode; pNode = pNode->pNext)
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
    D2CofNodeStrc* pHead = gpCofNodeList_0087E83C;
    ++pNode->nRefCount;
    pNode->dwWeaponClass = dwWeaponClass;
    pNode->pNext = pHead;
    pNode->pPrev = 0;
    if (pHead)
    {
        pHead->pPrev = pNode;
    }
    gpCofNodeList_0087E83C = pNode;
    pNode->pCofData = sub_00503250_LoadCofFile(szPath, &pNode->dwCofSize);
    D2_ASSERT(pNode->pCofData, 0x446);
    return pNode;
}

static __declspec(noinline) void __stdcall sub_005034B0_BuildCofPath(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass, char* szPath)
{
    D2_ASSERT(nClass < 25, 0x488);
    D2_ASSERT(nMode < gnModeTokens_0072E0B4, 0x489);

    char szWeaponClass[4];
    char szUnit[4];
    char szMode[4];
    const unsigned int dwUnit = gdwUnitTokens_0072E050[nClass];
    const unsigned int dwMode = gdwModeTokens_0072E0B8[nMode];
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
    if (sub_004068E0(szPath, &hFile))
    {
        sub_004068F0(hFile);
    }
    else
    {
        szPath[0] = 0;
    }
}

static __declspec(noinline) D2CofInfoStrc* sub_005035F0_FindCofInfo(D2GfxInfoStrc* pGfxInfo, unsigned int nMode, unsigned int dwWeaponClass)
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

static __declspec(noinline) D2CofDataStrc* __stdcall sub_00503640_GetCofData(D2GfxInfoStrc* pGfxInfo, unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    char szPath[260];

    D2_ASSERT(pGfxInfo, 0x4CA);

    D2CofInfoStrc* pCofInfo = sub_005035F0_FindCofInfo(pGfxInfo, nMode, dwWeaponClass);
    if (!pCofInfo)
    {
        szPath[0] = 0;
        memset(&szPath[1], 0, sizeof(szPath) - 1);
        sub_005034B0_BuildCofPath(nClass, nMode, dwWeaponClass, szPath);
        if (!szPath[0])
        {
            return 0;
        }

        pCofInfo = (D2CofInfoStrc*)FOG_Alloc(sizeof(D2CofInfoStrc), ".\\Src\\D2Comp.cpp", 0x4D8, 0);
        D2_ASSERT(pCofInfo, 0x4D9);
        memset(pCofInfo, 0, sizeof(D2CofInfoStrc));

        D2CofNodeStrc* pCofNode = sub_00503340_GetCofNode(nClass, szPath, nMode, dwWeaponClass);
        D2_ASSERT(pCofNode, 0x4DC);
        pCofInfo->pCofNode = pCofNode;
        pCofInfo->pNext = pGfxInfo->pCofInfo;
        pGfxInfo->pCofInfo = pCofInfo;
    }

    D2CofDataStrc* pCofData = pCofInfo->pCofNode->pCofData;
    D2_ASSERT(pCofData, 0x4E2);
    return pCofData;
}

void __fastcall sub_00503740_InitGfxData(D2CompositeUnitStrc* pCompositeUnit, D2GfxDataStrc* pGfxData)
{
    pGfxData->nUnitIndex = pCompositeUnit->nUnitIndex;
    pGfxData->nMode = pCompositeUnit->nMode;
    const int nComponent = pGfxData->nComponent;
    pGfxData->dwComponentToken = gdwComponentTokens_0072E108[nComponent];
    pGfxData->dwWClassToken = gdwWClassTokens_0072E15C[pCompositeUnit->nWClassTokenIndex];
    pGfxData->dwUnitToken = gdwUnitTokens_0072E050[pCompositeUnit->nUnitIndex];
    pGfxData->dwArmorType = 0x2074696C;
    if (pCompositeUnit->dwArmorType[nComponent])
    {
        pGfxData->dwArmorType = pCompositeUnit->dwArmorType[nComponent];
    }

    D2GfxInfoStrc* pGfxInfo = pCompositeUnit->pGfxInfo;
    D2_ASSERT(pGfxInfo, 0x502);

    D2CofDataStrc* pCofData = sub_00503640_GetCofData(pGfxInfo, pCompositeUnit->nUnitIndex, pCompositeUnit->nMode, gdwWClassTokens_0072E15C[pCompositeUnit->nWClassTokenIndex]);
    D2_ASSERT(pCofData, 0x506);

    const unsigned char* pLayer = (const unsigned char*)pCofData + 0x1C;
    for (unsigned int i = 0; i < pCofData->nLayers; ++i)
    {
        D2_ASSERT(nComponent < 16, 0x50E);
        if (pLayer[0] == nComponent)
        {
            pGfxData->nUnitType = pGfxData->nUnitIndex >= 7;
            pGfxData->dwModeToken = gdwModeTokens_0072E0B8[pGfxData->nMode];
            D2_ASSERT(pGfxData->dwArmorType, 0x51F);
            unsigned int dwHitClass = 0;
            sub_005031D0_CopyTokenPadded((char*)&dwHitClass, (const char*)pLayer + 5);
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

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00503FA0
void __stdcall sub_00503FA0_AddHoverLine(const Unicode* wszText, D2HoverLineStrc* pLines, int* pCount, int* pMaxWidth, int* pTotalHeight)
{
    D2HoverLineStrc* pLine = &pLines[*pCount];
    D2_ASSERT(*pCount < 7, 0x738);

    sub_005267E0(pLine->wszText, wszText);
    D2Win_10131_GetTextDimensions(pLine->wszText, &pLine->nWidth, &pLine->nHeight);
    *pMaxWidth = *pMaxWidth > pLine->nWidth + 6 ? *pMaxWidth : pLine->nWidth + 6;
    *pTotalHeight += pLine->nHeight;
    ++*pCount;
}

// 0x00505A80
int __fastcall sub_00505A80_DrawCompositeUnitHover(D2CompositeUnitStrc* pCompositeUnit)
{
    D2_ASSERT(pCompositeUnit, 1864);

    Unicode wszText[256];
    if (!(pCompositeUnit->dwFlags & gdwBitMasks[3]))
    {
        return 0;
    }

    tagRECT rect;
    SetRect(&rect, pCompositeUnit->nX - 30, pCompositeUnit->nY - 80, pCompositeUnit->nX + 30, pCompositeUnit->nY + 20);
    if (!CONTROL_MouseInsideRect(&rect))
    {
        return 0;
    }

    int nX = pCompositeUnit->nX;
    int nYEnd = pCompositeUnit->nY - 80;
    int nWidth = 0;
    int nHeight = 0;
    D2HoverLineStrc lines[7];
    int nCount = 0;
    int nColor = 0;
    sub_00502EF0(1);

    if (pCompositeUnit->dwProductCode == 'D2XP')
    {
        sub_00526320_ToUnicode(wszText, "Expansion", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }

    const int nType = pCompositeUnit->nUnitIndex;
    if (nType == 19)
    {
        sub_00526320_ToUnicode(wszText, "Moderator", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
ShowLevel:
        {
            const int nLevel = pCompositeUnit->nCharLevel;
            if (nLevel > 0)
            {
                memset(wszText, 0, sizeof(wszText));
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(5017), nLevel);
                sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);

                if (pCompositeUnit->dwFlags & gdwBitMasks[5])
                {
                    sub_00503FA0_AddHoverLine(D2LANG_GetStringFromTblIndex(5016), lines, &nCount, &nWidth, &nHeight);
                }

                sub_00526320_ToUnicode(wszText, "Realm: ", 256);
                sub_00526700(wszText, pCompositeUnit->wszRealmName);
                sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
            }
        }
    }
    else if (nType == 20)
    {
        sub_00526320_ToUnicode(wszText, "Sysop", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
        nColor = 3;
    }
    else if (nType == 18)
    {
        sub_00526320_ToUnicode(wszText, "Blizzard Rep", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
        nColor = 3;
    }
    else if (nType == 23)
    {
        sub_00526320_ToUnicode(wszText, "Speaker", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else if (nType == 21)
    {
        sub_00526320_ToUnicode(wszText, "Referee", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else if (nType == 22)
    {
        sub_00526320_ToUnicode(wszText, "Chat", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else if (nType == 24)
    {
        sub_00526320_ToUnicode(wszText, "Open Character", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else
    {
        const unsigned int dwProductCode = pCompositeUnit->dwProductCode;
        if (dwProductCode == 'D2DV' || dwProductCode == 'D2XP' || dwProductCode == 'D2ST')
        {
            goto ShowLevel;
        }

        const char* szProduct;
        switch (dwProductCode)
        {
        case 'DRTL':
        case 'DTST':
            szProduct = "Diablo";
            break;
        case 'DSHR':
            szProduct = "Diablo Shareware";
            break;
        case 'SSHR':
            szProduct = "Starcraft Shareware";
            break;
        case 'STAR':
        case 'JSTR':
            szProduct = "Starcraft";
            break;
        case 'SEXP':
            szProduct = "Brood War";
            break;
        case 'W2BN':
            szProduct = "Warcraft II";
            break;
        case 'WAR3':
            szProduct = "Warcraft III";
            break;
        case 'W3XP':
            szProduct = "Frozen Throne";
            break;
        default:
            szProduct = "Unknown";
            break;
        }

        sub_00526320_ToUnicode(wszText, szProduct, 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }

    sub_00526320_ToUnicode(wszText, "Account Name: ", 256);
    sub_00526700(wszText, pCompositeUnit->wszAccountName);
    sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);

    const int nBoxHeight = nHeight + 6;
    int nLeft = nX - (nWidth >> 1);
    int nOffset = 0;
    if (nLeft < 0)
    {
        nOffset = -nLeft;
        nLeft = 0;
    }
    else if (nLeft + nWidth > 800)
    {
        nOffset = 800 - nLeft - nWidth;
        nLeft = 800 - nWidth;
    }

    const int nTop = nYEnd - nBoxHeight;
    D2GFX_DrawBox(nLeft, nTop, nLeft + nWidth, nYEnd, 0, 2);
    nX += nOffset;

    int nY = nTop + 3;
    D2_ASSERT(nCount <= 7, 2052);
    const int nValidStrings = nCount;
    for (int i = 0; i < nValidStrings; ++i)
    {
        nY += lines[i].nHeight;
        D2HoverLineStrc* pLine = &lines[i];
        int nLineColor = 0;
        if (!i)
        {
            nLineColor = nColor;
        }
        sub_00502320(pLine->wszText, nX - (pLine->nWidth >> 1), nY, nLineColor, 0);
    }

    return 1;
}

void* gpHitClassTxt_0087D81C; // 0x0087D81C

D2TxtLinkStrc* gpHitClassLinker_0087D820; // 0x0087D820

D2TxtLinkStrc* gpItemTypesLinker_0087D828; // 0x0087D828

void* gpItemTypesTxt_0087D82C; // 0x0087D82C

int gnItemTypesTxtRecordCount_0087D830; // 0x0087D830

D2CompItemStrc gaItems_0087D838[255]; // 0x0087D838

int gaItemWeaponClass_0087E430[254]; // 0x0087E430

int gbCompItemsInit_0087E85C; // 0x0087E85C

static __forceinline int sub_GetCompPairValue(unsigned int nKey)
{
    for (unsigned int i = 0; i < gnCompPairs_0072EFD0; ++i)
    {
        if (nKey == gaCompPairs_0072EF68[i].nKey)
        {
            return gaCompPairs_0072EF68[i].nValue;
        }
    }

    return 0;
}

// 0x00506000
void __stdcall sub_00506000_InitCompItems()
{
    if (gbCompItemsInit_0087E85C)
    {
        return;
    }

    gbCompItemsInit_0087E85C = 1;
    memset(gaItems_0087D838, 0, sizeof(gaItems_0087D838));

    D2BinFieldStrc aItemTypesFields[] =
    {
        { "code", 0xA, 0, 0x00, &gpItemTypesLinker_0087D828 },
        { "equiv1", 0xF, 0, 0x04, &gpItemTypesLinker_0087D828 },
        { "equiv2", 0xF, 0, 0x06, &gpItemTypesLinker_0087D828 },
        { "repair", 4, 0, 0x08, 0 },
        { "body", 4, 0, 0x09, 0 },
        { "shoots", 0xF, 0, 0x0C, &gpItemTypesLinker_0087D828 },
        { "quiver", 0xF, 0, 0x0E, &gpItemTypesLinker_0087D828 },
        { "throwable", 4, 0, 0x10, 0 },
        { "reload", 4, 0, 0x11, 0 },
        { "reequip", 4, 0, 0x12, 0 },
        { "autostack", 4, 0, 0x13, 0 },
        { "magic", 4, 0, 0x14, 0 },
        { "normal", 4, 0, 0x16, 0 },
        { "charm", 4, 0, 0x17, 0 },
        { "gem", 4, 0, 0x18, 0 },
        { "beltable", 4, 0, 0x19, 0 },
        { "costformula", 4, 0, 0x20, 0 },
        { "varinvgfx", 4, 0, 0x23, 0 },
        { "invgfx1", 1, 0x1F, 0x24, 0 },
        { "invgfx2", 1, 0x1F, 0x44, 0 },
        { "invgfx3", 1, 0x1F, 0x64, 0 },
        { "invgfx4", 1, 0x1F, 0x84, 0 },
        { "invgfx5", 1, 0x1F, 0xA4, 0 },
        { "end", 0, 0, 0, 0 },
    };

    gpItemTypesLinker_0087D828 = sub_006BD040(".\\Src\\D2Comp.cpp", 0xACB);
    gpItemTypesTxt_0087D82C = sub_00504430_CompileTxt(sub_004FAC80(), "itemtypes", aItemTypesFields,
        &gnItemTypesTxtRecordCount_0087D830, 0xE4);

    D2BinFieldStrc aHitClassFields[] =
    {
        { "code", 0xA, 0, 0, &gpHitClassLinker_0087D820 },
        { "end", 0, 0, 0, 0 },
    };

    gpHitClassLinker_0087D820 = sub_006BD040(".\\Src\\D2Comp.cpp", 0xAD7);
    gpHitClassTxt_0087D81C = sub_00504430_CompileTxt(sub_004FAC80(), "hitclass", aHitClassFields, 0, 4);

    sub_00504570_LoadItems(sub_004FAC80());

    gaItems_0087D838[1].dwCode = ' til';
    gaItems_0087D838[1].nItemType = 3;
    gaItems_0087D838[1].nWeaponClass = gaWClassTokens_0072EF30[0];
    gaItems_0087D838[2].dwCode = ' dem';
    gaItems_0087D838[2].nItemType = 3;
    gaItems_0087D838[2].nWeaponClass = gaWClassTokens_0072EF30[0];
    gaItems_0087D838[3].dwCode = ' yvh';
    gaItems_0087D838[3].nItemType = 3;
    gaItems_0087D838[3].nWeaponClass = gaWClassTokens_0072EF30[0];

    int nNext = 4;
    for (int i = 0; i < gnItemsTxtRecordCount_008426EC; ++i)
    {
        D2ItemsTxt* pRecord = &gpItemsTxt_008426F0[i];

        unsigned int dwCode;
        if (pRecord->dwAltCode2)
        {
            dwCode = pRecord->dwAltCode2;
        }
        else
        {
            dwCode = pRecord->dwCode;
        }

        int bArmor = 1;
        if (!(sub_00504A20_CheckItemType(pRecord->wType[0], 0x2D) || sub_00504A20_CheckItemType(pRecord->wType[0], 3)
            || sub_00504A20_CheckItemType(pRecord->wType[0], 0x33) || sub_00504A20_CheckItemType(pRecord->wType[0], 0x25))
            || sub_00504A20_CheckItemType(pRecord->wType[0], 0x4B))
        {
            bArmor = 0;
        }

        int j;
        for (j = 0; j < nNext; ++j)
        {
            if (gaItems_0087D838[j].dwCode == dwCode)
            {
                goto next;
            }
        }

        if (bArmor == 1)
        {
            int nSlot = nNext;
            while ((sub_00504A20_CheckItemType(gaCompItems_0072E1E0[nSlot].nItemType, 0x2D)
                       && sub_00504A20_CheckItemType(pRecord->wType[0], 0x2D))
                || (sub_00504A20_CheckItemType(gaCompItems_0072E1E0[nSlot].nItemType, 0x32)
                       && sub_00504A20_CheckItemType(pRecord->wType[0], 0x32))
                || gaItems_0087D838[nSlot].dwCode)
            {
                ++nSlot;
            }

            if (nSlot >= 0xFF)
            {
                nSlot = nNext;
            }

            gaItems_0087D838[nSlot].dwCode = dwCode;
            gaItems_0087D838[nSlot].nItemType = pRecord->wType[0];
            gaItems_0087D838[nSlot].nWeaponClass = gaWClassTokens_0072EF30[sub_GetCompPairValue(pRecord->dwWeapClass)];
            gaItemWeaponClass_0087E430[nSlot] = gaWClassTokens_0072EF30[sub_GetCompPairValue(pRecord->dwWeapClass2Hand)];

            if (nNext == nSlot)
            {
                ++nNext;
            }
        }
next:
        ;
    }

    gnItems_0087D834 = 0xFF;
}

#include "gen/data/Source/D2Win/Src/D2Comp_00503340.inc"
