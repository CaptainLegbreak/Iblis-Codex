// 0x005267E0
extern "C" __declspec(dllexport) unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc) {
    unsigned short* p = pDst;
    do {
        *p++ = *pSrc;
    } while (*pSrc++);
    return pDst;
}
