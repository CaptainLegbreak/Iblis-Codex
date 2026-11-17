struct D2BigPowModStrc
{
    D2BigPowModStrc();

    int bValid;
    void* hBase;
    void* hModulus;
    unsigned char abRandomState[0x3C];
    unsigned int nRandomBytesLeft;
};

// 0x00527DC0
D2BigPowModStrc::D2BigPowModStrc() : bValid(0), nRandomBytesLeft(0)
{
}
