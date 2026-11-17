extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0

struct D2Unk00545D40Rec
{
    int nFirst;
    int nSecond;
    unsigned char nKind;
    unsigned char bActive;
    unsigned char b0A;
    unsigned char b0B;
    char unk0x0C[0x90];
    unsigned short w9C;
    char unk0x9E[0x5A];
};

// 0x00545D40
static void __stdcall sub_00545D40_InitRecord(D2Unk00545D40Rec* pRec, int nSecond, int nFirst, unsigned char nKind)
{
    memset(pRec, 0, sizeof(D2Unk00545D40Rec));
    pRec->nFirst = nFirst;
    pRec->nSecond = nSecond;
    pRec->b0A = 0;
    pRec->b0B = 0;
    pRec->bActive = 1;
    pRec->nKind = nKind;
    pRec->w9C = 0;
}

void __fastcall sub_K10_EmitInitRecord(D2Unk00545D40Rec* pRec, int n)
{
    sub_00545D40_InitRecord(pRec, n, n + 1, 2);
}
