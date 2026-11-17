struct D2ClientValues40Strc
{
    char unk0x00[0x14];
    int nValues[0x40];
};

// 0x004C0CE0
D2ClientValues40Strc* __fastcall sub_004C0CE0_ClearValues(D2ClientValues40Strc* pValues)
{
    for (int i = 0; i < 0x40; ++i)
    {
        pValues->nValues[i] = 0;
    }
    return pValues;
}
