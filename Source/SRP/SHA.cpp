struct Context00529F50 {
    unsigned int dwH0;
    unsigned int dwH1;
    unsigned int dwH2;
    unsigned int dwH3;
    unsigned int dwH4;
    unsigned int dwCountLow;
    unsigned int dwCountHigh;
};

struct T0041D340
{
    unsigned int state[5];
    unsigned int count[2];
    unsigned char buffer[64];
};

struct D2SrpSha1ContextStrc
{
    unsigned int aState[5];
    unsigned int aCount[2];
    unsigned char f_1C[64];
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags);         // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                 // 0x00412650
void __fastcall sub_00529F80_SHA1Update(T0041D340* context, unsigned char* data, unsigned int len); // 0x00529F80
void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext);            // 0x0052A040

// build: symbol @sub_00529F50@4 0x00529F50
extern "C" __declspec(dllexport) __declspec(noinline) void __fastcall sub_00529F50(Context00529F50* pContext) {
    pContext->dwH0 = 0x67452301;
    pContext->dwH1 = 0xEFCDAB89;
    pContext->dwH2 = 0x98BADCFE;
    pContext->dwH3 = 0x10325476;
    pContext->dwH4 = 0xC3D2E1F0;
    pContext->dwCountLow = pContext->dwCountHigh = 0;
}

// 0x0052A120
unsigned char* __fastcall SHA_Interleave(unsigned char* key, const unsigned char* sk, unsigned int sklen)
{
    unsigned int i;
    unsigned int klen;
    unsigned char* hbuf;
    unsigned char hout[20];
    T0041D340 ctxt;

    do
    {
        if (*sk != 0)
            break;
        ++sk;
    } while (--sklen);

    if (sklen & 1)
    {
        ++sk;
        --sklen;
    }

    klen = sklen >> 1;
    hbuf = (unsigned char*)SMemAlloc(klen, ".\\SHA.cpp", 0xC8, 0);
    if (!hbuf)
        return 0;

    for (i = 0; i < klen; ++i)
        hbuf[i] = sk[i * 2];
    sub_00529F50((Context00529F50*)&ctxt);
    sub_00529F80_SHA1Update(&ctxt, hbuf, klen);
    sub_0052A040_Sha1Final(hout, (D2SrpSha1ContextStrc*)&ctxt);
    for (i = 0; i < sizeof(hout); ++i)
        key[i * 2] = hout[i];

    for (i = 0; i < klen; ++i)
        hbuf[i] = sk[i * 2 + 1];
    sub_00529F50((Context00529F50*)&ctxt);
    sub_00529F80_SHA1Update(&ctxt, hbuf, klen);
    sub_0052A040_Sha1Final(hout, (D2SrpSha1ContextStrc*)&ctxt);
    for (i = 0; i < sizeof(hout); ++i)
        key[i * 2 + 1] = hout[i];

    SMemFree(hbuf, ".\\SHA.cpp", 0xEF, 0);
    return key;
}
