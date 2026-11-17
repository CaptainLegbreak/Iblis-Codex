struct Data00628140 { unsigned char bUnknown00[0x14]; unsigned int dwFlags14; };
struct Unit00628140 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00628140* pData; };
// 0x00628140
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00628140(Unit00628140* pUnit, unsigned int dwMask) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->dwFlags14 & dwMask;
    }
    return 0;
}
