void __fastcall sub_006C8A60_Draw(int nArg1, int nArg2, int a, int b, int c, int nLevel); // 0x006C8A60

// 0x006C8C00
void __fastcall sub_006C8C00_DrawAlpha(int nArg1, int nArg2, int a, int b, int c, unsigned char nAlpha)
{
    int nLevel;
    if (nAlpha >= 0xC0)
        nLevel = 5;
    else if (nAlpha >= 0x80)
        nLevel = 2;
    else if (nAlpha >= 0x40)
        nLevel = 1;
    else if (nAlpha > 0)
        nLevel = 0;
    else
        return;
    sub_006C8A60_Draw(nArg1, nArg2, a, b, c, nLevel);
}
