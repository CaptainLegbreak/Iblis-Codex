struct Sub005901E0 { unsigned char bUnknown00[0x88]; unsigned int dwValue88; };
struct Obj005901E0 { unsigned char bUnknown00[0x18]; Sub005901E0* pSub18; };
// 0x005901E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005901E0(Obj005901E0* pObj) {
    return pObj->pSub18->dwValue88;
}
