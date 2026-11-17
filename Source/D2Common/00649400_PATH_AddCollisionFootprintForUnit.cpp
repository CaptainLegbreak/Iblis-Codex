struct D2ActiveRoomStrc;

struct D2DynamicPathStrc
{
    char unk0x00[0x48];
    int dwCollisionPattern;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10 - 0x04];
    int dwAnimMode;
    char unk0x14[0x2C - 0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit);                                                   // 0x006209D0
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit);                                                        // 0x006205A0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_HasCollision(D2UnitStrc* pUnit);                                                        // 0x006219C0
void __stdcall COLLISION_SetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064DE30
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EA00
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EBA0
void __stdcall COLLISION_ResetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064DC00
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

inline int __fastcall UNITS_GetXPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int __fastcall UNITS_GetYPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00649400
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    switch (nType)
    {
    case 0:
    case 1:
    {
        const int nCollisionPattern = pUnit->pDynamicPath->dwCollisionPattern;
        COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), nCollisionPattern, UNITS_GetCollisionMask(pUnit));
        break;
    }

    case 2:
        COLLISION_SetMaskWithSizeXY(UNITS_GetRoom(pUnit), UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
        break;

    default:
        COLLISION_SetMaskWithSize(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetCollisionMask(pUnit));
        break;
    }
}

// 0x00649560
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    switch (nType)
    {
    case 0:
        if ((pUnit && pUnit->dwAnimMode != 17 && pUnit->dwAnimMode != 0) || bForce)
        {
ResetPattern:
            const int nCollisionPattern = pUnit->pDynamicPath->dwCollisionPattern;
            COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), nCollisionPattern, UNITS_GetCollisionMask(pUnit));
            return 1;
        }
        break;

    case 1:
        if ((pUnit && pUnit->dwAnimMode != 12 && pUnit->dwAnimMode != 0) || bForce)
        {
            goto ResetPattern;
        }
        break;

    case 2:
        if (UNITS_HasCollision(pUnit) || bForce)
        {
            COLLISION_ResetMaskWithSizeXY(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
            return 1;
        }
        break;

    default:
        COLLISION_ResetMaskWithSize(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetCollisionMask(pUnit));
        return 1;
    }

    return 0;
}
