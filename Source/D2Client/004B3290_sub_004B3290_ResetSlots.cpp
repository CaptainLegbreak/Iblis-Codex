struct D2ClientItemSlotStrc
{
    unsigned short wId;
    char unk0x02[0x06];
    int nUnitId;
    char unk0x0C[0x04];
};

#pragma pack(push, 1)
struct D2ClientValueBlockStrc
{
    char unk0x00[0x15];
    int anValues[20];
    D2ClientValueBlockStrc();
};
#pragma pack(pop)

extern D2ClientItemSlotStrc gaItemSlots_007C0C85[10];                                                       // 0x007C0C85
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25

void __cdecl sub_004939B0_LoadPopupHireling();                                                              // 0x004939B0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20

// 0x004B3290
void __cdecl sub_004B3290_ResetSlots()
{
    for (int i = 0; i < 10; ++i)
    {
        gaItemSlots_007C0C85[i].nUnitId = 0;
    }
}

// 0x004B3330
void __cdecl sub_004B3330_Empty()
{
}

// 0x004B3340
void __fastcall sub_004B3340_OnUiPacket2(unsigned short nArg)
{
    for (int i = 0; i < 10; ++i)
    {
        if (gaItemSlots_007C0C85[i].wId == nArg)
            break;
    }
    sub_004939B0_LoadPopupHireling();
}

// 0x004B3560
D2ClientValueBlockStrc::D2ClientValueBlockStrc()
{
    for (int i = 0; i < 20; ++i)
        anValues[i] = 0;
}

// 0x004B3FB0
void __cdecl sub_004B3FB0_CloseNpc2()
{
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
}
