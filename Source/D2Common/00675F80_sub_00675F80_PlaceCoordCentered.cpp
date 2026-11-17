struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

static __declspec(noinline) void __stdcall sub_00675F80_PlaceCoordCentered(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4);

// 0x00675F80
static void __stdcall sub_00675F80_PlaceCoordCentered(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX -= pCoord->nWidth / 2 + 8;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX += pCoord->nWidth / 2 + 8;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= pCoord->nHeight / 2 + 8;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += pCoord->nHeight / 2 + 8;
        }
        break;
    case 4:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX -= pCoord->nWidth / 2 + 8;
        }
        break;
    case 5:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX += pCoord->nWidth / 2 + 8;
        }
        break;
    case 6:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= pCoord->nHeight / 2 + 8;
        }
        break;
    case 7:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += pCoord->nHeight / 2 + 8;
        }
        break;
    }
}

// calling-convention shim (not game code)
void __fastcall sub_00675F80_Shim(D2DrlgCoordStrc* pCoords, int nCount)
{
    for (int i = 1; i < nCount; ++i)
    {
        sub_00675F80_PlaceCoordCentered(&pCoords[i - 1], &pCoords[i], i & 7, i & 1);
    }
}
