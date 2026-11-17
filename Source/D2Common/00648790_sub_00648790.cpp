struct Obj00648790 { unsigned char bUnknown00[0x28]; int nValue28; };
// 0x00648790
extern "C" __declspec(dllexport) void __stdcall sub_00648790(Obj00648790* pObj, int nValue) {
    if (nValue > 77) {
        nValue = 77;
    }
    pObj->nValue28 = nValue;
}
