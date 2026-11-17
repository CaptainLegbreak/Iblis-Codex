struct Game;
struct Unit { int type, classId; void* pool; int id; };
struct Client { void sub_005A5690(int unitId, unsigned char type); };  // 0x005A5690
struct PartyArgs { Unit* target; Unit* player; unsigned short f_8; };
unsigned short __fastcall sub_00554630(Unit*);  // 0x00554630
void __fastcall sub_0055B140(Game*,Unit*,Unit*);  // 0x0055B140
short __fastcall sub_0055B3F0(Unit*,Unit*);  // 0x0055B3F0
void __fastcall sub_0055B440(Unit*,Unit*);  // 0x0055B440
short __fastcall sub_00540100(Game*);  // 0x00540100
int __fastcall sub_00540320(Game*,short,Unit*);  // 0x00540320
void __fastcall sub_0055B650(Game*,Unit*);  // 0x0055B650
Client* __fastcall sub_005531C0(Unit*,const char*,int);  // 0x005531C0
void __fastcall sub_005A5970(Game*,Unit*,void*);  // 0x005A5970
typedef void (__fastcall *Iterator)(Game*,Unit*,void*);
void __fastcall sub_005538D0(Game*,Iterator,void*);  // 0x005538D0
enum { JOIN_RELATION = 2 };
// 0x005A5A30
void __fastcall sub_005A5A30(Game* game,Unit* player,Unit* target,int param,int* failure)
{
    unsigned short partyId=sub_00554630(target);
    sub_0055B140(game,player,target);
    sub_0055B140(game,target,player);
    if(sub_0055B3F0(player,target)!=JOIN_RELATION) {
        sub_0055B440(target,player);
        sub_0055B440(player,target);
        return;
    }
    if(partyId==0xFFFF) {
        partyId=sub_00540100(game);
        sub_00540320(game,partyId,target);
        sub_00540320(game,partyId,player);
        sub_0055B650(game,target);
    } else {
        sub_00540320(game,partyId,player);
    }
    sub_0055B650(game,player);
    sub_005531C0(player,".\\PLAYER\\PartyScreen.cpp",233)->sub_005A5690(!target ? -1 : target->id,8);
    PartyArgs args=PartyArgs();
    args.target=target;
    args.player=player;
    args.f_8=partyId;
    sub_005538D0(game,sub_005A5970,&args);
}
