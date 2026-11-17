struct D2GameStrc;
struct D2DamageStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
};

#define UNITFLAG_ISMERC 0x00000200
#define UNITFLAG_NOTC 0x00020000

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                 // 0x00552FD0

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005AD3A0
void __fastcall MISSMODE_SrvDmg06_MarkTargetNoTreasureClass(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pOwner && !UNIT_HasFlag(pOwner, UNITFLAG_ISMERC) && pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_NOTC;
    }
}
