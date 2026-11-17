extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc pSeed;
    unsigned int dwInitSeed;
};

int gnUnitInitSeed_008846E8;                                                                                // 0x008846E8

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
int __fastcall SEED_GetRandomValue(int nValue);                                                             // 0x00650DE0
void __stdcall ITEMS_InitItemSeed(D2UnitStrc* pItem);                                                       // 0x00627DC0
void __stdcall ITEMS_SetItemStartSeed(D2UnitStrc* pItem, int nSeed);                                        // 0x00627E20
unsigned int __stdcall ITEMS_GetItemStartSeed(D2UnitStrc* pItem);                                           // 0x00627DF0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00552DF0
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed)
{
    D2_ASSERT(pUnit, 415);

    SEED_InitSeed(&pUnit->pSeed);

    if (pSeed)
    {
        pUnit->dwInitSeed = (unsigned int)ITEMS_RollRandomNumberInline(pSeed);
    }
    else
    {
        pUnit->dwInitSeed = SEED_GetRandomValue(2 * gnUnitInitSeed_008846E8++);
    }

    SEED_InitLowSeed(&pUnit->pSeed, pUnit->dwInitSeed);
}

// 0x00552E90
void __fastcall sub_00552E90_InitItemSeeds(D2UnitStrc* pItem, D2SeedStrc* pGameSeed)
{
    ITEMS_InitItemSeed(pItem);
    ITEMS_SetItemStartSeed(pItem, (unsigned int)ITEMS_RollRandomNumberInline(pGameSeed));
    SEED_InitLowSeed(ITEMS_GetItemSeed(pItem), ITEMS_GetItemStartSeed(pItem));
}
