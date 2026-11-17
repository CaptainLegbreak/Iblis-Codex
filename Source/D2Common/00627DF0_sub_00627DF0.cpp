struct Data00627DF0 { unsigned char bUnknown00[0x10]; unsigned int dwValue10; };
struct Unit00627DF0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627DF0* pData; };
// 0x00627DF0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00627DF0(Unit00627DF0* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->dwValue10;
    }
    return 0;
}
