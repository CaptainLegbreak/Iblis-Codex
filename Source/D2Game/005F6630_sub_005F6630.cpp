struct Target005F6630 { unsigned char bUnknown00[0x14]; unsigned int dwValue14; unsigned int dwValue18; };
struct Obj005F6630 { unsigned char bUnknown00[0xA8]; unsigned int dwValueA8; };
// 0x005F6630
extern "C" __declspec(dllexport) void __fastcall sub_005F6630(Obj005F6630* pObj, int nUnusedEdx, Target005F6630** ppTarget) {
    Target005F6630* pTarget = *ppTarget;
    pTarget->dwValue14 = pObj->dwValueA8;
    pTarget->dwValue18 = 0;
}
