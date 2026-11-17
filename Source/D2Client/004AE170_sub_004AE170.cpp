struct Data004AE170 { unsigned char bUnknown00[0x34]; unsigned int dwMember34; };
struct Unit004AE170 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data004AE170* pData; };
// 0x004AE170
extern "C" __declspec(dllexport) unsigned int* __fastcall sub_004AE170(Unit004AE170* pUnit) {
    Data004AE170* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return &pData->dwMember34;
}
