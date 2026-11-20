#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Skills.h"
struct D2UnitStrc;

#define UNIT_PLAYER 0
#define UNIT_INVALID 6
#define STAT_MANA 8
#define SKILLSRVDO_SHAPESHIFT 116
#define STATE_NOMANAREGEN 85
#define STAT_MODIFIERLIST_SKILL 350
#define STAT_MODIFIERLIST_LEVEL 351
#define SKILLSFLAGINDEX_AURA 5
#define SKILLSFLAGINDEX_IMMEDIATE 15
struct D2SkillsTxt;

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    unsigned char unk_0C[0x22];
    unsigned short wSrvDoFunc;
    unsigned char unk_30[0x50];
    short nAuraState;
    unsigned char unk_82[0x106];
    unsigned char nManaShift;
    char unk0x189;
    short wMana;
    short wLevelMana;
    char unk0x18E[0xAE];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit); // 0x0063A400
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00647D00
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetSkillId(D2StatListStrc* pStatList, int nSkillId); // 0x006260D0
void __stdcall STATLIST_SetSkillLevel(D2StatListStrc* pStatList, int nSkillLevel); // 0x006260F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
int __fastcall sub_6FD13260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5); // 0x0056CDA0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* hSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges); // 0x00643B00
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x23_6FC3DC60(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned char a4, unsigned short a5, int a6); // 0x0053C590
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0056C160
int __fastcall SKILLS_HasManaOrChargesForUsedSkill(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1)
    {
        return pSkill->nCharges > 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1) - 1;
    if (nSkillLevel < 0)
    {
        nSkillLevel = 0;
    }

    const int nManaCost = (pSkillsTxtRecord->wMana + nSkillLevel * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
    if (pSkillsTxtRecord->wSrvDoFunc == SKILLSRVDO_SHAPESHIFT && STATES_IsUnitShapeShifted(pUnit))
    {
        return 1;
    }

    return STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) >= nManaCost;
}

// 0x0056D370
void __fastcall SKILLS_EnlargeVector(int* pX, int* pY)
{
    int nDistance = *pX * *pX + *pY * *pY;
    if (nDistance < 4)
    {
        *pX <<= 2;
        *pY <<= 2;
        nDistance = *pX * *pX + *pY * *pY;
    }

    if (nDistance < 16)
    {
        *pX <<= 1;
        *pY <<= 1;
    }
}

// 0x0056D3B0
void __fastcall SKILLS_MakeShortPerpendicularVector(int* pX, int* pY)
{
    int nX = *pY;
    int nY = -*pX;
    while (nX * nX + nY * nY > 3)
    {
        nX /= 2;
        nY /= 2;
    }

    *pX = nX;
    *pY = nY;
}

// 0x0057E270
void __fastcall SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nMinDamage = SKILLS_GetMinPhysDamage(pAttacker, nSkillId, nSkillLevel, 0);
        const int nMaxDamage = SKILLS_GetMaxPhysDamage(pAttacker, nSkillId, nSkillLevel, 0);
        pDamage->dwPhysDamage = SUNITDMG_ApplyDamageBonuses(pAttacker, 0, 0, nMinDamage, nMaxDamage, 0, 0, 128);
        D2GAME_RollElementalDamage_6FD14DD0(pAttacker, pDamage, nSkillId, nSkillLevel);
    }
}

// 0x0056FF10
static void __stdcall sub_0056FF10_StartAssignedAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
        {
            D2SkillStrc* pHighestLevelSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
            if (pHighestLevelSkill)
            {
                const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pHighestLevelSkill, 1);
                if (nSkillLevel > 0)
                {
                    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_IMMEDIATE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_IMMEDIATE & 7])
                    {
                        sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
                    }
                    else
                    {
                        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);

                        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
                        if (!pStatList)
                        {
                            pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
                        }

                        if (pStatList)
                        {
                            STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
                            STATLIST_SetSkillId(pStatList, nSkillId);
                            STATLIST_SetSkillLevel(pStatList, nSkillLevel);
                            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                            STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
                            STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
                        }
                    }

                    sub_6FD13260(pGame, pUnit, nSkillId, nSkillLevel, 1);
                }
            }
        }
    }
}

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags)
{
    if (nSkillId == SKILL_LEFTHANDSWING)
    {
        return;
    }

    if (!a2 && STATES_CheckState(pUnit, STATE_NOMANAREGEN))
    {
        STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
    }

    D2SkillStrc* pSkill = sub_006439B0_SkillFindByOwner(pUnit, nSkillId, nFlags);
    if (!pSkill)
    {
        return;
    }

    D2SkillStrc* pRightSkill = 0;
    if (a2)
    {
        SKILLS_SetLeftActiveSkill(pUnit, nSkillId, nFlags);
    }
    else
    {
        pRightSkill = UNITS_GetRightSkill(pUnit);
        SKILLS_SetRightActiveSkill(pUnit, nSkillId, nFlags);
    }

    {
        int nOwnerGUID = -1;
        SKILLS_GetSkillInfo(pSkill, &nOwnerGUID, 0, 0, 0);
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            D2GAME_PACKETS_SendPacket0x23_6FC3DC60(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 3499), pUnit->dwUnitType, pUnit->dwUnitId, a2, nSkillId, nOwnerGUID);
        }
    }

    if (!a2)
    {
        if (pRightSkill)
        {
            D2SkillsTxt* pRightSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\SKILLS\\Skills.cpp", 3507));
            if (pRightSkillsTxtRecord && pRightSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
            {
                if (pRightSkillsTxtRecord->nAuraState >= 0 || pRightSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pRightSkillsTxtRecord->nAuraState);
                    if (pStatList)
                    {
                        D2Common_10474(pUnit, pStatList);
                        STATLIST_FreeStatList(pStatList);
                    }

                    STATES_ToggleState(pUnit, pRightSkillsTxtRecord->nAuraState, 0);
                }

                D2GAME_EVENTS_Delete_6FC34840(SUNIT_GetGameFromUnit(pUnit), pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            }
        }

        if (SKILLS_GetSkillsTxtRecord(nSkillId)->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
        {
            sub_0056FF10_StartAssignedAura(SUNIT_GetGameFromUnit(pUnit), pUnit, nSkillId);
        }
    }
}
