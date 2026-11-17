char gbGlobal_007BF06C;                                                                                     // 0x007BF06C
extern int gnGlobal_007BF06D;                                                                               // 0x007BF06D

// 0x0049C470
static __forceinline bool sub_0049C470_IsPointInRect(int nX, int nY)
{
    if (nX >= 0x111 && nX <= 0x134 && nY >= 0x183 && nY <= 0x1A4)
        return true;
    return false;
}

int __stdcall sub_M113_Emit_0049C470(int nX, int nY)
{
    return sub_0049C470_IsPointInRect(nX, nY) ? 3 : 7;
}

// 0x0049C560
void __cdecl sub_0049C560_ResetSelection()
{
    gbGlobal_007BF06C = 0;
    gnGlobal_007BF06D = -1;
}
