struct Data00627FB0 { unsigned char bUnknown00[0x3E]; unsigned short wValues3E[1]; };
struct Unit00627FB0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627FB0* pData; };
// 0x00627FB0
extern "C" __declspec(dllexport) void __stdcall sub_00627FB0(Unit00627FB0* pUnit, unsigned short wValue, int nIndex) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValues3E[nIndex] = wValue;
    }
}
