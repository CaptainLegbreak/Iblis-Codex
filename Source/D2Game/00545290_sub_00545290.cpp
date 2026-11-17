struct Obj00545290 { unsigned int dwValues[32]; unsigned short wCount80; };
// 0x00545290
extern "C" __declspec(dllexport) int __fastcall sub_00545290(Obj00545290* pObj, unsigned int dwValue) {
    int nCount = pObj->wCount80;
    for (int i = 0; i < nCount; i++) {
        if (pObj->dwValues[i] == dwValue) {
            return 1;
        }
    }
    return 0;
}
