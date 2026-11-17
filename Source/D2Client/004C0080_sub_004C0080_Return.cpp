void __cdecl sub_00477EE0();                                                                                // 0x00477EE0
void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
void __fastcall sub_0044C860_SetValue(int nValue);                                                          // 0x0044C860
void __cdecl sub_0044D520();                                                                                // 0x0044D520

// 0x004C0080
void __cdecl sub_004C0080_Return()
{
}

// 0x004C0D00
void __cdecl sub_004C0D00_Reset()
{
    sub_00477EE0();
    sub_0044B880_SetValue(0);
    sub_0044C860_SetValue(1);
    sub_0044D520();
}
