struct D2GameStrc;
struct D2UnitStrc;
struct D2SkillStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);           // 0x005701B0
void __stdcall UNITS_InitLeftSkill(D2UnitStrc* pUnit);                                                      // 0x00622F10
void __stdcall UNITS_InitRightSkill(D2UnitStrc* pUnit);                                                     // 0x00622EA0

// 0x0054B810
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2C_2D_52_6FC867B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054B820
int __fastcall sub_0054B820_Rcv0x2D(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054BD00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x39_PurchaseLife_6FC86E50(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054BE70
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3C_SelectSkill_6FC87050(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nValue = *(int*)((char*)pPacket + 1);
    const int nOwnerGUID = *(int*)((char*)pPacket + 5);
    const int bLeftSkill = (unsigned int)nValue >> 31;
    const int nSkillId = nValue & 0x7FFFFFFF;
    if (nSkillId < 0)
    {
        return 3;
    }

    if (nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 3;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill)
    {
        return 3;
    }

    if (!SKILLS_GetSkillLevel(pUnit, pSkill, 1))
    {
        return 3;
    }

    D2GAME_AssignSkill_6FD13800(pUnit, bLeftSkill, nSkillId, nOwnerGUID);
    if (bLeftSkill)
    {
        UNITS_InitLeftSkill(pUnit);
    }
    else
    {
        UNITS_InitRightSkill(pUnit);
    }

    return 0;
}
