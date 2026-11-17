#pragma pack(push, 1)
struct Data004AC780 { unsigned char bUnknown00[0x14]; unsigned short wValue14; };
#pragma pack(pop)
struct Unit004AC780 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AC780* pData;
};
// 0x004AC780
extern "C" __declspec(dllexport) void __fastcall sub_004AC780(Unit004AC780* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->wValue14 = wValue;
    }
}
