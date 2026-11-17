struct Sub004BDFD0 { unsigned char bUnknown00[0x28]; unsigned int dwMember28; };
struct Obj004BDFD0 { unsigned char bUnknown00[0x14]; Sub004BDFD0* pSub14; };
// 0x004BDFD0
extern "C" __declspec(dllexport) unsigned int* __fastcall sub_004BDFD0(Obj004BDFD0* pObj) {
    return &pObj->pSub14->dwMember28;
}
