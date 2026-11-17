struct Data00627F50 { unsigned char bUnknown00[0x36]; unsigned short wValue36; };
struct Unit00627F50 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627F50* pData; };
// 0x00627F50
extern "C" __declspec(dllexport) void __stdcall sub_00627F50(Unit00627F50* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValue36 = wValue;
    }
}
