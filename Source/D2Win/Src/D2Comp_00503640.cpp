#include "D2Win.h"
#include "D2CmpTypes.h"
#include "D2WinTypes.h"

struct D2CofDataStrc
{
    unsigned char nLayers;
    unsigned char nFramesPerDirection;
    unsigned char nDirections;
    unsigned char nVersion;
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

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
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

// 0x00503640
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
