struct Obj0061AFA0 { unsigned char bUnknown00[0x14]; unsigned char bIndex14; unsigned char bUnknown15[0x23]; unsigned int dwRing38[4]; };
// 0x0061AFA0
extern "C" __declspec(dllexport) void __stdcall sub_0061AFA0(Obj0061AFA0* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwRing38[pObj->bIndex14] = dwValue;
        pObj->bIndex14 = (pObj->bIndex14 + 1) & 3;
    }
}
