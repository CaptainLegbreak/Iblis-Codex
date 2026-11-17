struct Entry00547390 { unsigned int dwUnknown00[4]; int nCount10; };
struct Sub00547390 { unsigned char bUnknown00[0x48]; Entry00547390* pEntries48[1]; };
struct Obj00547390 { unsigned char bUnknown00[0x10F0]; Sub00547390* pSub10F0; };
// 0x00547390
extern "C" __declspec(dllexport) void __fastcall sub_00547390(Obj00547390* pObj, int nIndex) {
    pObj->pSub10F0->pEntries48[nIndex]->nCount10++;
}
