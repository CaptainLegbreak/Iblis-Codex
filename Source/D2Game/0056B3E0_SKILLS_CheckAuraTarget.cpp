struct D2GameStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

struct D2MonStatsTxt
{
    char unk0x000[0x0C];
    unsigned char nFlags[4];
    char unk0x010[0x1A8 - 0x10];
};

struct D2MissilesTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[4];
    char unk0x008[0x1A4 - 0x08];
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

typedef char M195_CheckUnitFlags[(int)&((D2UnitStrc*)0)->dwFlags == 0xC4 ? 1 : -1];
typedef char M195_CheckUnitMode[(int)&((D2UnitStrc*)0)->dwAnimMode == 0x10 ? 1 : -1];
typedef char M195_CheckMonStatsFlags[(int)&((D2MonStatsTxt*)0)->nFlags == 0x0C ? 1 : -1];
typedef char M195_CheckMissilesFlags[(int)&((D2MissilesTxt*)0)->nFlags == 0x04 ? 1 : -1];

enum
{
    UNIT_MONSTER = 1,
    UNIT_MISSILE = 3,
    UNITFLAG_CANBEATTACKED = 0x00000004,
    UNITFLAG_ISVALIDTARGET = 0x00000008,
    STATE_JUSTHIT = 0x56,
};

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                           // 0x0046ACE0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus);                // 0x00622C40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                      // 0x0063E990
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster);                     // 0x0063E9F0
int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster);                                                   // 0x0063EDC0
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);           // 0x00554DE0
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260

static __forceinline int UNIT_HasFlag_M195(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x0056B3E0
int __fastcall SKILLS_CheckAuraTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nAuraFilter)
{
    D2UnitStrc* pAttacker = pUnit;
    const int nType = pTarget ? pTarget->dwUnitType : 6;

    switch (nType)
    {
    case 0:
    {
        if (!(nAuraFilter & 1))
        {
            return 0;
        }

        const int nMode = pTarget->dwAnimMode;
        if (nAuraFilter & 0x1000)
        {
            if (nMode != 0x11)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x11 || nMode == 0)
            {
                return 0;
            }
        }
        break;
    }
    case 1:
    {
        if (!(nAuraFilter & 2))
        {
            return 0;
        }

        const int nMode = pTarget->dwAnimMode;
        if (nAuraFilter & 0x1000)
        {
            if (nMode != 0x0C)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x0C || nMode == 0)
            {
                return 0;
            }
        }

        if (nAuraFilter & 4 && !MONSTERS_IsUndead(pTarget) || nAuraFilter & 0x4000 && MONSTERS_IsBoss(0, pTarget) || nAuraFilter & 0x40000 && MONSTERS_IsPrimeEvil(pTarget))
        {
            return 0;
        }
        break;
    }
    case 2:
    {
        if (!(nAuraFilter & 0x10))
        {
            return 0;
        }
        break;
    }
    case 3:
    {
        if (!(nAuraFilter & 8))
        {
            return 0;
        }

        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pTarget->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nFlags[0] & gdwBitMasks[1])
        {
            return 0;
        }
        break;
    }
    case 4:
    {
        if (!(nAuraFilter & 0x20))
        {
            return 0;
        }
        break;
    }
    default:
        return 0;
    }

    if (nAuraFilter & 0x80 && !UNIT_HasFlag_M195(pTarget, UNITFLAG_CANBEATTACKED))
    {
        return 0;
    }

    if (nAuraFilter & 0x400 && !UNIT_HasFlag_M195(pTarget, UNITFLAG_ISVALIDTARGET))
    {
        return 0;
    }

    if (nAuraFilter & 0x100 && DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    if (nAuraFilter & 0x10000)
    {
        if (pAttacker && pAttacker->dwUnitType == UNIT_MISSILE)
        {
            D2UnitStrc* pOwner = SUNIT_GetOwner(SUNIT_GetGameFromUnit(pAttacker), pAttacker);
            if (!pOwner)
            {
                return 0;
            }

            pAttacker = pOwner;
        }

        if (!SUNIT_AreUnitsAligned(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pTarget))
        {
            return 0;
        }

        if (pTarget->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
            if (!pMonStatsTxtRecord || pMonStatsTxtRecord->nFlags[1] & gdwBitMasks[0])
            {
                return 0;
            }
        }
    }

    if (nAuraFilter & 0x8000)
    {
        if (pAttacker && pAttacker->dwUnitType == UNIT_MISSILE)
        {
            D2UnitStrc* pOwner = SUNIT_GetOwner(SUNIT_GetGameFromUnit(pAttacker), pAttacker);
            if (!pOwner)
            {
                return 0;
            }

            pAttacker = pOwner;
        }

        if (!sub_00554200(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pTarget))
        {
            return 0;
        }
    }

    if (nAuraFilter & 0x20000)
    {
        if (pAttacker && pAttacker->dwUnitType == UNIT_MISSILE)
        {
            D2UnitStrc* pOwner = SUNIT_GetOwner(SUNIT_GetGameFromUnit(pAttacker), pAttacker);
            if (!pOwner)
            {
                return 0;
            }

            pAttacker = pOwner;
        }

        if (!UNITS_IsInMeleeRange(pAttacker, pTarget, 0))
        {
            return 0;
        }
    }

    if (nAuraFilter & 0x80000 && STATES_CheckState(pTarget, STATE_JUSTHIT))
    {
        return 0;
    }

    if (nAuraFilter & 0x200)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pAttacker);
        if (!pRoom || !UNITS_GetRoom(pTarget))
        {
            return 0;
        }

        D2CoordStrc coords;
        coords.nX = CLIENTS_GetUnitX(pAttacker);
        coords.nY = CLIENTS_GetUnitY(pAttacker);

        D2CoordStrc targetCoords;
        targetCoords.nX = CLIENTS_GetUnitX(pTarget);
        targetCoords.nY = CLIENTS_GetUnitY(pTarget);

        if (COLLISION_RayTrace(pRoom, &coords, &targetCoords, 4))
        {
            return 0;
        }
    }

    return 1;
}
