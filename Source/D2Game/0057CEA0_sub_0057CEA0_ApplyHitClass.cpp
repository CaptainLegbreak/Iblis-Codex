struct D2UnitStrc;

struct D2DamageStrc
{
    char unk0x00[0x60];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
};

int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit);                                                        // 0x00623C20

// 0x0057CEA0
static __forceinline void sub_0057CEA0_ApplyHitClass(D2DamageStrc* pDamage, D2UnitStrc* pAttacker)
{
    if (!pDamage->nHitClassActiveSet && !(pDamage->dwHitClass & 0xF))
    {
        pDamage->dwHitClass |= UNITS_GetHitClass(pAttacker);
    }
}

void __fastcall sub_M109_Emit_0057CEA0(D2UnitStrc* pAttacker, D2DamageStrc* pDamage)
{
    sub_0057CEA0_ApplyHitClass(pDamage, pAttacker);
    UNITS_GetHitClass((D2UnitStrc*)pDamage);
}
