struct Data00628250 { unsigned char bUnknown00[0x45]; char cValue45; };
struct Unit00628250 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00628250* pData; };
// 0x00628250
extern "C" __declspec(dllexport) char __stdcall sub_00628250(Unit00628250* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->cValue45;
    }
    return -1;
}
