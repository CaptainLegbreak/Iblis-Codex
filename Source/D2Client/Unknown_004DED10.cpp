#include "D2Client.h"
#include "D2DrlgMaps.h"
#include "D2ClientUi.h"

struct D2SlotObjectStrc;
struct D2SlotStrc;
struct D2HintCursorStrc;
struct D2Obj007C8A28Strc;
struct D2TileLibraryEntryStrc;
struct D2GfxLightStrc;
struct D2LightOffsetStrc;
struct D2LightOffsetsStrc;
struct D2TileLightNodeStrc;
struct D2TileLightEntryStrc;
struct D2TileLightCtxStrc;

#pragma pack(push, 1)
struct D2SlotObjectStrc
{
    char unk0x00[0x04];
    int f_4;
    char unk0x08[0x24];
    int nField0x2C;
    int nField0x30;
    unsigned int nKey;
    char unk0x38[0x09];
    unsigned int f_41;
};

#pragma pack(pop)

struct D2Obj007C8A28Strc
{
    void sub_004DE730(void* pArg);                                                                          // 0x004DE730
};

extern int gdwGlobal_007C8C78; // 0x007C8C78
D2HintCursorStrc* __fastcall sub_00481860(int nId); // 0x00481860
int __fastcall sub_00515710(D2SoundStrc* pSound); // 0x00515710
int __fastcall D2SOUND_IsSoundBufferPlaying(D2SoundStrc* pSound); // 0x00515740
int __fastcall sub_00515C30(D2SoundStrc* pSound); // 0x00515C30
void __fastcall D2SOUND_DestroySound(D2SoundStrc* pSound); // 0x005160D0

struct D2TileLightNodeStrc
{
    int unk0x00;
    int nX;
    int nY;
    D2DrlgTileDataStrc* pTileData;
    D2TileLightNodeStrc* pNext;
};

struct D2TileLightEntryStrc
{
    int unk0x00[8];
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
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall SCMD_ReadGridCell(int nX, int nY, unsigned char* pValue0, unsigned char* pValue1, unsigned char* pValue2, unsigned char* pValue3); // 0x00475AA0
int __stdcall TILE_TileDrawTrans(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha); // 0x004F6950
int __stdcall TILE_TileDrawLit(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels); // 0x004F6920

D2Obj007C8A28Strc gObj_007C8A28; // 0x007C8A28

D2SlotStrc gaSlots_007C8A78[16]; // 0x007C8A78

// 0x004DED10
void __fastcall sub_004DED10(void* pArg)
{
    gObj_007C8A28.sub_004DE730(pArg);
}

// 0x004DF7B0
void __fastcall sub_004DF7B0_StopSlot(D2SlotStrc* pSlot)
{
    if (pSlot->pSound)
    {
        if (pSlot->pObject)
        {
// build: symbol ?D2SOUND_GetStreamPosition@* 0x005159B0
            pSlot->pObject->f_41 = D2SOUND_GetStreamPosition(pSlot->pSound);
        }

// build: symbol ?D2SOUND_StopSound@* 0x00515EE0
        D2SOUND_StopSound(pSlot->pSound);
    }

    if (pSlot->pObject)
    {
        pSlot->pObject->nField0x30 = 2;
        pSlot->pObject->nField0x2C = 0;
        pSlot->pObject = 0;
    }
}

// 0x004DF800
void __cdecl sub_004DF800()
{
    if (!sub_00513B50())
    {
        return;
    }

// build: symbol ?D2SOUND_SetMasterVolume@* 0x00515CE0
    D2SOUND_SetMasterVolume(0);
    for (int i = 0; i < 16; ++i)
    {
        sub_004DF7B0_StopSlot(&gaSlots_007C8A78[i]);
    }

    D2SOUND_SetMasterVolume(0xFF);
}

// 0x004DF890
void __cdecl sub_004DF890()
{
    for (int i = 0; i < 16; ++i)
    {
        D2SlotStrc* pSlot = &gaSlots_007C8A78[i];
        if (pSlot->pObject && !sub_00481860(pSlot->pObject->f_4)->bFlag3E && !sub_00515710(pSlot->pSound))
        {
            if (sub_00515C30(pSlot->pSound))
            {
                sub_004DF7B0_StopSlot(pSlot);
            }

            if (pSlot->pObject)
            {
                pSlot->pObject->nField0x30 = 2;
                pSlot->pObject->nField0x2C = 0;
                pSlot->pObject = 0;
            }
        }
    }
}

// 0x004DFA40
int __fastcall sub_004DFA40_IsSlotPlaying(D2SlotStrc* pSlot)
{
    if (pSlot && pSlot->pSound)
    {
        return D2SOUND_IsSoundBufferPlaying(pSlot->pSound);
    }

    return 0;
}

// 0x004DFA60
void __cdecl sub_004DFA60()
{
    if (gdwGlobal_007C8C78)
    {
        sub_004DF800();
        for (int i = 0; i < 16; ++i)
        {
            D2SOUND_DestroySound(gaSlots_007C8A78[i].pSound);
            gaSlots_007C8A78[i].pSound = 0;
        }

        gdwGlobal_007C8C78 = 0;
    }
}

// 0x004DEDB0
static D2LightOffsetsStrc* __stdcall sub_004DEDB0_GetLightOffsets(D2TileLibraryEntryStrc* pTile, unsigned int* pCount, int bAlternate)
{
    *pCount = gaLightSampleCounts_006DB9D8[pTile->nLightDirection];
    if (bAlternate)
        return &gaLightOffsetsA_0072ABC8[pTile->nLightDirection];
    return &gaLightOffsetsB_0072A9E8[pTile->nLightDirection];
}

// 0x004DEDF0
static void __stdcall sub_004DEDF0_UpdateTileLights(D2TileLightEntryStrc* pEntry, D2TileLightCtxStrc* pCtx)
{
    if (!pEntry->pList)
        return;

    const int nScreenPanels = sub_0045AE90();
    const int bPerspective = sub_004F51D0_IsPerspective();
    const unsigned int nTick = GetTickCount();
    for (D2TileLightNodeStrc* pNode = pEntry->pList; pNode; pNode = pNode->pNext)
    {
        D2DrlgTileDataStrc* pTileData = pNode->pTileData;
        if ((pTileData->dwPopFlags & 4) && nTick >= pTileData->nPopTick)
        {
            pTileData->dwPopFlags &= ~4;
            pTileData->dwFlags |= 8;
        }

        if (pTileData->dwFlags & 0x408)
            continue;

        if (!(pTileData->dwFlags & 0x1C000))
            continue;

        unsigned int nCount;
        D2LightOffsetsStrc* pOffsets = sub_004DEDB0_GetLightOffsets(pTileData->pTile, &nCount, pTileData->dwPopFlags & 1);
        D2GfxLightStrc tLight;
        for (unsigned int i = 0; i < nCount; ++i)
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

// 0x004DF480
void __fastcall sub_004DF480_UpdateAllTileLights(D2TileLightCtxStrc* pCtx)
{
    int nCount = pCtx->nSize * pCtx->nSize;
    D2TileLightEntryStrc* pEntry = pCtx->pEntries;
    while (nCount--)
    {
        sub_004DEDF0_UpdateTileLights(pEntry, pCtx);
        ++pEntry;
    }
}

#include "gen/data/Source/D2Client/Unknown_004DED10.inc"
