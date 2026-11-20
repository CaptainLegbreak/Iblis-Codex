#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
struct D2SkillStrc;
struct D2TimerArgStrc;
struct D2PlayerDataStrc
{
    char szName[16];
    char unk0x10[28];
    int nPortalFlags;
    char unk0x30[64];
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
struct D2ObjectsTxt
{
    char unk0x00[360];
    unsigned int dwNameOffset;
};
struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    char unk0x04;
    unsigned char nPortalFlags;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __stdcall SStrCopy(char* szDest, const char* szSource, int nMax);                                      // 0x004135D0
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit);                                                      // 0x00622D00
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
#pragma intrinsic(memset)

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
#define STRCOPY_MAX 0x7FFFFFFF

// 0x00622150
char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4005);
    D2_ASSERT(pUnit->pPlayerData, 4007);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4008);

    return pUnit->pPlayerData->szName;
}

// 0x006221E0
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags)
{
    D2_ASSERT(pUnit, 4031);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4032);

    pUnit->pPlayerData->nPortalFlags = nPortalFlags;
}

// 0x00622230
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4041);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4042);

    return pUnit->pPlayerData->nPortalFlags;
}

// 0x00622270
unsigned int __stdcall UNITS_GetNameOffsetFromObject(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4051);

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        return pUnit->pObjectData->pObjectTxt->dwNameOffset;
    }

    return 0;
}

// 0x006222C0
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4068);
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 4069);
    return pUnit->pObjectData->nPortalFlags;
}

// 0x00622300
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag)
{
    D2_ASSERT(pUnit, 4079);
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 4080);
    pUnit->pObjectData->nPortalFlags = nPortalFlag;
}

// 0x00622350
int __stdcall UNITS_CheckObjectPortalFlag(D2UnitStrc* pUnit, unsigned char nFlag)
{
    D2_ASSERT(pUnit, 4090);
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 4091);

    return (nFlag & pUnit->pObjectData->nPortalFlags) != 0;
}

// 0x00622DC0
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit)
{
    return UNITS_IsInMovingMode(pUnit) != 0;
}

// 0x00622E90
void __stdcall UNITS_MergeDualWieldWeaponStatLists(D2UnitStrc* pUnit, int a2)
{
}

// 0x006234C0
void __fastcall UNITS_SetTimerArg(D2UnitStrc* pUnit, D2TimerArgStrc* pTimerArg)
{
    D2_ASSERT(pUnit, 5387);

    pUnit->pTimerArg = pTimerArg;
}

// 0x006234F0
D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 5395);

    return pUnit->pTimerArg;
}

// 0x00623520
void __stdcall UNITS_AllocStaticPath(D2UnitStrc* pUnit)
{
    if (!pUnit->pStaticPath)
    {
        pUnit->pStaticPath = (D2StaticPathStrc*)sub_0040B430(pUnit->pMemoryPool, sizeof(D2StaticPathStrc), ".\\UNITS\\Units.cpp", 5406, 0);
        memset(pUnit->pStaticPath, 0x00, sizeof(D2StaticPathStrc));
    }
}

// 0x00623570
void __stdcall UNITS_FreeStaticPath(D2UnitStrc* pUnit)
{
    if (pUnit->pStaticPath)
    {
        FOG_FreeServerMemory(pUnit->pMemoryPool, pUnit->pStaticPath, ".\\UNITS\\Units.cpp", 5419, 0);
    }
}
