struct Obj00625330 { unsigned char bUnknown00[0x18]; unsigned int dwValue18; };
// 0x00625330
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00625330(Obj00625330* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
}
