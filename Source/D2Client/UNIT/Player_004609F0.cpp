#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Structs.h"

struct D2GameStrc;
struct D2SkillsTxt;
struct D2PlayerDataStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall sub_00460930_SetUnitLightRadius(D2UnitStrc* pUnit, int nValue); // 0x00460930
void __fastcall sub_004609A0_SetUnitLightColor(D2UnitStrc* pUnit, int nValue); // 0x004609A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
void __stdcall D2Common_10954(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bFreeMemory); // 0x00647530

struct D2PlayerDataStrc
{
    char unk_000[0x154];
    int nState;
    int nValue1;
    int nValue2;
};

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

// 0x004609F0
void __fastcall sub_004609F0_OnStatChanged(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue)
{
    if (!pOwner)
    {
        return;
    }

    int nStatId = (unsigned int)nLayer_StatId >> 16;
    switch (nStatId)
    {
    case 89:
        sub_00460930_SetUnitLightRadius(pOwner, nNewValue);
        break;

    case 90:
        sub_004609A0_SetUnitLightColor(pOwner, nNewValue);
        break;

    case 97:
    case 107:
        if ((!pOwner ? 6 : pOwner->dwUnitType) == 0)
        {
            int nSkillId = (unsigned short)nLayer_StatId;
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pOwner, nSkillId, -1);
            if (!nNewValue)
            {
                if (pSkill && SKILLS_GetSkillLevel(pOwner, pSkill, 0) <= 0)
                {
                    SKILLS_RemoveSkill(pOwner, nSkillId, ".\\UNIT\\Player.cpp", 221);
                }
            }
            else if (!pSkill)
            {
                D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                if (nStatId == 97 || (pSkillsTxtRecord && pSkillsTxtRecord->nCharClass == (!pOwner ? -1 : pOwner->dwClassId)))
                {
                    SKILLS_AssignSkill(pOwner, nSkillId, 0, 0, ".\\UNIT\\Player.cpp", 232);
                }
            }
        }
        break;

    case 204:
        if ((!pOwner ? 6 : pOwner->dwUnitType) == 0)
        {
            int nLayer = (unsigned short)nLayer_StatId;
            int nSkillId = nLayer >> sgptDataTables->nStuff;
            int nSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
            if (pOther)
            {
                int nOwnerGUID = pOther->dwUnitId;
                int nCharges = STATLIST_UnitGetStatValue(pOther, nStatId, nLayer) & 0xFF;
                if (nCharges > 0 && STATLIST_GetOwner(pOther, 0) == pOwner)
                {
                    D2Common_10954(pOwner, nOwnerGUID, nSkillId, nSkillLevel, nCharges, 0);
                }
                else
                {
                    D2Common_10954(pOwner, nOwnerGUID, nSkillId, nSkillLevel, 0, 1);
                }
            }
        }
        break;
    }
}

static __forceinline int PLAYER_GetValue1(D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
        return pUnit->pPlayerData->nValue1;
    return 0;
}

static __forceinline int PLAYER_GetValue2(D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
        return pUnit->pPlayerData->nValue2;
    return 0;
}

// 0x00461D60
int __stdcall sub_00461D60_CheckPlayerState(int nValue1, int nValue2)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nUnitType = !pPlayer ? 6 : pPlayer->dwUnitType;
    if (!pPlayer || nUnitType != UNIT_PLAYER)
        return 0;

    D2PlayerDataStrc* pPlayerData = pPlayer->pPlayerData;
    if (!pPlayerData || pPlayerData->nState != 19)
        return 0;

    const int nFirst = PLAYER_GetValue1(pPlayer);
    const int nSecond = PLAYER_GetValue2(pPlayer);
    if (nFirst == nValue1 && nSecond == nValue2)
        return 1;
    return 0;
}
