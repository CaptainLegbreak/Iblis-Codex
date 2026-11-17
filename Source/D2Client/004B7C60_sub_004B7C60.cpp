int __fastcall sub_00469D90(int nA, int nB);                                                                // 0x00469D90
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
extern int gnGlobal_007273F4;                                                                               // 0x007273F4
extern int gnGlobal_00727400;                                                                               // 0x00727400

// 0x004B7C60
void __cdecl sub_004B7C60()
{
    if (sub_00469D90(0x26, 1))
    {
        unsigned short nValue = sub_00469AA0(0x26, 1);
        if (nValue != 0xFFFF && nValue <= 0xDF)
        {
            gnGlobal_007273F4 = nValue;
        }
    }
    if (sub_00469D90(0x26, 0))
    {
        unsigned short nValue = sub_00469AA0(0x26, 0);
        if (nValue != 0xFFFF && nValue <= 0xDF)
        {
            gnGlobal_00727400 = nValue;
        }
    }
}

#include "gen/data/Source/D2Client/004B7C60_sub_004B7C60.inc"
