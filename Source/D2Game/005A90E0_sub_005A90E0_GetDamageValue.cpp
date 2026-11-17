struct D2GameStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; };
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int id); // 0x0064B0C0
struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
};

// 0x005A90E0
int __fastcall sub_005A90E0_GetDamageValue(D2GameStrc* game, D2UnitStrc* missile, D2UnitStrc* unit, D2DamageStrc* damage, int unused)
{
 if (!missile) return 0;
 switch (MISSILE_GetElemTypeFromMissileId(!missile ? -1 : missile->dwClassId)) {
 case 0: return damage->dwPhysDamage;
 case 1: return damage->dwFireDamage;
 case 2: return damage->dwLtngDamage;
 case 3: return damage->dwMagDamage;
 case 4: return damage->dwColdDamage;
 case 5: return damage->dwPoisDamage;
 case 6: return damage->dwLifeLeech;
 case 7: return damage->dwManaLeech;
 case 8: return damage->dwStamLeech;
 case 9: return damage->dwStunLen;
 case 11: return damage->dwBurnDamage;
 case 12: return damage->dwColdDamage;
 default: return 0;
 }
}
