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

// 0x00678B80
static int __fastcall sub_6FDAB610(int nX1, int nY1, int nX2, int nY2)
{
    int nAbsDiffX = nX2 - nX1;
    int nAbsDiffY = nY2 - nY1;
    int nDiffX = nAbsDiffX;
    int nDiffY = nAbsDiffY;

    if (nAbsDiffX < 0)
        nAbsDiffX = -nAbsDiffX;
    if (nAbsDiffY < 0)
        nAbsDiffY = -nAbsDiffY;

    if (nAbsDiffX >= 2 * nAbsDiffY)
    {
        if (nDiffY < 0)
            nDiffY = -1;
        else
            nDiffY &= 1;
    }
    else if (nAbsDiffY >= 2 * nAbsDiffX)
    {
        if (nDiffX < 0)
            nDiffX = -1;
        else
            nDiffX &= 1;
    }

    if (nDiffX < -1)
        nDiffX = -2;
    else if (nDiffX > 1)
        nDiffX = 2;

    if (nDiffY < -1)
        nDiffY = -2;
    else if (nDiffY > 1)
        nDiffY = 2;

    return nDiffY + 5 * nDiffX + 12;
}

// 0x00678CB0
int __fastcall sub_00678CB0_GetFirstDirectionXY(int nX1, int nY1, int nX2, int nY2)
{
    return byte_6FDD2288[sub_6FDAB610(nX1, nY1, nX2, nY2)].unk0x00;
}

// 0x00678CF0
int __fastcall sub_6FDAB750(int nX1, int nY1, int nX2, int nY2)
{
    return stru_6FDD2158[sub_6FDAB610(nX1, nY1, nX2, nY2)].unk0x00;
}

// 0x00678D30
void __fastcall sub_00678D30_GetDirectionsXY(int nX1, int nY1, int nX2, int nY2, int* pTestDir)
{
    int nIndex = sub_6FDAB610(nX1, nY1, nX2, nY2);

    pTestDir[0] = stru_6FDD2158[nIndex].unk0x00;
    pTestDir[1] = stru_6FDD2158[nIndex].unk0x04;
    pTestDir[2] = stru_6FDD2158[nIndex].unk0x08;
}

// 0x00678DB0
void __fastcall sub_00678DB0_GetDirectionTripletXY(int nX1, int nY1, int nX2, int nY2, int* pTestDir)
{
    int nIndex = sub_6FDAB610(nX1, nY1, nX2, nY2);

    pTestDir[0] = byte_6FDD2288[nIndex].unk0x00;
    pTestDir[1] = byte_6FDD2288[nIndex].unk0x01;
    pTestDir[2] = byte_6FDD2288[nIndex].unk0x02;
}

#include "gen/data/Source/D2Common/00678B80_sub_6FDAB610.inc"
