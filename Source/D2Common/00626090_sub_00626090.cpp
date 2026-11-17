struct Obj00626090 { unsigned char bUnknown00[0x18]; unsigned int dwValue18; };
// 0x00626090
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00626090(Obj00626090* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
}
