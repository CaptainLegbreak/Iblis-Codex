struct D2UnitStrc;

struct D2UnkDamageRecordStrc
{
    int unk0x00[3];
    int nValue;
};

#define STAT_ITEM_DEMONDAMAGE_PERCENT 121

int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster);                                                       // 0x0063E940
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500

// 0x0057B630
static void __stdcall sub_0057B630_AddDemonDamage(D2UnitStrc* pAttacker, D2UnitStrc* pTarget, D2UnkDamageRecordStrc* pRecord)
{
    if (MONSTERS_IsDemon(pTarget))
    {
        const int nBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
        if (nBonus > 0)
        {
            pRecord->nValue += nBonus;
        }
    }
}

void __fastcall sub_K11_Emit0057B630(D2UnitStrc* pAttacker, D2UnitStrc* pTarget, D2UnkDamageRecordStrc* pRecord)
{
    sub_0057B630_AddDemonDamage(pAttacker, pTarget, pRecord);
}
