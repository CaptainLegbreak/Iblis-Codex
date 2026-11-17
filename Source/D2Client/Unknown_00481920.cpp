#include "D2Client.h"

struct T00481920
{
    char unk0x00[0x58];
};

extern T00481920* gpSoundEnvironTxt_007BC9A8;                                                       // 0x007BC9A8

// 0x00481920
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId)
{
    if (gpSoundEnvironTxt_007BC9A8 && nEnvironId >= 0 && nEnvironId < gdwGlobal_007BC9AC)
    {
        return &gpSoundEnvironTxt_007BC9A8[nEnvironId];
    }
    return 0;
}
