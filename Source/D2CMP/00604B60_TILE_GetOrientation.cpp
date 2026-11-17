struct D2TileLibraryEntryStrc
{
    int nDirection;
    short nRoofHeight;
    unsigned short wFlags16;
    int nHeight;
    int nWidth;
    int unk0x10;
    int nOrientation;
    int f_18;
    int nSubIndex;
    int nRarity;
    char unk0x24[4];
    unsigned char aSubtileFlags[25];
    char unk0x41[0x17];
    int unk0x58;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00604B60
int __stdcall TILE_GetOrientation(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 121); return pTile->nOrientation; }
// 0x00604B90
int __stdcall TILE_GetMainIndex(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 122); return pTile->f_18; }
// 0x00604BC0
int __stdcall TILE_GetFlags16(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 123); return pTile->wFlags16; }
// 0x00604BF0
int __stdcall TILE_GetWidth(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 124); return pTile->nWidth; }
// 0x00604C20
int __stdcall TILE_GetRarity(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 125); return pTile->nRarity; }
// 0x00604C50
int __stdcall TILE_GetSubIndex(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 126); return pTile->nSubIndex; }
// 0x00604C80
int __stdcall TILE_GetDirection(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 127); return pTile->nDirection; }
// 0x00604CB0
int __stdcall TILE_GetHeight(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 128); return pTile->nHeight; }
// 0x00604CE0
unsigned char* __stdcall sub_00604CE0(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 129); return pTile->aSubtileFlags; }
// 0x00604D10
int __stdcall TILE_GetUnk0x10(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 130); return pTile->unk0x10; }
// 0x00604D40
short __stdcall TILE_GetRoofHeight(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 131); return pTile->nRoofHeight; }
// 0x00604D80
int __stdcall TILE_GetUnk0x58(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 132); return pTile->unk0x58; }
