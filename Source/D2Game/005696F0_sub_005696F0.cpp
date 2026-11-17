struct D2ClientStrc;
struct D2GameStrc;
struct D2SkillStrc;
struct D2UnitStrc;

struct D2DataTablesStrc
{
    char unk0x00[0xBA8];
    int nHighestClassSkillCount;
};

#define PLRSAVE2_SKILLS_MARKER 0x6669
#define NUMBER_OF_PLAYERCLASSES 7

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient);                                                   // 0x005385F0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);                                          // 0x006460F0
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140

// 0x005696F0
int __fastcall sub_005696F0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd)
{
    unsigned char* pData = *ppSection;
    if (pData + sgptDataTables->nHighestClassSkillCount + 2 > pEnd)
    {
        return 1;
    }

    *(unsigned short*)pData = PLRSAVE2_SKILLS_MARKER;
    pData += 2;

    const int nClassId = CLIENTS_GetClassId(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrSave2.cpp", 775));
    if (nClassId >= NUMBER_OF_PLAYERCLASSES)
    {
        return 2;
    }

    for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        *pData = SKILLS_GetSkillLevel(pUnit, SKILLS_GetSkillById(pUnit, nSkillId, -1), 0);
        ++pData;
    }

    *ppSection = pData;
    return 0;
}
