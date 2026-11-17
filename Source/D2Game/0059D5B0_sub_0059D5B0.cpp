struct Game { char pad[0x1C]; void* pool; };
struct Quest; struct Arg; struct Unit; struct Flags;
typedef void (__fastcall *Callback)(Quest*,Arg*);
typedef bool (__fastcall *Status)(Quest*,Unit*,Flags*,Flags*,unsigned char*);
typedef bool (__fastcall *Active)(Quest*,int,Unit*,Flags*,Unit*);
typedef bool (__fastcall *Sequence)(Quest*);
struct Extra { unsigned char f0,f1,f2,f3; char pad4[0x14]; int value18,value1c; char pad20[0x14]; int value34; char f_38[0x30]; };
struct Quest { int number; Game* game; unsigned char act,notIntro,active,lastState,state,init; short padE; int sequenceId; unsigned int flags; Extra* extra; char guidPad[0x84]; Callback callbacks[15]; void* messages; int filter; int padE4; Status statusFilter; Active activeFilter; Sequence sequenceFilter; };
extern "C" void* __cdecl memset(void*,int,unsigned int);
void* __fastcall sub_0040B430(void*,int,const char*,int,int);  // 0x0040B430
extern char npc_messages[];  // 0x0073B288
void __fastcall sub_0059D1C0(Quest*,Arg*);  // 0x0059D1C0
void __fastcall sub_0059C3C0(Quest*,Arg*);  // 0x0059C3C0
void __fastcall sub_0059CB20(Quest*,Arg*);  // 0x0059CB20
void __fastcall sub_0059C6B0(Quest*,Arg*);  // 0x0059C6B0
void __fastcall sub_0059C760(Quest*,Arg*);  // 0x0059C760
void __fastcall sub_0059D4F0(Quest*,Arg*);  // 0x0059D4F0
void __fastcall sub_0059D4D0(Quest*,Arg*);  // 0x0059D4D0
void __fastcall sub_0059D050(Quest*,Arg*);  // 0x0059D050
bool __fastcall sub_0059CA50(Quest*,Unit*,Flags*,Flags*,unsigned char*);  // 0x0059CA50
bool __fastcall sub_0059D300(Quest*,int,Unit*,Flags*,Unit*);  // 0x0059D300
bool __fastcall sub_0059D450(Quest*);  // 0x0059D450
enum { QUEST_FILTER = 14, ALLOC_LINE = 1090 };
// 0x0059D5B0
void __fastcall sub_0059D5B0(Quest* quest)
{
    memset(quest->callbacks,0,sizeof(quest->callbacks));
    quest->callbacks[3]=sub_0059D1C0;
    quest->callbacks[0]=sub_0059C3C0;
    quest->callbacks[11]=sub_0059CB20;
    quest->callbacks[10]=sub_0059C6B0;
    quest->callbacks[2]=sub_0059C760;
    quest->callbacks[13]=sub_0059D4F0;
    quest->callbacks[14]=sub_0059D4D0;
    quest->callbacks[8]=sub_0059D050;
    quest->messages=npc_messages;
    quest->active=1;
    quest->state=0;
    Extra* extra=(Extra*)sub_0040B430(quest->game->pool,0x68,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp",ALLOC_LINE,0);
    quest->extra=extra;
    quest->filter=QUEST_FILTER;
    quest->statusFilter=sub_0059CA50;
    quest->init=4;
    quest->activeFilter=sub_0059D300;
    quest->sequenceFilter=sub_0059D450;
    memset(extra,0,0x68);
    extra->f1=0;
    extra->f2=0;
    extra->f3=0;
    extra->value18=0;
    extra->value1c=0;
    extra->value34=0;
}

#include "gen/data/Source/D2Game/0059D5B0_sub_0059D5B0.inc"
