#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
struct D2SkillsTxt;

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    unsigned char unk_0C[0x38];
    unsigned char nPrgDamage;
    unsigned char unk_45[0x1];
    short wSrvMissile[4];
    char unk0x04E[0x06];
    short wAuraStat[6];
    char unk0x060[0x20];
    short nAuraState;
    unsigned char unk_82[0xC6];
    int dwParam[8];
    char unk0x168[0xD4];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304


D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall sub_006260E0(D2StatListStrc* pStatList); // 0x006260E0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __fastcall SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3490

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int unk_0C[9];
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
};

int __stdcall STATLIST_GetStatValue(D2StatListStrc*, int, unsigned short); // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int, int); // 0x004E6CA0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __stdcall sub_005D3880_ProgressiveElemental(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3880
void __stdcall sub_005D3970_ProgressiveElementalConversion(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3970
static __declspec(noinline) void __stdcall sub_005D3790_ProgressiveLeech(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage);
void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3BA0
extern unsigned int gdwBitMasks[]; // 0x006CE268

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D2B60
int __fastcall D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int nManaCost)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 114);
    const int nSkillId = sub_006260E0(pStatList);
    if (STATLIST_UnitGetStatValue(pUnit, 6, 0) >= nManaCost)
    {
        STATLIST_AddUnitStat(pUnit, 6, -nManaCost, 0);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (STATLIST_UnitGetStatValue(pUnit, 6, 0) < (pSkillsTxtRecord->dwParam[4] << 8))
        {
            pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 114);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }
        }
        return 1;
    }
    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 114);
    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    STATLIST_SetUnitStat(pUnit, 6, 256, 0);
    return 0;
}

// 0x005D30F0
int __fastcall SKILLS_SrvSt22_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTargetUnit)))
    {
        switch (pTargetUnit->dwUnitType)
        {
        case 0:
        case 1:
            return 1;
        default:
            return 0;
        }
    }

    return 0;
}

// 0x005D35D0
int __fastcall sub_005D35D0_AlternateChargeWeapon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (pRight == pLeft || !pRight || !pLeft || !ITEMS_CanBeEquipped(pRight) || !ITEMS_CanBeEquipped(pLeft) || !ITEMSIsA(pRight, 45) || !ITEMSIsA(pLeft, 45))
        {
            pUnit->dwFlags |= 0x40;
            SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
            return 1;
        }
    }
    const int nFrame = pUnit->dwSeqFrame >> 8;
    if (nFrame % 2 == 0)
    {
        pUnit->dwFlags &= ~0x40;
        SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
        return 1;
    }

    pUnit->dwFlags |= 0x40;
    SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
    return 1;
}

static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x005D3790
static void __stdcall sub_005D3790_ProgressiveLeech(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return;
    const int nItemLevel = STATLIST_GetStatValue(pStatList, 351, 0);
    const int nCurrentLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    const int nSkillLevel = nCurrentLevel > nItemLevel ? nCurrentLevel : nItemLevel;
    if (nSkillLevel <= 0)
        return;
    if (pSkillsTxt->wAuraStat[0] < 0 || pSkillsTxt->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        return;
    const int nCharges = STATLIST_GetStatValue(pStatList, pSkillsTxt->wAuraStat[0], 0);
    if (nCharges <= 0)
        return;
    int nLeech = sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel);
    switch (nCharges)
    {
    case 1:
        pDamage->dwLifeLeech += nLeech;
        break;
    case 2:
        pDamage->dwLifeLeech += nLeech;
        pDamage->dwManaLeech += nLeech;
        break;
    case 3:
        nLeech *= 2;
        pDamage->dwLifeLeech += nLeech;
        pDamage->dwManaLeech += nLeech;
        break;
    default:
        break;
    }
}

// build: context SKILLS_ApplyProgressiveLeechAndElementalDamage
void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, sgptDataTables->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, sgptDataTables->pProgressiveStates[i]);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
                D2SkillsTxt* pSkillsTxtRecord = nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? sub_0045C4B0_GetSkillsTxtRecord(nSkillId) : 0;
                if (pSkillsTxtRecord)
                {
                    switch (pSkillsTxtRecord->nPrgDamage)
                    {
                    case 2:
                        sub_005D3790_ProgressiveLeech(pUnit, pStatList, pDamage);
                        break;

                    case 3:
                        sub_005D3880_ProgressiveElemental(pUnit, pStatList, pDamage);
                        break;

                    case 4:
                        sub_005D3970_ProgressiveElementalConversion(pUnit, pStatList, pDamage);
                        break;

                    default:
                        break;
                    }
                }
            }
        }
    }
}

// 0x005D3CF0
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return -1;
    }

    if (pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7] && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
            if (pStatList)
            {
                int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                nIndex = MIN(MAX(nIndex, 1), 3);

                return pSkillsTxtRecord->wSrvMissile[nIndex];
            }
        }
    }

    return pSkillsTxtRecord->wSrvMissile[1];
}
