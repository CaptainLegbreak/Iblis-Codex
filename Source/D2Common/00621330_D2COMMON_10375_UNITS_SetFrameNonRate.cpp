struct D2UnitStrc
{
    unsigned char unk_00[0x44];
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
};

// 0x00621330
void __stdcall D2COMMON_10375_UNITS_SetFrameNonRate(D2UnitStrc* pUnit, int nRate, int nFailRate)
{
    nFailRate <<= 8;
    pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;

    if (pUnit->nSeqCurrentFramePrecise >= nFailRate)
    {
        pUnit->nSeqCurrentFramePrecise -= nFailRate - (nRate << 8);
    }
}
