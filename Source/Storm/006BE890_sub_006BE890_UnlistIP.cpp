struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __cdecl sub_00410660_Log(const char* szChannel, const char* szFormat, ...); // 0x00410660
extern unsigned long gdwLastHackListLog_00989C34; // 0x00989C34

struct D2HackNode006BE890Strc
{
    unsigned int f_0;
    unsigned char f_4[8];
    D2HackNode006BE890Strc* pNext;
};
struct D2Server006BE890Strc
{
    unsigned char unk_000[0x890];
    int nHackListSize;
    D2CriticalSectionStrc tLock;
    D2HackNode006BE890Strc** ppBuckets;
    unsigned int f_8B0;
    unsigned char unk_8B4[0xBD0 - 0x8B4];
    int bHackList;
};

// 0x006BE890
void __fastcall sub_006BE890_UnlistIP(D2Server006BE890Strc* pServer, const char* szFile, unsigned int dwAddress, int nLine)
{
    if (!pServer->bHackList)
        return;

    EnterCriticalSection(&pServer->tLock);
    unsigned int nBucket = dwAddress % pServer->f_8B0;
    D2HackNode006BE890Strc* pPrev = 0;
    D2HackNode006BE890Strc* pNode = pServer->ppBuckets[nBucket];
    while (pNode)
    {
        D2HackNode006BE890Strc* pNext = pNode->pNext;
        if (pNode->f_0 == dwAddress)
        {
            if (pPrev)
            {
                pPrev->pNext = pNext;
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x4D0, 0);
                pNode = pPrev;
            }
            else
            {
                pServer->ppBuckets[nBucket] = pServer->ppBuckets[nBucket]->pNext;
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x4D7, 0);
                pNode = 0;
            }
            --pServer->nHackListSize;
        }
        pPrev = pNode;
        pNode = pNext;
    }
    LeaveCriticalSection(&pServer->tLock);

    int nSize = pServer->nHackListSize;
    unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastHackListLog_00989C34 > 2000)
    {
        sub_00410660_Log("HACK", "[HACKLIST]  Hacklist size is %d", nSize);
        gdwLastHackListLog_00989C34 = dwTick;
    }
}
