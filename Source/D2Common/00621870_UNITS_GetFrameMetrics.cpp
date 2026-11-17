struct D2ObjectsTxt
{
    unsigned char unk_00[0xD8];
    int dwFrameCnt[8];
};
struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
};
struct D2UnitStrc
{
    unsigned int dwUnitType;
    unsigned char unk_04[0x0C];
    unsigned int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    unsigned char unk_18[0x2C];
    int dwFrameNo;
    int dwFrameCount;
};

// 0x00621870
void __stdcall UNITS_GetFrameMetrics(D2UnitStrc* pUnit, int* pFrame, int* pFrameCount)
{
    if (!pUnit)
    {
        *pFrame = 0;
        *pFrameCount = 0;
        return;
    }

    if (pUnit->dwUnitType == 2)
    {
        *pFrame = pUnit->dwFrameNo;
        *pFrameCount = pUnit->pObjectData->pObjectTxt->dwFrameCnt[pUnit->dwAnimMode];
        return;
    }

    *pFrame = pUnit->dwFrameNo;
    *pFrameCount = pUnit->dwFrameCount;
}
