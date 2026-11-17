int __stdcall sub_006C6CB0(int a1, int a2, int a3, int a4, int a5, int a6, int a7); // 0x006C6CB0

// 0x006C7000
int __stdcall sub_006C7000_Wrapper(int a1, int a2, int a3, int a4, int a5, int a6)
{
    return sub_006C6CB0(a1, a2, a3, a4, a5, a6, 0);
}
