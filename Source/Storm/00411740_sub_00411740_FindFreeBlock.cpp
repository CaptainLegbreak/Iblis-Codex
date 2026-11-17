struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[3];
    int bInUse;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern D2FogBlockStrc* gapFreeBlocks_007768B8[0x100];                                                       // 0x007768B8
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100];                                              // 0x00776CC0

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
