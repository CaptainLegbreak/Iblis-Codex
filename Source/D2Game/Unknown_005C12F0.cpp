#include "D2Game.h"
#include "D2Structs.h"

struct D2MagicAffixTxt { char unk00[0x22]; unsigned short wVersion; char unk24[0x30]; unsigned char bSpawnable; char unk55[3]; int nLevel; char unk5C[0x34]; };
struct D2MagicAffixDataTbl { int nCount; D2MagicAffixTxt* pMagicAffix; D2MagicAffixTxt* pSuffix; D2MagicAffixTxt* pPrefix; D2MagicAffixTxt* pAutoMagic; };
struct D2AffixIndexAndPtrStrc { int nIndex; D2MagicAffixTxt* pAffix; };
D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables(); // 0x00633ED0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
int __stdcall ITEMS_GetItemLevel(D2UnitStrc*); // 0x006281E0
int __stdcall ITEMMODS_CanItemHaveMagicAffix(D2UnitStrc*, const D2MagicAffixTxt*); // 0x0065E620
int __fastcall sub_00472280(D2SeedStrc*, int, int); // 0x00472280
void __stdcall ITEMMODS_AssignProperty(int, D2UnitStrc*, D2UnitStrc*, const void*, int, int); // 0x0065FEC0
static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}
static __forceinline int ClampLevel(int v) { if (v <= 1) return 1; if (v >= 99) return 99; return v; }
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
// 0x005C12F0
short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    D2AffixIndexAndPtrStrc tAffixes[512];
    D2MagicAffixDataTbl* pTable = DATATBLS_GetMagicAffixDataTables();
    if (!pTable) return 0;
    D2MagicAffixTxt* pRecord;
    int nCount;
    if (bPrefix) { pRecord = pTable->pPrefix; nCount = pTable->pAutoMagic - pRecord; }
    else { pRecord = pTable->pSuffix; nCount = pTable->pPrefix - pRecord; }
    if (!pRecord) return 0;
    const int nFirstIndex = pRecord - pTable->pMagicAffix;
    int nIndex = -1;
    int nMax = 0;
    const unsigned int nRoll = RollSeed(ITEMS_GetItemSeed(pItem));
    const unsigned short nFormat = ITEMS_GetItemFormat(pItem);
    if ((nRoll & 1) || bForceAffixRoll)
    {
        int nLevel = ITEMS_GetItemLevel(pItem) + 2;
        nLevel = D2_MIN(D2_MAX(nLevel, 1), 99);
        for (int i = 0; i < nCount; ++i)
        {
            if ((!bRequireSpawnableAffix || pRecord[i].bSpawnable) && (pRecord[i].wVersion < 100 || nFormat >= 100) && pRecord[i].nLevel <= nLevel && ITEMMODS_CanItemHaveMagicAffix(pItem, &pRecord[i]) && nMax < 511)
            {
                tAffixes[nMax].pAffix = &pRecord[i];
                tAffixes[nMax].nIndex = nFirstIndex + i;
                ++nMax;
            }
        }
        if (nMax <= 0) return 0;
        const int nRandom = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nMax);
        if (nRandom >= nMax) return 0;
        D2AffixIndexAndPtrStrc* pAffix = &tAffixes[nRandom];
        if (!pAffix) return 0;
        nIndex = pAffix->nIndex;
        if (nPreferredAffixIndex > 0)
        {
            nPreferredAffixIndex += nFirstIndex;
            if (nPreferredAffixIndex > 0)
            {
                for (int i = 0; i < nMax; ++i)
                {
                    D2AffixIndexAndPtrStrc* pCurrent = &tAffixes[i];
                    if (pCurrent->nIndex == nPreferredAffixIndex - 1)
                    {
                        nIndex = pCurrent->nIndex;
                        pAffix = pCurrent;
                        goto ApplyProperties;
                    }
                }
                nIndex = -1;
            }
        }
ApplyProperties:
        if (bAssignProperties) ITEMMODS_AssignProperty(0, 0, pItem, pAffix->pAffix, 0, 0);
    }
    return nIndex + 1;
}
