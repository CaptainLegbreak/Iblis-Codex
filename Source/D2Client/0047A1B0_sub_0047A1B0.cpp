struct Obj0047A1B0 { unsigned char bUnknown00[0x28]; unsigned int dwValue28; unsigned int dwValue2C; };
// 0x0047A1B0
extern "C" __declspec(dllexport) void __fastcall sub_0047A1B0(Obj0047A1B0* pObj, unsigned int* pFirst, unsigned int* pSecond) {
    if (pObj) {
        *pFirst = pObj->dwValue28;
        *pSecond = pObj->dwValue2C;
    } else {
        *pFirst = 0;
        *pSecond = 0;
    }
}
