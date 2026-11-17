struct Obj00554650 { unsigned char bUnknown00[0x60]; unsigned int dwFlags60; };
// 0x00554650
extern "C" __declspec(dllexport) int __fastcall sub_00554650(Obj00554650* pObj, unsigned int dwBits) {
    unsigned int dwFlags = pObj->dwFlags60;
    if (dwFlags & 0xF0) {
        return 0;
    }
    pObj->dwFlags60 = dwFlags | dwBits;
    return 1;
}
