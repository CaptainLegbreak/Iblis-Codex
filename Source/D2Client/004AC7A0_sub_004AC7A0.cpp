#pragma pack(push, 1)
struct Data004AC7A0 { unsigned char bUnknown00[0x26]; unsigned short wValue26; };
#pragma pack(pop)
struct Unit004AC7A0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AC7A0* pData;
};
// 0x004AC7A0
extern "C" __declspec(dllexport) void __fastcall sub_004AC7A0(Unit004AC7A0* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->wValue26 = wValue;
    }
}
