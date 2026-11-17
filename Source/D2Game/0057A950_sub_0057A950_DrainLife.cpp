#define STAT_HITPOINTS 6
#define DRAIN_MIN 256

struct D2UnitStrc;

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

// 0x0057A950
static __forceinline void sub_0057A950_DrainLife(D2UnitStrc* pUnit, int nDrain)
{
    if (nDrain > 0)
    {
        int nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) - nDrain;
        if (nLife < DRAIN_MIN)
        {
            nLife = 0;
        }
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nLife, 0);
    }
}

void __fastcall sub_M120_Emit_0057A950(D2UnitStrc* pUnit, int nDrain)
{
    sub_0057A950_DrainLife(pUnit, nDrain);
}
