struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2SkillStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int unk0x04[10];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

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
    void* pInitFunc;
    int pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                 // 0x00681EF0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAt(D2ActiveRoomStrc* pRoom, int nX, int nY);              // 0x00463740
void __fastcall sub_004B9A00(int nId, D2UnitStrc* pUnit, int nArg3, int nArg4, int nArg5);                  // 0x004B9A00
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(int nIndex);                                         // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY);                  // 0x0063E7E0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                                  // 0x00648810
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                         // 0x006505C0

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x004E2D40
D2UnitStrc* __fastcall sub_004E2D40_UpdateState22(D2UnitStrc* pUnit)
{
    int nX;
    int nY;
    D2UnitStrc* pMissile = 0;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pPath && sub_006505C0_TestPathFlag8(pPath))
    {
        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0xAD), 1);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        nX = UNITS_GetUnitXPosition(pUnit);
        nY = UNITS_GetUnitYPosition(pUnit);

        unsigned char aDirections[8];
        aDirections[0] = 10;
        aDirections[1] = 8;
        aDirections[2] = 22;
        aDirections[3] = 20;
        aDirections[4] = 18;
        aDirections[5] = 16;
        aDirections[6] = 14;
        aDirections[7] = 12;
        const unsigned char nDirection = aDirections[sub_0063E7A0_GetByteTableEntry(PATH_GetDirection(pPath))];

        int nDeltaX;
        int nDeltaY;
        sub_0063E7E0_GetDirectionDelta(nDirection, &nDeltaX, &nDeltaY);
        const int nSpawnX = nX + nDeltaX;
        const int nSpawnY = nY + nDeltaY;
        if (!DUNGEON_IsRoomInTown(sub_00463740_FindRoomAt(pRoom, nSpawnX, nSpawnY)))
        {
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.dwFlags = 0x25;
            tParams.pOwner = pUnit;
            tParams.nX = nSpawnX;
            tParams.nY = nSpawnY;
            tParams.nTargetX = nSpawnX + 2 * nDeltaX;
            tParams.nTargetY = nSpawnY + 2 * nDeltaY;
            tParams.nVelocity = 3;
            tParams.nSkillLevel = nSkillLevel;
            tParams.nMissile = 0x8F;
            pMissile = sub_004CD540_CreateMissile(&tParams);
            sub_004B9A00(0x726, pUnit, 0, 0, 0);
        }
    }

    return pMissile;
}
