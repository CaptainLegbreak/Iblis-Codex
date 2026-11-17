struct Obj006252B0 { unsigned char bUnknown00[0x0C]; unsigned int dwValue0C; };
// 0x006252B0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006252B0(Obj006252B0* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue0C;
}
