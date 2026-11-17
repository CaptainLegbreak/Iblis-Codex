struct Obj00648A30 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned short wUnknown18;
    unsigned short wValue1A;
};

// 0x00648A30
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00648A30(Obj00648A30* pObj) {
    return pObj->wValue1A;
}
