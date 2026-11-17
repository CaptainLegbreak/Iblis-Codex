struct D2SkillStrc;
struct D2SkillListStrc;
struct D2MonsterDataStrc;
struct D2PlayerDataStrc;

struct D2SkillsTxt
{
    char unk0x00[6];
    unsigned char dwFlags[8];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    union
    {
        D2PlayerDataStrc* pPlayerData;
        D2MonsterDataStrc* pMonsterData;
    };
};

struct D2AnimUnkStrc
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
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2AnimUnkStrc gaPlayerModesAnimModulators[];                                                         // 0x006E8A00
extern D2AnimUnkStrc gaMonModesAnimModulators[];                                                            // 0x006E8B90
extern D2AnimUnkStrc gaMonModesAnimModulatorsExpansion[];                                                   // 0x006E8CD0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define TRUE 1
#define FALSE 0
#define MONSTER_FIRST_EXPANSION 410
#define SKILLSFLAGINDEX_USEATTACKRATE 3

// 0x00620290
D2UnitStrc* __stdcall UNITS_AllocUnit(void* pMemPool, int nUnitType)
{
    D2UnitStrc* pUnit = (D2UnitStrc*)sub_0040B430(pMemPool, 0xF4, ".\\UNITS\\Units.cpp", 1646, 0);
    memset(pUnit, 0, 0xF4);

    pUnit->dwUnitType = nUnitType;
    pUnit->pMemoryPool = pMemPool;

    switch (nUnitType)
    {
    case UNIT_MONSTER:
        pUnit->pMonsterData = (D2MonsterDataStrc*)sub_0040B430(pMemPool, 0x60, ".\\UNITS\\Units.cpp", 1659, 0);
        memset(pUnit->pMonsterData, 0, 0x60);
        break;
    }

    return pUnit;
}

// 0x00621580
int __fastcall UNITS_CanAnimModeUseAttackRate(int nAnimMode, int nUnitType, D2UnitStrc* pUnit, int nClassId)
{
    D2AnimUnkStrc* pAnimModeModulators = 0;
    switch (nUnitType)
    {
    case UNIT_PLAYER:
        pAnimModeModulators = &gaPlayerModesAnimModulators[nAnimMode];
        break;

    case UNIT_MONSTER:
        if (nClassId < MONSTER_FIRST_EXPANSION)
            pAnimModeModulators = &gaMonModesAnimModulators[nAnimMode];
        else
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion[nAnimMode];
        break;

    default:
        D2_ASSERT((nUnitType == UNIT_PLAYER) || (nUnitType == UNIT_MONSTER), 3055);
        return FALSE;
    }

    if (pAnimModeModulators->bCanUseAttackRate)
        return TRUE;

    if (!pAnimModeModulators->bCanUseSkillAttackRate)
        return FALSE;

    D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
    if (!pUsedSkill)
        return FALSE;

    return sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\UNITS\\Units.cpp", 3066))->dwFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_USEATTACKRATE];
}
