struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int pMemoryPool;
    int dwUnitId;
    char unk_10[0x10];
    D2SeedStrc pSeed;
    char unk_28[0x9C];
    unsigned int dwFlags;
};
struct D2SkillsTxt
{
    char unk_000[0x12E];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    unsigned int dwHitClass;
    char unk_138[0x104];
};
struct D2DataTablesStrc
{
    char unk_000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};
struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage[22];
    unsigned int dwHitClass;
    int unk_64[3];
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId); // 0x004EFC20
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nType); // 0x00629BB0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00563560
int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nObjectType, int nObjectGUID, int* pResult); // 0x00584420
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
static __forceinline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}
static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}
// 0x005C98F0
int __fastcall sub_005C98F0_Telekinesis(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !pUnit || pUnit->dwUnitType != 0 || PLAYER_IsBusy(pUnit))
        return 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
        return 0;
    pUnit->dwFlags |= 0x40;
    int nItemStatus = 0;
    int nResult;
    const int nTargetType = sub_0044BE50(pTarget);
    switch (nTargetType)
    {
    case 0:
    case 1:
        {
            if (!sub_00554200(pGame, pUnit, pTarget))
                return 0;
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
                return 0;
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
                return 0;
            int bKnockback = 0;
            if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < sub_004EFC20_GetSkillParam2(nSkillId))
                bKnockback = 1;
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
            D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
            damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
            damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
            if (pSkillsTxtRecord->dwHitClass)
                damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
            if (bKnockback)
                damage.wResultFlags |= 9;
            SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
            SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
            return 1;
        }
    case 4:
        if (!ITEMS_CheckItemTypeId(pTarget, 0x16)
            && !ITEMS_CheckItemTypeId(pTarget, 4)
            && !ITEMS_CheckItemTypeId(pTarget, 0x26)
            && !ITEMS_CheckItemTypeId(pTarget, 0x38)
            && !ITEMS_CheckItemTypeId(pTarget, 9)
            && !ITEMS_CheckItemTypeId(pTarget, 0x29))
        {
            SUNIT_AttachSound(pUnit, 0x13, pUnit);
            return 1;
        }
        D2GAME_PickupItem_6FC43340(pGame, pUnit, sub_00451F50(pTarget), &nItemStatus);
        return 1;
    case 2:
        {
            OBJECTS_OperateHandler(pGame, pUnit, sub_0044BE50(pTarget), sub_00451F50(pTarget), &nResult);
        }
        break;
    }
    return 1;
}
