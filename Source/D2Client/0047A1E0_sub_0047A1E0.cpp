struct Obj0047A1E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwValue24;
};

// 0x0047A1E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_0047A1E0(Obj0047A1E0* pObj) {
    if (pObj) {
        return pObj->dwValue24;
    }
    return 0;
}
