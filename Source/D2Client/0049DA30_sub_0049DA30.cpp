struct D2UnitStrc
{
    char unk0x00[0x0C];
    int dwUnitId;
};

unsigned char gnGlobal_007BF23A;                                                                            // 0x007BF23A
extern int gdwGlobal_007BF23B;                                                                              // 0x007BF23B

// 0x0049DA30
void __fastcall sub_0049DA30(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        gdwGlobal_007BF23B = pUnit->dwUnitId;
        gnGlobal_007BF23A = 1;
    }
    else
    {
        gnGlobal_007BF23A = 0;
    }
}
