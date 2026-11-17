struct Pair00650E70 { unsigned int dwFirst; unsigned int dwSecond; };
// 0x00650E70
extern "C" __declspec(dllexport) void __fastcall sub_00650E70(Pair00650E70* pPair, unsigned int* pFirst, unsigned int* pSecond) {
    *pFirst = pPair->dwFirst;
    *pSecond = pPair->dwSecond;
}
