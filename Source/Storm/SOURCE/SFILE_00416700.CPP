#include "Storm.h"
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void* hHeap, unsigned long dwFlags, unsigned long dwBytes); // 0x006CC318

unsigned char gnStormByteFlag_0077905E;                                                                     // 0x0077905E
int (__stdcall* gpfnStormNotify_007790B8)(int nArg);                                                        // 0x007790B8
extern void* gpStormOwnerA_007790C0;                                                                        // 0x007790C0

int __cdecl sub_00418B50();                                                                         // 0x00418B50
int __stdcall SFileFileExistsEx(void* hArchive, const char* szFileName, int nFlags);                  // 0x00418390
void* __cdecl StormGetInstance();                                                                  // 0x0041BEF0
void __cdecl sub_0041C1A0_LockErrorState();                                                                 // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState();                                                               // 0x0041C1E0
void __stdcall sub_0041C360_SetSuppress(int bSuppress);                                                     // 0x0041C360
void __cdecl SLogFlushAll();                                                                       // 0x0041FFF0

// 0x00416700
void __stdcall SFileSetPlatform(unsigned char nValue)
{
    gnStormByteFlag_0077905E = nValue;
}

// 0x00418B80
int __stdcall SFileFileExists(const char* szFileName)
{
    return SFileFileExistsEx(0, szFileName, sub_00418B50());
}

// 0x0041BEB0
int __stdcall sub_0041BEB0_FlushAndNotify(int nArg)
{
    sub_0041C360_SetSuppress(1);
    SLogFlushAll();
    if (gpfnStormNotify_007790B8)
        gpfnStormNotify_007790B8(nArg);
    return 0;
}




