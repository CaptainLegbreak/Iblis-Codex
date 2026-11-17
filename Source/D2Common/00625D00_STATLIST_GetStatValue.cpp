struct D2StatListStrc;

int __stdcall sub_00625350(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);          // 0x00625350

// 0x00625D00
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    return sub_00625350(pStatList, nStatId, nLayer);
}
