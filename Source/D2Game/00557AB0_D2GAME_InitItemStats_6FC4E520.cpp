struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x010[0x10];
    D2SeedStrc tSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2ItemDropStrc
{
    char unk0x00[0x0C];
    int nItemLvl;
    char unk0x10[0x44];
    int nQtyOverride;
};

struct D2ItemsTxt
{
    char unk0x000[0xCC];
    unsigned int dwMinAc;
    unsigned int dwMaxAc;
    char unk0x0D4[0x04];
    int dwSpeed;
    char unk0x0DC[0x22];
    unsigned char nMinDam;
    unsigned char nMaxDam;
    unsigned char nMinMisDam;
    unsigned char nMaxMisDam;
    unsigned char n2HandMinDam;
    unsigned char n2HandMaxDam;
    char unk0x104[0x0D];
    unsigned char nBlock;
    unsigned char nDurability;
    char unk0x113[0x17];
    unsigned char nQuest;
    unsigned char nQuestDiffCheck;
};

struct D2StatListStrc;
struct D2StatListExStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
static __forceinline unsigned int D2_MinU(unsigned int a, unsigned int b) { return a < b ? a : b; }
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
int __fastcall ITEMMODE_AssignItemQualityAndProperties(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop); // 0x00557450
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMS_SetVarGfxIndex(D2UnitStrc* pItem, unsigned char nIndex); // 0x00628420
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_GetSpawnStack(D2UnitStrc* pItem); // 0x00629660
int __stdcall ITEMS_GetMinStack(D2UnitStrc* pItem); // 0x006296F0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem); // 0x0062A0F0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740
unsigned char __stdcall ITEMS_GetVarInvGfxCount(D2UnitStrc* pItem); // 0x0062E8D0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __stdcall ITEMMODS_SetRandomElixirFileIndex(D2UnitStrc* pItem); // 0x0065E8E0

// 0x00556360
static __declspec(noinline) void sub_00556360_RollArmorClass(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1C9);

    const unsigned int nMinAc = pItemsTxtRecord->dwMinAc;
    const unsigned int nMaxAc = pItemsTxtRecord->dwMaxAc;
    const unsigned int nACValue = sub_00472280(&pItem->tSeed, nMinAc, nMaxAc - nMinAc + 1);
    D2_ASSERT(nACValue <= nMaxAc, 0x1CE);
    STATLIST_SetUnitStat(pItem, 31, nACValue, 0);
}

// 0x005563D0
static __declspec(noinline) void sub_005563D0_SetWeaponDamage(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1DB);

    if (pItemsTxtRecord->nMaxDam)
    {
        STATLIST_SetUnitStat(pItem, 22, pItemsTxtRecord->nMaxDam, 0);
    }

    if (pItemsTxtRecord->nMinDam)
    {
        STATLIST_SetUnitStat(pItem, 21, pItemsTxtRecord->nMinDam, 0);
    }

    if (pItemsTxtRecord->n2HandMinDam)
    {
        STATLIST_SetUnitStat(pItem, 23, pItemsTxtRecord->n2HandMinDam, 0);
    }

    if (pItemsTxtRecord->n2HandMaxDam)
    {
        STATLIST_SetUnitStat(pItem, 24, pItemsTxtRecord->n2HandMaxDam, 0);
    }

    if (pItemsTxtRecord->nMaxMisDam)
    {
        STATLIST_SetUnitStat(pItem, 159, pItemsTxtRecord->nMinMisDam, 0);
        STATLIST_SetUnitStat(pItem, 160, pItemsTxtRecord->nMaxMisDam, 0);
    }
}

static __forceinline void ITEMS_SetGoldStat(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == 0)
    {
        if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
        {
            STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
            return;
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

static void sub_00557A70_RollVarInvGfx(D2UnitStrc* pItem)
{
    if (ITEMS_GetVarInvGfxCount(pItem))
    {
        const unsigned char nIndex = sub_00472280(&pItem->tSeed, 0, ITEMS_GetVarInvGfxCount(pItem));
        ITEMS_SetVarGfxIndex(pItem, nIndex);
    }
}

// 0x00557AB0
int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int bQuestItem)
{
    if (ITEMS_GetItemType(*ppItem) == 4)
    {
        int nQuantity = 1;
        if (pItemDrop)
        {
            const int nItemLevel = pItemDrop->nItemLvl;
            nQuantity = SEED_RollLimitedRandomNumber(&(*ppItem)->tSeed, 5 * nItemLevel) + nItemLevel;
            if (nQuantity <= 0)
            {
                nQuantity = 1;
            }

            if (pItemDrop->nQtyOverride > 0)
            {
                nQuantity = pItemDrop->nQtyOverride;
            }
        }

        ITEMS_SetGoldStat(*ppItem, 14, nQuantity);
    }
    else if (ITEMS_GetQuiverType(*ppItem))
    {
        const int nMinStack = ITEMS_GetMinStack(*ppItem);
        int nQuantity = nMinStack + ITEMS_RollLimitedRandomNumber(&(*ppItem)->tSeed, ITEMS_GetTotalMaxStack(*ppItem) - nMinStack);
        if (nQuantity < 1)
        {
            nQuantity = 1;
        }

        if (pItemDrop && pItemDrop->nQtyOverride > 0)
        {
            nQuantity = pItemDrop->nQtyOverride;
        }

        STATLIST_SetUnitStat(*ppItem, 70, nQuantity, 0);
    }
    else
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!*ppItem ? -1 : (*ppItem)->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x686);

        if (ITEMS_CheckItemTypeId(*ppItem, 50))
        {
            STATLIST_SetUnitStat(*ppItem, 20, pItemsTxtRecord->nBlock, 0);
            STATLIST_SetUnitStat(*ppItem, 67, -pItemsTxtRecord->dwSpeed, 0);
            const unsigned int nMaxDurability = pItemsTxtRecord->nDurability;
            const unsigned int nDurability = nMaxDurability >> 1;
            unsigned int nValue = ITEMS_RollLimitedRandomNumber(&(*ppItem)->tSeed, nDurability) + nDurability;
            if (nValue >= 255)
            {
                nValue = 255;
            }
            STATLIST_SetUnitStat(*ppItem, 72, nValue, 0);
            STATLIST_SetUnitStat(*ppItem, 73, nMaxDurability >= 255 ? 255 : nMaxDurability, 0);
            sub_00556360_RollArmorClass(*ppItem);
        }
        else if (ITEMS_CheckItemTypeId(*ppItem, 45))
        {
            if (ITEMS_CheckIfStackable(*ppItem))
            {
                const int nMinStack = ITEMS_GetMinStack(*ppItem);
                const int nMaxStack = ITEMS_GetTotalMaxStack(*ppItem);
                unsigned int nQuantity = ITEMS_RollLimitedRandomNumber(&(*ppItem)->tSeed, nMaxStack - nMinStack) + nMinStack;
                if (pItemDrop && pItemDrop->nQtyOverride > 0)
                {
                    nQuantity = pItemDrop->nQtyOverride;
                }

                if (nQuantity < 1)
                {
                    nQuantity = 1;
                }

                if (ITEMS_IsMagSetRarUniCrfOrTmp(*ppItem))
                {
                    nQuantity = 1;
                }

                STATLIST_SetUnitStat(*ppItem, 70, nQuantity, 0);
            }

            const unsigned int nDurability = pItemsTxtRecord->nDurability;
            STATLIST_SetUnitStat(*ppItem, 72, D2_MinU(ITEMS_RollLimitedRandomNumber(&(*ppItem)->tSeed, nDurability >> 1) + (nDurability >> 1), 255), 0);
            STATLIST_SetUnitStat(*ppItem, 73, D2_MinU(nDurability, 255), 0);
            sub_005563D0_SetWeaponDamage(*ppItem);
            STATLIST_SetUnitStat(*ppItem, 68, -pItemsTxtRecord->dwSpeed, 0);
        }
        else
        {
            if (ITEMS_CheckIfStackable(*ppItem))
            {
                const int nMinStack = ITEMS_GetMinStack(*ppItem);
                const int nMaxStack = ITEMS_GetTotalMaxStack(*ppItem);
                int nSpawnStack = ITEMS_GetSpawnStack(*ppItem);
                if (nSpawnStack < nMinStack || !nSpawnStack)
                {
                    nSpawnStack = nMinStack > nMaxStack ? nMinStack : nMaxStack;
                }

                unsigned int nQuantity = ITEMS_RollLimitedRandomNumber(&(*ppItem)->tSeed, nSpawnStack - nMinStack) + nMinStack;
                if (pItemDrop && pItemDrop->nQtyOverride > 0)
                {
                    nQuantity = pItemDrop->nQtyOverride;
                }

                if (ITEMS_IsMagSetRarUniCrfOrTmp(*ppItem) || nQuantity < 1)
                {
                    nQuantity = 1;
                }

                STATLIST_SetUnitStat(*ppItem, 70, nQuantity, 0);
            }

            if (ITEMS_GetItemType(*ppItem) == 11)
            {
                ITEMMODS_SetRandomElixirFileIndex(*ppItem);
            }
        }
    }

    sub_00557A70_RollVarInvGfx(*ppItem);

    int nResult = 1;
    if (bQuestItem && pItemDrop)
    {
        nResult = ITEMMODE_AssignItemQualityAndProperties(pGame, ppItem, pItemDrop);

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!*ppItem ? -1 : (*ppItem)->dwClassId);
        if (pItemsTxtRecord && pItemsTxtRecord->nQuest && pItemsTxtRecord->nQuestDiffCheck)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateOrFlag(*ppItem, 0, 0x40);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(!*ppItem ? 0 : (*ppItem)->pMemoryPool, 0x40, 0, 4, !*ppItem ? -1 : (*ppItem)->dwUnitId);
                D2COMMON_10475_PostStatToStatList(*ppItem, pStatList, 1);
            }

            STATLIST_SetStatIfListIsValid(pStatList, 356, pGame->nDifficulty, 0);
            ITEMS_SetItemFlag(*ppItem, 0x10, 1);
        }
    }

    return nResult;
}
