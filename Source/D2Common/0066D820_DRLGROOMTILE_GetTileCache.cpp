struct D2TileLibraryEntryStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x14];
    D2SeedStrc pSeed;
    char unk0x1C[0x4C];
    void* pTiles;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall D2CMP_GetTiles(void** ppTiles, int nTileType, int nStyle, int nSequence, D2TileLibraryEntryStrc** ppTileEntries, int nMaxEntries);   // 0x00604AE0
int __stdcall TILE_GetRarity(D2TileLibraryEntryStrc* pTile);                                                 // 0x00604C20

static __forceinline unsigned int SEED_RollRandomNumberHighFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberHighFirst(pSeed) % nMax;
    }

    return SEED_RollRandomNumberHighFirst(pSeed) & (nMax - 1);
}

// 0x0066D820
D2TileLibraryEntryStrc* __fastcall DRLGROOMTILE_GetTileCache(D2DrlgRoomStrc* pDrlgRoom, int nType, unsigned int nPackedTileInformation)
{
    D2TileLibraryEntryStrc* ppTileEntries[40];

    const unsigned char nStyle = nPackedTileInformation ? (unsigned char)(nPackedTileInformation >> 20) & 0x3F : 0;
    const unsigned char nSequence = nPackedTileInformation ? (unsigned char)(nPackedTileInformation >> 8) : 0;

    const unsigned int nTiles = D2CMP_GetTiles(&pDrlgRoom->pTiles, nType, nStyle, nSequence, ppTileEntries, 40);
    if (!nTiles)
    {
        D2_ASSERT(D2CMP_GetTiles(&pDrlgRoom->pTiles, 10, 0, 0, ppTileEntries, 40), 0x73);
        return ppTileEntries[0];
    }

    int nTotalRarity = 0;
    for (unsigned int i = 0; i < nTiles; ++i)
    {
        D2_ASSERT(ppTileEntries[i], 0x7C);
        nTotalRarity += TILE_GetRarity(ppTileEntries[i]);
    }

    int nRand = SEED_RollLimitedRandomNumber(&pDrlgRoom->pSeed, nTotalRarity) + 1;
    int nIndex = 0;
    while (nTotalRarity && nTiles > 1 && nRand > 0)
    {
        nRand -= TILE_GetRarity(ppTileEntries[nIndex]);
        ++nIndex;
    }

    if (nIndex)
    {
        --nIndex;
    }

    return ppTileEntries[nIndex];
}
