struct D2UnitStrc;
struct D2SkillStrc;

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

struct D2HotkeySlotTableStrc
{
    int nX[60];
    int nY[60];
    int nSkill[60];
    int f_2D0[60];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                               // 0x004786A0
D2SkillStrc* __fastcall sub_006439B0_SkillFindByOwner(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);     // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
int __stdcall sub_00643B00(D2SkillStrc* pSkill, int a2, int a3, int a4, int* pCharges);          // 0x00643B00

extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300;                                                        // 0x007C0300
extern int gbGlobal_007C07FC;                                                                               // 0x007C07FC

// 0x004A9BD0
void __stdcall sub_004A9BD0_SkillSelectClickHandler(SMSGHANDLER_PARAMS* pMsg)
{
    D2_ASSERT(sub_00463DD0(), 954);

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
            D2SkillStrc* pSkill = sub_006439B0_SkillFindByOwner(sub_00463DD0(), gtHotkeySlots_007C0300.nSkill[i], gtHotkeySlots_007C0300.f_2D0[i]);
            if (pSkill)
            {
                int nCharges;
                if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1 && sub_00643B00(pSkill, 0, 0, 0, &nCharges) && nCharges <= 0)
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

                sub_004786A0_SendIntInt(0x3C, (gbGlobal_007C07FC ? 0x80000000 : 0) + gtHotkeySlots_007C0300.nSkill[i], gtHotkeySlots_007C0300.f_2D0[i]);
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
