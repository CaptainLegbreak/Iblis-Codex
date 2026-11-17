struct Data00627EA0 { unsigned int dwValue00; };
struct Unit00627EA0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627EA0* pData; };
// 0x00627EA0
extern "C" __declspec(dllexport) void __stdcall sub_00627EA0(Unit00627EA0* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->dwValue00 = dwValue;
    }
}
