#pragma pack(push, 1)
struct Data0064A6D0 { unsigned char bUnknown00[0x30]; unsigned int dwValue30; };
#pragma pack(pop)
struct Unit0064A6D0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A6D0* pData;
};
// 0x0064A6D0
extern "C" __declspec(dllexport) void __fastcall sub_0064A6D0(Unit0064A6D0* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        pUnit->pData->dwValue30 = dwValue;
    }
}
