enum D2C_M106RoomDbgConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

struct D2StaticPathStrc
{
    void* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
int __cdecl sub_004F5140();                                                                                 // 0x004F5140
int __stdcall sub_0061B130_GetCollision(D2ActiveRoomStrc* pRoom, int nX, int nY);                           // 0x0061B130
void __cdecl D2GFX_OutputString(int nXPos, int nYPos, const char* szFormat, ...);                           // 0x004F6890
void __stdcall sub_0045B4F0_DrawRoomCollision(D2ActiveRoomStrc* pRoom);                                     // 0x0045B4F0
void __stdcall sub_0045B5F0(D2ActiveRoomStrc* pRoom);                                                       // 0x0045B5F0

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0045B8B0
void __cdecl sub_0045B8B0_DrawLogicalRoom()
{
    if (sub_004F5140() == 3)
        return;

    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    int nX = UNITS_GetXPositionInline(pPlayer);
    int nY = UNITS_GetYPositionInline(pPlayer);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    D2GFX_OutputString(10, 0x37, "Logical Room->%d", sub_0061B130_GetCollision(pRoom, nX, nY));
    sub_0045B4F0_DrawRoomCollision(pRoom);
    sub_0045B5F0(pRoom);
}
