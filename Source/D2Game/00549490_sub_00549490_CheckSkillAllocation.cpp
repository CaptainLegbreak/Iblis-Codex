struct D2UnitStrc;
struct D2GameStrc;
struct D2ClientStrc;
struct D2SkillStrc;
struct D2SkillsTxt;

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

#pragma pack(push, 1)
struct D2GSPacketClt3B
{
    unsigned char nHeader;
    unsigned short nSkill;
};
#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(D2UnitStrc* pUnit, int nSkillId);               // 0x0056C700
int __stdcall SKILLS_CheckRequiredSkills(D2UnitStrc* pUnit, int nSkillId);                                  // 0x006447D0
int __stdcall SKILLS_CheckRequiredAttributes(D2UnitStrc* pUnit, int nSkillId);                              // 0x00644920
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x0053C4A0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId);                                                 // 0x004AA8B0
int __fastcall sub_6FD136E0(D2UnitStrc* pUnit, int nSkillId);                                               // 0x00570080
void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x0055F4F0
void __fastcall sub_6FD14C30(D2UnitStrc* pUnit);                                                            // 0x0056DE40

// 0x00549490
static __declspec(noinline) int sub_00549490_CheckSkillAllocation(D2UnitStrc* pUnit, int nSkillId)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 2;
    }
    if (!D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(pUnit, nSkillId))
    {
        return 3;
    }
    if (!SKILLS_CheckRequiredSkills(pUnit, nSkillId))
    {
        return 3;
    }
    return SKILLS_CheckRequiredAttributes(pUnit, nSkillId) ? 0 : 3;
}

// 0x0054BD90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3B_AddSkillPoint_6FC86EF0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }
    const int nSkillId = ((D2GSPacketClt3B*)pPacket)->nSkill;
    const int nResult = sub_00549490_CheckSkillAllocation(pUnit, nSkillId);
    if (nResult)
    {
        if (nResult == 2)
        {
            D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x114F), pUnit, 0, 1, 0);
        }
        return nResult;
    }
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0) >= sub_004AA8B0_GetSkillMaxLevel(nSkillId))
    {
        D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x1159), pUnit, 0, 1, 0);
        return 2;
    }
    if (!sub_6FD136E0(pUnit, nSkillId))
    {
        return 2;
    }
    sub_0055F4F0(pGame, pUnit, 1);
    sub_6FD14C30(pUnit);
    return 0;
}
