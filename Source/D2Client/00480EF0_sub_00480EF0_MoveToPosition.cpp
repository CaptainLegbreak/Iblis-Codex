struct D2DynamicPathStrc;

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
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};

struct D2UnitTargetStrc
{
    int nParam1;
    int nParam2;
    int unk0x08[5];
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5

#define D2_ABS(n) ((n) < 0 ? -(n) : (n))

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode);                                     // 0x0046C140
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nMode, int nTargetX, int nTargetY); // 0x004804E0
int __fastcall sub_00480C10_DispatchUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00480C10
extern "C" void __stdcall sub_00648750(D2DynamicPathStrc* pDynamicPath, int bSet);                         // 0x00648750

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00480EF0
void __fastcall sub_00480EF0_MoveToPosition(D2UnitStrc* pUnit, int nX, int nY, int bSetPosition)
{
    int bMove = 0;
    int nDiff = nX - UNITS_GetUnitXPosition(pUnit);
    if (D2_ABS(nDiff) > 1)
    {
        bMove = 1;
    }
    nDiff = nY - UNITS_GetUnitYPosition(pUnit);
    if (D2_ABS(nDiff) > 1)
    {
        bMove = 1;
    }

    const int nType = pUnit->dwUnitType;
    if ((nType != UNIT_MONSTER || sub_0046C140_TestMonModeFlag(pUnit->dwClassId, 2)) && bMove)
    {
        D2UnitTargetStrc tTarget;
        tTarget.nParam1 = nX;
        tTarget.nParam2 = nY;
        int nCommand = 1;
        switch (nType)
        {
        case UNIT_PLAYER:
            if (pUnit != sub_00463DE0_GetPlayerUnit())
            {
                if (bSetPosition)
                {
                    sub_004804E0_SetPosition(pUnit, nX, nY, 2, 0, 0);
                    return;
                }
                nCommand = 0x17;
            }
            break;

        case UNIT_MONSTER:
            tTarget.unk0x08[1] = 1;
            break;
        }
        tTarget.unk0x08[2] = 100;
        tTarget.unk0x08[3] = 15;
        sub_00480C10_DispatchUnitCommand(nCommand, pUnit, &tTarget, 0);
    }
    else
    {
        sub_00648750(pUnit->pDynamicPath, 0);
    }
}
