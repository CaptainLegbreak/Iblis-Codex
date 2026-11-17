extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SkillStrc;
struct D2SkillListStrc;

struct D2UnitStrc
{
    char unk0x00[0xA8];
    D2SkillListStrc* pSkills;
};

struct D2SkillsTxt
{
    char unk0x000[0x194];
    short wSkillDesc;
    char unk0x196[0x1DC - 0x196];
    unsigned char nCharClass;
    char unk0x1DD[0x23C - 0x1DD];
};

struct D2SkillDescTxt
{
    unsigned char nSkillPage;
    unsigned char nSkillRow;
    char nSkillColumn;
    char unk0x03[0x120 - 0x03];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB8C];
    D2SkillDescTxt* pSkillDescTxt;
    int unk0xB90;
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" const char szSkillsCppFile_006DAB88[];                                                           // 0x006DAB88

D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill);                                            // 0x006438F0
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x00643910
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_IsEnhanceable(int nSkillId);                                                           // 0x00645FB0
void __stdcall SKILLS_RefreshPassiveSkills(D2UnitStrc* pUnit);                                              // 0x00646F20
void __stdcall SKILLS_RemoveSkill(D2UnitStrc* pUnit, int nSkillId, const char* szFile, int nLine);          // 0x006470F0
void __stdcall sub_00647B20_AddSkillBonusLevel(D2UnitStrc* pUnit, int nSkillId, int nBonus);                // 0x00647B20

static D2SkillsTxt* SKILLCLT_GetSkillsTxtRecord(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return pSkillsTxtRecord;
}

static __forceinline D2SkillDescTxt* SKILLCLT_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
    {
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    }
    return 0;
}

// build: context sub_004C7990_GetSkillDescFromSkillId
static __forceinline D2SkillDescTxt* sub_004C7990_GetSkillDescFromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return SKILLCLT_GetSkillDescTxtRecord(pSkillsTxtRecord->wSkillDesc);
}

// 0x004C7990
void __fastcall sub_004C7990(D2UnitStrc* pUnit, int nA, int nB, unsigned char nC)
{
    D2_ASSERT(pUnit, 2410);
    D2_ASSERT(nA, 2411);
    D2_ASSERT(pUnit->pSkills, 2413);

    int nSkillId;
    D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pUnit->pSkills);
    while (pSkill)
    {
        D2SkillStrc* pNextSkill = SKILLS_GetNextSkill(pSkill);
        D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szSkillsCppFile_006DAB88, 2420));
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        D2SkillDescTxt* pSkillDescTxtRecord = sub_004C7990_GetSkillDescFromSkillId(nSkillId);
        if (!pSkillDescTxtRecord)
        {
            continue;
        }

        if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 0 && SKILLS_IsEnhanceable(nSkillId)
            && (!nB || pSkillsTxtRecord->nCharClass == nB)
            && (nC == 4 || pSkillDescTxtRecord->nSkillColumn == nC + 1)
            && SKILLS_GetOwnerGUIDFromSkill(pSkill) == -1)
        {
            sub_00647B20_AddSkillBonusLevel(pUnit, nSkillId, nA);

            D2SkillStrc* pUnitSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
            if (pUnitSkill && !SKILLS_GetSkillLevel(pUnit, pUnitSkill, 1))
            {
                SKILLS_RemoveSkill(pUnit, nSkillId, szSkillsCppFile_006DAB88, 2465);
            }
        }

        pSkill = pNextSkill;
    }

    SKILLS_RefreshPassiveSkills(pUnit);
}
