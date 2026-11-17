struct D2Config006C8250Strc
{
    int n000;
    int n004;
    int n008;
    unsigned char unk_00C[0xF8];
    int n104;
    int n108;
    int n10C;
};
extern int gaSelectorValues_0074C5A0[]; // 0x0074C5A0
extern D2Config006C8250Strc* gpConfig_007C9150; // 0x007C9150

// 0x006C8250
int __fastcall sub_006C8250_GetSetting(unsigned int nSelector, int* pValue)
{
    *pValue = gaSelectorValues_0074C5A0[nSelector];
    switch (nSelector)
    {
    case 0:
        return gpConfig_007C9150->n008;
    case 1:
        return gpConfig_007C9150->n004;
    case 2:
        return gpConfig_007C9150->n000;
    case 3:
        return gpConfig_007C9150->n104;
    case 4:
        return gpConfig_007C9150->n108;
    case 6:
        return gpConfig_007C9150->n10C;
    }
    return 0;
}
