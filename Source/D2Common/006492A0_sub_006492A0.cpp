// 0x006492A0
extern "C" __declspec(dllexport) int __stdcall sub_006492A0(int nX1, int nY1, int nX2, int nY2) {
    int nDX = nX2 - nX1;
    int nDY = nY2 - nY1;
    return nDX * nDX + nDY * nDY;
}
