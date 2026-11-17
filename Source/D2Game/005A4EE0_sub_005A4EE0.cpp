struct Unit005A4EE0 { int nType; };
// 0x005A4EE0
extern "C" __declspec(dllexport) int __fastcall sub_005A4EE0(Unit005A4EE0* pUnit) {
    if (pUnit) {
        int nType = pUnit->nType;
        if (nType == 1) {
            return nType;
        }
    }
    return 0;
}
