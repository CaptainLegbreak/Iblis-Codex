struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x008[0x18];
    D2SeedStrc tSeed;
};

struct D2ItemsTxt
{
    char unk0x000[0xCC];
    unsigned int dwMinAc;
    unsigned int dwMaxAc;
    char unk0x0D4[0x2A];
    unsigned char nMinDam;
    unsigned char nMaxDam;
    unsigned char nMinMisDam;
    unsigned char nMaxMisDam;
    unsigned char n2HandMinDam;
    unsigned char n2HandMaxDam;
    char unk0x104[0xA4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

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

void sub_A04_Emit_00557AB0(D2UnitStrc** ppItem, int bWeapon)
{
    if (bWeapon)
    {
        sub_005563D0_SetWeaponDamage(*ppItem);
    }
    else
    {
        sub_00556360_RollArmorClass(*ppItem);
    }
}
