struct D2GameStrc;
struct D2ClientStrc;
struct D2SkillStrc;
struct D2UnitEventStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; int dwAnimMode; };
struct D2MonStatsTxt { char unk00[0x1a0]; int nDamageRegen; };
struct D2SkillsTxt { char unk00[0xc]; signed char nCharClass; };
struct D2ItemStatCostTxt { char unk00[0x48]; short wItemEvent[2]; short wItemEventFunc[2]; char unk50[0xf4]; };
struct D2DataTablesStrc {
    char unk000[0xc4]; int nStatesTxtRecordCount; char unk0C8[0xb04];
    D2ItemStatCostTxt* pItemStatCostTxt; void* pLinker; int nItemStatCostTxtRecordCount;
    char unkBD8[0x94]; int nStuff; int nMask;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int); // 0x0045C4B0
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc*, D2UnitStrc*, int, int, int); // 0x0053C4A0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*, const char*, int); // 0x005531C0
D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc*); // 0x0055B7E0
void __fastcall sub_0056BD90_RefreshPetMaxForSkill(D2GameStrc*, D2UnitStrc*, int); // 0x0056BD90
void __fastcall sub_6FD11C90(D2UnitStrc*, int, int); // 0x0056C740
void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc*); // 0x0056DFA0
D2UnitEventStrc* __fastcall sub_6FD156A0(D2GameStrc*, D2UnitStrc*, int, int, int, int, int, int); // 0x0056E740
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc*, int, int, int); // 0x005701B0
void __fastcall SKILLITEM_ActivateAura(D2GameStrc*, D2UnitStrc*, int, int, int); // 0x005BF510
void __fastcall SKILLITEM_DeactivateAura(D2GameStrc*, D2UnitStrc*, int, int); // 0x005BF5D0
void __fastcall SUNITEVENT_Unregister(D2GameStrc*, D2UnitStrc*, int, int); // 0x005C0B50
D2UnitEventStrc* __fastcall SUNITEVENT_GetEvent(D2GameStrc*, D2UnitStrc*, int, int, int); // 0x005C0BE0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc*); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc*); // 0x006201D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc*, int*); // 0x00625820
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc*, int, int); // 0x00639E30
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc*); // 0x0063EE90
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*, int, int); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc*, int*, int*, int*, const char*, int); // 0x00645270
void __stdcall SKILLS_RefreshSkill(D2UnitStrc*, int); // 0x00646D60
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc*, int); // 0x00647110
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc*, int, int, int, const char*, int); // 0x00647280
void __stdcall D2Common_10954(D2UnitStrc*, int, int, int, int, int); // 0x00647530
#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))
inline D2ItemStatCostTxt* GetStatCost(int nStat) {
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount) return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}
// 0x0055B800
void __fastcall D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOther, int nLayerStatId, int nPreviousValue, int nNewValue)
{
    if (!pGame || !pUnit) return;
    int nStat = (unsigned int)nLayerStatId >> 16;
    D2ItemStatCostTxt* pCost = GetStatCost(nStat);
    if (!pCost) return;
    int nItemGUID = 0;
    if (pOther) nItemGUID = pOther->dwUnitId;
    if (pCost->wItemEvent[0] > 0) {
        if (nNewValue) {
            if (!SUNITEVENT_GetEvent(pGame, pUnit, 2, nLayerStatId, nLayerStatId)) {
                sub_6FD156A0(pGame, pUnit, pCost->wItemEvent[0], nLayerStatId, 0, pCost->wItemEventFunc[0], 2, nLayerStatId);
                short nSecondEvent = pCost->wItemEvent[1];
                if (nSecondEvent > 0) sub_6FD156A0(pGame, pUnit, nSecondEvent, nLayerStatId, 0, pCost->wItemEventFunc[1], 2, nLayerStatId);
            }
        } else SUNITEVENT_Unregister(pGame, pUnit, 2, nLayerStatId);
    }
    switch (nStat) {
    case 7:
        if (nNewValue != nPreviousValue && nPreviousValue > 0) {
            int nCurrent = STATLIST_UnitGetStatValue(pUnit, 6, 0);
            if (nCurrent > 0) {
                if (nPreviousValue <= 256) nPreviousValue = 256;
                float fValue = (float)nNewValue / nPreviousValue * nCurrent;
                int nValue = (int)fValue;
                STATLIST_SetUnitStat(pUnit, 6, D2_MIN(D2_MAX(nValue, 1), nNewValue), 0);
                if (pUnit->dwUnitType == 1) {
                    D2MonStatsTxt* pMonStats = sub_0055B7E0_GetMonStatsTxtFromUnit(pUnit);
                    if (pMonStats && pMonStats->nDamageRegen) STATLIST_SetUnitStat(pUnit, 74, ((nNewValue >> 8) * pMonStats->nDamageRegen) >> 4, 0);
                }
            }
        }
        break;
    case 9:
        if (nNewValue != nPreviousValue && nPreviousValue > 0) {
            int nCurrent = STATLIST_UnitGetStatValue(pUnit, 8, 0);
            if (nCurrent > 0) {
                if (nPreviousValue <= 256) nPreviousValue = 256;
                float fValue = (float)nNewValue / nPreviousValue * nCurrent;
                int nValue = (int)fValue;
                STATLIST_SetUnitStat(pUnit, 8, D2_MIN(D2_MAX(nValue, 1), nNewValue), 0);
            }
        }
        break;
    case 11:
        if (nNewValue != nPreviousValue && nPreviousValue > 0) {
            int nCurrent = STATLIST_UnitGetStatValue(pUnit, 10, 0);
            if (nCurrent > 0) {
                if (nPreviousValue <= 256) nPreviousValue = 256;
                float fValue = (float)nNewValue / nPreviousValue * nCurrent;
                int nValue = (int)fValue;
                STATLIST_SetUnitStat(pUnit, 10, D2_MIN(D2_MAX(nValue, 1), nNewValue), 0);
            }
        }
        break;
    case 97:
    case 107:
        {
            int nSkillId = (unsigned short)nLayerStatId;
            D2SkillsTxt* pSkills = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
            if (nSkillId && (nStat != 107 || pUnit->dwUnitType == 0 && (!pUnit ? -1 : pUnit->dwClassId) == pSkills->nCharClass)) {
                D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                if (!pSkill) {
                    pSkill = SKILLS_AddSkill(pUnit, nSkillId);
                    SKILLS_AssignSkill(pUnit, nSkillId, 0, 0, ".\\ITEMS\\ItemMode.cpp", 249);
                    D2ClientStrc* pClient;
                    if (pUnit->dwUnitType == 0) pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 253);
                    else pClient = 0;
                    D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(pClient, pUnit, nSkillId, 0, 0);
                }
                SKILLS_RefreshSkill(pUnit, nSkillId);
                sub_0056BD90_RefreshPetMaxForSkill(pGame, pUnit, nSkillId);
                if (nNewValue <= 0) {
                    nNewValue = 1;
                    if (SKILLS_GetSkillLevel(pUnit, pSkill, 0)) {
                        nNewValue = 0;
                        if (SKILLS_GetSkillLevel(pUnit, pSkill, 1)) return;
                    }
                    if (UNITS_GetLeftSkill(pUnit) == pSkill) D2GAME_AssignSkill_6FD13800(pUnit, 1, 0, -1);
                    if (UNITS_GetRightSkill(pUnit) == pSkill) D2GAME_AssignSkill_6FD13800(pUnit, 0, 0, -1);
                    if (nNewValue) SKILLS_AssignSkill(pUnit, nSkillId, 0, 1, ".\\ITEMS\\ItemMode.cpp", 282);
                }
            }
        }
        break;
    case 83:
        if (pUnit->dwUnitType == 0 && (!pUnit ? -1 : pUnit->dwClassId) == (unsigned short)nLayerStatId)
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else
        {
            int nType = pUnit->dwUnitType;
            int nClass = pUnit->dwClassId;
            int nMode = pUnit->dwAnimMode;
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ITEMS\\ItemMode.cpp", 304);
            if (nType == 0 && nClass == (unsigned short)nLayerStatId)
            {
                D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
            }
        }
        break;
    case 188:
        if (pUnit->dwUnitType == 0 && (!pUnit ? -1 : pUnit->dwClassId) == ((unsigned short)nLayerStatId >> 3))
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else
        {
            int nType = pUnit->dwUnitType;
            int nClass = pUnit->dwClassId;
            int nMode = pUnit->dwAnimMode;
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ITEMS\\ItemMode.cpp", 325);
            if (nType == 0 && nClass == ((unsigned short)nLayerStatId >> 3))
            {
                D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
            }
        }
        break;
    case 126:
    case 127:
        D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        break;
    case 151:
        {
            int nAuraSkill = (unsigned short)nLayerStatId;
            if (nNewValue) SKILLITEM_ActivateAura(pGame, pUnit, nItemGUID, nAuraSkill, nNewValue);
            else SKILLITEM_DeactivateAura(pGame, pUnit, nItemGUID, nAuraSkill);
        }
        break;
    case 204:
        if (pOther) {
            int nShift = sgptDataTables->nStuff;
            int nLevel = sgptDataTables->nMask;
            int nLayer = (unsigned short)nLayerStatId;
            int nSkillId = nLayer >> nShift;
            nLevel &= nLayer;
            int nCharges = STATLIST_UnitGetStatValue(pOther, nStat, nLayer) & 255;
            if (nCharges > 0 && STATLIST_GetOwner(pOther, 0) == pUnit) {
                D2Common_10954(pUnit, nItemGUID, nSkillId, nLevel, nCharges, 0);
            } else {
                D2Common_10954(pUnit, nItemGUID, nSkillId, nLevel, 0, 1);
                sub_0056BD90_RefreshPetMaxForSkill(pGame, pUnit, nSkillId);
            }
        }
        break;
    case 98:
        {
            int nState = (unsigned short)nLayerStatId;
            if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount) {
                int bState = STATES_CheckState(pUnit, nState);
                if (nNewValue) {
                    if (bState) return;
                    sub_6FD11C90(pUnit, nState, 0);
                    STATES_ToggleState(pUnit, nState, 1);
                } else {
                    if (!bState) return;
                    sub_6FD11C90(pUnit, nState, 1);
                    STATES_ToggleState(pUnit, nState, 0);
                }
                STATES_ToggleGfxStateFlag(pUnit, nState, 1);
            }
        }
        break;
    }
}
