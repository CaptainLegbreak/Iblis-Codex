struct D2DrlgOutdoorInfoStrc
{
    char unk0x00[0x68];
    int anValues68[1];
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x018[0x1C0 - 0x18];
    int unk0x1C0;
    char unk0x1C4[0x0C];
    int nLevelId;
};

int __fastcall sub_0067DCE0(D2DrlgLevelStrc* pLevel);                                               // 0x0067DCE0

// 0x00675290
int __fastcall sub_00675290_GetOutdoorValue(D2DrlgLevelStrc* pLevel, int nIndex)
{
    return pLevel->pOutdoors->anValues68[nIndex];
}

// 0x006757E0
int __fastcall sub_006757E0_GetLevelStyle(D2DrlgLevelStrc* pLevel, bool bFlag)
{
    switch (pLevel->unk0x1C0)
    {
    case 2:
        return !bFlag;
    case 16:
        return 2;
    case 27:
        return 3;
    case 31:
        return sub_0067DCE0(pLevel);
    }
    return -1;
}
