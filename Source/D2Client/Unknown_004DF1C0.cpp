#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define SKILLS_GetSkillsTxtRecord_E1120(nSkillId) \
    ((nSkillId) >= 0 && (nSkillId) < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0)
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2TileLibraryEntryStrc;
struct D2GfxLightStrc;
struct D2LightOffsetStrc;
struct D2LightOffsetsStrc;
struct D2TileLightNodeStrc;
struct D2UnitLightNodeStrc;
struct D2TileLightEntryStrc;
struct D2TileLightCtxStrc;
struct D2SlotObjectStrc;
struct D2SoundRecordStrc;
struct D2SlotStrc;
struct D2NpcSoundStrc;
struct WardenSectionStrc;
struct WardenHeaderStrc;
struct WardenRawModuleStrc;
struct WardenImportStrc;
class WardenModule;
struct D2RC4Strc;
struct D2SkillsTxt;
struct D2MissileStrc;
struct D2MissilesTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2TileLibraryEntryStrc
{
    unsigned int nLightDirection;
};

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int unk0x08[3];
    unsigned int dwFlags;
    D2TileLibraryEntryStrc* pTile;
    int nTileType;
    int unk0x20;
    unsigned int dwLightFlags;
    unsigned char nAlpha;
    unsigned char nFadeFrom;
    unsigned char nFadeTo;
    char unk0x2B;
    unsigned int dwLightTime;
};

struct D2TileLightNodeStrc
{
    int unk0x00;
    int nX;
    int nY;
    D2DrlgTileDataStrc* pTileData;
    D2TileLightNodeStrc* pNext;
};

struct D2UnitLightNodeStrc
{
    int unk0x00;
    int nX;
    int nY;
    D2CellPosStrc* pPos;
    D2UnitLightNodeStrc* pNext;
};

struct D2TileLightEntryStrc
{
    int unk0x00[5];
    D2TileLightNodeStrc* pFadeList;
    D2UnitLightNodeStrc* pUnitList;
    int unk0x1C;
    D2TileLightNodeStrc* pList;
};

struct D2TileLightCtxStrc
{
    int unk0x00;
    int nX;
    int nY;
    int unk0x0C[6];
    int f_24;
    int f_28;
    char unk0x2C[0xEAA8 - 0x2C];
    D2TileLightEntryStrc* pEntries;
    int unk0xEAAC;
    unsigned int nSize;
};
extern D2LightOffsetsStrc gaLightOffsetsA_0072ABC8[]; // 0x0072ABC8
extern D2LightOffsetsStrc gaLightOffsetsB_0072A9E8[]; // 0x0072A9E8
int __cdecl sub_0045AE90(); // 0x0045AE90
int __stdcall sub_00477730(); // 0x00477730
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall sub_00475AA0_ReadGridCell(int nX, int nY, unsigned char* pValue0, unsigned char* pValue1, unsigned char* pValue2, unsigned char* pValue3); // 0x00475AA0
int __stdcall TILE_TileDrawTrans(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha); // 0x004F6950
int __stdcall TILE_TileDrawLit(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels); // 0x004F6920

#pragma pack(push, 1)
struct D2SlotObjectStrc
{
    char unk0x00[0x04];
    int f_4;
    char unk0x08[0x1C];
    int nField0x24;
    char unk0x28[0x04];
    int nField0x2C;
    int nField0x30;
    unsigned int nKey;
    unsigned char nFlags;
    char unk0x39[0x03];
    unsigned char nPriority;
    int nField0x3D;
    unsigned int f_41;
};

struct D2SoundRecordStrc
{
    char unk0x00[0x3E];
    unsigned char nField0x3E;
    char unk0x3F[0x0C];
    unsigned char nField0x4B;
    char unk0x4C;
    unsigned char nField0x4D;
    char unk0x4E;
    unsigned char bStream;
    unsigned char nField0x50;
    char unk0x51[0x03];
    int nField0x54;
    char unk0x58[0x0C];
    int nField0x64;
    int nField0x68;
    int nField0x6C;
    int nField0x70;
    char f_74[0x0C];
    unsigned char nField0x80;
    unsigned char nField0x81;
    char unk0x82[0x04];
    int nState;
};

#pragma pack(pop)
struct D2SlotStrc
{
    D2SoundStrc* f_0;
    int nType;
    D2SlotObjectStrc* pObject;
    int nField0x0C;
    int nField0x10;
    int nField0x14;
    int nField0x18;
    float fField0x1C;
};

extern D2SlotStrc gaSlots_007C8A78[16]; // 0x007C8A78
int __fastcall sub_004B9DA0_CompareItems(D2SlotObjectStrc* pA, D2SlotObjectStrc* pB, int bCompareFloat, int bCompareValue); // 0x004B9DA0
D2SoundRecordStrc* __fastcall sub_00481860(int nId); // 0x00481860
int __fastcall sub_00482680_PickVariant(int nId); // 0x00482680
void __fastcall sub_00482970(int nId, int bFlag, int nArg); // 0x00482970
D2SlotStrc* __fastcall sub_004DF9D0_CheckCacheEntry(int nId); // 0x004DF9D0
void __fastcall sub_004DFC20(D2SlotStrc* pSlot); // 0x004DFC20
int __fastcall sub_005155D0(D2SoundStrc* pSound, int nA, int nB); // 0x005155D0
int __fastcall sub_005156A0(D2SoundStrc* pSound); // 0x005156A0
int __fastcall sub_00515710(D2SoundStrc* pSound); // 0x00515710
void __fastcall sub_00515A30(D2SoundStrc* pSound, int nValue); // 0x00515A30
void __fastcall sub_00515A60(D2SoundStrc* pSound, int nValue); // 0x00515A60
void __fastcall sub_00515B40(D2SoundStrc* pSound, float fValue); // 0x00515B40
int __fastcall sub_00515D70(D2SoundStrc* pSound, char* szPath, int nA, int nB); // 0x00515D70
void __fastcall sub_00516140(D2SoundStrc* pSound); // 0x00516140
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x94];
    unsigned int dwFlags;
};

extern D2NpcSoundStrc gaNpcSounds_0072AE28[]; // 0x0072AE28
extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634
int __fastcall sub_004E40A0(int nRange); // 0x004E40A0
int __cdecl sub_0044DB00(); // 0x0044DB00

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, unsigned long nSize, unsigned long nType, unsigned long nProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long nSize, unsigned long nFreeType); // 0x006CC220
extern "C" __declspec(dllimport) int __stdcall VirtualProtect(void* pAddress, unsigned long nSize, unsigned long nNewProtect, unsigned long* pOldProtect); // 0x006CC360
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FlushInstructionCache(void* hProcess, const void* pBaseAddress, unsigned long nSize); // 0x006CC35C
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

struct WardenSectionStrc
{
    unsigned int dwRva;
    unsigned int dwSize;
    unsigned int dwProtect;
};

struct WardenHeaderStrc
{
    unsigned int dwImageSize;
    unsigned int unk0x04;
    unsigned int dwRelocOffset;
    unsigned int nRelocCount;
    unsigned int unk0x10[3];
    unsigned int dwImportOffset;
    unsigned int nImportCount;
    unsigned int nSections;
};

struct WardenRawModuleStrc
{
    WardenHeaderStrc tHeader;
    WardenSectionStrc aSections[1];
};

struct WardenImportStrc
{
    unsigned int dwNameOffset;
    unsigned int dwThunkOffset;
};

class WardenModule
{
public:
    ~WardenModule();                                                                // 0x004E06A0
    bool sub_004E0730_Load(void* pData, int nSize);

    void* pImage;
    int unk0x04;
    int nImports;
    int unk0x0C;
    void* pEntry;
};

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize);
    void sub_0047F8C0_Crypt(unsigned char* pData, unsigned int nSize);       // 0x0047F8C0
};

struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissile;
    unsigned char unk_EC[0x4C];
    unsigned int dwCalc[4];
    char unk0x148[0x23C - 0x148];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0xB98 - 0xB70];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned char gaDirection64To4_006DBA60[64]; // 0x006DBA60
extern const unsigned char gaDirection4_006DBA58[4]; // 0x006DBA58
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

struct D2MissilesTxt
{
    char unk0x000[0x38];
    int dwParam[5];
    char unk0x04C[0x178 - 0x4C];
    unsigned char nAnimLen;
    char unk0x179[0x1A4 - 0x179];
};

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
static __declspec(noinline) int __stdcall sub_004E1400_UpdateInfernoAnimation(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel);

static D2LightOffsetsStrc* __stdcall sub_004DEDB0_GetLightOffsets(D2TileLibraryEntryStrc* pTile, unsigned int* pCount, int bAlternate)
{
    *pCount = gaLightSampleCounts_006DB9D8[pTile->nLightDirection];
    if (bAlternate)
        return &gaLightOffsetsA_0072ABC8[pTile->nLightDirection];
    return &gaLightOffsetsB_0072A9E8[pTile->nLightDirection];
}

// 0x004DF1C0
void __fastcall sub_004DF1C0_UpdateFadingTileLights(D2TileLightCtxStrc* pCtx)
{
    int nCount = pCtx->nSize * pCtx->nSize;
    D2TileLightEntryStrc* pEntry = pCtx->pEntries;
    while (nCount--)
    {
        if (pEntry->pFadeList)
        {
            const int nScreenPanels = sub_0045AE90();
            const int bPerspective = sub_004F51D0_IsPerspective();
            const int nLightDetail = sub_00477730();
            const unsigned int nTick = GetTickCount();
            const int bFade = nLightDetail >= 4;
            for (D2TileLightNodeStrc* pNode = pEntry->pFadeList; pNode; pNode = pNode->pNext)
            {
                D2DrlgTileDataStrc* pTileData = pNode->pTileData;
                D2_ASSERT(pTileData->nTileType != 15, 0xF9);

                const unsigned int dwLightFlags = pTileData->dwLightFlags;
                if (dwLightFlags & 2)
                {
                    if (bFade)
                    {
                        if (nTick < pTileData->dwLightTime)
                        {
                            pTileData->nAlpha = pTileData->nFadeFrom + (pTileData->nFadeTo - pTileData->nFadeFrom) * (int)(nTick - pTileData->dwLightTime + 500) / 500;
                        }
                        else
                        {
                            unsigned char* pAlpha = &pTileData->nAlpha;
                            *pAlpha = pTileData->nFadeTo;
                            pTileData->dwLightFlags = dwLightFlags & ~2;
                        }
                    }
                    else
                    {
                        unsigned char* pAlpha = &pTileData->nAlpha;
                        *pAlpha = pTileData->nFadeTo;
                        pTileData->dwLightFlags = dwLightFlags & ~2;
                    }

                    if (!pTileData->nAlpha)
                        pTileData->dwFlags |= 0x400;
                    else
                        pTileData->dwFlags &= ~0x400;
                }

                if ((pTileData->dwLightFlags & 4) && nTick >= pTileData->dwLightTime)
                {
                    pTileData->dwLightFlags &= ~4;
                    pTileData->dwFlags |= 8;
                }

                if (pTileData->dwFlags & 0x408)
                    continue;

                if (!(pTileData->dwFlags & 0x1C000))
                    continue;

                unsigned int nLights;
                D2LightOffsetsStrc* pOffsets = sub_004DEDB0_GetLightOffsets(pTileData->pTile, &nLights, pTileData->dwLightFlags & 1);
                D2GfxLightStrc tLight;
                for (unsigned int i = 0; i < nLights; ++i)
                {
                    unsigned char nValue0;
                    unsigned char nValue1;
                    unsigned char nValue2;
                    unsigned char nValue3;
                    sub_00475AA0_ReadGridCell(pNode->nX + 8 * pOffsets->aOffset[i].nX, pNode->nY + 8 * pOffsets->aOffset[i].nY, &nValue0, &nValue1, &nValue2, &nValue3);
                    nValue0 = nValue0 > 0 ? nValue0 : 0;
                    tLight.aColor[i] = (nValue3 << 24) | (nValue2 << 16) | (nValue1 << 8) | nValue0;
                }

                const unsigned char nAlpha = pTileData->nAlpha;
                int nX;
                int nY;
                if (bPerspective)
                {
                    nX = pNode->nX;
                    nY = pNode->nY;
                }
                else
                {
                    nX = pCtx->nX - pCtx->f_24 + pTileData->nWidth;
                    nY = pTileData->nHeight - pCtx->f_28 + pCtx->nY;
                }

                int bDrawn;
                if (nAlpha != 0xFF)
                    bDrawn = TILE_TileDrawTrans(pTileData->pTile, nX, nY, &tLight, nScreenPanels, nAlpha);
                else
                    bDrawn = TILE_TileDrawLit(pTileData->pTile, nX, nY, &tLight, nScreenPanels);

                if (bDrawn)
                    pTileData->dwFlags |= 0x20000;
            }
        }

        for (D2UnitLightNodeStrc* pUnitNode = pEntry->pUnitList; pUnitNode; pUnitNode = pUnitNode->pNext)
        {
            unsigned char nValue0;
            unsigned char nValue1;
            unsigned char nValue2;
            unsigned char nValue3;
            sub_00475AA0_ReadGridCell(pUnitNode->nX, pUnitNode->nY, &nValue0, &nValue1, &nValue2, &nValue3);
            sub_004DC7B0(pUnitNode->pPos, (nValue3 << 24) | (nValue2 << 16) | (nValue1 << 8) | nValue0, 0);
        }

        ++pEntry;
    }
}

// 0x004DFB50
static D2SlotStrc* __stdcall sub_004DFB50_GetFreeSlot(D2SlotObjectStrc* pObject, int nType)
{
    for (int i = 0; i < 16; ++i)
    {
        D2SlotStrc* pSlot = &gaSlots_007C8A78[i];
        if (!pSlot->pObject && pSlot->nType == nType && !sub_00515710(pSlot->f_0))
            return pSlot;
    }
    D2SlotStrc* pBest = 0;
    for (int i = 0; i < 16; ++i)
    {
        if (gaSlots_007C8A78[i].nType == nType && gaSlots_007C8A78[i].pObject)
        {
            if (!pBest || sub_004B9DA0_CompareItems(pBest->pObject, gaSlots_007C8A78[i].pObject, 1, 1))
                pBest = &gaSlots_007C8A78[i];
        }
    }
    if (!pBest || !sub_004B9DA0_CompareItems(pObject, pBest->pObject, 0, 0))
        return 0;
    if (pBest->f_0)
    {
        if (pBest->pObject)
            pBest->pObject->f_41 = sub_005159B0_GetSoundSampleCount(pBest->f_0);
        sub_00515EE0_StopSound(pBest->f_0);
    }
    if (pBest->pObject)
    {
        pBest->pObject->nField0x30 = 2;
        pBest->pObject->nField0x2C = 0;
        pBest->pObject = 0;
    }
    return pBest;
}

// 0x004E01B0
D2SlotStrc* __fastcall sub_004E01B0_PlaySlotSound(D2SlotObjectStrc* pObject)
{
    D2SoundRecordStrc* pFirst = sub_00481860(pObject->f_4);
    if (!(pObject->nFlags & 1))
        pObject->f_4 = sub_00482680_PickVariant(pObject->f_4);
    D2SlotStrc* pOld = sub_004DF9D0_CheckCacheEntry(pObject->f_4);
    if (pOld && !pOld->pObject->nField0x3D && pObject->nKey - pOld->pObject->nKey < 2 && pOld->pObject->nPriority >= pObject->nPriority)
        return 0;
    D2SoundRecordStrc* pRecord = sub_00481860(pObject->f_4);
    pFirst->nField0x68 = pFirst->nField0x64;
    pFirst->nField0x64 = pObject->f_4;
    if (!pRecord->bStream && pRecord->nState != 2)
    {
        sub_00482970(pObject->f_4, pRecord->nField0x4D == 0, 0);
        if (pRecord->nState != 2)
            return 0;
    }
    if (pRecord->nField0x81)
        return 0;
    int nType = 0;
    if (pRecord->nField0x50)
        nType = 1;
    if (!(nType & 1))
    {
        if (sub_00514C90_GetSoundMode() == 1)
            nType |= 2;
        if (sub_00514C90_GetSoundMode() == 2)
            nType |= 6;
    }
    D2SlotStrc* pSlot = sub_004DFB50_GetFreeSlot(pObject, nType);
    if (!pSlot)
        return 0;
    sub_00516140(pSlot->f_0);
    if (!pRecord->bStream)
    {
        sub_00515A30(pSlot->f_0, pRecord->nField0x3E);
        if (pRecord->nField0x80 == 1)
            sub_00515A60(pSlot->f_0, pRecord->nField0x54 * 2);
        if (!sub_005155D0(pSlot->f_0, pRecord->nField0x6C, pRecord->nField0x70))
            return 0;
    }
    pSlot->pObject = pObject;
    if (nType & 4)
    {
        float fValue = pRecord->nField0x4B ? 1.0f : 0.0f;
        sub_00515B40(pSlot->f_0, fValue);
    }
    pSlot->fField0x1C = 0.0f;
    pSlot->nField0x18 = -1;
    memset(&pSlot->nField0x0C, 0, 3 * sizeof(int));
    sub_004DFC20(pSlot);
    int bOk;
    if (!pRecord->bStream)
    {
        bOk = sub_005156A0(pSlot->f_0);
    }
    else
    {
        char szPath[0x50];
        sub_00482710(pObject->f_4, szPath);
        bOk = sub_00515D70(pSlot->f_0, szPath, pObject->nField0x24, pRecord->nField0x3E);
    }
    if (!bOk)
    {
        pSlot->pObject = 0;
        return 0;
    }
    return pSlot;
}

// 0x004E0370
static D2NpcSoundStrc* sub_004E0370_GetNpcSoundRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    switch (pUnit->dwClassId)
    {
    case 0x94:
        return &gaNpcSounds_0072AE28[0];
    case 0xFE:
        return &gaNpcSounds_0072AE28[1];
    case 0xFC:
        return &gaNpcSounds_0072AE28[2];
    case 0xB0:
        return &gaNpcSounds_0072AE28[3];
    case 0x9A:
        return &gaNpcSounds_0072AE28[5];
    case 0xB1:
        return &gaNpcSounds_0072AE28[6];
    case 0xC7:
        return &gaNpcSounds_0072AE28[7];
    case 0xB2:
        return &gaNpcSounds_0072AE28[8];
    case 0xC8:
        return &gaNpcSounds_0072AE28[9];
    case 0x93:
        return &gaNpcSounds_0072AE28[10];
    case 0xC6:
        return &gaNpcSounds_0072AE28[11];
    case 0x101:
        return &gaNpcSounds_0072AE28[12];
    case 0xFD:
        return &gaNpcSounds_0072AE28[13];
    case 0xC9:
        return &gaNpcSounds_0072AE28[16];
    case 0x96:
        return &gaNpcSounds_0072AE28[17];
    case 0xCA:
        return &gaNpcSounds_0072AE28[18];
    case 0xD2:
        return &gaNpcSounds_0072AE28[19];
    case 0x129:
        return &gaNpcSounds_0072AE28[20];
    case 0xFF:
        return &gaNpcSounds_0072AE28[21];
    case 0x9B:
    case 0xAF:
        return &gaNpcSounds_0072AE28[23];
    case 0x195:
        return &gaNpcSounds_0072AE28[14];
    case 0x92:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0x109:
    case 0x208:
        return &gaNpcSounds_0072AE28[4];
    case 0xFB:
    case 0x209:
        return &gaNpcSounds_0072AE28[22];
    case 0x200:
        return &gaNpcSounds_0072AE28[24];
    case 0x203:
        return &gaNpcSounds_0072AE28[25];
    case 0x202:
        return &gaNpcSounds_0072AE28[28];
    case 0x1FF:
        return &gaNpcSounds_0072AE28[27];
    case 0x201:
        return &gaNpcSounds_0072AE28[26];
    }

    return 0;
}

// 0x004E0590
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType)
{
    int nSound;
    D2NpcSoundStrc* pSound = sub_004E0370_GetNpcSoundRecord(pUnit);
    if (!pSound)
    {
        return 0;
    }

    if (nType == 2)
    {
        nSound = pSound->nGreetSound;
        return nSound;
    }

    for (unsigned int i = 0; i < 20; ++i)
    {
        nSound = pSound->f_0;
        if (!nType && pSound->nDaySound && !sub_004E40A0(2))
        {
            nSound = pSound->nDaySound;
        }

        if (pSound->nNightSound)
        {
            if (!nSound || !sub_004E40A0(3))
            {
                const int nCycle = ENVIRONMENT_GetCycleIndexFromAct(gpAct_007A0634);
                nSound = pSound->nNightSound;
                if (nCycle != 1)
                {
                    if (nCycle >= 2 && nCycle <= 3)
                    {
                        nSound += 1;
                    }
                    else
                    {
                        nSound += 2;
                    }
                }
            }

            nSound = sub_00482680_PickVariant(nSound);
        }
        else
        {
            nSound = sub_00482680_PickVariant(nSound);
        }

        if (nSound != pSound->nLastSound)
        {
            break;
        }
    }

    pSound->nLastSound = nSound;
    pSound->nLastTick = sub_0044DB00();
    return nSound;
}

// 0x004E0730
bool WardenModule::sub_004E0730_Load(void* pData, int nSize)
{
    int bFailed = 1;
    __try
    {
        WardenRawModuleStrc* pRaw = (WardenRawModuleStrc*)pData;
        unk0x04 = pRaw->tHeader.dwImageSize;
        pImage = VirtualAlloc(0, unk0x04, 0x1000, 4);
        if (!pImage)
        {
            __leave;
        }

        *(WardenHeaderStrc*)pImage = pRaw->tHeader;

        unsigned char* pChunk = (unsigned char*)&pRaw->aSections[((WardenHeaderStrc*)pImage)->nSections];
        unsigned char* pDest = (unsigned char*)pImage + pRaw->aSections[0].dwRva;
        unsigned char* pEnd = (unsigned char*)pImage + ((WardenHeaderStrc*)pImage)->dwImageSize;
        bool bCopy = true;
        while (pDest < pEnd)
        {
            unsigned short nLength = *(unsigned short*)pChunk;
            pChunk += 2;
            if (bCopy)
            {
                memcpy(pDest, pChunk, nLength);
                pChunk += nLength;
            }
            pDest += nLength;
            if (pDest >= pEnd)
            {
                break;
            }
            bCopy = !bCopy;
        }

        unsigned char* pReloc = (unsigned char*)pImage + ((WardenHeaderStrc*)pImage)->dwRelocOffset;
        unsigned int nOffset = 0;
        for (unsigned int i = 0; i < ((WardenHeaderStrc*)pImage)->nRelocCount; ++i)
        {
            if (pReloc[0] & 0x80)
            {
                nOffset = (((((pReloc[0] & 0x7F) << 8) + pReloc[1]) << 8) + pReloc[2] << 8) + pReloc[3];
                pReloc += 4;
            }
            else
            {
                nOffset += (pReloc[0] << 8) + pReloc[1];
                pReloc += 2;
            }
            *(unsigned int*)((unsigned char*)pImage + nOffset) += (unsigned int)pImage;
        }

        WardenImportStrc* pImports = (WardenImportStrc*)((unsigned char*)pImage + ((WardenHeaderStrc*)pImage)->dwImportOffset);
        for (unsigned int j = 0; j < ((WardenHeaderStrc*)pImage)->nImportCount; ++j)
        {
            const char* const szLibrary = (const char*)pImage + pImports[j].dwNameOffset;
            void* hLibrary = LoadLibraryA(szLibrary);
            if (!hLibrary)
            {
                __leave;
            }
            for (unsigned int* pThunk = (unsigned int*)((unsigned char*)pImage + pImports[j].dwThunkOffset); *pThunk; ++pThunk)
            {
                if (*pThunk & 0x80000000)
                {
                    *pThunk = (unsigned int)GetProcAddress(hLibrary, (const char*)(*pThunk & 0x7FFFFFFF));
                }
                else
                {
                    *pThunk = (unsigned int)GetProcAddress(hLibrary, (const char*)pImage + *pThunk);
                }
            }
            ++nImports;
        }

        for (unsigned int k = 0; k < ((WardenHeaderStrc*)pImage)->nSections; ++k)
        {
            WardenSectionStrc* pSection = &pRaw->aSections[k];
            void* pAddress = (unsigned char*)pImage + pSection->dwRva;
            unsigned long nLength = pSection->dwSize;
            unsigned long dwOldProtect;
            VirtualProtect(pAddress, nLength, pSection->dwProtect, &dwOldProtect);
            if (pSection->dwProtect & 0xF0)
            {
                FlushInstructionCache(GetCurrentProcess(), pAddress, nLength);
            }
        }

        if (((WardenHeaderStrc*)pImage)->dwRelocOffset < ((WardenHeaderStrc*)pImage)->dwImageSize)
        {
            const unsigned int nRelocStart = ((WardenHeaderStrc*)pImage)->dwRelocOffset;
            const unsigned int nPage = (nRelocStart + 0xFFF) & 0xFFFFF000;
            if (nPage >= nRelocStart && nPage < ((WardenHeaderStrc*)pImage)->dwImageSize)
            {
                VirtualFree((unsigned char*)pImage + nPage, ((WardenHeaderStrc*)pImage)->dwImageSize - nPage, 0x4000);
            }
        }
        bFailed = 0;
    }
    __except (1)
    {
    }

    if (bFailed)
    {
        this->~WardenModule();
    }
    return !bFailed;
}

// 0x004E09B0
void D2RC4Strc::sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize)
{
    for (unsigned int n = 0; n < 0x100; ++n)
    {
        S[n] = (unsigned char)n;
    }
    i = 0;
    j = 0;
    unsigned char k = 0;
    unsigned char b = 0;
    unsigned int n = 0;
    do
    {
        b += pKey[k] + S[n];
        unsigned char* pA = &S[n];
        unsigned char* pB = &S[b];
        unsigned char t = *pA;
        *pA = *pB;
        *pB = t;
        k = (unsigned char)((k + 1) % nKeySize);
        ++n;
    } while (n < 0x100);
}

// build: context CLT_Abs
static int CLT_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x004E1120
int __fastcall sub_004E1120_SkillCreateTargetMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord_E1120(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissile;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    int nEndX = nTargetX;
    int nEndY = nTargetY;
    int nSteps = 4;
    if (CLT_Abs(nTargetX - nX) < CLT_Abs(nTargetY - nY))
    {
        nEndX = nX;
        do
        {
            if (nEndX > nTargetX)
            {
                --nEndX;
            }
            else if (nEndX < nTargetX)
            {
                ++nEndX;
            }
        }
        while (--nSteps > 0);
    }
    else
    {
        nEndY = nY;
        do
        {
            if (nEndY > nTargetY)
            {
                --nEndY;
            }
            else if (nEndY < nTargetY)
            {
                ++nEndY;
            }
        }
        while (--nSteps > 0);
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    tMissile.pOwner = pUnit;
    tMissile.nTargetX = nEndX - nX;
    tMissile.nTargetY = nEndY - nY;
    tMissile.nX = nX + tMissile.nTargetX / 6 - 1;
    tMissile.nY = nY + tMissile.nTargetY / 6 - 1;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;
    sub_006488A0_SetDirection(pUnit->pDynamicPath, gaDirection4_006DBA58[gaDirection64To4_006DBA60[UNITS_GetDirectionToCoords(pUnit, nEndX, nEndY) & 0x3F] & 3]);
    sub_004CD540_CreateMissile(&tMissile);
    return 1;
}

#include "gen/data/Source/D2Client/Unknown_004DF1C0.inc"

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static inline D2MissilesTxt* sub_004E1400_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }

    return 0;
}

// 0x004E1400
static int __stdcall sub_004E1400_UpdateInfernoAnimation(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_004E1400_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nFrame <= 0)
    {
        nFrame = pMissilesTxtRecord->dwParam[1] + nSkillLevel - 1;
    }

    nFrame = D2_MIN(D2_MAX(nFrame, 1), 255);

    PATH_SetNewDistance(pMissile->pDynamicPath, nFrame);
    UNITS_SetAnimationSpeed(pMissile, (pMissilesTxtRecord->nAnimLen << 8) / nFrame);
    MISSILE_SetTotalFrames(pMissile, nFrame);
    MISSILE_SetCurrentFrame(pMissile, nFrame);
    return 1;
}

int __fastcall sub_004E1400_EmitCaller(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel)
{
    return sub_004E1400_UpdateInfernoAnimation(pUnit, pMissile, nSkillId, nSkillLevel);
}
