struct Data00627EF0 { unsigned char bUnknown00[0x38]; unsigned short wValues38[1]; };
struct Unit00627EF0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627EF0* pData; };
// 0x00627EF0
extern "C" __declspec(dllexport) void __stdcall sub_00627EF0(Unit00627EF0* pUnit, unsigned short wValue, int nIndex) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValues38[nIndex] = wValue;
    }
}
