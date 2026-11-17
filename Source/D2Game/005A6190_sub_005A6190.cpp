struct Data005A6190 { unsigned char bUnknown00[0x2C]; unsigned int dwValue2C; };
struct Unit005A6190 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data005A6190* pData; };
// 0x005A6190
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005A6190(Unit005A6190* pUnit) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        return pUnit->pData->dwValue2C;
    }
    return 0;
}
