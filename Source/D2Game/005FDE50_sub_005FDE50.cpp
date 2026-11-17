extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* D2FarProcFn)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn);                              // 0x006CC34C

struct D2CmpTileStrc
{
    char unk0x00[0x54];
    int unk0x54;
    int unk0x58;
    int unk0x5C;
};

struct D2CmpPoolEntryStrc
{
    int unk0x00;
    int unk0x04;
    D2CmpTileStrc* pTile;
};

typedef void (__fastcall* D2TileFreeCallbackFn)(D2CmpTileStrc* pTile);
D2TileFreeCallbackFn gpfnTileFreeCallback_0088CB1C;                                                         // 0x0088CB1C

// 0x005FDE50
void __fastcall sub_005FDE50(void* pEntry)
{
    D2CmpTileStrc* pTile = ((D2CmpPoolEntryStrc*)pEntry)->pTile;
    if (gpfnTileFreeCallback_0088CB1C)
    {
        D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnTileFreeCallback_0088CB1C), 0xB4);
        gpfnTileFreeCallback_0088CB1C(pTile);
    }

    pTile->unk0x54 = 0;
    pTile->unk0x5C = 0;
}
