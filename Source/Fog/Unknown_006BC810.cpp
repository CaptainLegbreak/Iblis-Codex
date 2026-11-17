#include "Fog.h"

#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct SkillLink;
struct Drlg;
struct Pad40_006BC810;
struct Obj006BC810;
struct PaletteColor;
struct MonStatsView;
struct ReceiveQueue;
struct Transport;
struct PaletteTables;
struct UnitView;
struct SkillText;
struct LevelView;
struct ReceiveConnection;
struct SendContext;
struct D2ConnectionStrc;
struct D2PacketHeaderStrc;

struct Pad40_006BC810 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj006BC810 {
    Pad40_006BC810 tPad000;
    Pad40_006BC810 tPad040;
    Pad40_006BC810 tPad080;
    Pad40_006BC810 tPad0C0;
    unsigned int dwUnknown100;
    unsigned int dwUnknown104;
    unsigned int dwUnknown108;
    unsigned int dwUnknown10C;
    unsigned int dwValue110;
};

typedef unsigned int U32;

typedef unsigned char U8;

typedef signed short S16;

typedef char check_pointer_size[sizeof(void*)==4?1:-1];

struct PaletteColor
{
    U8 c0;
    U8 c1;
    U8 c2;
    U8 unused;
};

typedef char check_PaletteColor_size[sizeof(PaletteColor)==4?1:-1];

typedef char check_PaletteColor_c1[OFFSET(PaletteColor,c1)==1?1:-1];

typedef char check_PaletteColor_c2[OFFSET(PaletteColor,c2)==2?1:-1];

struct MonStatsView
{
    U8 pad0[0x170];
    S16 skillIds[8];
    U8 pad180[8];
    S16 sequences[8];
    U8 pad198[0x10];
};

typedef char check_MonStatsView_skillIds[OFFSET(MonStatsView,skillIds)==0x170?1:-1];

typedef char check_MonStatsView_sequences[OFFSET(MonStatsView,sequences)==0x188?1:-1];

typedef char check_MonStatsView_size[sizeof(MonStatsView)==0x1A8?1:-1];

struct ReceiveQueue
{
    U32 status;
    U8 criticalSection[0x18];
    void* head;
    void* tail;
};

typedef char check_ReceiveQueue_head[OFFSET(ReceiveQueue,head)==0x1C?1:-1];

typedef char check_ReceiveQueue_tail[OFFSET(ReceiveQueue,tail)==0x20?1:-1];

typedef char check_ReceiveQueue_size[sizeof(ReceiveQueue)==0x24?1:-1];

struct Transport
{
    int enabled;
};

typedef char check_Transport_enabled[OFFSET(Transport,enabled)==0?1:-1];

extern "C" U8 __stdcall sub_00605210_FindNearestColor(const U8* palette, U32 count, int c0, int c1, int c2);
extern "C" void* __fastcall sub_00451F80_MonStats(int classId);
extern "C" int* __fastcall sub_0066C040_Visibility(Drlg* drlg, int levelId);
extern "C" unsigned short __fastcall sub_006C2090_ReadQueue(ReceiveQueue* queue, char* buffer, int capacity);
extern "C" int __fastcall sub_006BC030_Send(Transport* transport, const char* buffer, U32 size);

struct PaletteTables
{
    PaletteColor colors[256];
    U8 tables[256*32];
};

typedef char check_PaletteTables_tables[OFFSET(PaletteTables,tables)==0x400?1:-1];

typedef char check_PaletteTables_size[sizeof(PaletteTables)==9216?1:-1];

struct UnitView
{
    U32 type;
    int classId;
};

typedef char check_UnitView_classId[OFFSET(UnitView,classId)==4?1:-1];

struct SkillText
{
    S16 f_0;
    U8 pad2[0x11];
    U8 sequence;
};

typedef char check_SkillText_sequence[OFFSET(SkillText,sequence)==0x13?1:-1];

struct SkillLink
{
    SkillText* text;
};

typedef char check_SkillLink_text[OFFSET(SkillLink,text)==0?1:-1];

struct LevelView
{
    U8 pad0[0x1B4];
    Drlg* drlg;
    U8 padAfterDrlg[0x18];
    int f_1D0;
};

typedef char check_LevelView_drlg[OFFSET(LevelView,drlg)==0x1B4?1:-1];

typedef char check_LevelView_levelId[OFFSET(LevelView,f_1D0)==0x1D0?1:-1];

struct ReceiveConnection
{
    U8 pad0[0x170];
    ReceiveQueue queue;
};

typedef char check_ReceiveConnection_queue[OFFSET(ReceiveConnection,queue)==0x170?1:-1];

struct SendContext
{
    U8 pad0[0x110];
    Transport* transport;
};

typedef char check_SendContext_transport[OFFSET(SendContext,transport)==0x110?1:-1];

struct D2ConnectionStrc { char unknown000[0x110]; int* active; int unknown114; int kind,version; unsigned char id; };

struct D2PacketHeaderStrc { unsigned char id,command; unsigned short size; };

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
void __stdcall SMemCopy(void*,const void*,unsigned int); // 0x0041D2A0
int __stdcall sub_006BC860_Send(D2ConnectionStrc*,const unsigned char*,int); // 0x006BC860

// 0x006BC810
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006BC810(Obj006BC810* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue110;
}

extern "C" U32 __fastcall sub_00673FF0_visibilityMask(LevelView* first, LevelView* second)
{
    int* visibility = sub_0066C040_Visibility(first->drlg, first->f_1D0);
    const int targetId = second->f_1D0;
    int index;
    for (index = 0; index < 8; index += 1)
    {
        if (visibility[index] == targetId)
            break;
    }
    if (index == 8)
        return 0;
    return 1U << (index + 4);
}

// 0x006BC860
extern "C" int __stdcall sub_006BC860_send(SendContext* context, const char* buffer, int size)
{
    if (context && context->transport && context->transport->enabled != 0)
        return sub_006BC030_Send(context->transport, buffer, (unsigned short)size);
    return -1;
}

// 0x006BC8A0
int __stdcall sub_006BC8A0_SendBuffer(D2ConnectionStrc* connection,const unsigned char* data,int size)
{
 unsigned char buffer[0x2064];
 D2PacketHeaderStrc header;
 if(!connection || !connection->active || !*connection->active) return -1;
 unsigned int payload,total;
 if(connection->kind==4 && connection->version==2) {
  if(!data || (unsigned short)(size-1)>0x205E) {
   sub_00408A60(&gszEmptyAssertText,sub_00408090(),93);
   exit(-1);
  }
  payload=(unsigned short)size;
  SMemCopy(buffer+3,data,payload-1);
  header.size=(unsigned short)(size+3);
  header.command=*data;
  header.id=connection->id;
  SMemCopy(buffer,&header,4);
  total=payload+3;
 } else {
  *(unsigned short*)&header=(unsigned short)(size+2);
  if(*(unsigned short*)&header>=0x2064) {
   sub_00408A60(&gszEmptyAssertText,sub_00408090(),113);
   exit(-1);
  }
  SMemCopy(buffer,&header,2);
  if(!data) size=0;
  payload=(unsigned short)size;
  total=payload+2;
  if(data && total<0x2064) SMemCopy(buffer+2,data,payload);
 }
 return sub_006BC860_Send(connection,buffer,total)+(payload-total);
}
