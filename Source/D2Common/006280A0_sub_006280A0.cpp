struct Data006280A0 { unsigned char bUnknown00[0x18]; unsigned int dwFlags18; };
struct Unit006280A0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data006280A0* pData; };
// 0x006280A0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006280A0(Unit006280A0* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->dwFlags18 & dwMask;
    }
    return 0;
}
