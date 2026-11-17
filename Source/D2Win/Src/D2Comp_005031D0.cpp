#include "D2Win.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define COF_PAD 0x20
#define TOKEN_CHAR(c) ((char)(c) == COF_PAD ? 0 : (char)(c))
#define REMAP_COMPONENT(pComponent, nFallback)                                                              \
    {                                                                                                       \
        const int nItems = gnItems_0087D834;                                                                \
        int nItem = 0;                                                                                      \
        for (; nItem < nItems; ++nItem)                                                                     \
        {                                                                                                   \
            if (gaItems_0087D838[nItem].dwCode == gaCompItems_0072E1E0[*(pComponent)].dwCode)               \
            {                                                                                               \
                *(pComponent) = (unsigned char)nItem;                                                       \
                break;                                                                                      \
            }                                                                                               \
        }                                                                                                   \
        if (nItem >= nItems)                                                                                \
        {                                                                                                   \
            *(pComponent) = (unsigned char)(nFallback);                                                     \
        }                                                                                                   \
    }
struct D2BinFieldStrc;
struct D2BinFileStrc;
struct D2CofDataStrc;
struct D2CofNodeStrc;
struct D2CofInfoStrc;
struct D2GfxInfoStrc;
struct D2CompositeUnitStrc;
struct D2CompItemStrc;
struct Unicode;
struct D2CompItemsTxt;

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
    Unicode():wChar(0) {}
};

struct D2CompositeUnitStrc
{
    union
    {
        unsigned int dwFlags;
        unsigned int flags;
    };
    unsigned char nDirection;
    unsigned char nDirections;
    unsigned char unk0x06[2];
    int nFrame;
    int nFrameCount;
    int nAnimSpeed;
    union
    {
        int nX;
        int x;
    };
    union
    {
        int nY;
        int y;
    };
    union
    {
        unsigned int nUnitIndex;
        int unitClass;
    };
    unsigned int nMode;
    unsigned int nWClassTokenIndex;
    unsigned char nComponentColors[16];
    unsigned int dwArmorType[16];
    int nItemTypes[16];
    D2GfxInfoStrc* pGfxInfo;
    D2CelFileStrc* pEmblemCellFile;
    union
    {
        unsigned char nEmblemColor1;
        unsigned char f_C0;
    };
    union
    {
        unsigned char nEmblemColor2;
        unsigned char unk0xC1;
    };
    unsigned char unk0xC2[2];
    D2CompositeUnitStrc* pNext;
    D2CompositeUnitStrc* pPrev;
    Unicode accountName[64];
    Unicode characterName[64];
    Unicode guildTag[50];
    unsigned int productCode;
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
int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, unsigned char* pPalette); // 0x004F6480
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode); // 0x005042F0
void __stdcall sub_00506000_InitCompItems(); // 0x00506000
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2CompItemStrc gaCompItems_0072E1E0[]; // 0x0072E1E0
extern D2CompItemStrc gaItems_0087D838[]; // 0x0087D838
extern int gaItemWeaponClass_0087E430[]; // 0x0087E430
extern D2CompositeUnitStrc* gpCompositeUnitList_0087E838; // 0x0087E838
extern D2CofNodeStrc* gpCofNodeList_0087E83C; // 0x0087E83C
extern unsigned int gdwNextFrameTick_0087E840; // 0x0087E840
extern D2CelFileStrc* ghSquelchCelFile_0087E844; // 0x0087E844
extern int gnSquelchCelFileFrameCount_0087E848; // 0x0087E848
extern int gnSquelchCelFileFrame_0087E84C; // 0x0087E84C
extern D2CelFileStrc* ghSelectedCelFile_0087E850; // 0x0087E850
extern int gnSelectedCelFileFrameCount_0087E854; // 0x0087E854
extern int gnSelectedCelFileFrame_0087E858; // 0x0087E858
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
extern "C" const char gszExcelDirectory_006D8ED4[]; // 0x006D8ED4
extern void* ghPentagramCellFile; // 0x0087E96C
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFile(const char* szFile, int nType); // 0x004FA9B0
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __stdcall sub_005043E0_LoadExcelFile(void* hArchive, const char* szName, const char* szExtension, unsigned int* pnFileSize); // 0x005043E0
void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile); // 0x006BCDA0
int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile); // 0x006BCDE0
D2BinFileStrc* __stdcall FOG_CreateBinFile(void* pDataBuffer, int nBufferSize); // 0x006BD640

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinkField;
};

void __stdcall FOG_10207(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize); // 0x006BD780
extern "C" const char szBinExtension_006DCC68[]; // 0x006DCC68
extern int gbD2WinBinMode_0072EF2C; // 0x0072EF2C

struct D2CompItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0x72];
    unsigned short wVersion;
    char unk0xF8[0xB0];
};
extern "C" const char szBinFieldEnd_006D9060[]; // 0x006D9060
extern "C" const char szItemsTableMisc_006DCC70[]; // 0x006DCC70
extern "C" const char szItemsTableArmor_006DCC78[]; // 0x006DCC78
extern "C" const char szItemsFieldTransform_006DCC80[]; // 0x006DCC80
extern "C" const char szItemsField1or2Handed_006DCC8C[]; // 0x006DCC8C
extern "C" const char szItemsField2HandedWClass_006DCC98[]; // 0x006DCC98
extern "C" const char szItemsFieldWClass_006DCCA8[]; // 0x006DCCA8
extern "C" const char szItemsFieldComponent_006DCCB0[]; // 0x006DCCB0
extern "C" const char szItemsFieldLevel_006DCCBC[]; // 0x006DCCBC
extern "C" const char szItemsFieldSpawnable_006DCCC4[]; // 0x006DCCC4
extern "C" const char szItemsFieldAlternateGfx_006DCCD0[]; // 0x006DCCD0
extern "C" const char szItemTypesFieldCode_006DCCE0[]; // 0x006DCCE0
extern "C" const char szItemsFieldType_006DCCE8[]; // 0x006DCCE8
extern "C" const char szItemsFieldVersion_006DCCF0[]; // 0x006DCCF0
extern "C" const char szItemsTableWeapons_006DCCF8[]; // 0x006DCCF8
extern D2TxtLinkStrc* gpItemTypesLinker_0087D828; // 0x0087D828
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void __stdcall sub_006BD230_AddLinkCode(D2TxtLinkStrc* pLinker, unsigned int dwCode); // 0x006BD230
void* __stdcall sub_00504430_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount, int nRecordSize); // 0x00504430
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile); // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
extern unsigned char gabItemPalettes_00842710[9][0x6900]; // 0x00842710
extern const char gszGuildPrefix[]; // 0x006DCE68
extern const char gszGuildSuffix[]; // 0x006DCE64
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
Unicode* __fastcall sub_005267E0(Unicode*,const Unicode*); // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode*,const Unicode*); // 0x00526700
int __fastcall sub_00526800(const Unicode*); // 0x00526800
Unicode* __fastcall sub_00526F20(Unicode*,const char*,int); // 0x00526F20
void __fastcall sub_00526320(Unicode*,const char*,int); // 0x00526320
int __fastcall sub_00502EF0(int); // 0x00502EF0
int __stdcall sub_00503EC0_TruncateText(Unicode*,int); // 0x00503EC0
void __fastcall sub_00502520(const Unicode*,int*,int*); // 0x00502520
void __fastcall sub_00502320(const Unicode*,int,int,int,int); // 0x00502320

int gnItems_0087D834; // 0x0087D834

// 0x005031D0
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

// 0x00503220
static __declspec(noinline) D2CofDataStrc* sub_00503220_CheckCofData(D2CofDataStrc* pCofData)
{
    D2_ASSERT(pCofData, 0x3DD);
    return pCofData;
}

// 0x00503250
static __declspec(noinline) D2CofDataStrc* __stdcall sub_00503250_LoadCofFile(const char* szPath, unsigned int* pnSize)
{
    D2CofDataStrc* pCofData = (D2CofDataStrc*)sub_00517079_LoadFile(sub_004FAC80(), szPath, pnSize, ".\\Src\\D2Comp.cpp", 0x3EB);
    D2_ASSERT(pCofData, 0x3EC);
    D2_ASSERT(pCofData->nVersion == 20, 0x3F5);
    return pCofData;
}

// 0x005032B0
static __declspec(noinline) unsigned char* __stdcall sub_005032B0_GetLayerOrder(int nDirection, int nFrame, D2CofDataStrc* pCofData)
{
    D2_ASSERT(pCofData, 0x400);
    const int nFrames = pCofData->nFramesPerDirection;
    unsigned char* pOrder = (unsigned char*)pCofData + 0x1C + nFrames + pCofData->nLayers * (nFrames * nDirection + nFrame + 9);
    D2_ASSERT(pOrder, 0x408);
    return pOrder;
}

// build: context sub_00503340_GetCofNode
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
    pNode->nRefCount = 0;
    pNode->dwWeaponClass = 0;
    pNode->dwCofSize = 0;
    pNode->pCofData = 0;
    pNode->pNext = 0;
    pNode->pPrev = 0;
    ++pNode->nRefCount;
    pNode->nMode = nMode;
    pNode->nClass = nClass;
    pNode->dwWeaponClass = dwWeaponClass;
    pNode->pNext = gpCofNodeList_0087E83C;
    pNode->pPrev = 0;
    if (gpCofNodeList_0087E83C)
    {
        gpCofNodeList_0087E83C->pPrev = pNode;
    }
    gpCofNodeList_0087E83C = pNode;
    pNode->pCofData = sub_00503250_LoadCofFile(szPath, &pNode->dwCofSize);
    D2_ASSERT(pNode->pCofData, 0x446);
    return pNode;
}

// 0x005034B0
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

// 0x005035F0
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

// 0x00503740
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

// 0x005038A0
static __declspec(noinline) void __stdcall sub_005038A0_SetupGfxData(D2CompositeUnitStrc* pCompositeUnit, unsigned char nComponent, int nFrame, int nDirection, D2GfxDataStrc* pGfxData, D2CelFileStrc* pCelFile)
{
    pGfxData->pCelFile = pCelFile;
    pGfxData->nDirection = nDirection;
    pGfxData->nFrame = nFrame;
    pGfxData->nComponent = nComponent;
    sub_00503740_InitGfxData(pCompositeUnit, pGfxData);
    pGfxData->dwFlags |= 2;
}

// 0x00503920
static __declspec(noinline) unsigned char __stdcall sub_00503920_DirectionSlot(unsigned int nDirections, unsigned char nDirection)
{
    D2_ASSERT(nDirection < 64, 0x576);
    const unsigned char nIndex = gaDirectionIndex_006DCA60[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
    D2_ASSERT(nIndex <= 64, 0x578);
    return nIndex;
}

// 0x00503970
static __declspec(noinline) int __stdcall sub_00503970_CountLayerCels(D2CofDataStrc* pCofData, const unsigned char* pLayerOrder, int* pMaxHeight, unsigned char nDirection, int nFrame, D2CompositeUnitStrc* pCompositeUnit)
{
    D2_ASSERT(pCompositeUnit, 0x587);
    int nCount = 0;
    for (int i = 0; i < pCofData->nLayers; ++i)
    {
        const int nComponent = pLayerOrder[i];
        D2_ASSERT(nComponent < 16, 0x58E);

        D2GfxDataStrc tGfxData;
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.pCelFile = 0;
        tGfxData.nDirection = nDirection;
        tGfxData.nFrame = nFrame;
        tGfxData.nComponent = nComponent;
        sub_00503740_InitGfxData(pCompositeUnit, &tGfxData);
        tGfxData.dwFlags |= 2;

        if (sub_006001F0(&tGfxData, 0, 1) && tGfxData.pCel)
        {
            const int nHeight = sub_00601950(tGfxData.pCel) + pCompositeUnit->nX;
            if (nHeight > *pMaxHeight)
            {
                *pMaxHeight = nHeight;
            }
            ++nCount;
        }
    }
    return nCount;
}

// 0x00503A50
void __fastcall sub_00503A50_DrawCompositeShadow(D2CompositeUnitStrc* pCompositeUnit)
{
    D2_ASSERT(pCompositeUnit, 0x5B3);

    if (!(pCompositeUnit->dwFlags & gdwBitMasks[0]) || !(pCompositeUnit->dwFlags & gdwBitMasks[2]))
    {
        return;
    }

    const int nX = pCompositeUnit->nX - 2;
    const int nY = pCompositeUnit->nY;
    D2_ASSERT(pCompositeUnit->pGfxInfo, 0x5C3);

    D2CofInfoStrc* pCofInfo = sub_005035F0_FindCofInfo(pCompositeUnit->pGfxInfo, pCompositeUnit->nMode, gdwWClassTokens_0072E15C[pCompositeUnit->nWClassTokenIndex]);
    if (!pCofInfo)
    {
        return;
    }

    D2CofDataStrc* pCofData = pCofInfo->pCofNode->pCofData;
    D2_ASSERT(pCofData, 0x5CB);
    D2CofDataStrc* pHeader = sub_00503220_CheckCofData(pCofData);
    const int nFrame = pCompositeUnit->nFrame >> 8;
    const unsigned char* pLayerOrder = sub_005032B0_GetLayerOrder(pCompositeUnit->nDirection, nFrame, pCofData);
    D2_ASSERT(pLayerOrder, 0x5D0);

    int nMaxHeight = 0;
    if (sub_00503970_CountLayerCels(pHeader, pLayerOrder, &nMaxHeight, pCompositeUnit->nDirection, nFrame, pCompositeUnit) <= 0)
    {
        return;
    }

    for (unsigned int i = 0; i < pHeader->nLayers; ++i)
    {
        const int nComponent = pLayerOrder[i];
        D2_ASSERT(nComponent < 16, 0x5DA);

        D2GfxDataStrc tGfxData;
        memset(&tGfxData, 0, sizeof(tGfxData));
        sub_005038A0_SetupGfxData(pCompositeUnit, nComponent, nFrame, pCompositeUnit->nDirection, &tGfxData, 0);
        sub_004F6540(&tGfxData, nX, nY);
    }
}

int __fastcall sub_00503BA0_DrawCompositeUnit(D2CompositeUnitStrc* pCompositeUnit, int nGamma)
{
    D2_ASSERT(pCompositeUnit, 0x5F3);

    if (!(pCompositeUnit->dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }

    D2GfxDataStrc tGfxData;
    if (pCompositeUnit->dwFlags & gdwBitMasks[10])
    {
        D2CelFileStrc* pCelFile = ghSelectedCelFile_0087E850;
        D2_ASSERT(pCelFile, 0x5FE);
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.nFrame = gnSelectedCelFileFrame_0087E858;
        tGfxData.pCelFile = pCelFile;
        tGfxData.nDirection = 0;
        sub_004F6480(&tGfxData, pCompositeUnit->nX + 5, pCompositeUnit->nY - 5, -1, 3, 0);
    }

    D2CelFileStrc* pEmblemCellFile = pCompositeUnit->pEmblemCellFile;
    if (pEmblemCellFile)
    {
        unsigned char aPalette[256];
        aPalette[1] = pCompositeUnit->nEmblemColor1;
        aPalette[2] = pCompositeUnit->nEmblemColor2;
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.pCelFile = pEmblemCellFile;
        tGfxData.nDirection = 0;
        tGfxData.nFrame = 0;
        tGfxData.nDrawFlag = 1;
        sub_004F6480(&tGfxData, pCompositeUnit->nX - 0x14, pCompositeUnit->nY - 0x3C, -1, 5, aPalette);
    }

    D2_ASSERT(pCompositeUnit->pGfxInfo, 0x622);
    D2CofInfoStrc* pCofInfo = sub_005035F0_FindCofInfo(pCompositeUnit->pGfxInfo, pCompositeUnit->nMode, gdwWClassTokens_0072E15C[pCompositeUnit->nWClassTokenIndex]);
    if (!pCofInfo)
    {
        return 0;
    }

    D2CofDataStrc* pCofData = pCofInfo->pCofNode->pCofData;
    D2_ASSERT(pCofData, 0x62B);
    D2CofDataStrc* pHeader = sub_00503220_CheckCofData(pCofData);
    const int nFrame = pCompositeUnit->nFrame >> 8;
    const unsigned char* pLayerOrder = sub_005032B0_GetLayerOrder(pCompositeUnit->nDirection, nFrame, pCofData);
    D2_ASSERT(pLayerOrder, 0x630);

    int nDrawMode = 5;
    if ((pCompositeUnit->dwFlags & gdwBitMasks[5]) && (pCompositeUnit->dwFlags & gdwBitMasks[4]) || (pCompositeUnit->dwFlags & gdwBitMasks[13]))
    {
        nDrawMode = 1;
    }

    for (int i = 0; i < pHeader->nLayers; ++i)
    {
        const int nComponent = pLayerOrder[i];
        memset(&tGfxData, 0, sizeof(tGfxData));
        const unsigned char nDirection = sub_00503920_DirectionSlot(pCompositeUnit->nDirections, pCompositeUnit->nDirection);
        tGfxData.pCelFile = 0;
        tGfxData.nDirection = nDirection;
        tGfxData.nFrame = nFrame;
        tGfxData.nComponent = nComponent;
        sub_00503740_InitGfxData(pCompositeUnit, &tGfxData);
        tGfxData.dwFlags |= 2;

        const int nColor = pCompositeUnit->nComponentColors[nComponent];
        unsigned char* pPalette = 0;
        if (nColor != 0xFF)
        {
            pPalette = sub_005038D0_GetComponentPalette(nColor);
        }
        sub_004F6480(&tGfxData, pCompositeUnit->nX, pCompositeUnit->nY, nGamma, nDrawMode, pPalette);
    }

    pCompositeUnit->nFrame += pCompositeUnit->nAnimSpeed;
    if ((pCompositeUnit->nFrame >> 8) >= pCompositeUnit->nFrameCount - 1)
    {
        pCompositeUnit->nFrame = 0;
    }

    const unsigned int dwTickCount = GetTickCount();
    if (dwTickCount > gdwNextFrameTick_0087E840)
    {
        gdwNextFrameTick_0087E840 = dwTickCount + 0x42;
        ++gnSquelchCelFileFrame_0087E84C;
        if (gnSquelchCelFileFrame_0087E84C >= gnSquelchCelFileFrameCount_0087E848)
        {
            gnSquelchCelFileFrame_0087E84C = 0;
        }
        ++gnSelectedCelFileFrame_0087E858;
        if (gnSelectedCelFileFrame_0087E858 >= gnSelectedCelFileFrameCount_0087E854)
        {
            gnSelectedCelFileFrame_0087E858 = 0;
        }
    }

    if (pCompositeUnit->dwFlags & gdwBitMasks[9])
    {
        D2CelFileStrc* pCelFile = ghSquelchCelFile_0087E844;
        D2_ASSERT(pCelFile, 0x671);
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.nFrame = gnSquelchCelFileFrame_0087E84C;
        tGfxData.pCelFile = pCelFile;
        tGfxData.nDirection = 0;
        sub_004F6480(&tGfxData, pCompositeUnit->nX, pCompositeUnit->nY + 10, -1, 3, 0);
    }

    return 1;
}

// 0x00504040
static __declspec(noinline) int sub_00504040_LoadUnitCof(D2CompositeUnitStrc* pCompositeUnit)
{
    D2_ASSERT(pCompositeUnit, 0x81A);

    if (pCompositeUnit->nUnitIndex >= gnUnitTokens_0072E04C || pCompositeUnit->nMode >= gnModeTokens_0072E0B4 || pCompositeUnit->nWClassTokenIndex >= gnWClassTokens_0072E198)
    {
        pCompositeUnit->nUnitIndex = 7;
        pCompositeUnit->nMode = 5;
        pCompositeUnit->nWClassTokenIndex = 1;
    }

    D2GfxInfoStrc* pGfxInfo = pCompositeUnit->pGfxInfo;
    D2_ASSERT(pGfxInfo, 0x827);

    if (!sub_00503640_GetCofData(pGfxInfo, pCompositeUnit->nUnitIndex, pCompositeUnit->nMode, gdwWClassTokens_0072E15C[pCompositeUnit->nWClassTokenIndex]))
    {
        pCompositeUnit->nUnitIndex = 7;
        pCompositeUnit->nMode = 5;
        pCompositeUnit->nWClassTokenIndex = 1;
        D2_ASSERT(sub_00503640_GetCofData(pGfxInfo, 7, 5, gdwWClassTokens_0072E15C[1]), 0x836);
    }

    return 1;
}

// build: context sub_00504AF0_GetWeaponClass
static __declspec(noinline) int __stdcall sub_00504AF0_GetWeaponClass(unsigned int nUnitIndex, const unsigned char* pComponents)
{
    int nRight;
    int nLeft;
    int bTwoWeapons;
    if (pComponents[5] == 0xFF || pComponents[6] == 0xFF)
    {
        bTwoWeapons = 0;
    }
    else
    {
        bTwoWeapons = 1;
    }

    nRight = 0;
    if (pComponents[5] != 0xFF)
    {
        const int nItem = pComponents[5];
        if (bTwoWeapons)
        {
            nRight = gaItemWeaponClass_0087E430[nItem];
        }
        else
        {
            nRight = gaItems_0087D838[nItem].nWeaponClass;
            if (pComponents[6] == 0xFF && pComponents[7] == 0xFF && gaItemWeaponClass_0087E430[pComponents[5]] != gaItems_0087D838[pComponents[5]].nWeaponClass)
            {
                nRight = gaItemWeaponClass_0087E430[nItem];
            }
        }

        const int nItemType = gaItems_0087D838[nItem].nItemType;
        if ((nRight == 13 || nRight == 14) && nUnitIndex != 6 || sub_00504A20_CheckItemType(nItemType, 0x32))
        {
            nRight = gaCompItems_0072E1E0[pComponents[5]].nWeaponClass;
        }
    }

    nLeft = 0;
    if (pComponents[6] != 0xFF)
    {
        const int nItem = pComponents[6];
        nLeft = bTwoWeapons ? gaItemWeaponClass_0087E430[nItem] : gaItems_0087D838[nItem].nWeaponClass;
        const int nItemType = gaItems_0087D838[nItem].nItemType;
        if ((nLeft == 13 || nLeft == 14) && nUnitIndex != 6 || sub_00504A20_CheckItemType(nItemType, 0x32))
        {
            nLeft = gaCompItems_0072E1E0[pComponents[6]].nWeaponClass;
        }
    }

    if ((nRight == 13 || nRight == 14) && nUnitIndex != 6)
    {
        nRight = 0;
    }
    if ((nLeft == 13 || nLeft == 14) && nUnitIndex != 6)
    {
        nLeft = 0;
    }

    if (!nRight)
    {
        if (!nLeft)
        {
            return 1;
        }
        return nLeft;
    }

    if (nRight == nLeft && (nRight == 6 || nRight == 7))
    {
        return nRight;
    }
    if (nRight == 8)
    {
        return 8;
    }
    if (!nLeft)
    {
        return nRight;
    }

    if (nRight == 4)
    {
        if (nLeft == 4)
        {
            return 11;
        }
        if (nLeft == 2)
        {
            return 9;
        }
    }
    else
    {
        if (nRight == 2)
        {
            if (nLeft == 4)
            {
                return 12;
            }
            goto LEFT_CHECK;
        }
        if (nRight == 5 && nLeft == 2)
        {
            return 11;
        }
    }

    if (nLeft == 4)
    {
        if (nRight != 2)
        {
            goto RIGHT_CHECK;
        }
        return 11;
    }

LEFT_CHECK:
    if (nLeft == 5)
    {
        if (nRight == 2)
        {
            return 11;
        }
    }
    else if (nRight == 2)
    {
        if (nLeft == 2)
        {
            return 10;
        }
        return 0;
    }

RIGHT_CHECK:
    if (nRight == 5)
    {
        if (nLeft == 4 || nLeft == 5)
        {
            return 11;
        }
    }
    else if (nRight != 4)
    {
        if (nRight == 13)
        {
            if (nLeft != 13)
            {
                return 0;
            }
        }
        else
        {
            if (nRight != 14)
            {
                if (nRight == 1 && nLeft == 1)
                {
                    return 1;
                }
                return 0;
            }
            if (nLeft != 14)
            {
                return 0;
            }
        }
        return 13;
    }
    else if (nLeft == 5)
    {
        return 11;
    }
    return 0;
}

// 0x00504D60
static __declspec(noinline) void sub_00504D60_FixComponent(int nComponent, unsigned char* pComponent)
{
    if ((nComponent == 1 || nComponent == 2 || nComponent == 3 || nComponent == 4) && *pComponent > 3)
    {
        if (sub_00504A20_CheckItemType(gaCompItems_0072E1E0[*pComponent].nItemType, 3))
        {
            REMAP_COMPONENT(pComponent, *pComponent % 3 + 1);
        }
        if (sub_00504A20_CheckItemType(gaCompItems_0072E1E0[*pComponent].nItemType, 0x10))
        {
            REMAP_COMPONENT(pComponent, *pComponent % 3 + 1);
        }
        if (sub_00504A20_CheckItemType(gaCompItems_0072E1E0[*pComponent].nItemType, 0xF))
        {
            REMAP_COMPONENT(pComponent, *pComponent % 3 + 1);
        }
        if (sub_00504A20_CheckItemType(gaCompItems_0072E1E0[*pComponent].nItemType, 0x33))
        {
            REMAP_COMPONENT(pComponent, *pComponent % 3 + 1);
        }
        else
        {
            *pComponent = *pComponent % 3 + 1;
        }
    }

    if (!nComponent && !sub_00504A20_CheckItemType(gaItems_0087D838[*pComponent].nItemType, 0x25))
    {
        if (sub_00504A20_CheckItemType(gaCompItems_0072E1E0[*pComponent].nItemType, 0x25))
        {
            REMAP_COMPONENT(pComponent, 1);
        }
        else
        {
            *pComponent = 1;
        }
    }
}

// build: context sub_00504F80_InitCompositeUnit
void __stdcall sub_00504F80_InitCompositeUnit(D2CompositeUnitStrc* pCompositeUnit, unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors)
{
    D2_ASSERT(pCompositeUnit, 0xCDD);

    D2GfxInfoStrc* pGfxInfo = (D2GfxInfoStrc*)FOG_Alloc(sizeof(D2GfxInfoStrc), ".\\Src\\D2Comp.cpp", 0x866, 0);
    D2_ASSERT(pGfxInfo, 0x867);
    pGfxInfo->pCofInfo = 0;
    pCompositeUnit->pGfxInfo = pGfxInfo;
    pCompositeUnit->nUnitIndex = nUnitIndex;
    if (nUnitIndex < 7)
    {
        pCompositeUnit->nWClassTokenIndex = sub_00504AF0_GetWeaponClass(nUnitIndex, pComponents);
        if (!pCompositeUnit->nWClassTokenIndex)
        {
            return;
        }
    }
    else
    {
        pCompositeUnit->nWClassTokenIndex = 1;
    }

    pCompositeUnit->nMode = nMode;
    pCompositeUnit->dwFlags |= gdwBitMasks[0];
    pCompositeUnit->dwFlags |= gdwBitMasks[1];
    pCompositeUnit->dwFlags |= gdwBitMasks[2];

    for (unsigned int i = 0; i < 16; ++i)
    {
        pCompositeUnit->nItemTypes[i] = 1;
        if (*pComponents > 0 && *pComponents < 0xFF)
        {
            sub_00504D60_FixComponent(i, pComponents);
            pCompositeUnit->dwArmorType[i] = gaItems_0087D838[*pComponents].dwCode;
            pCompositeUnit->nItemTypes[i] = gaItems_0087D838[*pComponents].nItemType;
        }
        else
        {
            pCompositeUnit->dwArmorType[i] = 0;
        }
        ++pComponents;
    }

    for (int i = 0; i < 16; ++i)
    {
        const unsigned char nColor = pComponentColors[i];
        pCompositeUnit->nComponentColors[i] = nColor;
        if (nColor != 0xFF)
        {
            pCompositeUnit->nComponentColors[i] = nColor - 1;
        }
    }

    if (sub_00504040_LoadUnitCof(pCompositeUnit))
    {
        D2Win_10143(pCompositeUnit, nMode);
    }
}

D2CompositeUnitStrc* __stdcall sub_005066C0_CreateCompositeUnit(unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors)
{
    unsigned char* pComponent = pComponents;
    D2CompositeUnitStrc* pCompositeUnit = (D2CompositeUnitStrc*)FOG_Alloc(sizeof(D2CompositeUnitStrc), ".\\Src\\D2Comp.cpp", 0xC70, 0);
    D2_ASSERT(pCompositeUnit, 0xC71);
    memset(pCompositeUnit, 0, sizeof(D2CompositeUnitStrc));

    D2GfxInfoStrc* pGfxInfo = (D2GfxInfoStrc*)FOG_Alloc(sizeof(D2GfxInfoStrc), ".\\Src\\D2Comp.cpp", 0x866, 0);
    D2_ASSERT(pGfxInfo, 0x867);
    pGfxInfo->pCofInfo = 0;
    pCompositeUnit->pGfxInfo = pGfxInfo;
    sub_00506000_InitCompItems();
    pCompositeUnit->nUnitIndex = nUnitIndex;
    if (nUnitIndex < 7)
    {
        pCompositeUnit->nWClassTokenIndex = sub_00504AF0_GetWeaponClass(nUnitIndex, pComponent);
        if (!pCompositeUnit->nWClassTokenIndex)
        {
            return 0;
        }
    }
    else
    {
        pCompositeUnit->nWClassTokenIndex = 1;
    }

    pCompositeUnit->nMode = nMode;
    pCompositeUnit->dwFlags |= gdwBitMasks[0];
    pCompositeUnit->dwFlags |= gdwBitMasks[1];
    pCompositeUnit->dwFlags |= gdwBitMasks[2];

    unsigned int i = 0;
    do
    {
        pCompositeUnit->nItemTypes[i] = 1;
        if (*pComponent > 0 && *pComponent < gnItems_0087D834 && *pComponent != 0xFF)
        {
            sub_00504D60_FixComponent(i, pComponent);
            pCompositeUnit->dwArmorType[i] = gaItems_0087D838[*pComponent].dwCode;
            pCompositeUnit->nItemTypes[i] = gaItems_0087D838[*pComponent].nItemType;
        }
        else
        {
            pCompositeUnit->dwArmorType[i] = 0;
        }
        ++pComponent;
        ++i;
    }
    while (i < 16);

    for (int i = 0; i < 16; ++i)
    {
        const unsigned char nColor = pComponentColors[i];
        pCompositeUnit->nComponentColors[i] = nColor;
        if (nColor != 0xFF)
        {
            pCompositeUnit->nComponentColors[i] = nColor - 1;
        }
    }

    if (sub_00504040_LoadUnitCof(pCompositeUnit) && !D2Win_10143(pCompositeUnit, nMode))
    {
        return 0;
    }

    pCompositeUnit->pPrev = 0;
    pCompositeUnit->pNext = gpCompositeUnitList_0087E838;
    if (gpCompositeUnitList_0087E838)
    {
        gpCompositeUnitList_0087E838->pPrev = pCompositeUnit;
    }
    gpCompositeUnitList_0087E838 = pCompositeUnit;
    return pCompositeUnit;
}

#include "gen/data/Source/D2Win/Src/D2Comp_005031D0.inc"

// 0x00503EC0
int __stdcall sub_00503EC0_TruncateText(Unicode* wszText, int nMaxWidth)
{
    char szText[300];
    int nCount = 0;
    sub_00526F70(szText, wszText, 300);
    const int nLength = strlen(szText);
    int bTruncated = 0;
    while (nCount < nLength)
    {
        if (D2Win_10122(wszText, nCount + 1) >= nMaxWidth)
        {
            bTruncated = 1;
            break;
        }

        ++nCount;
    }

    szText[nCount] = 0;
    if (bTruncated)
    {
        strcat(szText, "...");
    }

    sub_00526F20_ToUnicode(wszText, szText, 299);
    return nCount;
}

unsigned char gabEmblemColor1_0087D810[12]; // 0x0087D810

unsigned char gabEmblemColor2_0087E82C[12]; // 0x0087E82C

// 0x005043E0
void* __stdcall sub_005043E0_LoadExcelFile(void* hArchive, const char* szName, const char* szExtension, unsigned int* pnFileSize)
{
    char szFilename[260];
    wsprintfA(szFilename, "%s\\%s%s", gszExcelDirectory_006D8ED4, szName, szExtension);
    return sub_00517079_LoadFile(hArchive, szFilename, pnFileSize, ".\\Src\\D2Comp.cpp", 0x958);
}

// 0x005053A0
void __stdcall D2Win_10158(D2CompositeUnitStrc* pCompositeUnit, unsigned char a2, unsigned char a3, unsigned char a4)
{
    D2_ASSERT(pCompositeUnit, 0xDB0);

    if (a2 < 1u || a2 > 32u)
    {
        return;
    }

    char szFile[512];
    wsprintfA(szFile, "%s\\ui\\emblems\\icon%02dc", szDataGlobal_006D4118, a2 - 1);
    pCompositeUnit->pEmblemCellFile = ARCHIVE_LoadCellFile(szFile, 0);

    if (a3 >= 1u && a3 <= 10u)
    {
        pCompositeUnit->f_C0 = gabEmblemColor1_0087D810[a3 - 1];
    }
    else
    {
        pCompositeUnit->f_C0 = 0;
    }

    if (a4 >= 1u && a4 <= 10u)
    {
        pCompositeUnit->unk0xC1 = gabEmblemColor2_0087E82C[a4 - 1];
    }
    else
    {
        pCompositeUnit->unk0xC1 = 0;
    }
}

// 0x005070D0
void __stdcall LIST_LoadPentspinCellfile()
{
    D2_ASSERT(ghPentagramCellFile == 0, 0x103);

    char szFile[260];
    wsprintfA(szFile, "%s\\UI\\CURSOR\\Pentspin", szDataGlobal_006D4118);
    ghPentagramCellFile = ARCHIVE_LoadCellFile(szFile, 0);
}

// 0x00504430
void* __stdcall sub_00504430_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount, int nRecordSize)
{
    unsigned int nFileSize = 0;
    void* pFileData;
    if (gbD2WinBinMode_0072EF2C)
    {
        char szFilename[260];
        wsprintfA(szFilename, "%s\\%s%s", gszExcelDirectory_006D8ED4, szName, szBinExtension_006DCC68);
        pFileData = sub_00517079_LoadFile(hArchive, szFilename, &nFileSize, ".\\Src\\D2Comp.cpp", 0x958);
    }
    else if (!_stricmp(szName, "leveldefs"))
    {
        pFileData = sub_005043E0_LoadExcelFile(hArchive, "levels", ".txt", &nFileSize);
    }
    else
    {
        pFileData = sub_005043E0_LoadExcelFile(hArchive, szName, ".txt", &nFileSize);
    }

    D2_ASSERT(pFileData, 0x9E3);

    int nRecordCount;
    void* pBinData;
    if (gbD2WinBinMode_0072EF2C)
    {
        nRecordCount = *(int*)pFileData;
        pBinData = (char*)pFileData + 4;
    }
    else
    {
        D2BinFileStrc* pBinFile = FOG_CreateBinFile(pFileData, nFileSize);
        nRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
        const int nSize = nRecordCount * nRecordSize;
        pBinData = FOG_AllocPool(0, nSize, ".\\Src\\D2Comp.cpp", 0x9FA, 0);
        memset(pBinData, 0, nSize);
        FOG_10207(pBinFile, pBinField, pBinData, nRecordCount, nRecordSize);
        FOG_FreeBinFile(pBinFile);
    }

    if (pRecordCount)
    {
        *pRecordCount = nRecordCount;
    }

    return pBinData;
}

int gnItemsTotalCount_008426EC; // 0x008426EC

D2CompItemsTxt* gpItemsTxt_008426F0; // 0x008426F0

D2CompItemsTxt* gpWeaponsTxt_008426F4; // 0x008426F4

int gnWeaponsTxtRecordCount_008426F8; // 0x008426F8

D2CompItemsTxt* gpArmorTxt_008426FC; // 0x008426FC

int gnArmorTxtRecordCount_00842700; // 0x00842700

D2CompItemsTxt* gpMiscTxt_00842704; // 0x00842704

int gnMiscTxtRecordCount_00842708; // 0x00842708

unsigned short* gpItemsVersion0Index_0084270C; // 0x0084270C

D2TxtLinkStrc* gpItemsLinker_0087D824; // 0x0087D824

// 0x00504570
void __fastcall sub_00504570_LoadItems(void* hArchive)
{
    D2BinFieldStrc aItemsFields[] =
    {
        { szItemsFieldVersion_006DCCF0, 3, 0, 0xF6, 0 },
        { szItemsFieldType_006DCCE8, 0xF, 0, 0x11E, &gpItemTypesLinker_0087D828 },
        { szItemTypesFieldCode_006DCCE0, 9, 0, 0x80, 0 },
        { szItemsFieldAlternateGfx_006DCCD0, 9, 0, 0x90, 0 },
        { szItemsFieldSpawnable_006DCCC4, 4, 0, 0x133, 0 },
        { szItemsFieldLevel_006DCCBC, 4, 0, 0xFD, 0 },
        { szItemsFieldComponent_006DCCB0, 4, 0, 0x115, 0 },
        { szItemsFieldWClass_006DCCA8, 9, 0, 0xC0, 0 },
        { szItemsField2HandedWClass_006DCC98, 9, 0, 0xC4, 0 },
        { szItemsField1or2Handed_006DCC8C, 6, 0, 0x13D, 0 },
        { szItemsFieldTransform_006DCC80, 4, 0, 0x141, 0 },
        { szBinFieldEnd_006D9060, 0, 0, 0, 0 },
    };

    D2CompItemsTxt* pWeapons = (D2CompItemsTxt*)sub_00504430_CompileTxt(hArchive, szItemsTableWeapons_006DCCF8, aItemsFields, &gnWeaponsTxtRecordCount_008426F8, sizeof(D2CompItemsTxt));
    D2CompItemsTxt* pArmor = (D2CompItemsTxt*)sub_00504430_CompileTxt(hArchive, szItemsTableArmor_006DCC78, aItemsFields, &gnArmorTxtRecordCount_00842700, sizeof(D2CompItemsTxt));
    D2CompItemsTxt* pMisc = (D2CompItemsTxt*)sub_00504430_CompileTxt(hArchive, szItemsTableMisc_006DCC70, aItemsFields, &gnMiscTxtRecordCount_00842708, sizeof(D2CompItemsTxt));

    gnItemsTotalCount_008426EC = gnArmorTxtRecordCount_00842700 + gnMiscTxtRecordCount_00842708 + gnWeaponsTxtRecordCount_008426F8;

    gpItemsTxt_008426F0 = (D2CompItemsTxt*)FOG_AllocPool(0, gnItemsTotalCount_008426EC * sizeof(D2CompItemsTxt), gszD2CompSourceFile, 0xA34, 0);
    D2CompItemsTxt* pItems = gpItemsTxt_008426F0;
    gpWeaponsTxt_008426F4 = gpItemsTxt_008426F0;
    memcpy(gpItemsTxt_008426F0, pWeapons, gnWeaponsTxtRecordCount_008426F8 * sizeof(D2CompItemsTxt));
    pItems += gnWeaponsTxtRecordCount_008426F8;
    gpArmorTxt_008426FC = pItems;
    memcpy(pItems, pArmor, gnArmorTxtRecordCount_00842700 * sizeof(D2CompItemsTxt));
    pItems += gnArmorTxtRecordCount_00842700;
    gpMiscTxt_00842704 = pItems;
    memcpy(pItems, pMisc, gnMiscTxtRecordCount_00842708 * sizeof(D2CompItemsTxt));

    FOG_FreePool(0, (char*)pWeapons - 4, gszD2CompSourceFile, 0xA44, 0);
    FOG_FreePool(0, (char*)pArmor - 4, gszD2CompSourceFile, 0xA45, 0);
    FOG_FreePool(0, (char*)pMisc - 4, gszD2CompSourceFile, 0xA46, 0);

    gpItemsVersion0Index_0084270C = (unsigned short*)FOG_AllocPool(0, gnItemsTotalCount_008426EC * sizeof(unsigned short), gszD2CompSourceFile, 0xA4B, 0);
    memset(gpItemsVersion0Index_0084270C, 0, gnItemsTotalCount_008426EC * sizeof(unsigned short));

    int i = 0;
    if (i < gnItemsTotalCount_008426EC)
    {
        D2CompItemsTxt* pRecords = gpItemsTxt_008426F0;
        int nCount = 0;
        do
        {
            if (!pRecords[i].wVersion)
            {
                gpItemsVersion0Index_0084270C[nCount] = i;
                ++nCount;
            }
            ++i;
        }
        while (i < gnItemsTotalCount_008426EC);
    }

    gpItemsLinker_0087D824 = sub_006BD040(gszD2CompSourceFile, 0xA56);
    for (int i = 0; i < gnItemsTotalCount_008426EC; ++i)
    {
        sub_006BD230_AddLinkCode(gpItemsLinker_0087D824, gpItemsTxt_008426F0[i].dwCode);
    }
}

// 0x00505470
static void sub_00505470_LoadItemPalette(const char* szName, int nIndex)
{
    char szPath[256];
    strcpy(szPath, "Data\\Global\\Items\\Palette\\");
    strcat(szPath, szName);
    strcat(szPath, ".dat");
    void* hFile;
    D2_ASSERT(ARCHIVE_OpenFile(0, szPath, &hFile, 1), 0xDD8);
    ARCHIVE_ReadFileToBuffer(0, hFile, gabItemPalettes_00842710[nIndex], 0x1500);
    ARCHIVE_CloseFile(0, hFile);
}

// 0x00505550
void __cdecl sub_00505550_LoadItemPalettes()
{
    sub_00505470_LoadItemPalette("grey", 1);
    sub_00505470_LoadItemPalette("grey2", 2);
    sub_00505470_LoadItemPalette("gold", 3);
    sub_00505470_LoadItemPalette("brown", 4);
    sub_00505470_LoadItemPalette("greybrown", 5);
    sub_00505470_LoadItemPalette("invgrey", 6);
    sub_00505470_LoadItemPalette("invgrey2", 7);
    sub_00505470_LoadItemPalette("invgreybrown", 8);
}

static __forceinline int sub_00505640_IsFemaleClass(int nClass)
{
    switch (nClass)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 1;
    }
    return 0;
}

// 0x00505640
const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nTitle, int bExpansion)
{
    if (bExpansion)
    {
        if (!sub_00505640_IsFemaleClass(nClass))
        {
            switch (nTitle)
            {
            case 1: return "Slayer ";
            case 2: return "Champion ";
            case 3: return "Patriarch ";
            case 4: return "Destroyer ";
            case 5: return "Conqueror ";
            case 6: return "Guardian ";
            }
        }
        else
        {
            switch (nTitle)
            {
            case 1: return "Slayer ";
            case 2: return "Champion ";
            case 3: return "Matriarch ";
            case 4: return "Destroyer ";
            case 5: return "Conqueror ";
            case 6: return "Guardian ";
            }
        }
    }
    else
    {
        if (!sub_00505640_IsFemaleClass(nClass))
        {
            switch (nTitle)
            {
            case 1: return "Sir ";
            case 2: return "Lord ";
            case 3: return "Baron ";
            case 4: return "Count ";
            case 5: return "Duke ";
            case 6: return "King ";
            }
        }
        else
        {
            switch (nTitle)
            {
            case 1: return "Dame ";
            case 2: return "Lady ";
            case 3: return "Baroness ";
            case 4: return "Countess ";
            case 5: return "Duchess ";
            case 6: return "Queen ";
            }
        }
    }

    return &gszEmptyAssertText;
}

// 0x00505810
int __fastcall sub_00505810_DrawCompositeLabel(D2CompositeUnitStrc* unit)
{
 if(!unit){sub_00408A60(&gszEmptyAssertText,sub_00408090(),1723);exit(-1);}
 if(!(unit->flags & gdwBitMasks[1]))return 0;
 int y=unit->y+6;
 Unicode text[256];
 int color=0,shadow=0;
 if(unit->unitClass==20){shadow=1;color=3;}
 else if(unit->unitClass==18){color=3;shadow=1;}
 else if(unit->flags & gdwBitMasks[5])color=1;
 unsigned int flags=unit->flags;
 if(unit->flags & gdwBitMasks[8])y+=15;
 if((flags & gdwBitMasks[6]) || (flags & gdwBitMasks[7])){
  const char* title=D2Win_10160_GetPlayerTitle(unit->unitClass,3*((flags>>5)&1)+2*((flags>>7)&1)+((flags>>6)&1),(flags>>12)&1);
  Unicode titleText[256];
  sub_00526F20(titleText,title,255);
  memset(text,0,sizeof(text));
  sub_005267E0(text,titleText);
  sub_00526700(text,unit->characterName);
 }else{
  if(unit->productCode=='D2DV' || unit->productCode=='D2ST' || unit->productCode=='D2XP')
   sub_005267E0(text,unit->characterName);
  else sub_005267E0(text,unit->accountName);
 }
 Unicode decoration[256];
 if(sub_00526800(unit->guildTag)){
  sub_00526320(decoration,gszGuildPrefix,256);
  sub_00526700(text,decoration);
  sub_00526700(text,unit->guildTag);
  sub_00526320(decoration,gszGuildSuffix,256);
  sub_00526700(text,decoration);
 }
 sub_00502EF0(12);
 sub_00503EC0_TruncateText(text,120);
 int width,height;
 sub_00502520(text,&width,&height);
 if(shadow)sub_00502320(text,unit->x-(width>>1)-1,y-1,6,0);
 sub_00502320(text,unit->x-(width>>1),y,color,0);
 return 1;
}
