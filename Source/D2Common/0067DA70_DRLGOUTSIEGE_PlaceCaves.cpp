struct D2LvlPrestTxt;

struct D2DrlgOutdoorInfoStrc
{
    char unk0x00[0x5C];
    int nGridWidth;
    int nGridHeight;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x18[0x0C];
    int nWidth;
    int nHeight;
    char unk0x2C[0x1A4];
    int nLevelId;
};

struct D2DrlgOutSiegeInitStrc
{
    int nLevelId;
    int field_4;
    int field_8;
    int nLevelPrestId1;
    int nLevelPrestId2;
};

extern const D2DrlgOutSiegeInitStrc gaOutSiegeCaves[3];                                                     // 0x006F1F9C
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLevelPrestId);                                  // 0x0061F0B0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nDirection, int a6); // 0x006743C0
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel);                                  // 0x00675770
void __stdcall sub_0067E160(D2DrlgLevelStrc* pLevel);                                         // 0x0067E160

// 0x0067DA70
static void DRLGOUTSIEGE_PlaceCaves(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    for (int i = 0; i < 3; ++i)
    {
        if (pLevel->nLevelId == gaOutSiegeCaves[i].nLevelId)
        {
            int nLevelPrestId;
            int nX;
            int nY;
            if (pLevel->nWidth > pLevel->nHeight)
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId2;
                DATATBLS_GetLvlPrestTxtRecord(nLevelPrestId);
                nX = gaOutSiegeCaves[i].field_8 ? pOutdoors->nGridWidth - 2 : 0;
                nY = 2;
            }
            else
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId1;
                DATATBLS_GetLvlPrestTxtRecord(nLevelPrestId);
                nX = 2;
                nY = gaOutSiegeCaves[i].field_8 ? pOutdoors->nGridHeight - 2 : 0;
            }
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nLevelPrestId, gaOutSiegeCaves[i].field_4, 0);
        }
    }
}

void __fastcall sub_M170_Emit_0067DA70(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nLevelId == 110)
    {
        DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
        return;
    }
    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    sub_0067E160(pLevel);
    DRLGOUTSIEGE_PlaceCaves(pLevel);
    if (pLevel->nLevelId == 111)
    {
        DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    }
    sub_0067E160(pLevel);
}

#include "gen/data/Source/D2Common/0067DA70_DRLGOUTSIEGE_PlaceCaves.inc"
