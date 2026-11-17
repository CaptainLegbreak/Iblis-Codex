struct Data00573500 { unsigned char bUnknown00[0x58]; unsigned int dwValue58; };
struct Unit00573500 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00573500* pData;
};
// 0x00573500
extern "C" __declspec(dllexport) void __fastcall sub_00573500(Unit00573500* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->dwValue58 = dwValue;
    }
}
