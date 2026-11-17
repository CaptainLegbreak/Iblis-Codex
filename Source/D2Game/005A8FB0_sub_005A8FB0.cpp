struct Game;
struct Unit { char type[4]; int classId; };
struct Damage {
    unsigned int hitFlags; unsigned short resultFlags,extra;
    int physical,enhancedPercent,fire,burn,burnLength,lightning,magic,cold,poison,
        poisonLength,coldLength,freezeLength,lifeLeech,manaLeech,staminaLeech,stunLength;
};
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int);  // 0x0064B0C0
enum { ZERO_DAMAGE=0 };
static __forceinline int GetClassId(Unit* unit) { return unit->classId; }
// 0x005A8FB0
void __fastcall sub_005A8FB0(Game* game,Unit* missile,Unit* owner,Damage* damage,int value)
{
    if (!missile) return;
    switch (MISSILE_GetElemTypeFromMissileId(GetClassId(missile))) {
    case 0: damage->physical=value; break;
    case 1: damage->fire=value; break;
    case 2: damage->lightning=value; break;
    case 3: damage->magic=value; break;
    case 4: damage->cold=value; if (value<=ZERO_DAMAGE) damage->coldLength=0; break;
    case 5: damage->poison=value; if (value<=ZERO_DAMAGE) damage->poisonLength=0; break;
    case 6: damage->lifeLeech=value; break;
    case 7: damage->manaLeech=value; break;
    case 8: damage->staminaLeech=value; break;
    case 9: damage->stunLength=value; break;
    case 11: damage->burn=value; if (value<=ZERO_DAMAGE) damage->burnLength=0; break;
    case 12: damage->cold=value; if (value<=ZERO_DAMAGE) damage->freezeLength=0; break;
    }
}
