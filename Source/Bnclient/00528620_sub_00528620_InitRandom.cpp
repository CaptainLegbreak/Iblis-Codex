struct D2BigPowModStrc
{
    void sub_00527DD0_InitRandom(unsigned int nSeed);                                                       // 0x00527DD0
};

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;

    void sub_00528620_InitRandom(unsigned int nSeed);
};

// 0x00528620
void D2BigPairStrc::sub_00528620_InitRandom(unsigned int nSeed)
{
    pState->sub_00527DD0_InitRandom(nSeed);
}
