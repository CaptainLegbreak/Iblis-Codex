struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

static __declspec(noinline) void __stdcall sub_00675EB0_PlaceCoord(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4);

// 0x00675EB0
static void __stdcall sub_00675EB0_PlaceCoord(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nWidth - pCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX += 16;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += 16;
        }
        else if (a4 == 2)
        {
            pCoord->nPosY -= 8;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX -= 16;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= 16;
        }
        else if (a4 == 2)
        {
            pCoord->nPosY += 8;
        }
        else if (a4 == 3)
        {
            pCoord->nPosY -= 8;
        }
        break;
    }
}

// calling-convention shim (not game code)
void __fastcall sub_00675EB0_Shim(D2DrlgCoordStrc* pCoords, int nCount)
{
    for (int i = 1; i < nCount; ++i)
    {
        sub_00675EB0_PlaceCoord(&pCoords[i - 1], &pCoords[i], i & 3, i & 1);
    }
}
