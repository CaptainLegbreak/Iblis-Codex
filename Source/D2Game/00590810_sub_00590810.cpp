struct Obj00590810 {
    unsigned char bUnknown00[9];
    unsigned char bFlag09;
    unsigned char bUnknown0A[2];
    unsigned char bValue0C;
};
// 0x00590810
extern "C" __declspec(dllexport) bool __fastcall sub_00590810(Obj00590810* pObj) {
    if (pObj->bFlag09 && pObj->bValue0C >= 4) {
        return true;
    }
    return false;
}
