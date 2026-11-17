struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2UnkPathStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

int __stdcall sub_00678C10(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2);           // 0x00678C10
extern const D2UnkPathStrc stru_6FDD2158[25];                                                               // 0x006F1518

// 0x00678D10
int __stdcall sub_6FDAB770(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    return stru_6FDD2158[sub_00678C10(tPoint1, tPoint2)].unk0x00;
}
