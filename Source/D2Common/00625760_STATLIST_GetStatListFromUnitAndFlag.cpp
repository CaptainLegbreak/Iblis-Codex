struct D2StatListStrc
{
    char unk0x00[16];
    unsigned int dwFlags;
};

struct D2UnitStrc
{
    char unk0x00[92];
    D2StatListStrc* pStatListEx;
};

D2StatListStrc* __stdcall sub_006256E0_StatListFindByFlags(D2StatListStrc* pStatList, int nFlag);           // 0x006256E0

#define STATLIST_EXTENDED 0x80000000

// 0x00625760
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag)
{
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return 0;
    }

    return sub_006256E0_StatListFindByFlags(pStatListEx, nFlag);
}
