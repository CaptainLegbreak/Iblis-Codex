void __stdcall SBigNew(void** phBig);                                                                       // 0x00423950
void __stdcall SBigDel(void* hBig);                                                                         // 0x00424E40

struct D2StormHandleStrc
{
    void* hHandle;

    D2StormHandleStrc();
    ~D2StormHandleStrc();
};

struct D2StormBitReaderStrc
{
    unsigned int* pData;
    unsigned int dwBits;
    int nBitsLeft;

    int sub_0041D8A0_ReadBit();
};

// 0x0041D320
D2StormHandleStrc::D2StormHandleStrc()
{
    SBigNew(&hHandle);
}

// 0x0041D330
D2StormHandleStrc::~D2StormHandleStrc()
{
    SBigDel(hHandle);
}

// 0x0041D8A0
int D2StormBitReaderStrc::sub_0041D8A0_ReadBit()
{
    int nBit = dwBits & 1;
    dwBits >>= 1;
    if (!--nBitsLeft)
    {
        dwBits = *pData++;
        nBitsLeft = 32;
    }
    return nBit;
}
