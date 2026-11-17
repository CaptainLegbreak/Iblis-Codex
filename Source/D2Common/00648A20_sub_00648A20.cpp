struct Obj00648A20 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned short wValue18;
};

// 0x00648A20
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00648A20(Obj00648A20* pObj) {
    return pObj->wValue18;
}
