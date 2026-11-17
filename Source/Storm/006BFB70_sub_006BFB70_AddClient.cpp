struct D2CriticalSectionStrc { char data[24]; };
struct D2QClientStrc {
 unsigned int id; D2QClientStrc* next; long references; int unknown0C; unsigned int socket; int unknown14; unsigned int address; D2QClientStrc* addressNext; int unknown20; int pending,queued;
 D2CriticalSectionStrc lock; char unknown44[0x14]; int enabled; char unknown5C[0x14]; int state; int unknown74; char unknown78[0x20]; unsigned int tick1,tick2,tick3,tick4; char unknownA8[0x5BC];
};
struct D2AddressRefStrc { unsigned int address,count; D2AddressRefStrc* next; };
struct T006BE350 {
 int unknown00; unsigned int nextId; int unknown08; unsigned int mask,modulus; D2QClientStrc** clients; int unknown18; D2CriticalSectionStrc* locks; D2QClientStrc** addressClients; int unknown24; D2CriticalSectionStrc addressLock; D2AddressRefStrc** addressRefs; char unknown44[0x810]; D2CriticalSectionStrc idLock; char unknown86C[0x14]; int count;
};
extern const char gszQServerSource[]; // 0x006FC460
extern const char gszQServerPrefix[]; // 0x006FC47C
void* __fastcall FOG_Alloc(unsigned int size,const char* file,int line,int flags); // 0x0040B380
unsigned int __cdecl sub_00410A80_GetTick(); // 0x00410A80
const char* __stdcall sub_006B013E_InetNtoa(unsigned int address); // 0x006B013E
void __cdecl sub_006BE300_Log(const char* prefix,const char* format,...); // 0x006BE300
extern "C" void* __cdecl memset(void*,int,unsigned int);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
static int __stdcall sub_006BF180_ReferenceAddress(T006BE350* server,const unsigned int* address); // 0x006BF180
static __declspec(noinline)
int __stdcall sub_006BF180_ReferenceAddress(T006BE350* server,const unsigned int* address)
{
 unsigned int value=*address;
 unsigned int bucket=value%server->modulus;
 D2AddressRefStrc* entry=server->addressRefs[bucket];
 while(entry) {
  if(entry->address==value) {
   ++entry->count;
   return 1;
  }
  entry=entry->next;
 }
 entry=(D2AddressRefStrc*)FOG_Alloc(sizeof(D2AddressRefStrc),gszQServerSource,2329,0);
 entry->address=value;
 entry->count=1;
 entry->next=server->addressRefs[bucket];
 server->addressRefs[bucket]=entry;
 return 1;
}
// 0x006BFB70
D2QClientStrc* __fastcall sub_006BFB70_AddClient(T006BE350* server,unsigned int socket,unsigned int address)
{
 D2QClientStrc* client=(D2QClientStrc*)FOG_Alloc(sizeof(D2QClientStrc),gszQServerSource,571,0);
 memset(client,0,sizeof(D2QClientStrc));
 EnterCriticalSection(&server->idLock);
 unsigned int id=++server->nextId;
 LeaveCriticalSection(&server->idLock);
 client->id=id;
 client->socket=socket;
 client->address=address;
 client->pending=0;client->queued=0;client->unknown74=0;
 client->enabled=1;client->state=2;
 unsigned int tick=sub_00410A80_GetTick();
 client->tick1=tick;client->tick2=tick;client->tick3=tick;client->tick4=tick;
 InitializeCriticalSection(&client->lock);
 unsigned int bucket=id&server->mask;
 EnterCriticalSection(&server->locks[bucket]);
 client->next=server->clients[bucket];
 server->clients[bucket]=client;
 LeaveCriticalSection(&server->locks[bucket]);
 EnterCriticalSection(&server->addressLock);
 unsigned int addressBucket=address&server->mask;
 client->addressNext=server->addressClients[addressBucket];
 server->addressClients[addressBucket]=client;
 LeaveCriticalSection(&server->addressLock);
 EnterCriticalSection(&server->idLock);
 sub_006BF180_ReferenceAddress(server,&address);
 InterlockedIncrement(&client->references);
 ++server->count;
 LeaveCriticalSection(&server->idLock);
 sub_006BE300_Log(gszQServerPrefix,"[QSrvAddClient]  Added client %d %s on socket %d",client->id,sub_006B013E_InetNtoa(client->address),client->socket);
 return client;
}
