struct Obj00625250 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwValue08; };
// 0x00625250
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00625250(Obj00625250* pObj) {
    if (!pObj) {
        return 6;
    }
    return pObj->dwValue08;
}
