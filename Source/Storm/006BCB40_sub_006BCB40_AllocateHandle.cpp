struct D2HandlePoolStrc
{
    char unk_000[0x100];
    int nCapacity;
    int nStride;
    int bInitialized;
    int nFirstFree;
    int nLastUsed;
    int nAllocated;
    unsigned short nSequence;
    unsigned short unk_11A;
    char* pEntries;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void*, int, unsigned int);

// 0x006BCB40
unsigned int __fastcall sub_006BCB40_AllocateHandle(D2HandlePoolStrc* pPool)
{
    unsigned int nHandle = -1;
    if (!pPool->bInitialized)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x87);
        exit(-1);
    }
    unsigned short* pEntry = (unsigned short*)(pPool->pEntries + pPool->nStride * pPool->nFirstFree);
    for (int nIndex = pPool->nFirstFree; nIndex < pPool->nCapacity; ++nIndex)
    {
        if (!*pEntry)
        {
            memset(pEntry, 0, pPool->nStride);
            *pEntry = pPool->nSequence;
            ++pPool->nSequence;
            if (!pPool->nSequence)
                pPool->nSequence = 0x8000;
            ++pPool->nAllocated;
            pPool->nFirstFree = nIndex + 1;
            if (pPool->nLastUsed < nIndex)
            {
                pPool->nLastUsed = nIndex;
                nHandle = *pEntry;
            }
            else
            {
                nHandle = *pEntry;
            }
            nHandle |= nIndex << 16;
            break;
        }
        pEntry = (unsigned short*)((char*)pEntry + pPool->nStride);
    }
    return nHandle;
}
