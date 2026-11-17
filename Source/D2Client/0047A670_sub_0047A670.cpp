struct Obj0047A670 { unsigned char bUnknown00[0x1C]; int nMode1C; };
// 0x0047A670
extern "C" __declspec(dllexport) int __fastcall sub_0047A670(Obj0047A670* pObj) {
    if (pObj) {
        switch (pObj->nMode1C) {
        case 0:
        case 1:
        case 6:
            return 0;
        }
    }
    return 1;
}
