#include "D2GameTypes.h"
struct D2CriticalSectionStrc;
struct D2FogBlockStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __cdecl sub_00411CD0_InitHeaps(); // 0x00411CD0
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

// 0x00411640
static __forceinline char* sub_00411640_GetBlockHeader(char* pMemory)
{
    if (!pMemory)
    {
        return pMemory;
    }
    char* pHeader = pMemory - 8;
    if (pHeader[3] & 8)
    {
        pHeader = *(char**)(pHeader - 4);
    }
    return pHeader;
}

// 0x00411660
static __forceinline int sub_00411660_GetSegmentField(char* pBlock)
{
    return *(int*)((*(unsigned short*)(pBlock + 4) << 16) + 4);
}

int __stdcall sub_M114_Emit_00411640(char* p, char* q)
{
    return (int)sub_00411640_GetBlockHeader(p) + sub_00411660_GetSegmentField(q);
}

// 0x004116E0
char* __fastcall sub_004116E0_GetBlockData(char* pHeader)
{
    if (!pHeader)
    {
        return 0;
    }
    char* pData = pHeader + 8;
    if (pHeader[3] & 4)
    {
        pData = *(char**)pData;
    }
    return pData;
}

// 0x00411DA0
int __cdecl sub_00411DA0_GetHeap()
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
    }
    return gbHeapInitialized_007788D0;
}

// 0x00411740
static D2FogBlockStrc* __stdcall sub_00411740_FindFreeBlock(unsigned int dwSize, unsigned int* pHash, int bLeaveIfMissing)
{
    const unsigned int nHash = (unsigned char)dwSize;
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[nHash]);
    *pHash = nHash;
    for (D2FogBlockStrc* pBlock = gapFreeBlocks_007768B8[nHash]; pBlock; pBlock = pBlock->pNext)
    {
        if (pBlock->dwSize == dwSize)
        {
            return pBlock;
        }
    }
    if (bLeaveIfMissing)
    {
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nHash]);
        *pHash = -1;
    }
    return 0;
}

D2FogBlockStrc* __stdcall sub_K01_Emit_00411740(unsigned int dwSize, unsigned int* pHash, int bLeaveIfMissing)
{
    return sub_00411740_FindFreeBlock(dwSize, pHash, bLeaveIfMissing);
}
