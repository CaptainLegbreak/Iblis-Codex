#include "D2GameTypes.h"
struct D2CriticalSectionStrc;
struct D2FogBlockStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __cdecl SMemInitialize(); // 0x00411CD0
extern int gbHeapInitialized_007788D0; // 0x007788D0


struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[3];
    int bInUse;
};


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern D2FogBlockStrc* gapFreeBlocks_007768B8[0x100]; // 0x007768B8
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0

// 0x004112B0
unsigned long __cdecl sub_004112B0_GetTickCount()
{
    return GetTickCount();
}

