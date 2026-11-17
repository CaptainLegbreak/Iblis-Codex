unsigned int gnPaletteStart_008E9930;                                                                       // 0x008E9930
unsigned int gnPaletteEnd_008E902C;                                                                         // 0x008E902C
int gbTableSet_008E9D40;                                                                                    // 0x008E9D40
unsigned char gaTable_008E9830[0x100];                                                                      // 0x008E9830
int gnGlobal_008E9028;                                                                                      // 0x008E9028
unsigned int gdwSwappedColor_008E9D38;                                                                      // 0x008E9D38
extern unsigned char gaPcxPalette_008E9938[256 * 4];                                                        // 0x008E9938
int gnSquareTable_008E9034[511];                                                                            // 0x008E9034

// 0x006056D0
unsigned char __stdcall sub_006056D0_FindNearestPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    unsigned int nBestDistance = 0x7FFFFFFF;
    unsigned int nBestIndex = 0;
    for (unsigned int i = gnPaletteStart_008E9930; i <= gnPaletteEnd_008E902C; ++i)
    {
        if (gbTableSet_008E9D40 && !gaTable_008E9830[i])
        {
            continue;
        }

        if (gnGlobal_008E9028 && gdwSwappedColor_008E9D38 == ((((nRed << 8) | nGreen) << 8) | nBlue))
        {
            nBestIndex = 0;
            break;
        }

        unsigned int nDistance = gnSquareTable_008E9034[nRed - gaPcxPalette_008E9938[i * 4 + 2] + 255]
            + gnSquareTable_008E9034[nGreen - gaPcxPalette_008E9938[i * 4 + 1] + 255]
            + gnSquareTable_008E9034[nBlue - gaPcxPalette_008E9938[i * 4] + 255];
        if (nDistance < nBestDistance)
        {
            nBestDistance = nDistance;
            nBestIndex = i;
        }
    }

    return (unsigned char)nBestIndex;
}
