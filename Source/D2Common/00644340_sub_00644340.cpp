struct Obj00644340 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwValue08;
};

// 0x00644340
extern "C" __declspec(dllexport) void __stdcall sub_00644340(Obj00644340* pObj, unsigned int dwValue) {
    if (pObj && dwValue <= 0x20) {
        pObj->dwValue08 = dwValue;
    }
}
