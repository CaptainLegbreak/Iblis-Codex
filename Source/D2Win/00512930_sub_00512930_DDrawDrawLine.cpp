extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern unsigned char* gpScreenBuffer_007C9154; // 0x007C9154

static void __fastcall DDRAW_PutPixel(int nX, int nY, unsigned char nColor)
{
    if (nX >= 0 && nX < gnScreenWidth_007C9138 && nY >= 0 && nY < gnScreenHeight_007C913C)
        gpScreenBuffer_007C9154[gnScreenWidth_007C9138 * nY + nX] = nColor;
}

// 0x00512930
void __fastcall sub_00512930_DDrawDrawLine(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nUnused)
{
    int nX = nX1;
    int nY = nY1;
    int nDX = nX2 - nX1;
    int nDY = nY2 - nY1;
    int nStepX;
    int nStepY;

    if (nDX < 0)
    {
        nStepX = -1;
        nDX = -nDX;
    }
    else
    {
        nStepX = 1;
    }

    if (nDY < 0)
    {
        nStepY = -1;
        nDY = -nDY;
    }
    else
    {
        nStepY = 1;
    }

    DDRAW_PutPixel(nX1, nY1, nColor);

    int nError = 0;
    if (nDX < nDY)
    {
        for (int i = 0; i < nDY; ++i)
        {
            nY += nStepY;
            nError += nDX;
            if (nError > nDY)
            {
                nX += nStepX;
                nError -= nDY;
            }

            DDRAW_PutPixel(nX, nY, nColor);
        }
    }
    else
    {
        for (int i = 0; i < nDX; ++i)
        {
            nX += nStepX;
            nError += nDY;
            if (nError > nDX)
            {
                nY += nStepY;
                nError -= nDX;
            }

            DDRAW_PutPixel(nX, nY, nColor);
        }
    }
}
