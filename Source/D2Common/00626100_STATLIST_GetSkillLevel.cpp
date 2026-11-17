struct D2StatListStrc
{
    char unk0x00[32];
    int dwSLvl;
};

int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);           // 0x006270B0

// 0x00626100
int __stdcall STATLIST_GetSkillLevel(D2StatListStrc* pStatList)
{
    return pStatList->dwSLvl;
}

// 0x00627150
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer)
{
    if (pStatList)
    {
        sub_006270B0(pStatList, nStatId, nValue, nLayer);
    }
}
