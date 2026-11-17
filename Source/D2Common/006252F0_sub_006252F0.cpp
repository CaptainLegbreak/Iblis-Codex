struct Obj006252F0 { unsigned char bUnknown00[0x14]; unsigned int dwValue14; };
// 0x006252F0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006252F0(Obj006252F0* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue14;
}
