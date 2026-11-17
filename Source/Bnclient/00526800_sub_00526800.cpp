// 0x00526800
extern "C" __declspec(dllexport) int __fastcall sub_00526800(const unsigned short* pText) {
    int nLength = 0;
    if (!pText) {
        return 0;
    }
    while (*pText) {
        pText++;
        nLength++;
    }
    return nLength;
}
