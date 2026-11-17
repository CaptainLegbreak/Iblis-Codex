struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);   // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);   // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection);  // 0x006CC1FC

struct D2QNodeStrc
{
    char unk0x00[0x0C];
    D2QNodeStrc* pNext;
};

struct D2QClientStrc
{
    char unk0x000[0x5BC];
    D2QClientStrc* pNext;
};

struct T006BE350
{
    int nMode;
    char unk0x004[0x10];
    void* p014;
    char unk0x018[0x04];
    D2CriticalSectionStrc* pLocks;
    void* p020;
    char unk0x024[0x04];
    D2CriticalSectionStrc tLock028;
    void* p040;
    char unk0x044[0x84C - 0x44];
    D2QNodeStrc* pChain84C;
    char unk0x850[0x04];
    D2CriticalSectionStrc tLock854;
    int nState;
    void* p870;
    void* p874;
    D2QClientStrc* f_878;
    char unk0x87C[0x88C - 0x87C];
    D2QNodeStrc* pChain88C;
    int n890;
    D2CriticalSectionStrc tLock894;
    D2QNodeStrc** ppBuckets;
    unsigned int f_8B0;
    D2CriticalSectionStrc tLock8B4;
    char unk0x8CC[0xB90 - 0x8CC];
    unsigned int aSockets[4];
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_0040D880(unsigned int s);                                                                // 0x0040D880
extern "C" int __stdcall WSACleanup(void);                                                                  // 0x006B0138
void __stdcall sub_006BE3C0_Shutdown(T006BE350* pServer);                                               // 0x006BE3C0
void __stdcall sub_006BFAD0_Notify(T006BE350* pServer, int a2, int a3);                                 // 0x006BFAD0
void __fastcall sub_006C2110_StopModeThread(T006BE350* pServer);                                       // 0x006C2110
void __fastcall sub_006C33D0_Stop(T006BE350* pServer);                                                 // 0x006C33D0
extern "C" const char gszQServerFile_006FC460[];                                                            // 0x006FC460
extern int gnLockCount_0074C3E0;                                                                            // 0x0074C3E0

static __declspec(noinline) void sub_006BF320_FreeChain(T006BE350* pServer);
static __declspec(noinline) void sub_006BF0F0_FreeBuckets(T006BE350* pServer);

static void sub_006BF320_FreeChain(T006BE350* pServer)
{
    EnterCriticalSection(&pServer->tLock854);
    D2QNodeStrc* pNode = pServer->pChain84C;
    while (pNode)
    {
        D2QNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, gszQServerFile_006FC460, 0x9B0, 0);
        pNode = pNext;
    }
    pServer->pChain84C = 0;
    LeaveCriticalSection(&pServer->tLock854);
}

static void sub_006BF0F0_FreeBuckets(T006BE350* pServer)
{
    EnterCriticalSection(&pServer->tLock894);
    for (unsigned int i = 0; i < pServer->f_8B0; ++i)
    {
        D2QNodeStrc* pNode = pServer->ppBuckets[i];
        while (pNode)
        {
            D2QNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode, gszQServerFile_006FC460, 0x8BE, 0);
            pNode = pNext;
        }
        pServer->ppBuckets[i] = 0;
    }
    pServer->n890 = 0;
    LeaveCriticalSection(&pServer->tLock894);
}

// 0x006C0170
int __stdcall sub_006C0170_DestroyServer(T006BE350* pServer, int a2, int a3)
{
    if (!pServer)
        return 1;

    if (a2)
        sub_006BFAD0_Notify(pServer, a2, a3);

    if (pServer->nState != 1 && pServer->nState != 2)
    {
        if (pServer->nMode)
            sub_006C2110_StopModeThread(pServer);
        else
            sub_006C33D0_Stop(pServer);
    }

    sub_006BF320_FreeChain(pServer);
    sub_006BF0F0_FreeBuckets(pServer);
    sub_006BE3C0_Shutdown(pServer);

    for (int i = 0; i < 4; ++i)
    {
        if (pServer->aSockets[i] != -1)
        {
            sub_0040D880(pServer->aSockets[i]);
            pServer->aSockets[i] = -1;
        }
    }

    WSACleanup();
    DeleteCriticalSection(&pServer->tLock854);
    DeleteCriticalSection(&pServer->tLock894);
    DeleteCriticalSection(&pServer->tLock8B4);

    while (pServer->f_878)
    {
        D2QClientStrc* pNext = pServer->f_878->pNext;
        FOG_Free(pServer->f_878, gszQServerFile_006FC460, 0x183, 0);
        pServer->f_878 = pNext;
    }

    while (pServer->pChain88C)
    {
        D2QNodeStrc* pNext = pServer->pChain88C->pNext;
        FOG_Free(pServer->pChain88C, gszQServerFile_006FC460, 0x189, 0);
        pServer->pChain88C = pNext;
    }

    FOG_Free(pServer->p870, gszQServerFile_006FC460, 0x18D, 0);
    FOG_Free(pServer->p874, gszQServerFile_006FC460, 0x18E, 0);
    FOG_Free(pServer->p040, gszQServerFile_006FC460, 0x192, 0);
    FOG_Free(pServer->ppBuckets, gszQServerFile_006FC460, 0x193, 0);
    FOG_Free(pServer->p020, gszQServerFile_006FC460, 0x195, 0);
    DeleteCriticalSection(&pServer->tLock028);
    FOG_Free(pServer->p014, gszQServerFile_006FC460, 0x198, 0);

    for (int i = 0; i < gnLockCount_0074C3E0; ++i)
        DeleteCriticalSection(&pServer->pLocks[i]);

    FOG_Free(pServer->pLocks, gszQServerFile_006FC460, 0x19C, 0);
    FOG_Free(pServer, gszQServerFile_006FC460, 0x19F, 0);
    return 1;
}

#include "gen/data/Source/Storm/006C0170_sub_006C0170_DestroyServer.inc"
