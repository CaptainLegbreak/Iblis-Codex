struct D2InAddrStrc
{
    unsigned long s_addr;
};

struct D2QServerIpNodeStrc
{
    unsigned long nAddress;
    int nCount;
    D2QServerIpNodeStrc* pNext;
};

struct D2QueueServerStrc
{
    char unk0x00[0x10];
    unsigned int nIpBuckets;
    char unk0x14[0x40 - 0x14];
    D2QServerIpNodeStrc** ppIpBuckets;
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

static __declspec(noinline) int __cdecl sub_006BF180_IncrementPerIpConnCount(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress);

// 0x006BF180
static int __cdecl sub_006BF180_IncrementPerIpConnCount(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress)
{
    const unsigned long nAddress = pAddress->s_addr;
    const unsigned int nBucket = nAddress % pServer->nIpBuckets;

    for (D2QServerIpNodeStrc* pNode = pServer->ppIpBuckets[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nAddress == nAddress)
        {
            ++pNode->nCount;
            return 1;
        }
    }

    D2QServerIpNodeStrc* pNew = (D2QServerIpNodeStrc*)FOG_Alloc(sizeof(D2QServerIpNodeStrc), ".\\Src\\QServer\\QServer.cpp", 0x919, 0);
    pNew->nAddress = nAddress;
    pNew->nCount = 1;
    pNew->pNext = pServer->ppIpBuckets[nBucket];
    pServer->ppIpBuckets[nBucket] = pNew;
    return 1;
}

// build: context sub_006BF180_Shim
// calling-convention shim (not game code)
int __cdecl sub_006BF180_Shim(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress)
{
    return sub_006BF180_IncrementPerIpConnCount(pServer, pAddress);
}
