struct Data00552D60 { unsigned char bUnknown00[0x50]; unsigned int dwValue50; };
struct Unit00552D60 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00552D60* pData;
};
// 0x00552D60
extern "C" __declspec(dllexport) void __fastcall sub_00552D60(Unit00552D60* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->dwValue50 = dwValue;
    }
}
