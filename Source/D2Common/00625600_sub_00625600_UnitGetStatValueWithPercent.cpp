struct D2StatListStrc;

struct D2UnitStrc
{
    char unk0x00[0x5C];
    D2StatListStrc* pStatListEx;
};

int __stdcall sub_006255A0_GetStatValueWithPercent(D2StatListStrc* pStatList, int nStatId, int nPercentStatId, int bAddBonus); // 0x006255A0

// 0x00625600
int __stdcall sub_00625600_UnitGetStatValueWithPercent(D2UnitStrc* pUnit, int nStatId, int nPercentStatId, int bAddBonus)
{
    return sub_006255A0_GetStatValueWithPercent(pUnit->pStatListEx, nStatId, nPercentStatId, bAddBonus);
}
