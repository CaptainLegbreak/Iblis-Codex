struct Obj00619EE0 {
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
    int nCount28;
};

// 0x00619EE0
extern "C" __declspec(dllexport) void __stdcall sub_00619EE0(Obj00619EE0* pObj) {
    if (pObj) {
        pObj->nCount28++;
    }
}
