extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct D2Block0060A050Strc
{
    unsigned char unk_00[0x0A];
    unsigned short nSize;
    unsigned char unk_0C[0x04];
    unsigned int pData;
};

struct D2BlockSet0060A050Strc
{
    unsigned char unk_00[0x50];
    int nBlocks;
    D2Block0060A050Strc* pBlocks;
};

static __declspec(noinline) int sub_0060A050_Serialize(unsigned char* pOut, D2BlockSet0060A050Strc* pSet);

// 0x0060A050
static int sub_0060A050_Serialize(unsigned char* pOut, D2BlockSet0060A050Strc* pSet)
{
    unsigned char* pStart = pOut;
    int nTotal = pSet->nBlocks * sizeof(D2Block0060A050Strc);
    memcpy(pOut, pSet->pBlocks, nTotal);
    D2Block0060A050Strc* pOutBlocks = (D2Block0060A050Strc*)pOut;
    pOut += nTotal;
    for (int i = 0; i < pSet->nBlocks; ++i)
    {
        D2Block0060A050Strc* pBlock = &pSet->pBlocks[i];
        memcpy(pOut, (const void*)pBlock->pData, pBlock->nSize);
        pOutBlocks[i].pData = pOut - pStart;
        nTotal += pBlock->nSize;
        pOut += pBlock->nSize;
    }
    return nTotal;
}

// calling-convention shim (not game code)
int __stdcall shim_5(unsigned char* pOut, D2BlockSet0060A050Strc* pSet)
{
    return sub_0060A050_Serialize(pOut, pSet);
}
