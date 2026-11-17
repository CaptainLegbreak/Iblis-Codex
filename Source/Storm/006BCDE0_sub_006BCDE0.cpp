struct Obj006BCDE0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwValue08;
};

// 0x006BCDE0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006BCDE0(Obj006BCDE0* pObj) {
    return pObj->dwValue08;
}
