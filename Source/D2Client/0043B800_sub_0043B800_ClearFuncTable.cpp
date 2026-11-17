struct D2FuncTable_0077ABF0Strc;

void __cdecl sub_00518C20();                                                                                // 0x00518C20
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0

// 0x0043B800
void __cdecl sub_0043B800_ClearFuncTable()
{
    gpFuncTable_0077ABF0 = 0;
    sub_00518C20();
}
