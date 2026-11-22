#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormLink.h"

struct D2CriticalSectionStrc;

struct D2FogBlockStrc;

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[2];
    int bReportLeak;
    int bInUse;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

void __fastcall sub_00411A80_ReleaseBlock(D2FogBlockStrc** ppLink); // 0x00411A80

D2FogBlockStrc** __fastcall sub_00411F00_ProcessUsedBlock(D2FogBlockStrc** ppLink); // 0x00411F00

void __stdcall SErrReportResourceLeak(const char* szName); // 0x0041D1E0

extern D2FogBlockStrc* gapFreeBlocks_007768B8[0x100]; // 0x007768B8

extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0

extern int gabFreeBlockDirty_007784C8[0x100]; // 0x007784C8

extern int gbHeapInitialized_007788D0; // 0x007788D0

// 0x00412240
int __cdecl sub_00412240_DestroyHeaps()
{
    int i = 0;
    if (gbHeapInitialized_007788D0)
    {
        gbHeapInitialized_007788D0 = 0;
        D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
        int n = 0x100;
        do
        {
            EnterCriticalSection(pLock);
            D2FogBlockStrc** ppLink = &gapFreeBlocks_007768B8[i];
            gabFreeBlockDirty_007784C8[i] = 0;
            while (*ppLink)
            {
                D2FogBlockStrc* pBlock = *ppLink;
                if (pBlock->bInUse)
                {
                    ppLink = sub_00411F00_ProcessUsedBlock(ppLink);
                }
                else
                {
                    if (pBlock->bReportLeak && pBlock->dwSize >= 0x80000000)
                        SErrReportResourceLeak("HSHEAP");
                    sub_00411A80_ReleaseBlock(ppLink);
                }
            }
            LeaveCriticalSection(pLock);
            DeleteCriticalSection(pLock);
            ++i;
            ++pLock;
        } while (--n);
    }
    return 1;
}
