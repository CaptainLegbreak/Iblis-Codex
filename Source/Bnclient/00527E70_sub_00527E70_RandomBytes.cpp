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

struct D2BigPowModStrc
{
    void* pUnknown0x00;
    void* hBase;
    void* hModulus;
    D2SrpDigestStrc tDigest;
    D2SrpDigestStrc tSavedDigest;
    unsigned char abOutput[0x14];
    unsigned int f_48;
};

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;

    void sub_00527E70_RandomBytes(unsigned char* pBuffer, unsigned int nSize);
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void __fastcall sub_00529F50_Sha1Init(D2SrpSha1ContextStrc* pContext);                                      // 0x00529F50
void __fastcall sub_00529F80_Sha1Update(D2SrpSha1ContextStrc* pContext, const unsigned char* pData, unsigned int nLength); // 0x00529F80
void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext);            // 0x0052A040

// 0x00527E70
void D2BigPairStrc::sub_00527E70_RandomBytes(unsigned char* pBuffer, unsigned int nSize)
{
    D2SrpSha1ContextStrc tContext;

    if (!nSize)
        return;

    unsigned int nAvail = pState->f_48;
    while (nSize > nAvail)
    {
        memcpy(pBuffer, &pState->abOutput[sizeof(pState->abOutput) - nAvail], nAvail);
        pBuffer += pState->f_48;
        nSize -= pState->f_48;
        sub_00529F50_Sha1Init(&tContext);
        sub_00529F80_Sha1Update(&tContext, pState->tDigest.ab, 0x14);
        sub_00529F80_Sha1Update(&tContext, pState->abOutput, 0x14);
        sub_00529F80_Sha1Update(&tContext, pState->tSavedDigest.ab, 0x14);
        sub_0052A040_Sha1Final(pState->abOutput, &tContext);
        pState->f_48 = 0x14;
        nAvail = pState->f_48;
    }

    if (nSize > 0)
    {
        memcpy(pBuffer, &pState->abOutput[sizeof(pState->abOutput) - pState->f_48], nSize);
        pState->f_48 -= nSize;
    }
}
