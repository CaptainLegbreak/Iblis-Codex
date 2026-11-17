struct Obj006252D0 { unsigned char bUnknown00[0x14]; unsigned int dwValue14; };
// 0x006252D0
extern "C" __declspec(dllexport) void __stdcall sub_006252D0(Obj006252D0* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwValue14 = dwValue;
    }
}
