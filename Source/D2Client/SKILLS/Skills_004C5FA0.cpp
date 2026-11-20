#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2PetTypeTxt;
struct D2SkillsTxt;
struct D2SkillDescTxt;


struct D2PetTypeTxt
{
    unsigned int dwPetType;
    unsigned char nFlags[4];
    char unk0x08[0xD8];
};


enum
{
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall sub_00479150_GetOwnerId(int nUnitId); // 0x00479150
int __fastcall sub_00479180_GetPetType(int nUnitId); // 0x00479180

struct D2SkillsTxt
{
    char unk_00[0x2E];
    short nClientFunction;
    unsigned char unk_30[0x164];
    short wSkillDesc;
    char unk0x196[0x1DC - 0x196];
    unsigned char nCharClass;
    char unk0x1DD[0x23C - 0x1DD];
};

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
void __fastcall sub_004CA000(D2UnitStrc* pUnit, int nSkillId); // 0x004CA000
void __fastcall sub_004C8B80_ResetLeapCollision(D2UnitStrc* pUnit); // 0x004C8B80
void __fastcall sub_004C9420(D2UnitStrc* pUnit, int nSkillId); // 0x004C9420
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2SkillDescTxt
{
    unsigned char nSkillPage;
    unsigned char nSkillRow;
    char nSkillColumn;
    char unk0x03[0x120 - 0x03];
};

extern "C" const char szSkillsCppFile_006DAB88[]; // 0x006DAB88
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_IsEnhanceable(int nSkillId); // 0x00645FB0
void __stdcall sub_00647B20_AddSkillBonusLevel(D2UnitStrc* pUnit, int nSkillId, int nBonus); // 0x00647B20

static __forceinline D2PetTypeTxt* DATATBLS_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }
    return 0;
}

// 0x004C5FA0
int __fastcall sub_004C5FA0_CheckPetTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if ((!pTarget ? 6 : pTarget->dwUnitType) != UNIT_MONSTER)
    {
        return 0;
    }

    const int nOwnerId = sub_00479150_GetOwnerId(!pTarget ? -1 : pTarget->dwUnitId);
    if (nOwnerId != (!pUnit ? -1 : pUnit->dwUnitId))
    {
        return 0;
    }

    D2PetTypeTxt* pPetTypeTxtRecord = DATATBLS_GetPetTypeTxtRecord(sub_00479180_GetPetType(!pTarget ? -1 : pTarget->dwUnitId));
    if (!pPetTypeTxtRecord)
    {
        return 0;
    }

    return (pPetTypeTxtRecord->nFlags[3 >> 3] & gdwBitMasks[3 & 7]) != 0;
}

static __forceinline D2SkillsTxt* GetSkillRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004C7890
void __fastcall sub_004C7890(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;
    if (STATES_CheckState(pUnit, 18))
        return;
    if (SKILLS_GetFlags(pSkill) & 2)
        return;
    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 2365);
    D2SkillsTxt* pSkillsTxt = GetSkillRecord(nSkillId);
    if (!pSkillsTxt)
        return;
    switch (pSkillsTxt->nClientFunction)
    {
    case 67:
        sub_004CA000(pUnit, nSkillId);
        break;
    case 77:
    case 78:
        sub_004C8B80_ResetLeapCollision(pUnit);
        break;
    case 76:
        sub_004C9420(pUnit, nSkillId);
        break;
    }
}

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
