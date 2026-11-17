struct Unicode
{
    unsigned short wChar;
    Unicode() {}
    Unicode(unsigned short wValue) : wChar(wValue) {}
    Unicode sub_004B15F0() const;
};
extern unsigned short gaCaseTable_00730778[];  // 0x00730778
enum { CASE_BOUND = 0x100 };
// 0x004B15F0
Unicode Unicode::sub_004B15F0() const
{
    return Unicode(wChar < CASE_BOUND ? gaCaseTable_00730778[wChar] : wChar);
}

#include "gen/data/Source/D2Client/004B15F0_sub_004B15F0.inc"
