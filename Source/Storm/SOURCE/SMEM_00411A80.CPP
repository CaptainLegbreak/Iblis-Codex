#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"

struct D2CriticalSectionStrc;

struct D2FogBlockStrc;

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[3];
    int bInUse;
};

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long dwSize, unsigned long dwFreeType); // 0x006CC220

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

extern unsigned long gnFlag2_00776CBC; // 0x00776CBC

extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0

extern unsigned long gnFlag0_007784C4; // 0x007784C4

extern int gbHeapInitialized_007788D0; // 0x007788D0

extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030

static D2StormRequestStrc* gpCurrentRequest_0077902C; // 0x0077902C

// 0x00411A80
void __fastcall sub_00411A80_ReleaseBlock(D2FogBlockStrc** ppLink)
{
    D2FogBlockStrc* pBlock = *ppLink;
    *ppLink = pBlock->pNext;
    VirtualFree(pBlock, 0, 0x8000);
}

// 0x00411CD0
void __cdecl SMemInitialize()
{
    if (!gbHeapInitialized_007788D0)
    {
        SRegLoadValue("Internal", "Debug Memory", 0, &gnFlag0_007784C4);
        SRegLoadValue("Internal", "Protect Memory", 0, &gnFlag2_00776CBC);
        D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
        int n = 0x100;
        do
        {
            InitializeCriticalSection(pLock);
            ++pLock;
        }
        while (--n);
        gbHeapInitialized_007788D0 = 1;
    }
}
