#pragma pack(push, 2)
struct D2PanelButtonStrc
{
    int bActive;
    int nValue;
    unsigned short nString;
    int nCel;
    unsigned short nFrame;
    int nType;
};
#pragma pack(pop)

extern D2PanelButtonStrc gaPanelButtons_007BC9E0[];                                                         // 0x007BC9E0

// 0x00487DA0
static __declspec(noinline) void sub_00487DA0_SetButtonD(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0x276F;
    gaPanelButtons_007BC9E0[nButton].nCel = 1;
    gaPanelButtons_007BC9E0[nButton].nType = 8;
    gaPanelButtons_007BC9E0[nButton].nFrame = 0x12;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

// 0x00487DE0
static __declspec(noinline) void sub_00487DE0_SetButtonC(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD0A;
    gaPanelButtons_007BC9E0[nButton].nCel = 4;
    gaPanelButtons_007BC9E0[nButton].nType = 1;
    gaPanelButtons_007BC9E0[nButton].nFrame = 6;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

void __cdecl sub_M214_Emit_00487ED0()
{
    sub_00487DE0_SetButtonC(2);
    sub_00487DA0_SetButtonD(3);
}
