// 0x005A0260
extern "C" __declspec(dllexport) int __fastcall sub_005A0260(const char* pText) {
    int nLength;
    for (nLength = 0; nLength < 9; nLength++, pText++) {
        if (!*pText) {
            return nLength;
        }
    }
    return 9;
}
