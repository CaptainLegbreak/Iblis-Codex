struct D2GfxPaletteViewStrc { unsigned int fields[72]; };
extern D2GfxPaletteViewStrc gPaletteView_0096F280; // 0x0096F280
extern D2GfxPaletteViewStrc* gpGfxPaletteView_007C9150; // 0x007C9150
// 0x006B1D60
void __fastcall sub_006B1D60_SetPaletteView(const D2GfxPaletteViewStrc* source)
{
    gPaletteView_0096F280 = *source;
    gpGfxPaletteView_007C9150 = &gPaletteView_0096F280;
}
