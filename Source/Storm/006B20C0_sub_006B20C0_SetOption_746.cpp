extern int gnValue_0074C020; // 0x0074C020

// 0x006B20C0
int __fastcall sub_006B20C0_SetOption(int nId, int nValue)
{
    if (nId != 11)
        return 0;
    gnValue_0074C020 = nValue;
    return 1;
}
