#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2ClientMenus.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2HotkeySlotTableStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
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

// 0x004A9BD0
void __stdcall SPELLSEL_SkillSelectClickMsg(SMSGHANDLER_PARAMS* pMsg)
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
                    if (GAME_GetUIVarState(3))
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
                GAME_ResetMouseState();
            }
        }
    }

    if (nStartY <= gnGlobal_00711470 - 49 && !bHandled && GAME_GetUIVarState(3))
    {
        sub_00455F20(3, 1, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

