struct D2DrlgCoordsStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
};

// 0x0067D7B0
static __forceinline void sub_0067D7B0(D2DrlgCoordsStrc* pCoords, int nType)
{
    switch (nType)
    {
    case 0:
        pCoords->nWidth = 0x40;
        pCoords->nHeight = 0xA0;
        break;

    case 1:
        pCoords->nWidth = 0xA0;
        pCoords->nHeight = 0x40;
        break;
    }
}

void __stdcall sub_M129_Emit_0067D7B0(D2DrlgCoordsStrc* pCoords, int nType)
{
    sub_0067D7B0(pCoords, nType);
}
