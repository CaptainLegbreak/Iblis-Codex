struct D2StatListStrc;

int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);          // 0x006270B0

// 0x00627250
int __stdcall sub_00627250_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer)
{
    return sub_006270B0(pStatList, nStatId, nValue, nLayer);
}
