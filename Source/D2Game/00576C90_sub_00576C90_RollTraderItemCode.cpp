struct D2GameStrc;
struct D2UnitStrc;
struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
        unsigned __int64 lSeed;
    };
};

struct D2ItemCacheStrc
{
    unsigned char nMin;
    unsigned char nMax;
    unsigned char nMagicMin;
    unsigned char nMagicMax;
    unsigned int dwCode;
    unsigned char nMagicLevel;
    char unk0x09[3];
};

struct D2UnitProxyStrc
{
    D2ItemCacheStrc* pItemCache;
    int nItems;
    unsigned int* pPermCache;
    int nPerms;
};

struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char bHireInit;
    unsigned char nAct;
    unsigned char bTrader;
    char unk0x04[0x04];
    unsigned int dwTicks;
    D2UnitProxyStrc pProxy;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x20];
    D2NpcTradeStrc npcTrade;
};

struct D2ItemsTxt;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __stdcall ITEMS_CheckBitField1Flag1(int nItemId);                                                       // 0x00629C80
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);               // 0x00633640

// 0x00576C90
int __fastcall sub_00576C90_RollTraderItemCode(D2GameStrc* pGame, D2UnitStrc* pNpc, D2SeedStrc* pSeed, int nUnused, unsigned int* pCode, int* pIndex)
{
    int nIndex = *pIndex;
    int nNpcIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nNpcIndex);
    if (pNpcRecord)
    {
        D2NpcTradeStrc* pTrade = &pNpcRecord->npcTrade;
        if (pTrade && pTrade->bTrader && pTrade->pProxy.nItems && pTrade->pProxy.pItemCache)
        {
            int nItemId = ITEMS_RollLimitedRandomNumber(pSeed, pTrade->pProxy.nItems);
            pSeed->lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;

            const int nRand = nItemId;
            DATATBLS_GetItemRecordFromItemCode(pTrade->pProxy.pItemCache[nRand].dwCode, &nItemId);
            ITEMS_CheckBitField1Flag1(nItemId);
            *pCode = pTrade->pProxy.pItemCache[nRand].dwCode;
            *pIndex = nIndex;
            return 1;
        }

        D2_ASSERT(pTrade, 899);
        D2_ASSERT(pTrade->bTrader, 900);
    }

    D2_ASSERT(pNpcRecord, 905);
    *pCode = 0;
    return 0;
}
