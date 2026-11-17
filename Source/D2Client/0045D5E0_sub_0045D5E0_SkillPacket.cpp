#pragma pack(push, 1)
struct D2SkillPacketStrc
{
    unsigned char nHeader;
    unsigned char nMode;
    unsigned short wSkillId;
    unsigned short f_4;
    unsigned char nUnitType;
    unsigned int dwUnitId;
    unsigned char nTargetType;
    unsigned int dwTargetId;
    int nX;
    int nY;
};
#pragma pack(pop)

struct D2UnitStrc;

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x230];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
void __fastcall sub_004C6930_DoSkillPrgFunc(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, unsigned char nMode); // 0x004C6930
void __fastcall sub_004C6AC0_DoSkill(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, int nMode);

#define SKILLSFLAGINDEX_PROGRESSIVE 2

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x0045D5E0
void __fastcall sub_0045D5E0_SkillPacket(D2SkillPacketStrc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pTarget = sub_00463990(pPacket->dwTargetId, pPacket->nTargetType);
    const int nX = pPacket->nX;
    const int nY = pPacket->nY;
    const short nSkillId = pPacket->wSkillId;
    const short nSkillLevel = pPacket->f_4;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PROGRESSIVE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PROGRESSIVE & 7])
    {
        sub_004C6AC0_DoSkill(pUnit, pTarget, nSkillId, nSkillLevel, nX, nY, pPacket->nMode);
    }
    else
    {
        sub_004C6930_DoSkillPrgFunc(pUnit, pTarget, nSkillId, nSkillLevel, nX, nY, pPacket->nMode);
    }
}
