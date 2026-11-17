extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;
struct D2SkillStrc;

struct D2PlayerCmdStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pPlayer;
    D2UnitStrc* pTarget;
    int nX;
    int nY;
    int nArg;
    int nMode;
    D2SkillStrc* pSkill;
};

struct D2SkillsTxt
{
    char unk0x00[0x4];
    unsigned char nFlags[8];
    char unk0x0C[0x8];
    char nAuraTargetState;
    char unk0x15[0x19];
    unsigned short wSrvDoFunc;
    char unk0x30[0x20C];
};

struct D2StringRefStrc
{
    unsigned short nStringId;
    unsigned short unk0x02;
};

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern int gnStringCount_00711EF0;                                                                          // 0x00711EF0
extern D2StringRefStrc gaStringRefs_00711DDC[];                                                             // 0x00711DDC
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId);                          // 0x004CB9C0
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                       // 0x004D9FC0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140

static void __stdcall sub_00461070_RequestSkillString(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(gnStringCount_00711EF0 > nIndex, 0x2CB);
    const unsigned short nStringId = gaStringRefs_00711DDC[nIndex].nStringId;
    if (nStringId)
        sub_004CB9C0_Request(pUnit, nStringId);
}

// 0x004610C0
static int __stdcall sub_004610C0_CheckSkillUse(D2SkillStrc** ppSkill, int* pUseState, D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0())
        return 1;

    if (!ppSkill || !*ppSkill)
        return 0;

    int nUseState = sub_004D9FC0_GetSkillUseState(pUnit, *ppSkill);
    if (pUseState)
        *pUseState = nUseState;

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(*ppSkill);
    if (!pSkillsTxt)
        return 0;

    if (nUseState > 0 && (nUseState <= 2 || nUseState == 4)
        && (pSkillsTxt->nFlags[3] & gdwBitMasks[4]))
    {
        *ppSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0);
        nUseState = sub_004D9FC0_GetSkillUseState(pUnit, *ppSkill);
    }

    if (nUseState == 5 || nUseState == 0)
        return 1;

    sub_00461070_RequestSkillString(pUnit, nUseState);
    return 0;
}

// 0x00461160
static __forceinline int sub_00461160_CheckCommandSkill(D2PlayerCmdStrc* pCmd, int* pUseState)
{
    return sub_004610C0_CheckSkillUse(&pCmd->pSkill, pUseState, pCmd->pPlayer);
}

int __stdcall sub_M135_Emit_00461160A(D2PlayerCmdStrc* pCmd, int* pUseState)
{
    return sub_00461160_CheckCommandSkill(pCmd, pUseState) + 0x3131;
}

int __stdcall sub_M135_Emit_00461160B(int nSkip, D2PlayerCmdStrc* pCmd)
{
    if (!sub_00461160_CheckCommandSkill(pCmd, 0))
        return nSkip;
    return 0x3133;
}
