struct D2ObjectControlStrc;
struct D2DynamicPathStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

struct D2ShrinesTxt
{
    unsigned char nCode;
    char unk0x01[0x03];
    int dwArg0;
    int dwArg1;
    int dwDurationInFrames;
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2UnitStrc* __stdcall UNITFINDS_GetNearestTestedUnit(D2UnitStrc* pUnit, int nX, int nY, int nSize, int (__fastcall* pfnUnitTest)(D2UnitStrc*, D2UnitStrc*)); // 0x0065A800
int __fastcall sub_6FC76F60(D2UnitStrc* pMonster, D2UnitStrc* pUnit1);                                      // 0x00582750
void __fastcall sub_005A4940_PromoteToUnique(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x005A4940

static __forceinline int CLIENTS_GetUnitX_Shrine(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitY_Shrine(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00583050
void __fastcall D2GAME_SHRINES_Monster_6FC76ED0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2UnitStrc* pMonster = UNITFINDS_GetNearestTestedUnit(pOp->pPlayer, CLIENTS_GetUnitX_Shrine(pOp->pPlayer), CLIENTS_GetUnitY_Shrine(pOp->pPlayer), 0, sub_6FC76F60);
    if (pMonster)
    {
        sub_005A4940_PromoteToUnique(pOp->pGame, pMonster);
    }
}
