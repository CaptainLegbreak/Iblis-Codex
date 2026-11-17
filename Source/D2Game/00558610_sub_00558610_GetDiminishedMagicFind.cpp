// 0x00558610
int __fastcall sub_00558610_GetDiminishedMagicFind(int nMagicFind, int nFactor, int nFactor2)
{
    if (nMagicFind <= 110) return nMagicFind;
    nMagicFind -= 100;
    nFactor2 *= nMagicFind;
    nMagicFind += nFactor;
    return nFactor2 / nMagicFind + 100;
}
