struct D2Record5F6E20Strc
{
    char unk0x00[0x32];
    short nMax;
    short nCurrent;
};

// 0x005F6E20
int __fastcall sub_005F6E20_GetPercentOver100(D2Record5F6E20Strc* pRecord)
{
    int nResult = 0;
    const short nMax = pRecord->nMax;
    if (nMax > 0)
    {
        nResult = pRecord->nCurrent * 100 / nMax - 100;
        nResult = nResult > 0 ? nResult : 0;
        if (nResult >= 120)
        {
            nResult = 120;
        }
    }

    return nResult;
}
