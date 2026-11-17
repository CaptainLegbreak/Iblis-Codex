struct Obj00479D20 {
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
    unsigned int dwValue30;
};

// 0x00479D20
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00479D20(Obj00479D20* pObj) {
    if (pObj) {
        return pObj->dwValue30;
    }
    return 1;
}
