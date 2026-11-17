struct D2DrlgLevelStrc
{
    char unk0x000[0x1D0];
    int nLevelId;
};

// 0x006801F0
int __fastcall sub_006801F0_GetCliffPresetId(D2DrlgLevelStrc* pLevel)
{
    return (pLevel->nLevelId == 2) + 0x33;
}
