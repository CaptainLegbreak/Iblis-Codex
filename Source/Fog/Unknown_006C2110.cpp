#include "D2SysTypes.h"
struct T006BE350 {
 char unknown000[0x854]; D2CriticalSectionStrc lock; char unknown86C[0x36C];
 void* threads[4]; unsigned int ids[4]; int stop[4]; char unknownC08[0x10]; int extraEnabled;
 void* extraThreads[4]; unsigned int extraIds[4]; int extraStop[4];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) unsigned int __stdcall WaitForMultipleObjects(unsigned int,void* const*,int,unsigned int);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
// 0x006C2110
void __fastcall sub_006C2110_StopServerThreads(T006BE350* server)
{
 void* handles[8];
 EnterCriticalSection(&server->lock);
 int count=0;
 for(int i=0;i<4;++i) {
  if(server->threads[i]) handles[count++]=server->threads[i];
  server->stop[i]=1;
  if(server->extraEnabled && server->extraThreads[i]) handles[count++]=server->extraThreads[i];
  server->extraStop[i]=1;
 }
 LeaveCriticalSection(&server->lock);
 if(count>0) WaitForMultipleObjects(count,handles,1,1000);
 for(int i=0;i<4;++i) {
  if(server->threads[i]) {
   CloseHandle(server->threads[i]);
   server->threads[i]=0;
   server->ids[i]=0;
  }
  if(server->extraEnabled && server->extraThreads[i]) {
   CloseHandle(server->extraThreads[i]);
   server->extraThreads[i]=0;
   server->extraIds[i]=0;
  }
 }
}
