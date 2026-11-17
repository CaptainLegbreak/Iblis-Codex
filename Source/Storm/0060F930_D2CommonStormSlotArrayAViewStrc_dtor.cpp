struct D2CommonStormSlotListAStrc;

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayAStrc();                                                                         // 0x0060F610
};

struct D2CommonStormSlotArrayAViewStrc : D2CommonStormSlotArrayAStrc
{
    ~D2CommonStormSlotArrayAViewStrc();
};

// 0x0060F930
D2CommonStormSlotArrayAViewStrc::~D2CommonStormSlotArrayAViewStrc()
{
}
