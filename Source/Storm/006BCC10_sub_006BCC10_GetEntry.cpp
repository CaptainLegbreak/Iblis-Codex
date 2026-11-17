extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HandleTable006BCC10Strc
{
    unsigned char unk_000[0x100];
    int nCount;
    int nStride;
    int bLive;
    unsigned char unk_10C[0x10];
    unsigned char* pEntries;
};

// 0x006BCC10
unsigned short* __fastcall sub_006BCC10_GetEntry(D2HandleTable006BCC10Strc* pTable, int nHandle)
{
    unsigned short* pResult = 0;
    if (nHandle != -1)
    {
        const short nIndex = (short)(nHandle >> 16);
        D2_ASSERT(nIndex >= 0 && nIndex < pTable->nCount, 0xDB);
        D2_ASSERT(pTable->bLive, 0xDE);
        unsigned short* pEntry = (unsigned short*)(pTable->pEntries + pTable->nStride * nIndex);
        const unsigned short nTag = (unsigned short)nHandle;
        if (*pEntry && (!nTag || *pEntry == nTag))
        {
            pResult = pEntry;
        }
    }
    return pResult;
}
