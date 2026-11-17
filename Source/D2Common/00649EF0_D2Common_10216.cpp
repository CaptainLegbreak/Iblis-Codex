union D2FP32_16
{
    struct
    {
        unsigned short wOffsetX;
        unsigned short wPosX;
        unsigned short wOffsetY;
        unsigned short wPosY;
    };

    struct
    {
        unsigned int dwPrecisionX;
        unsigned int dwPrecisionY;
    };
};

struct D2DynamicPathStrc
{
    D2FP32_16 tGameCoords;
    char unk0x08[0x5C];
    unsigned char nNewDirection;
    unsigned char nDirection;
};

int __stdcall PATH_ComputeDirectionFromPreciseCoords_6FDAC760(D2FP32_16 tStart, D2FP32_16 tTarget); // 0x0064FE10
void __fastcall sub_6FDA9720(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection);            // 0x006485F0

// 0x00649EF0
void __stdcall D2Common_10216(D2DynamicPathStrc* pDynamicPath, int nX, int nY, int a4)
{
    if (pDynamicPath)
    {
        D2FP32_16 tTarget;
        tTarget.dwPrecisionX = (nX << 16) + 0x8000;
        tTarget.dwPrecisionY = (nY << 16) + 0x8000;
        const int nDirection = PATH_ComputeDirectionFromPreciseCoords_6FDAC760(pDynamicPath->tGameCoords, tTarget);
        if (a4)
        {
            pDynamicPath->nNewDirection = nDirection & 0x3F;
            pDynamicPath->nDirection = nDirection & 0x3F;
        }
        else
        {
            sub_6FDA9720(pDynamicPath, nDirection);
        }
    }
}
