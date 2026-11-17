struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
struct D2ServerNode006BE3C0Strc
{
    unsigned char unk_000[0x5BC];
    D2ServerNode006BE3C0Strc* pNext;
};
struct D2Server006BE3C0Strc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc tLock;
    unsigned char unk_86C[4];
    D2ServerNode006BE3C0Strc** ppHeads;
    D2ServerNode006BE3C0Strc** ppTails;
    unsigned char unk_878[4];
    int nSlots;
};

// 0x006BE3C0
int __stdcall sub_006BE3C0_FreeAllSlots(D2Server006BE3C0Strc* pServer)
{
    for (int i = 0; i < pServer->nSlots; ++i)
    {
        EnterCriticalSection(&pServer->tLock);
        D2ServerNode006BE3C0Strc* pNode = pServer->ppHeads[i];
        pServer->ppHeads[i] = 0;
        pServer->ppTails[i] = 0;
        LeaveCriticalSection(&pServer->tLock);
        while (pNode)
        {
            D2ServerNode006BE3C0Strc* pFree = pNode;
            pNode = pNode->pNext;
            FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x1B9, 0);
        }
    }
    return 1;
}
