#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
struct Unicode;
struct D2HotkeySlotTableStrc;
struct D2SkillsTxt;
struct D2SkillIconStateStrc;
struct D2UiCelFileStrc;
struct D2WeatherLayerStateStrc;
struct D2MonsterDataStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
void __cdecl sub_0044DA40(); // 0x0044DA40
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0
extern int gnGlobal_00711470; // 0x00711470
extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300; // 0x007C0300
extern int gbGlobal_007C07FC; // 0x007C07FC
extern int gnHotkeySkill_007C06C8[16]; // 0x007C06C8
extern int gnHotkeyOwner_007C0768[16]; // 0x007C0768
extern int gbHotkeyLeft_007C07B8[16]; // 0x007C07B8
int __cdecl sub_00463DF0(); // 0x00463DF0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2SkillIconStateStrc gtSkillIconState_007C0300; // 0x007C0300
void __fastcall sub_004AA3A0_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw); // 0x004AA3A0

#pragma pack(push, 1)
struct D2UiCelFileStrc
{
    void* pCelFile;
    char szPath[0x1E];
};

struct D2NpcEntryStrc
{
    int nId;
    char unk0x04[0x12];
};

#pragma pack(pop)
struct D2WeatherLayerStateStrc
{
    void* apCelFiles[4];
};

void __fastcall sub_00478A00(void* pCel); // 0x00478A00
void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry); // 0x004B1680
extern unsigned char gbGlobal_007A0522; // 0x007A0522
extern D2UiCelFileStrc gaPanelCels_00724BF0[7]; // 0x00724BF0
extern D2WeatherLayerStateStrc gtWeatherLayer_007A89B0; // 0x007A89B0
extern D2WeatherLayerStateStrc gtWeatherLayer_007A893C; // 0x007A893C
extern D2NpcEntryStrc gaNpcEntries_00726850[]; // 0x00726850
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern int gnAutomapWidth_007A5220; // 0x007A5220
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit); // 0x00451F60
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId); // 0x00646140


// 0x004A9BD0
void __stdcall sub_004A9BD0_SkillSelectClickHandler(SMSGHANDLER_PARAMS* pMsg)
{
    D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 954);

    const int nStartY = sub_00468740();
    int bHandled = 0;
    for (int i = 0; i < 60; ++i)
    {
        const int nY = gtHotkeySlots_007C0300.nY[i];
        const int nX = gtHotkeySlots_007C0300.nX[i];
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(sub_00463DD0_GetPlayerUnit(), gtHotkeySlots_007C0300.nSkill[i], gtHotkeySlots_007C0300.f_2D0[i]);
            if (pSkill)
            {
                int nCharges;
                if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1 && SKILLS_GetSkillInfo(pSkill, 0, 0, 0, &nCharges) && nCharges <= 0)
                {
                    if (sub_004538D0(3))
                    {
                        sub_00455F20(3, 1, 0);
                    }

                    pMsg->bUseResult = 1;
                    pMsg->lResult = 0;
                    sub_00420290_BreakHandlerChain(pMsg);
                    return;
                }

                sub_004786A0_SendDwords2(0x3C, (gbGlobal_007C07FC ? 0x80000000 : 0) + gtHotkeySlots_007C0300.nSkill[i], gtHotkeySlots_007C0300.f_2D0[i]);
                sub_00455F20(3, 1, 0);
                gbGlobal_007C07FC = 0;
                bHandled = 1;
                sub_0044DA40();
            }
        }
    }

    if (nStartY <= gnGlobal_00711470 - 49 && !bHandled && sub_004538D0(3))
    {
        sub_00455F20(3, 1, 0);
    }

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

int gnSelectedHotkey_007C0708; // 0x007C0708

// 0x004A9FC0
static int sub_004A9FC0_IsHotkeyUsable(int nSlot)
{
    if (gnHotkeySkill_007C06C8[nSlot] == -1)
        return 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
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
    if (gnHotkeySkill_007C06C8[nSlot] == -1)
        return;
    if (!sub_004A9FC0_IsHotkeyUsable(nSlot))
        return;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    gnSelectedHotkey_007C0708 = nSlot;
    sub_004786A0_SendDwords2(0x3C, (gbHotkeyLeft_007C07B8[nSlot] ? 0x80000000 : 0) + gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
    if (gbHotkeyLeft_007C07B8[nSlot])
        SKILLS_SetLeftActiveSkill(pPlayer, gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
    else
        SKILLS_SetRightActiveSkill(pPlayer, gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
}

// 0x004AA740
void __fastcall sub_004AA740_CycleHotkey(int nDelta)
{
    if (sub_00463DF0())
        return;
    const int nStep = (nDelta > 0) * 2 - 1;
    if (nDelta < 0)
        nDelta = -nDelta;
    if (!nDelta)
        return;
    int nFound = -1;
    int nSlot = gnSelectedHotkey_007C0708 + nStep;
    for (int i = 0; i < 16; ++i, nSlot += nStep)
    {
        if (nSlot < 0)
            nSlot = 15;
        else if (nSlot >= 16)
            nSlot = 0;
        if (gnHotkeySkill_007C06C8[nSlot] != -1 && !gbHotkeyLeft_007C07B8[nSlot] && sub_004A9FC0_IsHotkeyUsable(nSlot))
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
    if (gnHotkeySkill_007C06C8[nSlot] != -1)
        return;

    gnHotkeySkill_007C06C8[nSlot] = gtHotkeySlots_007C0300.nSkill[nIndex];
    if (!gbGlobal_007C07FC)
        gbHotkeyLeft_007C07B8[nSlot] = 0;
    else
        gbHotkeyLeft_007C07B8[nSlot] = 1;
    gnHotkeyOwner_007C0768[nSlot] = gtHotkeySlots_007C0300.f_2D0[nIndex];
    sub_004786A0_SendDwords2(0x51, (nSlot << 16) + (gbHotkeyLeft_007C07B8[nSlot] ? 0x8000 : 0) + gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
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
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
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
    if (gbGlobal_007C07FC)
    {
        gtSkillIconState_007C0300.bFlag = 0;
        sub_004AA3A0_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 0, 0);
    }
}

unsigned char gbGlobal_007C0C6A; // 0x007C0C6A

// 0x004AA980
void __cdecl sub_004AA980()
{
    if (gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile)
    {
        sub_00478A00(gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile);
        gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile = 0;
    }
}

// 0x00472BD0
void __cdecl sub_00472BD0()
{
    for (int i = 0; i < 4; ++i)
    {
        if (gtWeatherLayer_007A89B0.apCelFiles[i])
        {
            sub_00478A00(gtWeatherLayer_007A89B0.apCelFiles[i]);
            gtWeatherLayer_007A89B0.apCelFiles[i] = 0;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (gtWeatherLayer_007A893C.apCelFiles[i])
        {
            sub_00478A00(gtWeatherLayer_007A893C.apCelFiles[i]);
            gtWeatherLayer_007A893C.apCelFiles[i] = 0;
        }
    }
}

// 0x004B17A0
void __cdecl sub_004B17A0()
{
    for (int i = 0; i < gnNpcEntryCount_0072554C; ++i)
        sub_004B1680(&gaNpcEntries_00726850[i]);
    gbGlobal_007C0C6A = 1;
}

// 0x004B1D70
int __cdecl sub_004B1D70_FindNpcEntry()
{
    int i = 0;
    int bFound = 0;
    while (i < gnNpcEntryCount_0072554C && !bFound)
    {
        if (gaNpcEntries_00726850[i].nId == gdwGlobal_007C0D2D)
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
static __declspec(noinline) void __stdcall sub_004AAAA0_DrawSkillTreeText(int nY, const Unicode* wszText)
{
    const int nRight = gnAutomapWidth_007A5220 - gnGlobal_007A2858;
    sub_004A7080(nRight - 0x5A, gnGlobal_00711470 + gnGlobal_007A285C + nY - 0x1E0, nRight, wszText, 0);
}

void __fastcall sub_M26_Emit_004AB090(char nMode)
{
    if (nMode == 2)
    {
        sub_004AAAA0_DrawSkillTreeText(0x9C, D2LANG_GetStringFromTblIndex(0x1092));
        sub_004AAAA0_DrawSkillTreeText(0xA8, D2LANG_GetStringFromTblIndex(0x1087));
    }
}

int ganSkillState_007C0A38[128]; // 0x007C0A38

unsigned long gdwLastTick_007C0C54; // 0x007C0C54

// 0x004AB7B0
int __cdecl sub_004AB7B0_CheckTickElapsed()
{
    unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastTick_007C0C54 > 1000)
    {
        gdwLastTick_007C0C54 = dwTick;
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
        for (int i = 0; i < SKILLS_GetPlayerSkillCount(sub_00451F60_UnitClassId(pPlayer)); ++i)
        {
            if (ganSkillState_007C0A38[i] == 1)
            {
                ganSkillState_007C0A38[i] = 0;
            }
        }
    }
}

// 0x004AC730
D2MonsterDataStrc* __fastcall sub_004AC730_MonsterDataOf(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
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
