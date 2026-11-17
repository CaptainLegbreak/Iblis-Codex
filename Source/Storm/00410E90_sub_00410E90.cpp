struct Obj00410E90 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    int nValue08;
    int nFlag0C;
};

// 0x00410E90
extern "C" __declspec(dllexport) int __stdcall sub_00410E90(Obj00410E90* pObj) {
    return pObj->nFlag0C ? pObj->nValue08 + 1 : pObj->nValue08;
}
