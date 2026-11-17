extern "C" int __cdecl abs(int);
#pragma intrinsic(abs)

// 0x00474080
int __fastcall sub_00474080_GetDistance(int nDX, int nDY)
{
    const int nAbsX = abs(nDX);
    const int nAbsY = abs(nDY);
    if (nAbsX >= nAbsY)
        return (unsigned int)(nAbsX * 0x3D7 + nAbsY * 0x197) >> 10;
    return (unsigned int)(nAbsY * 0x3D7 + nAbsX * 0x197) >> 10;
}
