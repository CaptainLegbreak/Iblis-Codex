struct Data005734E0 { unsigned char bUnknown00[0x54]; unsigned int dwValue54; };
struct Unit005734E0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data005734E0* pData; };
// 0x005734E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005734E0(Unit005734E0* pUnit) {
    Data005734E0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 1;
    }
    return pData->dwValue54;
}
