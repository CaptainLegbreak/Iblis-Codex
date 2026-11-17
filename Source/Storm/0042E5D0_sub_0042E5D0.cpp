// 0x0042E5D0
extern "C" __declspec(dllexport) void __fastcall sub_0042E5D0(unsigned short* pValues, unsigned int nCount) {
    for (unsigned int i = 0; i < nCount; i++) {
        pValues[i] = (unsigned short)((pValues[i] << 8) | (pValues[i] >> 8));
    }
}
