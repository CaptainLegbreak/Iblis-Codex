struct Obj004DCF10 {
    unsigned char bUnknown00[0x38];
    unsigned int dwValue38;
    unsigned char bUnknown3C[0xEA9C - 0x3C];
    unsigned int dwValueEA9C;
    unsigned int dwUnknownEAA0;
    unsigned int dwUnknownEAA4;
    unsigned int dwValueEAA8;
    unsigned int dwUnknownEAAC;
    unsigned int dwValueEAB0;
};
// 0x004DCF10
extern "C" __declspec(dllexport) void __fastcall sub_004DCF10(Obj004DCF10* pObj) {
    pObj->dwValueEAB0 = 0;
    pObj->dwValueEA9C = 0;
    pObj->dwValue38 = 0;
    pObj->dwValueEAA8 = 0;
}
