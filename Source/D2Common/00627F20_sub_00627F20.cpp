struct Data00627F20 { unsigned char bUnknown00[0x36]; unsigned short wValue36; };
struct Unit00627F20 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627F20* pData; };
// 0x00627F20
extern "C" __declspec(dllexport) unsigned short __stdcall sub_00627F20(Unit00627F20* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->wValue36;
    }
    return 0;
}
