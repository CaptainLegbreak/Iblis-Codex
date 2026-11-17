struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};

int __stdcall sub_004DA0F0_GetUnitGfxOffsetZ(D2UnitStrc* pUnit);                                            // 0x004DA0F0
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit);                                     // 0x004DA690
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode);                                      // 0x00649190
void __stdcall COLLISION_SetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);            // 0x0064CB90
void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);          // 0x0064CBE0

static __forceinline int sub_J10_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_J10_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004AFCE0
static __declspec(noinline) void sub_004AFCE0_UpdateCollisionForMode(D2UnitStrc* pUnit, int nMode)
{
    if (nMode == 12)
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~14;
        }
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
        if (sub_004DA0F0_GetUnitGfxOffsetZ(pUnit))
        {
            return;
        }
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA690_ReplaceMotionFlag1With8(pUnit);
        sub_004DA6E0_SetMotionFlag20(pUnit, 1);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, 2, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0xA0, 0);
    }
    else if (nMode == 14 || nMode == 10)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 14;
        }
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 1);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x3C01);
        if (!sub_004DA0F0_GetUnitGfxOffsetZ(pUnit))
        {
            return;
        }
        sub_004DA690_ReplaceMotionFlag1With8(pUnit);
        sub_004DA6E0_SetMotionFlag20(pUnit, 0);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, -8, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0, 0);
    }
}

void __fastcall sub_J10_Emit_004AFCE0(D2UnitStrc* pUnit, int nMode, int nOtherMode)
{
    sub_004AFCE0_UpdateCollisionForMode(pUnit, nMode);
    sub_004AFCE0_UpdateCollisionForMode(pUnit, nOtherMode);
}
