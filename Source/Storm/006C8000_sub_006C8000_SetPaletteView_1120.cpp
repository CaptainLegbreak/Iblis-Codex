struct D2GfxPaletteViewStrc { unsigned int fields[72]; };
extern D2GfxPaletteViewStrc gPaletteView_0098A040; // 0x0098A040
extern D2GfxPaletteViewStrc* gpGfxPaletteView_007C9150; // 0x007C9150
// 0x006C8000
void __fastcall sub_006C8000_SetPaletteView(const D2GfxPaletteViewStrc* source)
{
    gPaletteView_0098A040 = *source;
    gpGfxPaletteView_007C9150 = &gPaletteView_0098A040;
}
