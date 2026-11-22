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

extern int gnSelectedHotkey_007C0708;

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

                    pMsg->bReturn = 1;
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

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

