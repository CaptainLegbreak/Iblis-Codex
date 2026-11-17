struct Obj006260B0 { unsigned char bUnknown00[0x10]; unsigned int dwFlags10; unsigned int dwUnknown14; int nValue18; };
// 0x006260B0
extern "C" __declspec(dllexport) void __stdcall sub_006260B0(Obj006260B0* pObj, int nValue) {
    if (pObj) {
        if (nValue > 0) {
            pObj->dwFlags10 |= 2;
        }
        pObj->nValue18 = nValue;
    }
}
