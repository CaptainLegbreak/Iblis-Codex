struct D2DrlgStrc;
struct D2DrlgOrthStrc;

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgOutdoorInfoStrc
{
    char unk0x000[0x264];
    D2DrlgOrthStrc* pRoomData;
};

struct D2DrlgLevelStrc
{
    int nDrlgType;
    char unk0x004[0x10];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x018[0x04];
    D2DrlgCoordStrc pLevelCoords;
    char unk0x02C[0x188];
    D2DrlgStrc* pDrlg;
};

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset); // 0x0066B790

#define DRLGTYPE_PRESET 2

// 0x00677640
static __forceinline void sub_00677640_AddOrthToLevel(D2DrlgLevelStrc* pLevel, int nLevelId)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgLevelStrc* pWarpLevel = DRLG_GetLevel(pLevel->pDrlg, nLevelId);
    const int nDirection = DRLG_GetDirectionFromCoordinates(&pLevel->pLevelCoords, &pWarpLevel->pLevelCoords);
    DRLGROOM_AddOrth(&pOutdoors->pRoomData, pWarpLevel, nDirection, pWarpLevel->nDrlgType == DRLGTYPE_PRESET);
}

void __fastcall sub_M293_Emit_00677640(D2DrlgLevelStrc* pLevel, int nLevelId)
{
    sub_00677640_AddOrthToLevel(pLevel, nLevelId);
}
