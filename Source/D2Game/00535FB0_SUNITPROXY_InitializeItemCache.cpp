extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
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

#define MAX_NPC_INVENTORY 17

extern D2UnitProxyStrc gUnitProxyItemCache_00883D78[17];                                                    // 0x00883D78
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

// 0x00535FB0
static void SUNITPROXY_InitializeItemCache(D2GameStrc* pGame, D2UnitProxyStrc* pUnitProxy, int nNpcInventoryId)
{
    D2_ASSERT(nNpcInventoryId < MAX_NPC_INVENTORY, 164);
    pUnitProxy->nItems = gUnitProxyItemCache_00883D78[nNpcInventoryId].nItems;
    pUnitProxy->pItemCache = (D2ItemCacheStrc*)sub_0040B430(pGame->pMemoryPool, gUnitProxyItemCache_00883D78[nNpcInventoryId].nItems * sizeof(D2ItemCacheStrc), ".\\UNIT\\sunitproxy.cpp", 168, 0);
    memcpy(pUnitProxy->pItemCache, gUnitProxyItemCache_00883D78[nNpcInventoryId].pItemCache, gUnitProxyItemCache_00883D78[nNpcInventoryId].nItems * sizeof(D2ItemCacheStrc));
    pUnitProxy->nPerms = gUnitProxyItemCache_00883D78[nNpcInventoryId].nPerms;
    pUnitProxy->pPermCache = (unsigned int*)sub_0040B430(pGame->pMemoryPool, gUnitProxyItemCache_00883D78[nNpcInventoryId].nPerms * sizeof(unsigned int), ".\\UNIT\\sunitproxy.cpp", 171, 0);
    memcpy(pUnitProxy->pPermCache, gUnitProxyItemCache_00883D78[nNpcInventoryId].pPermCache, gUnitProxyItemCache_00883D78[nNpcInventoryId].nPerms * sizeof(unsigned int));
}

struct M08EmitRecStrc
{
    int nKind;
    char bFlagA;
    char bFlagB;
    char unk0x06[2];
    D2UnitProxyStrc tProxy;
};

void __fastcall sub_M08_EmitInitializeItemCache(D2GameStrc* pGame, M08EmitRecStrc* pRec)
{
    for (; pRec->nKind; ++pRec)
    {
        switch (pRec->nKind)
        {
        case 31:
            SUNITPROXY_InitializeItemCache(pGame, &pRec->tProxy, 9);
            pRec->bFlagA = 1;
            break;
        case 37:
            SUNITPROXY_InitializeItemCache(pGame, &pRec->tProxy, 3);
            pRec->bFlagB = 1;
            break;
        case 45:
            SUNITPROXY_InitializeItemCache(pGame, &pRec->tProxy, 0);
            break;
        }
    }
}
