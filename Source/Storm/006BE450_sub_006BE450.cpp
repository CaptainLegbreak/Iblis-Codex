struct Obj006BE450 { unsigned char bUnknown00[0x880]; unsigned int dwValue880; };
// 0x006BE450
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006BE450(Obj006BE450* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue880;
}
