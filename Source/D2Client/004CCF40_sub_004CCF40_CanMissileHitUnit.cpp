struct D2UnitStrc
{
    int dwUnitType;
    int unk0x04[48];
    unsigned int dwFlags;
};

struct D2MissilesTxt
{
    char unk0x000[0x187];
    unsigned char nCollideFriend;
    unsigned char nNextHit;
};

struct D2CltMissileFindArgStrc
{
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    D2MissilesTxt* pMissilesTxtRecord;
};

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit);                            // 0x0064A470
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define UNIT_ALIGNMENT_GOOD 2

inline int UNITS_IsValidTargetInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 3) & 1;
    return bResult;
}

inline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 2) & 1;
    return bResult;
}

// 0x004CCF40
static int __stdcall sub_004CCF40_CanMissileHitUnit(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pOwner, D2MissilesTxt* pMissilesTxtRecord)
{
    if (!UNITS_IsValidTargetInline(pUnit))
        return 0;

    if (!UNITS_CanBeAttackedInline(pUnit))
        return 0;

    if (pMissilesTxtRecord->nNextHit && STATES_CheckState(pUnit, 0x56))
        return 0;

    if (MISSILE_CheckUnitIfOwner(pMissile, pUnit))
        return 0;

    if (pOwner && !sub_00465C60_CheckUnitPair(pOwner, pUnit) && !pMissilesTxtRecord->nCollideFriend)
        return 0;

    return 1;
}

// 0x004CCFB0
int __fastcall sub_004CCFB0_CltCanCollideWithMonster(D2UnitStrc* pUnit, D2CltMissileFindArgStrc* pArg)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    return sub_004CCF40_CanMissileHitUnit(pUnit, pArg->pMissile, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x004CCFE0
int __fastcall sub_004CCFE0_CltCanCollideWithGoodAlignmentUnit(D2UnitStrc* pUnit, D2CltMissileFindArgStrc* pArg)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_GOOD)
        return 1;

    if (nUnitType != UNIT_PLAYER)
        return 0;

    return sub_004CCF40_CanMissileHitUnit(pUnit, pArg->pMissile, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x004CD020
int __fastcall sub_004CD020_CltCanCollideWithPlayerOrMonster(D2UnitStrc* pUnit, D2CltMissileFindArgStrc* pArg)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER && nUnitType != UNIT_MONSTER)
        return 0;

    return sub_004CCF40_CanMissileHitUnit(pUnit, pArg->pMissile, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}
