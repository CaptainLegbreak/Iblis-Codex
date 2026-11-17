struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
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
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x0C];
    unsigned int dwSeqSpeed;
    char unk0x40[0x84];
    unsigned int dwFlags;
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648780
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660

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

// 0x004E0A30
int __fastcall sub_004E0A30_CltDoClearSeqSpeed(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    pUnit->dwSeqSpeed = 0;
    return 1;
}

// 0x004E0BD0
int __fastcall sub_004E0BD0_CltStartClearCollision(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~0x0E;
    }

    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), 5, 0x1000);
    return 1;
}

// 0x004E0EB0
int __fastcall sub_004E0EB0_CltStartPathToTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!sub_004648F0_GetTargetUnit(pUnit))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    PATH_SetNewDistance(pPath, 5);
    PATH_SetType(pPath, 2);
    D2Common_10142(pPath, pUnit, 0);
    if (PATH_GetNumberOfPathPoints(pPath) <= 0)
    {
        PATH_SetType(pPath, 1);
        D2Common_10142(pPath, pUnit, 0);
        if (PATH_GetNumberOfPathPoints(pPath) <= 0)
        {
            return 0;
        }
    }

    SKILLS_SetFlags(pSkill, 1);
    return 1;
}
