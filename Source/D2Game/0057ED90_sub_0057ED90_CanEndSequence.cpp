extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2SkillStrc;

struct D2InventoryStrc;

struct D2PlayerDataStrc
{
    char unk0x000[0x150];
    int unk0x150;
    int unk0x154;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    D2PlayerDataStrc* pPlayerData;
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[2];
    unsigned char nFlags[8];
    char unk0x0C[0x0A];
    unsigned char nSeqInput;
    char unk0x17[0x225];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

typedef void (__fastcall* PLRMODESTARTXY)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY);
typedef void (__fastcall* PLRMODESTARTID)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget);

struct D2PlayerModeChartStrc
{
    PLRMODESTARTXY pfnStartXY;
    PLRMODESTARTID pfnStartID;
};

extern D2PlayerModeChartStrc gsPlayerModeChart_006E1740[];                                                       // 0x006E1740
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent);                       // 0x005415A0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __fastcall sub_0057ED70_IsEndAnimDue(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x0057ED70
int __fastcall sub_0057EEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int a4, D2SkillStrc* pSkill); // 0x0057EEC0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
void __cdecl sub_006248E0_Log(int nA, int nB, int nC, int nFlags, const char* szFile, int nLine, const char* szFormat, ...); // 0x006248E0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00580310
void __fastcall sub_6FC80E10(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00580380
void __fastcall PLRMODE_StartXY_Dead(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY);      // 0x0057FCA0
void __fastcall PLRMODE_StartXY_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY); // 0x0057F020

static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0057ED90
static int sub_0057ED90_CanEndSequence(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (pSkillsTxtRecord && pSkillsTxtRecord->nSeqInput > 0)
        {
            return 1;
        }
    }

    return pGame->dwGameFrame <= EVENT_GetEventFrame(pGame, pUnit, 1) + 0x05;
}

// 0x0057EDD0
static int sub_6FC81890(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode)
{
    if (pUnit->pInventory && INVENTORY_GetCursorItem(pUnit->pInventory) && nMode != 0 && nMode != 17)
    {
        return 0;
    }

    switch (nMode)
    {
    case 0:
    case 1:
    case 5:
    case 17:
        return 1;

    default:
        break;
    }

    switch (pUnit->dwAnimMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
        if (sub_0057ED70_IsEndAnimDue(pGame, pUnit) || nMode == 4 || nMode == 9)
        {
            return 1;
        }
        return 0;

    case 0:
    case 4:
    case 9:
    case 17:
        return 0;

    case 12:
        return sub_0057ED70_IsEndAnimDue(pGame, pUnit) ? 1 : 0;

    case 13:
        if (pUnit->dwClassId == 0)
        {
            return 0;
        }
        break;

    case 15:
        if (pUnit->dwClassId == 5)
        {
            return 0;
        }
        break;

    case 18:
        return sub_0057ED90_CanEndSequence(pGame, pUnit);

    default:
        break;
    }

    return 1;
}

// 0x005809D0
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7)
{
    D2_ASSERT(pGame, 0x805);

    if (sub_6FC81890(pGame, pUnit, nMode) && (a7 || sub_0057EEC0(pGame, pUnit, nMode, 1, pUsedSkill)))
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gsPlayerModeChart_006E1740[nMode].pfnStartXY), 0x812);

        if (pUsedSkill)
        {
            UNITS_SetUsedSkill(pUnit, pUsedSkill);
        }

        gsPlayerModeChart_006E1740[nMode].pfnStartXY(pGame, pUnit, nMode, nX, nY);
    }
}

// 0x00580A70
void __fastcall D2GAME_PLAYERMODE_Change_6FC81A00(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter)
{
    D2_ASSERT(pGame, 0x835);

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nTargetGUID);
    if (!pTarget)
    {
        sub_006248E0_Log(1, 2, 4, 4, ".\\PLAYER\\PlrModes.cpp", 0x83A, "StartModeID: Bad Target");
        return;
    }

    if (sub_6FC81890(pGame, pPlayer, nMode) && (bAllowReEnter || sub_0057EEC0(pGame, pPlayer, nMode, 1, pSkill)))
    {
        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->unk0x154 = 0;
        }

        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->unk0x150 = 0;
        }

        D2_ASSERT(!IsBadCodePtr((FARPROC)gsPlayerModeChart_006E1740[nMode].pfnStartID), 0x853);

        if (pSkill)
        {
            UNITS_SetUsedSkill(pPlayer, pSkill);
        }

        gsPlayerModeChart_006E1740[nMode].pfnStartID(pGame, pPlayer, nMode, pTarget);
    }
}

// 0x00581020
void __fastcall sub_6FC81250(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    const int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;
    switch (nAnimMode)
    {
    case 7:
    case 8:
    case 11:
        sub_6FC80A30(pGame, pUnit);
        sub_6FC80E10(pGame, pUnit);
        break;

    default:
        D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
        if (!pUsedSkill)
        {
            goto done;
        }

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\PLAYER\\PlrModes.cpp", 0x779));
        if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[0x12 >> 3] & gdwBitMasks[0x12 & 7]))
        {
            goto done;
        }

        sub_6FC80A30(pGame, pUnit);
        sub_6FC80E10(pGame, pUnit);
        break;
    }

done:
    switch (nAnimMode)
    {
    case 0:
        PLRMODE_StartXY_Dead(pGame, pUnit, 17, 0, 0);
        return;

    case 19:
        break;

    default:
        PLRMODE_StartXY_Neutral(pGame, pUnit, 1, 0, 0);
        return;
    }

    D2_ASSERT(pGame, 0x805);

    if (pUnit->pInventory && INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return;
    }

    switch (pUnit->dwAnimMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
        sub_0057ED70_IsEndAnimDue(pGame, pUnit);
        break;

    case 0:
    case 4:
    case 9:
    case 17:
        return;

    case 12:
        if (sub_0057ED70_IsEndAnimDue(pGame, pUnit))
        {
            break;
        }
        return;

    case 13:
        if (pUnit->dwClassId == 0)
        {
            return;
        }
        break;

    case 15:
        if (pUnit->dwClassId == 5)
        {
            return;
        }
        break;

    case 18:
        if (!sub_0057ED90_CanEndSequence(pGame, pUnit))
        {
            return;
        }
        break;

    default:
        break;
    }

    if (!sub_0057EEC0(pGame, pUnit, 4, 1, 0))
    {
        return;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)gsPlayerModeChart_006E1740[4].pfnStartXY), 0x812);

    gsPlayerModeChart_006E1740[4].pfnStartXY(pGame, pUnit, 4, -1, 0);
}

#include "gen/data/Source/D2Game/0057ED90_sub_0057ED90_CanEndSequence.inc"
