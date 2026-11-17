struct D2DynamicPathStrc;
struct D2MonStatsTxt;

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
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0xA0];
    int dwNodeIndex;
};

struct D2TargetNodeStrc
{
    D2UnitStrc* pUnit;
    int nNodeData;
    D2TargetNodeStrc* pNext;
    D2TargetNodeStrc* pPrevious;
};

struct D2GameStrc
{
    char unk0x0000[0x10F8];
    D2TargetNodeStrc* pTargetNodes[10];
};

struct D2AiControlStrc
{
    int nAiSpecialState;
};

enum
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
int __fastcall UNITS_CanSwitchAI(int nMonsterId);                                                           // 0x00623470

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
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

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
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

// 0x005B0BD0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    const int nXDiff = CLIENTS_GetUnitX(pUnit1) - CLIENTS_GetUnitX(pUnit2);
    const int nYDiff = CLIENTS_GetUnitY(pUnit1) - CLIENTS_GetUnitY(pUnit2);

    return nXDiff * nXDiff + nYDiff * nYDiff;
}

// 0x005B0D60
int __fastcall AITHINK_GetSpecialStateFromAiControl(D2AiControlStrc* pAiControl)
{
    return pAiControl->nAiSpecialState;
}

// 0x005B0DA0
int __fastcall AITHINK_CanUnitSwitchAi(D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, int nAiSpecialState, int bCheckIfSuperUnique)
{
    if (nAiSpecialState == 0)
    {
        return 1;
    }

    if (nAiSpecialState != 10 && nAiSpecialState != 11 && nAiSpecialState != 12)
    {
        return 1;
    }

    if (bCheckIfSuperUnique && MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 2))
    {
        return 0;
    }

    if (!pUnit)
    {
        return UNITS_CanSwitchAI(-1);
    }

    return UNITS_CanSwitchAI(pUnit->dwClassId);
}

// 0x005B1BC0
D2TargetNodeStrc* __fastcall sub_005B1BC0_FindTargetNode(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    if (!pGame || !pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return 0;
    }

    const int nNodeIndex = pUnit->dwNodeIndex;
    if (nNodeIndex == 11)
    {
        return 0;
    }

    for (D2TargetNodeStrc* pNode = pGame->pTargetNodes[nNodeIndex]; pNode; pNode = pNode->pNext)
    {
        if (pNode->pUnit == pUnit)
        {
            return pNode;
        }
    }

    return 0;
}
