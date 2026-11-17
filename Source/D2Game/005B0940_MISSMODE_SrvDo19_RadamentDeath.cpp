struct D2GameStrc;
struct D2DynamicPathStrc;

enum D2C_UnitTypes
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};

void __fastcall sub_0056DDE0_FillRecordAndCall(D2GameStrc* pGame, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, void* pArg8); // 0x0056DDE0
int __fastcall MISSMODE_RadamentDeathAreaEffectCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused); // 0x005AD8F0
int __fastcall MISSMODE_RadamentDeathAreaEffectCallbackFirstFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused); // 0x005AD910
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile);                   // 0x005AE1F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                        // 0x0064A380

static __forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005B0940
int __fastcall MISSMODE_SrvDo19_RadamentDeath(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    const int nCurrentFrame = sub_0064A380_GetRemainingFrames(pMissile);
    if (nCurrentFrame > 1 && nCurrentFrame < 25)
    {
        sub_0056DDE0_FillRecordAndCall(pGame, 0x3002, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), (int)pMissile, 124, 1, (void*)MISSMODE_RadamentDeathAreaEffectCallback);
    }
    else if (nCurrentFrame == 1)
    {
        sub_0056DDE0_FillRecordAndCall(pGame, 0x3002, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), (int)pMissile, 124, 1, (void*)MISSMODE_RadamentDeathAreaEffectCallbackFirstFrame);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}
