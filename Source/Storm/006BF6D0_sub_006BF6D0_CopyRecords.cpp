struct D2CriticalSectionStrc { unsigned int opaque[6]; };
struct D2RecordStrc { unsigned char data[0xac]; int value; };
struct D2ServerStrc { unsigned char unknown[0x8b4]; D2CriticalSectionStrc lock; unsigned char records[0x2dc]; int values[1]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int); // 0x006829C0
// 0x006BF6D0
void __fastcall sub_006BF6D0_CopyRecords(D2ServerStrc* server,D2RecordStrc* destination,int count)
{
 EnterCriticalSection(&server->lock);
 memcpy(destination,server->records,count*sizeof(D2RecordStrc));
 LeaveCriticalSection(&server->lock);
 for (int i=0;i<count;++i) destination[i].value=server->values[i];
}
