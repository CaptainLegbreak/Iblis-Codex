#pragma pack(push, 1)
struct Data004AE150 { unsigned char bUnknown00[0x3C]; unsigned int dwValue3C; };
#pragma pack(pop)
struct Unit004AE150 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AE150* pData;
};
// 0x004AE150
extern "C" __declspec(dllexport) void __fastcall sub_004AE150(Unit004AE150* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->dwValue3C = dwValue;
    }
}
