int __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                         // 0x00455F20
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600

// 0x00489A10
void __cdecl sub_00489A10_OpenUIVar25()
{
    sub_00455F20(0x19, 1, 0);
    sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
}
