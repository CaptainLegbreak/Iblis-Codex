struct D2StormHuffItemStrc;

struct D2StormHuffInputStrc
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    unsigned int Get8Bits()
    {
        if (nBitCount <= 8)
        {
            nBitBuffer |= *(unsigned short*)pInput << nBitCount;
            nBitCount += 16;
            pInput += 2;
        }
        unsigned int nValue = nBitBuffer & 0xFF;
        nBitBuffer >>= 8;
        nBitCount -= 8;
        return nValue;
    }
};

struct D2StormHuffTreeStrc
{
    int bIsCmp0;
    int unk0x04;
    unsigned int unk0x08[0xC19];
    D2StormHuffItemStrc* pItemsByValue[0x102];

    void sub_0041EF20_BuildTree(unsigned char nCmpType);                                                    // 0x0041EF20
    unsigned int sub_0041EBC0_DecodeOne(D2StormHuffInputStrc* pInput);                                      // 0x0041EBC0
    void sub_0041F510_InsertBranch(unsigned int nValue);                                                    // 0x0041F510
    void sub_0041F350_IncWeights(D2StormHuffItemStrc* pItem);                                               // 0x0041F350
    unsigned int sub_0041F740_Decompress(void* pOutput, unsigned int nOutputSize, D2StormHuffInputStrc* pInput); // 0x0041F740
};

// 0x0041F740
unsigned int D2StormHuffTreeStrc::sub_0041F740_Decompress(void* pOutput, unsigned int nOutputSize, D2StormHuffInputStrc* pInput)
{
    if (!nOutputSize)
    {
        return 0;
    }
    unsigned char nType = pInput->Get8Bits();
    sub_0041EF20_BuildTree(nType);
    bIsCmp0 = nType == 0;
    unsigned char* pbOut = (unsigned char*)pOutput;
    for (;;)
    {
        unsigned int nValue = sub_0041EBC0_DecodeOne(pInput);
        if (nValue == 0x101)
        {
            nValue = pInput->Get8Bits();
            sub_0041F510_InsertBranch(nValue);
            if (!bIsCmp0)
            {
                sub_0041F350_IncWeights(pItemsByValue[nValue]);
            }
        }
        if (nValue == 0x100)
        {
            return (unsigned int)(pbOut - (unsigned char*)pOutput);
        }
        *pbOut++ = (unsigned char)nValue;
        if (--nOutputSize == 0)
        {
            return (unsigned int)(pbOut - (unsigned char*)pOutput);
        }
        if (bIsCmp0)
        {
            sub_0041F350_IncWeights(pItemsByValue[nValue]);
        }
    }
}
