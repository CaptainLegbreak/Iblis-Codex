struct Obj00451F70 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwValue10;
};

// 0x00451F70
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00451F70(Obj00451F70* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue10;
}
