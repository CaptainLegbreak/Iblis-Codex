struct D2UnitStrc;
#pragma pack(push, 1)
struct D2SkillPacketStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short nSkillId;
};
#pragma pack(pop)
struct D2SkillsTxt
{
    char unk_00[0x2E];
    short nClientFunction;
    char unk_30[0x20C];
};
struct D2DataTablesStrc
{
    char unk_000[0xB98];
    D2SkillsTxt* pSkills;
    int unk_B9C;
    int nSkillCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall sub_00463990_GetUnit(int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_004CA000_EndSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004CA000
void __fastcall sub_004C8B80_EndSkill(D2UnitStrc* pUnit); // 0x004C8B80
void __fastcall sub_004C9420_EndSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004C9420
void __stdcall sub_00639DB0_ToggleState(D2UnitStrc* pUnit, int nState, int nEnable); // 0x00639DB0

static __forceinline D2SkillsTxt* GetSkillRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillCount)
        return &sgptDataTables->pSkills[nSkillId];
    return 0;
}

// 0x0045D6A0
void __fastcall sub_0045D6A0_EndPacketSkill(D2SkillPacketStrc* pPacket)
{
    D2UnitStrc* pUnit;
    const int nUnitType = pPacket->nUnitType;
    const int nUnitId = pPacket->nUnitId;
    const unsigned short nSkillId = pPacket->nSkillId;
    pUnit = sub_00463990_GetUnit(nUnitId, nUnitType);
    if (!pUnit)
        return;
    D2SkillsTxt* pSkill = GetSkillRecord(nSkillId);
    if (!pSkill)
        return;
    switch (pSkill->nClientFunction)
    {
    case 67:
        sub_004CA000_EndSkill(pUnit, nSkillId);
        break;
    case 77:
    case 78:
        sub_004C8B80_EndSkill(pUnit);
        break;
    case 76:
        sub_004C9420_EndSkill(pUnit, nSkillId);
        break;
    }
    sub_00639DB0_ToggleState(pUnit, 18, 0);
}
