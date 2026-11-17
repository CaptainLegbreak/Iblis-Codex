struct Data00627FE0 { unsigned char bUnknown00[0x32]; unsigned short wValue32; };
struct Unit00627FE0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627FE0* pData; };
// 0x00627FE0
extern "C" __declspec(dllexport) unsigned short __stdcall sub_00627FE0(Unit00627FE0* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->wValue32;
    }
    return 0;
}
