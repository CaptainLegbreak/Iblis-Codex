int __cdecl sub_004B1D70_FindNpcEntry();                                                                    // 0x004B1D70
void __stdcall sub_004B5AD0_OpenConfirmDialog(int nStringIndex);                                            // 0x004B5AD0
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B

// 0x004B5C00
int __cdecl sub_004B5C00_OpenConfirm()
{
    gnGlobal_007C0C6B = 1;
    sub_004B1D70_FindNpcEntry();
    sub_004B5AD0_OpenConfirmDialog(0x2BA0);
    return 1;
}
