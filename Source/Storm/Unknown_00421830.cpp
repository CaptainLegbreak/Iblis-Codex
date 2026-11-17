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

struct D2StormRecordStackStrc
{
    D2StormRecord14Strc pRecords[16];
    unsigned int nUsed;

    D2StormRecordStackStrc();
    ~D2StormRecordStackStrc();
};

// 0x00421830
D2StormRecordStackStrc::~D2StormRecordStackStrc()
{
}

// 0x00421B70
D2StormRecordStackStrc::D2StormRecordStackStrc() : nUsed(0)
{
}
