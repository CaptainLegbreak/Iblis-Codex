struct Obj00479BA0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwValue1C;
};

// 0x00479BA0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00479BA0(Obj00479BA0* pObj) {
    if (pObj) {
        return pObj->dwValue1C;
    }
    return 0;
}
