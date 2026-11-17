struct Data004AC840 { unsigned char bUnknown00[0x16]; unsigned short wFlags16; };
struct Unit004AC840 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data004AC840* pData; };
// 0x004AC840
extern "C" __declspec(dllexport) void __fastcall sub_004AC840(Unit004AC840* pUnit, int bSet) {
    if (pUnit && pUnit->nType == 1) {
        Data004AC840* pData = pUnit->pData;
        if (pData) {
            if (bSet) {
                pData->wFlags16 |= 0x100;
            } else {
                pData->wFlags16 &= ~0x100;
            }
        }
    }
}
