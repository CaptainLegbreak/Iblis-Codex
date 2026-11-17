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
// 0x005C0D70
void __stdcall sub_005C0D70(D2UnitStrc* pItem, int nItemLevel, int nClassFirstSkillId)
{
    int nSkills[3] = { -1, -1, -1 };
    int nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
    int nSkillCount;
    if (nRoll > 90)
        nSkillCount = 3;
    else if (nRoll > 70)
        nSkillCount = 2;
    else if (nRoll > 30)
        nSkillCount = 1;
    else
        return;
    int nBaseTier = 1;
    if (nItemLevel > 24)
        nBaseTier = 4;
    else if (nItemLevel > 18)
        nBaseTier = 3;
    else if (nItemLevel > 11)
        nBaseTier = 2;
    for (int i = 0; i < nSkillCount; ++i)
    {
        nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
        int nTier = nBaseTier;
        if (nRoll > 80)
            nTier = nBaseTier + 1;
        else if (nRoll <= 30)
        {
            if (nRoll > 10)
                nTier = nBaseTier - 1;
            else
                nTier = nBaseTier - 2;
        }
        nItemLevel = nTier;
        if (nItemLevel < 1)
            nItemLevel = 1;
        int nSkillId;
        do
        {
            const int nSkillRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 5;
            nSkillId = nClassFirstSkillId + 5 * (nItemLevel - 1) + nSkillRoll;
        }
        while (nSkillId == 73 || nSkillId == nSkills[0] || nSkillId == nSkills[1] || nSkillId == nSkills[2]);
        nSkills[i] = nSkillId;
        nItemLevel = 1;
        nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
        if (nRoll >= 90)
            nItemLevel = 3;
        else if (nRoll >= 60)
            nItemLevel = 2;
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(sub_004DC0B0_GetUnitMemoryPool(pItem), 0x40, 0, 4, sub_00451F50_GetUnitGUID(pItem));
            D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
        }
        if (pStatList)
            STATLIST_SetStatIfListIsValid(pStatList, 107, nItemLevel, nSkillId);
    }
}
