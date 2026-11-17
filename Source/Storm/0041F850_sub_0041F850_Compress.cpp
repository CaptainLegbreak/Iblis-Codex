struct D2StormHuffItemStrc;

struct D2StormHuffOutputStrc
{
    unsigned char* pOutputStart;
    unsigned int f_4;
    unsigned char* pOutput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    unsigned int sub_0041D940_GetSize();                                                                    // 0x0041D940
    void sub_0041D950_PutBits(unsigned int nValue, unsigned int nBits);                                     // 0x0041D950
    void sub_0041D9A0_Flush();                                                                              // 0x0041D9A0
};

struct D2StormHuffTreeStrc
{
    int bIsCmp0;
    unsigned int nUnk0x04;
    unsigned int unk0x08[0xC19];
    D2StormHuffItemStrc* pItemsByValue[0x102];

    void sub_0041D9E0_EncodeOne(D2StormHuffOutputStrc* pOutput, unsigned int nValue);                       // 0x0041D9E0
    void sub_0041EF20_BuildTree(unsigned char nCmpType);                                                    // 0x0041EF20
    void sub_0041F350_IncWeights(D2StormHuffItemStrc* pItem);                                               // 0x0041F350
    void sub_0041F510_InsertBranch(unsigned int nValue);                                                    // 0x0041F510
    unsigned int sub_0041F850_Compress(D2StormHuffOutputStrc* pOutput, void* pvIn, int cbIn, unsigned char nCmpType); // 0x0041F850
};

__declspec(noinline) void D2StormHuffOutputStrc::sub_0041D9A0_Flush()
{
    while (nBitCount)
    {
        if (f_4)
        {
            *pOutput++ = (unsigned char)nBitBuffer;
            f_4--;
        }
        nBitBuffer >>= 8;
        nBitCount -= nBitCount > 8 ? 8 : nBitCount;
    }
}

// 0x0041F850
unsigned int D2StormHuffTreeStrc::sub_0041F850_Compress(D2StormHuffOutputStrc* pOutput, void* pvIn, int cbIn, unsigned char nCmpType)
{
    sub_0041EF20_BuildTree(nCmpType);
    bIsCmp0 = nCmpType == 0;
    pOutput->sub_0041D950_PutBits(nCmpType, 8);
    unsigned char* pbIn = (unsigned char*)pvIn;
    while (cbIn != 0)
    {
        unsigned int nValue = *pbIn++;
        cbIn--;
        if (pItemsByValue[nValue] == 0)
        {
            sub_0041D9E0_EncodeOne(pOutput, 0x101);
            pOutput->sub_0041D950_PutBits(nValue, 8);
            sub_0041F510_InsertBranch(nValue);
            if (!bIsCmp0)
            {
                sub_0041F350_IncWeights(pItemsByValue[nValue]);
            }
        }
        else
        {
            sub_0041D9E0_EncodeOne(pOutput, nValue);
        }
        if (bIsCmp0)
        {
            sub_0041F350_IncWeights(pItemsByValue[nValue]);
        }
    }
    sub_0041D9E0_EncodeOne(pOutput, 0x100);
    pOutput->sub_0041D9A0_Flush();
    return pOutput->sub_0041D940_GetSize();
}
