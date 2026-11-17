#define MAX_MSG_SIZE 516

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2NetPacketRecStrc
{
    unsigned char data[MAX_MSG_SIZE];
    int nPacketSize;
    unsigned long dwTickCount;
    D2NetPacketRecStrc* pNext;
};

struct D2NetLockStrc
{
    D2CriticalSectionStrc tLock;

    void Lock(int nUnused);
    void Unlock(int nUnused);
};

struct D2Net52BE10Strc
{
    char unk0x00[0xD0];
    char aData[4];
};

typedef const char* (__stdcall* FnLoadComplete)();

struct D2ServerCallbackFunctions
{
    void* pfCallbacks[15];
    FnLoadComplete pfLoadComplete;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);

extern "C" const char szD2NetCpp_006E0488[];
extern char gData_006E0498[];
extern int gnConnectionMode_00882D10;
extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;
extern int gbD2ServerCallbackFunctionsInitialized_6FD45834;

int __fastcall sub_0052B800_IsConnectionMode2()
{
    return gnConnectionMode_00882D10 == 2;
}

int __fastcall NET_DequeueFirstPacketFromList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList, unsigned char* pBuffer, unsigned int nBufferSize)
{
    int nResult;

    EnterCriticalSection(pCriticalSection);

    D2NetPacketRecStrc* pPacket = *ppPacketList;
    if (pPacket && (gnConnectionMode_00882D10 != 2 || GetTickCount() - pPacket->dwTickCount >= 500))
    {
        memcpy(pBuffer, pPacket, nBufferSize < MAX_MSG_SIZE ? nBufferSize : MAX_MSG_SIZE);
        nResult = pPacket->nPacketSize;
        *ppPacketList = pPacket->pNext;
        FOG_Free(pPacket, szD2NetCpp_006E0488, 0x46, 0);
    }
    else
    {
        nResult = -1;
    }

    LeaveCriticalSection(pCriticalSection);
    return nResult;
}

void __cdecl sub_0052B8F0_Nop()
{
}

void __cdecl sub_0052B900_Nop()
{
}

bool __stdcall sub_0052BDD0_AlwaysTrue(int nUnused)
{
    return true;
}

void D2NetLockStrc::Lock(int nUnused)
{
    EnterCriticalSection(&tLock);
}

void D2NetLockStrc::Unlock(int nUnused)
{
    LeaveCriticalSection(&tLock);
}

unsigned int __fastcall sub_0052BE00_GetBits12(unsigned int nValue)
{
    return (nValue >> 12) & 7;
}

char* __fastcall sub_0052BE10_GetField0D0(D2Net52BE10Strc* pRecord)
{
    return pRecord->aData;
}

void __stdcall sub_0052BE40_Stub(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
}

void __stdcall sub_0052BE60_Stub(int a1, int a2, int a3, int a4)
{
}

void __cdecl sub_0052BE70_Stub()
{
}

void __stdcall sub_0052BE80_Stub(int a1, int a2, int a3)
{
}

int __stdcall sub_0052BE90_Stub(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    return 0;
}

void __stdcall sub_0052BED0_Stub(int a1, int a2, int a3, int a4, int a5)
{
}

void __cdecl sub_0052BEF0_Stub()
{
}

void __stdcall sub_0052BF40_Stub(int a1, int a2, int a3, int a4)
{
}

void __stdcall sub_0052BFB0_Stub(int a1, int a2, int a3, int a4)
{
}

const char* __fastcall sub_0052BFC0_GetLoadComplete()
{
    if (!gbD2ServerCallbackFunctionsInitialized_6FD45834)
    {
        return gData_006E0498;
    }
    return gpD2EventCallbackTable_6FD45830->pfLoadComplete();
}

// 0x0052DB30
int __fastcall sub_0052BFE0_GetGamesCount()
{
    int nResult = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] != 0 && gnGamesGUIDs_6FD447F8[i] != -1)
        {
            ++nResult;
        }
    }
    return nResult;
}
