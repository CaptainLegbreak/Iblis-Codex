struct Game; struct Unit;
struct StatValue { int value; };
unsigned short __fastcall sub_0057EC10(Game*,Unit*,Unit*,int,int);  // 0x0057EC10
enum { RANGE_OVERRIDE = 0 };
// 0x005A5470
unsigned short __fastcall sub_005A5470(Game* game,Unit* attacker,Unit* defender,StatValue stat,int ignoredRange)
{
    return sub_0057EC10(game,attacker,defender,stat.value,RANGE_OVERRIDE);
}
