struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct T0041D340
{
    unsigned int dwState[5];
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern D2CriticalSectionStrc gtQueueLock_00882004;                                                          // 0x00882004
extern int gnSlotArrayB_008822A8[94];                                                                       // 0x008822A8

// 0x00520200
void __cdecl sub_00520200_DeleteQueueLock()
{
    DeleteCriticalSection(&gtQueueLock_00882004);
}

// 0x00520680
void __fastcall sub_00520680_SHA1Init(T0041D340* pContext)
{
    pContext->dwState[0] = 0x67452301;
    pContext->dwState[1] = 0xEFCDAB89;
    pContext->dwState[2] = 0x98BADCFE;
    pContext->dwState[3] = 0x10325476;
    pContext->dwState[4] = 0xC3D2E1F0;
}

// 0x00520A80
static __forceinline int sub_00520A80_CheckStringBlock(const char* pBuffer, unsigned int nPos, unsigned int nCount, unsigned int nSize)
{
    if (nSize < nPos + nCount)
    {
        return 0;
    }
    if (!nCount)
    {
        return 1;
    }
    if (pBuffer[nSize - 1])
    {
        return 0;
    }
    const unsigned int nEnd = nSize - 1;
    unsigned int nFound = 0;
    for (unsigned int i = nPos; i < nEnd; ++i)
    {
        if (!pBuffer[i])
        {
            ++nFound;
        }
    }
    return nFound == nCount - 1;
}

// 0x00520C30
void __fastcall sub_00520C30_SetSlot(unsigned char nIndex, int nValue)
{
    gnSlotArrayB_008822A8[nIndex] = nValue;
}

int __fastcall sub_M119_Emit_00520A80(int nPos, int nCount, int nSize)
{
    return sub_00520A80_CheckStringBlock((const char*)nSize, nPos, nCount, nSize + 3);
}
