struct D2Record00648E40Strc
{
    unsigned char unk_00[0x90];
    unsigned char nValue90;
};

// 0x00648E40
void __stdcall sub_00648E40_SetByte90(D2Record00648E40Strc* pRecord, unsigned char nValue)
{
    pRecord->nValue90 = nValue;
}
