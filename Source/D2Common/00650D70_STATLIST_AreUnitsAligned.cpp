struct D2UnitStrc;

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0

#define UNIT_ALIGNMENT_EVIL 0
#define UNIT_ALIGNMENT_NEUTRAL 1
#define UNIT_ALIGNMENT_GOOD 2
#define TRUE 1
#define FALSE 0

// 0x00650D70
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    if (pUnit1 && pUnit2)
    {
        if (pUnit1 == pUnit2)
        {
            return TRUE;
        }

        const int nAlignment1 = STATLIST_GetUnitAlignment(pUnit1);
        const int nAlignment2 = STATLIST_GetUnitAlignment(pUnit2);

        switch (nAlignment1)
        {
        case UNIT_ALIGNMENT_EVIL:
            if (nAlignment2 == UNIT_ALIGNMENT_GOOD || nAlignment2 == UNIT_ALIGNMENT_NEUTRAL)
            {
                return FALSE;
            }

            if (nAlignment2 == UNIT_ALIGNMENT_EVIL)
            {
                return TRUE;
            }
            break;

        case UNIT_ALIGNMENT_NEUTRAL:
            return FALSE;

        case UNIT_ALIGNMENT_GOOD:
            if (nAlignment2 == UNIT_ALIGNMENT_GOOD)
            {
                return TRUE;
            }
            break;
        }
    }

    return FALSE;
}
