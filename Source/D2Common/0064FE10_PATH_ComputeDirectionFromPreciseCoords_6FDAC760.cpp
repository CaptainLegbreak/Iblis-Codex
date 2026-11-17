struct D2CoordStrc
{
    int nX;
    int nY;
};

void __fastcall PATH_GetDirectionVector(D2CoordStrc* pDirectionVector, int* pOutDirection, unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY); // 0x0064FC60

// 0x0064FE10
int __stdcall PATH_ComputeDirectionFromPreciseCoords_6FDAC760(unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY)
{

    PATH_GetDirectionVector((D2CoordStrc*)&dwStartPrecisionX, (int*)&dwTargetPrecisionY, dwStartPrecisionX, dwStartPrecisionY, dwTargetPrecisionX, dwTargetPrecisionY);

    return (int)dwTargetPrecisionY;
}
