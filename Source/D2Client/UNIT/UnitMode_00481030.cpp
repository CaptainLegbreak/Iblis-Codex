#include "D2Structs.h"
struct D2SkillStrc;

struct D2PlayerDataStrc
{
    char unk0x00[0x150];
    int dwPendingFlag;
    int dwPendingAction;
    int dwPendingType;
    int dwPendingId;
};


struct D2SkillsTxt
{
    char unk0x00[0x2E];
    unsigned short wUnk0x2E;
    char unk0x30[0x20C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x4];
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern "C" const char szUnitModeFile_006D8E84[];                                                            // 0x006D8E84

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

unsigned short __cdecl sub_0044BEC0_GetClickFlags();                                                        // 0x0044BEC0
int __cdecl sub_0044DAA0();                                                                                 // 0x0044DAA0
void __fastcall sub_0044DAD0(int nValue);                                                                   // 0x0044DAD0
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30
void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit);                                        // 0x0045C470
int __fastcall sub_00461AC0_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance); // 0x00461AC0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
void __fastcall sub_00467A70(int nArg);                                                                     // 0x00467A70
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                                // 0x004786A0
int __fastcall sub_0047A4F0_TestFlag1(int nUnitId1, int nUnitId2);                                          // 0x0047A4F0
void __fastcall sub_00480B40_SendPacket(int nHeader, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);   // 0x00480B40
int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag);                // 0x00480C10
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall sub_00622B50_TestInteractCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask);       // 0x00622B50
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit);                                                    // 0x00622DC0
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);                        // 0x00623660
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140

static __forceinline D2SkillsTxt* UMODE_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline D2PlayerDataStrc* UMODE_GetPlayerData(D2UnitStrc* pUnit)
{
    return (pUnit && pUnit->dwUnitType == 0) ? pUnit->pPlayerData : 0;
}

static __forceinline int UMODE_GetPendingFlag(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->dwPendingFlag;
    }
    return 0;
}

static __forceinline int UMODE_GetPendingAction(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->dwPendingAction;
    }
    return 0;
}

static __forceinline int UMODE_GetPendingType(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->dwPendingType;
    }
    return 0;
}

static __forceinline int UMODE_GetPendingId(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->dwPendingId;
    }
    return 0;
}

static __forceinline void UMODE_SetPendingAction(D2UnitStrc* pUnit, int bFlag, int nAction, int nType, int nId)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->dwPendingFlag = bFlag;
        pUnit->pPlayerData->dwPendingAction = nAction;
        pUnit->pPlayerData->dwPendingType = nType;
        pUnit->pPlayerData->dwPendingId = nId;
    }
}

static __forceinline int UMODE_IsTargetable(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwFlags >> 1) & 1 : 0;
}

static __declspec(noinline) int sub_00480BA0_CanUseSkillNow(D2UnitStrc* pPlayer);
static int sub_00480BA0_CanUseSkillNow(D2UnitStrc* pPlayer); // 0x00480BA0

static int sub_00480BA0_CanUseSkillNow(D2UnitStrc* pPlayer)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (!pSkill)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxt = UMODE_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pSkill, szUnitModeFile_006D8E84, 0x2CC));
    if (!pSkillsTxt || BITARRAY_CHECK((unsigned char*)pSkillsTxt, 63))
    {
        return 1;
    }

    if (pPlayer)
    {
        const int nMode = pPlayer->dwAnimMode;
        if (nMode == 1 || nMode == 5)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00481030
void __fastcall sub_00481030_DoUnitAction(int nAction, D2UnitStrc* pPlayer, int nArg1, int nArg2, int nArg3)
{
    if (!sub_00480BA0_CanUseSkillNow(pPlayer))
    {
        return;
    }

    int args[7] = {};
    args[0] = nArg1;
    args[1] = nArg2;

    int nEvent;
    switch (nAction)
    {
    case 1:
        nEvent = 1;
        break;

    case 2:
        nEvent = 0;
        break;

    case 3:
        nEvent = 0x17;
        break;

    case 4:
        nEvent = 0x18;
        break;

    case 19:
        if (nArg1 == 4)
        {
            D2UnitStrc* pItem = sub_00463990(nArg2, nArg1);
            if (pItem && pItem->dwUnitType == 4 && !sub_00451F30_TestUnitFlag(pItem, 2))
            {
                return;
            }
        }
        nEvent = 2;
        break;

    case 5:
    case 8:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), szUnitModeFile_006D8E84, 0x32C);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetLeftSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x15;
        break;

    case 6:
    case 7:
    case 9:
    case 10:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), szUnitModeFile_006D8E84, 0x336);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetLeftSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x16;
        break;

    case 12:
    case 15:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), szUnitModeFile_006D8E84, 0x33E);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetRightSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x15;
        break;

    case 13:
    case 14:
    case 16:
    case 17:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), szUnitModeFile_006D8E84, 0x348);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetRightSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x16;
        break;

    default:
        D2_ASSERT(0, 0x352);
    }

    if (nEvent == 1 || nEvent == 0x17)
    {
        if (UMODE_GetPendingAction(pPlayer) == 19)
        {
            return;
        }
    }

    if (sub_00480C10_UnitEvent(nEvent, pPlayer, args, 0))
    {
        switch (nAction)
        {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            STATLIST_SetUnitStat(pPlayer, 0x148, STATLIST_GetUnitBaseStat(pPlayer, 0x148, 0) + 1, 0);
            break;
        }
        sub_00480B40_SendPacket(nAction, pPlayer, nArg1, nArg2, nArg3);
    }

    UMODE_SetPendingAction(pPlayer, 0, 0, 0, 0);
}
