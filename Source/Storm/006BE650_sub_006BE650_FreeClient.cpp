extern "C" int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x0040B3C0
void __cdecl sub_006BE300_Nop(const char* szTag, const char* szFormat, ...); // 0x006BE300

struct D2CriticalSection006BE650Strc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSection006BE650Strc* pLock);

struct D2QMsg006BE650Strc
{
    unsigned int nSize;
    D2QMsg006BE650Strc* pNext;
};

struct D2QClient006BE650Strc
{
    unsigned char unk_00[0x04];
    D2QClient006BE650Strc* pNextClient;
    unsigned char unk_08[0x24];
    D2CriticalSection006BE650Strc pLock;
    unsigned char unk_44[0x30];
    D2QMsg006BE650Strc* pMsgHead;
};

static __declspec(noinline) void sub_006BE650_FreeClient(D2QClient006BE650Strc* ptClient);

// 0x006BE650
static void sub_006BE650_FreeClient(D2QClient006BE650Strc* ptClient)
{
    if (ptClient->pNextClient)
    {
        sub_006BE300_Nop("QSRV", "  ptClient->ptNextClient =  %08X", ptClient->pNextClient);
    }
    D2QMsg006BE650Strc* pMsg = ptClient->pMsgHead;
    while (pMsg)
    {
        D2QMsg006BE650Strc* pFree = pMsg;
        pMsg = pMsg->pNext;
        FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x3A7, 0);
    }
    ptClient->pMsgHead = 0;
    DeleteCriticalSection(&ptClient->pLock);
    FOG_Free(ptClient, ".\\Src\\QServer\\QServer.cpp", 0x3AE, 0);
}

// calling-convention shim (not game code)
void __stdcall shim_8(D2QClient006BE650Strc* ptClient)
{
    sub_006BE650_FreeClient(ptClient);
}
