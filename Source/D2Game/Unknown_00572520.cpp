struct Pair00572520 { unsigned int dwFirst; unsigned int dwSecond; };
struct Mid00572520 { Pair00572520* pPair; };
struct Obj00572520 { Mid00572520* pMid; };
// 0x00572520
extern "C" __declspec(dllexport) void __fastcall sub_00572520(Obj00572520* pObj, Pair00572520* pOut) {
    *pOut = *pObj->pMid->pPair;
}
