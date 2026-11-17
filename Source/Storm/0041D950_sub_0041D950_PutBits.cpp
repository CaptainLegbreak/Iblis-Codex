struct D2StormHuffInputStrc
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    D2StormHuffInputStrc(void* pInputBuffer);
};

struct D2StormHuffOutputStrc
{
    unsigned char* pOutputStart;
    unsigned int f_4;
    unsigned char* pOutput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    D2StormHuffOutputStrc(void* pOutputBuffer, unsigned int nOutputSize);
    void sub_0041D950_PutBits(unsigned int nValue, unsigned int nBits);
};

// 0x0041D950
void D2StormHuffOutputStrc::sub_0041D950_PutBits(unsigned int nValue, unsigned int nBits)
{
    nBitBuffer |= nValue << nBitCount;
    nBitCount += nBits;
    while (nBitCount >= 8)
    {
        if (f_4)
        {
            *pOutput++ = (unsigned char)nBitBuffer;
            f_4--;
        }
        nBitBuffer >>= 8;
        nBitCount -= 8;
    }
}
