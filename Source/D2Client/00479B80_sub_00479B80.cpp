struct Obj00479B80 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwValue18;
};

// 0x00479B80
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00479B80(Obj00479B80* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
}
