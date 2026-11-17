struct D2PaletteTableStrc;

extern D2PaletteTableStrc gPaletteTables_007D5458;                                                          // 0x007D5458
void __stdcall D2GFX_SetPaletteTables(D2PaletteTableStrc* pPaletteTables);                                  // 0x004F6410

// 0x004F8DD0
void __cdecl sub_004F8DD0_Empty()
{
}

// 0x004F8E90
void __cdecl sub_004F8E90_SetDefaultPalettes()
{
    D2GFX_SetPaletteTables(&gPaletteTables_007D5458);
}
