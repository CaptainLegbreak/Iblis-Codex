int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __stdcall sub_K04_EmitUse(int nValue);

// 0x00494FF0
static int __stdcall sub_00494FF0_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

// build: context sub_K04_EmitIsMouseInBox
void __fastcall sub_K04_EmitIsMouseInBox(int nX, int nY)
{
    sub_K04_EmitUse(sub_00494FF0_IsMouseInBox(nX + 0x31, nY - 0x27, 0x23, 0x25));
}
