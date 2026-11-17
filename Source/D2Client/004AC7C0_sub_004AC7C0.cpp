#pragma pack(push, 1)
struct Data004AC7C0 { unsigned char bUnknown00[0x26]; unsigned short wValue26; };
#pragma pack(pop)
struct Unit004AC7C0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data004AC7C0* pData; };
// 0x004AC7C0
extern "C" __declspec(dllexport) unsigned short __fastcall sub_004AC7C0(Unit004AC7C0* pUnit) {
    Data004AC7C0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return pData->wValue26;
}
