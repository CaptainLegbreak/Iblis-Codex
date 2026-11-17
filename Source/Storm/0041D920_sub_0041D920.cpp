struct Obj0041D920 { unsigned int dwCur00; unsigned int dwValue04; unsigned int dwBase08; unsigned int dwValue0C; unsigned int dwValue10; };
// 0x0041D920
extern "C" __declspec(dllexport) Obj0041D920* __fastcall sub_0041D920(Obj0041D920* pObj, int nUnusedEdx, unsigned int dwFirst, unsigned int dwSecond) {
    pObj->dwBase08 = dwFirst;
    pObj->dwCur00 = dwFirst;
    pObj->dwValue04 = dwSecond;
    pObj->dwValue0C = 0;
    pObj->dwValue10 = 0;
    return pObj;
}
