struct D2GameStrc;
struct D2InventoryStrc;
struct D2SkillStrc;
struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x40];
    int nSeqCurrentFramePrecise;
    char unk0x48[0x18];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

struct D2SkillsTxt
{
    char unk0x000[0x80];
    short nAuraState;
    char unk0x082[0x122];
    unsigned char nToHitShift;
    char unk0x1A5[0x03];
    unsigned int dwMinDam;
    char unk0x1AC[0x90];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __fastcall sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused); // 0x0056B9C0
int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit);                                                       // 0x00623B10
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
int __fastcall sub_6FD00370(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillLevel);                         // 0x005C8980
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit);                                                // 0x0064F460
int __fastcall sub_6FD119C0(D2UnitStrc* pUnit);                                                             // 0x0056C4E0
void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00580310
void __fastcall sub_6FC80E10(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00580380
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem);                                                      // 0x006288A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
D2UnitStrc* __fastcall sub_6FD11710(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0
void __fastcall sub_0056C600_ApplyThrowBonuses(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pWeapon); // 0x0056C600
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0
int __fastcall sub_6FD13330(D2GameStrc* pGame, D2UnitStrc* pUnit, int a5, int nSkillId, int nSkillLevel, int a6); // 0x0056CE70
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0056BA90
int __fastcall sub_6FCF5DE0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2DamageStrc damage = *(D2DamageStrc*)pAuraCallback->pArgs;
    sub_6FD10140(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0);
    return 1;
}

// 0x0056CA40
int __fastcall SKILLS_SrvSt01_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    pUnit->nSeqCurrentFramePrecise = UNITS_GetFrameBonus(pUnit) << 8;
    if (STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return sub_6FD00370(pGame, pUnit, nSkillLevel);
    }

    if (!COMPOSIT_IsWeaponBowOrXBow(pUnit) || sub_6FD119C0(pUnit))
    {
        return 1;
    }

    sub_6FC80A30(pGame, pUnit);
    sub_6FC80E10(pGame, pUnit);
    return 0;
}

// 0x0056CAF0
int __fastcall SKILLS_SrvSt02_Kick(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = 9;
    damage.dwHitFlags = 2;
    damage.dwPhysDamage = pSkillsTxtRecord->dwMinDam << pSkillsTxtRecord->nToHitShift;
    damage.dwHitClass = 1;
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    return 1;
}

// 0x0056E1E0
int __fastcall sub_0056E1E0_GetCrossbowClassFlag(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClassId, -1, 1);
    return nWeaponClassId == 7 ? 0x1F : 0;
}

// 0x0056F460
int __fastcall SKILLS_SrvDo003_Throw(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pWeapon = 0;
    int nBodyLoc;
    int bIsLeftHandItem;
    if (INVENTORY_GetEquippedWeapon(pInventory, &pWeapon, &nBodyLoc, &bIsLeftHandItem))
    {
        if (!bIsLeftHandItem)
        {
            if (nBodyLoc == 5)
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            }
            else
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            }
        }

        if (!ITEMS_CheckIfThrowable(pWeapon) && !STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 125, 0))
        {
            return 0;
        }
    }

    if (!pWeapon)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x40;
    const int nMissileType = ITEMS_GetMissileType(pWeapon);

    D2UnitStrc* pMissile;
    if (ITEMS_CheckItemTypeId(pWeapon, 38))
    {
        pMissile = sub_6FD11710(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = sub_6FD11420(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    sub_0056C600_ApplyThrowBonuses(pUnit, pMissile, pWeapon);
    return 1;
}

// 0x0056F550
int __fastcall SKILLS_SrvDo005_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pWeapon = 0;
    int nBodyLoc;
    int bIsLeftHandItem;
    if (INVENTORY_GetEquippedWeapon(pInventory, &pWeapon, &nBodyLoc, &bIsLeftHandItem))
    {
        if (bIsLeftHandItem)
        {
            if (nBodyLoc == 5)
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            }
            else
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            }
        }

        if (!ITEMS_CheckIfThrowable(pWeapon) && !STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 125, 0))
        {
            return 0;
        }
    }

    if (!pWeapon)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x40;
    const int nMissileType = ITEMS_GetMissileType(pWeapon);

    D2UnitStrc* pMissile;
    if (ITEMS_CheckItemTypeId(pWeapon, 38))
    {
        pMissile = sub_6FD11710(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = sub_6FD11420(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    sub_0056C600_ApplyThrowBonuses(pUnit, pMissile, pWeapon);
    return 1;
}

// 0x0056FE40
void __fastcall sub_0056FE40(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, a3);
        return;
    }

    if (SUNIT_IsDead(pUnit))
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, a3);
        return;
    }

    const int nAura = STATLIST_UnitGetStatValue(pUnit, 151, nSkillId);
    if (nAura <= 0)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, a3);
        return;
    }

    sub_0056F7F0(pGame, pUnit, nSkillId, nAura, 1, 1, 0);
    sub_6FD13330(pGame, pUnit, a3, nSkillId, nAura, 0);
}
