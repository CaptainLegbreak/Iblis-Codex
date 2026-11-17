typedef unsigned int U32;
typedef unsigned short U16;
typedef unsigned char U8;
struct UiControl;
extern "C" void __fastcall sub_00478600_SendPacket(U8 command, U16 value, U16 first, U16 second);
extern "C" int __fastcall sub_004FC9B0_AppendText(UiControl* control, const U16* text, int style, U8 metadata, int mode);
extern "C" int __fastcall sub_00455F20_SetUiState(int id, int state, int flag);
extern "C" int __cdecl sub_0044DCC0_Mode();
extern "C" int gPacketState; // 0x007C0E7C
extern "C" UiControl* gTextControl;
extern "C" int gPendingClear;
extern "C" int gCoordinateBase;
extern "C" int gCoordinateOffset;
extern "C" int gOpenFlag;
extern "C" int gUiPhase;
extern "C" U32 gRangeMode;
extern "C" int gRangeValue;

// 0x004B90B0
extern "C" void __cdecl sub_004B90B0_SendState()
{
    sub_00478600_SendPacket(0x4F, 7, 0, 0);
    gPacketState = 3;
}

extern "C" int __fastcall sub_0043E5F0_AppendText(const U16* text, int style)
{
    if (gTextControl)
        sub_004FC9B0_AppendText(gTextControl, text, style, 0, 1);
    return 1;
}

extern "C" int __fastcall sub_0043E610_AppendText(const U16* text, int style)
{
    if (gTextControl)
        sub_004FC9B0_AppendText(gTextControl, text, style, 0, 1);
    return 1;
}

extern "C" void __cdecl sub_00494FC0_ClearUi()
{
    if (gPendingClear != 0)
    {
        sub_00455F20_SetUiState(21, 1, 0);
        gPendingClear = 0;
    }
}

extern "C" void __cdecl sub_004898A0_OpenUi()
{
    gOpenFlag = 1;
    if (gUiPhase == 13)
        gUiPhase = 12;
    sub_00455F20_SetUiState(5, 1, 0);
}
