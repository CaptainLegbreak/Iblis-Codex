struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2SkillStrc;
struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int nTargetX;
    int nTargetY;
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
};
typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);
struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc*, int, int); // 0x00463740
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char); // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char, int*, int*); // 0x0063E7E0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
unsigned char __stdcall sub_00648810(D2DynamicPathStrc*); // 0x00648810
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc*); // 0x006505C0

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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
static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// 0x005CE4F0
D2UnitStrc* __fastcall SKILLS_CreateSpiderLayMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pMissile = 0;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pPath && sub_006505C0_TestPathFlag8(pPath))
    {
        int nXOffset;
        int nYOffset;
        {
            unsigned char spiderLayDirections[8] = { 10, 8, 22, 20, 18, 16, 14, 12 };
            const unsigned char nLayDirection = spiderLayDirections[sub_0063E7A0_GetByteTableEntry(sub_00648810(pPath))];
            sub_0063E7E0_GetDirectionDelta(nLayDirection, &nXOffset, &nYOffset);
        }
        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 173), 1);
        const int nUnitX = UNITS_GetXPositionInline(pUnit);
        const int nUnitY = UNITS_GetYPositionInline(pUnit);
        const int nX = nUnitX + nXOffset;
        const int nY = nUnitY + nYOffset;
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = pUnit;
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nTargetX = nX + 2 * nXOffset;
        missileParams.nTargetY = nY + 2 * nYOffset;
        missileParams.nVelocity = 3;
        missileParams.nSkill = 173;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.nMissile = 143;
        pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
    return pMissile;
}
