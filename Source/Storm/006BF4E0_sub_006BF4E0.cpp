struct Obj006BF4E0 { unsigned char bUnknown00[0xBD0]; unsigned int dwValueBD0; };
// 0x006BF4E0
extern "C" __declspec(dllexport) void __stdcall sub_006BF4E0(Obj006BF4E0* pObj, unsigned int dwValue) {
    pObj->dwValueBD0 = dwValue;
}
