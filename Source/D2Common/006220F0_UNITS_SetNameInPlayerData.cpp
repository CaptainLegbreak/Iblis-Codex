struct D2SkillStrc;

struct D2PlayerDataStrc
{
    char szName[16];
    char unk0x10[0x60];
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillFlags;
    int nLeftSkillFlags;
    int nSwitchRightSkillId;
    int nSwitchLeftSkillId;
    int nSwitchRightSkillFlags;
    int nSwitchLeftSkillFlags;
    int nWeaponGUID;
    int unk0x94;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2PlayerDataStrc* pPlayerData;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_INVALID 6

inline D2PlayerDataStrc* UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return pUnit->pPlayerData;
    }

    return 0;
}

// 0x006220F0
unsigned int __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* pUnit, char* szName)
{
    D2_ASSERT(pUnit, 0xF97);
    D2_ASSERT(pUnit->pPlayerData, 0xF99);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0xF9A);

    return SStrCopy(pUnit->pPlayerData->szName, szName, 0x7FFFFFFF);
}

// 0x00622EA0
void __stdcall UNITS_InitRightSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x13F6);

        D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
        pPlayerData->nRightSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x13FA);
        pPlayerData->nRightSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00622F10
void __stdcall UNITS_InitLeftSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1405);

        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        pPlayerData->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x1409);
        pPlayerData->nLeftSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00622F80
void __stdcall UNITS_InitSwitchRightSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1414);

        D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
        pPlayerData->nSwitchRightSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x1419);
        pPlayerData->nSwitchRightSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00622FF0
void __stdcall UNITS_InitSwitchLeftSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1424);

        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        pPlayerData->nSwitchLeftSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x1429);
        pPlayerData->nSwitchLeftSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00623060
void __stdcall UNITS_GetRightSkillData(D2UnitStrc* pUnit, int* pRightSkillId, int* pRightSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pRightSkillId = 0;
        *pRightSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1438);

        *pRightSkillId = pPlayerData->nRightSkillId;
        *pRightSkillFlags = pPlayerData->nRightSkillFlags;
    }
}

// 0x006230C0
void __stdcall UNITS_GetLeftSkillData(D2UnitStrc* pUnit, int* pLeftSkillId, int* pLeftSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pLeftSkillId = 0;
        *pLeftSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1449);

        *pLeftSkillId = pPlayerData->nLeftSkillId;
        *pLeftSkillFlags = pPlayerData->nLeftSkillFlags;
    }
}

// 0x00623120
void __stdcall UNITS_GetSwitchRightSkillDataResetRightSkill(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchRightSkillId = 0;
        *pSwitchRightSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x145A);

        *pSwitchRightSkillId = pPlayerData->nSwitchRightSkillId;
        *pSwitchRightSkillFlags = pPlayerData->nSwitchRightSkillFlags;

        pPlayerData->nRightSkillId = 0;
        pPlayerData->nRightSkillFlags = -1;
        pPlayerData->nWeaponGUID = -1;
        pPlayerData->unk0x94 = 0;
    }
}

// 0x006231A0
void __stdcall UNITS_GetSwitchLeftSkillDataResetLeftSkill(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchLeftSkillId = 0;
        *pSwitchLeftSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1470);

        *pSwitchLeftSkillId = pPlayerData->nSwitchLeftSkillId;
        *pSwitchLeftSkillFlags = pPlayerData->nSwitchLeftSkillFlags;

        pPlayerData->nLeftSkillId = 0;
        pPlayerData->nLeftSkillFlags = -1;
        pPlayerData->nWeaponGUID = -1;
        pPlayerData->unk0x94 = 0;
    }
}

// 0x00623220
void __stdcall UNITS_GetSwitchLeftSkillData(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchLeftSkillId = 0;
        *pSwitchLeftSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1487);

        *pSwitchLeftSkillId = pPlayerData->nSwitchLeftSkillId;
        *pSwitchLeftSkillFlags = pPlayerData->nSwitchLeftSkillFlags;
    }
}

// 0x00623290
void __stdcall UNITS_GetSwitchRightSkillData(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchRightSkillId = 0;
        *pSwitchRightSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1499);

        *pSwitchRightSkillId = pPlayerData->nSwitchRightSkillId;
        *pSwitchRightSkillFlags = pPlayerData->nSwitchRightSkillFlags;
    }
}
