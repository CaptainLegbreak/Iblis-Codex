struct D2GfxCellStrc
{
    unsigned int dwFlags;
    unsigned int dwWidth;
    unsigned int dwHeight;
    int nXOffset;
    int nYOffset;
    unsigned int unk0x14;
    unsigned int dwParent;
    unsigned int dwLength;
    unsigned char pPixels[1];
};

// 0x00606B00
void __fastcall sub_00606B00_RemapRleCell(D2GfxCellStrc* pCell, const unsigned char* pRemap)
{
    int nRows = pCell->dwHeight;
    unsigned char* pData = pCell->pPixels;
    for (;;)
    {
        const char nCode = *pData++;
        if (nCode < 0)
        {
            if (!(nCode & 0x7F))
            {
                if (!--nRows)
                {
                    return;
                }
            }
        }
        else
        {
            for (int i = 0; i < nCode; ++i)
            {
                *pData = pRemap[*pData];
                ++pData;
            }
        }
    }
}
