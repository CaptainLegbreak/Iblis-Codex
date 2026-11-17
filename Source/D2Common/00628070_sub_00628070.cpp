struct Data00628070 { unsigned char bUnknown00[0x34]; unsigned short wValue34; };
struct Unit00628070 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00628070* pData; };
// 0x00628070
extern "C" __declspec(dllexport) void __stdcall sub_00628070(Unit00628070* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValue34 = wValue;
    }
}
