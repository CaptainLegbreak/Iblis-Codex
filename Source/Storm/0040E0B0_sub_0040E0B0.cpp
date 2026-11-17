struct Obj0040E0B0 { unsigned char bUnknown00[0x30]; unsigned int dwValue30; unsigned int dwValue34; };
// 0x0040E0B0
extern "C" __declspec(dllexport) int __fastcall sub_0040E0B0(Obj0040E0B0* pObj, unsigned int* pFirst, unsigned int* pSecond) {
    *pFirst = pObj->dwValue30;
    *pSecond = pObj->dwValue34;
    return 1;
}
