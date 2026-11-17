struct Obj00648750 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwFlags34;
};

// 0x00648750
extern "C" __declspec(dllexport) void __stdcall sub_00648750(Obj00648750* pObj, int bSet) {
    if (bSet) {
        pObj->dwFlags34 |= 0x20;
    } else {
        pObj->dwFlags34 &= ~0x20;
    }
}
