struct D2GameStrc;
struct D2SkillStrc;
struct D2StatListStrc;
struct D2SeedStrc
{
    unsigned int dwLow;
    unsigned int dwHigh;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
};
struct D2SkillsTxt
{
    char unk0x00[0x07];
    unsigned char nFlags0;
    char unk0x08[0x2E - 0x08];
    unsigned short wSrvDoFunc;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
int __fastcall sub_0057ED70_IsEndAnimDue(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057ED70
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
extern const unsigned char gbMask_006CE284; // 0x006CE284

static __forceinline int sub_GetConcStat(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x2A);
    return STATLIST_GetStatValue(pStatList, 0xA4, 0);
}

static __forceinline int sub_GetAnimMode(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

// 0x0057EEC0
int __fastcall sub_0057EEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int bCheckUsedSkill, D2SkillStrc* pSkill)
{
    if (STATES_CheckState(pUnit, 0x36))
    {
        return 0;
    }

    if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 17)
    {
        return 0;
    }

    if (nMode == 0 || !bCheckUsedSkill)
    {
        return 1;
    }

    D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
    if (!pUsedSkill)
    {
        return 1;
    }

    const int nUsedSkillId = SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\PLAYER\\PlrModes.cpp", 185);

    D2SkillsTxt* pUsedSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nUsedSkillId);
    if (!pUsedSkillsTxtRecord)
    {
        return 1;
    }

    if (pSkill == pUsedSkill && (pUsedSkillsTxtRecord->wSrvDoFunc == 67 || pUsedSkillsTxtRecord->wSrvDoFunc == 76))
    {
        return 1;
    }

    if (pUsedSkillsTxtRecord->nFlags0 & gbMask_006CE284)
    {
        if ((STATES_CheckState(pUnit, 0x2A)
            && (int)(SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100)) < sub_GetConcStat(pUnit))
            || STATES_CheckState(pUnit, 0x0F))
        {
            if (sub_GetAnimMode(pUnit) == 1)
            {
                sub_6FC817D0(pGame, pUnit, 0, 1, 0, 0, 1);
                return 1;
            }

            return 0;
        }

        return 1;
    }

    if (sub_GetAnimMode(pUnit) == 1)
    {
        sub_6FC817D0(pGame, pUnit, 0, 1, 0, 0, 1);
        return 1;
    }

    switch (nMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
    case 13:
    case 18:
        if (sub_0057ED70_IsEndAnimDue(pGame, pUnit) != 0)
        {
            return 1;
        }
        break;

    default:
        break;
    }

    return 0;
}
