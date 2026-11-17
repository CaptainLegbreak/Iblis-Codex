struct D2ClientStrc;
struct D2GameStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

#define UNIT_PLAYER 0
#define STAT_SKILLPTS 5

void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x0053C4A0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_UpdatePlayerVitals_6FC4B240(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x0055F500
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);            // 0x0055FDE0
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove);   // 0x0056DEB0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);                                          // 0x006460F0
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140

// 0x00570360
void __fastcall sub_00570360(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    const int nClassId = pUnit->dwClassId;
    const int nSkillCount = SKILLS_GetPlayerSkillCount(nClassId);
    int nSkillPoints = 0;
    for (int i = 0; i < nSkillCount; ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
        if (pSkill)
        {
            nSkillPoints += SKILLS_GetSkillLevel(pUnit, pSkill, 0);
            D2GAME_SetSkills_6FD14C60(pUnit, nSkillId, 0, 1);
            D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\Skills.cpp", 4257), pUnit, nSkillId, 0, 1);
        }
    }

    STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, nSkillPoints, 0);
    D2GAME_UpdatePlayerVitals_6FC4B240(pGame, pUnit);
    D2GAME_UpdatePlayerItems_6FC4BB90(pGame, pUnit, 1);
}
