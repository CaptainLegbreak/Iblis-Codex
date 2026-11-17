extern "C" double __cdecl sqrt(double x);                                                                   // 0x006879C0
extern "C" void __cdecl _chkstk();                                                                          // 0x006831B0
extern "C" void __cdecl _ftol2_sse();                                                                       // 0x00682FD0

extern int gnRemapStart_008E9D48[80];                                                                       // 0x008E9D48
extern int gnRemapEnd_008E9E88[80];                                                                         // 0x008E9E88
extern int gnRemapOffsets_008E9FC8[80 * 80];                                                                // 0x008E9FC8

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x006089F0
void __fastcall sub_006089F0_BuildRemap(int nPitch)
{
    int aInside[80][80];

    for (int y = 0; y < 80; ++y)
    {
        for (int x = 0; x < 80; ++x)
        {
            int nDX = x - 40;
            int nNewX = nDX;
            int nDY = y - 40;
            int nDist = nDX * nDX + nDY * nDY;
            aInside[x][y] = nDist < 1600;
            if (aInside[x][y])
            {
                int nScaled = nDist * nDist / 1600;
                nDist = (int)(float)sqrt((double)nDist);
                nScaled = (int)(float)sqrt((double)nScaled);
                if (nScaled < nDist / 2)
                    nScaled = nDist / 2;

                if (nDist)
                {
                    nNewX = nDX * nScaled / nDist;
                    nDY = nScaled * nDY / nDist;
                }

                int nSrcX = nNewX + 40;
                nDY += 40;
                nSrcX = ((nSrcX <= 0) - 1) & nSrcX;
                const int nClampX = D2_MIN(nSrcX, 79);
                int nSrcY = ((nDY <= 0) - 1) & nDY;
                nSrcY = D2_MIN(nSrcY, 79);
                gnRemapOffsets_008E9FC8[y * 80 + x] = (nSrcY - y) * nPitch - x + nClampX;
            }
        }
    }

    for (int y = 0; y < 80; ++y)
    {
        gnRemapStart_008E9D48[y] = 0;
        gnRemapEnd_008E9E88[y] = 0;

        int x;
        for (x = 0; x < 80; ++x)
        {
            if (aInside[x][y])
                break;
        }

        if (x < 80)
        {
            gnRemapStart_008E9D48[y] = x;
            while (aInside[x][y])
                ++x;
            gnRemapEnd_008E9E88[y] = x;
        }
    }
}
