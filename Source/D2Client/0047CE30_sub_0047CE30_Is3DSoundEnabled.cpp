struct D2MenuItemStrc;
struct SMSGHANDLER_PARAMS;

int __cdecl sub_004DF940();                                                                                 // 0x004DF940
int __cdecl sub_004DF960();                                                                                 // 0x004DF960
int __cdecl sub_004DF980_IsSoundMode1Or2();                                                                 // 0x004DF980
void __cdecl sub_004E00D0();                                                                                // 0x004E00D0
void __cdecl sub_004E0140();                                                                                // 0x004E0140

// 0x0047CE30
int __fastcall sub_0047CE30_Is3DSoundEnabled()
{
    return sub_004DF940();
}

// 0x0047CE40
void __fastcall sub_0047CE40_3DSoundSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004E00D0();
}

// 0x0047CE60
int __fastcall sub_0047CE60_Is3DBiasEnabled()
{
    return sub_004DF980_IsSoundMode1Or2();
}

// 0x0047CEB0
int __fastcall sub_0047CEB0_IsEAXEnabled()
{
    return sub_004DF960();
}

// 0x0047CEC0
void __fastcall sub_0047CEC0_EAXSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004E0140();
}
