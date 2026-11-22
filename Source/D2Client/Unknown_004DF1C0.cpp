#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2DrlgMaps.h"
#include "D2ClientUi.h"
#include "D2ClientSound.h"

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
extern D2LightOffsetsStrc gaLightOffsetsA[]; // 0x0072ABC8
extern D2LightOffsetsStrc gaLightOffsetsB[]; // 0x0072A9E8
int __cdecl sub_0045AE90(); // 0x0045AE90
int __cdecl DLIGHTMAP_GetRenderMode(); // 0x00477730
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall SCMD_ReadGridCell(int nX, int nY, unsigned char* pValue0, unsigned char* pValue1, unsigned char* pValue2, unsigned char* pValue3); // 0x00475AA0
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

#pragma pack(pop)

extern D2SlotStrc gaSlots[16]; // 0x007C8A78
int __fastcall sub_004B9DA0_CompareItems(D2SlotObjectStrc* pA, D2SlotObjectStrc* pB, int bCompareFloat, int bCompareValue); // 0x004B9DA0
D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId); // 0x00481860
int __fastcall SOUNDHDR_PickVariant(int nId); // 0x00482680
void __fastcall SOUNDHDR_LoadCacheEntry(int nId, int bFlag, int nArg); // 0x00482970
D2SlotStrc* __fastcall SoundChannelFind(int nId); // 0x004DF9D0
void __fastcall sub_004DFC20_UpdateSoundSlot(D2SlotStrc* pSlot); // 0x004DFC20
int __fastcall D2SOUND_SetSoundData(D2SoundStrc* pSound, const void* pFile, unsigned int nSize); // 0x005155D0
int __fastcall sub_005156A0(D2SoundStrc* pSound); // 0x005156A0
int __fastcall sub_00515710(D2SoundStrc* pSound); // 0x00515710
void __fastcall sub_00515A30(D2SoundStrc* pSound, int nValue); // 0x00515A30
void __fastcall sub_00515A60(D2SoundStrc* pSound, int nValue); // 0x00515A60
void __fastcall sub_00515B40(D2SoundStrc* pSound, float fValue); // 0x00515B40
int __fastcall D2SOUND_StartSoundStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop); // 0x00515D70
void __fastcall D2SOUND_ResetSound(D2SoundStrc* pSound); // 0x00516140
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern D2NpcSoundStrc gaNpcSounds[]; // 0x0072AE28
extern D2DrlgActStrc* gpAct; // 0x007A0634
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
    void ApplyKeystream(unsigned char* pData, unsigned int nSize);       // 0x0047F8C0
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned char gaDirection64To4[64]; // 0x006DBA60
extern const unsigned char gaDirection4[4]; // 0x006DBA58
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
static int __stdcall sub_004E1400_UpdateInfernoAnimation(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel);

static D2LightOffsetsStrc* __stdcall sub_004DEDB0_GetLightOffsets(D2TileLibraryEntryStrc* pTile, unsigned int* pCount, int bAlternate)
{
// build: symbol ?gaLightSampleCounts@* 0x006DB9D8
    *pCount = gaLightSampleCounts[pTile->nLightDirection];
    if (bAlternate)
        return &gaLightOffsetsA[pTile->nLightDirection];
    return &gaLightOffsetsB[pTile->nLightDirection];
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
            const int nLightDetail = DLIGHTMAP_GetRenderMode();
            const unsigned int nTick = GetTickCount();
            const int bFade = nLightDetail >= 4;
            for (D2TileLightNodeStrc* pNode = pEntry->pFadeList; pNode; pNode = pNode->pNext)
            {
                D2DrlgTileDataStrc* pTileData = pNode->pTileData;
                D2_ASSERT(pTileData->nTileType != 15, 0xF9);

                const unsigned int dwLightFlags = pTileData->dwPopFlags;
                if (dwLightFlags & 2)
                {
                    if (bFade)
                    {
                        if (nTick < pTileData->nPopTick)
                        {
                            pTileData->nRed = pTileData->nGreen + (pTileData->nBlue - pTileData->nGreen) * (int)(nTick - pTileData->nPopTick + 500) / 500;
                        }
                        else
                        {
                            unsigned char* pAlpha = &pTileData->nRed;
                            *pAlpha = pTileData->nBlue;
                            pTileData->dwPopFlags = dwLightFlags & ~2;
                        }
                    }
                    else
                    {
                        unsigned char* pAlpha = &pTileData->nRed;
                        *pAlpha = pTileData->nBlue;
                        pTileData->dwPopFlags = dwLightFlags & ~2;
                    }

                    if (!pTileData->nRed)
                        pTileData->dwFlags |= 0x400;
                    else
                        pTileData->dwFlags &= ~0x400;
                }

                if ((pTileData->dwPopFlags & 4) && nTick >= pTileData->nPopTick)
                {
                    pTileData->dwPopFlags &= ~4;
                    pTileData->dwFlags |= 8;
                }

                if (pTileData->dwFlags & 0x408)
                    continue;

                if (!(pTileData->dwFlags & 0x1C000))
                    continue;

                unsigned int nLights;
                D2LightOffsetsStrc* pOffsets = sub_004DEDB0_GetLightOffsets(pTileData->pTile, &nLights, pTileData->dwPopFlags & 1);
                D2GfxLightStrc tLight;
                for (unsigned int i = 0; i < nLights; ++i)
                {
                    unsigned char nValue0;
                    unsigned char nValue1;
                    unsigned char nValue2;
                    unsigned char nValue3;
                    SCMD_ReadGridCell(pNode->nX + 8 * pOffsets->aOffset[i].nX, pNode->nY + 8 * pOffsets->aOffset[i].nY, &nValue0, &nValue1, &nValue2, &nValue3);
                    nValue0 = nValue0 > 0 ? nValue0 : 0;
                    tLight.aColor[i] = (nValue3 << 24) | (nValue2 << 16) | (nValue1 << 8) | nValue0;
                }

                const unsigned char nAlpha = pTileData->nRed;
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
            SCMD_ReadGridCell(pUnitNode->nX, pUnitNode->nY, &nValue0, &nValue1, &nValue2, &nValue3);
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
        D2SlotStrc* pSlot = &gaSlots[i];
        if (!pSlot->pObject && pSlot->nType == nType && !sub_00515710(pSlot->pSound))
            return pSlot;
    }
    D2SlotStrc* pBest = 0;
    for (int i = 0; i < 16; ++i)
    {
        if (gaSlots[i].nType == nType && gaSlots[i].pObject)
        {
            if (!pBest || sub_004B9DA0_CompareItems(pBest->pObject, gaSlots[i].pObject, 1, 1))
                pBest = &gaSlots[i];
        }
    }
    if (!pBest || !sub_004B9DA0_CompareItems(pObject, pBest->pObject, 0, 0))
        return 0;
    if (pBest->pSound)
    {
        if (pBest->pObject)
// build: symbol ?D2SOUND_GetStreamPosition@* 0x005159B0
            pBest->pObject->f_41 = D2SOUND_GetStreamPosition(pBest->pSound);
// build: symbol ?D2SOUND_StopSound@* 0x00515EE0
        D2SOUND_StopSound(pBest->pSound);
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
    D2SoundsTxt* pFirst = SOUNDHDR_GetSoundRecord(pObject->f_4);
    if (!(pObject->nFlags & 1))
        pObject->f_4 = SOUNDHDR_PickVariant(pObject->f_4);
    D2SlotStrc* pOld = SoundChannelFind(pObject->f_4);
    if (pOld && !pOld->pObject->nField0x3D && pObject->nKey - pOld->pObject->nKey < 2 && pOld->pObject->nPriority >= pObject->nPriority)
        return 0;
    D2SoundsTxt* pRecord = SOUNDHDR_GetSoundRecord(pObject->f_4);
    pFirst->anRecent[1] = pFirst->anRecent[0];
    pFirst->anRecent[0] = pObject->f_4;
    if (!pRecord->bStream && pRecord->nState != 2)
    {
        SOUNDHDR_LoadCacheEntry(pObject->f_4, pRecord->bAsyncOnly == 0, 0);
        if (pRecord->nState != 2)
            return 0;
    }
    if (pRecord->bFailed)
        return 0;
    int nType = 0;
    if (pRecord->bStereo)
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
    D2SOUND_ResetSound(pSlot->pSound);
    if (!pRecord->bStream)
    {
        sub_00515A30(pSlot->pSound, pRecord->nLoop);
        if (pRecord->nBlocks == 1)
            sub_00515A60(pSlot->pSound, pRecord->nBlock[0] * 2);
        if (!D2SOUND_SetSoundData(pSlot->pSound, pRecord->pData, pRecord->nSize))
            return 0;
    }
    pSlot->pObject = pObject;
    if (nType & 4)
    {
        float fValue = pRecord->bReverb ? 1.0f : 0.0f;
        sub_00515B40(pSlot->pSound, fValue);
    }
    pSlot->fAttenuation = 0.0f;
    pSlot->nVolume = -1;
    memset(&pSlot->tPos, 0, sizeof(pSlot->tPos));
    sub_004DFC20_UpdateSoundSlot(pSlot);
    int bOk;
    if (!pRecord->bStream)
    {
        bOk = sub_005156A0(pSlot->pSound);
    }
    else
    {
        char szPath[0x50];
        sub_00482710(pObject->f_4, szPath);
        bOk = D2SOUND_StartSoundStream(pSlot->pSound, szPath, pObject->nField0x24, pRecord->nLoop);
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
        return &gaNpcSounds[0];
    case 0xFE:
        return &gaNpcSounds[1];
    case 0xFC:
        return &gaNpcSounds[2];
    case 0xB0:
        return &gaNpcSounds[3];
    case 0x9A:
        return &gaNpcSounds[5];
    case 0xB1:
        return &gaNpcSounds[6];
    case 0xC7:
        return &gaNpcSounds[7];
    case 0xB2:
        return &gaNpcSounds[8];
    case 0xC8:
        return &gaNpcSounds[9];
    case 0x93:
        return &gaNpcSounds[10];
    case 0xC6:
        return &gaNpcSounds[11];
    case 0x101:
        return &gaNpcSounds[12];
    case 0xFD:
        return &gaNpcSounds[13];
    case 0xC9:
        return &gaNpcSounds[16];
    case 0x96:
        return &gaNpcSounds[17];
    case 0xCA:
        return &gaNpcSounds[18];
    case 0xD2:
        return &gaNpcSounds[19];
    case 0x129:
        return &gaNpcSounds[20];
    case 0xFF:
        return &gaNpcSounds[21];
    case 0x9B:
    case 0xAF:
        return &gaNpcSounds[23];
    case 0x195:
        return &gaNpcSounds[14];
    case 0x92:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0x109:
    case 0x208:
        return &gaNpcSounds[4];
    case 0xFB:
    case 0x209:
        return &gaNpcSounds[22];
    case 0x200:
        return &gaNpcSounds[24];
    case 0x203:
        return &gaNpcSounds[25];
    case 0x202:
        return &gaNpcSounds[28];
    case 0x1FF:
        return &gaNpcSounds[27];
    case 0x201:
        return &gaNpcSounds[26];
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
                const int nCycle = ENVIRONMENT_GetCycleIndexFromAct(gpAct);
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

            nSound = SOUNDHDR_PickVariant(nSound);
        }
        else
        {
            nSound = SOUNDHDR_PickVariant(nSound);
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

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
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
    sub_006488A0_SetDirection(pUnit->pDynamicPath, gaDirection4[gaDirection64To4[UNITS_GetDirectionToCoords(pUnit, nEndX, nEndY) & 0x3F] & 3]);
    sub_004CD540_CreateMissile(&tMissile);
    return 1;
}

#include "gen/data/Source/D2Client/Unknown_004DF1C0.inc"
struct D2SoundStrc;

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
