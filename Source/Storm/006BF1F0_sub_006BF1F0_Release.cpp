extern "C" int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x0040B3C0

struct D2QNode006BF1F0Strc
{
    unsigned int nKey;
    int nRefCount;
    D2QNode006BF1F0Strc* pNext;
};

struct D2QTable006BF1F0Strc
{
    unsigned char unk_00[0x10];
    unsigned int nBuckets;
    unsigned char unk_14[0x2C];
    D2QNode006BF1F0Strc** ppBuckets;
};

static __declspec(noinline) int sub_006BF1F0_Release(D2QTable006BF1F0Strc* pTable, unsigned int* pKey);

// 0x006BF1F0
static int sub_006BF1F0_Release(D2QTable006BF1F0Strc* pTable, unsigned int* pKey)
{
    const unsigned int nKey = *pKey;
    const unsigned int nBucket = nKey % pTable->nBuckets;
    D2QNode006BF1F0Strc* pPrev = 0;
    for (D2QNode006BF1F0Strc* pNode = pTable->ppBuckets[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            --pNode->nRefCount;
            if (pNode->nRefCount <= 0)
            {
                if (pPrev)
                {
                    pPrev->pNext = pNode->pNext;
                }
                else
                {
                    pTable->ppBuckets[nBucket] = pNode->pNext;
                }
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x940, 0);
            }
            return 1;
        }
        pPrev = pNode;
    }
    return 0;
}

// calling-convention shim (not game code)
int __stdcall shim_10(D2QTable006BF1F0Strc* pTable, unsigned int* pKey)
{
    return sub_006BF1F0_Release(pTable, pKey);
}
