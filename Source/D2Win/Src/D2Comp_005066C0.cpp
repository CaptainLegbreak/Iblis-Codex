#include "D2Win.h"

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
    char unk0xCC[0x168];
};

struct D2CompItemStrc
{
    unsigned int dwCode;
    int nWeaponClass;
    int nItemType;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, unsigned char* pPalette); // 0x004F6480
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode);                                 // 0x005042F0
void __stdcall sub_00506000_InitCompItems();                                                                // 0x00506000

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2CompItemStrc gaCompItems_0072E1E0[];                                                               // 0x0072E1E0
extern int gnItems_0087D834;                                                                                // 0x0087D834
extern D2CompItemStrc gaItems_0087D838[];                                                                   // 0x0087D838
extern int gaItemWeaponClass_0087E430[];                                                                    // 0x0087E430
extern D2CompositeUnitStrc* gpCompositeUnitList_0087E838;                                                   // 0x0087E838
extern D2CofNodeStrc* gpCofNodeList_0087E83C;                                                               // 0x0087E83C
extern unsigned int gdwNextFrameTick_0087E840;                                                              // 0x0087E840
extern D2CelFileStrc* ghSquelchCelFile_0087E844;                                                            // 0x0087E844
extern int gnSquelchCelFileFrameCount_0087E848;                                                             // 0x0087E848
extern int gnSquelchCelFileFrame_0087E84C;                                                                  // 0x0087E84C
extern D2CelFileStrc* ghSelectedCelFile_0087E850;                                                           // 0x0087E850
extern int gnSelectedCelFileFrameCount_0087E854;                                                            // 0x0087E854
extern int gnSelectedCelFileFrame_0087E858;                                                                 // 0x0087E858

#define COF_PAD 0x20
#define TOKEN_CHAR(c) ((char)(c) == COF_PAD ? 0 : (char)(c))

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
    D2CofDataStrc* pCofData = (D2CofDataStrc*)sub_00517079_LoadFile(sub_004FAC80(), szPath, pnSize, gszD2CompSourceFile, 0x3EB);
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

    D2CofNodeStrc* pNode = (D2CofNodeStrc*)FOG_Alloc(sizeof(D2CofNodeStrc), gszD2CompSourceFile, 0x437, 0);
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

    const char* szDir = gszCharsDir_006DCC34;
    if (nClass >= 7)
    {
        szDir = gszMonstersDir_006D6CAC;
    }
    wsprintfA(szPath, gszCofPathFormat_006D6C94, szDir, szUnit, szUnit, szMode, szWeaponClass);

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

        pCofInfo = (D2CofInfoStrc*)FOG_Alloc(sizeof(D2CofInfoStrc), gszD2CompSourceFile, 0x4D8, 0);
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

void __stdcall sub_00504F80_InitCompositeUnit(D2CompositeUnitStrc* pCompositeUnit, unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors)
{
    D2_ASSERT(pCompositeUnit, 0xCDD);

    D2GfxInfoStrc* pGfxInfo = (D2GfxInfoStrc*)FOG_Alloc(sizeof(D2GfxInfoStrc), gszD2CompSourceFile, 0x866, 0);
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

// 0x005066C0
D2CompositeUnitStrc* __stdcall sub_005066C0_CreateCompositeUnit(unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors)
{
    D2CompositeUnitStrc* pCompositeUnit = (D2CompositeUnitStrc*)FOG_Alloc(sizeof(D2CompositeUnitStrc), gszD2CompSourceFile, 0xC70, 0);
    D2_ASSERT(pCompositeUnit, 0xC71);
    memset(pCompositeUnit, 0, sizeof(D2CompositeUnitStrc));

    D2GfxInfoStrc* pGfxInfo = (D2GfxInfoStrc*)FOG_Alloc(sizeof(D2GfxInfoStrc), gszD2CompSourceFile, 0x866, 0);
    D2_ASSERT(pGfxInfo, 0x867);
    pGfxInfo->pCofInfo = 0;
    pCompositeUnit->pGfxInfo = pGfxInfo;
    sub_00506000_InitCompItems();
    unsigned char* pComponent = pComponents;
    pCompositeUnit->nUnitIndex = nUnitIndex;
    if (nUnitIndex >= 7)
    {
        pCompositeUnit->nWClassTokenIndex = 1;
    }
    else
    {
        pCompositeUnit->nWClassTokenIndex = sub_00504AF0_GetWeaponClass(nUnitIndex, pComponent);
        if (!pCompositeUnit->nWClassTokenIndex)
        {
            return 0;
        }
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

    for (int j = 0; j < 16; ++j)
    {
        const unsigned char nColor = *pComponentColors++;
        pCompositeUnit->nComponentColors[j] = nColor;
        if (nColor != 0xFF)
        {
            pCompositeUnit->nComponentColors[j] = nColor - 1;
        }
    }

    if (sub_00504040_LoadUnitCof(pCompositeUnit) && !D2Win_10143(pCompositeUnit, nMode))
    {
        return 0;
    }

    D2CompositeUnitStrc* pHead = gpCompositeUnitList_0087E838;
    pCompositeUnit->pPrev = 0;
    pCompositeUnit->pNext = pHead;
    if (pHead)
    {
        pHead->pPrev = pCompositeUnit;
    }
    gpCompositeUnitList_0087E838 = pCompositeUnit;
    return pCompositeUnit;
}
