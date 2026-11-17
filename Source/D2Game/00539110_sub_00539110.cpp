#pragma pack(push, 1)
struct Obj00539110 { unsigned char bUnknown00[0x45E]; unsigned short wValue45E; };
#pragma pack(pop)
// 0x00539110
extern "C" __declspec(dllexport) unsigned short __fastcall sub_00539110(Obj00539110* pObj) {
    return pObj->wValue45E;
}
