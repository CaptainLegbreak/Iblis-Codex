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

struct D2UnkPathStrc2
{
    unsigned char unk0x00;
    unsigned char unk0x01;
    unsigned char unk0x02;
};

extern const D2UnkPathStrc stru_6FDD2158[25];                                                               // 0x006F1518
extern const D2UnkPathStrc2 byte_6FDD2288[25];                                                              // 0x006F1648
int __stdcall sub_00678C10(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2);           // 0x00678C10

// 0x00678CD0
int __stdcall sub_00678CD0_GetFirstDirection(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    return byte_6FDD2288[sub_00678C10(pPoint1, pPoint2)].unk0x00;
}

// 0x00678D70
void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nIndex = sub_00678C10(pPoint1, pPoint2);

    pTestDir[0] = stru_6FDD2158[nIndex].unk0x00;
    pTestDir[1] = stru_6FDD2158[nIndex].unk0x04;
    pTestDir[2] = stru_6FDD2158[nIndex].unk0x08;
}

// 0x00678DF0
void __fastcall sub_00678DF0(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nIndex = sub_00678C10(pPoint1, pPoint2);

    pTestDir[0] = byte_6FDD2288[nIndex].unk0x00;
    pTestDir[1] = byte_6FDD2288[nIndex].unk0x01;
    pTestDir[2] = byte_6FDD2288[nIndex].unk0x02;
}
