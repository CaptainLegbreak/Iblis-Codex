#include "D2Sound.h"

struct D2DSoundBufferStrc;
struct D2DSoundVtableStrc {
 void* unknown000[11];
 int (__stdcall* Lock)(D2DSoundBufferStrc*,unsigned int,unsigned int,void**,unsigned int*,void**,unsigned int*,unsigned int);
 void* unknown030[7];
 int (__stdcall* Unlock)(D2DSoundBufferStrc*,void*,unsigned int,void*,unsigned int);
};
struct D2DSoundBufferStrc { D2DSoundVtableStrc* vtable; };
struct D2SoundStrc {
 D2DSoundBufferStrc* buffer; unsigned int bufferSize; int unknown008; void* buffer3d; void* propertySet;
 unsigned char* data; unsigned int dataSize; int streaming,unknown020;
 unsigned int progress; int dataSet,complete; unsigned int fillLimit;
 unsigned int flags; int volume; float attenuation; int loop; unsigned int loopStart;
};
extern D2CriticalSectionStrc gSoundLock; // 0x0088174C
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*); // 0x006CC214
extern const char gszEmptyAssert[]; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int); // 0x006829C0
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
// 0x00515180
int __fastcall sub_00515180_FillBuffer(D2SoundStrc* sound,unsigned int sourcePosition,unsigned int destinationPosition,unsigned int size)
{
 void* locked=0;
 if(sound && sound->buffer && sound->data && size) {
  EnterCriticalSection(&gSoundLock);
  unsigned int lockedSize=size;
  if(sound->buffer->vtable->Lock(sound->buffer,destinationPosition,size,&locked,&lockedSize,0,0,0)<0) {
   LeaveCriticalSection(&gSoundLock);
   return 0;
  }
  unsigned char* destination=(unsigned char*)locked;
  do {
   unsigned int end=sound->dataSize;
   if(sourcePosition>=end)
    sourcePosition=sound->loopStart+(sourcePosition-sound->loopStart)%(end-sound->loopStart);
   unsigned int count=size<end-sourcePosition?size:end-sourcePosition;
   memcpy(destination,sound->data+sourcePosition,count);
   sound->progress+=count;
   destination+=count;
   destinationPosition+=count;
   size-=count;
   sourcePosition+=count;
  } while(sound->loop && size);
  if(size) {
   if(sound->fillLimit!=(unsigned int)-1) {
    if(destinationPosition>=sound->fillLimit) goto unlock;
    size=sound->fillLimit-destinationPosition;
   }
   if(size) memset(destination,0,size);
  }
 unlock:
  sound->buffer->vtable->Unlock(sound->buffer,locked,lockedSize,0,0);
  if(!sound->loop && sound->progress>=sound->dataSize) sound->complete=1;
  LeaveCriticalSection(&gSoundLock);
  return 1;
 }
 sub_00408A60(gszEmptyAssert,sub_00408090(),221);
 exit(-1);
}
