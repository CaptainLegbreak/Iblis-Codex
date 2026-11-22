struct D2StormRecord14Strc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
    unsigned int m_offset;

    D2StormRecord14Strc();                                                                                  // 0x00421B50
    ~D2StormRecord14Strc();                                                                                 // 0x00421810
};

struct BigStack
{
    D2StormRecord14Strc pRecords[16];
    unsigned int nUsed;

    BigStack();
    ~BigStack();
};

// 0x00421830
BigStack::~BigStack()
{
}

// 0x00421B70
BigStack::BigStack() : nUsed(0)
{
}
