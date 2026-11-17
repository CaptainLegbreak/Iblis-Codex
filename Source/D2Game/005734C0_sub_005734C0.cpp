struct Data005734C0 { unsigned char bUnknown00[0x54]; unsigned int dwValue54; };
struct Unit005734C0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005734C0* pData;
};
// 0x005734C0
extern "C" __declspec(dllexport) void __fastcall sub_005734C0(Unit005734C0* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->dwValue54 = dwValue;
    }
}
