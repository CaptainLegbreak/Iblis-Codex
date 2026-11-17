struct SMSGHANDLER_PARAMS { char unknown0[12]; unsigned short x, y; char unknown10[8]; int handled, result; };
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __fastcall sub_004538D0(unsigned int); // 0x004538D0
int __cdecl sub_0045AE90(); // 0x0045AE90
int __fastcall sub_004A6630_IsInPanelButton(int, int, int); // 0x004A6630
int __cdecl sub_004A6690_IsMouseOnRightButton(); // 0x004A6690
struct D2UnitStrc;
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS*); // 0x00467F20
int __cdecl sub_004B3470_IsNpcQuestActive(); // 0x004B3470
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS*); // 0x00420290
extern int gnPressed_007C02E8; // 0x007C02E8
static __forceinline void MarkRightButtonPressed()
{
    gnPressed_007C02E8 = 1;
    const int nClickSound = 4;
    sub_004B9A00(nClickSound, 0, 0, 0, 0);
}

// 0x004A6790
void __stdcall sub_004A6790_HandleRightButton(SMSGHANDLER_PARAMS* message)
{
    int x = message->x;
    int y = message->y;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && sub_004538D0(nResolution + 7))
        return;
    int border = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (sub_004A6630_IsInPanelButton(border, x, y))
        {
            MarkRightButtonPressed();
            sub_00467F20_MsgHandler(message);
            if (border == 1 && sub_004B3470_IsNpcQuestActive()) return;
            message->handled = 1;
            message->result = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (sub_004A6690_IsMouseOnRightButton())
        {
            MarkRightButtonPressed();
            sub_00467F20_MsgHandler(message);
            if (border == 1 && sub_004B3470_IsNpcQuestActive()) return;
            message->handled = 1;
            message->result = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    message->handled = 0;
}
