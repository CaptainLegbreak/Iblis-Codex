struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2StatListStrc;
struct D2SkillStrc;

struct D2SkillsTxt
{
    char unk0x000[0x60];
    unsigned int dwAuraLenCalc;
    char unk0x064[0x1D8];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_0046AE50_StartTimedBox(int nFadeIn, int nHold, int nFadeOut, int nLevelId, int bForce);  // 0x0046AE50
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId);                                                 // 0x004AA8B0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
void __stdcall sub_00647AA0_SetSkillBonusLevel(D2UnitStrc* pUnit, int nSkillId, int nBonus);               // 0x00647AA0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004D87E0
void __fastcall sub_004D87E0_StateAuraEffect(D2UnitStrc* pUnit, int nState)
{
    int nLevel;
    D2StatListStrc* pStatList;
    int nSkillId;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);
    nLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    sub_0046AE50_StartTimedBox(5, nValue * 3 / 5, nValue * 2 / 5, nLevelId, 0);
}

// 0x004D88A0
void __fastcall sub_004D88A0_StateSkillLevel(D2UnitStrc* pUnit, int nState)
{
    int nLevel;
    D2StatListStrc* pStatList;
    int nSkillId;

    if (pUnit == sub_00463DD0())
    {
        return;
    }

    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);
    nLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    int nCurrent = pSkill ? SKILLS_GetSkillLevel(pUnit, pSkill, 1) : 0;
    if (nCurrent == nLevel)
    {
        return;
    }

    int nMax = sub_004AA8B0_GetSkillMaxLevel(nSkillId);
    if (nLevel > nMax)
    {
        SKILLS_AssignSkill(pUnit, nSkillId, nMax, 0, ".\\UNIT\\PlrSkills.cpp", 0x11B);
        sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nLevel - nMax);
    }
    else
    {
        SKILLS_AssignSkill(pUnit, nSkillId, nLevel, 0, ".\\UNIT\\PlrSkills.cpp", 0x120);
    }
}
