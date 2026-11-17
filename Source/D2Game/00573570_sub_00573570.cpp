struct Data00573570 { unsigned char bUnknown00[0x5C]; unsigned short wFlags5C; };
struct Unit00573570 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00573570* pData; };
// 0x00573570
extern "C" __declspec(dllexport) void __fastcall sub_00573570(Unit00573570* pUnit, unsigned short wMask, int bSet) {
    if (pUnit && pUnit->nType == 1) {
        Data00573570* pData = pUnit->pData;
        if (pData) {
            if (bSet) {
                pData->wFlags5C |= wMask;
            } else {
                pData->wFlags5C &= ~wMask;
            }
        }
    }
}
