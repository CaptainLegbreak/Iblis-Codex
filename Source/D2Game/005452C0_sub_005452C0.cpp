struct Obj005452C0 { unsigned char bUnknown00[0x1C]; unsigned int dwValues1C[32]; unsigned short wCount9C; };
// 0x005452C0
extern "C" __declspec(dllexport) int __fastcall sub_005452C0(Obj005452C0* pObj, unsigned int dwValue) {
    int nCount = pObj->wCount9C;
    for (int i = 0; i < nCount; i++) {
        if (pObj->dwValues1C[i] == dwValue) {
            return 1;
        }
    }
    return 0;
}
