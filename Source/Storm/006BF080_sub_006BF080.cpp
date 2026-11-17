struct Obj006BF080 { unsigned char bUnknown00[0xBBC]; unsigned int dwValueBBC; };
// 0x006BF080
extern "C" __declspec(dllexport) void __stdcall sub_006BF080(Obj006BF080* pObj, unsigned int dwValue) {
    pObj->dwValueBBC = dwValue;
}
