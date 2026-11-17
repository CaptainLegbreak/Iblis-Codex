struct Obj005DD230 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned short wFlags08;
};

// 0x005DD230
extern "C" __declspec(dllexport) void __fastcall sub_005DD230(Obj005DD230* pObj, unsigned short wMask, int bSet) {
    if (bSet) {
        pObj->wFlags08 |= wMask;
    } else {
        pObj->wFlags08 &= ~wMask;
    }
}
