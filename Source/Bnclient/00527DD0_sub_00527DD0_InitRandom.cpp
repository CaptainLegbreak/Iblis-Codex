struct D2SrpSha1ContextStrc
{
    unsigned int aState[5];
    unsigned int aCount[2];
    unsigned char f_1C[64];
};

struct D2SrpDigestStrc
{
    unsigned char ab[20];
};

struct D2SrpSeedRecordStrc
{
    long nTime;
    unsigned int nSeed;
    int nRandom;
};

struct D2BigPowModStrc
{
    void* pUnknown0x00;
    void* hBase;
    void* hModulus;
    D2SrpDigestStrc tDigest;
    D2SrpDigestStrc tSavedDigest;
    unsigned int aClear[6];

    void sub_00527DD0_InitRandom(unsigned int nSeed);
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
extern "C" void __cdecl srand(unsigned int nSeed);                                                          // 0x00687454
extern "C" int __cdecl rand();                                                                              // 0x00687461
void __fastcall sub_00529F50_Sha1Init(D2SrpSha1ContextStrc* pContext);                                      // 0x00529F50
void __fastcall sub_00529F80_Sha1Update(D2SrpSha1ContextStrc* pContext, const unsigned char* pData, unsigned int nLength); // 0x00529F80
void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext);            // 0x0052A040

// 0x00527DD0
void D2BigPowModStrc::sub_00527DD0_InitRandom(unsigned int nSeed)
{
    D2SrpSeedRecordStrc tRecord;
    D2SrpSha1ContextStrc tContext;
    _time32(&tRecord.nTime);
    tRecord.nSeed = nSeed;
    srand(nSeed);
    tRecord.nRandom = rand();
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)&tRecord, sizeof(tRecord));
    sub_0052A040_Sha1Final(tDigest.ab, &tContext);
    memcpy(&tSavedDigest, &tDigest, sizeof(tSavedDigest));
    memset(aClear, 0, sizeof(aClear));
}
