struct Obj00538650 { unsigned char bUnknown00[0x0A]; unsigned short wFlags0A; };
// 0x00538650
extern "C" __declspec(dllexport) void __fastcall sub_00538650(Obj00538650* pObj, unsigned short wMask, int bSet) {
    if (bSet) {
        pObj->wFlags0A |= wMask;
    } else {
        pObj->wFlags0A &= ~wMask;
    }
}
