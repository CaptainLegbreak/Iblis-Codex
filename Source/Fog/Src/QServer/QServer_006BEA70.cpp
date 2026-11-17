typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006BEA70_Client
{
    char unk_000[0x5BC];
    sub_006BEA70_Client* pNext;
};

struct sub_006BEA70_Server
{
    char unk_000[0x854];
    char cs[0x1C];
    sub_006BEA70_Client** ppBuckets;
    char unk_874[8];
    int nBuckets;
};

// 0x006BEA70
int __stdcall sub_006BEA70_CountBucket(sub_006BEA70_Server* pServer, int nBucket)
{
    if (nBucket >= pServer->nBuckets)
        return -1;

    int nCount = 0;
    EnterCriticalSection((CRITICAL_SECTION*)pServer->cs);
    for (sub_006BEA70_Client* pClient = pServer->ppBuckets[nBucket]; pClient; pClient = pClient->pNext)
        ++nCount;
    LeaveCriticalSection((CRITICAL_SECTION*)pServer->cs);
    return nCount;
}
