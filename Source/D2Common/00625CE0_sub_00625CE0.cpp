struct Obj00625CE0 { unsigned char bUnknown00[0x38]; unsigned int dwValue38; };
// 0x00625CE0
extern "C" __declspec(dllexport) void __stdcall sub_00625CE0(Obj00625CE0* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwValue38 = dwValue;
    }
}
