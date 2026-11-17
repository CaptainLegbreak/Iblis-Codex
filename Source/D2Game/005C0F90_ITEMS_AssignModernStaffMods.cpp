struct D2UnitStrc;
struct D2StatListStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc*); // 0x004DC0B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc*, int, int); // 0x006257D0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc*, int, int, int); // 0x00627150
static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed;
}

struct D2SkillsTxt { char pad0[0x18]; short nItemType; char pad1[0x23C-0x1A]; };
struct D2DataTablesStrc { char pad0[0xB98]; D2SkillsTxt* pSkills; void* pSkillsLinker; int nSkillsCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*, int); // 0x00629BB0
static __forceinline D2SkillsTxt* GetSkillsRecord(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsCount)
        return &sgptDataTables->pSkills[nSkill];
    return 0;
}
// 0x005C0F90
void __stdcall ITEMS_AssignModernStaffMods(D2UnitStrc* pUnit, int nItemLvl, int nClassFirstSkillId, int nItemDropLvl)
{
    int skillIds[3] = { -1, -1, -1 };
    int nRand = nItemDropLvl + RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
    int nCount = 0;
    if (nRand > 90)
    {
        nCount = 3;
    }
    else if (nRand > 70)
    {
        nCount = 2;
    }
    else if (nRand > 30 || nItemDropLvl)
    {
        nCount = 1;
    }
    else
    {
        return;
    }

    int nBase = 1;
    if (nItemLvl > 36 && ITEMS_GetItemFormat(pUnit) >= 100u)
    {
        nBase = 5;
    }
    else if (nItemLvl > 24)
    {
        nBase = 4;
    }
    else if (nItemLvl > 18)
    {
        nBase = 3;
    }
    else if (nItemLvl > 11)
    {
        nBase = 2;
    }

    for (int j = 0; j < nCount; ++j)
    {
        nRand = RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
        int nBaseLayer = 0;
        if (nRand > 80)
        {
            nBaseLayer = nBase + 1;
        }
        else if (nRand > 30)
        {
            nBaseLayer = nBase;
        }
        else if (nRand > 10)
        {
            nBaseLayer = nBase - 1;
        }
        else
        {
            nBaseLayer = nBase - 2;
        }

        if (nBaseLayer < 1)
        {
            nBaseLayer = 1;
        }

        if (ITEMS_GetItemQuality(pUnit) == 1 && nBaseLayer >= 4)
        {
            nBaseLayer = 4;
        }

        int nSkillId;
        int nTries = 6;
        do
        {
            const int nRoll = RollSeed(ITEMS_GetItemSeed(pUnit)) % 5;
            nSkillId = nRoll + 5 * (nBaseLayer - 1) + nClassFirstSkillId;

            D2SkillsTxt* pSkillsTxtRecord = GetSkillsRecord(nSkillId);
            if (!pSkillsTxtRecord || pSkillsTxtRecord->nItemType <= 0 || ITEMS_CheckItemTypeId(pUnit, pSkillsTxtRecord->nItemType))
            {
                if (nSkillId != skillIds[0] && nSkillId != skillIds[1] && nSkillId != skillIds[2])
                {
                    skillIds[j] = nSkillId;
                    break;
                }
                --nTries;
            }
            else
            {
                --nTries;
            }
        }
        while (nTries > 0);

        int nValue = 1;
        if (ITEMS_GetItemFormat(pUnit) < 100u || ITEMS_GetItemQuality(pUnit) != 1)
        {
            nRand = nItemDropLvl / 2 + RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
            if (nRand >= 90)
            {
                nValue = 3;
            }
            else if (nRand >= 60)
            {
                nValue = 2;
            }
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40u);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(sub_004DC0B0_GetUnitMemoryPool(pUnit), 0x40u, 0, 4, sub_00451F50_GetUnitGUID(pUnit));
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }

        if (pStatList)
        {
            STATLIST_SetStatIfListIsValid(pStatList, 107, nValue, nSkillId);
        }
    }
}
