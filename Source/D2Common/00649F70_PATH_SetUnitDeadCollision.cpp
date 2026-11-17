typedef int BOOL;

#define UNIT_MONSTER 1
#define COLLIDE_CORPSE 0x8000
#define COLLISION_PATTERN_SMALL_NO_PRESENCE 5
#define PATH_CORPSE_SIZE 3

struct D2ActiveRoomStrc;

#pragma pack(push, 1)
struct D2DynamicPathStrc
{
    unsigned short wOffsetX;
    unsigned short wPosX;
    unsigned short wOffsetY;
    unsigned short wPosY;
    int dwClientCoordX;
    int dwClientCoordY;
    char unk0x10[0x0C];
    D2ActiveRoomStrc* pRoom;
    char unk0x20[0x28];
    unsigned int dwCollisionPattern;
};
#pragma pack(pop)

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    D2DynamicPathStrc* pDynamicPath;
};

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);           // 0x00648C30
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit);                                        // 0x00649400
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce);                          // 0x00649560
void __stdcall COLLISION_SetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064DE30
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pPath);                                          // 0x00650590

void __stdcall D2Common_10228(D2UnitStrc* pUnit)
{
    if (pUnit->pDynamicPath)
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
    }
}

// 0x00649F70
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, BOOL bForGameLogic)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (bForGameLogic || pUnit->dwUnitType != UNIT_MONSTER)
    {
        D2Common_10228(pUnit);
        COLLISION_SetMaskWithSizeXY(pPath->pRoom, pPath->wPosX, pPath->wPosY, PATH_CORPSE_SIZE, PATH_CORPSE_SIZE, COLLIDE_CORPSE);
    }
    else
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
        pUnit->pDynamicPath->dwCollisionPattern = COLLISION_PATTERN_SMALL_NO_PRESENCE;
        PATH_SetFootprintCollisionMask(pPath, COLLIDE_CORPSE);
        PATH_AddCollisionFootprintForUnit(pUnit);
    }
    PATH_RecacheRoomIfNeeded(pPath);
}
