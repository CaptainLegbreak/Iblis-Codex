extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ItemsTxt;
struct D2ItemDataTbl { int nItemsTxtRecordCount; D2ItemsTxt* pItemsTxt; };

struct D2UnitStrc
{
    char unk0x00[0xE4];
    D2UnitStrc* pListNext;
};

struct D2GameStrc
{
    char unk0x0000[0x1B20];
    D2UnitStrc* pTileList;
};

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables();                                                      // 0x00633590

// 0x00555770
void __fastcall sub_00555770_RemoveAllTiles(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0x12D);
    D2UnitStrc* pTile = pGame->pTileList;
    while (pTile)
    {
        D2UnitStrc* pCurrent = pTile;
        pTile = pTile->pListNext;
        SUNIT_RemoveUnit(pGame, pCurrent);
    }
    pGame->pTileList = 0;
}

// 0x00555CC0
int __cdecl sub_00555CC0_GetItemsTxtCount()
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    if (!pItemDataTbl)
        return 0;
    return pItemDataTbl->nItemsTxtRecordCount;
}
