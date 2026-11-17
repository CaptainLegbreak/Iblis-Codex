struct SMSGHANDLER_PARAMS { char unknown0[12]; unsigned short x, y; char unknown10[8]; int handled, result; };
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __fastcall sub_004538D0(unsigned int); // 0x004538D0
int __cdecl sub_0045AE90(); // 0x0045AE90
int __fastcall sub_004A6580_IsInPanelButton(int, int, int); // 0x004A6580
int __cdecl sub_004A65E0_IsMouseOnLeftButton(); // 0x004A65E0
void __fastcall sub_004B9A00_ChangeUiState(int, int, int, int, int); // 0x004B9A00
void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS*); // 0x00467F20
int __cdecl sub_004B3470_IsNpcQuestActive(); // 0x004B3470
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS*); // 0x00420290
extern int gnPressed_007C02E4; // 0x007C02E4
// 0x004A66E0
void __stdcall sub_004A66E0_HandleLeftButton(SMSGHANDLER_PARAMS* message)
{
    int x = message->x;
    int y = message->y;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && sub_004538D0(nResolution + 7))
    {
        return;
    }
    int border = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (sub_004A6580_IsInPanelButton(border, x, y))
        {
            gnPressed_007C02E4 = 1;
            sub_004B9A00_ChangeUiState(4, 0, 0, 0, 0);
            sub_00467F20_MsgHandler(message);
            if (border == 2 && sub_004B3470_IsNpcQuestActive()) return;
            message->handled = 1;
            message->result = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (sub_004A65E0_IsMouseOnLeftButton())
        {
            gnPressed_007C02E4 = 1;
            sub_004B9A00_ChangeUiState(4, 0, 0, 0, 0);
            sub_00467F20_MsgHandler(message);
            if (border == 2 && sub_004B3470_IsNpcQuestActive()) return;
            message->handled = 1;
            message->result = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    message->handled = 0;
}
