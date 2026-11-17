int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740

// 0x0044D320
static __declspec(noinline) int __stdcall sub_0044D320_IsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX < nX || nMouseX > nX + nWidth || nMouseY < nY - nHeight || nMouseY > nY)
    {
        return 0;
    }
    return 1;
}

int __stdcall sub_K02_EmitIsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    return sub_0044D320_IsMouseInRect(nX, nY, nWidth, nHeight);
}
