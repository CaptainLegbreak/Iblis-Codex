struct D2ItemsTxt
{
    char unk0x000[0x80];
    unsigned int dwCode;
    char unk0x084[0xAF];
    unsigned char nSpawnable;
    char unk0x134[0x12];
    unsigned char nVendorMin[17];
    unsigned char nVendorMax[17];
    unsigned char nVendorMagicMin[17];
    unsigned char nVendorMagicMax[17];
    unsigned char nVendorMagicLvl[17];
    char unk0x19B[9];
    unsigned char nPermStoreItem;
    char unk0x1A5[3];
};

struct D2ItemDataTbl
{
    int nItemsTxtRecordCount;
    D2ItemsTxt* pItemsTxt;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables();                                                      // 0x00633590

D2UnitProxyStrc gUnitProxyItemCache_00883D78[17];                                                           // 0x00883D78
extern unsigned char gbUnitProxyItemCacheInitialized_00883E88[17];                                          // 0x00883E88

// 0x00536D50
void __stdcall SUNITPROXY_FillIGlobaltemCacheRecordForNpc(int nNpcId)
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    if (gbUnitProxyItemCacheInitialized_00883E88[nNpcId])
    {
        return;
    }

    gbUnitProxyItemCacheInitialized_00883E88[nNpcId] = 1;

    int nItemCount = 0;
    int nPermStoreItemCount = 0;
    for (int i = 0; i < pItemDataTbl->nItemsTxtRecordCount; ++i)
    {
        if (pItemDataTbl->pItemsTxt[i].nSpawnable && (pItemDataTbl->pItemsTxt[i].nVendorMax[nNpcId] || pItemDataTbl->pItemsTxt[i].nVendorMagicMax[nNpcId]))
        {
            if (!pItemDataTbl->pItemsTxt[i].nPermStoreItem)
            {
                ++nItemCount;
            }
            else
            {
                ++nPermStoreItemCount;
            }
        }
    }

    gUnitProxyItemCache_00883D78[nNpcId].pItemCache = (D2ItemCacheStrc*)FOG_AllocPool(0, sizeof(D2ItemCacheStrc) * nItemCount, ".\\UNIT\\sunitproxy.cpp", 0x523, 0);
    memset(gUnitProxyItemCache_00883D78[nNpcId].pItemCache, 0, sizeof(D2ItemCacheStrc) * nItemCount);
    gUnitProxyItemCache_00883D78[nNpcId].nItems = nItemCount;

    gUnitProxyItemCache_00883D78[nNpcId].pPermCache = (unsigned int*)FOG_AllocPool(0, sizeof(unsigned int) * nPermStoreItemCount, ".\\UNIT\\sunitproxy.cpp", 0x528, 0);
    memset(gUnitProxyItemCache_00883D78[nNpcId].pPermCache, 0, sizeof(unsigned int) * nPermStoreItemCount);
    gUnitProxyItemCache_00883D78[nNpcId].nPerms = nPermStoreItemCount;

    int nItemCacheIndex = 0;
    int nPermCacheIndex = 0;
    for (int i = 0; i < pItemDataTbl->nItemsTxtRecordCount; ++i)
    {
        if (pItemDataTbl->pItemsTxt[i].nSpawnable && (pItemDataTbl->pItemsTxt[i].nVendorMax[nNpcId] || pItemDataTbl->pItemsTxt[i].nVendorMagicMax[nNpcId]))
        {
            if (!pItemDataTbl->pItemsTxt[i].nPermStoreItem)
            {
                gUnitProxyItemCache_00883D78[nNpcId].pItemCache[nItemCacheIndex].nMin = pItemDataTbl->pItemsTxt[i].nVendorMin[nNpcId];
                gUnitProxyItemCache_00883D78[nNpcId].pItemCache[nItemCacheIndex].nMax = pItemDataTbl->pItemsTxt[i].nVendorMax[nNpcId];
                gUnitProxyItemCache_00883D78[nNpcId].pItemCache[nItemCacheIndex].nMagicMin = pItemDataTbl->pItemsTxt[i].nVendorMagicMin[nNpcId];
                gUnitProxyItemCache_00883D78[nNpcId].pItemCache[nItemCacheIndex].nMagicMax = pItemDataTbl->pItemsTxt[i].nVendorMagicMax[nNpcId];
                gUnitProxyItemCache_00883D78[nNpcId].pItemCache[nItemCacheIndex].nMagicLevel = pItemDataTbl->pItemsTxt[i].nVendorMagicLvl[nNpcId];
                gUnitProxyItemCache_00883D78[nNpcId].pItemCache[nItemCacheIndex].dwCode = pItemDataTbl->pItemsTxt[i].dwCode;
                ++nItemCacheIndex;
            }
            else
            {
                gUnitProxyItemCache_00883D78[nNpcId].pPermCache[nPermCacheIndex] = pItemDataTbl->pItemsTxt[i].dwCode;
                ++nPermCacheIndex;
            }
        }
    }
}
