#define OUTPUT_SIZE 0x80
extern int gdwGlobal_00992B1C;  // 0x00992B1C
extern "C" const char gszMainThread_006FF988[];  // 0x006FF988
extern "C" int __cdecl strncpy_s(char*,unsigned int,const char*,unsigned int);  // 0x006859D2
// 0x00401640
static __declspec(noinline) bool __stdcall sub_00401640_GetThreadName(int threadId,char* output) {
 if(gdwGlobal_00992B1C==threadId) strncpy_s(output,OUTPUT_SIZE,gszMainThread_006FF988,(unsigned int)-1);
 else output[0]=0;
 return true;
}

bool __fastcall EmitThreadName(int threadId,char* output) {
 return sub_00401640_GetThreadName(threadId,output);
}

#include "gen/data/Source/Fog/Unknown_00401640.inc"
