struct D2PoolSystemStrc;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct T00408A30_2
{
    char unk0x00[0x1E];
};

struct D2PoolRecordStrc;

struct D2PoolSystemStrc
{
    int bFreePoolAlloc;
    D2CriticalSectionStrc tLock;
    int nPools;
    T00408A30_2 aPools[40];
    int nLargeOverflow;
    int nUnk0x7A4;
    D2PoolRecordStrc* pUnk0x7A8;
    int* apLargeBlocks[1023];
    int nCount;
    char unk0x17AC[0x20];
};

struct T00408A30_1
{
    int bInit;
    D2CriticalSectionStrc tLock;
    D2PoolSystemStrc aSystems[8];
    int nUnk0xBE7C;
    unsigned int anFreeIndex[8];
    int nFreeCount;
};

extern T00408A30_1 gtPoolManager_0074F0E8;                                                                  // 0x0074F0E8
#define gtDefaultPoolSystem_0074F104 (gtPoolManager_0074F0E8.aSystems[0])

// 0x00409200
static int sub_00409200_GetBlockSize(int nIndex)
{
    if (!nIndex)
    {
        return 0x10;
    }
    return 1 << (nIndex + 4);
}

int __fastcall sub_M126_Emit_00409200(int a, int nIndex, int nUnused)
{
    return sub_00409200_GetBlockSize(nIndex) + a;
}

// 0x004099C0
static D2PoolSystemStrc* sub_004099C0_GetPoolSystem(D2PoolSystemStrc* pSystem)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    return pSystem;
}

D2PoolSystemStrc* __fastcall sub_M126_Emit_004099C0(int a, D2PoolSystemStrc* pSystem, int nUnused)
{
    return sub_004099C0_GetPoolSystem(pSystem);
}
