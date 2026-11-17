struct Sub00546F90 { unsigned char bUnknown00[0x48]; void* pEntries48[1]; };
struct Obj00546F90 { unsigned char bUnknown00[0x10F0]; Sub00546F90* pSub10F0; };
// 0x00546F90
extern "C" __declspec(dllexport) void* __fastcall sub_00546F90(Obj00546F90* pObj, int nIndex) {
    return pObj->pSub10F0->pEntries48[nIndex];
}
