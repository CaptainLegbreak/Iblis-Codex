struct D2SkillStrc;
struct D2UnitStrc;

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x198];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

struct D2AnimModeModulatorStrc
{
    int bCanUseVelocityModifierByPassiveSkill;
    int bCanUseVelocityModifier;
    int bCanUseSkillAttackRate;
    int bCanUseAttackRate;
    int bAllowAnimSpeed;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2AnimModeModulatorStrc gaPlayerModesAnimModulators_006E8A00[];                                      // 0x006E8A00
extern D2AnimModeModulatorStrc gaMonModesAnimModulators_006E8B90[];                                         // 0x006E8B90
extern D2AnimModeModulatorStrc gaMonModesAnimModulatorsExpansion_006E8CD0[];                                // 0x006E8CD0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline unsigned int DATATBLS_CheckMonStatsFlag_Inl(D2MonStatsTxt* pMonStatsTxtRecord)
{
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0];
    }

    return 0;
}

static __forceinline int UNITS_IsWalkOrRunMode_Inl(int nAnimMode)
{
    switch (nAnimMode)
    {
    case 2:
    case 0xF:
        return 1;
    }

    return 0;
}

// 0x006214A0
static int __stdcall UNITS_CanAnimModeUseVelocityModifier(int nUnitType, int nAnimMode, D2UnitStrc* pUnit, int nClassId)
{
    D2AnimModeModulatorStrc* pAnimModeModulators;
    switch (nUnitType)
    {
    case 0:
        pAnimModeModulators = &gaPlayerModesAnimModulators_006E8A00[nAnimMode];
        break;
    case 1:
        if (D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nClassId))
        {
            if (DATATBLS_CheckMonStatsFlag_Inl(pMonStatsTxtRecord))
            {
                return UNITS_IsWalkOrRunMode_Inl(nAnimMode);
            }
        }

        if (nClassId < 0x19A)
        {
            pAnimModeModulators = &gaMonModesAnimModulators_006E8B90[nAnimMode];
        }
        else
        {
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion_006E8CD0[nAnimMode];
        }
        break;
    default:
        D2_ASSERT(nUnitType == 0 || nUnitType == 1, 0xBD2);
        return 0;
    }

    if (pAnimModeModulators->bCanUseVelocityModifier)
    {
        return 1;
    }

    if (pAnimModeModulators->bCanUseVelocityModifierByPassiveSkill)
    {
        if (D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit))
        {
            const int nFlags = SKILLS_GetFlags(pUsedSkill);
            if (!(nFlags & 1) || (nFlags & 0x1000))
            {
                return 0;
            }

            return 1;
        }
    }

    return 0;
}

int __stdcall sub_O05_Emit_006214A0(D2UnitStrc* pUnit, int nUnitType, int nAnimMode, int nClassId)
{
    if (UNITS_CanAnimModeUseVelocityModifier(nUnitType, nAnimMode, pUnit, nClassId))
    {
        return nClassId;
    }
    return 0;
}

#include "gen/data/Source/D2Common/006214A0_UNITS_CanAnimModeUseVelocityModifier.inc"
