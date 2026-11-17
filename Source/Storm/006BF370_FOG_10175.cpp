struct D2CriticalSectionStrc { char data[24]; };
struct D2QPacketStrc { int id; unsigned char data[0x5B0]; int size; unsigned int tick; D2QPacketStrc* next; };
typedef int (__fastcall *D2PacketParser)(const unsigned char*,int,int*,int*,int*,int*,int,int,int);
struct T006BE350 { char unknown000[0x854]; D2CriticalSectionStrc lock; int unknown86C; D2QPacketStrc** heads; D2QPacketStrc** tails; D2QPacketStrc* freePackets; int channelCount; char unknown880[0x340]; D2PacketParser parser; };
extern const char gszQServerSource[]; // 0x006FC460
void* __fastcall FOG_Alloc(unsigned int size,const char* file,int line,int flags); // 0x0040B380
void* __cdecl sub_006829C0_Copy(void* dest,const void* source,unsigned int size); // 0x006829C0
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount();
// 0x006BF370
int __stdcall FOG_10175(T006BE350* server,const unsigned char* buffer,int size,int id)
{
 int consumed=0;
 int unknown1=0;
 int channel=0;
 int unknown2=0;
 int result=server->parser(buffer,size,&unknown1,&consumed,&channel,&unknown2,0,0,0);
 if(result!=2 && result!=1) return 0;
 D2QPacketStrc* packet;
 if(server->freePackets) {
  EnterCriticalSection(&server->lock);
  packet=server->freePackets;
  if(packet) server->freePackets=packet->next;
  else packet=(D2QPacketStrc*)FOG_Alloc(sizeof(D2QPacketStrc),gszQServerSource,2569,0);
  LeaveCriticalSection(&server->lock);
 } else packet=(D2QPacketStrc*)FOG_Alloc(sizeof(D2QPacketStrc),gszQServerSource,2578,0);
 sub_006829C0_Copy(packet->data,buffer+consumed,size-consumed);
 packet->size=size-consumed;
 packet->tick=GetTickCount();
 packet->next=0;
 packet->id=id;
 if(channel<server->channelCount) {
  EnterCriticalSection(&server->lock);
  D2QPacketStrc* last=server->tails[channel];
  if(!last) server->heads[channel]=packet;
  else last->next=packet;
  server->tails[channel]=packet;
  LeaveCriticalSection(&server->lock);
 }
 return 1;
}
