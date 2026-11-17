struct D2SkillsTxt;
struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    unsigned int dwSkillMode;
    unsigned int dwFlags;
    unsigned int unk0x10[2];
    unsigned int nPar1;
    unsigned int nPar2;
    unsigned int nPar3;
    unsigned int nPar4;
    int nSkillLevel;
    unsigned int nLevelBonus;
    int nQuantity;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define SKILLS_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00644380
int __stdcall D2Common_10969(D2SkillStrc* pSkill)
{
    SKILLS_ASSERT(pSkill, 2595);

    return pSkill->unk0x10[0];
}

// 0x006443B0
void __stdcall D2Common_10970(D2SkillStrc* pSkill, int nValue)
{
    SKILLS_ASSERT(pSkill, 2604);

    pSkill->unk0x10[0] = nValue;
}

// 0x006443F0
int __stdcall D2Common_10971(D2SkillStrc* pSkill)
{
    SKILLS_ASSERT(pSkill, 2613);

    return pSkill->unk0x10[1];
}

// 0x00644420
void __stdcall D2Common_10972(D2SkillStrc* pSkill, int nValue)
{
    SKILLS_ASSERT(pSkill, 2622);

    pSkill->unk0x10[1] = nValue;
}

// 0x00644460
void __stdcall D2Common_10973(D2SkillStrc* pSkill)
{
    SKILLS_ASSERT(pSkill, 2631);

    pSkill->unk0x10[0] = 0;
    pSkill->unk0x10[1] = 0;
}

// 0x006444A0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill)
{
    SKILLS_ASSERT(pSkill, 2642);

    return pSkill->nPar1;
}

// 0x006444D0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill)
{
    SKILLS_ASSERT(pSkill, 2651);

    return pSkill->nPar2;
}

// 0x00644500
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill)
{
    SKILLS_ASSERT(pSkill, 2660);

    return pSkill->nPar3;
}

// 0x00644530
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill)
{
    SKILLS_ASSERT(pSkill, 2669);

    return pSkill->nPar4;
}

// 0x00644560
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue)
{
    SKILLS_ASSERT(pSkill, 2678);

    pSkill->nPar1 = nValue;
}

// 0x006445A0
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue)
{
    SKILLS_ASSERT(pSkill, 2687);

    pSkill->nPar2 = nValue;
}

// 0x006445E0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue)
{
    SKILLS_ASSERT(pSkill, 2696);

    pSkill->nPar3 = nValue;
}

// 0x00644620
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue)
{
    SKILLS_ASSERT(pSkill, 2705);

    pSkill->nPar4 = nValue;
}

// 0x00644660
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue)
{
    SKILLS_ASSERT(pSkill, 2714);

    pSkill->dwFlags = nValue;
}

// 0x006450F0
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill)
{
    SKILLS_ASSERT(pSkill, 3492);

    return pSkill->nQuantity;
}

// 0x00645120
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nValue)
{
    SKILLS_ASSERT(pSkill, 3501);

    pSkill->nQuantity = nValue;
}
