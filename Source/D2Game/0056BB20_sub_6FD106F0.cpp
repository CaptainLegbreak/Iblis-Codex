struct D2GameStrc;
struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    unsigned int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

struct D2_6FD106F0_Strc
{
    D2UnitStrc* pUnit;
    int nDistance;
    int nX;
    int nY;
    int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*);
};

struct D2_6FD10880_Strc
{
    D2UnitStrc* unk0x00;
    unsigned int unk0x04;
    D2UnitStrc* unk0x08;
    unsigned int unk0x0C;
    unsigned int unk0x10;
    int unk0x14;
};

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x0056BB20
int __fastcall sub_6FD106F0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2_6FD106F0_Strc* pArgs = (D2_6FD106F0_Strc*)pAuraCallback->pArgs;

    if (!pArgs->pCallback || pArgs->pCallback(pAuraCallback->pGame, pUnit))
    {
        const int nXDiff = CLIENTS_GetUnitXInline(pUnit) - pArgs->nX;
        const int nYDiff = CLIENTS_GetUnitYInline(pUnit) - pArgs->nY;

        const int nDistance = nXDiff * nXDiff + nYDiff * nYDiff;
        if (nDistance < pArgs->nDistance)
        {
            pArgs->nDistance = nDistance;
            pArgs->pUnit = pUnit;
        }

        return 1;
    }

    return 0;
}

// 0x0056BCD0
int __fastcall sub_6FD10880(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2_6FD10880_Strc* pArgs = (D2_6FD10880_Strc*)pAuraCallback->pArgs;

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;

    if ((unsigned int)nUnitGUID <= pArgs->unk0x10 || (unsigned int)nUnitGUID >= pArgs->unk0x04)
    {
        if ((unsigned int)nUnitGUID <= pArgs->unk0x0C)
        {
            pArgs->unk0x0C = nUnitGUID;
            pArgs->unk0x08 = pUnit;
        }
        ++pArgs->unk0x14;
    }
    else
    {
        pArgs->unk0x04 = nUnitGUID;
        pArgs->unk0x00 = pUnit;
        ++pArgs->unk0x14;
    }

    return 1;
}
