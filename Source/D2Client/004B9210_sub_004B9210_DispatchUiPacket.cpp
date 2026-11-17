#pragma pack(push, 1)
struct D2UiPacketStrc_004B9210
{
    unsigned char nHeader;
    unsigned short nType;
    unsigned short nArg;
};
#pragma pack(pop)

void __fastcall sub_004A28A0_OnUiPacket1(D2UiPacketStrc_004B9210* pPacket);                                // 0x004A28A0
void __fastcall sub_004B3340_OnUiPacket2(unsigned short nArg);                                              // 0x004B3340
void __fastcall sub_004B25C0_OnUiPacket3(D2UiPacketStrc_004B9210* pPacket);                                // 0x004B25C0
void __fastcall sub_0049FF60_OnUiPacket4(D2UiPacketStrc_004B9210* pPacket);                                // 0x0049FF60
void __fastcall sub_004A3100_OnUiPacket36(int nArg);                                                        // 0x004A3100
void __cdecl sub_00477EE0();                                                                                // 0x00477EE0
void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
void __fastcall sub_0044C860_SetValue(int nValue);                                                          // 0x0044C860
void __cdecl sub_0044D520();                                                                                // 0x0044D520
void __cdecl sub_004BAA50_RefreshHintRange();                                                               // 0x004BAA50
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00

int gbHintsOff_007C5468;                                                                                    // 0x007C5468
void* gpCelFile_007C546C;                                                                                   // 0x007C546C

// 0x004B9210
void __fastcall sub_004B9210_DispatchUiPacket(D2UiPacketStrc_004B9210* pPacket)
{
    switch (pPacket->nType)
    {
    case 36:
        sub_004A3100_OnUiPacket36(pPacket->nArg);
        return;

    case 2:
        sub_004B3340_OnUiPacket2(pPacket->nArg);
        return;

    case 1:
        sub_004A28A0_OnUiPacket1(pPacket);
        return;

    case 3:
    case 6:
        sub_004B25C0_OnUiPacket3(pPacket);
        return;

    case 4:
    case 13:
        sub_0049FF60_OnUiPacket4(pPacket);
        return;

    case 23:
        sub_00477EE0();
        sub_0044B880_SetValue(0);
        sub_0044C860_SetValue(1);
        sub_0044D520();
        return;
    }
}

// 0x004BABC0
void __cdecl sub_004BABC0_ToggleHints()
{
    gbHintsOff_007C5468 = !gbHintsOff_007C5468;
    if (!gbHintsOff_007C5468)
    {
        sub_004BAA50_RefreshHintRange();
    }
}

// 0x004BE060
void __cdecl sub_004BE060()
{
    if (gpCelFile_007C546C)
    {
        sub_00478A00(gpCelFile_007C546C);
        gpCelFile_007C546C = 0;
    }
}
