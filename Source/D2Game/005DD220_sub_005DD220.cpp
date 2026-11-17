struct Obj005DD220 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned short wFlags08; };
// 0x005DD220
extern "C" __declspec(dllexport) int __fastcall sub_005DD220(Obj005DD220* pObj, unsigned short wMask) {
    return (pObj->wFlags08 & wMask) != 0;
}
