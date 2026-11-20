#include "D2Structs.h"
#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))

struct D2GameStrc;
struct D2SkillStrc;
struct D2StatListStrc;
struct D2ClientStrc;


struct D2SkillsTxt
{
    char unk0x000[0x186];
    short wMinMana;
    unsigned char nManaShift;
    unsigned char unk0x189;
    short wMana;
    short wLevelMana;
    char unk0x18E[0xAE];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0xC8];
    int nStuff;
    int nShiftedStuff;
};

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define STAT_MANA 8
#define STAT_ITEM_CHARGED_SKILL 204
#define STATE_BLOOD_MANA 114

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall ITEMMODS_GetItemCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int* pCharges, D2StatListStrc** ppStatList); // 0x0065C820
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);     // 0x00625D00
void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pItem); // 0x00627220
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __fastcall D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int nManaCost);                          // 0x005D2B60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall sub_006272B0_UnitStatListCall(D2UnitStrc* pUnit, int nType, int nValue, int n0);             // 0x006272B0

// build: context SKILLS_IsPlayerInline
static __forceinline int SKILLS_IsPlayerInline(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_PLAYER;
}

// build: context SKILLS_GetSkillsTxtRecord
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __declspec(noinline) int __stdcall sub_0056BEC0_UseChargedSkillCharge(D2GameStrc*, D2SkillStrc*, int, D2UnitStrc*);
static int __stdcall sub_0056BEC0_UseChargedSkillCharge(D2GameStrc*, D2SkillStrc*, int, D2UnitStrc*); // 0x0056BEC0
// 0x0056BEC0
static int __stdcall sub_0056BEC0_UseChargedSkillCharge(D2GameStrc* pGame, D2SkillStrc* pSkill, int nOwnerGUID, D2UnitStrc* pPlayer)
{
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nOwnerGUID);
    if (!pItem) return 0;
    int nChargeSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 898);
    int nChargeSkillLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 0);
    int nCharges = 0;
    D2StatListStrc* pStatList = 0;
    if (!ITEMMODS_GetItemCharges(pItem, nChargeSkillId, nChargeSkillLevel, &nCharges, &pStatList) || nCharges <= 0)
        return 0;
    nChargeSkillId = (nChargeSkillId << sgptDataTables->nStuff) + (nChargeSkillLevel & sgptDataTables->nShiftedStuff);
    const int nStatValue = STATLIST_GetStatValue(pStatList, STAT_ITEM_CHARGED_SKILL, nChargeSkillId);
    if (!nStatValue) return 0;
    const int nMaxCharges = nStatValue >> 8;
    --nCharges;
    if (nMaxCharges <= 0 || nMaxCharges > 255) return 0;
    nCharges = D2_MIN(D2_MAX(nCharges, 0), nMaxCharges);
    nChargeSkillLevel = (nCharges & 0xFF) + (nMaxCharges << 8);
    STATLIST_SetBaseStat2(pStatList, STAT_ITEM_CHARGED_SKILL, nChargeSkillLevel, nChargeSkillId, pItem);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pPlayer, ".\\SKILLS\\Skills.cpp", 933), pItem, 1, STAT_ITEM_CHARGED_SKILL, nChargeSkillLevel, nChargeSkillId);
    return 1;
}

// build: context sub_0056BFE0
int __fastcall sub_0056BFE0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_IsPlayerInline(pPlayer))
    {
        return 1;
    }
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 955) == nSkillId)
    {
        const int nOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pSkill);
        if (nOwnerGUID != -1)
        {
            return sub_0056BEC0_UseChargedSkillCharge(pGame, pSkill, nOwnerGUID, pPlayer);
        }
    }
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (!pSkillsTxtRecord->wMana && !pSkillsTxtRecord->wLevelMana)
    {
        return 0;
    }
    const int nLevelBonus = nSkillLevel - 1 < 0 ? 0 : nSkillLevel - 1;
    int nManaCost = (pSkillsTxtRecord->wMana + nLevelBonus * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
    const int nMinManaCost = pSkillsTxtRecord->wMinMana << 8;
    if (nMinManaCost > nManaCost)
    {
        nManaCost = nMinManaCost;
    }
    if (STATES_CheckState(pPlayer, STATE_BLOOD_MANA))
    {
        return D2GAME_SKILLS_BloodMana_6FD025E0(pPlayer, nManaCost);
    }
    if (STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0) < nManaCost)
    {
        return 0;
    }
    sub_006272B0_UnitStatListCall(pPlayer, STAT_MANA, -nManaCost, 0);
    return 1;
}
