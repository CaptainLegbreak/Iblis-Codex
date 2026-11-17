struct Sub00546FB0 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwMember08; };
struct Obj00546FB0 { unsigned char bUnknown00[0x10F0]; Sub00546FB0* pSub10F0; };
// 0x00546FB0
extern "C" __declspec(dllexport) unsigned int* __fastcall sub_00546FB0(Obj00546FB0* pObj) {
    return &pObj->pSub10F0->dwMember08;
}
