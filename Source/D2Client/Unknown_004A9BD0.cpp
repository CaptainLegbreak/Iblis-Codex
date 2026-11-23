#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2ClientMenus.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
struct Unicode;
struct D2HotkeySlotTableStrc;
struct D2SkillsTxt;
struct D2SkillIconStateStrc;
struct D2UiCelFileStrc;
struct D2WeatherLayerStateStrc;
struct D2MonsterDataStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0
extern int gnScreenHeight; // 0x00711470
extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300; // 0x007C0300
extern int gbSkillSelectRight; // 0x007C07FC
extern int gaHotkeySkills[16]; // 0x007C06C8
extern int gaHotkeyOwners[16]; // 0x007C0768
extern int gaHotkeyLeft[16]; // 0x007C07B8
int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140
extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2SkillIconStateStrc gtHotkeySlots; // 0x007C0300
void __fastcall SPELLSEL_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw); // 0x004AA3A0

#pragma pack(push, 1)
struct D2UiCelFileStrc
{
    void* pCelFile;
    char szPath[0x1E];
};

#pragma pack(pop)
struct D2WeatherLayerStateStrc
{
    void* apCelFiles[4];
};

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00
void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry); // 0x004B1680
extern unsigned char gnCharClass; // 0x007A0522
extern D2UiCelFileStrc gaPanelCels[7]; // 0x00724BF0
extern D2WeatherLayerStateStrc gtSplashCels; // 0x007A89B0
extern D2WeatherLayerStateStrc gtBubbleCels; // 0x007A893C
extern D2NpcEntryStrc gaNpcEntries[]; // 0x00726850
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern int gnAutomapWidth; // 0x007A5220
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId); // 0x00646140

int gnSelectedHotkey; // 0x007C0708

// 0x004A9FC0
static int sub_004A9FC0_IsHotkeyUsable(int nSlot)
{
    if (gaHotkeySkills[nSlot] == -1)
        return 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
    if (!pSkill)
        return 0;
    if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1)
    {
        int nCharges;
        if (SKILLS_GetSkillInfo(pSkill, 0, 0, 0, &nCharges) && nCharges <= 0)
            return 0;
    }
    return 1;
}

// 0x004AA030
void __fastcall sub_004AA030_SelectHotkey(int nSlot)
{
    if (gaHotkeySkills[nSlot] == -1)
        return;
    if (!sub_004A9FC0_IsHotkeyUsable(nSlot))
        return;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    gnSelectedHotkey = nSlot;
    MSG_SendTwoDwords(0x3C, (gaHotkeyLeft[nSlot] ? 0x80000000 : 0) + gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
    if (gaHotkeyLeft[nSlot])
        SKILLS_SetLeftActiveSkill(pPlayer, gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
    else
        SKILLS_SetRightActiveSkill(pPlayer, gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
}

// 0x004AA740
void __fastcall sub_004AA740_CycleHotkey(int nDelta)
{
    if (CUNIT_IsPlayerDeadOrMissing())
        return;
    const int nStep = (nDelta > 0) * 2 - 1;
    if (nDelta < 0)
        nDelta = -nDelta;
    if (!nDelta)
        return;
    int nFound = -1;
    int nSlot = gnSelectedHotkey + nStep;
    for (int i = 0; i < 16; ++i, nSlot += nStep)
    {
        if (nSlot < 0)
            nSlot = 15;
        else if (nSlot >= 16)
            nSlot = 0;
        if (gaHotkeySkills[nSlot] != -1 && !gaHotkeyLeft[nSlot] && sub_004A9FC0_IsHotkeyUsable(nSlot))
        {
            nFound = nSlot;
            if (!--nDelta)
                break;
        }
    }
    if (nFound != -1)
        sub_004AA030_SelectHotkey(nFound);
}

// 0x004AA0F0
static void sub_004AA0F0_AssignFreeHotkey(int nSlot, int nIndex)
{
    if (nSlot >= 16)
        return;
    if (gaHotkeySkills[nSlot] != -1)
        return;

    gaHotkeySkills[nSlot] = gtHotkeySlots_007C0300.nSkill[nIndex];
    if (!gbSkillSelectRight)
        gaHotkeyLeft[nSlot] = 0;
    else
        gaHotkeyLeft[nSlot] = 1;
    gaHotkeyOwners[nSlot] = gtHotkeySlots_007C0300.f_2D0[nIndex];
    MSG_SendTwoDwords(0x51, (nSlot << 16) + (gaHotkeyLeft[nSlot] ? 0x8000 : 0) + gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
}

// 0x004AA160
void __cdecl sub_004AA160_FillHotkeys()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(UNITS_GetStartSkill(pPlayer), 0x524);
    int nSlot = 0;
    for (int i = 0; i < 60; ++i)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, gtHotkeySlots_007C0300.nSkill[i]);
        if (!pSkill)
            continue;
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (!pSkillsTxt)
            continue;
        if (BITARRAY_CHECK(pSkillsTxt->nFlags, 4))
            continue;
        if (nSlot > 15)
            continue;
        sub_004AA0F0_AssignFreeHotkey(nSlot, i);
        ++nSlot;
    }
}

// 0x004AA680
void __cdecl sub_004AA680_BuildRightRows()
{
    if (gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 0, 0);
    }
}

unsigned char gbNpcEntriesProcessed; // 0x007C0C6A

// 0x004AA980
void __cdecl sub_004AA980()
{
    if (gaPanelCels[gnCharClass].pCelFile)
    {
        ARCHIVE_FreeClientCellFile(gaPanelCels[gnCharClass].pCelFile);
        gaPanelCels[gnCharClass].pCelFile = 0;
    }
}

// 0x00472BD0
void __cdecl sub_00472BD0()
{
    for (int i = 0; i < 4; ++i)
    {
        if (gtSplashCels.apCelFiles[i])
        {
            ARCHIVE_FreeClientCellFile(gtSplashCels.apCelFiles[i]);
            gtSplashCels.apCelFiles[i] = 0;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (gtBubbleCels.apCelFiles[i])
        {
            ARCHIVE_FreeClientCellFile(gtBubbleCels.apCelFiles[i]);
            gtBubbleCels.apCelFiles[i] = 0;
        }
    }
}

// 0x004B17A0
void __cdecl sub_004B17A0()
{
// build: symbol ?gnNpcEntryCount@* 0x0072554C
    for (int i = 0; i < gnNpcEntryCount; ++i)
        sub_004B1680(&gaNpcEntries[i]);
    gbNpcEntriesProcessed = 1;
}

// 0x004B1D70
int __cdecl sub_004B1D70_FindNpcEntry()
{
    int i = 0;
    int bFound = 0;
    while (i < gnNpcEntryCount && !bFound)
    {
// build: symbol ?gnInteractNpcClassId@* 0x007C0D2D
        if (gaNpcEntries[i].nId == gnInteractNpcClassId)
            bFound = 1;
        else
            ++i;
    }

    if (bFound == 1)
        return i;
    return 0;
}

#include "gen/data/Source/D2Client/Unknown_004A9BD0.inc"

// 0x004AAAA0
static void __stdcall sub_004AAAA0_DrawSkillTreeText(int nY, const Unicode* wszText)
{
    const int nRight = gnAutomapWidth - gnPanelOffsetX;
    TEXT_DrawCenteredText(nRight - 0x5A, gnScreenHeight + gnPanelOffsetY + nY - 0x1E0, nRight, wszText, 0);
}

void __fastcall sub_M26_Emit_004AB090(char nMode)
{
    if (nMode == 2)
    {
        sub_004AAAA0_DrawSkillTreeText(0x9C, D2LANG_GetStringFromTblIndex(0x1092));
        sub_004AAAA0_DrawSkillTreeText(0xA8, D2LANG_GetStringFromTblIndex(0x1087));
    }
}

int gaSkillButtonState[128]; // 0x007C0A38

unsigned long gdwSkillTreeClickTick; // 0x007C0C54

// 0x004AB7B0
int __cdecl sub_004AB7B0_CheckTickElapsed()
{
    unsigned long dwTick = GetTickCount();
    if (dwTick - gdwSkillTreeClickTick > 1000)
    {
        gdwSkillTreeClickTick = dwTick;
        return 1;
    }
    return 0;
}

// 0x004ABF10
void __cdecl sub_004ABF10_ClearSkillStates()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        for (int i = 0; i < SKILLS_GetPlayerSkillCount(GAME_GetUnitClassId(pPlayer)); ++i)
        {
            if (gaSkillButtonState[i] == 1)
            {
                gaSkillButtonState[i] = 0;
            }
        }
    }
}

// 0x004AC730
D2MonsterDataStrc* __fastcall sub_004AC730_MonsterDataOf(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return pUnit->pMonsterData;
    return 0;
}

// 0x004AC760
short __fastcall sub_004AC760_GetMonsterDataWord14(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_004AC730_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return pMonsterData->wNameSeed;
}
