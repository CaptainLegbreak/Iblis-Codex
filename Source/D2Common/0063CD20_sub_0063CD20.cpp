struct Obj0063CD20 {
    unsigned int dwUnknown00;
    unsigned int dwValue04;
};

// 0x0063CD20
extern "C" __declspec(dllexport) unsigned int __stdcall sub_0063CD20(Obj0063CD20* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue04;
}
