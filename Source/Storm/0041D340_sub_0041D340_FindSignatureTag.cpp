struct T0041D340
{
    unsigned __int64 nBitCount;
    unsigned int aState[5];
    unsigned char f_1C[64];

    void sub_00425D90_Init();                                                                               // 0x00425D90
    void sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen);                                // 0x00425DD0
    void sub_00425F00_Final(unsigned char* pDigest);                                                        // 0x00425F00
};

struct D2StormRsaKeyStrc
{
    void* f_0;
    void* f_4;

    D2StormRsaKeyStrc();                                                                                    // 0x0041D4D0
    ~D2StormRsaKeyStrc();                                                                                   // 0x0041D530
    void sub_00426070_SetKey(const void* pExponent, unsigned int nExponentSize, const void* pModulus, int nModulusSize); // 0x00426070
    void sub_004260A0_Process(unsigned char* pData, unsigned int nSize);                                    // 0x004260A0
};

int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize);                              // 0x0041D200
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                             // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith);                   // 0x0041D2C0
extern "C" void* __cdecl _alloca(unsigned int nSize);

// 0x0041D340
static __declspec(noinline) int __stdcall sub_0041D340_FindSignatureTag(const char* pData, unsigned int nSize, unsigned int nSignSize, unsigned int* pOffset)
{
    *pOffset = nSize - nSignSize - 4;
    if (nSize >= nSignSize + 4 && *(const int*)(pData + *pOffset) == 0x5349474E)
        return 1;
    return 0;
}

// 0x0041D370
static __declspec(noinline) void __stdcall sub_0041D370_HashData(unsigned int nLen, const unsigned char* pData, unsigned char* pDigest)
{
    T0041D340 tHash;
    tHash.sub_00425D90_Init();
    tHash.sub_00425DD0_Update(pData, nLen);
    tHash.sub_00425F00_Final(pDigest);
}

// 0x0041D590
int __fastcall sub_0041D590_SignBuffer(char* pData, unsigned int* pnSize, const void* pExponent, unsigned int nSignSize, const void* pModulus1, int nModulusSize1, const void* pModulus2, int nModulusSize2)
{
    unsigned int nOffset;
    if (!sub_0041D340_FindSignatureTag(pData, *pnSize, nSignSize, &nOffset))
        nOffset = *pnSize;
    unsigned char* pDigest = (unsigned char*)_alloca(nSignSize);
    SMemFill(pDigest, nSignSize, 0xBB);
    pDigest[nSignSize - 1] = 0x0B;
    sub_0041D370_HashData(nOffset, (const unsigned char*)pData, pDigest);
    unsigned char* pSign = (unsigned char*)_alloca(nSignSize);
    SMemCopy(pSign, pDigest, nSignSize);
    D2StormRsaKeyStrc tKey1;
    tKey1.sub_00426070_SetKey(pExponent, nSignSize, pModulus1, nModulusSize1);
    tKey1.sub_004260A0_Process(pSign, nSignSize);
    unsigned char* pCheck = (unsigned char*)_alloca(nSignSize);
    SMemCopy(pCheck, pSign, nSignSize);
    D2StormRsaKeyStrc tKey2;
    tKey2.sub_00426070_SetKey(pExponent, nSignSize, pModulus2, nModulusSize2);
    tKey2.sub_004260A0_Process(pCheck, nSignSize);
    if (SMemCmp(pCheck, pDigest, nSignSize))
        return 0;
    *(int*)(pData + nOffset) = 0x5349474E;
    SMemCopy(pData + nOffset + 4, pSign, nSignSize);
    *pnSize = nOffset + nSignSize + 4;
    return 1;
}
