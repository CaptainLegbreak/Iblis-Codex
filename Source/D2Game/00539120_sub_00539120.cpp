#pragma pack(push, 1)
struct Obj00539120 { unsigned char bUnknown00[0x45E]; unsigned short wValue45E; };
#pragma pack(pop)
// 0x00539120
extern "C" __declspec(dllexport) void __fastcall sub_00539120(Obj00539120* pObj, unsigned short wValue) {
    pObj->wValue45E = wValue;
}
