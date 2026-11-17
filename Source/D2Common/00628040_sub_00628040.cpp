struct Data00628040 { unsigned char bUnknown00[0x34]; unsigned short wValue34; };
struct Unit00628040 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00628040* pData; };
// 0x00628040
extern "C" __declspec(dllexport) unsigned short __stdcall sub_00628040(Unit00628040* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->wValue34;
    }
    return 0;
}
