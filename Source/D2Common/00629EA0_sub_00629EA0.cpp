struct Data00629EA0 { unsigned char bUnknown00[0x1C]; unsigned int dwValue1C; unsigned int dwValue20; };
struct Unit00629EA0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00629EA0* pData; };
// 0x00629EA0
extern "C" __declspec(dllexport) void __stdcall sub_00629EA0(Unit00629EA0* pUnit, unsigned int dwFirst, unsigned int dwSecond) {
    if (pUnit && pUnit->nType == 4) {
        Data00629EA0* pData = pUnit->pData;
        if (pData) {
            pData->dwValue1C = dwFirst;
            pData->dwValue20 = dwSecond;
        }
    }
}
