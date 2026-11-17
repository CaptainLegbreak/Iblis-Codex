struct D2PaletteRecordStrc
{
    unsigned char ab[0x100];
};

unsigned char gabItemPalettes_00842710[9][0x6900];                                                            // 0x00842710

// 0x005038D0
unsigned char* __fastcall sub_005038D0_GetComponentPalette(int nColor)
{
    int nRow = nColor >> 5;
    unsigned int nCol = nColor & 0x1F;
    if (nCol <= 0x14)
    {
        if (nRow == 0)
            nRow = 8;
        else if (nRow < 0)
            return 0;
        else if (nRow >= 9)
            return 0;
        else
        {
            if (nRow > 2)
            {
                if (nRow <= 4)
                    goto fail;
            }
        }
        return ((D2PaletteRecordStrc (*)[0x69])gabItemPalettes_00842710)[nRow][nCol].ab;
    }
fail:
    return 0;
}
