struct D2DrlgLevelStrc;

int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY);          // 0x00674120
void __fastcall sub_006743C0(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6); // 0x006743C0

// 0x0067E210
static __forceinline int sub_0067E210_PlaceShiftedPreset(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    const int nPreset = DRLGOUTDOORS_GetPresetIndexFromGridCell(pLevel, nX, nY);
    if (nPreset >= 0x393 && nPreset <= 0x39A)
    {
        sub_006743C0(pLevel, nX, nY, nPreset + 0x10, -1, 0);
        return 1;
    }
    return 0;
}

int __fastcall sub_M119_Emit_0067E210(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    return sub_0067E210_PlaceShiftedPreset(pLevel, nY, nX);
}
