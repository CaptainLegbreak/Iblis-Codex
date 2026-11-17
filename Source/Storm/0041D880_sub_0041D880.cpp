struct Obj0041D880 { const unsigned int* pCur00; unsigned int dwBits04; int nBitCount08; };
// 0x0041D880
extern "C" __declspec(dllexport) Obj0041D880* __fastcall sub_0041D880(Obj0041D880* pObj, int nUnusedEdx, const unsigned int* pBuffer) {
    pObj->pCur00 = pBuffer;
    pObj->dwBits04 = *pObj->pCur00++;
    pObj->nBitCount08 = 32;
    return pObj;
}
