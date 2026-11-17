int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __stdcall sub_K05_EmitUse(int nValue);

// 0x004A8CF0
static __declspec(noinline) int __stdcall sub_004A8CF0_IsMouseInRect(int nX, int nWidth, int nY, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + nWidth && nMouseY >= nY - nHeight && nMouseY <= nY)
        return 1;
    return 0;
}

void __fastcall sub_K05_EmitMouseInRect(int nX, int nY)
{
    sub_K05_EmitUse(sub_004A8CF0_IsMouseInRect(nX, 0x30, nY, 0x30));
    sub_K05_EmitUse(sub_004A8CF0_IsMouseInRect(nX + 0x30, 0x30, nY, 0x30));
}
