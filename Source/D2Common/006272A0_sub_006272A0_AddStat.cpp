struct D2StatListStrc;

void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030

// 0x006272A0
void __stdcall sub_006272A0_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer)
{
    STATLIST_AddStat(pStatList, nStatId, nValue, nLayer);
}
