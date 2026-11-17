struct Unit; struct Flags;
struct Quest { char pad[9]; unsigned char notIntro; char padA[2]; unsigned char state; char padD[0xD3]; int filter; };
int __stdcall sub_0065C310(Flags*,int,int);  // 0x0065C310
enum { NPC_ID = 176 };
// 0x00598910
bool __fastcall sub_00598910(Quest* quest,int npc,Unit* player,Flags* flags,Unit* npcUnit)
{
    if (npc == NPC_ID && sub_0065C310(flags,quest->filter,0)!=1) {
        if (quest->notIntro && quest->state==1 && !sub_0065C310(flags,quest->filter,15)) return true;
        if (sub_0065C310(flags,quest->filter,1)==1) return true;
    }
    return false;
}
