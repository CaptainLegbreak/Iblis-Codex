#pragma pack(push, 1)
struct Data005A0200 { unsigned char bUnknown00[0x26]; unsigned short wValue26; };
#pragma pack(pop)
struct Unit005A0200 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0200* pData;
};
// 0x005A0200
extern "C" __declspec(dllexport) void __fastcall sub_005A0200(Unit005A0200* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->wValue26 = wValue;
    }
}
