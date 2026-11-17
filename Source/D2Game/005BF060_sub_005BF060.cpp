typedef unsigned int size_t;
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                    // 0x00681EF0

struct D2GameStrc;
struct D2ClientStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2StatListStrc;
struct D2ItemsTxt;
struct D2MonStatsTxt;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    unsigned int dwUnitId;
    char unk0x10[0x1C];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
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

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

struct D2BooksTxt
{
    char unk0x00[0x08];
    int dwScrollSkillId;
    int dwBookSkillId;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBD4];
    int nItemStatCostTxtRecordCount;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define OBJECT_STASH 267
#define UPDATEUI_CLOSEALL 17
#define UPDATEUI_OPENCUBE 21
#define SKILL_FIREBALL 47
#define ITEMTYPE_BOOK 18
#define ITEMTYPE_SCROLL 22
#define STAT_HITPOINTS 6
#define STAT_LEVEL 12
#define STAT_VELOCITYPERCENT 67
#define STAT_ATTACKRATE 68
#define STAT_OTHER_ANIMRATE 69
#define STAT_QUANTITY 70
#define STAT_VALUE 71
#define STATE_SLOWED 24

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                         // 0x00629DA0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                             // 0x00535060
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                          // 0x00554D00
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                   // 0x00554190
void __fastcall sub_6FC4B830(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0055FA40
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo);      // 0x0053CAB0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID);      // 0x00554120
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                               // 0x006335F0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int a5); // 0x005FDCA0
int __fastcall SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int a6); // 0x005FDD60
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                   // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                              // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                               // 0x0063DFD0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                       // 0x00629BB0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                                // 0x00627F80
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex);                                                // 0x006374B0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                  // 0x0063E020
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                          // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                          // 0x0045AE20
void __fastcall sub_6FC47D30(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pUnused); // 0x0055E170
void __fastcall sub_6FC49220(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pUnused, int a7); // 0x00562390
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster);                                                        // 0x0063E940
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                                // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                    // 0x00621E40
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                 // 0x005A0180
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster);                     // 0x0063E9F0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling);                                             // 0x0063EE90
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);                                               // 0x0056E970
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);           // 0x006270B0
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);          // 0x00623F50

// 0x005BF060
int __fastcall sub_005BF060(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    const int nStatId = ITEMS_GetFileIndex(pItem);
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        const int nValue = STATLIST_UnitGetStatValue(pItem, STAT_VALUE, 0);
        if (nValue)
        {
            STATLIST_AddUnitStat(pUnit, nStatId, nValue, 0);
            return 1;
        }
    }

    return 0;
}

// 0x005BF0C0
int __fastcall SKILLITEM_pSpell07_OpenCube(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    if (PLAYER_IsBusy(pUnit))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
        if (!pInteractUnit || pInteractUnit->dwUnitType != UNIT_OBJECT || pInteractUnit->dwClassId != OBJECT_STASH)
        {
            return 0;
        }

        SUNIT_ResetInteractInfo(pUnit);
        sub_6FC4B830(pGame, pUnit);
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillItem.cpp", 947), UPDATEUI_CLOSEALL);
    }

    SUNIT_SetInteractInfo(pUnit, UNIT_ITEM, !pItem ? -1 : pItem->dwUnitId);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillItem.cpp", 961), UPDATEUI_OPENCUBE);
    sub_6FC4B830(pGame, pUnit);
    return 0;
}

// 0x005BF170
int __fastcall SKILLITEM_pSpell10_CastFireBallOnTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (!DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit)
    {
        return SKILLITEM_CastSkillOnTarget(pUnit, SKILL_FIREBALL, 1, pTargetUnit, 0);
    }

    return SKILLITEM_CastSkillOnPosition(pUnit, SKILL_FIREBALL, 1, D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath), 0);
}

// 0x005BF1F0
int __fastcall SKILLITEM_pSpell11_CastFireBallToCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, unsigned short nX, unsigned short nY, int nSkillId)
{
    if (!DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
    {
        return 0;
    }

    return SKILLITEM_CastSkillOnPosition(pUnit, SKILL_FIREBALL, 1, nX, nY, 0);
}

// 0x005BF3D0
int __fastcall SKILLS_SrvDo113_Scroll_Book(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pInvItem;
    D2UnitStrc* pItem;
    for (pInvItem = INVENTORY_GetFirstItem(pUnit->pInventory); pInvItem; pInvItem = INVENTORY_GetNextItem(pInvItem))
    {
        pItem = INVENTORY_UnitIsItem(pInvItem);
        if (ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BOOK))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord && pBooksTxtRecord->dwBookSkillId == nSkillId && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
            {
                break;
            }
        }
        else if (ITEMS_CheckItemTypeId(pItem, ITEMTYPE_SCROLL))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord && pBooksTxtRecord->dwScrollSkillId == nSkillId)
            {
                break;
            }
        }
    }

    if (pInvItem)
    {
        switch (INVENTORY_GetItemNodePage(pInvItem))
        {
        case 1:
        {
            int nUnused;
            sub_6FC47D30(pGame, pUnit, !pItem ? -1 : pItem->dwUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), &nUnused);
            return 1;
        }
        case 2:
        {
            int nUnused;
            sub_6FC49220(pGame, pUnit, !pItem ? -1 : pItem->dwUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), &nUnused, 0);
            return 1;
        }
        }
    }

    return 0;
}

// 0x005BF670
int __fastcall SKILLITEM_EventFunc06_AttackerTakesDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwPhysDamage = nDamage << 8;
    damage.dwHitClass = 0x8D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF720
int __fastcall SKILLITEM_EventFunc10_AttackerTakesLightDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwLtngDamage = nDamage << 8;
    damage.dwHitClass = 0x4D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF7D0
int __fastcall SKILLITEM_EventFunc11_ApplyFireDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwFireDamage = nDamage << 8;
    damage.dwHitClass = 0x2D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF880
int __fastcall SKILLITEM_EventFunc12_ApplyColdDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    const int nDefenderLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    int nLength = 25;
    if (nAttackerLevel > nDefenderLevel)
    {
        const int nLevelDiff = nAttackerLevel - nDefenderLevel;
        nLength += 10 * nLevelDiff;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwColdLen = nLength;
    damage.dwColdDamage = nDamage << 8;
    damage.dwHitClass = 0x3D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005C0260
int __fastcall SKILLITEM_EventFunc18_HealAfterDemonKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || !MONSTERS_IsDemon(pUnit))
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pAttacker);
    int nHitpoints = STATLIST_UnitGetStatValue(pAttacker, STAT_HITPOINTS, 0);
    if (nHitpoints >= nMaxHp)
    {
        return 0;
    }

    nHitpoints += nValue << 8;
    nHitpoints = nHitpoints > 0 ? nHitpoints : 0;
    STATLIST_SetUnitStat(pAttacker, STAT_HITPOINTS, nHitpoints < nMaxHp ? nHitpoints : nMaxHp, 0);
    UNITS_SetOverlay(pAttacker, 151, 0);
    return 1;
}

// 0x005C0310
int __fastcall SKILLITEM_EventFunc19_Slow(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    int nSlowValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nSlowValue)
    {
        return 0;
    }

    const int nUnitType = pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
    {
        if (nSlowValue >= 50)
        {
            nSlowValue = 50;
        }
    }
    else if (nUnitType == UNIT_MONSTER)
    {
        if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 12))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERS_IsBoss(0, pUnit))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 2))
        {
            if (nSlowValue >= 75)
            {
                nSlowValue = 75;
            }
        }
        else
        {
            if (nSlowValue >= 90)
            {
                nSlowValue = 90;
            }
        }
    }
    else
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAttacker;
    curse.pTarget = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = 750;
    curse.nStat = STAT_VELOCITYPERCENT;
    curse.nStatValue = -nSlowValue;
    curse.nState = STATE_SLOWED;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return 0;
    }

    sub_006270B0(pStatList, STAT_ATTACKRATE, -nSlowValue, 0);
    sub_006270B0(pStatList, STAT_OTHER_ANIMRATE, -nSlowValue, 0);
    UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\SKILLS\\SkillItem.cpp", 2186);
    return 1;
}
