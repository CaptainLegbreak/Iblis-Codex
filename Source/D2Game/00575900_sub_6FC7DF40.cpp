extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2GameStrc;
struct D2SkillStrc;
struct D2SkillListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xA4];
    D2SkillListStrc* pSkills;
};

struct D2PlayerPetStrc;

struct D2PlayerDataStrc
{
    char unk0x00[0x44];
    D2PlayerPetStrc* pPlayerPets;
};

struct D2SkillsTxt
{
    char unk0x000[0xBE];
    char nPetType;
    char unk0x0BF;
    unsigned int dwPetMax;
    char unk0x0C4[0x178];
};

struct D2PetTypeTxt
{
    unsigned int dwHcIdx;
    unsigned char nPetFlags[4];
    short wGroup;
    short wBaseMax;
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x4C];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern "C" const char gszPlayerPetsSourceFile[];                                                            // 0x006E15D8

extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int nPetType);
void __fastcall sub_6FC7D150(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int nBaseMax);           // 0x00575850
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill);                                            // 0x006438F0
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList);                     // 0x00643910
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

#define UNIT_PLAYER 0

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x00575900
void __fastcall sub_6FC7DF40(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData || !pPlayerData->pPlayerPets || !pPlayer->pSkills)
    {
        return;
    }

    int nPetCounters[256];
    memset(nPetCounters, 0, sizeof(nPetCounters));

    D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pPlayer->pSkills);
    while (pSkill)
    {
        D2SkillStrc* pNextSkill = SKILLS_GetNextSkill(pSkill);

        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszPlayerPetsSourceFile, 1139);
        const int nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
        pSkill = pNextSkill;

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            if (pSkillsTxtRecord->nPetType > 0 && pSkillsTxtRecord->nPetType < sgptDataTables->nPetTypeTxtRecordCount)
            {
                int nPetMax = SKILLS_EvaluateSkillFormula(pPlayer, pSkillsTxtRecord->dwPetMax, nSkillId, nLevel);
                if (nPetMax < 1)
                {
                    nPetMax = 1;
                }

                if (nPetMax > nPetCounters[pSkillsTxtRecord->nPetType])
                {
                    nPetCounters[pSkillsTxtRecord->nPetType] = nPetMax;
                    sub_6FC7D150(pGame, pPlayer, pSkillsTxtRecord->nPetType, nPetMax);
                }
            }
        }
    }

    for (int nPetType = 0; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        if (nPetCounters[nPetType] <= 0)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = sub_00478A20_GetPetTypeTxtRecord(nPetType);
            if (pPetTypeTxtRecord)
            {
                sub_6FC7D150(pGame, pPlayer, nPetType, pPetTypeTxtRecord->wBaseMax);
            }
        }
    }
}
